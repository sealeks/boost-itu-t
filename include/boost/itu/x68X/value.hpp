//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680VALUEPARSER_H_
#define         _ITU_X680VALUEPARSER_H_

#include <boost/itu/x68X/asn1module.hpp>
#include <boost/itu/x68X/x680.hpp>
#include <boost/itu/x68X/type.hpp>

namespace x680 {
    namespace bnf {


        // BooleanValue

        template <typename Iterator>
        struct BooleanValue_grammar : qi::grammar<Iterator, value_element(), skip_cmt_type> {

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


            qi::rule<Iterator, holder_type(), skip_cmt_type> pair;


        };


        // IntegerValue

        template <typename Iterator>
        struct IntegerValue_grammar : qi::grammar<Iterator, value_element(), skip_cmt_type> {

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

            qi::rule<Iterator, holder_type(), skip_cmt_type> pair;

        };

        //EnumeratedValue  = identifier


        // IntegerValue

        template <typename Iterator>
        struct RealValue_grammar : qi::grammar<Iterator, value_element(), skip_cmt_type> {

            typedef RealValue_grammar self_type;
            typedef value_element holder_type;

            RealValue_grammar() :
            RealValue_grammar::base_type(pair) {

                pair = realnumber_str[bind(&self_type::second_n, *this, qi::_val, qi::_1)]
                        | PLUS_INFINITY_[bind(&self_type::operator(), *this, qi::_val, std::string("PLUS-INFINITY"))]
                        | MINUS_INFINITY_[bind(&self_type::operator(), *this, qi::_val, std::string("MINUS-INFINITY"))]
                        | NOT_A_NUMBER_[bind(&self_type::operator(), *this, qi::_val, std::string("NOT-A-NUMBER"))];
            }

            void operator()(holder_type& holder, const std::string & val) {
                holder.type = v_real;
                holder.value = val;
            }


            qi::rule<Iterator, holder_type(), skip_cmt_type> pair;


        };





        // NullValue

        template <typename Iterator>
        struct NullValue_grammar : qi::grammar<Iterator, value_element(), skip_cmt_type> {

            typedef NullValue_grammar self_type;
            typedef value_element holder_type;

            NullValue_grammar() :
            NullValue_grammar::base_type(pair) {

                pair = NULL_[bind(&self_type::operator(), *this, qi::_val];
            }

            void operator()(holder_type & holder) {
                holder.type = v_null;
                        holder.value = "NULL";
            }


            qi::rule<Iterator, holder_type(), skip_cmt_type> pair;


        };



    }
}

#endif	

