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
    static bool build_range(rangeconstraint_atom_ptr vl, range_constraints<T>& rslt) {
        if (vl) {         
            value_atom_ptr fv = vl->from();
            value_atom_ptr tv = vl->to();            
            boost::shared_ptr<T> f;
            boost::shared_ptr<T> t;
            if (fv && (fv->get_value<T>()) && (!fv->get_value<T>(true)))
                return false;
            if (tv && (tv->get_value<T>()) && (!tv->get_value<T>(true)))
                return false;
            if (fv )
                f=fv->get_value<T>(true);
            if (tv )
                t=tv->get_value<T>(true);            
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
            }
            else {
                rslt = range_constraints<T>(range_constraints<T>::range_type::create_all());
                return true;                
            }        
        }
        return false;
    }
    
    static bool build_range_str8(rangeconstraint_atom_ptr vl, char8_constraints& rslt) {
        if (vl) {
            value_atom_ptr fv = vl->from();
            value_atom_ptr tv = vl->to();
            boost::shared_ptr<std::string::value_type> f;
            boost::shared_ptr<std::string::value_type> t;
            if (fv && (fv->get_value<std::string::value_type>()) && (!fv->get_value<std::string::value_type>(true)))
                return false;
            if (tv && (tv->get_value<std::string::value_type>()) && (!tv->get_value<std::string::value_type>(true)))
                return false;
            if (fv )
                f=fv->get_value<std::string::value_type>(true);
            if (tv )
                t=tv->get_value<std::string::value_type>(true);            
            switch (vl->fromtype()) {
                case close_range: break;
                case min_range: f = boost::shared_ptr<std::string::value_type>();
                    break;
                default:
                {
                    return false;
                }
            }

            switch (vl->totype()) {
                case close_range: break;
                case max_range: t = boost::shared_ptr<std::string::value_type>();
                    break;
                default:
                {
                    return false;
                }
            }
            if (f || t) {
                if (f && t) {
                    rslt = range_constraints<std::string::value_type>(range_constraints<std::string::value_type>::range_type::create_range(*f, *t));
                    return true;
                } else if (f) {
                    rslt = range_constraints<std::string::value_type>(range_constraints<std::string::value_type>::range_type::create_more_or_eq(*f));
                    return true;
                } else if (t) {
                    rslt = range_constraints<std::string::value_type>(range_constraints<std::string::value_type>::range_type::create_less_or_eq(*t));
                    return true;
                }
            }
        }
        return false;
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
        if (vl && (vl->as_typeconstraint())) {
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
            bool has_ext=vl.top().has_extention();
            while (vl.size() != 1) {
                range_constraints<T> rng = vl.top();
                vl.pop();                    
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
        bool has_ext=false;
        for (constraints_atom_vct::const_iterator ite = vl.begin(); ite != vl.end(); ++ite) {
            if ((*ite)) {
                integer_constraints_stack stki;
                integer_constraints rng;
                has_ext=false;
                for (constraint_atom_vct::const_iterator iti = (*ite)->constraintline().begin(); iti != (*ite)->constraintline().end(); ++iti) {
                    if ((*iti)->as_range()) {
                        if (!build_range<int64_t>((*iti)->as_range(), rng)) {
                            stki = integer_constraints_stack();
                            break;
                        }
                        if (rng.has_extention())
                            has_ext=true;
                        stki.push(rng);
                    } else if ((*iti)->as_valueconstraint()) {
                        if (!build_range<int64_t>((*iti)->as_valueconstraint(), rng)) {
                            stki = integer_constraints_stack();
                            break;
                        }
                        stki.push(rng);
                    } else if ((*iti)->as_typeconstraint()) {
                        if (!build_range((*iti)->as_typeconstraint(), rng)) {
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
                    } else if ((*iti)->as_allexcept()) {
                        if (stki.size() < 1) {
                            stki = integer_constraints_stack();
                            break;
                        }
                        rng = integer_constraints();
                        rng -= stki.top();
                        stki.top() = rng;
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
            } else if ((*iti)->as_typeconstraint()) {
                if (!build_range((*iti)->as_typeconstraint(), rng)) {
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
            } else if ((*iti)->as_allexcept()) {
                if (stki.size() < 1) {
                    stki = size_constraints_stack();
                    break;
                }
                rng = size_constraints();
                rng -= stki.top();
                stki.top() = rng;
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
        bool has_ext=false;
        for (constraints_atom_vct::const_iterator ite = vl.begin(); ite != vl.end(); ++ite) {
            if ((*ite)) {
                size_constraints_stack stki;
                size_constraints rng;
                has_ext=false;
                for (constraint_atom_vct::const_iterator iti = (*ite)->constraintline().begin(); iti != (*ite)->constraintline().end(); ++iti) {
                    if ((*iti)->as_size()) {
                        size_constraints_ptr tmp = build_size_constraints((*iti)->as_size()->constraints());
                        if (!tmp) {
                            stki = size_constraints_stack();
                            break;
                        }
                        rng = *tmp;
                        if (rng.has_extention())
                            has_ext=true;
                        stki.push(rng);
                    } else if ((*iti)->as_permitted()) {
                        if (!alpha) {
                            stki = size_constraints_stack();
                            break;
                        }
                        rng = size_constraints();
                        stki.push(rng);
                    } else if ((*iti)->as_typeconstraint()) {
                        if (!build_range((*iti)->as_typeconstraint(), rng)) {
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
                    } else if ((*iti)->as_allexcept()) {
                        if (stki.size() < 1) {
                            stki = size_constraints_stack();
                            break;
                        }
                        rng = size_constraints();
                        rng -= stki.top();
                        stki.top() = rng;
                    } else {
                        stki = size_constraints_stack();
                        break;
                    }
                }
                if ((!stki.empty())) {
                    if (((*ite)->extend()) || (has_ext)){
                        stki.top().add_extention();}
                    stke.push(stki.top());
                }
            }
        }
        return build_serial_constrains<std::size_t>(stke);
    }


    /////////////////////////////////////////////////
    //  Effective  char8 constraint logik
    /////////////////////////////////////////////////   

    static char8_constraints_ptr build_char8_constraints(constraints_atom_ptr vl) {

        char8_constraints_ptr rslt;
        typedef std::stack<char8_constraints> char8_constraints_stack;
        char8_constraints_stack stki;
        char8_constraints rng;
        for (constraint_atom_vct::const_iterator iti = vl->constraintline().begin(); iti != vl->constraintline().end(); ++iti) {
            if ((*iti)->as_range()) {
                if (!build_range_str8((*iti)->as_range(), rng)) {
                    stki = char8_constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_valueconstraint()) {
                if (!build_range((*iti)->as_valueconstraint(), rng)) {
                    stki = char8_constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_typeconstraint()) {
                if (!build_range((*iti)->as_typeconstraint(), rng)) {
                    stki = char8_constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_tvoso()) {
                if (!build_range((*iti)->as_tvoso(), rng)) {
                    stki = char8_constraints_stack();
                    break;
                }
                stki.push(rng);
            } else if ((*iti)->as_union()) {
                if (stki.size() < 2) {
                    stki = char8_constraints_stack();
                    break;
                }
                rng = stki.top();
                stki.pop();
                stki.top() |= rng;
            } else if ((*iti)->as_intersection()) {
                if (stki.size() < 2) {
                    stki = char8_constraints_stack();
                    break;
                }
                rng = stki.top();
                stki.pop();
                stki.top() &= rng;
            } else if ((*iti)->as_except()) {
                if (stki.size() < 2) {
                    stki = char8_constraints_stack();
                    break;
                }
                rng = stki.top();
                stki.pop();
                stki.top() -= rng;
            } else if ((*iti)->as_allexcept()) {
                if (stki.size() < 1) {
                    stki = char8_constraints_stack();
                    break;
                }
                rng = char8_constraints();
                rng -= stki.top();
                stki.top() = rng;
            } else {
                stki = char8_constraints_stack();
                break;
            }
        }
        if ((stki.size() == 1)) {
            if (vl->extend())
                stki.top().add_extention();
            return char8_constraints_ptr(new char8_constraints(stki.top()));
        }
        return rslt;
    }

    template<>
    char8_constraints_ptr build_constraints(const constraints_atom_vct& vl, bool alpha) {
        
        typedef std::stack<char8_constraints> char8_constraints_stack;
        
        char8_constraints_stack stke;
        bool has_ext=false;
        for (constraints_atom_vct::const_iterator ite = vl.begin(); ite != vl.end(); ++ite) {
            if ((*ite)) {
                char8_constraints_stack stki;
                char8_constraints rng;
                has_ext=false;
                for (constraint_atom_vct::const_iterator iti = (*ite)->constraintline().begin(); iti != (*ite)->constraintline().end(); ++iti) {
                    if ((*iti)->as_permitted()) {
                        char8_constraints_ptr tmp = build_char8_constraints((*iti)->as_permitted()->constraints());
                        if (!tmp) {
                            stki = char8_constraints_stack();
                            break;
                        }
                        rng = *tmp;
                        if (rng.has_extention())
                            has_ext=true;
                        stki.push(rng);
                    } else if ((*iti)->as_size()) {
                        rng = char8_constraints();
                        stki.push(rng);
                    } else if ((*iti)->as_typeconstraint()) {
                        if (!build_range((*iti)->as_typeconstraint(), rng)) {
                            stki = char8_constraints_stack();
                            break;
                        }
                        stki.push(rng);
                    } else if ((*iti)->as_tvoso()) {
                        if (!build_range((*iti)->as_tvoso(), rng)) {
                            stki = char8_constraints_stack();
                            break;
                        }
                        stki.push(rng);
                    } else if ((*iti)->as_union()) {
                        if (stki.size() < 2) {
                            stki = char8_constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() |= rng;
                    } else if ((*iti)->as_intersection()) {
                        if (stki.size() < 2) {
                            stki = char8_constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() &= rng;
                    } else if ((*iti)->as_except()) {
                        if (stki.size() < 2) {
                            stki = char8_constraints_stack();
                            break;
                        }
                        rng = stki.top();
                        stki.pop();
                        stki.top() -= rng;
                    } else if ((*iti)->as_allexcept()) {
                        if (stki.size() < 1) {
                            stki = char8_constraints_stack();
                            break;
                        }
                        rng = char8_constraints();
                        rng -= stki.top();
                        stki.top() = rng;
                    } else {
                        stki = char8_constraints_stack();
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
        return build_serial_constrains<std::string::value_type>(stke);
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
                if (!(vl->reff()->as_typeassigment()) || !(vl->reff()->as_typeassigment()->type()))
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
        char8_constraints_ptr rslt= effective_constraint<std::string::value_type>();
        if (rslt ) {
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

    bool type_atom::isrefferrence() const {
        return (((builtin_ == t_Reference)
                || (builtin_ == t_TypeFromObject)
                || (builtin_ == t_ValueSetFromObjects)) && (reff()));
    }

    bool type_atom::issimplerefferrence() {
        switch (builtin_) {
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
        return (((builtin_ == t_CHOICE) || (builtin_ == t_SET) || (builtin_ == t_SEQUENCE)));
    }

    bool type_atom::isstruct_of() const {
        return ( (builtin_ == t_SET_OF) || (builtin_ == t_SEQUENCE_OF));
    }

    bool type_atom::isstructure() const {
        return ((isstruct()) || (isstruct_of()));
    }

    bool type_atom::isopen() const {
        return ((builtin_ == t_ClassField) || (builtin_ == t_ANY));
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
            case t_IA5String:
            case t_VisibleString: return true;
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

    bool type_atom::can_integer_constraints() {
        return (root_builtin() == t_INTEGER);
    }

    bool type_atom::istextualy_choice() {
        if (builtin_ == t_CHOICE)
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
                (isdummy())) && (tag()));
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
            assignment_entity_ptr tmpasmt = object()->reff()->as_assigment();
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

    bool typeassignment_entity::isdefined_choice() {
        if (islocaldefined()) {
            if (tag()) {
                return (type() && type()->untagged_type() && (type()->untagged_type() ->istextualy_choice()));
            }
        }
        return (type() && ((istextualy_choice()) || (type()->builtin() == t_CHOICE)));
    }

    bool typeassignment_entity::islocaldeclare() const {
        if (scope() && (scope()->as_typeassigment()) && (type()))
            return (type()->isstructure());
        return false;
    }

    bool typeassignment_entity::islocaldefined() const {
        if (scope() && (scope()->as_typeassigment()) && (type()))
            return true;
        return false;
    }

    canonical_tag_vct typeassignment_entity::cncl_tags() {
        canonical_tag_vct tmp;
        if (type()) {
            if (type()->istextualy_choice()) {
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
                        tmp = type()->reff()->as_typeassigment()->cncl_tags();
                }
            } else {
                if (type()->cncl_tag())
                    tmp.push_back(type()->cncl_tag());
            }
        }
        return tmp;
    }

    typeassignment_entity_ptr typeassignment_entity::superfluous_assignment(module_entity_ptr mod) {
        if (type() && (!tag()) && (type()->reff()) && mod) {
            typeassignment_entity_ptr rf = ((type()->reff()) && (type()->reff()->as_typeassigment())) ?
                    type()->reff()->as_typeassigment() : typeassignment_entity_ptr();
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
                            (*it)->as_typeassigment()->as_named() : namedtypeassignment_entity_ptr();
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
                    bool isallways_expl = ((tmptype->istextualy_choice()) || (tmptype->isopen()) ||
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
                        bool isallways_expl = ((tmptype->istextualy_choice()) || (tmptype->isopen()) ||
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
                        bool isallways_expl = ((tmptype->istextualy_choice()) || (tmptype->isopen()) ||
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
