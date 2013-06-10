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

        // NumberListValue        

        struct NumberList_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef NumberList_grammar self_type;
            typedef value_element holder_type;

            NumberList_grammar() :
            NumberList_grammar::base_type(startrule) {
                init();
            }

            void init();

            void operator()(holder_type& holder, const std::string & val) {
                holder.type = v_number_list;
                value_element tmp;
                tmp.type = v_number;
                tmp.value = val;
                holder.values.push_back(tmp);
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




    }
}

#endif	

