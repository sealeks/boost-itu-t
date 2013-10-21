//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>

namespace x680 {



    /////////////////////////////////////////////////////////////////////////   
    // TYPE
    /////////////////////////////////////////////////////////////////////////     
    // predefined
    ///////////////////////////////////////////////////////////////////////// 


    /////////////////////////////////////////////////////////////////////////   
    // tagged
    /////////////////////////////////////////////////////////////////////////     


    /////////////////////////////////////////////////////////////////////////   
    // type_atom
    /////////////////////////////////////////////////////////////////////////   

    type_atom::type_atom(basic_entity_ptr scp, defined_type tp, tagged_ptr tg)
    : basic_atom(scp), builtin_(tp), tag_(tg) {
    }

    type_atom::type_atom(basic_entity_ptr scp, const std::string& reff, defined_type tp, tagged_ptr tg)
    : basic_atom(reff, scp), builtin_(tp), tag_(tg) {
    }

    defined_type type_atom::root_builtin() {
        if (builtin_ != t_Reference)
            return builtin_;
        resolve();
        if (reff() && (reff()->as_typeassigment())) {
            if (reff()->as_typeassigment()->type())
                return reff()->as_typeassigment()->type()->root_builtin();
        }
        return t_NODEF;
    }

    defined_type type_atom::effective_builtin() {
        if (builtin_ != t_Reference)
            return builtin_;
        if (!istypedef())
            return t_Reference;
        resolve();
        if (reff() && (reff()->as_typeassigment())) {
            if (reff()->as_typeassigment()->type())
                return reff()->as_typeassigment()->type()->root_builtin();
        }
        return t_NODEF;
    }

    bool type_atom::isopen() const {
        return ((builtin_ == t_ClassField) || (builtin_ == t_ANY));
    }

    bool type_atom::istypedef() const {
        return ((builtin_ == t_Reference) && (!tag_) && (constraints_.empty()));
    }

    bool type_atom::isno_taggedchoice() {
        if (builtin_ == t_CHOICE) {
            if (tag_) {
                return false;
            }
            return true;
        }
        if ((builtin_ != t_Reference) || (!reff()))
            return false;
        reff()-> resolve();
        if (reff() && (reff()->as_typeassigment())) {
            if (reff()->as_typeassigment()->type())
                return reff()->as_typeassigment()->type()->isno_taggedchoice();
        }
        return false;
    }

    bool type_atom::isallways_explicit() {
        return ((isno_taggedchoice()) || (isopen()) || (isdummy())) && ((tag()) && (tag()->number()));
    }

    basic_atom_ptr type_atom::effective_type() {
        if (builtin_ != t_Reference)
            return self();
        if (!istypedef())
            return self();
        resolve();
        if (reff() && (reff()->as_typeassigment())) {
            if (reff()->as_typeassigment()->type())
                return reff()->as_typeassigment()->type()->effective_type();
        }
        return basic_atom_ptr();
    }

    tagrule_type type_atom::tagrule() const {
        return (scope() && (scope()->moduleref())) ?
                scope()->moduleref()->tagrule() : noset_tags;
    }

    classfieldtype_atom* type_atom::as_classfield() {
        return dynamic_cast<classfieldtype_atom*> (this);
    }

    instanceoftype_atom* type_atom::as_instance() {
        return dynamic_cast<instanceoftype_atom*> (this);
    }

    fromobjecttype_atom* type_atom::as_fromobject() {
        return dynamic_cast<fromobjecttype_atom*> (this);
    }

    fromobjectsettype_atom* type_atom::as_fromobjectset() {
        return dynamic_cast<fromobjectsettype_atom*> (this);
    }

    void type_atom::resolve(basic_atom_ptr holder) {
        resolve_reff();
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }

    void type_atom::resolve_predef() {
        if (predefined() && scope()) {
            scope()->unicalelerror_throw(predefined()->values());
            resolve_predef_assign(predefined()->values());
            if (builtin() == t_ENUMERATED)
                resolve_predef_enum(predefined()->values());
            resolve_predef_check(predefined()->values());
        }
    }

    void type_atom::resolve_predef_assign(basic_entity_vector& vl) {
        for (basic_entity_vector::const_iterator it = vl.begin(); it != vl.end(); ++it) {
            switch (builtin()) {
                case t_INTEGER:
                {
                    if ((*it)->as_extention())
                        throw semantics::error("type '" + scope()->name() +
                            "' must not have extention in predefine   in module " +
                            (scope() ? scope()->modulerefname() : ""));

                }
                case t_BIT_STRING:
                {
                    if (((*it)->as_valueassigment()) && (!(*it)->as_valueassigment()->value()))
                        throw semantics::error("type '" + scope()->name() + "' predefine name '" +
                            (*it)->name() + "' dosn't assign " +
                            (scope() ? scope()->modulerefname() : ""));
                }
                default:
                {
                    if ((*it)->as_extention())
                        predefined()->extended(true);
                }
            }
            if (((*it)->as_valueassigment()) && ((*it)->as_valueassigment()->value())
                    && ((*it)->as_valueassigment()->value()->expecteddef())) {
                (*it)->as_valueassigment()->value()->resolve_reff(basic_atom_ptr(), extend_search);
                (*it)->as_valueassigment()->check_value_with_exception(v_number);

            }
        }
    }

    void type_atom::resolve_predef_enum(basic_entity_vector& vl) {
        std::set<int, std::less<int> > set;
        bool firstpart = true;
        for (basic_entity_vector::const_iterator it = vl.begin(); it != vl.end(); ++it) {
            if ((*it)->as_extention())
                firstpart = false;
            else if ((*it)->as_valueassigment()->value()) {
                value_atom_ptr vltmp = (*it)->as_valueassigment()->value();
                if (vltmp->as_number()) {
                    if (firstpart)
                        set.insert(vltmp->as_number()->value());
                } else {
                    if ((vltmp->root()) && (vltmp->root()->as_value()))
                        if (firstpart)
                            set.insert(vltmp->root()->as_value()->as_number()->value());
                }
            }
        }
        int start = 0;
        firstpart = true;
        for (basic_entity_vector::iterator it = vl.begin(); it != vl.end(); ++it) {
            if ((*it)->as_extention()) {
                firstpart = false;
            } else if (!(*it)->as_valueassigment()->value()) {
                int newen = start++;
                while (set.find(newen) != set.end())
                    newen = start++;
                (*it) = basic_entity_ptr(new valueassignment_entity((*it)->scope(), (*it)->name(), type_atom_ptr(new type_atom((*it)->scope(), t_INTEGER)),
                        value_atom_ptr(new numvalue_atom(newen))));
            } else {
                if (!firstpart) {
                    value_atom_ptr vltmp = (*it)->as_valueassigment()->value();
                    if (vltmp->as_number()) {
                        if (vltmp->as_number()->value() < start)
                            throw semantics::error("type '" + scope()->name() + "' predefine name '" +
                                (*it)->name() + "' is not at the rule " + scope()->modulerefname());
                        else
                            start = vltmp->as_number()->value() + 1;
                    } else {
                        if (vltmp->root()->as_value()->as_number()->value() < start)
                            throw semantics::error("type '" + scope()-> name() + "' predefine name '" +
                                (*it)->name() + "' is not at the rule " + scope()->modulerefname());
                        else
                            start = vltmp->root()->as_value()->as_number()->value() + 1;
                    }
                }
            }
        }
    }

    void type_atom::resolve_predef_check(basic_entity_vector& vl) {
        std::set<int, std::less<int> > set;
        for (basic_entity_vector::const_iterator it = vl.begin(); it != vl.end(); ++it) {
            if ((*it)->as_extention()) {
            } else if ((*it)->as_valueassigment()->value()) {
                value_atom_ptr vltmp = (*it)->as_valueassigment()->value();
                if (vltmp->as_number()) {
                    if (set.find(vltmp->as_number()->value()) != set.end())
                        throw semantics::error("type '" + scope()->name() + "' predefine name '" +
                            (*it)->name() + "'is not unical " + scope()->modulerefname());
                    else
                        set.insert(vltmp->as_number()->value());
                } else {
                    if ((vltmp->root()) && (vltmp->root()->as_value())) {
                        if (set.find(vltmp->root()->as_value()->as_number()->value()) != set.end())
                            throw semantics::error("type '" + scope()->name() + "' predefine name '" +
                                (*it)->name() + "' is not unical " + scope()->modulerefname());
                        else
                            set.insert(vltmp->root()->as_value()->as_number()->value());
                    }
                }
            }
        }
    }

    void type_atom::resolve_tag() {
        if (tag()) {
            if ((tag()->rule() == noset_tags) && (tag()->number())) {
                switch (tagrule()) {
                    case explicit_tags: if (isallways_explicit())
                            tag()->rule(explicit_tags);
                        break;
                    case implicit_tags:
                    case automatic_tags:
                    {
                        tag()->rule(isallways_explicit() ? explicit_tags : implicit_tags);
                        break;
                    }
                    default:
                    {
                        if (isallways_explicit())
                            tag()->rule(explicit_tags);
                    };
                }
            }
            if ((isallways_explicit()) && (tag()->rule() == implicit_tags) && (tag()->number()))
                // std::cout << "Test error namr: "  << scope()->name()  << std:: endl;
                scope()->referenceerror_throw("type ", " shall not be implicit '");
            if ((tag()->number()) && (tag()->number()->as_defined()) && (tag()->number()->expecteddef())) {
                tag()->number()->resolve_reff(basic_atom_ptr(), extend_search);
            }
        }
    }

    void type_atom::resolve_constraints() {
        for (constraints_atom_vct::iterator it = constraints_.begin(); it != constraints_.end(); ++it)
            (*it)->resolve();
    }


    /////////////////////////////////////////////////////////////////////////   
    // classfieldtype_atom
    /////////////////////////////////////////////////////////////////////////    

    instanceoftype_atom::instanceoftype_atom(basic_entity_ptr scp, const std::string& reffcl, tagged_ptr tg) :
    type_atom(scp, t_Instance_Of, tg), class_(class_atom_ptr(new class_atom(scp, reffcl))) {
    };

    void instanceoftype_atom::resolve(basic_atom_ptr holder) {
        if (_class())
            _class()->resolve();
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }


    /////////////////////////////////////////////////////////////////////////   
    // classfieldtype_atom
    /////////////////////////////////////////////////////////////////////////      

    classfieldtype_atom::classfieldtype_atom(basic_entity_ptr scp, const std::string& reffcl, const std::string& refffld, tagged_ptr tg) :
    type_atom(scp, t_ClassField, tg), class_(class_atom_ptr(new class_atom(scp, reffcl))), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void classfieldtype_atom::resolve(basic_atom_ptr holder) {
        if (_class())
            _class()->resolve();
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }

    /////////////////////////////////////////////////////////////////////////   
    // fromobjecttype_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjecttype_atom::fromobjecttype_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj, tagged_ptr tg) :
    type_atom(scp, t_TypeFromObject, tg), object_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void fromobjecttype_atom::resolve(basic_atom_ptr holder) {
        if (object())
            object()->resolve();
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }

    /////////////////////////////////////////////////////////////////////////   
    // fromobjectsettype_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjectsettype_atom::fromobjectsettype_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj, tagged_ptr tg) :
    type_atom(scp, t_ValueSetFromObjects, tg), objectset_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void fromobjectsettype_atom::resolve(basic_atom_ptr holder) {
        if (objectset())
            objectset()->resolve();
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }


    /////////////////////////////////////////////////////////////////////////   
    // typeassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    typeassignment_entity::typeassignment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp) :
    assignment_entity(scope, nm, et_Type), type_(tp) {
    };

    typeassignment_entity::typeassignment_entity(basic_entity_ptr scope) :
    assignment_entity(scope, et_Type) {
    };

    ////////

    basic_entity_ptr typeassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        if (sch & local_search) {
            if (((type()->predefined()))) {
                for (basic_entity_vector::iterator it = type()->predefined()->values().begin(); it != type()->predefined()->values().end(); ++it)
                    if ((*it)->name() == nm)
                        return *it;
            }
            if (type()->reff() && (type()->reff()->name() != nm)) {
                type()->resolve_reff();
                if (basic_entity_ptr fnd = type()->reff()->find_by_name(nm, sch))
                    return fnd;
            }
        }
        if (!(sch & extend_search))
            return basic_entity_ptr();
        if (basic_entity_ptr fnd = assignment_entity::find_by_name(nm))
            return fnd;
        if (scope())
            return scope()->find_by_name(nm, sch);
        return basic_entity_ptr();
    }

    namedtypeassignment_entity* typeassignment_entity::as_named() {
        return dynamic_cast<namedtypeassignment_entity*> (this);
    }

    void typeassignment_entity::resolve(basic_atom_ptr holder) {
        unicalelerror_throw(childs());
        assignment_entity::resolve(holder);
        resolve_child();
        if (type())
            type()->resolve();
        post_resolve_child();

    }

    void typeassignment_entity::post_resolve_child() {
        post_resolve_apply_componentsof();
        post_resolve_autotag();
    }

    void typeassignment_entity::post_resolve_apply_componentsof() {
        if ((type()) and (!childs().empty())) {
            if ((type()->builtin() == t_SEQUENCE) && ((type()->builtin() == t_SET))) {
                bool find_compomensof = true;
                while (find_compomensof) {
                    find_compomensof = false;
                    for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                        if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                            namedtypeassignment_entity* named = (*it)->as_typeassigment()->as_named();
                            if (named->marker() == mk_components_of) {
                                if (basic_entity_ptr namedreff = named->type()->reff()) {
                                    namedreff->resolve();
                                    basic_entity_vector tmpch;
                                    if ((namedreff->as_typeassigment())
                                            && (!namedreff->as_typeassigment()->childs().empty())) {
                                        if (!namedreff->as_typeassigment()->type())
                                            scope()->referenceerror_throw("Undefined type");
                                        if (namedreff->as_typeassigment()->type()->effective_builtin() != type()->builtin())
                                            scope()->referenceerror_throw("Apply COMPONENT OF error");
                                        for (basic_entity_vector::iterator its = namedreff->as_typeassigment()->childs().begin();
                                                its != namedreff->as_typeassigment()->childs().end(); ++its) {
                                            if ((*its)->as_typeassigment()->as_named()->marker() != mk_extention) {
                                                namedtypeassignment_entity_ptr tmp;
                                                if ((*its)->as_typeassigment()->as_named()->marker() == mk_default) {
                                                    tmp = namedtypeassignment_entity_ptr(new namedtypeassignment_entity((*it)->scope(),
                                                            (*its)->name(), (*its)->as_typeassigment()->as_named()->type(),
                                                            (*its)->as_typeassigment()->as_named()->_default()));
                                                } else
                                                    tmp = namedtypeassignment_entity_ptr(new namedtypeassignment_entity((*it)->scope(),
                                                        (*its)->name(), (*its)->as_typeassigment()->as_named()->type(),
                                                        (*its)->as_typeassigment()->as_named()->marker()));
                                                tmpch.push_back(tmp);
                                            } else
                                                break;
                                        }
                                        if (!tmpch.empty()) {
                                            childs().insert(childs().erase(it), tmpch.begin(), tmpch.end());
                                            find_compomensof = true;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    void typeassignment_entity::post_resolve_autotag() {
        if ((type()) and (!childs().empty())) {
        }
    }




    /////////////////////////////////////////////////////////////////////////   
    // namedtypeassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    namedtypeassignment_entity::namedtypeassignment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, tagmarker_type mrker)
    : typeassignment_entity(scp, nm, tp), marker_(mrker) {
    }

    namedtypeassignment_entity::namedtypeassignment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl)
    : typeassignment_entity(scp, nm, tp), marker_(mk_default), default_(vl) {
    }

    namedtypeassignment_entity::namedtypeassignment_entity(basic_entity_ptr scp, type_atom_ptr tp, value_atom_ptr vl)
    : typeassignment_entity(scp, "", tp), marker_(mk_exception), default_(vl) {
    }

    namedtypeassignment_entity::namedtypeassignment_entity(basic_entity_ptr scp)
    : typeassignment_entity(scp, "", type_atom_ptr()), marker_(mk_extention) {
    }

    void namedtypeassignment_entity::resolve(basic_atom_ptr holder) {
        typeassignment_entity::resolve(holder);
        resolve_default();
    }

    void namedtypeassignment_entity::resolve_default() {
        if (_default())
            _default()->resolve(type());
    }


}
