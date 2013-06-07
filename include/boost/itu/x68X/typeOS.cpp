//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/type.hpp>

namespace x680 {
    namespace bnf {

       


        // Type_grammar

        void Assignments_grammar::initOS() {


            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectSetAssignment grammar
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

            ObjectSet = qi::omit[qi::lit("{")]
                    >> oElementSetSpecs
                    >> qi::omit[qi::lit("}")];




            oElementSetSpecs %= oElementSetSpec >>
                    -(qi::omit[qi::lit(",")] >> oExtention >>
                    -(qi::omit[qi::lit(",")] >> oElementSetSpec));


            oUElems %= ((qi::omit[(UNION_ | qi::lit("|"))]
                    >> oUnions)[ bind(&object_element_vector::push_back, qi::_val, OBJECT_UNION) ]);

            oElementSetSpec
                    = oUnions[bind(&push_objects, qi::_val, qi::_1)] >> *(oUElems[bind(&push_objects, qi::_val, qi::_1)]);

            oIElems %= (qi::omit[(INTERSECTION_ | qi::lit("^"))]
                    >> oIntersections)[bind(&object_element_vector::push_back, qi::_val, OBJECT_INTERSECTION)];

            oUnions =
                    oIntersections[bind(&push_objects, qi::_val, qi::_1)] >> *(oIElems[bind(&push_objects, qi::_val, qi::_1)]);


            oEElems %= (qi::omit[EXCEPT_ ]
                    >> oExclusions)[bind(&object_element_vector::push_back, qi::_val, OBJECT_EXCEPT)];

            oIntersections =
                    oExclusions[bind(&push_objects, qi::_val, qi::_1)] >> *(oEElems[bind(&push_objects, qi::_val, qi::_1)]);


            oAElems %=
                    (qi::omit[qi::lit("ALL EXCEPT")]
                    >> oExclusions)[bind(&object_element_vector::push_back, qi::_val, OBJECT_ALLEXCEPT)];

            oExclusions
                    = oElement
                    | qi::omit[qi::lit("(")]
                    >> oElementSetSpec
                    >> qi::omit[ qi::lit(")")]
                    | oAElems
                    ;

            oExtention = qi::lit("...")[qi::_val = OBJECT_EXTENTION];

            oElement = DefaultSyntax[qi::_val = qi::_1 ] | DefinedObject_[bind(&object_reff, qi::_val, qi::_1)];




        }

    }
}