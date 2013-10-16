//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1_SEM_DEBUGCOUT_IMPLEMENTATIUON_H_
#define	_ITU_ASN1_SEM_DEBUGCOUT_IMPLEMENTATIUON_H_


#include <boost/itu/x68X/semantics.hpp>

namespace x680 {

    /////////////////////////////////////////////////////////////////////////   
    // COUT
    /////////////////////////////////////////////////////////////////////////   
    // std::cout  tree
    /////////////////////////////////////////////////////////////////////////          


    std::ostream& operator<<(std::ostream& stream, global_entity* self);
    std::ostream& operator<<(std::ostream& stream, module_entity* self);
    std::ostream& operator<<(std::ostream& stream, import_entity* self);
    std::ostream& operator<<(std::ostream& stream, expectdef_entity* self);
    std::ostream& operator<<(std::ostream& stream, extention_entity* self);
    std::ostream& operator<<(std::ostream& stream, basic_atom* self);
    std::ostream& operator<<(std::ostream& stream, const argument_entity_vct& self);
    std::ostream& operator<<(std::ostream& stream, argument_entity* self);
    std::ostream& operator<<(std::ostream& stream, argument_enum self);   

    // type
    std::ostream& operator<<(std::ostream& stream, typeassignment_entity* self);
    std::ostream& operatorstruct(std::ostream& stream, typeassignment_entity* self);
    std::ostream& operator<<(std::ostream& stream, tagmarker_type self);
    std::ostream& operator<<(std::ostream& stream, predefined* self);
    std::ostream& operator<<(std::ostream& stream, tagclass_type self);
    std::ostream& operator<<(std::ostream& stream, tagrule_type self);
    std::ostream& operator<<(std::ostream& stream, tagged& self);
    std::ostream& operator<<(std::ostream& stream, type_atom* self);
    //value
    std::ostream& operator<<(std::ostream& stream, valueassignment_entity* self);
    std::ostream& operator<<(std::ostream& stream, defined_type self);
    std::ostream& operator<<(std::ostream& stream, value_atom* self);
    std::ostream& operator<<(std::ostream& stream, numvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, realvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, boolvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, strvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, namedvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, structvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, definedvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, fromobjectvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, assignvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, choicevalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, openvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, nullvalue_atom* self);
    std::ostream& operator<<(std::ostream& stream, emptyvalue_atom* self);
    // valueset
    std::ostream& operator<<(std::ostream& stream, valuesetassignment_entity* self);
    std::ostream& operator<<(std::ostream& stream, valueset_atom* self);
    std::ostream& operator<<(std::ostream& stream, const constraints_atom_vct& self);
    std::ostream& operator<<(std::ostream& stream, constraints_atom* self);
    std::ostream& operator<<(std::ostream& stream, const constraint_atom_vct& self);
    std::ostream& operator<<(std::ostream& stream, constraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, valueconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, fromdefinedsetconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, fromdefinedconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, typeconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, rangeconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, namedconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, constraintmarker_type tp);
    std::ostream& operator<<(std::ostream& stream, range_type tp);
    std::ostream& operator<<(std::ostream& stream, complexconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, multipletypeconstraint_atom * self);
    std::ostream& operator<<(std::ostream& stream, exceptionconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, userconstraint_atom* self);
    std::ostream& operator<<(std::ostream& stream, const uargument_entity_vct& self);
    std::ostream& operator<<(std::ostream& stream, uargument_entity* self);      
    std::ostream& operator<<(std::ostream& stream, contentconstraint_atom* self);    
    std::ostream& operator<<(std::ostream& stream,relationconstraint_atom* self);  
    std::ostream& operator<<(std::ostream& stream,tableconstraint_atom* self);    
    std::ostream& operator<<(std::ostream& stream, tvosoconstraint_atom* self);    
    // class
    std::ostream& operator<<(std::ostream& stream, classassignment_entity* self);
    std::ostream& operator<<(std::ostream& stream, class_atom* self);
    std::ostream& operator<<(std::ostream& stream, definedclass_type self);
    std::ostream& operator<<(std::ostream& stream, fieldkind_type self);
    std::ostream& operator<<(std::ostream& stream, field_entity* self);
    std::ostream& operator<<(std::ostream& stream, typefield_entity* self);
    std::ostream& operator<<(std::ostream& stream, valuefield_entity* self);
    std::ostream& operator<<(std::ostream& stream, valuesetfield_entity* self);
    std::ostream& operator<<(std::ostream& stream, reffvaluefield_entity* self);
    std::ostream& operator<<(std::ostream& stream, reffvaluesetfield_entity* self);
    std::ostream& operator<<(std::ostream& stream, objectfield_entity* self);
    std::ostream& operator<<(std::ostream& stream, objectsetfield_entity* self);
    std::ostream& operator<<(std::ostream& stream, undeffield_entity* self);
    std::ostream& operator<<(std::ostream& stream, undefsetfield_entity* self);
    std::ostream& operator<<(std::ostream& stream, syntax_atom* self);
    std::ostream& operator<<(std::ostream& stream, groupsyntax_atom* self);
    // object
    std::ostream& operator<<(std::ostream& stream, objectassignment_entity* self);
    std::ostream& operator<<(std::ostream& stream, object_atom* self);
    std::ostream& operator<<(std::ostream& stream, definedobject_atom* self);
    std::ostream& operator<<(std::ostream& stream, definedsetobject_atom* self);
    std::ostream& operator<<(std::ostream& stream, fromdefinedsetobject_atom* self);
    std::ostream& operator<<(std::ostream& stream, fromdefinedobject_atom* self);
    std::ostream& operator<<(std::ostream& stream, defltobject_atom* self);
    std::ostream& operator<<(std::ostream& stream, fromobjectobject_atom* self);
    std::ostream& operator<<(std::ostream& stream, defsyntxobject_atom* self);
    std::ostream& operator<<(std::ostream& stream, const fieldsetting_atom_vct& self);
    std::ostream& operator<<(std::ostream& stream, fieldsetting_atom* self);
    std::ostream& operator<<(std::ostream& stream, const setting_atom_vct& self);
    std::ostream& operator<<(std::ostream& stream, setting_atom* self);
    std::ostream& fieldsettingstrm(std::ostream& stream, fieldsetting_atom* self);
    // objectset    
    std::ostream& operator<<(std::ostream& stream, objectsetassignment_entity* self);
    std::ostream& operator<<(std::ostream& stream, objectset_atom* self);
    // big
    std::ostream& operator<<(std::ostream& stream, bigassignment_entity* self);
    // value or object
    std::ostream& operator<<(std::ostream& stream, voassignment_entity* self);
    // valueset or objectset
    std::ostream& operator<<(std::ostream& stream, soassignment_entity* self);
    //little
    std::ostream& operator<<(std::ostream& stream, voassignment_entity* self);


}

#endif	

