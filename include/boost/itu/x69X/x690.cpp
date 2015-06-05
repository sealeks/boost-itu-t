//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#include <boost/lexical_cast.hpp>

#include <boost/itu/x69X/x690.hpp>

namespace boost {
    namespace asn1 {
        namespace x690 {

            std::ostream& operator<<(std::ostream& stream, const size_class& vl) {
                return vl.undefsize() ? (stream << "SIZE:  undef" << '\n') : (stream << "SIZE:  " << vl.size() << '\n');
            }

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////               



            ///////////////////////////////////////////////////////////////////////////////////
            // size_class to X.690

            std::size_t tosize_x690_cast(const size_class& val, octet_sequnce& src) {
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

            octet_sequnce tosize_x690_cast(const size_class& val) {
                octet_sequnce tmp;
                tosize_x690_cast(val, tmp);
                return tmp;
            }




            // STRING REALISZATION

            template<>
            void x690_string_to_stream_cast(const bit_string& val, output_coder& stream, octet_type lentype) {
                if (!lentype) {
                    stream.add(octet_sequnce(1, static_cast<octet_type> (val.unusebits() % 8)));
                    stream.add(val);
                    return;
                } else {

                    typedef bit_string::const_iterator const_iterator_type;
                    typedef bit_string::difference_type difference_type;

                    const_iterator_type it = val.begin();
                    while (it != val.end()) {
                        //stream.add(octet_sequnce(1, static_cast<octet_type> (TYPE_BITSTRING)));
                        stream.addtag(tag(TYPE_BITSTRING), false);
                        difference_type diff = std::distance(it, val.end());
                        if (diff > static_cast<difference_type> (CER_STRING_MAX_SIZE - 1)) {
                            diff = static_cast<difference_type> (CER_STRING_MAX_SIZE - 1);
                            stream.add(tosize_x690_cast(size_class(static_cast<std::size_t> (diff + 1))));
                            stream.add(octet_sequnce(1, static_cast<octet_type> (0)));
                        } else {
                            stream.add(tosize_x690_cast(size_class(static_cast<std::size_t> (diff + 1))));
                            stream.add(octet_sequnce(1, static_cast<octet_type> (val.unusebits() % 8)));
                        }
                        stream.add(octet_sequnce(it, it + diff));
                        it = it + diff;
                        stream.pop_stack();
                    }
                }
            }

            template<>            
            void x690_string_to_stream_cast(const octet_string& val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(val.as_base(), stream, lentype);
            }
            
            template<>            
            void x690_string_to_stream_cast(const utf8_string& val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(as_octet_sequnce(val), stream, lentype);
            }            
            
            template<>
            void x690_string_to_stream_cast(const bmp_string& val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(val.as_octets(), stream, lentype);
            }

            template<>
            void x690_string_to_stream_cast(const universal_string& val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(val.as_octets(), stream, lentype);
            }

            template<>
            void x690_string_to_stream_cast(const numeric_string& val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(as_octet_sequnce(val), stream, lentype);
            }

            template<>
            void x690_string_to_stream_cast(const printable_string& val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(as_octet_sequnce(val), stream, lentype);
            }

            template<>
            void x690_string_to_stream_cast(const t61_string & val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(as_octet_sequnce(val), stream, lentype);
            }

            template<>
            void x690_string_to_stream_cast(const videotex_string& val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(as_octet_sequnce(val), stream, lentype);
            }

            template<>
            void x690_string_to_stream_cast(const ia5_string& val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(as_octet_sequnce(val), stream, lentype);
            }

            template<>
            void x690_string_to_stream_cast(const graphic_string& val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(as_octet_sequnce(val), stream, lentype);
            }

            template<>
            void x690_string_to_stream_cast(const object_descriptor & val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(as_octet_sequnce(val), stream, lentype);
            }

            template<>
            void x690_string_to_stream_cast(const visible_string& val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(as_octet_sequnce(val), stream, lentype);
            }

            template<>
            void x690_string_to_stream_cast(const general_string& val, output_coder& stream, octet_type lentype) {
                x690_string_to_stream_cast(as_octet_sequnce(val), stream, lentype);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int8_t>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint8_t>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int16_t>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint16_t>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int32_t>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint32_t>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<int64_t>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<uint64_t>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<enumerated>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<float>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<double>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<long double>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<bool>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<null_type>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<oid_type>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<reloid_type>& vl) {
                return primitive_serialize(stream, vl);
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
                //return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<bit_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<octet_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<utf8_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<numeric_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<printable_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<t61_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<videotex_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<ia5_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<graphic_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value< object_descriptor>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<visible_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<general_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<universal_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<bmp_string>& vl) {
                stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<utctime>& vl) {
                return primitive_serialize(stream, vl);
            }

            template<>
            output_coder& operator<<(output_coder& stream, const implicit_value<gentime>& vl) {
                return primitive_serialize(stream, vl);
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

            void output_coder::sort_tlv(tlv_vector & vct) {

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

            template<>
            octet_sequnce::iterator reader_setunuse(octet_sequnce& seq, bit_string & vl) {
                octet_sequnce::iterator it = seq.begin();
                if (it != seq.end()) {
                    vl.unusebits(static_cast<std::size_t> (*it));
                    it++;
                }
                return it;
            }

            template<>
            void stringtype_inserter(universal_string& vl, octet_sequnce::iterator beg, octet_sequnce::iterator end) {
                vl.append_octets(octet_sequnce(beg, end));
            }

            template<>
            void stringtype_inserter(bmp_string& vl, octet_sequnce::iterator beg, octet_sequnce::iterator end) {
                vl.append_octets(octet_sequnce(beg, end));
            }

            ////////////////////////////////////////////

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<int8_t>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<uint8_t>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<int16_t>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<uint16_t>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<int32_t>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<uint32_t>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<int64_t>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<uint64_t>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<enumerated>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<float>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<double>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<long double>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<bool>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<null_type>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<oid_type>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<reloid_type>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<any_type>& vl) {
                std::size_t sz = stream.stack_size();
                octet_sequnce data;
                if (boost::itu::row_cast(stream.buffers(), stream.buffers().begin(), data, 0, sz)) {
                    if (from_x690_cast(vl.value(), data)) {
                        // stream.pop_stack();
                    }
                }
                return stream;
                //return  primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<bit_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<octet_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<utf8_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<numeric_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<printable_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<t61_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<videotex_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<ia5_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<graphic_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<object_descriptor>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<visible_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<general_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<universal_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<bmp_string>& vl) {
                stringtype_reader(stream, vl.value(), vl.id(), vl.mask());
                return stream;
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<utctime>& vl) {
                return primitive_deserialize(stream, vl);
            }

            template<>
            input_coder& operator>>(input_coder& stream, implicit_value<gentime>& vl) {
                return primitive_deserialize(stream, vl);
            }

            ////////  Archiver

            tag input_coder::test_tl(size_class & sz) {

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
                    ITU_T_IMPLICIT_TAG(value<octet_string > (false, Encoding_type_octet_aligned), 1);
                    break;
                }
                case Encoding_type_arbitrary:
                {
                    ITU_T_IMPLICIT_TAG(value<bit_string > (false, Encoding_type_arbitrary), 2);
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
                            if (ITU_T_IMPLICIT_TAG(value<octet_string > (true, Encoding_type_octet_aligned), 1)) return;
                            else free();
                            break;
                        }
                        case 2:
                        {
                            if (ITU_T_IMPLICIT_TAG(value<bit_string > (true, Encoding_type_arbitrary), 2)) return;
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
        //embeded_pdv

        template<> void embeded_pdv::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_IMPLICIT_TAG(*abstract_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_, 1);
        }

        template<> void embeded_pdv::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_IMPLICIT_TAG(*abstract_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_, 1);
        }

        template<> void embeded_pdv::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);
        }

        template<> void embeded_pdv::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);
        }

        template<> void embeded_pdv::Identification_type::serialize(boost::asn1::x690::output_coder& arch) {
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

        template<> void embeded_pdv::Identification_type::serialize(boost::asn1::x690::input_coder& arch) {
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

        template<> void embeded_pdv::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_CHOICE_TAG(*identification_, 0);
            ITU_T_IMPLICIT_TAG(*data_value_, 1);
        }

        template<> void embeded_pdv::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_CHOICE_TAG(*identification_, 0);
            ITU_T_IMPLICIT_TAG(*data_value_, 1);
        }



        //////////////////////////////////////////////////////////////

        template<> void character_string::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_IMPLICIT_TAG(*abstract_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_, 1);
        }

        template<> void character_string::Identification_type::Syntaxes_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_IMPLICIT_TAG(*abstract_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_, 1);
        }

        template<> void character_string::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);
        }

        template<> void character_string::Identification_type::Context_negotiation_type::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
            ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);
        }

        template<> void character_string::Identification_type::serialize(boost::asn1::x690::output_coder& arch) {
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

        template<> void character_string::Identification_type::serialize(boost::asn1::x690::input_coder& arch) {
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

        template<> void character_string::serialize(boost::asn1::x690::output_coder& arch) {
            ITU_T_CHOICE_TAG(*identification_, 0);
            ITU_T_IMPLICIT_TAG(*string_value_, 1);
        }

        template<> void character_string::serialize(boost::asn1::x690::input_coder& arch) {
            ITU_T_CHOICE_TAG(*identification_, 0);
            ITU_T_IMPLICIT_TAG(*string_value_, 1);
        }

#ifdef _MSC_VER
#pragma warning(pop)
#endif

    }
}

