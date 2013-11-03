//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1_SEM_OBJECTASSIGNMENT_IMPLEMENTATIUON_H_
#define	_ITU_ASN1_SEM_OBJECTASSIGNMENT_IMPLEMENTATIUON_H_

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

        definedobject_atom* as_defined();

        definedsetobject_atom* as_definedset();

        defltobject_atom* as_deflt();

        defsyntxobject_atom* as_defnsyntx();

        fromobjectobject_atom* as_fromobject();

        fromdefinedsetobject_atom* as_fromdefinedset();

        fromdefinedobject_atom* as_fromdefined();

        unionobject_atom* as_union();

        intersectionobject_atom* as_intersection();

        exceptobject_atom* as_except();

        allexceptobject_atom* as_allexcept();

        extentionobject_atom* as_extention();

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

    class definedobject_atom : public object_atom {

    public:

        definedobject_atom(basic_entity_ptr scope, const std::string& reff) : object_atom(scope, reff, ot_Refference) {
        };

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());


    };


    /////////////////////////////////////////////////////////////////////////        
    // definedsetobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class definedsetobject_atom : public object_atom {

    public:

        definedsetobject_atom(basic_entity_ptr scope, objectset_atom_ptr objs = objectset_atom_ptr());

        objectset_atom_ptr objectset() const {
            return objectset_;
        }

        void objectset(objectset_atom_ptr vl) {
            objectset_ = vl;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        objectset_atom_ptr objectset_;

    };


    /////////////////////////////////////////////////////////////////////////        
    // fromdefinedsetobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromdefinedsetobject_atom : public object_atom {

    public:

        fromdefinedsetobject_atom(basic_entity_ptr scope, const std::string& refffld, objectset_atom_ptr objs = objectset_atom_ptr());

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
    // fromdefinedobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class fromdefinedobject_atom : public object_atom {

    public:

        fromdefinedobject_atom(basic_entity_ptr scope, const std::string& refffld, object_atom_ptr obj = object_atom_ptr());

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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual fieldsetting_atom_ptr find_field(const std::string& name);


    private:

        fieldsetting_atom_vct fieldsetting_;

    };


    /////////////////////////////////////////////////////////////////////////        
    // defsyntxobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class defsyntxobject_atom : public object_atom {

    public:

        defsyntxobject_atom(basic_entity_ptr scope, fieldsetting_atom_vct fldst = fieldsetting_atom_vct())
        : object_atom(scope, ot_ObjectDefineSyn), fieldsetting_(fldst) {
        };

        fieldsetting_atom_vct& fieldsetting() {
            return fieldsetting_;
        }

        void fieldsetting(fieldsetting_atom_vct vl) {
            fieldsetting_ = vl;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual fieldsetting_atom_ptr find_field(const std::string& name);

        bool find_literal(const std::string& name);

    private:

        fieldsetting_atom_vct fieldsetting_;

    };


    /////////////////////////////////////////////////////////////////////////   
    // fromobjectobject_atom
    /////////////////////////////////////////////////////////////////////////      

    class fromobjectobject_atom : public object_atom {

    public:

        fromobjectobject_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj = object_atom_ptr());

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
    // allexceptobject_atom
    /////////////////////////////////////////////////////////////////////////  

    class allexceptobject_atom : public object_atom {

    public:

        allexceptobject_atom() : object_atom(ot_ALLEXCEPT) {
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

        object_atom_ptr object() const {
            return object_;
        }

        void object(object_atom_ptr vl) {
            object_ = vl;
        }

        class_atom_ptr _class() const {
            return class_;
        }

        void _class(class_atom_ptr vl) {
            class_ = vl;
        }

        /////        

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        void apply_fields();

    private:

        void calculate_fields(classassignment_entity*cls, defsyntxobject_atom* obj);

        void create_fields(field_entity* fld, setting_atom* st = 0);

        void create_fields_var(field_entity* fld, setting_atom* st = 0);

        basic_entity_ptr find_typefields(reffvaluefield_entity* fld);

        basic_entity_ptr find_typefields(reffvaluesetfield_entity* fld);
        
        basic_entity_ptr find_typefields(const std::string& nm);       

        bool calculate_fields(syntax_atom* syn, defsyntxobject_atom* obj, fieldsetting_atom_vct& newvct, bool optional = false);

        class_atom_ptr class_;
        object_atom_ptr object_;
    };





}

#endif	

