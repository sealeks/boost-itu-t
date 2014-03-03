//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_T_SEM_MODULE_IMPLEMENTATIUON_H_
#define	_ITU_T_SEM_MODULE_IMPLEMENTATIUON_H_

#include <boost/itu/x68X/modules.hpp>
#include <boost/itu/x68X/sem_typeassignment.hpp>
#include <boost/itu/x68X/sem_valueassignment.hpp>
#include <boost/itu/x68X/sem_valuesetassignment.hpp>
#include <boost/itu/x68X/sem_classassignment.hpp>
#include <boost/itu/x68X/sem_objectassignment.hpp>
#include <boost/itu/x68X/sem_objectsetassignment.hpp>

namespace x680 {
    namespace semantics {

        class error {

        public:

            error(const std::string& ms) : msg_(ms) {
            }
            
            std::string message() const {
                return msg_;
            }

        private:
            std::string msg_;
        };

        std::ostream& operator<<(std::ostream& stream, const error& self);





        /////////////////////////////////////////////////////////////////////////   
        // COMPILE
        /////////////////////////////////////////////////////////////////////////   
        // precomile modules
        /////////////////////////////////////////////////////////////////////////          

        global_entity_ptr compile_fs(const std::string& path, const std::string& ext = "asn");

        void compile_module(const x680::syntactic::module& mod, global_entity_ptr global);
        void compile_export(const x680::syntactic::module& mod, module_entity_ptr mdl);
        void compile_imports(const x680::syntactic::module& mod, module_entity_ptr mdl);
        basic_entity_ptr compile_import(const x680::syntactic::import& imp, module_entity_ptr mdl);
        void compile_assignments(const x680::syntactic::module& mod, module_entity_ptr mdl);
        basic_entity_ptr compile_assignment(basic_entity_ptr scope, const x680::syntactic::assignment& ent);
        setting_atom_vct compile_parameters(basic_entity_ptr scope, const x680::syntactic::parameter_vector& ent);
        argument_entity_vct compile_arguments(basic_entity_ptr scope, const x680::syntactic::argument_vector& ent);
        argument_entity_ptr compile_argument(basic_entity_ptr scope, const x680::syntactic::argument_type& ent);
        // type
        typeassignment_entity_ptr compile_typeassignment(basic_entity_ptr scope, const x680::syntactic::type_assignment& ent);
        basic_entity_vector compile_structtype(basic_entity_ptr scope, const x680::syntactic::type_element& ent);
        typeassignment_entity_ptr compile_namedtype(basic_entity_ptr scope, const x680::syntactic::type_assignment& ent);
        type_atom_ptr compile_type(basic_entity_ptr scope, const x680::syntactic::type_element& ent);
        predefined_ptr compile_typepredef(basic_entity_ptr scope, const x680::syntactic::type_element& ent);
        tagged_ptr compile_tag(basic_entity_ptr scope, const x680::syntactic::tag_type& ent);
        // value
        valueassignment_entity_ptr compile_valueassignment(basic_entity_ptr scope, const x680::syntactic::value_assignment& ent);
        value_atom_ptr compile_value(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_atom_ptr compile_value_impl(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_vct compile_structvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_vct compile_objidvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_vct compile_listvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_atom_ptr compile_assignvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_atom_ptr compile_realvalue(basic_entity_ptr scope, const std::string& val);
        value_atom_ptr compile_choicevalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_atom_ptr compile_openvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        value_atom_ptr compile_namedvalue(basic_entity_ptr scope, const x680::syntactic::value_element& ent);
        // valueset
        valuesetassignment_entity_ptr compile_valuesetassignment(basic_entity_ptr scope, const x680::syntactic::valueset_assignment& ent);
        valueset_atom_ptr compile_valueset(basic_entity_ptr scope, const x680::syntactic::valueset_element& ent);
        valueset_atom_ptr compile_valueset_impl(basic_entity_ptr scope, const x680::syntactic::valueset_element& ent);
        constraints_atom_vct compile_constraints_vct(basic_entity_ptr scope, const x680::syntactic::constraints_vector& ent);
        constraints_atom_ptr compile_constraints(basic_entity_ptr scope, const x680::syntactic::constraint_element_vector& ent);
        constraint_atom_ptr compile_constraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent);
        constraint_atom_ptr compile_namedconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent);
        constraint_atom_ptr compile_multipletypeconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent);
        constraint_atom_ptr compile_exceptionconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent);
        constraint_atom_ptr compile_contentconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent);
        constraint_atom_ptr compile_tvosoconstraint(basic_entity_ptr scope, const x680::syntactic::constraint_element& ent);
        uargument_entity_vct compile_uarguments(basic_entity_ptr scope, const x680::syntactic::uargument_vector& ent);
        uargument_entity_ptr compile_uargument(basic_entity_ptr scope, const x680::syntactic::uargument_type& ent);        
        // class
        classassignment_entity_ptr compile_classassignment(basic_entity_ptr scope, const x680::syntactic::class_assignment& ent);
        basic_entity_vector compile_classfields(basic_entity_ptr scope, const x680::syntactic::class_element& ent);
        class_atom_ptr compile_classdefined(basic_entity_ptr scope, const x680::syntactic::class_element& ent);
        basic_entity_ptr compile_typeclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_valueclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_valuesetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_reffvalueclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_reffvaluesetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_objectclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_objectsetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_undefclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        basic_entity_ptr compile_unsefsetclassfield(basic_entity_ptr scope, const x680::syntactic::classfield_type& ent);
        withsyntax_atom compile_withsyntax(basic_entity_ptr scope, const x680::syntactic::classsyntax_vector& ent);
        syntax_atom_vct compile_groupwithsyntax(basic_entity_ptr scope, const x680::syntactic::classsyntax_vector& ent);
        // object         
        objectassignment_entity_ptr compile_objectassignment(basic_entity_ptr scope, const x680::syntactic::object_assignment& ent);
        object_atom_ptr compile_object(basic_entity_ptr scope, const x680::syntactic::object_element& ent);
        object_atom_ptr compile_object_impl(basic_entity_ptr scope, const x680::syntactic::object_element& ent);
        fieldsetting_atom_vct compile_object_fields(basic_entity_ptr scope, const x680::syntactic::objectfield_vector& ent);
        fieldsetting_atom_ptr compile_object_field(basic_entity_ptr scope, const x680::syntactic::objectfield_type& ent);
        setting_atom_ptr compile_setting(basic_entity_ptr scope, const x680::syntactic::setting_element& ent);
        // objectset         
        objectsetassignment_entity_ptr compile_objectsetassignment(basic_entity_ptr scope, const x680::syntactic::objectset_assignment& ent);
        objectset_atom_ptr compile_objectset(basic_entity_ptr scope, const x680::syntactic::objectset_element& ent);
        objectset_atom_ptr compile_objectset_impl(basic_entity_ptr scope, const x680::syntactic::objectset_element& ent);
        object_atom_vct compile_objectset_vct(basic_entity_ptr scope, const x680::syntactic::objectset_element& ent);
        // big
        bigassignment_entity_ptr compile_bigassignment(basic_entity_ptr scope, const x680::syntactic::unknown_tc_assignment& ent);
        // value or object
        voassignment_entity_ptr compile_voassignment(basic_entity_ptr scope, const x680::syntactic::unknown_vo_assignment& ent);
        // valueset or objectset
        soassignment_entity_ptr compile_soassignment(basic_entity_ptr scope, const x680::syntactic::unknown_so_assignment& ent);
        // reff
        basic_atom_ptr compile_reff(basic_entity_ptr scope, const std::string& rf);



    }

}

#endif	

