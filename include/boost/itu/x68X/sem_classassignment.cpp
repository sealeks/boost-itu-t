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

    typefield_entity* field_entity::as_typefield() {
        return (fieldkind_ == fkind_TypeFieldSpec) ? dynamic_cast<typefield_entity*> (this) : 0;
    }

    valuefield_entity* field_entity::as_valuefield() {
        return (fieldkind_ == fkind_FixedTypeValueFieldSpec) ? dynamic_cast<valuefield_entity*> (this) : 0;
    }

    valuesetfield_entity* field_entity::as_valuesetfield() {
        return (fieldkind_ == fkind_FixedTypeValueSetFieldSpec) ? dynamic_cast<valuesetfield_entity*> (this) : 0;
    }

    reffvaluefield_entity* field_entity::as_reffvaluefield() {
        return (fieldkind_ == fkind_VariableTypeValueFieldSpec) ? dynamic_cast<reffvaluefield_entity*> (this) : 0;
    }

    reffvaluesetfield_entity* field_entity::as_reffvaluesetfield() {
        return (fieldkind_ == fkind_VariableTypeValueSetFieldSpec) ? dynamic_cast<reffvaluesetfield_entity*> (this) : 0;
    }

    objectfield_entity* field_entity::as_objectfield() {
        return (fieldkind_ == fkind_ObjectFieldSpec) ? dynamic_cast<objectfield_entity*> (this) : 0;
    }

    objectsetfield_entity* field_entity::as_objectsetfield() {
        return (fieldkind_ == fkind_ObjectSetFieldSpec) ? dynamic_cast<objectsetfield_entity*> (this) : 0;
    }

    undeffield_entity* field_entity::as_undeffield() {
        return (fieldkind_ == fkind_FixedType_or_Object) ? dynamic_cast<undeffield_entity*> (this) : 0;
    }

    undefsetfield_entity* field_entity::as_undefsetfield() {
        return (fieldkind_ == fkind_FixedTypeSet_or_ObjectSet) ? dynamic_cast<undefsetfield_entity*> (this) : 0;
    }

    /////////////////////////////////////////////////////////////////////////   
    // typefield_entity
    /////////////////////////////////////////////////////////////////////////  

    void typefield_entity::resolve() {
        if (_default())
            _default()->resolve_reff();
    }

    /////////////////////////////////////////////////////////////////////////   
    // valuefield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void valuefield_entity::resolve() {
        if (type())
            type()->resolve_reff();
        if (_default())
            _default()->resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////   
    // valuefield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void valuesetfield_entity::resolve() {
        if (type())
            type()->resolve_reff();
        if (_default())
            _default()->resolve_reff();
    }

    /////////////////////////////////////////////////////////////////////////   
    // reffvaluefield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void reffvaluefield_entity::resolve() {
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
        referenceerror_throw(field()->expectedname());
    }


    /////////////////////////////////////////////////////////////////////////   
    // reffvaluefield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void reffvaluesetfield_entity::resolve() {
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
        referenceerror_throw(field()->expectedname());
    }

    /////////////////////////////////////////////////////////////////////////   
    // objectfield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void objectfield_entity::resolve() {
        if (_class())
            _class()->resolve_reff();
        if (_default())
            _default()->resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////   
    // objectsetfield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void objectsetfield_entity::resolve() {
        if (_class())
            _class()->resolve_reff();
        if (_default())
            _default()->resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////   
    // undeffield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void undeffield_entity::resolve() {

    }


    /////////////////////////////////////////////////////////////////////////   
    // undeffield_entity
    ///////////////////////////////////////////////////////////////////////// 

    void undefsetfield_entity::resolve() {

    }


    /////////////////////////////////////////////////////////////////////////   
    // sintax_atom
    /////////////////////////////////////////////////////////////////////////      

    groupsyntax_atom* syntax_atom::as_group() {
        return dynamic_cast<groupsyntax_atom*> (this);
    }

    void syntax_atom::resolve() {
        if (expecteddef()) {
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (expectedname() == (*it)->name()) {
                    reff(*it);
                    return;
                }
            }
            scope()->referenceerror_throw(expectedname());
        }
    }

    /////////////////////////////////////////////////////////////////////////   
    // groupsyntax_atom
    ///////////////////////////////////////////////////////////////////////// 

    void groupsyntax_atom::resolve() {
        for (syntax_atom_vct::iterator it = group_.begin(); it != group_.end(); ++it)
            (*it)->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    //class_atom
    /////////////////////////////////////////////////////////////////////////   

    class_atom::class_atom(basic_entity_ptr scope, definedclass_type tp)
    : basic_atom(scope), builtin_(tp) {
    }

    class_atom::class_atom(basic_entity_ptr scope, const std::string& reff, definedclass_type tp)
    : basic_atom(reff, scope), builtin_(tp) {
    }

    void class_atom::resolve() {
        if (builtin_ == cl_Reference)
            resolve_reff();
    }



    /////////////////////////////////////////////////////////////////////////   
    // classassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    classassignment_entity::classassignment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr tp) :
    assignment_entity(scope, nm, et_Class), class_(tp) {
    };

    basic_entity_ptr classassignment_entity::find_by_name(const std::string& nm, bool all) {
        if (scope()) {
            prefind(nm, scope()->childs());
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it)
                if (nm == (*it)->name())
                    return *it;
        }
        if (scope())
            return scope()->find_by_name(nm, all);
        return basic_entity_ptr();
    }

    void classassignment_entity::resolve() {
        assignment_entity::resolve();
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
                    undeffield_entity* tmp = (*it)->as_classfield()->as_undeffield();
                    basic_entity_ptr fnd = scope()->find(tmp->big()->reff());
                    if (fnd) {
                        if (fnd->kind() == et_Type) {
                            type_atom_ptr tp = type_atom_ptr(new type_atom(scope(), tmp->big()->reff()->name(), t_Reference));
                            if (tmp->marker() == mk_default) {
                                if (!tmp->_defaultv())
                                    tmp->referenceerror_throw(tmp->big()->reff()->name());
                                *it = basic_entity_ptr(new valuefield_entity(scope(), tmp->name(), tp, tmp->_defaultv()));
                            } else
                                *it = basic_entity_ptr(new valuefield_entity(scope(), tmp->name(), tp, false, tmp->marker()));
                        }
                        if (fnd->kind() == et_Class) {
                            class_atom_ptr tp = class_atom_ptr(new class_atom(scope(), tmp->big()->reff()->name(), cl_Reference));
                            if (tmp->marker() == mk_default) {
                                if (!tmp->_defaulto())
                                    tmp->referenceerror_throw(tmp->big()->reff()->name());
                                *it = basic_entity_ptr(new objectfield_entity(scope(), tmp->name(), tp, tmp->_defaulto()));
                            } else
                                *it = basic_entity_ptr(new objectfield_entity(scope(), tmp->name(), tp, tmp->marker()));
                        }
                    } else
                        tmp->referenceerror_throw(tmp->big()->reff()->name());
                } else if ((*it)->as_classfield()->as_undefsetfield()) {
                    undefsetfield_entity* tmp = (*it)->as_classfield()->as_undefsetfield();
                    basic_entity_ptr fnd = scope()->find(tmp->big()->reff());
                    if (fnd) {
                        if (fnd->kind() == et_Type) {
                            type_atom_ptr tp = type_atom_ptr(new type_atom(scope(), tmp->big()->reff()->name(), t_Reference));
                            if (tmp->marker() == mk_default) {
                                if (!tmp->_defaultv())
                                    tmp->referenceerror_throw(tmp->big()->reff()->name());
                                *it = basic_entity_ptr(new valuesetfield_entity(scope(), tmp->name(), tp, tmp->_defaultv()));
                            } else
                                *it = basic_entity_ptr(new valuesetfield_entity(scope(), tmp->name(), tp, tmp->marker()));
                        }
                        if (fnd->kind() == et_Class) {
                            class_atom_ptr tp = class_atom_ptr(new class_atom(scope(), tmp->big()->reff()->name(), cl_Reference));
                            if (tmp->marker() == mk_default) {
                                if (!tmp->_defaulto())
                                    tmp->referenceerror_throw(tmp->big()->reff()->name());
                                *it = basic_entity_ptr(new objectsetfield_entity(scope(), tmp->name(), tp, tmp->_defaulto()));
                            } else
                                *it = basic_entity_ptr(new objectsetfield_entity(scope(), tmp->name(), tp, tmp->marker()));
                        }
                    } else
                        tmp->referenceerror_throw(tmp->big()->reff()->name());
                }
            }
        }
    }




    /////////////////////////////////////////////////////////////////////////   
    // OBJECT
    /////////////////////////////////////////////////////////////////////////       
    /////////////////////////////////////////////////////////////////////////   
    // object_atom
    /////////////////////////////////////////////////////////////////////////  

    object_atom::object_atom(object_type tp)
    : basic_atom(), builtin_(tp) {
    }

    object_atom::object_atom(basic_entity_ptr scope, object_type tp)
    : basic_atom(scope), builtin_(tp) {
    }

    object_atom::object_atom(basic_entity_ptr scope, const std::string& reff, object_type tp)
    : basic_atom(reff, scope), builtin_(tp) {
    }

    definedobject_atom* object_atom::as_defined() {
        return dynamic_cast<definedobject_atom*> (this);
    }

    definedsetobject_atom* object_atom::as_definedset() {
        return dynamic_cast<definedsetobject_atom*> (this);
    }

    defltobject_atom* object_atom::as_deflt() {
        return dynamic_cast<defltobject_atom*> (this);
    }

    defsyntxobject_atom* object_atom::as_defnsyntx() {
        return dynamic_cast<defsyntxobject_atom*> (this);
    }

    fromobjectobject_atom* object_atom::as_fromobject() {
        return dynamic_cast<fromobjectobject_atom*> (this);
    }

    fromdefinedsetobject_atom* object_atom::as_fromdefinedset() {
        return dynamic_cast<fromdefinedsetobject_atom*> (this);
    }

    fromdefinedobject_atom* object_atom::as_fromdefined() {
        return dynamic_cast<fromdefinedobject_atom*> (this);
    }

    unionobject_atom* object_atom::as_union() {
        return dynamic_cast<unionobject_atom*> (this);
    }

    intersectionobject_atom* object_atom::as_intersection() {
        return dynamic_cast<intersectionobject_atom*> (this);
    }

    exceptobject_atom* object_atom::as_except() {
        return dynamic_cast<exceptobject_atom*> (this);
    }

    allexceptobject_atom* object_atom::as_allexcept() {
        return dynamic_cast<allexceptobject_atom*> (this);
    }

    extentionobject_atom* object_atom::as_extention() {
        return dynamic_cast<extentionobject_atom*> (this);
    }

    void object_atom::resolve() {
        if (builtin_ == ot_Refference)
            resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////        
    // defenedobject_atom
    /////////////////////////////////////////////////////////////////////////  

    void definedobject_atom::resolve() {
        // if (builtin() == ot_Refference)
        resolve_reff();
    };


    /////////////////////////////////////////////////////////////////////////        
    // definedsetobject_atom
    /////////////////////////////////////////////////////////////////////////    

    definedsetobject_atom::definedsetobject_atom(basic_entity_ptr scope, objectset_atom_ptr objs) :
    object_atom(scope, ot_DefinedObjectSet), objectset_(objs) {
    };

    void definedsetobject_atom::resolve() {
        if (objectset())
            objectset()->resolve();
    }


    /////////////////////////////////////////////////////////////////////////        
    // fromdefinedsetobject_atom
    /////////////////////////////////////////////////////////////////////////  

    fromdefinedsetobject_atom::fromdefinedsetobject_atom(basic_entity_ptr scope, const std::string& refffld, objectset_atom_ptr objs) :
    object_atom(scope, ot_ObjectSetFromObjects), objectset_(objs), field_(basic_atom_ptr(new basic_atom(refffld, scope))) {

    }

    void fromdefinedsetobject_atom::resolve() {
        if (objectset())
            objectset()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////        
    // fromdefinedobject_atom
    /////////////////////////////////////////////////////////////////////////  

    fromdefinedobject_atom::fromdefinedobject_atom(basic_entity_ptr scope, const std::string& refffld, object_atom_ptr obj) :
    object_atom(scope, ot_ObjectSetFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scope))) {

    }

    void fromdefinedobject_atom::resolve() {
        if (object())
            object()->resolve();
    }


    /////////////////////////////////////////////////////////////////////////        
    // defltobject_atom
    /////////////////////////////////////////////////////////////////////////  

    void defltobject_atom::resolve() {
        for (fieldsetting_atom_vct::iterator it = fieldsetting_.begin(); it != fieldsetting_.end(); ++it) {
        }
    };

    fieldsetting_atom_ptr defltobject_atom::find_field(const std::string& name) {
        for (fieldsetting_atom_vct::iterator it = fieldsetting_.begin(); it != fieldsetting_.end(); ++it) {
            if ((*it)->field() == name)
                return (*it);
        }
        return fieldsetting_atom_ptr();
    }




    /////////////////////////////////////////////////////////////////////////        
    // defsyntxobject_atom
    /////////////////////////////////////////////////////////////////////////  

    void defsyntxobject_atom::resolve() {
        for (fieldsetting_atom_vct::iterator it = fieldsetting_.begin(); it != fieldsetting_.end(); ++it) {
        }
    };

    fieldsetting_atom_ptr defsyntxobject_atom::find_field(const std::string& name) {
        for (fieldsetting_atom_vct::iterator it = fieldsetting_.begin(); it != fieldsetting_.end(); ++it) {
            if ((*it)->field() == name)
                return (*it);
        }
        return fieldsetting_atom_ptr();
    }

    bool defsyntxobject_atom::find_literal(const std::string& name) {
        for (fieldsetting_atom_vct::iterator it = fieldsetting_.begin(); it != fieldsetting_.end(); ++it) {
            if (!(*it)->setting()->literal().empty()) {
                if (name == (*it)->setting()->literal()) {
                    std::string tmpstr = name;
                    ++it;
                    while ((it != fieldsetting_.end()) && (tmpstr.find_first_of(' ') != std::string::npos)) {
                        ++it;
                        tmpstr = tmpstr.substr(tmpstr.find_first_of(' ') + 1);
                    }
                    fieldsetting_.erase(fieldsetting_.begin(), it);
                    return true;
                } else
                    return false;
            }
        }
        return false;
    }

    /////////////////////////////////////////////////////////////////////////     
    // fromobjectobject_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjectobject_atom::fromobjectobject_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj)
    : object_atom(scp, ot_FromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void fromobjectobject_atom::resolve() {
        if (object())
            object()->resolve();
    }


    /////////////////////////////////////////////////////////////////////////   
    // objectassignment_entity
    /////////////////////////////////////////////////////////////////////////    

    objectassignment_entity::objectassignment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr cls, object_atom_ptr obj) :
    assignment_entity(scope, nm, et_Object), class_(cls), object_(obj) {
    };

    basic_entity_ptr objectassignment_entity::find_by_name(const std::string& nm, bool all) {
        if (scope()) {
            prefind(nm, scope()->childs());
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it)
                if (nm == (*it)->name())
                    return *it;
        }
        if (scope())
            return scope()->find_by_name(nm, all);
        return basic_entity_ptr();
    }

    void objectassignment_entity::resolve() {
        assignment_entity::resolve();
        if (_class())
            _class()->resolve();
        if (object())
            object()->resolve();
        resolve_child();
    }

    void objectassignment_entity::apply_fields() {
        //if (!has_arguments()) {
        if (!((object()->as_deflt()) || (object()->as_defnsyntx())))
            return;
        _class()->resolve();
        basic_entity_ptr cl = _class()->reff();
        while (cl && (cl->as_classassigment()) && (cl->as_classassigment()->_class()) && (cl->as_classassigment()->_class()->reff())) {
            cl->as_classassigment()->_class()->resolve();
            cl = cl->as_classassigment()->_class()->reff();
        }
        if (cl && (cl->as_classassigment())) {
            if (object()->as_defnsyntx()) {
                calculate_fields(cl->as_classassigment(), object()->as_defnsyntx());
            }
            if (classassignment_entity * clsa = cl->as_classassigment()) {
                for (basic_entity_vector::iterator it = clsa->childs().begin(); it != clsa->childs().end(); ++it) {
                    if (fieldsetting_atom_ptr fnd = object()->find_field((*it)->as_classfield()->name())) {
                        create_fields((*it)->as_classfield(), fnd->setting().get());
                    } else {
                        switch (((*it)->as_classfield()->marker())) {
                            case mk_default:create_fields((*it)->as_classfield());
                                break;
                            case mk_optional: break;
                            default: referenceerror_throw((*it)->as_classfield()->name(), "Field sould be set: ");
                        }
                    }
                }
                for (basic_entity_vector::iterator it = clsa->childs().begin(); it != clsa->childs().end(); ++it) {
                    if (fieldsetting_atom_ptr fnd = object()->find_field((*it)->as_classfield()->name())) {
                        create_fields_var((*it)->as_classfield(), fnd->setting().get());
                    } else {
                        switch (((*it)->as_classfield()->marker())) {
                            case mk_default:create_fields_var((*it)->as_classfield());
                                break;
                            case mk_optional: break;
                            default: referenceerror_throw((*it)->as_classfield()->name(), "Field sould be set: ");
                        }
                    }
                }
            }
        }
    }

    void objectassignment_entity::calculate_fields(classassignment_entity*cls, defsyntxobject_atom* obj) {
        fieldsetting_atom_vct newvct;
        if (cls->withsyntax()) {
            calculate_fields(cls->withsyntax().get(), obj, newvct);
            obj->fieldsetting(newvct);
        }
    }

    bool objectassignment_entity::calculate_fields(syntax_atom* syn, defsyntxobject_atom* obj, fieldsetting_atom_vct& newvct, bool optional) {
        if (syn->as_group()) {
            if (syn->isalias()) {
                if (obj->find_literal(syn->alias())) {
                } else {
                    if ((!syn->optional()) && !optional)
                        referenceerror_throw(syn->alias(), "Fields object parsing error:");
                    else
                        return false;
                }
            }
            for (syntax_atom_vct::iterator it = syn->as_group()->group().begin(); it != syn->as_group()->group().end(); ++it) {
                if ((it == syn->as_group()->group().begin()) && syn->optional()) {
                    if (!calculate_fields((*it).get(), obj, newvct, syn->optional()))
                        return false;
                } else
                    calculate_fields((*it).get(), obj, newvct);
            }
            return true;
        } else {
            if (syn->isalias()) {
                if (obj->find_literal(syn->alias())) {
                    if (obj->fieldsetting().empty())
                        referenceerror_throw(syn->alias(), "Fields object parsing error:");
                    newvct.push_back(fieldsetting_atom_ptr(new fieldsetting_atom(object()->scope(), syn->reff()->name(), obj->fieldsetting().front()->setting())));
                    obj->fieldsetting().erase(obj->fieldsetting().begin());
                    return true;
                } else {
                    if ((!syn->optional()) && !optional)
                        referenceerror_throw(syn->alias(), "Fields object parsing error:");
                    else
                        return false;
                }
            } else {
                if (obj->fieldsetting().empty())
                    referenceerror_throw(syn->alias(), "Fields object parsing error:");
                newvct.push_back(fieldsetting_atom_ptr(new fieldsetting_atom(object()->scope(), syn->reff()->name(), obj->fieldsetting().front()->setting())));
                obj->fieldsetting().erase(obj->fieldsetting().begin());
                return true;
            }
        }
        return false;
    }

    void objectassignment_entity::create_fields(field_entity* fld, setting_atom* st) {
        if (st) {
            if (fld->as_typefield()) {
                if (st->type()) {
                    childs_.push_back(typeassignment_entity_ptr(new typeassignment_entity(st->scope(), fld->name(), st->type())));
                } else
                    referenceerror_throw(fld->name(), "Field is not type: ");
            } else if (fld->as_valuefield()) {
                if (st->value())
                    childs_.push_back(basic_entity_ptr(new valueassignment_entity(st->scope(), fld->name(), fld->as_valuefield()->type(), st->value())));
                else
                    referenceerror_throw(fld->name(), "Field is not value: ");
            } else if (fld->as_valuesetfield()) {
                if (st->valueset())
                    childs_.push_back(basic_entity_ptr(new valuesetassignment_entity(st->scope(), fld->name(), fld->as_valuesetfield()->type(), st->valueset())));
                else
                    referenceerror_throw(fld->name(), "Field is not valueset: ");
            } else if (fld->as_objectfield()) {
                if (st->object())
                    childs_.push_back(basic_entity_ptr(new objectassignment_entity(st->scope(), fld->name(), fld->as_objectfield()->_class(), st->object())));
                else
                    referenceerror_throw(fld->name(), "Field is not object: ");
            } else if (fld->as_objectsetfield()) {
                if (st->objectset())
                    childs_.push_back(basic_entity_ptr(new objectsetassignment_entity(st->scope(), fld->name(), fld->as_objectsetfield()->_class(), st->objectset())));
                else
                    referenceerror_throw(fld->name(), "Field is not objectset: ");
            }
        } else {
            if (fld->as_typefield()) {
                childs_.push_back(basic_entity_ptr(new typeassignment_entity(fld->scope(), fld->name(), fld->as_typefield()->_default())));
            } else if (fld->as_valuefield()) {
                childs_.push_back(basic_entity_ptr(new valueassignment_entity(fld->scope(), fld->name(), fld->as_valuefield()->type(), fld->as_valuefield()->_default())));
            } else if (fld->as_valuesetfield()) {
                childs_.push_back(basic_entity_ptr(new valuesetassignment_entity(fld->scope(), fld->name(), fld->as_valuesetfield()->type(), fld->as_valuesetfield()->_default())));
            } else if (fld->as_objectfield()) {
                childs_.push_back(basic_entity_ptr(new objectassignment_entity(fld->scope(), fld->name(), fld->as_objectfield()->_class(), fld->as_objectfield()->_default())));
            } else if (fld->as_objectsetfield()) {
                childs_.push_back(basic_entity_ptr(new objectsetassignment_entity(fld->scope(), fld->name(), fld->as_objectsetfield()->_class(), fld->as_objectsetfield()->_default())));
            }
        }
    }

    void objectassignment_entity::create_fields_var(field_entity* fld, setting_atom* st) {
        if (st) {
            if (fld->as_reffvaluefield()) {
                basic_entity_ptr fnd = find_typefields(fld->as_reffvaluefield()->field()->reff()->name());
                if ((st->value()) && (fnd)) {
                    type_atom_ptr tp = type_atom_ptr(new type_atom(st->scope(), fld->as_reffvaluefield()->field()->reff()->name(), t_Reference));
                    tp->reff(fnd);
                    childs_.push_back(basic_entity_ptr(new valueassignment_entity(st->scope(), fld->name(), tp, st->value())));
                } else
                    referenceerror_throw(fld->name(), "Field is not value: ");
            } else if (fld->as_reffvaluesetfield()) {
                basic_entity_ptr fnd = find_typefields(fld->as_reffvaluesetfield()->field()->reff()->name());
                if (st->valueset()) {
                    type_atom_ptr tp = type_atom_ptr(new type_atom(st->scope(), fld->as_reffvaluesetfield()->field()->reff()->name(), t_Reference));
                    tp->reff(fnd);
                    childs_.push_back(basic_entity_ptr(new valuesetassignment_entity(st->scope(), fld->name(), tp, st->valueset())));
                } else
                    referenceerror_throw(fld->name(), "Field is not valueset: ");
            }
        } else {
            if (fld->as_reffvaluefield()) {
                basic_entity_ptr fnd = find_typefields(fld->as_reffvaluefield()->field()->reff()->name());
                if (!fnd)
                    referenceerror_throw(fld->name(), "Field is not  refference to type: ");
                type_atom_ptr tp = type_atom_ptr(new type_atom(st->scope(), fld->as_reffvaluefield()->field()->reff()->name(), t_Reference));
                tp->reff(fnd);
                childs_.push_back(basic_entity_ptr(new valueassignment_entity(fld->scope(), fld->name(), tp, fld->as_reffvaluefield()->_default())));
            } else if (fld->as_reffvaluesetfield()) {
                basic_entity_ptr fnd = find_typefields(fld->as_reffvaluesetfield()->field()->reff()->name());
                if (!fnd)
                    referenceerror_throw(fld->name(), "Field is not  refference to type: ");
                type_atom_ptr tp = type_atom_ptr(new type_atom(st->scope(), fld->as_reffvaluesetfield()->field()->reff()->name(), t_Reference));
                tp->reff(fnd);
                childs_.push_back(basic_entity_ptr(new valuesetassignment_entity(fld->scope(), fld->name(), tp, fld->as_reffvaluesetfield()->_default())));
            }
        }
    }

    basic_entity_ptr objectassignment_entity::find_typefields(const std::string& nm) {
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if (((*it)->name() == nm) && ((*it)->as_typeassigment()))
                return (*it);
        return basic_entity_ptr();
    }



}
