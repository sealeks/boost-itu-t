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

            SimpleDefinedObjectSet = DefinedObjectSet_[phx::bind(&objectset_defined, sprt::_val, sprt::_1)];

            DefinedObjectSet = DefinedObjectSet_[phx::bind(&objectset_defined, sprt::_val, sprt::_1)]
                    >> -(ActualParameters[phx::bind(&objectset_parameters, sprt::_val, sprt::_1)]);                 

            ObjectSetFromObject =  (DefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&objectset_fromobject, sprt::_val, sprt::_1, sprt::_2)];
                    
            ObjectSetFromObjectNA =  (SimpleDefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&objectset_fromobject, sprt::_val, sprt::_1, sprt::_2)];
                    
            ObjectSetFromObjects = (DefinedObjectSet 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&objectset_fromobjects, sprt::_val, sprt::_1, sprt::_2)];   
                    
            ObjectSetFromObjectsNA = (SimpleDefinedObjectSet 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&objectset_fromobjects, sprt::_val, sprt::_1, sprt::_2)];                       

            StrictObjectSet = ObjectSetdecl[phx::bind(&objectset_set, sprt::_val, sprt::_1)];

            oDefinedObjectSet = DefinedObjectSet[phx::bind(&object_objectsetdef, sprt::_val, sprt::_1)];

            oObjectSetFromObjects =  (DefinedObjectSet 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&object_objectsetfromobjects, sprt::_val, sprt::_1, sprt::_2)];
                    
            oObjectSetFromObject = (DefinedObject 
                    >>  qi::omit[qi::string(".") >> (*qi::space)]  
                    >>FieldName_)[phx::bind(&object_objectsetfromobject, sprt::_val, sprt::_1, sprt::_2)];        


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
                    >> oUnions)[ phx::bind(&objectsetpush_object, sprt::_val, OBJECT_UNION) ]);

            oElementSetSpec = oUnions[phx::bind(&push_objects, sprt::_val, sprt::_1)]
                    >> *(oUElems[phx::bind(&push_objects, sprt::_val, sprt::_1)]);

            oIElems %= (qi::omit[(INTERSECTION_ | qi::lit("^"))]
                    >> oIntersections)[phx::bind(&objectsetpush_object, sprt::_val, OBJECT_INTERSECTION)];

            oUnions = oIntersections[phx::bind(&push_objects, sprt::_val, sprt::_1)]
                    >> *(oIElems[phx::bind(&push_objects, sprt::_val, sprt::_1)]);


            oEElems %= (qi::omit[EXCEPT_ ]
                    >> oExclusions)[phx::bind(&objectsetpush_object, sprt::_val, OBJECT_EXCEPT)];

            oIntersections = oExclusions[phx::bind(&push_objects, sprt::_val, sprt::_1)]
                    >> *(oEElems[phx::bind(&push_objects, sprt::_val, sprt::_1)]);


            oAElems %= (qi::omit[ALL_ >> (+qi::space) >> EXCEPT_]
                    >> oExclusions)[phx::bind(&objectsetpush_object, sprt::_val, OBJECT_ALLEXCEPT)];

            oExclusions
                    = oElement
                    | qi::omit[qi::lit("(")]
                    >> oElementSetSpec
                    >> qi::omit[ qi::lit(")")]
                    | oAElems
                    ;

            oExtention = qi::lit("...")[sprt::_val = OBJECT_EXTENTION];

            oElement = oObjectSetFromObject | oObjectSetFromObjects | oDefinedObjectSet | Object;




        }

    }
}