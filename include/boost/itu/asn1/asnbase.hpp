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

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/iso_format.hpp>
#include <boost/date_time/date_format_simple.hpp>
#include <boost/date_time/date_facet.hpp>

#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/asn1/utf8.hpp>




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

#define ITU_T_CHOICE_REGESTRATE(regtype)\
namespace boost {\
        namespace asn1 {\
            template<>\
        struct bind_element< regtype > {\
            template<typename Archive>\
                    static bool op(Archive& arch, regtype & vl) {\
                return boost::asn1::bind_choice(arch, vl);\
            }\
            template<typename Archive>\
                    static bool op(Archive& arch, const regtype & vl) {\
                return boost::asn1::bind_choice(arch, vl);\
            }\
        };\
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

#define ITU_T_TYPEDEF(regtype, type , id, cl)  typedef type  regtype;
#define ITU_T_IMPLICIT_TYPEDEF(regtype, type , id, cl)  typedef boost::asn1::implicit_typedef< type, class _____TAGTYPE___##regtype ,  id , boost::asn1:: cl>  regtype;
#define ITU_T_EXPLICIT_TYPEDEF(regtype, type , id, cl)  typedef boost::asn1::explicit_typedef< type,  class _____TAGTYPE___##regtype , id , boost::asn1:: cl>   regtype;      




#define ITU_T_BIND_TAG(var)    boost::asn1::bind_basic(arch, var)
#define ITU_T_IMPLICIT_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::CONTEXT_CLASS)
#define ITU_T_IMPLICIT_APPLICATION_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::APPLICATION_CLASS)
#define ITU_T_IMPLICIT_PRIVATE_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::PRIVATE_CLASS)
#define ITU_T_IMPLICIT_UNIVERSAL_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::UNIVERSAL_CLASS) 
#define ITU_T_EXPLICIT_TAG(var, tag)    boost::asn1::bind_explicit(arch, var, tag, boost::asn1::CONTEXT_CLASS)
#define ITU_T_EXPLICIT_APPLICATION_TAG(var, tag)    boost::asn1::bind_explicit(arch, var, tag, boost::asn1::APPLICATION_CLASS)  
#define ITU_T_EXPLICIT_PRIVATE_TAG(var, tag)    boost::asn1::bind_explicit(arch, var, tag, boost::asn1::PRIVATE_CLASS)
#define ITU_T_EXPLICIT_UNIVERSAL_TAG(var, tag)    boost::asn1::bind_explicit(arch, var, tag, boost::asn1::UNIVERSAL_CLASS)
#define ITU_T_BIND_CHOICE(var)    boost::asn1::bind_choice(arch, var)
#define ITU_T_CHOICE_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::CONTEXT_CLASS)
#define ITU_T_CHOICE_APPLICATION_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::APPLICATION_CLASS)
#define ITU_T_CHOICE_PRIVATE_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::PRIVATE_CLASS)
#define ITU_T_CHOICE_UNIVERSAL_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::APPLICATION_CLASS)

#define ITU_T_EXTENTION   arch.resetextention();

#define ITU_T_CHOICE(enm)  boost::asn1::___asn__choice__base__< enm> 
#define ITU_T_CHOICE_CHECK(enm) ( arch.__input__()) || (check( enm ))

#define ITU_T_CHOICES_DECL(nm ,tp ,enm) boost::shared_ptr< tp > nm () const {return get< tp >(enm);}; void nm ( tp * vl) { set( vl, enm );} ; void nm ( const tp&  vl); \
                         boost::shared_ptr< tp > nm ## __new () { set<tp>( enm ); return get< tp >(enm);}; boost::shared_ptr< tp >  nm ## __new ( tp * vl) { set<tp>( vl, enm ); return get< tp >(enm);};

#define ITU_T_CHOICEC_DECL(nm ,tp ,enm) boost::shared_ptr< tp > nm () const {return get< tp >(enm);}; void nm ( tp * vl) { set( vl, enm );} ; \
                         boost::shared_ptr< tp > nm ## __new () { set<tp>( enm ); return get< tp >(enm);}; boost::shared_ptr< tp >  nm ## __new ( tp * vl) { set<tp>( vl, enm ); return get< tp >(enm);};

#define ITU_T_OPTIONAL_DECL(nm ,tp )  boost::shared_ptr< tp >& nm () { return nm ## _; };  const boost::shared_ptr< tp >& nm () const { return nm ## _; } \
                         void nm  (boost::shared_ptr< tp > vl) {nm ## _ = vl;}; void nm  ( tp *  vl) {nm ## _ = boost::shared_ptr< tp >(vl);}; void nm ( const tp & vl); \
                         boost::shared_ptr< tp> nm ## __new  (); void nm ## __free  () {nm ## _ = boost::shared_ptr< tp>();}; \
                         private: boost::shared_ptr< tp > nm ## _ ; public:                         

#define ITU_T_HOLDERH_DECL(nm ,tp )  void nm ( const tp & vl); tp & nm ();  const tp & nm () const ; void nm  (boost::shared_ptr< tp > vl); \
                         private: boost::asn1::value_holder< tp > nm ## _ ; public: 

#define ITU_T_HOLDERN_DECL(nm ,tp )  void nm ( const tp & vl); tp & nm ();  const tp & nm  () const; \
                         private:  tp  nm ## _ ; public: 

#define ITU_T_DEFAULTH_DECL(nm ,tp, dflt )    void nm ( const tp & vl);  const tp & nm () const ; void nm  (boost::shared_ptr< tp > vl); \
                         private: boost::asn1::default_holder<tp  , dflt> nm ## _ ; public: 


#define ITU_T_ARCHIVE_FUNC    template<typename Archive> void serialize(Archive& arch){};



namespace boost {
    namespace asn1 {


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
        inline boost::shared_ptr< T> simple_build_type() {
            return boost::shared_ptr< T > (new T());
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
        const id_type TYPE_NUMERICSTRING = 0x12;
        const id_type TYPE_PRINTABLESTRING = 0x13;
        const id_type TYPE_T61STRING = 0x14;
        const id_type TYPE_VIDEOTEXSTRING = 0x15;
        const id_type TYPE_IA5STRING = 0x16;
        const id_type TYPE_UTCTIME = 0x17;
        const id_type TYPE_GENERALZEDTIME = 0x18;
        const id_type TYPE_GRAPHICSTRING = 0x19;
        const id_type TYPE_VISIBLESTRING = 0x1A;
        const id_type TYPE_GENERALSTRING = 0x1B;
        const id_type TYPE_UNIVERSALSTRING = 0x1C;
        const id_type TYPE_CHARACTERSTRING = 0x1D;
        const id_type TYPE_BMPSTRING = 0x1E;

        const id_type EXTENDED_TAGID = 31;




        //// EOF_TYPE

        struct eoc_type {

        };



        //// ENUMERATED_TYPE

        typedef int32_t enumerated_base_type;

        class enumerated_type {

        public:

            enumerated_type(enumerated_base_type vl = 0) : value_(vl) {
            }

            void value(enumerated_base_type vl) {
                value_ = vl;
            }

            enumerated_base_type value() const {
                return value_;
            }

            operator enumerated_base_type() const {
                return value_;
            }

        private:
            enumerated_base_type value_;
        };







        //// ReLATIVE OID_TYPE

        class reloid_type : public boost::itu::containers::vector<oidindx_type> {

        public:

            reloid_type() : boost::itu::containers::vector<oidindx_type>() {
            }

            reloid_type(const oidindx_type * vl, std::size_t size);

            reloid_type(const boost::array<oidindx_type, 2 > & vl);

            reloid_type(const boost::array<oidindx_type, 3 > & vl);

            reloid_type(const boost::array<oidindx_type, 4 > & vl);

            reloid_type(const boost::array<oidindx_type, 5 > & vl);

            reloid_type(const boost::array<oidindx_type, 6 > & vl);

            reloid_type(const boost::array<oidindx_type, 7 > & vl);

            reloid_type(const boost::array<oidindx_type, 8 > & vl);

            reloid_type(const boost::array<oidindx_type, 9 > & vl);

            reloid_type(const boost::array<oidindx_type, 10 > & vl);

        };



        std::ostream& operator<<(std::ostream& stream, const reloid_type& vl);


        /// NULL TYPE

        class null_type {

        public:

            null_type() {
            }
        };

        inline std::ostream& operator<<(std::ostream& stream, const null_type& vl) {
            return stream << "NULL TYPE" << std::endl;
        }


        ///  UTF8STRING TYPE           

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

            std::wstring to_wstring() const {
                return (valid()) ? utf8_to_wstr(*this) : std::wstring();
            }

            bool valid() const {
                return check_utf8(*this);
            }

        };


        std::ostream& operator<<(std::ostream& stream, const utf8string_type& vl);



        //  SIMLE STRING TYPE

        template<id_type TAGID>
        class simplestring_type : public std::string {

        public:

            simplestring_type() : std::string() {
            }

            explicit simplestring_type(const octet_sequnce& vl) : std::string(vl.begin(), vl.end()) {
            }

            simplestring_type(const std::string& vl) : std::string(vl) {
            }

            simplestring_type(const std::string::value_type* vl) : std::string(vl) {
            }

            operator octet_sequnce() const {
                return octet_sequnce(begin(), end());
            }

            operator std::string() const {
                return *this;
            }

            static id_type tagid() {
                return TAGID;
            }

        };


        typedef simplestring_type<TYPE_NUMERICSTRING> numericstring_type;
        typedef simplestring_type<TYPE_PRINTABLESTRING> printablestring_type;
        typedef simplestring_type<TYPE_T61STRING> t61string_type;
        typedef simplestring_type<TYPE_VIDEOTEXSTRING> videotexstring_type;
        typedef simplestring_type<TYPE_IA5STRING> ia5string_type;
        typedef simplestring_type<TYPE_GRAPHICSTRING> graphicstring_type;
        typedef simplestring_type<TYPE_OBJECT_DESCRIPTOR> objectdescriptor_type;
        typedef simplestring_type<TYPE_VISIBLESTRING> visiblestring_type;
        typedef simplestring_type<TYPE_GENERALSTRING> generalstring_type;

        inline std::ostream& operator<<(std::ostream& stream, const numericstring_type& vl) {
            return stream << vl.operator std::string();
        }

        inline std::ostream& operator<<(std::ostream& stream, const printablestring_type& vl) {
            return stream << vl.operator std::string();
        }

        inline std::ostream& operator<<(std::ostream& stream, const t61string_type& vl) {
            return stream << vl.operator std::string();
        }

        inline std::ostream& operator<<(std::ostream& stream, const videotexstring_type& vl) {
            return stream << vl.operator std::string();
        }

        inline std::ostream& operator<<(std::ostream& stream, const ia5string_type& vl) {
            return stream << vl.operator std::string();
        }

        inline std::ostream& operator<<(std::ostream& stream, const graphicstring_type& vl) {
            return stream << vl.operator std::string();
        }

        inline std::ostream& operator<<(std::ostream& stream, const visiblestring_type& vl) {
            return stream << vl.operator std::string();
        }

        inline std::ostream& operator<<(std::ostream& stream, const generalstring_type& vl) {
            return stream << vl.operator std::string();
        }


        //UNICOD UNI STRING  
        //  32bit

        ///universalstring_type

        class universalstring_type : public std::string {

        public:

            universalstring_type() : std::string() {
            }

            universalstring_type(const std::wstring& vl) : std::string(wstr_to_universalstr(vl)) {
            }

            explicit universalstring_type(const std::string& vl) : std::string(wstr_to_universalstr(utf8_to_wstr(vl))) {
            }

            operator std::wstring() const {
                return universalstr_to_wstr(*this);
            }

            operator octet_sequnce() const {
                return octet_sequnce(begin(), end());
            }

            std::wstring to_wstring() const {
                return universalstr_to_wstr(*this);
            }

            std::string to_utf8() const {
                return wstr_to_utf8(universalstr_to_wstr(*this));
            }

            operator std::string() const {
                return *this;
            }


        };

        inline std::ostream& operator<<(std::ostream& stream, const universalstring_type& vl) {
            return stream << vl.operator std::string();
        }

        //UNICOD BMP STRING  
        //  16bit

        ///bmpstring_type

        class bmpstring_type : public std::string {

        public:

            bmpstring_type() : std::string() {
            }

            bmpstring_type(const std::wstring& vl) : std::string(wstr_to_bmpstr(vl)) {
            }

            explicit bmpstring_type(const std::string& vl) : std::string(wstr_to_bmpstr(utf8_to_wstr(vl))) {
            }

            operator std::wstring() const {
                return bmpstr_to_wstr(*this);
            }

            operator octet_sequnce() const {
                return octet_sequnce(begin(), end());
            }

            std::wstring to_wstring() const {
                return bmpstr_to_wstr(*this);
            }

            std::string to_utf8() const {
                return wstr_to_utf8(bmpstr_to_wstr(*this));
            }

            operator std::string() const {
                return *this;
            }



        };

        inline std::ostream& operator<<(std::ostream& stream, const bmpstring_type& vl) {
            return stream << vl.operator std::string();
        }

        //  time types


        ///  UTCTIME_TIME TYPE 

        typedef boost::posix_time::ptime utctime_type;

        octet_sequnce from_utctime(const utctime_type& val);

        utctime_type to_utctime(const octet_sequnce& val);

        inline utctime_type now_generator() {
            return boost::posix_time::microsec_clock::universal_time();
        }

        // inline utctime_type nowtest_generator() {
        //      return boost::posix_time::ptime(boost::gregorian::date(2012,11,29));
        //}            


        ///  GENERALSED_TIME TYPE  

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


        octet_sequnce from_gentime(const gentime_type& val);

        gentime_type to_gentime(const octet_sequnce& val);

        std::ostream& operator<<(std::ostream& stream, const gentime_type& vl);




        //////

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


        // tag traits

        ;

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




        //  tag class

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

        inline std::ostream& operator<<(std::ostream& stream, const tag& vl) {
            return stream << "TAG: " << vl.id() << " mask:" << vl.mask() << '\n';
        }












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




        /////////////////////////////////////////////////////////////////////////////

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







        /////////////////////////////////////////////////////////////////////////////

        template<typename S>
        class optional_explicit_value {

        public:

            typedef boost::shared_ptr<S> T;
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




        /////////////////////////////////////////////////////////////////////////////

        template<typename S>
        class optional_implicit_value {

        public:

            typedef boost::shared_ptr<S> T;
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


        ////////////////////////////////////////////////////////////////////////////

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

            T * operator-> () const // never throws
            {
                return value_.get();
            }

            const boost::shared_ptr<T>& shared_value() const {
                return value_;
            }

            boost::shared_ptr<T>& shared_value() {
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
            boost::shared_ptr<T> value_;
        };


        ////////////////////////////////////////////////////////////////////////////

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

            T * operator-> () const // never throws
            {
                return *value_.get();
            }

            const boost::shared_ptr<T>& shared_value() const {
                return value_;
            }

            boost::shared_ptr<T>& shared_value() {
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
            boost::shared_ptr<T> value_;
        };



        //////////////////////////////////////////////////////////////////////////////////////////////////////       

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

                choice_holder() : base_choice_holder(static_cast<int> (0)), val_(boost::shared_ptr<T>()) {
                }

                choice_holder(T* vl, int ID = 0) : base_choice_holder(static_cast<int> (ID)), val_(boost::shared_ptr<T>(vl)) {
                }

                choice_holder(boost::shared_ptr<T> vl, int ID = 0) : base_choice_holder(static_cast<int> (ID)), val_(vl) {
                }

                boost::shared_ptr<T>& value() {
                    return val_;
                }

                const boost::shared_ptr<T>& value() const {
                    return val_;
                }

                virtual bool empty() const {
                    return false;
                }

            private:
                boost::shared_ptr<T> val_;
            };


            typedef boost::shared_ptr<base_choice_holder> type_ptr;

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
            boost::shared_ptr<T>& value(bool isinput, E tp) {
                typedef choice_holder<T> choice_holder_type;
                if (isinput)
                    set(new T(), tp);
                return boost::static_pointer_cast< choice_holder_type > (val_)->value();
            }

            template<typename T>
            boost::shared_ptr<T> get(E ID) const {
                typedef choice_holder<T> choice_holder_type;
                return (type() == ID) ?
                        boost::static_pointer_cast< choice_holder_type > (val_)->value() :
                        boost::shared_ptr<T > ();
            }

            template<typename T>
            void set(T* vl, E ID) {
                val_ = type_ptr(new choice_holder<T > (vl, static_cast<int> (ID)));
            }

            template<typename T>
            void set(boost::shared_ptr<T> vl, E ID) {
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

        template<typename T>
        struct value_holder {

            value_holder() : internal_(new T()) {
            }

            explicit value_holder(const T & vl) :
            internal_(new T(vl)) {
            }

            explicit value_holder(boost::shared_ptr<T> vl) :
            internal_(vl ? vl : boost::shared_ptr<T>(new T())) {
            }

            T& operator*() const {
                return *internal_;
            }

            T& operator=(const T & vl) {
                internal_ = boost::shared_ptr<T > (new T(vl));
                return *internal_;
            }

            T& operator=(boost::shared_ptr<T> vl) {
                if (vl)
                    internal_ = vl;
                return *internal_;
            }

            boost::shared_ptr<T>& get_shared() {
                return internal_;
            }

            T * operator-> () const {
                return internal_.get();
            }


        private:

            boost::shared_ptr<T> internal_;
        };

        template<typename T, const T& DT>
        struct default_holder {

            default_holder()  {
            }

            explicit default_holder(const T & vl) :
            internal_(vl != DT ? new T(vl) : boost::shared_ptr<T>()) {
            }

            explicit default_holder(boost::shared_ptr<T> vl) :
            internal_(vl ? (((*vl) != DT) ? vl : boost::shared_ptr<T>()) : vl) {
            }

            const T& operator*() const {
                if (internal_)
                    return*internal_;
                return DT;
            }

            const T& operator=(const T & vl) {
                internal_ = (vl != DT) ? boost::shared_ptr<T > (new T(vl)) : boost::shared_ptr<T>();
                if (internal_)
                    return*internal_;
                return DT;
            }

            const T& operator=(boost::shared_ptr<T> vl) {
                internal_ = vl;
                if (internal_)
                    return*internal_;
                return DT;
            }

            boost::shared_ptr<T>& get_shared() {
                return internal_;
            }

            T * operator-> () const {
                return internal_.get();
            }
            

        private:

            boost::shared_ptr<T> internal_;

        };
        
        
        
          
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        template<typename T, T MIN, T MAX, bool EXT>
        struct int_constrainter {

            enum encodetype {
                nulloctet,
                halfoctet,
                oneoctet,
                twooctet,
                undeflen
            };
                    
            int_constrainter(T& vl) : value_(vl) {
            }
            
            static T min() {
                return MIN;
            }            
            
            static T max() {
                return MAX;
            }         
            
            static bool can_extended() {
                return EXT;
            }                  
            
            static boost::uint64_t range() {
                return MAX - MIN;
            }
            
            static bool null_range() {
                return MAX = MIN;
            }            
            
            static encodetype type(){
                boost::uint64_t rng=range();
                if (rng){
                    if (rng<0xFF)
                        return halfoctet; 
                    else if (rng>0xFF)
                        return twooctet;
                    return rng==0xFF ? oneoctet : undeflen;
                }
                return nulloctet;
            }
            
            T& value() {
                return value_;
            }
            
            bool extended() const {
                return ((value_<MIN) || (value_>MAX));
            }           
            
            const T& value() const {
                return value_;
            }  
            
            
            T sendval() const {
                bool ext = extended();
                if (can_extended())
                    return ext ? value_ : (value_ - MIN);
                return !ext ? (value_ - MIN) : (value_ < MIN ? 0 :  range());
            }
            
            static std::size_t bitsize(){
                boost::uint64_t rng=range();
                if (rng) {
                    std::size_t rslt= 1;
                    while(rng>>=1)
                        rslt++;
                    return rslt;
                }
            return 0;    
            }
                     

            
        private:
            
            T& value_;

        };
        
        
        template<typename Archive, typename T>
        inline bool bind_constraints(Archive & arch, T& vl, const T& MIN, const T& MAX) {
            std::size_t tst = arch.size();
            arch & int_constrainter<T, MIN, MAX, true> (vl);
            return (arch.size() != tst);
        }       
        
  
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        
        template<typename Archive, typename T>
        inline bool bind_basic(Archive & arch, T& vl) {
            std::size_t tst = arch.size();
            arch & implicit_value<T > (vl);
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_basic(Archive & arch, boost::shared_ptr<T>& vl) {
            std::size_t tst = arch.size();
            arch & optional_implicit_value<T > (vl);
            return (arch.size() != tst);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_basic(Archive & arch, implicit_typedef<T, Tag, ID, TYPE>& vl) {
            std::size_t tst = arch.size();
            arch & implicit_value<T > (vl.value(), ID, TYPE);
            return (arch.size() != tst);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_basic(Archive & arch, explicit_typedef<T, Tag, ID, TYPE>& vl) {
            std::size_t tst = arch.size();
            arch & explicit_value<T > (vl.value(), ID, TYPE);
            return (arch.size() != tst);
        }


        

        template<typename Archive, typename T>
        inline bool bind_explicit(Archive & arch, T& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            arch & explicit_value<T > (vl, id, type);
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_explicit(Archive & arch, boost::shared_ptr<T>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            arch & optional_explicit_value<T > (vl, id, type);
            return (arch.size() != tst);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_explicit(Archive & arch, explicit_typedef<T, Tag, ID, TYPE>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            arch & explicit_value< explicit_value<T > > (explicit_value<T > (vl.value(), ID, TYPE), id, type);
            return (arch.size() != tst);
        }


        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_explicit(Archive & arch, implicit_typedef<T, Tag, ID, TYPE>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            arch & explicit_value< implicit_value<T > > (implicit_value<T > (vl.value(), ID, TYPE), id, type);
            return (arch.size() != tst);
        }
        
        
        
        
        
        template<typename Archive, typename T>
        inline bool bind_implicit(Archive & arch, T& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            arch & implicit_value<T > (vl, id, type);
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_implicit(Archive & arch, boost::shared_ptr<T>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            arch & optional_implicit_value<T > (vl, id, type);
            return (arch.size() != tst);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_implicit(Archive & arch, explicit_typedef<T, Tag, ID, TYPE>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            arch & explicit_value<T > (vl.value(), id, type);
            return (arch.size() != tst);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_implicit(Archive & arch, implicit_typedef<T, Tag, ID, TYPE>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            arch & implicit_value<T > (vl.value(), id, type);
            return (arch.size() != tst);
        }

        
        
        

        template<typename Archive, typename T>
        inline bool bind_choice(Archive & arch, T& vl) {
            std::size_t tst = arch.size();
            vl.serialize(arch);
            return (arch.size() != tst);
        }

       template<typename Archive, typename T>
        inline bool bind_choice(Archive & arch, const T& vl) {
            std::size_t tst = arch.size();
            const_cast<T*> (&(vl))->serialize(arch);
            return (arch.size() != tst);
        }


        template<typename Archive, typename T>
        inline bool bind_choice(Archive & arch, boost::shared_ptr< T >& vl) {
            if (!vl) {
                if (arch.__input__())
                    vl = boost::shared_ptr< T > (new T());
                else
                    return false;
            }
            if (bind_choice(arch, *vl))
                return true;
            vl.reset();
            return false;
        }

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

                template<typename T > Encoding_type(boost::shared_ptr< T> vl, Encoding_type_enum enm) :
                        ITU_T_CHOICE(Encoding_type_enum) (vl, static_cast<int> (enm)) {
                }

                ITU_T_CHOICES_DECL(single_ASN1_type, any_type, Encoding_type_single_ASN1_type); // primitive
                ITU_T_CHOICES_DECL(octet_aligned, octetstring_type, Encoding_type_octet_aligned); // primitive
                ITU_T_CHOICES_DECL(arbitrary, bitstring_type, Encoding_type_arbitrary); // primitive

                ITU_T_ARCHIVE_FUNC;
            };


            external_type();

            external_type(const Encoding_type& arg__encoding);

            external_type(boost::shared_ptr< oid_type> arg__direct_reference,
                    boost::shared_ptr< int> arg__indirect_reference,
                    boost::shared_ptr< objectdescriptor_type> arg__data_value_descriptor,
                    boost::shared_ptr< Encoding_type> arg__encoding);

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

                template<typename T > Identification_type(boost::shared_ptr< T> vl, Identification_type_enum enm) :
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

                template<typename T > Identification_type(boost::shared_ptr< T> vl, Identification_type_enum enm) :
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

ITU_T_CHOICE_REGESTRATE(boost::asn1::external_type::Encoding_type)
ITU_T_CHOICE_REGESTRATE(boost::asn1::embeded_type::Identification_type);
ITU_T_CHOICE_REGESTRATE(boost::asn1::characterstring_type::Identification_type);

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif	/* _BOOST_ASN1_IMPLEMENTATIUON_H_ */

