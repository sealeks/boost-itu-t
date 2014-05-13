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

    objectassignment_entity_ptr object_atom::get_object(bool strict) {
        return objectassignment_entity_ptr();
    }

    objectassignment_entity_vct object_atom::get_objects(bool strict) {
        objectassignment_entity_ptr tmp = get_object(strict);
        if (tmp) {
            objectassignment_entity_vct tmpr;
            tmpr.push_back(tmp);
            return tmpr;
        }
        return objectassignment_entity_vct();
    }

    void object_atom::resolve(basic_atom_ptr holder) {
        if (builtin_ == ot_Refference)
            resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////        
    // defenedobject_atom
    /////////////////////////////////////////////////////////////////////////  

    objectassignment_entity_ptr defined_object_atom::get_object(bool strict) {
        if ((reff()) && (reff()->as_objectassigment())) {
            assignment_entity_ptr tmp = reff()->as_objectassigment()->refference_to();
            if (tmp->as_objectassigment())
                return tmp->as_objectassigment();
        }
        return objectassignment_entity_ptr();
    }

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

    objectassignment_entity_ptr definedobjects_object_atom::get_object(bool strict) {
        return objectassignment_entity_ptr();
    }

    objectassignment_entity_vct definedobjects_object_atom::get_objects(bool strict) {
        if (objectset_)
            return objectset_->get_objects(strict);
        return objectassignment_entity_vct();
    }

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

    objectassignment_entity_ptr fromdefined_objects_object_atom::get_object(bool strict) {
        return objectassignment_entity_ptr();
    }

    objectassignment_entity_vct fromdefined_objects_object_atom::get_objects(bool strict) {
        return calculate_objects(objectset_, field_, strict);
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

    objectassignment_entity_ptr fromdefined_object_atom::get_object(bool strict) {
        if (object_ && field_) {
            assignment_entity_ptr tmp = object_->find_component(field_->expectedname());
            if (tmp) {
                if ((tmp->as_objectassigment()) && (tmp->as_objectassigment()->object())) {
                    return tmp->as_objectassigment()->object()->get_object(strict);
                }
            }
        }
        return objectassignment_entity_ptr();
    }

    objectassignment_entity_vct fromdefined_object_atom::get_objects(bool strict) {
        return calculate_objects(object_, field_, strict);
    }

    void fromdefined_object_atom::resolve(basic_atom_ptr holder) {
        if (object())
            object()->resolve();
    }


    /////////////////////////////////////////////////////////////////////////        
    // defltobject_atom
    /////////////////////////////////////////////////////////////////////////  

    objectassignment_entity_ptr defltobject_atom::get_object(bool strict) {
        objectassignment_entity_ptr rt = ((scope()) && (scope()->as_objectassigment())) ?
                scope()->as_objectassigment() : objectassignment_entity_ptr();
        return rt ? rt : objectassignment_entity_ptr(new objectassignment_entity(scope(), "", class_atom_ptr(), self()->as_object()));
    }

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

    defsyntax_object_atom::defsyntax_object_atom(basic_entity_ptr scp, class_atom_ptr cls, fieldsetting_atom_vct fldst)
    : object_atom(scp, ot_ObjectDefineSyn), fieldsetting_(fldst) {
        embeded_assignment_ = objectassignment_entity_ptr(new objectassignment_entity(scp, "", cls, self()->as_object()));
    };

    void defsyntax_object_atom::_class(class_atom_ptr cls) {
        embeded_assignment_ = objectassignment_entity_ptr(new objectassignment_entity(scope(), "", cls, self()->as_object()));
    }

    objectassignment_entity_ptr defsyntax_object_atom::get_object(bool strict) {
        objectassignment_entity_ptr rt = ((scope()) && (scope()->as_objectassigment())) ?
                scope()->as_objectassigment() : objectassignment_entity_ptr();
        return rt ? rt : objectassignment_entity_ptr(new objectassignment_entity(scope(), "", class_atom_ptr(), self()->as_object()));
    }

    void defsyntax_object_atom::resolve(basic_atom_ptr holder) {
        if (embeded_assignment_ && (embeded_assignment_->as_objectassigment()) && !yetresolved_) {
            yetresolved_ = true;
            embeded_assignment_->as_objectassigment()->preresolve();
            embeded_assignment_->as_objectassigment()->apply_fields();
            embeded_assignment_->as_objectassigment()->resolve(holder);
        }
    };

    fieldsetting_atom_ptr defsyntax_object_atom::find_field(const std::string& name) {
        for (fieldsetting_atom_vct::iterator it = fieldsetting_.begin(); it != fieldsetting_.end(); ++it)
            if ((*it)->field() == name)
                return (*it);
        return fieldsetting_atom_ptr();
    }

    bool static find_literal_static(fieldsetting_atom_vct& vl, const std::string& name) {
        std::string tmpl = "";
        while ((!vl.empty()) && !(vl.front()->setting()->mask() & AS_LITERAL)) {
            vl.erase(vl.begin());
        }
        for (fieldsetting_atom_vct::iterator it = vl.begin(); it != vl.end(); ++it) {
            if (!(*it)->setting()->literal().empty()) {
                tmpl += (*it)->setting()->literal();
                if ((name.size() >= tmpl.size())
                        && (name.substr(0, tmpl.size()) == tmpl)) {
                    if (name == tmpl) {
                        vl.erase(vl.begin(), ++it);
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

    bool defsyntax_object_atom::find_literal(const std::string& name) {
        /*fieldsetting_atom_vct&  tmp = fieldsetting_;
        if (!find_literal_static(tmp, name))
            return false;*/
        return find_literal_static(fieldsetting_, name);
    }

    /////////////////////////////////////////////////////////////////////////     
    // fromobject_object_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobject_object_atom::fromobject_object_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj)
    : object_atom(scp, ot_FromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {
    };

    objectassignment_entity_ptr fromobject_object_atom::get_object(bool strict) {
        if (object_ && field_) {
            assignment_entity_ptr tmp = object_->find_component(field_->expectedname());
            if (tmp) {
                if ((tmp->as_objectassigment()) && (tmp->as_objectassigment()->object())) {
                    return tmp->as_objectassigment()->object()->get_object(strict);
                }
            }
        }
        return objectassignment_entity_ptr();
    }

    objectassignment_entity_vct fromobject_object_atom::get_objects(bool strict) {
        return calculate_objects(object_, field_, strict);
    }

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

    basic_atom_ptr objectassignment_entity::atom() const {
        return object_;
    }
    
    bool operator<(const objectassignment_entity& l , const objectassignment_entity& r) {
        if ((!r.name().empty()) || (!l.name().empty()))
            return l.name() < r.name();
        if ((l.object_) && (r.object_))
            return l.object_.get() < r.object_.get();
        return false;
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

    void objectassignment_entity::after_resolve() {

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
                calculate_fields((*it), obj, newvct, (*it)->optional());
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
                    if ((!syn->optional()) && !optional) {
                        /*if (!obj->fieldsetting().empty()) {
                            if (obj->fieldsetting().front()->setting()->mask() & AS_LITERAL)
                                std::cout << "is letral = " << obj->fieldsetting().front()->setting()->literal() << " for alias " 
                                        << syn->alias() << " sc " << syn->scope()->name() <<  " mod = " <<  (syn->moduleref() ? syn->moduleref()->name() : "" ) << std::endl;
                            else
                                std::cout << "not letral!!!!!! " << std::endl;
                            for (fieldsetting_atom_vct::iterator tit = obj->fieldsetting().begin(); tit != obj->fieldsetting().end(); ++tit){
                                if ((*tit)->setting()->mask() & AS_LITERAL)
                                    std::cout << "'" << (*tit)->setting()->literal() << "'" << std::endl;
                                else
                                    std::cout << "&sett&" << std::endl;                                                              
                            }
                            obj->fieldsetting().erase(obj->fieldsetting().begin());
                            if (!obj->fieldsetting().empty())
                                return calculate_fields(syn, obj, newvct, optional);
                        }*/
                        referenceerror_throw("Field object parsing error : ", syn->alias());
                    } else
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
                if (st->typeassignment()) {
                    st->typeassignment()->name(fld->name());
                    childs_.push_back(st->typeassignment());
                    childs_.back()->preresolve();
                    //childs_.back()->resolve();
                } else
                    referenceerror_throw("Field is not type : ", fld->name());
            } else if (fld->as_valuefield()) {
                if (st->value()) {
                    childs_.push_back(basic_entity_ptr(new valueassignment_entity(self(), fld->name(), fld->as_valuefield()->type(), st->value())));
                    childs_.back()->preresolve();
                } else
                    referenceerror_throw("Field is not value : ", fld->name());
            } else if (fld->as_valuesetfield()) {
                if (st->valueset()) {
                    childs_.push_back(basic_entity_ptr(new valuesetassignment_entity(self(), fld->name(), fld->as_valuesetfield()->type(), st->valueset())));
                    childs_.back()->preresolve();
                } else
                    referenceerror_throw("Field is not valueset : ", fld->name());
            } else if (fld->as_objectfield()) {
                if (st->object()) {
                    childs_.push_back(basic_entity_ptr(new objectassignment_entity(self(), fld->name(), fld->as_objectfield()->_class(), st->object())));
                    childs_.back()->preresolve();
                    childs_.back()->as_objectassigment()->apply_fields();
                } else
                    referenceerror_throw("Field is not object : ", fld->name());
            } else if (fld->as_objectsetfield()) {
                if (st->objectset()) {
                    childs_.push_back(basic_entity_ptr(new objectsetassignment_entity(self(), fld->name(), fld->as_objectsetfield()->_class(), st->objectset())));
                    if (childs_.back()->as_objectsetassigment()->objectset()) {
                        objectset_atom_ptr tmpobjs = childs_.back()->as_objectsetassigment()->objectset();
                        if (tmpobjs->as_defn()) {
                            for (object_atom_vct::iterator it = tmpobjs->as_defn()->objects().begin(); it != tmpobjs->as_defn()->objects().end(); ++it) {
                                if ((*it) && ((*it)->as_defnsyntx())) {
                                    (*it)->as_defnsyntx()->_class(fld->as_objectsetfield()->_class());
                                }
                            }
                        }
                    }
                    childs_.back()->preresolve();
                } else
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
            if (((*it)->name() == nm) && ((*it)->as_valueassigment())
                    && ((*it)->as_valueassigment()->type()) && ((*it)->as_valueassigment()->type()->reff()))
                return find_typefields((*it)->as_valueassigment()->type()->reff()->name());
            if (((*it)->name() == nm) && ((*it)->as_valuesetassigment())
                    && ((*it)->as_valuesetassigment()->type()) && ((*it)->as_valuesetassigment()->type()->reff()))
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
