//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680VALUEPARSER_H_
#define         _ITU_X680VALUEPARSER_H_

#include <boost/itu/x68X/x680.hpp>

namespace x680 {
    namespace syntactic {


        //  tag_rule

        void tag_rule(tag_type& holder, const tagrule_type& val);

        void tag_class(tag_type& holder, const tagclass_type& val);

        void tag_encoding(tag_type& holder, const encoding_references_type& val);

        void tag_number(tag_type& holder, const std::string& val);


        //  unknown_tc_element setter            

        void unknown_tc_refference(unknown_tc_element& holder, const std::string& val);

        void unknown_tc_parameters(unknown_tc_element& holder, const parameter_vector& val);



        //  unknown_tc_assignment setter        

        void unknown_tca_identifier(unknown_tc_assignment& holder, const std::string& val);

        void unknown_tca(unknown_tc_assignment& holder, const unknown_tc_element& val);

        void unknown_tca_arguments(unknown_tc_assignment& holder, const argument_vector& val);

        void unknown_tca_type(unknown_tc_assignment& holder, const type_assignment& val);

        void unknown_tca_class(unknown_tc_assignment& holder, const class_assignment& val);


        //  unknown_vo_element setter            

        void unknown_vo_refference(unknown_vo_element& holder, const std::string& val);

        void unknown_vo_parameters(unknown_vo_element& holder, const parameter_vector& val);

        void unknown_vo_value(unknown_vo_element& holder, const value_element& val);

        void unknown_vo_object(unknown_vo_element& holder, const object_element& val);



        //  unknown_vo_assignment setter        

        void unknown_voa_identifier(unknown_vo_assignment& holder, const std::string& val);

        void unknown_voa_refference(unknown_vo_assignment& holder, const std::string& val);

        void unknown_voa_value(unknown_vo_assignment& holder, const value_assignment& val);

        void unknown_voa_object(unknown_vo_assignment& holder, const object_assignment& val);


        //  unknown_so_element setter            

        void unknown_so_parameters(unknown_so_element& holder, const parameter_vector& val);

        void unknown_so_valueset(unknown_so_element& holder, const valueset_element& val);

        void unknown_so_objectset(unknown_so_element& holder, const objectset_element& val);



        //  unknown_so_assignment setter        

        void unknown_soa_identifier(unknown_so_assignment& holder, const std::string& val);

        void unknown_soa_refference(unknown_so_assignment& holder, const std::string& val);

        void unknown_soa_valueset(unknown_so_assignment& holder, const valueset_assignment& val);

        void unknown_soa_objectset(unknown_so_assignment& holder, const objectset_assignment& val);



        //  value_element setter            

        const value_element VALUE_BOOL_TRUE = value_element(true);
        const value_element VALUE_BOOL_FALSE = value_element(false);
        const value_element VALUE_EXTENTION = value_element(v_extention);

        void value_parameters(value_element& holder, const parameter_vector& val);

        void value_setdefined(value_element& holder, const std::string& val);

        void value_setassigned(value_element& holder, const std::string& id, const std::string& val);

        void value_setassignedval(value_element& holder, const std::string& id, const value_element& val);

        void value_emptyset(value_element& holder);

        void value_setnumber(value_element& holder, const std::string& val);

        void value_setreal(value_element& holder, const std::string& val);

        void value_setnull(value_element& holder);

        void value_setbstring(value_element& holder, const std::string& val);

        void value_sethstring(value_element& holder, const std::string& val);

        void value_setcstring(value_element& holder, const std::string& val);

        void value_setvalues(value_element& holder, const value_element_vector& values, const value_type& tp);

        void value_setvalue(value_element& holder, const std::string& id, const value_element& val, const value_type& tp);

        void value_namedval(value_element& holder, const std::string& id, const value_element& val);

        void value_choiceval(value_element& holder, const std::string& id, const value_element& val);

        void value_typevalue(value_element& holder, const typevalue_element& val);

        void value_fromobject(value_element& holder, const object_element& val, const std::string& reff);

        void value_exception(value_element& holder, const std::string& val);

        void values_enum_pushs(value_element_vector& holder, const value_element_vector& val);

        void values_enum_push(value_element_vector& holder, const value_element& val);








        //  type_element setter        

        void type_deff(type_element& holder, const defined_type& type);

        void type_refference(type_element& holder, const std::string& val);

        void type_objectfield(type_element& holder, const std::string& val, const std::string& reff);

        void type_fromobject(type_element& holder, const object_element& val, const std::string& reff);

        void type_fromobjectset(type_element& holder, const objectset_element& val, const std::string& reff);

        void type_parameters(type_element& holder, const parameter_vector& val);

        void type_instance(type_element& holder, const std::string& val);

        void type_deffinit(type_element& holder, const value_element_vector & val);

        void type_tag(type_element& holder, const tag_type& val);

        void type_tagged(type_element& holder, const tag_type& tg, const type_element& val);

        void type_pushs(type_element& holder, const type_assignment_vector& val);

        void type_constraints(type_element& holder, const constraints_vector& val);








        //  constraint_element setter

        void constraint_tp(constraint_element& holder, const constraint_type& val);

        void constraint_setelement(constraint_element& holder, const objectset_element& val);

        void constraint_identifier(constraint_element& holder, const std::string& val);

        void constraint_singlevalue(constraint_element& holder, const value_element& val);

        void constraint_subtype(constraint_element& holder, const type_element& val);

        void constraint_typeset(constraint_element& holder, const type_element& val);

        void constraint_patterntype(constraint_element& holder, const value_element& val);

        void constraint_property(constraint_element& holder, const value_element& val);

        void constraint_from(constraint_element& holder, const value_element& val);

        void constraint_fromtype(constraint_element& holder, const range_type& val);

        void constraint_to(constraint_element& holder, const value_element& val);

        void constraint_totype(constraint_element& holder, const range_type& val);

        void constraint_size(constraint_element& holder, const constraint_element_vector& val);

        void constraint_alphabet(constraint_element& holder, const constraint_element_vector& val);

        void constraint_singletype(constraint_element& holder, const constraint_element_vector& val);

        void constraint_namedtype(constraint_element& holder, const constraint_element_vector& val);

        void constraint_marker(constraint_element& holder, const constraintmarker_type& val);

        void constraint_multitype(constraint_element& holder, const constraint_element_vector& val);

        void constraint_userdef(constraint_element& holder, const userdefconstraint_vector& val);

        void constraint_relation(constraint_element& holder, const objectset_element& valr, const string_vector& valp);

        void constraint_content_t(constraint_element& holder, const type_element& val);

        void constraint_content_v(constraint_element& holder, const value_element& val);

        void constraint_content_tv(constraint_element& holder, const type_element& valt, const value_element& valv);

        void constraint_exceptnumber(constraint_element& holder, const std::string& val);

        void constraint_exceptidentifier(constraint_element& holder, const std::string& val);

        void constraint_excepttypevalue(constraint_element& holder, const type_element& valt, const value_element& valv);


        void constraint_fromobject(constraint_element& holder, const object_element& val, const std::string& reff);

        void constraint_fromobjects(constraint_element& holder, const objectset_element& val, const std::string& reff);

        void push_constraint(constraint_element_vector& holder, const constraint_element& val);

        void push_constraints(constraint_element_vector& holder, const constraint_element_vector& val);

        void pushs_constraint(constraints_vector& holder, const constraint_element& val);






        const constraint_element CONSTRAINT_UNION = constraint_element(cns_UNION);
        const constraint_element CONSTRAINT_INTERSECTION = constraint_element(cns_INTERSECTION);
        const constraint_element CONSTRAINT_EXCEPT = constraint_element(cns_EXCEPT);
        const constraint_element CONSTRAINT_ALLEXCEPT = constraint_element(cns_ALLEXCEPT);
        const constraint_element CONSTRAINT_EXTENTION = constraint_element(cns_EXTENTION, cmk_extention);


        // Userconstraint setter

        void userdefconstraint_governor_tp(userdefconstraint_type& holder, const type_element& val, const setting_element& par);

        void userdefconstraint_governor_cl(userdefconstraint_type& holder, const class_element& val, const setting_element& par);

        void userdefconstraint_governor_reff(userdefconstraint_type& holder, const std::string& val, const setting_element& par);

        void userdefconstraint_argument(userdefconstraint_type& holder, const setting_element& val);



        //  value_assignment setter        

        void valuea_reference(value_assignment& holder, const std::string& val);

        void valuea_type(value_assignment& holder, const type_element& val);

        void valuea_arguments(value_assignment& holder, const argument_vector& val);

        void valuea_value(value_assignment& holder, const value_element& val);


        //  valueset_element setter   

        void valueset_parameters(valueset_element& holder, const parameter_vector& val);

        void valueset_set(valueset_element& holder, const constraint_element_vector& val);

        void valueset_defined(valueset_element& holder, const std::string& val);

        void valueset_fromobject(valueset_element& holder, const object_element& val, const std::string& reff);

        void valueset_fromobjects(valueset_element& holder, const objectset_element& val, const std::string& reff);



        //  valueset_assignment setter        

        void valueset_reference(valueset_assignment& holder, const std::string& val);

        void valueseta_type(valueset_assignment& holder, const type_element& val);

        void valueseta_arguments(valueset_assignment& holder, const argument_vector& val);

        void valueseta_set(valueset_assignment& holder, const valueset_element& val);






        //  type_assignment setter        

        void type_identifier(type_assignment& holder, const std::string& val);

        void type_named(type_assignment& holder, const std::string& ind, const type_element& type);

        void typea_type(type_assignment& holder, const type_element& val);

        void typea_arguments(type_assignment& holder, const argument_vector& val);

        void type_marker(type_assignment& holder, const tagmarker_type& val);

        void type_defaultvalue(type_assignment& holder, const value_element& val);

        void type_exceptnumber(type_assignment& holder, const std::string& val);

        void type_exceptidetifier(type_assignment& holder, const std::string& val);

        void type_exceptvalue(type_assignment& holder, const value_element& val);

        void type_push(type_element& holder, const type_assignment& val);

        void type_select(type_element& holder, const std::string& ind, const type_element& type);


        const type_assignment extention_type_assignment(mk_extention);
        const type_assignment exception_type_assignment(mk_exception);






        // classfield setter

        void classfield_field(classfield_type& holder, const std::string& val);

        void classfield_holder_undf(classfield_type& holder, const std::string& val, bool type);

        void classfield_holder_ft(classfield_type& holder, const type_element& val, bool type);

        void classfield_holder_cl(classfield_type& holder, const class_element& val, bool type);

        void classfield_holder(classfield_type& holder, const std::string& val);

        void classfield_unique(classfield_type& holder);

        void classfield_optional(classfield_type& holder);

        void classfield_tp(classfield_type& holder, const fieldkind_type& val);

        void classfield_defaulttype(classfield_type& holder, const type_element& val);

        void classfield_defaultvalue(classfield_type& holder, const value_element& val);

        void classfield_defaultset(classfield_type& holder, const valueset_element& val);

        void classfield_defaultovalue(classfield_type& holder, const object_element& val);

        void classfield_defaultoset(classfield_type& holder, const objectset_element& val);

        void classfield_defaultov(classfield_type& holder, const unknown_vo_element& val);

        void classfield_defaultos(classfield_type& holder, const unknown_so_element& val);







        // classsintax setter

        void classsyntax_alias(classsyntax_type& holder, const std::string& val);

        void classsyntax_field(classsyntax_type& holder, const std::string& val);

        void classsyntax_agroup(classsyntax_type& holder, const std::string& alias, const classsyntax_vector& group);

        void classsyntax_group(classsyntax_type& holder, const classsyntax_vector& group);

        void classsyntax_optional(classsyntax_type& holder);






        // class_element setter

        const class_element CLASS_TYPE_IDENTIFIER = class_element(cl_TYPE_IDENTIFIER);
        const class_element CLASS_ABSTRACT_SYNTAX = class_element(cl_ABSTRACT_SYNTAX);

        void class_type(class_element& holder, const definedclass_type& val);

        void class_reference(class_element& holder, const std::string& val);

        void class_parameters(class_element& holder, const parameter_vector& val);

        void class_fields(class_element& holder, const classfield_vector& val);

        void class_syntaxes(class_element& holder, const classsyntax_vector& val);






        // class_assigment setter

        void classa_reference(class_assignment& holder, const std::string& val);

        void classa_class(class_assignment& holder, const class_element& val);

        void classa_set(class_assignment& holder, const std::string& ind, const class_element& cl);

        void classa_arguments(class_assignment& holder, const argument_vector& val);





        // setting setter        

        void setting_settype(setting_element& holder, const type_element& val);

        void setting_value(setting_element& holder, const value_element& val);

        void setting_valueset(setting_element& holder, const valueset_element& val);

        void setting_class(setting_element& holder, const class_element& val);

        void setting_object(setting_element& holder, const object_element& val);

        void setting_objectset(setting_element& holder, const objectset_element& val);

        void setting_literal(setting_element& holder, const std::string& val);









        // objectfield setter

        void objectfield_field(objectfield_type& holder, const std::string& val);

        void objectfield_setting(objectfield_type& holder, const setting_element& val);





        // object_element setter

        const object_element OBJECT_UNION = object_element(ot_UNION);
        const object_element OBJECT_INTERSECTION = object_element(ot_INTERSECTION);
        const object_element OBJECT_EXCEPT = object_element(ot_EXCEPT);
        const object_element OBJECT_ALLEXCEPT = object_element(ot_ALLEXCEPT);
        const object_element OBJECT_EXTENTION = object_element(ot_EXTENTION);

        void object_parameters(object_element& holder, const parameter_vector& val);

        void object_fields(object_element& holder, const objectfield_vector& val);

        void object_typeset(object_element& holder, const object_type& val);

        void object_refference(object_element& holder, const std::string& val);

        void object_fromobject(object_element& holder, const object_element& val, const std::string& reff);

        void object_objectsetdef(object_element& holder, const objectset_element& val);

        void object_objectsetfromobjects(object_element& holder, const objectset_element& val, const std::string& reff);

        void object_objectsetfromobject(object_element& holder, const object_element& val, const std::string& reff);





        // object_assigment setter

        void objecta_reference(object_assignment& holder, const std::string& val);

        void objecta_object(object_assignment& holder, const object_element& val);

        void objecta_class(object_assignment& holder, const class_element& val);

        void objecta_arguments(object_assignment& holder, const argument_vector& val);







        //  objectset_element setter   

        void objectset_parameters(objectset_element& holder, const parameter_vector& val);

        void objectset_set(objectset_element& holder, const object_element_vector& val);

        void objectset_defined(objectset_element& holder, const std::string& val);

        void objectset_fromobject(objectset_element& holder, const object_element& val, const std::string& reff);

        void objectset_fromobjects(objectset_element& holder, const objectset_element& val, const std::string& reff);




        // objectset_assigment setter

        void objectseta_reference(objectset_assignment& holder, const std::string& val);

        void objectseta_objectset(objectset_assignment& holder, const objectset_element& val);

        void objectseta_class(objectset_assignment& holder, const class_element& val);

        void objectseta_arguments(objectset_assignment& holder, const argument_vector& val);

        void push_objects(object_element_vector& holder, const object_element_vector& val);






        // tepevalue setter

        void typevalue_set(typevalue_element& holder, const type_element& tp, const value_element& val);

        void typevalues_set(typevalue_element& holder, const type_element& tp, const value_element& val);




        // Argument setter

        void argument_governor_tp(argument_type& holder, const type_element& val, const std::string& par, bool big);

        void argument_governor_cl(argument_type& holder, const class_element& val, const std::string& par, bool big);

        void argument_governor_reff(argument_type& holder, const std::string& val, const std::string& par, bool big);

        void argument_argument(argument_type& holder, const std::string& val, bool big);


        // Module setter       

        void module_name(module& holder, const std::string& val);

        void module_oid(module& holder, const value_element& val);

        void module_iri(module& holder, const std::string& val);

        void module_tags(module& holder, const tagrule_type & val);

        void module_encoding(module& holder, const encoding_references_type & val);

        void module_extesibility(module & holder);

        void module_allexport(module & holder);

        void module_exports(module& holder, const string_vector& val);

        void module_imports(module& holder, const imports& val);

        void module_assignments(module& holder, const assignment_vector& val);





        // Import setter            

        void import_name(import& holder, const std::string & val);

        void import_oid(import& holder, const value_element & val);

        void import_defined(import& holder, const value_element & val);

        void import_add(import& holder, const string_vector & val);


    }
}




#endif	

