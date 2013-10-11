//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/dedug_cout.hpp>

namespace x680 {

    /////////////////////////////////////////////////////////////////////////   
    // COUT
    /////////////////////////////////////////////////////////////////////////   
    // std::cout  tree
    /////////////////////////////////////////////////////////////////////////       

    std::ostream& indent(std::ostream& stream, typeassignment_entity* self) {
        if (self) {
            int inten = self->level();
            if (inten > 0) inten--;
            while (inten) {
                stream << "    ";
                inten--;
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, global_entity* self) {
        stream << "GLOBAL SCOPE:" << "\n";
        for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
            if ((*it)->as_module())
                stream << (*it)->as_module();
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, import_entity* self) {
        if (self->scope())
            stream << "      from module: " << self->name();
        else
            stream << "      from module: " << self->name() << "(?)";
        if (self->objectid())
            stream << " {" << self->objectid().get() << " }";
        stream << "\n      symbol: ";
        for (import_vector::iterator it = self->import().begin(); it != self->import().end(); ++it) {
            stream << *it << ", ";
        }
        stream << "\n";
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, module_entity* self) {
        stream << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        stream << "module: " << self->name();
        if (self->objectid())
            stream << " {" << self->objectid().get() << " }";
        stream << " \nfile:" << self->file() << "\n";

        stream << "----------------------------------------------------------\n";
        if (self->allexport())
            stream << "      export ALL\n ";

        stream << "      export: ";
        for (export_vector::iterator it = self->exports().begin(); it != self->exports().end(); ++it) {
            stream << *it << ", ";
        }

        stream << "\n----------------------------------------------------------\n";
        stream << "      IMPORTS: ";
        for (basic_entity_vector::iterator it = self->imports().begin(); it != self->imports().end(); ++it) {
            stream << "\n.............................................................................................\n";
            stream << "      import: \n";
            if ((*it)->as_import())
                stream << (*it)->as_import();
        }
        stream << "     \n";
        for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
            stream << "     \n";
            if ((*it)->as_bigassigment()) {
                stream << (*it)->as_bigassigment();
                continue;
            }
            if ((*it)->as_voassigment()) {
                stream << (*it)->as_voassigment();
                continue;
            }
            if ((*it)->as_soassigment()) {
                stream << (*it)->as_soassigment();
                continue;
            }
            if ((*it)->as_typeassigment()) {
                stream << (*it)->as_typeassigment();
                continue;
            }
            if ((*it)->as_valueassigment()) {
                stream << (*it)->as_valueassigment();
                continue;
            }
            if ((*it)->as_valuesetassigment()) {
                stream << (*it)->as_valuesetassigment();
                continue;
            }
            if ((*it)->as_classassigment()) {
                stream << (*it)->as_classassigment();
                continue;
            }
            if ((*it)->as_objectassigment()) {
                stream << (*it)->as_objectassigment();
                continue;
            }
            if ((*it)->as_objectsetassigment()) {
                stream << (*it)->as_objectsetassigment();
                continue;
            }


        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, expectdef_entity* self) {
        return stream << self->name() << "(?)";
    }

    std::ostream& operator<<(std::ostream& stream, extention_entity* self) {
        return stream << " ...";
    }

    std::ostream& operator<<(std::ostream& stream, basic_atom* self) {
        if (!self)
            return stream << "@unspec";
        if (self->as_type())
            return stream << self->as_type()->builtin();
        if (self->as_value())
            return stream << self->as_value();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, const argument_entity_vct& self) {
        if (self.empty())
            return stream;
        stream << " {";
        for (argument_entity_vct::const_iterator it = self.begin(); it != self.end(); ++it) {
            if (it != self.begin())
                stream << " ,";
            stream << (*it).get();
        }
        return stream << " }";
    }

    std::ostream& operator<<(std::ostream& stream, argument_entity* self) {
        if (self->governor()) {
            if (self->governor()->as_type())
                stream << "(T)" << self->governor()->as_type() << ":";
            else if (self->governor()->as_class())
                stream << "(C)" << self->governor()->as_class() << ":";
            else
                stream << "(T?C)" << self->governor()->reff()->name() << ":";
        }
        return stream << "[*" << self->reffcount() <<  "]" <<  self->argumenttype() << self->name();
    }
    
    std::ostream& operator<<(std::ostream& stream, argument_enum self) {
        switch (self) {    
           case argm_Type: return stream  << "(T)";
           case argm_Value: return stream  << "(v)";
           case argm_ValueSet: return stream  << "(vS)";
           case argm_Class:  return stream  << "(C)";
           case argm_Object:  return stream  << "(o)";
           case argm_ObjectSet: return stream  << "(oS)";  
            default:{}
        }
        return stream  << "(?u)";
    }    



    //  type

    std::ostream& operator<<(std::ostream& stream, typeassignment_entity* self) {
        if (self->as_named()) {
            indent(stream, self);
            if (self->as_named()->marker() == mk_components_of)
                stream << self->name() << " COMPONENTS OF ";
            else if (self->as_named()->marker() == mk_exception)
                stream << "! " << " ";
            else if (self->as_named()->marker() == mk_extention)
                return stream << "(...) " << "\n";
            else
                stream << self->name() << "  ";
            stream << self->type() << " ";
            operatorstruct(stream, self);
            if (self->type()->has_constraint())
                stream << self->type()->constraints();
            stream << self->as_named()->marker();
            if ((self->as_named()->_default())
                    && ((self->as_named()->marker() == mk_default)
                    || (self->as_named()->marker() == mk_exception))) {
                if (self->as_named()->marker() == mk_exception)
                    stream << " : ";
                stream << " " << self->as_named()->_default().get();
            }
        } else {
            stream << "(T) " << self->name();
            if (self->has_arguments())
                stream << self->arguments();
            stream << " :: = " << self->type().get();
            operatorstruct(stream, self);
            if (self->type()->has_constraint())
                stream << self->type()->constraints();
        }
        return stream << "\n";
        ;
    }

    std::ostream& operatorstruct(std::ostream& stream, typeassignment_entity* self) {
        switch (self->type()->builtin()) {
            case t_SEQUENCE:
            case t_SEQUENCE_OF:
            case t_SET:
            case t_SET_OF:
            case t_CHOICE:;
            {
                if (self->type()->has_extention())
                    stream << " {" << "(has ...)\n";
                else
                    stream << " {" << "\n";
                for (basic_entity_vector::const_iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                    if ((*it)->as_extention()) {
                        indent(stream, self);
                        stream << "   (...)\n";
                    } else if ((*it)->as_typeassigment())
                        stream << (*it)->as_typeassigment();
                }
                indent(stream, self);
                stream << "}" << " ";
                break;
            }
            default:
            {
                stream << " ";
            };
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, tagmarker_type self) {
        switch (self) {
                //case mk_none:
            case mk_default: stream << " DEFAULT ";
                break;
            case mk_optional: stream << " OPTIONAL ";
                break;
                //case mk_components_of:        
            default:
            {
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, predefined* self) {
        if (self->extended())
            stream << "{$(...) ";
        else
            stream << "{$ ";
        for (basic_entity_vector::const_iterator it = self->values().begin(); it != self->values().end(); ++it) {
            if (it != self->values().begin())
                stream << " ,";
            stream << (*it)->name();
            if ((*it)->as_extention())
                stream << "...";
            if (((*it)->as_valueassigment()) && ((*it)->as_valueassigment()->value())) {
                stream << "( " << (*it)->as_valueassigment()->value().get() << ")";
            };
        }
        return stream << " $}";
    }

    std::ostream& operator<<(std::ostream& stream, tagclass_type self) {
        switch (self) {
            case tcl_universal: return stream << "UNIVERSAL ";
            case tcl_application: return stream << "APPLICATION ";
            case tcl_private: return stream << "PRIVATE ";
            case tcl_context: return stream << "";
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, tagrule_type self) {
        switch (self) {
            case explicit_tags: return stream << "EXPLICIT ";
            case implicit_tags: return stream << "IMPLICIT ";
            case automatic_tags: return stream << "AUTOMATIC ";
            default: return stream;
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, tagged& self) {
        if (self.number()) {
            if (self.rule() == noset_tags)
                return stream << " [" << self._class() << " " << self.number().get() << "] ";
            else
                return stream << " [ " << self.rule() << self._class() << " " << self.number().get() << "] ";
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, type_atom* self) {
        if (self->tag()) {
            stream << *(self->tag());
        }
        switch (self->builtin()) {
            case t_Reference:
            {
                if (self->reff()->as_expectdef())
                    stream << "??? " << self->reff()->name();
                else {
                    stream << " " << self->externalpreff() << self->reff()->name();
                    if (self->rooted())
                        stream << "(@" << self->root() << ")";
                }
                break;
            }
            case t_ClassField:
            {
                stream << "(C)" << self->as_classfield()->_class().get() << "."
                        << self->as_classfield()->field()->reff()->name();
                break;
            }
            case t_Instance_Of:
            {
                stream << "INSTANCE OF " << self->as_instance()->_class().get();
                break;
            }
            case t_TypeFromObject:
            {
                stream << "(o)" << self->as_fromobject()->object().get() << "."
                        << self->as_fromobject()->field()->reff()->name();
                break;
            }
            case t_ValueSetFromObjects:
            {
                stream << "(oS)" << self->as_fromobjectset()->objectset().get() << "."
                        << self->as_fromobjectset()->field()->reff()->name();
                break;
            }
            default:
            {
                stream << self->builtin();
            }
        }
        if (self->parameterized())
            stream << self->parameters();
        if (self->predefined())
            stream << self->predefined().get();
        return stream;
    }
        
    
    std::ostream& operator<<(std::ostream& stream, defined_type self) {
        switch (self) {
            case t_NODEF: return stream << "NODEF";
            case t_BOOLEAN: return stream << "BOOLEAN";
            case t_INTEGER: return stream << "INTEGER";
            case t_BIT_STRING: return stream << "BIT_STRING";
            case t_OCTET_STRING: return stream << "OCTET_STRING";
            case t_NULL: return stream << "NULL";
            case t_OBJECT_IDENTIFIER: return stream << "OBJECT_IDENTIFIER";
            case t_ObjectDescriptor: return stream << "ObjectDescriptor";
            case t_EXTERNAL: return stream << "EXTERNAL";
            case t_REAL: return stream << "REAL";
            case t_ENUMERATED: return stream << "ENUMERATED";
            case t_EMBEDDED_PDV: return stream << "EMBEDDED_PDV";
            case t_UTF8String: return stream << "UTF8String";
            case t_RELATIVE_OID: return stream << "RELATIVE_OID";
            case t_SEQUENCE: return stream << "SEQUENCE";
            case t_SEQUENCE_OF: return stream << "SEQUENCE_OF";
            case t_SET: return stream << "SET";
            case t_SET_OF: return stream << "SET_OF";
            case t_NumericString: return stream << "NumericString";
            case t_PrintableString: return stream << "PrintableString";
            case t_T61String: return stream << "T61String";
            case t_VideotexString: return stream << "VideotexString";
            case t_IA5String: return stream << "IA5String";
            case t_UTCTime: return stream << "UTCTime";
            case t_GeneralizedTime: return stream << "GeneralizedTime";
            case t_GraphicString: return stream << "GraphicString";
            case t_VisibleString: return stream << "VisibleString";
            case t_GeneralString: return stream << "GeneralString";
            case t_UniversalString: return stream << "UniversalString";
            case t_CHARACTER_STRING: return stream << "CHARACTER_STRING";
            case t_BMPString: return stream << "BMPString";
            case t_TIME: return stream << "TIME";
            case t_TIME_OF_DAY: return stream << "TIME_OF_DAY";
            case t_DATE: return stream << "DATE";
            case t_DATE_TIME: return stream << "DATE_TIME";
            case t_DURATION: return stream << "DURATION";
            case t_CHOICE: return stream << "CHOICE";
            case t_Selection: return stream << "Selection";
            case t_Instance_Of: return stream << "Instance_Of";
            case t_RELATIVE_OID_IRI: return stream << "RELATIVE_OID_IRI";
            case t_OID_IRI: return stream << "OID_IRI";
            case t_ANY: return stream << "ANY";
            case t_ClassField: return stream << "ClassField";
            case t_TypeFromObject: return stream << "TypeFromObject";
            case t_ValueSetFromObjects: return stream << "ValueSetFromObjects";
            case t_Reference: return stream << "";
            default:
            {
            };
        }
        return stream;
    }



    // value

    std::ostream& operator<<(std::ostream& stream, valueassignment_entity* self) {
        stream << "(v) " << self->name() << " [" << self->type().get() << "]";
        if (self->has_arguments())
            stream << self->arguments();
        stream << " :: = ";
        if (self->value())
            return stream << self->value().get() << "\n";
        return stream << "???" << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, value_atom* self) {
        switch (self->valtype()) {
            case v_boolean: return (stream << self->as_bool());
            case v_number: return (stream << self->as_number());
            case v_real: return (stream << self->as_real());
            case v_null: return (stream << self->as_null());
            case v_empty: return (stream << self->as_empty());
            case v_named_value: return (stream << self->as_named());
            case v_hstring:
            case v_bstring:
            case v_cstring: return (stream << self->as_cstr());
            case v_struct: return (stream << self->as_struct());
            case v_objectid: return (stream << self->as_objid());
            case v_defined_list:
            case v_number_list:
            case v_value_list: return (stream << self->as_list());
            case v_defined: return (stream << self->as_defined());
            case v_ValueFromObject: return (stream << self->as_fromobject());
            case v_defined_assign: return (stream << self->as_assign());
            case v_choice: return (stream << self->as_choice());
            case v_open: return (stream << self->as_open());
            default:
            {
            }
        }
        return stream << "?: " << (int) self->valtype();
    }

    std::ostream& operator<<(std::ostream& stream, numvalue_atom* self) {
        return stream << "(" << self->value() << ")";
    }

    std::ostream& operator<<(std::ostream& stream, realvalue_atom* self) {
        return stream << "(" << self->value() << ")";
    }

    std::ostream& operator<<(std::ostream& stream, boolvalue_atom* self) {
        if (self->value())
            return stream << "(TRUE)";
        else
            return stream << "(FALSE)";
    }

    std::ostream& operator<<(std::ostream& stream, strvalue_atom* self) {
        stream << "('";
        switch (self->valtype()) {
            case v_hstring: stream << "&H ";
                break;
            case v_bstring: stream << "&B ";
                break;
            default:
            {
            }
        }
        return stream << self->value() << "')";
    }

    std::ostream& operator<<(std::ostream& stream, namedvalue_atom* self) {
        return stream << self->name() << " : " << self->value();
    }

    std::ostream& operator<<(std::ostream& stream, structvalue_atom* self) {
        stream << " { ";
        for (value_vct::const_iterator it = self->values().begin(); it != self->values().end(); ++it) {
            if (it != self->values().begin())
                if (self->as_objid())
                    stream << "  ";
                else
                    stream << ",  ";
            stream << (*it).get();
        }
        return stream << "}";
    }

    std::ostream& operator<<(std::ostream& stream, definedvalue_atom* self) {
        if (self->reff()) {
            if (self->reff()->as_expectdef())
                return stream << "??? " << self->reff()->name();
            else {
                stream << " " << self->reff()->name();
                if (self->rooted())
                    stream << "(@" << self->root() << ")";
                return stream;
            }
        }
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, fromobjectvalue_atom* self) {
        stream << "(o)" << self->object().get() << "." << self->field()->reff()->name();
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, assignvalue_atom* self) {
        return stream << "(" << self->name() << "(" << self->value().get() << ") )";
    }

    std::ostream& operator<<(std::ostream& stream, choicevalue_atom* self) {
        return stream << "(" << self->name() << " : " << self->value().get() << ")";
    }

    std::ostream& operator<<(std::ostream& stream, openvalue_atom* self) {
        return stream << "(" << self->type().get() << " : " << self->value().get() << ")";
        ;
    }

    std::ostream& operator<<(std::ostream& stream, nullvalue_atom* self) {
        return stream << "(NULL)";
    }

    std::ostream& operator<<(std::ostream& stream, emptyvalue_atom* self) {
        return stream << "({})";
    }




    //valueset

    std::ostream& operator<<(std::ostream& stream, valuesetassignment_entity* self) {
        stream << "(vS) " << self->name() << " [" << self->type().get() << "]";
        if (self->has_arguments())
            stream << self->arguments();
        return stream << ":: = " << self->valueset().get() << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, valueset_atom* self) {
        switch (self->builtin()) {
            case vs_Strait:
            {
                if (self->set())
                    return stream << self->set().get();
                return stream << "(vS)???";
            }
            case vs_ValueSetFromObject:
            {
                stream << "(o)" << self->as_fromobject()->object().get() << "."
                        << self->as_fromobject()->field()->reff()->name();
                break;
            }
            case vs_ValueSetFromObjects:
            {
                stream << "(oS)" << self->as_fromobjectset()->objectset().get() << "."
                        << self->as_fromobject()->field()->reff()->name();
                break;
            }
            case vs_defined:
            {
                if (self->reff()) {
                    if (self->reff()->as_expectdef())
                        return stream << "??? *" << self->reff()->name();
                    else {
                        stream << " " << self->reff()->name();
                    }
                } else
                    stream << "(vs)???";
            }
            default:
            {
            }
        }
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, const constraints_atom_vct& self) {
        if (self.empty())
            return stream;
        for (constraints_atom_vct::const_iterator it = self.begin(); it != self.end(); ++it)
            stream << (*it).get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, constraints_atom* self) {
        if (self) {
            if (self->reff()) {
                if (self->reff()->as_expectdef())
                    return stream << "??? " << self->reff()->name();
                else
                    stream << " " << self->reff()->name();
            } else {
                stream << "(#";
                if (self->extend())
                    stream << "(...) ";
                else
                    stream << " ";
                for (constraint_atom_vct::const_iterator it = self->constraintline().begin(); it != self->constraintline().end(); ++it)
                    stream << " " << (*it).get();
                if (self->extend())
                    stream << "  ...  ";
                for (constraint_atom_vct::const_iterator it = self->extendline().begin(); it != self->extendline().end(); ++it)
                    stream << " " << (*it).get();
                stream << " #)";
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, const constraint_atom_vct& self) {
        for (constraint_atom_vct::const_iterator it = self.begin(); it != self.end(); ++it) {
            if (*it) stream << " " << (*it).get();
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, constraint_atom* self) {
        switch (self->cotstrtype()) {
            case cns_PatternConstraint: stream << self->as_pattern();
            case cns_SingleValue: return stream << self->as_valueconstraint();
            case cns_ValueRange: return stream << self->as_range();
            case cns_DurationRange: return stream << self->as_duration();
            case cns_TimePointRange:return stream << self->as_timepoint();
            case cns_RecurrenceRange: return stream << self->as_reccurence();
            case cns_ContainedSubtype: return stream << self->as_subtypeconstraint();
            case cns_TypeConstraint: return stream << self->as_typeconstraint();
            case cns_PermittedAlphabet:return stream << self->as_permitted();
            case cns_SizeConstraint: return stream << self->as_size();
            case cns_SingleTypeConstraint: return stream << self->as_singletype();
            case cns_PropertySettings: return stream << self->as_property();
            case cns_MultipleTypeConstraints: return stream << self->as_multipletypeconstraint();
            case cns_NamedConstraint: return stream << self->as_named();
            case cns_ValueSetFromObjects: return stream << self->as_fromdefinedset();
            case cns_ValueSetFromObject: return stream << self->as_fromdefined();
            case cns_UNION: return stream << " | ";
            case cns_INTERSECTION: return stream << " & ";
            case cns_EXCEPT: return stream << " ^ ";
            case cns_ALLEXCEPT: return stream << " ~ ";
            case cns_EXTENTION: return stream << " ... ";
            case cns_EXCEPTION: return stream << self->as_exception();
        }
        return stream << "!!! NULL coctraint  !!!!";
    }

    std::ostream& operator<<(std::ostream& stream, valueconstraint_atom* self) {
        if (self->cotstrtype() == cns_PatternConstraint)
            return stream << "(PATTERN \"" << (self->value().get()) << "\")";
        return stream << (self->value().get());
    }

    std::ostream& operator<<(std::ostream& stream, fromdefinedsetconstraint_atom* self) {
        stream << "(oS) " << self->objectset().get() << "." << self->field()->reff()->name();
    }

    std::ostream& operator<<(std::ostream& stream, fromdefinedconstraint_atom* self) {
        stream << "(o) " << self->object().get() << "." << self->field()->reff()->name();
    }

    std::ostream& operator<<(std::ostream& stream, typeconstraint_atom* self) {
        return stream << (self->type().get());
    }

    std::ostream& operator<<(std::ostream& stream, rangeconstraint_atom* self) {
        stream << "[";
        stream << (self->fromtype());
        if ((self->from()))
            stream << (self->from().get());
        stream << "..";
        stream << (self->totype());
        if ((self->to()))
            stream << (self->to().get());
        stream << "]";
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, namedconstraint_atom* self) {
        stream << self->name();
        if (self->constraints())
            stream << " " << self->constraints().get();
        return stream << self->marker();
    }

    std::ostream& operator<<(std::ostream& stream, constraintmarker_type tp) {
        switch (tp) {
                //case cmk_none:
            case cmk_optional: return stream << " OPTIONAL";
            case cmk_absent: return stream << " ABSENT";
            case cmk_present: return stream << " PRESENT";
                //case  cmk_extention,
                //case cmk_exception
            default:
            {
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, range_type tp) {
        switch (tp) {
            case min_range: return stream << "MIN";
            case max_range: return stream << "MAX";
            case open_range: return stream << "<>";
            default:
            {
            }
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, complexconstraint_atom* self) {
        switch (self->cotstrtype()) {
            case cns_PermittedAlphabet: stream << " FROM";
                break;
            case cns_SizeConstraint: stream << " SIZE";
                break;
            case cns_SingleTypeConstraint: stream << " WITH COMPONENT";
                break;
            default:
            {
            }
        }
        return stream << " " << self->constraints().get();
    }

    std::ostream& operator<<(std::ostream& stream, multipletypeconstraint_atom * self) {
        stream << " WITH COMPONENTS { ";
        for (constraint_atom_vct::const_iterator it = self->components().begin(); it != self->components().end(); ++it)
            stream << (*it).get() << " ,";
        return stream << " }";
    }

    std::ostream& operator<<(std::ostream& stream, exceptionconstraint_atom* self) {
        return stream << " !" << self->type().get() << " : " << self->value().get();
    }


    // class

    std::ostream& operator<<(std::ostream& stream, classassignment_entity* self) {
        stream << "(C) " << self->name();
        if (self->has_arguments())
            stream << self->arguments();
        stream << " :: = ";
        if (self->_class()->builtin() == cl_SpecDef) {
            stream << " CLASS { ";
            for (basic_entity_vector::const_iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if ((*it) && ((*it)->as_classfield()))
                    stream << (*it)->as_classfield();
            }
            stream << " }";
            if (self->withsyntax()) {
                stream << "\n    WITH SYNTAX { \n   ";
                stream << self->withsyntax().get();
                stream << "    }";
            }

        }
        return stream << self->_class().get() << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, class_atom* self) {
        if (self->builtin() == cl_Reference) {
            if (self->reff()->as_expectdef())
                stream << "???" << self->reff()->name();
            else
                stream << self->reff()->name();
        } else {
            if (self->builtin() == cl_SpecDef)
                return stream;
            stream << self->builtin();
        }
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, definedclass_type self) {
        switch (self) {
            case cl_SpecDef: return stream << "spec: ";
            case cl_TYPE_IDENTIFIER: return stream << "TYPE-IDENTIFIER";
            case cl_ABSTRACT_SYNTAX: return stream << "ABSTRACT-SYNTAX";
            case cl_Reference: return stream << "";
            default:
            {
            };
        }

        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, fieldkind_type self) {
        switch (self) {
            case fkind_NoDef: return stream << "!null";
            case fkind_TypeFieldSpec: return stream << "T";
            case fkind_FixedTypeValueFieldSpec: return stream << "FixTypeVal";
            case fkind_VariableTypeValueFieldSpec: return stream << "VTVal";
            case fkind_FixedTypeValueSetFieldSpec: return stream << "FixTypeValSet";
            case fkind_VariableTypeValueSetFieldSpec: return stream << "VTSet";
            case fkind_ObjectFieldSpec: return stream << "ObjectVal";
            case fkind_ObjectSetFieldSpec: return stream << "ObjectSet";
            case fkind_FixedType_or_Object: return stream << "?FixTypeVal or ObjectVal";
            case fkind_FixedTypeSet_or_ObjectSet: return stream << "?FixTypeSet or ObjectSet";
            default:
            {
            }
        }
        return stream << "!null";
    }

    std::ostream& operator<<(std::ostream& stream, field_entity* self) {
        switch (self->fieldkind()) {
            case fkind_TypeFieldSpec: return stream << self->as_typefield();
            case fkind_FixedTypeValueFieldSpec: return stream << self->as_valuefield();
            case fkind_FixedTypeValueSetFieldSpec: return stream << self->as_valuesetfield();
            case fkind_VariableTypeValueFieldSpec: return stream << self->as_reffvaluefield();
            case fkind_VariableTypeValueSetFieldSpec: return stream << self->as_reffvaluesetfield();
            case fkind_ObjectFieldSpec: return stream << self->as_objectfield();
            case fkind_ObjectSetFieldSpec: return stream << self->as_objectsetfield();
            case fkind_FixedType_or_Object: return stream << self->as_undeffield();
            case fkind_FixedTypeSet_or_ObjectSet: return stream << self->as_undefsetfield();
            default:
            {
            }
        }
        return stream << "\n      " << self->name() << " :  " << self->fieldkind();
    }

    std::ostream& operator<<(std::ostream& stream, typefield_entity* self) {
        stream << "\n      (  T)  " << self->name() << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, valuefield_entity* self) {
        stream << "\n      (v  )  " << self->name() << " " << self->type().get();
        if (self->unique())
            stream << " UNIQUE";
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, valuesetfield_entity* self) {
        stream << "\n      (vS )  " << self->name() << " " << self->type().get();
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, reffvaluefield_entity* self) {
        stream << "\n      ( *v)  " << self->name();
        if (self->field()->expecteddef())
            stream << " ??? " << self->field()->reff()->name();
        else
            stream << " " << self->field()->reff()->name();
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, reffvaluesetfield_entity* self) {
        stream << "\n      (*Vs)  " << self->name();
        if (self->field()->expecteddef())
            stream << " ??? " << self->field()->reff()->name();
        else
            stream << " " << self->field()->reff()->name();
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, objectfield_entity* self) {
        stream << "\n      (o  )  " << self->name() << " " << self->_class().get();
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, objectsetfield_entity* self) {
        stream << "\n      (oS )  " << self->name() << " " << self->_class().get();
        stream << " " << self->marker();
        if (self->_default())
            stream << " " << self->_default().get();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, undeffield_entity* self) {
        stream << "\n      (v???o)  " << self->name() << " ??? " << self->big()->expectedname();
        stream << " " << self->marker();
        if (self->_defaultv())
            stream << " ( v+  " << self->_defaultv().get() << ")";
        if (self->_defaulto())
            stream << " (o+  " << self->_defaulto().get() << ")";
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, undefsetfield_entity* self) {
        stream << "\n      (V???S)  " << self->name() << " ??? " << self->big()->expectedname();
        stream << " " << self->marker();
        if (self->_defaultv())
            stream << " ( vs+  " << self->_defaultv().get() << ")";
        if (self->_defaulto())
            stream << " (os+  " << self->_defaulto().get() << ")";
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, syntax_atom* self) {
        if (self->as_group()) {
            if (self->isalias())
                stream << " " << self->alias();
            if (self->optional())
                stream << " [- ";
            else
                stream << " <- ";
            stream << " " << self->as_group();
            if (self->optional())
                stream << " -] ";
            else
                stream << " -> ";
        } else {
            if (self->optional())
                stream << " [ ";
            else
                stream << " < ";
            if (self->isalias())
                stream << " '" << self->alias() << "' ";
            if (self->expecteddef())
                stream << " ??? " << self->reff()->name();
            else
                stream << " *" << self->reff()->name();
            if (self->optional())
                stream << " ] ";
            else
                stream << " > ";
        }
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, groupsyntax_atom* self) {
        for (syntax_atom_vct::const_iterator it = self->group().begin(); it != self->group().end(); ++it) {
            if (it != self->group().begin())
                stream << "\n     " << (*it).get();
            else
                stream << "" << (*it).get();
        }
        return stream;
    }

    // object

    std::ostream& operator<<(std::ostream& stream, objectassignment_entity* self) {
        stream << "(o) " << self->name() << " [" << self->_class().get() << "]";
        if (self->has_arguments())
            stream << self->arguments();
        stream << " :: = ";
        if (self->childs().empty()) {
            if (self->object())
                return stream << self->object().get() << "\n";
        } else {
            stream << " {\n";
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if ((*it)->as_assigment()) {
                    stream << "     ";
                    if ((*it)->as_typeassigment()) {
                        stream << (*it)->as_typeassigment();
                        continue;
                    }
                    if ((*it)->as_valueassigment()) {
                        stream << (*it)->as_valueassigment();
                        continue;
                    }
                    if ((*it)->as_valuesetassigment()) {
                        stream << (*it)->as_valuesetassigment();
                        continue;
                    }
                    if ((*it)->as_objectassigment()) {
                        stream << (*it)->as_objectassigment();
                        continue;
                    }
                    if ((*it)->as_objectsetassigment()) {
                        stream << (*it)->as_objectsetassigment();
                        continue;
                    }
                }

            }
            return stream << "}\n";
        }
        return stream << "???" << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, object_atom* self) {
        switch (self->builtin()) {
            case ot_FromObject: return stream << self->as_fromobject();
            case ot_ObjectSetFromObjects: return stream << self->as_fromdefinedset();
            case ot_ObjectSetFromObject: return stream << self->as_fromdefined();
            case ot_Refference: return stream << self->as_defined();
            case ot_DefinedObjectSet: return stream << self->as_definedset();
            case ot_Object: return stream << self->as_deflt();
            case ot_ObjectDefineSyn: return stream << self->as_defnsyntx();
            case ot_UNION: return stream << " | ";
            case ot_INTERSECTION: return stream << " & ";
            case ot_EXCEPT: return stream << " ^ ";
            case ot_ALLEXCEPT: return stream << " ~ ";
            case ot_EXTENTION: return stream << " ... ";
        }
        return stream << "!!!!NULL OBJECT";
    }

    std::ostream& operator<<(std::ostream& stream, definedobject_atom* self) {
        if (self->reff()->as_expectdef())
            stream << "??? ";
        stream << "" << self->reff()->name();
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, definedsetobject_atom* self) {
        stream << "(oS) " << self->objectset().get();
    }

    std::ostream& operator<<(std::ostream& stream, fromdefinedsetobject_atom* self) {
        stream << "(oS) " << self->objectset().get() << "." << self->field()->reff()->name();
    }

    std::ostream& operator<<(std::ostream& stream, fromdefinedobject_atom* self) {
        stream << "(o) " << self->object().get() << "." << self->field()->reff()->name();
    }

    std::ostream& operator<<(std::ostream& stream, defltobject_atom* self) {
        return stream << self->fieldsetting(); //self->reff()->name();
    }

    std::ostream& operator<<(std::ostream& stream, fromobjectobject_atom* self) {
        stream << "(o)" << self->object().get() << "." << self->field()->reff()->name();
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, defsyntxobject_atom* self) {
        //return stream << self->fieldsetting();
        stream << " {  ";
        for (fieldsetting_atom_vct::const_iterator it = self->fieldsetting().begin(); it != self->fieldsetting().end(); ++it) {
            fieldsettingstrm(stream, (*it).get());
        }
        return stream << " }";
    }

    std::ostream& operator<<(std::ostream& stream, const fieldsetting_atom_vct& self) {
        stream << " {  \n";
        for (fieldsetting_atom_vct::const_iterator it = self.begin(); it != self.end(); ++it) {
            stream << (*it).get();
        }
        return stream << " }";
    }

    std::ostream& operator<<(std::ostream& stream, fieldsetting_atom* self) {
        stream << "    " << self->field() << "   [";
        if (self->setting()) {
            stream << self->setting()->mask();
            if (self->setting()->type())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->value())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->valueset())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->_class())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->object())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->objectset())
                stream << "+";
            else
                stream << "-";
        } else
            stream << "???";
        return stream << "]\n";
    }

    std::ostream& operator<<(std::ostream& stream, const setting_atom_vct& self) {
        if (self.empty())
            return stream;
        stream << " (";
        for (setting_atom_vct::const_iterator it = self.begin(); it != self.end(); ++it) {
            if (it != self.begin())
                stream << " ,";
            stream << (*it).get();
        }
        return stream << " )";
    }

    std::ostream& operator<<(std::ostream& stream, setting_atom* self) {
        stream << "[arg@";
        if (self->type())
            stream << "+";
        else
            stream << "-";
        if (self->value())
            stream << "+";
        else
            stream << "-";
        if (self->valueset())
            stream << "+";
        else
            stream << "-";
        if (self->_class())
            stream << "+";
        else
            stream << "-";
        if (self->object())
            stream << "+";
        else
            stream << "-";
        if (self->objectset())
            stream << "+";
        else
            stream << "-";
        return stream << "]";
    }

    std::ostream& fieldsettingstrm(std::ostream& stream, fieldsetting_atom* self) {
        stream << "  {";
        if (self->setting()) {
            if (!self->setting()->literal().empty())
                stream << "  '" << self->setting()->literal() << "'";
            if (self->setting()->type())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->value())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->valueset())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->_class())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->object())
                stream << "+";
            else
                stream << "-";
            if (self->setting()->objectset())
                stream << "+";
            else
                stream << "-";

        } else
            stream << "???";
        return stream << "} ";
    }


    //  objectset

    std::ostream& operator<<(std::ostream& stream, objectsetassignment_entity* self) {
        stream << "(oS) " << self->name() << " [" << self->_class().get() << "]";
        if (self->has_arguments())
            stream << self->arguments();
        stream << " :: = ";
        if (self->objectset())
            return stream << self->objectset().get() << "\n";
        return stream << "???" << "\n";
    }

    std::ostream& operator<<(std::ostream& stream, objectset_atom* self) {
        switch (self->builtin()) {
            case os_Strait:
            {
                if (self->as_defn()) {
                    stream << "($ ";
                    for (object_atom_vct::const_iterator it = self->as_defn()->objects().begin(); it != self->as_defn()->objects().end(); ++it)
                        stream << " " << (*it).get();
                    stream << " $)";
                    return stream;
                } else
                    return stream << "(oS)??? ";
            }
            case os_ObjectSetFromObjects:
            {
                stream << "(o)" << self->as_fromobjectset()->objectset().get() << "."
                        << self->as_fromobjectset()->field()->reff()->name();
                break;
            }
            case os_ObjectSetFromObject:
            {
                stream << "(oS)" << self->as_fromobject()->object().get() << "."
                        << self->as_fromobject()->field()->reff()->name();
                break;
            }
            case os_defined:
            {
                if (self->reff()->as_expectdef())
                    stream << "??? ";
                stream << " " << self->reff()->name();
            }
            default:
            {
            }
        }
        if (self->parameterized())
            stream << self->parameters();
        return stream;
    }


    // big

    std::ostream& operator<<(std::ostream& stream, bigassignment_entity* self) {
        return stream << "(?B)" << self->name() << " :: = " << "\n";
    }


    // value or object

    std::ostream& operator<<(std::ostream& stream, voassignment_entity* self) {
        stream << "(?VO)" << self->name() << " [ ??? " << self->big()->reff()->name() << "] :: = ";
        if (self->value())
            stream << "(+v)";
        else
            stream << "(-v)";
        if (self->object())
            stream << "(+o)";
        else
            stream << "(-o)";
        return stream << "\n";
    }

    // valueset or objectset

    std::ostream& operator<<(std::ostream& stream, soassignment_entity* self) {
        stream << "(?SO)" << self->name() << " [???" << self->big()->reff()->name() << "] :: = ";
        if (self->valueset())
            stream << "(+vs)";
        else
            stream << "(-vs)";
        if (self->objectset())
            stream << "(+os)";
        else
            stream << "(-os)";
        return stream << "\n";
    }




}
