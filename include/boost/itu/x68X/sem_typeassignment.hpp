//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_T_SEM_TYPEASSIGNMENT_IMPLEMENTATIUON_H_
#define	_ITU_T_SEM_TYPEASSIGNMENT_IMPLEMENTATIUON_H_

#include <boost/itu/x68X/sem_assignment.hpp>
#include <boost/itu/x68X/constraint_templates.h>

namespace x680 {



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

        void number(value_atom_ptr vl) {
            number_ = vl;
        }

        tagclass_type _class() const {
            return class_;
        }

        void _class(tagclass_type vl) {
            class_ = vl;
        }

        tagrule_type rule() const {
            return rule_;
        }

        void rule(tagrule_type vl) {
            rule_ = vl;
        }

    private:

        value_atom_ptr number_;
        tagclass_type class_;
        tagrule_type rule_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // canonical_tag
    /////////////////////////////////////////////////////////////////////////   


    boost::uint64_t from_defined_type(defined_type tp);

    class canonical_tag {

    public:

        canonical_tag(boost::uint64_t vl, tagclass_type cl = tcl_context)
        : number_(vl), class_(cl) {
        }

        canonical_tag(defined_type tp, tagclass_type cl = tcl_universal)
        : number_(from_defined_type(tp)), class_(cl) {
        }

        virtual ~canonical_tag() {
        }

        boost::uint64_t number() const {
            return number_;
        }

        tagclass_type _class() const {
            return class_;
        }


        friend bool operator==(const canonical_tag& ls, const canonical_tag& rs);

        friend bool operator!=(const canonical_tag& ls, const canonical_tag& rs);

        friend bool operator==(const canonical_tag_ptr& ls, const canonical_tag_ptr& rs);

        friend bool operator!=(const canonical_tag_ptr& ls, const canonical_tag_ptr& rs);

        friend bool operator<(const canonical_tag_ptr& ls, const canonical_tag_ptr& rs);

        bool operator<(const canonical_tag& other);

    private:

        boost::uint64_t number_;
        tagclass_type class_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // effective_tabconstraint
    /////////////////////////////////////////////////////////////////////////  

    class effective_tabconstraint : public basic_atom {

    public:

        typedef std::vector<std::string> fieldname_vct;

        effective_tabconstraint(basic_entity_ptr scp, classassignment_entity_ptr cls, objectsetassignment_entity_ptr objs, defined_type untp) :
        basic_atom(at_EffectiveTabConstraint, scp), class_(cls), objectsetassignment_(objs), unicaltype_(untp) {
        }

        classassignment_entity_ptr _class() {
            return class_;
        }

        void _class(classassignment_entity_ptr vl) {
            class_ = vl;
        }

        objectsetassignment_entity_ptr objectsetassignment() {
            return objectsetassignment_;
        }

        void objectsetassignment(objectsetassignment_entity_ptr vl) {
            objectsetassignment_ = vl;
        }

        fieldname_vct& fieldnames() {
            return fieldnames_;
        }

        std::string unicalfield() {
            return unicalfield_;
        }

        void unicalfield(const std::string& vl) {
            unicalfield_ = vl;
        }

        defined_type unicaltype() {
            return unicaltype_;
        }

        void unicaltype(defined_type vl) {
            unicaltype_ = vl;
        }

        bool find_field(const std::string& vl);

        typeassignment_entity_vct fields(const std::string& nm);

        objectassignment_entity_set objectset();

        value_vct fields();

        std::size_t count();

        bool valid();

        bool check();






    private:

        classassignment_entity_ptr class_;
        objectsetassignment_entity_ptr objectsetassignment_;
        fieldname_vct fieldnames_;
        std::string unicalfield_;
        defined_type unicaltype_;

    };

    /////////////////////////////////////////////////////////////////////////   
    // type_atom
    /////////////////////////////////////////////////////////////////////////  

    class type_atom : public basic_atom {

    public:
        type_atom(basic_entity_ptr scp, defined_type tp, tagged_ptr tg = tagged_ptr());
        type_atom(basic_entity_ptr scp, const std::string& reff, defined_type tp, tagged_ptr tg = tagged_ptr());

        defined_type builtin() const;

        defined_type root_builtin();

        tagged_ptr tag() const;

        void tag(tagged_ptr vl) {
            tag_ = vl;
        }
        
        tagged_vct tags_sequence();
        
        tagged_vct true_tags_sequence();        
        
        bool isuntagged();        
        
        bool ismultipe_tagged(); 

        typeassignment_entity_ptr from() const {
            return from_;
        }

        template<typename CriteriaTP>
        type_atom_ptr criteria_type() {
            return CriteriaTP::calculate(as_type());
        }

        // canonical tag
        canonical_tag_ptr cncl_tag();

        // preffix = textualy tagging
        canonical_tag_ptr textualy_tag();

        type_atom_ptr textualy_type();

        type_atom_ptr untagged_type();

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

        template<typename T>
        boost::shared_ptr<range_constraints<T> > effective_constraint() {
            return boost::shared_ptr<range_constraints<T> >();
        }

        integer_constraints_ptr integer_constraint();

        size_constraints_ptr size_constraint();

        char8_constraints_ptr char8_constraint();

        quadruple_constraints_ptr quadruple_constraint();

        tuple_constraints_ptr tuple_constraint();

        void predefined(predefined_ptr vl) {
            predefined_ = vl;
        }

        virtual bool isrefferrence() const;

        bool issimplerefferrence();

        bool isstruct() const;

        bool isstruct_of() const;

        bool isstructure() const;

        bool isopen() const;

        bool isenum() const;

        bool isstring();       

        bool can_per_constraints();

        bool can_alphabet_constraints();

        bool can_char_constraints();

        bool can_char8_constraints();

        bool can_tuple_constraints();

        bool can_quadruple_constraints();

        bool can_size_constraints();

        bool can_integer_constraints();

        bool isvaluestructure();

        virtual bool issubstitute() const;

        typeassignment_entity_ptr valuestructure();

        bool istextualy_choice();

        bool isallways_explicit();

        bool isprimitive();


        tagrule_type tagrule() const;

        classfieldtype_atom_ptr as_classfield();

        instanceoftype_atom_ptr as_instance();

        fromobject_type_atom_ptr as_fromobject();

        fromobjects_type_atom_ptr as_fromobjectset();

        selection_type_atom_ptr as_selection();

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());



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
        typeassignment_entity_ptr from_;

    };


    template<>
    integer_constraints_ptr type_atom::effective_constraint();

    template<>
    size_constraints_ptr type_atom::effective_constraint();

    template<>
    char8_constraints_ptr type_atom::effective_constraint();

    template<>
    quadruple_constraints_ptr type_atom::effective_constraint();

    template<>
    tuple_constraints_ptr type_atom::effective_constraint();



    /////////////////////////////////////////////////////////////////////////   
    // instanceoftype_atom
    /////////////////////////////////////////////////////////////////////////  

    class instanceoftype_atom : public type_atom {

    public:
        instanceoftype_atom(basic_entity_ptr scp, const std::string& reffcl, tagged_ptr tg = tagged_ptr());

        instanceoftype_atom(basic_entity_ptr scp, tagged_ptr tg = tagged_ptr()) : type_atom(scp, t_Instance_Of, tg) {
        };

        class_atom_ptr _class() const {
            return class_;
        }

        void _class(class_atom_ptr vl) {
            class_ = vl;
        }

        virtual void resolve_substitute();

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        class_atom_ptr class_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // classfieldtype_atom
    /////////////////////////////////////////////////////////////////////////  

    class classfieldtype_atom : public type_atom {

    public:
        classfieldtype_atom(basic_entity_ptr scp, const std::string& reffcl, const std::string& refffld, tagged_ptr tg = tagged_ptr());

        classfieldtype_atom(basic_entity_ptr scp, tagged_ptr tg = tagged_ptr()) : type_atom(scp, t_ClassField, tg) {
        };

        class_atom_ptr _class() const {
            return class_;
        }

        void _class(class_atom_ptr vl) {
            class_ = vl;
        }

        std::string field() const {
            return field_;
        }

        void field(const std::string& vl) {
            field_ = vl;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        class_atom_ptr class_;
        std::string field_;

    };

    /////////////////////////////////////////////////////////////////////////   
    // fromobject_type_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromobject_type_atom : public type_atom {

    public:

        fromobject_type_atom(basic_entity_ptr scp, const std::string& refffld,
                object_atom_ptr obj = object_atom_ptr(), tagged_ptr tg = tagged_ptr());

        object_atom_ptr object() const {
            return object_;
        }

        void object(object_atom_ptr vl) {
            object_ = vl;
        }

        basic_atom_ptr field() const {
            return field_;
        }

        void field(basic_atom_ptr vl) {
            field_ = vl;
        }

        virtual void resolve_substitute();

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        object_atom_ptr object_;
        basic_atom_ptr field_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // fromobjects_type_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromobjects_type_atom : public type_atom {

    public:

        fromobjects_type_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj = objectset_atom_ptr(), tagged_ptr tg = tagged_ptr());

        objectset_atom_ptr objectset() const {
            return objectset_;
        }

        void objectset(objectset_atom_ptr vl) {
            objectset_ = vl;
        }

        basic_atom_ptr field() const {
            return field_;
        }

        void field(basic_atom_ptr vl) {
            field_ = vl;
        }

        virtual void resolve_substitute();

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        objectset_atom_ptr objectset_;
        basic_atom_ptr field_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // selection_type_atom
    /////////////////////////////////////////////////////////////////////////  

    class selection_type_atom : public type_atom {

    public:

        selection_type_atom(basic_entity_ptr scp, const std::string& id, type_atom_ptr tp = type_atom_ptr(), tagged_ptr tg = tagged_ptr());

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        std::string identifier() const {
            return nidentifier_;
        }

        void identifier(const std::string& vl) {
            nidentifier_ = vl;
        }


        virtual void resolve_substitute();

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        type_atom_ptr type_;
        std::string nidentifier_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // typeassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    class typeassignment_entity : public assignment_entity {

    public:
        typeassignment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp = type_atom_ptr(), bool nmd = false);
        typeassignment_entity(basic_entity_ptr scope, bool nmd = false);

        type_atom_ptr type() const;

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        const x680::syntactic::type_assignment& synctas() const {
            return synctas_;
        }

        void synctas(const x680::syntactic::type_assignment& vl) {
            synctas_ = vl;
        }

        bool named() const {
            return named_;
        }

        std::size_t extention_count() const {
            return extention_count_;
        }

        void extention_count(std::size_t vl) {
            extention_count_ = vl;
        }

        bool is_cpp_expressed() const {
            return ((type()) && (!has_arguments()));
        }

        defined_type builtin() const {
            type_atom_ptr tmptype = type();
            return tmptype ? tmptype->builtin() : t_NODEF;
        }

        defined_type root_builtin() {
            type_atom_ptr tmptype = type();
            return tmptype ? tmptype->root_builtin() : t_NODEF;
        }

        typeassignment_entity_ptr root_typeassignment();

        typeassignment_entity_ptr prefixed_typeassignment();    

        template<typename CriteriaTP>
        typeassignment_entity_ptr criteria_typeassignment() {
            return CriteriaTP::calculate(as_typeassigment());
        }

        tagged_ptr tag() const {
            type_atom_ptr tmptype = type();
            return tmptype ? tmptype->tag() : tagged_ptr();
        }

        canonical_tag_ptr cncl_tag() {
            type_atom_ptr tmptype = type();
            return tmptype ? tmptype->cncl_tag() : canonical_tag_ptr();
        }

        // preffix = textualy tagging

        canonical_tag_ptr textualy_tag() {
            type_atom_ptr tmptype = type();
            return tmptype ? tmptype->textualy_tag() : canonical_tag_ptr();
        }

        type_atom_ptr textualy_type() {
            type_atom_ptr tmptype = type();
            return tmptype ? tmptype->textualy_type() : type_atom_ptr();
        }

        predefined_ptr predefined() {
            type_atom_ptr tmptype = type();
            return tmptype ? tmptype->predefined() : predefined_ptr();
        }

        bool isrefferrence() const {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->isrefferrence()));
        }

        bool issimplerefferrence() {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->issimplerefferrence()));
        }

        bool isstruct() const {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->isstruct()));
        }

        bool isstruct_of() const {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->isstruct_of()));
        }

        bool isstructure() const {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->isstructure()));
        }

        bool isopen() const {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->isopen()));
        }

        bool isenum() const {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->isenum()));
        }
        
        bool isstring() const {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->isstring()));
        }
        
        bool can_per_constraints() {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->can_per_constraints()));
        }

        bool can_alphabet_constraints() {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->can_alphabet_constraints()));
        }

        bool can_char_constraints() {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->can_char_constraints()));
        }

        bool can_char8_constraints() {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->can_char8_constraints()));
        }

        bool can_quadruple_constraints() {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->can_quadruple_constraints()));
        }

        bool can_size_constraints() {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->can_size_constraints()));
        }

        bool can_integer_constraints() {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->can_integer_constraints()));
        }

        bool istextualy_choice() {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->istextualy_choice()));
        }

        bool isprimitive() {
            type_atom_ptr tmptype = type();
            return (tmptype && (tmptype->isprimitive()));
        }

        bool isdefined_choice();

        bool islocaldeclare() const;

        bool islocaldefined() const;

        canonical_tag_vct cncl_tags();

        typeassignment_entity_ptr superfluous_assignment(module_entity_ptr mod);

        namedtypeassignment_entity_ptr as_named();

        namedtypeassignment_entity_vct canonicalorder_root();

        bool single_child_root();

        namedtypeassignment_entity_vct child_root_1(bool order=true);

        namedtypeassignment_entity_vct child_root_2(bool order=true);

        namedtypeassignment_entity_vct extention_group(std::size_t num);

        namedtypeassignment_entity_vct extentions();

        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        // protected:

        virtual void after_resolve();

        basic_entity_vector::iterator first_extention();

        basic_entity_vector::iterator second_extention();

        virtual basic_atom_ptr atom() const;

        effective_tabconstraint_ptr tabconstraint() const {
            return tabconstraint_;
        }

        void tabconstraint(effective_tabconstraint_ptr vl) {
            tabconstraint_ = vl;
        }

        effective_tabconstraint_ptr reff_tabconstraint() const {
            return !reff_tabconstraint_._empty() ? reff_tabconstraint_.lock() : effective_tabconstraint_ptr();
        }

        void reff_tabconstraint(effective_tabconstraint_ptr vl) {
            reff_tabconstraint_ = effective_tabconstraint_wptr(vl);
        }

        bool unicalfield() {
            return unicalfield_;
        }

        void unicalfield(bool vl) {
            unicalfield_ = vl;
        }


    protected:

        virtual void assign_from(assignment_entity_ptr from);

        virtual void substitute();

    private:

        void post_resolve_child();

        void post_resolve_apply_componentsof();

        bool resolve_extention();

        bool is_resolve_autotag();

        void post_resolve_autotag();

        void post_resolve_check();

        void post_resolve_tabconstraint();

        type_atom_ptr type_;
        bool named_;
        x680::syntactic::type_assignment synctas_;
        effective_tabconstraint_ptr tabconstraint_;
        effective_tabconstraint_wptr reff_tabconstraint_;
        bool unicalfield_;
        std::size_t extention_count_;
    };






    /////////////////////////////////////////////////////////////////////////   
    // namedtypeassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    class namedtypeassignment_entity : public typeassignment_entity {

    public:



        namedtypeassignment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, tagmarker_type mrker);
        namedtypeassignment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl);
        namedtypeassignment_entity(basic_entity_ptr scp, type_atom_ptr tp, value_atom_ptr vl);
        namedtypeassignment_entity(basic_entity_ptr scp, tagmarker_type mrker = mk_extention);

        value_atom_ptr _default() const {
            return default_;
        }

        void _default(value_atom_ptr v) {
            default_ = v;
        }

        tagmarker_type marker() const {
            return marker_;
        }

        extentionnum_ptr extentionnum() const {
            return extentionnum_;
        }

        bool has_extentionnum() const {
            return static_cast<bool> (extentionnum_);
        }

        void extentionnum(extentionnum_type vl) {
            extentionnum_ = extentionnum_ptr(new extentionnum_type(vl));
        }

        void extentionnum(extentionnum_ptr vl) {
            extentionnum_ = vl;
        }

        bool extentiongroup() const {
            return extentiongroup_;
        }

        void extentiongroup(bool vl) {
            extentiongroup_ = vl;
        }

        //////

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        void resolve_default();

        tagmarker_type marker_;
        value_atom_ptr default_;
        extentionnum_ptr extentionnum_;
        bool extentiongroup_;

    };



}

#endif	

