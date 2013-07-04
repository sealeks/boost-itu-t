//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>


namespace x680 {

    global_entity::global_entity()
    : root_entity(et_Global) {
    }

    std::ostream& operator<<(std::ostream& stream, global_entity& self){
        stream << "GLOBAL SCOPE:"  << "\n";
        for (root_entity_vector::iterator it=self.childs().begin(); it!=self.childs().end();++it){
            if ((*it)->as_module())
                   stream << *((*it)->as_module());          
        }
        return stream;
    }
    
    
    // module_entity

    expectdef_entity::expectdef_entity(const std::string& nm)
    : root_entity(nm, et_Module) {
    }

    // module_entity

    module_entity::module_entity(root_entity_ptr scope, const std::string& nm)
    : root_entity(scope, nm, et_Module) {
    }
    
    std::ostream& operator<<(std::ostream& stream, const module_entity& self){
        stream << "module: "  << self.name() <<"\n";
        return stream;
    } 
    

    namespace semantics {

        global_entity_ptr compile_fs(const std::string& path, const std::string& ext) {
            x680::syntactic::modules synxtasresult;
            int success = x680::syntactic::parse_fs(path, synxtasresult);

            global_entity_ptr global = global_entity_ptr( new global_entity());
            
            for (x680::syntactic::modules::const_iterator it = synxtasresult.begin(); it != synxtasresult.end(); ++it)
              compile_module(*it, global);
   
            return global;
        }
        
         void compile_module(const x680::syntactic::module& mod, global_entity_ptr global){
             module_entity_ptr modul = module_entity_ptr( new module_entity(global, mod.name));
             global->childs().push_back(modul);
         }       


    }
}