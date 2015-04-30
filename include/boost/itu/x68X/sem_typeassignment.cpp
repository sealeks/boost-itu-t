//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>

namespace x680 {

    /////////////////////////////////////////////////////////////////////////   
    // Effective constraint logic
    /////////////////////////////////////////////////////////////////////////  

    template<typename T>
    T can_effective_constraint(type_atom* vl) {
        return T();
    }

    template<>
    int64_t can_effective_constraint(type_atom* vl) {
        return vl->can_integer_constraints() ? 1 : 0;
    }

    template<>
    std::size_t can_effective_constraint(type_atom* vl) {
        return vl->can_size_constraints() ? 1 : 0;
    }

    template<>
    std::string::value_type can_effective_constraint(type_atom* vl) {
        return vl->can_char8_constraints() ? 1 : 0;
    }

    template<>
    quadruple can_effective_constraint(type_atom* vl) {
        return vl->can_quadruple_constraints() ? MAX_QUADRUPLE : NULL_QUADRUPLE;
    }

    template<>
    tuple can_effective_constraint(type_atom* vl) {
        return vl->can_tuple_constraints() ? MAX_TUPLE : NULL_TUPLE;
    }

    template<typename T>
    static boost::shared_ptr<range_constraints<T> > build_constraints(const constraints_atom_vct& vl, bool alpha) {
        return boost::shared_ptr<range_constraints<T> >();
    }

    template<typename T>
    static bool build_range(valueconstraint_atom_ptr vl, range_constraints<T>& rslt) {
        if (vl && (vl->value()) && (vl->value()->get_value<T>())) {
            rslt = range_constraints<T>(range_constraints<T>::range_type::create_single(*(vl->value()->get_value<T>())));
            return true;
        }
        return false;
    }

    template<typename T>
    bool build_range(rangeconstraint_atom_ptr vl, range_constraints<T>& rslt) {
        if (vl) {
            value_atom_ptr fv = vl->from();
            value_atom_ptr tv = vl->to();
            boost::shared_ptr<T> f;
            boost::shared_ptr<T> t;
            if (fv && (fv->get_value<T>()) && (!fv->get_value<T>(true)))
                return false;
            if (tv && (tv->get_value<T>()) && (!tv->get_value<T>(true)))
                return false;
            if (fv)
                f = fv->get_value<T>(true);
            if (tv)
                t = tv->get_value<T>(true);
            switch (vl->fromtype()) {
                case close_range: break;
                case open_range:
                {
                    if (f) {
                        f = boost::shared_ptr<T>(new T(*f + 1));
                        break;
                    }
                    return false;
                }
                case min_range: f = boost::shared_ptr<T>();
                    break;
                default:
                {
                    return false;
                }
            }

            switch (vl->totype()) {
                case close_range: break;
                case open_range:
                {
                    if (t) {
                        t = boost::shared_ptr<T>(new T(*t - 1));
                        break;
                    }
                    return false;
                }
                case max_range: t = boost::shared_ptr<T>();
                    break;
                default:
                {
                    return false;
                }
            }
            if (f || t) {
                if (f && t) {
                    rslt = range_constraints<T>(range_constraints<T>::range_type::create_range(*f, *t));
                    return true;
                } else if (f) {
                    rslt = range_constraints<T>(range_constraints<T>::range_type::create_more_or_eq(*f));
                    return true;
                } else if (t) {
                    rslt = range_constraints<T>(range_constraints<T>::range_type::create_less_or_eq(*t));
                    return true;
                }
            } else {
                rslt = range_constraints<T>(range_constraints<T>::range_type::create_all());
                return true;
            }
        }
        return false;
    }

    template<typename T>
    static bool build_range_str(rangeconstraint_atom_ptr vl, range_constraints<T>& rslt) {
        if (vl) {
            value_atom_ptr fv = vl->from();
            value_atom_ptr tv = vl->to();
            boost::shared_ptr<T> f;
            boost::shared_ptr<T> t;
            if (fv && (fv->get_value<T>()) && (!fv->get_value<T>(true)))
                return false;
            if (tv && (tv->get_value<T>()) && (!tv->get_value<T>(true)))
                return false;
            if (fv)
                f = fv->get_value<T>(true);
            if (tv)
                t = tv->get_value<T>(true);
            switch (vl->fromtype()) {
                case close_range: break;
                case min_range: f = boost::shared_ptr<T>();
                    break;
                default:
                {
                    return false;
                }
            }

            switch (vl->totype()) {
                case close_range: break;
                case max_range: t = boost::shared_ptr<T>();
                    break;
                default:
                {
                    return false;
                }
            }
            if (f || t) {
                if (f && t) {
                    rslt = range_constraints<T>(range_constraints<T>::range_type::create_range(*f, *t));
                    return true;
                } else if (f) {
                    rslt = range_constraints<T>(range_constraints<T>::range_type::create_more_or_eq(*f));
                    return true;
                } else if (t) {
                    rslt = range_constraints<T>(range_constraints<T>::range_type::create_less_or_eq(*t));
                    return true;
                }
            }
        }
        return false;
    }

    template<>
    bool build_range(rangeconstraint_atom_ptr vl, range_constraints<std::string::value_type>& rslt) {
        return build_range_str<std::string::value_type>(vl, rslt);
    }

    template<>
    bool build_range(rangeconstraint_atom_ptr vl, range_constraints<quadruple>& rslt) {
        return build_range_str<quadruple>(vl, rslt);
    }

    template<>
    bool build_range(rangeconstraint_atom_ptr vl, range_constraints<tuple>& rslt) {
        return build_range_str<tuple>(vl, rslt);
    }

    template<typename T>
    static bool build_range(tvosoconstraint_atom_ptr vl, range_constraints<T>& rslt) {
        if (vl && (vl->as_tvoso())) {
            vl->resolve();
            if (vl->type()) {
                boost::shared_ptr<range_constraints<T> > rslt_ptr = vl->type()->effective_constraint<T>();
                if (rslt_ptr) {
                    rslt = *rslt_ptr;
                    rslt.clear_extention();
                    return true;
                }
            }
        }
        return false;
    }

    template<typename T>
    static bool build_range(typeconstraint_atom_ptr vl, range_constraints<T>& rslt) {
        if (vl && (vl->as_subtypeconstraint())) {
            if (vl->type()) {
                boost::shared_ptr<range_constraints<T> > rslt_ptr = vl->type()->effective_constraint<T>();
                if (rslt_ptr) {
                    rslt = *rslt_ptr;
                    rslt.clear_extention();
                    return true;
                }
            }
        }
        return false;
    }

    template<typename T>
    static boost::shared_ptr< range_constraints<T> > build_serial_constrains(std::stack<range_constraints<T> > vl) {
        if (!vl.empty()) {
            bool has_ext = vl.top().has_extention();
            while (vl.size() != 1) {
                range_constraints<T> rng = vl.top();
                vl.pop();
                if ((!rng.all()) && (!vl.top().include(rng)))
                    throw semantics::error("");
                vl.top() &= rng;
            }
            if (has_ext)
                vl.top().add_extention();
            else
                vl.top().clear_extention();
            if (vl.top().effective())
                return boost::shared_ptr< range_constraints<T> >(new range_constraints<T>(vl.top()));
        }
        return boost::shared_ptr< range_constraints<T> >();
    }

    /////////////////////////////////////////////////
    // Effective  integer constraint logic
    /////////////////////////////////////////////////

    template<>
    integer_constraints_ptr build_constraints(const constraints_atom_vct& vl, bool alpha) {

        typedef std::stack<integer_constraints> integer_constraints_stack;

        integer_constraints_stack stke;
        bool has_ext = false;
        for (constraints_atom_vct::const_iterator ite = vl.begin(); ite != vl.end(); ++ite) {
            if ((*ite)) {
                integer_constraints_stack stki;
                integer_constraints rng;
                has_ext = false;
                for (constraint_atom_vct::const_iterator iti = (*ite)->constraintline().begin(); iti != (*ite)->constraintline().end(); ++iti) {
                    if ((*iti)->as_range()) {
                        if (!build_range<int64_t>((*iti)->as_range(), rng)) {
                            stki = integer_constraints_stack();
                            break;
                        }
                        if (rng.has_extention())
                            has_ext = true;
                        stki.push(rng);
                    } else if ((*iti)->as_valueconstraint()) {
                        if (!build_range<int64_t>((*iti)->as_valueconstraint(), rng)) {
                            stki = integer_constraints_stack();
                            break;
                        }
                        stki.push(rng);
                    } else if ((*iti)->as_subtypeconstraint()) {
                        if (!build_range((*iti)->as_subtypeconstraint(), rng)) {
                            stki = integer_constraints_stack();
                            break;
                        }
                        stki.push(rng);
                    } else if ((*iti)->as_tvoso()) {
                        if (!build_range((*iti)->as_tvoso(), rng)) {
                            stki = integer_constraints_stack();
                            break;
                        }
                        stki.push(rng);
                    } else if ((*iti)->as_union()) {
                        if (stki.size() < 2) {
                            stki = integer_constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() |= rng;
                    } else if ((*iti)->as_intersection()) {
                        if (stki.size() < 2) {
                            stki = integer_constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() &= rng;
                    } else if ((*iti)->as_except()) {
                        if (stki.size() < 2) {
                            stki = integer_constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() -= rng;
                    } else if ((*iti)->as_all()) {
                        stki.push(integer_constraints());
                    } else {
                        stki = integer_constraints_stack();
                        break;
                    }
                }
                if ((stki.size() == 1)) {
                    if (((*ite)->extend()) || has_ext)
                        stki.top().add_extention();
                    stke.push(stki.top());
                }
            }
        }
        return build_serial_constrains<int64_t>(stke);
    }






    /////////////////////////////////////////////////
    //  Effective  size constraint logic
    /////////////////////////////////////////////////   

    static size_constraints_ptr build_size_constraints(constraints_atom_ptr vl) {

        size_constraints_ptr rslt;
        typedef std::stack<size_constraints> size_constraints_stack;
        size_constraints_stack stki;
        size_constraints rng;
        for (constraint_atom_vct::const_iterator iti = vl->constraintline().begin(); iti != vl->constraintline().end(); ++iti) {
            if ((*iti)->as_range()) {
                if (!build_range<std::size_t>((*iti)->as_range(), rng)) {
                    stki = size_constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_valueconstraint()) {
                if (!build_range<std::size_t>((*iti)->as_valueconstraint(), rng)) {
                    stki = size_constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_subtypeconstraint()) {
                if (!build_range((*iti)->as_subtypeconstraint(), rng)) {
                    stki = size_constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_tvoso()) {
                if (!build_range((*iti)->as_tvoso(), rng)) {
                    stki = size_constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_union()) {
                if (stki.size() < 2) {
                    stki = size_constraints_stack();
                    break;
                }
                rng = stki.top();
                stki.pop();
                stki.top() |= rng;
            } else if ((*iti)->as_intersection()) {
                if (stki.size() < 2) {
                    stki = size_constraints_stack();
                    break;
                }
                rng = stki.top();
                stki.pop();
                stki.top() &= rng;
            } else if ((*iti)->as_except()) {
                if (stki.size() < 2) {
                    stki = size_constraints_stack();
                    break;
                }
                rng = stki.top();
                stki.pop();
                stki.top() -= rng;
            } else if ((*iti)->as_all()) {
                stki.push(size_constraints());
            } else {
                stki = size_constraints_stack();
                break;
            }
        }
        if ((stki.size() == 1)) {
            if (vl->extend())
                stki.top().add_extention();
            return size_constraints_ptr(new size_constraints(stki.top()));
        }
        return rslt;
    }

    template<>
    size_constraints_ptr build_constraints(const constraints_atom_vct& vl, bool alpha) {

        typedef std::stack<size_constraints> size_constraints_stack;
        size_constraints_stack stke;
        bool has_ext = false;
        for (constraints_atom_vct::const_iterator ite = vl.begin(); ite != vl.end(); ++ite) {
            if ((*ite)) {
                size_constraints_stack stki;
                size_constraints rng;
                has_ext = false;
                for (constraint_atom_vct::const_iterator iti = (*ite)->constraintline().begin(); iti != (*ite)->constraintline().end(); ++iti) {
                    if ((*iti)->as_size()) {
                        size_constraints_ptr tmp = build_size_constraints((*iti)->as_size()->constraints());
                        if (!tmp) {
                            stki = size_constraints_stack();
                            break;
                        }
                        rng = *tmp;
                        if (rng.has_extention())
                            has_ext = true;
                        stki.push(rng);
                    } else if ((*iti)->as_permitted()) {
                        if (!alpha) {
                            stki = size_constraints_stack();
                            break;
                        }
                        rng = size_constraints();
                        stki.push(rng);
                    } else if ((*iti)->as_subtypeconstraint()) {
                        if (!build_range((*iti)->as_subtypeconstraint(), rng)) {
                            stki = size_constraints_stack();
                            break;
                        }
                        stki.push(rng);
                    } else if ((*iti)->as_tvoso()) {
                        if (!build_range((*iti)->as_tvoso(), rng)) {
                            stki = size_constraints_stack();
                            break;
                        }
                        stki.push(rng);
                    } else if ((*iti)->as_union()) {
                        if (stki.size() < 2) {
                            stki = size_constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() |= rng;
                    } else if ((*iti)->as_intersection()) {
                        if (stki.size() < 2) {
                            stki = size_constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() &= rng;
                    } else if ((*iti)->as_except()) {
                        if (stki.size() < 2) {
                            stki = size_constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() -= rng;
                    } else if ((*iti)->as_all()) {
                        stki.push(size_constraints());
                    } else {
                        stki = size_constraints_stack();
                        break;
                    }
                }
                if ((!stki.empty())) {
                    if (((*ite)->extend()) || (has_ext)) {
                        stki.top().add_extention();
                    }
                    stke.push(stki.top());
                }
            }
        }
        return build_serial_constrains<std::size_t>(stke);
    }


    /////////////////////////////////////////////////
    //  Effective  char8 constraint logik
    /////////////////////////////////////////////////   

    template<typename T>
    boost::shared_ptr<range_constraints<T> > build_alphabet_constraints(constraints_atom_ptr vl) {

        typedef range_constraints<T> constraints_type;
        typedef std::stack<constraints_type> constraints_stack;

        boost::shared_ptr<constraints_type > rslt;
        constraints_stack stki;
        constraints_type rng;
        for (constraint_atom_vct::const_iterator iti = vl->constraintline().begin(); iti != vl->constraintline().end(); ++iti) {
            if ((*iti)->as_range()) {
                if (!build_range((*iti)->as_range(), rng)) {
                    stki = constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_valueconstraint()) {
                if (!build_range((*iti)->as_valueconstraint(), rng)) {
                    stki = constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_subtypeconstraint()) {
                if (!build_range((*iti)->as_subtypeconstraint(), rng)) {
                    stki = constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_tvoso()) {
                if (!build_range((*iti)->as_tvoso(), rng)) {
                    stki = constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_union()) {
                if (stki.size() < 2) {
                    stki = constraints_stack();
                    break;
                }
                rng = stki.top();
                stki.pop();
                stki.top() |= rng;
            } else if ((*iti)->as_intersection()) {
                if (stki.size() < 2) {
                    stki = constraints_stack();
                    break;
                }
                rng = stki.top();
                stki.pop();
                stki.top() &= rng;
            } else if ((*iti)->as_except()) {
                if (stki.size() < 2) {
                    stki = constraints_stack();
                    break;
                }
                rng = stki.top();
                stki.pop();
                stki.top() -= rng;
            } else if ((*iti)->as_all()) {
                stki.push(constraints_type());
            } else {
                stki = constraints_stack();
                break;
            }
        }
        if ((stki.size() == 1)) {
            if (vl->extend())
                stki.top().add_extention();
            return boost::shared_ptr<constraints_type >(new constraints_type(stki.top()));
        }
        return rslt;
    }

    template<typename T>
    boost::shared_ptr<range_constraints<T> > build_alphabet_constraints(const constraints_atom_vct& vl, bool alpha) {

        typedef range_constraints<T> constraints_type;
        typedef std::stack<constraints_type> constraints_stack;

        constraints_stack stke;
        bool has_ext = false;
        for (constraints_atom_vct::const_iterator ite = vl.begin(); ite != vl.end(); ++ite) {
            if ((*ite)) {
                constraints_stack stki;
                constraints_type rng;
                has_ext = false;
                for (constraint_atom_vct::const_iterator iti = (*ite)->constraintline().begin(); iti != (*ite)->constraintline().end(); ++iti) {
                    if ((*iti)->as_permitted()) {
                        boost::shared_ptr<constraints_type> tmp = build_alphabet_constraints<T>((*iti)->as_permitted()->constraints());
                        if (!tmp) {
                            stki = constraints_stack();
                            break;
                        }
                        rng = *tmp;
                        if (rng.has_extention())
                            has_ext = true;
                        stki.push(rng);
                    } else if ((*iti)->as_size()) {
                        rng = constraints_type();
                        stki.push(rng);
                    } else if ((*iti)->as_subtypeconstraint()) {
                        if (!build_range((*iti)->as_subtypeconstraint(), rng)) {
                            stki = constraints_stack();
                            break;
                        }
                        stki.push(rng);
                    } else if ((*iti)->as_tvoso()) {
                        if (!build_range((*iti)->as_tvoso(), rng)) {
                            stki = constraints_stack();
                            break;
                        }
                        stki.push(rng);
                    } else if ((*iti)->as_union()) {
                        if (stki.size() < 2) {
                            stki = constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() |= rng;
                    } else if ((*iti)->as_intersection()) {
                        if (stki.size() < 2) {
                            stki = constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() &= rng;
                    } else if ((*iti)->as_except()) {
                        if (stki.size() < 2) {
                            stki = constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() -= rng;
                    } else if ((*iti)->as_all()) {
                        stki.push(constraints_type());
                    } else {
                        stki = constraints_stack();
                        break;
                    }
                }
                if ((!stki.empty()) || has_ext) {
                    if ((*ite)->extend())
                        stki.top().add_extention();
                    stke.push(stki.top());
                }
            }
        }
        return build_serial_constrains<T>(stke);
    }

    template<>
    char8_constraints_ptr build_constraints(const constraints_atom_vct& vl, bool alpha) {
        return build_alphabet_constraints<std::string::value_type>(vl, alpha);
    }

    template<>
    quadruple_constraints_ptr build_constraints(const constraints_atom_vct& vl, bool alpha) {
        return build_alphabet_constraints<quadruple>(vl, alpha);
    }

    template<>
    tuple_constraints_ptr build_constraints(const constraints_atom_vct& vl, bool alpha) {
        return build_alphabet_constraints<tuple>(vl, alpha);
    }

    /////////////////////////////////////////////////
    //  Calculate effective constraint 
    /////////////////////////////////////////////////     

    template<typename T>
    static boost::shared_ptr<range_constraints<T> > calculate_effective_constraint(type_atom* vl) {
        boost::shared_ptr<range_constraints<T> > rslt;
        boost::shared_ptr<range_constraints<T> > rsltc;
        if (can_effective_constraint<T>(vl)) {
            if ((vl->isrefferrence()) && (vl->reff())) {
                if ((vl->reff()->as_typeassigment()) && (vl->reff()->as_typeassigment()->type()))
                    rslt = vl->reff()->as_typeassigment()->type()->effective_constraint<T>();
            }
            if (vl->has_constraint())
                rsltc = build_constraints<T>(vl->constraints(), vl->can_alphabet_constraints());

            if (rsltc) {
                if (rslt) {
                    rslt->clear_extention();
                    if ((!rsltc->all()) && (!(*rslt).include(*rsltc)))
                        throw semantics::error("");
                    (*rslt) &= *rsltc;
                    if (rsltc->has_extention())
                        rslt->add_extention();
                } else
                    rslt = boost::shared_ptr<range_constraints<T> >(new range_constraints<T>(*rsltc));
            }
        }
        return rslt;
    }

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
    // effective_tabconstraint
    /////////////////////////////////////////////////////////////////////////     

    bool effective_tabconstraint::find_field(const std::string& vl) {
        return std::find(fieldnames_.begin(), fieldnames_.end(), vl) != fieldnames_.end();
    }

    typeassignment_entity_vct effective_tabconstraint::fields(const std::string& nm) {
        typeassignment_entity_vct rslt;
        if (objectsetassignment_ && (objectsetassignment_->objectset())) {
            objectassignment_entity_set oset = objectsetassignment_->objectset()->get_unicalobjects();
            for (objectassignment_entity_set::const_iterator it = oset.begin(); it != oset.end(); ++it) {
                assignment_entity_ptr fndfield = (*it)->find_component(nm);
                if (fndfield) {
                    if (fndfield->as_typeassigment())
                        rslt.push_back(fndfield->as_typeassigment());
                    else if (fndfield->as_valueassigment()) {
                        if (fndfield->as_valueassigment()->type()->valuestructure())
                            rslt.push_back(fndfield->as_valueassigment()->type()->valuestructure());
                    } else if (fndfield->as_valuesetassigment()) {
                        if (fndfield->as_valuesetassigment()->type()->valuestructure())
                            rslt.push_back(fndfield->as_valuesetassigment()->type()->valuestructure());
                    }
                }
                /*else{
                    std::cout << "Field not found :" << nm << std::endl;
                }*/
            }
        }
        return rslt;
    }

    value_vct effective_tabconstraint::fields() {
        value_vct rslt;
        if (objectsetassignment_ && (objectsetassignment_->objectset())) {
            objectassignment_entity_set oset = objectsetassignment_->objectset()->get_unicalobjects();
            for (objectassignment_entity_set::const_iterator it = oset.begin(); it != oset.end(); ++it) {
                assignment_entity_ptr fndfield = (*it)->find_component(unicalfield());
                if (fndfield && (fndfield->as_valueassigment()) && (fndfield->as_valueassigment()->value()))
                    rslt.push_back(fndfield->as_valueassigment()->value());
            }
        }
        return rslt;
    }

    objectassignment_entity_set effective_tabconstraint::objectset() {
        return objectassignment_entity_set();
    }

    std::size_t effective_tabconstraint::count() {
        return (objectsetassignment_ && (objectsetassignment_->objectset())) ?
                objectsetassignment_->objectset()->get_unicalobjects().size() : 0;
    }

    bool effective_tabconstraint::valid() {
        std::size_t cnt=count();
        if (cnt){
            if (fields().size()!=cnt)
                return false;
            for (fieldname_vct::const_iterator it = fieldnames().begin(); it != fieldnames().end(); ++it) {
                if (fields(*it).size()!=cnt)
                    return false;
            }
            return true;            
        }
        return false;
    }

    bool effective_tabconstraint::check() {
        return false;
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

    defined_type type_atom::builtin() const {
        return builtin_;
    }

    tagged_ptr type_atom::tag() const {
        return tag_;
    }

    defined_type type_atom::root_builtin() {
        if (builtin() != t_Reference)
            return builtin();
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
            switch (builtin()) {
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
                    return canonical_tag_ptr(new canonical_tag(builtin()));
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

    type_atom_ptr type_atom::untagged_type() {
        type_atom_ptr rslt(new type_atom(*this));
        rslt->tag(tagged_ptr());
        return rslt;
    }

    template<>
    integer_constraints_ptr type_atom::effective_constraint() {
        return calculate_effective_constraint<int64_t>(this);
    }

    integer_constraints_ptr type_atom::integer_constraint() {
        return effective_constraint<int64_t>();
    }

    template<>
    size_constraints_ptr type_atom::effective_constraint() {
        return calculate_effective_constraint<std::size_t>(this);
    }

    size_constraints_ptr type_atom::size_constraint() {
        return effective_constraint<std::size_t>();
    }

    template<>
    char8_constraints_ptr type_atom::effective_constraint() {
        return calculate_effective_constraint<std::string::value_type>(this);
    }

    char8_constraints_ptr type_atom::char8_constraint() {
        char8_constraints_ptr rslt = effective_constraint<std::string::value_type>();
        if (rslt) {
            if (rslt->has_extention())
                return char8_constraints_ptr();
        }
        return rslt;
    }

    template<>
    quadruple_constraints_ptr type_atom::effective_constraint() {
        return calculate_effective_constraint<quadruple>(this);
    }

    quadruple_constraints_ptr type_atom::quadruple_constraint() {
        return effective_constraint<quadruple>();
    }

    template<>
    tuple_constraints_ptr type_atom::effective_constraint() {
        return calculate_effective_constraint<tuple>(this);
    }

    tuple_constraints_ptr type_atom::tuple_constraint() {
        return effective_constraint<tuple>();
    }

    bool type_atom::isrefferrence() const {
        return (((builtin() == t_Reference)
                || (builtin() == t_TypeFromObject)
                || (builtin() == t_ValueSetFromObjects)) && (reff()));
    }

    bool type_atom::issimplerefferrence() {
        switch (builtin()) {
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
            default:
            {
            }
        }
        return true;
    }

    bool type_atom::isstruct() const {
        return (((builtin() == t_CHOICE) || (builtin() == t_SET) || (builtin() == t_SEQUENCE)));
    }

    bool type_atom::isstruct_of() const {
        return ( (builtin() == t_SET_OF) || (builtin() == t_SEQUENCE_OF));
    }

    bool type_atom::isstructure() const {
        return ((isstruct()) || (isstruct_of()));
    }

    bool type_atom::isopen() const {
        return ((builtin() == t_ClassField) || (builtin() == t_ANY));
    }

    bool type_atom::isenum() const {
        return ((isrefferrence()) && (!tag_) && (constraints_.empty()));
    }

    bool type_atom::can_per_constraints() {
        return (can_char_constraints()) || (can_size_constraints() || (can_integer_constraints()));
    }

    bool type_atom::can_alphabet_constraints() {
        return (can_char_constraints()) && (can_size_constraints());
    }

    bool type_atom::can_char_constraints() {
        switch (root_builtin()) {
            case t_NumericString:
            case t_PrintableString:
            case t_IA5String:
            case t_VisibleString:
            case t_UniversalString:
            case t_BMPString: return true;
            default:
            {
            }
        }
        return false;
    }

    bool type_atom::can_char8_constraints() {
        switch (root_builtin()) {
            case t_NumericString:
            case t_PrintableString:
            case t_VisibleString: return true;
            default:
            {
            }
        }
        return false;
    }

    bool type_atom::can_tuple_constraints() {
        switch (root_builtin()) {
            case t_IA5String: return true;
            default:
            {
            }
        }
        return false;
    }

    bool type_atom::can_quadruple_constraints() {
        switch (root_builtin()) {
            case t_UniversalString:
            case t_BMPString: return true;
            default:
            {
            }
        }
        return false;
    }

    bool type_atom::can_size_constraints() {
        switch (root_builtin()) {
            case t_BIT_STRING:
            case t_OCTET_STRING:
            case t_NumericString:
            case t_PrintableString:
            case t_IA5String:
            case t_VisibleString:
            case t_UniversalString:
            case t_BMPString:
            case t_SEQUENCE_OF:
            case t_SET_OF: return true;
            default:
            {
            }
        }
        return false;
    }

    bool type_atom::isvaluestructure() {
        switch (root_builtin()) {
            case t_EXTERNAL:
            case t_REAL:
            case t_EMBEDDED_PDV:
            case t_SEQUENCE:
            case t_SET:
            case t_CHARACTER_STRING: return true;
            default:
            {
            }
        }
        return false;
    }

    bool type_atom::issubstitute() const {
        switch (builtin()) {
            case t_Selection:
            case t_Instance_Of:
            case t_TypeFromObject: return true;
                //case t_ValueSetFromObjects: return true;
            default:
            {
            }
        }
        return false;
    }

    typeassignment_entity_ptr type_atom::valuestructure() {
        if (isvaluestructure()) {
            if ((reff()) && (reff()->as_typeassigment()) && (reff()->as_typeassigment()->type())) {
                if ((reff()->as_typeassigment()->type()->builtin() == t_SEQUENCE) || (reff()->as_typeassigment()->type()->builtin() == t_SET))
                    return reff()->as_typeassigment();
                return reff()->as_typeassigment()->type()->valuestructure();
            } else if ((scope()) && (scope()->as_typeassigment()) && (scope()->as_typeassigment()->type())) {
                switch (builtin()) {
                        //case t_EXTERNAL:
                        //case t_REAL:
                        //case t_EMBEDDED_PDV:
                    case t_SEQUENCE:
                    case t_SET:
                        //case t_CHARACTER_STRING: 
                        return scope()->as_typeassigment();
                    default:
                    {
                    }
                }
            }
        }
        return typeassignment_entity_ptr();
    }

    bool type_atom::can_integer_constraints() {
        return (root_builtin() == t_INTEGER);
    }

    bool type_atom::istextualy_choice() {
        if (builtin() == t_CHOICE)
            return !tag();
        if (!isrefferrence() || tag())
            return false;
        /// if (reff())
        //    reff()-> resolve();
        if (reff() && (reff()->as_typeassigment())) {
            if (reff()->as_typeassigment()->type())
                return reff()->as_typeassigment()->type()->istextualy_choice();
        }
        return false;
    }

    bool type_atom::isallways_explicit() {
        return (((istextualy_choice()) || (isopen()) ||
                (isdummy())/* || (isdummysource())*/) && (tag()));
    }

    bool type_atom::isprimitive() {
        switch (this->root_builtin()) {
            case t_SEQUENCE:
            case t_SEQUENCE_OF:
            case t_SET:
            case t_SET_OF:
            case t_CHOICE:
            case t_Selection:
            case t_Instance_Of:
            case t_RELATIVE_OID_IRI:
            case t_Reference:
            case t_ANY:
            case t_CHARACTER_STRING:
            case t_TypeFromObject:
            case t_ValueSetFromObjects: return false;
            default:
            {
            }
        }
        return true;
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

    selection_type_atom_ptr type_atom::as_selection() {
        return builtin() == t_Selection ?
                boost::static_pointer_cast<selection_type_atom> (self()) : selection_type_atom_ptr();
    }

    void type_atom::resolve(basic_atom_ptr holder) {
        if (embeded_assignment_ && (embeded_assignment_->as_typeassigment()) && !yetresolved_) {
            yetresolved_ = true;
            embeded_assignment_->resolve_all(holder);
        } else {
            resolve_reff();
            resolve_tag();
            resolve_predef();
            resolve_constraints();
        }
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

    void instanceoftype_atom::resolve_substitute() {
        if (_class()) {
            from_ = typeassignment_entity_ptr(new typeassignment_entity(scope(), ""));
            tagged_ptr tmptg = tagged_ptr(new tagged(value_atom_ptr(new numvalue_atom(8)), tcl_universal));
            type_atom_ptr tmptp = boost::make_shared<type_atom>(scope(), t_SEQUENCE, tmptg);
            from_->type(tmptp);
            from_->childs().push_back(typeassignment_entity_ptr(new namedtypeassignment_entity(from_, "type-id", type_atom_ptr(), mk_none)));
            from_->childs().back()->as_typeassigment()->type(type_atom_ptr(new classfieldtype_atom(from_->childs().back())));
            from_->childs().back()->as_typeassigment()->type()->as_classfield()->field("&id");
            from_->childs().back()->as_typeassigment()->type()->as_classfield()->_class(_class());
            from_->childs().push_back(typeassignment_entity_ptr(new namedtypeassignment_entity(from_, "value", type_atom_ptr(), mk_none)));
            from_->childs().back()->as_typeassigment()->type(type_atom_ptr(new classfieldtype_atom(from_->childs().back())));
            from_->childs().back()->as_typeassigment()->type()->as_classfield()->field("&Type");
            from_->childs().back()->as_typeassigment()->type()->as_classfield()->_class(_class());
            from_->childs().back()->as_typeassigment()->type()->as_classfield()->tag(tagged_ptr(new tagged(value_atom_ptr(new numvalue_atom(0)))));
        }
    }

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
    type_atom(scp, t_ClassField, tg), class_(class_atom_ptr(new class_atom(scp, reffcl))), field_(refffld) {
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

    void fromobject_type_atom::resolve_substitute() {
        if ((object())) {
            assignment_entity_ptr tmpasmt = object()->reff()->as_assigment();
            if (tmpasmt) {
                assignment_entity_ptr fnd = tmpasmt->find_component(field_->expectedname());
                if (fnd && (fnd->as_typeassigment())) {
                    if (fnd->as_typeassigment()->type())
                        fnd->as_typeassigment()->type()->resolve_substitute();
                    reff(fnd);
                    from_ = fnd->as_typeassigment();
                }
                //else
                //scope()->referenceerror_throw("Type from object not resolved ");
            }
        }
    }

    void fromobject_type_atom::resolve(basic_atom_ptr holder) {
        if (object())
            object()->resolve();
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

    void fromobjects_type_atom::resolve_substitute() {

    }

    void fromobjects_type_atom::resolve(basic_atom_ptr holder) {
        if (objectset())
            objectset()->resolve();
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }


    /////////////////////////////////////////////////////////////////////////   
    // selection_type_atom
    /////////////////////////////////////////////////////////////////////////      

    selection_type_atom::selection_type_atom(basic_entity_ptr scp, const std::string& id, type_atom_ptr tp, tagged_ptr tg) :
    type_atom(scp, t_Selection, tg), type_(tp), nidentifier_(id) {
    };

    void selection_type_atom::resolve_substitute() {
        if ((type()) && (type()->reff())) {
            assignment_entity_ptr tmpasmt = type()->reff()->as_assigment();
            if (tmpasmt) {
                assignment_entity_ptr fnd = tmpasmt->find_component(nidentifier_);
                if (fnd && (fnd->as_typeassigment())) {
                    if (fnd->as_typeassigment()->type())
                        fnd->as_typeassigment()->type()->resolve_substitute();
                    reff(fnd);
                    from_ = fnd->as_typeassigment();
                }
                //else
                //scope()->referenceerror_throw("Type from object not resolved ");
            }
        }
    }

    void selection_type_atom::resolve(basic_atom_ptr holder) {
        if (type())
            type()->resolve(holder);
        resolve_tag();
        resolve_predef();
        resolve_constraints();
    }


    /////////////////////////////////////////////////////////////////////////   
    // typeassignment_entity
    /////////////////////////////////////////////////////////////////////////  

    typeassignment_entity::typeassignment_entity(basic_entity_ptr scope, const std::string& nm, type_atom_ptr tp, bool nmd) :
    assignment_entity(scope, nm, et_Type), type_(tp), named_(nmd), unicalfield_(false) {
    };

    typeassignment_entity::typeassignment_entity(basic_entity_ptr scope, bool nmd) :
    assignment_entity(scope, et_Type), named_(nmd), unicalfield_(false) {
    };

    basic_atom_ptr typeassignment_entity::atom() const {
        return type_;
    }

    type_atom_ptr typeassignment_entity::type() const {
        return type_;
    }


    ////////

    basic_entity_ptr typeassignment_entity::find_by_name(const std::string& nm, search_marker sch) {
        type_atom_ptr tmptype = type();
        if (sch & local_search) {
            if (((tmptype->predefined()))) {
                for (basic_entity_vector::iterator it = tmptype->predefined()->values().begin(); it != tmptype->predefined()->values().end(); ++it)
                    if ((*it)->name() == nm)
                        return *it;
            }
            if (tmptype->reff() && (tmptype->reff()->name() != nm)) {
                tmptype->resolve_reff();
                if (basic_entity_ptr fnd = tmptype->reff()->find_by_name(nm, sch))
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

    bool typeassignment_entity::isdefined_choice() {
        type_atom_ptr tmptype = type();
        if (islocaldefined()) {
            if (tag()) {
                return (tmptype && tmptype->untagged_type() && (tmptype->untagged_type() ->istextualy_choice()));
            }
        }
        return (tmptype && ((istextualy_choice()) || (type()->builtin() == t_CHOICE)));
    }

    bool typeassignment_entity::islocaldeclare() const {
        type_atom_ptr tmptype = type();
        if (scope() && (scope()->as_typeassigment()) && (tmptype))
            return (tmptype->isstructure());
        return false;
    }

    bool typeassignment_entity::islocaldefined() const {
        if (scope() && (scope()->as_typeassigment()) && (type()))
            return true;
        return false;
    }

    canonical_tag_vct typeassignment_entity::cncl_tags() {
        type_atom_ptr tmptype = type();
        canonical_tag_vct tmp;
        if (tmptype) {
            if (tmptype->istextualy_choice()) {
                if (tmptype->builtin() == t_CHOICE) {
                    if ((tmptype->tag()) && (tmptype->cncl_tag())) {
                        tmp.push_back(tmptype->cncl_tag());
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
                    if ((tmptype->reff()) && (tmptype->reff()->as_typeassigment()))
                        tmp = tmptype->reff()->as_typeassigment()->cncl_tags();
                }
            } else {
                if (tmptype->cncl_tag())
                    tmp.push_back(tmptype->cncl_tag());
            }
        }
        return tmp;
    }

    typeassignment_entity_ptr typeassignment_entity::superfluous_assignment(module_entity_ptr mod) {
        type_atom_ptr tmptype = type();
        if (tmptype && (!tag()) && (tmptype->reff()) && mod) {
            typeassignment_entity_ptr rf = ((tmptype->reff()) && (tmptype->reff()->as_typeassigment())) ?
                    tmptype->reff()->as_typeassigment() : typeassignment_entity_ptr();
            if (rf && (rf->moduleref() == mod)) {
                return rf;
            }
        }
        return typeassignment_entity_ptr();
    }

    namedtypeassignment_entity_ptr typeassignment_entity::as_named() {
        return named() ?
                boost::static_pointer_cast<namedtypeassignment_entity> (self()) : namedtypeassignment_entity_ptr();
    }

    void typeassignment_entity::resolve(basic_atom_ptr holder) {
        unicalelerror_throw(childs());
        assignment_entity::resolve(holder);
        if (type_)
            type_->resolve();
        assignment_entity::resolve_complex<typeassignment_entity>();
        resolve_child();
        post_resolve_child();

    }

    void typeassignment_entity::after_resolve() {
        type_atom_ptr tmptype = type();
        if (tmptype && (tmptype->can_per_constraints())) {
            try {
                tmptype->integer_constraint();
                tmptype->size_constraint();
                tmptype->char8_constraint();
                tmptype->quadruple_constraint();
                tmptype->tuple_constraint();
            } catch (...) {
                referenceerror_throw("Constraint error");
            }
        }
        after_resolve_child();
        post_resolve_tabconstraint();
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
        if (shadow())
            return;
        if (parameterized() || (has_arguments()))
            return;
        if (type_ && (type_->issubstitute())) {
            substitute();
        }
        type_atom_ptr tmptype = type();
        if ((tmptype) && (!childs().empty())) {
            if ((tmptype->builtin() == t_SEQUENCE) || ((tmptype->builtin() == t_SET))) {
                bool find_compomensof = true;
                while (find_compomensof) {
                    find_compomensof = false;
                    for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                        if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                            namedtypeassignment_entity_ptr named = (*it)->as_typeassigment()->as_named();
                            if ((named->marker() == mk_components_of)) {
                                typeassignment_entity_ptr issue = named;
                                if (basic_entity_ptr namedreff = named->type()->reff()) {
                                    issue = namedreff->as_typeassigment();
                                    namedreff->resolve();
                                }
                                basic_entity_vector tmpch;
                                if ((issue) && (!issue->childs().empty())) {
                                    if (!issue->type())
                                        referenceerror_throw("Undefined type", name());
                                    if (issue->type()->root_builtin() != type()->builtin())
                                        referenceerror_throw("Apply COMPONENT OF error", name());
                                    for (basic_entity_vector::iterator its = issue->childs().begin();
                                            its != issue->childs().end(); ++its) {
                                        if (!is_extention((*its)->as_typeassigment()->as_named()->marker())) {
                                            namedtypeassignment_entity_ptr tmp = (*its)->as_typeassigment()->clone<namedtypeassignment_entity>(scope(), false);
                                            if (tmp)
                                                tmpch.push_back(tmp);
                                        } else
                                            break;
                                    }
                                    if (!tmpch.empty()) {
                                        for (basic_entity_vector::iterator itr = tmpch.begin();
                                                itr != tmpch.end(); ++itr) {
                                            if (*itr) {
                                                (*itr)->preresolve();
                                                (*itr)->resolve();
                                                (*itr)->shadow_for(issue);
                                            }
                                        }
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
        unicalelerror_throw(childs());
    }

    bool typeassignment_entity::is_resolve_autotag() {
        if (parameterized() || (has_arguments()))
            return false;
        if (shadow())
            return false;
        type_atom_ptr tmptype = type();
        if ((tmptype) && (!childs().empty())) {
            bool automatic = true;
            std::size_t num = 0;
            if (tmptype->tagrule() == automatic_tags) {
                for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                    namedtypeassignment_entity_ptr tmpel = ((*it)->as_typeassigment() && (*it)->as_typeassigment()->as_named()) ?
                            (*it)->as_typeassigment()->as_named() : namedtypeassignment_entity_ptr();
                    type_atom_ptr tmptype1 = tmpel ? (tmpel->type()) : type_atom_ptr();
                    if ((tmptype1) && (tmptype1->tag()) &&
                            (tmpel->marker() != mk_components_of)) {
                        if ((tmptype1->textualy_tag()) /*|| (num++ > 3)*/) {
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
        if (parameterized() || (has_arguments()))
            return;
        if (shadow())
            return;
        int num = 0;
        basic_entity_vector::iterator fit = first_extention();
        basic_entity_vector::iterator sit = second_extention();
        for (basic_entity_vector::iterator it = childs().begin(); it != fit; ++it) {
            if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                type_atom_ptr tmptype = (*it)->as_typeassigment()->type();
                if ((tmptype) && (!(tmptype->tag()))) {
                    bool isallways_expl = ((tmptype->istextualy_choice()) || (tmptype->isopen()) ||
                            (tmptype->isdummy()));
                    tmptype-> tag(boost::make_shared<tagged>(boost::make_shared<numvalue_atom>(num++),
                            tcl_context, isallways_expl ? explicit_tags : implicit_tags));
                } else
                    if (!is_extention((*it)->as_typeassigment()->as_named()->marker()))
                    num++;
            }
        }
        if (sit != childs().end()) {
            for (basic_entity_vector::iterator it = sit; it != childs().end(); ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                    type_atom_ptr tmptype = (*it)->as_typeassigment()->type();
                    if ((tmptype) && (!(tmptype->tag()))) {
                        bool isallways_expl = ((tmptype->istextualy_choice()) || (tmptype->isopen()) ||
                                (tmptype->isdummy()));
                        tmptype-> tag(boost::make_shared<tagged>(boost::make_shared<numvalue_atom>(num++),
                                tcl_context, isallways_expl ? explicit_tags : implicit_tags));
                    } else
                        if (!is_extention((*it)->as_typeassigment()->as_named()->marker()))
                        num++;
                }
            }
        }
        if (sit != fit) {
            for (basic_entity_vector::iterator it = fit; it != sit; ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                    type_atom_ptr tmptype = (*it)->as_typeassigment()->type();
                    if ((tmptype) && (!(tmptype->tag()))) {
                        bool isallways_expl = ((tmptype->istextualy_choice()) || (tmptype->isopen()) ||
                                (tmptype->isdummy()));
                        tmptype-> tag(boost::make_shared<tagged>(boost::make_shared<numvalue_atom>(num++),
                                tcl_context, isallways_expl ? explicit_tags : implicit_tags));
                    } else
                        if (!is_extention((*it)->as_typeassigment()->as_named()->marker()))
                        num++;
                }
            }
        }
    }

    std::string subidentifier_helper(std::string& nm) {
        std::string rslt = nm;
        std::string::size_type it = nm.find_first_of('.');
        if ((it != std::string::npos) && ((it) && (it < (nm.size() - 1)))) {
            rslt = nm.substr(0, it);
            nm = nm.substr(it + 1);
        } else
            nm = "";
        return rslt;
    }

    static objectsetassignment_entity_ptr find_os_assign_tc_helper(objectset_atom_ptr vl) {
        if (vl->as_defn()) {
            if (vl->as_defn()->objects().size() == 1) {
                object_atom_ptr obj = vl->as_defn()->objects().front();
                if (obj->as_definedset()) {
                    objectset_atom_ptr objset = obj->as_definedset()->objectset();
                    if (objset && (objset->reff()) && (objset->reff()->as_objectsetassigment()))
                        return objset->reff()->as_objectsetassigment();
                }
            }
        } else if (vl->as_defined()) {
            if ((vl->reff()) && (vl->reff()->as_objectsetassigment()))
                return vl->reff()->as_objectsetassigment();
        }
        return objectsetassignment_entity_ptr();
    }

    static classassignment_entity_ptr find_cl_assign_tc_helper(objectset_atom_ptr vl) {
        objectsetassignment_entity_ptr objsetass = find_os_assign_tc_helper(vl);
        if (objsetass && (objsetass->_class()) && (objsetass->_class()->reff()))
            if (objsetass->_class()->reff()->as_classassigment())
                return objsetass->_class()->reff()->as_classassigment();
        return classassignment_entity_ptr();
    }

    static field_entity_ptr find_field_tc_helper(objectset_atom_ptr vl, const std::string& fld) {
        std::string tmp = fld;
        classassignment_entity_ptr classass = find_cl_assign_tc_helper(vl);
        while (classass) {
            std::string tmpfldname = subidentifier_helper(tmp);
            field_entity_ptr tmpfld = classass->find_field_by_name(tmpfldname);
            if (classass && tmpfld) {
                if (tmp.empty())
                    return tmpfld;
                class_atom_ptr clatm;
                if ((tmpfld->as_objectsetfield()) && (tmpfld->as_objectsetfield()->_class()))
                    clatm = tmpfld->as_objectsetfield()->_class();
                else if ((tmpfld->as_objectsetfield()) && (tmpfld->as_objectfield()->_class()))
                    clatm = tmpfld->as_objectsetfield()->_class();
                else
                    break;
                if (clatm && (clatm->reff()) && (clatm->reff()->as_classassigment())) {
                    if ((clatm->reff()->as_classassigment()->refference_to())
                            && (clatm->reff()->as_classassigment()->refference_to()->as_classassigment())) {
                        classass = clatm->reff()->as_classassigment()->refference_to()->as_classassigment();
                    } else
                        break;
                } else
                    break;
            } else
                break;
        }
        return field_entity_ptr();
    }

    static typeassignment_entity_ptr find_parent_constraint_holder_helper(typeassignment_entity_ptr vl) {
        if (vl->tabconstraint())
            return vl;
        if ((vl->parent()) && (vl->parent()->as_typeassigment()))
            return find_parent_constraint_holder_helper(vl->parent()->as_typeassigment());
        return typeassignment_entity_ptr();
    }

    void typeassignment_entity::post_resolve_tabconstraint() {
        typeassignment_entity_ptr prnt = parent() ? parent()->as_typeassigment() : typeassignment_entity_ptr();
        if ((type()) && (!type()->constraints().empty())
                && (as_named()) && (type()->constraints().size() == 1) && prnt) {
            constraints_atom_ptr tmpcnstrs = type()->constraints().front();
            if (tmpcnstrs && (tmpcnstrs->constraintline().size() == 1)) {
                constraint_atom_ptr tmpcnstr = tmpcnstrs->constraintline().front();
                if (tmpcnstr->as_table()) {
                    tableconstraint_atom_ptr tmptabcnstr = tmpcnstr->as_table();
                    if (tmptabcnstr) {
                        if ((!prnt->childs().empty())
                                /*&& (scope()->childs().front() == self())*/) {
                            objectset_atom_ptr objst = tmptabcnstr->objectset();
                            objectsetassignment_entity_ptr objass = find_os_assign_tc_helper(objst);
                            classassignment_entity_ptr clsass = find_cl_assign_tc_helper(objst);
                            if ((type()) && (type()->as_classfield())) {
                                field_entity_ptr fld = find_field_tc_helper(objst, type()->as_classfield()->field());
                                if (fld && clsass && (fld ->as_valuefield())) {
                                    type_atom_ptr typevl = fld ->as_valuefield()->type();
                                    defined_type untp = typevl->root_builtin();
                                    if (untp != t_NODEF) {
                                        if (prnt) {
                                            unicalfield(true);
                                            prnt->tabconstraint(effective_tabconstraint_ptr(new effective_tabconstraint(scope(), clsass, objass, untp)));
                                            prnt->tabconstraint()->unicalfield(type()->as_classfield()->field());
                                            reff_tabconstraint(prnt->tabconstraint());
                                        }
                                    } else
                                        std::cout << "warning: Table constraint have not resolved. Governer field type not supported." << std::endl;
                                } else
                                    std::cout << "warning: Table constraint have not resolved. Class field sould be valuefield." << std::endl;
                            } else
                                std::cout << "warning: Table constraint have not resolved. Type sould be classfield type." << std::endl;
                        } else
                            std::cout << "warning: Table constraint have not resolved. Governer field should be first." << std::endl;
                        //if ((type()) && (type()->as_classfield()))
                        //std::cout << type()->as_classfield()->field() << std::endl;
                    }
                } else if (tmpcnstr->as_relation()) {
                    relationconstraint_atom_ptr tmprelcnstr = tmpcnstr->as_relation();
                    if (tmprelcnstr) {
                        prnt = find_parent_constraint_holder_helper(prnt);
                        if (prnt && (prnt->tabconstraint())) {
                            objectset_atom_ptr objst = tmprelcnstr->objectset();
                            objectsetassignment_entity_ptr objass = find_os_assign_tc_helper(objst);
                            classassignment_entity_ptr clsass = find_cl_assign_tc_helper(objst);
                            effective_tabconstraint_ptr efftab = prnt->tabconstraint();
                            if (efftab && clsass && objass && (efftab->_class() == clsass) && (efftab->objectsetassignment() == objass)) {
                                if ((type()) && (type()->as_classfield())) {
                                    if (!prnt->tabconstraint()->find_field(type()->as_classfield()->field()))
                                        efftab->fieldnames().push_back(type()->as_classfield()->field());
                                    reff_tabconstraint(prnt->tabconstraint());
                                } else
                                    std::cout << "warning: Relation constraint have not resolved. Type sould be classfield type." << std::endl;
                            } else
                                std::cout << "warning: Relation constraint have not resolved. Class or Objectassignment notequal with table constrant." << std::endl;
                        } else
                            std::cout << "warning: Relation constraint have not resolved. Table constraint have not find.." << std::endl;
                        //if ((type()) && (type()->as_classfield()))
                        // std::cout << type()->as_classfield()->field() << std::endl;                        
                    }
                }
            }
        }
    }

    void typeassignment_entity::post_resolve_check() {
        //return;
        if (shadow())
            return;
        if (parameterized() || (has_arguments()))
            return;
        type_atom_ptr tmptype = type();
        if ((tmptype) && (!childs().empty())) {
            if ((tmptype->builtin() == t_SEQUENCE) || ((tmptype->builtin() == t_SET))) {
                canonical_tag_set tmpset;
                for (basic_entity_vector::iterator it = childs().begin(); it != childs().end(); ++it) {
                    namedtypeassignment_entity_ptr tmpel = ((*it)->as_typeassigment() && (*it)->as_typeassigment()->as_named()) ?
                            (*it)->as_typeassigment()->as_named() : namedtypeassignment_entity_ptr();
                    type_atom_ptr tmptype1 = tmpel ? (tmpel->type()) : type_atom_ptr();
                    if ((tmpel) && (tmptype1)) {
                        if (tmptype1->cncl_tag()) {
                            if (tmpset.find(tmptype1->cncl_tag()) != tmpset.end())
                                referenceerror_throw("Tagging of structured type is ambiguous :", tmpel->name());
                            tmpset.insert(tmptype1->cncl_tag());
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
                        if ((tmptype->builtin() == t_SEQUENCE) && (tmpel->marker() == mk_none))
                            tmpset.clear();
                    }
                }
            } else if (tmptype->builtin() == t_CHOICE) {
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

    void typeassignment_entity::assign_from(assignment_entity_ptr from) {
        if (from->as_typeassigment()) {
            assignment_entity::assign_from(from);
            type_atom_ptr selftype = type_;
            if (from->as_typeassigment()->type_) {
                if (from->as_typeassigment()->type_->as_classfield())
                    type_ = type_atom_ptr(new classfieldtype_atom(*(from->as_typeassigment()->type_->as_classfield())));
                else if (from->as_typeassigment()->type_->as_fromobject())
                    type_ = type_atom_ptr(new fromobject_type_atom(*(from->as_typeassigment()->type_->as_fromobject())));
                else if (from->as_typeassigment()->type_->as_fromobjectset())
                    type_ = type_atom_ptr(new fromobjects_type_atom(*(from->as_typeassigment()->type_->as_fromobjectset())));
                else if (from->as_typeassigment()->type_->as_instance())
                    type_ = type_atom_ptr(new instanceoftype_atom(*(from->as_typeassigment()->type_->as_instance())));
                else if (from->as_typeassigment()->type_->as_selection())
                    type_ = type_atom_ptr(new selection_type_atom(*(from->as_typeassigment()->type_->as_selection())));
                else
                    type_ = type_atom_ptr(new type_atom(*(from->as_typeassigment()->type_)));
            }
            if (selftype && type_) {
                if (selftype->constraints().empty())
                    type_->constraints().insert(type_->constraints().end(), selftype->constraints().begin(), selftype->constraints().end());
                if ((selftype->tag()) && (!type_->tag()))
                    type_->tag(tagged_ptr(new tagged(*(selftype->tag()))));
                if ((selftype->predefined()) && (!type_->predefined()))
                    type_->predefined(predefined_ptr(new x680::predefined(*(selftype->predefined()))));
                if ((selftype->embeded_assignment()))
                    type_->embeded_assignment(selftype->embeded_assignment());
            }
            if (from->as_typeassigment()->tabconstraint_)
                tabconstraint_ = from->as_typeassigment()->tabconstraint_;
        }
    }

    void typeassignment_entity::substitute() {
        if (type_ && !(has_rootarguments())) {
            type_->resolve_substitute();
            typeassignment_entity_ptr subtype = type_->from();
            if (subtype) {
                if (!type_->as_instance()) {
                    subtype = subtype->clone<typeassignment_entity>(basic_entity_ptr(), false);
                    subtype->preresolve();
                    subtype->resolve();
                }
                assign_from(subtype);
            } else
                referenceerror_throw("Subtitute type error :");
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

    namedtypeassignment_entity::namedtypeassignment_entity(basic_entity_ptr scp,  tagmarker_type mrker)
    : typeassignment_entity(scp, "", type_atom_ptr(), true), marker_(mrker) {
    }

    void namedtypeassignment_entity::resolve(basic_atom_ptr holder) {
        typeassignment_entity::resolve(holder);
        resolve_default();
    }

    void namedtypeassignment_entity::resolve_default() {
        if (_default()) {
            _default()->reff_resolver(type());
            _default()->resolve(type());
        }
    }


}
