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



     
    class basic_entity;
    typedef boost::shared_ptr<basic_entity> basic_entity_ptr;
    typedef boost::weak_ptr<basic_entity> basic_entity_wptr;
    typedef std::vector<basic_entity_ptr> basic_entity_vector;

    class expectdef_entity;
    typedef boost::shared_ptr<expectdef_entity> expectdef_entity_ptr;

    class global_entity;
    typedef boost::shared_ptr<global_entity> global_entity_ptr;

    class import_entity;
    typedef boost::shared_ptr<import_entity> import_entity_ptr;

    class module_entity;
    typedef boost::shared_ptr<module_entity> module_entity_ptr;
    
    
    
    

    class defined_entity;
    typedef boost::shared_ptr<defined_entity> defined_entity_ptr;

    class type_entity;
    typedef boost::shared_ptr<type_entity> type_entity_ptr;

    class value_entity;
    typedef boost::shared_ptr<value_entity> value_entity_ptr;
    
    typedef std::vector<std::string> export_vector;
    typedef std::vector<std::string> import_vector;   


    /////////////////////////////////////////////////////////////////////////   
    // basic_entity
    /////////////////////////////////////////////////////////////////////////  

    class basic_entity {

    public:

        basic_entity(basic_entity_ptr scope, const std::string& nm, entity_enum tp)
        : scope_(scope), name_(nm), type_(tp) {
        }

        basic_entity(const std::string& nm, entity_enum tp)
        : name_(nm), type_(tp) {
        }

        basic_entity(entity_enum tp)
        : type_(tp) {
        }

        virtual ~basic_entity() {
        }


        std::string name() const {
            return name_;
        }

        virtual entity_enum type() const {
            return type_;
        }

        basic_entity_ptr scope() const {
            return !scope_._empty() ? scope_.lock() : basic_entity_ptr();
        }

        virtual basic_entity_ptr find(const std::string& nm);

        virtual void resolve();

        void scope(basic_entity_ptr vl) {
            scope_ = basic_entity_wptr(vl);
        }

        basic_entity_vector& childs() {
            return childs_;
        }

        global_entity* as_global();

        module_entity* as_module();

        expectdef_entity* as_expectdef();

        import_entity* as_import();

        type_entity* as_type();

        value_entity* as_value();

        defined_entity * as_assignment();
        
        basic_entity_ptr self() const;

    protected:

        void resolve_child();
        
        static void resolve_assigments(basic_entity* elm); 
        static basic_entity_ptr resolve_assigment(basic_entity_ptr elm, basic_entity_ptr start=basic_entity_ptr());     
        static basic_entity_ptr resolve_nodef_assigment(basic_entity_ptr elm, basic_entity_ptr start=basic_entity_ptr());
        static basic_entity_ptr resolve_type_assigment(basic_entity_ptr  elm, basic_entity_ptr start=basic_entity_ptr());
        static basic_entity_ptr resolve_value_assigment(basic_entity_ptr  elm, basic_entity_ptr start=basic_entity_ptr());

    private:



        std::string name_;
        entity_enum type_;
        basic_entity_wptr scope_;
        basic_entity_vector childs_;
    };
    
    
    /////////////////////////////////////////////////////////////////////////   
    // assigment_entity



    /////////////////////////////////////////////////////////////////////////   
    // global_entity
    /////////////////////////////////////////////////////////////////////////  

    class global_entity : public basic_entity {

    public:

        global_entity();
        virtual void resolve();
        virtual basic_entity_ptr find(const std::string& nm);

    private:


    };

    std::ostream& operator<<(std::ostream& stream, global_entity& self);








    /////////////////////////////////////////////////////////////////////////   
    // import_entity
    /////////////////////////////////////////////////////////////////////////  

    class import_entity : public basic_entity {

    public:

        import_entity(const std::string& nm);
        virtual void resolve();
        
        import_vector& import() {
            return import_;
        }        
        
    private:

        import_vector import_;       

    };

    std::ostream& operator<<(std::ostream& stream, expectdef_entity& self);




    /////////////////////////////////////////////////////////////////////////   
    // module_entity
    /////////////////////////////////////////////////////////////////////////  

    class module_entity : public basic_entity {

    public:
        module_entity(basic_entity_ptr scope, const std::string& nm, const std::string& fl, bool allexp);

        export_vector& exports() {
            return exports_;
        }

        basic_entity_vector& imports() {
            return imports_;
        }

        std::string file() const {
            return file_;
        }

        bool allexport() const {
            return allexport_;
        }

        virtual basic_entity_ptr find(const std::string& nm);

        virtual void resolve();       

    private:
        
        void resolve_export();
        void resolve_externalmodule();
        basic_entity_ptr findmodule(const std::string& nm);         

        export_vector exports_;
        basic_entity_vector imports_;
        std::string file_;
        bool allexport_;
    };


    std::ostream& operator<<(std::ostream& stream, module_entity& self);
    
    
        /////////////////////////////////////////////////////////////////////////   
    // expectdef_entity
    /////////////////////////////////////////////////////////////////////////  

    class expectdef_entity : public basic_entity {

    public:

        expectdef_entity(basic_entity_ptr scope, const std::string& nm);



    };    
    
    /////////////////////////////////////////////////////////////////////////   
    // declare_entity
    /////////////////////////////////////////////////////////////////////////  

    class declare_entity : public basic_entity {

    public:
        declare_entity(basic_entity_ptr scope, const std::string& nm, defined_entity_ptr atm);
        
        virtual entity_enum type() const {
            return atom_ ? atom_->type() : et_Nodef;
        }

        basic_entity_ptr atom() const {
            return atom_;
        }

        void atom(defined_entity_ptr vl) {
            atom_ = vl;
        }
        
        virtual basic_entity_ptr find(const std::string& nm);


    private:
        
        defined_entity_ptr atom_;
    };    


    /////////////////////////////////////////////////////////////////////////   
    // defined_entity
    /////////////////////////////////////////////////////////////////////////  

    class defined_entity  {

    public:
        defined_entity(entity_enum tp): type_(tp) {};

        entity_enum type() const {
            return type_;
        }
        
         basic_entity_ptr reff() const {
            return reff_;
        }

        void reff(basic_entity_ptr vl) {
            reff_ = vl;
        }

    private:
        basic_entity_ptr  reff_;
        entity_enum type_;
    };


    std::ostream& operator<<(std::ostream& stream, defined_entity& self);
    



    /////////////////////////////////////////////////////////////////////////   
    // type_entity
    /////////////////////////////////////////////////////////////////////////  

    class type_entity : public defined_entity {

    public:
        type_entity(basic_entity_ptr scope, defined_type tp, const std::string& nm = "", const std::string& reff = "");

        defined_type builtin() const {
            return builtin_;
        }
        
        //virtual basic_entity_ptr find(const std::string& nm);

    private:

        defined_type builtin_;

    };


    std::ostream& operator<<(std::ostream& stream, type_entity& self);

    std::ostream& operator<<(std::ostream& stream, defined_type self);



    /////////////////////////////////////////////////////////////////////////   
    // type_entity
    /////////////////////////////////////////////////////////////////////////  

    class value_entity : public defined_entity {

    public:
        value_entity(basic_entity_ptr scope, value_type tpv, const std::string& nm = "", const std::string& reff = "");
        value_entity(basic_entity_ptr scope, value_type tpv, type_entity_ptr t, const std::string& nm = "", const std::string& reff = "");

        value_type valtype() const {
            return valtype_;
        }

        type_entity_ptr tp() const {
            return tp_;
        }
        
        void tp( basic_entity_ptr vl)  {
            tp_=boost::dynamic_pointer_cast<type_entity>(vl);
        }        
             

    private:

        value_type valtype_;
        type_entity_ptr tp_;

    };


    std::ostream& operator<<(std::ostream& stream, value_entity& self);

    //void check_resolve_ciclic(basic_entity_ptr elm, basic_entity_ptr start);     


    namespace semantics {

        class error {

        public:

            error(const std::string& ms) : msg_(ms) {
            }

            std::string message() const {
                return msg_;
            }

        private:
            std::string msg_;
        };

        std::ostream& operator<<(std::ostream& stream, const error& self);

        global_entity_ptr compile_fs(const std::string& path, const std::string& ext = "asn");

        void compile_module(const x680::syntactic::module& mod, global_entity_ptr global);
        void compile_export(const x680::syntactic::module& mod, module_entity_ptr mdl);
        void compile_imports(const x680::syntactic::module& mod, module_entity_ptr mdl);
        basic_entity_ptr compile_import(const x680::syntactic::import& imp);
        void compile_assignments(const x680::syntactic::module& mod, module_entity_ptr mdl);
        basic_entity_ptr compile_assignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        type_entity_ptr compile_typeassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        type_entity_ptr compile_type(basic_entity_ptr scope, const x680::syntactic::type_element& ent, const std::string id = "");
        value_entity_ptr compile_valueassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        value_entity_ptr compile_value(basic_entity_ptr scope, const x680::syntactic::value_element& ent, const std::string id = "");




    }
}

#endif	

