//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680TYPEPARSER_H_
#define         _ITU_X680TYPEPARSER_H_

#include <boost/itu/x68X/asn1module.hpp>
#include <boost/itu/x68X/x680.hpp>
#include <boost/itu/x68X/value.hpp>

namespace x680 {
    namespace bnf {

        //Tag

        struct Tag_grammar : qi::grammar<str_iterator, tag_type(), skip_cmt_type> {

            typedef Tag_grammar self_type;
            typedef tag_type holder_type;

            struct check_class : qi::symbols<std::string::value_type, tagclass_type > {

                check_class() {

                    add
                            ("UNIVERSAL", tcl_universal)
                            ("APPLICATION", tcl_application)
                            ("PRIVATE", tcl_private)
                            ;
                }
            };

            struct check_rule : qi::symbols<std::string::value_type, tagrule_type > {

                check_rule() {

                    add
                            ("IMPLICIT", implicit_tags)
                            ("EXPLICIT", explicit_tags)
                            ;
                }
            };

            Tag_grammar() :
            Tag_grammar::base_type(start_rule) {

                start_rule = qi::lit("[")
                        >> -(Class[bind(&self_type::classset, *this, qi::_val, qi::_1)])
                        >> (pos_number_str | DefinedValue_)[bind(&self_type::operator(), *this, qi::_val, qi::_1)]
                        >> qi::lit("]")
                        >> -(Rule[bind(&self_type::ruleset, *this, qi::_val, qi::_1)]);

            }

            void ruleset(holder_type& holder, const tagrule_type& val) {
                holder.rule = val;
            }

            void classset(holder_type& holder, const tagclass_type& val) {
                holder.class_ = val;
            }

            void operator()(holder_type& holder, const std::string& val) {
                holder.number = val;
            }

            check_class Class;
            check_rule Rule;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // Type_grammar
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        struct Type_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef Type_grammar self_type;
            typedef type_assignment holder_type;
            typedef type_assignment_vector holders_type;

            struct check_type_simple : qi::symbols<std::string::value_type, defined_type > {

                check_type_simple() {

                    add
                            ("BOOLEAN", t_BOOLEAN)
                            ("NULL", t_NULL)
                            ("ObjectDescriptor", t_ObjectDescriptor)
                            ("EXTERNAL", t_EXTERNAL)
                            ("REAL", t_REAL)
                            ("UTCTime", t_UTCTime)
                            ("GeneralizedTime", t_GeneralizedTime)
                            ("TIME", t_TIME)
                            ("DATE", t_DATE)
                            ("DURATION", t_TIME)
                            ("UTF8String", t_UTF8String)
                            ("NumericString", t_NumericString)
                            ("PrintableString", t_PrintableString)
                            ("T61String", t_T61String)
                            ("VideotexString", t_VideotexString)
                            ("IA5String", t_IA5String)
                            ("GraphicString", t_GraphicString)
                            ("VisibleString", t_VisibleString)
                            ("GeneralString", t_GeneralString)
                            ("UniversalString", t_UniversalString)
                            ("BMPString", t_BMPString)
                            ("TIME-OF-DAY", t_TIME_OF_DAY)
                            ;
                }
            };

            Type_grammar() :
            Type_grammar::base_type(start_rule) {
                init();
            }

            void init();

            void identifier(holder_type& holder, const std::string& val) {
                holder.identifier = val;
            }

            void typereffrence(holder_type& holder, const std::string& val) {
                holder.identifier = val;
            }

            void typeset(type_element& holder, const type_assignment& val) {
                holder = val.type;
            }

            void type(holder_type& holder, const type_assignment& val) {
                holder.type = val.type;
            }

            void type_select(holder_type& holder, const type_assignment& val) {
                holder.type = val.type;
                holder.type.builtin_t = t_Selection;
            }

            void for_taggedtype(holder_type& holder, const type_assignment& val) {
                tag_type tmp = holder.type.tag;
                holder.type = val.type;
                holder.type.tag = tmp;
            }

            void defftype(holder_type& holder, const defined_type& type) {
                holder.type.builtin_t = type;
            }

            void refference(holder_type& holder, const std::string& val) {
                holder.type.reference = val;
            }

            void markerset(holder_type& holder, const tagmarker_type& val) {
                holder.type.marker = val;
            }

            void deffinit(holder_type& holder, const value_element_vector & val) {
                holder.type.predefined = val;
            }

            void tagset(holder_type& holder, const tag_type& val) {
                holder.type.tag = val;
            }

            void push_component(holder_type& holder, const holder_type& val) {
                holder.type.elements.push_back(val);
            }

            void push_components(holder_type& holder, const holders_type& val) {
                holder.type.elements.insert(holder.type.elements.end(), val.begin(), val.end());
            }

            qi::rule<str_iterator, type_element(), skip_cmt_type> start_rule;

            qi::rule<str_iterator, holder_type(), skip_cmt_type> TypeAssignment;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> NamedType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> Type;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> BuitinType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> DefinedType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> ReferencedType;
            check_type_simple simple_typer;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SimpleType;

            qi::rule<str_iterator, holder_type(), skip_cmt_type> IntegerType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> EnumeratedType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> BitStringType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SequenceOfType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SetOfType;

            qi::rule<str_iterator, holder_type(), skip_cmt_type> ComponentType;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ComponentTypeList;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> RootComponentTypeList;
            qi::rule<str_iterator, holders_type(), skip_cmt_type>ExtensionAdditions;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ExtensionAdditionList;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ExtensionAddition;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ExtensionAdditionGroup;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ComponentTypeLists;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> ExceptionSpec;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> Extension;
            qi::rule<str_iterator, holders_type(), skip_cmt_type> ExtensionAndException;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> ExtensionEndMarker;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> OptionalExtensionMarker;

            qi::rule<str_iterator, holder_type(), skip_cmt_type> SequenceType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SetType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> SelectionType;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> ChoiceType;
            Enumerations_grammar Enumerations;
            NamedNumberList_grammar NamedNumberList;
            NamedNumberList_grammar NameBitList;
            Tag_grammar Tag;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> TaggedType;
            Value_grammar Value;

        };


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // TypeAssignment_grammar
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        struct TypeAssignment_grammar : qi::grammar<str_iterator, type_assignment(), skip_cmt_type> {

            typedef TypeAssignment_grammar self_type;
            typedef type_assignment holder_type;

            TypeAssignment_grammar() :
            TypeAssignment_grammar::base_type(start_rule) {
                init();
            }

            void typereffrence(holder_type& holder, const std::string& val) {
                holder.identifier = val;
            }

            void type(holder_type& holder, const type_element& val) {
                holder.type = val;
            }

            void init();

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            Type_grammar Type;
        };


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // TypeAssignment_grammar
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        struct ValueAssignment_grammar : qi::grammar<str_iterator, value_assignment(), skip_cmt_type> {

            typedef ValueAssignment_grammar self_type;
            typedef value_assignment holder_type;

            ValueAssignment_grammar() :
            ValueAssignment_grammar::base_type(start_rule) {
                init();
            }

            void init();

            void valuereference(holder_type& holder, const std::string& val) {
                holder.identifier = val;
            }

            void type(holder_type& holder, const type_element& val) {
                holder.type = val;
            }

            void value(holder_type& holder, const value_element& val) {
                holder.value = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            Type_grammar Type;
            Value_grammar Value;
        };


        //extern syn_elements_sk_rule Types_;

        struct Assignments_grammar : qi::grammar<str_iterator, assignment_vector(), skip_cmt_type> {

            typedef Assignments_grammar self_type;
            typedef assignment_vector holder_type;

            Assignments_grammar() :
            Assignments_grammar::base_type(start_rule) {
                init();
            }

            void init();

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            TypeAssignment_grammar TypeAssignment;
            ValueAssignment_grammar ValueAssignment;
        };

    }
}



#endif	

