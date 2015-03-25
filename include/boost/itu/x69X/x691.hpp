//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef ITU_X691BOOST__H
#define	ITU_X691BOOST__H

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)



#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/x22X/selectors.hpp>
#include <boost/itu/detail/error.hpp>


namespace boost {
    namespace asn1 {
        namespace x691 {


            const octet_type NEGATIVE_MARKER = '\x80';
            const octet_type POSITIVE_START = '\xFF';

            const octet_type CONTENT_CONIIUE = '\x80';
            const octet_type UNDEF_BLOCK_SIZE = '\x80';

            const octet_type NAN_REAL_ID = '\x42';
            const octet_type INFINITY_REAL_ID = '\x40';
            const octet_type NEGATINFINITY_REAL_ID = '\x41';
            const octet_type NEGATNULL_REAL_ID = '\x43';

            const std::size_t MAX_SIMPLELENGTH_SIZE = 0x80;
            const std::size_t MAX_DOUBLELENGTH_SIZE = 0x4000;
            const std::size_t MAX_OCTETLENGTH_SIZE = 0x100;
            const std::size_t MAX_SMALL_NN_SIZE = 64;

            const std::size_t FLOAT_MANTISSA_SIZE = 23;
            const std::size_t FLOAT_EXPONENTA_DELT = 127;

            const std::size_t DOUBLE_MANTISSA_SIZE = 52;
            const std::size_t DOUBLE_EXPONENTA_DELT = 1023;

            const std::size_t LONGDOUBLE_MANTISSA_SIZE = 112;
            const std::size_t LONGDOUBLE_EXPONENTA_DELT = 16383;


            const std::size_t CER_STRING_MAX_SIZE = 1000;
            // const std::size_t CER_STRING_MAX_SIZE = 2;


            //////  Endian conv;

            void endian_conv(octet_sequnce& val);

            octet_sequnce endian_conv_conv(const octet_sequnce& val);

            void endian_push_pack(const octet_sequnce& val, octet_sequnce& dst);


            /////// timeconv



            //  size_class

            class size_class {

            public:

                size_class() : size_(0) {
                }

                size_class(size_type vl) : size_(vl) {
                }

                size_type size() const {
                    return size_;
                }

            private:
                size_type size_;
            };

            inline std::ostream& operator<<(std::ostream& stream, const size_class& vl) {
                return stream << "SIZE:  " << vl.size() << '\n';
            }


            ///////////////////////////////////////////////////////////////////////////////////
            // size_class to X.691


            std::size_t to_x691_cast(const size_class& val, octet_sequnce& src);

            octet_sequnce to_x691_cast(const size_class& val);




            //  constrained whole number            

            template<typename T>
            class constrained_wnumber {

            public:

                typedef T internal_type;

                constrained_wnumber(T& vl, const T& min, const T& max) : value_(vl), MIN(min), MAX(max) {
                    if ((vl < MIN) || (vl > MAX))
                        vl = (vl < MIN) ? MIN : MAX;
                }

                const T& min() const {
                    return MIN;
                }

                const T& max() const {
                    return MAX;
                }

                boost::uint64_t range() const {
                    return MAX - MIN;
                }

                bool null_range() const {
                    return MAX = MIN;
                }

                // bitmap for alighned vaiant

                bool is_minimal() const {
                    return (range() <= MAX_OCTETLENGTH_SIZE);
                }

                const internal_type& value() const {
                    return value_;
                }

                boost::uint64_t sendval() const {
                    return value_ - MIN;
                }

                std::size_t bitsize() const {
                    if (boost::uint64_t rng = range()) {
                        std::size_t rslt = 1;
                        while (rng >>= 1)
                            rslt++;
                        return rslt;
                    }
                    return 0;
                }

                std::size_t octetsize() const {
                    if (std::size_t bssz = bitsize())
                        return (bssz - 1) / 8 + 1;
                    return 0;
                }

                bitstring_type as_bitmap() const {
                    std::size_t bssz = bitsize();
                    if (!bssz)
                        return bitstring_type();
                    boost::uint64_t val = sendval();
                    std::size_t octsz = (bssz - 1) / 8 + 1;
                    octet_sequnce tmp = endian_conv_conv(octet_sequnce(static_cast<octet_sequnce::value_type*> ((void*) &val),
                            static_cast<octet_sequnce::value_type*> ((void*) &val) + octsz));
#ifdef BIG_ENDIAN_ARCHITECTURE  
                    ?
#else                    
                    if (bssz % 8)
                        tmp.back() <<= (8 - bssz % 8);
#endif                    
                    return bitstring_type(tmp, (bssz % 8) ? (8 - bssz % 8) : 0);
                }

                octet_sequnce as_octetsequence() const {
                    boost::uint64_t val = sendval();
                    if (std::size_t octsz = octetsize())
                        return endian_conv_conv(octet_sequnce(static_cast<octet_sequnce::value_type*> ((void*) &val),
                            static_cast<octet_sequnce::value_type*> ((void*) &val) + octsz));
                    return octet_sequnce();
                }

                octetstring_type as_octetstring() const {
                    return octetstring_type(as_octetsequence());
                }



            private:

                internal_type& value_;
                const internal_type& MIN;
                const internal_type& MAX;
            };


            //  semiconstrained whole number            

            template<typename T>
            class semiconstrained_wnumber {

            public:

                typedef T internal_type;

                semiconstrained_wnumber(T& vl, const T& min) : value_(vl), MIN(min) {
                    if (vl < MIN)
                        vl = MIN;
                }

                const T& min() const {
                    return MIN;
                }

                const internal_type& value() const {
                    return value_;
                }

                boost::uint64_t sendval() const {
                    return value_ - MIN;
                }

                std::size_t bitsize() const {
                    if (boost::uint64_t rng = sendval()) {
                        std::size_t rslt = 1;
                        while (rng >>= 1)
                            rslt++;
                        return rslt;
                    }
                    return 0;
                }

                std::size_t octetsize() const {
                    if (std::size_t bssz = bitsize())
                        return (bssz - 1) / 8 + 1;
                    return 1;
                }

                octet_sequnce as_octetsequence() const {
                    boost::uint64_t val = sendval();
                    if (std::size_t octsz = octetsize()) {
                        octet_sequnce rslt = to_x691_cast(size_class(octsz));
                        octet_sequnce vl = octet_sequnce(static_cast<octet_sequnce::value_type*> ((void*) &val),
                                static_cast<octet_sequnce::value_type*> ((void*) &val) + octsz);
#ifdef BIG_ENDIAN_ARCHITECTURE  
                        rslt.insert(rslt.end(), vl.begin(), vl.end());
#else                    
                        rslt.insert(rslt.end(), vl.rbegin(), vl.rend());
#endif                         

                        return rslt;
                    }
                    return octet_sequnce(1, '\x0');

                }

                octetstring_type as_octetstring() const {
                    return octetstring_type(as_octetsequence());
                }



            private:

                internal_type& value_;
                const internal_type& MIN;
            };





            //  unconstrained whole number            

            template<typename T>
            class unconstrained_wnumber {

            public:

                typedef T internal_type;

                unconstrained_wnumber(T& vl) : value_(vl) {
                }

                const internal_type& value() const {
                    return value_;
                }

                std::size_t bitsize() const {
                    if (value_ >= 0) {
                        if (T rng = value_) {
                            std::size_t rslt = 1;
                            while (rng >>= 1)
                                rslt++;
                            return rslt;
                        }
                        return 0;
                    } else
                        return sizeof (T)*8;
                }

                std::size_t octetsize() const {
                    if (std::size_t bssz = bitsize())
                        return (bssz - 1) / 8 + 1;
                    return 1;
                }

                octet_sequnce as_octetsequence() const {
                    if (std::size_t octsz = octetsize()) {
                        octet_sequnce rslt = to_x691_cast(size_class(octsz));
                        octet_sequnce vl = octet_sequnce(static_cast<octet_sequnce::value_type*> ((void*) &value()),
                                static_cast<octet_sequnce::value_type*> ((void*) &value()) + octsz);
#ifdef BIG_ENDIAN_ARCHITECTURE  
                        rslt.insert(rslt.end(), vl.begin(), vl.end());
#else                    
                        rslt.insert(rslt.end(), vl.rbegin(), vl.rend());
#endif                         

                        return rslt;
                    }
                    return octet_sequnce(1, '\x0');
                }

                octetstring_type as_octetstring() const {
                    return octetstring_type(as_octetsequence());
                }



            private:

                internal_type& value() {
                    return value_;
                }

                internal_type& value_;
            };





            //  small_nn_wnumber  non-negative whole number

            template<typename T>
            class small_nn_wnumber {

            public:

                typedef T internal_type;

                small_nn_wnumber() : value_(0) {
                }

                small_nn_wnumber(T vl) : value_(vl < 0 ? 0 : vl) {
                }

                const internal_type& value() const {
                    return value_;
                }

                std::size_t bitsize() const {
                    if (value_ >= 0) {
                        if (T rng = value_) {
                            std::size_t rslt = 1;
                            while (rng >>= 1)
                                rslt++;
                            return rslt;
                        }
                        return 0;
                    } else
                        return sizeof (T)*8;
                }

                std::size_t octetsize() const {
                    if (std::size_t bssz = bitsize())
                        return (bssz - 1) / 8 + 1;
                    return 1;
                }

                bool is_minimal() const {
                    return value_<MAX_SMALL_NN_SIZE;
                }

                bitstring_type as_bitmap() const {
                    return /*bitstring_type(false) +*/ bitstring_type(octet_sequnce(1, static_cast<octet_sequnce::value_type> (((value() & 0x3F) << 1) &0x7F)), 1);
                }

                octet_sequnce as_octetsequence() const {
                    if (std::size_t octsz = octetsize()) {
                        octet_sequnce rslt = to_x691_cast(size_class(octsz));
                        octet_sequnce vl = octet_sequnce(static_cast<octet_sequnce::value_type*> ((void*) &value()),
                                static_cast<octet_sequnce::value_type*> ((void*) &value()) + octsz);
#ifdef BIG_ENDIAN_ARCHITECTURE  
                        rslt.insert(rslt.end(), vl.begin(), vl.end());
#else                    
                        rslt.insert(rslt.end(), vl.rbegin(), vl.rend());
#endif                         

                        return rslt;
                    }
                    return octet_sequnce(1, '\x0');
                }

                octetstring_type as_octetstring() const {
                    return octetstring_type(as_octetsequence());
                }




            private:
                internal_type value_;
            };








            ///////////////////





            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                                                           */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////




            /////  CAST FROM AND TO TYPE

            ///////////////////////////////////////////////////////////////////////////////////////////////
            // integer to X.691

            template<typename T>
            std::size_t to_x691_cast(T val, octet_sequnce& src) {
                octet_sequnce tmp;
                bool negat = (val < 0);



#ifdef BIG_ENDIAN_ARCHITECTURE      
                !!!not implement
#else

                if (negat)
                    if (val & (T(1) << (sizeof (T)*8 - 1))) {
                        val &= ~(T(1) << (sizeof (T)*8 - 1));
                        tmp.push_back(static_cast<octet_type> (POSITIVE_START & val));
                        val >>= 8;
                        val |= (T(1) << ((sizeof (T) - 1)*8 - 1));
                    }
                while (val) {
                    tmp.push_back(static_cast<octet_type> (POSITIVE_START & val));
                    val >>= 8;
                }
                if (negat && !tmp.empty())
                    while ((tmp.size() > 1) && (tmp.back() == static_cast<octet_type> (POSITIVE_START)))
                        tmp.pop_back();

                if ((tmp.empty() || (!negat && (tmp.back() & NEGATIVE_MARKER))))
                    tmp.push_back(static_cast<octet_type> (0));
                else {
                    if (negat && !(tmp.back() & NEGATIVE_MARKER))
                        tmp.push_back(static_cast<octet_type> (POSITIVE_START));
                }
                endian_push_pack(tmp, src);

#endif                              
                return tmp.size();
            }

            template<>
            std::size_t to_x691_cast(int8_t val, octet_sequnce& src);

            template<>
            std::size_t to_x691_cast(uint8_t val, octet_sequnce& src);





            ///////////////////////////////////////////////////////////////////////////////////
            // tag to X.691


            std::size_t to_x691_cast(const tag& val, octet_sequnce& src);

            octet_sequnce to_x691_cast(const tag& val);







            ///////////////////////////////////////////////////////////////////////////////////
            // small_nn_wnumber to X.691

            template<typename T>
            std::size_t to_x691_cast(const small_nn_wnumber<T>& val, bitstring_type& src) {
                if (val.value() < MAX_SMALL_NN_SIZE)
                    src = src + bitstring_type(octet_sequnce(1, static_cast<octet_type> (val.value() & 0x3F) << 1), 1);
                else {
                    octet_sequnce tmp;
                    to_x691_cast(val.value(), tmp);
                    src = src + bitstring_type(true) + bitstring_type(to_x691_cast(size_class(tmp.size()))) + bitstring_type(tmp);
                }
                return 0;
            }

            template<typename T>
            bitstring_type to_x691_cast(const small_nn_wnumber<T>& val) {
                if (val.value() < MAX_SMALL_NN_SIZE)
                    return bitstring_type(octet_sequnce(1, static_cast<octet_type> (val.value() & 0x3F) << 1), 1);
                octet_sequnce tmp;
                to_x691_cast(val.value(), tmp);
                return bitstring_type(true) + bitstring_type(to_x691_cast(size_class(tmp.size()))) + bitstring_type(tmp);
            }


            ///////////////////////////////////////////////////////////////////////////////////
            // real to X.691


            template<>
            std::size_t to_x691_cast(double val, octet_sequnce& src);

            template<>
            std::size_t to_x691_cast(float val, octet_sequnce& src);

            template<>
            std::size_t to_x691_cast(long double val, octet_sequnce& src);



            ///////////////////////////////////////////////////////////////////////////////////
            // bool to X.691

            template<>
            std::size_t to_x691_cast(bool val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // null to X.691

            std::size_t to_x691_cast(const null_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // enumerated_type to X.691

            std::size_t to_x691_cast(const enumerated_type& val, octet_sequnce& src);


            ///////////////////////////////////////////////////////////////////////////////////
            // oid to X.691


            std::size_t to_x691_cast(const oid_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // relative oid to X.691


            std::size_t to_x691_cast(const reloid_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // utctime to X.691


            std::size_t to_x691_cast(const utctime_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // gentime to X.691


            std::size_t to_x691_cast(const gentime_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // any_type to X.691


            std::size_t to_x691_cast(const any_type& val, octet_sequnce& src);

            template<typename T>
            octet_sequnce to_x691_cast(const T& val) {
                octet_sequnce rslt;
                to_x691_cast(val, rslt);
                return rslt;
            }


            //////////////////////////////////////////////////////////////////////////////////////////
            ///  archiver                

            class output_coder : public boost::itu::base_output_coder {

            public:

                output_coder(encoding_rule rul = boost::itu::BER_ENCODING) : boost::itu::base_output_coder(), rule_(rul), unaligned_(rul == boost::itu::PER_ALIGNED_ENCODING) {
                }

                virtual encoding_rule rule() const {
                    return rule_;
                }

                bool aligned() const {
                    return !unaligned_;
                }

                bool unaligned() const {
                    return unaligned_;
                }

                template<typename T>
                void operator&(const T& vl) {
                    *this << vl;
                }

                template<typename T>
                void operator&(const num_constrainter<T>& vl) {
                    *this << vl;
                }

                template<typename T>
                void operator&(const explicit_value<T >& vl) {
                    *this << vl.value();
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const explicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this << vl.value();
                }

                template<typename T>
                void operator&(const optional_explicit_value<T >& vl) {
                    *this << vl;
                }

                template<typename T>
                void operator&(const implicit_value<T >& vl) {
                    *this << vl;
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const implicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this << vl.value();
                }

                template<typename T>
                void operator&(const optional_implicit_value<T >& vl) {
                    *this << vl;
                }

                template<typename T>
                void operator&(const std::vector<T >& vl) {
                    *this << vl;
                }

                template<typename T>
                void operator&(const std::deque<T >& vl) {
                    *this << vl;
                }

                bool canonical() const {
                    return rule_ == boost::itu::CER_ENCODING;
                }

            private:

                encoding_rule rule_;
                bool unaligned_;

            };



            ////////////////////////////////////////////////////////////////////

            template<typename T>
            inline output_coder& operator<<(output_coder& stream, const T& vl) {
                //stream.add(to_x691_cast(vl));
                const_cast<T&> (vl).serialize(stream);
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const std::vector<T>& vl) {

                stream.add(to_x691_cast(size_class(vl.size())));

                typedef typename std::vector<T>::const_iterator vect_type_iterator;
                for (vect_type_iterator itr = vl.begin(); itr != vl.end(); ++itr)
                    //boost::asn1::bind_element<T>::op(stream, (*itr));
                    stream & (*itr);

                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const std::deque<T>& vl) {

                stream.add(to_x691_cast(size_class(vl.size())));

                typedef typename std::deque<T>::const_iterator vect_type_iterator;
                for (vect_type_iterator itr = vl.begin(); itr != vl.end(); ++itr)
                    //boost::asn1::bind_element<T>::op(stream, (*itr));
                    stream & (*itr);

                return stream;

            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const num_constrainter<T >& vl) {

                if (vl.can_extended()) {
                    stream.add_bitmap(bitstring_type(vl.extended()));
                    if (vl.extended())
                        return primitive_int_sirialize(stream, vl.value());
                }

                if (vl.null_range())
                    return stream;

                if ((vl.range() <= 0xFFFF) || (stream.unaligned())) {
                    constrained_wnumber<T> tmp(const_cast<T&> (vl.value()), vl.min(), vl.max());
                    if ((stream.unaligned()) || (tmp.is_minimal()))
                        stream.add_bitmap(tmp.as_bitmap(), false);
                    else
                        stream.add(tmp.as_octetsequence());
                    return stream;
                }

                return primitive_int_sirialize(stream, vl.value());
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const num_semiconstrainter<T>& vl) {


                if (vl.can_extended()) {
                    stream.add_bitmap(bitstring_type(vl.extended()));
                    if (vl.extended())
                        return primitive_int_sirialize(stream, vl.value());
                }
                semiconstrained_wnumber<T> tmp(const_cast<T&> (vl.value()), vl.min(), vl.extended());
                stream.add(tmp.as_octetsequence());
                return stream;
            }

            template<typename T>
            output_coder& primitive_int_sirialize(output_coder& stream, const T& vl) {

                bool emp = stream.buffers().empty();
                unconstrained_wnumber<T> tmp(const_cast<T&> (vl));
                stream.add(tmp.as_octetstring());
                return stream;

            }



            ////////////////// STRING REALIZATION

            template<typename T>
            void x691_string_to_stream_cast(const T& val, output_coder& stream, octet_type lentype) {
                /* if (!lentype) {
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
                             stream.add(to_x691_cast(size_class(static_cast<std::size_t> (diff))));
                         } else {
                             stream.add(to_x691_cast(size_class(static_cast<std::size_t> (diff))));
                         }
                         stream.add(octet_sequnce(it, it + diff));
                         it = it + diff;
                         stream.pop_stack();
                     }
                 }*/
            }


            template<>
            void x691_string_to_stream_cast(const bitstring_type& val, output_coder& stream, octet_type lentype);

            template<typename T>
            output_coder& stringtype_writer(output_coder& stream, const T& vl, id_type id, octet_type mask) {



                /*octet_type construct = vl.size()<(tag_traits<T>::number() == TYPE_BITSTRING ? (CER_STRING_MAX_SIZE - 1) : CER_STRING_MAX_SIZE)
                        ? PRIMITIVE_ENCODING : (stream.canonical() ? CONSTRUCTED_ENCODING : PRIMITIVE_ENCODING);

                stream.addtag(tag(id, mask | construct), false);
                const_sequences::iterator it = stream.last();

                std::size_t sz = stream.size();
                x691_string_to_stream_cast(vl, stream, construct);
                sz = stream.size(sz);
                ++it;

                if (construct) {
                    stream.add(to_x691_cast(size_class()), it);
                    stream.add(octet_sequnce(2, 0));
                } else
                    stream.add(to_x691_cast(size_class(sz)), it);
                stream.pop_stack();*/
                return stream;
            }

            template<typename T>
            output_coder& defstring8_writer(output_coder& stream, const T& vl, const std::size_t sz = 0) {
                stream.add(to_x691_cast(size_class(vl.size())));
                stream.add(octet_sequnce(vl.begin(), vl.end()));
                return stream;
            }



            output_coder& operator<<(output_coder& stream, const uint8_t& vl);

            output_coder& operator<<(output_coder& stream, const int8_t& vl);

            output_coder& operator<<(output_coder& stream, const uint16_t& vl);

            output_coder& operator<<(output_coder& stream, const int16_t& vl);

            output_coder& operator<<(output_coder& stream, const uint32_t& vl);

            output_coder& operator<<(output_coder& stream, const int32_t& vl);

            output_coder& operator<<(output_coder& stream, const uint64_t& vl);

            output_coder& operator<<(output_coder& stream, const int64_t& vl);

            output_coder& operator<<(output_coder& stream, const enumerated_type& vl);

            output_coder& operator<<(output_coder& stream, const float& vl);

            output_coder& operator<<(output_coder& stream, const double& vl);

            output_coder& operator<<(output_coder& stream, const long double& vl);

            output_coder& operator<<(output_coder& stream, const bool& vl);

            output_coder& operator<<(output_coder& stream, const null_type& vl);

            output_coder& operator<<(output_coder& stream, const oid_type& vl);

            output_coder& operator<<(output_coder& stream, const reloid_type& vl);

            output_coder& operator<<(output_coder& stream, const any_type& vl);

            output_coder& operator<<(output_coder& stream, const bitstring_type& vl);

            output_coder& operator<<(output_coder& stream, const octetstring_type& vl);

            output_coder& operator<<(output_coder& stream, const utf8string_type& vl);

            output_coder& operator<<(output_coder& stream, const numericstring_type& vl);

            output_coder& operator<<(output_coder& stream, const printablestring_type& vl);

            output_coder& operator<<(output_coder& stream, const t61string_type& vl);

            output_coder& operator<<(output_coder& stream, const videotexstring_type& vl);

            output_coder& operator<<(output_coder& stream, const ia5string_type& vl);

            output_coder& operator<<(output_coder& stream, const graphicstring_type& vl);

            output_coder& operator<<(output_coder& stream, const objectdescriptor_type& vl);

            output_coder& operator<<(output_coder& stream, const visiblestring_type& vl);

            output_coder& operator<<(output_coder& stream, const generalstring_type& vl);

            output_coder& operator<<(output_coder& stream, const universalstring_type& vl);

            output_coder& operator<<(output_coder& stream, const bmpstring_type& vl);

            output_coder& operator<<(output_coder& stream, const utctime_type& vl);

            output_coder& operator<<(output_coder& stream, const gentime_type& vl);




            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*INPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


            bool find_marked_sequece(const mutable_sequences& val, mutable_sequences::const_iterator bit, octet_sequnce& raw, std::size_t start = 0);


            /////  CAST FROM AND TO TYPE

            ///////////////////////////////////////////////////////////////////////////////////////////////
            // integer from X.691          

            template<typename T>
            bool from_x691_cast(T& vl, const octet_sequnce& dt) {
                octet_sequnce val = dt;
#ifdef BIG_ENDIAN_ARCHITECTURE 
                !!!not implement
#else              
                endian_conv(val);
                if (sizeof (T) > val.size())
                    val.resize(sizeof (T), octet_type((val.empty() || (val.back() & NEGATIVE_MARKER)) ? POSITIVE_START : 0));
                vl = (*(T*) (&val[0]));
#endif                  
                return true;
            }




            ///////////////////////////////////////////////////////////////////////////////////
            // tag from X.691

            std::size_t tag_from_x691_cast(const tag& val, const octet_sequnce& src);

            std::size_t tag_x691_cast(tag& val, const mutable_sequences& src, mutable_sequences::const_iterator bit, std::size_t beg = 0);

            ///////////////////////////////////////////////////////////////////////////////////
            // size_class from X.691

            std::size_t size_x691_cast(size_class& val, const mutable_sequences& src, mutable_sequences::const_iterator bit, std::size_t beg = 0);

            ///////////////////////////////////////////////////////////////////////////////////
            // real from X.691

            template<>
            bool from_x691_cast(float& vl, const octet_sequnce& val);

            template<>
            bool from_x691_cast(double& vl, const octet_sequnce& val);

            template<>
            bool from_x691_cast(long double& vl, const octet_sequnce& val);


            ///////////////////////////////////////////////////////////////////////////////////
            // bool from X.691

            template<>
            bool from_x691_cast(bool& vl, const octet_sequnce& val);


            ///////////////////////////////////////////////////////////////////////////////////
            // null from X.691

            template<>
            bool from_x691_cast(null_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // enumerated_type from X.691

            template<>
            bool from_x691_cast(enumerated_type& val, const octet_sequnce& src);


            ///////////////////////////////////////////////////////////////////////////////////
            // oid from X.691

            template<>
            bool from_x691_cast(oid_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // relative from to X.691

            template<>
            bool from_x691_cast(reloid_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // utctime_type from to X.691

            template<>
            bool from_x691_cast(utctime_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // gentime_type from to X.691

            template<>
            bool from_x691_cast(gentime_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // any_type from to X.691

            template<>
            bool from_x691_cast(any_type& val, const octet_sequnce& src);



            //////////////////////////////////////////////////////////
            //   archiver

            class input_coder : public boost::itu::base_input_coder {

            public:

                input_coder() : boost::itu::base_input_coder() {
                }

                template<typename T>
                void operator&(const T& vl) {
                    *this >> implicit_value<T > (vl);
                }

                template<typename T>
                void operator&(const explicit_value<T >& vl) {
                    *this >> vl;
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const explicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this >> explicit_value<T > (vl.value(), ID, TYPE);
                }

                template<typename T>
                void operator&(const optional_explicit_value<T >& vl) {
                    *this >> vl;
                }

                template<typename T>
                void operator&(const implicit_value<T >& vl) {
                    *this >> vl;
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const implicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this >> implicit_value<T > (vl.value(), ID, TYPE);
                }

                template<typename T>
                void operator&(const optional_implicit_value<T >& vl) {
                    *this >> vl;
                }

                template<typename T>
                void operator&(const std::vector<T >& vl) {
                    *this >> vl;
                }

                template<typename T>
                void operator&(const std::deque<T >& vl) {
                    *this >> vl;
                }

                virtual int test_id() {
                    /*tag tmptag;
                    if (tag_x691_cast(tmptag, buffers(), buffers().begin()))
                        return tmptag.id();
                    else*/
                    return tag::null_tag;
                }

                virtual int test_class() {
                    /*tag tmptag;
                    if (tag_x691_cast(tmptag, buffers(), buffers().begin()))
                        return tmptag.mask() & 0xC0;
                    else*/
                    return tag::null_tag;
                }



            };

            template<typename T>
            input_coder& operator>>(input_coder& stream, const explicit_value<T>& vl) {

                /* if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET)) {
                     stream & vl.value();
                     stream.pop_stack();
                     return stream;
                 }*/
                return stream;
                throw boost::system::system_error(boost::itu::ER_BEDSEQ);
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_explicit_value<T>& vl) {
                typedef boost::shared_ptr<T> shared_type;
                /*if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET, true)) {
                 *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr<T > (new T());
                    stream & explicit_value<T > (*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }*/
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_explicit_value< std::vector<T> >& vl) {
                typedef boost::shared_ptr< std::vector<T> > shared_type;
                /*if (stream.parse_tl(vl, false, true)) {
                 *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr< std::vector<T> > (new std::vector<T > ());
                    stream >> explicit_value<std::vector<T> >(*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }*/
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_explicit_value< std::deque<T> >& vl) {
                typedef boost::shared_ptr< std::deque<T> > shared_type;
                /*if (stream.parse_tl(vl, false, true)) {
                 *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr< std::deque<T> > (new std::deque<T > ());
                    stream >> explicit_value<std::deque<T> >(*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }*/
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const implicit_value<T>& vl) {

                /*if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET)) {
                    const_cast<T*> (&(vl.value()))->serialize(stream);
                    stream.pop_stack();
                    return stream;
                }*/
                return stream;
                throw boost::system::system_error(boost::itu::ER_BEDSEQ);
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_implicit_value<T>& vl) {
                typedef boost::shared_ptr<T> shared_type;
                /*if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET, true)) {
                 *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr<T > (new T());
                    stream & implicit_value<T > (*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }*/
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_implicit_value< std::vector<T> >& vl) {
                typedef boost::shared_ptr< std::vector<T> > shared_type;
                /*if (stream.parse_tl(vl, false, true)) {
                 *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr< std::vector<T> > (new std::vector<T > ());
                    stream >> implicit_value<std::vector<T> >(*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }*/
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_implicit_value< std::deque<T> >& vl) {
                typedef boost::shared_ptr< std::deque<T> > shared_type;
                /*if (stream.parse_tl(vl, false, true)) {
                 *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr< std::deque<T> > (new std::deque<T > ());
                    stream >> implicit_value<std::deque<T> >(*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }*/
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const explicit_value< std::vector<T> >& vl) {
                return stream >> implicit_value<std::vector<T> >(vl.value(), vl.id(), vl.type());
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const explicit_value< std::deque<T> >& vl) {
                return stream >> implicit_value< std::deque<T> >(vl.value(), vl.id(), vl.type());
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const implicit_value< std::vector<T> >& vl) {
                /*size_class tmpsize;
               if (stream.parse_tl(vl, tmpsize, false)) {
                   std::size_t beg = stream.size();
                  if (tmpsize.undefsize()) {
                       while (!stream.is_endof() && stream.size()) {
                           T tmp;
                           boost::asn1::bind_element<T>::op(stream, tmp);
                           const_cast<std::vector<T>*> (&(vl.value()))->push_back(tmp);
                       }
                   } else 
                   {
                       std::size_t sz = tmpsize.size();
                       while ((beg - stream.size()) < sz) {
                           T tmp;
                           boost::asn1::bind_element<T>::op(stream, tmp);
                           const_cast<std::vector<T>*> (&(vl.value()))->push_back(tmp);
                       }
                   }
                   stream.pop_stack();
               }*/
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const implicit_value< std::deque<T> >& vl) {
                /*size_class tmpsize;
                if (stream.parse_tl(vl, tmpsize, false)) {
                    std::size_t beg = stream.size();
                    if (tmpsize.undefsize()) {
                        while (!stream.is_endof() && stream.size()) {
                            T tmp;
                            boost::asn1::bind_element<T>::op(stream, tmp);
                            const_cast<std::deque<T>*> (&(vl.value()))->push_back(tmp);
                        }
                    } else
                    {
                        std::size_t sz = tmpsize.size();
                        while ((beg - stream.size()) < sz) {
                            T tmp;
                            boost::asn1::bind_element<T>::op(stream, tmp);
                            const_cast<std::deque<T>*> (&(vl.value()))->push_back(tmp);
                        }
                    }
                    stream.pop_stack();
                }*/
                return stream;
            }


            //////////////////////////////////////////////////////////////////////////////////

            template<typename T>
            input_coder& primitive_desirialize(input_coder& stream, const implicit_value<T>& vl) {
                /*size_class tmpsize;
                if (stream.parse_tl(vl, tmpsize, tag_traits<T>::number() == TYPE_SET)) {
                    octet_sequnce data;
                    std::size_t sz = tmpsize.size();
                    if (boost::itu::row_cast(stream.buffers(), stream.buffers().begin(), data, 0, sz)) {
                        if (from_x691_cast(*const_cast<T*> (&vl.value()), data)) {
                        }
                    }
                    stream.pop_stack();
                    return stream;
                }*/
                return stream;
                throw boost::system::system_error(boost::itu::ER_BEDSEQ);
            }

            template<typename T>
            octet_sequnce::iterator reader_setunuse(octet_sequnce& seq, T& vl) {
                return seq.begin();
            }

            template<>
            octet_sequnce::iterator reader_setunuse(octet_sequnce& seq, bitstring_type& vl);

            template<typename T>
            bool stringtype_reader(input_coder& stream, T& vl, id_type id, octet_type mask) {

                /*size_class tmpsize;
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
                                    octet_sequnce::iterator fit= reader_setunuse(data,vl);
                                    vl.insert(vl.end(), fit , data.end());
                                    return true;
                                }
                            }
                            return false;
                        }
                    } else
                    {
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
                                vl.insert(vl.end(), fit, data.end());
                                stream.pop_stack();
                                return true;
                            }
                        }
                    }
                }*/
                return false;
            }


            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<int8_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<uint8_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<int16_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<uint16_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<int32_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<uint32_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<int64_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<uint64_t>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<enumerated_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<float>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<double>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<long double>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<bool>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<null_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<oid_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<reloid_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<any_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<bitstring_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<octetstring_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<utf8string_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<numericstring_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<printablestring_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<t61string_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<videotexstring_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<ia5string_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<graphicstring_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<objectdescriptor_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<visiblestring_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<generalstring_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<universalstring_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<bmpstring_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<utctime_type>& vl);

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<gentime_type>& vl);



        }


        template<> void external_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void external_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void external_type::Encoding_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void external_type::Encoding_type::serialize(boost::asn1::x691::input_coder& arch);

        template<> void embeded_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void embeded_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void embeded_type::Identification_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void embeded_type::Identification_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void embeded_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void embeded_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void embeded_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void embeded_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::input_coder& arch);


        template<> void characterstring_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void characterstring_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void characterstring_type::Identification_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void characterstring_type::Identification_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void characterstring_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void characterstring_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void characterstring_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void characterstring_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::input_coder& arch);



    }
}


#endif	/* ASNBASE_H */

