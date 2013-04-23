//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/x680.hpp>

namespace x680 {
    namespace bnf {


        str_rule comment_beg = qi::char_("-") >> qi::char_("-");

        str_rule comment_end = comment_beg | qi::eol;

        str_rule pos_number_str = qi::char_("0")[ qi::_val = qi::_1 ]
                | (qi::char_("1-9")[ qi::_val = qi::_1]
                >> *(qi::char_("0-9")[ qi::_val += qi::_1]));


        str_rule number_str = (qi::string("-")[ qi::_val = qi::_1 ]
                >> qi::omit[*qi::blank]
                >> pos_number_str[ qi::_val += qi::_1 ])
        | pos_number_str[ qi::_val = qi::_1 ];

        str_rule curly_barket_pair = qi::char_("{")[ qi::_val = qi::_1 ]
                >> *qi::blank
                >> qi::char_("}")[ qi::_val += qi::_1];

        skip_comment_grammar<std::string::iterator> comment_skip;

        term_rule ECODED_ = qi::lit("ECODED");
        term_rule INTERSECTION_ = qi::lit("ECODED");
        term_rule SEQUENCE_ = qi::lit("SEQUENCE");
        term_rule ABSTRACT_SYNTAX_ = qi::lit("ABSTRACT-SYNTAX");
        term_rule ENCODING_CONTROL_ = qi::lit("ENCODING-CONTROL");
        term_rule ISO646String_ = qi::lit("ISO646String");
        term_rule SET_ = qi::lit("SET");
        term_rule ALL_ = qi::lit("ALL");
        term_rule END_ = qi::lit("END");
        term_rule MAX_ = qi::lit("MAX");
        term_rule SETTINGS_ = qi::lit("SETTINGS");
        term_rule APPLICATION_ = qi::lit("APPLICATION");
        term_rule ENUMERATED_ = qi::lit("ENUMERATED");
        term_rule MIN_ = qi::lit("MIN");
        term_rule SIZE_ = qi::lit("SIZE");
        term_rule AUTOMATIC_ = qi::lit("AUTOMATIC");
        term_rule EXCEPT_ = qi::lit("EXCEPT");
        term_rule MINUS_INFINITY_ = qi::lit("MINUS-INFINITY ");
        term_rule STRING_ = qi::lit("STRING");
        term_rule BEGIN_ = qi::lit("BEGIN");
        term_rule EXPLICIT_ = qi::lit("EXPLICIT");
        term_rule NOT_A_NUMBER_ = qi::lit("NOT-A-NUMBER");
        term_rule SYNTAX_ = qi::lit("SYNTAX");
        term_rule BIT_ = qi::lit("BIT");
        term_rule EXPORTS_ = qi::lit("EXPORTS");
        term_rule NULL_ = qi::lit("NULL");
        term_rule T61String_ = qi::lit("T61String");
        term_rule BMPString_ = qi::lit("BMPString");
        term_rule EXTENSIBILITY_ = qi::lit("EXTENSIBILITY");
        term_rule NumericString_ = qi::lit("NumericString");
        term_rule TAGS_ = qi::lit("TAGS");
        term_rule BOOLEAN_ = qi::lit("BOOLEAN");
        term_rule EXTERNAL_ = qi::lit("EXTERNAL ");
        term_rule OBJECT_ = qi::lit("OBJECT");
        term_rule TeletexString_ = qi::lit("TeletexString");
        term_rule BY_ = qi::lit("BY ");
        term_rule FALSE_ = qi::lit("FALSE");
        term_rule ObjectDescriptor_ = qi::lit("ObjectDescriptor");
        term_rule TIME_ = qi::lit("TIME");
        term_rule CHARACTER_ = qi::lit("CHARACTER");
        term_rule FROM_ = qi::lit("FROM");
        term_rule OCTET_ = qi::lit("OCTET");
        term_rule TIME_OF_DAY_ = qi::lit("TIME-OF-DAY");
        term_rule CHOICE_ = qi::lit("CHOICE");
        term_rule GeneralizedTime_ = qi::lit("GeneralizedTime");
        term_rule OF_ = qi::lit("OF");
        term_rule TRUE_ = qi::lit("TRUE");
        term_rule CLASS_ = qi::lit("CLASS");
        term_rule GeneralString_ = qi::lit("GeneralString");
        term_rule OID_IRI_ = qi::lit("OID-IRI");
        term_rule TYPE_IDENTIFIER_ = qi::lit("TYPE-IDENTIFIER");
        term_rule COMPONENT_ = qi::lit("COMPONENT");
        term_rule GraphicString_ = qi::lit("GraphicString");
        term_rule OPTIONAL_ = qi::lit("OPTIONAL");
        term_rule UNION_ = qi::lit("UNION");
        term_rule COMPONENTS_ = qi::lit("COMPONENTS");
        term_rule IA5String_ = qi::lit("IA5String");
        term_rule PATTERN_ = qi::lit("PATTERN");
        term_rule UNIQUE_ = qi::lit("UNIQUE");
        term_rule CONSTRAINED_ = qi::lit("CONSTRAINED");
        term_rule IDENTIFIER_ = qi::lit("IDENTIFIER");
        term_rule PDV_ = qi::lit("PDV");
        term_rule UNIVERSAL_ = qi::lit("UNIVERSAL");
        term_rule CONTAINING_ = qi::lit("");
        term_rule IMPLICIT_ = qi::lit("IMPLICIT");
        term_rule PLUS_INFINITY_ = qi::lit("PLUS-INFINITY");
        term_rule UniversalString_ = qi::lit("UniversalString");
        term_rule DATE_ = qi::lit("DATE");
        term_rule IMPLIED_ = qi::lit("IMPLIED");
        term_rule PRESENT_ = qi::lit("PRESENT");
        term_rule UTCTime_ = qi::lit("UTCTime");
        term_rule DATE_TIME_ = qi::lit("DATE-TIME");
        term_rule IMPORTS_ = qi::lit("IMPORTS");
        term_rule PrintableString_ = qi::lit("PrintableString");
        term_rule UTF8String_ = qi::lit("UTF8String");
        term_rule DEFAULT_ = qi::lit("DEFAULT");
        term_rule INCLUDES_ = qi::lit("INCLUDES");
        term_rule PRIVATE_ = qi::lit("PRIVATE");
        term_rule VideotexString_ = qi::lit("VideotexString");
        term_rule DEFINITIONS_ = qi::lit("DEFINITIONS");
        term_rule INSTANCE_ = qi::lit("INSTANCE");
        term_rule REAL_ = qi::lit("REAL");
        term_rule VisibleString_ = qi::lit("VisibleString");
        term_rule DURATION_ = qi::lit("DURATION");
        term_rule INSTRUCTIONS_ = qi::lit("INSTRUCTIONS");
        term_rule RELATIVE_OID_ = qi::lit("RELATIVE-OID");
        term_rule WITH_ = qi::lit("WITH");
        term_rule EMBEDDED_ = qi::lit("EMBEDDED");
        term_rule INTEGER_ = qi::lit("INTEGER");
        term_rule RELATIVE_OID_IRI_ = qi::lit("RELATIVE-OID-IRI");
        term_rule EXTENSIBILITY_IMPLIED_ = qi::lit("EXTENSIBILITY IMPLIED");



        str_rule typereference_ = qi::lexeme[qi::upper[ _val = qi::_1 ]
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

        str_rule modulereference_ = typereference_;

        str_rule objectreference_ = typereference_;

        str_rule objectsetreference_ = valuereference_;

        str_rule objectclassreference_ = qi::lexeme[qi::upper[ _val = qi::_1 ]
                >> *(((qi::char_("-")[ _val += qi::_1]
                >> qi::char_("A-Z0-9")[ _val += qi::_1])
                | (qi::char_("A-Z0-9")[ _val += qi::_1]
                >> -qi::char_("A-Z0-9")[ _val += qi::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::char_("A-Z0-9")))))]; //(~typereference_)          

        str_rule comment_ = comment_beg
                >> *((qi::print)[ _val += qi::_1] - comment_end)
        >> comment_end;

        str_rule Externalvaluereference_ = modulereference_
                >> qi::lit(".")
        >> valuereference_;

        str_rule DefinedValue_ = Externalvaluereference_ | valuereference_; //| ParameterizedValue


        unum_rule number = qi::uint_;

        unum_rule bstring = qi::char_("'")
        >> qi::bin[ qi::_val = qi::_1]
                >> qi::char_("'")
        >> qi::char_("H");

        unum_rule hstring = qi::char_("'")
        >> qi::hex[qi::_val = qi::_1]
                >> qi::char_("'")
        >> qi::char_("H");

        str_rule cstring = qi::char_("\"")
        >> *((qi::print)[ qi::_val += qi::_1] - qi::char_("\""))
        >> qi::char_("\"");

        str_rule Reference_ = typereference_[ qi::_val = qi::_1] | valuereference_[ qi::_val = qi::_1];

        str_rule ParameterizedReference_ = Reference_[ qi::_val = qi::_1]
                >> qi::omit[*qi::space]
                >> curly_barket_pair[ qi::_val += qi::_1];

        str_rule Symbol_ = ParameterizedReference_[ qi::_val = qi::_1] | Reference_[ qi::_val = qi::_1];

        strvect_sk_rule SymbolList_ = qi::lexeme[Symbol_] % qi::omit[qi::lexeme[ lit(",")]];

        strvect_sk_rule Exports_ = qi::lexeme[ qi::omit[EXPORTS_ >> +qi::space] ]
                >> -(!qi::lit(";")
                >> (qi::omit[ALL_] | SymbolList_))
        >> qi::omit[qi::lit(";")];


        SymbolsFromModule_grammar<std::string::iterator> SymbolsFromModule_;

        imports_sk_rule SymbolsFromModules_ = *SymbolsFromModule_;

        imports_sk_rule Imports_ = qi::lexeme[ qi::omit[IMPORTS_ >> +qi::space] ]
                >> -(!qi::lit(";")
                >> (SymbolsFromModules_))
        >> qi::omit[qi::lit(";")];



        objNameId_grammar<std::string::iterator> ObjIdComponents_;

        ObjectIdentifierValue_grammar< std::string::iterator> ObjectIdentifierValue_;


    }
}