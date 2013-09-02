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
    
    int basic_entity::level() const {
         int rslt=0;
         basic_entity_ptr scp= this->scope();
         while(scp){
             rslt++;
             scp = scp->scope();
         }
         return rslt;
    }    

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
                    basic_entity_ptr rslt(new typeassigment_entity(elm->scope(), tmp->name(), type_atom_ptr(new type_atom(elm->scope(), tmp->big()->reff()->name(), t_Reference))));
                    return resolve_type_assigment(rslt);
                }
                if (fnd->kind() == et_Class) {
                    basic_entity_ptr rslt(new classassigment_entity(elm->scope(), tmp->name(), class_atom_ptr(new class_atom(tmp->big()->reff()->name(), cl_Reference))));
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
            if ((tmp->value()) && (tmp->value()->reff()) && (tmp->value()->reff()->as_expectdef())) {
                basic_entity_ptr fnd = elm->find(tmp->value()->reff()->name());
                if (fnd) {
                    tmp->value()->reff(fnd);
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
    
    
    std::ostream& indent(std::ostream& stream, namedtypeassigment_atom* self){
        if (self){
            int inten =self->level();
            if (inten>0) inten--;
            while(inten){
                stream << "  ";
                inten--;
            }
        }
        return stream;
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

    std::ostream& operator<<(std::ostream& stream, global_entity* self) {
        stream << "GLOBAL SCOPE:" << "\n";
        for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
            if ((*it)->as_module())
                stream << (*it)->as_module();
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

    std::ostream& operator<<(std::ostream& stream, import_entity* self) {
        if (self->scope())
            stream << "      from module: " << self->name();
        else
            stream << "      from module: " << self->name() << "(?)";
        stream << "\n      symbol: ";
        for (import_vector::iterator it = self->import().begin(); it != self->import().end(); ++it) {
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

    std::ostream& operator<<(std::ostream& stream, module_entity* self) {
        stream << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        stream << "module: " << self->name() << "\nfile:" << self->file() << "\n";
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



    /////////////////////////////////////////////////////////////////////////   
    // expectdef_entity
    /////////////////////////////////////////////////////////////////////////

    expectdef_entity::expectdef_entity(const std::string& nm)
    : basic_entity(nm, et_Nodef) {
    }

    std::ostream& operator<<(std::ostream& stream, expectdef_entity* self) {
        stream << self->name() << "(?)";
        return stream;
    }

    /////////////////////////////////////////////////////////////////////////   
    // basic_atom
    /////////////////////////////////////////////////////////////////////////   

    basic_atom::basic_atom(basic_entity_ptr scp) : scope_(scp) {
    };

    basic_atom::basic_atom(const std::string& reff, basic_entity_ptr scp) : scope_(scp) {
        reff_ = basic_entity_ptr(new expectdef_entity(reff));
    }

    basic_atom* basic_atom::root() {
        if (!reff())
            return this;
        if (reff()->as_typeassigment())
            return reff()->as_typeassigment()->type()->root();
        if (reff()->as_valueassigment())
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

    std::ostream& operator<<(std::ostream& stream, basic_atom* self) {
        if (self->as_type())
            return stream << self->as_type()->builtin();
        if (self->as_value())
            return stream << self->as_value();
        return stream;
    }

    /////////////////////////////////////////////////////////////////////////   
    // predefined
    ///////////////////////////////////////////////////////////////////////// 

    std::ostream& operator<<(std::ostream& stream, predefined* self) {
        stream << "{$ ";
        for (valueassigment_entity_vct::const_iterator it = self->values().begin(); it != self->values().end(); ++it) {
            if (it != self->values().begin())
                stream << " ,";
            stream << (*it)->name();
            if ((*it)->value()) {
                stream << "( " << (*it)->value().get() << ")";
            };
        }
        return stream << " $}";
    }

    /////////////////////////////////////////////////////////////////////////   
    // tagged
    /////////////////////////////////////////////////////////////////////////     

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
                return stream << " ["   << self._class() << " "  << self.number().get()<< "] ";
            else
                return stream << " [ " << self.rule()  << self._class() << " "  << self.number().get() << "] ";
        }
        return stream;
    }

    /////////////////////////////////////////////////////////////////////////   
    // type_atom
    /////////////////////////////////////////////////////////////////////////   

    type_atom::type_atom(basic_entity_ptr scp, defined_type tp, tagged_ptr tg)
    : basic_atom(scp), builtin_(tp), tag_(tg) {
    }

    type_atom::type_atom(basic_entity_ptr scp, const std::string& reff, defined_type tp, tagged_ptr tg)
    : basic_atom(reff, scp), builtin_(tp), tag_(tg) {
    }

    type_atom::type_atom(basic_entity_ptr scp, defined_type tp, namedtypeassigment_atom_vct elms, tagged_ptr tg)
    : basic_atom(scp), builtin_(tp), tag_(tg), elemens_(elms) {
    }

    std::ostream& operator<<(std::ostream& stream, type_atom* self) {
        if (self->tag()) {
            stream << *(self->tag());
        }
        if (self->builtin() == t_Reference) {
            if (self->reff()->as_expectdef())
                stream << "??? *" << self->reff()->name();
            else {
                stream << " *" << self->reff()->name();
                if (self->rooted())
                    stream << "(@" << self->root() << ")";
            }
        } else {
            stream << self->builtin();
        }
        if (self->predefined())
            stream << self->predefined().get();
        switch (self->builtin()) {
            case t_SEQUENCE:
            case t_SEQUENCE_OF:
            case t_SET:
            case t_SET_OF:
            case t_CHOICE:;
            {
                stream << " {" << "\n";
                for (namedtypeassigment_atom_vct::const_iterator it = self->elemens().begin(); it != self->elemens().end(); ++it) {
                    stream << (*it).get() << "\n";
                }
                stream << "}" << "\n";
                break;
            }
            default:
            {
            };
        }
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
        if (self->reff()->as_expectdef())
            return stream << "??? *" << self->reff()->name();
        else {
            stream << " *" << self->reff()->name();
            if (self->rooted())
                stream << "(@" << self->root() << ")";
            return stream;
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

    /////////////////////////////////////////////////////////////////////////   
    // type_atom
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

    std::ostream& operator<<(std::ostream& stream, bigassigment_entity* self) {
        return stream << "(?B)" << self->name() << " :: = " << "\n";
    }


    /////////////////////////////////////////////////////////////////////////   
    // valueassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    littleassigment_entity::littleassigment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg, basic_atom_ptr lt) :
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

    std::ostream& operator<<(std::ostream& stream, littleassigment_entity* self) {
        return stream << "(?l)" << self->name() << " [" << "] :: = " << "\n";
    }


    /////////////////////////////////////////////////////////////////////////   
    // typeassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    typeassigment_entity::typeassigment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp) :
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

    namedtypeassigment_atom* typeassigment_entity::as_named() {
        return dynamic_cast<namedtypeassigment_atom*> (this);
    }

    std::ostream& operator<<(std::ostream& stream, typeassigment_entity* self) {
        return stream << "(T) " << self->name() << " :: = " << self->type().get() << "\n";
    }


    /////////////////////////////////////////////////////////////////////////   
    // namedtypeassigment_atom
    /////////////////////////////////////////////////////////////////////////  

    namedtypeassigment_atom::namedtypeassigment_atom(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, tagmarker_type mrker)
    : typeassigment_entity(scp, nm, tp), marker_(mrker) {
    }

    namedtypeassigment_atom::namedtypeassigment_atom(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl)
    : typeassigment_entity(scp, nm, tp), marker_(mk_default), default_(vl) {

    }

    std::ostream& operator<<(std::ostream& stream, namedtypeassigment_atom* self) {
        indent(stream, self); 
        return stream << self->name() << " " << self->type() << " " << self->marker();
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


    /////////////////////////////////////////////////////////////////////////   
    // valueassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    valueassigment_entity::valueassigment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl) :
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

    std::ostream& operator<<(std::ostream& stream, valueassigment_entity* self) {
        return stream << "(v) " << self->name() << " [" << self->type().get() << "] :: = " << self->value().get() << "\n";
    }


    /////////////////////////////////////////////////////////////////////////   
    // valuesetassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    valuesetassigment_entity::valuesetassigment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, basic_atom_ptr vl) :
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

    std::ostream& operator<<(std::ostream& stream, valuesetassigment_entity* self) {
        return stream << "(vS) " << self->name() << " [" << self->type().get() << "] :: = " << "\n";
    }


    /////////////////////////////////////////////////////////////////////////   
    // classassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    classassigment_entity::classassigment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr tp) :
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
            }
            return rslt;
        }

        typeassigment_entity_ptr compile_typeassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            x680::syntactic::type_assignment tmp = boost::get<x680::syntactic::type_assignment>(ent);
            return typeassigment_entity_ptr(new typeassigment_entity(scope, tmp.identifier, compile_type(scope, tmp.type)));
        }

        namedtypeassigment_atom_vct compile_structtype(basic_entity_ptr scope, const x680::syntactic::type_element& ent) {
            namedtypeassigment_atom_vct rslt;
            for (x680::syntactic::named_type_element_vector::const_iterator it = ent.elements.begin(); it != ent.elements.end(); ++it) {
                rslt.push_back(compile_namedtype(scope, it->identifier, it->type));
            }
            return rslt;
        }

        namedtypeassigment_atom_ptr compile_namedtype(basic_entity_ptr scope, const std::string& nm, const x680::syntactic::type_element& ent) {
            type_atom_ptr tmp = compile_type(scope, ent);
            if (ent.marker == mk_default) {
                return namedtypeassigment_atom_ptr(new namedtypeassigment_atom(scope, nm, tmp, compile_value(scope, ent.value)));
            } else {
                return namedtypeassigment_atom_ptr(new namedtypeassigment_atom(scope, nm, tmp, ent.marker));
            }
        }

        type_atom_ptr compile_type(basic_entity_ptr scope, const x680::syntactic::type_element& ent) {
            type_atom_ptr tmp = ent.reference.empty() ? type_atom_ptr(new type_atom(scope, ent.builtin_t, compile_tag(scope, ent.tag))) :
                    type_atom_ptr(new type_atom(scope, ent.reference, ent.builtin_t, compile_tag(scope, ent.tag)));
            tmp->predefined(compile_typepredef(scope, ent));
            switch (ent.builtin_t) {
                case t_SEQUENCE:
                case t_SEQUENCE_OF:
                case t_SET:
                case t_SET_OF:
                case t_CHOICE: tmp->elemens(compile_structtype(scope, ent));
                default:
                {
                };
            }
            return tmp;
        }

        predefined_ptr compile_typepredef(basic_entity_ptr scope, const x680::syntactic::type_element& ent) {
            if (ent.predefined.empty())
                return predefined_ptr();
            valueassigment_entity_vct rslt;
            for (x680::syntactic::value_element_vector::const_iterator it = ent.predefined.begin(); it != ent.predefined.end(); ++it) {
                if (it->value.empty()) {
                    valueassigment_entity_ptr el(new valueassigment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)), value_atom_ptr()));
                    rslt.push_back(el);
                } else {
                    try {
                        valueassigment_entity_ptr el(new valueassigment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                value_atom_ptr(new numvalue_atom(boost::lexical_cast<int > (it->value)))));
                        rslt.push_back(el);
                    } catch (boost::bad_lexical_cast) {
                        valueassigment_entity_ptr el(new valueassigment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                value_atom_ptr(new definedvalue_atom(it->value, scope))));
                        rslt.push_back(el);
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
            value_atom_ptr nm(new value_atom(scope, ent.number, v_defined));
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
            return valueassigment_entity_ptr(new valueassigment_entity(scope, tmp.identifier, compile_type(scope, tmp.type), compile_value(scope, tmp.value)));
        }

        value_atom_ptr compile_value(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            try {
                switch (ent.type) {
                    case v_boolean: return value_atom_ptr(new boolvalue_atom(ent.value == "TRUE"));
                    case v_number: return value_atom_ptr(new numvalue_atom(boost::lexical_cast<int > (ent.value)));
                    case v_real: return value_atom_ptr(new realvalue_atom(boost::lexical_cast<double > (ent.value)));
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
}