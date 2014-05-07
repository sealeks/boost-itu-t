//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_T_SEM_OBJECTASSIGNMENT_IMPLEMENTATIUON_H_
#define	_ITU_T_SEM_OBJECTASSIGNMENT_IMPLEMENTATIUON_H_

#include <boost/itu/x68X/sem_assignment.hpp>

namespace x680 {



    /////////////////////////////////////////////////////////////////////////   
    // OBJECT
    /////////////////////////////////////////////////////////////////////////   
    // fieldsetting_atom_atom
    /////////////////////////////////////////////////////////////////////////  

    class fieldsetting_atom : public basic_atom {

    public:

        fieldsetting_atom(basic_entity_ptr scope, const std::string& flf, setting_atom_ptr settg) :
        basic_atom(at_FieldSetting, scope), field_(flf), setting_(settg) {
        };

        fieldsetting_atom(const std::string& flf, setting_atom_ptr settg) :
        basic_atom(at_FieldSetting), field_(flf), setting_(settg) {
        };

        std::string field() const {
            return field_;
        }

        void field(std::string vl) {
            field_ = vl;
        }

        setting_atom_ptr setting() const {
            return setting_;
        }

        void setting(setting_atom_ptr vl) {
            setting_ = vl;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr()) {
        };

    private:
        std::string field_;
        setting_atom_ptr setting_;
    };


    /////////////////////////////////////////////////////////////////////////        
    // object_atom
    /////////////////////////////////////////////////////////////////////////  

    class object_atom : public basic_atom {

    public:
        object_atom(object_type tp);
        object_atom(basic_entity_ptr scope, object_type tp);
        object_atom(basic_entity_ptr scope, const std::string& reff, object_type tp);

        object_type builtin() const {
            return builtin_;
        }

        virtual bool isrefferrence() const;

        defined_object_atom_ptr as_defined();

        definedobjects_object_atom_ptr as_definedset();

        defltobject_atom_ptr as_deflt();

        defsyntax_object_atom_ptr as_defnsyntx();

        fromobject_object_atom_ptr as_fromobject();

        fromdefined_objects_object_atom_ptr as_fromdefinedset();

        fromdefined_object_atom_ptr as_fromdefined();

        unionobject_atom_ptr as_union();

        intersectionobject_atom_ptr as_intersection();

        exceptobject_atom_ptr as_except();

        allobject_atom_ptr as_all();

        extentionobject_atom_ptr as_extention();

        virtual objectassignment_entity_ptr get_object(bool strict = false);

        virtual objectassignment_entity_vct get_objects(bool strict = false);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual fieldsetting_atom_ptr find_field(const std::string& name) {
            return fieldsetting_atom_ptr();
        }

    private:

        object_type builtin_;

    };


    /////////////////////////////////////////////////////////////////////////        
    // defineobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class defined_object_atom : public object_atom {

    public:

        defined_object_atom(basic_entity_ptr scope, const std::string& reff) : object_atom(scope, reff, ot_Refference) {
        };

        virtual objectassignment_entity_ptr get_object(bool strict = false);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());


    };


    /////////////////////////////////////////////////////////////////////////        
    // definedobjects_object_atom
    /////////////////////////////////////////////////////////////////////////  

    class definedobjects_object_atom : public object_atom {

    public:

        definedobjects_object_atom(basic_entity_ptr scope, objectset_atom_ptr objs = objectset_atom_ptr());

        objectset_atom_ptr objectset() const {
            return objectset_;
        }

        void objectset(objectset_atom_ptr vl) {
            objectset_ = vl;
        }


        virtual objectassignment_entity_ptr get_object(bool strict = false);

        virtual objectassignment_entity_vct get_objects(bool strict = false);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        objectset_atom_ptr objectset_;

    };


    /////////////////////////////////////////////////////////////////////////        
    // fromdefined_objects_object_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromdefined_objects_object_atom : public object_atom {

    public:

        fromdefined_objects_object_atom(basic_entity_ptr scope, const std::string& refffld, objectset_atom_ptr objs = objectset_atom_ptr());

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

        virtual objectassignment_entity_ptr get_object(bool strict = false);

        virtual objectassignment_entity_vct get_objects(bool strict = false);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        objectset_atom_ptr objectset_;
        basic_atom_ptr field_;

    };


    /////////////////////////////////////////////////////////////////////////        
    // fromdefined_object_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromdefined_object_atom : public object_atom {

    public:

        fromdefined_object_atom(basic_entity_ptr scope, const std::string& refffld, object_atom_ptr obj = object_atom_ptr());

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

        virtual objectassignment_entity_ptr get_object(bool strict = false);

        virtual objectassignment_entity_vct get_objects(bool strict = false);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        object_atom_ptr object_;
        basic_atom_ptr field_;

    };


    /////////////////////////////////////////////////////////////////////////        
    // defltobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class defltobject_atom : public object_atom {

    public:

        defltobject_atom(basic_entity_ptr scope, fieldsetting_atom_vct fldst = fieldsetting_atom_vct())
        : object_atom(scope, ot_Object), fieldsetting_(fldst) {
        };

        fieldsetting_atom_vct& fieldsetting() {
            return fieldsetting_;
        }

        void fieldsetting(fieldsetting_atom_vct vl) {
            fieldsetting_ = vl;
        }

        virtual objectassignment_entity_ptr get_object(bool strict = false);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual fieldsetting_atom_ptr find_field(const std::string& name);


    private:

        fieldsetting_atom_vct fieldsetting_;

    };


    /////////////////////////////////////////////////////////////////////////        
    // defsyntax_object_atom
    /////////////////////////////////////////////////////////////////////////  

    class defsyntax_object_atom : public object_atom {

    public:

        defsyntax_object_atom(basic_entity_ptr scope, fieldsetting_atom_vct fldst = fieldsetting_atom_vct())
        : object_atom(scope, ot_ObjectDefineSyn), fieldsetting_(fldst) {
        };

        defsyntax_object_atom(basic_entity_ptr scope, class_atom_ptr cls, fieldsetting_atom_vct fldst = fieldsetting_atom_vct());

        void _class(class_atom_ptr cls);

        fieldsetting_atom_vct& fieldsetting() {
            return fieldsetting_;
        }

        void fieldsetting(fieldsetting_atom_vct vl) {
            fieldsetting_ = vl;
        }

        virtual objectassignment_entity_ptr get_object(bool strict = false);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual fieldsetting_atom_ptr find_field(const std::string& name);

        bool find_literal(const std::string& name);

    private:

        fieldsetting_atom_vct fieldsetting_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // fromobject_object_atom
    /////////////////////////////////////////////////////////////////////////      

    class fromobject_object_atom : public object_atom {

    public:

        fromobject_object_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj = object_atom_ptr());

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

        virtual objectassignment_entity_ptr get_object(bool strict = false);
        
        virtual objectassignment_entity_vct get_objects(bool strict = false);        

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        object_atom_ptr object_;
        basic_atom_ptr field_;

    };


    /////////////////////////////////////////////////////////////////////////        
    // unionobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class unionobject_atom : public object_atom {

    public:

        unionobject_atom() : object_atom(ot_UNION) {
        };

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr()) {
        };

    };

    /////////////////////////////////////////////////////////////////////////        
    // intersectionobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class intersectionobject_atom : public object_atom {

    public:

        intersectionobject_atom() : object_atom(ot_INTERSECTION) {
        };

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr()) {
        };

    };

    /////////////////////////////////////////////////////////////////////////        
    // exceptobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class exceptobject_atom : public object_atom {

    public:

        exceptobject_atom() : object_atom(ot_EXCEPT) {
        };

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr()) {
        };

    };

    /////////////////////////////////////////////////////////////////////////        
    //  allobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class allobject_atom : public object_atom {

    public:

        allobject_atom() : object_atom(ot_ALLEXCEPT) {
        };

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr()) {
        };

    };


    /////////////////////////////////////////////////////////////////////////        
    // extentionobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class extentionobject_atom : public object_atom {

    public:

        extentionobject_atom() : object_atom(ot_EXTENTION) {
        };

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr()) {
        };

    };







    /////////////////////////////////////////////////////////////////////////   
    // objectassignment_entity
    /////////////////////////////////////////////////////////////////////////    

    class objectassignment_entity : public assignment_entity {

    public:
        objectassignment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr cls, object_atom_ptr obj = object_atom_ptr());

        object_atom_ptr object() const;

        void object(object_atom_ptr vl) {
            object_ = vl;
        }

        class_atom_ptr _class() const {
            return class_;
        }

        void _class(class_atom_ptr vl) {
            class_ = vl;
        }

        const x680::syntactic::object_assignment& synctas() const {
            return synctas_;
        }

        void synctas(const x680::syntactic::object_assignment& vl) {
            synctas_ = vl;
        }

        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void after_resolve();

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        void apply_fields();

        virtual basic_atom_ptr atom() const;

    protected:

        virtual void assign_from(assignment_entity_ptr from);

    private:

        void calculate_fields(classassignment_entity_ptr cls, defsyntax_object_atom_ptr obj);

        void create_fields(field_entity_ptr fld, setting_atom_ptr st = setting_atom_ptr());

        void create_fields_var(field_entity_ptr fld, setting_atom_ptr st = setting_atom_ptr());

        basic_entity_ptr find_typefields(reffvaluefield_entity_ptr fld);

        basic_entity_ptr find_typefields(reffvaluesetfield_entity_ptr fld);

        basic_entity_ptr find_typefields(const std::string& nm);

        bool calculate_fields(syntax_atom_ptr syn, defsyntax_object_atom_ptr obj, fieldsetting_atom_vct& newvct, bool optional = false);

        class_atom_ptr class_;
        object_atom_ptr object_;
        x680::syntactic::object_assignment synctas_;
    };





}

#endif	

