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
    : basic_atom(scope), builtin_(tp) {
    }

    valueset_atom::valueset_atom(basic_entity_ptr scope, const std::string& reff, valueset_type tp)
    : basic_atom(reff, scope), builtin_(tp) {
    }

    fromobjectvalueset_atom* valueset_atom::as_fromobject() {
        return dynamic_cast<fromobjectvalueset_atom*> (this);
    }

    fromobjectsetvalueset_atom* valueset_atom::as_fromobjectset() {
        return dynamic_cast<fromobjectsetvalueset_atom*> (this);
    }

    void valueset_atom::resolve() {
        if (builtin_ != vs_Strait)
            resolve_reff();
        if (set())
            set()->resolve();

    }


    /////////////////////////////////////////////////////////////////////////   
    // fromobjectvalueset_atom
    /////////////////////////////////////////////////////////////////////////        

    fromobjectvalueset_atom::fromobjectvalueset_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj) :
    valueset_atom(scp, vs_ValueSetFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void fromobjectvalueset_atom::resolve() {
        if (object())
            object()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    // fromobjectsetvalueset_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjectsetvalueset_atom::fromobjectsetvalueset_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj) :
    valueset_atom(scp, vs_ValueSetFromObjects), objectset_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void fromobjectsetvalueset_atom::resolve() {
        if (objectset())
            objectset()->resolve();
    }


    /////////////////////////////////////////////////////////////////////////   
    // constraints_atom
    /////////////////////////////////////////////////////////////////////////

    void constraints_atom::resolve() {
        for (constraint_atom_vct::iterator it = constraintline_.begin(); it != constraintline_.end(); ++it)
            if (*it)
                (*it)->resolve();
        for (constraint_atom_vct::iterator it = extendline_.begin(); it != extendline_.end(); ++it)
            if (*it)
                (*it)->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    //constraint_atom
    /////////////////////////////////////////////////////////////////////////       

    constraint_atom::constraint_atom(constraint_type tpv)
    : basic_atom(), cotstrtype_(tpv) {
    }

    constraint_atom::constraint_atom(basic_entity_ptr scp, constraint_type tpv)
    : basic_atom(scp), cotstrtype_(tpv) {
    }

    constraint_atom::constraint_atom(basic_entity_ptr scp, const std::string& reff, constraint_type tpv)
    : basic_atom(reff, scp), cotstrtype_(tpv) {
    }

    valueconstraint_atom* constraint_atom::as_valueconstraint() {
        return cotstrtype_ == cns_SingleValue ? dynamic_cast<valueconstraint_atom*> (this) : 0;
    }

    fromdefinedsetconstraint_atom* constraint_atom::as_fromdefinedset() {
        return cotstrtype_ == cns_ValueSetFromObjects ? dynamic_cast<fromdefinedsetconstraint_atom*> (this) : 0;
    }

    fromdefinedconstraint_atom* constraint_atom::as_fromdefined() {
        return cotstrtype_ == cns_ValueSetFromObject ? dynamic_cast<fromdefinedconstraint_atom*> (this) : 0;
    }

    valueconstraint_atom* constraint_atom::as_pattern() {
        return cotstrtype_ == cns_PatternConstraint ? dynamic_cast<valueconstraint_atom*> (this) : 0;
    }

    typeconstraint_atom* constraint_atom::as_subtypeconstraint() {
        return cotstrtype_ == cns_ContainedSubtype ? dynamic_cast<typeconstraint_atom*> (this) : 0;
    };

    typeconstraint_atom* constraint_atom::as_typeconstraint() {
        return cotstrtype_ == cns_TypeConstraint ? dynamic_cast<typeconstraint_atom*> (this) : 0;
    };

    rangeconstraint_atom* constraint_atom::as_range() {
        return dynamic_cast<rangeconstraint_atom*> (this);
    }

    rangeconstraint_atom*constraint_atom::as_strictrange() {
        return cotstrtype_ == cns_ValueRange ? dynamic_cast<rangeconstraint_atom*> (this) : 0;
    };

    rangeconstraint_atom* constraint_atom::as_duration() {
        return cotstrtype_ == cns_DurationRange ? dynamic_cast<rangeconstraint_atom*> (this) : 0;
    };

    rangeconstraint_atom* constraint_atom::as_timepoint() {
        return cotstrtype_ == cns_TimePointRange ? dynamic_cast<rangeconstraint_atom*> (this) : 0;
    };

    rangeconstraint_atom* constraint_atom::as_reccurence() {
        return cotstrtype_ == cns_RecurrenceRange ? dynamic_cast<rangeconstraint_atom*> (this) : 0;
    };

    complexconstraint_atom* constraint_atom::as_complex() {
        return dynamic_cast<complexconstraint_atom*> (this);
    }

    complexconstraint_atom* constraint_atom::as_size() {
        return cotstrtype_ == cns_SizeConstraint ? dynamic_cast<complexconstraint_atom*> (this) : 0;
    };

    complexconstraint_atom* constraint_atom::as_permitted() {
        return cotstrtype_ == cns_PermittedAlphabet ? dynamic_cast<complexconstraint_atom*> (this) : 0;
    };

    complexconstraint_atom* constraint_atom::as_singletype() {
        return cotstrtype_ == cns_SingleTypeConstraint ? dynamic_cast<complexconstraint_atom*> (this) : 0;
    };

    namedconstraint_atom* constraint_atom::as_named() {
        return dynamic_cast<namedconstraint_atom*> (this);
    }

    multipletypeconstraint_atom * constraint_atom::as_multipletypeconstraint() {
        return dynamic_cast<multipletypeconstraint_atom *> (this);
    }

    stringconstraint_atom * constraint_atom::as_property() {
        return cotstrtype_ == cns_PropertySettings ? dynamic_cast<stringconstraint_atom *> (this) : 0;

    }

    unionconstraint_atom* constraint_atom::as_union() {
        return dynamic_cast<unionconstraint_atom*> (this);
    }

    intersectionconstraint_atom* constraint_atom::as_intersection() {
        return dynamic_cast<intersectionconstraint_atom*> (this);
    }

    exceptconstraint_atom* constraint_atom::as_except() {
        return dynamic_cast<exceptconstraint_atom*> (this);
    }

    allexceptconstraint_atom* constraint_atom::as_allexcept() {
        return dynamic_cast<allexceptconstraint_atom*> (this);
    }

    extentionconstraint_atom* constraint_atom::as_extention() {
        return dynamic_cast<extentionconstraint_atom*> (this);
    }

    exceptionconstraint_atom* constraint_atom::as_exception() {
        return dynamic_cast<exceptionconstraint_atom*> (this);
    }

    /////////////////////////////////////////////////////////////////////////   
    // valueconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    void valueconstraint_atom::resolve() {
        if (value_)
            value_->resolve_reff();
    }



    /////////////////////////////////////////////////////////////////////////        
    // fromdefinedsetconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    fromdefinedsetconstraint_atom::fromdefinedsetconstraint_atom(basic_entity_ptr scope, const std::string& refffld, objectset_atom_ptr objs) :
    constraint_atom(scope, cns_ValueSetFromObjects), objectset_(objs), field_(basic_atom_ptr(new basic_atom(refffld, scope))) {

    }

    void fromdefinedsetconstraint_atom::resolve() {
        if (objectset())
            objectset()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////        
    // fromdefinedconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    fromdefinedconstraint_atom::fromdefinedconstraint_atom(basic_entity_ptr scope, const std::string& refffld, object_atom_ptr obj) :
    constraint_atom(scope, cns_ValueSetFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scope))) {

    }

    void fromdefinedconstraint_atom::resolve() {
        if (object())
            object()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    // typeconstraint_atom
    /////////////////////////////////////////////////////////////////////////

    void typeconstraint_atom::resolve() {
        if (type_)
            type_->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    // rangeconstraint_atom
    /////////////////////////////////////////////////////////////////////////      

    void rangeconstraint_atom::resolve() {
        if (from_)
            from_->resolve_reff();
        if (to_)
            to_->resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////   
    // namedconstraint_atom
    ///////////////////////////////////////////////////////////////////////// 

    void namedconstraint_atom::resolve() {
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

    void multipletypeconstraint_atom::resolve() {
        for (constraint_atom_vct::iterator it = components_.begin(); it != components_.end(); ++it)
            if (*it)
                (*it)->resolve();
    }


    /////////////////////////////////////////////////////////////////////////   
    // complexconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    void complexconstraint_atom::resolve() {
        if (constraints_)
            constraints_->resolve();
    }




    /////////////////////////////////////////////////////////////////////////   
    // valuesetassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    valuesetassignment_entity::valuesetassignment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, valueset_atom_ptr vl) :
    assignment_entity(scope, nm, et_ValueSet), type_(tp), valueset_(vl) {
    };

    basic_entity_ptr valuesetassignment_entity::find_by_name(const std::string& nm, bool all) {
        if (all) {
            if (((type()->predefined()))) {
                for (basic_entity_vector::iterator it = type()->predefined()->values().begin(); it != type()->predefined()->values().end(); ++it)
                    if ((*it)->name() == nm)
                        return *it;
            }
            if (type()->reff()) {
                type()->resolve_reff(all);
                basic_entity_ptr fnd = type()->reff()->find_by_name(nm, all);
                if (fnd)
                    return fnd;
            }
        }
        if (basic_entity_ptr argfnd = assignment_entity::find_by_name(nm))
            return argfnd;         
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

    void valuesetassignment_entity::resolve() {
        assignment_entity::resolve();
        resolve_child();
        type()->resolve();
        if (valueset())
            valueset()->resolve();
    }


}
