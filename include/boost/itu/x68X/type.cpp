//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/type.hpp>

namespace x680 {
    namespace bnf {
        
        
        // Type_grammar

        void Type_grammar::init() {
            
             start_rule = Type[bind(&self_type::typeset, *this, qi::_val, qi::_1)];  

            NamedType = identifier_[bind(&self_type::identifier, *this, qi::_val, qi::_1)]
                    >> Type[bind(&self_type::type, *this, qi::_val, qi::_1)];

            DefinedType = DefinedType_[bind(&self_type::refference, *this, qi::_val, qi::_1)];

            ReferencedType = DefinedType;

            SimpleType = ((qi::lexeme[OCTET_ >> +qi::blank >> STRING_])[bind(&self_type::defftype, *this, qi::_val, t_OCTET_STRING)]
                    | (qi::lexeme[CHARACTER_ >> +qi::blank >> STRING_])[bind(&self_type::defftype, *this, qi::_val, t_CHARACTER_STRING)]
                    | (qi::lexeme[EMBEDDED_ >> +qi::blank >> PDV_])[bind(&self_type::defftype, *this, qi::_val, t_EMBEDDED_PDV)]
                    | (qi::lexeme[OBJECT_ >> +qi::blank >> IDENTIFIER_])[bind(&self_type::defftype, *this, qi::_val, t_OBJECT_IDENTIFIER)]
                    | (qi::lexeme[DATE_ >> +qi::blank >> TIME_])[bind(&self_type::defftype, *this, qi::_val, t_DATE_TIME)]
                    | simple_typer[bind(&self_type::defftype, *this, qi::_val, qi::_1)]
                    );

            IntegerType = INTEGER_[bind(&self_type::defftype, *this, qi::_val, t_INTEGER)]
                    >> -NamedNumberList[bind(&self_type::deffinit, *this, qi::_val, qi::_1)];

            EnumeratedType = ENUMERATED_[bind(&self_type::defftype, *this, qi::_val, t_ENUMERATED)]
                    >> -Enumerations[bind(&self_type::deffinit, *this, qi::_val, qi::_1)];

            BitStringType = qi::lexeme[BIT_ >> +qi::blank >> STRING_[bind(&self_type::defftype, *this, qi::_val, t_BIT_STRING)]]
                    >> -NameBitList[bind(&self_type::deffinit, *this, qi::_val, qi::_1)];
            
                       
            SequenceOfType = (qi::lexeme[SEQUENCE_ >> +qi::blank >> OF_])[bind(&self_type::defftype, *this, qi::_val, t_SEQUENCE_OF)]
                    >> (Type | NamedType)[bind(&self_type::push_component,*this, qi::_val, qi::_1) ];                   

            SetOfType = (qi::lexeme[SET_ >> +qi::blank >> OF_])[bind(&self_type::defftype, *this, qi::_val, t_SET_OF)]
                    >> (Type | NamedType)[bind(&self_type::push_component,*this, qi::_val, qi::_1) ];    
                   
                    
                    
                    
                    

           
         //    
            

            ComponentType%=((qi::omit[qi::lexeme[COMPONENTS_ >> +qi::blank >> OF_]] >> Type)[bind(&type_assigment::operator(), qi::_val, mk_components_of )]                        
                    | (NamedType >> qi::omit[OPTIONAL_])[bind(&type_assigment::operator(), qi::_val, mk_optional )]                          
                    | ((NamedType >> qi::omit[DEFAULT_])[bind(&type_assigment::operator(), qi::_val, mk_default )] >> qi::omit[Value[bind(&type_assigment::defaultvalue , qi::_val,  qi::_1)]])    
                    | NamedType); 
            
           ComponentTypeList = (ComponentType % qi::omit[qi::lit(",")]); 
           
           RootComponentTypeList = ComponentTypeList;
           
           ExtensionAdditionGroup = qi::omit[qi::lit("[[") >> -(pos_number_str >> qi::lit(":"))] >> ComponentTypeList  >> qi::omit[qi::lit("]]")];
           
           ExtensionAddition = qi::omit[qi::lit(",")] >> (ExtensionAdditionGroup | ComponentType);
           
           ExtensionAdditions =  ExtensionAddition >>  - (  ExtensionAddition) ;
             
            ExceptionSpec = qi::lit("!") >> (pos_number_str | DefinedValue_);// (| SignedNumber |Type ":" Value);                
                    
            ExtensionAndException =  (qi::lit("...")[qi::_val =  exception_type_assigment ]   >> qi::omit[ExceptionSpec]) |   qi::lit("...")[qi::_val =  extention_type_assigment ] ;
            
            ExtensionEndMarker = qi::omit[qi::lit(",")] >> qi::lit("...")[qi::_val =  extention_type_assigment ];
            
            OptionalExtensionMarker = - ( qi::omit[qi::lit(",")] >> qi::lit("...")[qi::_val =  extention_type_assigment ]);
            
            
            ComponentTypeLists = (RootComponentTypeList 
                   >>  qi::lit(",") 
                   >>  ExtensionAndException 
                   >>  ExtensionAdditions 
                   >> OptionalExtensionMarker)
                   | (RootComponentTypeList  
                   >> qi::lit(",") 
                   >> ExtensionAndException 
                   >> ExtensionAdditions  
                   >>  ExtensionEndMarker
                   >> qi::lit(",")  
                   >> RootComponentTypeList)
                   | (ExtensionAndException 
                   >> ExtensionAdditions  
                   >>  ExtensionEndMarker
                   >> qi::lit(",")  
                   >>  RootComponentTypeList) 
                   | (ExtensionAndException 
                   >> ExtensionAdditions 
                   >> OptionalExtensionMarker)
                  | RootComponentTypeList;        
            
           
            
            
            SelectionType =identifier_[bind(&self_type::identifier, *this, qi::_val, qi::_1)]
                    >> qi::lit("<")
                    >> Type[bind(&self_type::type_select, *this, qi::_val, qi::_1)];
            
            
            SequenceType = SEQUENCE_[bind(&self_type::defftype, *this, qi::_val, t_SEQUENCE)]
                    >>  qi::lit("{")
                    >> -(ComponentTypeLists [bind(&self_type::push_components,*this, qi::_val, qi::_1) ])    
                    >>  qi::lit("}");            

            
            SetType = SET_[bind(&self_type::defftype, *this, qi::_val, t_SET)] 
                    >>  qi::lit("{")
                    >> -(ComponentTypeLists [bind(&self_type::push_components,*this, qi::_val, qi::_1) ])
                    >>  qi::lit("}");   
            
            ChoiceType = CHOICE_[bind(&self_type::defftype, *this, qi::_val, t_CHOICE)] 
                    >>  qi::lit("{")
                    >> -(ComponentTypeLists[bind(&self_type::push_components,*this, qi::_val, qi::_1) ])   
                    >>  qi::lit("}");   

            BuitinType = SimpleType | IntegerType | EnumeratedType | BitStringType | SelectionType | SequenceOfType | SetOfType  | SequenceType | ChoiceType | SetType  ;

            Type = BuitinType | TaggedType | DefinedType;
            
            TaggedType = Tag[bind(&self_type::tagset, *this, qi::_val, qi::_1)]
                    >> Type[bind(&self_type::for_taggedtype, *this, qi::_val, qi::_1)];

        }
        
        
    

        // TypeAssignment_grammar

        void TypeAssignment_grammar::init() {
            
           start_rule = typereference_[bind(&self_type::typereffrence, *this, qi::_val, qi::_1)]
                    >> qi::lexeme[qi::lit("::=")]
                    >> Type[bind(&self_type::type, *this, qi::_val, qi::_1)];  
        }
        
        
        
        // ValueAssignment_grammar

        void ValueAssignment_grammar::init() {
            
           start_rule = valuereference_[bind(&self_type::valuereference, *this, qi::_val, qi::_1)]
                   >> Type[bind(&self_type::type, *this, qi::_val, qi::_1)]
                    >> qi::lexeme[qi::lit("::=")]
                    >> Value[bind(&self_type::value, *this, qi::_val, qi::_1)];  
        }
        
    }
}