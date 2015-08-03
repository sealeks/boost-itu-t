//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef ITU_X690BOOST__H
#define	ITU_X690BOOST__H

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)



#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/x22X/selectors.hpp>
#include <boost/itu/detail/error.hpp>
#include <boost/itu/x69X/x69x.hpp>


#define ITU_T_BIND_TAG(var)    boost::asn1::bind_basic(arch, var)
#define ITU_T_IMPLICIT_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::CONTEXT_CLASS)
#define ITU_T_IMPLICIT_APPLICATION_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::APPLICATION_CLASS)
#define ITU_T_IMPLICIT_PRIVATE_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::PRIVATE_CLASS)
#define ITU_T_IMPLICIT_UNIVERSAL_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::UNIVERSAL_CLASS) 
#define ITU_T_BIND_IMPLICIT(var, tag, cls)    boost::asn1::bind_implicit(arch, var, tag, cls) 
#define ITU_T_EXPLICIT_TAG(var, tag)    boost::asn1::bind_explicit(arch, var, tag, boost::asn1::CONTEXT_CLASS)
#define ITU_T_EXPLICIT_APPLICATION_TAG(var, tag)    boost::asn1::bind_explicit(arch, var, tag, boost::asn1::APPLICATION_CLASS)  
#define ITU_T_EXPLICIT_PRIVATE_TAG(var, tag)    boost::asn1::bind_explicit(arch, var, tag, boost::asn1::PRIVATE_CLASS)
#define ITU_T_EXPLICIT_UNIVERSAL_TAG(var, tag)    boost::asn1::bind_explicit(arch, var, tag, boost::asn1::UNIVERSAL_CLASS)
#define ITU_T_BIND_EXPLICIT(var, tag, cls)    boost::asn1::bind_explicit(arch, var, tag, cls)
#define ITU_T_BIND_CHOICE(var)    boost::asn1::bind_choice(arch, var)
#define ITU_T_CHOICE_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::CONTEXT_CLASS)
#define ITU_T_CHOICE_APPLICATION_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::APPLICATION_CLASS)
#define ITU_T_CHOICE_PRIVATE_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::PRIVATE_CLASS)
#define ITU_T_CHOICE_UNIVERSAL_TAG(var, tag)    boost::asn1::bind_implicit(arch, var, tag, boost::asn1::APPLICATION_CLASS)
#define ITU_T_BIND_CHOICE_TAG(var, tag, cls)    boost::asn1::bind_implicit(arch, var, tag, cls)
#define ITU_T_BIND_PREFIXED(var, hlpr) boost::asn1::bind_prefixed(arch, var, hlpr ## __prefixed__helper)

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
                return boost::asn1::bind_choice(arch, const_cast<regtype&>(vl));\
            }\
        };\
                }\
            }\
            
#define ITU_T_DEFINE_OUT_TIME_NTYPE(nm) template<std::size_t N> void operator&(const nm <N>& vl) {\
                    direct_serialize(vl, *this);}

#define ITU_T_DEFINE_IN_TIME_NTYPE(nm) template<std::size_t N> void operator&(nm <N>& vl) {\
                    direct_serialize(vl, *this);}

namespace boost {
    namespace asn1 {

        struct CENTURY_ENCODING;
        struct ANY_CENTURY_ENCODING;
        struct YEAR_ENCODING;
        struct ANY_YEAR_ENCODING;
        struct YEAR_MONTH_ENCODING;
        struct ANY_YEAR_MONTH_ENCODING;
        struct DATE_ENCODING;
        struct ANY_DATE_ENCODING;
        struct YEAR_DAY_ENCODING;
        struct ANY_YEAR_DAY_ENCODING;
        struct YEAR_WEEK_ENCODING;
        struct ANY_YEAR_WEEK_ENCODING;
        struct YEAR_WEEK_DAY_ENCODING;
        struct ANY_YEAR_WEEK_DAY_ENCODING;
        struct HOURS_ENCODING;
        struct HOURS_UTC_ENCODING;
        struct HOURS_AND_DIFF_ENCODING;
        struct TIME_DIFFERENCE;
        struct MINUTES_ENCODING;
        struct MINUTES_UTC_ENCODING;
        struct MINUTES_AND_DIFF_ENCODING;
        struct TIME_OF_DAY_ENCODING;
        struct TIME_OF_DAY_UTC_ENCODING;
        struct TIME_OF_DAY_AND_DIFF_ENCODING;
        template<std::size_t N> struct HOURS_AND_FRACTION_ENCODING;
        template<std::size_t N> struct HOURS_UTC_AND_FRACTION_ENCODING;
        template<std::size_t N> struct HOURS_AND_DIFF_AND_FRACTION_ENCODING;
        template<std::size_t N> struct MINUTES_AND_FRACTION_ENCODING;
        template<std::size_t N> struct MINUTES_UTC_AND_FRACTION_ENCODING;
        template<std::size_t N> struct MINUTES_AND_DIFF_AND_FRACTION_ENCODING;
        template<std::size_t N> struct TIME_OF_DAY_AND_FRACTION_ENCODING;
        template<std::size_t N> struct TIME_OF_DAY_UTC_AND_FRACTION_ENCODING;
        template<std::size_t N> struct TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING;
        struct DURATION_INTERVAL_ENCODING;
        struct REC_DURATION_INTERVAL_ENCODING;
        /*struct MIXED_ENCODING;
        struct DATE_TYPE;
        struct TIME_TYPE;*/

        namespace x690 {

            template<typename T, typename U>
            void direct_serialize(T& val, U& arch) {
                val.serialize(arch);
            }

            template<typename T, typename U>
            void direct_serialize(const T& val, U& arch) {
                const_cast<T&> (val).serialize(arch);
            }



            const std::size_t CER_STRING_MAX_SIZE = 1000;
            // const std::size_t CER_STRING_MAX_SIZE = 2;


            /////// timeconv



            //  size_class

            class size_class {

            public:

                size_class() : size_(0), undefsize_(true) {
                }

                size_class(size_type vl) : size_(vl), undefsize_(false) {
                }

                bool undefsize() const {
                    return undefsize_;
                }

                size_type size() const {
                    return size_;
                }


            private:
                size_type size_;
                bool undefsize_;

            };

            std::ostream& operator<<(std::ostream& stream, const size_class& vl);


            ///////////////////





            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                                                           */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////







            ///////////////////////////////////////////////////////////////////////////////////
            // size_class to X.690


            std::size_t tosize_x690_cast(const size_class& val, octet_sequnce& src);

            octet_sequnce tosize_x690_cast(const size_class& val);

            //////////////////////////////////////////////////////////////////////////////////////////
            ///  archiver                

            class output_coder : public boost::itu::base_output_coder {

                typedef std::pair<iterator_type, iterator_type> iterator_pair;

                struct tlv_info {

                    tlv_info(const tag& t, const iterator_pair & itrs) : tg(t), iterators(itrs) {
                    }
                    tag tg;
                    iterator_pair iterators;
                };

                typedef std::vector<tlv_info> tlv_vector;

                struct stack_item {

                    stack_item(bool isst, const tlv_vector & itrs) : is_set(isst), tlv_iterators(itrs) {
                    }

                    stack_item(bool isst) : is_set(isst) {
                    }

                    stack_item() : is_set(false) {
                    }
                    bool is_set;
                    tlv_vector tlv_iterators;
                };


                typedef std::stack<stack_item > stack_type;

            public:

                output_coder(encoding_rule rul = boost::itu::BER_ENCODING) :
                boost::itu::base_output_coder(rul) {
                    canonical_ = (rule_ == boost::itu::CER_ENCODING);
                }

                template<typename T>
                void operator&(const T& vl) {
                    *this << implicit_value<T > (vl);
                }

                template<typename T>
                void operator&(const explicit_value<T >& vl) {
                    *this << vl;
                }

                template<typename T>
                void operator&(const prefixed_value<T >& vl) {
                    *this << vl;
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const explicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this << explicit_value<T > (vl.value(), ID, TYPE);
                }

                template<typename T>
                void operator&(const implicit_value<T >& vl) {
                    *this << vl;
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const implicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this << implicit_value<T > (vl.value(), ID, TYPE);
                }

                template<typename T>
                void operator&(const sequence_of<T >& vl) {
                    *this << vl;
                }

                template<typename T>
                void operator&(const set_of<T >& vl) {
                    *this << vl;
                }

                void operator&(const CENTURY_ENCODING& vl);
                void operator&(const ANY_CENTURY_ENCODING& vl);
                void operator&(const YEAR_ENCODING& vl);
                void operator&(const ANY_YEAR_ENCODING& vl);
                void operator&(const YEAR_MONTH_ENCODING& vl);
                void operator&(const ANY_YEAR_MONTH_ENCODING& vl);
                void operator&(const DATE_ENCODING& vl);
                void operator&(const ANY_DATE_ENCODING& vl);
                void operator&(const YEAR_DAY_ENCODING& vl);
                void operator&(const ANY_YEAR_DAY_ENCODING& vl);
                void operator&(const YEAR_WEEK_ENCODING& vl);
                void operator&(const ANY_YEAR_WEEK_ENCODING& vl);
                void operator&(const YEAR_WEEK_DAY_ENCODING& vl);
                void operator&(const ANY_YEAR_WEEK_DAY_ENCODING& vl);
                void operator&(const HOURS_ENCODING& vl);
                void operator&(const HOURS_UTC_ENCODING& vl);
                void operator&(const HOURS_AND_DIFF_ENCODING& vl);
                void operator&(const TIME_DIFFERENCE& vl);
                void operator&(const MINUTES_ENCODING& vl);
                void operator&(const MINUTES_UTC_ENCODING& vl);
                void operator&(const MINUTES_AND_DIFF_ENCODING& vl);
                void operator&(const TIME_OF_DAY_ENCODING& vl);
                void operator&(const TIME_OF_DAY_UTC_ENCODING& vl);
                void operator&(const TIME_OF_DAY_AND_DIFF_ENCODING& vl);
                ITU_T_DEFINE_OUT_TIME_NTYPE(HOURS_AND_FRACTION_ENCODING);            
                ITU_T_DEFINE_OUT_TIME_NTYPE(HOURS_UTC_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_OUT_TIME_NTYPE(HOURS_AND_DIFF_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_OUT_TIME_NTYPE(MINUTES_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_OUT_TIME_NTYPE(MINUTES_UTC_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_OUT_TIME_NTYPE(MINUTES_AND_DIFF_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_OUT_TIME_NTYPE(TIME_OF_DAY_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_OUT_TIME_NTYPE(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_OUT_TIME_NTYPE(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING);
                void operator&(const DURATION_INTERVAL_ENCODING& vl);
                void operator&(const REC_DURATION_INTERVAL_ENCODING& vl);
                /*void operator&(const MIXED_ENCODING& vl);
                void operator&(const DATE_TYPE& vl);
                void operator&(const TIME_TYPE& vl);*/

                iterator_type addtag(const tag& tg, bool settype);

                void pop_stack();

                virtual void clear();

            private:

                void sort_tlv(tlv_vector& vct);


                stack_type stack_;

            };



            ////////////////////////////////////////////////////////////////////

            template<typename T>
            inline output_coder& operator<<(output_coder& stream, const T& vl) {
                stream.add(to_x690_cast(vl));
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const explicit_value<T>& vl) {

                stream.addtag(tag(vl.id(), vl.mask() | CONSTRUCTED_ENCODING), (tag_traits<T>::number() == TYPE_SET));
                const_sequences::iterator it = stream.last();

                std::size_t sz = stream.size();
                stream & vl.value();

                sz = stream.size(sz);
                ++it;

                if ((stream.canonical())) {
                    stream.add(tosize_x690_cast(size_class()), it);
                    stream.add(octet_sequnce(2, 0));
                } else
                    stream.add(tosize_x690_cast(size_class(sz)), it);
                stream.pop_stack();
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const explicit_value< sequence_of<T> >& vl) {
                return stream << implicit_value<sequence_of<T> >(vl.value(), vl.id(), vl.type());
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const explicit_value< set_of<T> >& vl) {
                return stream << implicit_value<set_of<T> >(vl.value(), vl.id(), vl.type());
            }

            template<typename T>
            void write_prexed(output_coder& stream, const prefixed_value<T>& vl, std::size_t nestlvl) {
                if (!nestlvl) {
                    if (vl.is_explicit())
                        stream << explicit_value<T>(vl.value(), vl.helper().vect.front().first, vl.helper().vect.front().second);
                    else
                        stream << implicit_value<T>(vl.value(), vl.helper().vect.front().first, vl.helper().vect.front().second);
                } else {

                    stream.addtag(tag(vl.helper().vect[nestlvl].first, from_cast(vl.helper().vect[nestlvl].second) | CONSTRUCTED_ENCODING),
                            (tag_traits<T>::number() == TYPE_SET));

                    const_sequences::iterator it = stream.last();

                    std::size_t sz = stream.size();

                    write_prexed(stream, vl, nestlvl - 1);

                    sz = stream.size(sz);
                    ++it;

                    if ((stream.canonical())) {
                        stream.add(tosize_x690_cast(size_class()), it);
                        stream.add(octet_sequnce(2, 0));
                    } else
                        stream.add(tosize_x690_cast(size_class(sz)), it);

                    stream.pop_stack();
                }
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const prefixed_value<T>& vl) {
                if (!vl.helper().vect.empty())
                    write_prexed(stream, vl, vl.helper().vect.size() - 1);
                else
                    stream << implicit_value<T>(vl.value());
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const implicit_value<T>& vl) {

                stream.addtag(tag(vl.id(), vl.mask() | CONSTRUCTED_ENCODING), (tag_traits<T>::number() == TYPE_SET));
                const_sequences::iterator it = stream.last();

                std::size_t sz = stream.size();
                const_cast<T*> (&(vl.value()))->serialize(stream);
                sz = stream.size(sz);
                ++it;


                if (stream.canonical()) {
                    stream.add(tosize_x690_cast(size_class()), it);
                    stream.add(octet_sequnce(2, 0));
                } else
                    stream.add(tosize_x690_cast(size_class(sz)), it);
                stream.pop_stack();
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const implicit_value<sequence_of<T> >& vl) {

                stream.addtag(tag(vl.id(), vl.mask() | CONSTRUCTED_ENCODING), false);
                const_sequences::iterator it = stream.last();

                std::size_t sz = stream.size();
                typedef typename sequence_of<T>::const_iterator vect_type_iterator;
                for (vect_type_iterator itr = vl.value().begin(); itr != vl.value().end(); ++itr)
                    boost::asn1::bind_element<T>::op(stream, (*itr));
                sz = stream.size(sz);
                ++it;

                if (stream.canonical()) {
                    stream.add(tosize_x690_cast(size_class()), it);
                    stream.add(octet_sequnce(2, 0));
                } else
                    stream.add(tosize_x690_cast(size_class(sz)), it);
                stream.pop_stack();
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const implicit_value<set_of<T> >& vl) {

                stream.addtag(tag(vl.id(), vl.mask() | CONSTRUCTED_ENCODING), false);
                const_sequences::iterator it = stream.last();

                std::size_t sz = stream.size();
                typedef typename set_of<T>::const_iterator vect_type_iterator;
                for (vect_type_iterator itr = vl.value().begin(); itr != vl.value().end(); ++itr)
                    boost::asn1::bind_element<T>::op(stream, (*itr));
                sz = stream.size(sz);
                ++it;

                if (stream.canonical()) {
                    stream.add(tosize_x690_cast(size_class()), it);
                    stream.add(octet_sequnce(2, 0));
                } else
                    stream.add(tosize_x690_cast(size_class(sz)), it);
                stream.pop_stack();
                return stream;
            }

            template<typename T>
            output_coder& primitive_serialize(output_coder& stream, const implicit_value<T>& vl) {

                stream.addtag(tag(vl.id(), vl.mask()), (tag_traits<T>::number() == TYPE_SET));
                const_sequences::iterator it = stream.last();

                std::size_t sz = stream.size();
                stream << vl.value();
                sz = stream.size(sz);
                ++it;

                stream.add(tosize_x690_cast(size_class(sz)), it);
                stream.pop_stack();
                return stream;
            }






            ////////////////// STRING REALIZATION

            template<typename T>
            void x690_string_to_stream_cast(const T& val, output_coder& stream, octet_type lentype) {
                if (!lentype) {
                    stream.add(val);
                    return;
                } else {

                    typedef typename T::const_iterator const_iterator_type;
                    typedef typename T::difference_type difference_type;

                    const_iterator_type it = val.begin();
                    while (it != val.end()) {
                        stream.addtag(tag(tag_traits<T>::number()), false);
                        difference_type diff = std::distance(it, val.end());
                        if (diff >static_cast<difference_type> (CER_STRING_MAX_SIZE)) {
                            diff = static_cast<difference_type> (CER_STRING_MAX_SIZE);
                            stream.add(tosize_x690_cast(size_class(static_cast<std::size_t> (diff))));
                        } else {
                            stream.add(tosize_x690_cast(size_class(static_cast<std::size_t> (diff))));
                        }
                        stream.add(octet_sequnce(it, it + diff));
                        it = it + diff;
                        stream.pop_stack();
                    }
                }
            }


            template<>
            void x690_string_to_stream_cast(const bit_string& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const octet_string& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const utf8_string& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const oid_iri_type& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const reloid_iri_type& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const bmp_string& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const universal_string& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const numeric_string& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const printable_string& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const t61_string & val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const videotex_string& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const ia5_string& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const graphic_string& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const object_descriptor & val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const visible_string& val, output_coder& stream, octet_type lentype);

            template<>
            void x690_string_to_stream_cast(const general_string& val, output_coder& stream, octet_type lentype);

            template<typename T>
            output_coder& stringtype_writer(output_coder& stream, const T& vl, id_type id, octet_type mask) {

                std::size_t strsz = vl.size();
                if (tag_traits<T>::number() == TYPE_BMPSTRING)
                    strsz *= 2;
                if (tag_traits<T>::number() == TYPE_UNIVERSALSTRING)
                    strsz *= 4;

                octet_type construct = strsz < (tag_traits<T>::number() == TYPE_BITSTRING ? (CER_STRING_MAX_SIZE - 1) : CER_STRING_MAX_SIZE)
                        ? PRIMITIVE_ENCODING : (stream.canonical() ? CONSTRUCTED_ENCODING : PRIMITIVE_ENCODING);

                stream.addtag(tag(id, mask | construct), false);
                const_sequences::iterator it = stream.last();

                std::size_t sz = stream.size();
                x690_string_to_stream_cast(vl, stream, construct);
                sz = stream.size(sz);
                ++it;

                if (construct) {
                    stream.add(tosize_x690_cast(size_class()), it);
                    stream.add(octet_sequnce(2, 0));
                } else
                    stream.add(tosize_x690_cast(size_class(sz)), it);
                stream.pop_stack();
                return stream;
            }



            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int8_t>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint8_t>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int16_t>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint16_t>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int32_t>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint32_t>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int64_t>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint64_t>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<enumerated>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<float>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<double>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<long double>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<bool>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<null_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<oid_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<reloid_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<any_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<bit_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<octet_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<utf8_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<oid_iri_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<reloid_iri_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<numeric_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<printable_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<t61_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<videotex_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<ia5_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<graphic_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<object_descriptor>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<visible_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<general_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<universal_string>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<bmp_string>& vl);


            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<utctime>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<gentime>& vl);




            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*INPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////




            /////  CAST FROM AND TO TYPE



            ///////////////////////////////////////////////////////////////////////////////////
            // size_class from X.690

            std::size_t size_x690_cast(size_class& val, const mutable_sequences& src, mutable_sequences::const_iterator bit, std::size_t beg = 0);



            //////////////////////////////////////////////////////////
            //   archiver

            class input_coder : public boost::itu::base_input_coder {

                struct tlv_size {

                    tlv_size(bool def, std::size_t sz) : defined(def), size(sz) {
                    }
                    bool defined;
                    std::size_t size;
                };

                struct tlv_item {

                    tlv_item(bool st, const tlv_size & sz) : is_set(st), sizeinfo(sz) {
                    }
                    bool is_set;
                    tlv_size sizeinfo;
                };


                typedef std::stack<tlv_item> tlv_stack;


            public:

                input_coder(encoding_rule rul = boost::itu::BER_ENCODING) :
                boost::itu::base_input_coder(rul) {
                }

                template<typename T>
                void operator&(T& vl) {
                    implicit_value<T > tmpvl(vl);
                    *this >> tmpvl;
                }

                template<typename T>
                void operator&(explicit_value<T >& vl) {
                    *this >> vl;
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(explicit_typedef <T, Tag, ID, TYPE>& vl) {
                    explicit_value<T > tmpvl(vl.value(), ID, TYPE);
                    *this >> tmpvl;
                }

                template<typename T>
                void operator&(optional_explicit_value<T >& vl) {
                    *this >> vl;
                }

                template<typename T>
                void operator&(implicit_value<T >& vl) {
                    *this >> vl;
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(implicit_typedef <T, Tag, ID, TYPE>& vl) {
                    implicit_value<T > tmpvl(vl.value(), ID, TYPE);
                    *this >> tmpvl;
                }

                template<typename T>
                void operator&(optional_implicit_value<T >& vl) {
                    *this >> vl;
                }

                template<typename T>
                void operator&(prefixed_value<T >& vl) {
                    *this >> vl;
                }

                template<typename T>
                void operator&(optional_prefixed_value<T >& vl) {
                    *this >> vl;
                }

                template<typename T>
                void operator&(sequence_of<T >& vl) {
                    *this >> vl;
                }

                template<typename T>
                void operator&(set_of<T >& vl) {
                    *this >> vl;
                }

                void operator&(CENTURY_ENCODING& vl);
                void operator&(ANY_CENTURY_ENCODING& vl);
                void operator&(YEAR_ENCODING& vl);
                void operator&(ANY_YEAR_ENCODING& vl);
                void operator&(YEAR_MONTH_ENCODING& vl);
                void operator&(ANY_YEAR_MONTH_ENCODING& vl);
                void operator&(DATE_ENCODING& vl);
                void operator&(ANY_DATE_ENCODING& vl);
                void operator&(YEAR_DAY_ENCODING& vl);
                void operator&(ANY_YEAR_DAY_ENCODING& vl);
                void operator&(YEAR_WEEK_ENCODING& vl);
                void operator&(ANY_YEAR_WEEK_ENCODING& vl);
                void operator&(YEAR_WEEK_DAY_ENCODING& vl);
                void operator&(ANY_YEAR_WEEK_DAY_ENCODING& vl);
                void operator&(HOURS_ENCODING& vl);
                void operator&(HOURS_UTC_ENCODING& vl);
                void operator&(HOURS_AND_DIFF_ENCODING& vl);
                void operator&(TIME_DIFFERENCE& vl);
                void operator&(MINUTES_ENCODING& vl);
                void operator&(MINUTES_UTC_ENCODING& vl);
                void operator&(MINUTES_AND_DIFF_ENCODING& vl);
                void operator&(TIME_OF_DAY_ENCODING& vl);
                void operator&(TIME_OF_DAY_UTC_ENCODING& vl);
                void operator&(TIME_OF_DAY_AND_DIFF_ENCODING& vl);
                ITU_T_DEFINE_IN_TIME_NTYPE(HOURS_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_IN_TIME_NTYPE(HOURS_UTC_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_IN_TIME_NTYPE(HOURS_AND_DIFF_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_IN_TIME_NTYPE(MINUTES_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_IN_TIME_NTYPE(MINUTES_UTC_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_IN_TIME_NTYPE(MINUTES_AND_DIFF_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_IN_TIME_NTYPE(TIME_OF_DAY_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_IN_TIME_NTYPE(TIME_OF_DAY_UTC_AND_FRACTION_ENCODING);
                ITU_T_DEFINE_IN_TIME_NTYPE(TIME_OF_DAY_AND_DIFF_AND_FRACTION_ENCODING);
                void operator&(DURATION_INTERVAL_ENCODING& vl);
                void operator&(REC_DURATION_INTERVAL_ENCODING& vl);
                /*void operator&(MIXED_ENCODING& vl);
                void operator&(DATE_TYPE& vl);
                void operator&(TIME_TYPE& vl);*/

                tag test_tl(size_class& sz);

                bool parse_tl(const tag& tg, size_class& rsltsz, bool settype, bool optional = false);

                std::size_t stack_size();

                virtual int test_id() {
                    tag tmptag;
                    if (tag_x690_cast(tmptag, buffers(), buffers().begin()))
                        return tmptag.id();
                    else
                        return tag::null_tag;
                }

                virtual int test_class() {
                    tag tmptag;
                    if (tag_x690_cast(tmptag, buffers(), buffers().begin()))
                        return tmptag.mask() & 0xC0;
                    else
                        return tag::null_tag;
                }

                bool parse_tl(const tag& tg, bool settype, bool optional = false) {
                    size_class rsltsz;
                    return parse_tl(tg, rsltsz, settype, optional);
                }

                void pop_stack();

                bool next(std::size_t & sz) const;

            private:


                tlv_stack stack_;

            };

            template<typename T>
            input_coder& operator>>(input_coder& stream, explicit_value<T>& vl) {

                if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET)) {
                    stream & vl.value();
                    stream.pop_stack();
                    return stream;
                }
                throw boost::system::system_error(boost::itu::ER_BEDSEQ);
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, explicit_value< sequence_of<T> >& vl) {
                implicit_value<sequence_of<T> > tmpvl(vl.value(), vl.id(), vl.type());
                return stream >> tmpvl;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, explicit_value< set_of<T> >& vl) {
                implicit_value< set_of<T> > tmpvl(vl.value(), vl.id(), vl.type());
                return stream >> tmpvl;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, optional_explicit_value<T>& vl) {
                if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET, true)) {
                    vl.value() = boost::shared_ptr<T > (new T());
                    explicit_value<T > tmpvl(*vl.value(), vl.id(), vl.type());
                    stream & tmpvl;
                    //stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, optional_explicit_value< sequence_of<T> >& vl) {
                if (stream.parse_tl(vl, false, true)) {
                    vl.value() = boost::shared_ptr< sequence_of<T> > (new sequence_of<T > ());
                    explicit_value<sequence_of<T> > tmpvl(*vl.value(), vl.id(), vl.type());
                    stream >> tmpvl;
                    //stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, optional_explicit_value< set_of<T> >& vl) {
                if (stream.parse_tl(vl, false, true)) {
                    vl.value() = boost::shared_ptr< set_of<T> > (new set_of<T > ());
                    explicit_value<set_of<T> > tmpvl(*vl.value(), vl.id(), vl.type());
                    stream >> tmpvl;
                    //stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, implicit_value<T>& vl) {

                if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET)) {
                    vl.value().serialize(stream);
                    stream.pop_stack();
                    return stream;
                }
                throw boost::system::system_error(boost::itu::ER_BEDSEQ);
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, implicit_value< sequence_of<T> >& vl) {
                size_class tmpsize;
                if (stream.parse_tl(vl, tmpsize, false)) {
                    std::size_t beg = stream.size();
                    if (tmpsize.undefsize()) {
                        while (!stream.is_endof() && stream.size()) {
                            T tmp;
                            boost::asn1::bind_element<T>::op(stream, tmp);
                            vl.value().push_back(tmp);
                        }
                    } else {
                        std::size_t sz = tmpsize.size();
                        while ((beg - stream.size()) < sz) {
                            T tmp;
                            boost::asn1::bind_element<T>::op(stream, tmp);
                            vl.value().push_back(tmp);
                        }
                    }
                    stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, implicit_value< set_of<T> >& vl) {
                size_class tmpsize;
                if (stream.parse_tl(vl, tmpsize, false)) {
                    std::size_t beg = stream.size();
                    if (tmpsize.undefsize()) {
                        while (!stream.is_endof() && stream.size()) {
                            T tmp;
                            boost::asn1::bind_element<T>::op(stream, tmp);
                            vl.value().push_back(tmp);
                        }
                    } else {
                        std::size_t sz = tmpsize.size();
                        while ((beg - stream.size()) < sz) {
                            T tmp;
                            boost::asn1::bind_element<T>::op(stream, tmp);
                            vl.value().push_back(tmp);
                        }
                    }
                    stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, optional_implicit_value<T>& vl) {
                if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET, true)) {
                    vl.value() = boost::shared_ptr<T > (new T());
                    implicit_value<T > tmpvl(*vl.value(), vl.id(), vl.type());
                    stream & tmpvl;
                    //stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, optional_implicit_value< sequence_of<T> >& vl) {
                if (stream.parse_tl(vl, false, true)) {
                    vl.value() = boost::shared_ptr< sequence_of<T> > (new sequence_of<T > ());
                    implicit_value<sequence_of<T> > tmpvl(*vl.value(), vl.id(), vl.type());
                    stream >> tmpvl;
                    //stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, optional_implicit_value< set_of<T> >& vl) {
                if (stream.parse_tl(vl, false, true)) {
                    vl.value() = boost::shared_ptr< set_of<T> > (new set_of<T > ());
                    implicit_value<set_of<T> > tmpvl(*vl.value(), vl.id(), vl.type());
                    stream >> tmpvl;
                    //stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            void read_prefixed(input_coder& stream, prefixed_value<T>& vl, std::size_t nestlvl) {
                if (!nestlvl) {
                    if (vl.is_explicit()) {
                        explicit_value<T> tmpvl(vl.value(), vl.helper().vect.front().first, vl.helper().vect.front().second);
                        stream >> tmpvl;
                    } else {
                        implicit_value<T> tmpvl(vl.value(), vl.helper().vect.front().first, vl.helper().vect.front().second);
                        stream >> tmpvl;
                    }
                } else {
                    if (stream.parse_tl(tag(vl.helper().vect[nestlvl].first, from_cast(vl.helper().vect[nestlvl].second) | CONSTRUCTED_ENCODING),
                            tag_traits<T>::number() == TYPE_SET)) {
                        read_prefixed(stream, vl, nestlvl - 1);
                        stream.pop_stack();
                    }
                }
                //throw boost::system::system_error(boost::itu::ER_BEDSEQ);
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, prefixed_value<T>& vl) {
                if (!vl.helper().vect.empty())
                    read_prefixed(stream, vl, vl.helper().vect.size() - 1);
                else {
                    implicit_value<T> tmpvl(vl.value());
                    stream >> tmpvl;
                }
                return stream;
            }

            template<typename T>
            void read_optional_prefixed(input_coder& stream, optional_prefixed_value<T>& vl, std::size_t nestlvl) {
                if (!nestlvl) {
                    if (vl.is_explicit()) {
                        optional_explicit_value<T> tmpvl(vl.value(), vl.helper().vect.front().first, vl.helper().vect.front().second);
                        stream >> tmpvl;
                    } else {
                        optional_implicit_value<T> tmpvl(vl.value(), vl.helper().vect.front().first, vl.helper().vect.front().second);
                        stream >> tmpvl;
                    }
                } else {
                    if (stream.parse_tl(tag(vl.helper().vect[nestlvl].first, from_cast(vl.helper().vect[nestlvl].second) | CONSTRUCTED_ENCODING), true)) {
                        vl.value() = shared_ptr<T>(new T());
                        prefixed_value<T> tmpvl(*(vl.value()), vl.helper());
                        read_prefixed(stream, tmpvl, nestlvl - 1);
                        stream.pop_stack();
                    }
                }
                //throw boost::system::system_error(boost::itu::ER_BEDSEQ);
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, optional_prefixed_value<T>& vl) {
                if (!vl.helper().vect.empty())
                    read_optional_prefixed(stream, vl, vl.helper().vect.size() - 1);
                else {
                    optional_implicit_value<T> tmpvl(vl.value());
                    stream >> tmpvl;
                }
                return stream;
            }



            //////////////////////////////////////////////////////////////////////////////////

            template<typename T>
            input_coder& primitive_deserialize(input_coder& stream, implicit_value<T>& vl) {
                size_class tmpsize;
                if (stream.parse_tl(vl, tmpsize, tag_traits<T>::number() == TYPE_SET)) {
                    octet_sequnce data;
                    std::size_t sz = tmpsize.size();
                    if (boost::itu::row_cast(stream.buffers(), stream.buffers().begin(), data, 0, sz)) {
                        if (from_x690_cast(vl.value(), data)) {
                        }
                    }
                    stream.pop_stack();
                    return stream;
                }
                throw boost::system::system_error(boost::itu::ER_BEDSEQ);
            }

            template<typename T>
            octet_sequnce::iterator reader_setunuse(octet_sequnce& seq, T& vl) {
                return seq.begin();
            }

            template<>
            octet_sequnce::iterator reader_setunuse(octet_sequnce& seq, bit_string& vl);

            template<typename T>
            void stringtype_inserter(T& vl, octet_sequnce::iterator beg, octet_sequnce::iterator end) {
                vl.insert(vl.end(), beg, end);
            }

            template<>
            void stringtype_inserter(universal_string& vl, octet_sequnce::iterator beg, octet_sequnce::iterator end);

            template<>
            void stringtype_inserter(bmp_string& vl, octet_sequnce::iterator beg, octet_sequnce::iterator end);

            template<typename T>
            bool stringtype_reader(input_coder& stream, T& vl, id_type id, octet_type mask) {

                size_class tmpsize;
                tag tmptag = stream.test_tl(tmpsize);
                if (stream.parse_tl(tag(id, mask), tmpsize, false)) {
                    if (tmpsize.undefsize()) {
                        if (tmptag.constructed()) {
                            while (!stream.is_endof() && !stream.buffers().empty()) {
                                if (!stringtype_reader(stream, vl, tag_traits<T>::number(), 0))
                                    return false;
                            }
                            stream.pop_stack();
                            return true;
                        } else {
                            std::size_t sz = 0;
                            if (boost::itu::find_eof(stream.buffers(), stream.buffers().begin(), sz)) {
                                octet_sequnce data;
                                if (boost::itu::row_cast(stream.buffers(), stream.buffers().begin(), data, 0, sz)) {
                                    octet_sequnce::iterator fit = reader_setunuse(data, vl);
                                    stringtype_inserter(vl, fit, data.end());
                                    return true;
                                }
                            }
                            return false;
                        }
                    } else {
                        if (tmptag.constructed()) {
                            while (!stream.buffers().empty()) {
                                if (!stringtype_reader(stream, vl, tag_traits<T>::number(), 0)) {
                                    return true;
                                }
                                stream.pop_stack();
                            }
                            return false;
                        } else {
                            octet_sequnce data;
                            if (boost::itu::row_cast(stream.buffers(), stream.buffers().begin(), data, 0, tmpsize.size())) {
                                octet_sequnce::iterator fit = reader_setunuse(data, vl);
                                stringtype_inserter(vl, fit, data.end());
                                stream.pop_stack();
                                return true;
                            }
                        }
                    }
                }
                return false;
            }


            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<int8_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<uint8_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<int16_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<uint16_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<int32_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<uint32_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<int64_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<uint64_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<enumerated>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<float>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<double>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<long double>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<bool>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<null_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<oid_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<reloid_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<any_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<bit_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<octet_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<utf8_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<numeric_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<printable_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<t61_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<videotex_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<ia5_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<graphic_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<object_descriptor>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<visible_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<general_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<universal_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<bmp_string>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<utctime>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<gentime>& vl);



        }



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        template<typename Archive, typename T>
        inline bool bind_basic(Archive & arch, T& vl) {
            std::size_t tst = arch.size();
            implicit_value<T > tmpvl(vl);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_basic(Archive & arch, value_holder<T>& vl) {
            return bind_basic(arch, *vl);
        }

        template<typename T>
        inline bool bind_basic(boost::asn1::x690::output_coder & arch, boost::shared_ptr<T>& vl) {
            if (static_cast<bool> (vl))
                return bind_basic(arch, *vl);
            return false;
        }

        template<typename T>
        inline bool bind_basic(boost::asn1::x690::input_coder & arch, boost::shared_ptr<T>& vl) {
            std::size_t tst = arch.size();
            optional_implicit_value<T > tmpvl(vl);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename T, const T& DT>
        inline bool bind_basic(boost::asn1::x690::output_coder & arch, default_holder<T, DT>& vl) {
            if (!vl.isdefault())
                return bind_basic(arch, vl.get_shared());
            return false;
        }

        template<typename T, const T& DT>
        inline bool bind_basic(boost::asn1::x690::input_coder & arch, default_holder<T, DT>& vl) {
            return bind_basic(arch, vl.get_shared());
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_basic(Archive & arch, implicit_typedef<T, Tag, ID, TYPE>& vl) {
            std::size_t tst = arch.size();
            implicit_value<T > tmpvl(vl.value(), ID, TYPE);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_basic(Archive & arch, explicit_typedef<T, Tag, ID, TYPE>& vl) {
            std::size_t tst = arch.size();
            explicit_value<T > tmpvl(vl.value(), ID, TYPE);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_explicit(Archive & arch, T& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            explicit_value<T > tmpvl(vl, id, type);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_explicit(Archive & arch, value_holder<T>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            return bind_explicit(arch, *vl, id, type);
        }

        template<typename T>
        inline bool bind_explicit(boost::asn1::x690::output_coder & arch, boost::shared_ptr<T>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            if (static_cast<bool> (vl))
                return bind_explicit(arch, *vl, id, type);
            return false;
        }

        template<typename T>
        inline bool bind_explicit(boost::asn1::x690::input_coder & arch, boost::shared_ptr<T>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            optional_explicit_value<T > tmpvl(vl, id, type);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename T, const T& DT>
        inline bool bind_explicit(boost::asn1::x690::output_coder & arch, default_holder<T, DT>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            if (!vl.isdefault())
                return bind_explicit(arch, vl.get_shared(), id, type);
            return false;
        }

        template<typename T, const T& DT>
        inline bool bind_explicit(boost::asn1::x690::input_coder & arch, default_holder<T, DT>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            return bind_explicit(arch, vl.get_shared(), id, type);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_explicit(Archive & arch, explicit_typedef<T, Tag, ID, TYPE>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            explicit_value< explicit_value<T > > tmpvl(explicit_value<T > (vl.value(), ID, TYPE), id, type);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_explicit(Archive & arch, implicit_typedef<T, Tag, ID, TYPE>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            explicit_value< implicit_value<T > > tmpvl(implicit_value<T > (vl.value(), ID, TYPE), id, type);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_implicit(Archive & arch, T& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            implicit_value<T > tmpvl(vl, id, type);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_implicit(Archive & arch, value_holder<T>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            return bind_implicit(arch, *vl, id, type);
        }

        template<typename T>
        inline bool bind_implicit(boost::asn1::x690::output_coder & arch, boost::shared_ptr<T>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            if (static_cast<bool> (vl))
                return bind_implicit(arch, *vl, id, type);
            return false;
        }

        template<typename T>
        inline bool bind_implicit(boost::asn1::x690::input_coder & arch, boost::shared_ptr<T>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            optional_implicit_value<T > tmpvl(vl, id, type);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename T, const T& DT>
        inline bool bind_implicit(boost::asn1::x690::output_coder & arch, default_holder<T, DT>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            if (!vl.isdefault())
                return bind_implicit(arch, vl.get_shared(), id, type);
            return false;
        }

        template<typename T, const T& DT>
        inline bool bind_implicit(boost::asn1::x690::input_coder & arch, default_holder<T, DT>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            return bind_implicit(arch, vl.get_shared(), id, type);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_implicit(Archive & arch, explicit_typedef<T, Tag, ID, TYPE>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            explicit_value<T > tmpvl(vl.value(), id, type);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_implicit(Archive & arch, implicit_typedef<T, Tag, ID, TYPE>& vl, const id_type& id, const class_type& type = CONTEXT_CLASS) {
            std::size_t tst = arch.size();
            implicit_value<T > tmpvl(vl.value(), id, type);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_prefixed(Archive & arch, T& vl, const prefixed_helper& hlper) {
            std::size_t tst = arch.size();
            prefixed_value<T > tmpvl(vl, hlper);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_prefixed(Archive & arch, value_holder<T>& vl, const prefixed_helper& hlper) {
            return bind_prefixed(arch, *vl, hlper);
        }

        template<typename T>
        inline bool bind_prefixed(boost::asn1::x690::output_coder & arch, boost::shared_ptr<T>& vl, const prefixed_helper& hlper) {
            if (static_cast<bool> (vl))
                return bind_prefixed(arch, *vl, hlper);
            return false;
        }

        template<typename T>
        inline bool bind_prefixed(boost::asn1::x690::input_coder & arch, boost::shared_ptr<T>& vl, const prefixed_helper& hlper) {
            std::size_t tst = arch.size();
            optional_prefixed_value<T > tmpvl(vl, hlper);
            arch & tmpvl;
            return (arch.size() != tst);
        }

        template<typename T, const T& DT>
        inline bool bind_prefixed(boost::asn1::x690::output_coder & arch, default_holder<T, DT>& vl, const prefixed_helper& hlper) {
            if (!vl.isdefault())
                return bind_prefixed(arch, vl.get_shared(), hlper);
            return false;
        }

        template<typename T, const T& DT>
        inline bool bind_prefixed(boost::asn1::x690::input_coder & arch, default_holder<T, DT>& vl, const prefixed_helper& hlper) {
            return bind_prefixed(arch, vl.get_shared(), hlper);
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
            vl.serialize(arch);
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_choice(Archive & arch, value_holder<T>& vl) {
            return bind_choice(arch, *vl);
        }

        template<typename T>
        inline bool bind_choice(boost::asn1::x690::output_coder & arch, boost::shared_ptr< T >& vl) {
            if (!static_cast<bool> (vl))
                return false;
            if (bind_choice(arch, *vl))
                return true;
            vl.reset();
            return false;
        }

        template<typename T>
        inline bool bind_choice(boost::asn1::x690::input_coder & arch, boost::shared_ptr< T >& vl) {
            if (!static_cast<bool> (vl))
                vl = boost::shared_ptr< T > (new T());
            if (bind_choice(arch, *vl))
                return true;
            vl.reset();
            return false;
        }

        template<typename T, const T& DT>
        inline bool bind_choice(boost::asn1::x690::output_coder & arch, default_holder<T, DT>& vl) {
            if (!vl.isdefault())
                return bind_choice(arch, vl.get_shared());
            return false;
        }

        template<typename T, const T& DT>
        inline bool bind_choice(boost::asn1::x690::input_coder & arch, default_holder<T, DT>& vl) {
            return bind_choice(arch, vl.get_shared());
        }




        template<> void external_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void external_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void external_type::Encoding_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void external_type::Encoding_type::serialize(boost::asn1::x690::input_coder& arch);

        template<> void embeded_pdv::serialize(boost::asn1::x690::output_coder& arch);
        template<> void embeded_pdv::serialize(boost::asn1::x690::input_coder& arch);
        template<> void embeded_pdv::Identification_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void embeded_pdv::Identification_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void embeded_pdv::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void embeded_pdv::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void embeded_pdv::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void embeded_pdv::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::input_coder& arch);


        template<> void character_string::serialize(boost::asn1::x690::output_coder& arch);
        template<> void character_string::serialize(boost::asn1::x690::input_coder& arch);
        template<> void character_string::Identification_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void character_string::Identification_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void character_string::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void character_string::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void character_string::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void character_string::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::input_coder& arch);



    }
}

ITU_T_CHOICE_REGESTRATE(boost::asn1::external_type::Encoding_type)
ITU_T_CHOICE_REGESTRATE(boost::asn1::embeded_pdv::Identification_type);
ITU_T_CHOICE_REGESTRATE(boost::asn1::character_string::Identification_type);

#endif	/* ASNBASE_H */

