//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/setters.hpp>

namespace x680 {
    namespace syntactic {

        //  tag_rule

        void tag_rule(tag_type& holder, const tagrule_type& val) {
            holder.rule = val;
        }

        void tag_class(tag_type& holder, const tagclass_type& val) {
            holder.class_ = val;
        }

        void tag_encoding(tag_type& holder, const encoding_references_type& val) {
            holder.encoding = val;
        }

        void tag_number(tag_type& holder, const std::string& val) {
            holder.number = val;
        }


        //  unknown_tc_element setter            

        void unknown_tc_refference(unknown_tc_element& holder, const std::string& val) {
            holder.reff = val;
        }

        void unknown_tc_parameters(unknown_tc_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }



        //  unknown_tc_assignment setter        

        void unknown_tca_identifier(unknown_tc_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        void unknown_tca(unknown_tc_assignment& holder, const unknown_tc_element& val) {
            holder.unknown_tc = val;
        }

        void unknown_tca_arguments(unknown_tc_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }

        void unknown_tca_type(unknown_tc_assignment& holder, const type_assignment& val) {
            holder.typea = type_assignment_ptr(new type_assignment(val));
            holder.alternative_ |= AS_TYPE;
        }

        void unknown_tca_class(unknown_tc_assignment& holder, const class_assignment& val) {
            holder.classa = class_assignment_ptr(new class_assignment(val));
            holder.alternative_ |= AS_CLASS;
        }


        //  unknown_vo_element setter            

        void unknown_vo_refference(unknown_vo_element& holder, const std::string& val) {
            holder.reff = val;
        }

        void unknown_vo_parameters(unknown_vo_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }

        void unknown_vo_value(unknown_vo_element& holder, const value_element& val) {
            holder.value_ = value_element_ptr(new value_element(val));
            holder.alternative_ |= AS_VALUE;
        }

        void unknown_vo_object(unknown_vo_element& holder, const object_element& val) {
            holder.object_ = object_element_ptr(new object_element(val));
            holder.alternative_ |= AS_OBJECT;
        }



        //  unknown_vo_assignment setter        

        void unknown_voa_identifier(unknown_vo_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        void unknown_voa_refference(unknown_vo_assignment& holder, const std::string& val) {
            holder.reff = val;
        }


        void unknown_voa_value(unknown_vo_assignment& holder, const value_assignment& val) {
            holder.valuea = value_assignment_ptr(new value_assignment(val));
            holder.alternative_ |= AS_VALUE;
        }

        void unknown_voa_object(unknown_vo_assignment& holder, const object_assignment& val) {
            holder.objecta = object_assignment_ptr(new object_assignment(val));
            holder.alternative_ |= AS_OBJECT;
        }


        //  unknown_so_element setter            

        void unknown_so_parameters(unknown_so_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }

        void unknown_so_valueset(unknown_so_element& holder, const valueset_element& val) {
            holder.valueset_ = valueset_element_ptr(new valueset_element(val));
            holder.alternative_ |= AS_VALUESET;
        }

        void unknown_so_objectset(unknown_so_element& holder, const objectset_element& val) {
            holder.objectset_ = objectset_element_ptr(new objectset_element(val));
            holder.alternative_ |= AS_OBJECTSET;
        }



        //  unknown_so_assignment setter        

        void unknown_soa_identifier(unknown_so_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        void unknown_soa_refference(unknown_so_assignment& holder, const std::string& val) {
            holder.reff = val;
        }

        void unknown_soa_valueset(unknown_so_assignment& holder, const valueset_assignment& val) {
            holder.valueseta = valueset_assignment_ptr(new valueset_assignment(val));
            holder.alternative_ |= AS_VALUESET;
        }

        void unknown_soa_objectset(unknown_so_assignment& holder, const objectset_assignment& val) {
            holder.objectseta = objectset_assignment_ptr(new objectset_assignment(val));
            holder.alternative_ |= AS_OBJECTSET;
        }



        //  value_element setter            

        void value_parameters(value_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }

        void value_setdefined(value_element& holder, const std::string& val) {
            holder.type = v_defined;
            holder.identifier = val;
        }

        void value_setassigned(value_element& holder, const std::string& id, const std::string& val) {
            holder.type = v_defined_assign;
            holder.identifier = id;
            holder.value = val;
        }

        void value_setassignedval(value_element& holder, const std::string& id, const value_element& val) {
            holder.type = v_defined_assign; //val;
            holder.identifier = id;
            holder.values.push_back(val);
        }

        void value_emptyset(value_element& holder) {
            holder.type = v_empty;
        }

        void value_setnumber(value_element& holder, const std::string& val) {
            holder.type = v_number;
            holder.value = val;
        }

        void value_setreal(value_element& holder, const std::string& val) {
            holder.type = v_real;
            holder.value = val;
        }

        void value_setnull(value_element& holder) {
            holder.type = v_null;
            holder.value = "NULL";
        }

        void value_setbstring(value_element& holder, const std::string& val) {
            holder.type = v_bstring;
            holder.value = val;
        }

        void value_sethstring(value_element& holder, const std::string& val) {
            holder.type = v_hstring;
            holder.value = val;
        }

        void value_setcstring(value_element& holder, const std::string& val) {
            holder.type = v_cstring;
            holder.value = val;
        }

        void value_setvalues(value_element& holder, const value_element_vector& values, const value_type& tp) {
            holder.type = tp;
            holder.values = values;
        }

        void value_setvalue(value_element& holder, const std::string& id, const value_element& val, const value_type& tp) {
            holder.identifier = id;
            holder.type = tp;
            holder.values.push_back(val);
            ;
        }

        void value_namedval(value_element& holder, const std::string& id, const value_element& val) {
            holder.identifier = id;
            holder.type = v_named_value;
            holder.values.push_back(val);
        }

        void value_choiceval(value_element& holder, const std::string& id, const value_element& val) {
            holder.identifier = id;
            holder.type = v_choice;
            holder.values.push_back(val);
        }

        void value_typevalue(value_element& holder, const typevalue_element& val) {
            holder.type = v_open;
            holder.typevalue = typevalue_element_ptr(new typevalue_element(val));
        }

        void value_fromobject(value_element& holder, const object_element& val, const std::string& reff) {
            holder.objectref = object_element_ptr(new object_element(val));
            holder.fieldreference = reff;
            holder.type = v_ValueFromObject;
        }

        void value_exception(value_element& holder, const std::string& val) {
            holder.type = v_exception;
            holder.value = val;
        }

        void values_enum_pushs(value_element_vector& holder, const value_element_vector& val) {
            holder.insert(holder.end(), val.begin(), val.end());
        }

        void values_enum_push(value_element_vector& holder, const value_element& val) {
            holder.push_back(val);
        }








        //  type_element setter        

        void type_deff(type_element& holder, const defined_type& type) {
            holder.builtin_t = type;
        }

        void type_refference(type_element& holder, const std::string& val) {
            holder.reference = val;
            holder.builtin_t = t_Reference;
        }

        void type_objectfield(type_element& holder, const std::string& val, const std::string& reff) {
            holder.reference = val;
            holder.fieldreference = reff;
            holder.builtin_t = t_ClassField;
        }

        void type_fromobject(type_element& holder, const object_element& val, const std::string& reff) {
            holder.objectref = object_element_ptr(new object_element(val));
            holder.fieldreference = reff;
            holder.builtin_t = t_TypeFromObject;
        }

        void type_fromobjectset(type_element& holder, const objectset_element& val, const std::string& reff) {
            holder.objectsetref = objectset_element_ptr(new objectset_element(val));
            holder.fieldreference = reff;
            holder.builtin_t = t_ValueSetFromObjects;
        }

        void type_parameters(type_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }

        void type_instance(type_element& holder, const std::string& val) {
            holder.reference = val;
            holder.builtin_t = t_Instance_Of;
        }

        void type_deffinit(type_element& holder, const value_element_vector & val) {
            holder.predefined = val;
        }

        void type_tag(type_element& holder, const tag_type& val) {
            holder.tag = val;
        }

        void type_tagged(type_element& holder, const tag_type& tg, const type_element& val) {
            holder = val;
            holder.tag = tg;
        }

        void type_pushs(type_element& holder, const type_assignment_vector& val) {
            holder.elements.insert(holder.elements.end(), val.begin(), val.end());
        }

        void type_constraints(type_element& holder, const constraints_vector& val) {
            holder.constraints = val;
        }








        //  constraint_element setter

        void constraint_tp(constraint_element& holder, const constraint_type& val) {
            holder.tp = val;
        }

        void constraint_setelement(constraint_element& holder, const objectset_element& val) {
            holder.objectsetref = objectset_element_ptr(new objectset_element(val));
            holder.tp = cns_SimpleTableConstraint;
        }

        void constraint_identifier(constraint_element& holder, const std::string& val) {
            holder.identifier = val;
            holder.tp = cns_NamedConstraint;
        }

        void constraint_singlevalue(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_SingleValue;
        }

        void constraint_subtype(constraint_element& holder, const type_element& val) {
            holder.type = val;
            holder.tp = cns_ContainedSubtype;
        }

        void constraint_typeset(constraint_element& holder, const type_element& val) {
            holder.type = val;
            holder.tp = cns_TypeConstraint;
        }

        void constraint_patterntype(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_PatternConstraint;
        }

        void constraint_property(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_PropertySettings;
        }

        void constraint_from(constraint_element& holder, const value_element& val) {
            holder.from_ = val;
        }

        void constraint_fromtype(constraint_element& holder, const range_type& val) {
            holder.fromtype_ = val;
        }

        void constraint_to(constraint_element& holder, const value_element& val) {
            holder.to_ = val;
            holder.tp = cns_ValueRange;
        }

        void constraint_totype(constraint_element& holder, const range_type& val) {
            holder.totype_ = val;
            holder.tp = cns_ValueRange;
        }

        void constraint_size(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_SizeConstraint;
        }

        void constraint_alphabet(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_PermittedAlphabet;
        }

        void constraint_singletype(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_SingleTypeConstraint;
        }

        void constraint_namedtype(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_NamedConstraint;
        }

        void constraint_marker(constraint_element& holder, const constraintmarker_type& val) {
            holder.marker = val;
        }

        void constraint_multitype(constraint_element& holder, const constraint_element_vector& val) {
            holder.constraint = val;
            holder.tp = cns_MultipleTypeConstraints;
        }

        void constraint_userdef(constraint_element& holder, const uargument_vector& val) {
            holder.uparameters = val;
            holder.tp = cns_UserDefinedConstraint;
        }

        void constraint_relation(constraint_element& holder, const objectset_element& valr, const string_vector& valp) {
            holder.objectsetref = objectset_element_ptr(new objectset_element(valr));
            holder.parameters = valp;
            holder.tp = cns_ComponentRelation;
        }

        void constraint_content_t(constraint_element& holder, const type_element& val) {
            holder.type = val;
            holder.tp = cns_Contents;
        }

        void constraint_content_v(constraint_element& holder, const value_element& val) {
            holder.value = val;
            holder.tp = cns_Contents;
        }

        void constraint_content_tv(constraint_element& holder, const type_element& valt, const value_element& valv) {
            holder.type = valt;
            holder.value = valv;
            holder.tp = cns_Contents;
        }

        void constraint_exceptnumber(constraint_element& holder, const std::string& val) {
            holder.type.value.type = v_number;
            holder.type.value.value = val;
            holder.value.type = v_number;
            holder.value.value = val;
            holder.type.builtin_t = t_INTEGER;
            holder.type.marker = mk_exception;
            holder.tp = cns_EXCEPTION;
        }

        void constraint_exceptidentifier(constraint_element& holder, const std::string& val) {
            holder.type.value.type = v_defined;
            holder.type.value.identifier = val;
            holder.value.type = v_defined;
            holder.value.identifier = val;
            holder.type.marker = mk_exception;
            holder.tp = cns_EXCEPTION;
        }

        void constraint_excepttypevalue(constraint_element& holder, const type_element& valt, const value_element& valv) {
            holder.type = valt;
            holder.type.value = valv;
            holder.value = valv;
            holder.type.marker = mk_exception;
            holder.tp = cns_EXCEPTION;
        }

        void constraint_fromobject(constraint_element& holder, const object_element& val, const std::string& reff) {
            holder.objectref = object_element_ptr(new object_element(val));
            holder.fieldreference = reff;
            holder.tp = cns_ValueSetFromObject;
        }

        void constraint_fromobjects(constraint_element& holder, const objectset_element& val, const std::string& reff) {
            holder.objectsetref = objectset_element_ptr(new objectset_element(val));
            holder.fieldreference = reff;
            holder.tp = cns_ValueSetFromObjects;
        }
        
        void constraint_tvsos(constraint_element& holder, const std::string& reff) {
            holder.identifier = reff;
            holder.tp = cns_Undef_T_ST_VS;
        }        

        void push_constraint(constraint_element_vector& holder, const constraint_element& val) {
            holder.push_back(val);
        }

        void push_constraints(constraint_element_vector& holder, const constraint_element_vector& val) {
            holder.insert(holder.end(), val.begin(), val.end());
        }

        void pushs_constraint(constraints_vector& holder, const constraint_element& val) {
            constraint_element_vector tmp;
            tmp.push_back(val);
            holder.push_back(tmp);
        }



        
        //  value_assignment setter        

        void valuea_reference(value_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        void valuea_type(value_assignment& holder, const type_element& val) {
            holder.type = val;
        }

        void valuea_arguments(value_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }

        void valuea_value(value_assignment& holder, const value_element& val) {
            holder.value = val;
        }


        //  valueset_element setter   

        void valueset_parameters(valueset_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }

        void valueset_set(valueset_element& holder, const constraint_element_vector& val) {
            holder.set = val;
            holder.tp = vs_Strait;
        }

        void valueset_defined(valueset_element& holder, const std::string& val) {
            holder.reference = val;
            holder.tp = vs_defined;
        }

        void valueset_fromobject(valueset_element& holder, const object_element& val, const std::string& reff) {
            holder.objectref = object_element_ptr(new object_element(val));
            holder.fieldreference = reff;
            holder.tp = vs_ValueSetFromObject;
        }

        void valueset_fromobjects(valueset_element& holder, const objectset_element& val, const std::string& reff) {
            holder.objectsetref = objectset_element_ptr(new objectset_element(val));
            holder.fieldreference = reff;
            holder.tp = vs_ValueSetFromObjects;
        }



        //  valueset_assignment setter        

        void valueset_reference(valueset_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        void valueseta_type(valueset_assignment& holder, const type_element& val) {
            holder.type = val;
        }

        void valueseta_arguments(valueset_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }

        void valueseta_set(valueset_assignment& holder, const valueset_element& val) {
            holder.set = val;
        }






        //  type_assignment setter        

        void type_identifier(type_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        void type_named(type_assignment& holder, const std::string& ind, const type_element& type) {
            holder.identifier = ind;
            holder.type = type;
        }

        void typea_type(type_assignment& holder, const type_element& val) {
            holder.type = val;
        }

        void typea_arguments(type_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }

        void type_marker(type_assignment& holder, const tagmarker_type& val) {
            holder.type.marker = val;
        }

        void type_defaultvalue(type_assignment& holder, const value_element& val) {
            holder.type.marker = mk_default;
            holder.type.value = val;
        }

        void type_exceptnumber(type_assignment& holder, const std::string& val) {
            holder.type.value.type = v_number;
            holder.type.value.value = val;
            holder.type.builtin_t = t_INTEGER;
            holder.type.marker = mk_exception;
        }

        void type_exceptidetifier(type_assignment& holder, const std::string& val) {
            holder.type.value.type = v_defined;
            holder.type.value.identifier = val;
            holder.type.builtin_t = t_INTEGER;
            holder.type.marker = mk_exception;
        }

        void type_exceptvalue(type_assignment& holder, const value_element& val) {
            holder.type.value = val;
            holder.type.marker = mk_exception;
        }

        void type_push(type_element& holder, const type_assignment& val) {
            holder.elements.push_back(val);
        }

        void type_select(type_element& holder, const std::string& ind, const type_element& type) {
            type_assignment tmp;
            tmp.identifier = ind;
            tmp.type = type;
            holder.elements.push_back(tmp);
            holder.builtin_t = t_Selection;
        }








        // classfield setter

        void classfield_field(classfield_type& holder, const std::string& val) {
            holder.field = val;
        }

        void classfield_holder_undf(classfield_type& holder, const std::string& val, bool type) {
            holder.holder = val;
            holder.tp = type ? fkind_FixedType_or_Object : fkind_FixedTypeSet_or_ObjectSet;
        }

        void classfield_holder_ft(classfield_type& holder, const type_element& val, bool type) {
            holder.tp = type ? fkind_FixedTypeValueFieldSpec : fkind_FixedTypeValueSetFieldSpec;
            holder.holdertype = val;
        }

        void classfield_holder_cl(classfield_type& holder, const class_element& val, bool type) {
            holder.tp = type ? fkind_ObjectFieldSpec : fkind_ObjectSetFieldSpec;
            holder.holderclass = class_element_ptr(new class_element(val));
        }

        void classfield_holder(classfield_type& holder, const std::string& val) {
            holder.holder = val;
        }

        void classfield_unique(classfield_type& holder) {
            holder.unique = true;
            holder.tp = fkind_FixedTypeValueFieldSpec;
        }

        void classfield_optional(classfield_type& holder) {
            holder.marker = field_optional;
        }

        void classfield_tp(classfield_type& holder, const fieldkind_type& val) {
            holder.tp = val;
        }

        void classfield_defaulttype(classfield_type& holder, const type_element& val) {
            holder.marker = field_defaulttype;
            holder.defaulttype = val;
        }

        void classfield_defaultvalue(classfield_type& holder, const value_element& val) {
            holder.marker = field_defaultvalue;
            holder.defaultvalue = val;
        }

        void classfield_defaultset(classfield_type& holder, const valueset_element& val) {
            holder.marker = field_defaultset;
            holder.defaultset = val;
        }

        void classfield_defaultovalue(classfield_type& holder, const object_element& val) {
            holder.marker = field_defaultovalue;
            holder.defaultovalue = object_element_ptr(new object_element(val));
        }

        void classfield_defaultoset(classfield_type& holder, const objectset_element& val) {
            holder.marker = field_defaultoset;
            holder.defaultoset = objectset_element_ptr(new objectset_element(val));
        }

        void classfield_defaultov(classfield_type& holder, const unknown_vo_element& val) {
            holder.marker = field_defaultov;
            holder.defvalobj = val;
        }

        void classfield_defaultos(classfield_type& holder, const unknown_so_element& val) {
            holder.marker = field_defaultos;
            holder.defvalobjset = val;
        }







        // classsintax setter

        void classsyntax_alias(classsyntax_type& holder, const std::string& val) {
            holder.alias = val;
        }

        void classsyntax_field(classsyntax_type& holder, const std::string& val) {
            holder.field = val;
        }

        void classsyntax_agroup(classsyntax_type& holder, const std::string& alias, const classsyntax_vector& group) {
            holder.alias = alias;
            holder.group = group;
            holder.optional = true;
        }

        void classsyntax_group(classsyntax_type& holder, const classsyntax_vector& group) {
            holder.group = group;
            holder.optional = true;
        }

        void classsyntax_optional(classsyntax_type& holder) {
            holder.optional = true;
        }






        // class_element setter

        void class_type(class_element& holder, const definedclass_type& val) {
            holder.tp = val;
            //cl_TYPE_IDENTIFIER, 
            //cl_ABSTRACT_SYNTAX                  
        }

        void class_reference(class_element& holder, const std::string& val) {
            holder.reference = val;
            holder.tp = cl_Reference;
        }

        void class_parameters(class_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }

        void class_fields(class_element& holder, const classfield_vector& val) {
            holder.fields = val;
        }

        void class_syntaxes(class_element& holder, const classsyntax_vector& val) {
            holder.syntaxes = val;
        }






        // class_assigment setter

        void classa_reference(class_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        void classa_class(class_assignment& holder, const class_element& val) {
            holder.class_ = val;
        }

        void classa_set(class_assignment& holder, const std::string& ind, const class_element& cl) {
            holder.identifier = ind;
            holder.class_ = cl;
        }

        void classa_arguments(class_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }





        // setting setter        

        void setting_settype(setting_element& holder, const type_element& val) {
            holder.type = type_element_ptr(new type_element(val));
            holder.alternative |= AS_TYPE;
        }

        void setting_value(setting_element& holder, const value_element& val) {
            holder.value = value_element_ptr(new value_element(val));
            holder.alternative |= AS_VALUE;
        }

        void setting_valueset(setting_element& holder, const valueset_element& val) {
            holder.valueset = valueset_element_ptr(new valueset_element(val));
            holder.alternative |= AS_VALUESET;
        }

        void setting_class(setting_element& holder, const class_element& val) {
            holder.class_ = class_element_ptr(new class_element(val));
            holder.alternative |= AS_CLASS;
        }

        void setting_object(setting_element& holder, const object_element& val) {
            holder.object = object_element_ptr(new object_element(val));
            holder.alternative |= AS_OBJECT;
        }

        void setting_objectset(setting_element& holder, const objectset_element& val) {
            holder.objectset = objectset_element_ptr(new objectset_element(val));
            holder.alternative |= AS_OBJECTSET;
        }

        void setting_literal(setting_element& holder, const std::string& val) {
            holder.literal = boost::algorithm::trim_right_copy(val);
            holder.alternative |= AS_LITERAL;
        }









        // objectfield setter

        void objectfield_field(objectfield_type& holder, const std::string& val) {
            holder.field = val;
        }

        void objectfield_setting(objectfield_type& holder, const setting_element& val) {
            holder.setting = val;
        }





        // object_element setter

        void object_parameters(object_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }

        void object_fields(object_element& holder, const objectfield_vector& val) {
            holder.fields = val;
        }

        void object_typeset(object_element& holder, const object_type& val) {
            holder.tp = val;
        }

        void object_refference(object_element& holder, const std::string& val) {
            holder.reff = val;
            holder.tp = ot_Refference;
        }

        void object_fromobject(object_element& holder, const object_element& val, const std::string& reff) {
            holder.objectref = object_element_ptr(new object_element(val));
            holder.fieldreference = reff;
            holder.tp = ot_FromObject;
        }

        void object_objectsetdef(object_element& holder, const objectset_element& val) {
            holder.objectsetref = objectset_element_ptr(new objectset_element(val));
            holder.tp = ot_DefinedObjectSet;
        }

        void object_objectsetfromobjects(object_element& holder, const objectset_element& val, const std::string& reff) {
            holder.objectsetref = objectset_element_ptr(new objectset_element(val));
            holder.fieldreference = reff;
            holder.tp = ot_ObjectSetFromObjects;
        }

        void object_objectsetfromobject(object_element& holder, const object_element& val, const std::string& reff) {
            holder.objectref = object_element_ptr(new object_element(val));
            holder.fieldreference = reff;
            holder.tp = ot_ObjectSetFromObject;
        }





        // object_assigment setter

        void objecta_reference(object_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        void objecta_object(object_assignment& holder, const object_element& val) {
            holder.object = val;
        }

        void objecta_class(object_assignment& holder, const class_element& val) {
            holder.class_ = val;
        }

        void objecta_arguments(object_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }







        //  objectset_element setter   

        void objectset_parameters(objectset_element& holder, const parameter_vector& val) {
            holder.parameters = val;
        }

        void objectset_set(objectset_element& holder, const object_element_vector& val) {
            holder.set = val;
            holder.tp = os_Strait;
        }

        void objectset_defined(objectset_element& holder, const std::string& val) {
            holder.reference = val;
            holder.tp = os_defined;
        }

        void objectset_fromobject(objectset_element& holder, const object_element& val, const std::string& reff) {
            holder.objectref = object_element_ptr(new object_element(val));
            holder.fieldreference = reff;
            holder.tp = os_ObjectSetFromObject;
        }

        void objectset_fromobjects(objectset_element& holder, const objectset_element& val, const std::string& reff) {
            holder.objectsetref = objectset_element_ptr(new objectset_element(val));
            holder.fieldreference = reff;
            holder.tp = os_ObjectSetFromObjects;
        }




        // objectset_assigment setter

        void objectseta_reference(objectset_assignment& holder, const std::string& val) {
            holder.identifier = val;
        }

        void objectseta_objectset(objectset_assignment& holder, const objectset_element& val) {
            holder.set = val;
        }

        void objectseta_class(objectset_assignment& holder, const class_element& val) {
            holder.class_ = val;
        }

        void objectseta_arguments(objectset_assignment& holder, const argument_vector& val) {
            holder.arguments = val;
        }

        void push_objects(object_element_vector& holder, const object_element_vector& val) {
            holder.insert(holder.end(), val.begin(), val.end());
        }






        // tepevalue setter

        void typevalue_set(typevalue_element& holder, const type_element& tp, const value_element& val) {
            holder.type = tp;
            holder.value = val;
        }

        void typevalues_set(typevalue_element& holder, const type_element& tp, const value_element& val) {
            holder.type = tp;
            holder.value = val;
        }




        // Argument setter

        void argument_governor_tp(argument_type& holder, const type_element& val, const std::string& par, bool big) {
            holder.governortype = val;
            holder.tp = gvr_Type;
            holder.argument = par;
            holder.atp = big ? argm_Big : argm_Little;
        }

        void argument_governor_cl(argument_type& holder, const class_element& val, const std::string& par, bool big) {
            holder.governorclass = val;
            holder.tp = gvr_Class;
            holder.argument = par;
            holder.atp = big ? argm_Big : argm_Little;
        }

        void argument_governor_reff(argument_type& holder, const std::string& val, const std::string& par, bool big) {
            holder.reff = val;
            holder.tp = gvr_Type_or_Class;
            holder.argument = par;
            holder.atp = big ? argm_Big : argm_Little;
        }

        void argument_argument(argument_type& holder, const std::string& val, bool big) {
            holder.argument = val;
            holder.atp = big ? argm_Big : argm_Little;
        }

        
        // UArgument setter

        void uargument_governor_tp(uargument_type& holder, const type_element& val, const setting_element& sett) {
            holder.governortype = val;
            holder.tp = gvr_Type;
            holder.parameter = sett;
        }

        void uargument_governor_cl(uargument_type& holder, const class_element& val, const setting_element& sett) {
            holder.governorclass = val;
            holder.tp = gvr_Class;
            holder.parameter = sett;
        }

        void uargument_governor_reff(uargument_type& holder, const std::string& val, const setting_element& sett) {
            holder.reff = val;
            holder.tp = gvr_Type_or_Class;
            holder.parameter = sett;
        }

        void uargument_setting(uargument_type& holder, const setting_element& sett) {
            holder.parameter = sett;
        }        

        // Module setter       

        void module_name(module& holder, const std::string& val) {
            holder.name = val;
        }

        void module_oid(module& holder, const value_element& val) {
            holder.oid = val;
        }

        void module_iri(module& holder, const std::string& val) {
            holder.iri = val;
        }

        void module_tags(module& holder, const tagrule_type & val) {
            holder.default_tags_t = val;
        }

        void module_encoding(module& holder, const encoding_references_type & val) {
            holder.encoding_references_t = val;
        }

        void module_extesibility(module & holder) {
            holder.extesibility_implied = true;
        }

        void module_allexport(module & holder) {
            holder.allexport = true;
        }

        void module_exports(module& holder, const string_vector& val) {
            holder.exports_ = val;
        }

        void module_imports(module& holder, const imports& val) {
            holder.imports_ = val;
        }

        void module_assignments(module& holder, const assignment_vector& val) {
            holder.elements = val;
        }





        // Import setter            

        void import_name(import& holder, const std::string & val) {
            holder.name = val;
        }

        void import_oid(import& holder, const value_element & val) {
            holder.oid = val;
        }

        void import_defined(import& holder, const value_element & val) {
            holder.defined = val;
        }

        void import_add(import& holder, const string_vector & val) {
            holder.names = val;
        }


    }
}