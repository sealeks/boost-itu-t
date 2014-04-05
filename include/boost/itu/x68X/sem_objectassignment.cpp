//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>


namespace x680 {


    /////////////////////////////////////////////////////////////////////////   
    // OBJECT
    /////////////////////////////////////////////////////////////////////////       
    /////////////////////////////////////////////////////////////////////////   
    // object_atom
    /////////////////////////////////////////////////////////////////////////  

    object_atom::object_atom(object_type tp)
    : basic_atom(at_Object), builtin_(tp) {
    }

    object_atom::object_atom(basic_entity_ptr scope, object_type tp)
    : basic_atom(at_Object, scope), builtin_(tp) {
    }

    object_atom::object_atom(basic_entity_ptr scope, const std::string& reff, object_type tp)
    : basic_atom(at_Object, scope, reff), builtin_(tp) {
    }

    bool object_atom::isrefferrence() const {
        return (((builtin_ == ot_Refference)
                || (builtin_ == ot_FromObject)
                || (builtin_ == ot_DefinedObjectSet)
                || (builtin_ == ot_DefinedObjectSet)
                || (builtin_ == ot_ObjectSetFromObject)) && (reff()));
    }

    defined_object_atom_ptr object_atom::as_defined() {
        return builtin_ == ot_Refference ?
                boost::static_pointer_cast<defined_object_atom> (self()) : defined_object_atom_ptr();
    }

    definedobjects_object_atom_ptr object_atom::as_definedset() {
        return builtin_ == ot_DefinedObjectSet ?
                boost::static_pointer_cast<definedobjects_object_atom> (self()) : definedobjects_object_atom_ptr();
    }

    defltobject_atom_ptr object_atom::as_deflt() {
        return builtin_ == ot_Object ?
                boost::static_pointer_cast<defltobject_atom> (self()) : defltobject_atom_ptr();
    }

    defsyntax_object_atom_ptr object_atom::as_defnsyntx() {
        return builtin_ == ot_ObjectDefineSyn ?
                boost::static_pointer_cast<defsyntax_object_atom> (self()) : defsyntax_object_atom_ptr();
    }

    fromobject_object_atom_ptr object_atom::as_fromobject() {
        return builtin_ == ot_FromObject ?
                boost::static_pointer_cast<fromobject_object_atom> (self()) : fromobject_object_atom_ptr();
    }

    fromdefined_objects_object_atom_ptr object_atom::as_fromdefinedset() {
        return builtin_ == ot_ObjectSetFromObjects ?
                boost::static_pointer_cast<fromdefined_objects_object_atom> (self()) : fromdefined_objects_object_atom_ptr();
    }

    fromdefined_object_atom_ptr object_atom::as_fromdefined() {
        return builtin_ == ot_ObjectSetFromObject ?
                boost::static_pointer_cast<fromdefined_object_atom> (self()) : fromdefined_object_atom_ptr();
    }

    unionobject_atom_ptr object_atom::as_union() {
        return builtin_ == ot_UNION ?
                boost::static_pointer_cast<unionobject_atom> (self()) : unionobject_atom_ptr();
    }

    intersectionobject_atom_ptr object_atom::as_intersection() {
        return builtin_ == ot_INTERSECTION ?
                boost::static_pointer_cast<intersectionobject_atom> (self()) : intersectionobject_atom_ptr();
    }

    exceptobject_atom_ptr object_atom::as_except() {
        return builtin_ == ot_EXCEPT ?
                boost::static_pointer_cast<exceptobject_atom> (self()) : exceptobject_atom_ptr();
    }

    allobject_atom_ptr object_atom::as_all() {
        return builtin_ == ot_ALLEXCEPT ?
                boost::static_pointer_cast< allobject_atom> (self()) : allobject_atom_ptr();
    }

    extentionobject_atom_ptr object_atom::as_extention() {
        return builtin_ == ot_EXTENTION ?
                boost::static_pointer_cast<extentionobject_atom> (self()) : extentionobject_atom_ptr();
    }

    void object_atom::resolve(basic_atom_ptr holder) {
        if (builtin_ == ot_Refference)
            resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////        
    // defenedobject_atom
    /////////////////////////////////////////////////////////////////////////  

    void defined_object_atom::resolve(basic_atom_ptr holder) {
        // if (builtin() == ot_Refference)
        resolve_reff();
    };


    /////////////////////////////////////////////////////////////////////////        
    // definedobjects_object_atom
    /////////////////////////////////////////////////////////////////////////    

    definedobjects_object_atom::definedobjects_object_atom(basic_entity_ptr scope, objectset_atom_ptr objs) :
    object_atom(scope, ot_DefinedObjectSet), objectset_(objs) {
    };

    void definedobjects_object_atom::resolve(basic_atom_ptr holder) {
        if (objectset())
            objectset()->resolve();
    }


    /////////////////////////////////////////////////////////////////////////        
    // fromdefined_objects_object_atom
    /////////////////////////////////////////////////////////////////////////  

    fromdefined_objects_object_atom::fromdefined_objects_object_atom(basic_entity_ptr scope, const std::string& refffld, objectset_atom_ptr objs) :
    object_atom(scope, ot_ObjectSetFromObjects), objectset_(objs), field_(basic_atom_ptr(new basic_atom(at_Nodef, scope, refffld))) {

    }

    void fromdefined_objects_object_atom::resolve(basic_atom_ptr holder) {
        if (objectset())
            objectset()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////        
    // fromdefined_object_atom
    /////////////////////////////////////////////////////////////////////////  

    fromdefined_object_atom::fromdefined_object_atom(basic_entity_ptr scope, const std::string& refffld, object_atom_ptr obj) :
    object_atom(scope, ot_ObjectSetFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(scope, refffld))) {

    }

    void fromdefined_object_atom::resolve(basic_atom_ptr holder) {
        if (object())
            object()->resolve();
    }


    /////////////////////////////////////////////////////////////////////////        
    // defltobject_atom
    /////////////////////////////////////////////////////////////////////////  

    void defltobject_atom::resolve(basic_atom_ptr holder) {
        for (fieldsetting_atom_vct::iterator it = fieldsetting_.begin(); it != fieldsetting_.end(); ++it) {
        }
    };

    fieldsetting_atom_ptr defltobject_atom::find_field(const std::string& name) {
        for (fieldsetting_atom_vct::iterator it = fieldsetting_.begin(); it != fieldsetting_.end(); ++it)
            if ((*it)->field() == name)
                return (*it);
        return fieldsetting_atom_ptr();
    }




    /////////////////////////////////////////////////////////////////////////        
    // defsyntax_object_atom
    /////////////////////////////////////////////////////////////////////////  

    void defsyntax_object_atom::resolve(basic_atom_ptr holder) {
        for (fieldsetting_atom_vct::iterator it = fieldsetting_.begin(); it != fieldsetting_.end(); ++it) {
        }
    };

    fieldsetting_atom_ptr defsyntax_object_atom::find_field(const std::string& name) {
        for (fieldsetting_atom_vct::iterator it = fieldsetting_.begin(); it != fieldsetting_.end(); ++it)
            if ((*it)->field() == name)
                return (*it);
        return fieldsetting_atom_ptr();
    }

    bool defsyntax_object_atom::find_literal(const std::string& name) {
        std::string tmpl = "";
        for (fieldsetting_atom_vct::iterator it = fieldsetting_.begin(); it != fieldsetting_.end(); ++it) {
            if (!(*it)->setting()->literal().empty()) {
                tmpl += (*it)->setting()->literal();
                if ((name.size() >= tmpl.size())
                        && (name.substr(0, tmpl.size()) == tmpl)) {
                    if (name == tmpl) {
                        fieldsetting_.erase(fieldsetting_.begin(), ++it);
                        return true;
                    } else
                        tmpl += " ";
                } else
                    return false;
            } else
                return false;
        }
        return false;
    }

    /////////////////////////////////////////////////////////////////////////     
    // fromobject_object_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobject_object_atom::fromobject_object_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj)
    : object_atom(scp, ot_FromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {
    };

    void fromobject_object_atom::resolve(basic_atom_ptr holder) {
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
    // objectassignment_entity
    /////////////////////////////////////////////////////////////////////////    

    objectassignment_entity::objectassignment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr cls, object_atom_ptr obj) :
    assignment_entity(scope, nm, et_Object), class_(cls), object_(obj) {
    };

    basic_atom_ptr objectassignment_entity::typed_atom() const {
        return object();
    }

    object_atom_ptr objectassignment_entity::object() const {
        return object_;
    }

    basic_entity_ptr objectassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
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

    void objectassignment_entity::resolve(basic_atom_ptr holder) {
        assignment_entity::resolve(holder);
        if (_class())
            _class()->resolve();
        if (object())
            object()->resolve();
        assignment_entity::resolve_complex<objectassignment_entity>();
        resolve_child();
    }

    void objectassignment_entity::apply_fields() {
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
            if (classassignment_entity_ptr clsa = cl->as_classassigment()) {
                for (basic_entity_vector::iterator it = clsa->childs().begin(); it != clsa->childs().end(); ++it) {
                    if (!(((*it)->as_classfield()->as_reffvaluefield()) || ((*it)->as_classfield()->as_reffvaluesetfield()))) {
                        if (fieldsetting_atom_ptr fnd = object()->find_field((*it)->as_classfield()->name())) {
                            create_fields((*it)->as_classfield(), fnd->setting());
                        } else {
                            switch (((*it)->as_classfield()->marker())) {
                                case mk_default:create_fields((*it)->as_classfield());
                                    break;
                                case mk_optional: break;
                                default: referenceerror_throw("Field sould be set : ", (*it)->as_classfield()->name());
                            }
                        }
                    }
                }
                for (basic_entity_vector::iterator it = clsa->childs().begin(); it != clsa->childs().end(); ++it) {
                    if (((*it)->as_classfield()->as_reffvaluefield()) || ((*it)->as_classfield()->as_reffvaluesetfield())) {
                        if (fieldsetting_atom_ptr fnd = object()->find_field((*it)->as_classfield()->name())) {
                            create_fields_var((*it)->as_classfield(), fnd->setting());
                        } else {
                            switch (((*it)->as_classfield()->marker())) {
                                case mk_default:create_fields_var((*it)->as_classfield());
                                    break;
                                case mk_optional: break;
                                default: referenceerror_throw("Field sould be set : ", (*it)->as_classfield()->name());
                            }
                        }
                    }
                }
                for (basic_entity_vector::iterator it = clsa->childs().begin(); it != clsa->childs().end(); ++it) {
                    if (((*it)->as_classfield()->as_reffvaluefield()) || ((*it)->as_classfield()->as_reffvaluesetfield())) {
                        if ((*it)->as_classfield()->as_reffvaluefield()) {
                            find_typefields((*it)->as_classfield()->as_reffvaluefield());
                        } else {
                            find_typefields((*it)->as_classfield()->as_reffvaluesetfield());
                        }
                    }
                }
            }
        }
    }

    void objectassignment_entity::calculate_fields(classassignment_entity_ptr cls, defsyntax_object_atom_ptr obj) {
        fieldsetting_atom_vct newvct;
        if (cls->withsyntax()) {
            calculate_fields(cls->withsyntax(), obj, newvct);
            obj->fieldsetting(newvct);
        }
    }

    bool objectassignment_entity::calculate_fields(syntax_atom_ptr syn, defsyntax_object_atom_ptr obj, fieldsetting_atom_vct& newvct, bool optional) {
        if (syn->as_group()) {
            if (syn->isalias()) {
                if (obj->find_literal(syn->alias())) {
                } else {
                    if ((!syn->optional()) && !optional)
                        referenceerror_throw("Field object parsing error :", syn->alias());
                    else
                        return false;
                }
            }
            for (syntax_atom_vct::iterator it = syn->as_group()->group().begin(); it != syn->as_group()->group().end(); ++it) {
                if ((it == syn->as_group()->group().begin()) && syn->optional()) {
                    if (!calculate_fields((*it), obj, newvct, syn->optional()))
                        return false;
                } else
                    calculate_fields((*it), obj, newvct);
            }
            return true;
        } else {
            if (syn->isalias()) {
                if (obj->find_literal(syn->alias())) {
                    if (obj->fieldsetting().empty()) {
                        referenceerror_throw("Field object parsing error : ", syn->alias());
                    }
                    if (syn->reff()->name().empty())
                        return true;
                    newvct.push_back(fieldsetting_atom_ptr(new fieldsetting_atom(object()->scope(), syn->reff()->name(), obj->fieldsetting().front()->setting())));
                    obj->fieldsetting().erase(obj->fieldsetting().begin());
                    return true;
                } else {
                    if ((!syn->optional()) && !optional)
                        referenceerror_throw("Field object parsing error : ", syn->alias());
                    else
                        return false;
                }
            } else {
                if (obj->fieldsetting().empty())
                    referenceerror_throw("Field object parsing error : ", syn->alias());
                newvct.push_back(fieldsetting_atom_ptr(new fieldsetting_atom(object()->scope(), syn->reff()->name(), obj->fieldsetting().front()->setting())));
                obj->fieldsetting().erase(obj->fieldsetting().begin());
                return true;
            }
        }
        return false;
    }

    void objectassignment_entity::create_fields(field_entity_ptr fld, setting_atom_ptr st) {
        if (st) {
            if (fld->as_typefield()) {
                if (st->type()) {
                    childs_.push_back(typeassignment_entity_ptr(new typeassignment_entity(fld->scope(), fld->name(), st->type())));
                } else
                    referenceerror_throw("Field is not type : ", fld->name());
            } else if (fld->as_valuefield()) {
                if (st->value())
                    childs_.push_back(basic_entity_ptr(new valueassignment_entity(fld->scope(), fld->name(), fld->as_valuefield()->type(), st->value())));
                else
                    referenceerror_throw("Field is not value : ", fld->name());
            } else if (fld->as_valuesetfield()) {
                if (st->valueset())
                    childs_.push_back(basic_entity_ptr(new valuesetassignment_entity(fld->scope(), fld->name(), fld->as_valuesetfield()->type(), st->valueset())));
                else
                    referenceerror_throw("Field is not valueset : ", fld->name());
            } else if (fld->as_objectfield()) {
                if (st->object())
                    childs_.push_back(basic_entity_ptr(new objectassignment_entity(fld->scope(), fld->name(), fld->as_objectfield()->_class(), st->object())));
                else
                    referenceerror_throw("Field is not object : ", fld->name());
            } else if (fld->as_objectsetfield()) {
                if (st->objectset())
                    childs_.push_back(basic_entity_ptr(new objectsetassignment_entity(fld->scope(), fld->name(), fld->as_objectsetfield()->_class(), st->objectset())));
                else
                    referenceerror_throw("Field is not objectset : ", fld->name());
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

    void objectassignment_entity::create_fields_var(field_entity_ptr fld, setting_atom_ptr st) {
        if (st) {
            if (fld->as_reffvaluefield()) {
                if ((st->value())) {
                    type_atom_ptr tp = type_atom_ptr(new type_atom(fld->scope(), fld->as_reffvaluefield()->field()->reff()->name(), t_Reference));
                    childs_.push_back(basic_entity_ptr(new valueassignment_entity(fld->scope(), fld->name(), tp, st->value())));
                }
            } else if (fld->as_reffvaluesetfield()) {
                if (st->valueset()) {
                    type_atom_ptr tp = type_atom_ptr(new type_atom(fld->scope(), fld->as_reffvaluesetfield()->field()->reff()->name(), t_Reference));
                    childs_.push_back(basic_entity_ptr(new valuesetassignment_entity(fld->scope(), fld->name(), tp, st->valueset())));
                }
            }
        } else {
            if (fld->as_reffvaluefield()) {
                type_atom_ptr tp = type_atom_ptr(new type_atom(fld->scope(), fld->as_reffvaluefield()->field()->reff()->name(), t_Reference));
                childs_.push_back(basic_entity_ptr(new valueassignment_entity(fld->scope(), fld->name(), tp, fld->as_reffvaluefield()->_default())));
            } else if (fld->as_reffvaluesetfield()) {
                type_atom_ptr tp = type_atom_ptr(new type_atom(fld->scope(), fld->as_reffvaluesetfield()->field()->reff()->name(), t_Reference));
                childs_.push_back(basic_entity_ptr(new valuesetassignment_entity(fld->scope(), fld->name(), tp, fld->as_reffvaluesetfield()->_default())));
            }
        }
    }

    basic_entity_ptr objectassignment_entity::find_typefields(reffvaluefield_entity_ptr fld) {
        if ((fld->field()) && (fld->field()->reff())) {
            for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                if ((*it)->name() == (fld->name())) {
                    if ((*it)->as_valueassigment())
                        (*it)->as_valueassigment()->type()
                        ->reff(find_typefields((*it)->as_valueassigment()->type()->reff()->name()));
                    return basic_entity_ptr();
                }
            }
        }
        return basic_entity_ptr();
    }

    basic_entity_ptr objectassignment_entity::find_typefields(reffvaluesetfield_entity_ptr fld) {
        if ((fld->field()) && (fld->field()->reff())) {
            for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                if ((*it)->name() == (fld->field()->reff()->name())) {
                    if ((*it)->as_valuesetassigment())
                        (*it)->as_valuesetassigment()->type()
                        ->reff(find_typefields((*it)->as_valuesetassigment()->type()->reff()->name()));
                    return basic_entity_ptr();
                }
            }
        }
        return basic_entity_ptr();
    }

    basic_entity_ptr objectassignment_entity::find_typefields(const std::string& nm) {
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
            if (((*it)->name() == nm) && ((*it)->as_typeassigment())) {
                return (*it);
            }
            if (((*it)->name() == nm) && ((*it)->as_valueassigment()))
                return find_typefields((*it)->as_valueassigment()->type()->reff()->name());
            if (((*it)->name() == nm) && ((*it)->as_valuesetassigment()))
                return find_typefields((*it)->as_valuesetassigment()->type()->reff()->name());
        }
        referenceerror_throw("Field   refference error : ", nm);
        return basic_entity_ptr();
    }

    void objectassignment_entity::assign_from(assignment_entity_ptr from) {
        if (from->as_objectassigment()) {
            assignment_entity::assign_from(from);
            object_atom_ptr selftype = object_;
            object_ = from->as_objectassigment()->object_;
        }
    }


}
