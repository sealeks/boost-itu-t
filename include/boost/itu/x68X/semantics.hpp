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
        et_Import,        
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
    
    class import_entity;
    typedef boost::shared_ptr<import_entity> import_entity_ptr;    
    
    class module_entity;
    typedef boost::shared_ptr<module_entity> module_entity_ptr;    

    class assignment_entity;    
    typedef boost::shared_ptr<assignment_entity> assignment_entity_ptr;      
    
    class type_entity;    
    typedef boost::shared_ptr<type_entity> type_entity_ptr;    
      
    
     /////////////////////////////////////////////////////////////////////////   
    // root_entity
    /////////////////////////////////////////////////////////////////////////  
    
    
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
        
        virtual root_entity_ptr find(const std::string& nm){
            return find_in_scope(scope(), nm);
        }
        
        void scope(root_entity_ptr vl)  {
            scope_=root_entity_wptr(vl);
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
        
        expectdef_entity* as_expectdef(){
            return type_==et_Nodef  ? reinterpret_cast<expectdef_entity* >(this) : 0;
        }    
        
        import_entity* as_import(){
            return type_==et_Import  ? reinterpret_cast<import_entity* >(this) : 0;
        }      
        
        type_entity* as_type(){
            return type_==et_Type  ? reinterpret_cast<type_entity* >(this) : 0;
        }              
        
        assignment_entity* as_assignment(){
            return reinterpret_cast<assignment_entity* >(this);
        }     
        
    protected:        
        
        root_entity_ptr find_in_scope(root_entity_ptr scp, const std::string& nm);     
        root_entity_ptr find_in_scope (const std::string& nm);         

    private:

    
        
        std::string name_;
        entity_enum type_;
        root_entity_wptr scope_;
        root_entity_vector childs_;        
    };
    
    
    

      /////////////////////////////////////////////////////////////////////////   
    // global_entity
    /////////////////////////////////////////////////////////////////////////  
    
    
    class global_entity : public root_entity {   
 
    public:
        
        global_entity();

    private:
        

    };    
    
     std::ostream& operator<<(std::ostream& stream, global_entity& self);   
    

    
    
     /////////////////////////////////////////////////////////////////////////   
    // expectdef_entity
    /////////////////////////////////////////////////////////////////////////  
    
     
    class expectdef_entity : public root_entity {   
 
    public:
        
        expectdef_entity(const std::string& nm);
 
        
    };
    
    
    
     /////////////////////////////////////////////////////////////////////////   
    // import_entity
    /////////////////////////////////////////////////////////////////////////  
    
     class import_entity : public root_entity {   
 
    public:
        
        import_entity(const std::string& nm);
 
        
    };   
    
    std::ostream& operator<<(std::ostream& stream, expectdef_entity& self); 
    
    
    
    
     /////////////////////////////////////////////////////////////////////////   
    // module_entity
    /////////////////////////////////////////////////////////////////////////  
    
    class module_entity : public root_entity {      
    public:      
        module_entity(root_entity_ptr scope, const std::string& nm, const std::string& fl, bool allexp);
        
        root_entity_vector& exports()  {
            return exports_;
        }   
        
        root_entity_vector& imports()  {
            return imports_;
        }           
        
        std::string file() const {
            return file_;
        }
        
        bool allexport() const {
            return allexport_;
        }      
        
        virtual root_entity_ptr find(const std::string& nm){
            root_entity_ptr rslt = find_in_scope(scope(), nm);
            if (rslt)
                return rslt;            
            rslt = find_in_scope(nm);
            if (rslt)
                return rslt;
            return find_in_import(nm);
        }        
        
    protected:

        root_entity_ptr find_in_import(const std::string& nm);           
        
    private:
        
        root_entity_vector exports_;
        root_entity_vector imports_;        
         std::string file_;
         bool allexport_;
    };


    std::ostream& operator<<(std::ostream& stream, module_entity& self);  
    
    
      /////////////////////////////////////////////////////////////////////////   
    // assignment_entity
    /////////////////////////////////////////////////////////////////////////  
    
    class assignment_entity : public root_entity {      
    public:      
        assignment_entity(root_entity_ptr scope, const std::string& nm, entity_enum tp, const std::string& rf="");
       
        root_entity_ptr reff() const {
            return reff_ ? reff_ : root_entity_ptr();
        }        
        
        void reff(root_entity_ptr vl)  {
            reff_=vl;
        }   
        
      
        
    private:
              
       root_entity_ptr reff_;
    };


    std::ostream& operator<<(std::ostream& stream, assignment_entity& self);     
    
    
     /////////////////////////////////////////////////////////////////////////   
    // type_entity
    /////////////////////////////////////////////////////////////////////////  
    
    class type_entity : public assignment_entity {      
    public:      
         type_entity(root_entity_ptr scope, const std::string& nm, defined_type tp,  const std::string& reff="");    
         defined_type builtin() const {
            return builtin_;
        }            
        
    private:
              
       defined_type builtin_;
       
    };


    std::ostream& operator<<(std::ostream& stream, type_entity& self);     
    
    std::ostream& operator<<(std::ostream& stream, defined_type self);

    namespace semantics {
        
        
        class error{
        public:
            error(const std::string& ms) : msg_(ms) {}
            std::string message() const{
                return msg_;}
            
        private:
            std::string msg_;
        };
        
        std::ostream& operator<<(std::ostream& stream, const error& self); 

        global_entity_ptr compile_fs(const std::string& path, const std::string& ext = "asn");
        
        void compile_module(const x680::syntactic::module& mod, global_entity_ptr global);  
        void compile_export(const x680::syntactic::module& mod, module_entity_ptr mdl);
        void compile_imports(const x680::syntactic::module& mod, module_entity_ptr mdl);        
        root_entity_ptr compile_import(const x680::syntactic::import& imp);
        void compile_assignments(const x680::syntactic::module& mod, module_entity_ptr mdl);          
        root_entity_ptr compile_assignment(root_entity_ptr scope, const x680::syntactic::assignment& ent);
        
        
        
        
        void check_modules_ref(global_entity_ptr global);
        void resolve_local_refs(global_entity_ptr global);    
        bool resolve_local_ref(module_entity* mod, bool all);          



    }
}

#endif	

