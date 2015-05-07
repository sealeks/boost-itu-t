//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>

namespace x680 {

    bool objectassignment_entity_ptr_less::operator()(const objectassignment_entity_ptr& l, const objectassignment_entity_ptr& r) const {
        if (l && r)
            return (*l) < (*r);
        return r ? true : false;
    }

    namespace semantics {

        std::ostream& operator<<(std::ostream& stream, const error& self) {
            stream << "Semantic error: " << self.message() << "\n";
            return stream;
        }

    }

    void debug_warning(const std::string& msg) {
        std::cout << msg << std::endl;
        std::cout.flush();
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

    assignment_entity_ptr basic_entity::parent(std::size_t rng) {
        if (as_assigment()) {
            basic_entity_ptr self = as_assigment();
            /*(as_assigment()->shadow_for()) ? as_assigment()->shadow_for() : as_assigment()*/;
            basic_entity_ptr scp = ((self->scope()) && (self->scope()->reff_shadow())) ? self->scope()->reff_shadow() : self->scope();
            if (scp) {
                if (rng)
                    return scp->parent(--rng);
                if (scp->as_assigment())
                    return scp->as_assigment();
            }
        }
        return assignment_entity_ptr();
    }

    void basic_entity::reff_shadow(basic_entity_ptr vl) {
        reff_shadow_ = vl;
        if (vl)
            vl->shadow_for(self());
    }

    void basic_entity::shadow_for(basic_entity_ptr vl) {
        if (vl && (vl.get() == this))
            throw semantics::error("Internal error selfscoping :" + name());
        shadow_for_ = basic_entity_wptr(vl);
    }

    basic_entity_vector& basic_entity::childs() {
        return childs_;
    }

    void basic_entity::childs(basic_entity_vector& vl) {
        childs_ = vl;
        for (basic_entity_vector::const_iterator it = childs_.begin(); it != childs_.end(); ++it) {
            if (*it)
                (*it)->scope(self());
        }
    }

    std::size_t basic_entity::level() const {
        std::size_t rslt = 0;
        basic_entity_ptr scp = (shadow_for()) ? shadow_for()->scope() : scope();
        while (scp) {
            if (!(scp->shadow_for())) {
                if (!((scp->as_typeassigment()) && (scp->as_typeassigment()->isstruct_of())))
                    rslt++;
                scp = scp->scope();
            } else {
                scp = scp->shadow_for();
            }
        }
        return rslt;
    }

    global_entity_ptr basic_entity::as_global() {
        return kind_ == et_Global ? boost::static_pointer_cast<global_entity> (self()) : global_entity_ptr();
    }

    module_entity_ptr basic_entity::as_module() {
        return kind_ == et_Module ? boost::static_pointer_cast<module_entity> (self()) : module_entity_ptr();
    }

    expectdef_entity_ptr basic_entity::as_expectdef() {
        return kind_ == et_NodefE ? boost::static_pointer_cast<expectdef_entity> (self()) : expectdef_entity_ptr();
    }

    import_entity_ptr basic_entity::as_import() {
        return kind_ == et_Import ? boost::static_pointer_cast<import_entity> (self()) : import_entity_ptr();
    }

    assignment_entity_ptr basic_entity::as_assigment() {
        return ((kind_ == et_Type)
                || (kind_ == et_Value)
                || (kind_ == et_ValueSet)
                || (kind_ == et_Class)
                || (kind_ == et_Object)
                || (kind_ == et_ObjectSet)) ? boost::static_pointer_cast<assignment_entity> (self()) : assignment_entity_ptr();
    }

    argument_entity_ptr basic_entity::as_argument() {
        return kind_ == et_Argument ? boost::static_pointer_cast<argument_entity> (self()) : argument_entity_ptr();
    }

    uargument_entity_ptr basic_entity::as_uargument() {
        return kind_ == et_UArgument ? boost::static_pointer_cast<uargument_entity> (self()) : uargument_entity_ptr();
    }

    bigassignment_entity_ptr basic_entity::as_bigassigment() {
        return kind_ == et_NodefT ? boost::static_pointer_cast<bigassignment_entity> (self()) : bigassignment_entity_ptr();
    }

    voassignment_entity_ptr basic_entity::as_voassigment() {
        return kind_ == et_NodefV ? boost::static_pointer_cast<voassignment_entity > (self()) : voassignment_entity_ptr();
    }

    soassignment_entity_ptr basic_entity::as_soassigment() {
        return kind_ == et_NodefS ? boost::static_pointer_cast<soassignment_entity > (self()) : soassignment_entity_ptr();
    }

    typeassignment_entity_ptr basic_entity::as_typeassigment() {
        return kind_ == et_Type ? boost::static_pointer_cast<typeassignment_entity> (self()) : typeassignment_entity_ptr();
    }

    typeassignment_entity_ptr basic_entity::as_typeassigment(basic_entity_vector::iterator it) {
        return (*it) ? ((*it)->as_typeassigment()) : typeassignment_entity_ptr();
    }

    namedtypeassignment_entity_ptr basic_entity::as_named_typeassigment() {
        typeassignment_entity_ptr tmp = as_typeassigment();
        return tmp ? tmp->as_named() : namedtypeassignment_entity_ptr();
    }

    namedtypeassignment_entity_ptr basic_entity::as_named_typeassigment(basic_entity_vector::iterator it) {
        return (*it) ? ((*it)->as_named_typeassigment()) : namedtypeassignment_entity_ptr();
    }

    valueassignment_entity_ptr basic_entity::as_valueassigment() {
        return kind_ == et_Value ? boost::static_pointer_cast<valueassignment_entity> (self()) : valueassignment_entity_ptr();
    }

    valueassignment_entity_ptr basic_entity::as_valueassigment(basic_entity_vector::iterator it) {
        return (*it) ? ((*it)->as_valueassigment()) : valueassignment_entity_ptr();
    }

    valuesetassignment_entity_ptr basic_entity::as_valuesetassigment() {
        return kind_ == et_ValueSet ? boost::static_pointer_cast<valuesetassignment_entity> (self()) : valuesetassignment_entity_ptr();
    }

    classassignment_entity_ptr basic_entity::as_classassigment() {
        return kind_ == et_Class ? boost::static_pointer_cast<classassignment_entity> (self()) : classassignment_entity_ptr();
    }

    objectassignment_entity_ptr basic_entity::as_objectassigment() {
        return kind_ == et_Object ? boost::static_pointer_cast<objectassignment_entity> (self()) : objectassignment_entity_ptr();
    }

    objectsetassignment_entity_ptr basic_entity::as_objectsetassigment() {
        return kind_ == et_ObjectSet ? boost::static_pointer_cast<objectsetassignment_entity> (self()) : objectsetassignment_entity_ptr();
    }

    field_entity_ptr basic_entity::as_classfield() {
        return kind_ == et_ClassField ? boost::static_pointer_cast<field_entity> (self()) : field_entity_ptr();
    }

    extention_entity_ptr basic_entity::as_extention() {
        return kind_ == et_Extention ? boost::static_pointer_cast<extention_entity> (self()) : extention_entity_ptr();
    }

    type_atom_ptr basic_entity::extract_type() {
        return as_typeassigment() ? (as_typeassigment()->type()) : (type_atom_ptr());
    }

    type_atom_ptr basic_entity::extract_type(basic_entity_vector::iterator it) {
        return (*it) ? ((*it)->extract_type()) : (type_atom_ptr());
    }

    value_atom_ptr basic_entity::extract_value() {
        return as_valueassigment() ? (as_valueassigment()->value()) : (value_atom_ptr());
    }

    value_atom_ptr basic_entity::extract_value(basic_entity_vector::iterator it) {
        return (*it) ? ((*it)->extract_value()) : (value_atom_ptr());
    }

    module_entity_ptr basic_entity::moduleref() {
        module_entity_ptr rf = as_module();
        basic_entity_ptr sc = scope();
        while ((!rf) && (sc)) {
            rf = sc->as_module();
            sc = sc->scope();
        }
        return rf;
    }

    std::string basic_entity::modulerefname() {
        module_entity_ptr rf = moduleref();
        if (rf)
            return " in module: " + rf->name() + " in file: " + rf->file();
        return " in undefined module";
    }

    std::string basic_entity::source_throw() {
        std::string rslt = "";
        if (as_typeassigment()) {
            if (as_typeassigment()->as_named())
                rslt = rslt + " in named type";
            else
                rslt = rslt + " in typeassignment";
        } else if (as_valueassigment())
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
        basic_entity_ptr sc = self();
        std::string stack = "";
        if ((scope()) && (moduleref()) && (moduleref() != self())) {
            while ((sc) && (moduleref() != sc)) {
                stack = stack.empty() ? sc->name() : (sc->name() + "." + stack);
                sc = sc->scope();
            }
            if (moduleref() == sc)
                stack = sc->name() + "@" + stack;
            rslt = rslt + " " + stack + " ";
            sc = scope();
        } else
            rslt = rslt + " ";
        return rslt;
    }

    void basic_entity::referenceerror_throw(const std::string& msg, const std::string& nm) {
        std::string rslt = msg;
        if (!nm.empty())
            rslt += " '" + nm + "' ";
        rslt += source_throw();
        rslt = rslt + " " + modulerefname();
        throw semantics::error(rslt);
    }

    void basic_entity::unicalelerror_throw(const basic_entity_vector& elms) {
        std::set<std::string> set;
        for (basic_entity_vector::const_iterator it = elms.begin(); it != elms.end(); ++it) {
            if ((*it)->as_extention()) {
            } else {
                if (!(*it)->name().empty()) {
                    if (set.find((*it)->name()) != set.end())
                        throw semantics::error("Identifier '" + (*it)->name() + "' duplicates "
                            + (*it)->source_throw() + " " + modulerefname());
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
                    return reff->moduleref()->find_in_importmodule(
                        reff->as_expectdef()->module(), reff->as_expectdef()->name());
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

    void basic_entity::after_resolve() {
        after_resolve_child();
    }

    void basic_entity::resolve_child() {
        for (basic_entity_vector::const_iterator it = childs_.begin(); it != childs_.end(); ++it) {
            (*it)->resolve();
        }
    }

    void basic_entity::after_resolve_child() {
        for (basic_entity_vector::const_iterator it = childs().begin(); it != childs().end(); ++it) {
            if (*it)
                (*it)->after_resolve();
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

    std::string basic_entity::subidentifier(std::string& nm) {
        std::string rslt = nm;
        std::string::size_type it = nm.find_first_of('.');
        if ((it != std::string::npos) && ((it) && (it < (nm.size() - 1)))) {
            rslt = nm.substr(0, it);
            nm = nm.substr(it + 1);
        } else
            nm = "";
        return rslt;
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

    module_entity::module_entity(basic_entity_ptr scope, const std::string& nm,
            const std::string& fl, bool allexp, tagrule_type tgr, bool ext)
    : basic_entity(scope, nm, et_Module), file_(fl), allexport_(allexp),
    extesibility_implied_(ext), tagrule_(tgr) {
    }

    /////

    basic_entity_ptr module_entity::find_by_name(const std::string& nm, search_marker sch) {
        prefind(nm, childs());
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if ((*it)->name() == nm)
                return *it;
        for (basic_entity_vector::iterator it = imports().begin(); it != imports().end(); ++it) {
            import_entity_ptr importmod = (*it)->as_import();
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
            import_entity_ptr importmod = (*it)->as_import();
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
            import_entity_ptr importmod = (*it)->as_import();
            if (importmod && (importmod->objectid())) {
                importmod->objectid()->resolve();
            }
        }
        for (basic_entity_vector::iterator it = imports().begin(); it != imports().end(); ++it) {
            import_entity_ptr importmod = (*it)->as_import();
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

    std::vector<std::string> module_entity::setfrom_objid(value_atom_ptr vls) {
        std::vector<std::string> tmp;
        structvalue_atom_ptr vl = vls->as_list();
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
            return (setfrom_objid(ls) == setfrom_objid(rs));
        return false;
    }

    void module_entity::preresolve_assigments(basic_entity_vector& elm) {
        for (basic_entity_vector::iterator it = elm.begin(); it != elm.end(); ++it) {
            switch ((*it)->kind()) {
                case et_NodefT: *it = preresolve_nodef_assigment(*it);
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
        bigassignment_entity_ptr tmp = elm->as_bigassigment();
        if (tmp && (tmp->big()) && (tmp->big()->reff())) {
            basic_entity_ptr fnd = elm->find(tmp->big()->reff());
            if (fnd) {
                if ((fnd->kind() == et_Type) && (tmp->bigT())) {
                    tmp->bigT()->synctas(tmp->synctasT());
                    return tmp->bigT();
                }
                if ((fnd->kind() == et_Class) && (tmp->bigC())) {
                    tmp->bigC()->synctas(tmp->synctasC());
                    return tmp->bigC();
                }
            } else {
                tmp->referenceerror_throw("Assighment refference error : ");
            }
        }
        tmp->referenceerror_throw("Assighment refference error : ");
        return basic_entity_ptr();
    }

    basic_entity_ptr module_entity::preresolve_nodefv_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        /*if (!start)
            start = elm;
        else
            check_resolve_ciclic(elm, start);*/
        voassignment_entity_ptr tmp = elm->as_voassigment();
        if (tmp && (tmp->big()) && (tmp->big()->reff())) {
            basic_entity_ptr fnd = elm->find(tmp->big()->reff());
            if (fnd) {
                if ((fnd->kind() == et_Type) && (tmp->bigT())) {
                    tmp->bigT()->synctas(tmp->synctasT());
                    return tmp->bigT();
                }
                if ((fnd->kind() == et_Class) && (tmp->bigC())) {
                    tmp->bigC()->synctas(tmp->synctasC());
                    return tmp->bigC();
                }
            } else {
                tmp->referenceerror_throw("Assighment refference error : ");
            }
        }
        tmp->referenceerror_throw("Assighment refference error : ");
        return basic_entity_ptr();
    }

    basic_entity_ptr module_entity::preresolve_nodefs_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        /*if (!start)
            start = elm;
        else
            check_resolve_ciclic(elm, start);*/
        soassignment_entity_ptr tmp = elm->as_soassigment();
        if (tmp && (tmp->big()) && (tmp->big()->reff())) {
            basic_entity_ptr fnd = elm->find(tmp->big()->reff());
            if (fnd) {
                if ((fnd->kind() == et_Type) && (tmp->bigT())) {
                    tmp->bigT()->synctas(tmp->synctasT());
                    return tmp->bigT();
                }
                if ((fnd->kind() == et_Class) && (tmp->bigC())) {
                    tmp->bigC()->synctas(tmp->synctasC());
                    return tmp->bigC();
                }
            } else {
                tmp->referenceerror_throw("Assighment refference error : ");
            }
        }
        tmp->referenceerror_throw("Assighment refference error : ");
        return basic_entity_ptr();
    }



    /////////////////////////////////////////////////////////////////////////   
    // expectdef_entity
    /////////////////////////////////////////////////////////////////////////

    expectdef_entity::expectdef_entity(basic_entity_ptr scope, const std::string& nm)
    : basic_entity(scope, nm, et_NodefE) {
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
    : basic_entity(scope, nm, et_Argument), governor_(gvnr), typesize_(tp), argumenttype_(argm_Nodef) {
    }

    argument_entity::argument_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr gvnr, argumentsize_type tp)
    : basic_entity(scope, nm, et_Argument), governor_(gvnr), typesize_(tp), argumenttype_(argm_Nodef) {
        if (tp == argm_Big) {
            unspecified_ = assignment_entity_ptr(new valuesetassignment_entity(scope, nm, gvnr));
            argumenttype_ = argm_ValueSet;
        } else {
            unspecified_ = assignment_entity_ptr(new valueassignment_entity(scope, nm, gvnr));
            argumenttype_ = argm_Value;
        }
    }

    argument_entity::argument_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr gvnr, argumentsize_type tp)
    : basic_entity(scope, nm, et_Argument), governor_(gvnr), typesize_(tp), argumenttype_(argm_Nodef) {
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

    basic_atom_ptr argument_entity::reff() {
        return reff_;
    }

    void argument_entity::governor(type_atom_ptr vl) {
        if (argumenttype_ != argm_Nodef)
            scope()->referenceerror_throw("Internal error: duplicate argument governer set ; ", name());
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
            scope()->referenceerror_throw("Internal error: duplicate argument governer set : ", name());
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

    void argument_entity::apply_argument(setting_atom_ptr val, basic_entity_ptr scp) {
        if (!val->as_setting())
            throw semantics::error("");
        setting_atom_ptr vl = val->as_setting();
        switch (argumenttype_) {
            case argm_Type:
            {
                if (vl->type()) {
                    if ((unspecified_) && (unspecified_->as_typeassigment())) {
                        unspecified_->as_typeassigment()->type(vl->type());
                        unspecified_->as_typeassigment()->childs(vl->typeassignment()->childs());
                        if (scp) {
                            unspecified_->scope(scp);
                            //unspecified_->as_typeassigment()->type()->scope(unspecified_);
                        }
                    }
                    reff_ = vl->type();
                } else
                    throw semantics::error("");
                break;
            }
            case argm_Value:
            {
                if (vl->value()) {
                    if ((unspecified_) && (unspecified_->as_valueassigment())) {
                        unspecified_->as_valueassigment()->value(vl->value());
                        if (scp) {
                            unspecified_->scope(scp);
                            //unspecified_->as_valueassigment()->value()->scope(unspecified_);
                        }
                    }
                    reff_ = vl->value();
                } else
                    throw semantics::error("");
                break;
            }
            case argm_ValueSet:
            {
                if (vl->valueset()) {
                    if ((unspecified_) && (unspecified_->as_valuesetassigment())) {
                        unspecified_->as_valuesetassigment()->valueset(vl->valueset());
                        if (scp) {
                            unspecified_->scope(scp);
                            //unspecified_->as_valuesetassigment()->valueset()->scope(unspecified_);
                        }
                    }
                    reff_ = vl->valueset();
                } else
                    throw semantics::error("");
                break;
            }
            case argm_Class:
            {
                if (vl->_class()) {
                    if ((unspecified_) && (unspecified_->as_classassigment())) {
                        unspecified_->as_classassigment()->_class(vl->_class());
                        unspecified_->as_classassigment()->childs(vl->classassignment()->childs());
                        if (scp) {
                            unspecified_->scope(scp);
                            //unspecified_->as_classassigment()->_class()->scope(unspecified_);;
                        }
                    }
                    reff_ = vl->_class();
                } else
                    throw semantics::error("");
                break;
            }
            case argm_Object:
            {
                if (vl->object()) {
                    if ((unspecified_) && (unspecified_->as_objectassigment())) {
                        unspecified_->as_objectassigment()->object(vl->object());
                        if (scp) {
                            unspecified_->scope(scp);
                            //unspecified_->as_objectassigment()->object()->scope(unspecified_);;
                        }
                    }
                    reff_ = vl->object();
                } else
                    throw semantics::error("");
                break;
            }
            case argm_ObjectSet:
            {
                if (vl->objectset()) {
                    if ((unspecified_) && (unspecified_->as_objectsetassigment())) {
                        unspecified_->as_objectsetassigment()->objectset(vl->objectset());
                        if (scp) {
                            unspecified_->scope(scp);
                            //unspecified_->as_objectsetassigment()->objectset()->scope(unspecified_);;
                        }
                    }
                    reff_ = vl->objectset();
                } else
                    throw semantics::error("");
                break;
            }
            default:
            {
                //case argm_WillbeDef:{
                if (!has_governor()) {
                    if (vl->type()) {
                        argumenttype_ = argm_Type;
                        assignment_entity_ptr unspecifiedn_ = assignment_entity_ptr(new typeassignment_entity(scope(), name()));
                        unspecifiedn_->as_typeassigment()->type(vl->type());
                        unspecifiedn_->as_typeassigment()->childs(vl->typeassignment()->childs());
                        unspecifiedn_.swap(unspecified_);
                        if (scp) {
                            unspecified_->scope(scp);
                            //unspecified_->as_typeassigment()->type()->scope(unspecified_);
                        }
                        break;
                    } else if (vl->_class()) {
                        argumenttype_ = argm_Class;
                        assignment_entity_ptr unspecifiedn_ = assignment_entity_ptr(new classassignment_entity(scope(), name()));
                        unspecifiedn_->as_classassigment()->_class(vl->_class());
                        unspecifiedn_->as_classassigment()->childs(vl->classassignment()->childs());
                        unspecifiedn_.swap(unspecified_);
                        if (scp) {
                            unspecified_->scope(scp);
                            //unspecified_->as_classassigment()->_class()->scope(unspecified_);
                        }
                        break;
                    }
                }
                throw semantics::error("");
            }
                /*default:
                {
                    throw semantics::error("");
                }*/
        }
    }

    void argument_entity::clear_argument() {
        if (unspecified_) {
            if (unspecified_->as_typeassigment()) {
                unspecified_->as_typeassigment()->type(type_atom_ptr());
                unspecified_->as_typeassigment()->childs().clear();
            } else if (unspecified_->as_valueassigment()) {
                unspecified_->as_valueassigment()->value(value_atom_ptr());
            } else if (unspecified_->as_valuesetassigment()) {
                unspecified_->as_valuesetassigment()->valueset(valueset_atom_ptr());
            } else if (unspecified_->as_classassigment()) {
                unspecified_->as_classassigment()->_class(class_atom_ptr());
            } else if (unspecified_->as_objectassigment()) {
                unspecified_->as_objectassigment()->object(object_atom_ptr());
            } else if (unspecified_->as_objectsetassigment()) {
                unspecified_->as_objectsetassigment()->objectset(objectset_atom_ptr());
            }
        }
    }

    void argument_entity::insert_dummyrefference(basic_atom_ptr val) {
        if (argumenttype_ == argm_Nodef) {
            if (val->as_type()) {
                unspecified_ = assignment_entity_ptr(new typeassignment_entity(scope(), name()));
                argumenttype_ = argm_Type;
            } else if (val->as_class()) {
                unspecified_ = assignment_entity_ptr(new classassignment_entity(scope(), name()));
                argumenttype_ = argm_Class;
            } else if (val->kind() == at_Nodef) {
                unspecified_ = assignment_entity_ptr(new assignment_entity(scope(), name(), et_Nodef));
                argumenttype_ = argm_WillbeDef;
            } else {

#ifdef  DEBUG_SEMANTIC                
                debug_warning("Should be error argument type set");
#else
                val->scope()->referenceerror_throw("Should be error argument type set ; ", name());
#endif                
                return;
            }
        }
        switch (argumenttype_) {
            case argm_Type:
            {
                if (!val->as_type()) {
#ifdef  DEBUG_SEMANTIC                
                    debug_warning("Should be error argument type ambiguous: Type ");
#else
                    val->scope()->referenceerror_throw("Argument type ambiguous: Type expected : ", name());
#endif                         
                    return;
                }
                break;
            }
            case argm_Value:
            {
                if (!val->as_value()) {
#ifdef  DEBUG_SEMANTIC                
                    debug_warning("Should be error argument type ambiguous: Value ");
#else
                    val->scope()->referenceerror_throw("Argument type ambiguous. Value expected : ", name());
#endif    
                    return;
                }
                break;
            }
            case argm_ValueSet:
            {
                if (!val->as_valueset()) {
#ifdef  DEBUG_SEMANTIC                
                    debug_warning("Should be error argument type ambiguous: ValueSet ");
#else
                    val->scope()->referenceerror_throw("Argument type ambiguous. ValueSet expected : ", name());
#endif   
                    return;
                }
                break;
            }
            case argm_Class:
            {
                if (!val->as_class()) {
#ifdef  DEBUG_SEMANTIC                
                    debug_warning("Should be error argument type ambiguous: Class ");
#else
                    val->scope()->referenceerror_throw("Argument type ambiguous. Class expected : ", name());
#endif   
                    return;
                }
                break;
            }
            case argm_Object:
            {
                if (!val->as_object()) {
#ifdef  DEBUG_SEMANTIC                
                    debug_warning("Should be error argument type ambiguous: Object ");
#else
                    val->scope()->referenceerror_throw("Argument type ambiguous. Object expected : ", name());
#endif   
                    return;
                }
                break;
            }
            case argm_ObjectSet:
            {
                if (!val->as_objectset()) {
#ifdef  DEBUG_SEMANTIC                
                    debug_warning("Should be error argument type ambiguous: ObjectSet ");
#else
                    val->scope()->referenceerror_throw("Argument type ambiguous. ObjectSet expected : ", name());
#endif   
                    return;
                }
                break;
            }
            case argm_WillbeDef:
            {
                break;
            }
            default:
            {
#ifdef  DEBUG_SEMANTIC                
                debug_warning("Should be error argument type dummy insert ");
#endif                                 
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
        if (unspecified_) {
            if ((unspecified_->as_typeassigment()) && (unspecified_->as_typeassigment()->type()))
                return unspecified_->resolve();
            if ((unspecified_->as_valueassigment()) && (unspecified_->as_valueassigment()->value()))
                return unspecified_->resolve();
            if ((unspecified_->as_valuesetassigment()) && (unspecified_->as_valuesetassigment()->valueset()))
                return unspecified_->resolve();
            if ((unspecified_->as_classassigment()) && (unspecified_->as_classassigment()->_class()))
                return unspecified_->resolve();
            if ((unspecified_->as_objectassigment()) && (unspecified_->as_objectassigment()->object()))
                return unspecified_->resolve();
            if ((unspecified_->as_objectsetassigment()) && (unspecified_->as_objectsetassigment()->objectset()))
                return unspecified_->resolve();
        }
    }


    /////////////////////////////////////////////////////////////////////////   
    // argument_entity
    /////////////////////////////////////////////////////////////////////////  

    uargument_entity::uargument_entity(basic_entity_ptr scope, setting_atom_ptr st)
    : basic_entity(scope, "", et_UArgument), setting_(st) {
    }

    uargument_entity::uargument_entity(basic_entity_ptr scope, type_atom_ptr gvnr)
    : basic_entity(scope, "", et_UArgument), governor_(gvnr) {
    }

    uargument_entity::uargument_entity(basic_entity_ptr scope, class_atom_ptr gvnr)
    : basic_entity(scope, "", et_UArgument), governor_(gvnr) {
    }

    uargument_entity::uargument_entity(basic_entity_ptr scope, basic_atom_ptr gvnr)
    : basic_entity(scope, "", et_UArgument), governor_(gvnr) {
    }

    bool uargument_entity::has_undef_governor() const {
        return ( governor_ && !((governor_->as_type()) || (governor_->as_class())));
    }

    void uargument_entity::governor(type_atom_ptr vl) {
        governor_ = vl;
    }

    void uargument_entity::governor(class_atom_ptr vl) {
        governor_ = vl;
    }

    void uargument_entity::governor(basic_atom_ptr vl) {
        governor_ = vl;
    }

    void uargument_entity::resolve(basic_atom_ptr holder) {
        if (has_governor())
            governor()->resolve_reff();
    }


    /////////////////////////////////////////////////////////////////////////   
    // basic_atom
    /////////////////////////////////////////////////////////////////////////   

    basic_atom::basic_atom(assignment_enum tp, basic_entity_ptr scp) :
    kind_(tp), scope_(scp), extention_(false), isdummy_(false), isdummysource_(false), yetresolved_(false) {
    };

    basic_atom::basic_atom(assignment_enum tp, basic_entity_ptr scp, const std::string& reff) :
    kind_(tp), scope_(scp), extention_(false), isdummy_(false), isdummysource_(false), yetresolved_(false) {
        reff_ = basic_entity_ptr(new expectdef_entity(scp, reff));
    }

    basic_atom::basic_atom(basic_entity_ptr scp, const std::string& reff) :
    kind_(at_Nodef), scope_(scp), extention_(false), isdummy_(false), isdummysource_(false), yetresolved_(false) {
        reff_ = basic_entity_ptr(new expectdef_entity(scp, reff));
    }

    bool basic_atom::isrefferrence() const {
        return false;
    }

    bool basic_atom::has_rootargumented() const {
        return ((scope()) &&(scope()->as_assigment())) ? scope()->as_assigment()->has_rootarguments() : false;
    }

    module_entity_ptr basic_atom::external() const {
        if ((scope()) && (reff()) /*&& (!reff()->as_expectdef()) */ && (scope()->moduleref()) && (reff()->moduleref()))
            return ((scope()->moduleref()) != (reff()->moduleref())) ? reff()->moduleref() : module_entity_ptr();
        return module_entity_ptr();
    }

    std::string basic_atom::externalpreff() const {
        if (external())
            return external()->name() + "::";
        return "";
    }

    basic_entity_ptr basic_atom::reff() const {
        return reff_;
    }

    void basic_atom::reff_resolver(basic_atom_ptr vl) {
        reff_resolver_ = basic_atom_wptr(vl);
    }

    bool basic_atom::extesibility_implied() const {
        return (scope() && (scope()->moduleref())
                && (scope()->moduleref()->extesibility_implied()));
    }

    basic_atom_ptr basic_atom::root() {
        if (!reff())
            return self();
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
        return basic_atom_ptr();
    }

    bool basic_atom::isdummyAS() const {
        return ((isdummysource_ || isdummy_) && (scope()) && (scope()->as_classassigment()) &&
                (scope()->as_classassigment()->_class()) && (scope()->as_classassigment()->_class()->builtin() == cl_ABSTRACT_SYNTAX));
    }

    bool basic_atom::isembeded() const {
        return static_cast<bool> (embeded_assignment_);
    }

    bool basic_atom::rooted() {
        return ((root()) && (root() != self()));
    }

    assignment_entity_ptr basic_atom::embeded_assignment() const {
        return embeded_assignment_;
    }

    void basic_atom::embeded_assignment(assignment_entity_ptr vl) {
        embeded_assignment_ = vl;
    }

    basic_entity_vector& basic_atom::childs() {
        return embeded_assignment_ ? embeded_assignment_->childs() : nullchilds_;
    }

    type_atom_ptr basic_atom::as_type() {
        return kind_ == at_Type ? boost::static_pointer_cast<type_atom> (self()) : type_atom_ptr();
    }

    value_atom_ptr basic_atom::as_value() {
        return kind_ == at_Value ? boost::static_pointer_cast<value_atom> (self()) : value_atom_ptr();
    }

    valueset_atom_ptr basic_atom::as_valueset() {
        return kind_ == at_ValueSet ? boost::static_pointer_cast<valueset_atom> (self()) : valueset_atom_ptr();
    }

    class_atom_ptr basic_atom::as_class() {
        return kind_ == at_Class ? boost::static_pointer_cast<class_atom> (self()) : class_atom_ptr();
    }

    object_atom_ptr basic_atom::as_object() {
        return kind_ == at_Object ? boost::static_pointer_cast<object_atom> (self()) : object_atom_ptr();
    }

    objectset_atom_ptr basic_atom::as_objectset() {
        return kind_ == at_ObjectSet ? boost::static_pointer_cast<objectset_atom> (self()) : objectset_atom_ptr();
    }

    setting_atom_ptr basic_atom::as_setting() {
        return kind_ == at_Setting ? boost::static_pointer_cast<setting_atom> (self()) : setting_atom_ptr();
    }

    syntax_atom_ptr basic_atom::as_syntax() {
        return kind_ == at_Syntax ? boost::static_pointer_cast<syntax_atom> (self()) : syntax_atom_ptr();
    }

    fieldsetting_atom_ptr basic_atom::as_fieldsetting() {
        return kind_ == at_FieldSetting ? boost::static_pointer_cast<fieldsetting_atom> (self()) : fieldsetting_atom_ptr();
    }

    constraint_atom_ptr basic_atom::as_constraint() {
        return kind_ == at_Constraint ? boost::static_pointer_cast<constraint_atom> (self()) : constraint_atom_ptr();
    }

    constraints_atom_ptr basic_atom::as_constraints() {
        return kind_ == at_Constraints ? boost::static_pointer_cast<constraints_atom> (self()) : constraints_atom_ptr();
    }

    effective_tabconstraint_ptr basic_atom::as_effective_tab() {
        return kind_ == at_EffectiveTabConstraint ?
                boost::static_pointer_cast<effective_tabconstraint> (self()) : effective_tabconstraint_ptr();
    }

    assignment_entity_ptr basic_atom::refference_to() {
        if ((reff()) && (reff()->as_assigment()))
            return reff()->as_assigment()->refference_to();
        return assignment_entity_ptr();
    }

    entity_enum basic_atom::check_reff(basic_atom_ptr holder, search_marker sch) {
        if ((scope()) && (reff()) && (reff()->as_expectdef())) {
            basic_entity_ptr source = holder ?
                    (holder->reff() ? holder->reff() : holder->scope()) : scope();
            if (source) {
                basic_entity_ptr fnd = source->find(reff(), holder ? local_search : sch);
                if (fnd) {
                    if ((fnd->kind() != et_Nodef) && (fnd->kind() != et_NodefT) && (fnd->kind() != et_NodefV) &&
                            (fnd->kind() != et_NodefS) && (fnd->kind() != et_NodefE)) {
                        return fnd->kind();
                    }
                }
            }
        }
        if (reff()->as_assigment())
            return reff()->as_assigment()->kind();
        if (as_type())
            return et_Type;
        else if (as_value())
            return et_Value;
        else if (as_valueset())
            return et_ValueSet;
        else if (as_class())
            return et_Class;
        else if (as_object())
            return et_Object;
        else if (as_objectset())
            return et_ObjectSet;
        return et_Nodef;
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
#ifdef  DEBUG_SEMANTIC                
                            debug_warning("Should be error : " + expectedname() + " ref to typeassigment");
#else
                            scope()->referenceerror_throw("Refference to Type : ", expectedname());
#endif                                                          
                    } else if (fnd->as_valueassigment()) {
                        if (!as_value())
#ifdef  DEBUG_SEMANTIC                
                            debug_warning("Should be error : " + expectedname() + " ref to valueassigment");
#else
                            scope()->referenceerror_throw("Refference to Value : ", expectedname());
#endif                                                          
                    } else if (fnd->as_valuesetassigment()) {
                        if (!as_valueset())
#ifdef  DEBUG_SEMANTIC                
                            debug_warning("Should be error : " + expectedname() + " ref to valuesetassigment");
#else
                            scope()->referenceerror_throw("Refference to ValueSet : ", expectedname());
#endif                                                         
                    } else if (fnd->as_classassigment()) {
                        if (!as_class())
#ifdef  DEBUG_SEMANTIC                
                            debug_warning("Should be error : " + expectedname() + " ref to classassigment");
#else
                            scope()->referenceerror_throw("Refference to Class : ", expectedname());
#endif                                                            
                    } else if (fnd->as_objectassigment()) {
                        if (!as_object())
#ifdef  DEBUG_SEMANTIC                
                            debug_warning("Should be error : " + expectedname() + " ref to objectassigment");
#else
                            scope()->referenceerror_throw("Refference to Object: ", expectedname());
#endif                                                           
                    } else if (fnd->as_objectsetassigment()) {
                        if (!as_objectset())
#ifdef  DEBUG_SEMANTIC                
                            debug_warning("Should be error : " + expectedname() + " ref to objectsetassigment");
#else
                            scope()->referenceerror_throw("Refference to ObjectSet: ", expectedname());
#endif                                                                     
                    } else if (fnd->as_argument()) {
#ifdef  DEBUG_SEMANTIC                        
                        //debug_warning("Here is argument parser: '" + expectedname() + "'");
#endif                          
                        fnd->as_argument()->insert_dummyrefference(self());
                        return;
                    } else {
#ifdef  DEBUG_SEMANTIC                
                        debug_warning("Should be error : refference '" + expectedname() + "' undefined assigment");
#else
                        scope()->referenceerror_throw("Refference to Undefined : ", expectedname());
#endif                                               
                        return;
                    }

                    reff(fnd);
                } else {
                    if (holder) {
                        resolve_reff(basic_atom_ptr(), sch);
                        return;
                    } else {
#ifdef  DEBUG_SEMANTIC                
                        debug_warning("Should be error : refference : " + expectedname() + "  source : " +
                                source->name() + "  scope : " + scope()->name());
#else
                        scope()->referenceerror_throw("Refference don't find", expectedname());
#endif                         
                    }
                }
            } else {
#ifdef  DEBUG_SEMANTIC                
                debug_warning("Should be error : refference : " + expectedname() + "  not found : no holder");
#else
                throw semantics::error(expectedname() + "Try find in null scope");
#endif                  
            }
        }
    }

    void basic_atom::resolve(basic_atom_ptr holder) {
    }

    void basic_atom::resolve_substitute() {
    }

    assignment_entity_ptr basic_atom::find_component(const std::string& nmf) {
        assignment_entity_ptr rslt;
        if (embeded_assignment_) {
            rslt = embeded_assignment_;
        } else
            if ((reff()) && (reff()->as_assigment())) {
            rslt = reff()->as_assigment();
        } else if ((scope()) && (scope()->as_assigment())
                && (scope()->as_assigment()->atom())
                && (scope()->as_assigment()->atom().get() == this))
            rslt = scope()->as_assigment();
        if (rslt)
            rslt = rslt->refference_to();
        if (rslt)
            return rslt->find_component(nmf);
        return assignment_entity_ptr();
    }

    objectassignment_entity_vct basic_atom::calculate_objects(basic_atom_ptr atm, basic_atom_ptr fld, bool strict) {
        objectassignment_entity_vct rslt;
        if (atm && fld) {
            objectassignment_entity_vct vct;
            if (atm->as_object())
                vct = atm->as_object()->get_objects(strict);
            if (atm->as_objectset())
                vct = atm->as_objectset()->get_objects(strict);
            for (objectassignment_entity_vct::iterator it = vct.begin(); it != vct.end(); ++it) {
                if ((*it) && ((*it)->object())) {
                    assignment_entity_ptr tmp = (*it)->object()->find_component(fld->expectedname());
                    if (tmp) {
                        objectassignment_entity_vct subrslt;
                        if ((tmp->as_objectsetassigment()) && (tmp->as_objectsetassigment()->objectset()))
                            subrslt = tmp->as_objectsetassigment()->objectset()->get_objects(strict);
                        if ((tmp->as_objectassigment()) && (tmp->as_objectassigment()->object()))
                            subrslt = tmp->as_objectassigment()->object()->get_objects(strict);
                        if (!subrslt.empty())
                            rslt.insert(rslt.end(), subrslt.begin(), subrslt.end());
                    }
                }
            }
        }
        return rslt;
    }


    /////////////////////////////////////////////////////////////////////////   
    // SETTING
    /////////////////////////////////////////////////////////////////////////     
    // setting_atom
    /////////////////////////////////////////////////////////////////////////   

    type_atom_ptr setting_atom::type() {
        return typeassignment_ ? typeassignment_->type() : type_atom_ptr();
    }

    class_atom_ptr setting_atom::_class() {
        return classassignment_ ? classassignment_->_class() : class_atom_ptr();
    }

    /*object_atom_ptr setting_atom::object() {
        return objectassignment_ ? objectassignment_->object() : object_atom_ptr();
    }*/

    /////////////////////////////////////////////////////////////////////////   
    // ASSIGNMENT
    /////////////////////////////////////////////////////////////////////////         
    // assignment_entity
    /////////////////////////////////////////////////////////////////////////  

    bool assignment_entity::has_rootarguments() const {
        if (has_arguments()) {
            if ((shadow_for()) && (shadow_for()->as_assigment()))
                return shadow_for()->as_assigment()->has_rootarguments();
            return true;
        }
        if (scope()) {
            assignment_entity_ptr scp = scope()->as_assigment();
            if (scp) {
                return scp->has_rootarguments();
            }
        }
        return false;
    }

    bool assignment_entity::parameterized() const {
        basic_atom_ptr rslt = atom();
        return rslt ? (rslt->parameterized()) : false;
    }

    assignment_entity_ptr assignment_entity::find_component(const std::string& nmf) {
        std::string nm = nmf;
        std::string search = subidentifier(nm);
        assignment_entity_ptr slf = refference_to();
        for (basic_entity_vector::iterator it = slf->childs().begin(); it != slf->childs().end(); ++it) {
            if ((*it)->name() == search) {
                if ((*it)->as_assigment()) {
                    if (nm.empty()) {
                        return (*it)->as_assigment();
                    } else {
                        assignment_entity_ptr ref = (*it)->as_assigment()->refference_to();
                        if (ref && (ref->as_assigment())) {
                            ref->as_assigment()->resolve();
                            return ref->as_assigment()->find_component(nm);
                        }
                    }
                } else
                    return assignment_entity_ptr();
            }
        }
        return assignment_entity_ptr();
    }

    basic_entity_ptr assignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        for (argument_entity_vct::const_iterator it = arguments_.begin(); it != arguments_.end(); ++it)
            if ((*it)->name() == nm)
                return (*it);
        return basic_entity_ptr();
    }

    void assignment_entity::resolve(basic_atom_ptr holder) {
        for (argument_entity_vct::const_iterator it = arguments_.begin(); it != arguments_.end(); ++it)
            if ((*it))
                (*it)->resolve();
    }

    void assignment_entity::preresolve() {
        for (argument_entity_vct::const_iterator it = arguments_.begin(); it != arguments_.end(); ++it) {
            if ((*it)->has_undef_governor()) {
                if (!(*it)->governor()->reff())
                    scope()->referenceerror_throw(/*scope()->name()*/);
                basic_entity_ptr fnd = scope()->find((*it)->governor()->reff());
                if (fnd) {
                    if (fnd->kind() == et_Type) {
                        (*it)->governor(type_atom_ptr(new type_atom((*it)->scope(), (*it)->governor()->expectedname(), t_Reference)));
                    } else if (fnd->kind() == et_Class) {
                        (*it)->governor(class_atom_ptr(new class_atom((*it)->scope(), (*it)->governor()->expectedname(), cl_Reference)));
                    } else
                        scope()->referenceerror_throw(/*(*it)->governor()->expectedname()*/);
                } else
                    scope()->referenceerror_throw(/*scope()->name()*/);
            }
        }
    }

    void assignment_entity::resolve_all(basic_atom_ptr holder) {
        preresolve();
        if (as_objectassigment())
            as_objectassigment()->apply_fields();
        resolve(holder);
        after_resolve();
    }

    assignment_entity_ptr assignment_entity::refference_to() {
        if (as_typeassigment()) {
            if ((as_typeassigment()->type())
                    && (as_typeassigment()->type()->reff())
                    && (as_typeassigment()->type()->reff()->as_assigment())) {
                return as_typeassigment()->type()->reff()->as_assigment()->refference_to();
            }
        } else if (as_valueassigment()) {
            if ((as_valueassigment()->value())
                    && (as_valueassigment()->value()->reff())
                    && (as_valueassigment()->value()->reff()->as_assigment())) {
                return as_valueassigment()->value()->reff()->as_assigment()->refference_to();
            }
        } else if (as_valuesetassigment()) {
            if ((as_valuesetassigment()->valueset())
                    && (as_valuesetassigment()->valueset()->reff())
                    && (as_valuesetassigment()->valueset()->reff()->as_assigment())) {
                return as_valuesetassigment()->valueset()->reff()->as_assigment()->refference_to();
            }
        } else if (as_classassigment()) {
            if ((as_classassigment()->_class())
                    && (as_classassigment()->_class()->reff())
                    && (as_classassigment()->_class()->reff()->as_assigment())) {
                return as_classassigment()->_class()->reff()->as_assigment()->refference_to();
            }
        } else if (as_objectassigment()) {
            if ((as_objectassigment()->object())
                    && (as_objectassigment()->object()->reff())
                    && (as_objectassigment()->object()->reff()->as_assigment())) {
                return as_objectassigment()->object()->reff()->as_assigment()->refference_to();
            }
        } else if (as_objectsetassigment()) {
            if ((as_objectsetassigment()->objectset())
                    && (as_objectsetassigment()->objectset()->reff())
                    && (as_objectsetassigment()->objectset()->reff()->as_assigment())) {
                return as_objectsetassigment()->objectset()->reff()->as_assigment()->refference_to();
            }
        }
        if ((as_assigment()) && (as_assigment()->atom()) && (as_assigment()->atom()->embeded_assignment())) {
            return as_assigment()->atom()->embeded_assignment()->refference_to();
        }
        return as_assigment();
    }

    void assignment_entity::apply_arguments(const setting_atom_vct& vl, basic_entity_ptr scp) {
        if ((vl.empty()) || (vl.size() != arguments_.size()))
            throw semantics::error("");
        argument_entity_vct::const_iterator it2 = arguments_.begin();
        for (setting_atom_vct::const_iterator it1 = vl.begin(); it1 != vl.end(); ++it1) {

            if (!(*it1) || !(*it2))
                throw semantics::error("");
            (*it2)->apply_argument(*it1, scp);
            ++it2;
        }
    }

    void assignment_entity::resolve_arguments() {
        for (argument_entity_vct::const_iterator it = arguments_.begin(); it != arguments_.end(); ++it) {
            if ((*it) && (*it)->unspecified()) {
                (

                        *it)->unspecified()->preresolve();
                (*it)->unspecified()->resolve();
            }
        }
    }

    void assignment_entity::assign_from(assignment_entity_ptr from) {
        if (from) {

            childs() = from->childs();
            reff_shadow(from);
        }
    }

    template<>
    typeassignment_entity_ptr assignment_entity::as_baseassignment() {

        return as_typeassigment();
    }

    template<>
    valueassignment_entity_ptr assignment_entity::as_baseassignment() {

        return as_valueassigment();
    }

    template<>
    valuesetassignment_entity_ptr assignment_entity::as_baseassignment() {

        return as_valuesetassigment();
    }

    template<>
    classassignment_entity_ptr assignment_entity::as_baseassignment() {

        return as_classassigment();
    }

    template<>
    objectassignment_entity_ptr assignment_entity::as_baseassignment() {

        return as_objectassigment();
    }

    template<>
    objectsetassignment_entity_ptr assignment_entity::as_baseassignment() {

        return as_objectsetassigment();
    }

    template<>
    typeassignment_entity_ptr assignment_entity::clone(basic_entity_ptr scp, bool shdw) {
        if (!as_typeassigment())
            return typeassignment_entity_ptr();
        typeassignment_entity_ptr tmp = x680::semantics::compile_typeassignment(scp ? scp : scope(), as_typeassigment()->synctas());
        if (tmp && shdw)
            tmp->shadow(true);

        return tmp;
    }

    template<>
    namedtypeassignment_entity_ptr assignment_entity::clone(basic_entity_ptr scp, bool shdw) {
        if (!as_typeassigment())
            return namedtypeassignment_entity_ptr();
        if (!(as_typeassigment()->as_named()))
            return namedtypeassignment_entity_ptr();
        typeassignment_entity_ptr tmp = x680::semantics::compile_namedtype(scp ? scp : scope(), as_typeassigment()->synctas());
        if (tmp && shdw)
            tmp->shadow(true);

        return tmp->as_named();
    }

    template<>
    valueassignment_entity_ptr assignment_entity::clone(basic_entity_ptr scp, bool shdw) {
        if (!as_valueassigment())
            return valueassignment_entity_ptr();
        valueassignment_entity_ptr tmp = x680::semantics::compile_valueassignment(scp ? scp : scope(), as_valueassigment()->synctas());
        if (tmp && shdw)
            tmp->shadow(true);

        return tmp;
    }

    template<>
    valuesetassignment_entity_ptr assignment_entity::clone(basic_entity_ptr scp, bool shdw) {
        if (!as_valuesetassigment())
            return valuesetassignment_entity_ptr();
        valuesetassignment_entity_ptr tmp = x680::semantics::compile_valuesetassignment(scp ? scp : scope(), as_valuesetassigment()->synctas());
        if (tmp && shdw)
            tmp->shadow(true);

        return tmp;
    }

    template<>
    classassignment_entity_ptr assignment_entity::clone(basic_entity_ptr scp, bool shdw) {
        if (!as_classassigment())
            return classassignment_entity_ptr();
        classassignment_entity_ptr tmp = x680::semantics::compile_classassignment(scp ? scp : scope(), as_classassigment()->synctas());
        if (tmp && shdw)
            tmp->shadow(true);

        return tmp;
    }

    template<>
    objectassignment_entity_ptr assignment_entity::clone(basic_entity_ptr scp, bool shdw) {
        if (!as_objectassigment())
            return objectassignment_entity_ptr();
        objectassignment_entity_ptr tmp = x680::semantics::compile_objectassignment(scp ? scp : scope(), as_objectassigment()->synctas());
        if (tmp && shdw)
            tmp->shadow(true);

        return tmp;
    }

    template<>
    objectsetassignment_entity_ptr assignment_entity::clone(basic_entity_ptr scp, bool shdw) {
        if (!as_objectsetassigment())
            return objectsetassignment_entity_ptr();
        objectsetassignment_entity_ptr tmp = x680::semantics::compile_objectsetassignment(scp ? scp : scope(), as_objectsetassigment()->synctas());
        if (tmp && shdw)
            tmp->shadow(true);

        return tmp;
    }



    /////////////////////////////////////////////////////////////////////////   
    // BIG
    /////////////////////////////////////////////////////////////////////////   
    // bigassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    bigassignment_entity::bigassignment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg) :
    assignment_entity(scope, nm, et_NodefT), big_(bg) {
    };

    x680::syntactic::type_assignment bigassignment_entity::synctasT() const {

        return synctas_.typea ? (*(synctas_.typea)) : x680::syntactic::type_assignment();
    }

    x680::syntactic::class_assignment bigassignment_entity::synctasC() const {

        return synctas_.classa ? (*(synctas_.classa)) : x680::syntactic::class_assignment();
    }

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

    x680::syntactic::value_assignment voassignment_entity::synctasT() const {

        return synctas_.valuea ? (*(synctas_.valuea)) : x680::syntactic::value_assignment();
    }

    x680::syntactic::object_assignment voassignment_entity::synctasC() const {

        return synctas_.objecta ? (*(synctas_.objecta)) : x680::syntactic::object_assignment();
    }

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

    x680::syntactic::valueset_assignment soassignment_entity::synctasT() const {

        return synctas_.valueseta ? (*(synctas_.valueseta)) : x680::syntactic::valueset_assignment();
    }

    x680::syntactic::objectset_assignment soassignment_entity::synctasC() const {

        return synctas_.objectseta ? (*(synctas_.objectseta)) : x680::syntactic::objectset_assignment();
    }

    /////////

    basic_entity_ptr soassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        if (scope())
            return scope()->find_by_name(nm, sch);
        return basic_entity_ptr();
    }

}
