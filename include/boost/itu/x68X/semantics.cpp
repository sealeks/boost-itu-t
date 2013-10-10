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

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "itu-t",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(0)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "ccitt",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(0)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "iso",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(1)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "joint-iso-itu-t",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(2)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "joint-iso-ccitt",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(2)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "recommendation",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(0)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "question",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(1)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "administration",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(2)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "network-operator",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(3)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "identified-organization",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(4)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "r-recommendation",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(5)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "standard",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(0)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "registration-authority",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(1)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, "member-body",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(2)))));

        insert_assigment(global, valueassignment_entity_ptr(new valueassignment_entity(global, " identified-organization",
                type_atom_ptr(new type_atom(global, t_INTEGER)), value_atom_ptr(new numvalue_atom(3)))));



        // ABSTRACT-SYNTAX        

        classassignment_entity_ptr ASCL = classassignment_entity_ptr(new classassignment_entity(global, "ABSTRACT-SYNTAX"));

        ASCL->_class(class_atom_ptr(new class_atom(ASCL, cl_ABSTRACT_SYNTAX)));

        ASCL->childs().push_back(basic_entity_ptr(new valuefield_entity(ASCL, "&id",
                type_atom_ptr(new type_atom(ASCL, t_OBJECT_IDENTIFIER)), true)));
        ASCL->childs().push_back(basic_entity_ptr(new typefield_entity(ASCL, "&Type")));
        ASCL->childs().push_back(basic_entity_ptr(new valuefield_entity(ASCL, "&property",
                type_atom_ptr(new type_atom(ASCL, t_BIT_STRING)), value_atom_ptr(new emptyvalue_atom()))));
        predefined_ptr predef_abstrsyn = predefined_ptr(new predefined(ASCL, t_BIT_STRING));
        predef_abstrsyn->values().push_back(valueassignment_entity_ptr(new valueassignment_entity(ASCL, "handles-invalid-encodings",
                type_atom_ptr(new type_atom(ASCL, t_INTEGER)), value_atom_ptr(new numvalue_atom(0)))));
        ASCL->childs()[2]->as_classfield()->as_valuefield()->type()->predefined(predef_abstrsyn);

        ASCL->withsyntax(withsyntax_atom(new groupsyntax_atom(ASCL, "", syntax_atom_vct(), false)));
        ASCL->withsyntax()->as_group()->group().push_back(syntax_atom_ptr(new syntax_atom(ASCL, "", "&Type")));
        ASCL->withsyntax()->as_group()->group().back()->reff(ASCL->childs()[1]);
        ASCL->withsyntax()->as_group()->group().push_back(syntax_atom_ptr(new syntax_atom(ASCL, "IDENTIFIED BY", "&d")));
        ASCL->withsyntax()->as_group()->group().back()->reff(ASCL->childs()[0]);
        ASCL->withsyntax()->as_group()->group().push_back(syntax_atom_ptr(new syntax_atom(ASCL, "HAS PROPERTY", "&property", true)));
        ASCL->withsyntax()->as_group()->group().back()->reff(ASCL->childs()[2]);

        insert_assigment(global, ASCL);


        // TYPE-IDENTIFIER

        classassignment_entity_ptr TPID = classassignment_entity_ptr(new classassignment_entity(global, "TYPE-IDENTIFIER"));

        TPID->_class(class_atom_ptr(new class_atom(TPID, cl_ABSTRACT_SYNTAX)));

        TPID->childs().push_back(basic_entity_ptr(new valuefield_entity(TPID, "&id",
                type_atom_ptr(new type_atom(TPID, t_OBJECT_IDENTIFIER)), true)));
        TPID->childs().push_back(basic_entity_ptr(new typefield_entity(TPID, "&Type")));

        TPID->withsyntax(withsyntax_atom(new groupsyntax_atom(TPID, "", syntax_atom_vct(), false)));
        TPID->withsyntax()->as_group()->group().push_back(syntax_atom_ptr(new syntax_atom(TPID, "", "&Type")));
        TPID->withsyntax()->as_group()->group().back()->reff(TPID->childs()[1]);
        TPID->withsyntax()->as_group()->group().push_back(syntax_atom_ptr(new syntax_atom(TPID, "IDENTIFIED BY", "&d")));
        TPID->withsyntax()->as_group()->group().back()->reff(TPID->childs()[0]);

        insert_assigment(global, TPID);

    }



    /////////////////////////////////////////////////////////////////////////   
    //  BASIC
    /////////////////////////////////////////////////////////////////////////
    // basic_entity
    ///////////////////////////////////////////////////////////////////////// 

    void basic_entity::scope(basic_entity_ptr vl) {
        if (vl && (vl.get() == this))
            throw semantics::error("Internal error selfscoping :" + name());
        scope_ = basic_entity_wptr(vl);
    }

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

    assignment_entity * basic_entity::as_assigment() {
        return dynamic_cast<assignment_entity*> (this);
    }

    bigassignment_entity * basic_entity::as_bigassigment() {
        return dynamic_cast<bigassignment_entity*> (this);
    }

    voassignment_entity * basic_entity::as_voassigment() {
        return dynamic_cast<voassignment_entity*> (this);
    }

    soassignment_entity * basic_entity::as_soassigment() {
        return dynamic_cast<soassignment_entity*> (this);
    }

    typeassignment_entity * basic_entity::as_typeassigment() {
        return dynamic_cast<typeassignment_entity*> (this);
    }

    valueassignment_entity * basic_entity::as_valueassigment() {
        return dynamic_cast<valueassignment_entity*> (this);
    }

    valuesetassignment_entity * basic_entity::as_valuesetassigment() {
        return dynamic_cast<valuesetassignment_entity*> (this);
    }

    classassignment_entity * basic_entity::as_classassigment() {
        return dynamic_cast<classassignment_entity*> (this);
    }

    objectassignment_entity * basic_entity::as_objectassigment() {
        return dynamic_cast<objectassignment_entity*> (this);
    }

    objectsetassignment_entity * basic_entity::as_objectsetassigment() {
        return dynamic_cast<objectsetassignment_entity*> (this);
    }

    field_entity* basic_entity::as_classfield() {
        return dynamic_cast<field_entity*> (this);
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
        else if (as_valuesetassigment())
            rslt = rslt + " in valuesetassignment";
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

    void basic_entity::referenceerror_throw(const std::string& val, const std::string& msg) {
        std::string rslt = msg + "'" + val + "'";
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



    ////////

    basic_entity_ptr basic_entity::find(const basic_entity_ptr& reff, bool all) {
        if (reff->as_expectdef()) {
            if (reff->as_expectdef()->ismodule()) {
                if (reff->moduleref())
                    return reff->moduleref()->find_in_importmodule(reff->as_expectdef()->module(), reff->as_expectdef()->name());
                else
                    basic_entity_ptr();
            } else {
                return find_by_name(reff->as_expectdef()->name(), all);
            }
        }
        return reff;
    }

    basic_entity_ptr basic_entity::find_by_name(const std::string& nm, bool all) {
        //throw semantics::error("Idenifier" + nm + " not found");
        return basic_entity_ptr();
    }

    void basic_entity::resolve() {
        //preresolve();
        resolve_child();
    };

    void basic_entity::preresolve() {
    };

    void basic_entity::resolve_child() {
        for (basic_entity_vector::const_iterator it = childs().begin(); it != childs().end(); ++it) {
            (*it)->resolve();
        }
    }

    void basic_entity::prefind(const std::string& nm, basic_entity_vector& elm) {
        for (basic_entity_vector::iterator it = elm.begin(); it != elm.end(); ++it) {
            if ((*it)->name() == nm) {
                if (((*it)->kind() == et_Nodef))
                    *it = module_entity::preresolve_nodef_assigment(*it);
                if (((*it)->kind() == et_NodefV))
                    *it = module_entity::preresolve_nodefv_assigment(*it);
                if (((*it)->kind() == et_NodefS))
                    *it = module_entity::preresolve_nodefs_assigment(*it);
            }
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
        preresolve();
        apply_fields();
        resolve_child();
    }

    void global_entity::preresolve() {
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->as_module())
                (*it)->as_module()->preresolve_oid();
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->as_module())
                (*it)->as_module()->preresolve_externalref();
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->as_module())
                (*it)->as_module()->preresolve();
    }

    basic_entity_ptr global_entity::find_by_name(const std::string& nm, bool all) {
        prefind(nm, childs());
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->name() == nm)
                return *it;
        return basic_entity_ptr();
    }

    void global_entity::apply_fields() {
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->as_module())
                (*it)->as_module()->apply_fields();
    }


    /////////////////////////////////////////////////////////////////////////
    // import_entity
    /////////////////////////////////////////////////////////////////////////

    import_entity::import_entity(const std::string& nm)
    : basic_entity(nm, et_Import) {
    }

    void import_entity::resolve() {
        if (objectid())
            objectid()->resolve();
    }

    basic_entity_ptr import_entity::find_by_name(const std::string& nm, bool all) {
        for (import_vector::iterator it = import_.begin(); it != import_.end(); ++it)
            if (((*it) == nm) && (scope()))
                return scope()->find_by_name(nm, all);
        return basic_entity_ptr();
    }

    /////////////////////////////////////////////////////////////////////////   
    // module_entity
    /////////////////////////////////////////////////////////////////////////   

    module_entity::module_entity(basic_entity_ptr scope, const std::string& nm, const std::string& fl, bool allexp)
    : basic_entity(scope, nm, et_Module), file_(fl), allexport_(allexp) {
    }

    /////

    basic_entity_ptr module_entity::find_by_name(const std::string& nm, bool all) {
        prefind(nm, childs());
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->name() == nm)
                return *it;
        for (basic_entity_vector::iterator it = imports().begin(); it != imports().end(); ++it) {
            import_entity* importmod = (*it)->as_import();
            if (importmod) {
                basic_entity_ptr fnd = importmod->find_by_name(nm, all);
                if (fnd)
                    return fnd;
            }
        }
        if (scope())
            return scope()->find_by_name(nm, all);
        return basic_entity_ptr();
    }

    basic_entity_ptr module_entity::find_in_importmodule(const std::string& mod, const std::string& nm) {
        for (basic_entity_vector::iterator it = imports().begin(); it != imports().end(); ++it) {
            import_entity* importmod = (*it)->as_import();
            if (importmod && (importmod->name() == mod) && (importmod->scope()))
                return importmod->find_by_name(nm);
        }
        return basic_entity_ptr();
    }

    void module_entity::resolve() {
        resolve_child();
    }

    void module_entity::preresolve_externalref() {
        if (allexport()) {
            for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
                exports().push_back((*it)->name());
        }
        for (basic_entity_vector::iterator it = imports().begin(); it != imports().end(); ++it) {
            import_entity* importmod = (*it)->as_import();
            if (importmod && (importmod->objectid())) {
                importmod->objectid()->resolve();
            }
        }
        for (basic_entity_vector::iterator it = imports().begin(); it != imports().end(); ++it) {
            import_entity* importmod = (*it)->as_import();
            if (importmod) {
                basic_entity_ptr finded = findmodule(importmod->objectid(), importmod->name());
                if (finded && (finded->as_module())) {
                    importmod->scope(finded);
                } else {
                    throw semantics::error("Not find imported module: " + importmod->name() +
                            " in module: " + name() + " in file: " + file());
                }
            }
        }
    }

    void module_entity::preresolve() {
        unicalelerror_throw(childs());
        preresolve_assigments(childs_);
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->as_assigment())
                (*it)->as_assigment()->preresolve();
    }

    void module_entity::preresolve_oid() {
        if (objectid()) {
            objectid()->resolve();
        }
    }

    basic_entity_ptr module_entity::findmodule(const std::string& nm) {
        if (scope() && scope()->as_global()) {
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (((*it)->as_module()) && (nm == (*it)->name()))
                    return *it;
            }
        }
        return basic_entity_ptr();
    }

    void module_entity::apply_fields() {
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
            if ((*it)->as_objectassigment())
                (*it)->as_objectassigment()->apply_fields();
        }
    }

    basic_entity_ptr module_entity::findmodule(value_atom_ptr oid, const std::string& nm) {
        if (!oid)
            return findmodule(nm);
        if (scope() && scope()->as_global()) {
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (((*it)->as_module()) && ((*it)->as_module()->objectid()))
                    if (compareoid((*it)->as_module()->objectid(), oid))
                        return *it;
            }
        }
        return findmodule(nm);
    }

    std::vector<std::string> module_entity::setfrom_objid(value_atom*vls) {
        std::vector<std::string> tmp;
        structvalue_atom*vl = vls->as_list();
        if (!vl) {
            if ((vls->as_defined()->root()) && (vls->as_defined()->root()->as_value()) && (vls->as_defined()->root()->as_value()->as_list()))
                vl = vls->as_defined()->root()->as_value()->as_list();
            else
                throw semantics::error(" Undefined module Object Identificator");
        }
        try {
            for (value_vct::const_iterator it = vl->values().begin(); it != vl->values().end(); ++it) {
                switch ((*it)->valtype()) {
                    case v_number:
                        tmp.push_back(boost::lexical_cast<std::string>((*it)->as_number()->value()));
                        break;
                    case v_defined_assign:
                    {
                        if ((*it)->as_assign()->value()) {
                            if ((*it)->as_assign()->value()->as_number())
                                tmp.push_back(boost::lexical_cast<std::string>((*it)->as_assign()->value()->as_number()->value()));
                            else
                                tmp.push_back((*it)->as_assign()->name());
                            break;
                        }
                    }
                    case v_defined:
                    {
                        if (((*it)->as_defined()->root()) && ((*it)->as_defined()->root()->as_value())) {
                            if ((*it)->as_defined()->root()->as_value()->as_number()) {
                                tmp.push_back(boost::lexical_cast<std::string>((*it)->as_defined()->root()->as_value()->as_number()->value()));
                                break;
                            } else if ((*it)->as_defined()->root()->as_value()->as_objid()) {
                                std::vector<std::string> tmp2 = setfrom_objid((*it)->as_defined()->root()->as_value()->as_objid());
                                tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
                                break;
                            }
                        }
                        tmp.push_back((*it)->as_defined()->expectedname());
                        break;
                    }
                    default:
                    {
                        throw semantics::error(" Undefined module Object Identificator");
                    };
                }
            }
        } catch (boost::bad_lexical_cast) {
            throw semantics::error(" Undefined module Object Identificator");
        }
        return tmp;
    }

    bool module_entity::compareoid(structvalue_atom_ptr ls, value_atom_ptr rs) {
        if (ls && rs)
            return (setfrom_objid(ls.get()) == setfrom_objid(rs.get()));
        return false;
    }

    void module_entity::preresolve_assigments(basic_entity_vector& elm) {
        for (basic_entity_vector::iterator it = elm.begin(); it != elm.end(); ++it) {
            switch ((*it)->kind()) {
                case et_Nodef: *it = preresolve_nodef_assigment(*it);
                    break;
                case et_NodefV: *it = preresolve_nodefv_assigment(*it);
                    break;
                case et_NodefS: *it = preresolve_nodefs_assigment(*it);
                    break;
                default:
                {
                };
            }
        }
    }

    basic_entity_ptr module_entity::preresolve_nodef_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        /*if (!start)
            start = elm;
        else
            check_resolve_ciclic(elm, start);*/
        bigassignment_entity* tmp = elm->as_bigassigment();
        if (tmp && (tmp->big()) && (tmp->big()->reff())) {
            basic_entity_ptr fnd = elm->find(tmp->big()->reff());
            if (fnd) {
                if (fnd->kind() == et_Type) {
                    basic_entity_ptr rslt(new typeassignment_entity(elm->scope(), tmp->name(),
                            type_atom_ptr(new type_atom(elm->scope(), tmp->big()->reff()->name(), t_Reference))));
                    rslt->as_assigment()->arguments(tmp->arguments());
                    swap_arguments_scope(rslt->as_assigment(), rslt);
                    return rslt;
                }
                if (fnd->kind() == et_Class) {
                    basic_entity_ptr rslt(new classassignment_entity(elm->scope(), tmp->name(),
                            class_atom_ptr(new class_atom(elm->scope(), tmp->big()->reff()->name(), cl_Reference))));
                    rslt->as_assigment()->arguments(tmp->arguments());
                    swap_arguments_scope(rslt->as_assigment(), rslt);
                    return rslt;
                }
            } else {
                tmp->referenceerror_throw(tmp->big()->reff()->name());
            }
        }
        tmp->referenceerror_throw(tmp->name());
        return basic_entity_ptr();
    }

    basic_entity_ptr module_entity::preresolve_nodefv_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        /*if (!start)
            start = elm;
        else
            check_resolve_ciclic(elm, start);*/
        voassignment_entity* tmp = elm->as_voassigment();
        if (tmp && (tmp->big()) && (tmp->big()->reff())) {
            basic_entity_ptr fnd = elm->find(tmp->big()->reff());
            if (fnd) {
                if (fnd->kind() == et_Type) {
                    if (tmp->value()) {
                        basic_entity_ptr rslt(new valueassignment_entity(elm->scope(), tmp->name(),
                                type_atom_ptr(new type_atom(elm->scope(), tmp->big()->reff()->name(), t_Reference)), tmp->value()));
                        rslt->as_valueassigment()->value()->swap_scope(rslt);
                        rslt->as_assigment()->arguments(tmp->arguments());
                        swap_arguments_scope(rslt->as_assigment(), rslt);
                        return rslt;
                    } else {
                        tmp->referenceerror_throw(tmp->big()->reff()->name());
                    }
                }
                if (fnd->kind() == et_Class) {
                    if (tmp->object()) {
                        basic_entity_ptr rslt(new objectassignment_entity(elm->scope(), tmp->name(),
                                class_atom_ptr(new class_atom(elm->scope(), tmp->big()->reff()->name(), cl_Reference)), tmp->object()));
                        rslt->as_objectassigment()->object()->swap_scope(rslt);
                        rslt->as_assigment()->arguments(tmp->arguments());
                        swap_arguments_scope(rslt->as_assigment(), rslt);
                        return rslt;
                    } else {
                        tmp->referenceerror_throw(tmp->big()->reff()->name());
                    }
                }
            } else {
                tmp->referenceerror_throw(tmp->big()->reff()->name());
            }
        }
        tmp->referenceerror_throw(tmp->name());
        return basic_entity_ptr();
    }

    basic_entity_ptr module_entity::preresolve_nodefs_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        /*if (!start)
            start = elm;
        else
            check_resolve_ciclic(elm, start);*/
        soassignment_entity* tmp = elm->as_soassigment();
        if (tmp && (tmp->big()) && (tmp->big()->reff())) {
            basic_entity_ptr fnd = elm->find(tmp->big()->reff());
            if (fnd) {
                if (fnd->kind() == et_Type) {
                    if (tmp->valueset()) {
                        basic_entity_ptr rslt(new valuesetassignment_entity(elm->scope(), tmp->name(),
                                type_atom_ptr(new type_atom(elm->scope(), tmp->big()->reff()->name(), t_Reference)), tmp->valueset()));
                        rslt->as_valuesetassigment()->valueset()->swap_scope(rslt);
                        rslt->as_assigment()->arguments(tmp->arguments());
                        swap_arguments_scope(rslt->as_assigment(), rslt);
                        return rslt;
                    } else {
                        tmp->referenceerror_throw(tmp->big()->reff()->name());
                    }
                }
                if (fnd->kind() == et_Class) {
                    if (tmp->objectset()) {
                        basic_entity_ptr rslt(new objectsetassignment_entity(elm->scope(), tmp->name(),
                                class_atom_ptr(new class_atom(elm->scope(), tmp->big()->reff()->name(), cl_Reference)), tmp->objectset()));
                        rslt->as_objectsetassigment()->objectset()->swap_scope(rslt);
                        rslt->as_assigment()->arguments(tmp->arguments());
                        swap_arguments_scope(rslt->as_assigment(), rslt);
                        return rslt;
                    } else {
                        tmp->referenceerror_throw(tmp->big()->reff()->name());
                    }
                }
            } else {
                tmp->referenceerror_throw(tmp->big()->reff()->name());
            }
        }
        tmp->referenceerror_throw(tmp->name());
        return basic_entity_ptr();
    }

    void module_entity::swap_arguments_scope(assignment_entity* assign, basic_entity_ptr newscope) {
        //assign->scope(newscope);
        for (argument_entity_vct::const_iterator it = assign->arguments().begin(); it != assign->arguments().end(); ++it) {
            (*it)->scope(newscope);
            if ((*it)->governor())
                (*it)->governor()->scope(newscope);
        }
    }


    /////////////////////////////////////////////////////////////////////////   
    // expectdef_entity
    /////////////////////////////////////////////////////////////////////////

    expectdef_entity::expectdef_entity(basic_entity_ptr scope, const std::string& nm)
    : basic_entity(scope, nm, et_Nodef) {
        buildreff();
    }

    void expectdef_entity::buildreff() {
        std::string::size_type it = name_.find_first_of('.');
        if (it != std::string::npos) {
            if ((it) && (it < (name_.size() - 1))) {
                if (name_[it + 1] != '&') {
                    module_ = name_.substr(0, it);
                    name_ = name_.substr(it + 1);
                }
            }
        }
    }


    /////////////////////////////////////////////////////////////////////////   
    // argument_entity
    /////////////////////////////////////////////////////////////////////////  

    argument_entity::argument_entity(basic_entity_ptr scope, const std::string& nm, argumentsize_type tp)
    : basic_entity(scope, nm, et_Argument), typesize_(tp), argumenttype_(argm_Nodef) {
    }

    argument_entity::argument_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr gvnr, argumentsize_type tp)
    : basic_entity(scope, nm, et_Argument), typesize_(tp), argumenttype_(argm_Nodef), governor_(gvnr) {
    }

    argument_entity::argument_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr gvnr, argumentsize_type tp)
    : basic_entity(scope, nm, et_Argument), typesize_(tp), argumenttype_(argm_Nodef), governor_(gvnr) {
    }

    argument_entity::argument_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr gvnr, argumentsize_type tp)
    : basic_entity(scope, nm, et_Argument), typesize_(tp), argumenttype_(argm_Nodef), governor_(gvnr) {
    }

    bool argument_entity::has_undef_governor() const {
        return ( governor_ && !((governor_->as_type()) || (governor_->as_class())));
    }

    void argument_entity::governor(basic_atom_ptr vl) {
        governor_ = vl;
    }

    void argument_entity::argumenttype(argument_enum vl) {
        argumenttype_ = vl;
    }



    /////////////////////////////////////////////////////////////////////////   
    // basic_atom
    /////////////////////////////////////////////////////////////////////////   

    basic_atom::basic_atom(basic_entity_ptr scp) : scope_(scp), extention_(false) {
    };

    basic_atom::basic_atom(const std::string& reff, basic_entity_ptr scp) : scope_(scp), extention_(false) {
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
        if ((reff()->as_valuesetassigment()) && (reff()->as_valuesetassigment()->valueset()))
            return reff()->as_valuesetassigment()->valueset()->root();
        if ((reff()->as_classassigment()) && (reff()->as_classassigment()->_class()))
            return reff()->as_classassigment()->_class()->root();
        if ((reff()->as_objectassigment()) && (reff()->as_objectassigment()->object()))
            return reff()->as_objectassigment()->object()->root();
        if ((reff()->as_objectsetassigment()) && (reff()->as_objectsetassigment()->objectset()))
            return reff()->as_objectsetassigment()->objectset()->root();
        return 0;
    }

    bool basic_atom::rooted() {
        return ((root()) && (root() != this));
    }

    type_atom* basic_atom::as_type() {
        return dynamic_cast<type_atom*> (this);
    }

    value_atom* basic_atom::as_value() {
        return dynamic_cast<value_atom*> (this);
    }

    valueset_atom* basic_atom::as_valueset() {
        return dynamic_cast<valueset_atom*> (this);
    }

    class_atom* basic_atom::as_class() {
        return dynamic_cast<class_atom*> (this);
    }

    object_atom* basic_atom::as_object() {
        return dynamic_cast<object_atom*> (this);
    }

    objectset_atom* basic_atom::as_objectset() {
        return dynamic_cast<objectset_atom*> (this);
    }

    void basic_atom::resolve() {
    }

    void basic_atom::swap_scope(basic_entity_ptr to_, basic_entity_ptr from_) {
        if (!from_)
            from_ = scope();
        if ((from_) && (from_ != to_))
            scope_ = to_;
    }

    void basic_atom::resolve_reff(bool all) {
        if ((scope()) && (reff()) && (reff()->as_expectdef())) {
            basic_entity_ptr fnd = scope()->find(reff(), all);
            if (fnd)
                reff(fnd);
            //  else
            //     scope()->referenceerror_throw(expectedname());
        }
    }



    /////////////////////////////////////////////////////////////////////////   
    // ASSIGNMENT
    /////////////////////////////////////////////////////////////////////////         
    // assignment_entity
    /////////////////////////////////////////////////////////////////////////  

    /*basic_entity* basic_atom::root_assignment(basic_entity* assign) {
        if (!assign->reff())
            return assign;
        if ((reff()->as_typeassigment()) && (reff()->as_typeassigment()->type()))
            return reff()->as_typeassigment()->type()->root_assignment();
        if ((reff()->as_valueassigment()) && (reff()->as_valueassigment()->value()))
            return reff()->as_valueassigment()->value()->root_assignment();
        if ((reff()->as_valuesetassigment()) && (reff()->as_valuesetassigment()->valueset()))
            return reff()->as_valuesetassigment()->valueset()->root_assignment();   
        if ((reff()->as_classassigment()) && (reff()->as_classassigment()->_class()))
            return reff()->as_classassigment()->_class()->root_assignment();
        if ((reff()->as_objectassigment()) && (reff()->as_objectassigment()->object()))
            return reff()->as_objectassigment()->object()->root_assignment();
        if ((reff()->as_objectsetassigment()) && (reff()->as_objectsetassigment()->objectset()))
            return reff()->as_objectsetassigment()->objectset()->root_assignment();          
        return 0;
    }*/

    basic_entity_ptr assignment_entity::find_by_name(const std::string& nm, bool all) {
        return basic_entity_ptr();
    }

    void assignment_entity::resolve() {
        for (argument_entity_vct::const_iterator it = arguments_.begin(); it != arguments_.end(); ++it)
            if ((*it)->governor())
                (*it)->governor()->resolve_reff();
    }

    void assignment_entity::preresolve() {
        for (argument_entity_vct::const_iterator it = arguments_.begin(); it != arguments_.end(); ++it) {
            if ((*it)->has_undef_governor()) {
                if (!(*it)->governor()->reff())
                    scope()->referenceerror_throw(scope()->name());
                basic_entity_ptr fnd = scope()->find((*it)->governor()->reff());
                if (fnd) {
                    if (fnd->kind() == et_Type) {
                        (*it)->governor(type_atom_ptr(new type_atom((*it)->scope(), (*it)->governor()->expectedname(), t_Reference)));
                    } else if (fnd->kind() == et_Class) {
                        (*it)->governor(class_atom_ptr(new class_atom((*it)->scope(), (*it)->governor()->expectedname(), cl_Reference)));
                    } else
                        scope()->referenceerror_throw((*it)->governor()->expectedname());
                } else
                    scope()->referenceerror_throw(scope()->name());
            }
        }
    }




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

    void type_atom::resolve() {
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
                (*it)->as_valueassigment()->value()->resolve_reff(false);
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
            if ((tag()->number()) && (tag()->number()->as_defined()) && (tag()->number()->expecteddef())) {
                tag()->number()->resolve_reff(false);
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

    void instanceoftype_atom::resolve() {
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

    void classfieldtype_atom::resolve() {
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

    void fromobjecttype_atom::resolve() {
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

    void fromobjectsettype_atom::resolve() {
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

    basic_entity_ptr typeassignment_entity::find_by_name(const std::string& nm, bool all) {
        if (all) {
            if (((type()->predefined()))) {
                for (basic_entity_vector::iterator it = type()->predefined()->values().begin(); it != type()->predefined()->values().end(); ++it)
                    if ((*it)->name() == nm)
                        return *it;
            }
            if ((type()->reff())) {
                type()->resolve_reff();
                basic_entity_ptr fnd = type()->reff()->find_by_name(nm, all);
                if (fnd)
                    return fnd;
            }
        }
        if (scope())
            return scope()->find_by_name(nm, all);
        return basic_entity_ptr();
    }

    void typeassignment_entity::resolve() {
        unicalelerror_throw(childs());
        assignment_entity::resolve();
        resolve_child();
        if (type())
            type()->resolve();

    }

    namedtypeassignment_entity* typeassignment_entity::as_named() {
        return dynamic_cast<namedtypeassignment_entity*> (this);
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

    void namedtypeassignment_entity::resolve() {
        typeassignment_entity::resolve();
        resolve_default();
    }

    void namedtypeassignment_entity::resolve_default() {
        if ((_default()) && (_default()->expecteddef())) {
            basic_entity_ptr fnd = find_by_name(_default()->expectedname());
            if (fnd)
                _default()->reff(fnd);
            else
                referenceerror_throw(_default()->expectedname());
        }
    }







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

    void value_atom::resolve_vect(value_vct& vl) {
        for (value_vct::iterator it = vl.begin(); it != vl.end(); ++it)
            (*it)->resolve_reff();
    }

    /*void value_atom::swap_scope_vect(value_vct& vl, basic_entity_ptr to_, basic_entity_ptr from_) {
        for (value_vct::iterator it = vl.begin(); it != vl.end(); ++it)
            (*it)->swap_scope(to_, from_);
    }*/


    /////////////////////////////////////////////////////////////////////////   
    // namedvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void namedvalue_atom::resolve() {
        if (value_)
            value_->resolve_reff();
    }



    /////////////////////////////////////////////////////////////////////////   
    // structvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void structvalue_atom::resolve() {
        resolve_vect(values_);
    }

    /*void structvalue_atom::swap_scope(basic_entity_ptr to_, basic_entity_ptr from_) {      
        swap_scope_vect(values_,to_,from_);
    }*/

    /////////////////////////////////////////////////////////////////////////   
    // definedvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void definedvalue_atom::resolve() {
        resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////     
    // fromobjectvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjectvalue_atom::fromobjectvalue_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj)
    : value_atom(scp, v_ValueFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void fromobjectvalue_atom::resolve() {
        if (object())
            object()->resolve();
    }


    /////////////////////////////////////////////////////////////////////////   
    // assignvalue_atom
    ///////////////////////////////////////////////////////////////////////// 

    void assignvalue_atom::resolve() {
        if (value_)
            value_->resolve_reff();
    }

    /////////////////////////////////////////////////////////////////////////   
    // choicevalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void choicevalue_atom::resolve() {
        if (value_)
            value_->resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////   
    // openvalue_atom_atom
    /////////////////////////////////////////////////////////////////////////      

    void openvalue_atom::resolve() {
        if (type_)
            type_->resolve();
        if (value_)
            value_->resolve_reff();
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

    basic_entity_ptr valueassignment_entity::find_by_name(const std::string& nm, bool all) {
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

    void valueassignment_entity::resolve() {
        assignment_entity::resolve();
        resolve_child();
        type()->resolve();
        if (value())
            value()->resolve();
    }








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
    // defenedsetobject_atom
    /////////////////////////////////////////////////////////////////////////  

    void definedsetobject_atom::resolve() {
        //if (builtin() == ot_DefinedObjectSet)
        resolve_reff();
    };

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






    /////////////////////////////////////////////////////////////////////////   
    // OBJECTSET
    /////////////////////////////////////////////////////////////////////////       
    /////////////////////////////////////////////////////////////////////////   
    // object_atom
    /////////////////////////////////////////////////////////////////////////  

    objectset_atom::objectset_atom(basic_entity_ptr scope, objectset_type tp)
    : basic_atom(scope), builtin_(tp) {
    }

    objectset_atom::objectset_atom(basic_entity_ptr scope, const std::string& reff, objectset_type tp)
    : basic_atom(reff, scope), builtin_(tp) {
    }

    definedobjectset_atom* objectset_atom::as_defined() {
        return dynamic_cast<definedobjectset_atom*> (this);
    }

    defnobjectset_atom* objectset_atom::as_defn() {
        return dynamic_cast<defnobjectset_atom*> (this);
    }

    fromobjectobjectset_atom* objectset_atom::as_fromobject() {
        return dynamic_cast<fromobjectobjectset_atom*> (this);
    }

    fromobjectsetobjectset_atom* objectset_atom::as_fromobjectset() {
        return dynamic_cast<fromobjectsetobjectset_atom*> (this);
    }

    void objectset_atom::resolve() {
        if (builtin_ != os_Strait)
            resolve_reff();
    }



    /////////////////////////////////////////////////////////////////////////   
    // fromobjectobjectset_atom
    /////////////////////////////////////////////////////////////////////////        

    fromobjectobjectset_atom::fromobjectobjectset_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj) :
    objectset_atom(scp, os_ObjectSetFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void fromobjectobjectset_atom::resolve() {
        if (object())
            object()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////   
    // fromobjectsetobjectset_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjectsetobjectset_atom::fromobjectsetobjectset_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj) :
    objectset_atom(scp, os_ObjectSetFromObjects), objectset_(obj), field_(basic_atom_ptr(new basic_atom(refffld, scp))) {
    };

    void fromobjectsetobjectset_atom::resolve() {
        if (objectset())
            objectset()->resolve();
    }

    /////////////////////////////////////////////////////////////////////////        
    // defnobjectset_atom
    /////////////////////////////////////////////////////////////////////////      

    void defnobjectset_atom::resolve() {
        for (object_atom_vct::iterator it = objects_.begin(); it != objects_.end(); ++it) {
            (*it)->resolve();
        }
    };

    /////////////////////////////////////////////////////////////////////////   
    // objectsetassignment_entity
    /////////////////////////////////////////////////////////////////////////    

    objectsetassignment_entity::objectsetassignment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr cls, objectset_atom_ptr objs) :
    assignment_entity(scope, nm, et_ObjectSet), class_(cls), objectset_(objs) {
    };

    basic_entity_ptr objectsetassignment_entity::find_by_name(const std::string& nm, bool all) {
        if (scope()) {
            prefind(nm, scope()->childs());
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it)
                if (nm == (*it)->name()) {
                    return *it;
                }
        }
        if (scope())
            return scope()->find_by_name(nm, all);
        return basic_entity_ptr();
    }

    void objectsetassignment_entity::resolve() {
        assignment_entity::resolve();
        if (_class())
            _class()->resolve();
        if (objectset())
            objectset()->resolve();
    }




    /////////////////////////////////////////////////////////////////////////   
    // BIG
    /////////////////////////////////////////////////////////////////////////   
    // bigassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    bigassignment_entity::bigassignment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg) :
    assignment_entity(scope, nm, et_Nodef), big_(bg) {
    };

    basic_entity_ptr bigassignment_entity::find_by_name(const std::string& nm, bool all) {
        if (scope())
            prefind(nm, scope()->childs());
        for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it)
            if (nm == (*it)->name())
                return *it;
        if (scope())
            return scope()->find_by_name(nm);
        return basic_entity_ptr();
    }





    /////////////////////////////////////////////////////////////////////////   
    // VALUE OR OBJECT
    /////////////////////////////////////////////////////////////////////////   
    // voassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    voassignment_entity::voassignment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg) :
    assignment_entity(scope, nm, et_NodefV), big_(bg) {
    };

    /////////

    basic_entity_ptr voassignment_entity::find_by_name(const std::string& nm, bool all) {
        if (scope())
            return scope()->find_by_name(nm, all);
        return basic_entity_ptr();
    }


    /////////////////////////////////////////////////////////////////////////   
    // VALUE OR OBJECT
    /////////////////////////////////////////////////////////////////////////   
    // voassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    soassignment_entity::soassignment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg) :
    assignment_entity(scope, nm, et_NodefS), big_(bg) {
    };

    /////////

    basic_entity_ptr soassignment_entity::find_by_name(const std::string& nm, bool all) {
        if (scope())
            return scope()->find_by_name(nm, all);
        return basic_entity_ptr();
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
                modul->objectid(structvalue_atom_ptr(new structvalue_atom(v_objectid, compile_objidvalue(modul, mod.oid))));
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
            import_entity_ptr rslt = import_entity_ptr(new import_entity(imp.name));
            rslt->objectid(compile_value(mdl, imp.oid));
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
                case 4: return compile_objectassignment(scope, ent);
                case 5: return compile_objectsetassignment(scope, ent);
                case 6: return compile_bigassignment(scope, ent);
                case 7: return compile_voassignment(scope, ent);
                case 8: return compile_soassignment(scope, ent);
            }
            return rslt;
        }

        setting_atom_vct compile_parameters(basic_entity_ptr scope, const x680::syntactic::parameter_vector& ent) {
            setting_atom_vct tmp;
            for (x680::syntactic::parameter_vector::const_iterator it = ent.begin(); it != ent.end(); ++it)
                tmp.push_back(compile_setting(scope, *it));
            return tmp;
        }

        argument_entity_vct compile_arguments(basic_entity_ptr scope, const x680::syntactic::argument_vector& ent) {
            argument_entity_vct tmp;
            for (x680::syntactic::argument_vector::const_iterator it = ent.begin(); it != ent.end(); ++it)
                tmp.push_back(compile_argument(scope, *it));
            return tmp;
        }

        argument_entity_ptr compile_argument(basic_entity_ptr scope, const x680::syntactic::argument_type& ent) {
            argument_entity_ptr tmp(new argument_entity(scope, ent.argument, ent.atp));
            switch (ent.tp) {
                case gvr_Type: tmp->governor(compile_type(scope, ent.governortype));
                    break;
                case gvr_Class: tmp->governor(compile_classdefined(scope, ent.governorclass));
                    break;
                case gvr_Type_or_Class: tmp->governor(basic_atom_ptr(new basic_atom(ent.reff)));
                    break;
                default:
                {
                }
            }
            return tmp;
        }

        //  type

        typeassignment_entity_ptr compile_typeassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::type_assignment tmp = boost::get<x680::syntactic::type_assignment>(ent);
            typeassignment_entity_ptr tmpt(new typeassignment_entity(scope, tmp.identifier, compile_type(scope, tmp.type)));
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
            tmpt->arguments(compile_arguments(tmpt, tmp.arguments));
            return tmpt;
        }

        basic_entity_vector compile_structtype(basic_entity_ptr scope, const x680::syntactic::type_element& ent) {
            basic_entity_vector rslt;
            for (x680::syntactic::named_type_element_vector::const_iterator it = ent.elements.begin(); it != ent.elements.end(); ++it)
                rslt.push_back(compile_namedtype(scope, *it));
            return rslt;
        }

        typeassignment_entity_ptr compile_namedtype(basic_entity_ptr scope, const x680::syntactic::type_assignment& ent) {
            type_atom_ptr tmp = (ent.type.marker != mk_extention) ? compile_type(scope, ent.type) : type_atom_ptr();
            typeassignment_entity_ptr tmpt;
            switch (ent.type.marker) {
                case mk_default: tmpt = namedtypeassignment_entity_ptr(new namedtypeassignment_entity(scope, ent.identifier, tmp, compile_value(scope, ent.type.value)));
                    break;
                case mk_exception: tmpt = namedtypeassignment_entity_ptr(new namedtypeassignment_entity(scope, tmp, compile_value(scope, ent.type.value)));
                    break;
                case mk_extention:
                {
                    tmpt = namedtypeassignment_entity_ptr(new namedtypeassignment_entity(scope));
                    if (scope && (scope->as_typeassigment()) && (scope->as_typeassigment()->type()))
                        scope->as_typeassigment()->type()->extention(true);

                    return tmpt;
                    break;
                }
                default: tmpt = namedtypeassignment_entity_ptr(new namedtypeassignment_entity(scope, ent.identifier, tmp, ent.type.marker));
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
            tmpt->type()->constraints(compile_constraints_vct(tmpt, ent.type.constraints));
            return tmpt;
        }

        type_atom_ptr compile_type(basic_entity_ptr scope, const x680::syntactic::type_element& ent) {
            type_atom_ptr tmp;
            switch (ent.builtin_t) {
                case t_ClassField: tmp = type_atom_ptr(new classfieldtype_atom(scope, ent.reference, ent.fieldreference,
                            compile_tag(scope, ent.tag)));
                    break;
                case t_Instance_Of: tmp = type_atom_ptr(new instanceoftype_atom(scope, ent.reference,
                            compile_tag(scope, ent.tag)));
                    break;
                case t_TypeFromObject: tmp = type_atom_ptr(new fromobjecttype_atom(scope, ent.fieldreference,
                            compile_object(scope, *ent.objectref), compile_tag(scope, ent.tag)));
                    break;
                case t_ValueSetFromObjects: tmp = type_atom_ptr(new fromobjectsettype_atom(scope, ent.fieldreference,
                            compile_objectset(scope, *ent.objectsetref), compile_tag(scope, ent.tag)));
                    break;
                default:
                    tmp = ent.reference.empty() ? type_atom_ptr(new type_atom(scope, ent.builtin_t, compile_tag(scope, ent.tag))) :
                            type_atom_ptr(new type_atom(scope, ent.reference, ent.builtin_t, compile_tag(scope, ent.tag)));
            }
            tmp->constraints(compile_constraints_vct(scope, ent.constraints));
            tmp->parameters(compile_parameters(scope, ent.parameters));
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
                            valueassignment_entity_ptr el(new valueassignment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)), value_atom_ptr()));
                            rslt.push_back(el);
                        } else {
                            try {
                                valueassignment_entity_ptr el(new valueassignment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                        value_atom_ptr(new numvalue_atom(boost::lexical_cast<int > (it->values.begin()->identifier)))));
                                rslt.push_back(el);
                            } catch (boost::bad_lexical_cast) {
                                valueassignment_entity_ptr el(new valueassignment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                        value_atom_ptr(new definedvalue_atom(it->values.begin()->identifier, scope))));
                                rslt.push_back(el);
                            }
                        }
                    } else {
                        try {
                            valueassignment_entity_ptr el(new valueassignment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                    value_atom_ptr(new numvalue_atom(boost::lexical_cast<int > (it->value)))));
                            rslt.push_back(el);
                        } catch (boost::bad_lexical_cast) {
                            valueassignment_entity_ptr el(new valueassignment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
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




        //  value

        valueassignment_entity_ptr compile_valueassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::value_assignment tmp = boost::get<x680::syntactic::value_assignment>(ent);
            valueassignment_entity_ptr tmpt(new valueassignment_entity(scope, tmp.identifier, compile_type(scope, tmp.type), value_atom_ptr()));
            value_atom_ptr tmpv = compile_value(tmpt, tmp.value);
            tmpt->value(tmpv);
            tmpt->type()->predefined(compile_typepredef(tmpt, tmp.type));
            tmpt->arguments(compile_arguments(tmpt, tmp.arguments));
            return tmpt;
        }

        value_atom_ptr compile_value(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            value_atom_ptr tmp = compile_value_impl(scope, ent);
            if (tmp)
                tmp->parameters(compile_parameters(scope, ent.parameters));
            return tmp;
        }

        value_atom_ptr compile_value_impl(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
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
                    case v_struct: return value_atom_ptr(new structvalue_atom(ent.type, compile_structvalue(scope, ent)));
                    case v_objectid: return value_atom_ptr(new structvalue_atom(ent.type, compile_objidvalue(scope, ent)));
                    case v_defined_list:
                    case v_number_list:
                    case v_value_list: return value_atom_ptr(new structvalue_atom(ent.type, compile_listvalue(scope, ent)));
                    case v_defined: return value_atom_ptr(new definedvalue_atom(ent.identifier, scope));
                    case v_ValueFromObject: return value_atom_ptr(new fromobjectvalue_atom(scope, ent.fieldreference,
                                compile_object(scope, *ent.objectref)));
                    case v_defined_assign: return compile_assignvalue(scope, ent);
                    case v_choice: return compile_choicevalue(scope, ent);
                    case v_open: return compile_openvalue(scope, ent);
                    default:
                    {
                    }
                }
            } catch (boost::bad_lexical_cast) {
                return value_atom_ptr(new value_atom(scope, v_nodef));
            }
            return value_atom_ptr();
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



        // valueset

        valuesetassignment_entity_ptr compile_valuesetassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::valueset_assignment tmp = boost::get<x680::syntactic::valueset_assignment>(ent);
            valuesetassignment_entity_ptr tmpv(new valuesetassignment_entity(scope, tmp.identifier, compile_type(scope, tmp.type), valueset_atom_ptr()));
            tmpv->valueset(compile_valueset(tmpv, tmp.set));
            tmpv->arguments(compile_arguments(tmpv, tmp.arguments));
            return tmpv;
        }
        
        valueset_atom_ptr compile_valueset(basic_entity_ptr scope, const x680::syntactic::valueset_element& ent) {
            valueset_atom_ptr tmp = compile_valueset_impl(scope, ent);
            tmp->parameters(compile_parameters(scope, ent.parameters));
            return tmp;            
        }        

        valueset_atom_ptr compile_valueset_impl(basic_entity_ptr scope, const x680::syntactic::valueset_element& ent) {
            switch(ent.tp){
                case vs_ValueSetFromObject: return valueset_atom_ptr(new fromobjectvalueset_atom(scope, ent.reference, compile_object(scope, *ent.objectref)));
                case vs_ValueSetFromObjects: return valueset_atom_ptr(new fromobjectsetvalueset_atom(scope, ent.reference, compile_objectset(scope, *ent.objectsetref)));  
                case vs_Strait:
                {
                    valueset_atom_ptr tmp(new valueset_atom(scope, ent.tp));
                    tmp->set(compile_constraints(scope, ent.set));
                    tmp->parameters(compile_parameters(scope, ent.parameters));
                    return tmp;
                }
                default:{}}            
            return valueset_atom_ptr(new valueset_atom(scope, ent.reference, ent.tp));
        }

        constraints_atom_vct compile_constraints_vct(basic_entity_ptr scope, const x680::syntactic::constraints_vector& ent) {
            constraints_atom_vct tmp;
            for (x680::syntactic::constraints_vector::const_iterator it = ent.begin(); it != ent.end(); ++it)
                tmp.push_back(compile_constraints(scope, *it));
            return tmp;
        }

        constraints_atom_ptr compile_constraints(basic_entity_ptr scope, const x680::syntactic::constraint_element_vector& ent) {
            bool first = true;
            constraint_atom_vct tmp1;
            constraint_atom_vct tmp2;
            for (x680::syntactic::constraint_element_vector::const_iterator it = ent.begin(); it != ent.end(); ++it) {
                if (it->tp == cns_EXTENTION) {
                    first = false;
                } else {
                    if (first)
                        tmp1.push_back(compile_constraint(scope, *it));
                    else
                        tmp2.push_back(compile_constraint(scope, *it));
                }
            }
            return first ? constraints_atom_ptr(new constraints_atom(scope, tmp1)) : constraints_atom_ptr(new constraints_atom(scope, tmp1, tmp2));
        }

        constraint_atom_ptr compile_constraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent) {
            constraint_atom_ptr tmp;
            switch (ent.tp) {
                case cns_PatternConstraint:
                case cns_SingleValue: return constraint_atom_ptr(new valueconstraint_atom(scope, ent.tp, compile_value(scope, ent.value)));
                case cns_ValueRange:
                case cns_DurationRange:
                case cns_TimePointRange:
                case cns_RecurrenceRange: return constraint_atom_ptr(new rangeconstraint_atom(scope, ent.tp,
                            (((ent.fromtype_ == close_range) || (ent.fromtype_ == open_range)) ? compile_value(scope, ent.from_) : value_atom_ptr()), ent.fromtype_,
                            (((ent.totype_ == close_range) || (ent.totype_ == open_range)) ? compile_value(scope, ent.to_) : value_atom_ptr()), ent.totype_));
                case cns_ContainedSubtype:
                case cns_TypeConstraint: return constraint_atom_ptr(new typeconstraint_atom(scope, ent.tp,
                            compile_type(scope, ent.type), false));
                case cns_PermittedAlphabet:
                case cns_SizeConstraint:
                case cns_SingleTypeConstraint: return constraint_atom_ptr(new complexconstraint_atom(scope, ent.tp,
                            compile_constraints(scope, ent.constraint)));
                case cns_PropertySettings: return constraint_atom_ptr(new stringconstraint_atom(scope, ent.tp, ent.identifier));
                case cns_MultipleTypeConstraints: return compile_multipletypeconstraint(scope, ent);
                case cns_NamedConstraint: return compile_namedconstraint(scope, ent);
                case cns_UNION: return constraint_atom_ptr(new unionconstraint_atom());
                case cns_INTERSECTION: return constraint_atom_ptr(new intersectionconstraint_atom());
                case cns_EXCEPT: return constraint_atom_ptr(new exceptconstraint_atom());
                case cns_ALLEXCEPT: return constraint_atom_ptr(new allexceptconstraint_atom());
                case cns_EXTENTION: return constraint_atom_ptr(new extentionconstraint_atom());
                case cns_EXCEPTION: return compile_exceptionconstraint(scope, ent);
                    /*case cns_UserDefinedConstraint,
                    case cns_SimpleTableConstraint,
                    case cns_ComponentRelation,
                    case cns_ContentsType,
                    case cns_ContentsValue,
                    case cns_ContentsTypeValue,*/
                default:
                {
                }
            }
            return constraint_atom_ptr(new constraint_atom());
        }

        constraint_atom_ptr compile_namedconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent) {
            if (!ent.constraint.empty())
                return constraint_atom_ptr(new namedconstraint_atom(scope, ent.identifier, compile_constraints(scope, ent.constraint), ent.marker));
            return constraint_atom_ptr(new namedconstraint_atom(scope, ent.identifier, ent.marker));
        }

        constraint_atom_ptr compile_multipletypeconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent) {
            constraint_atom_vct tmp;
            for (x680::syntactic::constraint_element_vector::const_iterator it = ent.constraint.begin(); it != ent.constraint.end(); ++it) {
                switch (it->tp) {
                    case cns_NamedConstraint: tmp.push_back(compile_namedconstraint(scope, *it));
                        break;
                    default: tmp.push_back(compile_constraint(scope, *it));
                }
            }
            return constraint_atom_ptr(new multipletypeconstraint_atom(scope, tmp));
        }

        constraint_atom_ptr compile_exceptionconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent) {
            return constraint_atom_ptr(new exceptionconstraint_atom(scope, compile_type(scope, ent.type), compile_value(scope, ent.value)));
        }




        //class

        classassignment_entity_ptr compile_classassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::class_assignment tmp = boost::get<x680::syntactic::class_assignment>(ent);
            classassignment_entity_ptr tmpc(new classassignment_entity(scope, tmp.identifier));
            switch (tmp.class_.tp) {
                case cl_Reference:
                {
                    tmpc->_class(class_atom_ptr(new class_atom(tmpc, tmp.class_.reference, tmp.class_.tp)));
                    tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
                    return tmpc;
                }
                case cl_TYPE_IDENTIFIER:
                {
                    tmpc->_class(class_atom_ptr(new class_atom(tmpc, "TYPE-IDENTIFIER", cl_Reference)));
                    tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
                    return tmpc;
                }
                case cl_ABSTRACT_SYNTAX:
                {
                    tmpc->_class(class_atom_ptr(new class_atom(tmpc, "ABSTRACT-SYNTAX", cl_Reference)));
                    tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
                    return tmpc;
                }
                case cl_SpecDef:
                {
                    tmpc->_class(class_atom_ptr(new class_atom(tmpc, tmp.class_.tp)));
                    tmpc->childs() = compile_classfields(tmpc, tmp.class_);
                    withsyntax_atom wsyn = compile_withsyntax(scope, tmp.class_.syntaxes);
                    tmpc->withsyntax(compile_withsyntax(tmpc, tmp.class_.syntaxes));
                    tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
                    return tmpc;
                }
                default:
                {
                }
            }
            tmpc->_class(class_atom_ptr(new class_atom(tmpc, tmp.class_.tp)));
            tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
            return tmpc;
        }

        class_atom_ptr compile_classdefined(basic_entity_ptr scope, const x680::syntactic::class_element& ent) {
            class_atom_ptr tmp;
            switch (ent.tp) {
                case cl_Reference: tmp = class_atom_ptr(new class_atom(scope, ent.reference, ent.tp));
                    break;
                case cl_TYPE_IDENTIFIER: tmp = class_atom_ptr(new class_atom(scope, "TYPE-IDENTIFIER", cl_Reference));
                    break;
                case cl_ABSTRACT_SYNTAX: tmp = class_atom_ptr(new class_atom(scope, "ABSTRACT-SYNTAX", cl_Reference));
                    break;
                default: tmp = class_atom_ptr(new class_atom(scope, ent.reference, ent.tp));
            }
            tmp->parameters(compile_parameters(scope, ent.parameters));
            return tmp;
        }

        basic_entity_vector compile_classfields(basic_entity_ptr scope, const x680::syntactic::class_element& ent) {
            basic_entity_vector tmp;
            for (x680::syntactic::classfield_vector::const_iterator it = ent.fields.begin(); it != ent.fields.end(); ++it) {
                switch (it->tp) {
                    case fkind_TypeFieldSpec: tmp.push_back(compile_typeclassfield(scope, *it));
                        break;
                    case fkind_FixedTypeValueFieldSpec: tmp.push_back(compile_valueclassfield(scope, *it));
                        break;
                    case fkind_FixedTypeValueSetFieldSpec: tmp.push_back(compile_valuesetclassfield(scope, *it));
                        break;
                    case fkind_VariableTypeValueFieldSpec: tmp.push_back(compile_reffvalueclassfield(scope, *it));
                        break;
                    case fkind_VariableTypeValueSetFieldSpec: tmp.push_back(compile_reffvaluesetclassfield(scope, *it));
                        break;
                    case fkind_ObjectFieldSpec: tmp.push_back(compile_objectclassfield(scope, *it));
                        break;
                    case fkind_ObjectSetFieldSpec: tmp.push_back(compile_objectsetclassfield(scope, *it));
                        break;
                    case fkind_FixedType_or_Object: tmp.push_back(compile_undefclassfield(scope, *it));
                        break;
                    case fkind_FixedTypeSet_or_ObjectSet: tmp.push_back(compile_unsefsetclassfield(scope, *it));
                        break;
                    default: tmp.push_back(basic_entity_ptr(new field_entity(scope, it->field, it->tp)));
                }
            }
            return tmp;
        }

        basic_entity_ptr compile_typeclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            switch (ent.marker) {
                case field_defaulttype:
                {
                    type_atom_ptr tp = compile_type(scope, ent.defaulttype);
                    return basic_entity_ptr(new typefield_entity(scope, ent.field, tp));
                }
                case field_optional: return basic_entity_ptr(new typefield_entity(scope, ent.field, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new typefield_entity(scope, ent.field));
        }

        basic_entity_ptr compile_valueclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            type_atom_ptr tp = compile_type(scope, ent.holdertype);
            switch (ent.marker) {
                case field_defaultvalue:
                {
                    value_atom_ptr vl = compile_value(scope, ent.defaultvalue);
                    return basic_entity_ptr(new valuefield_entity(scope, ent.field, tp, vl));
                }
                case field_optional: return basic_entity_ptr(new valuefield_entity(scope, ent.field, tp, ent.unique, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new valuefield_entity(scope, ent.field, tp, ent.unique));
        }

        basic_entity_ptr compile_valuesetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            type_atom_ptr tp = compile_type(scope, ent.holdertype);
            switch (ent.marker) {
                case field_defaultset:
                {
                    valueset_atom_ptr vl = compile_valueset(scope, ent.defaultset);
                    return basic_entity_ptr(new valuesetfield_entity(scope, ent.field, tp, vl));
                }
                case field_optional: return basic_entity_ptr(new valuesetfield_entity(scope, ent.field, tp, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new valuesetfield_entity(scope, ent.field, tp));
        }

        basic_entity_ptr compile_reffvalueclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            //basic_atom_ptr reff = basic_atom_ptr( new basic_atom( ent.holder, scope));
            switch (ent.marker) {
                case field_defaultvalue:
                {
                    value_atom_ptr vl = compile_value(scope, ent.defaultvalue);
                    return basic_entity_ptr(new reffvaluefield_entity(scope, ent.field, ent.holder, vl));
                }
                case field_optional: return basic_entity_ptr(new reffvaluefield_entity(scope, ent.field, ent.holder, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new reffvaluefield_entity(scope, ent.field, ent.holder));
        }

        basic_entity_ptr compile_reffvaluesetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            //basic_atom_ptr reff = basic_atom_ptr( new basic_atom( ent.holder, scope));
            switch (ent.marker) {
                case field_defaultvalue:
                {
                    valueset_atom_ptr vl = compile_valueset(scope, ent.defaultset);
                    return basic_entity_ptr(new reffvaluesetfield_entity(scope, ent.field, ent.holder, vl));
                }
                case field_optional: return basic_entity_ptr(new reffvaluesetfield_entity(scope, ent.field, ent.holder, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new reffvaluesetfield_entity(scope, ent.field, ent.holder));
        }

        basic_entity_ptr compile_objectclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            class_atom_ptr cl = compile_classdefined(scope, *ent.holderclass);
            switch (ent.marker) {
                case field_defaultovalue:
                {
                    object_atom_ptr vl = compile_object(scope, *ent.defaultovalue);
                    return basic_entity_ptr(new objectfield_entity(scope, ent.field, cl, vl));
                }
                case field_optional: return basic_entity_ptr(new objectfield_entity(scope, ent.field, cl, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new objectfield_entity(scope, ent.field, cl));
        }

        basic_entity_ptr compile_objectsetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            class_atom_ptr cl = compile_classdefined(scope, *ent.holderclass);
            switch (ent.marker) {
                case field_defaultoset:
                {
                    objectset_atom_ptr vl = compile_objectset(scope, *ent.defaultoset);
                    return basic_entity_ptr(new objectsetfield_entity(scope, ent.field, cl, vl));
                }
                case field_optional: return basic_entity_ptr(new objectsetfield_entity(scope, ent.field, cl, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new objectsetfield_entity(scope, ent.field, cl));
        }

        basic_entity_ptr compile_undefclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            basic_atom_ptr bg = basic_atom_ptr(new basic_atom(ent.holder, scope));
            switch (ent.marker) {
                case field_defaultov:
                {
                    value_atom_ptr vl = ent.defvalobj.value_ ?
                            compile_value(scope, *ent.defvalobj.value_) : value_atom_ptr();
                    object_atom_ptr obj = ent.defvalobj.object_ ?
                            compile_object(scope, *ent.defvalobj.object_) : object_atom_ptr();
                    return basic_entity_ptr(new undeffield_entity(scope, ent.field, bg, vl, obj));
                }
                case field_optional: return basic_entity_ptr(new undeffield_entity(scope, ent.field, bg, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new undeffield_entity(scope, ent.field, bg));
        }

        basic_entity_ptr compile_unsefsetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            basic_atom_ptr bg = basic_atom_ptr(new basic_atom(ent.holder, scope));
            switch (ent.marker) {
                case field_defaultos:
                {
                    valueset_atom_ptr vl = ent.defvalobjset.valueset_ ?
                            compile_valueset(scope, *ent.defvalobjset.valueset_) : valueset_atom_ptr();
                    objectset_atom_ptr obj = ent.defvalobjset.objectset_ ?
                            compile_objectset(scope, *ent.defvalobjset.objectset_) : objectset_atom_ptr();
                    return basic_entity_ptr(new undefsetfield_entity(scope, ent.field, bg, vl, obj));
                }
                case field_optional: return basic_entity_ptr(new undefsetfield_entity(scope, ent.field, bg, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new undefsetfield_entity(scope, ent.field, bg));
        }

        withsyntax_atom compile_withsyntax(basic_entity_ptr scope, const x680::syntactic::classsyntax_vector& ent) {
            if (ent.empty())
                return withsyntax_atom();
            return withsyntax_atom(new groupsyntax_atom(scope, "", compile_groupwithsyntax(scope, ent), false));
        }

        syntax_atom_vct compile_groupwithsyntax(basic_entity_ptr scope, const x680::syntactic::classsyntax_vector& ent) {
            syntax_atom_vct tmp;
            for (x680::syntactic::classsyntax_vector::const_iterator it = ent.begin(); it != ent.end(); ++it) {
                if (it->group.empty()) {
                    tmp.push_back(syntax_atom_ptr(new syntax_atom(scope, it->alias, it->field, it->optional)));
                } else {
                    tmp.push_back(syntax_atom_ptr(new groupsyntax_atom(scope, it->alias, compile_groupwithsyntax(scope, it->group), it->optional)));
                }
            }
            return tmp;
        }


        // object         

        objectassignment_entity_ptr compile_objectassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::object_assignment tmp = boost::get<x680::syntactic::object_assignment>(ent);
            objectassignment_entity_ptr tmpc(new objectassignment_entity(scope, tmp.identifier, compile_classdefined(scope, tmp.class_), object_atom_ptr()));
            object_atom_ptr obj = compile_object(tmpc, tmp.object);
            tmpc->object(obj);
            tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
            return tmpc;
        }

        object_atom_ptr compile_object(basic_entity_ptr scope, const x680::syntactic::object_element& ent) {
            object_atom_ptr tmp = compile_object_impl(scope, ent);
            if (tmp)
                tmp->parameters(compile_parameters(scope, ent.parameters));
            return tmp;
        }

        object_atom_ptr compile_object_impl(basic_entity_ptr scope, const x680::syntactic::object_element& ent) {
            switch (ent.tp) {
                case ot_FromObject: return object_atom_ptr(new fromobjectobject_atom(scope, ent.fieldreference,
                            compile_object(scope, *ent.objectref)));
                case ot_ObjectSetFromObjects:
                case ot_Refference: return object_atom_ptr(new definedobject_atom(scope, ent.reff));
                case ot_DefinedObjectSet: return object_atom_ptr(new definedsetobject_atom(scope, ent.reff));
                case ot_Object: return object_atom_ptr(new defltobject_atom(scope, compile_object_fields(scope, ent.fields)));
                case ot_ObjectDefineSyn: return object_atom_ptr(new defsyntxobject_atom(scope, compile_object_fields(scope, ent.fields)));
                case ot_UNION: return object_atom_ptr(new unionobject_atom());
                case ot_INTERSECTION: return object_atom_ptr(new intersectionobject_atom());
                case ot_EXCEPT: return object_atom_ptr(new exceptobject_atom());
                case ot_ALLEXCEPT: return object_atom_ptr(new allexceptobject_atom());
                case ot_EXTENTION: return object_atom_ptr(new extentionobject_atom());
            }
            return object_atom_ptr();

        }

        fieldsetting_atom_vct compile_object_fields(basic_entity_ptr scope, const x680::syntactic::objectfield_vector& ent) {
            fieldsetting_atom_vct tmp;
            for (x680::syntactic::objectfield_vector::const_iterator it = ent.begin(); it != ent.end(); ++it)
                tmp.push_back(compile_object_field(scope, (*it)));
            return tmp;
        }

        fieldsetting_atom_ptr compile_object_field(basic_entity_ptr scope, const x680::syntactic::objectfield_type& ent) {
            return fieldsetting_atom_ptr(new fieldsetting_atom(scope, ent.field, compile_setting(scope, ent.setting)));
        }

        setting_atom_ptr compile_setting(basic_entity_ptr scope, const x680::syntactic::setting_element& ent) {
            setting_atom_ptr tmp(new setting_atom(ent.alternative, scope));
            if ((ent.alternative & AS_TYPE) && (ent.type))
                tmp->type(compile_type(scope, *ent.type));
            if ((ent.alternative & AS_VALUE) && (ent.value))
                tmp->value(compile_value(scope, *ent.value));
            if ((ent.alternative & AS_VALUESET) && (ent.valueset))
                tmp->valueset(compile_valueset(scope, * ent.valueset));
            if ((ent.alternative & AS_CLASS) && (ent.class_))
                tmp->_class(compile_classdefined(scope, *ent.class_));
            if ((ent.alternative & AS_OBJECT) && (ent.object))
                tmp->object(compile_object(scope, *ent.object));
            if ((ent.alternative & AS_OBJECTSET) && (ent.objectset))
                tmp->objectset(compile_objectset(scope, *ent.objectset));
            if ((ent.alternative & AS_LITERAL))
                tmp->literal(ent.literal);
            return tmp;
        }


        // objectset         

        objectsetassignment_entity_ptr compile_objectsetassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::objectset_assignment tmp = boost::get<x680::syntactic::objectset_assignment>(ent);
            objectsetassignment_entity_ptr tmpc(new objectsetassignment_entity(scope, tmp.identifier, compile_classdefined(scope, tmp.class_), objectset_atom_ptr()));
            objectset_atom_ptr objs = compile_objectset(tmpc, tmp.set);
            tmpc->objectset(objs);
            tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
            return tmpc;
        }

        objectset_atom_ptr compile_objectset(basic_entity_ptr scope, const x680::syntactic::objectset_element& ent) {
            objectset_atom_ptr tmp = compile_objectset_impl(scope, ent);
            tmp->parameters(compile_parameters(scope, ent.parameters));
            return tmp;
        }

        objectset_atom_ptr compile_objectset_impl(basic_entity_ptr scope, const x680::syntactic::objectset_element& ent) {
            switch (ent.tp) {
                case os_ObjectSetFromObject: return objectset_atom_ptr(new fromobjectobjectset_atom(scope, ent.reference, compile_object(scope, *ent.objectref)));
                case os_ObjectSetFromObjects: return objectset_atom_ptr(new fromobjectsetobjectset_atom(scope, ent.reference, compile_objectset(scope, *ent.objectsetref)));                
                //case os_defined:
                case os_Strait: return objectset_atom_ptr(new defnobjectset_atom(scope, compile_objectset_vct(scope, ent)));
                default:
                {
                }
            }
            return objectset_atom_ptr(new definedobjectset_atom(scope, ent.reference));
        }

        object_atom_vct compile_objectset_vct(basic_entity_ptr scope, const x680::syntactic::objectset_element& ent) {
            object_atom_vct tmp;
            for (x680::syntactic::object_element_vector::const_iterator it = ent.set.begin(); it != ent.set.end(); ++it)
                tmp.push_back(compile_object(scope, *it));
            return tmp;
        }

        bigassignment_entity_ptr compile_bigassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::unknown_tc_assignment tmp = boost::get<x680::syntactic::unknown_tc_assignment>(ent);
            bigassignment_entity_ptr tmpv = bigassignment_entity_ptr(new bigassignment_entity(scope, tmp.identifier, compile_reff(tmp.unknown_tc.reff)));
            tmpv->arguments(compile_arguments(tmpv, tmp.arguments));
            return tmpv;
        }

        // value or object 

        voassignment_entity_ptr compile_voassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::unknown_vo_assignment tmp = boost::get<x680::syntactic::unknown_vo_assignment>(ent);
            voassignment_entity_ptr tmpv = voassignment_entity_ptr(new voassignment_entity(scope, tmp.identifier, compile_reff(tmp.reff)));
            if ((tmp.unknown_vo.alternative_ & AS_VALUE) && (tmp.unknown_vo.value_))
                tmpv->value(compile_value(scope, *(tmp.unknown_vo.value_)));
            if ((tmp.unknown_vo.alternative_ & AS_OBJECT) && (tmp.unknown_vo.object_))
                tmpv->object(compile_object(scope, *(tmp.unknown_vo.object_)));
            tmpv->arguments(compile_arguments(tmpv, tmp.arguments));
            return tmpv;
        }

        // valueset or objectset

        soassignment_entity_ptr compile_soassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::unknown_so_assignment tmp = boost::get<x680::syntactic::unknown_so_assignment>(ent);
            soassignment_entity_ptr tmpv = soassignment_entity_ptr(new soassignment_entity(scope, tmp.identifier, compile_reff(tmp.reff)));
            if ((tmp.unknown_so.alternative_ & AS_VALUESET) && (tmp.unknown_so.valueset_))
                tmpv->valueset(compile_valueset(scope, *(tmp.unknown_so.valueset_)));
            if ((tmp.unknown_so.alternative_ & AS_OBJECTSET) && (tmp.unknown_so.objectset_))
                tmpv->objectset(compile_objectset(scope, *(tmp.unknown_so.objectset_)));
            tmpv->arguments(compile_arguments(tmpv, tmp.arguments));
            return tmpv;
        }

        // reff

        basic_atom_ptr compile_reff(const std::string& rf) {
            return basic_atom_ptr(new basic_atom(rf));
        }


    }









    /////////////////////////////////////////////////////////////////////////   
    // COUT
    /////////////////////////////////////////////////////////////////////////   
    // std::cout  tree
    /////////////////////////////////////////////////////////////////////////       

    std::ostream& indent(std::ostream& stream, typeassignment_entity* self) {
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
            stream << "     \n";
            if ((*it)->as_bigassigment()) {
                stream << (*it)->as_bigassigment();
                continue;
            }
            if ((*it)->as_voassigment()) {
                stream << (*it)->as_voassigment();
                continue;
            }
            if ((*it)->as_soassigment()) {
                stream << (*it)->as_soassigment();
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
            if ((*it)->as_valuesetassigment()) {
                stream << (*it)->as_valuesetassigment();
                continue;
            }
            if ((*it)->as_classassigment()) {
                stream << (*it)->as_classassigment();
                continue;
            }
            if ((*it)->as_objectassigment()) {
                stream << (*it)->as_objectassigment();
                continue;
            }
            if ((*it)->as_objectsetassigment()) {
                stream << (*it)->as_objectsetassigment();
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

    std::ostream& operator<<(std::ostream& stream, const argument_entity_vct& self) {
        if (self.empty())
            return stream;
        stream << " {";
        for (argument_entity_vct::const_iterator it = self.begin(); it != self.end(); ++it) {
            if (it != self.begin())
                stream << " ,";
            stream << (*it).get();
        }
        return stream << " }";
    }

    std::ostream& operator<<(std::ostream& stream, argument_entity* self) {
        if (self->governor()) {
            if (self->governor()->as_type())
                stream << "(T)" << self->governor()->as_type() << ":";
            else if (self->governor()->as_class())
                stream << "(C)" << self->governor()->as_class() << ":";
            else
                stream << "(T?C)" << self->governor()->reff()->name() << ":";
        }
        return stream << self->name();
    }



    //  type

    std::ostream& operator<<(std::ostream& stream, typeassignment_entity* self) {
        if (self->as_named()) {
            indent(stream, self);
            if (self->as_named()->marker() == mk_components_of)
                stream << self->name() << " COMPONENTS OF ";
            else if (self->as_named()->marker() == mk_exception)
                stream << "! " << " ";
            else if (self->as_named()->marker() == mk_extention)
                return stream << "(...) " << "\n";
            else
                stream << self->name() << "  ";
            stream << self->type() << " ";
            operatorstruct(stream, self);
            if (self->type()->has_constraint())
                stream << self->type()->constraints();
            stream << self->as_named()->marker();
            if ((self->as_named()->_default())
                    && ((self->as_named()->marker() == mk_default)
                    || (self->as_named()->marker() == mk_exception))) {
                if (self->as_named()->marker() == mk_exception)
                    stream << " : ";
                stream << " " << self->as_named()->_default().get();
            }
        } else {
            stream << "(T) " << self->name();
            if (self->has_arguments())
                stream << self->arguments();
            stream << " :: = " << self->type().get();
            operatorstruct(stream, self);
            if (self->type()->has_constraint())
                stream << self->type()->constraints();
        }
        return stream << "\n";
        ;
    }

    std::ostream& operatorstruct(std::ostream& stream, typeassignment_entity* self) {
        switch (self->type()->builtin()) {
            case t_SEQUENCE:
            case t_SEQUENCE_OF:
            case t_SET:
            case t_SET_OF:
            case t_CHOICE:;
            {
                if (self->type()->has_extention())
                    stream << " {" << "(has ...)\n";
                else
                    stream << " {" << "\n";
                for (basic_entity_vector::const_iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                    if ((*it)->as_extention()) {
                        indent(stream, self);
                        stream << "   (...)\n";
                    } else if ((*it)->as_typeassigment())
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
        switch (self->builtin()) {
            case t_Reference:
            {
                if (self->reff()->as_expectdef())
                    stream << "??? " << self->reff()->name();
                else {
                    stream << " " << self->externalpreff() << self->reff()->name();
                    if (self->rooted())
                        stream << "(@" << self->root() << ")";
                }
                break;
            }
            case t_ClassField:
            {
                stream << "(C)" << self->as_classfield()->_class().get() << "."
                        << self->as_classfield()->field()->reff()->name();
                break;
            }
            case t_Instance_Of:
            {
                stream << "INSTANCE OF " << self->as_instance()->_class().get();
                break;
            }
            case t_TypeFromObject:
            {
                stream << "(o)" << self->as_fromobject()->object().get() << "."
                        << self->as_fromobject()->field()->reff()->name();
                break;
            }
            case t_ValueSetFromObjects:
            {
                stream << "(vs)" << self->as_fromobjectset()->objectset().get() << "."
                        << self->as_fromobjectset()->field()->reff()->name();
                break;
            }
            default:
            {
                stream << self->builtin();
            }
        }
        if (self->parameterized())
            stream << self->parameters();
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



    // value

    std::ostream& operator<<(std::ostream& stream, valueassignment_entity* self) {
        stream << "(v) " << self->name() << " [" << self->type().get() << "]";
        if (self->has_arguments())
            stream << self->arguments();
        stream << " :: = ";
        if (self->value())
            return stream << self->value().get() << "\n";
        return stream << "???" << "\n";
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
            case v_ValueFromObject: return (stream << self->as_fromobject());
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
                if (self->as_objid())
                    stream << "  ";
                else
                    stream << ",  ";
            stream << (*it).get();
        }
        return stream << "}";
    }

    std::ostream& operator<<(std::ostream& stream, definedvalue_atom* self) {
        if (self->reff()) {
            if (self->reff()->as_expectdef())
                return stream << "??? " << self->reff()->name();
            else {
                stream << " " << self->reff()->name();
                if (self->rooted())
                    stream << "(@" << self->root() << ")";
                return stream;
            }
        }
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, fromobjectvalue_atom* self) {
        stream << "(v)" << self->object().get() << "." << self->field()->reff()->name();
        if (self->parameterized())
            stream << self->parameters();
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




    //valueset

    std::ostream& operator<<(std::ostream& stream, valuesetassignment_entity* self) {
        stream << "(vS) " << self->name() << " [" << self->type().get() << "]";
        if (self->has_arguments())
            stream << self->arguments();
        return stream << ":: = " << self->valueset().get() << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, valueset_atom* self) {
        switch (self->builtin()) {
            case vs_Strait:
            {
                if (self->set())
                    return stream << self->set().get();
                return stream << "(vs)???";
            }
            case vs_ValueSetFromObject:
            {
                stream << "(o)" << self->as_fromobject()->object().get() << "."
                        << self->as_fromobject()->field()->reff()->name();
                break;
            }
            case vs_ValueSetFromObjects:
            {
                stream << "(oS)" << self->as_fromobjectset()->objectset().get() << "."
                        << self->as_fromobject()->field()->reff()->name();
                break;
            }
            case vs_defined:
            {
                if (self->reff()) {
                    if (self->reff()->as_expectdef())
                        return stream << "??? *" << self->reff()->name();
                    else {
                        stream << " " << self->reff()->name();
                    }
                } else
                    stream << "(vs)???";
            }
            default:
            {
            }
        }
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, const constraints_atom_vct& self) {
        if (self.empty())
            return stream;
        for (constraints_atom_vct::const_iterator it = self.begin(); it != self.end(); ++it)
            stream << (*it).get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, constraints_atom* self) {
        if (self) {
            if (self->reff()) {
                if (self->reff()->as_expectdef())
                    return stream << "??? " << self->reff()->name();
                else
                    stream << " " << self->reff()->name();
            } else {
                stream << "(#";
                if (self->extend())
                    stream << "(...) ";
                else
                    stream << " ";
                for (constraint_atom_vct::const_iterator it = self->constraintline().begin(); it != self->constraintline().end(); ++it)
                    stream << " " << (*it).get();
                if (self->extend())
                    stream << "  ...  ";
                for (constraint_atom_vct::const_iterator it = self->extendline().begin(); it != self->extendline().end(); ++it)
                    stream << " " << (*it).get();
                stream << " #)";
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, const constraint_atom_vct& self) {
        for (constraint_atom_vct::const_iterator it = self.begin(); it != self.end(); ++it) {
            if (*it) stream << " " << (*it).get();
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, constraint_atom* self) {
        switch (self->cotstrtype()) {
            case cns_PatternConstraint: stream << self->as_pattern();
            case cns_SingleValue: return stream << self->as_valueconstraint();
            case cns_ValueRange: return stream << self->as_range();
            case cns_DurationRange: return stream << self->as_duration();
            case cns_TimePointRange:return stream << self->as_timepoint();
            case cns_RecurrenceRange: return stream << self->as_reccurence();
            case cns_ContainedSubtype: return stream << self->as_subtypeconstraint();
            case cns_TypeConstraint: return stream << self->as_typeconstraint();
            case cns_PermittedAlphabet:return stream << self->as_permitted();
            case cns_SizeConstraint: return stream << self->as_size();
            case cns_SingleTypeConstraint: return stream << self->as_singletype();
            case cns_PropertySettings: return stream << self->as_property();
            case cns_MultipleTypeConstraints: return stream << self->as_multipletypeconstraint();
            case cns_NamedConstraint: return stream << self->as_named();
            case cns_UNION: return stream << " | ";
            case cns_INTERSECTION: return stream << " & ";
            case cns_EXCEPT: return stream << " ^ ";
            case cns_ALLEXCEPT: return stream << " ~ ";
            case cns_EXTENTION: return stream << " ... ";
            case cns_EXCEPTION: return stream << self->as_exception();
        }
        return stream << "!!! NULL coctraint  !!!!";
    }

    std::ostream& operator<<(std::ostream& stream, valueconstraint_atom* self) {
        if (self->cotstrtype() == cns_PatternConstraint)
            return stream << "(PATTERN \"" << (self->value().get()) << "\")";
        return stream << (self->value().get());
    }

    std::ostream& operator<<(std::ostream& stream, typeconstraint_atom* self) {
        return stream << (self->type().get());
    }

    std::ostream& operator<<(std::ostream& stream, rangeconstraint_atom* self) {
        stream << "[";
        stream << (self->fromtype());
        if ((self->from()))
            stream << (self->from().get());
        stream << "..";
        stream << (self->totype());
        if ((self->to()))
            stream << (self->to().get());
        stream << "]";
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, namedconstraint_atom* self) {
        stream << self->name();
        if (self->constraints())
            stream << " " << self->constraints().get();
        return stream << self->marker();
    }

    std::ostream& operator<<(std::ostream& stream, constraintmarker_type tp) {
        switch (tp) {
                //case cmk_none:
            case cmk_optional: return stream << " OPTIONAL";
            case cmk_absent: return stream << " ABSENT";
            case cmk_present: return stream << " PRESENT";
                //case  cmk_extention,
                //case cmk_exception
            default:
            {
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, range_type tp) {
        switch (tp) {
            case min_range: return stream << "MIN";
            case max_range: return stream << "MAX";
            case open_range: return stream << "<>";
            default:
            {
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, complexconstraint_atom* self) {
        switch (self->cotstrtype()) {
            case cns_PermittedAlphabet: stream << " FROM";
                break;
            case cns_SizeConstraint: stream << " SIZE";
                break;
            case cns_SingleTypeConstraint: stream << " WITH COMPONENT";
                break;
            default:
            {
            }
        }
        return stream << " " << self->constraints().get();
    }

    std::ostream& operator<<(std::ostream& stream, multipletypeconstraint_atom * self) {
        stream << " WITH COMPONENTS { ";
        for (constraint_atom_vct::const_iterator it = self->components().begin(); it != self->components().end(); ++it)
            stream << (*it).get() << " ,";
        return stream << " }";
    }

    std::ostream& operator<<(std::ostream& stream, exceptionconstraint_atom* self) {
        return stream << " !" << self->type().get() << " : " << self->value().get();
    }


    // class

    std::ostream& operator<<(std::ostream& stream, classassignment_entity* self) {
        stream << "(C) " << self->name();
        if (self->has_arguments())
            stream << self->arguments();
        stream << " :: = ";
        if (self->_class()->builtin() == cl_SpecDef) {
            stream << " CLASS { ";
            for (basic_entity_vector::const_iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if ((*it) && ((*it)->as_classfield()))
                    stream << (*it)->as_classfield();
            }
            stream << " }";
            if (self->withsyntax()) {
                stream << "\n    WITH SYNTAX { \n   ";
                stream << self->withsyntax().get();
                stream << "    }";
            }

        }
        return stream << self->_class().get() << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, class_atom* self) {
        if (self->builtin() == cl_Reference) {
            if (self->reff()->as_expectdef())
                stream << "???" << self->reff()->name();
            else
                stream << self->reff()->name();
        } else {
            if (self->builtin() == cl_SpecDef)
                return stream;
            stream << self->builtin();
        }
        if (self->parameterized())
            stream << self->parameters();
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

    std::ostream& operator<<(std::ostream& stream, fieldkind_type self) {
        switch (self) {
            case fkind_NoDef: return stream << "!null";
            case fkind_TypeFieldSpec: return stream << "T";
            case fkind_FixedTypeValueFieldSpec: return stream << "FixTypeVal";
            case fkind_VariableTypeValueFieldSpec: return stream << "VTVal";
            case fkind_FixedTypeValueSetFieldSpec: return stream << "FixTypeValSet";
            case fkind_VariableTypeValueSetFieldSpec: return stream << "VTSet";
            case fkind_ObjectFieldSpec: return stream << "ObjectVal";
            case fkind_ObjectSetFieldSpec: return stream << "ObjectSet";
            case fkind_FixedType_or_Object: return stream << "?FixTypeVal or ObjectVal";
            case fkind_FixedTypeSet_or_ObjectSet: return stream << "?FixTypeSet or ObjectSet";
            default:
            {
            }
        }
        return stream << "!null";
    }

    std::ostream& operator<<(std::ostream& stream, field_entity* self) {
        switch (self->fieldkind()) {
            case fkind_TypeFieldSpec: return stream << self->as_typefield();
            case fkind_FixedTypeValueFieldSpec: return stream << self->as_valuefield();
            case fkind_FixedTypeValueSetFieldSpec: return stream << self->as_valuesetfield();
            case fkind_VariableTypeValueFieldSpec: return stream << self->as_reffvaluefield();
            case fkind_VariableTypeValueSetFieldSpec: return stream << self->as_reffvaluesetfield();
            case fkind_ObjectFieldSpec: return stream << self->as_objectfield();
            case fkind_ObjectSetFieldSpec: return stream << self->as_objectsetfield();
            case fkind_FixedType_or_Object: return stream << self->as_undeffield();
            case fkind_FixedTypeSet_or_ObjectSet: return stream << self->as_undefsetfield();
            default:
            {
            }
        }
        return stream << "\n      " << self->name() << " :  " << self->fieldkind();
    }

    std::ostream& operator<<(std::ostream& stream, typefield_entity* self) {
        stream << "\n      (  T)  " << self->name() << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, valuefield_entity* self) {
        stream << "\n      (v  )  " << self->name() << " " << self->type().get();
        if (self->unique())
            stream << " UNIQUE";
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, valuesetfield_entity* self) {
        stream << "\n      (vS )  " << self->name() << " " << self->type().get();
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, reffvaluefield_entity* self) {
        stream << "\n      ( *v)  " << self->name();
        if (self->field()->expecteddef())
            stream << " ??? " << self->field()->reff()->name();
        else
            stream << " " << self->field()->reff()->name();
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, reffvaluesetfield_entity* self) {
        stream << "\n      (*Vs)  " << self->name();
        if (self->field()->expecteddef())
            stream << " ??? " << self->field()->reff()->name();
        else
            stream << " " << self->field()->reff()->name();
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, objectfield_entity* self) {
        stream << "\n      (o  )  " << self->name() << " " << self->_class().get();
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, objectsetfield_entity* self) {
        stream << "\n      (oS )  " << self->name() << " " << self->_class().get();
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, undeffield_entity* self) {
        stream << "\n      (v???o)  " << self->name() << " ??? " << self->big()->expectedname();
        stream << " " << self->marker();
        if (self->_defaultv())
            stream << " ( v+  " << self->_defaultv().get() << ")";
        if (self->_defaulto())
            stream << " (o+  " << self->_defaulto().get() << ")";
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, undefsetfield_entity* self) {
        stream << "\n      (V???S)  " << self->name() << " ??? " << self->big()->expectedname();
        stream << " " << self->marker();
        if (self->_defaultv())
            stream << " ( vs+  " << self->_defaultv().get() << ")";
        if (self->_defaulto())
            stream << " (os+  " << self->_defaulto().get() << ")";
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, syntax_atom* self) {
        if (self->as_group()) {
            if (self->isalias())
                stream << " " << self->alias();
            if (self->optional())
                stream << " [- ";
            else
                stream << " <- ";
            stream << " " << self->as_group();
            if (self->optional())
                stream << " -] ";
            else
                stream << " -> ";
        } else {
            if (self->optional())
                stream << " [ ";
            else
                stream << " < ";
            if (self->isalias())
                stream << " '" << self->alias() << "' ";
            if (self->expecteddef())
                stream << " ??? " << self->reff()->name();
            else
                stream << " *" << self->reff()->name();
            if (self->optional())
                stream << " ] ";
            else
                stream << " > ";
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, groupsyntax_atom* self) {
        for (syntax_atom_vct::const_iterator it = self->group().begin(); it != self->group().end(); ++it) {
            if (it != self->group().begin())
                stream << "\n     " << (*it).get();
            else
                stream << "" << (*it).get();
        }
        return stream;
    }

    // object

    std::ostream& operator<<(std::ostream& stream, objectassignment_entity* self) {
        stream << "(o) " << self->name() << " [" << self->_class().get() << "]";
        if (self->has_arguments())
            stream << self->arguments();
        stream << " :: = ";
        if (self->childs().empty()) {
            if (self->object())
                return stream << self->object().get() << "\n";
        } else {
            stream << " {\n";
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if ((*it)->as_assigment()) {
                    stream << "     ";
                    if ((*it)->as_typeassigment()) {
                        stream << (*it)->as_typeassigment();
                        continue;
                    }
                    if ((*it)->as_valueassigment()) {
                        stream << (*it)->as_valueassigment();
                        continue;
                    }
                    if ((*it)->as_valuesetassigment()) {
                        stream << (*it)->as_valuesetassigment();
                        continue;
                    }
                    if ((*it)->as_objectassigment()) {
                        stream << (*it)->as_objectassigment();
                        continue;
                    }
                    if ((*it)->as_objectsetassigment()) {
                        stream << (*it)->as_objectsetassigment();
                        continue;
                    }
                }

            }
            return stream << "}\n";
        }
        return stream << "???" << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, object_atom* self) {
        switch (self->builtin()) {
            case ot_FromObject: return stream << self->as_fromobject();
            case ot_ObjectSetFromObjects:
            case ot_Refference: return stream << self->as_defined();
            case ot_DefinedObjectSet: return stream << self->as_definedset();
            case ot_Object: return stream << self->as_deflt();
            case ot_ObjectDefineSyn: return stream << self->as_defnsyntx();
            case ot_UNION: return stream << " | ";
            case ot_INTERSECTION: return stream << " & ";
            case ot_EXCEPT: return stream << " ^ ";
            case ot_ALLEXCEPT: return stream << " ~ ";
            case ot_EXTENTION: return stream << " ... ";
        }
        return stream << "!!!!NULL OBJECT";
    }

    std::ostream& operator<<(std::ostream& stream, definedobject_atom* self) {
        if (self->reff()->as_expectdef())
            stream << "??? ";
        stream << "" << self->reff()->name();
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, definedsetobject_atom* self) {
        if (self->reff()->as_expectdef())
            stream << "??? ";
        stream << "" << self->reff()->name();
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, defltobject_atom* self) {
        return stream << self->fieldsetting(); //self->reff()->name();
    }

    std::ostream& operator<<(std::ostream& stream, fromobjectobject_atom* self) {
        stream << "(o)" << self->object().get() << "." << self->field()->reff()->name();
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, defsyntxobject_atom* self) {
        //return stream << self->fieldsetting();
        stream << " {  ";
        for (fieldsetting_atom_vct::const_iterator it = self->fieldsetting().begin(); it != self->fieldsetting().end(); ++it) {
            fieldsettingstrm(stream, (*it).get());
        }
        return stream << " }";
    }

    std::ostream& operator<<(std::ostream& stream, const fieldsetting_atom_vct& self) {
        stream << " {  \n";
        for (fieldsetting_atom_vct::const_iterator it = self.begin(); it != self.end(); ++it) {
            stream << (*it).get();
        }
        return stream << " }";
    }

    std::ostream& operator<<(std::ostream& stream, fieldsetting_atom* self) {
        stream << "    " << self->field() << "   [";
        if (self->setting()) {
            stream << self->setting()->mask();
            if (self->setting()->type())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->value())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->valueset())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->_class())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->object())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->objectset())
                stream << "+";
            else
                stream << "-";
        } else
            stream << "???";
        return stream << "]\n";
    }

    std::ostream& operator<<(std::ostream& stream, const setting_atom_vct& self) {
        if (self.empty())
            return stream;
        stream << " (";
        for (setting_atom_vct::const_iterator it = self.begin(); it != self.end(); ++it) {
            if (it != self.begin())
                stream << " ,";
            stream << (*it).get();
        }
        return stream << " )";
    }

    std::ostream& operator<<(std::ostream& stream, setting_atom* self) {
        stream << "[arg@";
        if (self->type())
            stream << "+";
        else
            stream << "-";
        if (self->value())
            stream << "+";
        else
            stream << "-";
        if (self->valueset())
            stream << "+";
        else
            stream << "-";
        if (self->_class())
            stream << "+";
        else
            stream << "-";
        if (self->object())
            stream << "+";
        else
            stream << "-";
        if (self->objectset())
            stream << "+";
        else
            stream << "-";
        return stream << "]";
    }

    std::ostream& fieldsettingstrm(std::ostream& stream, fieldsetting_atom* self) {
        stream << "  {";
        if (self->setting()) {
            if (!self->setting()->literal().empty())
                stream << "  '" << self->setting()->literal() << "'";
            if (self->setting()->type())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->value())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->valueset())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->_class())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->object())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->objectset())
                stream << "+";
            else
                stream << "-";

        } else
            stream << "???";
        return stream << "} ";
    }


    //  objectset

    std::ostream& operator<<(std::ostream& stream, objectsetassignment_entity* self) {
        stream << "(oS) " << self->name() << " [" << self->_class().get() << "]";
        if (self->has_arguments())
            stream << self->arguments();
        stream << " :: = ";
        if (self->objectset())
            return stream << self->objectset().get() << "\n";
        return stream << "???" << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, objectset_atom* self) {
        switch (self->builtin()) {
            case os_Strait:
            {
                if (self->as_defn()) {
                    stream << "($ ";
                    for (object_atom_vct::const_iterator it = self->as_defn()->objects().begin(); it != self->as_defn()->objects().end(); ++it)
                        stream << " " << (*it).get();
                    stream << " $)";
                    return stream;
                }
                else   
                    return stream << "(oS)??? ";
            }
            case os_ObjectSetFromObjects:
            {
                stream << "(o)" << self->as_fromobjectset()->objectset().get() << "."
                        << self->as_fromobjectset()->field()->reff()->name();
                break;
            }
            case os_ObjectSetFromObject:            {
                stream << "(oS)" << self->as_fromobject()->object().get() << "."
                        << self->as_fromobject()->field()->reff()->name();
                break;
            }
            case os_defined:{
                if (self->reff()->as_expectdef())
                    stream << "??? ";
                stream << " " << self->reff()->name();
            }
            default:{}
        }
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }


    // big

    std::ostream& operator<<(std::ostream& stream, bigassignment_entity* self) {
        return stream << "(?B)" << self->name() << " :: = " << "\n";
    }


    // value or object

    std::ostream& operator<<(std::ostream& stream, voassignment_entity* self) {
        stream << "(?VO)" << self->name() << " [ ??? " << self->big()->reff()->name() << "] :: = ";
        if (self->value())
            stream << "(+v)";
        else
            stream << "(-v)";
        if (self->object())
            stream << "(+o)";
        else
            stream << "(-o)";
        return stream << "\n";
    }

    // valueset or objectset

    std::ostream& operator<<(std::ostream& stream, soassignment_entity* self) {
        stream << "(?SO)" << self->name() << " [???" << self->big()->reff()->name() << "] :: = ";
        if (self->valueset())
            stream << "(+vs)";
        else
            stream << "(-vs)";
        if (self->objectset())
            stream << "(+os)";
        else
            stream << "(-os)";
        return stream << "\n";
    }




}
