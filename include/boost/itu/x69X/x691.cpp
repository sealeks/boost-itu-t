//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#include <boost/lexical_cast.hpp>
#include <boost/itu/x69X/x691.hpp>

namespace boost {
    namespace asn1 {
        namespace x691 {


            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////               



            ///////////////////////////////////////////////////////////////////////////////////
            // size_class to X.691

            std::size_t to_x691_cast(const size_class& val, octet_sequnce& src) {
                if (val.size() < LENGH_128B) {
                    src.push_back(static_cast<octet_type> (static_cast<octet_type> (val.size())));
                    return 1;
                } else if (val.size() < LENGH_16K) {
                    boost::uint16_t vl = static_cast<boost::uint16_t> (val.size());
#ifdef BIG_ENDIAN_ARCHITECTURE              
                    src.push_back(static_cast<octet_type> (((vl << 8) & 0x3FFF | ? ? ? 0x8000));
                            src.push_back(static_cast<octet_type> (vl & ? ? 0xFF));
#else                    
                    src.push_back(static_cast<octet_type> (((vl >> 8) & 0x3F) | 0x80));
                    src.push_back(static_cast<octet_type> (vl & 0xFF));
#endif                    
                    return 2;
                }
                src.push_back(static_cast<octet_type> (0xC0));
                std::size_t m = (val.size() % (LENGH_64K + 1)) / LENGH_16K;
                src.push_back(static_cast<octet_type> (m));
                return 2;
            }

            octet_sequnce to_x691_cast(const size_class& val) {
                octet_sequnce tmp;
                to_x691_cast(val, tmp);
                return tmp;
            }





            //// enumerated_type cast                          

            std::size_t to_x691_cast(const enumerated_type& val, octet_sequnce& src) {
                return to_x691_cast(val.value(), src);
            }


            ///////////////////////////////////////////////////////////////////////////////////
            // any_type to X.691

            std::size_t to_x691_cast(const any_type& val, octet_sequnce& src) {
                std::size_t strtsz = src.size();
                val.get(src);
                return (src.size() - strtsz);
            }



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////            

            void output_coder::add_bitmap(const bitstring_type & vl, bool alighn) {
                if (unusebits()) {
                    //const_sequences::reverse_iterator it = listbuffers_->rbegin();
                    boost::itu::vect_octet_sequnce_ptr::reverse_iterator dit = rows_vect.rbegin();
                    boost::itu::octet_sequnce_ptr lstdata_ptr = *dit;
                    octet_sequnce& lstdata = *lstdata_ptr;
                    unusebits(boost::itu::split_bits_in_octets(lstdata, alighn ? 0 : unusebits(), vl.as_octet_sequnce(), vl.unusebits()));
                    listbuffers_->back() = const_buffer(&(rows_vect.back()->operator[](0)), rows_vect.back()->size());
                } else {
                    add(vl.as_octet_sequnce());
                    unusebits(vl.unusebits());
                }
            }

            void output_coder::add_octets(const octet_sequnce& vl, bool alighn) {
                if (unusebits()) {
                    //const_sequences::reverse_iterator it = listbuffers_->rbegin();
                    boost::itu::vect_octet_sequnce_ptr::reverse_iterator dit = rows_vect.rbegin();
                    boost::itu::octet_sequnce_ptr lstdata_ptr = *dit;
                    octet_sequnce& lstdata = *lstdata_ptr;
                    boost::itu::split_bits_in_octets(lstdata, alighn ? 0 : unusebits(), vl);
                    listbuffers_->back() = const_buffer(&(rows_vect.back()->operator[](0)), rows_vect.back()->size());
                } else {
                    add(vl);
                }
            }

            void output_coder::add_octets(const octetstring_type & vl, bool alighn) {
                add_octets(vl.as_octet_sequnce(), alighn);
            }


            // STRING REALISZATION

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& sz, const octet_sequnce& elms, bool align) {
                stream.add(sz);
                stream.add(elms);
                return stream;
            }

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& sz, const bitstring_type& elms, bool align) {
                stream.add(sz);
                stream.add(elms);
                return stream;
            }

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& elms, std::size_t rlsz, bool align) {
                if (rlsz) {
                    if (rlsz == elms.size())
                        stream.add(elms);
                    else if (rlsz < elms.size())
                        stream.add(octet_sequnce(elms.begin(), elms.begin() + rlsz));
                    else {
                        stream.add(elms);
                        stream.add(octet_sequnce(rlsz - elms.size()));
                    }
                }
                return stream;
            }

            template<>
            output_coder& octet_writer_undefsz(output_coder& stream, const bitstring_type& vl) {
                std::size_t sz = vl.sizebits();
                std::size_t beg = 0;
                while (beg < sz) {
                    if ((sz - beg) < LENGH_16K) {
                        octets_writer(stream, to_x691_cast(size_class(sz - beg)),
                                bitstring_type(octet_sequnce(vl.begin() + beg / 8, vl.end())), vl.unusebits());
                        beg = sz;
                    } else {
                        if ((sz - beg) < LENGH_64K) {
                            std::size_t m = (sz - beg) / LENGH_16K;
                            std::size_t nbeg = beg + LENGH_16K*m;
                            octets_writer(stream, to_x691_cast(size_class(LENGH_16K * m)),
                                    octet_sequnce(vl.begin() + beg / 8, vl.begin() + nbeg / 8));
                            beg = nbeg;
                        } else {
                            octets_writer(stream, to_x691_cast(size_class(LENGH_64K)),
                                    octet_sequnce(vl.begin() + beg / 8, vl.begin() + (beg + LENGH_64K) / 8));
                            beg += LENGH_64K;
                        }
                        if (beg == sz)
                            octets_writer(stream, to_x691_cast(size_class(0)),
                                octet_sequnce());
                    }
                }
                return stream;
            }

            output_coder& operator<<(output_coder& stream, const uint8_t& vl) {
                return primitive_int_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const int8_t& vl) {
                return primitive_int_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const uint16_t& vl) {
                return primitive_int_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const int16_t& vl) {
                return primitive_int_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const uint32_t& vl) {
                return primitive_int_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const int32_t& vl) {
                return primitive_int_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const uint64_t& vl) {
                return primitive_int_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const int64_t& vl) {
                return primitive_int_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const enumerated_type& vl) {
                return stream; // primitive_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const float& vl) {
                return primitive_690_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const double& vl) {
                return primitive_690_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const long double& vl) {
                return primitive_690_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const bool& vl) {
                stream.add_bitmap(bitstring_type(vl));
                return stream;
            }

            output_coder& operator<<(output_coder& stream, const null_type& vl) {
                return stream;
            }

            output_coder& operator<<(output_coder& stream, const oid_type& vl) {
                return primitive_690_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const reloid_type& vl) {
                return primitive_690_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const any_type& vl) {
                return stream;
            }

            output_coder& operator<<(output_coder& stream, const bitstring_type& vl) {
                return octet_writer_undefsz(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const octetstring_type& vl) {
                return octet_writer_undefsz(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<octetstring_type>& vl) {
                return octet_writer_defsz(stream, vl); // as known-multi 1 oct                
            }

            output_coder& operator<<(output_coder& stream, const utf8string_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<utf8string_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const numericstring_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce()); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<numericstring_type>& vl) {
                return octet_writer_defsz(stream, vl); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const printablestring_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce()); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<printablestring_type>& vl) {
                return octet_writer_defsz(stream, vl); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const t61string_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<t61string_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const videotexstring_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<videotexstring_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const ia5string_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce()); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<ia5string_type>& vl) {
                return octet_writer_defsz(stream, vl); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const graphicstring_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<graphicstring_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const objectdescriptor_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<objectdescriptor_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const visiblestring_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce()); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<visiblestring_type>& vl) {
                return octet_writer_defsz(stream, vl); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const generalstring_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<generalstring_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const universalstring_type& vl) {
                //stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream; // known-multi 4 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<universalstring_type>& vl) {
                //stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream; // known-multi 4 oct
            }

            output_coder& operator<<(output_coder& stream, const bmpstring_type& vl) {
                //stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream; // known-multi 2 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<bmpstring_type>& vl) {
                //stringtype_writer(stream, vl.value(), vl.id(), vl.mask());
                return stream; // known-multi 2 oct
            }

            output_coder& operator<<(output_coder& stream, const utctime_type& vl) {
                return primitive_690_serialize(stream, vl);
            }

            output_coder& operator<<(output_coder& stream, const gentime_type& vl) {
                return primitive_690_serialize(stream, vl);
            }







            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*INPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            std::size_t input_coder::get_bitmap(std::size_t sz, bitstring_type& vl, bool alighn) {
                if (sz) {
                    std::size_t usbit = usebits();
                    std::size_t octsize = 1;
                    if (usbit < sz)
                        octsize += ((sz - usbit - 1) / 8 + 1);
                    std::size_t bmp_octsize = (sz - 1) / 8 + 1;
                    octet_sequnce raw;
                    if (!(boost::itu::row_cast(buffers(), buffers().begin(), raw, 0, octsize)))
                        return 0;
                    if (unusebits()) {
                        boost::itu::left_shift_bits_in_octets(raw, unusebits());
                        if (bmp_octsize < raw.size())
                            raw.erase(raw.begin() + bmp_octsize, raw.end());
                    };
                    vl = bitstring_type(raw, sz ? (8 - sz % 8) : 0);
                }
                return sz;
            }

            std::size_t input_coder::get_octets(std::size_t sz, octet_sequnce& vl, bool alighn) {
                if (sz) {
                    if (unusebits())
                        sz++;
                    vl.clear();
                    if (!boost::itu::row_cast(buffers(), buffers().begin(), vl, 0, sz))
                        return 0;
                    if (unusebits()) {
                        boost::itu::left_shift_bits_in_octets(vl, unusebits());
                        vl.erase(vl.begin()+(sz - 1), vl.end());
                    }
                }
                return sz;
            }

            std::size_t input_coder::pop_bitmap(std::size_t sz, bool alighn) {
                if (sz) {
                    std::size_t usbit = usebits();
                    std::size_t octsize = 0;
                    if (usbit < sz)
                        octsize += ((sz - usbit - 1) / 8 + 1);
                    if (octsize)
                        pop_front(octsize);
                    unusebits(unusebits() + sz);
                }
                return sz;
            }

            std::size_t input_coder::pop_octets(std::size_t sz, bool alighn) {
                if (sz)
                    pop_front(sz);
                return sz;
            }

            std::size_t input_coder::get_pop_bitmap(std::size_t sz, bitstring_type& vl, bool alighn) {
                std::size_t rslt = get_bitmap(sz, vl, alighn);
                if (rslt) {
                    pop_bitmap(sz, alighn);
                } else {
                    if (sz)
                        throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                }
                return rslt;
            }

            std::size_t input_coder::get_pop_octets(std::size_t sz, octet_sequnce& vl, bool alighn) {
                std::size_t rslt = get_octets(sz, vl, alighn);
                if (rslt) {
                    pop_octets(sz, alighn);
                } else {
                    if (sz)
                        throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                }
                return rslt;
            }

            bitstring_type input_coder::get_pop_bmp(std::size_t sz, bool alighn) {
                bitstring_type tmp;
                get_pop_bitmap(sz, tmp, alighn);
                return tmp;
            }

            octet_sequnce input_coder::get_pop_octs(std::size_t sz, bool alighn) {
                octet_sequnce tmp;
                get_pop_octets(sz, tmp, alighn);
                return tmp;
            }




            ///////////////////////////////////////////////////////////////////////////////////
            // size_class from X.691                

            std::size_t size_x691_cast(size_class& val, const mutable_sequences& src, mutable_sequences::const_iterator bit, std::size_t beg) {
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
                                    if (!from_x691_cast<std::size_t > (bodysize, s2))
                                        return 0;
                                    val = size_class(bodysize);
                                    return s2.size();
                                } else {
                                    std::size_t bodysize = 0;
                                    if (!from_x691_cast<std::size_t > (bodysize, s2))
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
            // bool from X.691

            template<>
            bool from_x691_cast(bool& vl, const octet_sequnce& val) {
                if (val.empty())
                    vl = false;
                else
                    vl = val[0];
                return true;
            }

            ///////////////////////////////////////////////////////////////////////////////////
            // null from X.691               

            template<>
            bool from_x691_cast(null_type& val, const octet_sequnce& vl) {
                if (vl.empty()) {
                    val = null_type();
                    return true;
                }
                return false;
            }

            ///////////////////////////////////////////////////////////////////////////////////
            // enumerated_type from X.691

            template<>
            bool from_x691_cast(enumerated_type& val, const octet_sequnce& src) {
                enumerated_base_type tmp = 0;
                if (from_x691_cast(tmp, src)) {
                    val = tmp;
                    return true;
                }
                return false;
            }



            ///////////////////////////////////////////////////////////////////////////////////
            // any_type from to X.691

            template<>
            bool from_x691_cast(any_type& val, const octet_sequnce& src) {
                val.set(src);
                return true;
            }


            ////////////////////////////////////////////

            input_coder& operator>>(input_coder& stream, const int8_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const uint8_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const int16_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const uint16_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const int32_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const uint32_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const int64_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const uint64_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const enumerated_type& vl) {
                return stream; //primitive_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const float& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const double& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const long double& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const bool& vl) {
                bitstring_type rslt = stream.get_pop_bmp(1);
                const_cast<bool&> (vl) = rslt.bit(1);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const null_type& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const oid_type& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const reloid_type& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const any_type& vl) {
                /*std::size_t sz = stream.stack_size();
                octet_sequnce data;
                if (boost::itu::row_cast(stream.buffers(), stream.buffers().begin(), data, 0, sz)) {
                    if (from_x691_cast(*const_cast<any_type*> (&vl.value()), data)) {
                        // stream.pop_stack();
                    }
                }*/
                return stream;
                //return  primitive_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const bitstring_type& vl) {
                //octet_reader_undefsz(stream, const_cast<bitstring_type&> ((vl.value()))):
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<bitstring_type>& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const octetstring_type& vl) {
                octet_reader_undefsz(stream, const_cast<octetstring_type&> (vl));
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<octetstring_type>& vl) {
                octet_reader_defsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const utf8string_type& vl) {
                octet_reader_undefsz(stream, const_cast<utf8string_type&> (vl));
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<utf8string_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, const numericstring_type& vl) {
                octet_reader_undefsz(stream, const_cast<numericstring_type&> (vl));
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<numericstring_type>& vl) {
                octet_reader_defsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const printablestring_type& vl) {
                octet_reader_undefsz(stream, const_cast<printablestring_type&> (vl));
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<printablestring_type>& vl) {
                octet_reader_defsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const t61string_type& vl) {
                octet_reader_undefsz(stream, const_cast<t61string_type&> (vl));
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<t61string_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, const videotexstring_type& vl) {
                octet_reader_undefsz(stream, const_cast<videotexstring_type&> (vl));
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<videotexstring_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, const ia5string_type& vl) {
                octet_reader_undefsz(stream, const_cast<ia5string_type&> (vl));
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<ia5string_type>& vl) {
                octet_reader_defsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const graphicstring_type& vl) {
                octet_reader_undefsz(stream, const_cast<graphicstring_type&> (vl));
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<graphicstring_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, const objectdescriptor_type& vl) {
                octet_reader_undefsz(stream, const_cast<objectdescriptor_type&> (vl));
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<objectdescriptor_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, const visiblestring_type& vl) {
                octet_reader_undefsz(stream, const_cast<visiblestring_type&> (vl));
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<visiblestring_type>& vl) {
                octet_reader_defsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const generalstring_type& vl) {
                octet_reader_undefsz(stream, const_cast<generalstring_type&> (vl));
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<generalstring_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, const universalstring_type& vl) {
                /*const_cast<universalstring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<universalstring_type*> (&(vl.value())), vl.id(), vl.mask());*/
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<universalstring_type>& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const bmpstring_type& vl) {
                /*const_cast<bmpstring_type*> (&(vl.value()))->clear();
                stringtype_reader(stream, *const_cast<bmpstring_type*> (&(vl.value())), vl.id(), vl.mask());*/
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const size_constrainter<bmpstring_type>& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, const utctime_type& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, const gentime_type& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            ////////  Archiver


        }

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif       

        /////// external_type

        template<> void external_type::Encoding_type::serialize(boost::asn1::x691::output_coder& arch) {
            /*  switch (type()) {
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
              }*/
        }

        template<> void external_type::Encoding_type::serialize(boost::asn1::x691::input_coder& arch) {
            int __tag_id__ = arch.test_id();
            /*   switch (arch.test_class()) {
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
               }*/
        }

        template<> void external_type::serialize(boost::asn1::x691::output_coder& arch) {
            /* ITU_T_BIND_TAG(direct_reference_);
             ITU_T_BIND_TAG(indirect_reference_);
             ITU_T_BIND_TAG(data_value_descriptor_);
             ITU_T_BIND_CHOICE(*encoding_);*/
        }

        template<> void external_type::serialize(boost::asn1::x691::input_coder& arch) {
            /*     ITU_T_BIND_TAG(direct_reference_);
                 ITU_T_BIND_TAG(indirect_reference_);
                 ITU_T_BIND_TAG(data_value_descriptor_);
                 ITU_T_BIND_CHOICE(*encoding_);*/
        }




        //////////////////////////////////////////////////////////
        //embeded_type

        template<> void embeded_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::output_coder& arch) {
            //ITU_T_IMPLICIT_TAG(*abstract_, 0);
            // ITU_T_IMPLICIT_TAG(*transfer_, 1);
        }

        template<> void embeded_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::input_coder& arch) {
            // ITU_T_IMPLICIT_TAG(*abstract_, 0);
            // ITU_T_IMPLICIT_TAG(*transfer_, 1);
        }

        template<> void embeded_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::output_coder& arch) {
            //ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
            //ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);
        }

        template<> void embeded_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::input_coder& arch) {
            //ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
            //ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);
        }

        template<> void embeded_type::Identification_type::serialize(boost::asn1::x691::output_coder& arch) {
            switch (type()) {
                case Identification_type_syntaxes:
                {
                    //ITU_T_IMPLICIT_TAG(value<Syntaxes_type > (false, Identification_type_syntaxes), 0);
                    break;
                }
                case Identification_type_syntax:
                {
                    //ITU_T_IMPLICIT_TAG(value<oid_type > (false, Identification_type_syntax), 1);
                    break;
                }
                case Identification_type_presentation_context_id:
                {
                    //ITU_T_IMPLICIT_TAG(value<int > (false, Identification_type_presentation_context_id), 2);
                    break;
                }
                case Identification_type_context_negotiation:
                {
                    //ITU_T_IMPLICIT_TAG(value<Context_negotiation_type > (false, Identification_type_context_negotiation), 3);
                    break;
                }
                case Identification_type_transfer_syntax:
                {
                    //ITU_T_IMPLICIT_TAG(value<oid_type > (false, Identification_type_transfer_syntax), 4);
                    break;
                }
                case Identification_type_fixed:
                {
                    //ITU_T_IMPLICIT_TAG(value<null_type > (false, Identification_type_fixed), 5);
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void embeded_type::Identification_type::serialize(boost::asn1::x691::input_coder& arch) {
            int __tag_id__ = arch.test_id();
            /* switch (arch.test_class()) {
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
             }*/
        }

        template<> void embeded_type::serialize(boost::asn1::x691::output_coder& arch) {
            /* ITU_T_CHOICE_TAG(*identification_, 0);
             ITU_T_IMPLICIT_TAG(*data_value_, 1);*/
        }

        template<> void embeded_type::serialize(boost::asn1::x691::input_coder& arch) {
            /*   ITU_T_CHOICE_TAG(*identification_, 0);
               ITU_T_IMPLICIT_TAG(*data_value_, 1);*/
        }



        //////////////////////////////////////////////////////////////

        template<> void characterstring_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::output_coder& arch) {
            /*     ITU_T_IMPLICIT_TAG(*abstract_, 0);
                 ITU_T_IMPLICIT_TAG(*transfer_, 1);*/
        }

        template<> void characterstring_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::input_coder& arch) {
            /* ITU_T_IMPLICIT_TAG(*abstract_, 0);
             ITU_T_IMPLICIT_TAG(*transfer_, 1);*/
        }

        template<> void characterstring_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::output_coder& arch) {
            /*  ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
              ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);*/
        }

        template<> void characterstring_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::input_coder& arch) {
            /*   ITU_T_IMPLICIT_TAG(*presentation_context_id_, 0);
               ITU_T_IMPLICIT_TAG(*transfer_syntax_, 1);*/
        }

        template<> void characterstring_type::Identification_type::serialize(boost::asn1::x691::output_coder& arch) {
            /*   switch (type()) {
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
               }*/
        }

        template<> void characterstring_type::Identification_type::serialize(boost::asn1::x691::input_coder& arch) {
            int __tag_id__ = arch.test_id();
            /*    switch (arch.test_class()) {
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
                }*/
        }

        template<> void characterstring_type::serialize(boost::asn1::x691::output_coder& arch) {
            //ITU_T_CHOICE_TAG(*identification_, 0);
            // ITU_T_IMPLICIT_TAG(*string_value_, 1);
        }

        template<> void characterstring_type::serialize(boost::asn1::x691::input_coder& arch) {
            // ITU_T_CHOICE_TAG(*identification_, 0);
            // ITU_T_IMPLICIT_TAG(*string_value_, 1);
        }

#ifdef _MSC_VER
#pragma warning(pop)
#endif

    }
}

