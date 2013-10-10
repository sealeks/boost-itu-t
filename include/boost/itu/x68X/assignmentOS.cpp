//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>

namespace x680 {
    namespace syntactic {




        // Type_grammar

        void Modules_grammar::initOS() {


            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //  ObjectSetAssignment grammar
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////// 


            ObjectSet = ObjectSetFromObject | ObjectSetFromObjects | StrictObjectSet | DefinedObjectSet;

            ObjectSetNA = ObjectSetFromObject | ObjectSetFromObjects | StrictObjectSet | SimpleDefinedObjectSet;

            SimpleDefinedObjectSet = DefinedObjectSet_[bind(&objectset_defined, qi::_val, qi::_1)];

            DefinedObjectSet = DefinedObjectSet_[bind(&objectset_defined, qi::_val, qi::_1)]
                    >> -(ActualParameters[bind(&objectset_parameters, qi::_val, qi::_1)]);                 

            ObjectSetFromObject =  (DefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[bind(&objectset_fromobject, qi::_val, qi::_1, qi::_2)];
                    
            ObjectSetFromObjectNA =  (SimpleDefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[bind(&objectset_fromobject, qi::_val, qi::_1, qi::_2)];
                    
            ObjectSetFromObjects = (DefinedObjectSet 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[bind(&objectset_fromobjects, qi::_val, qi::_1, qi::_2)];   
                    
            ObjectSetFromObjectsNA = (SimpleDefinedObjectSet 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[bind(&objectset_fromobjects, qi::_val, qi::_1, qi::_2)];                       

            StrictObjectSet = ObjectSetdecl[bind(&objectset_set, qi::_val, qi::_1)];

            oDefinedObjectSet = DefinedObjectSet[bind(&object_objectsetdef, qi::_val, qi::_1)];

            oObjectSetFromObjects =  (DefinedObjectSet 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[bind(&object_objectsetfromobjects, qi::_val, qi::_1, qi::_2)];
                    
            oObjectSetFromObject = (DefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[bind(&object_objectsetfromobject, qi::_val, qi::_1, qi::_2)];        


            ObjectSetdecl = qi::omit[qi::lit("{")]
                    >> oElementSetSpecs
                    >> qi::omit[qi::lit("}")];


            oElementSetSpecs = oElementSetSpecs2 | oElementSetSpecs1;

            oElementSetSpecs1 %= oElementSetSpec >>
                    -(qi::omit[qi::lit(",")] >> oExtention >>
                    -(qi::omit[qi::lit(",")] >> oElementSetSpec));

            oElementSetSpecs2 %= oExtention >>
                    -(qi::omit[qi::lit(",")] >> oElementSetSpec);


            oUElems %= ((qi::omit[(UNION_ | qi::lit("|"))]
                    >> oUnions)[ bind(&object_element_vector::push_back, qi::_val, OBJECT_UNION) ]);

            oElementSetSpec = oUnions[bind(&push_objects, qi::_val, qi::_1)]
                    >> *(oUElems[bind(&push_objects, qi::_val, qi::_1)]);

            oIElems %= (qi::omit[(INTERSECTION_ | qi::lit("^"))]
                    >> oIntersections)[bind(&object_element_vector::push_back, qi::_val, OBJECT_INTERSECTION)];

            oUnions = oIntersections[bind(&push_objects, qi::_val, qi::_1)]
                    >> *(oIElems[bind(&push_objects, qi::_val, qi::_1)]);


            oEElems %= (qi::omit[EXCEPT_ ]
                    >> oExclusions)[bind(&object_element_vector::push_back, qi::_val, OBJECT_EXCEPT)];

            oIntersections = oExclusions[bind(&push_objects, qi::_val, qi::_1)]
                    >> *(oEElems[bind(&push_objects, qi::_val, qi::_1)]);


            oAElems %= (qi::omit[qi::lit("ALL EXCEPT")]
                    >> oExclusions)[bind(&object_element_vector::push_back, qi::_val, OBJECT_ALLEXCEPT)];

            oExclusions
                    = oElement
                    | qi::omit[qi::lit("(")]
                    >> oElementSetSpec
                    >> qi::omit[ qi::lit(")")]
                    | oAElems
                    ;

            oExtention = qi::lit("...")[qi::_val = OBJECT_EXTENTION];

            oElement = oObjectSetFromObject | oObjectSetFromObjects | oDefinedObjectSet | Object;




        }

    }
}