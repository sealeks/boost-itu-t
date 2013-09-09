//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>
#include <set>

namespace x680 {

    void insert_assigment(basic_entity_ptr scope, basic_entity_ptr val) {
        scope->childs().push_back(val);
    }

    void insert_global(basic_entity_ptr global) {

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "itu-t",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(0)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "ccitt",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(0)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "iso",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(1)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "joint-iso-itu-t",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(2)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "recommendation",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(0)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "question",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(1)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "administration",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(2)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "network-operator",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(3)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "identified-organization",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(4)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "r-recommendation",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(5)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "standard",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(0)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "registration-authority",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(1)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, "member-body",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(2)))));

        insert_assigment(global, valueassigment_entity_ptr(new valueassigment_entity(global, " identified-organization",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(3)))));



    }

    /////////////////////////////////////////////////////////////////////////   
    // basic_entity
    ///////////////////////////////////////////////////////////////////////// 

    int basic_entity::level() const {
        int rslt = 0;
        basic_entity_ptr scp = scope();
        while (scp) {
            rslt++;
            scp = scp->scope();
        }
        return rslt;
    }

    global_entity* basic_entity::as_global() {
        return dynamic_cast<global_entity*> (this);
    }

    module_entity* basic_entity::as_module() {
        return dynamic_cast<module_entity*> (this);
    }

    expectdef_entity* basic_entity::as_expectdef() {
        return dynamic_cast<expectdef_entity*> (this);
    }

    import_entity* basic_entity::as_import() {
        return dynamic_cast<import_entity*> (this);
    }

    bigassigment_entity * basic_entity::as_bigassigment() {
        return dynamic_cast<bigassigment_entity*> (this);
    }

    littleassigment_entity * basic_entity::as_littleassigment() {
        return dynamic_cast<littleassigment_entity*> (this);
    }

    typeassigment_entity * basic_entity::as_typeassigment() {
        return dynamic_cast<typeassigment_entity*> (this);
    }

    valueassigment_entity * basic_entity::as_valueassigment() {
        return dynamic_cast<valueassigment_entity*> (this);
    }

    valuesetassigment_entity * basic_entity::as_valuesetassigment() {
        return dynamic_cast<valuesetassigment_entity*> (this);
    }

    classassigment_entity * basic_entity::as_classassigment() {
        return dynamic_cast<classassigment_entity*> (this);
    }

    extention_entity * basic_entity::as_extention() {
        return dynamic_cast<extention_entity*> (this);
    }

    module_entity* basic_entity::moduleref() {
        module_entity* rf = as_module();
        basic_entity_ptr sc = scope();
        while ((!rf) && (sc)) {
            rf = sc->as_module();
            sc = sc->scope();
        }
        return rf;
    }

    std::string basic_entity::modulerefname() {
        module_entity* rf = moduleref();
        if (rf)
            return " in module: " + rf->name() + " in file: " + rf->file();
        return " in undefined module";
    }

    std::string basic_entity::source_throw() {
        std::string rslt = "";
        if (as_typeassigment())
            rslt = rslt + " in typeassignment";
        else if (as_valueassigment())
            rslt = rslt + " in valueassignment";
        else if (as_classassigment())
            rslt = rslt + " in classassignment";
        else if (as_module())
            return "";
        else
            rslt = rslt + " in assignment";
        if ((scope()) && (moduleref()) && (moduleref() != scope().get())) {
            std::string stack = "";
            basic_entity_ptr sc = scope();
            while ((sc) && (moduleref() != sc.get())) {
                stack = stack.empty() ? sc->name() : (sc->name() + "::" + stack);
                sc = sc->scope();
            }
            if (moduleref() == sc.get())
                stack = sc->name() + "::" + stack;
            rslt = rslt + " stack: " + stack + " ";
        } else
            rslt = rslt + " ";
        return rslt;
    }

    void basic_entity::referenceerror_throw(const std::string& val) {
        std::string rslt = " Unknown reference : '" + val + "'";
        rslt += source_throw();
        rslt = rslt + " '" + name() + "'" + modulerefname();
        throw semantics::error(rslt);
    }

    void basic_entity::unicalelerror_throw(const basic_entity_vector& elms) {
        std::set<std::string> set;
        for (basic_entity_vector::const_iterator it = elms.begin(); it != elms.end(); ++it) {
            if ((*it)->as_extention()) {
            } else {
                if (!(*it)->name().empty()) {
                    if (set.find((*it)->name()) != set.end())
                        throw semantics::error("Identifier '" + (*it)->name() + "' duplicates " + (*it)->source_throw() + modulerefname());
                    else
                        set.insert((*it)->name());
                }
            }
        }
    }

    void basic_entity::resolve_assigments(basic_entity_vector& elm) {
        for (basic_entity_vector::iterator it = elm.begin(); it != elm.end(); ++it) {
            resolve_assigment(*it);
        }
    }

    void basic_entity::resolve_assigment(basic_entity_ptr& elm, basic_entity_ptr start) {

        switch (elm->kind()) {
            case et_Nodef:
            {
                elm = resolve_nodef_assigment(elm, start);
                break;
            }
            case et_Type:
            {
                resolve_type_assigment(elm, start);
                break;
            }
            case et_Value:
            {
                resolve_value_assigment(elm, start);
                break;
            }
            case et_Class:
            {
                resolve_class_assigment(elm, start);
                break;
            }
        }
    }

    basic_entity_ptr basic_entity::resolve_nodef_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        basic_entity_ptr rslt = resolve_nodef_assigment(elm.get(), start.get());
        return rslt ? rslt : elm;
    }

    basic_entity_ptr basic_entity::resolve_nodef_assigment(basic_entity* elm, basic_entity* start) {
        /*if (!start)
            start = elm;
        else
            check_resolve_ciclic(elm, start);*/
        bigassigment_entity* tmp = elm->as_bigassigment();
        if (tmp && (tmp->big()) && (tmp->big()->reff())) {
            basic_entity_ptr fnd = elm->find(tmp->big()->reff()->name());
            if (fnd) {
                if (fnd->kind() == et_Type) {
                    basic_entity_ptr rslt(new typeassigment_entity(elm->scope(), tmp->name(),
                            type_atom_ptr(new type_atom(elm->scope(), tmp->big()->reff()->name(), t_Reference))));
                    resolve_type_assigment(rslt);
                    return rslt;
                }
                if (fnd->kind() == et_Class) {
                    basic_entity_ptr rslt(new classassigment_entity(elm->scope(), tmp->name(),
                            class_atom_ptr(new class_atom(tmp->big()->reff()->name(), cl_Reference))));
                    resolve_class_assigment(rslt);
                    return rslt;
                }
            }
        }
        return basic_entity_ptr();
    }

    void basic_entity::resolve_atom(basic_atom_ptr elm, bool all) {
        resolve_atom(elm.get(), all);
    }

    void basic_entity::resolve_atom(basic_atom* elm, bool all) {
        if (elm && (elm->expecteddef()) && (elm->scope())) {
            basic_entity_ptr fnd = elm->scope()->find(elm->reff()->name(), all);
            if (fnd) {
                elm->reff(fnd);
            } else {
                if (elm->scope()) {
                    elm->scope()->referenceerror_throw(elm->reff()->name());
                }
            }
        }
    }

    void basic_entity::resolve_type_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        resolve_type_assigment(elm.get(), start.get());
    }

    void basic_entity::resolve_type_assigment(basic_entity* elm, basic_entity* start) {
        /* if (!start)
             start = elm;
         else
             check_resolve_ciclic(elm, start);*/
        typeassigment_entity* tmp = elm->as_typeassigment();
        if (tmp) {
            if ((tmp->type()) && (tmp->type()->expecteddef())) {
                basic_entity_ptr fnd = elm->find(tmp->type()->expectedname());
                if (fnd)
                    tmp->type()->reff(fnd);
                else
                    tmp->referenceerror_throw(tmp->type()->expectedname());
            }
            //resolve_typepredef_assigment(tmp);
        }
    }

    void basic_entity::resolve_value_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        resolve_value_assigment(elm.get(), start.get());
    }

    void basic_entity::resolve_value_assigment(basic_entity* elm, basic_entity* start) {
        /* if (!start)
             start = elm;
         else
             check_resolve_ciclic(elm, start);*/
        valueassigment_entity* tmp = elm->as_valueassigment();
        if (tmp) {
            if ((tmp->type()) && (tmp->type()->expecteddef())) {
                basic_entity_ptr fnd = elm->find(tmp->type()->expectedname());
                if (fnd)
                    tmp->type()->reff(fnd);
                else
                    tmp->referenceerror_throw(tmp->type()->expectedname());
            }
            if ((tmp->value()) && (tmp->value()->expecteddef())) {
                basic_entity_ptr fnd = elm->find(tmp->value()->expectedname());
                if (fnd)
                    tmp->value()->reff(fnd);
                else
                    tmp->referenceerror_throw(tmp->value()->expectedname());
            }
        }
    }

    void basic_entity::resolve_class_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        resolve_type_assigment(elm.get(), start.get());
    }

    void basic_entity::resolve_class_assigment(basic_entity* elm, basic_entity* start) {
        /* if (!start)
             start = elm;
         else
             check_resolve_ciclic(elm, start);*/
        classassigment_entity* tmp = elm->as_classassigment();
        if (tmp) {
            if ((tmp->_class()) && (tmp->_class()->reff()) && (tmp->_class()->reff()->as_expectdef())) {
                basic_entity_ptr fnd = elm->find(tmp->_class()->reff()->name());
                if (fnd)
                    tmp->_class()->reff(fnd);
                else
                    tmp->referenceerror_throw(tmp->_class()->expectedname());
            }
        }
    }

    ////////

    basic_entity_ptr basic_entity::find(const std::string& nm, bool all) {
        //throw semantics::error("Idenifier" + nm + " not found");
        return basic_entity_ptr();
    }

    void basic_entity::resolve() {
        resolve_child();
    };

    void basic_entity::resolve_child() {
        for (basic_entity_vector::const_iterator it = childs().begin(); it != childs().end(); ++it) {
            (*it)->resolve();
        }
    }


    /////////////////////////////////////////////////////////////////////////   
    // global_entity
    /////////////////////////////////////////////////////////////////////////  

    global_entity::global_entity()
    : basic_entity(et_Global) {
    }

    ////////

    void global_entity::resolve() {
        resolve_child();
    }

    void global_entity::preresolve() {
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->as_module()) {
                (*it)->as_module()->preresolve();
            }
    }

    basic_entity_ptr global_entity::find(const std::string& nm, bool all) {
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->name() == nm) {
                return *it;
            }
        return basic_entity_ptr();
    }



    /////////////////////////////////////////////////////////////////////////
    // import_entity
    /////////////////////////////////////////////////////////////////////////

    import_entity::import_entity(const std::string& nm, basic_entity_ptr inscp)
    : basic_entity(nm, et_Import), inscope_(inscp) {
    }

    void import_entity::resolve() {
        if (objectid()) {
            objectid()->resolve();
        }
    }

    basic_entity_ptr import_entity::find(const std::string& nm, bool all) {
        if (inscope())
            return inscope()->find(nm, all);
        return basic_entity_ptr();
    }

    /////////////////////////////////////////////////////////////////////////   
    // module_entity
    /////////////////////////////////////////////////////////////////////////   

    module_entity::module_entity(basic_entity_ptr scope, const std::string& nm, const std::string& fl, bool allexp)
    : basic_entity(scope, nm, et_Module), file_(fl), allexport_(allexp) {
    }

    /////

    basic_entity_ptr module_entity::find(const std::string& nm, bool all) {
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->name() == nm) {
                resolve_assigment(*it);
                return *it;
            }
        for (basic_entity_vector::iterator it = imports().begin(); it != imports().end(); ++it) {
            import_entity* importmod = (*it)->as_import();
            if (importmod->scope()) {
                basic_entity_ptr fnd = importmod->scope()->find(nm, all);
                if (fnd)
                    return fnd;
            }
        }
        if (scope())
            return scope()->find(nm, all);
        return basic_entity_ptr();
    }

    void module_entity::resolve() {
        //resolve_oid();
        unicalelerror_throw(childs());
        resolve_export();
        resolve_externalmodule();
        resolve_child();
        resolve_assigments(childs());
    }

    void module_entity::preresolve() {
        resolve_oid();
        for (basic_entity_vector::iterator it = imports().begin(); it != imports().end(); ++it)
            if ((*it)->as_import())
                (*it)->as_import()->resolve();

    }

    void module_entity::resolve_export() {
        if (allexport()) {
            for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                exports().push_back((*it)->name());
            }
        } else {
            for (export_vector::iterator it = exports().begin(); it != exports().end(); ++it) {
            }
        }
    }

    void module_entity::resolve_externalmodule() {
        for (basic_entity_vector::iterator it = imports().begin(); it != imports().end(); ++it) {
            import_entity* importmod = (*it)->as_import();
            if (importmod) {
                basic_entity_ptr finded = findmodule(importmod->name());
                if (finded && (finded->as_module())) {
                    importmod->scope(finded);
                } else {
                    throw semantics::error("Not find imported module: " + importmod->name() +
                            " in module: " + name() + " in file: " + file());
                }
            }
        }
    }

    basic_entity_ptr module_entity::findmodule(const std::string& nm) {
        if (scope() && scope()->as_global()) {
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (nm == (*it)->name())
                    return *it;
            }
        }
        return basic_entity_ptr();
    }

    void module_entity::resolve_oid() {
        if (objectid()) {
            objectid()->resolve();
        }
    }







    /////////////////////////////////////////////////////////////////////////   
    // expectdef_entity
    /////////////////////////////////////////////////////////////////////////

    expectdef_entity::expectdef_entity(basic_entity_ptr scope, const std::string& nm)
    : basic_entity(scope, nm, et_Nodef) {
    }



    /////////////////////////////////////////////////////////////////////////   
    // basic_atom
    /////////////////////////////////////////////////////////////////////////   

    basic_atom::basic_atom(basic_entity_ptr scp) : scope_(scp) {
    };

    basic_atom::basic_atom(const std::string& reff, basic_entity_ptr scp) : scope_(scp) {
        reff_ = basic_entity_ptr(new expectdef_entity(scp, reff));
    }

    module_entity* basic_atom::external() const {
        if ((scope()) && (reff()) && (!reff()->as_expectdef()) && (scope()->moduleref()) && (reff()->moduleref()))
            return ((scope()->moduleref()) != (reff()->moduleref())) ? reff()->moduleref() : 0;
        return 0;
    }

    std::string basic_atom::externalpreff() const {
        if (external())
            return external()->name() + "::";
        return "";
    }

    basic_atom* basic_atom::root() {
        if (!reff())
            return this;
        if ((reff()->as_typeassigment()) && (reff()->as_typeassigment()->type()))
            return reff()->as_typeassigment()->type()->root();
        if ((reff()->as_valueassigment()) && (reff()->as_valueassigment()->value()))
            return reff()->as_valueassigment()->value()->root();
        return 0;
    }

    bool basic_atom::rooted() {
        return ((root()) && (root() != this));
    }

    value_atom* basic_atom::as_value() {
        return dynamic_cast<value_atom*> (this);
    }

    type_atom* basic_atom::as_type() {
        return dynamic_cast<type_atom*> (this);
    }

    void basic_atom::resolve() {
    }

    basic_entity_ptr basic_atom::find(const std::string& nm, bool all) {
        if (scope())
            return scope()->find(nm, all);
        return basic_entity_ptr();
    }


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

    void type_atom::resolve() {
        resolve_tag();
        resolve_predef();
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
                        throw semantics::error("type '" + scope()->name() + "' must not have extention in predefine   in module " +
                            scope()->modulerefname());

                }
                case t_BIT_STRING:
                {
                    if (((*it)->as_valueassigment()) && (!(*it)->as_valueassigment()->value()))
                        throw semantics::error("type '" + scope()->name() + "' predefine name '" +
                            (*it)->name() + "' dosn't assign " + scope()->modulerefname());
                }
                default:
                {
                    if ((*it)->as_extention())
                        predefined()->extended(true);
                }
            }
            if (((*it)->as_valueassigment()) && ((*it)->as_valueassigment()->value())
                    && ((*it)->as_valueassigment()->value()->expecteddef())) {
                basic_entity_ptr fnd = find((*it)->as_valueassigment()->value()->expectedname(), false);
                if (fnd)
                    (*it)->as_valueassigment()->value()->reff(fnd);
                else
                    (*it)->referenceerror_throw((*it)->as_valueassigment()->value()->expectedname());
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
                (*it) = basic_entity_ptr(new valueassigment_entity((*it)->scope(), (*it)->name(), type_atom_ptr(new type_atom((*it)->scope(), t_INTEGER)),
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
            if ((tag()->number()) && (tag()->number()->as_defined()) && (tag()->number()->expecteddef())) {
                basic_entity_ptr fnd = find(tag()->number()->expectedname(), false);
                if (fnd)
                    tag()->number()->reff(fnd);
                else
                    throw semantics::error("");
            }
        }
    }


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
        return dynamic_cast<structvalue_atom*> (this);
    }

    objidvalue_atom* value_atom::as_objid() {
        return dynamic_cast<objidvalue_atom*> (this);
    }

    listvalue_atom* value_atom::as_list() {
        return dynamic_cast<listvalue_atom*> (this);
    }

    definedvalue_atom* value_atom::as_defined() {
        return dynamic_cast<definedvalue_atom*> (this);
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

    void value_atom::resolve_vect(value_vct& vl) {
        for (value_vct::iterator it = vl.begin(); it != vl.end(); ++it)
            basic_entity::resolve_atom(*it);
    }

    void value_atom::resolve_ptr(value_atom_ptr vl) {
        basic_entity::resolve_atom(vl);
    }

    /////////////////////////////////////////////////////////////////////////   
    // namedvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void namedvalue_atom::resolve() {
        resolve_ptr(value_);
    }


    /////////////////////////////////////////////////////////////////////////   
    // structvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void structvalue_atom::resolve() {
        resolve_vect(values_);
    }


    /////////////////////////////////////////////////////////////////////////   
    // objidvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void objidvalue_atom::resolve() {
        resolve_vect(values_);
    }


    /////////////////////////////////////////////////////////////////////////   
    // listvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void listvalue_atom::resolve() {
        resolve_vect(values_);
    }

    /////////////////////////////////////////////////////////////////////////   
    // definedvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void definedvalue_atom::resolve() {
        basic_entity::resolve_atom(this);
    }


    /////////////////////////////////////////////////////////////////////////   
    // assignvalue_atom
    ///////////////////////////////////////////////////////////////////////// 

    void assignvalue_atom::resolve() {
        resolve_ptr(value_);
    }

    /////////////////////////////////////////////////////////////////////////   
    // choicevalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void choicevalue_atom::resolve() {
        resolve_ptr(value_);
    }


    /////////////////////////////////////////////////////////////////////////   
    // openvalue_atom_atom
    /////////////////////////////////////////////////////////////////////////      

    void openvalue_atom::resolve() {
        if (type_)
            type_->resolve();
        resolve_ptr(value_);
    }



    /////////////////////////////////////////////////////////////////////////   
    //class_atom
    /////////////////////////////////////////////////////////////////////////   

    class_atom::class_atom(definedclass_type tp)
    : basic_atom(basic_entity_ptr()), builtin_(tp) {
    }

    class_atom::class_atom(const std::string& reff, definedclass_type tp)
    : basic_atom(reff, basic_entity_ptr()), builtin_(tp) {
    }


    /////////////////////////////////////////////////////////////////////////   
    // bigassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    bigassigment_entity::bigassigment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg) :
    basic_entity(scope, nm, et_Nodef), big_(bg) {
    };

    basic_entity_ptr bigassigment_entity::find(const std::string& nm, bool all) {
        if (scope())
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (nm == (*it)->name()) {
                    resolve_assigment(*it);
                    return *it;
                }
            }
        if (scope())
            return scope()->find(nm);
        return basic_entity_ptr();
    }




    /////////////////////////////////////////////////////////////////////////   
    // valueassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    littleassigment_entity::littleassigment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg, basic_atom_ptr lt) :
    basic_entity(scope, nm, et_Type), big_(bg), little_(lt) {
    };

    /////////

    basic_entity_ptr littleassigment_entity::find(const std::string& nm, bool all) {
        if (scope())
            return scope()->find(nm, all);
        return basic_entity_ptr();
    }




    /////////////////////////////////////////////////////////////////////////   
    // typeassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    typeassigment_entity::typeassigment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp) :
    basic_entity(scope, nm, et_Type), type_(tp) {
    };

    ////////

    basic_entity_ptr typeassigment_entity::find(const std::string& nm, bool all) {
        if (all) {
            if (((type()->predefined()))) {
                for (basic_entity_vector::iterator it = type()->predefined()->values().begin(); it != type()->predefined()->values().end(); ++it) {
                    if ((*it)->name() == nm) {
                        resolve_assigment(*it);
                        return *it;
                    }
                }
            }

            if ((type()->reff())) {
                resolve_atom(type());
                basic_entity_ptr fnd = type()->reff()->find(nm, all);
                if (fnd)
                    return fnd;
            }
        }
        if (scope())
            return scope()->find(nm, all);
        return basic_entity_ptr();
    }

    void typeassigment_entity::resolve() {
        unicalelerror_throw(childs());
        resolve_child();
        type()->resolve();
        resolve_assigments(childs());

    }

    namedtypeassigment_entity* typeassigment_entity::as_named() {
        return dynamic_cast<namedtypeassigment_entity*> (this);
    }



    /////////////////////////////////////////////////////////////////////////   
    // namedtypeassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    namedtypeassigment_entity::namedtypeassigment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, tagmarker_type mrker)
    : typeassigment_entity(scp, nm, tp), marker_(mrker) {
    }

    namedtypeassigment_entity::namedtypeassigment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl)
    : typeassigment_entity(scp, nm, tp), marker_(mk_default), default_(vl) {

    }

    void namedtypeassigment_entity::resolve() {
        typeassigment_entity::resolve();
        resolve_default();
    }

    void namedtypeassigment_entity::resolve_default() {
        if ((_default()) && (_default()->expecteddef())) {
            basic_entity_ptr fnd = find(_default()->expectedname());
            if (fnd)
                _default()->reff(fnd);
            else
                referenceerror_throw(_default()->expectedname());
        }
    }

    /////////////////////////////////////////////////////////////////////////   
    // valueassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    valueassigment_entity::valueassigment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl) :
    basic_entity(scope, nm, et_Value), type_(tp), value_(vl) {
    };

    void valueassigment_entity::check_value_with_exception(value_type tp) {
        if ((value()) && (value()->root()) && (value()->root()->as_value())) {
            if (value()->root()->as_value()->valtype() != tp)
                throw semantics::error("value '" + name() + "' has invalid type " +
                    modulerefname());
        }
    }

    basic_entity_ptr valueassigment_entity::find(const std::string& nm, bool all) {
        if (all) {
            if (((type()->predefined()))) {
                for (basic_entity_vector::iterator it = type()->predefined()->values().begin(); it != type()->predefined()->values().end(); ++it) {
                    if ((*it)->name() == nm) {
                        resolve_assigment(*it);
                        return *it;
                    }
                }
            }
            if (type()->reff()) {
                resolve_atom(type());
                basic_entity_ptr fnd = type()->reff()->find(nm, all);
                if (fnd)
                    return fnd;
            }
        }
        if (scope())
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (nm == (*it)->name()) {
                    resolve_assigment(*it);
                    return *it;
                }
            }
        if (scope())
            return scope()->find(nm, all);
        return basic_entity_ptr();
    }

    void valueassigment_entity::resolve() {
        resolve_child();
        type()->resolve();
        if (value())
            value()->resolve();
    }


    /////////////////////////////////////////////////////////////////////////   
    // valuesetassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    valuesetassigment_entity::valuesetassigment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, basic_atom_ptr vl) :
    basic_entity(scope, nm, et_ValueSet), type_(tp), valueset_(vl) {
    };

    basic_entity_ptr valuesetassigment_entity::find(const std::string& nm, bool all) {
        if (all) {
            if (((type()->predefined()))) {
                for (basic_entity_vector::const_iterator it = type()->predefined()->values().begin(); it != type()->predefined()->values().end(); ++it) {
                    if ((*it)->name() == nm) {
                        return *it;
                    }
                }
            }
        }
        if (scope())
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (nm == (*it)->name()) {
                    resolve_assigment(*it);
                    return *it;
                }
            }
        if (scope())
            return scope()->find(nm, all);
        return basic_entity_ptr();
    }

    void valuesetassigment_entity::resolve() {
    }

    /////////////////////////////////////////////////////////////////////////   
    // classassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    classassigment_entity::classassigment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr tp) :
    basic_entity(scope, nm, et_Class), class_(tp) {
    };

    basic_entity_ptr classassigment_entity::find(const std::string& nm, bool all) {
        if (scope())
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (nm == (*it)->name()) {
                    resolve_assigment(*it);
                    return *it;
                }
            }
        if (scope())
            return scope()->find(nm, all);
        return basic_entity_ptr();
    }

    void classassigment_entity::resolve() {
    }


    namespace semantics {

        std::ostream& operator<<(std::ostream& stream, const error& self) {
            stream << "Semantic error: " << self.message() << "\n";
            return stream;
        }













        /////////////////////////////////////////////////////////////////////////   
        // precomile modules
        /////////////////////////////////////////////////////////////////////////           

        global_entity_ptr compile_fs(const std::string& path, const std::string& ext) {
            x680::syntactic::modules synxtasresult;
            int success = x680::syntactic::parse_fs(path, synxtasresult);

            global_entity_ptr global = global_entity_ptr(new global_entity());


            insert_global(global);

            for (x680::syntactic::modules::const_iterator it = synxtasresult.begin(); it != synxtasresult.end(); ++it)
                compile_module(*it, global);
            global->preresolve();
            global->resolve();
            return global;
        }



        //  compile_module        

        void compile_module(const x680::syntactic::module& mod, global_entity_ptr global) {
            module_entity_ptr modul = module_entity_ptr(new module_entity(global, mod.name, mod.file, mod.allexport));
            compile_export(mod, modul);
            compile_imports(mod, modul);
            compile_assignments(mod, modul);
            if (mod.oid.type == v_objectid)
                modul->objectid(objidvalue_atom_ptr(new objidvalue_atom(compile_objidvalue(modul, mod.oid))));
            global->childs().push_back(modul);
        }



        //  compile_export

        void compile_export(const x680::syntactic::module& mod, module_entity_ptr mdl) {
            for (x680::syntactic::exports::const_iterator it = mod.exports_.begin(); it != mod.exports_.end(); ++it)
                mdl->exports().push_back(*it);
        }



        //  compile_imports      

        void compile_imports(const x680::syntactic::module& mod, module_entity_ptr mdl) {
            for (x680::syntactic::imports::const_iterator it = mod.imports_.begin(); it != mod.imports_.end(); ++it) {
                mdl->imports().push_back(compile_import(*it, mdl));
            }
        }




        //  compile_import         

        basic_entity_ptr compile_import(const x680::syntactic::import& imp, module_entity_ptr mdl) {
            import_entity_ptr rslt = import_entity_ptr(new import_entity(imp.name, mdl));
            if (imp.oid.type == v_objectid)
                rslt->objectid(objidvalue_atom_ptr(new objidvalue_atom(compile_objidvalue(rslt, imp.oid))));
            for (x680::syntactic::string_vector::const_iterator it = imp.names.begin(); it != imp.names.end(); ++it)
                rslt->import().push_back(*it);
            return rslt;
        }




        //  compile_assignments

        void compile_assignments(const x680::syntactic::module& mod, module_entity_ptr mdl) {
            for (x680::syntactic::assignment_vector::const_iterator it = mod.elements.begin(); it != mod.elements.end(); ++it) {
                if (basic_entity_ptr rs = compile_assignment(mdl, *it))
                    mdl->childs().push_back(rs);
            }
        }


        //  compile_assignment        

        basic_entity_ptr compile_assignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            entity_enum tp = et_Nodef;
            basic_entity_ptr rslt;
            switch (ent.which()) {
                case 0: return compile_typeassignment(scope, ent);
                case 1: return compile_valueassignment(scope, ent);
                case 2: return compile_valuesetassignment(scope, ent);
                case 3: return compile_classassignment(scope, ent);
                case 6: return compile_bigassignment(scope, ent);
            }
            return rslt;
        }

        typeassigment_entity_ptr compile_typeassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::type_assignment tmp = boost::get<x680::syntactic::type_assignment>(ent);
            typeassigment_entity_ptr tmpt(new typeassigment_entity(scope, tmp.identifier, compile_type(scope, tmp.type)));
            switch (tmp.type.builtin_t) {
                case t_SEQUENCE:
                case t_SEQUENCE_OF:
                case t_SET:
                case t_SET_OF:
                case t_CHOICE: tmpt->childs() = compile_structtype(tmpt, tmp.type);
                default:
                {
                };
            }
            tmpt->type()->predefined(compile_typepredef(tmpt, tmp.type));
            return tmpt;
        }

        basic_entity_vector compile_structtype(basic_entity_ptr scope, const x680::syntactic::type_element& ent) {
            basic_entity_vector rslt;
            for (x680::syntactic::named_type_element_vector::const_iterator it = ent.elements.begin(); it != ent.elements.end(); ++it) {
                rslt.push_back(compile_namedtype(scope, *it));
            }
            return rslt;
        }

        typeassigment_entity_ptr compile_namedtype(basic_entity_ptr scope, const x680::syntactic::type_assignment& ent) {
            type_atom_ptr tmp = compile_type(scope, ent.type);
            typeassigment_entity_ptr tmpt;
            if (ent.type.marker == mk_default) {
                tmpt = namedtypeassigment_entity_ptr(new namedtypeassigment_entity(scope, ent.identifier, tmp, compile_value(scope, ent.type.value)));
            } else {
                tmpt = namedtypeassigment_entity_ptr(new namedtypeassigment_entity(scope, ent.identifier, tmp, ent.type.marker));
            }
            tmpt->type()->predefined(compile_typepredef(tmpt, ent.type));
            switch (ent.type.builtin_t) {
                case t_SEQUENCE:
                case t_SEQUENCE_OF:
                case t_SET:
                case t_SET_OF:
                case t_CHOICE: tmpt->childs() = compile_structtype(tmpt, ent.type);
                default:
                {
                };
            }
            return tmpt;
        }

        type_atom_ptr compile_type(basic_entity_ptr scope, const x680::syntactic::type_element& ent) {
            if (ent.builtin_t == t_ClassField)
                return type_atom_ptr(new type_atom(scope, ent.builtin_t, compile_tag(scope, ent.tag)));
            type_atom_ptr tmp = ent.reference.empty() ? type_atom_ptr(new type_atom(scope, ent.builtin_t, compile_tag(scope, ent.tag))) :
                    type_atom_ptr(new type_atom(scope, ent.reference, ent.builtin_t, compile_tag(scope, ent.tag)));

            return tmp;
        }

        predefined_ptr compile_typepredef(basic_entity_ptr scope, const x680::syntactic::type_element& ent) {
            if (ent.predefined.empty())
                return predefined_ptr();
            basic_entity_vector rslt;
            for (x680::syntactic::value_element_vector::const_iterator it = ent.predefined.begin(); it != ent.predefined.end(); ++it) {
                if (it->type == v_extention) {
                    extention_entity_ptr el(new extention_entity());
                    rslt.push_back(el);
                } else {
                    if (it->value.empty()) {
                        if (it->values.empty()) {
                            valueassigment_entity_ptr el(new valueassigment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)), value_atom_ptr()));
                            rslt.push_back(el);
                        } else {
                            try {
                                valueassigment_entity_ptr el(new valueassigment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                        value_atom_ptr(new numvalue_atom(boost::lexical_cast<int > (it->values.begin()->identifier)))));
                                rslt.push_back(el);
                            } catch (boost::bad_lexical_cast) {
                                valueassigment_entity_ptr el(new valueassigment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                        value_atom_ptr(new definedvalue_atom(it->values.begin()->identifier, scope))));
                                rslt.push_back(el);
                            }
                        }
                    } else {
                        try {
                            valueassigment_entity_ptr el(new valueassigment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                    value_atom_ptr(new numvalue_atom(boost::lexical_cast<int > (it->value)))));
                            rslt.push_back(el);
                        } catch (boost::bad_lexical_cast) {
                            valueassigment_entity_ptr el(new valueassigment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                    value_atom_ptr(new definedvalue_atom(it->fromreff, scope))));
                            rslt.push_back(el);
                        }
                    }
                }
            }
            predefined_ptr tmp(new predefined(scope, ent.builtin_t));
            tmp->values(rslt);
            return tmp;
        }

        tagged_ptr compile_tag(basic_entity_ptr scope, const x680::syntactic::tag_type& ent) {
            if (ent.number.empty())
                return tagged_ptr();
            try {
                value_atom_ptr nm(new numvalue_atom(boost::lexical_cast<int > (ent.number)));
                return tagged_ptr(new tagged(nm, ent.class_, ent.rule));
            } catch (...) {
            }
            value_atom_ptr nm(new definedvalue_atom(ent.number, scope));
            return tagged_ptr(new tagged(nm, ent.class_, ent.rule));
        }

        classassigment_entity_ptr compile_classassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::class_assignment tmp = boost::get<x680::syntactic::class_assignment>(ent);
            return classassigment_entity_ptr(new classassigment_entity(scope, tmp.identifier, compile_class(tmp.class_)));
        }

        class_atom_ptr compile_class(const x680::syntactic::class_element& ent) {
            return ent.reference.empty() ? class_atom_ptr(new class_atom(ent.tp)) : class_atom_ptr(new class_atom(ent.reference, ent.tp));
        }

        valueassigment_entity_ptr compile_valueassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::value_assignment tmp = boost::get<x680::syntactic::value_assignment>(ent);
            valueassigment_entity_ptr tmpt(new valueassigment_entity(scope, tmp.identifier, compile_type(scope, tmp.type), value_atom_ptr()));
            value_atom_ptr tmpv = compile_value(tmpt, tmp.value);
            tmpt->value(tmpv);
            tmpt->type()->predefined(compile_typepredef(tmpt, tmp.type));
            return tmpt;
        }

        value_atom_ptr compile_value(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            try {
                switch (ent.type) {
                    case v_boolean: return value_atom_ptr(new boolvalue_atom(ent.value == "TRUE"));
                    case v_number: return value_atom_ptr(new numvalue_atom(boost::lexical_cast<int > (ent.value)));
                    case v_real: return compile_realvalue(scope, ent.value);
                    case v_null: return value_atom_ptr(new nullvalue_atom());
                    case v_empty: return value_atom_ptr(new emptyvalue_atom());
                    case v_named_value: return compile_namedvalue(scope, ent);
                    case v_bstring:
                    case v_hstring:
                    case v_cstring: return value_atom_ptr(new strvalue_atom(ent.value, ent.type));
                    case v_struct: return value_atom_ptr(new structvalue_atom(compile_structvalue(scope, ent)));
                    case v_objectid: return value_atom_ptr(new objidvalue_atom(compile_objidvalue(scope, ent)));
                    case v_defined_list:
                    case v_number_list:
                    case v_value_list: return value_atom_ptr(new listvalue_atom(ent.type, compile_listvalue(scope, ent)));
                    case v_defined: return value_atom_ptr(new definedvalue_atom(ent.identifier, scope));
                    case v_defined_assign: return compile_assignvalue(scope, ent);
                    case v_choice: return compile_choicevalue(scope, ent);
                    case v_open: return compile_openvalue(scope, ent);
                    default:
                    {
                    }
                }
            } catch (boost::bad_lexical_cast) {
            }
            return value_atom_ptr(new value_atom(scope, v_nodef));
        }

        value_atom_ptr compile_assignvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            try {
                if (ent.value.empty()) {
                    if (!ent.values.empty()) {
                        value_atom_ptr tmp = compile_value(scope, *(ent.values.begin()));
                        return value_atom_ptr(new assignvalue_atom(ent.identifier, tmp));
                    }
                } else {
                    value_atom_ptr tmp(new numvalue_atom(boost::lexical_cast<int > (ent.value)));
                    return value_atom_ptr(new assignvalue_atom(ent.identifier, tmp));
                }
            } catch (boost::bad_lexical_cast) {
            }
            return value_atom_ptr(new value_atom(scope, v_nodef));
        }

        value_atom_ptr compile_realvalue(basic_entity_ptr scope, const std::string& val) {
            try {
                if (val == "PLUS-INFINITY")
                    return value_atom_ptr(new realvalue_atom(std::numeric_limits<double>::infinity()));
                if (val == "MINUS-INFINITY")
                    return value_atom_ptr(new realvalue_atom(-std::numeric_limits<double>::infinity()));
                if (val == "NOT-A-NUMBER")
                    return value_atom_ptr(new realvalue_atom(-std::numeric_limits<double>::signaling_NaN()));
                return value_atom_ptr(new realvalue_atom(boost::lexical_cast<double > (val)));
            } catch (boost::bad_lexical_cast) {
            }
            return value_atom_ptr(new value_atom(scope, v_nodef));
        }

        value_atom_ptr compile_choicevalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            if (!ent.values.empty()) {
                value_atom_ptr tmp = compile_value(scope, *(ent.values.begin()));
                return value_atom_ptr(new choicevalue_atom(ent.identifier, tmp));
            }
            return value_atom_ptr(new value_atom(scope, v_nodef));
        }

        value_atom_ptr compile_openvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            if (ent.typevalue) {
                return value_atom_ptr(new openvalue_atom(compile_type(scope, ent.typevalue->type), compile_value(scope, ent.typevalue->value)));
            }
            return value_atom_ptr(new value_atom(scope, v_nodef));
        }

        value_atom_ptr compile_namedvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            if (!ent.values.empty())
                return value_atom_ptr(new namedvalue_atom(ent.identifier, compile_value(scope, *(ent.values.begin()))));
            return value_atom_ptr(new value_atom(scope, v_nodef));
        }

        value_vct compile_structvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            value_vct rslt;
            if ((ent.type == v_struct)) {
                for (x680::syntactic::value_element_vector::const_iterator it = ent.values.begin(); it != ent.values.end(); ++it) {
                    if (!it->values.empty()) {
                        rslt.push_back(value_atom_ptr(new namedvalue_atom(it->identifier, compile_value(scope, *(it->values.begin())))));
                    }
                }
            }
            return rslt;
        }

        value_vct compile_objidvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            value_vct rslt;
            if ((ent.type == v_objectid)) {
                for (x680::syntactic::value_element_vector::const_iterator it = ent.values.begin(); it != ent.values.end(); ++it) {
                    rslt.push_back(value_atom_ptr(compile_value(scope, *it)));
                }
            }
            return rslt;
        }

        value_vct compile_listvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            value_vct rslt;
            for (x680::syntactic::value_element_vector::const_iterator it = ent.values.begin(); it != ent.values.end(); ++it) {
                rslt.push_back(value_atom_ptr(compile_value(scope, *it)));
            }
            return rslt;
        }

        valuesetassigment_entity_ptr compile_valuesetassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::valueset_assignment tmp = boost::get<x680::syntactic::valueset_assignment>(ent);
            return valuesetassigment_entity_ptr(new valuesetassigment_entity(scope, tmp.identifier, compile_type(scope, tmp.type), basic_atom_ptr()));
        }

        bigassigment_entity_ptr compile_bigassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::unknown_tc_assignment tmp = boost::get<x680::syntactic::unknown_tc_assignment>(ent);
            return bigassigment_entity_ptr(new bigassigment_entity(scope, tmp.identifier, compile_test(tmp.unknown_tc.reff)));
        }

        basic_atom_ptr compile_test(const std::string& rf) {
            return basic_atom_ptr(new basic_atom(rf));
        }


    }











    /////////////////////////////////////////////////////////////////////////   
    // std::cout  tree
    /////////////////////////////////////////////////////////////////////////    

    std::ostream& indent(std::ostream& stream, typeassigment_entity* self) {
        if (self) {
            int inten = self->level();
            if (inten > 0) inten--;
            while (inten) {
                stream << "    ";
                inten--;
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, global_entity* self) {
        stream << "GLOBAL SCOPE:" << "\n";
        for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
            if ((*it)->as_module())
                stream << (*it)->as_module();
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, import_entity* self) {
        if (self->scope())
            stream << "      from module: " << self->name();
        else
            stream << "      from module: " << self->name() << "(?)";
        if (self->objectid())
            stream << " {" << self->objectid().get() << " }";
        stream << "\n      symbol: ";
        for (import_vector::iterator it = self->import().begin(); it != self->import().end(); ++it) {
            stream << *it << ", ";
        }
        stream << "\n";
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, module_entity* self) {
        stream << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        stream << "module: " << self->name();
        if (self->objectid())
            stream << " {" << self->objectid().get() << " }";
        stream << " \nfile:" << self->file() << "\n";

        stream << "----------------------------------------------------------\n";
        if (self->allexport())
            stream << "      export ALL\n ";

        stream << "      export: ";
        for (export_vector::iterator it = self->exports().begin(); it != self->exports().end(); ++it) {
            stream << *it << ", ";
        }

        stream << "\n----------------------------------------------------------\n";
        stream << "      IMPORTS: ";
        for (basic_entity_vector::iterator it = self->imports().begin(); it != self->imports().end(); ++it) {
            stream << "\n.............................................................................................\n";
            stream << "      import: \n";
            if ((*it)->as_import())
                stream << (*it)->as_import();
        }
        stream << "     \n";
        for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
            if ((*it)->as_bigassigment()) {
                stream << (*it)->as_bigassigment();
                continue;
            }
            if ((*it)->as_littleassigment()) {
                stream << (*it)->as_littleassigment();
                continue;
            }
            if ((*it)->as_typeassigment()) {
                stream << (*it)->as_typeassigment();
                continue;
            }
            if ((*it)->as_valueassigment()) {
                stream << (*it)->as_valueassigment();
                continue;
            }
            if ((*it)->as_classassigment()) {
                stream << (*it)->as_classassigment();
                continue;
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, expectdef_entity* self) {
        return stream << self->name() << "(?)";
    }

    std::ostream& operator<<(std::ostream& stream, extention_entity* self) {
        return stream << " ...";
    }

    std::ostream& operator<<(std::ostream& stream, basic_atom* self) {
        if (self->as_type())
            return stream << self->as_type()->builtin();
        if (self->as_value())
            return stream << self->as_value();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, predefined* self) {
        if (self->extended())
            stream << "{$(...) ";
        else
            stream << "{$ ";
        for (basic_entity_vector::const_iterator it = self->values().begin(); it != self->values().end(); ++it) {
            if (it != self->values().begin())
                stream << " ,";
            stream << (*it)->name();
            if ((*it)->as_extention())
                stream << "...";
            if (((*it)->as_valueassigment()) && ((*it)->as_valueassigment()->value())) {
                stream << "( " << (*it)->as_valueassigment()->value().get() << ")";
            };
        }
        return stream << " $}";
    }

    std::ostream& operator<<(std::ostream& stream, tagclass_type self) {
        switch (self) {
            case tcl_universal: return stream << "UNIVERSAL ";
            case tcl_application: return stream << "APPLICATION ";
            case tcl_private: return stream << "PRIVATE ";
            case tcl_context: return stream << "";
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, tagrule_type self) {
        switch (self) {
            case explicit_tags: return stream << "EXPLICIT ";
            case implicit_tags: return stream << "IMPLICIT ";
            case automatic_tags: return stream << "AUTOMATIC ";
            default: return stream;
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, tagged& self) {
        if (self.number()) {
            if (self.rule() == noset_tags)
                return stream << " [" << self._class() << " " << self.number().get() << "] ";
            else
                return stream << " [ " << self.rule() << self._class() << " " << self.number().get() << "] ";
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, type_atom* self) {
        if (self->tag()) {
            stream << *(self->tag());
        }
        if (self->builtin() == t_Reference) {
            if (self->reff()->as_expectdef())
                stream << "??? *" << self->reff()->name();
            else {
                stream << " *" << self->externalpreff() << self->reff()->name();
                if (self->rooted())
                    stream << "(@" << self->root() << ")";
            }
        } else {
            stream << self->builtin();
        }
        if (self->predefined())
            stream << self->predefined().get();

        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, defined_type self) {
        switch (self) {
            case t_NODEF: return stream << "NODEF";
            case t_BOOLEAN: return stream << "BOOLEAN";
            case t_INTEGER: return stream << "INTEGER";
            case t_BIT_STRING: return stream << "BIT_STRING";
            case t_OCTET_STRING: return stream << "OCTET_STRING";
            case t_NULL: return stream << "NULL";
            case t_OBJECT_IDENTIFIER: return stream << "OBJECT_IDENTIFIER";
            case t_ObjectDescriptor: return stream << "ObjectDescriptor";
            case t_EXTERNAL: return stream << "EXTERNAL";
            case t_REAL: return stream << "REAL";
            case t_ENUMERATED: return stream << "ENUMERATED";
            case t_EMBEDDED_PDV: return stream << "EMBEDDED_PDV";
            case t_UTF8String: return stream << "UTF8String";
            case t_RELATIVE_OID: return stream << "RELATIVE_OID";
            case t_SEQUENCE: return stream << "SEQUENCE";
            case t_SEQUENCE_OF: return stream << "SEQUENCE_OF";
            case t_SET: return stream << "SET";
            case t_SET_OF: return stream << "SET_OF";
            case t_NumericString: return stream << "NumericString";
            case t_PrintableString: return stream << "PrintableString";
            case t_T61String: return stream << "T61String";
            case t_VideotexString: return stream << "VideotexString";
            case t_IA5String: return stream << "IA5String";
            case t_UTCTime: return stream << "UTCTime";
            case t_GeneralizedTime: return stream << "GeneralizedTime";
            case t_GraphicString: return stream << "GraphicString";
            case t_VisibleString: return stream << "VisibleString";
            case t_GeneralString: return stream << "GeneralString";
            case t_UniversalString: return stream << "UniversalString";
            case t_CHARACTER_STRING: return stream << "CHARACTER_STRING";
            case t_BMPString: return stream << "BMPString";
            case t_TIME: return stream << "TIME";
            case t_TIME_OF_DAY: return stream << "TIME_OF_DAY";
            case t_DATE: return stream << "DATE";
            case t_DATE_TIME: return stream << "DATE_TIME";
            case t_DURATION: return stream << "DURATION";
            case t_CHOICE: return stream << "CHOICE";
            case t_Selection: return stream << "Selection";
            case t_Instance_Of: return stream << "Instance_Of";
            case t_RELATIVE_OID_IRI: return stream << "RELATIVE_OID_IRI";
            case t_OID_IRI: return stream << "OID_IRI";
            case t_ANY: return stream << "ANY";
            case t_ClassField: return stream << "ClassField";
            case t_TypeFromObject: return stream << "TypeFromObject";
            case t_ValueSetFromObjects: return stream << "ValueSetFromObjects";
            case t_Reference: return stream << "";
            default:
            {
            };
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, value_atom* self) {
        switch (self->valtype()) {
            case v_boolean: return (stream << self->as_bool());
            case v_number: return (stream << self->as_number());
            case v_real: return (stream << self->as_real());
            case v_null: return (stream << self->as_null());
            case v_empty: return (stream << self->as_empty());
            case v_named_value: return (stream << self->as_named());
            case v_hstring:
            case v_bstring:
            case v_cstring: return (stream << self->as_cstr());
            case v_struct: return (stream << self->as_struct());
            case v_objectid: return (stream << self->as_objid());
            case v_defined_list:
            case v_number_list:
            case v_value_list: return (stream << self->as_list());
            case v_defined: return (stream << self->as_defined());
            case v_defined_assign: return (stream << self->as_assign());
            case v_choice: return (stream << self->as_choice());
            case v_open: return (stream << self->as_open());
            default:
            {
            }
        }
        return stream << "?: " << (int) self->valtype();
    }

    std::ostream& operator<<(std::ostream& stream, numvalue_atom* self) {
        return stream << "(" << self->value() << ")";
    }

    std::ostream& operator<<(std::ostream& stream, realvalue_atom* self) {
        return stream << "(" << self->value() << ")";
    }

    std::ostream& operator<<(std::ostream& stream, boolvalue_atom* self) {
        if (self->value())
            return stream << "(TRUE)";
        else
            return stream << "(FALSE)";
    }

    std::ostream& operator<<(std::ostream& stream, strvalue_atom* self) {
        stream << "('";
        switch (self->valtype()) {
            case v_hstring: stream << "&H ";
                break;
            case v_bstring: stream << "&B ";
                break;
            default:
            {
            }
        }
        return stream << self->value() << "')";
    }

    std::ostream& operator<<(std::ostream& stream, namedvalue_atom* self) {
        return stream << self->name() << " : " << self->value();
    }

    std::ostream& operator<<(std::ostream& stream, structvalue_atom* self) {
        stream << " { ";
        for (value_vct::const_iterator it = self->values().begin(); it != self->values().end(); ++it) {
            if (it != self->values().begin())
                stream << ",  ";
            stream << (*it).get();
        }
        return stream << "}";
    }

    std::ostream& operator<<(std::ostream& stream, objidvalue_atom* self) {
        stream << " { ";
        for (value_vct::const_iterator it = self->values().begin(); it != self->values().end(); ++it) {
            if (it != self->values().begin())
                stream << "  ";
            stream << (*it).get();
        }
        return stream << "}";
    }

    std::ostream& operator<<(std::ostream& stream, listvalue_atom* self) {
        stream << " { ";
        for (value_vct::const_iterator it = self->values().begin(); it != self->values().end(); ++it) {
            if (it != self->values().begin())
                stream << ",  ";
            stream << (*it).get();
        }
        return stream << "}";
    }

    std::ostream& operator<<(std::ostream& stream, definedvalue_atom* self) {
        if (self->reff()) {
            if (self->reff()->as_expectdef())
                return stream << "??? *" << self->reff()->name();
            else {
                stream << " *" << self->reff()->name();
                if (self->rooted())
                    stream << "(@" << self->root() << ")";
                return stream;
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, assignvalue_atom* self) {
        return stream << "(" << self->name() << "(" << self->value().get() << ") )";
    }

    std::ostream& operator<<(std::ostream& stream, choicevalue_atom* self) {
        return stream << "(" << self->name() << " : " << self->value().get() << ")";
    }

    std::ostream& operator<<(std::ostream& stream, openvalue_atom* self) {
        return stream << "(" << self->type().get() << " : " << self->value().get() << ")";
        ;
    }

    std::ostream& operator<<(std::ostream& stream, nullvalue_atom* self) {
        return stream << "(NULL)";
    }

    std::ostream& operator<<(std::ostream& stream, emptyvalue_atom* self) {
        return stream << "({})";
    }

    std::ostream& operator<<(std::ostream& stream, bigassigment_entity* self) {
        return stream << "(?B)" << self->name() << " :: = " << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, littleassigment_entity* self) {
        return stream << "(?l)" << self->name() << " [" << "] :: = " << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, typeassigment_entity* self) {
        if (self->as_named()) {
            indent(stream, self);
            stream << self->name() << " ";
            if (self->as_named()->marker() == mk_components_of)
                stream << self->name() << "COMPONENTS OF ";
            stream << self->type() << " ";
            operatorstruct(stream, self);
            stream << self->as_named()->marker();
            if ((self->as_named()->_default()) && (self->as_named()->marker() == mk_default))
                stream << " " << self->as_named()->_default().get();
        } else {
            stream << "(T) " << self->name() << " :: = " << self->type().get();
            operatorstruct(stream, self);
        }
        return stream << "\n";
        ;
    }

    std::ostream& operatorstruct(std::ostream& stream, typeassigment_entity* self) {
        switch (self->type()->builtin()) {
            case t_SEQUENCE:
            case t_SEQUENCE_OF:
            case t_SET:
            case t_SET_OF:
            case t_CHOICE:;
            {
                stream << " {" << "\n";
                for (basic_entity_vector::const_iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                    if ((*it)->as_typeassigment())
                        stream << (*it)->as_typeassigment();
                }
                indent(stream, self);
                stream << "}" << " ";
                break;
            }
            default:
            {
                stream << " ";
            };
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, tagmarker_type self) {
        switch (self) {
                //case mk_none:
            case mk_default: stream << " DEFAULT ";
                break;
            case mk_optional: stream << " OPTIONAL ";
                break;
                //case mk_components_of:        
            default:
            {
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, valueassigment_entity* self) {
        stream << "(v) " << self->name() << " [" << self->type().get() << "] :: = ";
        if (self->value())
            return stream << self->value().get() << "\n";
        return stream << "???" << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, valuesetassigment_entity* self) {
        return stream << "(vS) " << self->name() << " [" << self->type().get() << "] :: = " << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, classassigment_entity* self) {
        return stream << "(C) " << self->name() << " :: = " << self->_class().get() << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, class_atom* self) {
        if (self->builtin() == cl_Reference) {
            if (self->reff()->as_expectdef())
                stream << "???" << self->reff()->name();
            else
                stream << self->reff()->name();
        } else {
            stream << self->builtin();
        }
        //stream << " id: " << self->name();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, definedclass_type self) {
        switch (self) {
            case cl_SpecDef: return stream << "spec: ";
            case cl_TYPE_IDENTIFIER: return stream << "TYPE-IDENTIFIER";
            case cl_ABSTRACT_SYNTAX: return stream << "ABSTRACT-SYNTAX";
            case cl_Reference: return stream << "";
            default:
            {
            };
        }
        return stream;
    }
}