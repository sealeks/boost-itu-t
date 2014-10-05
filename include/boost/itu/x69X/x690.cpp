//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#include <boost/lexical_cast.hpp>

#include <boost/itu/x69X/x690.hpp>

namespace boost {
    namespace asn1 {
        namespace x690 {

            void endian_conv(octet_sequnce& val) {
#ifdef BIG_ENDIAN_ARCHITECTURE                               
#else
                std::reverse(val.begin(), val.end());
#endif               
            }

            octet_sequnce endian_conv_conv(const octet_sequnce& val) {
#ifdef BIG_ENDIAN_ARCHITECTURE
                return val;
#else
                octet_sequnce tmp(val.size());
                std::copy(val.rbegin(), val.rend(), std::back_inserter(tmp));
                return tmp;
#endif                                
            }

            void endian_push_pack(const octet_sequnce& val, octet_sequnce& dst) {
#ifdef BIG_ENDIAN_ARCHITECTURE
                std::copy(val.begin(), val.end(), std::back_inserter(dst))
#else
                std::copy(val.rbegin(), val.rend(), std::back_inserter(dst));
#endif    
            }



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////               


            /////////////////////////////

            template<>
            std::size_t to_x690_cast(int8_t val, octet_sequnce& src) {
                src.push_back(static_cast<octet_type> (0xFF & val));
                return 1;
            }

            template<>
            std::size_t to_x690_cast(uint8_t val, octet_sequnce& src) {
                return to_x690_cast(static_cast<int16_t> (val), src);
            }


            /// id class

            std::size_t to_x690_cast(const tag& val, octet_sequnce& src) {
                if (val.simpleid()) {
                    src.push_back(static_cast<octet_type> (val.simpleid()));
                    return 1;
                } else {
                    id_type id_ = val.id();
                    octet_sequnce tmp;
                    src.push_back(static_cast<octet_type> (0x1F | val.mask()));
                    while (id_) {
                        tmp.push_back(static_cast<octet_type> ((id_ & 0x7F) | CONTENT_CONIIUE));
                        id_ >>= 7;
                    }
                    endian_push_pack(tmp, src);
                    if (tmp.size())
                        src.back() &= static_cast<octet_type> (0x7F);
                    return (src.size() + 1);
                }
            }

            octet_sequnce to_x690_cast(const tag& val) {
                octet_sequnce tmp;
                to_x690_cast(val, tmp);
                return tmp;
            }




            ///////////////////////////////////////////////////////////////////////////////////
            // size_class to X.690

            std::size_t to_x690_cast(const size_class& val, octet_sequnce& src) {
                if (!val.undefsize()) {
                    if (val.size() < MAX_SIMPLELENGTH_SIZE) {
                        src.push_back(static_cast<octet_type> (static_cast<octet_type> (val.size())));
                        return 1;
                    } else {
                        octet_sequnce tmp;
                        size_type vl = val.size();
                        while (vl) {
                            tmp.push_back(static_cast<octet_type> (0xFF & vl));
                            vl >>= 8;
                        }
                        src.push_back(static_cast<octet_type> (CONTENT_CONIIUE | static_cast<octet_type> (tmp.size())));
                        endian_push_pack(tmp, src);
                        return (src.size() + 1);
                    }
                } else {
                    src.push_back(static_cast<octet_type> (static_cast<octet_type> (UNDEF_BLOCK_SIZE)));
                    return 1;
                }
            }

            octet_sequnce to_x690_cast(const size_class& val) {
                octet_sequnce tmp;
                to_x690_cast(val, tmp);
                return tmp;
            }


            //// real cast

            template<typename T, typename B, std::size_t MANT, std::size_t EXPB>
            static std::size_t to_x690_cast_realimpl(T val, octet_sequnce& src) {

                std::size_t strtsz = src.size();
                if (val == 0)
                    return 0;
                if (val != val) {
                    src.push_back(static_cast<octet_type> (NAN_REAL_ID));
                    return 1;
                }
                if (std::numeric_limits<T>::infinity() == val) {
                    src.push_back(static_cast<octet_type> (INFINITY_REAL_ID));
                    return 1;
                }
                if (-std::numeric_limits<T>::infinity() == val) {
                    src.push_back(static_cast<octet_type> (NEGATINFINITY_REAL_ID));
                    return 1;
                }
                if (val == -0.0) {
                    src.push_back(static_cast<octet_type> (NEGATNULL_REAL_ID));
                    return 1;
                }

                octet_sequnce tmp;
                bool negat = false;
                B base0 = *reinterpret_cast<B*> (&val);
                if (base0 < 0) {
                    negat = true;
                    base0 &= ~(B(1) << (sizeof (B)*8 - 1));
                }

                B base = ~(B(1) << (sizeof (B)*8 - 1));
                base >>= (sizeof (B)*8 - MANT - 1);
                base &= base0;
                base |= (B(1) << MANT);

                int32_t exp = static_cast<int32_t> (base0 >> MANT) - MANT - EXPB;

                octet_type sign = static_cast<octet_type> (0x80 | ((negat) ? 0x40 : 0x0));

                while (!static_cast<octet_type> (base & '\xFF')) {
                    exp += 8;
                    base = base >> 8;
                }

                while (!static_cast<octet_type> (base & '\x1')) {
                    exp += 1;
                    base = base >> 1;
                }

                tmp.clear();
                std::size_t expsz = to_x690_cast(exp, tmp);

                //if (!expsz) throw;

                switch (expsz) {
                    case 1:
                    {
                        src.push_back(static_cast<octet_type> (sign));
                        break;
                    }
                    case 2:
                    {
                        sign |= 0x1;
                        src.push_back(static_cast<octet_type> (sign));
                        break;
                    }
                    case 3:
                    {
                        sign |= 0x2;
                        src.push_back(static_cast<octet_type> (sign));
                        break;
                    }
                    default:
                    {
                        src.push_back(static_cast<octet_type> (expsz));
                    }
                }

                std::copy(tmp.begin(), tmp.end(), std::back_inserter(src));


                tmp.clear();
                while (base) {
                    tmp.push_back(static_cast<octet_type> (base) & '\xFF');
                    base = base >> 8;
                }
                endian_push_pack(tmp, src);
                return (src.size() - strtsz);
            }

            template<>
            std::size_t to_x690_cast(double val, octet_sequnce& src) {
                return to_x690_cast_realimpl<double, int64_t, DOUBLE_MANTISSA_SIZE, DOUBLE_EXPONENTA_DELT > (val, src);
            }

            template<>
            std::size_t to_x690_cast(long double val, octet_sequnce& src) {
                return to_x690_cast_realimpl<double, int64_t, DOUBLE_MANTISSA_SIZE, DOUBLE_EXPONENTA_DELT > (static_cast<double> (val), src);
            }

            template<>
            std::size_t to_x690_cast(float val, octet_sequnce& src) {
                return to_x690_cast_realimpl<float, int32_t, FLOAT_MANTISSA_SIZE, FLOAT_EXPONENTA_DELT > (val, src);
            }

            //// bool cast

            template<>
            std::size_t to_x690_cast(bool val, octet_sequnce& src) {
                src.push_back(static_cast<octet_type> (val ? 0xFF : 0));
                return 1;
            }


            //// null cast            

            std::size_t to_x690_cast(const null_type& val, octet_sequnce& src) {
                return 0;
            }


            //// enumerated_type cast                          

            std::size_t to_x690_cast(const enumerated_type& val, octet_sequnce& src) {
                return to_x690_cast(val.value(), src);
            }



            //// oid cast

            static void to_x690_castoid_impl(oidindx_type vl, octet_sequnce& src) {
                octet_sequnce tmp;
                bool first = true;
                while (vl || first) {
                    first = false;
                    tmp.push_back(static_cast<octet_type> ((static_cast<oidindx_type> (0x7F) & vl) | static_cast<oidindx_type> (CONTENT_CONIIUE)));
                    vl >>= 7;
                }
                endian_push_pack(tmp, src);
                if (!src.empty())
                    src.back() = src.back() & static_cast<octet_type> (0x7F);
            }

            std::size_t to_x690_cast(const oid_type& val, octet_sequnce& src) {
                if (val.size() < 2) return 0;
                std::size_t strtsz = src.size();
                oidindx_type tmpval = 40 * val[0];
                tmpval += val[1];
                to_x690_castoid_impl(tmpval, src);
                for (oid_type::const_iterator it = (val.begin() + 2); it != val.end(); ++it)
                    to_x690_castoid_impl(*it, src);
                return (src.size() - strtsz);
            }

            std::size_t to_x690_cast(const reloid_type& val, octet_sequnce& src) {
                if (val.empty()) return 0;
                std::size_t strtsz = src.size();
                for (oid_type::const_iterator it = (val.begin()); it != val.end(); ++it)
                    to_x690_castoid_impl(*it, src);
                return (src.size() - strtsz);
            }

            ///////////////////////////////////////////////////////////////////////////////////
            // utctime to X.690

            std::size_t to_x690_cast(const utctime_type& val, octet_sequnce& src) {
                std::size_t strtsz = src.size();
                octet_sequnce tmp = from_utctime(val);
                src.insert(src.end(), tmp.begin(), tmp.end());
                return (src.size() - strtsz);
            }

            ///////////////////////////////////////////////////////////////////////////////////
            // gentime to X.690

            std::size_t to_x690_cast(const gentime_type& val, octet_sequnce& src) {
                std::size_t strtsz = src.size();
                octet_sequnce tmp = from_gentime(val);
                src.insert(src.end(), tmp.begin(), tmp.end());
                return (src.size() - strtsz);
            }

            ///////////////////////////////////////////////////////////////////////////////////
            // any_type to X.690

            std::size_t to_x690_cast(const any_type& val, octet_sequnce& src) {
                std::size_t strtsz = src.size();
                val.get(src);
                return (src.size() - strtsz);
            }


            // STRING REALISZATION

            template<>
            void x690_string_to_stream_cast(const bitstring_type& val, output_coder& stream, octet_type lentype) {
                if (!lentype) {
                    stream.add(octet_sequnce(1, static_cast<octet_type> (val.unusebits() % 8)));
                    stream.add(val);
                    return;
                } else {

                    typedef bitstring_type::const_iterator const_iterator_type;
                    typedef bitstring_type::difference_type difference_type;

                    const_iterator_type it = val.begin();
                    while (it != val.end()) {
                        //stream.add(octet_sequnce(1, static_cast<octet_type> (TYPE_BITSTRING)));
                        stream.addtag(tag(TYPE_BITSTRING), false);
                        difference_type diff = std::distance(it, val.end());
                        if (diff > static_cast<difference_type> (CER_STRING_MAX_SIZE - 1)) {
                            diff = static_cast<difference_type> (CER_STRING_MAX_SIZE - 1);
                            stream.add(to_x690_cast(size_class(static_cast<std::size_t> (diff + 1))));
                            stream.add(octet_sequnce(1, static_cast<octet_type> (0)));
                        } else {
                            stream.add(to_x690_cast(size_class(static_cast<std::size_t> (diff + 1))));
                            stream.add(octet_sequnce(1, static_cast<octet_type> (val.unusebits() % 8)));
                        }
                        stream.add(octet_sequnce(it, it + diff));
                        it = it + diff;
                        stream.pop_stack();
                    }
                }
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int8_t>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint8_t>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int16_t>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint16_t>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int32_t>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint32_t>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int64_t>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint64_t>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<enumerated_type>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<float>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<double>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<long double>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<bool>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<null_type>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<oid_type>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<reloid_type>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<any_type>& vl) {
                //vl.setcontructed();
                if (vl.value().coder() && vl.value().type() != any_type::bind_simple) {
                    if (vl.value().type() != any_type::bind_tie)
                        stream.tie(vl.value().coder()->out());
                    else
                        stream.move_from(vl.value().coder()->out());
                    return stream;
                }
                return stream << vl.value();
                //return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<bitstring_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<octetstring_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<utf8string_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<numericstring_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<printablestring_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<t61string_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<videotexstring_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<ia5string_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<graphicstring_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value< objectdescriptor_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<visiblestring_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<generalstring_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<universalstring_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<bmpstring_type>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<utctime_type>& vl) {
                return primitive_sirialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<gentime_type>& vl) {
                return primitive_sirialize(stream, vl);
            }



            /// output_coder

            output_coder::iterator_type output_coder::addtag(const tag& tg, bool settype) {
                if (/*false*/rule_ != boost::itu::CER_ENCODING) return add(to_x690_cast(tg));
                iterator_type it = add(to_x690_cast(tg));
                if (!stack_.empty() && stack_.top().is_set)
                    stack_.top().tlv_iterators.push_back(tlv_info(tg, iterator_pair(it, it)));
                stack_.push(stack_item(settype));
                return it;
            }

            void output_coder::pop_stack() {
                if (/*false*/rule_ != boost::itu::CER_ENCODING) return;
                if (!stack_.empty()) {
                    if (stack_.top().is_set)
                        sort_tlv(stack_.top().tlv_iterators);
                    stack_.pop();
                    if ((!stack_.empty()) && (stack_.top().is_set) && (!stack_.top().tlv_iterators.empty()))
                        stack_.top().tlv_iterators.back().iterators.second = last();
                }
            }

            void output_coder::sort_tlv(tlv_vector& vct) {

                typedef std::map<tag, iterator_pair> tlv_map;

                tlv_map mps;
                for (tlv_vector::iterator it = vct.begin(); it != vct.end(); ++it) {
                    if (mps.upper_bound(it->tg) != mps.end())
                        buffers().splice(mps.upper_bound(it->tg)->second.first, buffers(), it->iterators.first, ++iterator_type(it->iterators.second));
                    mps.insert(std::make_pair(it->tg, iterator_pair(it->iterators.first, it->iterators.second)));
                }
            }

            void output_coder::clear() {
                while (!stack_.empty())
                    stack_.pop();
                boost::itu::base_output_coder::clear();

            }



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*INPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            bool find_marked_sequece(const mutable_sequences& val, mutable_sequences::const_iterator bit, octet_sequnce& raw, std::size_t start) {
                mutable_sequences::const_iterator it = bit;
                std::size_t sz = 0;
                std::size_t szc = 0;
                std::size_t szb = 0;
                std::size_t sze = 0;
                bool find = false;
                while ((it != val.end()) && (!find)) {
                    szc = boost::asio::buffer_size(*it);
                    if ((sz + szc) > start) {
                        szb = sz > start ? 0 : start - sz;
                        sze = szc - szb;
                        mutable_buffer tmp = boost::asio::buffer(*it + szb, sze);
                        std::size_t szf = boost::asio::buffer_size(tmp);
                        std::size_t szi = 0;
                        while ((szi < szf) && (!find)) {
                            if (!((*(boost::asio::buffer_cast<octet_type*>(tmp) + szi)) & '\x80'))
                                find = true;
                            raw.push_back((*(boost::asio::buffer_cast<octet_type*>(tmp) + szi) & '\x7F'));
                            szi++;
                        }

                    }
                    sz += szc;
                    ++it;
                }
                return find;
            }


            ///////////////////////////////////////////////////////////////////////////////////
            // tag from X.690                 

            std::size_t tag_from_x690_cast(const tag& val, const octet_sequnce& src) {
                octet_sequnce tmp = to_x690_cast(val);
                if ((src.size() >= tmp.size()) && (tmp == octet_sequnce(src.begin(), src.begin() + tmp.size())))
                    return tmp.size();
                return 0;
            }

            std::size_t tag_x690_cast(tag& val, const mutable_sequences& src, mutable_sequences::const_iterator bit, std::size_t beg) {
                octet_sequnce s1;
                if (boost::itu::row_cast(src, bit, s1, beg, 1) && (!s1.empty())) {
                    if ((s1[0] & '\x1F') != '\x1F') {
                        val = tag(s1[0] & '\x1F', s1[0] & '\xE0');
                        return 1;
                    } else {
                        octet_sequnce s2;
                        if (find_marked_sequece(src, bit, s2, beg + 1) && (!s2.empty()) && (s2.size() <= (sizeof (id_type)))) {
                            id_type tmp = 0;
                            for (octet_sequnce::const_iterator it = s2.begin(); it != s2.end(); ++it)
                                tmp = (tmp << 7) | (static_cast<octet_type> (*it) & '\x7F');
                            val = tag(tmp, s1[0] & '\xE0');
                            return (1 + s2.size());
                        }
                    }
                }
                return 0;
            }


            ///////////////////////////////////////////////////////////////////////////////////
            // size_class from X.690                

            std::size_t size_x690_cast(size_class& val, const mutable_sequences& src, mutable_sequences::const_iterator bit, std::size_t beg) {
                octet_sequnce s1;
                if (boost::itu::row_cast(src, bit, s1, beg, 1) && (!s1.empty())) {
                    if (!(s1[0] & '\x80')) {
                        val = size_class(s1[0] & '\x7F');
                        return 1;
                    } else {
                        if ((s1[0] != '\x80')) {
                            std::size_t szblk = static_cast<std::size_t> (s1[0] & '\x7F');
                            octet_sequnce s2;
                            if (boost::itu::row_cast(src, bit, s2, beg + 1, szblk) && (!s2.empty()) && (s2.size() <= sizeof (std::size_t))) {
                                if (s2.front() & '\x80') {
                                    s2.insert(s2.begin(), '\x0');
                                    std::size_t bodysize = 0;
                                    if (!from_x690_cast<std::size_t > (bodysize, s2))
                                        return 0;
                                    val = size_class(bodysize);
                                    return s2.size();
                                } else {
                                    std::size_t bodysize = 0;
                                    if (!from_x690_cast<std::size_t > (bodysize, s2))
                                        return 0;
                                    val = size_class(bodysize);
                                    return 1 + s2.size();
                                }
                            }
                        } else {
                            val = size_class();
                            return 1;
                        }
                    }
                }
                return 0;
            }




            ///////////////////////////////////////////////////////////////////////////////////
            // real from X.690

            template<typename T>
            static bool from_x690_real_cast_special(T& vl, const octet_sequnce& val) {
                if (!val.empty()) {
                    switch (val[0]) {
                        case NAN_REAL_ID:
                        {
                            vl = std::numeric_limits<T>::quiet_NaN();
                            return true;
                        }
                        case INFINITY_REAL_ID:
                        {
                            vl = std::numeric_limits<T>::infinity();
                            return true;
                        }
                        case NEGATINFINITY_REAL_ID:
                        {
                            vl = -std::numeric_limits<T>::infinity();
                            return true;
                        }
                        case NEGATNULL_REAL_ID:
                        {
                            vl = -0.0;
                            return true;
                        }
                        default:
                        {
                            vl = std::numeric_limits<T>::quiet_NaN();
                            return true;
                        }
                    }
                }
                vl = 0;
                return true;
            }

            template<typename T>
            static bool from_x690_real_cast_decimal(T& vl, const octet_sequnce& val) {
                try {
                    vl = boost::lexical_cast<T > (std::string(val.begin(), val.end()));
                } catch (boost::bad_lexical_cast &) {
                    vl = std::numeric_limits<T>::quiet_NaN();
                }
                return true;
            }

            template<typename T, typename B, std::size_t MANT, std::size_t EXPB>
            static bool from_x690_real_cast_bin(T& vl, const octet_sequnce& val) {
                if (!val.empty()) {
                    B negat = (val[0] & '\x40') ? (B(1) << (sizeof (B)*8 - 1)) : 0;
                    int32_t base = 2;
                    switch (val[0] & '\x30') {
                        case '\x10': base = 8;
                            break;
                        case '\x20': base = 16;
                            break;
                    }
                    std::size_t factor = static_cast<std::size_t> ((val[0] & '\xC') >> 2);
                    std::size_t exp_sz = 1;
                    switch (val[0] & '\x3') {
                        case '\x1': exp_sz = 2;
                            break;
                        case '\x2': exp_sz = 3;
                            break;
                        case '\x3':
                        {
                            if (val.size() > 1) {
                                exp_sz = static_cast<std::size_t> (*reinterpret_cast<uint8_t*> (val[1]));
                            } else
                                return false;
                            break;
                        }
                    }

                    if (val.size() <= exp_sz)
                        return false;
                    octet_sequnce::const_iterator itrexen = val.begin() + exp_sz + 1;
                    int32_t exp_b = 0;
                    if (!from_x690_cast(exp_b, octet_sequnce(val.begin() + 1, itrexen)))
                        return false;
                    exp_b += (EXPB + MANT + factor);
                    B mant = 0;
                    //B marker0 = ((~B(0)) << MANT);
                    for (octet_sequnce::const_iterator it = itrexen; it != val.end(); ++it) {
                        if ((mant = (mant << 8) | static_cast<B> (*reinterpret_cast<const uint8_t*> (&(*it)))) & ((~B(0)) << MANT)) {
                            exp_b += (std::distance(it, val.end()) - 1)*8;
                            while (mant & ((~B(0)) << MANT)) {
                                mant >>= 1;
                                exp_b++;
                            }
                            break;
                        }
                    }

                    if (!mant) {
                        vl = 0;
                        return true;
                    }

                    //B marker1 = (B(1) << (MANT));
                    while (!((B(1) << (MANT)) & mant)) {
                        exp_b--;
                        mant <<= 1;
                    }
                    if (exp_b < 0) {
                        vl = static_cast<T>(negat ? -0.0 : 0);
                        return true;
                    }
                    B exp = static_cast<B> (exp_b);
                    //B marker2 = (~((~B(0)) << (sizeof(B)*8-MANT-1)));                         
                    if (exp >= (~((~B(0)) << (sizeof (B)*8 - MANT - 1)))) {
                        vl = negat ? (-std::numeric_limits<T>::infinity()) : (std::numeric_limits<T>::infinity());
                        return true;
                    }
                    exp <<= MANT;
                    B rslt = (mant & (~(B(1) << (MANT)))) | exp | negat;
                    vl = *reinterpret_cast<T*> (&rslt);
                }

                return true;
            }

            template<>
            bool from_x690_cast(float& vl, const octet_sequnce& val) {
                if (val.empty()) {
                    vl = 0;
                    return true;
                } else {
                    switch (val[0] & '\xC0') {
                        case 0: return from_x690_real_cast_decimal(vl, val);
                        case '\x40': return from_x690_real_cast_special(vl, val);
                        default: return from_x690_real_cast_bin<float, uint32_t, FLOAT_MANTISSA_SIZE, FLOAT_EXPONENTA_DELT > (vl, val);
                    }
                }
                return false;
            }

            template<>
            bool from_x690_cast(double& vl, const octet_sequnce& val) {
                if (val.empty()) {
                    vl = 0;
                    return true;
                } else {
                    switch (val[0] & '\xC0') {
                        case 0: return from_x690_real_cast_decimal(vl, val);
                        case '\x40': return from_x690_real_cast_special(vl, val);
                        default: return from_x690_real_cast_bin<double, uint64_t, DOUBLE_MANTISSA_SIZE, DOUBLE_EXPONENTA_DELT > (vl, val);
                    }
                }
                return false;
            }

            template<>
            bool from_x690_cast(long double& vl, const octet_sequnce& val) {
                if (val.empty()) {
                    vl = 0;
                    return true;
                } else {
                    switch (val[0] & '\xC0') {
                        case 0: return from_x690_real_cast_decimal(vl, val);
                        case '\x40': return from_x690_real_cast_special(vl, val);
                        default:
                        {
                            double tmp = 0;
                            if (from_x690_real_cast_bin<double, uint64_t, DOUBLE_MANTISSA_SIZE, DOUBLE_EXPONENTA_DELT > (tmp, val)) {
                                vl = tmp;
                                return true;
                            }
                        }
                    }
                }
                return false;
            }


            ///////////////////////////////////////////////////////////////////////////////////
            // bool from X.690

            template<>
            bool from_x690_cast(bool& vl, const octet_sequnce& val) {
                if (val.empty())
                    vl = false;
                else
                    vl = val[0];
                return true;
            }

            ///////////////////////////////////////////////////////////////////////////////////
            // null from X.690               

            template<>
            bool from_x690_cast(null_type& val, const octet_sequnce& vl) {
                if (vl.empty()) {
                    val = null_type();
                    return true;
                }
                return false;
            }

            ///////////////////////////////////////////////////////////////////////////////////
            // enumerated_type from X.690

            template<>
            bool from_x690_cast(enumerated_type& val, const octet_sequnce& src) {
                enumerated_base_type tmp;
                if (from_x690_cast(tmp, src)) {
                    val = tmp;
                    return true;
                }
                return false;
            }


            ///////////////////////////////////////////////////////////////////////////////////
            // oid from X.690

            bool from_x690_impl_cast(oidindx_type& val, const octet_sequnce& vl, octet_sequnce::const_iterator& its) {
                val = 0;
                while (its != vl.end()) {
                    val = (val << 7) | (static_cast<oidindx_type> (*reinterpret_cast<const uint8_t*> (&(*its))) & '\x7F');
                    if (((*its) & '\x80')) {
                        ++its;
                    } else {
                        ++its;
                        return true;
                    }
                }
                return false;
            }

            ///////////////////////////////////////////////////////////////////////////////////
            // relative from to X.690

            template<>
            bool from_x690_cast(oid_type& val, const octet_sequnce& vl) {
                octet_sequnce::const_iterator its = vl.begin();
                if (its == vl.end())
                    return false;
                val.clear();
                bool fst = true;
                oidindx_type tmp = 0;
                while (its != vl.end()) {
                    if (!from_x690_impl_cast(tmp, vl, its))
                        return false;
                    if (!fst)
                        val.push_back(tmp);
                    else {
                        fst = false;
                        if (tmp < 40) {
                            val.push_back(0);
                            val.push_back(tmp);
                        } else {
                            if (tmp < 80) {
                                val.push_back(1);
                                val.push_back(tmp - 40);
                            } else {
                                val.push_back(2);
                                val.push_back(tmp - 80);
                            }
                        }
                    }
                }
                return true;
            }

            ///////////////////////////////////////////////////////////////////////////////////
            // relative from to X.690

            template<>
            bool from_x690_cast(reloid_type& val, const octet_sequnce& vl) {
                octet_sequnce::const_iterator its = vl.begin();
                if (its == vl.end())
                    return false;
                val.clear();
                oidindx_type tmp = 0;
                while (its != vl.end()) {
                    if (!from_x690_impl_cast(tmp, vl, its))
                        return false;
                    val.push_back(tmp);
                }
                return true;
            }


            ///////////////////////////////////////////////////////////////////////////////////
            // utctime_type from to X.690

            template<>
            bool from_x690_cast(utctime_type& val, const octet_sequnce& src) {
                val = to_utctime(src);
                return true; //!val.is_special();
            }

            ///////////////////////////////////////////////////////////////////////////////////
            // gentime_type from to X.690

            template<>
            bool from_x690_cast(gentime_type& val, const octet_sequnce& src) {
                val = to_gentime(src);
                return true; //!val.value().is_special();
            }

            ///////////////////////////////////////////////////////////////////////////////////
            // any_type from to X.690

            template<>
            bool from_x690_cast(any_type& val, const octet_sequnce& src) {
                val.set(src);
                return true;
            }
            
            template<>
            octet_sequnce::iterator reader_setunuse(octet_sequnce& seq,  bitstring_type& vl) {
                octet_sequnce::iterator it=seq.begin();
                if (it!=seq.end()){
                    vl.unusebits(static_cast<std::size_t>(*it));
                    it++;
                }
                return it;
            }              



            ////////////////////////////////////////////

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<int8_t>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<uint8_t>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<int16_t>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<uint16_t>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<int32_t>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<uint32_t>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<int64_t>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<uint64_t>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<enumerated_type>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<float>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<double>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<long double>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<bool>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<null_type>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<oid_type>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<reloid_type>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<any_type>& vl) {
                std::size_t sz = stream.stack_size();
                octet_sequnce data;
                if (boost::itu::row_cast(stream.buffers(), stream.buffers().begin(), data, 0, sz)) {
                    if (from_x690_cast(*const_cast<any_type*> (&vl.value()), data)) {
                        // stream.pop_stack();
                    }
                }
                return stream;
                //return  primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<bitstring_type>& vl) {
                const_cast<bitstring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<bitstring_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<octetstring_type>& vl) {
                const_cast<octetstring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<octetstring_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<utf8string_type>& vl) {
                const_cast<utf8string_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<utf8string_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<numericstring_type>& vl) {
                const_cast<numericstring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<numericstring_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<printablestring_type>& vl) {
                const_cast<printablestring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<printablestring_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<t61string_type>& vl) {
                const_cast<t61string_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<t61string_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<videotexstring_type>& vl) {
                const_cast<videotexstring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<videotexstring_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<ia5string_type>& vl) {
                const_cast<ia5string_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<ia5string_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<graphicstring_type>& vl) {
                const_cast<graphicstring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<graphicstring_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<objectdescriptor_type>& vl) {
                const_cast<objectdescriptor_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<objectdescriptor_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<visiblestring_type>& vl) {
                const_cast<visiblestring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<visiblestring_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<generalstring_type>& vl) {
                const_cast<generalstring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<generalstring_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<universalstring_type>& vl) {
                const_cast<universalstring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<universalstring_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<bmpstring_type>& vl) {
                const_cast<bmpstring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<bmpstring_type*> (&(vl.value())), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<utctime_type>& vl) {
                return primitive_desirialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, const implicit_value<gentime_type>& vl) {
                return primitive_desirialize(stream, vl);
            }

            ////////  Archiver

            tag input_coder::test_tl(size_class& sz) {

                tag tmptag;
                std::size_t sztag = tag_x690_cast(tmptag, buffers(), buffers().begin());
                if (sztag) {
                    std::size_t szsize = size_x690_cast(sz, buffers(), buffers().begin(), sztag);
                    if (szsize)
                        return tmptag;
                }
                return tag();
            }

            std::size_t input_coder::stack_size() {

                if (!stack_.empty()) {
                    return stack_.top().sizeinfo.defined ?
                            stack_.top().sizeinfo.size : ((stack_.top().sizeinfo.size > 2) ?
                            (stack_.top().sizeinfo.size - 2) : 0);
                }
                return 0;
            }

            bool input_coder::parse_tl(const tag& tg, size_class& rsltsz, bool settype, bool optional) {


                std::size_t size_tlv = size();
                bool is_set_child = false;
                std::size_t size_test = 0;
                tag tmptag;

                if (!stack_.empty()) {
                    is_set_child = stack_.top().is_set;
                    size_tlv = stack_.top().sizeinfo.defined ?
                            stack_.top().sizeinfo.size : ((stack_.top().sizeinfo.size > 2) ?
                            (stack_.top().sizeinfo.size - 2) : 0);
                    //std::cout << " size_tlv : " << size_tlv  << std::endl;
                }

                //std::cout << " buffer: ";
                //boost::itu::operator <<(std::cout, buffers());
                //std::cout << std::endl;

                while (size_test < size_tlv) {
                    std::size_t sztag = tag_x690_cast(tmptag, buffers(), buffers().begin());
                    if (sztag && (tg == tmptag)) {
                        if (optional)
                            return true;
                        std::size_t szsize = size_x690_cast(rsltsz, buffers(), buffers().begin(), sztag);
                        if (szsize) {
                            std::size_t next_test = rsltsz.size();

                            if (rsltsz.undefsize()) {
                                if (!next(next_test))
                                    return false;
                            } else
                                next_test += (szsize + sztag);

                            pop_front(szsize + sztag);

                            if (!stack_.empty())
                                stack_.top().sizeinfo.size = (stack_.top().sizeinfo.size >= next_test) ?
                                (stack_.top().sizeinfo.size - next_test) : 0;
                            stack_.push(tlv_item(settype, tlv_size(!rsltsz.undefsize(), (next_test - (szsize + sztag)))));
                            return true;
                        }
                        return false;
                    } else {
                        if (!sztag)
                            return false;
                        std::size_t next_test = 0;
                        if (!next(next_test))
                            return false;
                        if (!is_set_child) {
                            if (optional)
                                return false;
                            if (!stack_.empty())
                                stack_.top().sizeinfo.size = (stack_.top().sizeinfo.size >= next_test) ?
                                (stack_.top().sizeinfo.size - next_test) : 0;
                            size_test += next_test;
                            pop_front(next_test);
                        } else {

                            size_test += next_test;
                            if (!boost::itu::splice_frontlist(buffers(), next_test, size_tlv))
                                return false;

                        }
                    }
                }
                return false;
            }

            void input_coder::pop_stack() {
                if (!stack_.empty()) {
                    if (!stack_.top().sizeinfo.defined) {
                        if (is_endof())
                            pop_front(2);
                        else
                            throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                    } else {
                        pop_front(stack_.top().sizeinfo.size);
                    }
                    stack_.pop();
                }
            }

            bool input_coder::next(std::size_t & sz) const {
                tag tmptag;
                std::size_t sztag = tag_x690_cast(tmptag, buffers(), buffers().begin(), sz);
                if (sztag) {
                    size_class tmpsize;
                    std::size_t szsize = size_x690_cast(tmpsize, buffers(), buffers().begin(), sztag + sz);
                    if (szsize) {
                        if (tmpsize.undefsize()) {
                            if (tmptag.constructed()) {
                                sz += (szsize + sztag);
                                while ((!is_endof(sz)) && (sz < size()))
                                    if (!next(sz))
                                        return false;

                                if (!is_endof(sz))
                                    return false;
                                sz += 2;
                                return true;
                            } else {
                                std::size_t rsltsz = 0;
                                if (boost::itu::find_eof(buffers(), buffers().begin(), rsltsz, sz)) {
                                    sz += (szsize + sztag + rsltsz);
                                    return true;
                                }
                            }
                        } else {
                            sz += (szsize + sztag + tmpsize.size());
                            return true;
                        }
                    }
                }
                return false;
            }


        }
        
        

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif       

        /////// external_type

        template<> void external_type::Encoding_type::serialize(boost::asn1::x690::output_coder& arch) {
            switch (type()) {
                case Encoding_type_single_ASN1_type:
                {
                    ITU_T_EXPLICIT_TAG(value<any_type > (false, Encoding_type_single_ASN1_type), 0);
                    break;
                }
                case Encoding_type_octet_aligned:
                {
                    ITU_T_IMPLICIT_TAG(value<octetstring_type > (false, Encoding_type_octet_aligned), 1);
                    break;
                }
                case Encoding_type_arbitrary:
                {
                    ITU_T_IMPLICIT_TAG(value<bitstring_type > (false, Encoding_type_arbitrary), 2);
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void external_type::Encoding_type::serialize(boost::asn1::x690::input_coder& arch) {
            int __tag_id__ = arch.test_id();
            switch (arch.test_class()) {
                case 0x0:
                {
                    switch (__tag_id__) {
                        default:
                        {
                        }
                    }
                }
                case 0x40:
                {
                    switch (__tag_id__) {
                        default:
                        {
                        }
                    }
                }
                case 0x80:
                {
                    switch (__tag_id__) {
                        case 0:
                        {
                            if (ITU_T_EXPLICIT_TAG(value<any_type > (true, Encoding_type_single_ASN1_type), 0)) return;
                            else free();
                            break;
                        }
                        case 1:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<octetstring_type > (true, Encoding_type_octet_aligned), 1)) return;
                            else free();
                            break;
                        }
                        case 2:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<bitstring_type > (true, Encoding_type_arbitrary), 2)) return;
                            else free();
                            break;
                        }
                        default:
                        {
                        }
                    }
                }
                case 0xC0:
                {
                    switch (__tag_id__) {
                        default:
                        {
                        }
                    }
                }
                default:
                {
                }
            }
        }

        template<> void external_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_BIND_TAG(direct_reference_);
            ITU_T_BIND_TAG(indirect_reference_);
            ITU_T_BIND_TAG(data_value_descriptor_);
            ITU_T_BIND_CHOICE(*encoding_);
        }

        template<> void external_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_BIND_TAG(direct_reference_);
            ITU_T_BIND_TAG(indirect_reference_);
            ITU_T_BIND_TAG(data_value_descriptor_);
            ITU_T_BIND_CHOICE(*encoding_);
        }




        //////////////////////////////////////////////////////////
        //embeded_type

        template<> void embeded_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_IMPLICIT_TAG(*abstract_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_, 1);
        }

        template<> void embeded_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_IMPLICIT_TAG(*abstract_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_, 1);
        }

        template<> void embeded_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);
        }

        template<> void embeded_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);
        }

        template<> void embeded_type::Identification_type::serialize(boost::asn1::x690::output_coder& arch) {
            switch (type()) {
                case Identification_type_syntaxes:
                {
                    ITU_T_IMPLICIT_TAG(value<Syntaxes_type > (false, Identification_type_syntaxes), 0);
                    break;
                }
                case Identification_type_syntax:
                {
                    ITU_T_IMPLICIT_TAG(value<oid_type > (false, Identification_type_syntax), 1);
                    break;
                }
                case Identification_type_presentation_context_id:
                {
                    ITU_T_IMPLICIT_TAG(value<int > (false, Identification_type_presentation_context_id), 2);
                    break;
                }
                case Identification_type_context_negotiation:
                {
                    ITU_T_IMPLICIT_TAG(value<Context_negotiation_type > (false, Identification_type_context_negotiation), 3);
                    break;
                }
                case Identification_type_transfer_syntax:
                {
                    ITU_T_IMPLICIT_TAG(value<oid_type > (false, Identification_type_transfer_syntax), 4);
                    break;
                }
                case Identification_type_fixed:
                {
                    ITU_T_IMPLICIT_TAG(value<null_type > (false, Identification_type_fixed), 5);
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void embeded_type::Identification_type::serialize(boost::asn1::x690::input_coder& arch) {
            int __tag_id__ = arch.test_id();
            switch (arch.test_class()) {
                case 0x0:
                {
                    switch (__tag_id__) {
                        default:
                        {
                        }
                    }
                }
                case 0x40:
                {
                    switch (__tag_id__) {
                        default:
                        {
                        }
                    }
                }
                case 0x80:
                {
                    switch (__tag_id__) {
                        case 0:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<Syntaxes_type > (true, Identification_type_syntaxes), 0)) return;
                            else free();
                            break;
                        }
                        case 1:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<oid_type > (true, Identification_type_syntax), 1)) return;
                            else free();
                            break;
                        }
                        case 2:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<int > (true, Identification_type_presentation_context_id), 2)) return;
                            else free();
                            break;
                        }
                        case 3:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<Context_negotiation_type > (true, Identification_type_context_negotiation), 3)) return;
                            else free();
                            break;
                        }
                        case 4:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<oid_type > (true, Identification_type_transfer_syntax), 4)) return;
                            else free();
                            break;
                        }
                        case 5:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<null_type > (true, Identification_type_fixed), 5)) return;
                            else free();
                            break;
                        }
                        default:
                        {
                        }
                    }
                }
                case 0xC0:
                {
                    switch (__tag_id__) {
                        default:
                        {
                        }
                    }
                }
                default:
                {
                }
            }
        }

        template<> void embeded_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_CHOICE_TAG(*identification_, 0);
            ITU_T_IMPLICIT_TAG(*data_value_, 1);
        }

        template<> void embeded_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_CHOICE_TAG(*identification_, 0);
            ITU_T_IMPLICIT_TAG(*data_value_, 1);
        }



        //////////////////////////////////////////////////////////////

        template<> void characterstring_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_IMPLICIT_TAG(*abstract_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_, 1);
        }

        template<> void characterstring_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_IMPLICIT_TAG(*abstract_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_, 1);
        }

        template<> void characterstring_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);
        }

        template<> void characterstring_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);
        }

        template<> void characterstring_type::Identification_type::serialize(boost::asn1::x690::output_coder& arch) {
            switch (type()) {
                case Identification_type_syntaxes:
                {
                    ITU_T_IMPLICIT_TAG(value<Syntaxes_type > (false, Identification_type_syntaxes), 0);
                    break;
                }
                case Identification_type_syntax:
                {
                    ITU_T_IMPLICIT_TAG(value<oid_type > (false, Identification_type_syntax), 1);
                    break;
                }
                case Identification_type_presentation_context_id:
                {
                    ITU_T_IMPLICIT_TAG(value<int > (false, Identification_type_presentation_context_id), 2);
                    break;
                }
                case Identification_type_context_negotiation:
                {
                    ITU_T_IMPLICIT_TAG(value<Context_negotiation_type > (false, Identification_type_context_negotiation), 3);
                    break;
                }
                case Identification_type_transfer_syntax:
                {
                    ITU_T_IMPLICIT_TAG(value<oid_type > (false, Identification_type_transfer_syntax), 4);
                    break;
                }
                case Identification_type_fixed:
                {
                    ITU_T_IMPLICIT_TAG(value<null_type > (false, Identification_type_fixed), 5);
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void characterstring_type::Identification_type::serialize(boost::asn1::x690::input_coder& arch) {
            int __tag_id__ = arch.test_id();
            switch (arch.test_class()) {
                case 0x0:
                {
                    switch (__tag_id__) {
                        default:
                        {
                        }
                    }
                }
                case 0x40:
                {
                    switch (__tag_id__) {
                        default:
                        {
                        }
                    }
                }
                case 0x80:
                {
                    switch (__tag_id__) {
                        case 0:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<Syntaxes_type > (true, Identification_type_syntaxes), 0)) return;
                            else free();
                            break;
                        }
                        case 1:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<oid_type > (true, Identification_type_syntax), 1)) return;
                            else free();
                            break;
                        }
                        case 2:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<int > (true, Identification_type_presentation_context_id), 2)) return;
                            else free();
                            break;
                        }
                        case 3:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<Context_negotiation_type > (true, Identification_type_context_negotiation), 3)) return;
                            else free();
                            break;
                        }
                        case 4:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<oid_type > (true, Identification_type_transfer_syntax), 4)) return;
                            else free();
                            break;
                        }
                        case 5:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<null_type > (true, Identification_type_fixed), 5)) return;
                            else free();
                            break;
                        }
                        default:
                        {
                        }
                    }
                }
                case 0xC0:
                {
                    switch (__tag_id__) {
                        default:
                        {
                        }
                    }
                }
                default:
                {
                }
            }
        }

        template<> void characterstring_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_CHOICE_TAG(*identification_, 0);
            ITU_T_IMPLICIT_TAG(*string_value_, 1);
        }

        template<> void characterstring_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_CHOICE_TAG(*identification_, 0);
            ITU_T_IMPLICIT_TAG(*string_value_, 1);
        }

#ifdef _MSC_VER
#pragma warning(pop)
#endif
        
    }
}

