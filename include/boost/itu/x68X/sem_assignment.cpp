//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>

namespace x680 {

    void debug_warning(const std::string& msg) {
        std::cout << msg << std::endl;
    }

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

    argument_entity* basic_entity::as_argument() {
        return dynamic_cast<argument_entity*> (this);
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
        else if (as_objectassigment())
            rslt = rslt + " in objectassignment";
        else if (as_objectsetassigment())
            rslt = rslt + " in objectsetassignment";        
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

    basic_entity_ptr basic_entity::find(const basic_entity_ptr& reff, search_marker sch) {
        if (reff->as_expectdef()) {
            if (reff->as_expectdef()->ismodule()) {
                if (reff->moduleref())
                    return reff->moduleref()->find_in_importmodule(reff->as_expectdef()->module(), reff->as_expectdef()->name());
                else
                    basic_entity_ptr();
            } else {
                return find_by_name(reff->as_expectdef()->name(), sch);
            }
        }
        return reff;
    }

    basic_entity_ptr basic_entity::find_by_name(const std::string& nm, search_marker sch) {
        //throw semantics::error("Idenifier" + nm + " not found");
        return basic_entity_ptr();
    }

    void basic_entity::resolve(basic_atom_ptr holder) {
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

    void global_entity::resolve(basic_atom_ptr holder) {
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

    basic_entity_ptr global_entity::find_by_name(const std::string& nm, search_marker sch) {
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

    void import_entity::resolve(basic_atom_ptr holder) {
        if (objectid())
            objectid()->resolve();
    }

    basic_entity_ptr import_entity::find_by_name(const std::string& nm, search_marker sch) {
        for (import_vector::iterator it = import_.begin(); it != import_.end(); ++it)
            if (((*it) == nm) && (scope()))
                return scope()->find_by_name(nm, sch);
        return basic_entity_ptr();
    }

    /////////////////////////////////////////////////////////////////////////   
    // module_entity
    /////////////////////////////////////////////////////////////////////////   

    module_entity::module_entity(basic_entity_ptr scope, const std::string& nm, const std::string& fl, bool allexp)
    : basic_entity(scope, nm, et_Module), file_(fl), allexport_(allexp) {
    }

    /////

    basic_entity_ptr module_entity::find_by_name(const std::string& nm, search_marker sch) {
        prefind(nm, childs());
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->name() == nm)
                return *it;
        for (basic_entity_vector::iterator it = imports().begin(); it != imports().end(); ++it) {
            import_entity* importmod = (*it)->as_import();
            if (importmod) {
                basic_entity_ptr fnd = importmod->find_by_name(nm, sch);
                if (fnd)
                    return fnd;
            }
        }
        if (scope())
            return scope()->find_by_name(nm, sch);
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

    void module_entity::resolve(basic_atom_ptr holder) {
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
                if ((fnd->kind() == et_Type) && (tmp->bigT()))
                    return tmp->bigT();
                if ((fnd->kind() == et_Class) && (tmp->bigC()))
                    return tmp->bigC();
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
                if ((fnd->kind() == et_Type) && (tmp->bigT()))
                    return tmp->bigT();
                if ((fnd->kind() == et_Class) && (tmp->bigC()))
                    return tmp->bigC();
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
                if ((fnd->kind() == et_Type) && (tmp->bigT()))
                    return tmp->bigT();
                if ((fnd->kind() == et_Class) && (tmp->bigC()))
                    return tmp->bigC();
            } else {
                tmp->referenceerror_throw(tmp->big()->reff()->name());
            }
        }
        tmp->referenceerror_throw(tmp->name());
        return basic_entity_ptr();
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
        if (tp == argm_Big) {
            unspecified_ = assignment_entity_ptr(new valuesetassignment_entity(scope, nm, gvnr));
            argumenttype_ = argm_ValueSet;
        } else {
            unspecified_ = assignment_entity_ptr(new valueassignment_entity(scope, nm, gvnr));
            argumenttype_ = argm_Value;
        }
    }

    argument_entity::argument_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr gvnr, argumentsize_type tp)
    : basic_entity(scope, nm, et_Argument), typesize_(tp), argumenttype_(argm_Nodef), governor_(gvnr) {
        if (tp == argm_Big) {
            unspecified_ = assignment_entity_ptr(new objectsetassignment_entity(scope, nm, gvnr));
            argumenttype_ = argm_ObjectSet;
        } else {
            unspecified_ = assignment_entity_ptr(new objectassignment_entity(scope, nm, gvnr));
            argumenttype_ = argm_Object;
        }
    }

    bool argument_entity::has_undef_governor() const {
        return ( governor_ && !((governor_->as_type()) || (governor_->as_class())));
    }

    void argument_entity::governor(type_atom_ptr vl) {
        if (argumenttype_ != argm_Nodef)
            scope()->referenceerror_throw(name(), "Internal error: duplicate argument governer set");
        governor_ = vl;
        if (typesize_ == argm_Big) {
            unspecified_ = assignment_entity_ptr(new valuesetassignment_entity(scope(), name(), vl));
            argumenttype_ = argm_ValueSet;
        } else {
            unspecified_ = assignment_entity_ptr(new valueassignment_entity(scope(), name(), vl));
            argumenttype_ = argm_Value;
        }
    }

    void argument_entity::governor(class_atom_ptr vl) {
        if (argumenttype_ != argm_Nodef)
            scope()->referenceerror_throw(name(), "Internal error: duplicate argument governer set");
        governor_ = vl;
        if (typesize_ == argm_Big) {
            unspecified_ = assignment_entity_ptr(new objectsetassignment_entity(scope(), name(), vl));
            argumenttype_ = argm_ObjectSet;
        } else {
            unspecified_ = assignment_entity_ptr(new objectassignment_entity(scope(), name(), vl));
            argumenttype_ = argm_Object;
        }
    }

    void argument_entity::governor(basic_atom_ptr vl) {
        governor_ = vl;
    }

    void argument_entity::insert_dummyrefference(basic_atom_ptr val) {
        if (argumenttype_ == argm_Nodef) {
            if (val->as_type()) {
                unspecified_ = assignment_entity_ptr(new typeassignment_entity(scope(), name()));
                argumenttype_ = argm_Type;
            } else if (val->as_class()) {
                unspecified_ = assignment_entity_ptr(new classassignment_entity(scope(), name()));
                argumenttype_ = argm_Class;
            } else
                debug_warning("Should be error argument type set");
        }
        switch (argumenttype_) {
            case argm_Type:
            {
                if (!val->as_type())
                    debug_warning("Should be error argument type ambiguous: Type ");
                break;
            }
            case argm_Value:
            {
                if (!val->as_value())
                    debug_warning("Should be error argument type ambiguous: Value ");
                break;
            }
            case argm_ValueSet:
            {
                if (!val->as_valueset())
                    debug_warning("Should be error argument type ambiguous: ValueSet ");
                break;
            }
            case argm_Class:
            {
                if (!val->as_class())
                    debug_warning("Should be error argument type ambiguous: Class ");
                break;
            }
            case argm_Object:
            {
                if (!val->as_object())
                    debug_warning("Should be error argument type ambiguous: Object ");
                break;
            }
            case argm_ObjectSet:
            {
                if (!val->as_objectset())
                    debug_warning("Should be error argument type ambiguous: ObjectSet ");
                break;
            }
            default:
            {
                debug_warning("Should be error argument type dummy insert ");
                return;
            }
        }
        val->isdummy(true);
        val->reff(unspecified_);
        dummyrefferences_.push_back(val);
    }

    void argument_entity::resolve(basic_atom_ptr holder) {
        if (has_governor())
            governor()->resolve_reff();

    }


    /////////////////////////////////////////////////////////////////////////   
    // basic_atom
    /////////////////////////////////////////////////////////////////////////   

    basic_atom::basic_atom(basic_entity_ptr scp) : scope_(scp), extention_(false), isdummy_(false) {
    };

    basic_atom::basic_atom(const std::string& reff, basic_entity_ptr scp) : scope_(scp), extention_(false), isdummy_(false) {
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

    void basic_atom::resolve(basic_atom_ptr holder) {
    }

void basic_atom::resolve_reff(basic_atom_ptr holder, search_marker sch) {
        if ((scope()) && (reff()) && (reff()->as_expectdef())) {
            basic_entity_ptr source = holder ?
                    (holder->reff() ? holder->reff() : holder->scope()) : scope();
            if (source) {
                basic_entity_ptr fnd = source->find(reff(), holder ? local_search : sch);
                if (fnd) {
                    if (fnd->as_typeassigment()) {
                        if (!as_type())
                            debug_warning("Should be error : " + expectedname() + " ref to typeassigment");
                    } else if (fnd->as_valueassigment()) {
                        if (!as_value())
                            debug_warning("Should be error : " + expectedname() + " ref to valueassigment");
                    } else if (fnd->as_valuesetassigment()) {
                        if (!as_valueset())
                            debug_warning("Should be error : " + expectedname() + " ref to valuesetassigment");
                    } else if (fnd->as_classassigment()) {
                        if (!as_class())
                            debug_warning("Should be error : " + expectedname() + " ref to classassigment");
                    } else if (fnd->as_objectassigment()) {
                        if (!as_object())
                            debug_warning("Should be error : " + expectedname() + " ref to objectassigment");
                    } else if (fnd->as_objectsetassigment()) {
                        if (!as_objectset())
                            debug_warning("Should be error : " + expectedname() + " ref to objectsetassigment");
                    } else if (fnd->as_argument()) {
                        debug_warning("Here is argument parser: " + expectedname() + "");
                        fnd->as_argument()->insert_dummyrefference(self());
                        return;
                    } else
                        debug_warning("Should be error : refference" + expectedname() + "undefined assigment");
                    reff(fnd);
                } else {
                    if (holder) {
                        resolve_reff(basic_atom_ptr(), sch);
                        return;
                    } else
                        debug_warning("Should be error : refference : " + expectedname() + "  source : " +
                            source->name() + "  scope : " + scope()->name());
                }
            } else
                debug_warning("Should be error : refference : " + expectedname() + "  not found : no holder");
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

    basic_entity_ptr assignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        for (argument_entity_vct::const_iterator it = arguments_.begin(); it != arguments_.end(); ++it)
            if ((*it)->name() == nm)
                return (*it);
        return basic_entity_ptr();
    }

    void assignment_entity::resolve(basic_atom_ptr holder) {
        for (argument_entity_vct::const_iterator it = arguments_.begin(); it != arguments_.end(); ++it)
            if ((*it)->governor())
                (*it)->resolve();
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
    // BIG
    /////////////////////////////////////////////////////////////////////////   
    // bigassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    bigassignment_entity::bigassignment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg) :
    assignment_entity(scope, nm, et_Nodef), big_(bg) {
    };

    basic_entity_ptr bigassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
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

    basic_entity_ptr voassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        if (scope())
            return scope()->find_by_name(nm, sch);
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

    basic_entity_ptr soassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        if (scope())
            return scope()->find_by_name(nm, sch);
        return basic_entity_ptr();
    }

}
