//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/semantics.hpp>

namespace x680 {
    namespace semantics {

        std::ostream& operator<<(std::ostream& stream, const error& self) {
            stream << "Semantic error: " << self.message() << "\n";
            return stream;
        }



        /////////////////////////////////////////////////////////////////////////   
        // precomile modules
        /////////////////////////////////////////////////////////////////////////           

        global_entity_ptr compile_fs(const std::string& path, const std::string& ext) {
            x680::syntactic::modules synxtasresult;
            x680::syntactic::parse_fs(path, synxtasresult);

            global_entity_ptr global = global_entity_ptr(new global_entity());


            insert_global(global);

            for (x680::syntactic::modules::const_iterator it = synxtasresult.begin(); it != synxtasresult.end(); ++it) {
                std::cout << "compile module: " << it->name << std::endl;
                compile_module(*it, global);
            }
            global->resolve();
            return global;
        }



        //  compile_module        

        void compile_module(const x680::syntactic::module& mod, global_entity_ptr global) {
            module_entity_ptr modul = module_entity_ptr(new module_entity(global, mod.name, mod.file,
                    mod.allexport, mod.default_tags_t == noset_tags ? explicit_tags : mod.default_tags_t, mod.extesibility_implied));
            compile_export(mod, modul);
            compile_imports(mod, modul);
            compile_assignments(mod, modul);
            if (mod.oid.type == v_objectid)
                modul->objectid(structvalue_atom_ptr(new structvalue_atom(v_objectid, compile_objidvalue(modul, mod.oid))));
            global->childs().push_back(modul);
        }



        //  compile_export

        void compile_export(const x680::syntactic::module& mod, module_entity_ptr mdl) {
            for (x680::syntactic::exports::const_iterator it = mod.exports_.begin(); it != mod.exports_.end(); ++it)
                mdl->exports().push_back(*it);
        }



        //  compile_imports      

        void compile_imports(const x680::syntactic::module& mod, module_entity_ptr mdl) {
            for (x680::syntactic::imports::const_iterator it = mod.imports_.begin(); it != mod.imports_.end(); ++it) {
                mdl->imports().push_back(compile_import(*it, mdl));
            }
        }




        //  compile_import         

        basic_entity_ptr compile_import(const x680::syntactic::import& imp, module_entity_ptr mdl) {
            import_entity_ptr rslt = import_entity_ptr(new import_entity(imp.name));
            rslt->objectid(compile_value(mdl, imp.oid));
            for (x680::syntactic::string_vector::const_iterator it = imp.names.begin(); it != imp.names.end(); ++it)
                rslt->import().push_back(*it);
            return rslt;
        }




        //  compile_assignments

        void compile_assignments(const x680::syntactic::module& mod, module_entity_ptr mdl) {
            for (x680::syntactic::assignment_vector::const_iterator it = mod.elements.begin(); it != mod.elements.end(); ++it) {
                if (basic_entity_ptr rs = compile_assignment(mdl, *it))
                    mdl->childs().push_back(rs);
            }
        }


        //  compile_assignment        

        basic_entity_ptr compile_assignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent) {
            basic_entity_ptr rslt;
            switch (ent.which()) {
                case 0: return compile_typeassignment(scope, boost::get<x680::syntactic::type_assignment>(ent));
                case 1: return compile_valueassignment(scope, boost::get<x680::syntactic::value_assignment>(ent));
                case 2: return compile_valuesetassignment(scope, boost::get<x680::syntactic::valueset_assignment>(ent));
                case 3: return compile_classassignment(scope, boost::get<x680::syntactic::class_assignment>(ent));
                case 4: return compile_objectassignment(scope, boost::get<x680::syntactic::object_assignment>(ent));
                case 5: return compile_objectsetassignment(scope, boost::get<x680::syntactic::objectset_assignment>(ent));
                case 6: return compile_bigassignment(scope, boost::get<x680::syntactic::unknown_tc_assignment>(ent));
                case 7: return compile_voassignment(scope, boost::get<x680::syntactic::unknown_vo_assignment>(ent));
                case 8: return compile_soassignment(scope, boost::get<x680::syntactic::unknown_so_assignment>(ent));
            }
            return rslt;
        }

        setting_atom_vct compile_parameters(basic_entity_ptr scope, const x680::syntactic::parameter_vector& ent) {
            setting_atom_vct tmp;
            for (x680::syntactic::parameter_vector::const_iterator it = ent.begin(); it != ent.end(); ++it)
                tmp.push_back(compile_setting(scope, *it));
            return tmp;
        }

        argument_entity_vct compile_arguments(basic_entity_ptr scope, const x680::syntactic::argument_vector& ent) {
            argument_entity_vct tmp;
            for (x680::syntactic::argument_vector::const_iterator it = ent.begin(); it != ent.end(); ++it)
                tmp.push_back(compile_argument(scope, *it));
            return tmp;
        }

        argument_entity_ptr compile_argument(basic_entity_ptr scope, const x680::syntactic::argument_type& ent) {
            argument_entity_ptr tmp(new argument_entity(scope, ent.argument, ent.atp));
            switch (ent.tp) {
                case gvr_Type: tmp->governor(compile_type(scope, ent.governortype));
                    break;
                case gvr_Class: tmp->governor(compile_classdefined(scope, ent.governorclass));
                    break;
                case gvr_Type_or_Class: tmp->governor(basic_atom_ptr(new basic_atom(scope, ent.reff)));
                    break;
                default:
                {
                }
            }
            return tmp;
        }

        //  type

        typeassignment_entity_ptr compile_typeassignment(basic_entity_ptr scope, const x680::syntactic::type_assignment& tmp) {
            typeassignment_entity_ptr tmpt(new typeassignment_entity(scope, tmp.identifier, compile_type(scope, tmp.type)));
            switch (tmp.type.builtin_t) {
                case t_SEQUENCE:
                case t_SEQUENCE_OF:
                case t_SET:
                case t_SET_OF:
                case t_CHOICE: tmpt->childs() = compile_structtype(tmpt, tmp.type);
                default:
                {
                };
            }
            tmpt->type()->predefined(compile_typepredef(tmpt, tmp.type));
            tmpt->arguments(compile_arguments(tmpt, tmp.arguments));
            return tmpt;
        }

        basic_entity_vector compile_structtype(basic_entity_ptr scope, const x680::syntactic::type_element& ent) {
            basic_entity_vector rslt;
            for (x680::syntactic::named_type_element_vector::const_iterator it = ent.elements.begin(); it != ent.elements.end(); ++it)
                rslt.push_back(compile_namedtype(scope, *it));
            return rslt;
        }

        typeassignment_entity_ptr compile_namedtype(basic_entity_ptr scope, const x680::syntactic::type_assignment& ent) {
            namedtypeassignment_entity_ptr tmpt;
            switch (ent.type.marker) {
                case mk_default:
                {
                    tmpt = namedtypeassignment_entity_ptr(new namedtypeassignment_entity(scope, ent.identifier, type_atom_ptr(), value_atom_ptr()));
                    tmpt->type(compile_type(tmpt, ent.type));
                    tmpt-> _default(compile_value(tmpt, ent.type.value));
                    break;
                }
                case mk_exception:
                {
                    tmpt = namedtypeassignment_entity_ptr(new namedtypeassignment_entity(scope, type_atom_ptr(), value_atom_ptr()));
                    tmpt->type(compile_type(tmpt, ent.type));
                    tmpt-> _default(compile_value(tmpt, ent.type.value));
                    break;
                }
                case mk_extention:
                {
                    tmpt = namedtypeassignment_entity_ptr(new namedtypeassignment_entity(scope));
                    if (scope && (scope->as_typeassigment()) && (scope->as_typeassigment()->type()))
                        scope->as_typeassigment()->type()->extention(true);
                    return tmpt;
                    break;
                }
                default:
                {
                    tmpt = namedtypeassignment_entity_ptr(new namedtypeassignment_entity(scope, ent.identifier, type_atom_ptr(), ent.type.marker));
                    tmpt->type(compile_type(tmpt, ent.type));
                }
            }
            tmpt->type()->predefined(compile_typepredef(tmpt, ent.type));
            switch (ent.type.builtin_t) {
                case t_SEQUENCE:
                case t_SEQUENCE_OF:
                case t_SET:
                case t_SET_OF:
                case t_CHOICE: tmpt->childs() = compile_structtype(tmpt, ent.type);
                default:
                {
                };
            }
            tmpt->type()->constraints(compile_constraints_vct(tmpt, ent.type.constraints));
            return tmpt;
        }

        type_atom_ptr compile_type(basic_entity_ptr scope, const x680::syntactic::type_element& ent) {
            type_atom_ptr tmp;
            switch (ent.builtin_t) {
                case t_ClassField: tmp = type_atom_ptr(new classfieldtype_atom(scope, ent.reference, ent.fieldreference,
                            compile_tag(scope, ent.tag)));
                    break;
                case t_Instance_Of: tmp = type_atom_ptr(new instanceoftype_atom(scope, ent.reference,
                            compile_tag(scope, ent.tag)));
                    break;
                case t_TypeFromObject: tmp = type_atom_ptr(new fromobjecttype_atom(scope, ent.fieldreference,
                            compile_object(scope, *ent.objectref), compile_tag(scope, ent.tag)));
                    break;
                case t_ValueSetFromObjects: tmp = type_atom_ptr(new fromobjectsettype_atom(scope, ent.fieldreference,
                            compile_objectset(scope, *ent.objectsetref), compile_tag(scope, ent.tag)));
                    break;
                default:
                    tmp = ent.reference.empty() ? type_atom_ptr(new type_atom(scope, ent.builtin_t, compile_tag(scope, ent.tag))) :
                            type_atom_ptr(new type_atom(scope, ent.reference, ent.builtin_t, compile_tag(scope, ent.tag)));
            }
            tmp->constraints(compile_constraints_vct(scope, ent.constraints));
            tmp->parameters(compile_parameters(scope, ent.parameters));
            return tmp;
        }

        predefined_ptr compile_typepredef(basic_entity_ptr scope, const x680::syntactic::type_element& ent) {
            if (ent.predefined.empty())
                return predefined_ptr();
            basic_entity_vector rslt;
            for (x680::syntactic::value_element_vector::const_iterator it = ent.predefined.begin(); it != ent.predefined.end(); ++it) {
                if (it->type == v_extention) {
                    extention_entity_ptr el(new extention_entity());
                    rslt.push_back(el);
                } else {
                    if (it->value.empty()) {
                        if (it->values.empty()) {
                            valueassignment_entity_ptr el(new valueassignment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER))));
                            rslt.push_back(el);
                        } else {
                            try {
                                valueassignment_entity_ptr el(new valueassignment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                        value_atom_ptr(new numvalue_atom(boost::lexical_cast<int > (it->values.begin()->identifier)))));
                                rslt.push_back(el);
                            } catch (boost::bad_lexical_cast) {
                                valueassignment_entity_ptr el(new valueassignment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                        value_atom_ptr(new definedvalue_atom(it->values.begin()->identifier, scope))));
                                rslt.push_back(el);
                            }
                        }
                    } else {
                        try {
                            valueassignment_entity_ptr el(new valueassignment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                    value_atom_ptr(new numvalue_atom(boost::lexical_cast<int > (it->value)))));
                            rslt.push_back(el);
                        } catch (boost::bad_lexical_cast) {
                            valueassignment_entity_ptr el(new valueassignment_entity(scope, it->identifier, type_atom_ptr(new type_atom(scope, t_INTEGER)),
                                    value_atom_ptr(new definedvalue_atom(it->fromreff, scope))));
                            rslt.push_back(el);
                        }
                    }
                }
            }
            predefined_ptr tmp(new predefined(scope, ent.builtin_t));
            tmp->values(rslt);
            return tmp;
        }

        tagged_ptr compile_tag(basic_entity_ptr scope, const x680::syntactic::tag_type& ent) {
            if (ent.number.empty())
                return tagged_ptr();
            try {
                value_atom_ptr nm(new numvalue_atom(boost::lexical_cast<int > (ent.number)));
                return tagged_ptr(new tagged(nm, ent.class_, ent.rule));
            } catch (...) {
            }
            value_atom_ptr nm(new definedvalue_atom(ent.number, scope));
            return tagged_ptr(new tagged(nm, ent.class_, ent.rule));
        }




        //  value

        valueassignment_entity_ptr compile_valueassignment(basic_entity_ptr scope, const x680::syntactic::value_assignment& tmp) {
            valueassignment_entity_ptr tmpt(new valueassignment_entity(scope, tmp.identifier, compile_type(scope, tmp.type)));
            value_atom_ptr tmpv = compile_value(tmpt, tmp.value);
            tmpt->value(tmpv);
            tmpt->type()->predefined(compile_typepredef(tmpt, tmp.type));
            tmpt->arguments(compile_arguments(tmpt, tmp.arguments));
            return tmpt;
        }

        value_atom_ptr compile_value(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            value_atom_ptr tmp = compile_value_impl(scope, ent);
            if (tmp)
                tmp->parameters(compile_parameters(scope, ent.parameters));
            return tmp;
        }

        value_atom_ptr compile_value_impl(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            try {
                switch (ent.type) {
                    case v_boolean: return value_atom_ptr(new boolvalue_atom(ent.value == "TRUE"));
                    case v_number: return value_atom_ptr(new numvalue_atom(boost::lexical_cast<int > (ent.value)));
                    case v_real: return compile_realvalue(scope, ent.value);
                    case v_null: return value_atom_ptr(new nullvalue_atom());
                    case v_empty: return value_atom_ptr(new emptyvalue_atom());
                    case v_named_value: return compile_namedvalue(scope, ent);
                    case v_bstring:
                    case v_hstring:
                    case v_cstring: return value_atom_ptr(new strvalue_atom(ent.value, ent.type));
                    case v_struct: return value_atom_ptr(new structvalue_atom(ent.type, compile_structvalue(scope, ent)));
                    case v_objectid: return value_atom_ptr(new structvalue_atom(ent.type, compile_objidvalue(scope, ent)));
                    case v_defined_list:
                    case v_number_list:
                    case v_value_list: return value_atom_ptr(new structvalue_atom(ent.type, compile_listvalue(scope, ent)));
                    case v_defined: return value_atom_ptr(new definedvalue_atom(ent.identifier, scope));
                    case v_ValueFromObject: return value_atom_ptr(new fromobjectvalue_atom(scope, ent.fieldreference,
                                compile_object(scope, *ent.objectref)));
                    case v_defined_assign: return compile_assignvalue(scope, ent);
                    case v_choice: return compile_choicevalue(scope, ent);
                    case v_open: return compile_openvalue(scope, ent);
                    default:
                    {
                    }
                }
            } catch (boost::bad_lexical_cast) {
            }
            //scope->referenceerror_throw(scope->name(), "Value dos'nt set");
            return value_atom_ptr();
        }

        value_atom_ptr compile_assignvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            try {
                if (ent.value.empty()) {
                    if (!ent.values.empty()) {
                        value_atom_ptr tmp = compile_value(scope, *(ent.values.begin()));
                        return value_atom_ptr(new assignvalue_atom(ent.identifier, tmp));
                    }
                } else {
                    value_atom_ptr tmp(new numvalue_atom(boost::lexical_cast<int > (ent.value)));
                    return value_atom_ptr(new assignvalue_atom(ent.identifier, tmp));
                }
            } catch (boost::bad_lexical_cast) {
            }
            return value_atom_ptr(new value_atom(scope, v_nodef));
        }

        value_atom_ptr compile_realvalue(basic_entity_ptr scope, const std::string& val) {
            try {
                if (val == "PLUS-INFINITY")
                    return value_atom_ptr(new realvalue_atom(std::numeric_limits<double>::infinity()));
                if (val == "MINUS-INFINITY")
                    return value_atom_ptr(new realvalue_atom(-std::numeric_limits<double>::infinity()));
                if (val == "NOT-A-NUMBER")
                    return value_atom_ptr(new realvalue_atom(-std::numeric_limits<double>::signaling_NaN()));
                return value_atom_ptr(new realvalue_atom(boost::lexical_cast<double > (val)));
            } catch (boost::bad_lexical_cast) {
            }
            return value_atom_ptr(new value_atom(scope, v_nodef));
        }

        value_atom_ptr compile_choicevalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            if (!ent.values.empty()) {
                value_atom_ptr tmp = compile_value(scope, *(ent.values.begin()));
                return value_atom_ptr(new choicevalue_atom(ent.identifier, tmp));
            }
            return value_atom_ptr(new value_atom(scope, v_nodef));
        }

        value_atom_ptr compile_openvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            if (ent.typevalue) {
                return value_atom_ptr(new openvalue_atom(compile_type(scope, ent.typevalue->type), compile_value(scope, ent.typevalue->value)));
            }
            return value_atom_ptr(new value_atom(scope, v_nodef));
        }

        value_atom_ptr compile_namedvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            if (!ent.values.empty())
                return value_atom_ptr(new namedvalue_atom(ent.identifier, compile_value(scope, *(ent.values.begin()))));
            return value_atom_ptr(new value_atom(scope, v_nodef));
        }

        value_vct compile_structvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            value_vct rslt;
            if ((ent.type == v_struct)) {
                for (x680::syntactic::value_element_vector::const_iterator it = ent.values.begin(); it != ent.values.end(); ++it) {
                    if (!it->values.empty()) {
                        rslt.push_back(value_atom_ptr(new namedvalue_atom(it->identifier, compile_value(scope, *(it->values.begin())))));
                    }
                }
            }
            return rslt;
        }

        value_vct compile_objidvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            value_vct rslt;
            if ((ent.type == v_objectid)) {
                for (x680::syntactic::value_element_vector::const_iterator it = ent.values.begin(); it != ent.values.end(); ++it) {
                    rslt.push_back(value_atom_ptr(compile_value(scope, *it)));
                }
            }
            return rslt;
        }

        value_vct compile_listvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent) {
            value_vct rslt;
            for (x680::syntactic::value_element_vector::const_iterator it = ent.values.begin(); it != ent.values.end(); ++it) {
                rslt.push_back(value_atom_ptr(compile_value(scope, *it)));
            }
            return rslt;
        }



        // valueset

        valuesetassignment_entity_ptr compile_valuesetassignment(basic_entity_ptr scope, const x680::syntactic::valueset_assignment& tmp) {
            valuesetassignment_entity_ptr tmpv(new valuesetassignment_entity(scope, tmp.identifier, compile_type(scope, tmp.type)));
            tmpv->valueset(compile_valueset(tmpv, tmp.set));
            tmpv->arguments(compile_arguments(tmpv, tmp.arguments));
            return tmpv;
        }

        valueset_atom_ptr compile_valueset(basic_entity_ptr scope, const x680::syntactic::valueset_element& ent) {
            valueset_atom_ptr tmp = compile_valueset_impl(scope, ent);
            tmp->parameters(compile_parameters(scope, ent.parameters));
            return tmp;
        }

        valueset_atom_ptr compile_valueset_impl(basic_entity_ptr scope, const x680::syntactic::valueset_element& ent) {
            switch (ent.tp) {
                case vs_ValueSetFromObject: return valueset_atom_ptr(new fromobjectvalueset_atom(scope, ent.reference, compile_object(scope, *ent.objectref)));
                case vs_ValueSetFromObjects: return valueset_atom_ptr(new fromobjectsetvalueset_atom(scope, ent.reference, compile_objectset(scope, *ent.objectsetref)));
                case vs_Strait:
                {
                    valueset_atom_ptr tmp(new valueset_atom(scope, ent.tp));
                    tmp->set(compile_constraints(scope, ent.set));
                    tmp->parameters(compile_parameters(scope, ent.parameters));
                    return tmp;
                }
                default:
                {
                }
            }
            return valueset_atom_ptr(new valueset_atom(scope, ent.reference, ent.tp));
        }

        constraints_atom_vct compile_constraints_vct(basic_entity_ptr scope, const x680::syntactic::constraints_vector& ent) {
            constraints_atom_vct tmp;
            for (x680::syntactic::constraints_vector::const_iterator it = ent.begin(); it != ent.end(); ++it)
                tmp.push_back(compile_constraints(scope, *it));
            return tmp;
        }

        constraints_atom_ptr compile_constraints(basic_entity_ptr scope, const x680::syntactic::constraint_element_vector& ent) {
            bool first = true;
            constraint_atom_vct tmp1;
            constraint_atom_vct tmp2;
            for (x680::syntactic::constraint_element_vector::const_iterator it = ent.begin(); it != ent.end(); ++it) {
                if (it->tp == cns_EXTENTION) {
                    first = false;
                } else {
                    if (first)
                        tmp1.push_back(compile_constraint(scope, *it));
                    else
                        tmp2.push_back(compile_constraint(scope, *it));
                }
            }
            return first ? constraints_atom_ptr(new constraints_atom(scope, tmp1)) : constraints_atom_ptr(new constraints_atom(scope, tmp1, tmp2));
        }

        constraint_atom_ptr compile_constraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent) {
            constraint_atom_ptr tmp;
            switch (ent.tp) {
                case cns_PatternConstraint:
                case cns_SingleValue: return constraint_atom_ptr(new valueconstraint_atom(scope, ent.tp, compile_value(scope, ent.value)));
                case cns_ValueRange:
                case cns_DurationRange:
                case cns_TimePointRange:
                case cns_RecurrenceRange: return constraint_atom_ptr(new rangeconstraint_atom(scope, ent.tp,
                            (((ent.fromtype_ == close_range) || (ent.fromtype_ == open_range)) ? compile_value(scope, ent.from_) : value_atom_ptr()), ent.fromtype_,
                            (((ent.totype_ == close_range) || (ent.totype_ == open_range)) ? compile_value(scope, ent.to_) : value_atom_ptr()), ent.totype_));
                case cns_ContainedSubtype:
                case cns_TypeConstraint: return constraint_atom_ptr(new typeconstraint_atom(scope, ent.tp,
                            compile_type(scope, ent.type), false));
                case cns_PermittedAlphabet:
                case cns_SizeConstraint:
                case cns_SingleTypeConstraint: return constraint_atom_ptr(new complexconstraint_atom(scope, ent.tp,
                            compile_constraints(scope, ent.constraint)));
                case cns_PropertySettings: return constraint_atom_ptr(new stringconstraint_atom(scope, ent.tp, ent.identifier));
                case cns_MultipleTypeConstraints: return compile_multipletypeconstraint(scope, ent);
                case cns_NamedConstraint: return compile_namedconstraint(scope, ent);
                case cns_ValueSetFromObjects: return constraint_atom_ptr(new fromdefinedsetconstraint_atom(scope, ent.fieldreference,
                            compile_objectset(scope, *ent.objectsetref)));
                case cns_ValueSetFromObject: return constraint_atom_ptr(new fromdefinedconstraint_atom(scope, ent.fieldreference,
                            compile_object(scope, *ent.objectref)));
                case cns_UNION: return constraint_atom_ptr(new unionconstraint_atom());
                case cns_INTERSECTION: return constraint_atom_ptr(new intersectionconstraint_atom());
                case cns_EXCEPT: return constraint_atom_ptr(new exceptconstraint_atom());
                case cns_ALLEXCEPT: return constraint_atom_ptr(new allexceptconstraint_atom());
                case cns_EXTENTION: return constraint_atom_ptr(new extentionconstraint_atom());
                case cns_EXCEPTION: return compile_exceptionconstraint(scope, ent);
                case cns_UserDefinedConstraint: return constraint_atom_ptr(new userconstraint_atom(scope, compile_uarguments(scope, ent.uparameters)));
                case cns_Contents: return compile_contentconstraint(scope, ent);
                case cns_ComponentRelation: return constraint_atom_ptr(new relationconstraint_atom(scope, compile_objectset(scope, *ent.objectsetref), ent.parameters));
                case cns_SimpleTableConstraint: return constraint_atom_ptr(new tableconstraint_atom(scope, compile_objectset(scope, *ent.objectsetref)));
                case cns_Undef_T_ST_VS: return compile_tvosoconstraint(scope, ent);
                    /*case cns_ComponentRelation*/
                default:
                {
                }
            }
            return constraint_atom_ptr(new constraint_atom());
        }

        constraint_atom_ptr compile_namedconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent) {
            if (!ent.constraint.empty())
                return constraint_atom_ptr(new namedconstraint_atom(scope, ent.identifier, compile_constraints(scope, ent.constraint), ent.marker));
            return constraint_atom_ptr(new namedconstraint_atom(scope, ent.identifier, ent.marker));
        }

        constraint_atom_ptr compile_multipletypeconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent) {
            constraint_atom_vct tmp;
            for (x680::syntactic::constraint_element_vector::const_iterator it = ent.constraint.begin(); it != ent.constraint.end(); ++it) {
                switch (it->tp) {
                    case cns_NamedConstraint: tmp.push_back(compile_namedconstraint(scope, *it));
                        break;
                    default: tmp.push_back(compile_constraint(scope, *it));
                }
            }
            return constraint_atom_ptr(new multipletypeconstraint_atom(scope, tmp));
        }

        constraint_atom_ptr compile_exceptionconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent) {
            return constraint_atom_ptr(new exceptionconstraint_atom(scope, compile_type(scope, ent.type), compile_value(scope, ent.value)));
        }

        constraint_atom_ptr compile_contentconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent) {
            if ((ent.type.builtin_t != t_NODEF) && (ent.value.type != v_nodef)) {
                return constraint_atom_ptr(new contentconstraint_atom(scope, compile_type(scope, ent.type), compile_value(scope, ent.value)));
            } else if (ent.type.builtin_t != t_NODEF) {
                return constraint_atom_ptr(new contentconstraint_atom(scope, compile_type(scope, ent.type)));
            } else if (ent.value.type != v_nodef) {
                return constraint_atom_ptr(new contentconstraint_atom(scope, compile_value(scope, ent.value)));
            }
            scope->referenceerror_throw(scope->name(), "Content constraint dos'nt set");
            return constraint_atom_ptr();
        }

        constraint_atom_ptr compile_tvosoconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent) {
            tvosoconstraint_atom_ptr tmp(new tvosoconstraint_atom(scope));
            if (((*ent.setting).alternative & AS_TYPE) && ((*ent.setting).type))
                tmp->type(compile_type(scope, (*((*ent.setting).type))));
            if (((*ent.setting).alternative & AS_VALUESET) && ((*ent.setting).valueset))
                tmp->valueset(compile_valueset(scope, (*((*ent.setting).valueset))));
            if (((*ent.setting).alternative & AS_OBJECTSET) && ((*ent.setting).objectset))
                tmp->objectset(compile_objectset(scope, (*((*ent.setting).objectset))));
            return tmp;
        }

        uargument_entity_vct compile_uarguments(basic_entity_ptr scope, const x680::syntactic::uargument_vector& ent) {
            uargument_entity_vct tmp;
            for (x680::syntactic::uargument_vector::const_iterator it = ent.begin(); it != ent.end(); ++it)
                tmp.push_back(compile_uargument(scope, *it));
            return tmp;
        }

        uargument_entity_ptr compile_uargument(basic_entity_ptr scope, const x680::syntactic::uargument_type& ent) {
            switch (ent.tp) {
                case gvr_Type:
                {
                    uargument_entity_ptr tmp(new uargument_entity(scope, compile_type(scope, ent.governortype)));
                    tmp->setting(compile_setting(tmp, ent.parameter));
                    return tmp;
                }
                case gvr_Class:
                {
                    uargument_entity_ptr tmp(new uargument_entity(scope, compile_classdefined(scope, ent.governorclass)));
                    tmp->setting(compile_setting(tmp, ent.parameter));
                    return tmp;
                }
                case gvr_Type_or_Class:
                {
                    uargument_entity_ptr tmp(new uargument_entity(scope, basic_atom_ptr(new basic_atom(scope, ent.reff))));
                    tmp->setting(compile_setting(tmp, ent.parameter));
                    return tmp;
                }
                default:
                {
                }
            }
            return uargument_entity_ptr(new uargument_entity(scope, compile_setting(scope, ent.parameter)));
        }





        //class

        classassignment_entity_ptr compile_classassignment(basic_entity_ptr scope, const x680::syntactic::class_assignment& tmp) {
            classassignment_entity_ptr tmpc(new classassignment_entity(scope, tmp.identifier));
            switch (tmp.class_.tp) {
                case cl_Reference:
                {
                    tmpc->_class(class_atom_ptr(new class_atom(tmpc, tmp.class_.reference, tmp.class_.tp)));
                    tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
                    return tmpc;
                }
                case cl_TYPE_IDENTIFIER:
                {
                    tmpc->_class(class_atom_ptr(new class_atom(tmpc, "TYPE-IDENTIFIER", cl_Reference)));
                    tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
                    return tmpc;
                }
                case cl_ABSTRACT_SYNTAX:
                {
                    tmpc->_class(class_atom_ptr(new class_atom(tmpc, "ABSTRACT-SYNTAX", cl_Reference)));
                    tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
                    return tmpc;
                }
                case cl_SpecDef:
                {
                    tmpc->_class(class_atom_ptr(new class_atom(tmpc, tmp.class_.tp)));
                    tmpc->childs() = compile_classfields(tmpc, tmp.class_);
                    withsyntax_atom wsyn = compile_withsyntax(scope, tmp.class_.syntaxes);
                    tmpc->withsyntax(compile_withsyntax(tmpc, tmp.class_.syntaxes));
                    tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
                    return tmpc;
                }
                default:
                {
                }
            }
            tmpc->_class(class_atom_ptr(new class_atom(tmpc, tmp.class_.tp)));
            tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
            return tmpc;
        }

        class_atom_ptr compile_classdefined(basic_entity_ptr scope, const x680::syntactic::class_element& ent) {
            class_atom_ptr tmp;
            switch (ent.tp) {
                case cl_Reference: tmp = class_atom_ptr(new class_atom(scope, ent.reference, ent.tp));
                    break;
                case cl_TYPE_IDENTIFIER: tmp = class_atom_ptr(new class_atom(scope, "TYPE-IDENTIFIER", cl_Reference));
                    break;
                case cl_ABSTRACT_SYNTAX: tmp = class_atom_ptr(new class_atom(scope, "ABSTRACT-SYNTAX", cl_Reference));
                    break;
                default: tmp = class_atom_ptr(new class_atom(scope, ent.reference, ent.tp));
            }
            tmp->parameters(compile_parameters(scope, ent.parameters));
            return tmp;
        }

        basic_entity_vector compile_classfields(basic_entity_ptr scope, const x680::syntactic::class_element& ent) {
            basic_entity_vector tmp;
            for (x680::syntactic::classfield_vector::const_iterator it = ent.fields.begin(); it != ent.fields.end(); ++it) {
                switch (it->tp) {
                    case fkind_TypeFieldSpec: tmp.push_back(compile_typeclassfield(scope, *it));
                        break;
                    case fkind_FixedTypeValueFieldSpec: tmp.push_back(compile_valueclassfield(scope, *it));
                        break;
                    case fkind_FixedTypeValueSetFieldSpec: tmp.push_back(compile_valuesetclassfield(scope, *it));
                        break;
                    case fkind_VariableTypeValueFieldSpec: tmp.push_back(compile_reffvalueclassfield(scope, *it));
                        break;
                    case fkind_VariableTypeValueSetFieldSpec: tmp.push_back(compile_reffvaluesetclassfield(scope, *it));
                        break;
                    case fkind_ObjectFieldSpec: tmp.push_back(compile_objectclassfield(scope, *it));
                        break;
                    case fkind_ObjectSetFieldSpec: tmp.push_back(compile_objectsetclassfield(scope, *it));
                        break;
                    case fkind_FixedType_or_Object: tmp.push_back(compile_undefclassfield(scope, *it));
                        break;
                    case fkind_FixedTypeSet_or_ObjectSet: tmp.push_back(compile_unsefsetclassfield(scope, *it));
                        break;
                    default: tmp.push_back(basic_entity_ptr(new field_entity(scope, it->field, it->tp)));
                }
            }
            return tmp;
        }

        basic_entity_ptr compile_typeclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            switch (ent.marker) {
                case field_defaulttype:
                {
                    type_atom_ptr tp = compile_type(scope, ent.defaulttype);
                    return basic_entity_ptr(new typefield_entity(scope, ent.field, tp));
                }
                case field_optional: return basic_entity_ptr(new typefield_entity(scope, ent.field, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new typefield_entity(scope, ent.field));
        }

        basic_entity_ptr compile_valueclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            type_atom_ptr tp = compile_type(scope, ent.holdertype);
            switch (ent.marker) {
                case field_defaultvalue:
                {
                    value_atom_ptr vl = compile_value(scope, ent.defaultvalue);
                    return basic_entity_ptr(new valuefield_entity(scope, ent.field, tp, vl));
                }
                case field_optional: return basic_entity_ptr(new valuefield_entity(scope, ent.field, tp, ent.unique, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new valuefield_entity(scope, ent.field, tp, ent.unique));
        }

        basic_entity_ptr compile_valuesetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            type_atom_ptr tp = compile_type(scope, ent.holdertype);
            switch (ent.marker) {
                case field_defaultset:
                {
                    valueset_atom_ptr vl = compile_valueset(scope, ent.defaultset);
                    return basic_entity_ptr(new valuesetfield_entity(scope, ent.field, tp, vl));
                }
                case field_optional: return basic_entity_ptr(new valuesetfield_entity(scope, ent.field, tp, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new valuesetfield_entity(scope, ent.field, tp));
        }

        basic_entity_ptr compile_reffvalueclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            //basic_atom_ptr reff = basic_atom_ptr( new basic_atom( ent.holder, scope));
            switch (ent.marker) {
                case field_defaultvalue:
                {
                    value_atom_ptr vl = compile_value(scope, ent.defaultvalue);
                    return basic_entity_ptr(new reffvaluefield_entity(scope, ent.field, ent.holder, vl));
                }
                case field_optional: return basic_entity_ptr(new reffvaluefield_entity(scope, ent.field, ent.holder, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new reffvaluefield_entity(scope, ent.field, ent.holder));
        }

        basic_entity_ptr compile_reffvaluesetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            //basic_atom_ptr reff = basic_atom_ptr( new basic_atom( ent.holder, scope));
            switch (ent.marker) {
                case field_defaultvalue:
                {
                    valueset_atom_ptr vl = compile_valueset(scope, ent.defaultset);
                    return basic_entity_ptr(new reffvaluesetfield_entity(scope, ent.field, ent.holder, vl));
                }
                case field_optional: return basic_entity_ptr(new reffvaluesetfield_entity(scope, ent.field, ent.holder, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new reffvaluesetfield_entity(scope, ent.field, ent.holder));
        }

        basic_entity_ptr compile_objectclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            class_atom_ptr cl = compile_classdefined(scope, *ent.holderclass);
            switch (ent.marker) {
                case field_defaultovalue:
                {
                    object_atom_ptr vl = compile_object(scope, *ent.defaultovalue);
                    return basic_entity_ptr(new objectfield_entity(scope, ent.field, cl, vl));
                }
                case field_optional: return basic_entity_ptr(new objectfield_entity(scope, ent.field, cl, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new objectfield_entity(scope, ent.field, cl));
        }

        basic_entity_ptr compile_objectsetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            class_atom_ptr cl = compile_classdefined(scope, *ent.holderclass);
            switch (ent.marker) {
                case field_defaultoset:
                {
                    objectset_atom_ptr vl = compile_objectset(scope, *ent.defaultoset);
                    return basic_entity_ptr(new objectsetfield_entity(scope, ent.field, cl, vl));
                }
                case field_optional: return basic_entity_ptr(new objectsetfield_entity(scope, ent.field, cl, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new objectsetfield_entity(scope, ent.field, cl));
        }

        basic_entity_ptr compile_undefclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            basic_atom_ptr bg = basic_atom_ptr(new basic_atom(scope, ent.holder));
            switch (ent.marker) {
                case field_defaultov:
                {
                    value_atom_ptr vl = ent.defvalobj.value_ ?
                            compile_value(scope, *ent.defvalobj.value_) : value_atom_ptr();
                    object_atom_ptr obj = ent.defvalobj.object_ ?
                            compile_object(scope, *ent.defvalobj.object_) : object_atom_ptr();
                    return basic_entity_ptr(new undeffield_entity(scope, ent.field, bg, vl, obj));
                }
                case field_optional: return basic_entity_ptr(new undeffield_entity(scope, ent.field, bg, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new undeffield_entity(scope, ent.field, bg));
        }

        basic_entity_ptr compile_unsefsetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent) {
            basic_atom_ptr bg = basic_atom_ptr(new basic_atom(scope, ent.holder));
            switch (ent.marker) {
                case field_defaultos:
                {
                    valueset_atom_ptr vl = ent.defvalobjset.valueset_ ?
                            compile_valueset(scope, *ent.defvalobjset.valueset_) : valueset_atom_ptr();
                    objectset_atom_ptr obj = ent.defvalobjset.objectset_ ?
                            compile_objectset(scope, *ent.defvalobjset.objectset_) : objectset_atom_ptr();
                    return basic_entity_ptr(new undefsetfield_entity(scope, ent.field, bg, vl, obj));
                }
                case field_optional: return basic_entity_ptr(new undefsetfield_entity(scope, ent.field, bg, mk_optional));
                default:
                {
                }
            }
            return basic_entity_ptr(new undefsetfield_entity(scope, ent.field, bg));
        }

        withsyntax_atom compile_withsyntax(basic_entity_ptr scope, const x680::syntactic::classsyntax_vector& ent) {
            if (ent.empty())
                return withsyntax_atom();
            return withsyntax_atom(new groupsyntax_atom(scope, "", compile_groupwithsyntax(scope, ent), false));
        }

        syntax_atom_vct compile_groupwithsyntax(basic_entity_ptr scope, const x680::syntactic::classsyntax_vector& ent) {
            syntax_atom_vct tmp;
            for (x680::syntactic::classsyntax_vector::const_iterator it = ent.begin(); it != ent.end(); ++it) {
                if (it->group.empty()) {
                    tmp.push_back(syntax_atom_ptr(new syntax_atom(scope, it->alias, it->field, it->optional)));
                } else {
                    tmp.push_back(syntax_atom_ptr(new groupsyntax_atom(scope, it->alias, compile_groupwithsyntax(scope, it->group), it->optional)));
                }
            }
            return tmp;
        }


        // object         

        objectassignment_entity_ptr compile_objectassignment(basic_entity_ptr scope, const x680::syntactic::object_assignment& tmp) {
            objectassignment_entity_ptr tmpc(new objectassignment_entity(scope, tmp.identifier, compile_classdefined(scope, tmp.class_)));
            object_atom_ptr obj = compile_object(tmpc, tmp.object);
            tmpc->object(obj);
            tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
            return tmpc;
        }

        object_atom_ptr compile_object(basic_entity_ptr scope, const x680::syntactic::object_element& ent) {
            object_atom_ptr tmp = compile_object_impl(scope, ent);
            if (tmp)
                tmp->parameters(compile_parameters(scope, ent.parameters));
            return tmp;
        }

        object_atom_ptr compile_object_impl(basic_entity_ptr scope, const x680::syntactic::object_element& ent) {
            switch (ent.tp) {
                case ot_FromObject: return object_atom_ptr(new fromobjectobject_atom(scope, ent.fieldreference,
                            compile_object(scope, *ent.objectref)));
                case ot_ObjectSetFromObjects: return object_atom_ptr(new fromdefinedsetobject_atom(scope, ent.fieldreference,
                            compile_objectset(scope, *ent.objectsetref)));
                case ot_ObjectSetFromObject: return object_atom_ptr(new fromdefinedobject_atom(scope, ent.fieldreference,
                            compile_object(scope, *ent.objectref)));
                case ot_Refference: return object_atom_ptr(new definedobject_atom(scope, ent.reff));
                case ot_DefinedObjectSet: return object_atom_ptr(new definedsetobject_atom(scope, compile_objectset(scope, *ent.objectsetref)));
                case ot_Object: return object_atom_ptr(new defltobject_atom(scope, compile_object_fields(scope, ent.fields)));
                case ot_ObjectDefineSyn: return object_atom_ptr(new defsyntxobject_atom(scope, compile_object_fields(scope, ent.fields)));
                case ot_UNION: return object_atom_ptr(new unionobject_atom());
                case ot_INTERSECTION: return object_atom_ptr(new intersectionobject_atom());
                case ot_EXCEPT: return object_atom_ptr(new exceptobject_atom());
                case ot_ALLEXCEPT: return object_atom_ptr(new allexceptobject_atom());
                case ot_EXTENTION: return object_atom_ptr(new extentionobject_atom());
                default:
                {
                }
            }
            return object_atom_ptr();

        }

        fieldsetting_atom_vct compile_object_fields(basic_entity_ptr scope, const x680::syntactic::objectfield_vector& ent) {
            fieldsetting_atom_vct tmp;
            for (x680::syntactic::objectfield_vector::const_iterator it = ent.begin(); it != ent.end(); ++it)
                tmp.push_back(compile_object_field(scope, (*it)));
            return tmp;
        }

        fieldsetting_atom_ptr compile_object_field(basic_entity_ptr scope, const x680::syntactic::objectfield_type& ent) {
            return fieldsetting_atom_ptr(new fieldsetting_atom(scope, ent.field, compile_setting(scope, ent.setting)));
        }

        setting_atom_ptr compile_setting(basic_entity_ptr scope, const x680::syntactic::setting_element& ent) {
            setting_atom_ptr tmp(new setting_atom(ent.alternative, scope));
            if ((ent.alternative & AS_TYPE) && (ent.type))
                tmp->type(compile_type(scope, *ent.type));
            if ((ent.alternative & AS_VALUE) && (ent.value))
                tmp->value(compile_value(scope, *ent.value));
            if ((ent.alternative & AS_VALUESET) && (ent.valueset))
                tmp->valueset(compile_valueset(scope, * ent.valueset));
            if ((ent.alternative & AS_CLASS) && (ent.class_))
                tmp->_class(compile_classdefined(scope, *ent.class_));
            if ((ent.alternative & AS_OBJECT) && (ent.object))
                tmp->object(compile_object(scope, *ent.object));
            if ((ent.alternative & AS_OBJECTSET) && (ent.objectset))
                tmp->objectset(compile_objectset(scope, *ent.objectset));
            if ((ent.alternative & AS_LITERAL))
                tmp->literal(ent.literal);
            return tmp;
        }


        // objectset         

        objectsetassignment_entity_ptr compile_objectsetassignment(basic_entity_ptr scope, const x680::syntactic::objectset_assignment& tmp) {
            objectsetassignment_entity_ptr tmpc(new objectsetassignment_entity(scope, tmp.identifier, compile_classdefined(scope, tmp.class_)));
            objectset_atom_ptr objs = compile_objectset(tmpc, tmp.set);
            tmpc->objectset(objs);
            tmpc->arguments(compile_arguments(tmpc, tmp.arguments));
            return tmpc;
        }

        objectset_atom_ptr compile_objectset(basic_entity_ptr scope, const x680::syntactic::objectset_element& ent) {
            objectset_atom_ptr tmp = compile_objectset_impl(scope, ent);
            tmp->parameters(compile_parameters(scope, ent.parameters));
            return tmp;
        }

        objectset_atom_ptr compile_objectset_impl(basic_entity_ptr scope, const x680::syntactic::objectset_element& ent) {
            switch (ent.tp) {
                case os_ObjectSetFromObject: return objectset_atom_ptr(new fromobjectobjectset_atom(scope, ent.reference, compile_object(scope, *ent.objectref)));
                case os_ObjectSetFromObjects: return objectset_atom_ptr(new fromobjectsetobjectset_atom(scope, ent.reference, compile_objectset(scope, *ent.objectsetref)));
                    //case os_defined:
                case os_Strait: return objectset_atom_ptr(new defnobjectset_atom(scope, compile_objectset_vct(scope, ent)));
                default:
                {
                }
            }
            return objectset_atom_ptr(new definedobjectset_atom(scope, ent.reference));
        }

        object_atom_vct compile_objectset_vct(basic_entity_ptr scope, const x680::syntactic::objectset_element& ent) {
            object_atom_vct tmp;
            for (x680::syntactic::object_element_vector::const_iterator it = ent.set.begin(); it != ent.set.end(); ++it)
                tmp.push_back(compile_object(scope, *it));
            return tmp;
        }

        bigassignment_entity_ptr compile_bigassignment(basic_entity_ptr scope, const x680::syntactic::unknown_tc_assignment& tmp) {
            bigassignment_entity_ptr tmpv = bigassignment_entity_ptr(new bigassignment_entity(scope, tmp.identifier));
            tmpv->big(compile_reff(scope, tmp.unknown_tc.reff));
            tmpv->arguments(compile_arguments(tmpv, tmp.arguments));
            tmpv->big()->parameters(compile_parameters(scope, tmp.unknown_tc.parameters));
            if ((tmp.alternative_ & AS_TYPE) && (tmp.typea))
                tmpv->bigT(compile_typeassignment(scope, *tmp.typea));
            if ((tmp.alternative_ & AS_CLASS) && (tmp.classa))
                tmpv->bigC(compile_classassignment(scope, *tmp.classa));
            return tmpv;
        }

        // value or object 

        voassignment_entity_ptr compile_voassignment(basic_entity_ptr scope, const x680::syntactic::unknown_vo_assignment& tmp) {
            voassignment_entity_ptr tmpv = voassignment_entity_ptr(new voassignment_entity(scope, tmp.identifier));
            tmpv->big(compile_reff(tmpv, tmp.reff));
            if ((tmp.alternative_ & AS_VALUE) && (tmp.valuea))
                tmpv->bigT(compile_valueassignment(scope, *tmp.valuea));
            if ((tmp.alternative_ & AS_OBJECT) && (tmp.objecta))
                tmpv->bigC(compile_objectassignment(scope, *tmp.objecta));

            return tmpv;
        }

        // valueset or objectset

        soassignment_entity_ptr compile_soassignment(basic_entity_ptr scope, const x680::syntactic::unknown_so_assignment& tmp) {
            soassignment_entity_ptr tmpv = soassignment_entity_ptr(new soassignment_entity(scope, tmp.identifier));
            tmpv->big(compile_reff(tmpv, tmp.reff));
            if ((tmp.alternative_ & AS_VALUESET) && (tmp.valueseta))
                tmpv->bigT(compile_valuesetassignment(scope, *tmp.valueseta));
            if ((tmp.alternative_ & AS_OBJECTSET) && (tmp.objectseta))
                tmpv->bigC(compile_objectsetassignment(scope, *tmp.objectseta));

            return tmpv;
        }

        // reff

        basic_atom_ptr compile_reff(basic_entity_ptr scope, const std::string& rf) {
            return basic_atom_ptr(new basic_atom(scope, rf));
        }


    }




}
