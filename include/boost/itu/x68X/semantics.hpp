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

    class bigassigment_entity;
    typedef boost::shared_ptr<bigassigment_entity> bigassigment_entity_ptr;

    class littleassigment_entity;
    typedef boost::shared_ptr<littleassigment_entity> littleassigment_entity_ptr;

    class typeassigment_entity;
    typedef boost::shared_ptr<typeassigment_entity> typeassigment_entity_ptr;

    class valueassigment_entity;
    typedef boost::shared_ptr<valueassigment_entity> valueassigment_entity_ptr;
    
    class valuesetassigment_entity;
    typedef boost::shared_ptr<valuesetassigment_entity> valuesetassigment_entity_ptr;    
    
    class classassigment_entity;
    typedef boost::shared_ptr<classassigment_entity> classassigment_entity_ptr;    

    class defined_entity;
    typedef boost::shared_ptr<defined_entity> defined_entity_ptr;

    class type_entity;
    typedef boost::shared_ptr<type_entity> type_entity_ptr;

    class value_entity;
    typedef boost::shared_ptr<value_entity> value_entity_ptr;
    
    class class_entity;
    typedef boost::shared_ptr<class_entity> class_entity_ptr;    

    typedef std::vector<std::string> export_vector;
    typedef std::vector<std::string> import_vector;


    /////////////////////////////////////////////////////////////////////////   
    // basic_entity
    /////////////////////////////////////////////////////////////////////////  

    class basic_entity {

    public:

        basic_entity(basic_entity_ptr scope, const std::string& nm, entity_enum tp)
        : scope_(scope), name_(nm), kind_(tp) {
        }

        basic_entity(const std::string& nm, entity_enum tp)
        : name_(nm), kind_(tp) {
        }

        basic_entity(entity_enum tp)
        : kind_(tp) {
        }

        virtual ~basic_entity() {
        }

        std::string name() const {
            return name_;
        }

        entity_enum kind() const {
            return kind_;
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

        bigassigment_entity* as_bigassigment();

        littleassigment_entity* as_littleassigment();

        typeassigment_entity* as_typeassigment();

        valueassigment_entity* as_valueassigment();
        
        valuesetassigment_entity* as_valuesetassigment();
        
        classassigment_entity* as_classassigment();        

    protected:

        void resolve_child();

        static void resolve_assigments(basic_entity* elm);
        static basic_entity_ptr resolve_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
        static basic_entity_ptr resolve_nodef_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
        static basic_entity_ptr resolve_type_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
        static basic_entity_ptr resolve_value_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
        static basic_entity_ptr resolve_class_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());        

    private:



        std::string name_;
        entity_enum kind_;
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

        expectdef_entity(const std::string& nm);



    };



    /////////////////////////////////////////////////////////////////////////   
    // defined_entity
    /////////////////////////////////////////////////////////////////////////  

    class defined_entity {

    public:
        defined_entity();
        defined_entity(const std::string& reff);

        basic_entity_ptr reff() const {
            return reff_;
        }

        void reff(basic_entity_ptr vl) {
            reff_ = vl;
        }

    private:
        basic_entity_ptr reff_;
    };


    std::ostream& operator<<(std::ostream& stream, defined_entity& self);

    /////////////////////////////////////////////////////////////////////////   
    // type_entity
    /////////////////////////////////////////////////////////////////////////  

    class type_entity : public defined_entity {

    public:
        type_entity(defined_type tp);
        type_entity(const std::string& reff, defined_type tp);

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
    // value_entity
    /////////////////////////////////////////////////////////////////////////  

    class value_entity : public defined_entity {

    public:
        value_entity(value_type tpv);
        value_entity(const std::string& reff, value_type tpv);

        value_type valtype() const {
            return valtype_;
        }

    private:

        value_type valtype_;

    };
    
   
    std::ostream& operator<<(std::ostream& stream, value_entity& self);
    
    
    /////////////////////////////////////////////////////////////////////////   
    // class_entity
    /////////////////////////////////////////////////////////////////////////  

    class class_entity : public defined_entity {

    public:
        class_entity(definedclass_type tp);
        class_entity(const std::string& reff, definedclass_type tp);

        definedclass_type builtin() const {
            return builtin_;
        }

        //virtual basic_entity_ptr find(const std::string& nm);

    private:

        definedclass_type builtin_;

    };     

    /////////////////////////////////////////////////////////////////////////   
    // bigassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class bigassigment_entity : public basic_entity {

    public:
        bigassigment_entity(basic_entity_ptr scope, const std::string& nm, defined_entity_ptr bg);

        defined_entity_ptr big() const {
            return big_;
        }

        void big(defined_entity_ptr vl) {
            big_ = vl;
        }

        virtual basic_entity_ptr find(const std::string& nm);


    private:

        defined_entity_ptr big_;
    };

    std::ostream& operator<<(std::ostream& stream, bigassigment_entity& self);


    /////////////////////////////////////////////////////////////////////////   
    // littleassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class littleassigment_entity : public basic_entity {

    public:
        littleassigment_entity(basic_entity_ptr scope, const std::string& nm, defined_entity_ptr bg, defined_entity_ptr lt);

        defined_entity_ptr big() const {
            return big_;
        }

        void big(type_entity_ptr vl) {
            big_ = vl;
        }

        defined_entity_ptr little() const {
            return little_;
        }

        void little(defined_entity_ptr vl) {
            little_ = vl;
        }

        virtual basic_entity_ptr find(const std::string& nm);


    private:

        defined_entity_ptr big_;
        defined_entity_ptr little_;
    };

    std::ostream& operator<<(std::ostream& stream, littleassigment_entity& self);



    /////////////////////////////////////////////////////////////////////////   
    // typeassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class typeassigment_entity : public basic_entity {

    public:
        typeassigment_entity(basic_entity_ptr scope, const std::string& nm, type_entity_ptr tp);

        type_entity_ptr type() const {
            return type_;
        }

        void type(type_entity_ptr vl) {
            type_ = vl;
        }

        virtual basic_entity_ptr find(const std::string& nm);
        


    private:

        type_entity_ptr type_;
    };

    std::ostream& operator<<(std::ostream& stream, typeassigment_entity& self);


    /////////////////////////////////////////////////////////////////////////   
    // valueassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class valueassigment_entity : public basic_entity {

    public:
        valueassigment_entity(basic_entity_ptr scope, const std::string& nm, type_entity_ptr tp, value_entity_ptr vl);

        type_entity_ptr type() const {
            return type_;
        }

        void type(type_entity_ptr vl) {
            type_ = vl;
        }

        value_entity_ptr value() const {
            return value_;
        }

        void value(value_entity_ptr vl) {
            value_ = vl;
        }

        virtual basic_entity_ptr find(const std::string& nm);


    private:

        type_entity_ptr type_;
        value_entity_ptr value_;
    };

    std::ostream& operator<<(std::ostream& stream, valueassigment_entity& self);


    /////////////////////////////////////////////////////////////////////////   
    // valueassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class valuesetassigment_entity : public basic_entity {

    public:
        valuesetassigment_entity(basic_entity_ptr scope, const std::string& nm, type_entity_ptr tp, defined_entity_ptr vl);

        type_entity_ptr type() const {
            return type_;
        }

        void type(type_entity_ptr vl) {
            type_ = vl;
        }

        defined_entity_ptr valueset() const {
            return valueset_;
        }

        void valueset(defined_entity_ptr vl) {
            valueset_ = vl;
        }

        virtual basic_entity_ptr find(const std::string& nm);


    private:

        type_entity_ptr type_;
        defined_entity_ptr valueset_;
    };

    std::ostream& operator<<(std::ostream& stream, valuesetassigment_entity& self);


    
    /////////////////////////////////////////////////////////////////////////   
    // classassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class classassigment_entity : public basic_entity {

    public:
        classassigment_entity(basic_entity_ptr scope, const std::string& nm, class_entity_ptr tp);

        class_entity_ptr _class() const {
            return class_;
        }

        void _class(class_entity_ptr vl) {
            class_ = vl;
        }

        virtual basic_entity_ptr find(const std::string& nm);
        


    private:

        class_entity_ptr class_;
    };

    std::ostream& operator<<(std::ostream& stream, classassigment_entity& self);    

    std::ostream& operator<<(std::ostream& stream, class_entity& self);
    
    std::ostream& operator<<(std::ostream& stream, definedclass_type self); 


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
        typeassigment_entity_ptr compile_typeassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        type_entity_ptr compile_type(const x680::syntactic::type_element& ent);
        classassigment_entity_ptr compile_classassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        class_entity_ptr compile_class(const x680::syntactic::class_element& ent);        
        valueassigment_entity_ptr compile_valueassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        value_entity_ptr compile_value(const x680::syntactic::value_element& ent);
        valuesetassigment_entity_ptr compile_valuesetassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent); 
        bigassigment_entity_ptr compile_bigassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        defined_entity_ptr compile_test(const std::string& rf);




    }
}

#endif	

