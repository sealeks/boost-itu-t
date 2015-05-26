//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef _BOOST_ASN1_IMPLEMENTATIUON_H_
#define	_BOOST_ASN1_IMPLEMENTATIUON_H_

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4800)
#endif

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)



#include <boost/dynamic_bitset.hpp>
#include <boost/static_assert.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/iso_format.hpp>
#include <boost/date_time/date_format_simple.hpp>
#include <boost/date_time/date_facet.hpp>

#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/asn1/utf8.hpp>
#include <limits>

#if ((__WCHAR_MAX__) && (__WCHAR_MAX__ > 0x10000))
typedef wchar_t universalchar_t; // 32 bit
typedef boost::uint16_t bmpchar_t; // 16 bit
typedef std::wstring base_universalstring_type;
typedef std::basic_string<universalchar_t> base_bmpstring_type;
BOOST_STATIC_ASSERT(sizeof (wchar_t) == 4);
#else   
#define __ITU_ISBPM_WCHAR__         
typedef wchar_t bmpchar_t; // 16 bit
typedef boost::uint32_t universalchar_t;
typedef std::wstring base_bmpstring_type;
typedef std::basic_string<universalchar_t> base_universalstring_type;
BOOST_STATIC_ASSERT(sizeof (wchar_t) == 2);
#endif




#define ITU_T_ARRAY(...) __VA_ARGS__

#define ITU_T_SIMPLE_STRING_TRAITS( name) struct name : public std::string::traits_type{};

#define ITU_T_SET_REGESTRATE(regtype) \
namespace boost {\
        namespace asn1 {\
            template<>\
            struct tag_traits< regtype > {\
                static  id_type number() {\
                    return TYPE_SET;\
                }\
                static  octet_type class_type() {\
                    return 0;\
                }\
            } ;\
        }\
}\

#define ITU_T_TYPE_REGESTRATE(regtype, id, cl) \
namespace boost {\
        namespace asn1 {\
            template<>\
            struct tag_traits< regtype > {\
                static  id_type number() {\
                    return id;\
                }\
                static  octet_type class_type() {\
                    return static_cast<octet_type>(cl);\
                }\
            } ;\
        }\
}\

#define ITU_T_UNIVERSALTYPE_REGESTRATE(regtype, id) \
namespace boost {\
        namespace asn1 {\
            template<>\
            struct tag_traits< regtype > {\
                static  id_type number() {\
                    return id;\
                }\
                static  octet_type class_type() {\
                    return 0;\
                }\
            } ;\
        }\
}\


#define ITU_T_INTERNAL_REGESTRATE(regtype, id) \
            template<>\
            struct tag_traits< regtype > {\
                static  id_type number() {\
                    return id;\
                }\
                static  octet_type class_type() {\
                    return 0;\
                }\
            } ;\
            

#define ITU_T_USE_UNIVESAL_DECL using boost::asn1::null_type;\
    using boost::asn1::enumerated_type;\
    using boost::asn1::bitstring_type;\
    using boost::asn1::octetstring_type;\
    using boost::asn1::oid_type;\
    using boost::asn1::reloid_type;\
    using boost::asn1::utctime_type;\
    using boost::asn1::gentime_type;\
    using boost::asn1::ia5string_type;\
    using boost::asn1::printablestring_type;\
    using boost::asn1::visiblestring_type;\
    using boost::asn1::visiblestring_type;\
    using boost::asn1::numericstring_type;\
    using boost::asn1::universalstring_type;\
    using boost::asn1::bmpstring_type;\
    using boost::asn1::utf8string_type;\
    using boost::asn1::generalstring_type;\
    using boost::asn1::graphicstring_type;\
    using boost::asn1::t61string_type;\
    using boost::asn1::t61string_type;\
    using boost::asn1::videotexstring_type;\
    using boost::asn1::objectdescriptor_type;\
    using boost::asn1::external_type;\
    using boost::asn1::embeded_type;\
    using boost::asn1::characterstring_type;\
    using boost::asn1::any_type;\
    using boost::asn1::value_holder;\
    using boost::asn1::default_holder;\
    using boost::asn1::integer_type;\
    using boost::shared_ptr;\
    using boost::int8_t;\
    using boost::uint8_t;\
    using boost::int16_t;\
    using boost::uint16_t;\
    using boost::int32_t;\
    using boost::uint32_t;\
    using boost::int64_t;\
    using boost::uint64_t;

#define ITU_T_EXTENTION_READ  bool __is_extention__ =  arch.get_pop_bmp(1).bit(0);
#define ITU_T_EXTENTION_WRITE_NULL  bool __is_extention__ = false;boost::asn1::bitstring_type __extention_bmp__ =  boost::asn1::bitstring_type(__is_extention__); arch.add_bitmap(__extention_bmp__);
#define ITU_T_EXTENTION_WRITE_CHOICE( x0, xn)  bool __is_extention__ = ((static_cast<int>(type())>=static_cast<int>(x0 )) && (static_cast<int>(type())<=static_cast<int>(xn )));boost::asn1::bitstring_type __extention_bmp__ =  boost::asn1::bitstring_type(__is_extention__); arch.add_bitmap(__extention_bmp__);
#define ITU_T_EXTENTION_WRITE  bool __is_extention__ = static_cast<bool>( __ext_optional_groups_bmp__);boost::asn1::bitstring_type __extention_bmp__ =  boost::asn1::bitstring_type(__is_extention__); arch.add_bitmap(__extention_bmp__);
#define ITU_T_EXTENTION  __is_extention__

#define ITU_T_EXTENTION_GROUP_BOOL( num )  bool __is_ext_optional_ ## num
#define ITU_T_EXTENTION_GROUP_AS_BMP( num )  boost::asn1::bitstring_type(__is_ext_optional_ ## num )

#define ITU_T_EXTENTION_GROUPS_BMP  boost::asn1::bitstring_type __ext_optional_groups_bmp__
#define ITU_T_EXTENTION_GROUPS_CHECK( num )  __ext_optional_groups_bmp__.bit( num )
#define ITU_T_EXTENTION_GROUPS_WRITE  arch.set_extentions_marker(__ext_optional_groups_bmp__);
#define ITU_T_EXTENTION_GROUPS_READ  boost::asn1::bitstring_type __ext_optional_groups_bmp__; arch.get_extentions_marker(__ext_optional_groups_bmp__);


#define ITU_T_OPTIONAL_READ(sz)  boost::asn1::bitstring_type __optional_bmp__ =  arch.get_pop_bmp(sz);
#define ITU_T_OPTIONAL_WRITE arch.add_bitmap(__optional_bmp__);
#define ITU_T_OPTIONAL_CHECK(num)   if (__optional_bmp__.bit( num ))
#define ITU_T_OPTIONAL_BMP  boost::asn1::bitstring_type __optional_bmp__ 


#define ITU_T_EXISTS_BMP(name)  boost::asn1::bitstring_type(static_cast<bool>(name))
#define ITU_T_EXISTS_BOOL(name)  static_cast<bool>(name)

#define ITU_T_TYPEDEF(regtype, type , id, cl)  typedef type  regtype;
#define ITU_T_IMPLICIT_TYPEDEF(regtype, type , id, cl)  typedef boost::asn1::implicit_typedef< type, class _____TAGTYPE___##regtype ,  id , boost::asn1:: cl>  regtype;
#define ITU_T_EXPLICIT_TYPEDEF(regtype, type , id, cl)  typedef boost::asn1::explicit_typedef< type,  class _____TAGTYPE___##regtype , id , boost::asn1:: cl>   regtype;      

#define ITU_T_START_OPEN  arch.start_open();
#define ITU_T_END_OPEN  arch.end_open();
#define ITU_T_CLEAR_EXTENTIONS( num )  arch.clear_extentions(__ext_optional_groups_bmp__, num);
#define ITU_T_CLEAR_EXTENTION  arch.clear_extention();

#define ITU_T_RESET_EXTENTION   arch.resetextention();

#define ITU_T_CHOICE(enm)  boost::asn1::___asn__choice__base__< enm> 

#define ITU_T_CHOICE_CTORS(nm)          nm() : boost::asn1::___asn__choice__base__< nm ## _enum >() {};\
                                                                              template<typename T > nm (shared_ptr< T> vl, nm ## _enum enm) :  boost::asn1::___asn__choice__base__< nm ## _enum > (vl, static_cast<int> (enm)) {};\
                                                                              template<typename T > nm (const T& vl, nm ## _enum enm) : boost::asn1::___asn__choice__base__< nm ## _enum > (new T(vl), static_cast<int> (enm)) {};



//boost::asn1::___asn__choice__base__< enm>

#define ITU_T_CHOICE_CHECK(enm) ( arch.__input__()) || (check( enm ))

////////////////////////////////

// primitive choice
#define ITU_T_CHOICES_DECL(nm ,tp ,enm) shared_ptr< tp > nm () const {return get< tp >(enm);};\
                                                                             void nm ( tp * vl) { set( vl, enm );} ;\
                                                                             void nm ( const tp&  vl); \
                                                                             shared_ptr< tp > nm ## __new () { set<tp>( enm ); return get< tp >(enm);};\
                                                                             shared_ptr< tp >  nm ## __new ( tp * vl) { set<tp>( vl, enm ); return get< tp >(enm);};

#define ITU_T_CHOICES_DEFN(fullnm, nm  ,tp ,enm) void fullnm (const tp & vl){ set< tp >(new tp (vl), enm );}

// choice
#define ITU_T_CHOICEC_DECL(nm ,tp ,enm) shared_ptr< tp > nm () const {return get< tp >(enm);};\
                                                                             void nm ( tp * vl) { set( vl, enm );} ;\
                                                                             shared_ptr< tp > nm ## __new () { set<tp>( enm ); return get< tp >(enm);};\
                                                                             shared_ptr< tp >  nm ## __new ( tp * vl) { set<tp>( vl, enm ); return get< tp >(enm);};
        
#define ITU_T_CHOICEC_DEFN(fullnm, nm  ,tp ,enm);        


/////////////////////////////////


// value with holder
#define ITU_T_HOLDERH_DECL(nm ,tp )  void nm ( const tp & vl);\
                                                                       tp & nm ();\
                                                                       const tp & nm () const ;\
                                                                       void nm  (shared_ptr< tp > vl);\
                                                                       private: boost::asn1::value_holder< tp > nm ## _ ; public:

#define ITU_T_HOLDERH_DEFN(fullnm, nm ,tp )  tp & fullnm () {return *  nm ## _; }\
                                                                                    const tp & fullnm () const {return *  nm ## _;}\
                                                                                    void fullnm (const tp & vl) {  nm ## _ = vl; } \
                                                                                    void fullnm (shared_ptr< tp> vl) { nm ## _ = vl; }

// value simple 
#define ITU_T_HOLDERN_DECL(nm ,tp )  void nm ( const tp & vl);\
                                                                       tp & nm ();\
                                                                       const tp & nm  () const; \
                                                                       private:  tp  nm ## _ ; public: 



#define ITU_T_HOLDERN_DEFN(fullnm, nm ,tp )  tp & fullnm () {return  nm ## _; }\
                                                                                    const tp & fullnm () const {return  nm ## _;}\
                                                                                    void fullnm (const tp & vl) { nm ## _ = vl; } 


/////////////////////////////////

// optional value
#define ITU_T_OPTIONAL_DECL(nm ,tp )  shared_ptr< tp >& nm () { return nm ## _; };\
                                                                        const shared_ptr< tp >& nm () const { return nm ## _; } \
                                                                        void nm  (shared_ptr< tp > vl) {nm ## _ = vl;};\
                                                                        void nm  ( tp *  vl) {nm ## _ = shared_ptr< tp >(vl);}; \
                                                                        void nm ## __free  () {nm ## _ = shared_ptr< tp>();};\
                                                                        void nm ( const tp & vl); \
                                                                        shared_ptr< tp> nm ## __new  ();\
                                                                        private: shared_ptr< tp > nm ## _ ; public:            

#define ITU_T_OPTIONAL_DEFN(fullnm, nm ,tp )  shared_ptr< tp > fullnm ## __new() { return  nm ## _ = shared_ptr< tp >(new  tp ());}\
                                                                                     void fullnm(const tp & vl) {  nm ## _ = shared_ptr< tp >(new tp (vl));}



/////////////////////////////////

// default value
#define ITU_T_DEFAULTH_DECL(nm ,tp, dflt )    void nm ( const tp & vl);\
                                                                                  const tp & nm () const ;\
                                                                                  void nm  (shared_ptr< tp > vl); \
                                                                                  private: boost::asn1::default_holder<tp  , dflt> nm ## _ ; public: 
                                                                             
                                                                             
#define ITU_T_DEFAULTH_DEFN(fullnm, nm ,tp )    const tp & fullnm () const { return * nm ##  _; }\
                                                                                  void fullnm (const tp & vl) { nm ##  _ = vl;}\
                                                                                  void fullnm (shared_ptr<  tp > vl) { nm ##  _ = vl;}                          



                                                                             

#define ITU_T_EXTENDED_DECL()  void extended ( bool vl ) {__extended__ = vl  ? shared_ptr<bool>( new bool(vl)) : shared_ptr<bool>(); } ; bool extended ()  const { return static_cast<bool>(__extended__);}; \
                         private: shared_ptr<bool>  __extended__ ; public: 


#define ITU_T_ARCHIVE_FUNC    template<typename Archive> void serialize(Archive& arch){};

#define ITU_T_ARCHIVE_X690_DECL(nm)     template<> void nm  ::serialize(boost::asn1::x690::output_coder& arch);\
    template<> void nm  ::serialize(boost::asn1::x690::input_coder& arch);

#define ITU_T_ARCHIVE_X691_DECL(nm)     template<> void nm  ::serialize(boost::asn1::x691::output_coder& arch);\
    template<> void nm  ::serialize(boost::asn1::x691::input_coder& arch);

namespace boost {
    namespace asn1 {



        const std::size_t LENGH_128B = 0x80; //  0x4;
        const std::size_t LENGH_16K = 0x4000; //  0x10;
        const std::size_t LENGH_64K = 0x10000; //0x40        


        using boost::asio::const_buffer;
        using boost::asio::const_buffers_1;
        using boost::asio::mutable_buffer;
        using boost::asio::mutable_buffers_1;

        using boost::itu::mutable_sequences;
        using boost::itu::const_sequences;
        using boost::itu::encoding_rule;
        using boost::itu::octet_type;
        using boost::itu::octet_sequnce;
        using boost::itu::asn_coder_ptr;

        template<typename T>
        inline shared_ptr< T> simple_build_type() {
            return shared_ptr< T > (new T());
        }

        typedef std::size_t id_type;
        typedef std::size_t size_type;

        const octet_type PRIMITIVE_ENCODING = '\x0';
        const octet_type CONSTRUCTED_ENCODING = '\x20';


        ///////////////////

        const id_type TYPE_EOC = 0x0;
        const id_type TYPE_BOOLEAN = 0x1;
        const id_type TYPE_INTEGER = 0x2;
        const id_type TYPE_BITSTRING = 0x3;
        const id_type TYPE_OCTETSTRING = 0x4;
        const id_type TYPE_NULL = 0x5;
        const id_type TYPE_OBJECT_IDENTIFIER = 0x6;
        const id_type TYPE_OBJECT_DESCRIPTOR = 0x7;
        const id_type TYPE_EXTERNAL = 0x8;
        const id_type TYPE_REAL = 0x9;
        const id_type TYPE_ENUMERATED = 0xA;
        const id_type TYPE_EMBEDDED_PDV = 0xB;
        const id_type TYPE_UTF8STRING = 0xC;
        const id_type TYPE_RELATIVE_OID = 0xD;

        const id_type TYPE_SEQ = 0x10;
        const id_type TYPE_SET = 0x11;
        const id_type TYPE_NUMERICSTRING = 0x12; // known-multi 1 oct
        const id_type TYPE_PRINTABLESTRING = 0x13; // known-multi 1 oct
        const id_type TYPE_T61STRING = 0x14;
        const id_type TYPE_VIDEOTEXSTRING = 0x15;
        const id_type TYPE_IA5STRING = 0x16; // known-multi 1 oct
        const id_type TYPE_UTCTIME = 0x17;
        const id_type TYPE_GENERALZEDTIME = 0x18;
        const id_type TYPE_GRAPHICSTRING = 0x19;
        const id_type TYPE_VISIBLESTRING = 0x1A; // known-multi 1 oct
        const id_type TYPE_GENERALSTRING = 0x1B;
        const id_type TYPE_UNIVERSALSTRING = 0x1C; // known-multi 4 oct
        const id_type TYPE_CHARACTERSTRING = 0x1D;
        const id_type TYPE_BMPSTRING = 0x1E; // known-multi 2 oct

        const id_type EXTENDED_TAGID = 31;




        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // eoc_type
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        struct eoc_type {

        };





        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // null_type
        //////////////////////////////////////////////////////////////////////////////////////////////////// 

        class null_type {

        public:

            null_type() {
            }
        };

        std::ostream& operator<<(std::ostream& stream, const null_type& vl);
        
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // integer_type
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        typedef int32_t integer_type;


        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // enumerated_type
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        typedef int32_t enum_base_type;

        class enumerated_type {

        public:

            enumerated_type(enum_base_type vl = 0) : value_(vl) {
            }

            void value(enum_base_type vl) {
                value_ = vl;
            }

            enum_base_type value() const {
                return value_;
            }

            enum_base_type as_base() const {
                return value_;
            }

            friend bool operator<(const enumerated_type& ls, const enumerated_type& rs) {
                return ls.value_ < rs.value_;
            }

            friend bool operator==(const enumerated_type& ls, const enumerated_type& rs) {
                return ls.value_ == rs.value_;
            }


        private:
            enum_base_type value_;
        };


        typedef std::map<std::size_t, enumerated_type > indx_enumerated_map;
        typedef std::map<enumerated_type, std::size_t> enumerated_indx_map;

        indx_enumerated_map create_indx_enumerated(const enum_base_type* ev, std::size_t sz);
        enumerated_indx_map create_enumerated_indx(const enum_base_type* ev, std::size_t sz);





        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // reloid_type
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        class reloid_type : public boost::itu::containers::vector<oidindx_type> {

        public:

            reloid_type() : boost::itu::containers::vector<oidindx_type>() {
            }

            reloid_type(const oidindx_type * vl, std::size_t size);

        };



        std::ostream& operator<<(std::ostream& stream, const reloid_type& vl);





        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // utf8string_type
        ////////////////////////////////////////////////////////////////////////////////////////////////////           

        class utf8string_type : public std::string {

        public:

            utf8string_type() : std::string() {
            }

            explicit utf8string_type(const octet_sequnce& vl) : std::string(vl.begin(), vl.end()) {
            }

            explicit utf8string_type(const std::string& vl) : std::string(vl) {
            }

            utf8string_type(const std::wstring& vl) : std::string(wstr_to_utf8(vl)) {
            }

            operator std::wstring() const {
                return (valid()) ? utf8_to_wstr(*this) : std::wstring();
            }

            operator octet_sequnce() const {
                return (valid()) ? octet_sequnce(begin(), end()) : octet_sequnce();
            }

            octet_sequnce as_octet_sequnce() const {
                return (valid()) ? octet_sequnce(begin(), end()) : octet_sequnce();
            }

            std::wstring to_wstring() const {
                return (valid()) ? utf8_to_wstr(*this) : std::wstring();
            }

            bool valid() const {
                return check_utf8(*this);
            }

        };


        std::ostream& operator<<(std::ostream& stream, const utf8string_type& vl);







        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  SIMLE STRING TYPE
        ////////////////////////////////////////////////////////////////////////////////////////////////////


        ITU_T_SIMPLE_STRING_TRAITS(numericstring_traits); // known-multi 1 oct
        ITU_T_SIMPLE_STRING_TRAITS(printablestring_traits); // known-multi 1 oct
        ITU_T_SIMPLE_STRING_TRAITS(t61string_traits);
        ITU_T_SIMPLE_STRING_TRAITS(videotexstring_traits);
        //ITU_T_SIMPLE_STRING_TRAITS(ia5string_traits); // known-multi 1 oct
        ITU_T_SIMPLE_STRING_TRAITS(graphicstring_traits);
        ITU_T_SIMPLE_STRING_TRAITS(objectdescriptor_traits);
        ITU_T_SIMPLE_STRING_TRAITS(visiblestring_traits); // known-multi 1 oct
        ITU_T_SIMPLE_STRING_TRAITS(generalstring_traits);
        
        typedef std::string::value_type main_char_type;

        typedef std::basic_string<main_char_type, numericstring_traits > numericstring_type; // known-multi 1 oct
        typedef std::basic_string<main_char_type, printablestring_traits > printablestring_type; // known-multi 1 oct
        typedef std::basic_string<main_char_type, t61string_traits > t61string_type;
        typedef std::basic_string<main_char_type, videotexstring_traits > videotexstring_type;
        //typedef std::basic_string<main_char_type, ia5string_traits > ia5string_type; // known-multi 1 oct
        typedef std::string ia5string_type; // known-multi 1 oct
        typedef std::basic_string<main_char_type, graphicstring_traits > graphicstring_type;
        typedef std::basic_string<main_char_type, objectdescriptor_traits > objectdescriptor_type;
        typedef std::basic_string<main_char_type, visiblestring_traits > visiblestring_type; // known-multi 1 oct
        typedef std::basic_string<main_char_type, generalstring_traits > generalstring_type;
     
        
        template<typename T>
        octet_sequnce as_octet_sequnce(const T& vl) {
            return octet_sequnce(vl.begin(), vl.end());
        }       
        
        template<typename T>
        std::string as_std_string(const T& vl) {
            return std::string(vl.begin(), vl.end());
        }                  
        
        inline std::ostream& operator<<(std::ostream& stream, const numericstring_type& vl) {
            return stream << std::string(vl.begin(), vl.end());
        }

        inline std::ostream& operator<<(std::ostream& stream, const printablestring_type& vl) {
            return stream << std::string(vl.begin(), vl.end());
        }

        inline std::ostream& operator<<(std::ostream& stream, const t61string_type& vl) {
            return stream << std::string(vl.begin(), vl.end());
        }

        inline std::ostream& operator<<(std::ostream& stream, const videotexstring_type& vl) {
            return stream << std::string(vl.begin(), vl.end());
        }

        /*inline std::ostream& operator<<(std::ostream& stream, const ia5string_type& vl) {
            return stream << std::string(vl.begin(), vl.end());
            //return stream << vl;            
        }*/

        inline std::ostream& operator<<(std::ostream& stream, const graphicstring_type& vl) {
            return stream << std::string(vl.begin(), vl.end());
        }

        inline std::ostream& operator<<(std::ostream& stream, const visiblestring_type& vl) {
            return stream << std::string(vl.begin(), vl.end());
        }

        inline std::ostream& operator<<(std::ostream& stream, const generalstring_type& vl) {
            return stream << std::string(vl.begin(), vl.end());
        }







        //UNICOD UNI STRING  
        //  32bit

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // universalstring_type
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        class universalstring_type : public base_universalstring_type {

            // known-multi 4 oct

        public:

            universalstring_type() : base_universalstring_type() {
            }

            // from utf-8

            explicit universalstring_type(const std::string& vl) :
            base_universalstring_type(utf8_to_32str<base_universalstring_type>(vl)) {
            }


#ifdef __ITU_ISBPM_WCHAR__

            universalstring_type(const std::wstring& vl) :
            base_universalstring_type(utf_to_utf<base_universalstring_type, std::wstring>(vl)) {
            }

            operator std::wstring() const {
                return utf_to_utf< std::wstring, base_universalstring_type>(*this);
            }

            std::wstring to_wstring() const {
                return utf_to_utf< std::wstring, base_universalstring_type>(*this);
            }


#else            

            universalstring_type(const std::wstring& vl) :
            base_universalstring_type(vl) {
            }

            operator std::wstring() const {
                return *this;
            }

            std::wstring to_wstring() const {
                return *this;
            }


#endif

            std::string to_utf8() const {
                return utf32_to_8str(*this);
            }

            operator std::string() const {
                return to_utf8();
            }

            octet_sequnce as_octets() const {
                return empty() ? octet_sequnce() : octet_sequnce(reinterpret_cast<const octet_sequnce::value_type*> (data()),
                        reinterpret_cast<const octet_sequnce::value_type*> (data()) + size()*4);
            }

            bool append_octets(const octet_sequnce& vl) {
                if (vl.size() / 4)
                    append(reinterpret_cast<const value_type*> (vl.data()), vl.size() / 4);
                return ((!vl.size()) || ((vl.size() / 4) && !(vl.size() % 4)));
            }

        };

        std::ostream& operator<<(std::ostream& stream, const universalstring_type& vl);







        //UNICOD BMP STRING  
        //  16bit

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // bmpstring_type
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        class bmpstring_type : public /*std::string*/ base_bmpstring_type {

            // known-multi 2 oct

        public:

            bmpstring_type() : base_bmpstring_type() {
            }

            // frrom utf-8

            explicit bmpstring_type(const std::string& vl) :
            base_bmpstring_type(utf8_to_16str<base_bmpstring_type>(vl)) {
            }

#ifdef __ITU_ISBPM_WCHAR__     

            bmpstring_type(const std::wstring& vl) : base_bmpstring_type(vl) {
            }

            operator std::wstring() const {
                return *this;
            }

            std::wstring to_wstring() const {
                return *this;
            }



#else          

            bmpstring_type(const std::wstring& vl) :
            base_bmpstring_type(utf_to_utf<base_bmpstring_type, std::wstring>(vl)) {
            }

            operator std::wstring() const {
                return utf_to_utf<std::wstring, base_bmpstring_type>(*this);
            }

            std::wstring to_wstring() const {
                return utf_to_utf<std::wstring, base_bmpstring_type>(*this);
            }



#endif  

            std::string to_utf8() const {
                return utf16_to_8str(*this);
            }

            operator std::string() const {
                return to_utf8();
            }

            octet_sequnce as_octets() const {
                return empty() ? octet_sequnce() : octet_sequnce(reinterpret_cast<const octet_sequnce::value_type*> (data()),
                        reinterpret_cast<const octet_sequnce::value_type*> (data()) + size()*2);
            }

            bool append_octets(const octet_sequnce& vl) {
                if (vl.size() / 2)
                    append(reinterpret_cast<const value_type*> (vl.data()), vl.size() / 2);
                return ((!vl.size()) || ((vl.size() / 2) && !(vl.size() % 2)));
            }

        };

        std::ostream& operator<<(std::ostream& stream, const bmpstring_type& vl);







        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // utctime_type
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        typedef boost::posix_time::ptime utctime_type;

        octet_sequnce from_utctime(const utctime_type& val);

        visiblestring_type as_visiblestring(const utctime_type& val);

        utctime_type to_utctime(const octet_sequnce& val);

        utctime_type to_utctime(const visiblestring_type& val);

        inline utctime_type now_generator() {
            return boost::posix_time::microsec_clock::universal_time();
        }




        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // gentime_type
        ////////////////////////////////////////////////////////////////////////////////////////////////////  

        class gentime_type {

        public:

            gentime_type() : val_() {
            }

            gentime_type(const boost::posix_time::ptime& vl) : val_(vl) {
            }

            boost::posix_time::ptime value() const {
                return val_;
            }

            void value(const boost::posix_time::ptime vl) {
                val_ = vl;
            }

            operator boost::posix_time::ptime() const {
                return val_;
            }

        private:
            boost::posix_time::ptime val_;
        };



        octet_sequnce from_gentime(const gentime_type& val);

        visiblestring_type as_visiblestring(const gentime_type& val);

        gentime_type to_gentime(const octet_sequnce& val);

        gentime_type to_gentime(const visiblestring_type& val);


        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // any_type
        ////////////////////////////////////////////////////////////////////////////////////////////////////          

        class any_type {

        public:

            enum bind_type {

                bind_simple,
                bind_tie,
                bind_move
            };

            any_type(asn_coder_ptr cdr = asn_coder_ptr()) : type_(cdr ? bind_tie : bind_simple) {
            }

            template<typename Archive>
            void bind(Archive& arch) {
                arch.bind(data);
            }

            void tie(asn_coder_ptr cdr) {
                coder_ = cdr;
                type_ = cdr ? bind_tie : bind_simple;
            }

            void move_from(asn_coder_ptr cdr) {
                coder_ = cdr;
                type_ = cdr ? bind_move : bind_simple;
            }

            asn_coder_ptr coder() const {
                return coder_;
            }

            void set(const octet_sequnce& dt) {
                data = dt;
            }

            std::size_t get(octet_sequnce& dt) const {
                dt.insert(dt.end(), data.begin(), data.end());
                return data.size();
            }

            bind_type type() const {
                return type_;
            }

        private:
            asn_coder_ptr coder_;
            octet_sequnce data;
            bind_type type_;
        };



        std::ostream& operator<<(std::ostream& stream, const gentime_type& vl);








        //////////////////////////////////////////////////////////////////////////////////////////////////

        typedef enum {

            UNIVERSAL_CLASS = 0x0,
            APPLICATION_CLASS = 0x40,
            CONTEXT_CLASS = 0x80,
            PRIVATE_CLASS = 0xC0,
        } class_type;

        inline static octet_type from_cast(class_type vl) {
            return static_cast<octet_type> (vl);
        }

        class_type to_class_type(octet_type vl);

        template<typename T>
        struct tag_traits {

            static id_type number() {
                return TYPE_SEQ;
            }

            static octet_type class_type() {
                return 0;
            }
        };

        template<typename T >
        struct tag_traits< std::deque<T> > {

            static id_type number() {
                return TYPE_SET;
            }

            static octet_type class_type() {
                return 0;
            }
        };

        ITU_T_INTERNAL_REGESTRATE(eoc_type, TYPE_EOC)
        ITU_T_INTERNAL_REGESTRATE(int8_t, TYPE_INTEGER)
        ITU_T_INTERNAL_REGESTRATE(uint8_t, TYPE_INTEGER)
        ITU_T_INTERNAL_REGESTRATE(int16_t, TYPE_INTEGER)
        ITU_T_INTERNAL_REGESTRATE(uint16_t, TYPE_INTEGER)
        ITU_T_INTERNAL_REGESTRATE(int32_t, TYPE_INTEGER)
        ITU_T_INTERNAL_REGESTRATE(uint32_t, TYPE_INTEGER)
        ITU_T_INTERNAL_REGESTRATE(int64_t, TYPE_INTEGER)
        ITU_T_INTERNAL_REGESTRATE(uint64_t, TYPE_INTEGER)
        ITU_T_INTERNAL_REGESTRATE(long double, TYPE_REAL)
        ITU_T_INTERNAL_REGESTRATE(double, TYPE_REAL)
        ITU_T_INTERNAL_REGESTRATE(float, TYPE_REAL)
        ITU_T_INTERNAL_REGESTRATE(bool, TYPE_BOOLEAN)
        ITU_T_INTERNAL_REGESTRATE(oid_type, TYPE_OBJECT_IDENTIFIER)
        ITU_T_INTERNAL_REGESTRATE(reloid_type, TYPE_RELATIVE_OID)
        ITU_T_INTERNAL_REGESTRATE(null_type, TYPE_NULL)
        ITU_T_INTERNAL_REGESTRATE(bitstring_type, TYPE_BITSTRING)
        ITU_T_INTERNAL_REGESTRATE(octetstring_type, TYPE_OCTETSTRING)
        ITU_T_INTERNAL_REGESTRATE(enumerated_type, TYPE_ENUMERATED)
        ITU_T_INTERNAL_REGESTRATE(utf8string_type, TYPE_UTF8STRING)
        ITU_T_INTERNAL_REGESTRATE(numericstring_type, TYPE_NUMERICSTRING)
        ITU_T_INTERNAL_REGESTRATE(printablestring_type, TYPE_PRINTABLESTRING)
        ITU_T_INTERNAL_REGESTRATE(t61string_type, TYPE_T61STRING)
        ITU_T_INTERNAL_REGESTRATE(videotexstring_type, TYPE_VIDEOTEXSTRING)
        ITU_T_INTERNAL_REGESTRATE(ia5string_type, TYPE_IA5STRING)
        ITU_T_INTERNAL_REGESTRATE(graphicstring_type, TYPE_GRAPHICSTRING)
        ITU_T_INTERNAL_REGESTRATE(objectdescriptor_type, TYPE_OBJECT_DESCRIPTOR)
        ITU_T_INTERNAL_REGESTRATE(visiblestring_type, TYPE_VISIBLESTRING)
        ITU_T_INTERNAL_REGESTRATE(generalstring_type, TYPE_GENERALSTRING)
        ITU_T_INTERNAL_REGESTRATE(universalstring_type, TYPE_UNIVERSALSTRING)
        ITU_T_INTERNAL_REGESTRATE(bmpstring_type, TYPE_BMPSTRING)
        ITU_T_INTERNAL_REGESTRATE(utctime_type, TYPE_UTCTIME)
        ITU_T_INTERNAL_REGESTRATE(gentime_type, TYPE_GENERALZEDTIME)






        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  tag
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        class tag {

        public:

            static const id_type null_tag = (!id_type(0));

            tag() : id_(null_tag), mask_(0) {
            }

            tag(id_type vl, octet_type type = 0) : id_(vl), mask_(type) {
            }

            octet_type mask() const {
                return mask_;
            }

            class_type type() const {
                return to_class_type(mask_);
            }

            id_type id() const {
                return id_;
            }

            id_type simpleid() const {
                return (id_ < EXTENDED_TAGID) ? static_cast<octet_type> (mask_ | id_) : 0;
            }

            operator bool() const {
                return (id_ != null_tag);
            }

            bool constructed() const {
                return (mask_ & CONSTRUCTED_ENCODING);
            }

            friend bool operator<(const tag& ls, const tag& rs) {
                if (static_cast<uint8_t> (ls.type() | CONSTRUCTED_ENCODING) == static_cast<uint8_t> (rs.type() | CONSTRUCTED_ENCODING))
                    return ls.id() < rs.id();
                else
                    return static_cast<uint8_t> (ls.type() | CONSTRUCTED_ENCODING) < static_cast<uint8_t> (rs.type() | CONSTRUCTED_ENCODING);
            }

            friend bool operator==(const tag& ls, const tag& rs) {
                if (static_cast<uint8_t> (ls.type() | CONSTRUCTED_ENCODING) == static_cast<uint8_t> (rs.type() | CONSTRUCTED_ENCODING))
                    return ls.id() == rs.id();
                return false;
            }

        private:
            id_type id_;
            octet_type mask_;
        };

        std::ostream& operator<<(std::ostream& stream, const tag& vl);






        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  explicit_value
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        template<typename T>
        class explicit_value {

        public:

            typedef T base_type;

            explicit explicit_value(T& vl, id_type id, const class_type& type = CONTEXT_CLASS) : id_(id), val_(vl), mask_(from_cast(type) | CONSTRUCTED_ENCODING) {
            }

            explicit explicit_value(const T& vl, id_type id, const class_type& type = CONTEXT_CLASS) : id_(id), val_(const_cast<T&> (vl)), mask_(from_cast(type) | CONSTRUCTED_ENCODING) {
            }

            const T& value() const {
                return val_;
            }

            T& value() {
                return val_;
            }

            id_type id() const {
                return id_;
            }

            class_type type() const {
                return to_class_type(mask_);
            }

            octet_type mask() const {
                return mask_;
            }

            bool operator==(const tag& rs) const {
                return (id() == rs.id() && mask() == rs.mask());
            }

            operator tag() const {
                return tag(id_, mask_);
            }


        private:
            id_type id_;
            T& val_;
            octet_type mask_;
        };






        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  implicit_value
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        template<typename T>
        class implicit_value {

        public:

            typedef T root_type;

            explicit implicit_value(T& vl, id_type id, const class_type& type) :
            id_(id), val_(vl), mask_(from_cast(type)) {
            }

            explicit implicit_value(const T& vl, id_type id, const class_type& type) :
            id_(id), val_(const_cast<T&> (vl)), mask_(from_cast(type)) {
            }

            explicit implicit_value(T& vl, const class_type& type) :
            id_(tag_traits<T>::number()), val_(vl), mask_(from_cast(type)) {
            }

            explicit implicit_value(const T& vl, const class_type& type) :
            id_(tag_traits<T>::number()), val_(const_cast<T&> (vl)), mask_(from_cast(type)) {
            }

            explicit implicit_value(T& vl) :
            id_(tag_traits<T>::number()), val_(vl), mask_(tag_traits<T>::class_type()) {
            }

            explicit implicit_value(const T& vl) :
            id_(tag_traits<T>::number()), val_(const_cast<T&> (vl)), mask_(tag_traits<T>::class_type()) {
            }

            const T& value() const {
                return val_;
            }

            T& value() {
                return val_;
            }

            id_type id() const {
                return id_;
            }

            class_type type() const {
                return to_class_type(mask_);
            }

            octet_type mask() const {
                return mask_;
            }

            void setcontructed() const {
                mask_ |= CONSTRUCTED_ENCODING;
            }

            bool operator==(const tag& rs) const {
                return (id() == rs.id() && (mask() | CONSTRUCTED_ENCODING) == (rs.mask() | CONSTRUCTED_ENCODING));
            }

            operator tag() const {
                return tag(id_, mask_);
            }


        private:
            id_type id_;
            T& val_;
            mutable octet_type mask_;
        };







        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  optional_explicit_value
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        template<typename S>
        class optional_explicit_value {

        public:

            typedef shared_ptr<S> T;
            typedef S root_type;

            explicit optional_explicit_value(T& vl, id_type id, const class_type& type = CONTEXT_CLASS) : id_(id), val_(vl), mask_(from_cast(type) | CONSTRUCTED_ENCODING) {
            }

            explicit optional_explicit_value(const T& vl, id_type id, const class_type& type = CONTEXT_CLASS) : id_(id), val_(const_cast<T&> (vl)), mask_(from_cast(type) | CONSTRUCTED_ENCODING) {
            }

            const T& value() const {
                return val_;
            }

            T& value() {
                return val_;
            }

            id_type id() const {
                return id_;
            }

            class_type type() const {
                return to_class_type(mask_);
            }

            octet_type mask() const {
                return mask_;
            }

            static bool primitive() {
                return false;
            }

            bool operator==(const tag& rs) const {
                return (id() == rs.id() && mask() == rs.mask());
            }

            operator tag() const {
                return tag(id_, mask_);
            }


        private:
            id_type id_;
            T& val_;
            octet_type mask_;
        };






        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  optional_implicit_value 
        //////////////////////////////////////////////////////////////////////////////////////////////////// 

        template<typename S>
        class optional_implicit_value {

        public:

            typedef shared_ptr<S> T;
            typedef S root_type;

            explicit optional_implicit_value(T& vl, id_type id, const class_type& type) :
            id_(id), val_(vl), mask_(from_cast(type)) {
            }

            explicit optional_implicit_value(const T& vl, id_type id, const class_type& type) :
            id_(id), val_(const_cast<T&> (vl)), mask_(from_cast(type)) {
            }

            explicit optional_implicit_value(T& vl, const class_type& type) :
            id_(tag_traits<S>::number()), val_(vl), mask_(from_cast(type)) {
            }

            explicit optional_implicit_value(const T& vl, const class_type& type) :
            id_(tag_traits<S>::number()), val_(const_cast<T&> (vl)), mask_(from_cast(type)) {
            }

            explicit optional_implicit_value(T& vl) :
            id_(tag_traits<S>::number()), val_(vl), mask_(tag_traits<S>::class_type()) {
            }

            explicit optional_implicit_value(const T& vl) :
            id_(tag_traits<S>::number()), val_(const_cast<T&> (vl)), mask_(tag_traits<S>::class_type()) {
            }

            const T& value() const {
                return val_;
            }

            T& value() {
                return val_;
            }

            id_type id() const {
                return id_;
            }

            class_type type() const {
                return to_class_type(mask_);
            }

            octet_type mask() const {
                return mask_;
            }

            bool operator==(const tag& rs) const {
                return (id() == rs.id() && (mask() | CONSTRUCTED_ENCODING) == (rs.mask() | CONSTRUCTED_ENCODING));
            }

            operator tag() const {
                return tag(id_, mask_);
            }


        private:
            id_type id_;
            T& val_;
            octet_type mask_;
        };







        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  implicit_typedef 
        ////////////////////////////////////////////////////////////////////////////////////////////////////  

        template<typename T, class Tag, id_type ID, class_type TYPE = CONTEXT_CLASS >
        class implicit_typedef {

        public:

            implicit_typedef() : value_(new T()) {
            }

            implicit_typedef(const T& val) : value_(new T(val)) {
            }

            void operator()(const T& val) {
                *value_ = val;
            }

            operator T() const {
                return *value_;
            }

            T operator=(const T& val) {
                return *value_ = val;
            }

            const T& value() const {
                return *value_;
            }

            T& value() {
                return *value_;
            }

            T& operator*() const // never throws
            {
                return *value_;
            }

            T * operator->() const // never throws
            {
                return value_.get();
            }

            const shared_ptr<T>& shared_value() const {
                return value_;
            }

            shared_ptr<T>& shared_value() {
                return value_;
            }

            id_type id() const {
                return ID;
            }

            class_type type() const {
                return TYPE;
            }

            friend bool operator==(const implicit_typedef<T, Tag, ID, TYPE>& ls, const implicit_typedef<T, Tag, ID, TYPE>& rs) {
                return (ls.value_ == rs.value_);
            }

            friend bool operator!=(const implicit_typedef<T, Tag, ID, TYPE>& ls, const implicit_typedef<T, Tag, ID, TYPE>& rs) {
                return (ls.value_ != rs.value_);
            }


        private:
            shared_ptr<T> value_;
        };







        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  explicit_typedef 
        ////////////////////////////////////////////////////////////////////////////////////////////////////  

        template<typename T, class Tag, id_type ID, class_type TYPE = CONTEXT_CLASS >
        class explicit_typedef {

        public:

            explicit_typedef() : value_(new T()) {
            }

            explicit_typedef(const T& val) : value_(new T(val)) {
            }

            void operator()(const T& val) {
                *value_ = val;
            }

            operator T() const {
                return *value_;
            }

            T operator=(const T& val) {
                return *value_ = val;
            }

            const T& value() const {
                return *value_;
            }

            T& value() {
                return *value_;
            }

            T& operator*() const // never throws
            {
                return *value_;
            }

            T * operator->() const // never throws
            {
                return *value_.get();
            }

            const shared_ptr<T>& shared_value() const {
                return value_;
            }

            shared_ptr<T>& shared_value() {
                return value_;
            }

            id_type id() const {
                return ID;
            }

            class_type type() const {
                return TYPE;
            }

            friend bool operator==(const explicit_typedef<T, Tag, ID, TYPE>& ls, const explicit_typedef<T, Tag, ID, TYPE>& rs) {
                return (ls.value_ == rs.value_);
            }

            friend bool operator!=(const explicit_typedef<T, Tag, ID, TYPE>& ls, const explicit_typedef<T, Tag, ID, TYPE>& rs) {
                return (ls.value_ != rs.value_);
            }

        private:
            shared_ptr<T> value_;
        };











        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  ___asn__choice__base__
        ////////////////////////////////////////////////////////////////////////////////////////////////////                    

        template<typename E>
        class ___asn__choice__base__ {

            class base_choice_holder {

            public:

                base_choice_holder(int type = 0) : type_(type) {
                }

                virtual ~base_choice_holder() {
                }

                virtual bool empty() const {
                    return true;
                }

                int type() const {
                    return type_;
                }

                void type(int val) {
                    type_ = val;
                }
            protected:
                int type_;
            };

            template<typename T>
            class choice_holder : public base_choice_holder {

            public:

                choice_holder() : base_choice_holder(static_cast<int> (0)), val_(shared_ptr<T>()) {
                }

                choice_holder(T* vl, int ID = 0) : base_choice_holder(static_cast<int> (ID)), val_(shared_ptr<T>(vl)) {
                }

                choice_holder(shared_ptr<T> vl, int ID = 0) : base_choice_holder(static_cast<int> (ID)), val_(vl) {
                }

                shared_ptr<T>& value() {
                    return val_;
                }

                const shared_ptr<T>& value() const {
                    return val_;
                }

                virtual bool empty() const {
                    return false;
                }

            private:
                shared_ptr<T> val_;
            };


            typedef shared_ptr<base_choice_holder> type_ptr;

        public:

            ___asn__choice__base__() : val_() {
            }

            template<typename T>
            ___asn__choice__base__(T* vl, int id) : val_(new choice_holder<T>(vl, id)) {
            }

            virtual ~___asn__choice__base__() {
            }

            bool empty() const {
                return ((!val_) || (val_->empty()));
            }

            E type() const {
                return static_cast<E> (val_ ? val_->type() : 0);
            }

            void type(E val) {
                if (val_)
                    val_->type(static_cast<E> (val));
            }

            bool check(E val) {
                return type() == val;
            }

            template<typename T>
            shared_ptr<T>& value(bool isinput, E tp) {
                typedef choice_holder<T> choice_holder_type;
                if (isinput)
                    set(new T(), tp);
                return boost::static_pointer_cast< choice_holder_type > (val_)->value();
            }

            template<typename T>
            shared_ptr<T> get(E ID) const {
                typedef choice_holder<T> choice_holder_type;
                return (type() == ID) ?
                        boost::static_pointer_cast< choice_holder_type > (val_)->value() :
                        shared_ptr<T > ();
            }

            template<typename T>
            void set(T* vl, E ID) {
                val_ = type_ptr(new choice_holder<T > (vl, static_cast<int> (ID)));
            }

            template<typename T>
            void set(shared_ptr<T> vl, E ID) {
                val_ = type_ptr(new choice_holder<T > (vl, static_cast<int> (ID)));
            }

            template<typename T>
            void set(E ID) {
                val_ = type_ptr(new choice_holder<T > (new T(), static_cast<int> (ID)));
            }

            void free() {
                val_ = type_ptr();
            }

        protected:

            type_ptr val_;

        };






        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  value_holder
        ////////////////////////////////////////////////////////////////////////////////////////////////////        

        template<typename T>
        struct value_holder {

            value_holder() : internal_(new T()) {
            }

            explicit value_holder(const T & vl) :
            internal_(new T(vl)) {
            }

            explicit value_holder(shared_ptr<T> vl) :
            internal_(vl ? vl : shared_ptr<T>(new T())) {
            }

            T& operator*() const {
                return *internal_;
            }

            T& operator=(const T & vl) {
                internal_ = shared_ptr<T > (new T(vl));
                return *internal_;
            }

            T& operator=(shared_ptr<T> vl) {
                if (vl)
                    internal_ = vl;
                return *internal_;
            }

            shared_ptr<T>& get_shared() {
                return internal_;
            }

            T * operator->() const {
                return internal_.get();
            }


        private:

            shared_ptr<T> internal_;
        };





        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  default_holder
        ////////////////////////////////////////////////////////////////////////////////////////////////////        

        template<typename T, const T& DT>
        struct default_holder {

            default_holder() {
            }

            explicit default_holder(const T & vl) :
            internal_(vl != DT ? new T(vl) : shared_ptr<T>()) {
            }

            explicit default_holder(shared_ptr<T> vl) :
            internal_(vl ? (((*vl) != DT) ? vl : shared_ptr<T>()) : vl) {
            }

            const T& operator*() const {
                if (internal_)
                    return*internal_;
                return DT;
            }

            operator bool() const {
                return ((internal_) && (* internal_ != DT));
            }

            const T& operator=(const T & vl) {
                internal_ = (vl != DT) ? shared_ptr<T > (new T(vl)) : shared_ptr<T>();
                if (internal_)
                    return*internal_;
                return DT;
            }

            const T& operator=(shared_ptr<T> vl) {
                internal_ = vl;
                if (internal_)
                    return*internal_;
                return DT;
            }

            shared_ptr<T>& get_shared() {
                return internal_;
            }

            bool isdefault() const {
                return ((!internal_) || (* internal_ == DT));
            }

            T * operator->() const {
                return internal_.get();
            }


        private:

            shared_ptr<T> internal_;

        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  num_constrainter
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        template<typename T>
        struct num_constrainter {

            num_constrainter(T& vl, const T& mn, const T& mx, bool ext) :
            value_(vl), MIN(mn), MAX(mx), EXT(ext), SEMI(false) {
            }

            num_constrainter(value_holder<T>& vl, const T& mn, const T& mx, bool ext) :
            value_(*vl), MIN(mn), MAX(mx), EXT(ext), SEMI(false) {
            }

            num_constrainter(shared_ptr<T>& vl, const T& mn, const T& mx, bool ext) :
            value_(*vl), MIN(mn), MAX(mx), EXT(ext), SEMI(false) {
            }

            template<const T& DT>
            num_constrainter(default_holder<T, DT>& vl, const T& mn, const T& mx, bool ext) :
            value_(const_cast<T&> (*vl)), MIN(mn), MAX(mx), EXT(ext), SEMI(false) {
            }

            template<class Tag, id_type ID, class_type TYPE >
            num_constrainter(implicit_typedef<T, Tag, ID, TYPE>& vl, const T& mn, const T& mx, bool ext) :
            value_(*vl), MIN(mn), MAX(mx), EXT(ext), SEMI(false) {
            }

            template<class Tag, id_type ID, class_type TYPE >
            num_constrainter(explicit_typedef<T, Tag, ID, TYPE>& vl, const T& mn, const T& mx, bool ext) :
            value_(*vl), MIN(mn), MAX(mx), EXT(ext), SEMI(false) {
            }

            num_constrainter(T& vl, const T& mn, bool ext) :
            value_(vl), MIN(mn), MAX(), EXT(ext), SEMI(true) {
            }

            num_constrainter(value_holder<T>& vl, const T& mn, bool ext) :
            value_(*vl), MIN(mn), MAX(), EXT(ext), SEMI(true) {
            }

            num_constrainter(shared_ptr<T>& vl, const T& mn, bool ext) :
            value_(*vl), MIN(mn), MAX(), EXT(ext), SEMI(true) {
            }

            template<const T& DT>
            num_constrainter(default_holder<T, DT>& vl, const T& mn, bool ext) :
            value_(const_cast<T&> (*vl)), MIN(mn), MAX(), EXT(ext), SEMI(true) {
            }

            template<class Tag, id_type ID, class_type TYPE >
            num_constrainter(implicit_typedef<T, Tag, ID, TYPE>& vl, const T& mn, bool ext) :
            value_(*vl), MIN(mn), MAX(), EXT(ext), SEMI(true) {
            }

            template<class Tag, id_type ID, class_type TYPE >
            num_constrainter(explicit_typedef<T, Tag, ID, TYPE>& vl, const T& mn, bool ext) :
            value_(*vl), MIN(mn), MAX(), EXT(ext), SEMI(true) {
            }

            const T& min() const {
                return MIN;
            }

            const T& max() const {
                return MAX;
            }

            bool can_extended() const {
                return EXT;
            }

            bool nill_extended() const {
                return (!MIN && !MAX && !EXT);
            }

            bool constrained() const {
                return MIN || MAX || SEMI;
            }

            bool semi() const {
                return SEMI;
            }

            boost::uint64_t range() const {
                return MAX - MIN;
            }

            bool is_single() const {
                return MAX == MIN;
            }

            T& value() {
                return value_;
            }

            const T& value() const {
                return value_;
            }

            bool extended() const {
                return SEMI ? (value_ < MIN) : ((value_ < MIN) || (value_ > MAX));
            }

            void to_single() {
                value_ = MIN;
            }

        private:

            T& value_;
            const T& MIN;
            const T& MAX;
            bool EXT;
            bool SEMI;
        };



        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  element_constrainter
        ////////////////////////////////////////////////////////////////////////////////////////////////////        

        struct null_constrainter {

        };


        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //  size_constrainter
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        template<typename T, typename EC = null_constrainter>
        struct size_constrainter {

            typedef EC elements_constrainter_type;

            size_constrainter(T& vl) :
            value_(vl), MIN(0), MAX(0), EXT(false), AVAIL(false) {
            }

            size_constrainter(T& vl, bool ext) :
            value_(vl), MIN(0), MAX(0), EXT(ext), AVAIL(true) {
            }

            size_constrainter(T& vl, const std::size_t& mn, const std::size_t& mx = 0, bool ext = false) :
            value_(vl), MIN(mn), MAX(mx), EXT(ext), AVAIL(true) {
            }

            template<class Tag, id_type ID, class_type TYPE >
            size_constrainter(implicit_typedef<T, Tag, ID, TYPE>& vl, const std::size_t& mn, const std::size_t& mx = 0, bool ext = false) :
            value_(*vl), MIN(mn), MAX(mx), EXT(ext), AVAIL(true) {
            }

            template<class Tag, id_type ID, class_type TYPE >
            size_constrainter(explicit_typedef<T, Tag, ID, TYPE>& vl, const std::size_t& mn, const std::size_t& mx = 0, bool ext = false) :
            value_(*vl), MIN(mn), MAX(mx), EXT(ext), AVAIL(true) {
            }

            const std::size_t& min() const {
                return MIN;
            }

            const std::size_t& max() const {
                return MAX;
            }

            bool available() const {
                return AVAIL;
            }

            bool can_extended() const {
                return EXT;
            }

            bool nill_extended() const {
                return (AVAIL && !MIN && !MAX);
            }

            bool constrained() const {
                return (MIN || MAX) && (MAX < LENGH_64K);
            }

            bool semi() const {
                return (MIN && !MAX);
            }

            bool is_single() const {
                return (MAX == MIN) && (MAX < LENGH_64K);
            }

            boost::uint64_t range() const {
                return MAX - MIN;
            }

            T& value() {
                return value_;
            }

            const T& value() const {
                return value_;
            }

            bool extended(std::size_t sz) const {
                return semi() ? (sz < MIN) : ((sz < MIN) || (sz > MAX));
            }

            bool check(std::size_t sz) const {
                if (available()) {
                    if ((extended(sz)) && (!can_extended()))
                        return false;
                }
                return true;
            }

        private:

            T& value_;
            const std::size_t& MIN;
            const std::size_t& MAX;
            bool EXT;
            bool AVAIL;
        };





        ////////////////////////////////////////////////////////////////////////////////////////////////////        

        template<typename T>
        struct bind_element {

            template<typename Archive>
            static bool op(Archive& arch, T& vl) {
                std::size_t tst = arch.size();
                arch & vl;
                return (arch.size() != tst);
            }

            template<typename Archive>
            static bool op(Archive& arch, const T& vl) {
                std::size_t tst = arch.size();
                arch & vl;
                return (arch.size() != tst);
            }

            template<typename Archive>
            static bool op(Archive& arch, value_holder<T>& vl) {
                return op(arch, (*vl));
            }

        };



#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif            



        /////////////////////////////////////////////////////////////////////////////////////////////////

        struct external_type {

            struct Encoding_type;

            enum Encoding_type_enum {

                Encoding_type_null = 0,
                Encoding_type_single_ASN1_type,
                Encoding_type_octet_aligned,
                Encoding_type_arbitrary,
            };

            struct Encoding_type : public ITU_T_CHOICE(Encoding_type_enum) {

                Encoding_type() : ITU_T_CHOICE(Encoding_type_enum) () {
                }

                template<typename T > Encoding_type(shared_ptr< T> vl, Encoding_type_enum enm) :
                        ITU_T_CHOICE(Encoding_type_enum) (vl, static_cast<int> (enm)) {
                }

                ITU_T_CHOICES_DECL(single_ASN1_type, any_type, Encoding_type_single_ASN1_type); // primitive
                ITU_T_CHOICES_DECL(octet_aligned, octetstring_type, Encoding_type_octet_aligned); // primitive
                ITU_T_CHOICES_DECL(arbitrary, bitstring_type, Encoding_type_arbitrary); // primitive

                ITU_T_ARCHIVE_FUNC;
            };


            external_type();

            external_type(const Encoding_type& arg__encoding);

            external_type(shared_ptr< oid_type> arg__direct_reference,
                    shared_ptr< int> arg__indirect_reference,
                    shared_ptr< objectdescriptor_type> arg__data_value_descriptor,
                    shared_ptr< Encoding_type> arg__encoding);

            ITU_T_OPTIONAL_DECL(direct_reference, oid_type);
            ITU_T_OPTIONAL_DECL(indirect_reference, int);
            ITU_T_OPTIONAL_DECL(data_value_descriptor, objectdescriptor_type);
            ITU_T_HOLDERH_DECL(encoding, Encoding_type);

            ITU_T_ARCHIVE_FUNC;
        };

        ITU_T_INTERNAL_REGESTRATE(external_type, TYPE_EXTERNAL)


        /////////////////////////////////////////////////////////////////////////////////////////////////   


        struct embeded_type {

            struct Identification_type;

            enum Identification_type_enum {

                Identification_type_null = 0,
                Identification_type_syntaxes,
                Identification_type_syntax,
                Identification_type_presentation_context_id,
                Identification_type_context_negotiation,
                Identification_type_transfer_syntax,
                Identification_type_fixed,
            };

            struct Identification_type : public ITU_T_CHOICE(Identification_type_enum) {


                struct Syntaxes_type;
                struct Context_negotiation_type;

                struct Syntaxes_type {

                    Syntaxes_type();

                    Syntaxes_type(const oid_type& arg__abstract,
                            const oid_type& arg__transfer);

                    ITU_T_HOLDERH_DECL(abstract, oid_type);
                    ITU_T_HOLDERH_DECL(transfer, oid_type);

                    ITU_T_ARCHIVE_FUNC;
                };

                struct Context_negotiation_type {

                    Context_negotiation_type();

                    Context_negotiation_type(const int& arg__presentation_context_id,
                            const oid_type& arg__transfer_syntax);

                    ITU_T_HOLDERH_DECL(presentation_context_id, int);
                    ITU_T_HOLDERH_DECL(transfer_syntax, oid_type);

                    ITU_T_ARCHIVE_FUNC;
                };

                Identification_type() : ITU_T_CHOICE(Identification_type_enum) () {
                }

                template<typename T > Identification_type(shared_ptr< T> vl, Identification_type_enum enm) :
                        ITU_T_CHOICE(Identification_type_enum) (vl, static_cast<int> (enm)) {
                }

                ITU_T_CHOICEC_DECL(syntaxes, Syntaxes_type, Identification_type_syntaxes);
                ITU_T_CHOICES_DECL(syntax, oid_type, Identification_type_syntax); // primitive
                ITU_T_CHOICES_DECL(presentation_context_id, int, Identification_type_presentation_context_id); // primitive
                ITU_T_CHOICEC_DECL(context_negotiation, Context_negotiation_type, Identification_type_context_negotiation);
                ITU_T_CHOICES_DECL(transfer_syntax, oid_type, Identification_type_transfer_syntax); // primitive
                ITU_T_CHOICES_DECL(fixed, null_type, Identification_type_fixed); // primitive

                ITU_T_ARCHIVE_FUNC;
            };


            embeded_type();

            embeded_type(const Identification_type& arg__identification,
                    const octetstring_type& arg__data_value);

            ITU_T_HOLDERH_DECL(identification, Identification_type);
            ITU_T_HOLDERH_DECL(data_value, octetstring_type);

            ITU_T_ARCHIVE_FUNC;
        };

        ITU_T_INTERNAL_REGESTRATE(embeded_type, TYPE_EMBEDDED_PDV)



        //////////////////////////////////////////////////////////////////////////////////////////////////


        struct characterstring_type {

            struct Identification_type;

            enum Identification_type_enum {

                Identification_type_null = 0,
                Identification_type_syntaxes,
                Identification_type_syntax,
                Identification_type_presentation_context_id,
                Identification_type_context_negotiation,
                Identification_type_transfer_syntax,
                Identification_type_fixed,
            };

            struct Identification_type : public ITU_T_CHOICE(Identification_type_enum) {


                struct Syntaxes_type;
                struct Context_negotiation_type;

                struct Syntaxes_type {

                    Syntaxes_type();

                    Syntaxes_type(const oid_type& arg__abstract,
                            const oid_type& arg__transfer);

                    ITU_T_HOLDERH_DECL(abstract, oid_type);
                    ITU_T_HOLDERH_DECL(transfer, oid_type);

                    ITU_T_ARCHIVE_FUNC;
                };

                struct Context_negotiation_type {

                    Context_negotiation_type();

                    Context_negotiation_type(const int& arg__presentation_context_id,
                            const oid_type& arg__transfer_syntax);

                    ITU_T_HOLDERH_DECL(presentation_context_id, int);
                    ITU_T_HOLDERH_DECL(transfer_syntax, oid_type);

                    ITU_T_ARCHIVE_FUNC;
                };

                Identification_type() : ITU_T_CHOICE(Identification_type_enum) () {
                }

                template<typename T > Identification_type(shared_ptr< T> vl, Identification_type_enum enm) :
                        ITU_T_CHOICE(Identification_type_enum) (vl, static_cast<int> (enm)) {
                }

                ITU_T_CHOICEC_DECL(syntaxes, Syntaxes_type, Identification_type_syntaxes);
                ITU_T_CHOICES_DECL(syntax, oid_type, Identification_type_syntax); // primitive
                ITU_T_CHOICES_DECL(presentation_context_id, int, Identification_type_presentation_context_id); // primitive
                ITU_T_CHOICEC_DECL(context_negotiation, Context_negotiation_type, Identification_type_context_negotiation);
                ITU_T_CHOICES_DECL(transfer_syntax, oid_type, Identification_type_transfer_syntax); // primitive
                ITU_T_CHOICES_DECL(fixed, null_type, Identification_type_fixed); // primitive

                ITU_T_ARCHIVE_FUNC;
            };


            characterstring_type();

            characterstring_type(const Identification_type& arg__identification,
                    const octetstring_type& arg__string_value);

            ITU_T_HOLDERH_DECL(identification, Identification_type);
            ITU_T_HOLDERH_DECL(string_value, octetstring_type);

            ITU_T_ARCHIVE_FUNC;
        };

        ITU_T_INTERNAL_REGESTRATE(characterstring_type, TYPE_CHARACTERSTRING)

    }
}




#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif	/* _BOOST_ASN1_IMPLEMENTATIUON_H_ */

