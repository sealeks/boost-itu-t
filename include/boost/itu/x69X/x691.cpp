//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#include <boost/lexical_cast.hpp>
#include <boost/itu/x69X/x691.hpp>

namespace boost {
    namespace asn1 {
        namespace x691 {

            std::ostream& operator<<(std::ostream& stream, const size_class& vl) {
                return stream << "SIZE:  " << vl.size() << '\n';
            }


            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                      */
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



            // element constrainter

            void numericstring_ec::out(boost::asn1::x691::output_coder& stream, numeric_string::value_type vl) {
                stream.add_bitmap(bit_string(octet_sequnce(1,
                        octet_sequnce::value_type((vl != '\x20') ? ((vl - '\x2F') << 4) : 0)), 4));
            }

            numeric_string::value_type numericstring_ec::in(boost::asn1::x691::input_coder& stream) {
                bit_string vl = stream.get_pop_bmp(4);
                octet_sequnce tmp = vl.as_octet_sequnce();
                if (!tmp.empty()) {
                    tmp[0] >>= 4;
                    tmp[0] &= '\xF';
                    return tmp[0] ? (tmp[0] + '\x2F') : ('\x20');
                }
                return 0;
            }

            void printablestring_ec::out(boost::asn1::x691::output_coder& stream, printable_string::value_type vl) {
                stream.add_bitmap(bit_string(octet_sequnce(1, stream.aligned() ?
                        octet_sequnce::value_type(vl) : octet_sequnce::value_type(vl << 1)), stream.aligned() ? 0 : 1));
            }

            printable_string::value_type printablestring_ec::in(boost::asn1::x691::input_coder& stream) {
                bit_string vl = stream.get_pop_bmp(stream.aligned() ? 8 : 7);
                octet_sequnce tmp = vl.as_octet_sequnce();
                if (!tmp.empty())
                    return stream.aligned() ? (tmp[0] & '\x7F') : ((tmp[0] >> 1) & '\x7F');
                return 0;
            }

            void ia5string_ec::out(boost::asn1::x691::output_coder& stream, ia5_string::value_type vl) {
                stream.add_bitmap(bit_string(octet_sequnce(1, stream.aligned() ?
                        octet_sequnce::value_type(vl) : octet_sequnce::value_type(vl << 1)), stream.aligned() ? 0 : 1));
            }

            ia5_string::value_type ia5string_ec::in(boost::asn1::x691::input_coder& stream) {
                bit_string vl = stream.get_pop_bmp(stream.aligned() ? 8 : 7);
                octet_sequnce tmp = vl.as_octet_sequnce();
                if (!tmp.empty())
                    return stream.aligned() ? (tmp[0] & '\x7F') : ((tmp[0] >> 1) & '\x7F');
                return 0;
            }

            void visiblestring_ec::out(boost::asn1::x691::output_coder& stream, visible_string::value_type vl) {
                stream.add_bitmap(bit_string(octet_sequnce(1, stream.aligned() ?
                        octet_sequnce::value_type(vl) : octet_sequnce::value_type(vl << 1)), stream.aligned() ? 0 : 1));
            }

            visible_string::value_type visiblestring_ec::in(boost::asn1::x691::input_coder& stream) {
                bit_string vl = stream.get_pop_bmp(stream.aligned() ? 8 : 7);
                octet_sequnce tmp = vl.as_octet_sequnce();
                if (!tmp.empty())
                    return stream.aligned() ? (tmp[0] & '\x7F') : ((tmp[0] >> 1) & '\x7F');
                return 0;
            }

            void bmpstring_ec::out(boost::asn1::x691::output_coder& stream, bmp_string::value_type vl) {
                stream.add_octets(octet_sequnce(reinterpret_cast<const octet_sequnce::value_type*> (&vl),
                        reinterpret_cast<const octet_sequnce::value_type*> (&vl) + 2), stream.aligned());
            }

            bmp_string::value_type bmpstring_ec::in(boost::asn1::x691::input_coder& stream) {
                octet_sequnce tmp = stream.get_pop_octs(2, stream.aligned());
                return *reinterpret_cast<const bmp_string::value_type*> (tmp.data());
            }

            void universalstring_ec::out(boost::asn1::x691::output_coder& stream, universal_string::value_type vl) {
                stream.add_octets(octet_sequnce(reinterpret_cast<const octet_sequnce::value_type*> (&vl),
                        reinterpret_cast<const octet_sequnce::value_type*> (&vl) + 4), stream.aligned());
            }

            universal_string::value_type universalstring_ec::in(boost::asn1::x691::input_coder& stream) {
                octet_sequnce tmp = stream.get_pop_octs(4, stream.aligned());
                return *reinterpret_cast<const universal_string::value_type*> (tmp.data());
            }



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////            

            void output_coder::add_bitmap(const bit_string & vl, bool alighn) {
                if (unusebits()) {
                    //const_sequences::reverse_iterator it = listbuffers_->rbegin();
                    boost::itu::octet_sequnce_ptr_vect::reverse_iterator dit = rows_vect().rbegin();
                    boost::itu::octet_sequnce_ptr lstdata_ptr = *dit;
                    octet_sequnce& lstdata = *lstdata_ptr;
                    unusebits(boost::itu::split_bits_in_octets(lstdata, alighn ? 0 : unusebits(), vl.as_octet_sequnce(), vl.unusebits()));
                    listbuffers_->back() = const_buffer(&(rows_vect().back()->operator[](0)), rows_vect().back()->size());
                } else {
                    add(vl.as_octet_sequnce());
                    unusebits(vl.unusebits());
                }
            }

            void output_coder::add_octets(const octet_sequnce& vl, bool alighn) {
                if ((!alighn) && (unusebits())) {
                    //const_sequences::reverse_iterator it = listbuffers_->rbegin();
                    boost::itu::octet_sequnce_ptr_vect::reverse_iterator dit = rows_vect().rbegin();
                    boost::itu::octet_sequnce_ptr lstdata_ptr = *dit;
                    octet_sequnce& lstdata = *lstdata_ptr;
                    boost::itu::split_bits_in_octets(lstdata, alighn ? 0 : unusebits(), vl);
                    listbuffers_->back() = const_buffer(&(rows_vect().back()->operator[](0)), rows_vect().back()->size());
                } else {
                    add(vl);
                }
            }

            void output_coder::add_octets(const octet_string & vl, bool alighn) {
                add_octets(vl.as_base(), alighn);
            }

            void output_coder::add_nsn_small(std::size_t indx) {
                *this << small_nn_wnumber <std::size_t>(indx);
            }

            void output_coder::start_open() {
                datastate_push();
            }

            void output_coder::end_open() {
                if (has_datastate()) {
                    data_state ds = datastate_pop();
                    octet_sequnce data;
                    for (boost::itu::const_sequences::const_iterator it = ds.listbuffers_->begin(); it != ds.listbuffers_->end(); ++it) {
                        data.insert(data.end(), boost::asio::buffer_cast<const octet_type*>(*it),
                                boost::asio::buffer_cast<const octet_type*>(*it) + boost::asio::buffer_size(*it));
                    }
                    if (data.empty())
                        data.push_back(0);
                    octet_writer_undefsz(*this, data);
                }
            }

            void output_coder::set_extentions_marker(const bit_string & vl) {
                if (vl.sizebits()) {
                    add_nsn_small(vl.sizebits() - 1);
                    add_bitmap(vl);
                }
            }



            // STRING REALISZATION

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& elms, bool align) {
                stream.add_octets(elms, stream.aligned());
                return stream;
            }

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& sz, const octet_sequnce& elms, bool align) {
                stream.add_octets(sz, align);
                return octets_writer(stream, elms, align);
            }

            output_coder& octets_writer(output_coder& stream, const bit_string& elms, bool align) {
                stream.add_bitmap(elms, stream.aligned());
                return stream;
            }

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& sz, const bit_string& elms, bool align) {
                stream.add_octets(sz, align);
                return octets_writer(stream, elms, align);
            }

            template<>
            bool check_alighn(const size_constrainter<bit_string >& vl) {
                return (!(vl.is_single()) || ((vl.is_single()) && (vl.value().sizebits() > MIN_NOT_ALIGN_BITSIZE)));
            }

            template<>
            output_coder& octet_writer_undefsz(output_coder& stream, const bit_string& vl) {
                std::size_t sz = vl.sizebits();
                std::size_t beg = 0;
                while (beg < sz) {
                    if ((sz - beg) < LENGH_16K) {
                        octets_writer(stream, to_x691_cast(size_class(sz - beg)),
                                bit_string(octet_sequnce(vl.begin() + beg / 8, vl.end()), vl.unusebits()), stream.aligned());
                        beg = sz;
                    } else {
                        if ((sz - beg) < LENGH_64K) {
                            std::size_t m = (sz - beg) / LENGH_16K;
                            std::size_t nbeg = beg + LENGH_16K*m;
                            octets_writer(stream, to_x691_cast(size_class(LENGH_16K * m)),
                                    octet_sequnce(vl.begin() + beg / 8, vl.begin() + nbeg / 8), stream.aligned());
                            beg = nbeg;
                        } else {
                            octets_writer(stream, to_x691_cast(size_class(LENGH_64K)),
                                    octet_sequnce(vl.begin() + beg / 8, vl.begin() + (beg + LENGH_64K) / 8), stream.aligned());
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
            output_coder& octet_writer_defsz(output_coder& stream, const size_constrainter<bit_string>& vl) {

                if (vl.available()) {
                    if (vl.can_extended())
                        stream.add_bitmap(bit_string(vl.extended(vl.value().size())));

                    if ((!vl.extended(vl.value().size())) && (vl.constrained())) {

                        std::size_t tmpsz = vl.value().sizebits();
                        if (!vl.check(tmpsz))
                            throw boost::system::system_error(boost::itu::ER_PROTOCOL);

                        if (vl.max() < LENGH_64K) {
                            writer_defsz(stream, vl);
                            return octets_writer(stream, vl.value(), stream.aligned() ? check_alighn(vl) : false);
                        }
                    }
                }
                return octet_writer_undefsz(stream, vl.value());
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
                stream.add_bitmap(bit_string(vl));
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

            output_coder& operator<<(output_coder& stream, const bit_string& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<bit_string>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const octet_string& vl) {
                return octet_writer_undefsz(stream, vl.as_base());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<octet_string>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const utf8_string& vl) {
                return octet_writer_undefsz(stream, octet_sequnce(vl.begin(), vl.end()));
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<utf8_string>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const oid_iri_type& vl) {
                return octet_writer_undefsz(stream, octet_sequnce(vl.begin(), vl.end()));
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<oid_iri_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const reloid_iri_type& vl) {
                return octet_writer_undefsz(stream, octet_sequnce(vl.begin(), vl.end()));
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<reloid_iri_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const numeric_string& vl) {
                return stream << size_constrainter<numeric_string, numericstring_ec>(const_cast<numeric_string&> (vl)); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<numeric_string>& vl) {
                return stream << size_constrainter<numeric_string, numericstring_ec>(const_cast<numeric_string&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const printable_string& vl) {
                return stream << size_constrainter<printable_string, printablestring_ec>(const_cast<printable_string&> (vl)); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<printable_string>& vl) {
                return stream << size_constrainter<printable_string, printablestring_ec>(const_cast<printable_string&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const t61_string& vl) {
                return octet_writer_undefsz(stream, as_octet_sequnce(vl));
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<t61_string>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const videotex_string& vl) {
                return octet_writer_undefsz(stream, as_octet_sequnce(vl));
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<videotex_string>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const ia5_string& vl) {
                return stream << size_constrainter< ia5_string, ia5string_ec>(const_cast<ia5_string&> (vl)); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter< ia5_string>& vl) {
                return stream << size_constrainter< ia5_string, ia5string_ec>(const_cast<ia5_string&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const graphic_string& vl) {
                return octet_writer_undefsz(stream, as_octet_sequnce(vl));
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<graphic_string>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const object_descriptor& vl) {
                return octet_writer_undefsz(stream, as_octet_sequnce(vl));
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<object_descriptor>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const visible_string& vl) {
                return stream << size_constrainter<visible_string, visiblestring_ec>(const_cast<visible_string&> (vl)); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<visible_string>& vl) {
                return stream << size_constrainter<visible_string, visiblestring_ec>(const_cast<visible_string&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const general_string& vl) {
                return octet_writer_undefsz(stream, as_octet_sequnce(vl));
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<general_string>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const universal_string& vl) {
                return stream << size_constrainter<universal_string, universalstring_ec>(const_cast<universal_string&> (vl)); // known-multi 4 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<universal_string>& vl) {
                return stream << size_constrainter<universal_string, universalstring_ec>(const_cast<universal_string&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 4 oct
            }

            output_coder& operator<<(output_coder& stream, const bmp_string& vl) {
                return stream << size_constrainter< bmp_string, bmpstring_ec>(const_cast<bmp_string&> (vl)); // known-multi 2 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter< bmp_string>& vl) {
                return stream << size_constrainter< bmp_string, bmpstring_ec>(const_cast<bmp_string&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 2 oct
            }

            output_coder& operator<<(output_coder& stream, const utctime& vl) {
                visible_string tmp = as_visiblestring(vl);
                return stream << tmp;
            }

            output_coder& operator<<(output_coder& stream, const gentime& vl) {
                visible_string tmp = as_visiblestring(vl);
                return stream << tmp;
            }







            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*INPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            std::size_t input_coder::get_bitmap(std::size_t sz, bit_string& vl, bool alighn) {
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
                    vl = bit_string(raw, sz ? (8 - sz % 8) : 0);
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
                        if (alighn) {
                            vl.erase(vl.begin());
                        } else {
                            boost::itu::left_shift_bits_in_octets(vl, unusebits());
                            vl.erase(vl.begin()+(sz - 1), vl.end());
                        }
                    }
                }
                return sz;
            }

            std::size_t input_coder::pop_bitmap(std::size_t sz, bool alighn) {
                if (sz) {
                    std::size_t usbit = usebits();
                    std::size_t octsize = 0;
                    if (usbit <= sz)
                        octsize += ((sz - usbit) / 8 + 1);
                    if (octsize)
                        pop_front(octsize);
                    unusebits(unusebits() + sz);
                }
                return sz;
            }

            std::size_t input_coder::pop_octets(std::size_t sz, bool alighn) {
                if (alighn && (unusebits())) {
                    pop_front(sz + 1);
                    unusebits(0);
                    return (sz + 1);
                }
                pop_front(sz);
                return sz;
            }

            std::size_t input_coder::get_pop_bitmap(std::size_t sz, bit_string& vl, bool alighn) {
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

            bit_string input_coder::get_pop_bmp(std::size_t sz, bool alighn) {
                bit_string tmp;
                get_pop_bitmap(sz, tmp, alighn);
                return tmp;
            }

            octet_sequnce input_coder::get_pop_octs(std::size_t sz, bool alighn) {
                octet_sequnce data;
                get_pop_octets(sz, data, alighn);
                return data;
            }

            std::size_t input_coder::get_nsn_small() {
                std::size_t rslt = 0;
                small_nn_wnumber <std::size_t> vl(rslt);
                *this >> vl;
                return rslt;
            }

            void input_coder::start_open() {
                octet_sequnce data;
                octet_reader_undefsz(*this, data);
                datastate_push();
                add(data);
            }

            void input_coder::end_open() {
                datastate_pop();
            }

            void input_coder::get_extentions_marker(bit_string& vl) {
                std::size_t rslt = get_nsn_small() + 1;
                vl = get_pop_bmp(rslt);
            }

            void input_coder::clear_extentions(const bit_string& exbmp, std::size_t cnt) {
                if (exbmp.sizebits() > cnt) {
                    std::size_t clear_cnt = exbmp.sizebits() - cnt;
                    while (clear_cnt--) {
                        octet_sequnce data;
                        octet_reader_undefsz(*this, data);
                    }
                }
            }

            void input_coder::clear_extention() {
                octet_sequnce data;
                octet_reader_undefsz(*this, data);
            }



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*INPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////                     

            template<>
            input_coder& octet_reader(input_coder& stream, bit_string& vl, std::size_t sz, bool alighn) {
                if (sz) {
                    bit_string readvl = stream.get_pop_bmp(sz, alighn);
                    vl.append(readvl);
                }
                return stream;
            }


            ////////////////////////////////////////////

            input_coder& operator>>(input_coder& stream, int8_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, uint8_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, int16_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, uint16_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, int32_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, uint32_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, int64_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, uint64_t & vl) {
                return primitive_int_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, enumerated& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, float& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, double& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, long double& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, bool& vl) {
                bit_string rslt = stream.get_pop_bmp(1);
                vl = rslt.bit(0);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, null_type& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, oid_type& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, reloid_type& vl) {
                return primitive_690_deserialize(stream, vl);
            }

            input_coder& operator>>(input_coder& stream, any_type& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, bit_string& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<bit_string>& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, octet_string& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<octet_string>& vl) {
                octet_reader_defsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, utf8_string& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<utf8_string>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, oid_iri_type& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<oid_iri_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, reloid_iri_type& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<reloid_iri_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, numeric_string& vl) {
                size_constrainter<numeric_string, numericstring_ec> tmp(vl);
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<numeric_string>& vl) {
                size_constrainter<numeric_string, numericstring_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, printable_string& vl) {
                size_constrainter<printable_string, printablestring_ec> tmp(vl);
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<printable_string>& vl) {
                size_constrainter<printable_string, printablestring_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, t61_string& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<t61_string>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, videotex_string& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<videotex_string>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, ia5_string& vl) {
                size_constrainter< ia5_string, ia5string_ec> tmp(vl);
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter< ia5_string>& vl) {
                size_constrainter< ia5_string, ia5string_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, graphic_string& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<graphic_string>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, object_descriptor& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<object_descriptor>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, visible_string& vl) {
                size_constrainter<visible_string, visiblestring_ec> tmp(vl);
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<visible_string>& vl) {
                size_constrainter<visible_string, visiblestring_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, general_string& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<general_string>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, universal_string& vl) {
                size_constrainter<universal_string, universalstring_ec> tmp(vl);
                return stream >> tmp; // known-multi 4 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<universal_string>& vl) {
                size_constrainter<universal_string, universalstring_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 4 oct
            }

            input_coder& operator>>(input_coder& stream, bmp_string& vl) {
                size_constrainter< bmp_string, bmpstring_ec> tmp(vl);
                return stream >> tmp; // known-multi 2 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter< bmp_string>& vl) {
                size_constrainter< bmp_string, bmpstring_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 2 oct
            }

            input_coder& operator>>(input_coder& stream, utctime& vl) {
                visible_string tmp;
                stream >> tmp;
                vl = to_utctime(tmp);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, gentime& vl) {
                visible_string tmp;
                stream >> tmp;
                vl = to_gentime(tmp);
                return stream;
            }

            ////////  Archiver


        }

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif       

        /////// external_type

        template<> void external_type::serialize(boost::asn1::x691::output_coder& arch) {

            ITU_T_OPTIONAL_BMP = ITU_T_EXISTS_BMP(direct_reference_) +
                    ITU_T_EXISTS_BMP(indirect_reference_) +
                    ITU_T_EXISTS_BMP(data_value_descriptor_);

            ITU_T_OPTIONAL_WRITE;

            ITU_T_BIND_PER(direct_reference_);
            ITU_T_BIND_PER(indirect_reference_);
            ITU_T_BIND_PER(data_value_descriptor_);
            ITU_T_BIND_PER(encoding_);
        }

        template<> void external_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_OPTIONAL_READ(3);

            ITU_T_OPTIONAL_CHECK(0) ITU_T_BIND_PER(direct_reference_);
            ITU_T_OPTIONAL_CHECK(1) ITU_T_BIND_PER(indirect_reference_);
            ITU_T_OPTIONAL_CHECK(2) ITU_T_BIND_PER(data_value_descriptor_);
            ITU_T_BIND_PER(encoding_);
        }

        // choice encoding

        template<> void external_type::Encoding_type::serialize(boost::asn1::x691::output_coder& arch) {
            switch (type()) {
                case Encoding_type_single_ASN1_type:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 2);
                    ITU_T_BIND_PER(value<any_type > (false, Encoding_type_single_ASN1_type));
                    break;
                }
                case Encoding_type_octet_aligned:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 2);
                    ITU_T_BIND_PER(value<octet_string > (false, Encoding_type_octet_aligned));
                    break;
                }
                case Encoding_type_arbitrary:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 2);
                    ITU_T_BIND_PER(value<bit_string > (false, Encoding_type_arbitrary));
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void external_type::Encoding_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_GET_CONSTAINED_INDX(2);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_PER(value<any_type > (true, Encoding_type_single_ASN1_type));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(value<octet_string > (true, Encoding_type_octet_aligned));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(value<bit_string > (true, Encoding_type_arbitrary));
                    break;
                }
                default:
                {
                }
            }
        }




        //////////////////////////////////////////////////////////
        //embeded_pdv

        template<> void embeded_pdv::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(identification_);
            ITU_T_BIND_PER(data_value_);
        }

        template<> void embeded_pdv::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(identification_);
            ITU_T_BIND_PER(data_value_);
        }

        // choice identification

        template<> void embeded_pdv::Identification_type::serialize(boost::asn1::x691::output_coder& arch) {
            switch (type()) {
                case Identification_type_syntaxes:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 5);
                    ITU_T_BIND_PER(value<Syntaxes_type > (false, Identification_type_syntaxes));
                    break;
                }
                case Identification_type_syntax:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 5);
                    ITU_T_BIND_PER(value<oid_type > (false, Identification_type_syntax));
                    break;
                }
                case Identification_type_presentation_context_id:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 5);
                    ITU_T_BIND_PER(value<integer_type > (false, Identification_type_presentation_context_id));
                    break;
                }
                case Identification_type_context_negotiation:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 5);
                    ITU_T_BIND_PER(value<Context_negotiation_type > (false, Identification_type_context_negotiation));
                    break;
                }
                case Identification_type_transfer_syntax:
                {
                    ITU_T_SET_CONSTAINED_INDX(4, 5);
                    ITU_T_BIND_PER(value<oid_type > (false, Identification_type_transfer_syntax));
                    break;
                }
                case Identification_type_fixed:
                {
                    ITU_T_SET_CONSTAINED_INDX(5, 5);
                    ITU_T_BIND_PER(value<null_type > (false, Identification_type_fixed));
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void embeded_pdv::Identification_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_GET_CONSTAINED_INDX(5);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_PER(value<Syntaxes_type > (true, Identification_type_syntaxes));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(value<oid_type > (true, Identification_type_syntax));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(value<integer_type > (true, Identification_type_presentation_context_id));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_PER(value<Context_negotiation_type > (true, Identification_type_context_negotiation));
                    break;
                }
                case 4:
                {
                    ITU_T_BIND_PER(value<oid_type > (true, Identification_type_transfer_syntax));
                    break;
                }
                case 5:
                {
                    ITU_T_BIND_PER(value<null_type > (true, Identification_type_fixed));
                    break;
                }
                default:
                {
                }
            }
        }

        // sequence syntaxes

        template<> void embeded_pdv::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(abstract_);
            ITU_T_BIND_PER(transfer_);
        }

        template<> void embeded_pdv::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(abstract_);
            ITU_T_BIND_PER(transfer_);
        }

        // sequence context-negotiation

        template<> void embeded_pdv::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(presentation_context_id_);
            ITU_T_BIND_PER(transfer_syntax_);
        }

        template<> void embeded_pdv::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(presentation_context_id_);
            ITU_T_BIND_PER(transfer_syntax_);
        }





        //////////////////////////////////////////////////////////////

        template<> void character_string::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(identification_);
            ITU_T_BIND_PER(data_value_);
        }

        template<> void character_string::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(identification_);
            ITU_T_BIND_PER(data_value_);
        }

        // choice identification

        template<> void character_string::Identification_type::serialize(boost::asn1::x691::output_coder& arch) {
            switch (type()) {
                case Identification_type_syntaxes:
                {
                    ITU_T_SET_CONSTAINED_INDX(0, 5);
                    ITU_T_BIND_PER(value<Syntaxes_type > (false, Identification_type_syntaxes));
                    break;
                }
                case Identification_type_syntax:
                {
                    ITU_T_SET_CONSTAINED_INDX(1, 5);
                    ITU_T_BIND_PER(value<oid_type > (false, Identification_type_syntax));
                    break;
                }
                case Identification_type_presentation_context_id:
                {
                    ITU_T_SET_CONSTAINED_INDX(2, 5);
                    ITU_T_BIND_PER(value<integer_type > (false, Identification_type_presentation_context_id));
                    break;
                }
                case Identification_type_context_negotiation:
                {
                    ITU_T_SET_CONSTAINED_INDX(3, 5);
                    ITU_T_BIND_PER(value<Context_negotiation_type > (false, Identification_type_context_negotiation));
                    break;
                }
                case Identification_type_transfer_syntax:
                {
                    ITU_T_SET_CONSTAINED_INDX(4, 5);
                    ITU_T_BIND_PER(value<oid_type > (false, Identification_type_transfer_syntax));
                    break;
                }
                case Identification_type_fixed:
                {
                    ITU_T_SET_CONSTAINED_INDX(5, 5);
                    ITU_T_BIND_PER(value<null_type > (false, Identification_type_fixed));
                    break;
                }
                default:
                {
                }
            }
        }

        template<> void character_string::Identification_type::serialize(boost::asn1::x691::input_coder& arch) {

            ITU_T_GET_CONSTAINED_INDX(5);

            switch (__indx__) {
                case 0:
                {
                    ITU_T_BIND_PER(value<Syntaxes_type > (true, Identification_type_syntaxes));
                    break;
                }
                case 1:
                {
                    ITU_T_BIND_PER(value<oid_type > (true, Identification_type_syntax));
                    break;
                }
                case 2:
                {
                    ITU_T_BIND_PER(value<integer_type > (true, Identification_type_presentation_context_id));
                    break;
                }
                case 3:
                {
                    ITU_T_BIND_PER(value<Context_negotiation_type > (true, Identification_type_context_negotiation));
                    break;
                }
                case 4:
                {
                    ITU_T_BIND_PER(value<oid_type > (true, Identification_type_transfer_syntax));
                    break;
                }
                case 5:
                {
                    ITU_T_BIND_PER(value<null_type > (true, Identification_type_fixed));
                    break;
                }
                default:
                {
                }
            }
        }

        // sequence syntaxes

        template<> void character_string::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(abstract_);
            ITU_T_BIND_PER(transfer_);
        }

        template<> void character_string::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(abstract_);
            ITU_T_BIND_PER(transfer_);
        }

        // sequence context-negotiation

        template<> void character_string::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::output_coder& arch) {
            ITU_T_BIND_PER(presentation_context_id_);
            ITU_T_BIND_PER(transfer_syntax_);
        }

        template<> void character_string::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::input_coder& arch) {
            ITU_T_BIND_PER(presentation_context_id_);
            ITU_T_BIND_PER(transfer_syntax_);
        }



#ifdef _MSC_VER
#pragma warning(pop)
#endif

    }
}

