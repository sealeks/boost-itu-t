//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/x680.hpp>

namespace x680 {
    namespace syntactic {

        position_iterator::position_iterator(const supertype& s) :
        supertype(s), base_(new supertype(s)), pos_(new difference_type(0)) {
        }

        position_iterator&
        position_iterator::operator++() {
            return *this = private_ctr(++super(), base_, pos_);
        }

        position_iterator
        position_iterator::operator++(int a) {
            return private_ctr(super()++, base_, pos_);
        }

        position_iterator&
        position_iterator::operator--() {
            return *this = private_ctr(--super(), base_, pos_);
        }

        position_iterator
        position_iterator::operator--(int a) {
            return private_ctr(super()--, base_, pos_);
        }

#ifdef __GNUC__    

        position_iterator&
                position_iterator::operator+=(const difference_type& n) {
            return *this = private_ctr(super() + n, base_, pos_);
        }

        position_iterator
        position_iterator::operator+(const difference_type& n) const {
            return private_ctr(super(), base_, pos_);
        }

        position_iterator&
                position_iterator::operator-=(const difference_type& n) {
            return *this = private_ctr(super() - n, base_, pos_);
        }

        position_iterator
        position_iterator::operator-(const difference_type& n) const {
            return private_ctr(super(), base_, pos_);
        }

#endif

        position_iterator::supertype&
        position_iterator::super() const {
            return (supertype&) (*this);
        }

        position_iterator::supertype&
        position_iterator::base() const {
            return *base_;
        }

        position_iterator::difference_type
        position_iterator::pos() const {
            return *pos_;
        }

        void position_iterator::checkpos() const {
            if ((super() - base()) > pos())
                *pos_ = super() - base();
        }

        position_iterator position_iterator::private_ctr(const supertype& s, supertypeptr b, differenceptr p) const {
            checkpos();
            position_iterator tmp(s);
            tmp.base_ = b;
            tmp.pos_ = p;
            return tmp;
        }



        ///   synxtas_error  

        synxtas_error::synxtas_error(const std::string& file, const std::string& src, std::size_t ps) :
        filepos_(ps), linepos_(0), linenum_(0), file_(file) {
            linepos_ = build(src, ps, linenum_, line_);
        }

        std::size_t synxtas_error::build(const std::string& src, std::size_t pos, std::size_t& symb, std::string& line) {
            std::size_t rslt = 0;
            symb = 0;
            std::string::size_type it = 0, itl = 0, ita = 0, itd = 0;
            while ((it < pos) && (it != std::string::npos)) {
                itl = it;
                ita = src.find_first_of('\x0a', it);
                itd = src.find_first_of('\x0d', it);
                if ((ita != std::string::npos) && (itd != std::string::npos)) {
                    it = ((ita < itd) || ((ita - itd) == 1)) ? ita : itd;
                } else {
                    if (ita != std::string::npos)
                        it = ita;
                    if (itd != std::string::npos)
                        it = itd;
                    if ((ita == std::string::npos) && (itd == std::string::npos))
                        it = std::string::npos;
                }
                if (((it == std::string::npos) && (pos < src.size())) || (it > pos))
                    it = pos;
                rslt++;
                if (it != std::string::npos) {
                    it++;
                    it = it < src.size() ? it : std::string::npos;
                } else
                    symb = 0;
                line = src.substr(itl, it == std::string::npos ? std::string::npos : (it - itl));
                symb = (it == std::string::npos ? 0 : (it - itl));
            }
            return rslt; // = rslt ? rslt - 1 : rslt;
        }

        std::ostream& operator<<(std::ostream& stream, const synxtas_error& self) {
            stream << "Synxtas error in file: " << self.file() << " pos(" << self.filepos() << ")." << '\n';
            stream << "line: " << self.linepos() << " lpos:" << self.linenum() << "." << '\n';
            stream << "string: '" << self.line() << "'" << '\n';
            return stream;
        }






        str_rule pos_number_str = distinct(qi::alnum | ('-' >> qi::alnum))[qi::char_("0")[ sprt::_val = sprt::_1 ]
                | (qi::char_("1-9")[ sprt::_val = sprt::_1]
                >> *(qi::char_("0-9")[ sprt::_val += sprt::_1]))];


        str_rule number_str = distinct(qi::alnum | ('-' >> qi::alnum))[(qi::string("-")[ sprt::_val = sprt::_1 ]
                >> qi::omit[*qi::blank]
                >> pos_number_str[ sprt::_val += sprt::_1 ])
        | pos_number_str[ sprt::_val = sprt::_1 ]];

        str_rule realnumber_str = distinct(qi::alnum | ('-' >> qi::alnum))[number_str[ sprt::_val = sprt::_1 ]
                >> (qi::string(".")[ sprt::_val += sprt::_1 ] >> number_str[ sprt::_val += sprt::_1 ])];

        str_rule bstring_str = distinct(qi::alnum | ('-' >> qi::alnum))[ qi::omit[qi::char_("'")]
        >> *(qi::char_("0-1")[ sprt::_val += sprt::_1] | qi::omit[qi::space])
        >> qi::omit[ qi::char_("'")
        >> qi::char_("B")]];

        str_rule hstring_str = distinct(qi::alnum | ('-' >> qi::alnum))[ qi::omit[qi::char_("'")]
        >> *(qi::char_("0-9ABCDEF")[ sprt::_val += sprt::_1] | qi::omit[qi::space])
        >> qi::omit[ qi::char_("'")
        >> qi::char_("H")]];

        str_rule cstring_str = distinct(qi::alnum | ('-' >> qi::alnum))[ qi::char_("\"")
        >> *((qi::print)[ sprt::_val += sprt::_1] - qi::char_("\""))
        >> qi::char_("\"")];

        str_rule IRIValue = cstring_str;



        str_rule curly_barket_pair = qi::char_("{")[ sprt::_val = sprt::_1 ]
                >> *qi::space
                >> qi::char_("}")[ sprt::_val += sprt::_1];

        skip_comment_grammar comment_skip;

        term_rule ECODED_ = distinct(qi::alnum | ('-' >> qi::alnum))["ECODED"];
        term_rule INTERSECTION_ = distinct(qi::alnum | ('-' >> qi::alnum))["ECODED"];
        term_rule SEQUENCE_ = distinct(qi::alnum | ('-' >> qi::alnum))["SEQUENCE"];
        term_rule ABSTRACT_SYNTAX_ = distinct(qi::alnum | ('-' >> qi::alnum))["ABSTRACT-SYNTAX"];
        term_rule ABSENT_ = distinct(qi::alnum | ('-' >> qi::alnum))["ABSENT"];
        term_rule ENCODING_CONTROL_ = distinct(qi::alnum | ('-' >> qi::alnum))["ENCODING-CONTROL"];
        term_rule ISO646String_ = distinct(qi::alnum | ('-' >> qi::alnum))["ISO646String"];
        term_rule SET_ = distinct(qi::alnum | ('-' >> qi::alnum))["SET"];
        term_rule ALL_ = distinct(qi::alnum | ('-' >> qi::alnum))["ALL"];
        term_rule END_ = distinct(qi::alnum | ('-' >> qi::alnum))["END"];
        term_rule MAX_ = distinct(qi::alnum | ('-' >> qi::alnum))["MAX"];
        term_rule SETTINGS_ = distinct(qi::alnum | ('-' >> qi::alnum))["SETTINGS"];
        term_rule APPLICATION_ = distinct(qi::alnum | ('-' >> qi::alnum))["APPLICATION"];
        term_rule ENUMERATED_ = distinct(qi::alnum | ('-' >> qi::alnum))["ENUMERATED"];
        term_rule MIN_ = distinct(qi::alnum | ('-' >> qi::alnum))["MIN"];
        term_rule SIZE_ = distinct(qi::alnum | ('-' >> qi::alnum))["SIZE"];
        term_rule AUTOMATIC_ = distinct(qi::alnum | ('-' >> qi::alnum))["AUTOMATIC"];
        term_rule EXCEPT_ = distinct(qi::alnum | ('-' >> qi::alnum))["EXCEPT"];
        term_rule ENCODED_ = distinct(qi::alnum | ('-' >> qi::alnum))["ENCODED"];
        term_rule MINUS_INFINITY_ = distinct(qi::alnum | ('-' >> qi::alnum))["MINUS-INFINITY"];
        term_rule STRING_ = distinct(qi::alnum | ('-' >> qi::alnum))["STRING"];
        term_rule BEGIN_ = distinct(qi::alnum | ('-' >> qi::alnum))["BEGIN"];
        term_rule EXPLICIT_ = distinct(qi::alnum | ('-' >> qi::alnum))["EXPLICIT"];
        term_rule NOT_A_NUMBER_ = distinct(qi::alnum | ('-' >> qi::alnum))["NOT-A-NUMBER"];
        term_rule SYNTAX_ = distinct(qi::alnum | ('-' >> qi::alnum))["SYNTAX"];
        term_rule BIT_ = distinct(qi::alnum | ('-' >> qi::alnum))["BIT"];
        term_rule EXPORTS_ = distinct(qi::alnum | ('-' >> qi::alnum))["EXPORTS"];
        term_rule NULL_ = distinct(qi::alnum | ('-' >> qi::alnum))["NULL"];
        term_rule T61String_ = distinct(qi::alnum | ('-' >> qi::alnum))["T61String"];
        term_rule BMPString_ = distinct(qi::alnum | ('-' >> qi::alnum))["BMPString"];
        term_rule EXTENSIBILITY_ = distinct(qi::alnum | ('-' >> qi::alnum))["EXTENSIBILITY"];
        term_rule NumericString_ = distinct(qi::alnum | ('-' >> qi::alnum))["NumericString"];
        term_rule TAGS_ = distinct(qi::alnum | ('-' >> qi::alnum))["TAGS"];
        term_rule BOOLEAN_ = distinct(qi::alnum | ('-' >> qi::alnum))["BOOLEAN"];
        term_rule EXTERNAL_ = distinct(qi::alnum | ('-' >> qi::alnum))["EXTERNAL "];
        term_rule OBJECT_ = distinct(qi::alnum | ('-' >> qi::alnum))["OBJECT"];
        term_rule TeletexString_ = distinct(qi::alnum | ('-' >> qi::alnum))["TeletexString"];
        term_rule BY_ = distinct(qi::alnum | ('-' >> qi::alnum))["BY"];
        term_rule FALSE_ = distinct(qi::alnum | ('-' >> qi::alnum))["FALSE"];
        term_rule ObjectDescriptor_ = distinct(qi::alnum | ('-' >> qi::alnum))["ObjectDescriptor"];
        term_rule TIME_ = distinct(qi::alnum | ('-' >> qi::alnum))["TIME"];
        term_rule CHARACTER_ = distinct(qi::alnum | ('-' >> qi::alnum))["CHARACTER"];
        term_rule FROM_ = distinct(qi::alnum | ('-' >> qi::alnum))["FROM"];
        term_rule OCTET_ = distinct(qi::alnum | ('-' >> qi::alnum))["OCTET"];
        term_rule TIME_OF_DAY_ = distinct(qi::alnum | ('-' >> qi::alnum))["TIME-OF-DAY"];
        term_rule CHOICE_ = distinct(qi::alnum | ('-' >> qi::alnum))["CHOICE"];
        term_rule GeneralizedTime_ = distinct(qi::alnum | ('-' >> qi::alnum))["GeneralizedTime"];
        term_rule OF_ = distinct(qi::alnum | ('-' >> qi::alnum))["OF"];
        term_rule TRUE_ = distinct(qi::alnum | ('-' >> qi::alnum))["TRUE"];
        term_rule CLASS_ = distinct(qi::alnum | ('-' >> qi::alnum))["CLASS"];
        term_rule GeneralString_ = distinct(qi::alnum | ('-' >> qi::alnum))["GeneralString"];
        term_rule OID_IRI_ = distinct(qi::alnum | ('-' >> qi::alnum))["OID-IRI"];
        term_rule TYPE_IDENTIFIER_ = distinct(qi::alnum | ('-' >> qi::alnum))["TYPE-IDENTIFIER"];
        term_rule COMPONENT_ = distinct(qi::alnum | ('-' >> qi::alnum))["COMPONENT"];
        term_rule GraphicString_ = distinct(qi::alnum | ('-' >> qi::alnum))["GraphicString"];
        term_rule OPTIONAL_ = distinct(qi::alnum | ('-' >> qi::alnum))["OPTIONAL"];
        term_rule UNION_ = distinct(qi::alnum | ('-' >> qi::alnum))["UNION"];
        term_rule COMPONENTS_ = distinct(qi::alnum | ('-' >> qi::alnum))["COMPONENTS"];
        term_rule IA5String_ = distinct(qi::alnum | ('-' >> qi::alnum))["IA5String"];
        term_rule PATTERN_ = distinct(qi::alnum | ('-' >> qi::alnum))["PATTERN"];
        term_rule UNIQUE_ = distinct(qi::alnum | ('-' >> qi::alnum))["UNIQUE"];
        term_rule CONSTRAINED_ = distinct(qi::alnum | ('-' >> qi::alnum))["CONSTRAINED"];
        term_rule IDENTIFIER_ = distinct(qi::alnum | ('-' >> qi::alnum))["IDENTIFIER"];
        term_rule PDV_ = distinct(qi::alnum | ('-' >> qi::alnum))["PDV"];
        term_rule UNIVERSAL_ = distinct(qi::alnum | ('-' >> qi::alnum))["UNIVERSAL"];
        term_rule CONTAINING_ = distinct(qi::alnum | ('-' >> qi::alnum))["CONTAINING"];
        term_rule IMPLICIT_ = distinct(qi::alnum | ('-' >> qi::alnum))["IMPLICIT"];
        term_rule PLUS_INFINITY_ = distinct(qi::alnum | ('-' >> qi::alnum))["PLUS-INFINITY"];
        term_rule UniversalString_ = distinct(qi::alnum | ('-' >> qi::alnum))["UniversalString"];
        term_rule DATE_ = distinct(qi::alnum | ('-' >> qi::alnum))["DATE"];
        term_rule IMPLIED_ = distinct(qi::alnum | ('-' >> qi::alnum))["IMPLIED"];
        term_rule PRESENT_ = distinct(qi::alnum | ('-' >> qi::alnum))["PRESENT"];
        term_rule UTCTime_ = distinct(qi::alnum | ('-' >> qi::alnum))["UTCTime"];
        term_rule DATE_TIME_ = distinct(qi::alnum | ('-' >> qi::alnum))["DATE-TIME"];
        term_rule IMPORTS_ = distinct(qi::alnum | ('-' >> qi::alnum))["IMPORTS"];
        term_rule PrintableString_ = distinct(qi::alnum | ('-' >> qi::alnum))["PrintableString"];
        term_rule UTF8String_ = distinct(qi::alnum | ('-' >> qi::alnum))["UTF8String"];
        term_rule DEFAULT_ = distinct(qi::alnum | ('-' >> qi::alnum))["DEFAULT"];
        term_rule INCLUDES_ = distinct(qi::alnum | ('-' >> qi::alnum))["INCLUDES"];
        term_rule PRIVATE_ = distinct(qi::alnum | ('-' >> qi::alnum))["PRIVATE"];
        term_rule VideotexString_ = distinct(qi::alnum | ('-' >> qi::alnum))["VideotexString"];
        term_rule DEFINITIONS_ = distinct(qi::alnum | ('-' >> qi::alnum))["DEFINITIONS"];
        term_rule INSTANCE_ = distinct(qi::alnum | ('-' >> qi::alnum))["INSTANCE"];
        term_rule REAL_ = distinct(qi::alnum | ('-' >> qi::alnum))["REAL"];
        term_rule VisibleString_ = distinct(qi::alnum | ('-' >> qi::alnum))["VisibleString"];
        term_rule DURATION_ = distinct(qi::alnum | ('-' >> qi::alnum))["DURATION"];
        term_rule INSTRUCTIONS_ = distinct(qi::alnum | ('-' >> qi::alnum))["INSTRUCTIONS"];
        term_rule RELATIVE_OID_ = distinct(qi::alnum | ('-' >> qi::alnum))["RELATIVE-OID"];
        term_rule WITH_ = distinct(qi::alnum | ('-' >> qi::alnum))["WITH"];
        term_rule EMBEDDED_ = distinct(qi::alnum | ('-' >> qi::alnum))["EMBEDDED"];
        term_rule INTEGER_ = distinct(qi::alnum | ('-' >> qi::alnum))["INTEGER"];
        term_rule RELATIVE_OID_IRI_ = distinct(qi::alnum | ('-' >> qi::alnum))["RELATIVE-OID-IRI"];

        str_rule ABSTRACT_SYNTAX__ = distinct(qi::alnum | ('-' >> qi::alnum))["ABSTRACT-SYNTAX"];
        str_rule TYPE_IDENTIFIER__ = distinct(qi::alnum | ('-' >> qi::alnum))["TYPE-IDENTIFIER"];

        str_rule literal_except_token = distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("BIT")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("BOOLEAN")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("CHARACTER")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("CHOICE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("DATE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("DATE-TIME")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("DURATION")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("EMBEDDED")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("END")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("ENUMERATED")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("EXTERNAL")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("FALSE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("INSTANCE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("INTEGER")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("INTERSECTION")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("MINUS-INFINITY")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("NULL")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("OBJECT")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("OCTET")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("PLUS-INFINITY")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("REAL")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("RELATIVE-OID")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("SEQUENCE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("SET")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("TIME")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("TIME-OF-DAY")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("TRUE")]
        | distinct(qi::alnum | ('-' >> qi::alnum))[qi::string("UNION")];


        str_rule word_ = distinct(qi::alnum | ('-' >> qi::alnum))[ qi::lexeme[qi::upper[ sprt::_val = sprt::_1 ]
                >> *(((qi::char_("-")[sprt::_val += sprt::_1]
                >> qi::upper[sprt::_val += sprt::_1])
                | (qi::upper[sprt::_val += sprt::_1]
                >> -qi::upper[sprt::_val += sprt::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::upper))))]];

        str_rule spaces_ = distinct((*qi::space) >> '&')[qi::space[ sprt::_val = sprt::_1 ] >> *(qi::space[sprt::_val += sprt::_1 ])];

        str_rule Literal_ = (word_ - literal_except_token) | qi::string(",");

        str_rule SyntaxField_ = Literal_[sprt::_val = sprt::_1 ] >> *(spaces_[ sprt::_val += ' '] >> Literal_[ sprt::_val += sprt::_1 ]);

        str_rule typereference_ = distinct(qi::alnum | ('-' >> qi::alnum))[qi::lexeme[qi::upper[ sprt::_val = sprt::_1 ]
                >> *(((qi::char_("-")[sprt::_val += sprt::_1]
                >> qi::alnum[sprt::_val += sprt::_1])
                | (qi::alnum[sprt::_val += sprt::_1]
                >> -qi::alnum[sprt::_val += sprt::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::alnum))))]];

        str_rule identifier_ = distinct(qi::alnum | ('-' >> qi::alnum))[qi::lexeme[qi::lower[sprt::_val = sprt::_1 ]
                >> *(((qi::char_("-")[sprt::_val += sprt::_1]
                >> qi::alnum[sprt::_val += sprt::_1])
                | (qi::alnum[sprt::_val += sprt::_1]
                >> -qi::alnum[sprt::_val += sprt::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::alnum))))]];

        str_rule valuereference_ = identifier_;

        str_rule valuesetreference_ = typereference_;

        str_rule modulereference_ = typereference_;

        str_rule objectreference_ = valuereference_;

        str_rule objectsetreference_ = typereference_;

        str_rule objectclassreference_ = distinct(qi::alnum | ('-' >> qi::alnum))[qi::lexeme[qi::upper[sprt::_val = sprt::_1 ]
                >> *(((qi::char_("-")[sprt::_val += sprt::_1]
                >> qi::char_("A-Z0-9")[sprt::_val += sprt::_1])
                | (qi::char_("A-Z0-9")[sprt::_val += sprt::_1]
                >> -qi::char_("A-Z0-9")[sprt::_val += sprt::_1])) - (qi::char_("-")
                >> ((qi::char_("-") | !qi::char_("A-Z0-9")))))]]; //(~typereference_)      

        str_rule typereference_strict = distinct(qi::alnum | ('-' >> qi::alnum))[typereference_ - qi::omit[objectclassreference_]];

        str_rule typefieldreference_ = qi::lexeme[qi::string("&")[sprt::_val = sprt::_1 ] >> typereference_[sprt::_val += sprt::_1 ]]; //(&typereference_[sprt::_val += sprt::_1 ])   

        str_rule valuefieldreference_ = qi::lexeme[qi::string("&")[sprt::_val = sprt::_1 ] >> valuereference_[sprt::_val += sprt::_1 ]]; //(&valuereference_)  

        str_rule valuesetfieldreference_ = qi::lexeme[qi::string("&")[sprt::_val = sprt::_1 ] >> typereference_[sprt::_val += sprt::_1 ]]; //(&typereference_)   

        str_rule objectfieldreference_ = qi::lexeme[qi::string("&")[sprt::_val = sprt::_1 ] >> objectreference_[sprt::_val += sprt::_1 ]]; //(&objectreference_)

        str_rule objectsetfieldreference_ = qi::lexeme[qi::string("&")[sprt::_val = sprt::_1 ] >> objectsetreference_[sprt::_val += sprt::_1 ]]; //(&objectsetreference_)  


        str_rule bigreference_ = typereference_;

        str_rule littlereference_ = valuereference_;

        str_rule bothreference_ = bigreference_ | littlereference_;

        str_rule bigfieldreference_ = typefieldreference_;

        str_rule littlefieldreference_ = valuefieldreference_;

        str_rule PrimitiveFieldName_ = bigfieldreference_ | littlefieldreference_;

        str_rule FieldName_ = PrimitiveFieldName_[sprt::_val = sprt::_1 ] >> -(qi::string(".")[sprt::_val += sprt::_1 ]
                >> qi::omit[(*qi::space)] >> (PrimitiveFieldName_[sprt::_val += sprt::_1 ] % qi::string(".")[sprt::_val += sprt::_1 ]));

        str_rule BFieldName_ = bigfieldreference_[sprt::_val = sprt::_1 ] >> -(qi::string(".")[sprt::_val += sprt::_1 ]
                >> qi::omit[(*qi::space)] >> (bigfieldreference_[sprt::_val += sprt::_1 ] % qi::string(".")[sprt::_val += sprt::_1 ]));

        str_rule LFieldName_ = littlefieldreference_[sprt::_val = sprt::_1 ] >> -(qi::string(".")[sprt::_val += sprt::_1 ]
                >> qi::omit[(*qi::space)] >> (littlefieldreference_[sprt::_val += sprt::_1 ] % qi::string(".")[sprt::_val += sprt::_1 ]));



        str_rule ExternalTypeReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> typereference_[sprt::_val += sprt::_1 ];

        str_rule ExternalTypeReference_strict = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> typereference_strict[sprt::_val += sprt::_1 ];


        str_rule ExternalValueReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> valuereference_[sprt::_val += sprt::_1 ];

        str_rule ExternalValueSetReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> valuesetreference_[sprt::_val += sprt::_1 ];

        str_rule ExternalObjectClassReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> objectclassreference_[sprt::_val += sprt::_1 ];

        str_rule ExternalObjectReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> objectreference_[sprt::_val += sprt::_1 ];

        str_rule ExternalObjectSetReference_ = modulereference_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ]
                >> objectsetreference_[sprt::_val += sprt::_1 ];

        str_rule UsefulObjectClass_ = TYPE_IDENTIFIER__
                | ABSTRACT_SYNTAX__;

        str_rule DefinedObjectClass_ = TYPE_IDENTIFIER__
                | ABSTRACT_SYNTAX__
                | ExternalObjectClassReference_
                | objectclassreference_;



        str_rule DefinedType_ = ExternalTypeReference_ | typereference_; //| ParameterizedType | ParameterizedValueSetType

        str_rule DefinedType_strict = ExternalTypeReference_strict | typereference_strict; //| ParameterizedType | ParameterizedValueSetType        

        str_rule DefinedValue_ = ExternalValueReference_ | valuereference_; //| ParameterizedValue        

        str_rule DefinedValueSet_ = ExternalValueSetReference_ | valuesetreference_; //| ParameterizedValue          

        str_rule DefinedObject_ = ExternalObjectReference_ | objectreference_;

        str_rule DefinedObjectSet_ = ExternalObjectSetReference_ | objectsetreference_;

        str_rule UserDefinedConstraintParameter_ = (DefinedType_ | DefinedObjectClass_)
        >> -(qi::string(".") >> DefinedValue_);

        str_rule AtNotation_ = distinct(qi::alnum | ('-' >> qi::alnum) | '.' | '@')[qi::string("@")[sprt::_val = sprt::_1 ]
                >> *(qi::string(".")[sprt::_val += sprt::_1 ]) >> (identifier_[sprt::_val += sprt::_1 ] % qi::string(".")[sprt::_val += sprt::_1 ])];

        str_rule Reference_ = typereference_ | valuereference_;

        str_rule ObjectClassFieldType_ = distinct(qi::alnum | ('-' >> qi::alnum) | '.')[DefinedObjectClass_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ] >> qi::omit[(*qi::space)] >> FieldName_[sprt::_val += sprt::_1 ] ];

        str_rule LittleFromObject_ = distinct(qi::alnum | ('-' >> qi::alnum) | '.')[DefinedObject_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ] >> qi::omit[(*qi::space)] >> FieldName_[sprt::_val += sprt::_1 ]];

        str_rule BigFromObjects_ = distinct(qi::alnum | ('-' >> qi::alnum) | '.')[DefinedObjectSet_[sprt::_val = sprt::_1 ]
                >> qi::string(".")[sprt::_val += sprt::_1 ] >> qi::omit[(*qi::space)] >> FieldName_[sprt::_val += sprt::_1 ]];

        str_rule ParameterizedReference_ = Reference_
                >> qi::omit[*qi::space
                >> curly_barket_pair];

        str_rule Symbol_ = ParameterizedReference_ | Reference_;





    }
}