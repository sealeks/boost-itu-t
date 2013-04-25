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

                pair = (identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                        >> qi::lit("(")
                        >> (number_str[bind(&self_type::second_n, *this, qi::_val, qi::_1)]  
                        | identifier_[bind(&self_type::second_i , *this, qi::_val, qi::_1)] )
                        >> qi::lit(")"));
            }

            void first(holder_type& holder, const std::string & val) {

                holder.identifier = val;
                
            }

            void second_n(holder_type& holder, const std::string & val) {
                holder.type =v_number;
                holder.value = val;
            }
            
            void second_i(holder_type& holder, const std::string & val) {
                holder.type =v_identifier;
                holder.value = val;
            }            


            qi::rule<str_iterator, holder_type(), skip_cmt_type> pair;
        };

        
        
        
        
        
        //NamedNumberList        


        struct NamedNumberList_grammar : qi::grammar<str_iterator, value_element_vector(), skip_cmt_type> {

            typedef NamedNumberList_grammar self_type;
            typedef value_element_vector holder_type;

            NamedNumberList_grammar() :
            NamedNumberList_grammar::base_type(vect)  {

                vect = qi::lit("{")
                        >> -(components[bind(&self_type::operator (), *this, qi::_val, qi::_1)] % qi::omit[","])
                        >> qi::lit("}");
            }

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

                     pair = component[ qi::_val = qi::_1 ] |
                       identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                        | qi::lit("...")[bind(&self_type::extention, *this, qi::_val)];
            }

            void first(holder_type& holder, const std::string & val) {
                holder.identifier = val;
                holder.type= v_identifier;
                
            }

            void extention(holder_type & holder) {
                holder.type= v_extention;
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

                vect = qi::lit("{")
                        >> -(components[bind(&self_type::operator (), *this, qi::_val, qi::_1)] % qi::omit[","])
                        >> qi::lit("}");
            }

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

                pair = (identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                        >> qi::lit("(")
                        >> pos_number_str[bind(&self_type::second, *this, qi::_val, qi::_1)]
                        >> qi::lit(")"))
                        | identifier_[bind(&self_type::first, *this, qi::_val, qi::_1)]
                        | pos_number_str[bind(&self_type::second, *this, qi::_val, qi::_1)];
            }

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






        //ObjectIdentifierValue


        struct ObjectIdentifierValue_grammar :
        public qi::grammar<str_iterator, value_element_vector(), skip_cmt_type > {

            typedef ObjectIdentifierValue_grammar self_type;
            typedef value_element_vector holder_type;

            ObjectIdentifierValue_grammar()
            : ObjectIdentifierValue_grammar::base_type(vect) {

                vect = qi::lit("{")
                        >> *(components[bind(&self_type::operator (), *this, qi::_val, qi::_1)])
                        >> qi::lit("}");
            }

            void operator()(holder_type& holder, value_element & val) {
                holder.push_back(val);               
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> vect;
            objNameId_grammar components;
        };



        

        

        // BooleanValue


        struct BooleanValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef BooleanValue_grammar self_type;
            typedef value_element holder_type;

            BooleanValue_grammar() :
            BooleanValue_grammar::base_type(pair) {

                pair = TRUE_[bind(&self_type::operator(), *this, qi::_val, std::string("TRUE"))]
                        | FALSE_[bind(&self_type::operator(), *this, qi::_val, std::string("FALSE"))];
            }

            void operator()(holder_type& holder, const std::string & val) {
                holder.type = v_boolean;
                holder.value = val;
            }


            qi::rule<str_iterator, holder_type(), skip_cmt_type> pair;


        };


        // IntegerValue


        struct IntegerValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef IntegerValue_grammar self_type;
            typedef value_element holder_type;

            IntegerValue_grammar() :
            IntegerValue_grammar::base_type(pair) {

                pair = number_str[bind(&self_type::operator(), *this, qi::_val, qi::_1)];
            }

            void operator()(holder_type& holder, const std::string & val) {
                holder.type = v_number;
                holder.value = val;
            }

            qi::rule<str_iterator, holder_type(), skip_cmt_type> pair;

        };

        //EnumeratedValue  = identifier


        // IntegerValue


        struct RealValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef RealValue_grammar self_type;
            typedef value_element holder_type;

            RealValue_grammar() :
            RealValue_grammar::base_type(pair) {

                pair = realnumber_str[bind(&self_type::operator(), *this, qi::_val, qi::_1)]
                        | PLUS_INFINITY_[bind(&self_type::operator(), *this, qi::_val, std::string("PLUS-INFINITY"))]
                        | MINUS_INFINITY_[bind(&self_type::operator(), *this, qi::_val, std::string("MINUS-INFINITY"))]
                        | NOT_A_NUMBER_[bind(&self_type::operator(), *this, qi::_val, std::string("NOT-A-NUMBER"))];
            }

            void operator()(holder_type& holder, const std::string & val) {
                holder.type = v_real;
                holder.value = val;
            }


            qi::rule<str_iterator, holder_type(), skip_cmt_type> pair;


        };





        // NullValue


        struct NullValue_grammar : qi::grammar<str_iterator, value_element(), skip_cmt_type> {

            typedef NullValue_grammar self_type;
            typedef value_element holder_type;

            NullValue_grammar() :
            NullValue_grammar::base_type(pair) {

                pair = NULL_[bind(&self_type::operator(), *this, qi::_val) ];
                
            }

            void operator()(holder_type & holder) {
                holder.type = v_null;
                        holder.value = "NULL";
            }


            qi::rule<str_iterator, holder_type(), skip_cmt_type> pair;


        };



    }
}

#endif	

