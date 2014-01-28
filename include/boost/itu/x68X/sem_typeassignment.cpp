//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>

namespace x680 {



    /////////////////////////////////////////////////////////////////////////   
    // TYPE
    /////////////////////////////////////////////////////////////////////////     
    // predefined
    ///////////////////////////////////////////////////////////////////////// 


    /////////////////////////////////////////////////////////////////////////   
    // tagged
    /////////////////////////////////////////////////////////////////////////    


    /////////////////////////////////////////////////////////////////////////   
    // canonical_tag
    /////////////////////////////////////////////////////////////////////////   

    boost::uint64_t from_defined_type(defined_type tp) {
        switch (tp) {
            case t_BOOLEAN: return 1;
            case t_INTEGER: return 2;
            case t_BIT_STRING: return 3;
            case t_OCTET_STRING: return 4;
            case t_NULL: return 5;
            case t_OBJECT_IDENTIFIER: return 6;
            case t_ObjectDescriptor: return 7;
            case t_EXTERNAL: return 8;
            case t_REAL: return 9;
            case t_ENUMERATED: return 10;
            case t_EMBEDDED_PDV: return 11;
            case t_UTF8String: return 12;
            case t_RELATIVE_OID: return 13;
            case t_SEQUENCE:
            case t_SEQUENCE_OF: return 16;
            case t_SET:
            case t_SET_OF: return 17;
            case t_NumericString: return 18;
            case t_PrintableString: return 19;
            case t_T61String: return 20;
            case t_VideotexString: return 21;
            case t_IA5String: return 22;
            case t_UTCTime: return 23;
            case t_GeneralizedTime: return 24;
            case t_GraphicString: return 25;
            case t_VisibleString: return 26;
            case t_GeneralString: return 27;
            case t_UniversalString: return 28;
            case t_CHARACTER_STRING: return 29;
            case t_BMPString: return 30;
            case t_TIME: return 31;
            case t_TIME_OF_DAY: return 32;
            case t_DATE_TIME: return 33;
            case t_DURATION: return 34;
            case t_Instance_Of: return 16;
            default:
            {
            }
                /* 
                case t_Selection: return          
                case t_RELATIVE_OID_IRI: return 
                case t_OID_IRI: return 
                case t_NODEF: return 
                case t_ClassField,
                case t_TypeFromObject,
                case t_ValueSetFromObjects,
                case t_CHOICE,                
                case t_Reference*/
        }
        return 0;
    }

    bool operator==(const canonical_tag& ls, const canonical_tag& rs) {
        return (ls.number_ == rs.number_) && (ls.class_ == rs.class_);
    }

    bool operator!=(const canonical_tag& ls, const canonical_tag& rs) {
        return !(ls == rs);
    }

    bool operator==(const canonical_tag_ptr& ls, const canonical_tag_ptr& rs) {
        if ((!ls) || (!rs))
            return false;
        return (*ls) == (*rs);
    }

    bool operator!=(const canonical_tag_ptr& ls, const canonical_tag_ptr& rs) {
        if ((!ls) || (!rs))
            return true;
        return (*ls) != (*rs);
    }

    bool operator<(const canonical_tag_ptr& ls, const canonical_tag_ptr& rs) {
         if ((!ls) || (!rs))
            return false;      
        return (*ls) < (*rs);         
    }
        

    bool canonical_tag::operator<(const canonical_tag& other) {
        if (class_ != other.class_)
            return static_cast<int> (class_) <static_cast<int> (other.class_);
        return number_ < other.number_;
    }

    /////////////////////////////////////////////////////////////////////////   
    // type_atom
    /////////////////////////////////////////////////////////////////////////   

    type_atom::type_atom(basic_entity_ptr scp, defined_type tp, tagged_ptr tg)
    : basic_atom(at_Type, scp), builtin_(tp), tag_(tg) {
    }

    type_atom::type_atom(basic_entity_ptr scp, const std::string& reff, defined_type tp, tagged_ptr tg)
    : basic_atom(at_Type, scp, reff), builtin_(tp), tag_(tg) {
    }

    defined_type type_atom::root_builtin() {
        if (builtin_ != t_Reference)
            return builtin_;
        if (reff() && (reff()->as_typeassigment())) {
            if (reff()->as_typeassigment()->type())
                return reff()->as_typeassigment()->type()->root_builtin();
        }
        return t_NODEF;
    }

    canonical_tag_ptr type_atom::cncl_tag() {
        if (!tag()) {
            if ((istextualy_choice()) || (isopen()) ||
                    (isdummy()))
                return canonical_tag_ptr();
            switch (builtin_) {
                case t_Reference:
                {
                    if (reff() && (reff()->as_typeassigment())) {
                        if (reff()->as_typeassigment()->type())
                            return reff()->as_typeassigment()->type()->cncl_tag();
                    }
                    break;
                }
                default:
                {
                    return canonical_tag_ptr(new canonical_tag(builtin_));
                }
            }
        } else {
            if ((tag()->number()->root())
                    && (tag()->number()->root()->as_value())
                    && (tag()->number()->root()->as_value()->as_number())) {
                boost::uint64_t num = tag()->number()->root()->as_value()->as_number()->value();
                return canonical_tag_ptr(new canonical_tag(num, tag()->_class()));
            }
        }
        return canonical_tag_ptr();
    }


    canonical_tag_ptr type_atom::textualy_tag() {
        if (type_atom_ptr ptmp = textualy_type()) {
            if ((ptmp->tag()->number()->root())
                    && (ptmp->tag()->number()->root()->as_value())
                    && (ptmp->tag()->number()->root()->as_value()->as_number())) {
                boost::uint64_t num = ptmp->tag()->number()->root()->as_value()->as_number()->value();
                return canonical_tag_ptr(new canonical_tag(num, ptmp->tag()->_class()));
            }
        }
        return canonical_tag_ptr();
    }

    type_atom_ptr type_atom::textualy_type() {
        if (!tag()) {
            if (isrefferrence()) {
                if (reff() && (reff()->as_typeassigment())) {
                    if (reff()->as_typeassigment()->type())
                        return reff()->as_typeassigment()->type()->textualy_type();
                } else {
                    return type_atom_ptr();
                }
            }
        } else {
            return self()->as_type();
        }
        return type_atom_ptr();
    }

    bool type_atom::isrefferrence() const {
         return (((builtin_ == t_Reference) 
                 ||   (builtin_ ==t_TypeFromObject)
                 || (builtin_ ==t_ValueSetFromObjects)) && (reff()));
    }   
    
    bool type_atom::islocaldeclare() const {    
        if (scope() && (scope()->as_typeassigment()))
            return ((isstruct()) || (isstruct_of()));
        return false;
    }
    
    bool type_atom::issimplerefferrence() {
        switch(builtin_){
           case t_SEQUENCE: 
           case t_SEQUENCE_OF: 
           case t_SET: 
           case t_SET_OF: 
           case t_CHOICE:
           case t_Selection:
           case t_Instance_Of: 
           case t_RELATIVE_OID_IRI: 
           case t_Reference:
           case t_TypeFromObject: 
           case t_ValueSetFromObjects: return false;
            default:{}}
         return(!tag());
    }     
    
     bool type_atom::isstruct() const {
         return (((builtin_ == t_CHOICE) || (builtin_ == t_SET)  || (builtin_ == t_SEQUENCE)));
     }
     
     bool type_atom::isstruct_of() const {
         return (( (builtin_ == t_SET_OF)  || (builtin_ == t_SEQUENCE_OF)) && (!tag()));
     }   
     
    bool type_atom::isopen() const {
        return ((builtin_ == t_ClassField) || (builtin_ == t_ANY));
    }

    bool type_atom::isenum() const {
        return ((isrefferrence())  && (!tag_) && (constraints_.empty()));
    }

    bool type_atom::istextualy_choice() {
        if ((builtin_ == t_CHOICE) && (!tag()))
            return true;
        if (!isrefferrence())
            return false;
        //reff()-> resolve();
        if (reff() && (reff()->as_typeassigment())) {
            if (reff()->as_typeassigment()->type())
                return reff()->as_typeassigment()->type()->istextualy_choice();
        }
        return false;
    }

    bool type_atom::isnotagged_choice() {
        if (builtin_ == t_CHOICE)
            return !tag();
        if (!isrefferrence())
            return false;
        if (tag())
            return false;        
        reff()-> resolve();
        if (reff() && (reff()->as_typeassigment())) {
            if (reff()->as_typeassigment()->type())
                return reff()->as_typeassigment()->type()->isnotagged_choice();
        }
        return false;
    }    


    bool type_atom::isallways_explicit() {
        return (((istextualy_choice()) || (isopen()) ||
                (isdummy())) && (tag()));
    }

    tagrule_type type_atom::tagrule() const {
        return (scope() && (scope()->moduleref())) ?
                scope()->moduleref()->tagrule() : noset_tags;
    }

    classfieldtype_atom_ptr type_atom::as_classfield() {
        return builtin() == t_ClassField ?
                boost::static_pointer_cast<classfieldtype_atom> (self()) : classfieldtype_atom_ptr();
    }

    instanceoftype_atom_ptr type_atom::as_instance() {
        return builtin() == t_Instance_Of ?
                boost::static_pointer_cast<instanceoftype_atom> (self()) : instanceoftype_atom_ptr();
    }

    fromobject_type_atom_ptr type_atom::as_fromobject() {
        return builtin() == t_TypeFromObject ?
                boost::static_pointer_cast<fromobject_type_atom> (self()) : fromobject_type_atom_ptr();
    }

    fromobjects_type_atom_ptr type_atom::as_fromobjectset() {
        return builtin() == t_ValueSetFromObjects ?
                boost::static_pointer_cast<fromobjects_type_atom> (self()) : fromobjects_type_atom_ptr();
    }

    void type_atom::resolve(basic_atom_ptr holder) {
        resolve_reff();
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }

    void type_atom::resolve_predef() {
        if (predefined() && scope()) {
            scope()->unicalelerror_throw(predefined()->values());
            resolve_predef_assign(predefined()->values());
            if (builtin() == t_ENUMERATED)
                resolve_predef_enum(predefined()->values());
            resolve_predef_check(predefined()->values());
        }
    }

    void type_atom::resolve_predef_assign(basic_entity_vector& vl) {
        for (basic_entity_vector::const_iterator it = vl.begin(); it != vl.end(); ++it) {
            switch (builtin()) {
                case t_INTEGER:
                {
                    if ((*it)->as_extention())
                        throw semantics::error("type '" + scope()->name() +
                            "' must not have extention in predefine   in module " +
                            (scope() ? scope()->modulerefname() : ""));

                }
                case t_BIT_STRING:
                {
                    if (((*it)->as_valueassigment()) && (!(*it)->as_valueassigment()->value()))
                        throw semantics::error("type '" + scope()->name() + "' predefine name '" +
                            (*it)->name() + "' dosn't assign " +
                            (scope() ? scope()->modulerefname() : ""));
                }
                default:
                {
                    if ((*it)->as_extention())
                        predefined()->extended(true);
                }
            }
            if (((*it)->as_valueassigment()) && ((*it)->as_valueassigment()->value())
                    && ((*it)->as_valueassigment()->value()->expecteddef())) {
                (*it)->as_valueassigment()->value()->resolve_reff(basic_atom_ptr(), extend_search);
                (*it)->as_valueassigment()->check_value_with_exception(v_number);

            }
        }
    }

    void type_atom::resolve_predef_enum(basic_entity_vector& vl) {
        std::set<int, std::less<int> > set;
        bool firstpart = true;
        for (basic_entity_vector::const_iterator it = vl.begin(); it != vl.end(); ++it) {
            if ((*it)->as_extention())
                firstpart = false;
            else if ((*it)->as_valueassigment()->value()) {
                value_atom_ptr vltmp = (*it)->as_valueassigment()->value();
                if (vltmp->as_number()) {
                    if (firstpart)
                        set.insert(vltmp->as_number()->value());
                } else {
                    if ((vltmp->root()) && (vltmp->root()->as_value()))
                        if (firstpart)
                            set.insert(vltmp->root()->as_value()->as_number()->value());
                }
            }
        }
        int start = 0;
        firstpart = true;
        for (basic_entity_vector::iterator it = vl.begin(); it != vl.end(); ++it) {
            if ((*it)->as_extention()) {
                firstpart = false;
            } else if (!(*it)->as_valueassigment()->value()) {
                int newen = start++;
                while (set.find(newen) != set.end())
                    newen = start++;
                (*it) = basic_entity_ptr(new valueassignment_entity((*it)->scope(), (*it)->name(), type_atom_ptr(new type_atom((*it)->scope(), t_INTEGER)),
                        value_atom_ptr(new numvalue_atom(newen))));
            } else {
                if (!firstpart) {
                    value_atom_ptr vltmp = (*it)->as_valueassigment()->value();
                    if (vltmp->as_number()) {
                        if (vltmp->as_number()->value() < start)
                            throw semantics::error("Type '" + scope()->name() + "' predefined name '" +
                                (*it)->name() + "' is not at the rule " + scope()->modulerefname());
                        else
                            start = vltmp->as_number()->value() + 1;
                    } else {
                        if (vltmp->root()->as_value()->as_number()->value() < start)
                            throw semantics::error("Type '" + scope()-> name() + "' predefined name '" +
                                (*it)->name() + "' is not at the rule " + scope()->modulerefname());
                        else
                            start = vltmp->root()->as_value()->as_number()->value() + 1;
                    }
                }
            }
        }
    }

    void type_atom::resolve_predef_check(basic_entity_vector& vl) {
        std::set<int, std::less<int> > set;
        for (basic_entity_vector::const_iterator it = vl.begin(); it != vl.end(); ++it) {
            if ((*it)->as_extention()) {
            } else if ((*it)->as_valueassigment()->value()) {
                value_atom_ptr vltmp = (*it)->as_valueassigment()->value();
                if (vltmp->as_number()) {
                    if (set.find(vltmp->as_number()->value()) != set.end())
                        throw semantics::error("Type '" + scope()->name() + "' predefined name '" +
                            (*it)->name() + "'is not unical " + scope()->modulerefname());
                    else
                        set.insert(vltmp->as_number()->value());
                } else {
                    if ((vltmp->root()) && (vltmp->root()->as_value())) {
                        if (set.find(vltmp->root()->as_value()->as_number()->value()) != set.end())
                            throw semantics::error("Type '" + scope()->name() + "' predefined name '" +
                                (*it)->name() + "' is not unical " + scope()->modulerefname());
                        else
                            set.insert(vltmp->root()->as_value()->as_number()->value());
                    }
                }
            }
        }
    }

    void type_atom::resolve_tag() {
        if (tag()) {
            if ((tag()->rule() == noset_tags)/* && (tag()->number())*/) {
                switch (tagrule()) {
                    case explicit_tags:
                        tag()->rule(explicit_tags);
                        break;
                    case implicit_tags:
                    case automatic_tags:
                    {
                        tag()->rule(isallways_explicit() ? explicit_tags : implicit_tags);
                        break;
                    }
                    default:
                    {
                        tag()->rule(explicit_tags);
                    };
                }
            }
            if ((isallways_explicit()) && (tag()->rule() == implicit_tags)) {
                if (scope())
                    scope()->referenceerror_throw("Named type should not be implicit", scope()->name());
                else
                    throw semantics::error("Named type should not be implicit");
            }
            if ((tag()->number()) && (tag()->number()->as_defined()) && (tag()->number()->expecteddef())) {
                tag()->number()->resolve_reff(basic_atom_ptr(), extend_search);
            }
        }
    }

    void type_atom::resolve_constraints() {
        for (constraints_atom_vct::iterator it = constraints_.begin(); it != constraints_.end(); ++it)
            (*it)->resolve();
    }


    /////////////////////////////////////////////////////////////////////////   
    // classfieldtype_atom
    /////////////////////////////////////////////////////////////////////////    

    instanceoftype_atom::instanceoftype_atom(basic_entity_ptr scp, const std::string& reffcl, tagged_ptr tg) :
    type_atom(scp, t_Instance_Of, tg), class_(class_atom_ptr(new class_atom(scp, reffcl))) {
    };

    void instanceoftype_atom::resolve(basic_atom_ptr holder) {
        if (_class())
            _class()->resolve();
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }


    /////////////////////////////////////////////////////////////////////////   
    // classfieldtype_atom
    /////////////////////////////////////////////////////////////////////////      

    classfieldtype_atom::classfieldtype_atom(basic_entity_ptr scp, const std::string& reffcl, const std::string& refffld, tagged_ptr tg) :
    type_atom(scp, t_ClassField, tg), class_(class_atom_ptr(new class_atom(scp, reffcl))), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {
    };

    void classfieldtype_atom::resolve(basic_atom_ptr holder) {
        if (_class())
            _class()->resolve();
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }

    /////////////////////////////////////////////////////////////////////////   
    // fromobject_type_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobject_type_atom::fromobject_type_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj, tagged_ptr tg) :
    type_atom(scp, t_TypeFromObject, tg), object_(obj), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {
    };

    void fromobject_type_atom::resolve(basic_atom_ptr holder) {
        if (object())
            object()->resolve();
        if (object()->reff()) {
            assignment_entity_ptr tmpasmt=object()->reff()->as_assigment(); 
            if (tmpasmt) {
                if (tmpasmt->find_component(field_->expectedname())) {
                    reff(tmpasmt->find_component(field_->expectedname()));
                }
            }
        }        
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }

    /////////////////////////////////////////////////////////////////////////   
    // fromobjects_type_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobjects_type_atom::fromobjects_type_atom(basic_entity_ptr scp, const std::string& refffld, objectset_atom_ptr obj, tagged_ptr tg) :
    type_atom(scp, t_ValueSetFromObjects, tg), objectset_(obj), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {
    };

    void fromobjects_type_atom::resolve(basic_atom_ptr holder) {
        if (objectset())
            objectset()->resolve();
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }


    /////////////////////////////////////////////////////////////////////////   
    // typeassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    typeassignment_entity::typeassignment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, bool nmd) :
    assignment_entity(scope, nm, et_Type), type_(tp), named_(nmd) {
    };

    typeassignment_entity::typeassignment_entity(basic_entity_ptr scope, bool nmd) :
    assignment_entity(scope, et_Type), named_(nmd) {
    };

    ////////

    basic_entity_ptr typeassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        if (sch & local_search) {
            if (((type()->predefined()))) {
                for (basic_entity_vector::iterator it = type()->predefined()->values().begin(); it != type()->predefined()->values().end(); ++it)
                    if ((*it)->name() == nm)
                        return *it;
            }
            if (type()->reff() && (type()->reff()->name() != nm)) {
                type()->resolve_reff();
                if (basic_entity_ptr fnd = type()->reff()->find_by_name(nm, sch))
                    return fnd;
            }
        }
        if (!(sch & extend_search))
            return basic_entity_ptr();
        if (basic_entity_ptr fnd = assignment_entity::find_by_name(nm))
            return fnd;
        if (scope())
            return scope()->find_by_name(nm, sch);
        return basic_entity_ptr();
    }

    canonical_tag_vct typeassignment_entity::cncl_tags() {
        canonical_tag_vct tmp;
        if (type()) {
            if (type()->isnotagged_choice()) {
                if (type()->builtin() == t_CHOICE) {
                    if ((type()->tag()) && (type()->cncl_tag())) {
                            tmp.push_back(type()->cncl_tag());
                    } else {
                        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                            if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                                canonical_tag_vct tmpv = (*it)->as_typeassigment()->cncl_tags();
                                if (!tmpv.empty())
                                    tmp.insert(tmp.end(), tmpv.begin(), tmpv.end());
                            }
                        }
                    }
                } else {
                    if ((type()->reff()) && (type()->reff()->as_typeassigment()))
                        tmp=type()->reff()->as_typeassigment()->cncl_tags();
                }
            } else {
                if (type()->cncl_tag())
                    tmp.push_back(type()->cncl_tag());
            }
        }
    return tmp;
}    

    namedtypeassignment_entity_ptr typeassignment_entity::as_named() {
        return named() ?
                boost::static_pointer_cast<namedtypeassignment_entity> (self()) : namedtypeassignment_entity_ptr();
    }

    void typeassignment_entity::resolve(basic_atom_ptr holder) {
        unicalelerror_throw(childs());
        assignment_entity::resolve(holder);
        resolve_child();
        if (type())
            type()->resolve();
        post_resolve_child();

    }
    

    basic_entity_vector::iterator typeassignment_entity::first_extention() {
        for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it)
            if (((*it)->as_typeassigment()) && 
                    ((*it)->as_typeassigment()->as_named()) &&
                    ((*it)->as_typeassigment()->as_named()->marker() == mk_extention))
                return (++it);
        return childs().end();
    }

    basic_entity_vector::iterator typeassignment_entity::second_extention() {
        basic_entity_vector::iterator fit = first_extention();
        if (fit != childs().end()) {
            for (basic_entity_vector::iterator it = fit; it != childs().end(); ++it)
            if (((*it)->as_typeassigment()) && 
                    ((*it)->as_typeassigment()->as_named()) &&
                    ((*it)->as_typeassigment()->as_named()->marker() == mk_extention))
                    return (++it);
        }
        return childs().end();
    }        

    void typeassignment_entity::post_resolve_child() {
        bool autotag = is_resolve_autotag();
        post_resolve_apply_componentsof();
        if (autotag)
            post_resolve_autotag();
        post_resolve_check();
    }

    void typeassignment_entity::post_resolve_apply_componentsof() {
        if ((type()) && (!childs().empty())) {
            if ((type()->builtin() == t_SEQUENCE) || ((type()->builtin() == t_SET))) {
                bool find_compomensof = true;
                while (find_compomensof) {
                    find_compomensof = false;
                    for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                        if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                            namedtypeassignment_entity_ptr named = (*it)->as_typeassigment()->as_named();
                            if (named->marker() == mk_components_of) {
                                if (basic_entity_ptr namedreff = named->type()->reff()) {
                                    namedreff->resolve();
                                    basic_entity_vector tmpch;
                                    if ((namedreff->as_typeassigment())
                                            && (!namedreff->as_typeassigment()->childs().empty())) {
                                        if (!namedreff->as_typeassigment()->type())
                                            referenceerror_throw("Undefined type", name());
                                        if (namedreff->as_typeassigment()->type()->root_builtin() != type()->builtin())
                                            referenceerror_throw("Apply COMPONENT OF error", name());
                                        for (basic_entity_vector::iterator its = namedreff->as_typeassigment()->childs().begin();
                                                its != namedreff->as_typeassigment()->childs().end(); ++its) {
                                            if ((*its)->as_typeassigment()->as_named()->marker() != mk_extention) {
                                                namedtypeassignment_entity_ptr tmp;
                                                if ((*its)->as_typeassigment()->as_named()->marker() == mk_default) {
                                                    tmp = namedtypeassignment_entity_ptr(new namedtypeassignment_entity((*it)->scope(),
                                                            (*its)->name(), (*its)->as_typeassigment()->as_named()->type(),
                                                            (*its)->as_typeassigment()->as_named()->_default()));
                                                    //if  (tmp->type()->scope()!=(*its)->as_typeassigment()->as_named()->type()->scope()){
                                                    tmp->type()->scope((*its)->as_typeassigment()->as_named()->type()->scope()); //}
                                                } else {
                                                    tmp = namedtypeassignment_entity_ptr(new namedtypeassignment_entity((*it)->scope(),
                                                            (*its)->name(), (*its)->as_typeassigment()->as_named()->type(),
                                                            (*its)->as_typeassigment()->as_named()->marker()));
                                                    //  if (tmp->type()->scope()!=(*its)->as_typeassigment()->as_named()->type()->scope()){                                                 
                                                    tmp->type()->scope((*its)->as_typeassigment()->as_named()->type()->scope()); //}
                                                }
                                                tmpch.push_back(tmp);
                                            } else
                                                break;
                                        }
                                        if (!tmpch.empty()) {
                                            childs().insert(childs().erase(it), tmpch.begin(), tmpch.end());
                                            find_compomensof = true;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        unicalelerror_throw(childs());
    }

    bool typeassignment_entity::is_resolve_autotag() {
        if ((type()) && (!childs().empty())) {
            bool automatic = true;
            std::size_t num = 0;
            if (type()->tagrule() == automatic_tags) {
                for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                    namedtypeassignment_entity_ptr tmpel = ((*it)->as_typeassigment() && (*it)->as_typeassigment()->as_named()) ?
                        (*it)->as_typeassigment()->as_named() : namedtypeassignment_entity_ptr() ;                    
                    if ((tmpel) && (tmpel->type()) && (tmpel->type()->tag()) &&
                            (tmpel->marker() != mk_components_of)) {
                        if ((tmpel->type()->textualy_tag()) /*|| (num++ > 3)*/) {
                            //debug_warning("warning:  : " + source_throw() + " automatic tagging skiped.");
                            automatic = false;
                            break;
                        }
                    } else
                        num++;
                }
                return automatic;
            }
        }
        return false;
    }

    void typeassignment_entity::post_resolve_autotag() {
        int num = 0;
        basic_entity_vector::iterator fit = first_extention();
        basic_entity_vector::iterator sit = second_extention();
        for (basic_entity_vector::iterator it = childs().begin(); it != fit; ++it) {
            if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                type_atom_ptr tmptype = (*it)->as_typeassigment()->type();
                if ((tmptype) && (!(tmptype->tag()))) {
                    bool isallways_expl = ((tmptype->isnotagged_choice()) || (tmptype->isopen()) ||
                            (tmptype->isdummy()));
                    tmptype-> tag(boost::make_shared<tagged>(boost::make_shared<numvalue_atom>(num++),
                            tcl_context, isallways_expl ? explicit_tags : implicit_tags));
                } else
                    if ((*it)->as_typeassigment()->as_named()->marker() != mk_extention)
                    num++;
            }
        }
        if (sit != childs().end()) {
            for (basic_entity_vector::iterator it = sit; it != childs().end(); ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                    type_atom_ptr tmptype = (*it)->as_typeassigment()->type();
                    if ((tmptype) && (!(tmptype->tag()))) {
                        bool isallways_expl = ((tmptype->isnotagged_choice()) || (tmptype->isopen()) ||
                                (tmptype->isdummy()));
                        tmptype-> tag(boost::make_shared<tagged>(boost::make_shared<numvalue_atom>(num++),
                                tcl_context, isallways_expl ? explicit_tags : implicit_tags));
                    } else
                        if ((*it)->as_typeassigment()->as_named()->marker() != mk_extention)
                        num++;
                }
            }
        }
        if (sit != fit) {
            for (basic_entity_vector::iterator it = fit; it != sit; ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                    type_atom_ptr tmptype = (*it)->as_typeassigment()->type();
                    if ((tmptype) && (!(tmptype->tag()))) {
                        bool isallways_expl = ((tmptype->isnotagged_choice()) || (tmptype->isopen()) ||
                                (tmptype->isdummy()));
                        tmptype-> tag(boost::make_shared<tagged>(boost::make_shared<numvalue_atom>(num++),
                                tcl_context, isallways_expl ? explicit_tags : implicit_tags));
                    } else
                        if ((*it)->as_typeassigment()->as_named()->marker() != mk_extention)
                        num++;
                }
            }
        }
    }


    void typeassignment_entity::post_resolve_check() {
        if ((type()) && (!childs().empty())) {
            if ((type()->builtin() == t_SEQUENCE) || ((type()->builtin() == t_SET))) {
                canonical_tag_set tmpset;
                for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                    namedtypeassignment_entity_ptr tmpel = ((*it)->as_typeassigment() && (*it)->as_typeassigment()->as_named()) ?
                            (*it)->as_typeassigment()->as_named() : namedtypeassignment_entity_ptr();
                    if ((tmpel) && (tmpel->type())) {
                        if (tmpel->type()->cncl_tag()) {
                            if (tmpset.find(tmpel->type()->cncl_tag()) != tmpset.end())
                                referenceerror_throw("Tagging of structured type is ambiguous :", tmpel->name());
                            tmpset.insert(tmpel->type()->cncl_tag());                           
                        } else {
                            canonical_tag_vct tmpelmts = tmpel->cncl_tags();
                            if (!tmpelmts.empty()) {
                                for (canonical_tag_vct::iterator its = tmpelmts.begin(); its != tmpelmts.end(); ++its) {
                                    if (tmpset.find(*its) != tmpset.end())
                                        referenceerror_throw("Tagging of structured type is ambiguous :", tmpel->name());
                                    else
                                        tmpset.insert(*its);
                                }
                            }
                        }
                        if ((type()->builtin() == t_SEQUENCE) && (tmpel->marker() == mk_none))
                            tmpset.clear();
                    }
                }
            } else if (type()->builtin() == t_CHOICE) {
                canonical_tag_set tmpset;
                for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                    namedtypeassignment_entity_ptr tmpel = ((*it)->as_typeassigment() && (*it)->as_typeassigment()->as_named()) ?
                            (*it)->as_typeassigment()->as_named() : namedtypeassignment_entity_ptr();
                    if ((tmpel) && (tmpel->type())) {
                        canonical_tag_vct tmpelmts = tmpel->cncl_tags();
                        if (!tmpelmts.empty()) {
                            for (canonical_tag_vct::iterator its = tmpelmts.begin(); its != tmpelmts.end(); ++its) {
                                if (tmpset.find(*its) != tmpset.end())
                                    referenceerror_throw("Tagging of structured type is ambiguous :", tmpel->name());
                                else
                                    tmpset.insert(*its);
                            }
                        }
                    }
                }
            }
        }
    }




    /////////////////////////////////////////////////////////////////////////   
    // namedtypeassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    namedtypeassignment_entity::namedtypeassignment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, tagmarker_type mrker)
    : typeassignment_entity(scp, nm, tp, true), marker_(mrker) {
    }

    namedtypeassignment_entity::namedtypeassignment_entity(basic_entity_ptr scp, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl)
    : typeassignment_entity(scp, nm, tp, true), marker_(mk_default), default_(vl) {
    }

    namedtypeassignment_entity::namedtypeassignment_entity(basic_entity_ptr scp, type_atom_ptr tp, value_atom_ptr vl)
    : typeassignment_entity(scp, "", tp, true), marker_(mk_exception), default_(vl) {
    }

    namedtypeassignment_entity::namedtypeassignment_entity(basic_entity_ptr scp)
    : typeassignment_entity(scp, "", type_atom_ptr(), true), marker_(mk_extention) {
    }

    void namedtypeassignment_entity::resolve(basic_atom_ptr holder) {
        typeassignment_entity::resolve(holder);
        resolve_default();
    }

    void namedtypeassignment_entity::resolve_default() {
        if (_default())
            _default()->resolve(type());
    }


}
