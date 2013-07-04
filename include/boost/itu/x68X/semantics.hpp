//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1MODULE_IMPLEMENTATIUON_H_
#define	_ITU_ASN1MODULE_IMPLEMENTATIUON_H_

#include <boost/itu/x68X/modules.hpp>
#include <boost/weak_ptr.hpp>

namespace x680 {

    enum entity_enum {

        et_Nodef,
        et_Global,       
        et_Module,
        et_Type,
        et_Value,
        et_ValueSet,
        et_Class,
        et_Object,
        et_ObjectSet,
        et_Parameter
    };


    class root_entity;
    typedef boost::shared_ptr<root_entity> root_entity_ptr;
    typedef boost::weak_ptr<root_entity> root_entity_wptr;
    typedef std::vector<root_entity_ptr> root_entity_vector;    
    
    class expectdef_entity;
    typedef boost::shared_ptr<expectdef_entity> expectdef_entity_ptr;
    
    class global_entity;
    typedef boost::shared_ptr<global_entity> global_entity_ptr;
    
    class module_entity;
    typedef boost::shared_ptr<module_entity> module_entity_ptr;    

    // root_entity

    class root_entity {

    public:

        root_entity(root_entity_ptr scope, const std::string& nm, entity_enum tp) 
        : scope_(scope), name_(nm), type_(tp) {
        }
        
        root_entity(const std::string& nm, entity_enum tp) 
        :   name_(nm), type_(tp) {
        }                
        
        root_entity(entity_enum tp) 
        :  type_(tp) {
        }        

        virtual ~root_entity() {
        }

        std::string name() const {
            return name_;
        }

        entity_enum type() const {
            return type_;
        }
        
        root_entity_ptr scope() const {
            return !scope_._empty() ? scope_.lock() : root_entity_ptr();
        }        
        
        root_entity_vector& childs()  {
            return childs_;
        }   
        
        global_entity* as_global(){
            return type_==et_Global  ? reinterpret_cast<global_entity* >(this) : 0;
        }
        
        module_entity* as_module(){
            return type_==et_Module  ? reinterpret_cast<module_entity* >(this) : 0;
        }        

    private:
        std::string name_;
        entity_enum type_;
        root_entity_wptr scope_;
        root_entity_vector childs_;        
    };
    
    
    // global_entity
    
    class global_entity : public root_entity {   
 
    public:
        
        global_entity();

    private:
        

    };    
    
     std::ostream& operator<<(std::ostream& stream, global_entity& self);   
    
    //const global_entity_ptr GLOBALSCOPE = global_entity_ptr( new global_entity());
    
    
    // expectdef_entity
     
    class expectdef_entity : public root_entity {   
 
    public:
        
        expectdef_entity(const std::string& nm);
 
        
    };
    
    
    
    // module_entity
    
    class module_entity : public root_entity {      
    public:      
        module_entity(root_entity_ptr scope, const std::string& nm);
 
        
    };


    std::ostream& operator<<(std::ostream& stream, const module_entity& self);  

    namespace semantics {

        global_entity_ptr compile_fs(const std::string& path, const std::string& ext = "asn");
        
        void compile_module(const x680::syntactic::module& mod, global_entity_ptr global);        




    }
}

#endif	

