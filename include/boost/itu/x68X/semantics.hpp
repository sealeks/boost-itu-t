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
        et_Parameter,
        et_Extention
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

    class namedtypeassigment_entity;
    typedef boost::shared_ptr<namedtypeassigment_entity> namedtypeassigment_entity_ptr;
    typedef std::vector<namedtypeassigment_entity_ptr> namedtypeassigment_entity_vct;

    class valueassigment_entity;
    typedef boost::shared_ptr<valueassigment_entity> valueassigment_entity_ptr;
    typedef std::vector<valueassigment_entity_ptr> valueassigment_entity_vct;

    class valuesetassigment_entity;
    typedef boost::shared_ptr<valuesetassigment_entity> valuesetassigment_entity_ptr;

    class classassigment_entity;
    typedef boost::shared_ptr<classassigment_entity> classassigment_entity_ptr;

    class extention_entity;
    typedef boost::shared_ptr<extention_entity> extention_entity_ptr;


    class basic_atom;
    typedef boost::shared_ptr<basic_atom> basic_atom_ptr;



    class predefined;
    typedef boost::shared_ptr<predefined> predefined_ptr;

    class tagged;
    typedef boost::shared_ptr<tagged> tagged_ptr;

    class type_atom;
    typedef boost::shared_ptr<type_atom> type_atom_ptr;




    class value_atom;
    typedef boost::shared_ptr<value_atom> value_atom_ptr;
    typedef std::vector<value_atom_ptr> value_vct;

    class numvalue_atom;
    typedef boost::shared_ptr<numvalue_atom> numvalue_atom_ptr;

    class realvalue_atom;
    typedef boost::shared_ptr<realvalue_atom> realvalue_atom_ptr;

    class boolvalue_atom;
    typedef boost::shared_ptr<boolvalue_atom> boolvalue_atom_ptr;

    class strvalue_atom;
    typedef boost::shared_ptr<strvalue_atom> strvalue_atom_ptr;

    class namedvalue_atom;
    typedef boost::shared_ptr<namedvalue_atom> namedvalue_atom_ptr;
    typedef std::vector<namedvalue_atom_ptr> namedvalue_vct;

    class structvalue_atom;
    typedef boost::shared_ptr<structvalue_atom> structvalue_atom_ptr;

    class objidvalue_atom;
    typedef boost::shared_ptr<objidvalue_atom> objidvalue_atom_ptr;

    class listvalue_atom;
    typedef boost::shared_ptr<listvalue_atom> listvalue_atom_ptr;

    class definedvalue_atom;
    typedef boost::shared_ptr<definedvalue_atom> definedvalue_atom_ptr;

    class assignvalue_atom;
    typedef boost::shared_ptr<assignvalue_atom> assignvalue_atom_ptr;

    class choicevalue_atom;
    typedef boost::shared_ptr<choicevalue_atom> choicevalue_atom_ptr;

    class openvalue_atom;
    typedef boost::shared_ptr<openvalue_atom> openvalue_atom_ptr;

    class nullvalue_atom;
    typedef boost::shared_ptr<nullvalue_atom> nullvalue_atom_ptr;

    class emptyvalue_atom;
    typedef boost::shared_ptr<emptyvalue_atom> emptyvalue_atom_ptr;




    class class_atom;
    typedef boost::shared_ptr<class_atom> class_atom_ptr;

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

        void scope(basic_entity_ptr vl) {
            scope_ = basic_entity_wptr(vl);
        }

        basic_entity_vector& childs() {
            return childs_;
        }

        int level() const;

        module_entity* moduleref();

        std::string modulerefname();

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

        extention_entity* as_extention();

        std::string source_throw();

        void referenceerror_throw(const std::string& val);

        void unicalelerror_throw(const basic_entity_vector& elms);

        /////

        virtual basic_entity_ptr find(const std::string& nm, bool all = true);

        virtual void resolve();

    protected:

        void resolve_child();

    public:

        static void resolve_assigments(basic_entity_vector& elm);
        static void resolve_assigment(basic_entity_ptr& elm, basic_entity_ptr start = basic_entity_ptr());
        static void resolve_atom(basic_atom* elm, bool all = true);
        static void resolve_atom(basic_atom_ptr elm, bool all = true);
        static basic_entity_ptr resolve_nodef_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
        static basic_entity_ptr resolve_nodef_assigment(basic_entity* elm, basic_entity* start = 0);
        static void resolve_type_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
        static void resolve_type_assigment(basic_entity* elm, basic_entity* start = 0);
        static void resolve_value_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
        static void resolve_value_assigment(basic_entity* elm, basic_entity* start = 0);
        static void resolve_class_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
        static void resolve_class_assigment(basic_entity* elm, basic_entity* start = 0);

    private:

        std::string name_;
        entity_enum kind_;
        basic_entity_wptr scope_;
        basic_entity_vector childs_;
    };





    /////////////////////////////////////////////////////////////////////////   
    // assigment_entity
    /////////////////////////////////////////////////////////////////////////  


    /////////////////////////////////////////////////////////////////////////   
    // global_entity
    /////////////////////////////////////////////////////////////////////////  

    class global_entity : public basic_entity {

    public:

        global_entity();

        //////

        virtual basic_entity_ptr find(const std::string& nm, bool all = true);

        virtual void resolve();

    };





    /////////////////////////////////////////////////////////////////////////   
    // import_entity
    /////////////////////////////////////////////////////////////////////////  

    class import_entity : public basic_entity {

    public:

        import_entity(const std::string& nm);

        import_vector& import() {
            return import_;
        }

    private:

        import_vector import_;

    };





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

        //////

        virtual basic_entity_ptr find(const std::string& nm, bool all = true);

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



    /////////////////////////////////////////////////////////////////////////   
    // expectdef_entity
    /////////////////////////////////////////////////////////////////////////  

    class expectdef_entity : public basic_entity {

    public:

        expectdef_entity(const std::string& nm);
    };


    /////////////////////////////////////////////////////////////////////////   
    // expectdef_entity
    /////////////////////////////////////////////////////////////////////////  

    class extention_entity : public basic_entity {

    public:

        extention_entity() : basic_entity(et_Extention) {
        };
    };


    /////////////////////////////////////////////////////////////////////////   
    // basic_atom
    /////////////////////////////////////////////////////////////////////////  

    class basic_atom {

    public:
        basic_atom(basic_entity_ptr scp = basic_entity_ptr());
        basic_atom(const std::string& reff, basic_entity_ptr scp = basic_entity_ptr());

        virtual ~basic_atom() {
        }

        basic_entity_ptr scope() const {
            return scope_;
        }

        basic_entity_ptr reff() const {
            return reff_;
        }

        void reff(basic_entity_ptr vl) {
            reff_ = vl;
        }

        bool expecteddef() const {
            return ((reff_) && (reff_->as_expectdef()));
        }

        std::string expectedname() const {
            return expecteddef() ? reff_->name() : "";
        }

        module_entity* external() const;

        std::string externalpreff() const;

        virtual basic_atom* root();

        bool rooted();

        value_atom* as_value();

        type_atom* as_type();

        ////////

        virtual basic_entity_ptr find(const std::string& nm, bool all = true);

        virtual void resolve();


    protected:
        basic_entity_ptr reff_;
        basic_entity_ptr scope_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // predefined
    /////////////////////////////////////////////////////////////////////////      

    class predefined {

    public:

        predefined(basic_entity_ptr scp, defined_type tp)
        : scope_(scp), type_(tp), extended_(false) {
        };

        virtual ~predefined() {
        };

        basic_entity_vector& values() {
            return values_;
        }

        void values(const basic_entity_vector& vl) {
            values_ = vl;
        }

        defined_type type() const {
            return type_;
        }

        basic_entity_ptr scope() const {
            return scope_;
        }

        bool extended() const {
            return extended_;
        }

        void extended(bool vl) {
            extended_ = vl;
        }

    private:

        basic_entity_ptr scope_;
        basic_entity_vector values_;
        defined_type type_;
        bool extended_;
    };




    /////////////////////////////////////////////////////////////////////////   
    // tagged
    /////////////////////////////////////////////////////////////////////////      

    class tagged {

    public:

        tagged(value_atom_ptr vl, tagclass_type cl = tcl_context, tagrule_type rl = noset_tags)
        : number_(vl), class_(cl), rule_(rl) {
        }

        virtual ~tagged() {
        }

        value_atom_ptr number() const {
            return number_;
        }

        tagclass_type _class() const {
            return class_;
        }

        tagrule_type rule() const {
            return rule_;
        }

    private:

        value_atom_ptr number_;
        tagclass_type class_;
        tagrule_type rule_;

    };



    /////////////////////////////////////////////////////////////////////////   
    // type_atom
    /////////////////////////////////////////////////////////////////////////  

    class type_atom : public basic_atom {

    public:
        type_atom(basic_entity_ptr scp, defined_type tp, tagged_ptr tg = tagged_ptr());
        type_atom(basic_entity_ptr scp, const std::string& reff, defined_type tp, tagged_ptr tg = tagged_ptr());

        defined_type builtin() const {
            return builtin_;
        }

        tagged_ptr tag() const {
            return tag_;
        }

        predefined_ptr predefined() {
            return predefined_;
        }

        void predefined(predefined_ptr vl) {
            predefined_ = vl;
        }

        virtual void resolve();



    protected:

        void resolve_predef();
        void resolve_predef_assign(basic_entity_vector& vl);
        void resolve_predef_enum(basic_entity_vector& vl);
        void resolve_predef_check(basic_entity_vector& vl);
        void resolve_tag();

        defined_type builtin_;
        tagged_ptr tag_;
        predefined_ptr predefined_;

    };





    /////////////////////////////////////////////////////////////////////////   
    // value_atom
    /////////////////////////////////////////////////////////////////////////  

    class value_atom : public basic_atom {

    public:
        value_atom(basic_entity_ptr scp, value_type tpv);
        value_atom(basic_entity_ptr scp, const std::string& reff, value_type tpv);

        value_type valtype() const {
            return valtype_;
        }

        numvalue_atom* as_number();

        realvalue_atom* as_real();

        boolvalue_atom* as_bool();

        strvalue_atom* as_cstr();

        namedvalue_atom* as_named();

        structvalue_atom* as_struct();

        objidvalue_atom* as_objid();

        listvalue_atom* as_list();

        definedvalue_atom* as_defined();

        assignvalue_atom* as_assign();

        choicevalue_atom* as_choice();

        openvalue_atom* as_open();

        nullvalue_atom* as_null();

        emptyvalue_atom* as_empty();


    protected:

        void resolve_vect(value_vct& vl);

        void resolve_ptr(value_atom_ptr vl);

    private:

        value_type valtype_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // numvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class numvalue_atom : public value_atom {

    public:

        numvalue_atom(int vl) : value_atom(basic_entity_ptr(), v_number), value_(vl) {
        };

        int value() const {
            return value_;
        }

    private:

        int value_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // realvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class realvalue_atom : public value_atom {

    public:

        realvalue_atom(double vl) : value_atom(basic_entity_ptr(), v_real), value_(vl) {
        };

        double value() const {
            return value_;
        }

    private:

        double value_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // realvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class boolvalue_atom : public value_atom {

    public:

        boolvalue_atom(bool vl) : value_atom(basic_entity_ptr(), v_real), value_(vl) {
        };

        bool value() const {
            return value_;
        }

    private:

        bool value_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // strvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class strvalue_atom : public value_atom {

    public:

        strvalue_atom(const std::string& vl, value_type tpv) : value_atom(basic_entity_ptr(), tpv), value_(vl) {
        };

        std::string value() const {
            return value_;
        }

    private:

        std::string value_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // namedvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class namedvalue_atom : public value_atom {

    public:

        namedvalue_atom(const std::string& nm, value_atom_ptr vl)
        : value_atom(basic_entity_ptr(), v_named_value), name_(nm), value_(vl) {
        };

        std::string name() const {
            return name_;
        }

        value_atom_ptr value() const {
            return value_;
        }

        virtual void resolve();


    private:

        std::string name_;
        value_atom_ptr value_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // structvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class structvalue_atom : public value_atom {

    public:

        structvalue_atom(value_vct vls)
        : value_atom(basic_entity_ptr(), v_struct), values_(vls) {
        };

        value_vct& values() {
            return values_;
        }

        virtual void resolve();

    private:

        value_vct values_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // objidvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class objidvalue_atom : public value_atom {

    public:

        objidvalue_atom(value_vct vls)
        : value_atom(basic_entity_ptr(), v_objectid), values_(vls) {
        };

        value_vct& values() {
            return values_;
        }

        virtual void resolve();

    private:

        value_vct values_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // listvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class listvalue_atom : public value_atom {

    public:

        listvalue_atom(value_type tpv, value_vct vls)
        : value_atom(basic_entity_ptr(), tpv), values_(vls) {
        };

        value_vct& values() {
            return values_;
        }

        virtual void resolve();

    private:

        value_vct values_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // definedvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class definedvalue_atom : public value_atom {

    public:

        definedvalue_atom(const std::string& rff, basic_entity_ptr scp)
        : value_atom(scp, rff, v_defined) {
        };

        virtual void resolve();

    };



    /////////////////////////////////////////////////////////////////////////   
    // assignvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class assignvalue_atom : public value_atom {

    public:

        assignvalue_atom(const std::string& id, value_atom_ptr vl)
        : value_atom(basic_entity_ptr(), v_defined_assign), name_(id), value_(vl) {
        };

        const std::string& name() const {
            return name_;
        }

        value_atom_ptr value() const {
            return value_;
        }

        void value(value_atom_ptr vl) {
            value_ = vl;
        }

        virtual void resolve();




    private:

        std::string name_;
        value_atom_ptr value_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // choicevalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class choicevalue_atom : public value_atom {

    public:

        choicevalue_atom(const std::string& id, value_atom_ptr vl)
        : value_atom(basic_entity_ptr(), v_choice), name_(id), value_(vl) {
        };

        const std::string& name() const {
            return name_;
        }

        value_atom_ptr value() const {
            return value_;
        }

        void value(value_atom_ptr vl) {
            value_ = vl;
        }

        virtual void resolve();


    private:

        std::string name_;
        value_atom_ptr value_;
    };




    /////////////////////////////////////////////////////////////////////////   
    // openvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    class openvalue_atom : public value_atom {

    public:

        openvalue_atom(type_atom_ptr tp, value_atom_ptr vl)
        : value_atom(basic_entity_ptr(), v_open), type_(tp), value_(vl) {
        };

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        value_atom_ptr value() const {
            return value_;
        }

        void value(value_atom_ptr vl) {
            value_ = vl;
        }

        virtual void resolve();




    private:

        type_atom_ptr type_;
        value_atom_ptr value_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // nullvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class nullvalue_atom : public value_atom {

    public:

        nullvalue_atom() : value_atom(basic_entity_ptr(), v_null) {
        };

    };



    /////////////////////////////////////////////////////////////////////////   
    // emptyvalue_atom
    /////////////////////////////////////////////////////////////////////////  

    class emptyvalue_atom : public value_atom {

    public:

        emptyvalue_atom() : value_atom(basic_entity_ptr(), v_empty) {
        };

    };






    /////////////////////////////////////////////////////////////////////////   
    // class_atom
    /////////////////////////////////////////////////////////////////////////  

    class class_atom : public basic_atom {

    public:
        class_atom(definedclass_type tp);
        class_atom(const std::string& reff, definedclass_type tp);

        definedclass_type builtin() const {
            return builtin_;
        }

    private:

        definedclass_type builtin_;

    };





    /////////////////////////////////////////////////////////////////////////   
    // bigassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class bigassigment_entity : public basic_entity {

    public:
        bigassigment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg);

        basic_atom_ptr big() const {
            return big_;
        }

        void big(basic_atom_ptr vl) {
            big_ = vl;
        }


        /////        

        virtual basic_entity_ptr find(const std::string& nm, bool all = true);

        virtual void resolve() {
        };


    private:

        basic_atom_ptr big_;
    };




    /////////////////////////////////////////////////////////////////////////   
    // littleassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class littleassigment_entity : public basic_entity {

    public:
        littleassigment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg, basic_atom_ptr lt);

        basic_atom_ptr big() const {
            return big_;
        }

        void big(type_atom_ptr vl) {
            big_ = vl;
        }

        basic_atom_ptr little() const {
            return little_;
        }

        void little(basic_atom_ptr vl) {
            little_ = vl;
        }


        /////        

        virtual basic_entity_ptr find(const std::string& nm, bool all = true);

        virtual void resolve() {
        };


    private:

        basic_atom_ptr big_;
        basic_atom_ptr little_;
    };





    /////////////////////////////////////////////////////////////////////////   
    // typeassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class typeassigment_entity : public basic_entity {

    public:
        typeassigment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp);

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        namedtypeassigment_entity* as_named();


        /////        

        virtual basic_entity_ptr find(const std::string& nm, bool all = true);

        virtual void resolve();

        // protected:

        //   void resolve_predef();        

    private:

        type_atom_ptr type_;
    };






    /////////////////////////////////////////////////////////////////////////   
    // namedtypeassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class namedtypeassigment_entity : public typeassigment_entity {

    public:

        namedtypeassigment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, tagmarker_type mrker);
        namedtypeassigment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl);

        value_atom_ptr _default() const {
            return default_;
        }

        tagmarker_type marker() const {
            return marker_;
        }

        //////

        virtual void resolve();

    private:

        void resolve_default();

        value_atom_ptr default_;
        tagmarker_type marker_;

    };





    /////////////////////////////////////////////////////////////////////////   
    // valueassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class valueassigment_entity : public basic_entity {

    public:
        valueassigment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl);

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        value_atom_ptr value() const {
            return value_;
        }

        void value(value_atom_ptr vl) {
            value_ = vl;
        }

        void check_value_with_exception(value_type tp);


        /////        

        virtual basic_entity_ptr find(const std::string& nm, bool all = true);

        virtual void resolve();


    private:

        type_atom_ptr type_;
        value_atom_ptr value_;
    };




    /////////////////////////////////////////////////////////////////////////   
    // valueassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class valuesetassigment_entity : public basic_entity {

    public:
        valuesetassigment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, basic_atom_ptr vl);

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        basic_atom_ptr valueset() const {
            return valueset_;
        }

        void valueset(basic_atom_ptr vl) {
            valueset_ = vl;
        }


        /////        

        virtual basic_entity_ptr find(const std::string& nm, bool all = true);

        virtual void resolve();


    private:

        type_atom_ptr type_;
        basic_atom_ptr valueset_;
    };





    /////////////////////////////////////////////////////////////////////////   
    // classassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class classassigment_entity : public basic_entity {

    public:
        classassigment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr tp);

        class_atom_ptr _class() const {
            return class_;
        }

        void _class(class_atom_ptr vl) {
            class_ = vl;
        }


        /////        

        virtual basic_entity_ptr find(const std::string& nm, bool all = true);

        virtual void resolve();

    private:

        class_atom_ptr class_;
    };




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


        /////////////////////////////////////////////////////////////////////////   
        // precomile modules
        /////////////////////////////////////////////////////////////////////////          

        global_entity_ptr compile_fs(const std::string& path, const std::string& ext = "asn");

        void compile_module(const x680::syntactic::module& mod, global_entity_ptr global);
        void compile_export(const x680::syntactic::module& mod, module_entity_ptr mdl);
        void compile_imports(const x680::syntactic::module& mod, module_entity_ptr mdl);
        basic_entity_ptr compile_import(const x680::syntactic::import& imp);
        void compile_assignments(const x680::syntactic::module& mod, module_entity_ptr mdl);
        basic_entity_ptr compile_assignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);

        typeassigment_entity_ptr compile_typeassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        basic_entity_vector compile_structtype(basic_entity_ptr scope, const x680::syntactic::type_element& ent);
        typeassigment_entity_ptr compile_namedtype(basic_entity_ptr scope, const x680::syntactic::type_assignment& ent);
        type_atom_ptr compile_type(basic_entity_ptr scope, const x680::syntactic::type_element& ent);
        predefined_ptr compile_typepredef(basic_entity_ptr scope, const x680::syntactic::type_element& ent);
        tagged_ptr compile_tag(basic_entity_ptr scope, const x680::syntactic::tag_type& ent);

        classassigment_entity_ptr compile_classassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        class_atom_ptr compile_class(const x680::syntactic::class_element& ent);

        valueassigment_entity_ptr compile_valueassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        value_atom_ptr compile_value(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_vct compile_structvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_vct compile_objidvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_vct compile_listvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_atom_ptr compile_assignvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_atom_ptr compile_realvalue(basic_entity_ptr scope, const std::string& val);
        value_atom_ptr compile_choicevalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_atom_ptr compile_openvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_atom_ptr compile_namedvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);

        valuesetassigment_entity_ptr compile_valuesetassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);

        bigassigment_entity_ptr compile_bigassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);

        basic_atom_ptr compile_test(const std::string& rf);



    }

    /////////////////////////////////////////////////////////////////////////   
    // std::cout  tree
    /////////////////////////////////////////////////////////////////////////          


    std::ostream& indent(std::ostream& stream, typeassigment_entity* self);
    std::ostream& operator<<(std::ostream& stream, global_entity* self);
    std::ostream& operator<<(std::ostream& stream, module_entity* self);
    std::ostream& operator<<(std::ostream& stream, import_entity* self);
    std::ostream& operator<<(std::ostream& stream, expectdef_entity* self);
    std::ostream& operator<<(std::ostream& stream, extention_entity* self);
    std::ostream& operator<<(std::ostream& stream, basic_atom* self);
    std::ostream& operator<<(std::ostream& stream, predefined* self);
    std::ostream& operator<<(std::ostream& stream, tagclass_type self);
    std::ostream& operator<<(std::ostream& stream, tagrule_type self);
    std::ostream& operator<<(std::ostream& stream, tagged& self);
    std::ostream& operator<<(std::ostream& stream, type_atom* self);
    std::ostream& operator<<(std::ostream& stream, defined_type self);
    std::ostream& operator<<(std::ostream& stream, value_atom* self);
    std::ostream& operator<<(std::ostream& stream, numvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, realvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, boolvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, strvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, namedvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, structvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, objidvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, listvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, definedvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, assignvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, choicevalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, openvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, nullvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, emptyvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, bigassigment_entity* self);
    std::ostream& operator<<(std::ostream& stream, littleassigment_entity* self);
    std::ostream& operator<<(std::ostream& stream, typeassigment_entity* self);
    std::ostream& operator<<(std::ostream& stream, tagmarker_type self);
    std::ostream& operator<<(std::ostream& stream, valueassigment_entity* self);
    std::ostream& operator<<(std::ostream& stream, valuesetassigment_entity* self);
    std::ostream& operator<<(std::ostream& stream, classassigment_entity* self);
    std::ostream& operator<<(std::ostream& stream, class_atom* self);
    std::ostream& operator<<(std::ostream& stream, definedclass_type self);


}

#endif	

