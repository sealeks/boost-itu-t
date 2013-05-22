//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680VALUEPARSER_H_
#define         _ITU_X680VALUEPARSER_H_

#include <boost/itu/x68X/asn1module.hpp>
#include <boost/itu/x68X/x680.hpp>


namespace x680 {
    namespace bnf {


        // NamedNumber_grammar

        struct NamedNumber_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef NamedNumber_grammar self_type;
            typedef value_element holder_type;

            NamedNumber_grammar() :
            NamedNumber_grammar::base_type(pair) {
                init();
            }

            void init();

            void first(holder_type& holder, const std::string & val) {
                holder.identifier = val;
            }

            void second_n(holder_type& holder, const std::string & val) {
                holder.type = v_number;
                holder.value = val;
            }

            void second_i(holder_type& holder, const std::string & val) {
                holder.type = v_identifier;
                holder.value = val;
            }


            qi::rule<str_iterator, holder_type(), skip_cmt_type> pair;
        };






        //NamedNumberList        

        struct NamedNumberList_grammar : qi::grammar<str_iterator, value_element_vector(), skip_cmt_type> {

            typedef NamedNumberList_grammar self_type;
            typedef value_element_vector holder_type;

            NamedNumberList_grammar() :
            NamedNumberList_grammar::base_type(vect) {
                init();
            }

            void init();

            void operator()(holder_type& holder, const value_element & val) {
                holder.push_back(val);
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type > vect;
            NamedNumber_grammar components;

        };





        // Enumeration_grammar

        struct Enumeration_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef Enumeration_grammar self_type;
            typedef value_element holder_type;

            Enumeration_grammar() :
            Enumeration_grammar::base_type(pair) {
                init();
            }

            void init();

            void first(holder_type& holder, const std::string & val) {
                holder.identifier = val;
                holder.type = v_identifier;

            }

            void extention(holder_type & holder) {
                holder.type = v_extention;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> pair;
            NamedNumber_grammar component;

        };






        //Enumerations       

        struct Enumerations_grammar : qi::grammar<str_iterator, value_element_vector(), skip_cmt_type> {

            typedef Enumerations_grammar self_type;
            typedef value_element_vector holder_type;

            Enumerations_grammar() :
            Enumerations_grammar::base_type(vect) {
                init();
            }

            void init();

            void operator()(holder_type& holder, const value_element & val) {

                holder.push_back(val);
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type > vect;
            Enumeration_grammar components;

        };




        //objNameId

        struct objNameId_grammar : public qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef objNameId_grammar self_type;
            typedef value_element holder_type;

            objNameId_grammar()
            : objNameId_grammar::base_type(pair) {
                init();
            }

            void init();

            void first(holder_type& holder, const std::string & val) {
                holder.identifier = val;
                holder.type = v_identifier;
            }

            void second(holder_type& holder, const std::string & val) {
                holder.value = val;
                holder.type = v_number;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type > pair;
        };






        //ObjectIdentifierSet

        struct ObjectIdentifierSet_grammar :
        public qi::grammar<str_iterator, value_element_vector(), skip_cmt_type > {

            typedef ObjectIdentifierSet_grammar self_type;
            typedef value_element_vector holder_type;

            ObjectIdentifierSet_grammar()
            : ObjectIdentifierSet_grammar::base_type(vect) {
                init();
            }

            void init();

            void operator()(holder_type& holder, value_element & val) {
                holder.push_back(val);
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> vect;
            objNameId_grammar components;
        };





        // value grammar


        // BooleanValue

        struct BooleanValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef BooleanValue_grammar self_type;
            typedef value_element holder_type;

            BooleanValue_grammar() :
            BooleanValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void operator()(holder_type& holder, const std::string & val) {
                holder.type = v_boolean;
                holder.value = val;
            }


            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;


        };


        // IntegerValue

        struct IntegerValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef IntegerValue_grammar self_type;
            typedef value_element holder_type;

            IntegerValue_grammar() :
            IntegerValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void number(holder_type& holder, const std::string & val) {
                holder.type = v_number;
                holder.value = val;
            }

            void identifier(holder_type& holder, const std::string & val) {
                holder.type = v_identifier;
                holder.value = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;

        };


        // IdentifierValue_grammar

        struct IdentifierValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef IdentifierValue_grammar self_type;
            typedef value_element holder_type;

            IdentifierValue_grammar() :
            IdentifierValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void identifier(holder_type& holder, const std::string & val) {
                holder.type = v_identifier;
                holder.value = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;

        };



        //EnumeratedValue  = identifier

        struct RealValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef RealValue_grammar self_type;
            typedef value_element holder_type;

            RealValue_grammar() :
            RealValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void operator()(holder_type& holder, const std::string & val) {
                holder.type = v_real;
                holder.value = val;
            }


            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;


        };


        //HStringValue_grammar

        struct HStringValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef HStringValue_grammar self_type;
            typedef value_element holder_type;

            HStringValue_grammar() :
            HStringValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void operator()(holder_type& holder, const std::string & val) {
                holder.value = val;
                holder.type = v_hstring;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;

        };


        //BStringValue_grammar

        struct BStringValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef BStringValue_grammar self_type;
            typedef value_element holder_type;

            BStringValue_grammar() :
            BStringValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void operator()(holder_type& holder, const std::string & val) {
                holder.value = val;
                holder.type = v_bstring;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;

        };


        //CStringValue_grammar

        struct CStringValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef CStringValue_grammar self_type;
            typedef value_element holder_type;

            CStringValue_grammar() :
            CStringValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void operator()(holder_type& holder, const std::string & val) {
                holder.value = val;
                holder.type = v_cstring;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;

        };




        // NullValue

        struct NullValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef NullValue_grammar self_type;
            typedef value_element holder_type;

            NullValue_grammar() :
            NullValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void operator()(holder_type & holder) {
                holder.type = v_null;
                holder.value = "NULL";
            }


            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;


        };


        // IdentifierList_grammar

        struct IdentifierList_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef IdentifierList_grammar self_type;
            typedef value_element holder_type;

            IdentifierList_grammar() :
            IdentifierList_grammar::base_type(startrule) {
                init();
            }

            void init();

            void operator()(holder_type & holder, const std::string& val) {
                holder.type = v_identifier_list;
                value_element tmp;
                tmp.type = v_identifier;
                tmp.identifier = val;
                holder.values.push_back(tmp);
            }

            void operator()(holder_type & holder) {
                holder.type = v_empty_set;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;


        };


        //ObjectIdentifierValue

        struct ObjectIdentifierValue_grammar :
        public qi::grammar<str_iterator, value_element(), skip_cmt_type > {

            typedef ObjectIdentifierValue_grammar self_type;
            typedef value_element holder_type;

            ObjectIdentifierValue_grammar()
            : ObjectIdentifierValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void operator()(holder_type& holder, const value_element_vector & val) {
                holder.type = v_named_list;
                holder.values = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;
            ObjectIdentifierSet_grammar ObjectIdentifierSet;
        };




        // SimpleValue        

        struct SimpleValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef SimpleValue_grammar self_type;
            typedef value_element holder_type;

            SimpleValue_grammar() :
            SimpleValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;

            NullValue_grammar NullValue;
            BooleanValue_grammar BooleanValue;
            IntegerValue_grammar IntegerValue;
            RealValue_grammar RealValue;
            CStringValue_grammar CStringValue;
            ObjectIdentifierValue_grammar ObjectIdentifierValue;
            HStringValue_grammar HStringValue;
            BStringValue_grammar BStringValue;
            IdentifierList_grammar IdentifierList;


        };


        // NamedValue        

        struct NamedValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef NamedValue_grammar self_type;
            typedef value_element holder_type;

            NamedValue_grammar() :
            NamedValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void idetifier(holder_type& holder, const std::string& val) {
                holder.identifier = val;
            }

            void value(holder_type& holder, const value_element & val) {
                std::string tmp = holder.identifier;
                holder = val;
                holder.identifier = tmp;
                holder.type = v_named_value;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;

            SimpleValue_grammar SimpleValue;

        };


        // StructValue        

        struct StructValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef StructValue_grammar self_type;
            typedef value_element holder_type;

            StructValue_grammar() :
            StructValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void idetifier(holder_type& holder, const std::string& val) {
                holder.identifier = val;
            }

            void named_value(holder_type& holder, value_element & val) {
                std::string tmp = holder.identifier;
                holder = val;
                holder.identifier = tmp;
            }

            void choice_value(holder_type& holder, value_element & val) {
                std::string tmp = holder.identifier;
                holder = val;
                holder.identifier = tmp;
                holder.type = v_choice;
            }

            void value(holder_type& holder, value_element & val) {
                holder = val;
            }

            void values(holder_type& holder, value_element_vector& val) {
                holder.type = v_variable_list;
                holder.values = val;
            }

            void named_values(holder_type& holder, const value_element_vector& val) {
                holder.type = v_named_value;
                holder.values = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> NamedValue;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> Value;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> ChoiceValue;
            qi::rule<str_iterator, holder_type(), skip_cmt_type> ComplexValue;
            qi::rule<str_iterator, value_element_vector(), skip_cmt_type> ComponentValueList;

            SimpleValue_grammar SimpleValue;

        };


        // ReferencedValue        

        struct ReferencedValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef ReferencedValue_grammar self_type;
            typedef value_element holder_type;

            ReferencedValue_grammar() :
            ReferencedValue_grammar::base_type(startrule) {
                init();
            }

            void init();

            void defined(holder_type& holder, const std::string& val) {
                holder.type = v_defined;
                holder.identifier = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;

        };


        // Value        

        struct Value_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef Value_grammar self_type;
            typedef value_element holder_type;

            Value_grammar() :
            Value_grammar::base_type(startrule) {
                init();
            }

            void init();



            qi::rule<str_iterator, holder_type(), skip_cmt_type> startrule;

            SimpleValue_grammar SimpleValue;
            StructValue_grammar StructValue;
            ReferencedValue_grammar ReferencedValue;

        };

    }
}

#endif	

