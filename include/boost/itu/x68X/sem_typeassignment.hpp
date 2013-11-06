//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1_SEM_TYPEASSIGNMENT_IMPLEMENTATIUON_H_
#define	_ITU_ASN1_SEM_TYPEASSIGNMENT_IMPLEMENTATIUON_H_

#include <boost/itu/x68X/sem_assignment.hpp>

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

        void tag(tagged_ptr vl) {
            tag_ = vl;
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

        defined_type root_builtin();

        defined_type effective_builtin();

        bool isopen() const;

        bool istypedef() const;

        bool isno_taggedchoice();

        bool isallways_explicit();

        basic_atom_ptr effective_type();

        tagrule_type tagrule() const;

        classfieldtype_atom_ptr as_classfield();

        instanceoftype_atom_ptr as_instance();

        fromobjecttype_atom_ptr as_fromobject();

        fromobjectsettype_atom_ptr as_fromobjectset();

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

    };


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

        basic_atom_ptr field() const {
            return field_;
        }

        void field(basic_atom_ptr vl) {
            field_ = vl;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        class_atom_ptr class_;
        basic_atom_ptr field_;

    };

    /////////////////////////////////////////////////////////////////////////   
    // fromobjecttype_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromobjecttype_atom : public type_atom {

    public:

        fromobjecttype_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj = object_atom_ptr(), tagged_ptr tg = tagged_ptr());

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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        object_atom_ptr object_;
        basic_atom_ptr field_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // fromobjectsettype_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromobjectsettype_atom : public type_atom {

    public:

        fromobjectsettype_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj = objectset_atom_ptr(), tagged_ptr tg = tagged_ptr());

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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        objectset_atom_ptr objectset_;
        basic_atom_ptr field_;

    };



    /////////////////////////////////////////////////////////////////////////   
    // typeassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    class typeassignment_entity : public assignment_entity {

    public:
        typeassignment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp = type_atom_ptr(), bool nmd = false);
        typeassignment_entity(basic_entity_ptr scope, bool nmd = false);

        type_atom_ptr type() const {
            return type_;
        }

        void type(type_atom_ptr vl) {
            type_ = vl;
        }

        bool named() const {
            return named_;
        }

        namedtypeassignment_entity_ptr as_named();


        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        // protected:

        //   void resolve_predef();        

    private:

        void post_resolve_child();

        void post_resolve_apply_componentsof();

        bool is_resolve_autotag();

        void post_resolve_autotag();

        type_atom_ptr type_;
        bool named_;
    };






    /////////////////////////////////////////////////////////////////////////   
    // namedtypeassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    class namedtypeassignment_entity : public typeassignment_entity {

    public:

        namedtypeassignment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, tagmarker_type mrker);
        namedtypeassignment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl);
        namedtypeassignment_entity(basic_entity_ptr scp, type_atom_ptr tp, value_atom_ptr vl);
        namedtypeassignment_entity(basic_entity_ptr scp);

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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        void resolve_default();

        tagmarker_type marker_;
        value_atom_ptr default_;

    };



}

#endif	

