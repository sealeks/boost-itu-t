//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1_SEM_CLASSASSIGNMENT_IMPLEMENTATIUON_H_
#define	_ITU_ASN1_SEM_CLASSASSIGNMENT_IMPLEMENTATIUON_H_

#include <boost/itu/x68X/sem_assignment.hpp>

namespace x680 {

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

        objectfield_entity* as_objectfield();

        objectsetfield_entity* as_objectsetfield();

        undeffield_entity* as_undeffield();

        undefsetfield_entity* as_undefsetfield();


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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    protected:
        basic_atom_ptr field_;
        valueset_atom_ptr default_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // objectfield_entity
    /////////////////////////////////////////////////////////////////////////  

    class objectfield_entity : public field_entity {

    public:

        objectfield_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr tp, object_atom_ptr dflt) :
        field_entity(scope, nm, fkind_ObjectFieldSpec, mk_default), class_(tp), default_(dflt) {
        };

        objectfield_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr tp, tagmarker_type mkr = mk_none) :
        field_entity(scope, nm, fkind_ObjectFieldSpec, mkr), class_(tp) {
        };

        class_atom_ptr _class() const {
            return class_;
        }

        void _class(class_atom_ptr vl) {
            class_ = vl;
        }

        object_atom_ptr _default() const {
            return default_;
        }

        void _default(object_atom_ptr vl) {
            default_ = vl;
        }

        //         

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    protected:
        class_atom_ptr class_;
        object_atom_ptr default_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // objectsetfield_entity
    /////////////////////////////////////////////////////////////////////////  

    class objectsetfield_entity : public field_entity {

    public:

        objectsetfield_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr tp, objectset_atom_ptr dflt) :
        field_entity(scope, nm, fkind_ObjectSetFieldSpec, mk_default), class_(tp), default_(dflt) {
        };

        objectsetfield_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr tp, tagmarker_type mkr = mk_none) :
        field_entity(scope, nm, fkind_ObjectSetFieldSpec, mkr), class_(tp) {
        };

        class_atom_ptr _class() const {
            return class_;
        }

        void _class(class_atom_ptr vl) {
            class_ = vl;
        }

        objectset_atom_ptr _default() const {
            return default_;
        }

        void _default(objectset_atom_ptr vl) {
            default_ = vl;
        }



        //         

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    protected:
        class_atom_ptr class_;
        objectset_atom_ptr default_;
    };



    /////////////////////////////////////////////////////////////////////////   
    // undeffield_entity
    /////////////////////////////////////////////////////////////////////////  

    class undeffield_entity : public field_entity {

    public:

        undeffield_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg, value_atom_ptr dfltv, object_atom_ptr dflto) :
        field_entity(scope, nm, fkind_FixedType_or_Object, mk_default), big_(bg), defaultv_(dfltv), defaulto_(dflto) {
        };

        undeffield_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg, tagmarker_type mkr = mk_none) :
        field_entity(scope, nm, fkind_FixedType_or_Object, mkr), big_(bg) {
        };

        basic_atom_ptr big() const {
            return big_;
        }

        void big(basic_atom_ptr vl) {
            big_ = vl;
        }

        value_atom_ptr _defaultv() const {
            return defaultv_;
        }

        void _defaulto(value_atom_ptr vl) {
            defaultv_ = vl;
        }

        object_atom_ptr _defaulto() const {
            return defaulto_;
        }

        void _defaulto(object_atom_ptr vl) {
            defaulto_ = vl;
        }

        //         

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    protected:
        basic_atom_ptr big_;
        value_atom_ptr defaultv_;
        object_atom_ptr defaulto_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // undefsetfield_entity
    /////////////////////////////////////////////////////////////////////////  

    class undefsetfield_entity : public field_entity {

    public:

        undefsetfield_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg, valueset_atom_ptr dfltv, objectset_atom_ptr dflto) :
        field_entity(scope, nm, fkind_FixedTypeSet_or_ObjectSet, mk_default), big_(bg), defaultv_(dfltv), defaulto_(dflto) {
        };

        undefsetfield_entity(basic_entity_ptr scope, const std::string& nm, basic_atom_ptr bg, tagmarker_type mkr = mk_none) :
        field_entity(scope, nm, fkind_FixedTypeSet_or_ObjectSet, mkr), big_(bg) {
        };

        basic_atom_ptr big() const {
            return big_;
        }

        void big(basic_atom_ptr vl) {
            big_ = vl;
        }

        valueset_atom_ptr _defaultv() const {
            return defaultv_;
        }

        void _defaultv(valueset_atom_ptr vl) {
            defaultv_ = vl;
        }

        objectset_atom_ptr _defaulto() const {
            return defaulto_;
        }

        void _defaulto(objectset_atom_ptr vl) {
            defaulto_ = vl;
        }



        //         

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    protected:
        basic_atom_ptr big_;
        valueset_atom_ptr defaultv_;
        objectset_atom_ptr defaulto_;
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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

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

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        syntax_atom_vct group_;
    };


    /////////////////////////////////////////////////////////////////////////   
    // class_atom
    /////////////////////////////////////////////////////////////////////////  

    class class_atom : public basic_atom {

    public:
        class_atom(basic_entity_ptr scope, definedclass_type tp);
        class_atom(basic_entity_ptr scope, const std::string& reff, definedclass_type tp = cl_Reference);

        definedclass_type builtin() const {
            return builtin_;
        }

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

    private:

        definedclass_type builtin_;

    };




    /////////////////////////////////////////////////////////////////////////   
    // classassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    class classassignment_entity : public assignment_entity {

    public:
        classassignment_entity(basic_entity_ptr scope, const std::string& nm, class_atom_ptr tp = class_atom_ptr());

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

        virtual basic_entity_ptr find_by_name(const std::string& nm, search_marker sch = full_search);

        virtual void resolve(basic_atom_ptr holder = basic_atom_ptr());

        virtual void preresolve();

    private:

        class_atom_ptr class_;
        withsyntax_atom withsyntax_;
    };



}

#endif	

