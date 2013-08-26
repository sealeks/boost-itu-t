//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>


namespace x680 {

    /////////////////////////////////////////////////////////////////////////   
    // basic_entity
    ///////////////////////////////////////////////////////////////////////// 

    basic_entity_ptr basic_entity::find(const std::string& nm) {
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

    global_entity* basic_entity::as_global() {
        return kind_ == et_Global ? dynamic_cast<global_entity*> (this) : 0;
    }

    module_entity* basic_entity::as_module() {
        return kind_ == et_Module ? dynamic_cast<module_entity*> (this) : 0;
    }

    expectdef_entity* basic_entity::as_expectdef() {
        return kind_ == et_Nodef ? dynamic_cast<expectdef_entity*> (this) : 0;
    }

    import_entity* basic_entity::as_import() {
        return kind_ == et_Import ? dynamic_cast<import_entity*> (this) : 0;
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

    void basic_entity::resolve_assigments(basic_entity* elm) {
        for (basic_entity_vector::iterator it = elm->childs().begin(); it != elm->childs().end(); ++it) {
            *it = resolve_assigment(*it);
        }
    }

    basic_entity_ptr basic_entity::resolve_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        if (elm->name().empty())
            return elm;
        switch (elm->kind()) {
            case et_Nodef:
            {
                return resolve_nodef_assigment(elm, start);
                break;
            }
            case et_Type:
            {
                return resolve_type_assigment(elm, start);
                break;
            }
            case et_Value:
            {
                return resolve_value_assigment(elm, start);
                break;
            }
            case et_Class:
            {
                return resolve_class_assigment(elm, start);
                break;
            }
        }
        return elm;
    }

    basic_entity_ptr basic_entity::resolve_nodef_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        /*if (!start)
            start = elm;
        else
            check_resolve_ciclic(elm, start);*/
        bigassigment_entity* tmp = elm->as_bigassigment();
        if (tmp && (tmp->big()) && (tmp->big()->reff())) {
            basic_entity_ptr fnd = elm->find(tmp->big()->reff()->name());
            if (fnd) {
                if (fnd->kind() == et_Type) {
                    basic_entity_ptr rslt(new typeassigment_entity(elm->scope(), tmp->name(), type_entity_ptr(new type_entity(tmp->big()->reff()->name(), t_Reference))));
                    return resolve_type_assigment(rslt);
                }
                if (fnd->kind() == et_Class) {
                    basic_entity_ptr rslt(new classassigment_entity(elm->scope(), tmp->name(), class_entity_ptr(new class_entity(tmp->big()->reff()->name(), cl_Reference))));
                    return resolve_class_assigment(rslt);
                }
            }
        }
        return elm;
    }

    basic_entity_ptr basic_entity::resolve_type_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        /* if (!start)
             start = elm;
         else
             check_resolve_ciclic(elm, start);*/
        typeassigment_entity* tmp = elm->as_typeassigment();
        if (tmp) {
            if ((tmp->type()) && (tmp->type()->reff()) && (tmp->type()->reff()->as_expectdef())) {
                basic_entity_ptr fnd = elm->find(tmp->type()->reff()->name());
                if (fnd) {
                    tmp->type()->reff(fnd);
                }
            }
        }
        return elm;
    }

    basic_entity_ptr basic_entity::resolve_value_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        /* if (!start)
             start = elm;
         else
             check_resolve_ciclic(elm, start);*/
        valueassigment_entity* tmp = elm->as_valueassigment();
        if (tmp) {
            if ((tmp->type()) && (tmp->type()->reff()) && (tmp->type()->reff()->as_expectdef())) {
                basic_entity_ptr fnd = elm->find(tmp->type()->reff()->name());
                if (fnd) {
                    tmp->type()->reff(fnd);
                }
            }
        }
        return elm;
    }

    basic_entity_ptr basic_entity::resolve_class_assigment(basic_entity_ptr elm, basic_entity_ptr start) {
        /* if (!start)
             start = elm;
         else
             check_resolve_ciclic(elm, start);*/
        classassigment_entity* tmp = elm->as_classassigment();
        if (tmp) {
            if ((tmp->_class()) && (tmp->_class()->reff()) && (tmp->_class()->reff()->as_expectdef())) {
                basic_entity_ptr fnd = elm->find(tmp->_class()->reff()->name());
                if (fnd) {
                    tmp->_class()->reff(fnd);
                }
            }
        }
        return elm;
    }

    /////////////////////////////////////////////////////////////////////////   
    // global_entity
    /////////////////////////////////////////////////////////////////////////  

    global_entity::global_entity()
    : basic_entity(et_Global) {
    }

    void global_entity::resolve() {
        resolve_child();
    }

    basic_entity_ptr global_entity::find(const std::string& nm) {
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if (nm == (*it)->name())
                return *it;
        return basic_entity_ptr();
    }

    std::ostream& operator<<(std::ostream& stream, global_entity& self) {
        stream << "GLOBAL SCOPE:" << "\n";
        for (basic_entity_vector::iterator it = self.childs().begin(); it != self.childs().end(); ++it) {
            if ((*it)->as_module())
                stream << *((*it)->as_module());
        }
        return stream;
    }



    /////////////////////////////////////////////////////////////////////////
    // import_entity
    /////////////////////////////////////////////////////////////////////////

    import_entity::import_entity(const std::string& nm)
    : basic_entity(nm, et_Import) {
    }

    void import_entity::resolve() {
        /*if (scope()) {
            for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                basic_entity_ptr fnd = find((*it)->name());
                if (fnd) {
         *it = fnd;
                }
            }
        }*/
    }

    std::ostream& operator<<(std::ostream& stream, import_entity& self) {
        if (self.scope())
            stream << "      from module: " << self.name();
        else
            stream << "      from module: " << self.name() << "(?)";
        stream << "\n      symbol: ";
        for (import_vector::iterator it = self.import().begin(); it != self.import().end(); ++it) {
            stream << *it << ", ";
        }
        stream << "\n";
        return stream;
    }



    /////////////////////////////////////////////////////////////////////////   
    // module_entity
    /////////////////////////////////////////////////////////////////////////   

    module_entity::module_entity(basic_entity_ptr scope, const std::string& nm, const std::string& fl, bool allexp)
    : basic_entity(scope, nm, et_Module), file_(fl), allexport_(allexp) {
    }

    basic_entity_ptr module_entity::find(const std::string& nm) {
        for (basic_entity_vector::iterator it = imports().begin(); it != imports().end(); ++it) {
            import_entity* importmod = (*it)->as_import();
            if (importmod->scope() && (!importmod->scope()->childs().empty())) {
                basic_entity_ptr fnd = importmod->scope()->childs().front()->find(nm);
                if (fnd)
                    return fnd;
            }
        }
    }

    void module_entity::resolve() {
        resolve_export();
        resolve_externalmodule();
        resolve_assigments(this);
    }

    void module_entity::resolve_export() {
        if (allexport()) {
            for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                exports().push_back((*it)->name());
            }
        } else {
            for (export_vector::iterator it = exports().begin(); it != exports().end(); ++it) {
                /*    basic_entity_ptr fnd = find(*it);
                    if (fnd) {
                        //*it = fnd;
                    } else {
                        throw semantics::error("Not find exported symbol: " + *it +
                                " in module: " + name() + " in file: " + file());
                    }*/
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

    std::ostream& operator<<(std::ostream& stream, module_entity& self) {
        stream << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        stream << "module: " << self.name() << "\nfile:" << self.file() << "\n";
        stream << "----------------------------------------------------------\n";
        if (self.allexport())
            stream << "      export ALL\n ";

        stream << "      export: ";
        for (export_vector::iterator it = self.exports().begin(); it != self.exports().end(); ++it) {
            stream << *it << ", ";
        }

        stream << "\n----------------------------------------------------------\n";
        stream << "      IMPORTS: ";
        for (basic_entity_vector::iterator it = self.imports().begin(); it != self.imports().end(); ++it) {
            stream << "\n.............................................................................................\n";
            stream << "      import: \n";
            if ((*it)->as_import())
                stream << *((*it)->as_import());
        }
        stream << "     \n";
        for (basic_entity_vector::iterator it = self.childs().begin(); it != self.childs().end(); ++it) {
            if ((*it)->as_bigassigment()) {
                stream << *((*it)->as_bigassigment());
                continue;
            }
            if ((*it)->as_littleassigment()) {
                stream << *((*it)->as_littleassigment());
                continue;
            }
            if ((*it)->as_typeassigment()) {
                stream << *((*it)->as_typeassigment());
                continue;
            }
            if ((*it)->as_valueassigment()) {
                stream << *((*it)->as_valueassigment());
                continue;
            }
            if ((*it)->as_classassigment()) {
                stream << *((*it)->as_classassigment());
                continue;
            }
        }
        return stream;
    }



    /////////////////////////////////////////////////////////////////////////   
    // expectdef_entity
    /////////////////////////////////////////////////////////////////////////

    expectdef_entity::expectdef_entity(const std::string& nm)
    : basic_entity(nm, et_Nodef) {
    }

    std::ostream& operator<<(std::ostream& stream, expectdef_entity& self) {
        stream << self.name() << "(?)";
        return stream;
    }

    /////////////////////////////////////////////////////////////////////////   
    // defined_entity
    /////////////////////////////////////////////////////////////////////////   

    defined_entity::defined_entity() {
    };

    defined_entity::defined_entity(const std::string& reff) {
        reff_ = basic_entity_ptr(new expectdef_entity(reff));
    }

    std::ostream& operator<<(std::ostream& stream, defined_entity& self) {
        stream << "\n        ";
        /*     switch (self.kind()) {
           case et_Type:
           {
               return stream << *(self.as_type());
               break;
           }
           case et_Value:
           {
               return stream << *(self.as_value());
               break;
           }
           case et_ValueSet:
           {
               stream << "VS: ";
               break;
           }
           case et_Class:
           {
               stream << "OC: ";
               break;
           }
           case et_Object:
           {
               stream << "OO: ";
               break;
           }
           case et_ObjectSet:
           {
               stream << "OS: ";
               break;
           }
           default:
           {
               stream << "ND:";
           }
       }
 if (self.as_expectdef())
           stream << self.name() << "(?)";
       else
           stream << self.name();
       if (self.reff() && (self.kind() == et_Nodef))
           stream << " reff to " << self.reff()->name();*/
        return stream;
    }


    /////////////////////////////////////////////////////////////////////////   
    // type_entity
    /////////////////////////////////////////////////////////////////////////   

    type_entity::type_entity(defined_type tp)
    : defined_entity(), builtin_(tp) {
    }

    type_entity::type_entity(const std::string& reff, defined_type tp)
    : defined_entity(reff), builtin_(tp) {
    }

    //   basic_entity_ptr type_entity::find(const std::string& nm) {

    //            }

    std::ostream& operator<<(std::ostream& stream, type_entity& self) {
        if (self.builtin() == t_Reference) {
            if (self.reff()->as_expectdef())
                stream << "???" << self.reff()->name();
            else
                stream << self.reff()->name();
        } else {
            stream << self.builtin();
        }
        //stream << " id: " << self.name();
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

    /////////////////////////////////////////////////////////////////////////   
    // value_entity
    /////////////////////////////////////////////////////////////////////////       

    value_entity::value_entity(value_type tpv)
    : defined_entity(), valtype_(tpv) {
    }

    value_entity::value_entity(const std::string& reff, value_type tpv)
    : defined_entity(reff), valtype_(tpv) {
    }

    std::ostream& operator<<(std::ostream& stream, value_entity& self) {
        stream << "VL: " << (int) self.valtype();
        /*  if (self.tp())
            stream << " ||" << *self.tp() << " || ";
        else
            stream << " || ?  || ";
        if (self.builtin() == t_Reference) {
            if (self.reff()->as_expectdef())
                stream << " reff_to: [" << *(self.reff()->as_expectdef()) << "] ";
            else
                stream << " reff_to: [" << self.reff()->name() << "] ";
        }*/
        //stream << " id: " << self.name();
        return stream;
    }



    /*basic_entity_ptr check_resolve_ciclic(basic_entity_ptr elm) {
        if (elm && start && elm == start) {
            if (elm->scope() && elm->scope()->as_module()) {
                throw semantics::error("Ciclic refference : " + elm->name() +
                        " in module: " + elm->scope()->as_module()->name() +
                        " in file: " + elm->scope()->as_module()->file());
            } else {
                throw semantics::error("Ciclic refference : " + elm->name());
            }
        }
    }*/


    /////////////////////////////////////////////////////////////////////////   
    // type_entity
    /////////////////////////////////////////////////////////////////////////   

    class_entity::class_entity(definedclass_type tp)
    : defined_entity(), builtin_(tp) {
    }

    class_entity::class_entity(const std::string& reff, definedclass_type tp)
    : defined_entity(reff), builtin_(tp) {
    }


    /////////////////////////////////////////////////////////////////////////   
    // bigassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    bigassigment_entity::bigassigment_entity(basic_entity_ptr scope, const std::string& nm, defined_entity_ptr bg) :
    basic_entity(scope, nm, et_Nodef), big_(bg) {
    };

    basic_entity_ptr bigassigment_entity::find(const std::string& nm) {
        if (scope())
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (nm == (*it)->name()) {
                    *it = resolve_assigment(*it);
                    return *it;
                }
            }
        if (scope())
            return scope()->find(nm);
    }

    std::ostream& operator<<(std::ostream& stream, bigassigment_entity& self) {
        return stream << "(?B)" << self.name() << " :: = " << "\n";
    }


    /////////////////////////////////////////////////////////////////////////   
    // valueassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    littleassigment_entity::littleassigment_entity(basic_entity_ptr scope, const std::string& nm, defined_entity_ptr bg, defined_entity_ptr lt) :
    basic_entity(scope, nm, et_Type), big_(bg), little_(lt) {
    };

    basic_entity_ptr littleassigment_entity::find(const std::string& nm) {
        /* if (scope())
             for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                 if (nm == (*it)->name()) {
         *it = resolve_assigment(*it);
                     return *it;
                 }
             }*/
        if (scope())
            return scope()->find(nm);
    }

    std::ostream& operator<<(std::ostream& stream, littleassigment_entity& self) {
        return stream << "(?l)" << self.name() << " [" << "] :: = " << "\n";
    }


    /////////////////////////////////////////////////////////////////////////   
    // typeassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    typeassigment_entity::typeassigment_entity(basic_entity_ptr scope, const std::string& nm, type_entity_ptr tp) :
    basic_entity(scope, nm, et_Type), type_(tp) {
    };

    basic_entity_ptr typeassigment_entity::find(const std::string& nm) {
        if (scope())
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (nm == (*it)->name()) {
                    *it = resolve_assigment(*it);
                    return *it;
                }
            }
        if (scope())
            return scope()->find(nm);
    }

    std::ostream& operator<<(std::ostream& stream, typeassigment_entity& self) {
        return stream << "(T) " << self.name() << " :: = " << *(self.type()) << "\n";
    }


    /////////////////////////////////////////////////////////////////////////   
    // valueassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    valueassigment_entity::valueassigment_entity(basic_entity_ptr scope, const std::string& nm, type_entity_ptr tp, value_entity_ptr vl) :
    basic_entity(scope, nm, et_Value), type_(tp), value_(vl) {
    };

    basic_entity_ptr valueassigment_entity::find(const std::string& nm) {
        if (scope())
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (nm == (*it)->name()) {
                    *it = resolve_assigment(*it);
                    return *it;
                }
            }
        if (scope())
            return scope()->find(nm);
    }

    std::ostream& operator<<(std::ostream& stream, valueassigment_entity& self) {
        return stream << "(v) " << self.name() << " [" << *(self.type()) << "] :: = " << "\n";
    }


    /////////////////////////////////////////////////////////////////////////   
    // valuesetassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    valuesetassigment_entity::valuesetassigment_entity(basic_entity_ptr scope, const std::string& nm, type_entity_ptr tp, defined_entity_ptr vl) :
    basic_entity(scope, nm, et_ValueSet), type_(tp), valueset_(vl) {
    };

    basic_entity_ptr valuesetassigment_entity::find(const std::string& nm) {
        if (scope())
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (nm == (*it)->name()) {
                    *it = resolve_assigment(*it);
                    return *it;
                }
            }
        if (scope())
            return scope()->find(nm);
    }

    std::ostream& operator<<(std::ostream& stream, valuesetassigment_entity& self) {
        return stream << "(vS) " << self.name() << " [" << *(self.type()) << "] :: = " << "\n";
    }


    /////////////////////////////////////////////////////////////////////////   
    // classassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    classassigment_entity::classassigment_entity(basic_entity_ptr scope, const std::string& nm, class_entity_ptr tp) :
    basic_entity(scope, nm, et_Class), class_(tp) {
    };

    basic_entity_ptr classassigment_entity::find(const std::string& nm) {
        if (scope())
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it) {
                if (nm == (*it)->name()) {
                    *it = resolve_assigment(*it);
                    return *it;
                }
            }
        if (scope())
            return scope()->find(nm);
    }

    std::ostream& operator<<(std::ostream& stream, classassigment_entity& self) {
        return stream << "(C) " << self.name() << " :: = " << *(self._class()) << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, class_entity& self) {
        if (self.builtin() == cl_Reference) {
            if (self.reff()->as_expectdef())
                stream << "???" << self.reff()->name();
            else
                stream << self.reff()->name();
        } else {
            stream << self.builtin();
        }
        //stream << " id: " << self.name();
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


    namespace semantics {

        std::ostream& operator<<(std::ostream& stream, const error& self) {
            stream << "Semantic error: " << self.message() << "\n";
            return stream;
        }




        //  compile_fs          

        global_entity_ptr compile_fs(const std::string& path, const std::string& ext) {
            x680::syntactic::modules synxtasresult;
            int success = x680::syntactic::parse_fs(path, synxtasresult);

            global_entity_ptr global = global_entity_ptr(new global_entity());

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
                mdl->imports().push_back(compile_import(*it));
            }
        }




        //  compile_import         

        basic_entity_ptr compile_import(const x680::syntactic::import& imp) {
            import_entity_ptr rslt = import_entity_ptr(new import_entity(imp.name));
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
                    /*{
                        tp = et_Value;
                        x680::syntactic::value_assignment tmp = boost::get<x680::syntactic::value_assignment>(ent);
                        rslt = value_entity_ptr(new value_entity(scope,  tmp.value.type, tmp.identifier, tmp.value.type==v_identifier ? tmp.value.identifier : ""));
                        break;
                    }*/
                    /* case 2:
                     {
                         tp = et_ValueSet;
                         x680::syntactic::valueset_assignment tmp = boost::get<x680::syntactic::valueset_assignment>(ent);
                         rslt = littleassigment_entity_ptr ( new typeassigment_entity(scope, tmp.identifier,compile_test((tp))));
                         break;
                     }
                     case 3:
                     {
                         tp = et_Class;
                         x680::syntactic::class_assignment tmp = boost::get<x680::syntactic::class_assignment>(ent);
                         rslt = typeassigment_entity_ptr ( new typeassigment_entity(scope, tmp.identifier,compile_test((tp))));
                         break;
                     }
                     case 4:
                     {
                         tp = et_Object;
                         x680::syntactic::object_assignment tmp = boost::get<x680::syntactic::object_assignment>(ent);
                         rslt = typeassigment_entity_ptr ( new typeassigment_entity(scope, tmp.identifier,compile_test((tp))));
                         break;
                     }
                     case 5:
                     {
                         tp = et_ObjectSet;
                         x680::syntactic::objectset_assignment tmp = boost::get<x680::syntactic::objectset_assignment>(ent);
                         rslt =typeassigment_entity_ptr ( new typeassigment_entity(scope, tmp.identifier,compile_test((tp))));
                         break;
                     }
                     case 6:
                     case 7:
                     {
                         tp = et_Nodef;
                         x680::syntactic::unknown_tc_assignment tmp = boost::get<x680::syntactic::unknown_tc_assignment>(ent);
                         rslt = typeassigment_entity_ptr ( new typeassigment_entity(scope, tmp.identifier,compile_test((tp))));
                         break;
                     }

                     default:
                     {
                         rslt = typeassigment_entity_ptr ( new typeassigment_entity(scope, "NDF",compile_test((tp))));
                     }*/
            }
            return rslt;
        }

        typeassigment_entity_ptr compile_typeassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::type_assignment tmp = boost::get<x680::syntactic::type_assignment>(ent);
            return typeassigment_entity_ptr(new typeassigment_entity(scope, tmp.identifier, compile_type(tmp.type)));
        }

        type_entity_ptr compile_type(const x680::syntactic::type_element& ent) {
            return ent.reference.empty() ? type_entity_ptr(new type_entity(ent.builtin_t)) : type_entity_ptr(new type_entity(ent.reference, ent.builtin_t));
        }

        classassigment_entity_ptr compile_classassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::class_assignment tmp = boost::get<x680::syntactic::class_assignment>(ent);
            return classassigment_entity_ptr(new classassigment_entity(scope, tmp.identifier, compile_class(tmp.class_)));
        }

        class_entity_ptr compile_class(const x680::syntactic::class_element& ent) {
            return ent.reference.empty() ? class_entity_ptr(new class_entity(ent.tp)) : class_entity_ptr(new class_entity(ent.reference, ent.tp));
        }

        valueassigment_entity_ptr compile_valueassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::value_assignment tmp = boost::get<x680::syntactic::value_assignment>(ent);
            return valueassigment_entity_ptr(new valueassigment_entity(scope, tmp.identifier, compile_type(tmp.type), compile_value(tmp.value)));
        }

        value_entity_ptr compile_value(const x680::syntactic::value_element& ent) {
            return (ent.type != v_identifier) ? value_entity_ptr(new value_entity(ent.type)) : value_entity_ptr(new value_entity(ent.identifier, ent.type));
        }

        valuesetassigment_entity_ptr compile_valuesetassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::valueset_assignment tmp = boost::get<x680::syntactic::valueset_assignment>(ent);
            return valuesetassigment_entity_ptr(new valuesetassigment_entity(scope, tmp.identifier, compile_type(tmp.type), defined_entity_ptr()));
        }

        bigassigment_entity_ptr compile_bigassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::unknown_tc_assignment tmp = boost::get<x680::syntactic::unknown_tc_assignment>(ent);
            return bigassigment_entity_ptr(new bigassigment_entity(scope, tmp.identifier, compile_test(tmp.unknown_tc.reff)));
        }

        defined_entity_ptr compile_test(const std::string& rf) {
            return defined_entity_ptr(new defined_entity(rf));
        }




    }
}