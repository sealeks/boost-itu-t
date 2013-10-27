//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1_SEM_ASSIGNMENT_IMPLEMENTATIUON_H_
#define	_ITU_ASN1_SEM_ASSIGNMENT_IMPLEMENTATIUON_H_


#include <boost/itu/x68X/x680.hpp>
#include <boost/enable_shared_from_this.hpp>

#define  DEBUG_SEMANTIC

namespace x680 {


    typedef int search_marker;

    const search_marker local_search = 0x1;
    const search_marker extend_search = 0x2;
    const search_marker full_search = 0x3;

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
        et_Argument,
        et_UArgument,
        et_Extention
    };

    enum argument_enum {

        argm_Nodef,
        argm_Type,
        argm_Value,
        argm_ValueSet,
        argm_Class,
        argm_Object,
        argm_ObjectSet
    };




    class basic_entity;
    typedef boost::shared_ptr<basic_entity> basic_entity_ptr;
    typedef boost::weak_ptr<basic_entity> basic_entity_wptr;
    typedef std::vector<basic_entity_ptr> basic_entity_vector;

    class expectdef_entity;
    typedef boost::shared_ptr<expectdef_entity> expectdef_entity_ptr;


    class argument_entity;
    typedef boost::shared_ptr<argument_entity> argument_entity_ptr;
    typedef std::vector<argument_entity_ptr> argument_entity_vct;

    class uargument_entity;
    typedef boost::shared_ptr<uargument_entity> uargument_entity_ptr;
    typedef std::vector<uargument_entity_ptr> uargument_entity_vct;

    class global_entity;
    typedef boost::shared_ptr<global_entity> global_entity_ptr;

    class import_entity;
    typedef boost::shared_ptr<import_entity> import_entity_ptr;

    class module_entity;
    typedef boost::shared_ptr<module_entity> module_entity_ptr;

    class assignment_entity;
    typedef boost::shared_ptr<assignment_entity> assignment_entity_ptr;

    class bigassignment_entity;
    typedef boost::shared_ptr<bigassignment_entity> bigassignment_entity_ptr;

    class typeassignment_entity;
    typedef boost::shared_ptr<typeassignment_entity> typeassignment_entity_ptr;

    class namedtypeassignment_entity;
    typedef boost::shared_ptr<namedtypeassignment_entity> namedtypeassignment_entity_ptr;
    typedef std::vector<namedtypeassignment_entity_ptr> namedtypeassignment_entity_vct;

    class valueassignment_entity;
    typedef boost::shared_ptr<valueassignment_entity> valueassignment_entity_ptr;
    typedef std::vector<valueassignment_entity_ptr> valueassignment_entity_vct;

    class valuesetassignment_entity;
    typedef boost::shared_ptr<valuesetassignment_entity> valuesetassignment_entity_ptr;

    class classassignment_entity;
    typedef boost::shared_ptr<classassignment_entity> classassignment_entity_ptr;

    class objectassignment_entity;
    typedef boost::shared_ptr<objectassignment_entity> objectassignment_entity_ptr;

    class objectsetassignment_entity;
    typedef boost::shared_ptr<objectsetassignment_entity> objectsetassignment_entity_ptr;

    class extention_entity;
    typedef boost::shared_ptr<extention_entity> extention_entity_ptr;

    class voassignment_entity;
    typedef boost::shared_ptr<voassignment_entity> voassignment_entity_ptr;

    class soassignment_entity;
    typedef boost::shared_ptr<soassignment_entity> soassignment_entity_ptr;



    class basic_atom;
    typedef boost::shared_ptr<basic_atom> basic_atom_ptr;
    typedef std::vector<basic_atom_ptr> basic_atom_vct;

    class setting_atom;
    typedef boost::shared_ptr<setting_atom> setting_atom_ptr;
    typedef std::vector<setting_atom_ptr> setting_atom_vct;



    class predefined;
    typedef boost::shared_ptr<predefined> predefined_ptr;

    class tagged;
    typedef boost::shared_ptr<tagged> tagged_ptr;

    class type_atom;
    typedef boost::shared_ptr<type_atom> type_atom_ptr;

    class classfieldtype_atom;
    typedef boost::shared_ptr<classfieldtype_atom> classfieldtype_atom_ptr;

    class instanceoftype_atom;
    typedef boost::shared_ptr<instanceoftype_atom> instanceoftype_atom_ptr;

    class fromobjecttype_atom;
    typedef boost::shared_ptr<fromobjecttype_atom> fromobjecttype_atom_ptr;

    class fromobjectsettype_atom;
    typedef boost::shared_ptr<fromobjectsettype_atom> fromobjectsettype_atom_ptr;


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

    class fromobjectvalue_atom;
    typedef boost::shared_ptr<fromobjectvalue_atom> fromobjectvalue_atom_ptr;

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

    class fromobjectvalueset_atom;
    typedef boost::shared_ptr<fromobjectvalueset_atom> fromobjectvalueset_atom_ptr;

    class fromobjectsetvalueset_atom;
    typedef boost::shared_ptr<fromobjectsetvalueset_atom> fromobjectsetvalueset_atom_ptr;

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

    class fromdefinedsetconstraint_atom;
    typedef boost::shared_ptr<fromdefinedsetconstraint_atom> fromdefinedsetconstraint_atom_ptr;

    class fromdefinedconstraint_atom;
    typedef boost::shared_ptr<fromdefinedconstraint_atom> fromdefinedconstraint_atom_ptr;

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

    class userconstraint_atom;
    typedef boost::shared_ptr<userconstraint_atom> userconstraint_atom_ptr;

    class contentconstraint_atom;
    typedef boost::shared_ptr<contentconstraint_atom> contentconstraint_atom_ptr;

    class relationconstraint_atom;
    typedef boost::shared_ptr<relationconstraint_atom> relationconstraint_atom_ptr;

    class tableconstraint_atom;
    typedef boost::shared_ptr<tableconstraint_atom> tableconstraint_atom_ptr;

    class tvosoconstraint_atom;
    typedef boost::shared_ptr<tvosoconstraint_atom> tvosoconstraint_atom_ptr;

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

    class objectfield_entity;
    typedef boost::shared_ptr<objectfield_entity> objectfield_entity_ptr;

    class objectsetfield_entity;
    typedef boost::shared_ptr<objectsetfield_entity> objectsetfield_entity_ptr;

    class undeffield_entity;
    typedef boost::shared_ptr<undeffield_entity> undeffield_entity_ptr;

    class undefsetfield_entity;
    typedef boost::shared_ptr<undefsetfield_entity> undefsetfield_entity_ptr;



    class syntax_atom;
    typedef boost::shared_ptr<syntax_atom> syntax_atom_ptr;
    typedef std::vector<syntax_atom_ptr> syntax_atom_vct;

    class groupsyntax_atom;
    typedef boost::shared_ptr<groupsyntax_atom> groupsyntax_atom_ptr;
    typedef groupsyntax_atom_ptr withsyntax_atom;




    class fieldsetting_atom;
    typedef boost::shared_ptr<fieldsetting_atom> fieldsetting_atom_ptr;
    typedef std::vector<fieldsetting_atom_ptr> fieldsetting_atom_vct;

    class object_atom;
    typedef boost::shared_ptr<object_atom> object_atom_ptr;
    typedef std::vector<object_atom_ptr> object_atom_vct;

    class definedobject_atom;
    typedef boost::shared_ptr<definedobject_atom> definedobject_atom_ptr;

    class definedsetobject_atom;
    typedef boost::shared_ptr<definedsetobject_atom> definedsetobject_atom_ptr;

    class fromdefinedsetobject_atom;
    typedef boost::shared_ptr<fromdefinedsetobject_atom> fromdefinedsetobject_atom_ptr;

    class fromdefinedobject_atom;
    typedef boost::shared_ptr<fromdefinedobject_atom> fromdefinedobject_atom_ptr;

    class defltobject_atom;
    typedef boost::shared_ptr<defltobject_atom> defltobject_atom_ptr;

    class defsyntxobject_atom;
    typedef boost::shared_ptr<defsyntxobject_atom> defsyntxobject_atom_ptr;

    class fromobjectobject_atom;
    typedef boost::shared_ptr<fromobjectobject_atom> fromobjectobject_atom_ptr;

    class unionobject_atom;
    typedef boost::shared_ptr<unionobject_atom> unionobject_atom_ptr;

    class intersectionobject_atom;
    typedef boost::shared_ptr<intersectionobject_atom> intersectionobject_atom_ptr;

    class exceptobject_atom;
    typedef boost::shared_ptr<exceptobject_atom> exceptobject_atom_ptr;

    class allexceptobject_atom;
    typedef boost::shared_ptr<allexceptobject_atom> allexceptobject_atom_ptr;

    class exceptobject_atom;
    typedef boost::shared_ptr<exceptobject_atom> exceptobject_atom_ptr;

    class allexceptobject_atom;
    typedef boost::shared_ptr<allexceptobject_atom> allexceptobject_atom_ptr;

    class extentionobject_atom;
    typedef boost::shared_ptr<extentionobject_atom> extentionobject_atom_ptr;



    class objectset_atom;
    typedef boost::shared_ptr<objectset_atom> objectset_atom_ptr;

    class fromobjectobjectset_atom;
    typedef boost::shared_ptr<fromobjectobjectset_atom> fromobjectobjectset_atom_ptr;

    class fromobjectsetobjectset_atom;
    typedef boost::shared_ptr<fromobjectsetobjectset_atom> fromobjectsetobjectset_atom_ptr;

    class definedobjectset_atom;
    typedef boost::shared_ptr<definedobjectset_atom> definedobjectset_atom_ptr;

    class defnobjectset_atom;
    typedef boost::shared_ptr<defnobjectset_atom> defnobjectset_atom_ptr;



    typedef std::vector<std::string> export_vector;
    typedef std::vector<std::string> import_vector;



    void debug_warning(const std::string& msg);

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

        basic_entity(entity_enum tp, basic_entity_ptr scope = basic_entity_ptr())
        : scope_(scope), kind_(tp) {
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

        void scope(basic_entity_ptr vl);

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

        assignment_entity* as_assigment();

        argument_entity* as_argument();

        uargument_entity* as_uargument();

        bigassignment_entity* as_bigassigment();

        voassignment_entity* as_voassigment();

        soassignment_entity* as_soassigment();

        typeassignment_entity* as_typeassigment();

        valueassignment_entity* as_valueassigment();

        valuesetassignment_entity* as_valuesetassigment();

        classassignment_entity* as_classassigment();

        objectassignment_entity * as_objectassigment();

        objectsetassignment_entity * as_objectsetassigment();

        field_entity* as_classfield();

        extention_entity* as_extention();

        std::string source_throw();

        void referenceerror_throw(const std::string& val, const std::string& msg = "Unknown reference :");

        void unicalelerror_throw(const basic_entity_vector& elms);

        /////

        basic_entity_ptr find(const basic_entity_ptr& reff, search_marker sch = full_search);

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual void preresolve();

    protected:

        void resolve_child();

        void prefind(const std::string& nm, basic_entity_vector& elm);

        basic_entity_wptr scope_;
        basic_entity_vector childs_;
        std::string name_;
        entity_enum kind_;


    };





    /////////////////////////////////////////////////////////////////////////   
    // assignment_entity
    /////////////////////////////////////////////////////////////////////////  


    /////////////////////////////////////////////////////////////////////////   
    // global_entity
    /////////////////////////////////////////////////////////////////////////  

    class global_entity : public basic_entity {

    public:

        global_entity();

        //////

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual void preresolve();

        void apply_fields();

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

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());


    private:

        import_vector import_;
        value_atom_ptr objectid_;

    };





    /////////////////////////////////////////////////////////////////////////   
    // module_entity
    /////////////////////////////////////////////////////////////////////////  

    class module_entity : public basic_entity {

        friend class basic_entity;

    public:
        module_entity(basic_entity_ptr scope, const std::string& nm,
                const std::string& fl, bool allexp, tagrule_type tgr, bool ext);

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

        bool extesibility_implied() const {
            return extesibility_implied_;
        }

        tagrule_type tagrule() const {
            return tagrule_;
        }

        structvalue_atom_ptr objectid() const {
            return objectid_;
        }

        void objectid(structvalue_atom_ptr vl) {
            objectid_ = vl;
        }

        //////

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        basic_entity_ptr find_in_importmodule(const std::string& mod, const std::string& nm);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual void preresolve();

        void preresolve_externalref();

        void preresolve_oid();

        void apply_fields();

    private:

        basic_entity_ptr findmodule(const std::string& nm);

        basic_entity_ptr findmodule(value_atom_ptr oid, const std::string& nm);

        std::vector<std::string> setfrom_objid(value_atom* vls);

        bool compareoid(structvalue_atom_ptr ls, value_atom_ptr rs);

        static void preresolve_assigments(basic_entity_vector& elm);
        static basic_entity_ptr preresolve_nodef_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
        static basic_entity_ptr preresolve_nodefv_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());
        static basic_entity_ptr preresolve_nodefs_assigment(basic_entity_ptr elm, basic_entity_ptr start = basic_entity_ptr());


        export_vector exports_;
        basic_entity_vector imports_;
        std::string file_;
        bool allexport_;
        bool extesibility_implied_;
        structvalue_atom_ptr objectid_;
        tagrule_type tagrule_;
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
    // argument_entity
    /////////////////////////////////////////////////////////////////////////  

    class argument_entity : public basic_entity {

    public:

        argument_entity(basic_entity_ptr scope, const std::string& nm, argumentsize_type tp);
        argument_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr gvnr, argumentsize_type tp);
        argument_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr gvnr, argumentsize_type tp);
        argument_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr gvnr, argumentsize_type tp);

        basic_atom_ptr governor() const {
            return governor_;
        }

        bool has_governor() const {
            return governor_;
        }

        bool has_undef_governor() const;

        void governor(type_atom_ptr vl);

        void governor(class_atom_ptr vl);

        void governor(basic_atom_ptr vl);

        argument_enum argumenttype() const {
            return argumenttype_;
        }

        assignment_entity_ptr unspecified() const {
            return unspecified_;
        }

        std::size_t reffcount() {
            return dummyrefferences_.size();
        }

        void insert_dummyrefference(basic_atom_ptr val);

        ///

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        basic_atom_ptr governor_;
        argumentsize_type typesize_;
        assignment_entity_ptr unspecified_;
        basic_atom_vct dummyrefferences_;
        argument_enum argumenttype_;

    };



    /////////////////////////////////////////////////////////////////////////   
    // uargument_entity
    /////////////////////////////////////////////////////////////////////////  

    class uargument_entity : public basic_entity {

    public:

        uargument_entity(basic_entity_ptr scope, setting_atom_ptr st);
        uargument_entity(basic_entity_ptr scope, type_atom_ptr gvnr);
        uargument_entity(basic_entity_ptr scope, class_atom_ptr gvnr);
        uargument_entity(basic_entity_ptr scope, basic_atom_ptr gvnr);

        basic_atom_ptr governor() const {
            return governor_;
        }

        bool has_governor() const {
            return governor_;
        }


        bool has_undef_governor() const;

        void governor(type_atom_ptr vl);

        void governor(class_atom_ptr vl);

        void governor(basic_atom_ptr vl);

        setting_atom_ptr setting() const {
            return setting_;
        }

        void setting(setting_atom_ptr vl) {
            setting_ = vl;
        }

        basic_atom_ptr parameter() const {
            return parameter_;
        }

        void parameter(basic_atom_ptr vl) {
            parameter_ = vl;
        }


        ///

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        basic_atom_ptr governor_;
        setting_atom_ptr setting_;
        basic_atom_ptr parameter_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // extention_entity
    /////////////////////////////////////////////////////////////////////////  

    class extention_entity : public basic_entity {

    public:

        extention_entity() : basic_entity(et_Extention) {
        };
    };


    /////////////////////////////////////////////////////////////////////////   
    // basic_atom
    /////////////////////////////////////////////////////////////////////////  

    class basic_atom : public boost::enable_shared_from_this<basic_atom> {

    public:

        typedef boost::shared_ptr<basic_atom> self_shared_type;

        basic_atom(basic_entity_ptr scp = basic_entity_ptr());
        basic_atom(const std::string& reff, basic_entity_ptr scp = basic_entity_ptr());

        virtual ~basic_atom() {
        }

        basic_entity_ptr scope() const {
            return scope_;
        }

        void scope(basic_entity_ptr vl) {
            scope_ = vl;
        }

        self_shared_type self() {
            return shared_from_this();
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

        bool extesibility_implied() const;

        setting_atom_vct& parameters() {
            return parameters_;
        }

        void parameters(setting_atom_vct vl) {
            parameters_ = vl;
        }

        bool parameterized() const {
            return !parameters_.empty();
        }

        std::string expectedname() const {
            return expecteddef() ? reff_->name() : "";
        }

        module_entity* external() const;

        std::string externalpreff() const;

        virtual basic_atom* root();

        void extention(bool vl) {
            extention_ = vl;
        }

        bool has_extention() const {
            return extention_;
        }

        bool isdummy() const {
            return isdummy_;
        }

        void isdummy(bool vl) {
            isdummy_ = vl;
        }

        bool rooted();

        type_atom* as_type();

        value_atom* as_value();

        valueset_atom* as_valueset();

        class_atom* as_class();

        object_atom* as_object();

        objectset_atom* as_objectset();

        ////////

        void resolve_reff(basic_atom_ptr holder = basic_atom_ptr(), search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());


    protected:
        basic_entity_ptr reff_;
        basic_entity_ptr scope_;
        setting_atom_vct parameters_;
        bool extention_;
        bool isdummy_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // SETTING
    /////////////////////////////////////////////////////////////////////////     
    // setting_atom
    /////////////////////////////////////////////////////////////////////////    

    class setting_atom : public basic_atom {

    public:

        setting_atom(alternmask msk, basic_entity_ptr scp = basic_entity_ptr()) : basic_atom(scp), mask_(msk) {
        };

        alternmask mask() {
            return mask_;
        }

        void mask(alternmask vl) {
            mask_ = vl;
        }

        type_atom_ptr type() {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        value_atom_ptr value() {
            return value_;
        }

        void value(value_atom_ptr vl) {
            value_ = vl;
        }

        valueset_atom_ptr valueset() {
            return valueset_;
        }

        void valueset(valueset_atom_ptr vl) {
            valueset_ = vl;
        }

        class_atom_ptr _class() {
            return class_;
        }

        void _class(class_atom_ptr vl) {
            class_ = vl;
        }

        object_atom_ptr object() {
            return object_;
        }

        void object(object_atom_ptr vl) {
            object_ = vl;
        }

        objectset_atom_ptr objectset() {
            return objectset_;
        }

        void objectset(objectset_atom_ptr vl) {
            objectset_ = vl;
        }

        std::string literal() {
            return literal_;
        }

        void literal(const std::string& vl) {
            literal_ = vl;
        }


    private:

        alternmask mask_;
        type_atom_ptr type_;
        value_atom_ptr value_;
        valueset_atom_ptr valueset_;
        class_atom_ptr class_;
        object_atom_ptr object_;
        objectset_atom_ptr objectset_;
        std::string literal_;
    };







    /////////////////////////////////////////////////////////////////////////   
    // ASSIGNMENT
    /////////////////////////////////////////////////////////////////////////         
    // assignment_entity
    /////////////////////////////////////////////////////////////////////////  

    class assignment_entity : public basic_entity {

    public:

        assignment_entity(basic_entity_ptr scope, const std::string& nm, entity_enum tp)
        : basic_entity(scope, nm, tp) {
        }

        assignment_entity(basic_entity_ptr scope, entity_enum tp)
        : basic_entity(tp, scope) {
        }

        assignment_entity(const std::string& nm, entity_enum tp)
        : basic_entity(nm, tp) {
        }

        assignment_entity(entity_enum tp)
        : basic_entity(tp) {
        }

        argument_entity_vct& arguments() {
            return arguments_;
        }

        void arguments(argument_entity_vct vl) {
            arguments_ = vl;
        }

        bool has_arguments() const {
            return !arguments_.empty();
        }




        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual void preresolve();

    private:

        argument_entity_vct arguments_;

    };







    /////////////////////////////////////////////////////////////////////////   
    // BIG
    /////////////////////////////////////////////////////////////////////////   
    // bigassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    class bigassignment_entity : public assignment_entity {

    public:
        bigassignment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg = basic_atom_ptr());

        basic_atom_ptr big() const {
            return big_;
        }

        void big(basic_atom_ptr vl) {
            big_ = vl;
        }

        typeassignment_entity_ptr bigT() const {
            return bigT_;
        }

        void bigT(typeassignment_entity_ptr vl) {
            bigT_ = vl;
        }

        classassignment_entity_ptr bigC() const {
            return bigC_;
        }

        void bigC(classassignment_entity_ptr vl) {
            bigC_ = vl;
        }

        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr()) {
        };


    private:

        basic_atom_ptr big_;
        typeassignment_entity_ptr bigT_;
        classassignment_entity_ptr bigC_;
    };






    /////////////////////////////////////////////////////////////////////////   
    // VALUE OR OBJECT
    /////////////////////////////////////////////////////////////////////////     
    // voassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    class voassignment_entity : public assignment_entity {

    public:
        voassignment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg = basic_atom_ptr());

        basic_atom_ptr big() const {
            return big_;
        }

        void big(basic_atom_ptr vl) {
            big_ = vl;
        }

        valueassignment_entity_ptr bigT() const {
            return bigT_;
        }

        void bigT(valueassignment_entity_ptr vl) {
            bigT_ = vl;
        }

        objectassignment_entity_ptr bigC() const {
            return bigC_;
        }

        void bigC(objectassignment_entity_ptr vl) {
            bigC_ = vl;
        }



        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr()) {
        };


    private:

        basic_atom_ptr big_;
        valueassignment_entity_ptr bigT_;
        objectassignment_entity_ptr bigC_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // VALUESET OR OBJECTSET
    /////////////////////////////////////////////////////////////////////////     
    // soassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    class soassignment_entity : public assignment_entity {

    public:
        soassignment_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg = basic_atom_ptr());

        basic_atom_ptr big() const {
            return big_;
        }

        void big(basic_atom_ptr vl) {
            big_ = vl;
        }

        valuesetassignment_entity_ptr bigT() const {
            return bigT_;
        }

        void bigT(valuesetassignment_entity_ptr vl) {
            bigT_ = vl;
        }

        objectsetassignment_entity_ptr bigC() const {
            return bigC_;
        }

        void bigC(objectsetassignment_entity_ptr vl) {
            bigC_ = vl;
        }


        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr()) {
        };


    private:

        basic_atom_ptr big_;
        valuesetassignment_entity_ptr bigT_;
        objectsetassignment_entity_ptr bigC_;
    };


}

#endif	
