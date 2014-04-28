//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_T_SEM_DEBUGCOUT_IMPLEMENTATIUON_H_
#define	_ITU_T_SEM_DEBUGCOUT_IMPLEMENTATIUON_H_


#include <boost/itu/x68X/semantics.hpp>
#include <fstream>

namespace x680 {

    /////////////////////////////////////////////////////////////////////////   
    // COUT
    /////////////////////////////////////////////////////////////////////////   
    // std::cout  tree
    /////////////////////////////////////////////////////////////////////////          


    std::ostream& operator<<(std::ostream& stream, global_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, module_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, import_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, expectdef_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, extention_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, basic_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, const argument_entity_vct& self);
    std::ostream& operator<<(std::ostream& stream, argument_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, argument_enum self);   

    // type
    std::ostream& operator<<(std::ostream& stream, typeassignment_entity_ptr self);
    std::ostream& operatorstruct(std::ostream& stream, typeassignment_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, tagmarker_type self);
    std::ostream& operator<<(std::ostream& stream, predefined_ptr self);
    std::ostream& operator<<(std::ostream& stream, tagclass_type self);
    std::ostream& operator<<(std::ostream& stream, tagrule_type self);
    std::ostream& operator<<(std::ostream& stream, tagged& self);
    std::ostream& operator<<(std::ostream& stream, type_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, canonical_tag_ptr self);    
    //value
    std::ostream& operator<<(std::ostream& stream, valueassignment_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, defined_type self);
    std::ostream& operator<<(std::ostream& stream, value_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, numvalue_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, realvalue_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, boolvalue_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, strvalue_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, namedvalue_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, structvalue_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, defined_value_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, fromobject_value_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, assignvalue_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, choicevalue_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, openvalue_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, nullvalue_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, emptyvalue_atom_ptr self);
    // valueset
    std::ostream& operator<<(std::ostream& stream, valuesetassignment_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, valueset_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, const constraints_atom_vct& self);
    std::ostream& operator<<(std::ostream& stream, constraints_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, const constraint_atom_vct& self);
    std::ostream& operator<<(std::ostream& stream, constraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, valueconstraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, fromdefined_objects_constraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, valuesetconstraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, fromdefined_constraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, typeconstraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, rangeconstraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, namedconstraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, constraintmarker_type tp);
    std::ostream& operator<<(std::ostream& stream, range_type tp);
    std::ostream& operator<<(std::ostream& stream, complexconstraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, multipletypeconstraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, exceptionconstraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, userconstraint_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, const uargument_entity_vct& self);
    std::ostream& operator<<(std::ostream& stream, uargument_entity_ptr self);      
    std::ostream& operator<<(std::ostream& stream, contentconstraint_atom_ptr self);    
    std::ostream& operator<<(std::ostream& stream,relationconstraint_atom_ptr self);  
    std::ostream& operator<<(std::ostream& stream,tableconstraint_atom_ptr self);    
    std::ostream& operator<<(std::ostream& stream, tvosoconstraint_atom_ptr self);    
    // class
    std::ostream& operator<<(std::ostream& stream, classassignment_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, class_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, definedclass_type self);
    std::ostream& operator<<(std::ostream& stream, fieldkind_type self);
    std::ostream& operator<<(std::ostream& stream, field_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, typefield_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, valuefield_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, valuesetfield_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, reffvaluefield_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, reffvaluesetfield_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, objectfield_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, objectsetfield_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, undeffield_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, undefsetfield_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, syntax_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, groupsyntax_atom_ptr self);
    // object
    std::ostream& operator<<(std::ostream& stream, objectassignment_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, object_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, defined_object_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, definedobjects_object_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, fromdefined_objects_object_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, fromdefined_object_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, defltobject_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, fromobject_object_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, defsyntax_object_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, const fieldsetting_atom_vct& self);
    std::ostream& operator<<(std::ostream& stream, fieldsetting_atom_ptr self);
    std::ostream& operator<<(std::ostream& stream, const setting_atom_vct& self);
    std::ostream& operator<<(std::ostream& stream, setting_atom_ptr self);
    std::ostream& fieldsettingstrm(std::ostream& stream, fieldsetting_atom_ptr self);
    // objectset    
    std::ostream& operator<<(std::ostream& stream, objectsetassignment_entity_ptr self);
    std::ostream& operator<<(std::ostream& stream, objectset_atom_ptr self);
    // big
    std::ostream& operator<<(std::ostream& stream, bigassignment_entity_ptr self);
    // value or object
    std::ostream& operator<<(std::ostream& stream, voassignment_entity_ptr self);
    // valueset or objectset
    std::ostream& operator<<(std::ostream& stream, soassignment_entity_ptr self);
    //little
    std::ostream& operator<<(std::ostream& stream, voassignment_entity_ptr self);


}



#endif	

