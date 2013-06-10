//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680VALUEPARSER_H_
#define         _ITU_X680VALUEPARSER_H_

#include <boost/itu/x68X/asn1module.hpp>
#include <boost/itu/x68X/x680.hpp>


namespace x680 {
    namespace bnf {


        //  unknown_tc_element setter            

        inline void unknown_tc_refference(unknown_tc_element& holder, const std::string& val) {
            holder.reff = val;
        }

        inline void unknown_tc_parameters(unknown_tc_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }



        //  unknown_tc_assignment setter        

        inline void unknown_tca_identifier(unknown_tc_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        inline void unknown_tca(unknown_tc_assignment& holder, const unknown_tc_element& val) {
            holder.unknown_tc = val;
        }

        inline void unknown_tca_arguments(unknown_tc_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }





        //  value_element setter            

        const value_element VALUE_BOOL_TRUE = value_element(true);
        const value_element VALUE_BOOL_FALSE = value_element(false);
        const value_element VALUE_EXTENTION = value_element(v_extention);

        inline void value_parameters(value_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }

        inline void value_setdefined(value_element& holder, const std::string& val) {
            holder.type = v_defined;
            holder.identifier = val;
        }

        inline void value_setassigned(value_element& holder, const std::string& id, const std::string& val) {
            holder.type = v_identifier_assign;
            holder.identifier = id;
            holder.value = val;
        }

        inline void value_setassignedval(value_element& holder, const std::string& id, const value_element& val) {
            holder.type = v_identifier_assignval;
            holder.identifier = id;
            holder.values.push_back(val);
        }

        inline void value_emptyset(value_element& holder) {
            holder.type = v_empty_set;
        }

        inline void value_setnumber(value_element& holder, const std::string& val) {
            holder.type = v_number;
            holder.value = val;
        }

        inline void value_setreal(value_element& holder, const std::string& val) {
            holder.type = v_real;
            holder.value = val;
        }

        inline void value_setnull(value_element& holder) {
            holder.type = v_null;
            holder.value = "NULL";
        }

        inline void value_setbstring(value_element& holder, const std::string& val) {
            holder.type = v_bstring;
            holder.value = val;
        }

        inline void value_sethstring(value_element& holder, const std::string& val) {
            holder.type = v_hstring;
            holder.value = val;
        }

        inline void value_setcstring(value_element& holder, const std::string& val) {
            holder.type = v_cstring;
            holder.value = val;
        }

        inline void value_setvalues(value_element& holder, const value_element_vector& values, const value_type& tp) {
            holder.type = tp;
            holder.values = values;
        }

        inline void value_setvalue(value_element& holder, const std::string& id, const value_element& val, const value_type& tp) {
            holder.identifier = id;
            holder.type = tp;
            holder.values.push_back(val);
            ;
        }

        inline void value_namedval(value_element& holder, const std::string& id, const value_element& val) {
            holder.identifier = id;
            holder.type = v_named_value;
            holder.values.push_back(val);
        }

        inline void value_choiceval(value_element& holder, const std::string& id, const value_element& val) {
            holder.identifier = id;
            holder.type = v_choice;
            holder.values.push_back(val);
        }

        inline void value_typevalue(value_element& holder, const typevalue_element_vector& val) {
            holder.type = v_open;
            holder.typevalue = val;
        }

        inline void value_fromobject(value_element& holder, const std::string& val) {
            holder.fromreff = val;
            holder.type = v_TypeFromObject;
        }

        inline void value_exception(value_element& holder, const std::string& val) {
            holder.type = v_exception;
            holder.value = val;
        }

        inline void values_enum_pushs(value_element_vector& holder, const value_element_vector& val) {
            holder.insert(holder.end(), val.begin(), val.end());
        }

        inline void values_enum_push(value_element_vector& holder, const value_element& val) {
            holder.push_back(val);
        }








        //  type_element setter        

        inline void type_deff(type_element& holder, const defined_type& type) {
            holder.builtin_t = type;
        }

        inline void type_refference(type_element& holder, const std::string& val) {
            holder.reference = val;
            holder.builtin_t = t_Reference;
        }

        inline void type_objectfield(type_element& holder, const std::string& val) {
            holder.reference = val;
            holder.builtin_t = t_ClassField;
        }

        inline void type_fromobject(type_element& holder, const std::string& val) {
            holder.reference = val;
            holder.builtin_t = t_TypeFromObject;
        }

        inline void type_fromobjectset(type_element& holder, const std::string& val) {
            holder.reference = val;
            holder.builtin_t = t_ValueSetFromObjects;
        }

        inline void type_parameters(type_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }

        inline void type_instance(type_element& holder, const std::string& val) {
            holder.reference = val;
            holder.builtin_t = t_Instance_Of;
        }

        inline void type_deffinit(type_element& holder, const value_element_vector & val) {
            holder.predefined = val;
        }

        inline void type_tag(type_element& holder, const tag_type& val) {
            holder.tag = val;
        }

        inline void type_tagged(type_element& holder, const tag_type& tg, const type_element& val) {
            holder = val;
            holder.tag = tg;
        }

        inline void type_pushs(type_element& holder, const type_assignment_vector& val) {
            holder.elements.insert(holder.elements.end(), val.begin(), val.end());
        }

        inline void type_constraints(type_element& holder, const constraints_vector& val) {
            holder.constraints = val;
        }








        //  constraint_element setter

        inline void constraint_tp(constraint_element& holder, const constraint_type& val) {
            holder.tp = val;
        }

        inline void constraint_identifier(constraint_element& holder, const std::string& val) {
            holder.identifier = val;
            holder.tp = cns_NamedConstraint;
        }

        inline void constraint_singlevalue(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_SingleValue;
        }

        inline void constraint_subtype(constraint_element& holder, const type_element& val) {
            holder.type = val;
            holder.tp = cns_ContainedSubtype;
        }

        inline void constraint_type(constraint_element& holder, const type_element& val) {
            holder.type = val;
            holder.tp = cns_TypeConstraint;
        }

        inline void constraint_patterntype(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_PatternConstraint;
        }

        inline void constraint_property(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_PropertySettings;
        }

        inline void constraint_from(constraint_element& holder, const value_element& val) {
            holder.from_ = val;
        }

        inline void constraint_fromtype(constraint_element& holder, const range_type& val) {
            holder.fromtype_ = val;
        }

        inline void constraint_to(constraint_element& holder, const value_element& val) {
            holder.to_ = val;
            holder.tp = cns_ValueRange;
        }

        inline void constraint_totype(constraint_element& holder, const range_type& val) {
            holder.totype_ = val;
            holder.tp = cns_ValueRange;
        }

        inline void constraint_size(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_SizeConstraint;
        }

        inline void constraint_alphabet(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_PermittedAlphabet;
        }

        inline void constraint_singletype(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_SingleTypeConstraint;
        }

        inline void constraint_namedtype(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_NamedConstraint;
        }

        inline void constraint_marker(constraint_element& holder, const constraintmarker_type& val) {
            holder.marker = val;
        }

        inline void constraint_multitype(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_MultipleTypeConstraints;
        }

        inline void constraint_userdef(constraint_element& holder, const string_vector& val) {
            holder.parameters = val;
            //holder.tp = cns_UserDefinedConstraint;
        }

        inline void constraint_relation(constraint_element& holder, const std::string& valr, const string_vector& valp) {
            holder.objsetref = valr;
            holder.parameters = valp;
            holder.tp = cns_ComponentRelation;
        }

        inline void constraint_content_t(constraint_element& holder, const type_element& val) {
            holder.type = val;
            holder.tp = cns_ContentsType;
        }

        inline void constraint_content_v(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_ContentsValue;
        }

        inline void constraint_content_tv(constraint_element& holder, const type_element& valt, const value_element& valv) {
            holder.type = valt;
            holder.value = valv;
            holder.tp = cns_ContentsTypeValue;
        }

        inline void constraint_exceptnumber(constraint_element& holder, const std::string& val) {
            holder.type.value.type = v_number;
            holder.type.value.value = val;
            holder.value.type = v_number;
            holder.value.value = val;
            holder.type.builtin_t = t_INTEGER;
            holder.type.marker = mk_exception;
            holder.tp = cns_EXCEPTION;
        }

        inline void constraint_exceptidentifier(constraint_element& holder, const std::string& val) {
            holder.type.value.type = v_identifier;
            holder.type.value.identifier = val;
            holder.value.type = v_identifier;
            holder.value.identifier = val;
            holder.type.marker = mk_exception;
            holder.tp = cns_EXCEPTION;
        }

        inline void constraint_excepttypevalue(constraint_element& holder, const type_element& valt, const value_element& valv) {
            holder.type = valt;
            holder.type.value = valv;
            holder.value = valv;
            holder.type.marker = mk_exception;
            holder.tp = cns_EXCEPTION;
        }

        inline void push_constraint(constraint_element_vector& holder, const constraint_element& val) {
            holder.push_back(val);
        }

        inline void push_constraints(constraint_element_vector& holder, const constraint_element_vector& val) {
            holder.insert(holder.end(), val.begin(), val.end());
        }

        inline void pushs_constraint(constraints_vector& holder, const constraint_element& val) {
            constraint_element_vector tmp;
            tmp.push_back(val);
            holder.push_back(tmp);
        }


        const constraint_element CONSTRAINT_UNION = constraint_element(cns_UNION);
        const constraint_element CONSTRAINT_INTERSECTION = constraint_element(cns_INTERSECTION);
        const constraint_element CONSTRAINT_EXCEPT = constraint_element(cns_EXCEPT);
        const constraint_element CONSTRAINT_ALLEXCEPT = constraint_element(cns_ALLEXCEPT);
        const constraint_element CONSTRAINT_EXTENTION = constraint_element(cns_EXTENTION, cmk_extention);






        //  value_assignment setter        

        inline void valuea_reference(value_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        inline void valuea_type(value_assignment& holder, const type_element& val) {
            holder.type = val;
        }

        inline void valuea_arguments(value_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }

        inline void valuea_value(value_assignment& holder, const value_element& val, bool exact) {
            holder.value = val;
            holder.exact = exact;
        }








        //  valueset_assignment setter        

        inline void valueset_reference(valueset_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        inline void valueseta_type(valueset_assignment& holder, const type_element& val) {
            holder.type = val;
        }

        inline void valueseta_arguments(valueset_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }

        inline void valueset_set(valueset_assignment& holder, const valueset_element& val, bool exact) {
            holder.set = val;
            holder.exact = exact;
        }






        //  type_assignment setter        

        inline void type_identifier(type_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        inline void type_named(type_assignment& holder, const std::string& ind, const type_element& type) {
            holder.identifier = ind;
            holder.type = type;
        }

        inline void typea_type(type_assignment& holder, const type_element& val) {
            holder.type = val;
        }

        inline void typea_arguments(type_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }

        inline void type_marker(type_assignment& holder, const tagmarker_type& val) {
            holder.type.marker = val;
        }

        inline void type_defaultvalue(type_assignment& holder, const value_element& val) {
            holder.type.marker = mk_default;
            holder.type.value = val;
        }

        inline void type_exceptnumber(type_assignment& holder, const std::string& val) {
            holder.type.value.type = v_number;
            holder.type.value.value = val;
            holder.type.builtin_t = t_INTEGER;
            holder.type.marker = mk_exception;
        }

        inline void type_exceptidetifier(type_assignment& holder, const std::string& val) {
            holder.type.value.type = v_identifier;
            holder.type.value.identifier = val;
            //holder.type.builtin_t = t_INTEGER;
            holder.type.marker = mk_exception;
        }

        inline void type_exceptvalue(type_assignment& holder, const value_element& val) {
            holder.type.value = val;
            holder.type.marker = mk_exception;
        }

        inline void type_push(type_element& holder, const type_assignment& val) {
            holder.elements.push_back(val);
        }

        inline void type_select(type_element& holder, const std::string& ind, const type_element& type) {
            type_assignment tmp;
            tmp.identifier = ind;
            tmp.type = type;
            holder.elements.push_back(tmp);
            holder.builtin_t = t_Selection;
        }


        const type_assignment extention_type_assignment(mk_extention);
        const type_assignment exception_type_assignment(mk_exception);






        // classfield setter

        inline void classfield_field(classfield_type& holder, const std::string& val) {
            holder.field = val;
        }

        inline void classfield_holder_ft(classfield_type& holder, const type_element& val, bool type) {
            if (val.builtin_t == t_Reference) {
                holder.holder = val.reference;
                holder.tp = type ? fkind_FixedType_or_Object : fkind_FixedTypeSet_or_ObjectSet;
            } else {
                holder.tp = type ? fkind_FixedTypeValueFieldSpec : fkind_FixedTypeValueSetFieldSpec;
            }
            holder.holdertype = val;
        }

        inline void classfield_holder(classfield_type& holder, const std::string& val) {
            holder.holder = val;
        }

        inline void classfield_unique(classfield_type& holder) {
            holder.unique = true;
            holder.tp = fkind_FixedTypeValueFieldSpec;
        }

        inline void classfield_optional(classfield_type& holder) {
            holder.marker = field_optional;
        }

        inline void classfield_tp(classfield_type& holder, const fieldkind_type& val) {
            holder.tp = val;
        }

        inline void classfield_defaulttype(classfield_type& holder, const type_element& val) {
            holder.marker = field_defaulttype;
            holder.defaulttype = val;
        }

        inline void classfield_defaultvalue(classfield_type& holder, const value_element& val) {
            holder.marker = field_defaultvalue;
            holder.defaultvalue = val;
        }

        inline void classfield_defaultset(classfield_type& holder, const valueset_element& val) {
            holder.marker = field_defaultset;
            holder.defaultset = val;
        }

        inline void classfield_defaultref(classfield_type& holder, const std::string& val) {
            holder.marker = field_defaultref;
            holder.defaultreff = val;
        }







        // classsintax setter

        inline void classsyntax_alias(classsyntax_type& holder, const std::string& val) {
            holder.alias = val;
        }

        inline void classsyntax_field(classsyntax_type& holder, const std::string& val) {
            holder.field = val;
        }

        inline void classsyntax_agroup(classsyntax_type& holder, const std::string& alias, const classsyntax_vector& group) {
            holder.alias = alias;
            holder.group = group;
            holder.optional = true;
        }

        inline void classsyntax_group(classsyntax_type& holder, const classsyntax_vector& group) {
            holder.group = group;
            holder.optional = true;
        }

        inline void classsyntax_optional(classsyntax_type& holder) {
            holder.optional = true;
        }






        // class_element setter

        const class_element CLASS_TYPE_IDENTIFIER = class_element(cl_TYPE_IDENTIFIER);
        const class_element CLASS_ABSTRACT_SYNTAX = class_element(cl_ABSTRACT_SYNTAX);

        inline void class_type(class_element& holder, const definedclass_type& val) {
            holder.tp = val;
            //cl_TYPE_IDENTIFIER, 
            //cl_ABSTRACT_SYNTAX                  
        }

        inline void class_reference(class_element& holder, const std::string& val) {
            holder.reference = val;
            holder.tp = cl_Reference;
        }

        inline void class_parameters(class_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }

        inline void class_fields(class_element& holder, const classfield_vector& val) {
            holder.fields = val;
        }

        inline void class_syntaxes(class_element& holder, const classsyntax_vector& val) {
            holder.syntaxes = val;
        }






        // class_assigment setter

        inline void classa_reference(class_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        inline void classa_class(class_assignment& holder, const class_element& val) {
            holder.class_ = val;
        }

        inline void classa_set(class_assignment& holder, const std::string& ind, const class_element& cl) {
            holder.identifier = ind;
            holder.class_ = cl;
        }

        inline void classa_arguments(class_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }




        // objectfield setter

        inline void objectfield_field(objectfield_type& holder, const std::string& val) {
            holder.field = val;
        }

        inline void objectfield_typeset(objectfield_type& holder, const type_element& val) {
            holder.holdertype = val;
            holder.tp = ofk_Type;
        }

        inline void objectfield_value(objectfield_type& holder, const value_element& val) {
            holder.holdervalue = val;
            holder.tp = ofk_Value;
        }

        inline void objectfield_valueset(objectfield_type& holder, const valueset_element& val) {
            holder.holdervalueset = val;
            holder.tp = ofk_ValueSet;
        }



        // objectelement setter

        const object_element OBJECT_UNION = object_element(ot_UNION);
        const object_element OBJECT_INTERSECTION = object_element(ot_INTERSECTION);
        const object_element OBJECT_EXCEPT = object_element(ot_EXCEPT);
        const object_element OBJECT_ALLEXCEPT = object_element(ot_ALLEXCEPT);
        const object_element OBJECT_EXTENTION = object_element(ot_EXTENTION);

        inline void object_fields(object_element& holder, const objectfield_vector& val) {
            holder.fields = val;
            holder.tp = ot_Object;
        }

        inline void object_reff(object_element& holder, const std::string& val) {
            holder.reff = val;
            holder.tp = ot_Refference;
        }

        inline void object_raw(object_element& holder, const std::string& val) {
            holder.raw = val;
            holder.tp = ot_Raw;
        }





        // object_assigment setter

        inline void objecta_reference(object_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        inline void objecta_object(object_assignment& holder, const object_element& val) {
            holder.object = val;
        }

        inline void objecta_class(object_assignment& holder, const class_element& val) {
            holder.class_ = val;
        }

        inline void objecta_arguments(object_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }








        // objectset_assigment setter

        inline void objectseta_reference(objectset_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        inline void objectseta_objectset(objectset_assignment& holder, const objectset_element& val) {
            holder.set = val;
        }

        inline void objectseta_class(objectset_assignment& holder, const class_element& val) {
            holder.class_ = val;
        }

        inline void objectseta_arguments(objectset_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }

        inline void push_objects(object_element_vector& holder, const object_element_vector& val) {
            holder.insert(holder.end(), val.begin(), val.end());
        }






        // tepevalue setter

        inline void typevalue_set(typevalue_element& holder, const type_element& tp, const value_element& val) {
            holder.type = tp;
            holder.value = val;
        }

        inline void typevalues_set(typevalue_element_vector& holder, const type_element& tp, const value_element& val) {
            typevalue_element tmp;
            tmp.type = tp;
            tmp.value = val;
            holder.push_back(tmp);
        }




        // Argument setter

        inline void argument_governor_tp(argument_type& holder, const type_element& val, const std::string& par) {
            if (val.builtin_t == t_Reference) {
                holder.governorreff = val.reference;
                holder.tp = gvr_Type_or_Class;
            } else {
                holder.governortype = val;
                holder.tp = gvr_Type;
            }
            holder.argument = par;
        }

        inline void argument_governor_cl(argument_type& holder, const class_element& val, const std::string& par) {
            holder.governorclass = val;
            holder.tp = gvr_Class;
            holder.argument = par;
        }

        inline void argument_governor_reff(argument_type& holder, const std::string& val) {
            holder.governorreff = val;
            holder.tp = gvr_Type_or_Class;
        }

        inline void argument_argument(argument_type& holder, const std::string& val) {
            holder.argument = val;
        }




        // Parameter setter

        inline void parameter_reff(parameter_element& holder, const std::string& val) {
            holder.reff = val;
            holder.tp = prm_Reff;
        }

        inline void parameter_type(parameter_element& holder, const type_element& val) {
            holder.type = val;
            holder.tp = prm_Type;
        }

        inline void parameter_class(parameter_element& holder, const std::string& val) {
            holder.reff = val;
            holder.tp = prm_Class;
        }

        inline void parameter_value(parameter_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = prm_Value;
        }

        inline void parameter_object(parameter_element& holder, const object_element& val) {
            holder.object = val;
            holder.tp = prm_Object;
        }

        inline void parameter_valueset(parameter_element& holder, const valueset_element& val) {
            holder.valueset = val;
            holder.tp = prm_ValueSet;
        }

        inline void parameter_objectset(parameter_element& holder, const objectset_element& val) {
            holder.objectset = val;
            holder.tp = prm_ObjectSet;
        }






    }
}


// FUSION

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::unknown_tc_element,
        (std::string, reff)
        (x680::bnf::parameter_vector, parameters)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::unknown_tc_assignment,
        (std::string, identifier)
        (x680::bnf::argument_vector, arguments)
        (x680::bnf::unknown_tc_element, unknown_tc)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::string_pair_vector,
        (std::vector<x680::bnf::string_pair>, first)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::tag_type,
        (std::string, number)
        (x680::tagclass_type, class_)
        (x680::tagrule_type, rule)
        (x680::encoding_references_type, encoding)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::constraint_element,
        (std::string, identifier)
        (x680::constraint_type, tp)
        (x680::bnf::value_element, value)
        (x680::bnf::value_element, from_)
        (x680::range_type, fromtype_)
        (x680::bnf::value_element, to_)
        (x680::range_type, totype_)
        (x680::bnf::type_element, type)
        (x680::constraintmarker_type, marker)
        (x680::bnf::string_vector, parameters)
        (std::string, objsetref)
        (x680::bnf::constraint_element_vector, constraint)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::value_element,
        (x680::bnf::parameter_vector, parameters)
        (std::string, identifier)
        (std::string, value)
        (x680::value_type, type)
        (x680::bnf::value_element_vector, values)
        (x680::bnf::typevalue_element_vector, typevalue)
        (std::string, fromreff)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::value_assignment,
        (std::string, identifier)
        (x680::bnf::argument_vector, arguments)
        (x680::bnf::type_element, type)
        (x680::bnf::value_element, value)
        (bool, exact)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::valueset_assignment,
        (std::string, identifier)
        (x680::bnf::argument_vector, arguments)
        (x680::bnf::type_element, type)
        (x680::bnf::valueset_element, set)
        (bool, exact)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::type_element,
        (x680::tag_type, tag)
        (x680::bnf::parameter_vector, parameters)
        (x680::tagmarker_type, marker)
        (x680::bnf::value_element, value)
        (std::string, reference)
        (x680::defined_type, builtin_t)
        (x680::bnf::named_type_element_vector, elements)
        (x680::bnf::value_element_vector, predefined)
        (x680::bnf::constraints_vector, constraints)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::type_assignment,
        (std::string, identifier)
        (x680::bnf::argument_vector, arguments)
        (x680::bnf::type_element, type)
        (x680::bnf::constraint_element_vector, constraints)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::classfield_type,
        (std::string, field)
        (std::string, holder)
        (x680::bnf::type_element, holdertype)
        (x680::fieldmarker_type, marker)
        (x680::fieldkind_type, tp)
        (bool, unique)
        (x680::bnf::type_element, defaulttype)
        (x680::bnf::value_element, defaultvalue)
        (x680::bnf::valueset_element, defaultset)
        (std::string, defaultreff)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::classsyntax_type,
        (std::string, alias)
        (std::string, field)
        (bool, optional)
        (x680::bnf::classsyntax_vector, group)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::class_element,
        (x680::definedclass_type, tp)
        (x680::bnf::parameter_vector, parameters)
        (std::string, reference)
        (x680::bnf::classfield_vector, fields)
        (x680::bnf::classsyntax_vector, syntaxes)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::class_assignment,
        (std::string, identifier)
        (x680::bnf::argument_vector, arguments)
        (x680::bnf::class_element, class_)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::objectfield_type,
        (std::string, field)
        (x680::objectfieldkind_type, tp)
        (x680::bnf::type_element, holdertype)
        (x680::bnf::value_element, holdervalue)
        (x680::bnf::valueset_element, holdervalueset)
        (std::string, holderreff)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::object_element,
        (x680::bnf::objectfield_vector, fields)
        (x680::object_type, tp)
        (std::string, reff)
        (std::string, raw)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::object_assignment,
        (std::string, identifier)
        (x680::bnf::argument_vector, arguments)
        (x680::bnf::class_element, class_)
        (x680::bnf::object_element, object)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::objectset_assignment,
        (std::string, identifier)
        (x680::bnf::argument_vector, arguments)
        (x680::bnf::class_element, class_)
        (x680::bnf::objectset_element, set)
        )


BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::argument_type,
        (std::string, governorreff)
        (x680::bnf::type_element, governortype)
        (x680::bnf::class_element, governorclass)
        (x680::governor_type, tp)
        (std::string, argument)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::parameter_element,
        (x680::parameter_type, tp)
        (x680::bnf::type_element, type)
        (x680::bnf::class_element, class_)
        (x680::bnf::value_element, value)
        (x680::bnf::object_element, object)
        (x680::bnf::valueset_element, valueset)
        (x680::bnf::objectset_element, objectset)
        (std::string, reff)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::typevalue_element,
        (x680::bnf::type_element, type)
        (x680::bnf::value_element, value)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::import,
        (std::string, name)
        (x680::bnf::value_element, oid)
        (x680::bnf::string_vector, names)
        )

BOOST_FUSION_ADAPT_STRUCT(
        x680::bnf::module,
        (std::string, name)
        (x680::bnf::value_element, oid)
        (x680::encoding_references_type, encoding_references_t)
        (x680::tagrule_type, default_tags_t)
        (bool, extesibility_implied)
        (x680::bnf::exports, exports_)
        (x680::bnf::imports, imports_)
        (x680::bnf::assignment_vector, elements)
        )

#endif	

