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


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // Simple declareted type
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        struct SympleTypeDecl_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef SympleTypeDecl_grammar self_type;
            typedef type_element holder_type;

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

            SympleTypeDecl_grammar() :
            SympleTypeDecl_grammar::base_type(start_rule) {

                start_rule = ((qi::lexeme[OCTET_ >> +qi::blank >> STRING_])[bind(&self_type::operator(), *this, qi::_val, t_OCTET_STRING)]
                        | (qi::lexeme[CHARACTER_ >> +qi::blank >> STRING_])[bind(&self_type::operator(), *this, qi::_val, t_CHARACTER_STRING)]
                        | (qi::lexeme[EMBEDDED_ >> +qi::blank >> PDV_])[bind(&self_type::operator(), *this, qi::_val, t_EMBEDDED_PDV)]
                        | (qi::lexeme[OBJECT_ >> +qi::blank >> IDENTIFIER_])[bind(&self_type::operator(), *this, qi::_val, t_OBJECT_IDENTIFIER)]
                        | (qi::lexeme[DATE_ >> +qi::blank >> TIME_])[bind(&self_type::operator(), *this, qi::_val, t_DATE_TIME)]
                        | simple_typer[bind(&self_type::operator(), *this, qi::_val, qi::_1)]
                        );


            }

            void operator()(holder_type& holder, const defined_type & tp) {
                holder.builtin_t = tp;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            check_type_simple simple_typer;

        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // INTEGER
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // IntegerType

        struct IntegerType_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef IntegerType_grammar self_type;
            typedef type_element holder_type;

            IntegerType_grammar() :
            IntegerType_grammar::base_type(start_rule) {

                start_rule = INTEGER_[bind(&self_type::operator(), *this, qi::_val)]
                        >> -NamedNumberList[bind(&self_type::operator(), *this, qi::_val, qi::_1)];

            }

            void operator()(holder_type & holder) {
                holder.builtin_t = t_INTEGER;
            }

            void operator()(holder_type& holder, const value_element_vector & val) {
                holder.predefined = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            NamedNumberList_grammar NamedNumberList;

        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // ENUMERATED
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        // EnumeratedType

        struct EnumeratedType_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef EnumeratedType_grammar self_type;
            typedef type_element holder_type;

            EnumeratedType_grammar() :
            EnumeratedType_grammar::base_type(start_rule) {

                start_rule = ENUMERATED_[bind(&self_type::operator(), *this, qi::_val)]
                        >> -Enumerations[bind(&self_type::operator(), *this, qi::_val, qi::_1)];

            }

            void operator()(holder_type& holder) {
                holder.builtin_t = t_ENUMERATED;
            }

            void operator()(holder_type& holder, const value_element_vector & val) {
                holder.predefined = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            Enumerations_grammar Enumerations;

        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        // BIT STRING
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // BitStringTypeType

        struct BitStringType_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef BitStringType_grammar self_type;
            typedef type_element holder_type;

            BitStringType_grammar() :
            BitStringType_grammar::base_type(start_rule) {

                start_rule = qi::lexeme[BIT_ >> +qi::blank >> STRING_[bind(&self_type::operator(), *this, qi::_val)]]
                        >> -NameBitList[bind(&self_type::operator(), *this, qi::_val, qi::_1)];

            }

            void operator()(holder_type & holder) {
                holder.builtin_t = t_BIT_STRING;
            }

            void operator()(holder_type& holder, const value_element_vector & val) {
                holder.predefined = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            NamedNumberList_grammar NameBitList;

        };







        //BuiltinType

        struct BuiltinType_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef BuiltinType_grammar self_type;
            typedef type_element holder_type;

            BuiltinType_grammar() :
            BuiltinType_grammar::base_type(start_rule) {
                start_rule = (IntegerType | EnumeratedType | BitStringType | SympleTypeDecl)[bind(&self_type::operator(), *this, qi::_val, qi::_1)];
            }

            void operator()(holder_type& holder, const type_element& val) {
                holder.from(val);
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            SympleTypeDecl_grammar SympleTypeDecl;
            IntegerType_grammar IntegerType;
            EnumeratedType_grammar EnumeratedType;
            BitStringType_grammar BitStringType;

        };




        //DefindeType

        struct DefinedType_grammar : qi::grammar<str_iterator, defined_type_element(), skip_cmt_type> {

            typedef DefinedType_grammar self_type;
            typedef defined_type_element holder_type;

            DefinedType_grammar() :
            DefinedType_grammar::base_type(start_rule) {

                start_rule = DefinedType_[bind(&self_type::operator(), *this, qi::_val, qi::_1)];

            }

            void operator()(holder_type& holder, const std::string& val) {
                holder.reference = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;

        };



        //ReferencedType

        struct ReferencedType_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef ReferencedType_grammar self_type;
            typedef type_element holder_type;

            ReferencedType_grammar() :
            ReferencedType_grammar::base_type(start_rule) {

                start_rule = DefinedType[bind(&self_type::operator(), *this, qi::_val, qi::_1)];

            }

            void operator()(holder_type& holder, const defined_type_element& val) {
                holder.from(val);
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            DefinedType_grammar DefinedType;

        };





        //Type

        struct Type_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef Type_grammar self_type;
            typedef type_element holder_type;

            Type_grammar() :
            Type_grammar::base_type(start_rule) {
                init();
            }

            void init();

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            BuiltinType_grammar BuiltinType;
            ReferencedType_grammar ReferencedType;
        };


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

                start_rule = -(Rule[bind(&self_type::ruleset, *this, qi::_val, qi::_1)])
                        >> qi::lit("[")
                        >> -(Class[bind(&self_type::classset, *this, qi::_val, qi::_1)])
                        >> (pos_number_str | DefinedValue_)[bind(&self_type::operator(), *this, qi::_val, qi::_1)]
                        >> qi::lit("]");

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


        //TaggedType

        struct TaggedType_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef TaggedType_grammar self_type;
            typedef type_element holder_type;

            TaggedType_grammar() :
            TaggedType_grammar::base_type(start_rule) {

                start_rule = Tag[bind(&self_type::tagset, *this, qi::_val, qi::_1)]
                        >> Type[bind(&self_type::operator(), *this, qi::_val, qi::_1)];

            }

            void tagset(holder_type& holder, const tag_type& val) {
                holder.tag = val;
            }

            void operator()(holder_type& holder, const type_element& val) {
                holder.from_tagged(val);
            }

            Tag_grammar Tag;
            Type_grammar Type;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;

        };


        //TypeA

        struct TypeA_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef TypeA_grammar self_type;
            typedef type_element holder_type;

            TypeA_grammar() :
            TypeA_grammar::base_type(start_rule) {

                start_rule = TaggedType | Type;

            }


            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            TaggedType_grammar TaggedType;
            Type_grammar Type;

        };




        //ComponentType

        struct ComponentType_grammar : qi::grammar<str_iterator, named_type_element(), skip_cmt_type> {

            typedef ComponentType_grammar self_type;
            typedef named_type_element holder_type;

            ComponentType_grammar() :
            ComponentType_grammar::base_type(start_rule) {
                init();
            }

            void init();

            void operator()(holder_type& holder, const std::string& val) {
                holder.identifier = val;
            }

            void element(holder_type& holder, const type_element& val) {
                holder.type = val;
            }

            void marker(holder_type& holder, const tagmarker_type& val) {
                holder.marker = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            TypeA_grammar Type;


        };



        //SequenceType

        struct SequenceType_grammar : qi::grammar<str_iterator, type_element(), skip_cmt_type> {

            typedef SequenceType_grammar self_type;
            typedef type_element holder_type;

            SequenceType_grammar() :
            SequenceType_grammar::base_type(start_rule) {
                init();
            }

            void init();

            void operator()(holder_type& holder) {
                holder.builtin_t = t_SEQUENCE;
            }

            void operator()(holder_type& holder, const named_type_element& val) {
                holder.elements.push_back(val);
            }


            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            //ComponentType_grammar Component;

        };




        //TypeAssignment

        struct TypeAssignment_grammar : qi::grammar<str_iterator, type_assigment(), skip_cmt_type> {

            typedef TypeAssignment_grammar self_type;
            typedef type_assigment holder_type;

            TypeAssignment_grammar() :
            TypeAssignment_grammar::base_type(start_rule) {

                start_rule = typereference_[bind(&self_type::operator(), *this, qi::_val, qi::_1)]
                        >> qi::lexeme[qi::lit("::=")]
                        >> Type[bind(&self_type::element, *this, qi::_val, qi::_1)];

            }

            void operator()(holder_type& holder, const std::string& val) {
                holder.identifier = val;
            }

            void element(holder_type& holder, const type_element& val) {
                holder.from(val);
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            TypeA_grammar Type;

        };



        //extern syn_elements_sk_rule Types_;

        struct Types_grammar : qi::grammar<str_iterator, type_assigment_vector(), skip_cmt_type> {

            typedef Types_grammar self_type;
            typedef type_assigment_vector holder_type;

            Types_grammar() :
            Types_grammar::base_type(start_rule) {

                start_rule = *TypeAssignment;

            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> start_rule;
            ;
            TypeAssignment_grammar TypeAssignment;
        };

    }
}



#endif	

