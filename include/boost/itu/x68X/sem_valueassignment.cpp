//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>

namespace x680 {


    /////////////////////////////////////////////////////////////////////////   
    // VALUE
    ///////////////////////////////////////////////////////////////////////// 
    // value_atom
    /////////////////////////////////////////////////////////////////////////       

    value_atom::value_atom(basic_entity_ptr scp, value_type tpv)
    : basic_atom(at_Value, scp), valtype_(tpv) {
    }

    value_atom::value_atom(basic_entity_ptr scp, const std::string& reff, value_type tpv)
    : basic_atom(at_Value, scp, reff), valtype_(tpv) {
    }

    bool value_atom::isrefferrence() const {
        return (((valtype() == v_defined)
                || (valtype() == v_defined_assign)
                || (valtype() == v_ValueFromObject)) && (reff()));
    }

    numvalue_atom_ptr value_atom::as_number() {
        return (valtype() == v_number) ?
                boost::static_pointer_cast<numvalue_atom> (self()) : numvalue_atom_ptr();
    }

    realvalue_atom_ptr value_atom::as_real() {
        return (valtype() == v_real) ?
                boost::static_pointer_cast<realvalue_atom> (self()) : realvalue_atom_ptr();
    }

    boolvalue_atom_ptr value_atom::as_bool() {
        return (valtype() == v_boolean) ?
                boost::static_pointer_cast<boolvalue_atom> (self()) : boolvalue_atom_ptr();
    }

    strvalue_atom_ptr value_atom::as_cstr() {
        return ((valtype() == v_bstring) || (valtype() == v_hstring) || (valtype() == v_cstring)) ?
                boost::static_pointer_cast<strvalue_atom> (self()) : strvalue_atom_ptr();
    }

    namedvalue_atom_ptr value_atom::as_named() {
        return (valtype() == v_named_value) ?
                boost::static_pointer_cast<namedvalue_atom> (self()) : namedvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_struct() {
        return (valtype() == v_struct) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_objid() {
        return (valtype() == v_objectid) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_valuelist() {
        return (valtype() == v_value_list) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_definedlist() {
        return (valtype() == v_defined_list) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_numberlist() {
        return (valtype() == v_number_list) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    structvalue_atom_ptr value_atom::as_list() {
        return ((valtype() == v_struct) || (valtype() == v_struct) || (valtype() == v_objectid) ||
                (valtype() == v_value_list) || (valtype() == v_defined_list) || (valtype() == v_number_list)) ?
                boost::static_pointer_cast<structvalue_atom> (self()) : structvalue_atom_ptr();
    }

    defined_value_atom_ptr value_atom::as_defined() {
        return (valtype() == v_defined) ?
                boost::static_pointer_cast<defined_value_atom> (self()) : defined_value_atom_ptr();
    }

    fromobject_value_atom_ptr value_atom::as_fromobject() {
        return (valtype() == v_ValueFromObject) ?
                boost::static_pointer_cast<fromobject_value_atom> (self()) : fromobject_value_atom_ptr();
    }

    choicevalue_atom_ptr value_atom::as_choice() {
        return (valtype() == v_choice) ?
                boost::static_pointer_cast<choicevalue_atom> (self()) : choicevalue_atom_ptr();
    }

    openvalue_atom_ptr value_atom::as_open() {
        return (valtype() == v_open) ?
                boost::static_pointer_cast<openvalue_atom> (self()) : openvalue_atom_ptr();
    }

    assignvalue_atom_ptr value_atom::as_assign() {
        return (valtype() == v_defined_assign) ?
                boost::static_pointer_cast<assignvalue_atom> (self()) : assignvalue_atom_ptr();
    }

    nullvalue_atom_ptr value_atom::as_null() {
        return (valtype() == v_null) ?
                boost::static_pointer_cast<nullvalue_atom> (self()) : nullvalue_atom_ptr();
    }

    emptyvalue_atom_ptr value_atom::as_empty() {
        return (valtype() == v_empty) ?
                boost::static_pointer_cast<emptyvalue_atom> (self()) : emptyvalue_atom_ptr();
    }

    void value_atom::resolve_vect(value_vct& vl, basic_atom_ptr holder) {
        for (value_vct::iterator it = vl.begin(); it != vl.end(); ++it)
            (*it)->resolve_reff(holder);
    }

    template<>
    boost::shared_ptr<int64_t> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            return get_value_parent<int64_t>(except_abstract);
        } else if (as_number()) {
            return boost::shared_ptr<int64_t>(new int64_t(static_cast<int64_t> (as_number()->value())));
        }
        return boost::shared_ptr<int64_t>();
    }

    template<>
    boost::shared_ptr<std::string::value_type> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            return get_value_parent<std::string::value_type>(except_abstract);
        } else if (as_cstr()) {
            std::string tmp = as_cstr()->value();
            if (tmp.size() == 1)
                return boost::shared_ptr<std::string::value_type>(new std::string::value_type(tmp[0]));
        }
        return boost::shared_ptr<std::string::value_type>();
    }

    template<>
    boost::shared_ptr<std::size_t> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            return get_value_parent<std::size_t>(except_abstract);
        } else if ((as_number()) && (as_number()->value() >= 0)) {
            return boost::shared_ptr<std::size_t>(new std::size_t(static_cast<std::size_t> (as_number()->value())));
        }
        return boost::shared_ptr<std::size_t>();
    }

    template<>
    boost::shared_ptr<bool> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            return get_value_parent<bool>(except_abstract);
        } else if (as_bool()) {
            return boost::shared_ptr<bool>(new bool(as_bool()->value()));
        }
        return boost::shared_ptr<bool>();
    }

    template<>
    boost::shared_ptr<double> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            return get_value_parent<double>(except_abstract);
        } else if (as_real()) {
            return boost::shared_ptr<double>(new double(as_real()->value()));
        }
        return boost::shared_ptr<double>();
    }

    template<>
    boost::shared_ptr<std::string> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            return get_value_parent<std::string>(except_abstract);
        } else if (as_cstr()) {
            return boost::shared_ptr<std::string>(new std::string(as_cstr()->value()));
        }
        return boost::shared_ptr<std::string>();
    }

    template<>
    boost::shared_ptr<quadruple> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            return get_value_parent<quadruple>(except_abstract);
        } else if (as_list()) {
            boost::shared_ptr<num_vector> fnd = get_value<num_vector>();
            if (fnd) {
                if (fnd->size() == 4) {
                    if (((fnd->operator [](0) >= 0) && (fnd->operator [](0) <= 127)) &&
                            ((fnd->operator [](1) >= 0) && (fnd->operator [](1) <= 255)) &&
                            ((fnd->operator [](2) >= 0) && (fnd->operator [](2) <= 255)) &&
                            ((fnd->operator [](3) >= 0) && (fnd->operator [](3) <= 255)))
                        return boost::shared_ptr<quadruple>(new quadruple(static_cast<uint8_t> (fnd->operator [](0)),
                            static_cast<uint8_t> (fnd->operator [](1)),
                            static_cast<uint8_t> (fnd->operator [](2)),
                            static_cast<uint8_t> (fnd->operator [](3))));
                }
            }
        }
        return boost::shared_ptr<quadruple>();
    }

    template<>
    boost::shared_ptr<tuple> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            if (get_value_parent<tuple>(except_abstract))
                return get_value_parent<tuple>(except_abstract);
            else if (get_value_parent<std::string::value_type>(except_abstract)) {
                boost::shared_ptr<std::string::value_type> tmp = get_value_parent<std::string::value_type>(except_abstract);
                return boost::shared_ptr<tuple>(new tuple(static_cast<uint8_t> (*tmp / 16), static_cast<uint8_t> (*tmp % 16)));
            }
        } else if (as_list()) {
            boost::shared_ptr<num_vector> fnd = get_value<num_vector>();
            if (fnd) {
                if (fnd->size() == 2) {
                    if (((fnd->operator [](0) >= 0) && (fnd->operator [](0) <= 7)) &&
                            ((fnd->operator [](1) >= 0) && (fnd->operator [](1) <= 15)))
                        return boost::shared_ptr<tuple>(new tuple(static_cast<uint8_t> (fnd->operator [](0)),
                            static_cast<uint8_t> (fnd->operator [](1))));
                }
            }
        } else if (get_value<std::string::value_type>(except_abstract)) {
            boost::shared_ptr<std::string::value_type> tmp = get_value<std::string::value_type>(except_abstract);
            return boost::shared_ptr<tuple>(new tuple(static_cast<uint8_t> (*tmp / 16), static_cast<uint8_t> (*tmp % 16)));
        }
        return boost::shared_ptr<tuple>();
    }

    template<>
    boost::shared_ptr<string_vector> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            return get_value_parent<string_vector>(except_abstract);
        }
        return boost::shared_ptr<string_vector>();
    }

    template<>
    boost::shared_ptr<num_vector> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            return get_value_parent<num_vector>(except_abstract);
        } else if (as_list()) {
            structvalue_atom_ptr lst = as_list();
            boost::shared_ptr<num_vector> rslt = boost::shared_ptr<num_vector>(new num_vector());
            for (value_vct::const_iterator it = lst->values().begin(); it != lst->values().end(); ++it) {
                if (*it) {
                    if ((*it)->get_value<int64_t>(except_abstract)) {
                        rslt->push_back(*((*it)->get_value<int64_t>(except_abstract)));
                    } else
                        return boost::shared_ptr<num_vector>();
                } else return boost::shared_ptr<num_vector>();
            }
            return rslt;
        } else if (as_empty()) {
            return boost::shared_ptr<num_vector>(new num_vector());
        }
        return boost::shared_ptr<num_vector>();
    }

    template<>
    boost::shared_ptr<unum_vector> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            return get_value_parent<unum_vector>(except_abstract);
        } else if (as_list()) {
            boost::shared_ptr<unum_vector> rslt = boost::shared_ptr<unum_vector>(new unum_vector());
            for (value_vct::const_iterator it = as_list()->values().begin(); it != as_list()->values().end(); ++it) {
                value_atom_ptr el = *it;
                if (el && (el->as_assign()))
                    el = el->as_assign()->value();

                if (el) {
                    if (el->get_value<std::size_t>(except_abstract)) {
                        rslt->push_back(*(el->get_value<std::size_t>(except_abstract)));
                    } else if (el->get_value<unum_vector>(except_abstract)) {
                        boost::shared_ptr<unum_vector> sub = el->get_value<unum_vector>(except_abstract);
                        rslt->insert(rslt->end(), sub->begin(), sub->end());
                    } else
                        return boost::shared_ptr<unum_vector>();
                } else return boost::shared_ptr<unum_vector>();
            }
            return rslt;
        } else if (as_empty()) {
            return boost::shared_ptr<unum_vector>(new unum_vector());
        }
        return boost::shared_ptr<unum_vector>();
    }

    template<>
    boost::shared_ptr<bstring_initer> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            get_value_parent<bstring_initer>(except_abstract);
        } else if (as_cstr()) {
            std::string tmp = boost::algorithm::to_upper_copy(as_cstr()->value());
            std::string rslt;
            std::size_t cnt = 0;
            int sub = 0;
            if (valtype() == v_bstring) {
                for (std::string::const_iterator it = tmp.begin(); it != tmp.end(); ++it) {
                    sub <<= 1;
                    sub |= (((*it) == '1') ? 0x1 : 0x0);
                    if ((++cnt) == 8) {
                        rslt.insert(rslt.end(), static_cast<std::string::value_type> (sub));
                        cnt = 0;
                        sub = 0;
                    }
                }
                if (cnt > 0) {
                    rslt.insert(rslt.end(), static_cast<std::string::value_type> (sub));
                }
                return boost::shared_ptr<bstring_initer>(new bstring_initer(rslt, cnt ? (8 - cnt) : 0));
            } else if (valtype() == v_hstring) {
                for (std::string::const_iterator it = tmp.begin(); it != tmp.end(); ++it) {
                    sub <<= 4;
                    if ((*it>='\x30') && (*it<='\x39')) 
                        sub |= static_cast<int> (*it - '\x30');
                    else if (((*it>='\x41') && (*it<='\x46')) )
                        sub |= static_cast<int> (*it - '\x41'+'\xA');
                    cnt+=4;
                    if ((cnt) == 8) {
                        rslt.insert(rslt.end(), static_cast<std::string::value_type> ('\xFF' & sub));
                        cnt = 0;
                        sub = 0;
                    }
                }
                if (cnt) {
                    rslt.insert(rslt.end(), static_cast<std::string::value_type> (sub));                    
                }
                return boost::shared_ptr<bstring_initer>(new bstring_initer(rslt, cnt ? 4 : 0));
            }
        } else if (as_empty()) {
            return boost::shared_ptr<bstring_initer>(new bstring_initer());
        }
        return boost::shared_ptr<bstring_initer>();
    }

    template<>
    boost::shared_ptr<hstring_initer> value_atom::get_value(bool except_abstract) {
        boost::shared_ptr<bstring_initer> tmp = get_value<bstring_initer>();
        if (tmp && !(tmp->unused % 8)) {
            return boost::shared_ptr<hstring_initer>(new hstring_initer(tmp->str));
        }
        return boost::shared_ptr<hstring_initer>();
    }

    template<>
    boost::shared_ptr<tuple_vector> value_atom::get_value(bool except_abstract) {
        return boost::shared_ptr<tuple_vector>();
    }

    template<>
    boost::shared_ptr<quadruple_vector> value_atom::get_value(bool except_abstract) {
        if (as_defined()) {
            get_value_parent<bstring_initer>(except_abstract);
        } else if (get_value<quadruple>(except_abstract)) {
            boost::shared_ptr<quadruple_vector> rslt(new quadruple_vector());
            rslt->push_back(*(get_value<quadruple>(except_abstract)));
            return rslt;
        } else if (as_list()) {
            boost::shared_ptr<quadruple_vector> rslt(new quadruple_vector());
            structvalue_atom_ptr lst = as_list();
            for (value_vct::const_iterator it = lst->values().begin(); it != lst->values().end(); ++it) {
                if (*it) {
                    if ((*it)->get_value<quadruple_vector>(except_abstract)){
                        boost::shared_ptr<quadruple_vector> sub=(*it)->get_value<quadruple_vector>(except_abstract);
                        rslt->insert(rslt->end(),sub->begin(), sub->end());
                    } 
                    else break;
                }
            }
            return rslt;
        }
        return boost::shared_ptr<quadruple_vector>();
    }




    /////////////////////////////////////////////////////////////////////////   
    // namedvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void namedvalue_atom::resolve(basic_atom_ptr holder) {
        if (value_)
            value_->resolve_reff(holder);
    }



    /////////////////////////////////////////////////////////////////////////   
    // structvalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void structvalue_atom::resolve(basic_atom_ptr holder) {
        resolve_vect(values_, holder);
    }


    /////////////////////////////////////////////////////////////////////////   
    // defined_value_atom
    /////////////////////////////////////////////////////////////////////////      

    void defined_value_atom::resolve(basic_atom_ptr holder) {
        resolve_reff(holder);
    }


    /////////////////////////////////////////////////////////////////////////     
    // fromobject_value_atom
    /////////////////////////////////////////////////////////////////////////      

    fromobject_value_atom::fromobject_value_atom(basic_entity_ptr scp, const std::string& refffld, object_atom_ptr obj)
    : value_atom(scp, v_ValueFromObject), object_(obj), field_(basic_atom_ptr(new basic_atom(scp, refffld))) {
    };

    void fromobject_value_atom::resolve(basic_atom_ptr holder) {
        if (object())
            object()->resolve(holder);
        if (object()->reff()) {
            assignment_entity_ptr tmpasmt = object()->reff()->as_assigment();
            if (tmpasmt) {
                if (tmpasmt->find_component(field_->expectedname())) {
                    reff(tmpasmt->find_component(field_->expectedname()));
                }
            }
        }
    }


    /////////////////////////////////////////////////////////////////////////   
    // assignvalue_atom
    ///////////////////////////////////////////////////////////////////////// 

    void assignvalue_atom::resolve(basic_atom_ptr holder) {
        if (value_)
            value_->resolve_reff(holder);
        if (value_->reff())
            reff(value_->reff());
    }

    /////////////////////////////////////////////////////////////////////////   
    // choicevalue_atom
    /////////////////////////////////////////////////////////////////////////      

    void choicevalue_atom::resolve(basic_atom_ptr holder) {
        if (value_)
            value_->resolve_reff(holder);
    }


    /////////////////////////////////////////////////////////////////////////   
    // openvalue_atom_atom
    /////////////////////////////////////////////////////////////////////////      

    void openvalue_atom::resolve(basic_atom_ptr holder) {
        if (type_)
            type_->resolve();
        if (value_)
            value_->resolve_reff(type_);
    }



    /////////////////////////////////////////////////////////////////////////   
    // valueassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    valueassignment_entity::valueassignment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, value_atom_ptr vl) :
    assignment_entity(scope, nm, et_Value), type_(tp), value_(vl) {
    };

    void valueassignment_entity::check_value_with_exception(value_type tp) {
        if ((value()) && (value()->root()) && (value()->root()->as_value())) {
            if (value()->root()->as_value()->valtype() != tp)
                throw semantics::error("value '" + name() + "' has invalid type " +
                    modulerefname());
        }
    }

    basic_entity_ptr valueassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        if (sch & local_search) {
            if (((type()->predefined()))) {
                for (basic_entity_vector::iterator it = type()->predefined()->values().begin(); it != type()->predefined()->values().end(); ++it)
                    if ((*it)->name() == nm)
                        return *it;
            }
            if ((type()->reff() && (type()->reff()->name() != nm))) {
                type()->resolve_reff(basic_atom_ptr(), sch);
                if (basic_entity_ptr fnd = type()->reff()->find_by_name(nm, sch))
                    return fnd;
            }
        }
        if (!(sch & extend_search))
            return basic_entity_ptr();
        if (basic_entity_ptr fnd = assignment_entity::find_by_name(nm))
            return fnd;
        if (scope()) {
            prefind(nm, scope()->childs());
            for (basic_entity_vector::iterator it = scope()->childs().begin(); it != scope()->childs().end(); ++it)
                if (nm == (*it)->name())
                    return *it;
        }
        if (scope())
            return scope()->find_by_name(nm, sch);
        return basic_entity_ptr();
    }

    void valueassignment_entity::resolve(basic_atom_ptr holder) {
        assignment_entity::resolve(holder);
        resolve_child();
        type()->resolve();
        if (value())
            value()->resolve(type());
    }



}
