//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/x680.hpp>

namespace x680 {
    namespace bnf {



        str_rule pos_number_str = qi::char_("0")[ qi::_val = qi::_1 ]
                | (qi::char_("1-9")[ qi::_val = qi::_1]
                >> *(qi::char_("0-9")[ qi::_val += qi::_1]));


        str_rule number_str = (qi::string("-")[ qi::_val = qi::_1 ]
                >> qi::omit[*qi::blank]
                >> pos_number_str[ qi::_val += qi::_1 ])
        | pos_number_str[ qi::_val = qi::_1 ];

        str_rule realnumber_str = number_str[ qi::_val = qi::_1 ]
                >> (qi::string(".")[ qi::_val += qi::_1 ] >> number_str[ qi::_val += qi::_1 ]);

        str_rule bstring_str = qi::omit[qi::char_("'")]
        >> *(qi::char_("0-1")[ qi::_val += qi::_1] | qi::omit[qi::space])
        >> qi::omit[ qi::char_("'")
        >> qi::char_("B")];

        str_rule hstring_str = qi::omit[qi::char_("'")]
        >> *(qi::char_("0-9ABCDEF")[ qi::_val += qi::_1] | qi::omit[qi::space])
        >> qi::omit[ qi::char_("'")
        >> qi::char_("H")];

        str_rule cstring_str = qi::char_("\"")
        >> *((qi::print)[ qi::_val += qi::_1] - qi::char_("\""))
        >> qi::char_("\"");



        str_rule curly_barket_pair = qi::char_("{")[ qi::_val = qi::_1 ]
                >> *qi::blank
                >> qi::char_("}")[ qi::_val += qi::_1];

        skip_comment_grammar comment_skip;

        term_rule ECODED_ = distinct(qi::alnum | '-')["ECODED"];
        term_rule INTERSECTION_ = distinct(qi::alnum | '-')["ECODED"];
        term_rule SEQUENCE_ = distinct(qi::alnum | '-')["SEQUENCE"];
        term_rule ABSTRACT_SYNTAX_ = distinct(qi::alnum | '-')["ABSTRACT-SYNTAX"];
        term_rule ABSENT_ = distinct(qi::alnum | '-')["ABSENT"];
        term_rule ENCODING_CONTROL_ = distinct(qi::alnum | '-')["ENCODING-CONTROL"];
        term_rule ISO646String_ = distinct(qi::alnum | '-')["ISO646String"];
        term_rule SET_ = distinct(qi::alnum | '-')["SET"];
        term_rule ALL_ = distinct(qi::alnum | '-')["ALL"];
        term_rule END_ = distinct(qi::alnum | '-')["END"];
        term_rule MAX_ = distinct(qi::alnum | '-')["MAX"];
        term_rule SETTINGS_ = distinct(qi::alnum | '-')["SETTINGS"];
        term_rule APPLICATION_ = distinct(qi::alnum | '-')["APPLICATION"];
        term_rule ENUMERATED_ = distinct(qi::alnum | '-')["ENUMERATED"];
        term_rule MIN_ = distinct(qi::alnum | '-')["MIN"];
        term_rule SIZE_ = distinct(qi::alnum | '-')["SIZE"];
        term_rule AUTOMATIC_ = distinct(qi::alnum | '-')["AUTOMATIC"];
        term_rule EXCEPT_ = distinct(qi::alnum | '-')["EXCEPT"];
        term_rule ENCODED_ = distinct(qi::alnum | '-')["ENCODED"];
        ;
        term_rule MINUS_INFINITY_ = distinct(qi::alnum | '-')["MINUS-INFINITY"];
        term_rule STRING_ = distinct(qi::alnum | '-')["STRING"];
        term_rule BEGIN_ = distinct(qi::alnum | '-')["BEGIN"];
        term_rule EXPLICIT_ = distinct(qi::alnum | '-')["EXPLICIT"];
        term_rule NOT_A_NUMBER_ = distinct(qi::alnum | '-')["NOT-A-NUMBER"];
        term_rule SYNTAX_ = distinct(qi::alnum | '-')["SYNTAX"];
        term_rule BIT_ = distinct(qi::alnum | '-')["BIT"];
        term_rule EXPORTS_ = distinct(qi::alnum | '-')["EXPORTS"];
        term_rule NULL_ = distinct(qi::alnum | '-')["NULL"];
        term_rule T61String_ = distinct(qi::alnum | '-')["T61String"];
        term_rule BMPString_ = distinct(qi::alnum | '-')["BMPString"];
        term_rule EXTENSIBILITY_ = distinct(qi::alnum | '-')["EXTENSIBILITY"];
        term_rule NumericString_ = distinct(qi::alnum | '-')["NumericString"];
        term_rule TAGS_ = distinct(qi::alnum | '-')["TAGS"];
        term_rule BOOLEAN_ = distinct(qi::alnum | '-')["BOOLEAN"];
        term_rule EXTERNAL_ = distinct(qi::alnum | '-')["EXTERNAL "];
        term_rule OBJECT_ = distinct(qi::alnum | '-')["OBJECT"];
        term_rule TeletexString_ = distinct(qi::alnum | '-')["TeletexString"];
        term_rule BY_ = distinct(qi::alnum | '-')["BY "];
        term_rule FALSE_ = distinct(qi::alnum | '-')["FALSE"];
        term_rule ObjectDescriptor_ = distinct(qi::alnum | '-')["ObjectDescriptor"];
        term_rule TIME_ = distinct(qi::alnum | '-')["TIME"];
        term_rule CHARACTER_ = distinct(qi::alnum | '-')["CHARACTER"];
        term_rule FROM_ = distinct(qi::alnum | '-')["FROM"];
        term_rule OCTET_ = distinct(qi::alnum | '-')["OCTET"];
        term_rule TIME_OF_DAY_ = distinct(qi::alnum | '-')["TIME-OF-DAY"];
        term_rule CHOICE_ = distinct(qi::alnum | '-')["CHOICE"];
        term_rule GeneralizedTime_ = distinct(qi::alnum | '-')["GeneralizedTime"];
        term_rule OF_ = distinct(qi::alnum | '-')["OF"];
        term_rule TRUE_ = distinct(qi::alnum | '-')["TRUE"];
        term_rule CLASS_ = distinct(qi::alnum | '-')["CLASS"];
        term_rule GeneralString_ = distinct(qi::alnum | '-')["GeneralString"];
        term_rule OID_IRI_ = distinct(qi::alnum | '-')["OID-IRI"];
        term_rule TYPE_IDENTIFIER_ = distinct(qi::alnum | '-')["TYPE-IDENTIFIER"];
        term_rule COMPONENT_ = distinct(qi::alnum | '-')["COMPONENT"];
        term_rule GraphicString_ = distinct(qi::alnum | '-')["GraphicString"];
        term_rule OPTIONAL_ = distinct(qi::alnum | '-')["OPTIONAL"];
        term_rule UNION_ = distinct(qi::alnum | '-')["UNION"];
        term_rule COMPONENTS_ = distinct(qi::alnum | '-')["COMPONENTS"];
        term_rule IA5String_ = distinct(qi::alnum | '-')["IA5String"];
        term_rule PATTERN_ = distinct(qi::alnum | '-')["PATTERN"];
        term_rule UNIQUE_ = distinct(qi::alnum | '-')["UNIQUE"];
        term_rule CONSTRAINED_ = distinct(qi::alnum | '-')["CONSTRAINED"];
        term_rule IDENTIFIER_ = distinct(qi::alnum | '-')["IDENTIFIER"];
        term_rule PDV_ = distinct(qi::alnum | '-')["PDV"];
        term_rule UNIVERSAL_ = distinct(qi::alnum | '-')["UNIVERSAL"];
        term_rule CONTAINING_ = distinct(qi::alnum | '-')["CONTAINING"];
        term_rule IMPLICIT_ = distinct(qi::alnum | '-')["IMPLICIT"];
        term_rule PLUS_INFINITY_ = distinct(qi::alnum | '-')["PLUS-INFINITY"];
        term_rule UniversalString_ = distinct(qi::alnum | '-')["UniversalString"];
        term_rule DATE_ = distinct(qi::alnum | '-')["DATE"];
        term_rule IMPLIED_ = distinct(qi::alnum | '-')["IMPLIED"];
        term_rule PRESENT_ = distinct(qi::alnum | '-')["PRESENT"];
        term_rule UTCTime_ = distinct(qi::alnum | '-')["UTCTime"];
        term_rule DATE_TIME_ = distinct(qi::alnum | '-')["DATE-TIME"];
        term_rule IMPORTS_ = distinct(qi::alnum | '-')["IMPORTS"];
        term_rule PrintableString_ = distinct(qi::alnum | '-')["PrintableString"];
        term_rule UTF8String_ = distinct(qi::alnum | '-')["UTF8String"];
        term_rule DEFAULT_ = distinct(qi::alnum | '-')["DEFAULT"];
        term_rule INCLUDES_ = distinct(qi::alnum | '-')["INCLUDES"];
        term_rule PRIVATE_ = distinct(qi::alnum | '-')["PRIVATE"];
        term_rule VideotexString_ = distinct(qi::alnum | '-')["VideotexString"];
        term_rule DEFINITIONS_ = distinct(qi::alnum | '-')["DEFINITIONS"];
        term_rule INSTANCE_ = distinct(qi::alnum | '-')["INSTANCE"];
        term_rule REAL_ = distinct(qi::alnum | '-')["REAL"];
        term_rule VisibleString_ = distinct(qi::alnum | '-')["VisibleString"];
        term_rule DURATION_ = distinct(qi::alnum | '-')["DURATION"];
        term_rule INSTRUCTIONS_ = distinct(qi::alnum | '-')["INSTRUCTIONS"];
        term_rule RELATIVE_OID_ = distinct(qi::alnum | '-')["RELATIVE-OID"];
        term_rule WITH_ = distinct(qi::alnum | '-')["WITH"];
        term_rule EMBEDDED_ = distinct(qi::alnum | '-')["EMBEDDED"];
        term_rule INTEGER_ = distinct(qi::alnum | '-')["INTEGER"];
        term_rule RELATIVE_OID_IRI_ = distinct(qi::alnum | '-')["RELATIVE-OID-IRI"];


        str_rule literal_except_token = distinct(qi::alnum | '-')[qi::string("BIT")]
        | distinct(qi::alnum | '-')[qi::string("BOOLEAN")]
        | distinct(qi::alnum | '-')[qi::string("CHARACTER")]
        | distinct(qi::alnum | '-')[qi::string("CHOICE")]
        | distinct(qi::alnum | '-')[qi::string("DATE")]
        | distinct(qi::alnum | '-')[qi::string("DATE-TIME")]
        | distinct(qi::alnum | '-')[qi::string("DURATION")]
        | distinct(qi::alnum | '-')[qi::string("EMBEDDED")]
        | distinct(qi::alnum | '-')[qi::string("END")]
        | distinct(qi::alnum | '-')[qi::string("ENUMERATED")]
        | distinct(qi::alnum | '-')[qi::string("EXTERNAL")]
        | distinct(qi::alnum | '-')[qi::string("FALSE")]
        | distinct(qi::alnum | '-')[qi::string("INSTANCE")]
        | distinct(qi::alnum | '-')[qi::string("INTEGER")]
        | distinct(qi::alnum | '-')[qi::string("INTERSECTION")]
        | distinct(qi::alnum | '-')[qi::string("MINUS-INFINITY")]
        | distinct(qi::alnum | '-')[qi::string("NULL")]
        | distinct(qi::alnum | '-')[qi::string("OBJECT")]
        | distinct(qi::alnum | '-')[qi::string("OCTET")]
        | distinct(qi::alnum | '-')[qi::string("PLUS-INFINITY")]
        | distinct(qi::alnum | '-')[qi::string("REAL")]
        | distinct(qi::alnum | '-')[qi::string("RELATIVE-OID")]
        | distinct(qi::alnum | '-')[qi::string("SEQUENCE")]
        | distinct(qi::alnum | '-')[qi::string("SET")]
        | distinct(qi::alnum | '-')[qi::string("TIME")]
        | distinct(qi::alnum | '-')[qi::string("TIME-OF-DAY")]
        | distinct(qi::alnum | '-')[qi::string("TRUE")]
        | distinct(qi::alnum | '-')[qi::string("UNION")];


        str_rule word_ = qi::lexeme[qi::upper[ qi::_val = qi::_1 ]
                >> *(((qi::char_("-")[ _val += qi::_1]
                >> qi::upper[ _val += qi::_1])
                | (qi::upper[ _val += qi::_1]
                >> -qi::upper[ _val += qi::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::upper))))];

        str_rule spaces_ = qi::space[ qi::_val = qi::_1 ] >> *(qi::space[qi::_val += qi::_1 ]);

        str_rule Literal_ = (word_ - literal_except_token) | qi::string(",");

        str_rule SyntaxField_ = Literal_[qi::_val = qi::_1 ] >> *(spaces_[ qi::_val += qi::_1 ] >> Literal_[ qi::_val += qi::_1 ]);

        str_rule typereference_ = qi::lexeme[qi::upper[ qi::_val = qi::_1 ]
                >> *(((qi::char_("-")[ _val += qi::_1]
                >> qi::alnum[ _val += qi::_1])
                | (qi::alnum[ _val += qi::_1]
                >> -qi::alnum[ _val += qi::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::alnum))))];

        str_rule identifier_ = qi::lexeme[qi::lower[ _val = qi::_1 ]
                >> *(((qi::char_("-")[ _val += qi::_1]
                >> qi::alnum[ _val += qi::_1])
                | (qi::alnum[ _val += qi::_1]
                >> -qi::alnum[ _val += qi::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::alnum))))];

        str_rule valuereference_ = identifier_;

        str_rule valuesetreference_ = typereference_;

        str_rule modulereference_ = typereference_;

        str_rule objectreference_ = valuereference_;

        str_rule objectsetreference_ = typereference_;

        str_rule objectclassreference_ = qi::lexeme[qi::upper[ _val = qi::_1 ]
                >> *(((qi::char_("-")[ _val += qi::_1]
                >> qi::char_("A-Z0-9")[ _val += qi::_1])
                | (qi::char_("A-Z0-9")[ _val += qi::_1]
                >> -qi::char_("A-Z0-9")[ _val += qi::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::char_("A-Z0-9")))))]; //(~typereference_)        

        str_rule typefieldreference_ = qi::lexeme[qi::string("&")[qi::_val = qi::_1 ] >> typereference_[qi::_val += qi::_1]]; //(&typereference_)   

        str_rule valuefieldreference_ = qi::lexeme[qi::string("&")[qi::_val = qi::_1 ] >> valuereference_[qi::_val += qi::_1]]; //(&valuereference_)  

        str_rule valuesetfieldreference_ = qi::lexeme[qi::string("&")[qi::_val = qi::_1 ] >> typereference_[qi::_val += qi::_1]]; //(&typereference_)   

        str_rule objectfieldreference_ = qi::lexeme[qi::string("&")[qi::_val = qi::_1 ] >> objectreference_[qi::_val += qi::_1]]; //(&objectreference_)

        str_rule objectsetfieldreference_ = qi::lexeme[qi::string("&")[qi::_val = qi::_1 ] >> objectsetreference_[qi::_val += qi::_1]]; //(&objectsetreference_)  


        str_rule bigreference_ = typereference_;

        str_rule littlereference_ = valuereference_;
        
        str_rule bothreference_ = bigreference_ | littlereference_;

        str_rule bigfieldreference_ = typefieldreference_;

        str_rule littlefieldreference_ = valuefieldreference_;

        str_rule PrimitiveFieldName_ = bigfieldreference_ | littlefieldreference_;

        str_rule FieldName_ = PrimitiveFieldName_[qi::_val = qi::_1] >> -(qi::string(".")[qi::_val += qi::_1] >> (PrimitiveFieldName_[qi::_val += qi::_1] % qi::string(".")[qi::_val += qi::_1]));

        str_rule ExternalTypeReference_ = modulereference_[qi::_val = qi::_1 ]
                >> qi::string(".")[qi::_val += qi::_1]
                >> typereference_[qi::_val += qi::_1];

        str_rule DefinedType_ = ExternalTypeReference_ | typereference_; //| ParameterizedType | ParameterizedValueSetType


        str_rule ExternalValueReference_ = modulereference_[qi::_val = qi::_1 ]
                >> qi::string(".")[qi::_val += qi::_1]
                >> valuereference_[qi::_val += qi::_1];

        str_rule ExternalValueSetReference_ = modulereference_[qi::_val = qi::_1 ]
                >> qi::string(".")[qi::_val += qi::_1]
                >> valuesetreference_[qi::_val += qi::_1];

        str_rule ExternalObjectClassReference_ = modulereference_[qi::_val = qi::_1 ]
                >> qi::string(".")[qi::_val += qi::_1]
                >> objectclassreference_[qi::_val += qi::_1];

        str_rule ExternalObjectReference_ = modulereference_[qi::_val = qi::_1 ]
                >> qi::string(".")[qi::_val += qi::_1]
                >> objectreference_[qi::_val += qi::_1];

        str_rule ExternalObjectSetReference_ = modulereference_[qi::_val = qi::_1 ]
                >> qi::string(".")[qi::_val += qi::_1]
                >> objectsetreference_[qi::_val += qi::_1];



        str_rule DefinedObjectClass_ = ExternalObjectClassReference_
                | TYPE_IDENTIFIER_
                | ABSTRACT_SYNTAX_
                | objectclassreference_;
        

        str_rule DefinedValue_ = ExternalValueReference_ | valuereference_; //| ParameterizedValue        

        str_rule DefinedValueSet_ = ExternalValueSetReference_ | valuesetreference_; //| ParameterizedValue          

        str_rule DefinedObject_ = ExternalObjectReference_ | objectreference_;

        str_rule DefinedObjectSet_ = ExternalObjectSetReference_ | objectsetreference_;

        str_rule UserDefinedConstraintParameter_ = (DefinedType_[qi::_val = qi::_1 ] | DefinedObjectClass_[qi::_val = qi::_1 ]) >> -(qi::string(".")[qi::_val += qi::_1] >> DefinedValue_[qi::_val += qi::_1]);

        str_rule AtNotation_ = qi::string("@")[qi::_val = qi::_1 ] >> *(qi::string(".")[qi::_val += qi::_1]) >> (identifier_[qi::_val += qi::_1] % qi::string(".")[qi::_val += qi::_1]);

        str_rule Reference_ = typereference_ | valuereference_;
        
        str_rule ObjectClassFieldType_ = DefinedObjectClass_[qi::_val = qi::_1 ] >> qi::string(".")[qi::_val += qi::_1] >> FieldName_[qi::_val += qi::_1];     
        
        str_rule SimpleTypeFromObject_ = DefinedObject_[qi::_val = qi::_1 ] >> qi::string(".")[qi::_val += qi::_1] >> FieldName_[qi::_val += qi::_1];;
        
        str_rule SimpleValueSetFromObjects_ = DefinedObjectSet_[qi::_val = qi::_1 ] >> qi::string(".")[qi::_val += qi::_1] >> FieldName_[qi::_val += qi::_1];;         

        str_rule ParameterizedReference_ = Reference_[ qi::_val = qi::_1]
                >> qi::omit[*qi::space]
                >> curly_barket_pair[ qi::_val += qi::_1];

        str_rule Symbol_ = ParameterizedReference_[ qi::_val = qi::_1] | Reference_[ qi::_val = qi::_1];

        strvect_sk_rule SymbolList_ = qi::lexeme[Symbol_] % qi::omit[qi::lexeme[ lit(",")]];








    }
}