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
#include <boost/itu/x69X/x69x.hpp>

namespace boost {
    namespace asn1 {
        namespace x691 {

;
            const std::size_t MAX_OCTETLENGTH_SIZE = 0x100;
            const std::size_t MAX_SMALL_NN_SIZE = 64;


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
                        /*octet_sequnce vl = octet_sequnce(static_cast<octet_sequnce::value_type*> ((void*) &value()),
                                static_cast<octet_sequnce::value_type*> ((void*) &value()) + octsz);
                        endian_conv(vl);                         
                        return vl;*/
                        octet_sequnce vl;
                        to_x690_cast<internal_type>(value_, vl);
                        return vl;
                    }
                    return octet_sequnce(1, '\x0');
                }

                octetstring_type as_octetstring() const {
                    return octetstring_type(as_octetsequence());
                }

                bool from_octetsequence(const octet_sequnce& dt) {
                    return from_x690_cast(value_, dt);
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




            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                                                           */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


            /////  CAST FROM AND TO TYPE

            ///////////////////////////////////////////////////////////////////////////////////////////////
            // null to X.691

            template<typename T>
            std::size_t to_x691_cast(T val, octet_sequnce& src) {
                return 0;
            }

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
            // enumerated_type to X.691

            std::size_t to_x691_cast(const enumerated_type& val, octet_sequnce& src);


            ///////////////////////////////////////////////////////////////////////////////////
            // any_type to X.691


            std::size_t to_x691_cast(const any_type& val, octet_sequnce& src);

            template<typename T>
            octet_sequnce to_x691_cast(const T& val) {
                octet_sequnce rslt;
                to_x691_cast(val, rslt);
                return rslt;
            }


            // element constrainter

            struct numericstring_ec {

                static bitstring_type out(octet_sequnce::value_type vl, bool alighn) {
                    return bitstring_type(vl, 4);
                }
            };

            struct visiblestring_ec {

                static bitstring_type out(octet_sequnce::value_type vl, bool alighn) {
                    return bitstring_type(octet_sequnce(1, alighn ? octet_sequnce::value_type(vl) : octet_sequnce::value_type(vl << 1)), alighn ? 0 : 1);
                }
            };


            //////////////////////////////////////////////////////////////////////////////////////////
            ///  archiver                

            class output_coder : public boost::itu::base_output_coder {

            public:

                output_coder(encoding_rule rul = boost::itu::PER_UNALIGNED_ENCODING) : boost::itu::base_output_coder(), rule_(rul), unaligned_(true/*rul == boost::itu::PER_UNALIGNED_ENCODING*/) {
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


                void add_bitmap(const bitstring_type & vl, bool alighn = false);

                void add_octets(const octet_sequnce& vl, bool alighn = false);

                void add_octets(const octetstring_type & vl, bool alighn = false);

                template<typename T>
                void operator&(const T& vl) {
                    *this << vl;
                }

                template<typename T>
                void operator&(const explicit_value<T >& vl) {
                    *this & vl.value();
                }

                template<typename T>
                void operator&(const implicit_value<T >& vl) {
                    *this & vl.value();
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const explicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this & vl.value();
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const implicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this & vl.value();
                }

                bool canonical() const {
                    return rule_ == boost::itu::CER_ENCODING;
                }

                std::size_t unusebits() const {
                    return unuse_ % 8;
                }

                std::size_t usebits() const {
                    return 8 - unusebits();
                }

            protected:

                std::size_t unusebits(std::size_t vl) {
                    return unuse_ = vl % 8;
                }

            private:

                encoding_rule rule_;
                bool unaligned_;

            };



            ////////////////////////////////////////////////////////////////////

            template<typename T>
            inline output_coder& operator<<(output_coder& stream, const T& vl) {
                const_cast<T&> (vl).serialize(stream);
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const std::vector<T>& vl) {

                stream.add(to_x691_cast(size_class(vl.size())));

                typedef typename std::vector<T>::const_iterator vect_type_iterator;
                for (vect_type_iterator itr = vl.begin(); itr != vl.end(); ++itr)
                    stream & (*itr);

                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const std::deque<T>& vl) {

                stream.add(to_x691_cast(size_class(vl.size())));

                typedef typename std::deque<T>::const_iterator vect_type_iterator;
                for (vect_type_iterator itr = vl.begin(); itr != vl.end(); ++itr)
                    stream & (*itr);

                return stream;

            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const num_constrainter<T >& vl) {

                if (vl.can_extended()) {
                    stream.add_bitmap(bitstring_type(vl.extended()));
                    if (vl.extended())
                        return primitive_int_serialize(stream, vl.value());
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

                return primitive_int_serialize(stream, vl.value());
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const num_semiconstrainter<T>& vl) {


                if (vl.can_extended()) {
                    stream.add_bitmap(bitstring_type(vl.extended()));
                    if (vl.extended())
                        return primitive_int_serialize(stream, vl.value());
                }

                semiconstrained_wnumber<T> tmp(const_cast<T&> (vl.value()), vl.min(), vl.extended());
                stream.add(tmp.as_octetsequence());

                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const size_constrainter<T, null_constrainter >& vl) {
                return stream << vl.value();
            }

            template<typename T, typename EC>
            output_coder& operator<<(output_coder& stream, const size_constrainter<T, EC >& vl) {
                return stream << vl.value();
            }




            ////////////////// STRING REALIZATION

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& elms, bool align = false);

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& sz, const octet_sequnce& elms, bool align = false);


            output_coder& octets_writer(output_coder& stream, const bitstring_type& elms, bool align = false);

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& sz, const bitstring_type& elms, bool align = false);

            template<typename T>
            output_coder& elements_writer(output_coder& stream, T beg, T end, bool align = false) {
                for (T it = beg; it != end; ++it)
                    stream << (*it);
                return stream;
            }

            template<typename T>
            output_coder& elements_writer(output_coder& stream, const octet_sequnce& sz, T beg, T end, bool align = false) {
                stream.add_octets(sz, align);
                return elements_writer<T>(stream, beg, end, align);
            }

            template<typename T, typename EC>
            output_coder& spec_elements_writer(output_coder& stream, T beg, T end, bool align = false) {
                for (T it = beg; it != end; ++it)
                    stream.add_bitmap(EC::out(*it, stream.aligned()));
                return stream;
            }

            template<typename T, typename EC>
            output_coder& spec_elements_writer(output_coder& stream, const octet_sequnce& sz, T beg, T end, bool align = false) {
                stream.add_octets(sz, align);
                return spec_elements_writer<T, EC>(stream, beg, end, align);
            }

            template<typename T>
            void writer_defsz(output_coder& stream, const size_constrainter<T>& vl) {

                std::size_t tmpsz = vl.value().size();
                if (!vl.check(tmpsz))
                    throw boost::system::system_error(boost::itu::ER_PROTOCOL);

                if (!vl.null_range()) {
                    constrained_wnumber<std::size_t> tmp(tmpsz, vl.min(), vl.max());
                    if ((stream.unaligned()) || (tmp.is_minimal()))
                        stream.add_bitmap(tmp.as_bitmap(), false);
                    else
                        stream.add_octets(tmp.as_octetsequence(), true);
                }
            }

            template<typename T, typename EC>
            void writer_defsz(output_coder& stream, const size_constrainter<T, EC>& vl) {

                std::size_t tmpsz = vl.value().size();
                if (!vl.check(tmpsz))
                    throw boost::system::system_error(boost::itu::ER_PROTOCOL);

                if (!vl.null_range()) {
                    constrained_wnumber<std::size_t> tmp(tmpsz, vl.min(), vl.max());
                    if ((stream.unaligned()) || (tmp.is_minimal()))
                        stream.add_bitmap(tmp.as_bitmap(), false);
                    else
                        stream.add_octets(tmp.as_octetsequence(), true);
                }
            }

            template<typename T>
            output_coder& octet_writer_undefsz(output_coder& stream, const T& vl) {
                std::size_t sz = vl.size();
                std::size_t beg = 0;
                while (beg < sz) {
                    if ((sz - beg) < LENGH_16K) {
                        octets_writer(stream, to_x691_cast(size_class(sz - beg)),
                                octet_sequnce(vl.begin() + beg, vl.end()), stream.aligned());
                        beg = sz;
                    } else {
                        if ((sz - beg) < LENGH_64K) {
                            std::size_t m = (sz - beg) / LENGH_16K;
                            std::size_t nbeg = beg + LENGH_16K*m;
                            octets_writer(stream, to_x691_cast(size_class(LENGH_16K * m)),
                                    octet_sequnce(vl.begin() + beg, vl.begin() + nbeg), stream.aligned());
                            beg = nbeg;
                        } else {
                            octets_writer(stream, to_x691_cast(size_class(LENGH_64K)),
                                    octet_sequnce(vl.begin() + beg, vl.begin() + beg + LENGH_64K), stream.aligned());
                            beg += LENGH_64K;
                        }
                        if (beg == sz)
                            octets_writer(stream, to_x691_cast(size_class(0)),
                                octet_sequnce(), stream.aligned());
                    }
                }
                return stream;
            }

            template<>
            output_coder& octet_writer_undefsz(output_coder& stream, const bitstring_type& vl);

            template<typename T>
            output_coder& element_writer_undefsz(output_coder& stream, const T& vl) {
                std::size_t sz = vl.size();
                std::size_t beg = 0;
                while (beg < sz) {
                    if ((sz - beg) < LENGH_16K) {
                        stream.add_octets(to_x691_cast(size_class(sz - beg)), stream.aligned());
                        elements_writer(vl.begin() + beg, vl.end());
                        beg = sz;
                    } else {
                        if ((sz - beg) < LENGH_64K) {
                            std::size_t m = (sz - beg) / LENGH_16K;
                            std::size_t nbeg = beg + LENGH_16K*m;
                            stream.add_octets(to_x691_cast(size_class(LENGH_16K * m)), stream.aligned());
                            elements_writer(vl.begin() + beg, vl.begin() + nbeg);
                            beg = nbeg;
                        } else {
                            stream.add_octets(to_x691_cast(size_class(LENGH_64K)), stream.aligned());
                            elements_writer(vl.begin() + beg, vl.begin() + beg + LENGH_64K);
                            beg += LENGH_64K;
                        }
                        if (beg == sz)
                            octets_writer(stream, to_x691_cast(size_class(0)),
                                octet_sequnce());
                    }
                }
                return stream;
            }

            template<typename T, typename EC>
            output_coder& spec_element_writer_undefsz(output_coder& stream, const T& vl) {
                std::size_t sz = vl.size();
                std::size_t beg = 0;
                while (beg < sz) {
                    if ((sz - beg) < LENGH_16K) {
                        spec_elements_writer<typename T::const_iterator, EC > (stream, to_x691_cast(size_class(sz - beg)),
                                vl.begin() + beg, vl.end(), stream.aligned());
                        beg = sz;
                    } else {
                        if ((sz - beg) < LENGH_64K) {
                            std::size_t m = (sz - beg) / LENGH_16K;
                            std::size_t nbeg = beg + LENGH_16K*m;
                            spec_elements_writer<typename T::const_iterator, EC > (stream, to_x691_cast(size_class(LENGH_16K * m)),
                                    vl.begin() + beg, vl.begin() + nbeg, stream.aligned());
                            beg = nbeg;
                        } else {
                            spec_elements_writer<typename T::const_iterator, EC > (stream, to_x691_cast(size_class(LENGH_64K)),
                                    vl.begin() + beg, vl.begin() + beg + LENGH_64K, stream.aligned());
                            beg += LENGH_64K;
                        }
                        if (beg == sz) {
                            T tmp;
                            spec_elements_writer<typename T::const_iterator, EC > (stream, to_x691_cast(size_class(0)),
                                    tmp.begin(), tmp.end(), stream.aligned());
                        }
                    }
                }
                return stream;
            }

            template<typename T>
            output_coder& octet_writer_defsz(output_coder& stream, const size_constrainter<T>& vl) {

                if (vl.available()) {
                    if (vl.can_extended())
                        stream.add_bitmap(bitstring_type(vl.extended(vl.value().size())));

                    if ((!vl.extended(vl.value().size())) && (vl.constrained())) {

                        std::size_t tmpsz = vl.value().size();
                        if (!vl.check(tmpsz))
                            throw boost::system::system_error(boost::itu::ER_PROTOCOL);

                        if (vl.max() < LENGH_64K) {
                            writer_defsz(stream, vl);
                            return octets_writer(stream, octet_sequnce(vl.value()), vl.max() <= 2);
                        }
                    }
                }
                return octet_writer_undefsz(stream, vl.value());
            }

            template<typename T>
            output_coder& element_writer_defsz(output_coder& stream, const size_constrainter<T>& vl) {


                if (vl.available()) {
                    if (vl.can_extended())
                        stream.add_bitmap(bitstring_type(vl.extended(vl.value().size())));

                    if ((!vl.extended(vl.value().size())) && (vl.constrained())) {

                        if (vl.max() < LENGH_64K) {
                            writer_defsz(stream, vl);
                            return elements_writer(stream, vl.value().begin(), vl.value().end(), stream.aligned());
                        }
                    }
                }
                return element_writer_undefsz(stream, vl.value());
            }

            template<typename T, typename EC>
            output_coder& spec_element_writer_defsz(output_coder& stream, const size_constrainter<T, EC>& vl) {

                if (vl.available()) {
                    if (vl.can_extended())
                        stream.add_bitmap(bitstring_type(vl.extended(vl.value().size())));

                    if ((!vl.extended(vl.value().size())) && (vl.constrained())) {

                        if (vl.max() < LENGH_64K) {
                            writer_defsz(stream, vl);
                            return spec_elements_writer<typename T::const_iterator, EC > (stream, vl.value().begin(), vl.value().end(), stream.aligned());
                        }
                    }
                }
                return spec_element_writer_undefsz<T, EC>(stream, vl.value());
            }

            template<typename T>
            output_coder& primitive_int_serialize(output_coder& stream, const T& vl) {

                unconstrained_wnumber<T> tmp(const_cast<T&> (vl));
                octet_sequnce data = tmp.as_octetsequence();
                octet_writer_undefsz(stream, data);
                return stream;

            }

            template<typename T>
            output_coder& primitive_690_serialize(output_coder& stream, const T& vl) {
                octet_sequnce tmp;
                to_x690_cast(vl, tmp);
                octet_writer_undefsz(stream, tmp);
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

            // strings

            output_coder& operator<<(output_coder& stream, const bitstring_type& vl);

            output_coder& operator<<(output_coder& stream, const octetstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<octetstring_type>& vl);

            output_coder& operator<<(output_coder& stream, const utf8string_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<utf8string_type>& vl);

            output_coder& operator<<(output_coder& stream, const numericstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<numericstring_type>& vl);

            template<typename EC>
            output_coder& operator<<(output_coder& stream, const size_constrainter<numericstring_type, EC>& vl) {
                return spec_element_writer_defsz<numericstring_type, EC>(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const printablestring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<printablestring_type>& vl);

            output_coder& operator<<(output_coder& stream, const t61string_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<t61string_type>& vl);

            output_coder& operator<<(output_coder& stream, const videotexstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<videotexstring_type>& vl);

            output_coder& operator<<(output_coder& stream, const ia5string_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<ia5string_type>& vl);

            output_coder& operator<<(output_coder& stream, const graphicstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<graphicstring_type>& vl);

            output_coder& operator<<(output_coder& stream, const objectdescriptor_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<objectdescriptor_type>& vl);

            output_coder& operator<<(output_coder& stream, const visiblestring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<visiblestring_type>& vl);

            template<typename EC>
            output_coder& operator<<(output_coder& stream, const size_constrainter<visiblestring_type, EC>& vl) {
                return spec_element_writer_defsz<visiblestring_type, EC>(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const generalstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<generalstring_type>& vl);

            output_coder& operator<<(output_coder& stream, const universalstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<universalstring_type>& vl);

            output_coder& operator<<(output_coder& stream, const bmpstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<bmpstring_type>& vl);



            output_coder& operator<<(output_coder& stream, const utctime_type& vl);

            output_coder& operator<<(output_coder& stream, const gentime_type& vl);




            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*INPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


            /////  CAST FROM AND TO TYPE

            ///////////////////////////////////////////////////////////////////////////////////////////////
            // integer from X.691          

            template<typename T>
            bool from_x691_cast(T& vl, const octet_sequnce& dt) {
                /*  octet_sequnce val = dt;
  #ifdef BIG_ENDIAN_ARCHITECTURE 
                  !!!not implement
  #else              
                  endian_conv(val);
                  if (sizeof (T) > val.size())
                      val.resize(sizeof (T), octet_type((val.empty() || (val.back() & NEGATIVE_MARKER)) ? POSITIVE_START : 0));
                  vl = (*(T*) (&val[0]));
  #endif      */
                return true;
            }




            ///////////////////////////////////////////////////////////////////////////////////
            // enumerated_type from X.691

            template<>
            bool from_x691_cast(enumerated_type& val, const octet_sequnce& src);



            ///////////////////////////////////////////////////////////////////////////////////
            // any_type from to X.691

            template<>
            bool from_x691_cast(any_type& val, const octet_sequnce& src);



            //////////////////////////////////////////////////////////
            //   archiver

            class input_coder : public boost::itu::base_input_coder {

            public:

                input_coder(encoding_rule rul = boost::itu::PER_UNALIGNED_ENCODING) : boost::itu::base_input_coder(), rule_(rul), unaligned_(true/*rul == boost::itu::PER_UNALIGNED_ENCODING*/) {
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

                std::size_t get_bitmap(std::size_t sz, bitstring_type& vl, bool alighn = false);

                std::size_t get_octets(std::size_t sz, octet_sequnce& vl, bool alighn = false);

                std::size_t pop_bitmap(std::size_t sz, bool alighn = false);

                std::size_t pop_octets(std::size_t sz, bool alighn = false);

                std::size_t get_pop_bitmap(std::size_t sz, bitstring_type& vl, bool alighn = false);

                std::size_t get_pop_octets(std::size_t sz, octet_sequnce& vl, bool alighn = false);

                bitstring_type get_pop_bmp(std::size_t sz, bool alighn = false);

                octet_sequnce get_pop_octs(std::size_t sz, bool alighn = false);

                template<typename T>
                void operator&(const T& vl) {
                    *this >> const_cast<T&> (vl);
                }

                template<typename T>
                void operator&(const explicit_value<T >& vl) {
                    *this & vl.value();
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const explicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this & vl.value();
                }

                template<typename T>
                void operator&(const implicit_value<T >& vl) {
                    *this & vl.value();
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const implicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this & vl.value();
                }

                std::size_t unusebits() const {
                    return unuse_ % 8;
                }

                std::size_t usebits() const {
                    return 8 - unusebits();
                }

            protected:

                std::size_t unusebits(std::size_t vl) {
                    return unuse_ = vl % 8;
                }

            private:

                encoding_rule rule_;
                bool unaligned_;

            };


            //////////////////////////////////////////////////////////////////////////////////

            template<typename T>
            input_coder& element_reader(input_coder& stream, T& vl, std::size_t sz) {
                typedef typename T::value_type value_type;
                while (sz--) {
                    value_type tmp;
                    stream & tmp;
                    vl.push_back(tmp);
                }
                return stream;
            }

            template<typename T>
            input_coder& octet_reader_undefsz(input_coder& stream, T& vl) {
                while (true) {
                    octet_sequnce strt = stream.get_pop_octs(1, stream.aligned());
                    if (strt.size()) {
                        octet_sequnce::value_type dtrm = strt[0];
                        switch (dtrm & '\xC0') {
                            case '\xC0':
                            {
                                octet_sequnce nxt = stream.get_pop_octs(1, stream.aligned());
                                std::size_t sz = LENGH_16K;
                                if ((nxt.size()) && ((0x7 & nxt[0]) <= 4))
                                    sz *= static_cast<std::size_t> (0x7 & nxt[0]);
                                else
                                    throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                                octet_sequnce dt = stream.get_pop_octs(sz, stream.aligned());
                                vl.insert(vl.end(), dt.begin(), dt.end());
                                break;
                            }
                            case '\x80':
                            {
                                octet_sequnce nxt = stream.get_pop_octs(1, stream.aligned());
                                boost::uint16_t dtrm16 = dtrm & '\x3f';
                                dtrm16 <<= 8;
                                if (nxt.size())
                                    dtrm16 |= nxt[0];
                                else
                                    throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                                std::size_t sz = static_cast<std::size_t> (dtrm16 & 0x3FFF);
                                octet_sequnce dt = stream.get_pop_octs(sz, stream.aligned());
                                vl.insert(vl.end(), dt.begin(), dt.end());
                                return stream;
                            }
                            default:
                            {
                                std::size_t sz = static_cast<std::size_t> (dtrm & '\x7F');
                                octet_sequnce dt = stream.get_pop_octs(sz, stream.aligned());
                                vl.insert(vl.end(), dt.begin(), dt.end());
                                return stream;
                            }
                        }
                    } else
                        throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                }
                return stream;
            }

            template<typename T>
            input_coder& element_reader_undefsz(input_coder& stream, T& vl) {
                while (true) {
                    octet_sequnce strt = stream.get_pop_octs(1, stream.aligned());
                    if (strt.size()) {
                        octet_sequnce::value_type dtrm = strt[0];
                        switch (dtrm & '\xC0') {
                            case '\xC0':
                            {
                                octet_sequnce nxt = stream.get_pop_octs(1, stream.aligned());
                                std::size_t sz = LENGH_16K;
                                if ((nxt.size()) && ((0x7 & nxt[0]) <= 4))
                                    sz *= static_cast<std::size_t> (0x7 & nxt[0]);
                                else
                                    throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                                element_reader(stream, vl, sz);
                                break;
                            }
                            case '\x80':
                            {
                                octet_sequnce nxt = stream.get_pop_octs(1, stream.aligned());
                                boost::uint16_t dtrm16 = dtrm & '\x3f';
                                dtrm16 <<= 8;
                                if (nxt.size())
                                    dtrm16 |= nxt[0];
                                else
                                    throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                                std::size_t sz = static_cast<std::size_t> (dtrm16 & 0x3FFF);
                                element_reader(stream, vl, sz);
                                return stream;
                            }
                            default:
                            {
                                std::size_t sz = static_cast<std::size_t> (dtrm & '\x7F');
                                element_reader(stream, vl, sz);
                                return stream;
                            }
                        }
                    } else
                        throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                }
                return stream;
            }

            template<typename T>
            input_coder& octet_reader_defsz(input_coder& stream, size_constrainter<T>& vl) {

                if (vl.can_extended()) {
                    bitstring_type extendbit = stream.get_pop_bmp(1);
                    if (extendbit.bit(1)) {
                        return octet_reader_undefsz(stream, const_cast<T&> (vl.value()));
                    }
                }

                /*if ((!vl.extended(vl.value().size())) && (vl.constrained())) {

                    std::size_t tmpsz = vl.value().size();

                    if (vl.max() < LENGH_64K) {
                        if (!vl.null_range()) {
                            constrained_wnumber<std::size_t> tmp(tmpsz, vl.min(), vl.max());
                            if ((stream.unaligned()) || (tmp.is_minimal()))
                                stream.add_bitmap(tmp.as_bitmap(), false);
                            else
                                stream.add(tmp.as_octetsequence());
                        }
                        return octets_writer(stream, octet_sequnce(vl.value()), tmpsz, vl.max() <= 2);
                    }
                }*/
                return octet_reader_undefsz(stream, const_cast<T&> (vl.value()));
            }

            template<typename T>
            input_coder& primitive_deserialize(input_coder& stream, T& vl) {
                /*octet_sequnce data;
                octet_reader_undefsz(stream, data);
                from_x690_cast<T>(const_cast<T&> (vl), data);*/
                return stream;
            }

            template<typename T>
            input_coder& primitive_690_deserialize(input_coder& stream, T& vl) {
                octet_sequnce data;
                octet_reader_undefsz(stream, data);
                from_x690_cast<T>(const_cast<T&> (vl), data);
                return stream;
            }

            template<typename T>
            input_coder& primitive_int_deserialize(input_coder& stream, T& vl) {
                octet_sequnce data;
                octet_reader_undefsz(stream, data);
                unconstrained_wnumber<T> tmp(const_cast<T&> (vl));
                tmp.from_octetsequence(data);
                return stream;
            }

            template<typename T>
            inline input_coder& operator>>(input_coder& stream, T& vl) {
                const_cast<T&> (vl).serialize(stream);
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, std::vector<T>& vl) {
                element_reader_undefsz(stream, const_cast<std::vector<T>&> (vl));
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, std::deque<T>& vl) {
                element_reader_undefsz(stream, const_cast<std::vector<T>&> (vl));
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, num_constrainter<T >& vl) {

                if (vl.can_extended()) {
                    bitstring_type extendbit = stream.get_pop_bmp(1);
                    if (extendbit.bit(1))
                        return primitive_int_deserialize<T>(stream, vl.value());
                }

                if (vl.null_range())
                    return stream;

                /*if ((vl.range() <= 0xFFFF) || (stream.unaligned())) {
                    constrained_wnumber<T> tmp(const_cast<T&> (vl.value()), vl.min(), vl.max());
                    if ((stream.unaligned()) || (tmp.is_minimal()))
                        stream.add_bitmap(tmp.as_bitmap(), false);
                    else
                        stream.add(tmp.as_octetsequence());
                    return stream;
                }*/

                return primitive_int_deserialize<T>(stream, vl.value());
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, num_semiconstrainter<T>& vl) {


                if (vl.can_extended()) {
                    bitstring_type extendbit = stream.get_pop_bmp(1);
                    if (extendbit.bit(1))
                        return primitive_int_serialize(stream, vl.value());
                }
                //semiconstrained_wnumber<T> tmp(const_cast<T&> (vl.value()), vl.min(), vl.extended());
                //stream.add(tmp.as_octetsequence());
                return primitive_int_deserialize(stream, vl.value());
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, size_constrainter<T, null_constrainter>& vl) {
                return stream >> vl.value();
            }

            template<typename T, typename EC>
            input_coder& operator>>(input_coder& stream, size_constrainter<T, EC>& vl) {
                return stream >> vl.value();
            }



            input_coder& operator>>(input_coder& stream, int8_t& vl);

            input_coder& operator>>(input_coder& stream, uint8_t& vl);

            input_coder& operator>>(input_coder& stream, int16_t& vl);

            input_coder& operator>>(input_coder& stream, uint16_t& vl);

            input_coder& operator>>(input_coder& stream, int32_t& vl);

            input_coder& operator>>(input_coder& stream, uint32_t& vl);

            input_coder& operator>>(input_coder& stream, int64_t& vl);

            input_coder& operator>>(input_coder& stream, uint64_t& vl);

            input_coder& operator>>(input_coder& stream, enumerated_type& vl);

            input_coder& operator>>(input_coder& stream, float& vl);

            input_coder& operator>>(input_coder& stream, double& vl);

            input_coder& operator>>(input_coder& stream, long double& vl);

            input_coder& operator>>(input_coder& stream, bool& vl);

            input_coder& operator>>(input_coder& stream, null_type& vl);

            input_coder& operator>>(input_coder& stream, oid_type& vl);

            input_coder& operator>>(input_coder& stream, reloid_type& vl);

            input_coder& operator>>(input_coder& stream, any_type& vl);


            input_coder& operator>>(input_coder& stream, bitstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<bitstring_type>& vl);

            input_coder& operator>>(input_coder& stream, octetstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<octetstring_type>& vl);

            input_coder& operator>>(input_coder& stream, utf8string_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<utf8string_type>& vl);

            input_coder& operator>>(input_coder& stream, numericstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<numericstring_type>& vl);

            template<typename EC>
            input_coder& operator>>(input_coder& stream, size_constrainter<numericstring_type>& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, printablestring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<printablestring_type>& vl);

            input_coder& operator>>(input_coder& stream, t61string_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<t61string_type>& vl);

            input_coder& operator>>(input_coder& stream, videotexstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<videotexstring_type>& vl);

            input_coder& operator>>(input_coder& stream, ia5string_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<ia5string_type>& vl);

            input_coder& operator>>(input_coder& stream, graphicstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<graphicstring_type>& vl);

            input_coder& operator>>(input_coder& stream, objectdescriptor_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<objectdescriptor_type>& vl);

            input_coder& operator>>(input_coder& stream, visiblestring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<visiblestring_type>& vl);

            input_coder& operator>>(input_coder& stream, generalstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<generalstring_type>& vl);

            input_coder& operator>>(input_coder& stream, universalstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<universalstring_type>& vl);

            input_coder& operator>>(input_coder& stream, bmpstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<bmpstring_type>& vl);


            input_coder& operator>>(input_coder& stream, utctime_type& vl);

            input_coder& operator>>(input_coder& stream, gentime_type& vl);



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

