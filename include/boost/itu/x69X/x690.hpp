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


namespace boost {
    namespace asn1 {
        namespace x690 {

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

            inline std::ostream& operator<<(std::ostream& stream, const size_class& vl) {
                return vl.undefsize() ? (stream << "SIZE:  undef" << '\n') : (stream << "SIZE:  " << vl.size() << '\n');
            }


            ///////////////////





            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                                                           */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////




            /////  CAST FROM AND TO TYPE

            ///////////////////////////////////////////////////////////////////////////////////////////////
            // integer to X.690

            template<typename T>
            std::size_t to_x690_cast(T val, octet_sequnce& src) {
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
            std::size_t to_x690_cast(int8_t val, octet_sequnce& src);

            template<>
            std::size_t to_x690_cast(uint8_t val, octet_sequnce& src);





            ///////////////////////////////////////////////////////////////////////////////////
            // tag to X.690


            std::size_t to_x690_cast(const tag& val, octet_sequnce& src);

            octet_sequnce to_x690_cast(const tag& val);


            ///////////////////////////////////////////////////////////////////////////////////
            // size_class to X.690


            std::size_t to_x690_cast(const size_class& val, octet_sequnce& src);

            octet_sequnce to_x690_cast(const size_class& val);


            ///////////////////////////////////////////////////////////////////////////////////
            // real to X.690


            template<>
            std::size_t to_x690_cast(double val, octet_sequnce& src);

            template<>
            std::size_t to_x690_cast(float val, octet_sequnce& src);

            template<>
            std::size_t to_x690_cast(long double val, octet_sequnce& src);



            ///////////////////////////////////////////////////////////////////////////////////
            // bool to X.690

            template<>
            std::size_t to_x690_cast(bool val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // null to X.690

            std::size_t to_x690_cast(const null_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // enumerated_type to X.690

            std::size_t to_x690_cast(const enumerated_type& val, octet_sequnce& src);


            ///////////////////////////////////////////////////////////////////////////////////
            // oid to X.690


            std::size_t to_x690_cast(const oid_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // relative oid to X.690


            std::size_t to_x690_cast(const reloid_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // utctime to X.690


            std::size_t to_x690_cast(const utctime_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // gentime to X.690


            std::size_t to_x690_cast(const gentime_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // any_type to X.690


            std::size_t to_x690_cast(const any_type& val, octet_sequnce& src);

            template<typename T>
            octet_sequnce to_x690_cast(const T& val) {
                octet_sequnce rslt;
                to_x690_cast(val, rslt);
                return rslt;
            }


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

                output_coder(encoding_rule rul = boost::itu::BER_ENCODING) : boost::itu::base_output_coder(), rule_(rul) {
                }

                virtual encoding_rule rule() const {
                    return rule_;
                }

                template<typename T>
                void operator&(const T& vl) {
                    *this << implicit_value<T > (vl);
                }

                template<typename T>
                void operator&(const explicit_value<T >& vl) {
                    *this << vl;
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const explicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this << explicit_value<T > (vl.value(), ID, TYPE);
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
                    *this << implicit_value<T > (vl.value(), ID, TYPE);
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

                iterator_type addtag(const tag& tg, bool settype);

                void pop_stack();

                virtual void clear();

                bool canonical() const {
                    return rule_ == boost::itu::CER_ENCODING;
                }

            private:

                void sort_tlv(tlv_vector& vct);


                stack_type stack_;
                encoding_rule rule_;

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
                    stream.add(to_x690_cast(size_class()), it);
                    stream.add(octet_sequnce(2, 0));
                } else
                    stream.add(to_x690_cast(size_class(sz)), it);
                stream.pop_stack();
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const explicit_value< std::vector<T> >& vl) {
                return stream << implicit_value<std::vector<T> >(vl.value(), vl.id(), vl.type());
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const explicit_value< std::deque<T> >& vl) {
                return stream << implicit_value<std::deque<T> >(vl.value(), vl.id(), vl.type());
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
                    stream.add(to_x690_cast(size_class()), it);
                    stream.add(octet_sequnce(2, 0));
                } else
                    stream.add(to_x690_cast(size_class(sz)), it);
                stream.pop_stack();
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const implicit_value<std::vector<T> >& vl) {

                stream.addtag(tag(vl.id(), vl.mask() | CONSTRUCTED_ENCODING), false);
                const_sequences::iterator it = stream.last();

                std::size_t sz = stream.size();
                typedef typename std::vector<T>::const_iterator vect_type_iterator;
                for (vect_type_iterator itr = vl.value().begin(); itr != vl.value().end(); ++itr)
                    boost::asn1::bind_element<T>::op(stream, (*itr));
                sz = stream.size(sz);
                ++it;

                if (stream.canonical()) {
                    stream.add(to_x690_cast(size_class()), it);
                    stream.add(octet_sequnce(2, 0));
                } else
                    stream.add(to_x690_cast(size_class(sz)), it);
                stream.pop_stack();
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const implicit_value<std::deque<T> >& vl) {

                stream.addtag(tag(vl.id(), vl.mask() | CONSTRUCTED_ENCODING), false);
                const_sequences::iterator it = stream.last();

                std::size_t sz = stream.size();
                typedef typename std::deque<T>::const_iterator vect_type_iterator;
                for (vect_type_iterator itr = vl.value().begin(); itr != vl.value().end(); ++itr)
                    boost::asn1::bind_element<T>::op(stream, (*itr));
                sz = stream.size(sz);
                ++it;

                if (stream.canonical()) {
                    stream.add(to_x690_cast(size_class()), it);
                    stream.add(octet_sequnce(2, 0));
                } else
                    stream.add(to_x690_cast(size_class(sz)), it);
                stream.pop_stack();
                return stream;
            }

            template<typename T>
            output_coder& primitive_sirialize(output_coder& stream, const implicit_value<T>& vl) {

                stream.addtag(tag(vl.id(), vl.mask()), (tag_traits<T>::number() == TYPE_SET));
                const_sequences::iterator it = stream.last();

                std::size_t sz = stream.size();
                stream << vl.value();
                sz = stream.size(sz);
                ++it;

                stream.add(to_x690_cast(size_class(sz)), it);
                stream.pop_stack();
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const optional_explicit_value<T>& vl) {
                if (vl.value())
                    stream << explicit_value<T > (*vl.value(), vl.id(), vl.type());
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const optional_implicit_value<T>& vl) {
                if (vl.value())
                    stream << implicit_value<T > (*vl.value(), vl.id(), vl.type());
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
                            stream.add(to_x690_cast(size_class(static_cast<std::size_t> (diff))));
                        } else {
                            stream.add(to_x690_cast(size_class(static_cast<std::size_t> (diff))));
                        }
                        stream.add(octet_sequnce(it, it + diff));
                        it = it + diff;
                        stream.pop_stack();
                    }
                }
            }


            template<>
            void x690_string_to_stream_cast(const bitstring_type& val, output_coder& stream, octet_type lentype);

            template<typename T>
            output_coder& stringtype_writer(output_coder& stream, const T& vl, id_type id, octet_type mask) {



                octet_type construct = vl.size()<(tag_traits<T>::number() == TYPE_BITSTRING ? (CER_STRING_MAX_SIZE - 1) : CER_STRING_MAX_SIZE)
                        ? PRIMITIVE_ENCODING : (stream.canonical() ? CONSTRUCTED_ENCODING : PRIMITIVE_ENCODING);

                stream.addtag(tag(id, mask | construct), false);
                const_sequences::iterator it = stream.last();

                std::size_t sz = stream.size();
                x690_string_to_stream_cast(vl, stream, construct);
                sz = stream.size(sz);
                ++it;

                if (construct) {
                    stream.add(to_x690_cast(size_class()), it);
                    stream.add(octet_sequnce(2, 0));
                } else
                    stream.add(to_x690_cast(size_class(sz)), it);
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
            output_coder& operator<<(output_coder& stream, const implicit_value<enumerated_type>& vl);

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
            output_coder& operator<<(output_coder& stream, const implicit_value<bitstring_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<octetstring_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<utf8string_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<numericstring_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<printablestring_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<t61string_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<videotexstring_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<ia5string_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<graphicstring_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<objectdescriptor_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<visiblestring_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<generalstring_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<universalstring_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<bmpstring_type>& vl);


            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<utctime_type>& vl);

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<gentime_type>& vl);




            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*INPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


            bool find_marked_sequece(const mutable_sequences& val, mutable_sequences::const_iterator bit, octet_sequnce& raw, std::size_t start = 0);


            /////  CAST FROM AND TO TYPE

            ///////////////////////////////////////////////////////////////////////////////////////////////
            // integer from X.690          

            template<typename T>
            bool from_x690_cast(T& vl, const octet_sequnce& dt) {
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
            // tag from X.690

            std::size_t tag_from_x690_cast(const tag& val, const octet_sequnce& src);

            std::size_t tag_x690_cast(tag& val, const mutable_sequences& src, mutable_sequences::const_iterator bit, std::size_t beg = 0);

            ///////////////////////////////////////////////////////////////////////////////////
            // size_class from X.690

            std::size_t size_x690_cast(size_class& val, const mutable_sequences& src, mutable_sequences::const_iterator bit, std::size_t beg = 0);

            ///////////////////////////////////////////////////////////////////////////////////
            // real from X.690

            template<>
            bool from_x690_cast(float& vl, const octet_sequnce& val);

            template<>
            bool from_x690_cast(double& vl, const octet_sequnce& val);

            template<>
            bool from_x690_cast(long double& vl, const octet_sequnce& val);


            ///////////////////////////////////////////////////////////////////////////////////
            // bool from X.690

            template<>
            bool from_x690_cast(bool& vl, const octet_sequnce& val);


            ///////////////////////////////////////////////////////////////////////////////////
            // null from X.690

            template<>
            bool from_x690_cast(null_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // enumerated_type from X.690

            template<>
            bool from_x690_cast(enumerated_type& val, const octet_sequnce& src);


            ///////////////////////////////////////////////////////////////////////////////////
            // oid from X.690

            template<>
            bool from_x690_cast(oid_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // relative from to X.690

            template<>
            bool from_x690_cast(reloid_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // utctime_type from to X.690

            template<>
            bool from_x690_cast(utctime_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // gentime_type from to X.690

            template<>
            bool from_x690_cast(gentime_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // any_type from to X.690

            template<>
            bool from_x690_cast(any_type& val, const octet_sequnce& src);



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
            input_coder& operator>>(input_coder& stream, const explicit_value<T>& vl) {

                if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET)) {
                    stream & vl.value();
                    stream.pop_stack();
                    return stream;
                }
                throw boost::system::system_error(boost::itu::ER_BEDSEQ);
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_explicit_value<T>& vl) {
                typedef boost::shared_ptr<T> shared_type;
                if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET, true)) {
                    *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr<T > (new T());
                    stream & explicit_value<T > (*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_explicit_value< std::vector<T> >& vl) {
                typedef boost::shared_ptr< std::vector<T> > shared_type;
                if (stream.parse_tl(vl, false, true)) {
                    *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr< std::vector<T> > (new std::vector<T > ());
                    stream >> explicit_value<std::vector<T> >(*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_explicit_value< std::deque<T> >& vl) {
                typedef boost::shared_ptr< std::deque<T> > shared_type;
                if (stream.parse_tl(vl, false, true)) {
                    *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr< std::deque<T> > (new std::deque<T > ());
                    stream >> explicit_value<std::deque<T> >(*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const implicit_value<T>& vl) {

                if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET)) {
                    const_cast<T*> (&(vl.value()))->serialize(stream);
                    stream.pop_stack();
                    return stream;
                }
                throw boost::system::system_error(boost::itu::ER_BEDSEQ);
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_implicit_value<T>& vl) {
                typedef boost::shared_ptr<T> shared_type;
                if (stream.parse_tl(vl, tag_traits<T>::number() == TYPE_SET, true)) {
                    *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr<T > (new T());
                    stream & implicit_value<T > (*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_implicit_value< std::vector<T> >& vl) {
                typedef boost::shared_ptr< std::vector<T> > shared_type;
                if (stream.parse_tl(vl, false, true)) {
                    *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr< std::vector<T> > (new std::vector<T > ());
                    stream >> implicit_value<std::vector<T> >(*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const optional_implicit_value< std::deque<T> >& vl) {
                typedef boost::shared_ptr< std::deque<T> > shared_type;
                if (stream.parse_tl(vl, false, true)) {
                    *const_cast<shared_type*> (&(vl.value())) = boost::shared_ptr< std::deque<T> > (new std::deque<T > ());
                    stream >> implicit_value<std::deque<T> >(*vl.value(), vl.id(), vl.type());
                    //stream.pop_stack();
                }
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
                size_class tmpsize;
                if (stream.parse_tl(vl, tmpsize, false)) {
                    std::size_t beg = stream.size();
                    if (tmpsize.undefsize()) {
                        while (!stream.is_endof() && stream.size()) {
                            T tmp;
                            boost::asn1::bind_element<T>::op(stream, tmp);
                            const_cast<std::vector<T>*> (&(vl.value()))->push_back(tmp);
                        }
                    } else {
                        std::size_t sz = tmpsize.size();
                        while ((beg - stream.size()) < sz) {
                            T tmp;
                            boost::asn1::bind_element<T>::op(stream, tmp);
                            const_cast<std::vector<T>*> (&(vl.value()))->push_back(tmp);
                        }
                    }
                    stream.pop_stack();
                }
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, const implicit_value< std::deque<T> >& vl) {
                size_class tmpsize;
                if (stream.parse_tl(vl, tmpsize, false)) {
                    std::size_t beg = stream.size();
                    if (tmpsize.undefsize()) {
                        while (!stream.is_endof() && stream.size()) {
                            T tmp;
                            boost::asn1::bind_element<T>::op(stream, tmp);
                            const_cast<std::deque<T>*> (&(vl.value()))->push_back(tmp);
                        }
                    } else {
                        std::size_t sz = tmpsize.size();
                        while ((beg - stream.size()) < sz) {
                            T tmp;
                            boost::asn1::bind_element<T>::op(stream, tmp);
                            const_cast<std::deque<T>*> (&(vl.value()))->push_back(tmp);
                        }
                    }
                    stream.pop_stack();
                }
                return stream;
            }


            //////////////////////////////////////////////////////////////////////////////////

            template<typename T>
            input_coder& primitive_desirialize(input_coder& stream, const implicit_value<T>& vl) {
                size_class tmpsize;
                if (stream.parse_tl(vl, tmpsize, tag_traits<T>::number() == TYPE_SET)) {
                    octet_sequnce data;
                    std::size_t sz = tmpsize.size();
                    if (boost::itu::row_cast(stream.buffers(), stream.buffers().begin(), data, 0, sz)) {
                        if (from_x690_cast(*const_cast<T*> (&vl.value()), data)) {
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
            octet_sequnce::iterator reader_setunuse(octet_sequnce& seq,  bitstring_type& vl);
            

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
                                    octet_sequnce::iterator fit= reader_setunuse(data,vl);
                                    vl.insert(vl.end(), fit , data.end());
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
                                octet_sequnce::iterator fit= reader_setunuse(data,vl);
                                vl.insert(vl.end(), fit , data.end());
                                stream.pop_stack();
                                return true;
                            }
                        }
                    }
                }
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
        

        template<> void external_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void external_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void external_type::Encoding_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void external_type::Encoding_type::serialize(boost::asn1::x690::input_coder& arch);

        template<> void embeded_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void embeded_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void embeded_type::Identification_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void embeded_type::Identification_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void embeded_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void embeded_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void embeded_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void embeded_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::input_coder& arch);


        template<> void characterstring_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void characterstring_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void characterstring_type::Identification_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void characterstring_type::Identification_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void characterstring_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void characterstring_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::input_coder& arch);
        template<> void characterstring_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::output_coder& arch);
        template<> void characterstring_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::input_coder& arch);



    }
}


#endif	/* ASNBASE_H */

