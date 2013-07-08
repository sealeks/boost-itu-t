//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>


namespace x680 {

    /////////////////////////////////////////////////////////////////////////   
    // global_entity
    /////////////////////////////////////////////////////////////////////////  

    global_entity::global_entity()
    : root_entity(et_Global) {
    }

    std::ostream& operator<<(std::ostream& stream, global_entity& self) {
        stream << "GLOBAL SCOPE:" << "\n";
        for (root_entity_vector::iterator it = self.childs().begin(); it != self.childs().end(); ++it) {
            if ((*it)->as_module())
                stream << *((*it)->as_module());
        }
        return stream;
    }

    /////////////////////////////////////////////////////////////////////////   
    // expectdef_entity
    /////////////////////////////////////////////////////////////////////////

    expectdef_entity::expectdef_entity(const std::string& nm)
    : root_entity(nm, et_Nodef) {
    }

    std::ostream& operator<<(std::ostream& stream, expectdef_entity& self) {
        stream << self.name() << "(?)";
        return stream;
    }

    /////////////////////////////////////////////////////////////////////////
    // import_entity
    /////////////////////////////////////////////////////////////////////////

    import_entity::import_entity(const std::string& nm)
    : root_entity(nm, et_Import) {
    }

    std::ostream& operator<<(std::ostream& stream, import_entity& self) {
        if (self.scope())
            stream << "      from module: " << self.name();
        else
            stream << "      from module: " << self.name() << "(?)";
        stream << "\n      symbol: ";
        for (root_entity_vector::iterator it = self.childs().begin(); it != self.childs().end(); ++it) {
            if ((*it)->as_expectdef())
                stream << *((*it)->as_expectdef()) << ", ";
            else
                stream << (*it)->name() << ", ";
        }
        stream << "\n";
        return stream;
    }

    /////////////////////////////////////////////////////////////////////////   
    // module_entity
    /////////////////////////////////////////////////////////////////////////   

    module_entity::module_entity(root_entity_ptr scope, const std::string& nm, const std::string& fl)
    : root_entity(scope, nm, et_Module), file_(fl) {
    }

    std::ostream& operator<<(std::ostream& stream, module_entity& self) {
        stream << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        stream << "module: " << self.name() << "\nfile:" << self.file() << "\n";
        stream << "----------------------------------------------------------\n";
        stream << "      export: ";
        for (root_entity_vector::iterator it = self.exports().begin(); it != self.exports().end(); ++it) {
            if ((*it)->as_expectdef())
                stream << *((*it)->as_expectdef()) << ", ";
            else
                stream << (*it)->name() << ", ";
        }
        stream << "\n----------------------------------------------------------\n";
        stream << "      IMPORTS: ";
        for (root_entity_vector::iterator it = self.imports().begin(); it != self.imports().end(); ++it) {
            stream << "\n.............................................................................................\n";
            stream << "      import: \n";
            if ((*it)->as_import())
                stream << *((*it)->as_import());
        }
        stream << "      ELEMENS: ";
        for (root_entity_vector::iterator it = self.childs().begin(); it != self.childs().end(); ++it) {;
            //stream << "      components: ";
            if ((*it)->as_assignment())
                stream << *((*it)->as_assignment());
        } 
        return stream;
    }


    /////////////////////////////////////////////////////////////////////////   
    // assignment_entity
    /////////////////////////////////////////////////////////////////////////   

    assignment_entity::assignment_entity(root_entity_ptr scope, const std::string& nm, entity_enum tp, const std::string& rf)
    : root_entity(scope, nm, tp){
        if (!rf.empty())
            reff(root_entity_ptr(new expectdef_entity(rf)));
    }

    std::ostream& operator<<(std::ostream& stream, assignment_entity& self) {
        stream << "\n        ";
        switch (self.type()) {
            case et_Type:
            {
                return stream << *(self.as_type());
                break;
            }
            case et_Value:
            {
                stream << "VL: ";
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
        return stream;
    }
    

    /////////////////////////////////////////////////////////////////////////   
    // type_entity
    /////////////////////////////////////////////////////////////////////////   

    type_entity::type_entity(root_entity_ptr scope, const std::string& nm, defined_type tp,  const std::string& reff)
    : assignment_entity(scope, nm, et_Type, reff), builtin_(tp) {
    }

    std::ostream& operator<<(std::ostream& stream, type_entity& self) {
        stream << "TP: " << self.builtin();
        if (self.builtin()==t_Reference)
            stream << " reff_to: [" << *(self.reff()->as_expectdef()) <<  "] ";
        stream << " id: "  << self.name();
        return stream;
    }
    
    std::ostream& operator<<(std::ostream& stream, defined_type self) {
        switch(self){
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
          case t_Reference: return stream << "Reference";   
            default:{};
        }
        return stream;
    }    

    namespace semantics {

        global_entity_ptr compile_fs(const std::string& path, const std::string& ext) {
            x680::syntactic::modules synxtasresult;
            int success = x680::syntactic::parse_fs(path, synxtasresult);

            global_entity_ptr global = global_entity_ptr(new global_entity());

            for (x680::syntactic::modules::const_iterator it = synxtasresult.begin(); it != synxtasresult.end(); ++it)
                compile_module(*it, global);

            return global;
        }

        void compile_module(const x680::syntactic::module& mod, global_entity_ptr global) {
            module_entity_ptr modul = module_entity_ptr(new module_entity(global, mod.name, mod.file));
            compile_export(mod, modul);
            compile_imports(mod, modul);
            compile_assignments(mod, modul);            
            global->childs().push_back(modul);
        }

        void compile_export(const x680::syntactic::module& mod, module_entity_ptr mdl) {
            for (x680::syntactic::exports::const_iterator it = mod.exports_.begin(); it != mod.exports_.end(); ++it)
                mdl->exports().push_back(root_entity_ptr(new expectdef_entity(*it)));
        }

        void compile_imports(const x680::syntactic::module& mod, module_entity_ptr mdl) {
            for (x680::syntactic::imports::const_iterator it = mod.imports_.begin(); it != mod.imports_.end(); ++it) {
                mdl->imports().push_back(compile_import(*it));
            }
        }

        root_entity_ptr compile_import(const x680::syntactic::import& imp) {
            import_entity_ptr rslt = import_entity_ptr(new import_entity(imp.name));
            for (x680::syntactic::string_vector::const_iterator it = imp.names.begin(); it != imp.names.end(); ++it)
                rslt->childs().push_back(root_entity_ptr(new expectdef_entity(*it)));
            return rslt;
        }
        
        void compile_assignments(const x680::syntactic::module& mod, module_entity_ptr mdl){
            for (x680::syntactic::assignment_vector::const_iterator it = mod.elements.begin(); it != mod.elements.end(); ++it) {
                mdl->childs().push_back(compile_assignment(mdl,*it));
            }            
        }   

        root_entity_ptr compile_assignment(root_entity_ptr scope, const x680::syntactic::assignment& ent) {
            entity_enum tp = et_Nodef;
            assignment_entity_ptr rslt;
            switch (ent.which()) {
                case 0:
                {
                    tp = et_Type;
                     x680::syntactic::type_assignment tmp=boost::get<x680::syntactic::type_assignment>(ent);
                    rslt = type_entity_ptr(new type_entity(scope, tmp.identifier, tmp.type.builtin_t,tmp.type.reference));
                    break;
                }
                case 1:
                {
                    tp = et_Value;
                     x680::syntactic::value_assignment tmp=boost::get<x680::syntactic::value_assignment>(ent);
                    rslt = assignment_entity_ptr(new assignment_entity(scope, tmp.identifier, tp));
                    break;
                }        
                case 2:
                {
                    tp = et_ValueSet;
                     x680::syntactic::valueset_assignment tmp=boost::get<x680::syntactic::valueset_assignment>(ent);
                    rslt = assignment_entity_ptr(new assignment_entity(scope, tmp.identifier, tp));
                    break;
                }         
                case 3:
                {
                    tp = et_Class;
                     x680::syntactic::class_assignment tmp=boost::get<x680::syntactic::class_assignment>(ent);
                    rslt = assignment_entity_ptr(new assignment_entity(scope, tmp.identifier, tp));
                    break;
                }    
                case 4:
                {
                    tp = et_Object;
                     x680::syntactic::object_assignment tmp=boost::get<x680::syntactic::object_assignment>(ent);
                    rslt = assignment_entity_ptr(new assignment_entity(scope, tmp.identifier, tp));
                    break;
                }        
                case 5:
                {
                    tp = et_ObjectSet;
                     x680::syntactic::objectset_assignment tmp=boost::get<x680::syntactic::objectset_assignment>(ent);
                    rslt = assignment_entity_ptr(new assignment_entity(scope, tmp.identifier, tp));
                    break;
                }                   
                default:{
                    rslt = assignment_entity_ptr(new assignment_entity(scope, "NDF", tp));
                }
            }        
            return rslt;
        }


    }
}