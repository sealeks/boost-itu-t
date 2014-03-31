//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>


namespace x680 {



    /////////////////////////////////////////////////////////////////////////   
    // VALUESET
    /////////////////////////////////////////////////////////////////////////   
    // valueset_atom
    /////////////////////////////////////////////////////////////////////////  

    valueset_atom::valueset_atom(basic_entity_ptr scope, valueset_type tp)
    : basic_atom(at_ValueSet, scope), builtin_(tp) {
    }

    valueset_atom::valueset_atom(basic_entity_ptr scope, const std::string& reff, valueset_type tp)
    : basic_atom(at_ValueSet, scope, reff), builtin_(tp) {
    }

    fromobject_valueset_atom_ptr valueset_atom::as_fromobject() {
        return builtin_ == vs_ValueSetFromObject ?
                boost::static_pointer_cast<fromobject_valueset_atom> (self()) : fromobject_valueset_atom_ptr();
    }

    bool valueset_atom::isrefferrence() const {
        return (((builtin_ == vs_defined)
                || (builtin_ == vs_ValueSetFromObjects)
                || (builtin_ == vs_ValueSetFromObject)) && (reff()));
    }

    fromobjects_valueset_atom_ptr valueset_atom::as_fromobjectset() {
        return builtin_ == vs_ValueSetFromObjects ?
                boost::static_pointer_cast<fromobjects_valueset_atom> (self()) : fromobjects_valueset_atom_ptr();
    }

    void valueset_atom::resolve(basic_atom_ptr holder) {
        if (builtin_ != vs_Strait)
            resolve_reff();
        if (set())
            set()->resolve();

    }


    /////////////////////////////////////////////////////////////////////////   
    // fromobject_valueset_atom
    /////////////////////////////////////////////////////////////////////////        

    fromobject_valueset_atom::fromobject_valueset_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj) :
    valueset_atom(scp, vs_ValueSetFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {
    };

    void fromobject_valueset_atom::resolve(basic_atom_ptr holder) {
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
    // fromobjects_valueset_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjects_valueset_atom::fromobjects_valueset_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj) :
    valueset_atom(scp, vs_ValueSetFromObjects), objectset_(obj), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {
    };

    void fromobjects_valueset_atom::resolve(basic_atom_ptr holder) {
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
    // constraints_atom
    /////////////////////////////////////////////////////////////////////////

    static void resolve_tsvo(constraint_atom_vct& vl) {
        for (constraint_atom_vct::iterator it = vl.begin(); it != vl.end(); ++it) {
            if ((*it)->as_tvoso()) {
                if ((*it)->as_tvoso()->type())
                    (*it) = typeconstraint_atom_ptr(new typeconstraint_atom((*it)->as_tvoso()->scope(), cns_ContainedSubtype, (*it)->as_tvoso()->type(), false));
                else if ((*it)->as_tvoso()->objectset())
                    (*it) = tableconstraint_atom_ptr(new tableconstraint_atom((*it)->as_tvoso()->scope(), (*it)->as_tvoso()->objectset()));
                //else if ((*it)->as_tvoso()->valueset()))
                //(*it) =tableconstraint_atom_ptr( new tableconstraint_atom((*it)->as_tvoso()->scope()(*it)->as_tvoso()->objectset()));                
            } /*else if (((*it)->as_complex()) && ((*it)->as_complex()->constraints()))
                resolve_tsvo(*((*it)->as_complex()->constraints()));*/
        }
    }

    static void resolve_tsvo(constraints_atom& vl) {
        resolve_tsvo(vl.constraintline());
        resolve_tsvo(vl.extendline());
    }

    void constraints_atom::resolve(basic_atom_ptr holder) {
        for (constraint_atom_vct::iterator it = constraintline_.begin(); it != constraintline_.end(); ++it) {
            if (*it)
                (*it)->resolve();
        }
        for (constraint_atom_vct::iterator it = extendline_.begin(); it != extendline_.end(); ++it)
            if (*it)
                (*it)->resolve();
        resolve_tsvo(*this);
    }

    /////////////////////////////////////////////////////////////////////////   
    //constraint_atom
    /////////////////////////////////////////////////////////////////////////       

    constraint_atom::constraint_atom(constraint_type tpv)
    : basic_atom(at_Constraint), cotstrtype_(tpv) {
    }

    constraint_atom::constraint_atom(basic_entity_ptr scp, constraint_type tpv)
    : basic_atom(at_Constraint, scp), cotstrtype_(tpv) {
    }

    constraint_atom::constraint_atom(basic_entity_ptr scp, const std::string& reff, constraint_type tpv)
    : basic_atom(at_Constraint, scp, reff), cotstrtype_(tpv) {
    }

    valueconstraint_atom_ptr constraint_atom::as_valueconstraint() {
        return cotstrtype_ == cns_SingleValue ?
                boost::static_pointer_cast<valueconstraint_atom> (self()) : valueconstraint_atom_ptr();
    }

    fromdefined_objects_constraint_atom_ptr constraint_atom::as_fromdefinedset() {
        return cotstrtype_ == cns_ValueSetFromObjects ?
                boost::static_pointer_cast<fromdefined_objects_constraint_atom> (self()) : fromdefined_objects_constraint_atom_ptr();
    }

    fromdefined_constraint_atom_ptr constraint_atom::as_fromdefined() {
        return cotstrtype_ == cns_ValueSetFromObject ?
                boost::static_pointer_cast<fromdefined_constraint_atom> (self()) : fromdefined_constraint_atom_ptr();
    }

    valueconstraint_atom_ptr constraint_atom::as_pattern() {
        return cotstrtype_ == cns_PatternConstraint ?
                boost::static_pointer_cast<valueconstraint_atom> (self()) : valueconstraint_atom_ptr();
    }

    typeconstraint_atom_ptr constraint_atom::as_subtypeconstraint() {
        return ((cotstrtype_ == cns_ContainedSubtype) || (cotstrtype_ == cns_TypeConstraint )) ?
                boost::static_pointer_cast<typeconstraint_atom> (self()) : typeconstraint_atom_ptr();
    };

    typeconstraint_atom_ptr constraint_atom::as_typeconstraint() {
        return ((cotstrtype_ == cns_ContainedSubtype) || (cotstrtype_ == cns_TypeConstraint )) ?
                boost::static_pointer_cast<typeconstraint_atom> (self()) : typeconstraint_atom_ptr();
    };

    rangeconstraint_atom_ptr constraint_atom::as_range() {
        return cotstrtype_ == cns_ValueRange ?
                boost::static_pointer_cast<rangeconstraint_atom> (self()) : rangeconstraint_atom_ptr();
    }

    rangeconstraint_atom_ptr constraint_atom::as_strictrange() {
        return ((cotstrtype_ == cns_ValueRange) || (cotstrtype_ == cns_DurationRange) ||
                (cotstrtype_ == cns_TimePointRange) || (cotstrtype_ == cns_RecurrenceRange)) ?
                boost::static_pointer_cast<rangeconstraint_atom> (self()) : rangeconstraint_atom_ptr();
    };

    rangeconstraint_atom_ptr constraint_atom::as_duration() {
        return cotstrtype_ == cns_DurationRange ?
                boost::static_pointer_cast<rangeconstraint_atom> (self()) : rangeconstraint_atom_ptr();
    };

    rangeconstraint_atom_ptr constraint_atom::as_timepoint() {
        return cotstrtype_ == cns_TimePointRange ?
                boost::static_pointer_cast<rangeconstraint_atom> (self()) : rangeconstraint_atom_ptr();
    };

    rangeconstraint_atom_ptr constraint_atom::as_reccurence() {
        return cotstrtype_ == cns_RecurrenceRange ?
                boost::static_pointer_cast<rangeconstraint_atom> (self()) : rangeconstraint_atom_ptr();
    };

    complexconstraint_atom_ptr constraint_atom::as_complex() {
        return cotstrtype_ == cns_SingleTypeConstraint ?
                boost::static_pointer_cast<complexconstraint_atom> (self()) : complexconstraint_atom_ptr();
    }

    complexconstraint_atom_ptr constraint_atom::as_size() {
        return cotstrtype_ == cns_SizeConstraint ?
                boost::static_pointer_cast<complexconstraint_atom> (self()) : complexconstraint_atom_ptr();
    };

    complexconstraint_atom_ptr constraint_atom::as_permitted() {
        return cotstrtype_ == cns_PermittedAlphabet ?
                boost::static_pointer_cast<complexconstraint_atom> (self()) : complexconstraint_atom_ptr();
    };

    complexconstraint_atom_ptr constraint_atom::as_singletype() {
        return cotstrtype_ == cns_SingleTypeConstraint ?
                boost::static_pointer_cast<complexconstraint_atom> (self()) : complexconstraint_atom_ptr();
    };

    namedconstraint_atom_ptr constraint_atom::as_named() {
        return cotstrtype_ == cns_NamedConstraint ?
                boost::static_pointer_cast<namedconstraint_atom> (self()) : namedconstraint_atom_ptr();
    }

    multipletypeconstraint_atom_ptr constraint_atom::as_multipletypeconstraint() {
        return cotstrtype_ == cns_MultipleTypeConstraints ?
                boost::static_pointer_cast<multipletypeconstraint_atom > (self()) : multipletypeconstraint_atom_ptr();
    }

    stringconstraint_atom_ptr constraint_atom::as_property() {
        return cotstrtype_ == cns_PropertySettings ?
                boost::static_pointer_cast<stringconstraint_atom > (self()) : stringconstraint_atom_ptr();
    }

    userconstraint_atom_ptr constraint_atom::as_user() {
        return cotstrtype_ == cns_UserDefinedConstraint ?
                boost::static_pointer_cast<userconstraint_atom> (self()) : userconstraint_atom_ptr();
    }

    contentconstraint_atom_ptr constraint_atom::as_content() {
        return cotstrtype_ == cns_Contents ?
                boost::static_pointer_cast<contentconstraint_atom> (self()) : contentconstraint_atom_ptr();
    }

    relationconstraint_atom_ptr constraint_atom::as_relation() {
        return cotstrtype_ == cns_ComponentRelation ?
                boost::static_pointer_cast<relationconstraint_atom> (self()) : relationconstraint_atom_ptr();
    }

    tableconstraint_atom_ptr constraint_atom::as_table() {
        return cotstrtype_ == cns_SimpleTableConstraint ?
                boost::static_pointer_cast<tableconstraint_atom> (self()) : tableconstraint_atom_ptr();
    }

    tvosoconstraint_atom_ptr constraint_atom::as_tvoso() {
        return cotstrtype_ == cns_Undef_T_ST_VS ?
                boost::static_pointer_cast<tvosoconstraint_atom> (self()) : tvosoconstraint_atom_ptr();
    }

    unionconstraint_atom_ptr constraint_atom::as_union() {
        return cotstrtype_ == cns_UNION ?
                boost::static_pointer_cast<unionconstraint_atom> (self()) : unionconstraint_atom_ptr();
    }

    intersectionconstraint_atom_ptr constraint_atom::as_intersection() {
        return cotstrtype_ == cns_INTERSECTION ?
                boost::static_pointer_cast<intersectionconstraint_atom> (self()) : intersectionconstraint_atom_ptr();
    }

    exceptconstraint_atom_ptr constraint_atom::as_except() {
        return cotstrtype_ == cns_EXCEPT ?
                boost::static_pointer_cast<exceptconstraint_atom> (self()) : exceptconstraint_atom_ptr();
    }

    allconstraint_atom_ptr constraint_atom::as_all() {
        return cotstrtype_ == cns_ALLEXCEPT ?
                boost::static_pointer_cast<allconstraint_atom> (self()) : allconstraint_atom_ptr();
    }

    extentionconstraint_atom_ptr constraint_atom::as_extention() {
        return cotstrtype_ == cns_EXTENTION ?
                boost::static_pointer_cast<extentionconstraint_atom> (self()) : extentionconstraint_atom_ptr();
    }

    exceptionconstraint_atom_ptr constraint_atom::as_exception() {
        return cotstrtype_ == cns_EXCEPTION ?
                boost::static_pointer_cast<exceptionconstraint_atom> (self()) : exceptionconstraint_atom_ptr();
    }

    /////////////////////////////////////////////////////////////////////////   
    // valueconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    void valueconstraint_atom::resolve(basic_atom_ptr holder) {
        if (value_)
            value_->resolve_reff();
    }



    /////////////////////////////////////////////////////////////////////////        
    // fromdefined_objects_constraint_atom
    /////////////////////////////////////////////////////////////////////////  

    fromdefined_objects_constraint_atom::fromdefined_objects_constraint_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr objs) :
    constraint_atom(scp, cns_ValueSetFromObjects), objectset_(objs), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {

    }

    void fromdefined_objects_constraint_atom::resolve(basic_atom_ptr holder) {
        if (objectset())
            objectset()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////        
    // fromdefined_constraint_atom
    /////////////////////////////////////////////////////////////////////////  

    fromdefined_constraint_atom::fromdefined_constraint_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj) :
    constraint_atom(scp, cns_ValueSetFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {

    }

    void fromdefined_constraint_atom::resolve(basic_atom_ptr holder) {
        if (object())
            object()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    // typeconstraint_atom
    /////////////////////////////////////////////////////////////////////////

    void typeconstraint_atom::resolve(basic_atom_ptr holder) {
        if (type_)
            type_->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    // rangeconstraint_atom
    /////////////////////////////////////////////////////////////////////////   

    rangeconstraint_atom::rangeconstraint_atom(basic_entity_ptr scp, constraint_type tpc, value_atom_ptr fr, range_type frtp, value_atom_ptr to, range_type totp) :
    constraint_atom(scp, tpc), from_(fr), fromtype_(frtp), to_(to), totype_(totp) {
    };

    void rangeconstraint_atom::resolve(basic_atom_ptr holder) {
        if (from_)
            from_->resolve_reff();
        if (to_)
            to_->resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////   
    // namedconstraint_atom
    ///////////////////////////////////////////////////////////////////////// 

    void namedconstraint_atom::resolve(basic_atom_ptr holder) {
        if (constraints_)
            constraints_->resolve();
    }


    /////////////////////////////////////////////////////////////////////////   
    // multipletypeconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    bool multipletypeconstraint_atom::full() const {
        return ((!components_.empty()) &&
                (components_.front()) &&
                (!components_.front()->as_extention()));
    }

    void multipletypeconstraint_atom::resolve(basic_atom_ptr holder) {
        for (constraint_atom_vct::iterator it = components_.begin(); it != components_.end(); ++it)
            if (*it)
                (*it)->resolve();
    }


    /////////////////////////////////////////////////////////////////////////   
    // complexconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    void complexconstraint_atom::resolve(basic_atom_ptr holder) {
        if (constraints_)
            constraints_->resolve(holder);
    }


    /////////////////////////////////////////////////////////////////////////   
    // exceptionconstraint_atom
    /////////////////////////////////////////////////////////////////////////    

    void exceptionconstraint_atom::resolve(basic_atom_ptr holder) {
        if (type())
            type()->resolve();
        if (value())
            value()->resolve(type());
    }


    /////////////////////////////////////////////////////////////////////////   
    // userconstraint_atom
    /////////////////////////////////////////////////////////////////////////    

    void userconstraint_atom::resolve(basic_atom_ptr holder) {
        for (uargument_entity_vct::const_iterator it = arguments_.begin(); it != arguments_.end(); ++it) {
            if ((*it)->has_undef_governor()) {
                if (!(*it)->governor()->reff())
                    scope()->referenceerror_throw("User constraint error : ", scope()->name());
                basic_entity_ptr fnd = scope()->find((*it)->governor()->reff());
                if (fnd) {
                    if (fnd->kind() == et_Type) {
                        (*it)->governor(type_atom_ptr(new type_atom((*it)->scope(), (*it)->governor()->expectedname(), t_Reference)));
                    } else if (fnd->kind() == et_Class) {
                        (*it)->governor(class_atom_ptr(new class_atom((*it)->scope(), (*it)->governor()->expectedname(), cl_Reference)));
                    } else
                        scope()->referenceerror_throw("User constraint error : ", (*it)->governor()->expectedname());
                } else
                    scope()->referenceerror_throw("User constraint error : ", scope()->name());
            }
        }
    }


    /////////////////////////////////////////////////////////////////////////   
    // contentconstraint_atom
    /////////////////////////////////////////////////////////////////////////    

    void contentconstraint_atom::resolve(basic_atom_ptr holder) {
        if (type())
            type()->resolve();
        if (value())
            value()->resolve();
    }


    /////////////////////////////////////////////////////////////////////////   
    // relationconstraint_atom
    /////////////////////////////////////////////////////////////////////////    

    void relationconstraint_atom::resolve(basic_atom_ptr holder) {
        if (objectset())
            objectset()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    // tableconstraint_atom
    /////////////////////////////////////////////////////////////////////////    

    void tableconstraint_atom::resolve(basic_atom_ptr holder) {
        if (objectset())
            objectset()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    // tvosoconstraint_atom
    /////////////////////////////////////////////////////////////////////////    

    tvosoconstraint_atom::tvosoconstraint_atom(basic_entity_ptr scp, const std::string& reff)
    : constraint_atom(scp, cns_Undef_T_ST_VS),
    tp_(argm_Nodef) {
    }

    void tvosoconstraint_atom::resolve(basic_atom_ptr holder) {
        if (type() && (type()->reff())) {
            basic_entity_ptr fnd = type()->scope()->find(type()->reff());
            if (fnd)
                if (fnd && ((fnd->as_typeassigment())
                        || (fnd->as_argument()))) {
                    if ((fnd->as_typeassigment()) || ((fnd->as_argument()->argumenttype() == argm_Nodef)
                            || (fnd->as_argument()->argumenttype() == argm_Type))) {
                        tp_ = argm_Type;
                        if (objectset_)
                            objectset_.reset();
                        if (valueset_)
                            valueset_.reset();
                        type()->resolve();
                        return;
                    }
                }
        }
        if (valueset() && (valueset()->reff())) {
            basic_entity_ptr fnd = valueset()->scope()->find(valueset()->reff());
            if (fnd && ((fnd->as_valuesetassigment()) || (fnd->as_argument()))) {
                if ((fnd->as_valuesetassigment()) || (fnd->as_argument()->argumenttype() == argm_ValueSet)) {
                    tp_ = argm_ValueSet;
                    if (objectset_)
                        objectset_.reset();
                    if (type_)
                        type_.reset();
                    valueset()->resolve();
                    return;
                }
            }
        }
        if (objectset() && (objectset()->reff())) {
            basic_entity_ptr fnd = objectset()->scope()->find(objectset()->reff());
            if (fnd && ((fnd->as_objectsetassigment()) || (fnd->as_argument()))) {
                if ((fnd->as_objectsetassigment()) || (fnd->as_argument()->argumenttype() == argm_ObjectSet)) {
                    tp_ = argm_ObjectSet;
                    if (valueset_)
                        valueset_.reset();
                    if (type_)
                        type_.reset();
                    objectset()->resolve();
                    return;
                }
            }
        }
        scope()->referenceerror_throw("Unresoved constraint : ", scope()->name());
    }

    /////////////////////////////////////////////////////////////////////////   
    // valuesetassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    valuesetassignment_entity::valuesetassignment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, valueset_atom_ptr vl) :
    assignment_entity(scope, nm, et_ValueSet), type_(tp), valueset_(vl) {
    };

    valueset_atom_ptr valuesetassignment_entity::valueset() const {
        return valueset_;
    }

    basic_entity_ptr valuesetassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        if (sch & local_search) {
            if (((type()->predefined()))) {
                for (basic_entity_vector::iterator it = type()->predefined()->values().begin(); it != type()->predefined()->values().end(); ++it)
                    if ((*it)->name() == nm)
                        return *it;
            }
            if ((type()->reff() && (type()->reff()->name() != nm))) {
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

    void valuesetassignment_entity::resolve(basic_atom_ptr holder) {
        assignment_entity::resolve(holder);
        resolve_child();
        type()->resolve();
        if (valueset())
            valueset()->resolve(type());
    }


}
