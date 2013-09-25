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
        et_NodefV,
        et_NodefS,
        et_Global,
        et_Module,
        et_Import,
        et_Type,
        et_Value,
        et_ValueSet,
        et_Class,
        et_ClassField,
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

    class voassigment_entity;
    typedef boost::shared_ptr<voassigment_entity> voassigment_entity_ptr;

    class soassigment_entity;
    typedef boost::shared_ptr<soassigment_entity> soassigment_entity_ptr;



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




    class valueset_atom;
    typedef boost::shared_ptr<valueset_atom> valueset_atom_ptr;

    class constraints_atom;
    typedef boost::shared_ptr<constraints_atom> constraints_atom_ptr;
    typedef std::vector<constraints_atom_ptr> constraints_atom_vct;

    class constraint_atom;
    typedef boost::shared_ptr<constraint_atom> constraint_atom_ptr;
    typedef std::vector<constraint_atom_ptr> constraint_atom_vct;

    class typeconstraint_atom;
    typedef boost::shared_ptr<typeconstraint_atom> typeconstraint_atom_ptr;

    class valueconstraint_atom;
    typedef boost::shared_ptr<valueconstraint_atom> valueconstraint_atom_ptr;

    class rangeconstraint_atom;
    typedef boost::shared_ptr<rangeconstraint_atom> rangeconstraint_atom_ptr;

    class stringconstraint_atom;
    typedef boost::shared_ptr<stringconstraint_atom> stringconstraint_atom_ptr;

    class namedconstraint_atom;
    typedef boost::shared_ptr<namedconstraint_atom> namedconstraint_atom_ptr;

    class multipletypeconstraint_atom;
    typedef boost::shared_ptr<multipletypeconstraint_atom> multipletypeconstraint_atom_ptr;

    class complexconstraint_atom;
    typedef boost::shared_ptr<complexconstraint_atom> complexconstraint_atom_ptr;

    class unionconstraint_atom;
    typedef boost::shared_ptr<unionconstraint_atom> unionconstraint_atom_ptr;

    class intersectionconstraint_atom;
    typedef boost::shared_ptr<intersectionconstraint_atom> intersectionconstraint_atom_ptr;

    class exceptconstraint_atom;
    typedef boost::shared_ptr<exceptconstraint_atom> exceptconstraint_atom_ptr;

    class allexceptconstraint_atom;
    typedef boost::shared_ptr<allexceptconstraint_atom> allexceptconstraint_atom_ptr;

    class exceptconstraint_atom;
    typedef boost::shared_ptr<exceptconstraint_atom> exceptconstraint_atom_ptr;

    class allexceptconstraint_atom;
    typedef boost::shared_ptr<allexceptconstraint_atom> allexceptconstraint_atom_ptr;

    class extentionconstraint_atom;
    typedef boost::shared_ptr<extentionconstraint_atom> extentionconstraint_atom_ptr;

    class exceptionconstraint_atom;
    typedef boost::shared_ptr<exceptionconstraint_atom> exceptionconstraint_atom_ptr;


    class class_atom;
    typedef boost::shared_ptr<class_atom> class_atom_ptr;


    class field_entity;
    typedef boost::shared_ptr<field_entity> field_entity_ptr;
    typedef std::vector<field_entity_ptr> field_entity_vct;

    class typefield_entity;
    typedef boost::shared_ptr<typefield_entity> typefield_entity_ptr;

    class valuefield_entity;
    typedef boost::shared_ptr<valuefield_entity> valuefield_entity_ptr;

    class valuesetfield_entity;
    typedef boost::shared_ptr<valuesetfield_entity> valuesetfield_entity_ptr;

    class reffvaluefield_entity;
    typedef boost::shared_ptr<reffvaluefield_entity> reffvaluefield_entity_ptr;

    class reffvaluesetfield_entity;
    typedef boost::shared_ptr<reffvaluesetfield_entity> reffvaluesetfield_entity_ptr;




    class syntax_atom;
    typedef boost::shared_ptr<syntax_atom> syntax_atom_ptr;
    typedef std::vector<syntax_atom_ptr> syntax_atom_vct;

    class groupsyntax_atom;
    typedef boost::shared_ptr<groupsyntax_atom> groupsyntax_atom_ptr;
    typedef groupsyntax_atom_ptr withsyntax_atom;



    typedef std::vector<std::string> export_vector;
    typedef std::vector<std::string> import_vector;



    void insert_assigment(basic_entity_ptr scope, basic_entity_ptr val);

    void insert_global(basic_entity_ptr global);







    /////////////////////////////////////////////////////////////////////////   
    //  BASIC
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

        voassigment_entity* as_voassigment();

        soassigment_entity* as_soassigment();

        typeassigment_entity* as_typeassigment();

        valueassigment_entity* as_valueassigment();

        valuesetassigment_entity* as_valuesetassigment();

        classassigment_entity* as_classassigment();

        field_entity* as_classfield();

        extention_entity* as_extention();

        std::string source_throw();

        void referenceerror_throw(const std::string& val);

        void unicalelerror_throw(const basic_entity_vector& elms);

        /////

        basic_entity_ptr find(const basic_entity_ptr& reff, bool all = true);

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        virtual void resolve();



    protected:

        virtual void preresolve();

        void resolve_child();

        void prefind(const std::string& nm, basic_entity_vector& elm);

        basic_entity_wptr scope_;
        basic_entity_vector childs_;
        std::string name_;
        entity_enum kind_;


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

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        virtual void resolve();


    protected:

        virtual void preresolve();

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

        value_atom_ptr objectid() const {
            return objectid_;
        }

        void objectid(value_atom_ptr vl) {
            objectid_ = vl;
        }

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        virtual void resolve();


    private:

        import_vector import_;
        value_atom_ptr objectid_;

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

        structvalue_atom_ptr objectid() const {
            return objectid_;
        }

        void objectid(structvalue_atom_ptr vl) {
            objectid_ = vl;
        }

        //////

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        basic_entity_ptr find_in_importmodule(const std::string& mod, const std::string& nm);

        virtual void resolve();

        void preresolve_externalref();

        void preresolve_oid();


    private:


        basic_entity_ptr findmodule(const std::string& nm);

        basic_entity_ptr findmodule(value_atom_ptr oid, const std::string& nm);

        std::vector<std::string> setfrom_objid(value_atom* vls);

        bool compareoid(structvalue_atom_ptr ls, value_atom_ptr rs);


        export_vector exports_;
        basic_entity_vector imports_;
        std::string file_;
        bool allexport_;
        structvalue_atom_ptr objectid_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // expectdef_entity
    /////////////////////////////////////////////////////////////////////////  

    class expectdef_entity : public basic_entity {

    public:

        expectdef_entity(basic_entity_ptr scope, const std::string& nm);

        std::string module() const {
            return module_;
        }

        bool ismodule() const {
            return !module_.empty();
        }


    protected:

        std::string module_;

        void buildreff();


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

        void resolve_reff(bool all = true);

        virtual void resolve();

        virtual void swap_scope(basic_entity_ptr to_, basic_entity_ptr from_ = basic_entity_ptr());


    protected:
        basic_entity_ptr reff_;
        basic_entity_ptr scope_;
    };






    /////////////////////////////////////////////////////////////////////////   
    // TYPE
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

        constraints_atom_vct& constraints() {
            return constraints_;
        }

        void constraints(constraints_atom_vct vl) {
            constraints_ = vl;
        }

        bool has_constraint() const {
            return !constraints_.empty();
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
        void resolve_constraints();

        defined_type builtin_;
        tagged_ptr tag_;
        predefined_ptr predefined_;
        constraints_atom_vct constraints_;

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

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

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

        void _default(value_atom_ptr v) {
            default_ = v;
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
    // VALUE
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

        structvalue_atom* as_objid();

        structvalue_atom* as_valuelist();

        structvalue_atom* as_definedlist();

        structvalue_atom* as_numberlist();

        structvalue_atom* as_list();

        definedvalue_atom* as_defined();

        assignvalue_atom* as_assign();

        choicevalue_atom* as_choice();

        openvalue_atom* as_open();

        nullvalue_atom* as_null();

        emptyvalue_atom* as_empty();


    protected:

        void resolve_vect(value_vct& vl);

        //void swap_scope_vect(value_vct& vl, basic_entity_ptr to_, basic_entity_ptr from_= basic_entity_ptr());

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

        boolvalue_atom(bool vl) : value_atom(basic_entity_ptr(), v_boolean), value_(vl) {
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

        structvalue_atom(value_type tpv, value_vct vls)
        : value_atom(basic_entity_ptr(), tpv), values_(vls) {
        };

        value_vct& values() {
            return values_;
        }

        virtual void resolve();

        //virtual  void swap_scope(basic_entity_ptr to_, basic_entity_ptr from_= basic_entity_ptr());     

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

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        virtual void resolve();


    private:

        type_atom_ptr type_;
        value_atom_ptr value_;
    };







    /////////////////////////////////////////////////////////////////////////   
    // VALUESET
    /////////////////////////////////////////////////////////////////////////   
    // valueset_atom
    /////////////////////////////////////////////////////////////////////////  

    class valueset_atom : public basic_atom {

    public:
        valueset_atom(basic_entity_ptr scope, valueset_type tp);
        valueset_atom(basic_entity_ptr scope, const std::string& reff, valueset_type tp);

        valueset_type builtin() const {
            return builtin_;
        }

        constraints_atom_ptr set() const {
            return set_;
        }

        void set(constraints_atom_ptr vl) {
            set_ = vl;
        }

        virtual void resolve();

    private:

        valueset_type builtin_;
        constraints_atom_ptr set_;

    };




    /////////////////////////////////////////////////////////////////////////   
    // constraints_atom
    /////////////////////////////////////////////////////////////////////////  

    class constraints_atom : public basic_atom {

    public:

        constraints_atom(basic_entity_ptr scp, const std::string& reff) :
        basic_atom(reff, scp) {
        };

        constraints_atom(basic_entity_ptr scp, const constraint_atom_vct& fst, bool ext = false) :
        basic_atom(scp), constraintline_(fst), extend_(ext) {
        };

        constraints_atom(basic_entity_ptr scp, const constraint_atom_vct& fst, const constraint_atom_vct& scd) :
        basic_atom(scp), constraintline_(fst), extendline_(scd), extend_(true) {
        };

        constraint_atom_vct& constraintline() {
            return constraintline_;
        }

        constraint_atom_vct& extendline() {
            return extendline_;
        }

        bool extend() const {
            return (!extendline_.empty()) || extend_;
        }

        void extend(bool val) {
            extend_ = val;
        }

        ////

        virtual void resolve();

    protected:

        constraint_atom_vct constraintline_;
        constraint_atom_vct extendline_;
        bool extend_;

    };




    /////////////////////////////////////////////////////////////////////////   
    // constraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class constraint_atom : public basic_atom {

    public:
        constraint_atom(constraint_type tp = cns_nodef);
        constraint_atom(basic_entity_ptr scp, constraint_type tp);
        constraint_atom(basic_entity_ptr scp, const std::string& reff, constraint_type tp);

        constraint_type cotstrtype() const {
            return cotstrtype_;
        }

        valueconstraint_atom* as_valueconstraint();

        valueconstraint_atom* as_pattern();

        typeconstraint_atom* as_subtypeconstraint();

        typeconstraint_atom* as_typeconstraint();

        rangeconstraint_atom* as_range();

        rangeconstraint_atom* as_strictrange();

        rangeconstraint_atom* as_duration();

        rangeconstraint_atom* as_timepoint();

        rangeconstraint_atom* as_reccurence();

        namedconstraint_atom* as_named();

        complexconstraint_atom* as_complex();

        complexconstraint_atom* as_size();

        complexconstraint_atom* as_permitted();

        complexconstraint_atom* as_singletype();

        multipletypeconstraint_atom * as_multipletypeconstraint();

        stringconstraint_atom * as_property();

        unionconstraint_atom* as_union();

        intersectionconstraint_atom* as_intersection();

        exceptconstraint_atom* as_except();

        allexceptconstraint_atom* as_allexcept();

        extentionconstraint_atom* as_extention();

        exceptionconstraint_atom* as_exception();


    private:

        constraint_type cotstrtype_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // valueconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class valueconstraint_atom : public constraint_atom {

    public:

        valueconstraint_atom(basic_entity_ptr scp, constraint_type tpc, value_atom_ptr vl) : constraint_atom(scp, tpc), value_(vl) {
        };

        value_atom_ptr value() {
            return value_;
        }

        virtual void resolve();

    private:

        value_atom_ptr value_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // typeconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class typeconstraint_atom : public constraint_atom {

    public:

        typeconstraint_atom(basic_entity_ptr scp, constraint_type tpc, type_atom_ptr tp, bool incl) :
        constraint_atom(scp, tpc), type_(tp), includes_(incl) {
        };

        type_atom_ptr type() {
            return type_;
        }

        bool includdes() {
            return includes_;
        }

        virtual void resolve();

    private:

        type_atom_ptr type_;
        bool includes_;

    };



    /////////////////////////////////////////////////////////////////////////   
    // stringconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class stringconstraint_atom : public constraint_atom {

    public:

        stringconstraint_atom(basic_entity_ptr scp, constraint_type tpc, const std::string& prop) :
        constraint_atom(scp, tpc), property_(prop) {
        };

        std::string property() {
            return property_;
        }

    private:

        std::string property_;


    };


    /////////////////////////////////////////////////////////////////////////   
    // rangeconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class rangeconstraint_atom : public constraint_atom {

    public:

        rangeconstraint_atom(basic_entity_ptr scp, constraint_type tpc, value_atom_ptr fr, range_type frtp, value_atom_ptr to, range_type totp) :
        constraint_atom(scp, tpc), from_(fr), fromtype_(frtp), to_(to), totype_(totp) {
        };

        value_atom_ptr from() {
            return from_;
        }

        range_type fromtype() {
            return fromtype_;
        }

        value_atom_ptr to() {
            return to_;
        }

        range_type totype() {
            return totype_;
        }

        virtual void resolve();

    private:

        value_atom_ptr from_;
        range_type fromtype_;
        value_atom_ptr to_;
        range_type totype_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // namedconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class namedconstraint_atom : public constraint_atom {

    public:

        namedconstraint_atom(basic_entity_ptr scp, const std::string& nm, constraints_atom_ptr ctrs, constraintmarker_type mrkr = cmk_none) :
        constraint_atom(scp, cns_NamedConstraint), name_(nm), constraints_(ctrs), marker_(mrkr) {
        };

        namedconstraint_atom(basic_entity_ptr scp, const std::string& nm, constraintmarker_type mrkr = cmk_none) :
        constraint_atom(scp, cns_NamedConstraint), name_(nm), marker_(mrkr) {
        };

        std::string name() {
            return name_;
        }

        constraints_atom_ptr constraints() {
            return constraints_;
        }

        constraintmarker_type marker() {
            return marker_;
        }

        virtual void resolve();

    private:

        std::string name_;
        constraints_atom_ptr constraints_;
        constraintmarker_type marker_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // multipletypeconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class multipletypeconstraint_atom : public constraint_atom {

    public:

        multipletypeconstraint_atom(basic_entity_ptr scp, const constraint_atom_vct& fst) :
        constraint_atom(scp, cns_MultipleTypeConstraints), components_(fst) {
        };

        constraint_atom_vct& components() {
            return components_;
        }

        bool full() const;

        virtual void resolve();


    protected:

        constraint_atom_vct components_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // complexconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class complexconstraint_atom : public constraint_atom {

    public:

        complexconstraint_atom(basic_entity_ptr scp, constraint_type tpc, constraints_atom_ptr ctrs) :
        constraint_atom(scp, tpc), constraints_(ctrs) {
        };

        constraints_atom_ptr constraints() {
            return constraints_;
        }

        virtual void resolve();


    private:

        constraints_atom_ptr constraints_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // unionconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class unionconstraint_atom : public constraint_atom {

    public:

        unionconstraint_atom() : constraint_atom(cns_UNION) {
        }
    };




    /////////////////////////////////////////////////////////////////////////   
    // intersectionconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class intersectionconstraint_atom : public constraint_atom {

    public:

        intersectionconstraint_atom() : constraint_atom(cns_INTERSECTION) {
        }
    };


    /////////////////////////////////////////////////////////////////////////   
    // exceptconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class exceptconstraint_atom : public constraint_atom {

    public:

        exceptconstraint_atom() : constraint_atom(cns_EXCEPT) {
        }
    };


    /////////////////////////////////////////////////////////////////////////   
    // allexceptconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class allexceptconstraint_atom : public constraint_atom {

    public:

        allexceptconstraint_atom() : constraint_atom(cns_ALLEXCEPT) {
        }
    };


    /////////////////////////////////////////////////////////////////////////   
    // exceptconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class extentionconstraint_atom : public constraint_atom {

    public:

        extentionconstraint_atom() : constraint_atom(cns_EXTENTION) {
        }
    };


    /////////////////////////////////////////////////////////////////////////   
    // allexceptconstraint_atom
    /////////////////////////////////////////////////////////////////////////  

    class exceptionconstraint_atom : public constraint_atom {

    public:

        exceptionconstraint_atom() : constraint_atom(cns_EXCEPTION) {
        }
    };



    /////////////////////////////////////////////////////////////////////////   
    // valuesetassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class valuesetassigment_entity : public basic_entity {

    public:
        valuesetassigment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, valueset_atom_ptr vl);

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        valueset_atom_ptr valueset() const {
            return valueset_;
        }

        void valueset(valueset_atom_ptr vl) {
            valueset_ = vl;
        }


        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        virtual void resolve();


    private:

        type_atom_ptr type_;
        valueset_atom_ptr valueset_;
    };







    /////////////////////////////////////////////////////////////////////////   
    // CLASS
    /////////////////////////////////////////////////////////////////////////    
    // field_entity
    /////////////////////////////////////////////////////////////////////////

    class field_entity : public basic_entity {

    public:
        field_entity(basic_entity_ptr scope, const std::string& nm, fieldkind_type tp, tagmarker_type mkr = mk_none);

        fieldkind_type fieldkind() const {
            return fieldkind_;
        }

        void fieldkind(fieldkind_type vl) {
            fieldkind_ = vl;
        }

        tagmarker_type marker() const {
            return marker_;
        }

        void marker(tagmarker_type vl) {
            marker_ = vl;
        }

        typefield_entity* as_typefield();

        valuefield_entity* as_valuefield();

        valuesetfield_entity* as_valuesetfield();

        reffvaluefield_entity* as_reffvaluefield();

        reffvaluesetfield_entity* as_reffvaluesetfield();


    protected:
        fieldkind_type fieldkind_;
        tagmarker_type marker_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // typefield_entity
    /////////////////////////////////////////////////////////////////////////  

    class typefield_entity : public field_entity {

    public:

        typefield_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr dflt) :
        field_entity(scope, nm, fkind_TypeFieldSpec, mk_default), default_(dflt) {
        };

        typefield_entity(basic_entity_ptr scope, const std::string& nm, tagmarker_type mkr = mk_none) :
        field_entity(scope, nm, fkind_TypeFieldSpec, mkr) {
        };

        type_atom_ptr _default() const {
            return default_;
        }

        void _default(type_atom_ptr vl) {
            default_ = vl;
        }

        //         

        virtual void resolve();

    protected:
        type_atom_ptr default_;
    };

    /////////////////////////////////////////////////////////////////////////   
    // valuefield_entity
    /////////////////////////////////////////////////////////////////////////  

    class valuefield_entity : public field_entity {

    public:

        valuefield_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, value_atom_ptr dflt) :
        field_entity(scope, nm, fkind_FixedTypeValueFieldSpec, mk_default), type_(tp), default_(dflt), unique_(false) {
        };

        valuefield_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, bool unic, tagmarker_type mkr = mk_none) :
        field_entity(scope, nm, fkind_FixedTypeValueFieldSpec, mkr), type_(tp), unique_(unic) {
        };

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        value_atom_ptr _default() const {
            return default_;
        }

        void _default(value_atom_ptr vl) {
            default_ = vl;
        }

        bool unique() const {
            return unique_;
        }

        void unique(bool vl) {
            unique_ = vl;
        }

        //         

        virtual void resolve();

    protected:
        type_atom_ptr type_;
        value_atom_ptr default_;
        bool unique_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // valuesetfield_entity
    /////////////////////////////////////////////////////////////////////////  

    class valuesetfield_entity : public field_entity {

    public:

        valuesetfield_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, valueset_atom_ptr dflt) :
        field_entity(scope, nm, fkind_FixedTypeValueSetFieldSpec, mk_default), type_(tp), default_(dflt) {
        };

        valuesetfield_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, tagmarker_type mkr = mk_none) :
        field_entity(scope, nm, fkind_FixedTypeValueSetFieldSpec, mkr), type_(tp) {
        };

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        valueset_atom_ptr _default() const {
            return default_;
        }

        void _default(valueset_atom_ptr vl) {
            default_ = vl;
        }



        //         

        virtual void resolve();

    protected:
        type_atom_ptr type_;
        valueset_atom_ptr default_;
    };




    /////////////////////////////////////////////////////////////////////////   
    // reffvaluefield_entity
    /////////////////////////////////////////////////////////////////////////  

    class reffvaluefield_entity : public field_entity {

    public:

        reffvaluefield_entity(basic_entity_ptr scope, const std::string& nm, const std::string& reff, value_atom_ptr dflt) :
        field_entity(scope, nm, fkind_VariableTypeValueFieldSpec, mk_default), field_(new basic_atom(reff, scope)), default_(dflt) {
        };

        reffvaluefield_entity(basic_entity_ptr scope, const std::string& nm, const std::string& reff, tagmarker_type mkr = mk_none) :
        field_entity(scope, nm, fkind_VariableTypeValueFieldSpec, mkr), field_(new basic_atom(reff, scope)) {
        };

        basic_atom_ptr field() const {
            return field_;
        }

        void field(basic_atom_ptr vl) {
            field_ = vl;
        }

        value_atom_ptr _default() const {
            return default_;
        }

        void _default(value_atom_ptr vl) {
            default_ = vl;
        }

        //         

        virtual void resolve();

    protected:
        basic_atom_ptr field_;
        value_atom_ptr default_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // reffvaluesetfield_entity
    /////////////////////////////////////////////////////////////////////////  

    class reffvaluesetfield_entity : public field_entity {

    public:

        reffvaluesetfield_entity(basic_entity_ptr scope, const std::string& nm, const std::string& reff, valueset_atom_ptr dflt) :
        field_entity(scope, nm, fkind_VariableTypeValueSetFieldSpec, mk_default), field_(new basic_atom(reff, scope)), default_(dflt) {
        };

        reffvaluesetfield_entity(basic_entity_ptr scope, const std::string& nm, const std::string& reff, tagmarker_type mkr = mk_none) :
        field_entity(scope, nm, fkind_VariableTypeValueSetFieldSpec, mkr), field_(new basic_atom(reff, scope)) {
        };

        basic_atom_ptr field() const {
            return field_;
        }

        void field(basic_atom_ptr vl) {
            field_ = vl;
        }

        valueset_atom_ptr _default() const {
            return default_;
        }

        void _default(valueset_atom_ptr vl) {
            default_ = vl;
        }



        //         

        virtual void resolve();

    protected:
        basic_atom_ptr field_;
        valueset_atom_ptr default_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // syntax_atom
    /////////////////////////////////////////////////////////////////////////  

    class syntax_atom : public basic_atom {

    public:

        syntax_atom(basic_entity_ptr scope, std::string als, bool opt) :
        basic_atom(scope), alias_(als), optional_(opt) {
        }

        syntax_atom(basic_entity_ptr scope, std::string als, const std::string& field, bool opt) :
        basic_atom(field, scope), alias_(als), optional_(opt) {
        }

        bool optional() const {
            return optional_;
        }

        std::string alias() const {
            return alias_;
        }

        bool isalias() const {
            return !alias_.empty();
        }

        groupsyntax_atom* as_group();



        //         

        virtual void resolve();

    private:
        std::string alias_;
        bool optional_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // groupsyntax_atom
    /////////////////////////////////////////////////////////////////////////  

    class groupsyntax_atom : public syntax_atom {

    public:

        groupsyntax_atom(basic_entity_ptr scope, std::string als, syntax_atom_vct grp, bool opt) :
        syntax_atom(scope, als, opt), group_(grp) {
        }

        syntax_atom_vct& group() {
            return group_;
        }

        void group(syntax_atom_vct vl) {
            group_ = vl;
        }

        //         

        virtual void resolve();

    private:

        syntax_atom_vct group_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // class_atom
    /////////////////////////////////////////////////////////////////////////  

    class class_atom : public basic_atom {

    public:
        class_atom(basic_entity_ptr scope, definedclass_type tp);
        class_atom(basic_entity_ptr scope, const std::string& reff, definedclass_type tp);

        definedclass_type builtin() const {
            return builtin_;
        }

        virtual void resolve();

    private:

        definedclass_type builtin_;

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

        withsyntax_atom withsyntax() const {
            return withsyntax_;
        }

        void withsyntax(withsyntax_atom vl) {
            withsyntax_ = vl;
        }

        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        virtual void resolve();

    private:

        class_atom_ptr class_;
        withsyntax_atom withsyntax_;
    };






    /////////////////////////////////////////////////////////////////////////   
    // BIG
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

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        virtual void resolve() {
        };


    private:

        basic_atom_ptr big_;
    };






    /////////////////////////////////////////////////////////////////////////   
    // VALUE OR OBJECT
    /////////////////////////////////////////////////////////////////////////     
    // voassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class voassigment_entity : public basic_entity {

    public:
        voassigment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg);

        basic_atom_ptr big() const {
            return big_;
        }

        void big(type_atom_ptr vl) {
            big_ = vl;
        }

        value_atom_ptr value() const {
            return value_;
        }

        void value(value_atom_ptr vl) {
            value_ = vl;
        }

        basic_atom_ptr object() const {
            return object_;
        }

        void object(basic_atom_ptr vl) {
            object_ = vl;
        }


        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        virtual void resolve() {
        };


    private:

        basic_atom_ptr big_;
        value_atom_ptr value_;
        basic_atom_ptr object_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // VALUESET OR OBJECTSET
    /////////////////////////////////////////////////////////////////////////     
    // soassigment_entity
    /////////////////////////////////////////////////////////////////////////  

    class soassigment_entity : public basic_entity {

    public:
        soassigment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg);

        basic_atom_ptr big() const {
            return big_;
        }

        void big(type_atom_ptr vl) {
            big_ = vl;
        }

        valueset_atom_ptr valueset() const {
            return valueset_;
        }

        void valueset(valueset_atom_ptr vl) {
            valueset_ = vl;
        }

        basic_atom_ptr objectset() const {
            return objectset_;
        }

        void objectset(basic_atom_ptr vl) {
            objectset_ = vl;
        }


        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, bool all = true);

        virtual void resolve() {
        };


    private:

        basic_atom_ptr big_;
        valueset_atom_ptr valueset_;
        basic_atom_ptr objectset_;
    };




    /////////////////////////////////////////////////////////////////////////   
    // RESOLVE
    /////////////////////////////////////////////////////////////////////////    
    // resolve functions
    /////////////////////////////////////////////////////////////////////////  

    void preresolve_assigments(basic_entity_vector& elm);
    basic_entity_ptr preresolve_nodef_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
    basic_entity_ptr preresolve_nodef_assigment(basic_entity* elm, basic_entity* start = 0);
    basic_entity_ptr preresolve_nodefv_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
    basic_entity_ptr preresolve_nodefv_assigment(basic_entity* elm, basic_entity* start = 0);
    basic_entity_ptr preresolve_nodefs_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
    basic_entity_ptr preresolve_nodefs_assigment(basic_entity* elm, basic_entity* start = 0);

    void resolve_assigments(basic_entity_vector& elm);
    void resolve_assigment(basic_entity_ptr& elm, basic_entity_ptr start = basic_entity_ptr());
    void resolve_type_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
    void resolve_type_assigment(basic_entity* elm, basic_entity* start = 0);
    void resolve_value_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
    void resolve_value_assigment(basic_entity* elm, basic_entity* start = 0);
    void resolve_class_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
    void resolve_class_assigment(basic_entity* elm, basic_entity* start = 0);



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
        // COMPILE
        /////////////////////////////////////////////////////////////////////////   
        // precomile modules
        /////////////////////////////////////////////////////////////////////////          

        global_entity_ptr compile_fs(const std::string& path, const std::string& ext = "asn");

        void compile_module(const x680::syntactic::module& mod, global_entity_ptr global);
        void compile_export(const x680::syntactic::module& mod, module_entity_ptr mdl);
        void compile_imports(const x680::syntactic::module& mod, module_entity_ptr mdl);
        basic_entity_ptr compile_import(const x680::syntactic::import& imp, module_entity_ptr mdl);
        void compile_assignments(const x680::syntactic::module& mod, module_entity_ptr mdl);
        basic_entity_ptr compile_assignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        // type
        typeassigment_entity_ptr compile_typeassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        basic_entity_vector compile_structtype(basic_entity_ptr scope, const x680::syntactic::type_element& ent);
        typeassigment_entity_ptr compile_namedtype(basic_entity_ptr scope, const x680::syntactic::type_assignment& ent);
        type_atom_ptr compile_type(basic_entity_ptr scope, const x680::syntactic::type_element& ent);
        predefined_ptr compile_typepredef(basic_entity_ptr scope, const x680::syntactic::type_element& ent);
        tagged_ptr compile_tag(basic_entity_ptr scope, const x680::syntactic::tag_type& ent);
        // value
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
        // valueset
        valuesetassigment_entity_ptr compile_valuesetassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        valueset_atom_ptr compile_valueset(basic_entity_ptr scope, const x680::syntactic::valueset_element& ent);
        constraints_atom_vct compile_constraints_vct(basic_entity_ptr scope, const x680::syntactic::constraints_vector& ent);
        constraints_atom_ptr compile_constraints(basic_entity_ptr scope, const x680::syntactic::constraint_element_vector& ent);
        constraint_atom_ptr compile_constraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent);
        constraint_atom_ptr compile_namedconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent);
        constraint_atom_ptr compile_multipletypeconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent);
        // class
        classassigment_entity_ptr compile_classassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        basic_entity_vector compile_classfields(basic_entity_ptr scope, const x680::syntactic::class_element& ent);
        basic_entity_ptr compile_typeclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_valueclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_valuesetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_reffvalueclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_reffvaluesetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        withsyntax_atom compile_withsyntax(basic_entity_ptr scope, const x680::syntactic::classsyntax_vector& ent);
        syntax_atom_vct compile_groupwithsyntax(basic_entity_ptr scope, const x680::syntactic::classsyntax_vector& ent);
        // big
        bigassigment_entity_ptr compile_bigassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        // value or object
        voassigment_entity_ptr compile_voassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        // valueset or objectset
        soassigment_entity_ptr compile_soassignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        // reff
        basic_atom_ptr compile_reff(const std::string& rf);



    }






    /////////////////////////////////////////////////////////////////////////   
    // COUT
    /////////////////////////////////////////////////////////////////////////   
    // std::cout  tree
    /////////////////////////////////////////////////////////////////////////          


    std::ostream& operator<<(std::ostream& stream, global_entity* self);
    std::ostream& operator<<(std::ostream& stream, module_entity* self);
    std::ostream& operator<<(std::ostream& stream, import_entity* self);
    std::ostream& operator<<(std::ostream& stream, expectdef_entity* self);
    std::ostream& operator<<(std::ostream& stream, extention_entity* self);
    std::ostream& operator<<(std::ostream& stream, basic_atom* self);

    // type
    std::ostream& operator<<(std::ostream& stream, typeassigment_entity* self);
    std::ostream& operatorstruct(std::ostream& stream, typeassigment_entity* self);
    std::ostream& operator<<(std::ostream& stream, tagmarker_type self);
    std::ostream& operator<<(std::ostream& stream, predefined* self);
    std::ostream& operator<<(std::ostream& stream, tagclass_type self);
    std::ostream& operator<<(std::ostream& stream, tagrule_type self);
    std::ostream& operator<<(std::ostream& stream, tagged& self);
    std::ostream& operator<<(std::ostream& stream, type_atom* self);
    //value
    std::ostream& operator<<(std::ostream& stream, valueassigment_entity* self);
    std::ostream& operator<<(std::ostream& stream, defined_type self);
    std::ostream& operator<<(std::ostream& stream, value_atom* self);
    std::ostream& operator<<(std::ostream& stream, numvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, realvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, boolvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, strvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, namedvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, structvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, definedvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, assignvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, choicevalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, openvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, nullvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, emptyvalue_atom* self);
    // valueset
    std::ostream& operator<<(std::ostream& stream, valuesetassigment_entity* self);
    std::ostream& operator<<(std::ostream& stream, valueset_atom* self);
    std::ostream& operator<<(std::ostream& stream, const constraints_atom_vct& self);
    std::ostream& operator<<(std::ostream& stream, constraints_atom* self);
    std::ostream& operator<<(std::ostream& stream, const constraint_atom_vct& self);
    std::ostream& operator<<(std::ostream& stream, constraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, valueconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, typeconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, rangeconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, namedconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, constraintmarker_type tp);
    std::ostream& operator<<(std::ostream& stream, range_type tp);
    std::ostream& operator<<(std::ostream& stream, complexconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, multipletypeconstraint_atom * self);
    // class
    std::ostream& operator<<(std::ostream& stream, classassigment_entity* self);
    std::ostream& operator<<(std::ostream& stream, class_atom* self);
    std::ostream& operator<<(std::ostream& stream, definedclass_type self);
    std::ostream& operator<<(std::ostream& stream, fieldkind_type self);
    std::ostream& operator<<(std::ostream& stream, field_entity* self);
    std::ostream& operator<<(std::ostream& stream, typefield_entity* self);
    std::ostream& operator<<(std::ostream& stream, valuefield_entity* self);
    std::ostream& operator<<(std::ostream& stream, valuesetfield_entity* self);
    std::ostream& operator<<(std::ostream& stream, reffvaluefield_entity* self);
    std::ostream& operator<<(std::ostream& stream, reffvaluesetfield_entity* self);
    std::ostream& operator<<(std::ostream& stream, syntax_atom* self);
    std::ostream& operator<<(std::ostream& stream, groupsyntax_atom* self);
    // big
    std::ostream& operator<<(std::ostream& stream, bigassigment_entity* self);
    // value or object
    std::ostream& operator<<(std::ostream& stream, voassigment_entity* self);
    // valueset or objectset
    std::ostream& operator<<(std::ostream& stream, soassigment_entity* self);
    //little
    std::ostream& operator<<(std::ostream& stream, voassigment_entity* self);


}

#endif	

