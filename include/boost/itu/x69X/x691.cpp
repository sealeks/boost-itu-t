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

            void numericstring_ec::out(boost::asn1::x691::output_coder& stream, numericstring_type::value_type vl) {
                stream.add_bitmap(bitstring_type(octet_sequnce(1, 
                        octet_sequnce::value_type((vl != '\x20') ? ((vl - '\x2F') << 4) : 0)), 4));
            }

            numericstring_type::value_type numericstring_ec::in(boost::asn1::x691::input_coder& stream) {
                bitstring_type vl = stream.get_pop_bmp(4);
                octet_sequnce tmp = vl.as_octet_sequnce();
                if (!tmp.empty()) {
                    tmp[0] >>= 4;
                    tmp[0] &= '\xF';
                    return tmp[0] ? (tmp[0] + '\x2F') : ('\x20');
                }
                return 0;
            }

            void printablestring_ec::out(boost::asn1::x691::output_coder& stream, printablestring_type::value_type vl) {
                stream.add_bitmap(bitstring_type(octet_sequnce(1, stream.aligned() ?
                        octet_sequnce::value_type(vl) : octet_sequnce::value_type(vl << 1)), stream.aligned() ? 0 : 1));
            }

            printablestring_type::value_type printablestring_ec::in(boost::asn1::x691::input_coder& stream) {
                bitstring_type vl = stream.get_pop_bmp(stream.aligned() ? 8 : 7);
                octet_sequnce tmp = vl.as_octet_sequnce();
                if (!tmp.empty())
                    return stream.aligned() ? (tmp[0] & '\x7F') : ((tmp[0] >> 1) & '\x7F');
                return 0;
            }

            void ia5string_ec::out(boost::asn1::x691::output_coder& stream, ia5string_type::value_type vl) {
                stream.add_bitmap(bitstring_type(octet_sequnce(1, stream.aligned() ?
                        octet_sequnce::value_type(vl) : octet_sequnce::value_type(vl << 1)), stream.aligned() ? 0 : 1));
            }

            ia5string_type::value_type ia5string_ec::in(boost::asn1::x691::input_coder& stream) {
                bitstring_type vl = stream.get_pop_bmp(stream.aligned() ? 8 : 7);
                octet_sequnce tmp = vl.as_octet_sequnce();
                if (!tmp.empty())
                    return stream.aligned() ? (tmp[0] & '\x7F') : ((tmp[0] >> 1) & '\x7F');
                return 0;
            }

            void visiblestring_ec::out(boost::asn1::x691::output_coder& stream, visiblestring_type::value_type vl) {
                stream.add_bitmap(bitstring_type(octet_sequnce(1, stream.aligned() ?
                        octet_sequnce::value_type(vl) : octet_sequnce::value_type(vl << 1)), stream.aligned() ? 0 : 1));
            }

            visiblestring_type::value_type visiblestring_ec::in(boost::asn1::x691::input_coder& stream) {
                bitstring_type vl = stream.get_pop_bmp(stream.aligned() ? 8 : 7);
                octet_sequnce tmp = vl.as_octet_sequnce();
                if (!tmp.empty())
                    return stream.aligned() ? (tmp[0] & '\x7F') : ((tmp[0] >> 1) & '\x7F');
                return 0;
            }

            void bmpstring_ec::out(boost::asn1::x691::output_coder& stream, bmpstring_type::value_type vl) {
                stream.add_octets(octet_sequnce(reinterpret_cast<const octet_sequnce::value_type*> (&vl),
                        reinterpret_cast<const octet_sequnce::value_type*> (&vl) + 2), stream.aligned());
            }

            bmpstring_type::value_type bmpstring_ec::in(boost::asn1::x691::input_coder& stream) {
                octet_sequnce tmp = stream.get_pop_octs(2, stream.aligned());
                return *reinterpret_cast<const bmpstring_type::value_type*> (tmp.data());
            }

            void universalstring_ec::out(boost::asn1::x691::output_coder& stream, universalstring_type::value_type vl) {
                stream.add_octets(octet_sequnce(reinterpret_cast<const octet_sequnce::value_type*> (&vl),
                        reinterpret_cast<const octet_sequnce::value_type*> (&vl) + 4), stream.aligned());
            }

            universalstring_type::value_type universalstring_ec::in(boost::asn1::x691::input_coder& stream) {
                octet_sequnce tmp = stream.get_pop_octs(4, stream.aligned());
                return *reinterpret_cast<const universalstring_type::value_type*> (tmp.data());
            }



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////            

            void output_coder::add_bitmap(const bitstring_type & vl, bool alighn) {
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

            void output_coder::add_octets(const octetstring_type & vl, bool alighn) {
                add_octets(vl.as_octet_sequnce(), alighn);
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

            void output_coder::set_extentions_marker(const bitstring_type & vl) {
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

            output_coder& octets_writer(output_coder& stream, const bitstring_type& elms, bool align) {
                stream.add_bitmap(elms, stream.aligned());
                return stream;
            }

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& sz, const bitstring_type& elms, bool align) {
                stream.add_octets(sz, align);
                return octets_writer(stream, elms, align);
            }

            template<>
            bool check_alighn(const size_constrainter<bitstring_type >& vl) {
                return (!(vl.is_single()) || ((vl.is_single()) && (vl.value().sizebits() > MIN_NOT_ALIGN_BITSIZE)));
            }

            template<>
            output_coder& octet_writer_undefsz(output_coder& stream, const bitstring_type& vl) {
                std::size_t sz = vl.sizebits();
                std::size_t beg = 0;
                while (beg < sz) {
                    if ((sz - beg) < LENGH_16K) {
                        octets_writer(stream, to_x691_cast(size_class(sz - beg)),
                                bitstring_type(octet_sequnce(vl.begin() + beg / 8, vl.end()), vl.unusebits()), stream.aligned());
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
            output_coder& octet_writer_defsz(output_coder& stream, const size_constrainter<bitstring_type>& vl) {

                if (vl.available()) {
                    if (vl.can_extended())
                        stream.add_bitmap(bitstring_type(vl.extended(vl.value().size())));

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
                return octet_writer_undefsz(stream, vl.as_octet_sequnce());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<bitstring_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const octetstring_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<octetstring_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const utf8string_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<utf8string_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const numericstring_type& vl) {
                return stream << size_constrainter<numericstring_type, numericstring_ec>(const_cast<numericstring_type&> (vl)); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<numericstring_type>& vl) {
                return stream << size_constrainter<numericstring_type, numericstring_ec>(const_cast<numericstring_type&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const printablestring_type& vl) {
                return stream << size_constrainter<printablestring_type, printablestring_ec>(const_cast<printablestring_type&> (vl)); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<printablestring_type>& vl) {
                return stream << size_constrainter<printablestring_type, printablestring_ec>(const_cast<printablestring_type&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 1 oct
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
                return stream << size_constrainter< ia5string_type, ia5string_ec>(const_cast<ia5string_type&> (vl)); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter< ia5string_type>& vl) {
                return stream << size_constrainter< ia5string_type, ia5string_ec>(const_cast<ia5string_type&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 1 oct
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
                return stream << size_constrainter<visiblestring_type, visiblestring_ec>(const_cast<visiblestring_type&> (vl)); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<visiblestring_type>& vl) {
                return stream << size_constrainter<visiblestring_type, visiblestring_ec>(const_cast<visiblestring_type&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 1 oct
            }

            output_coder& operator<<(output_coder& stream, const generalstring_type& vl) {
                return octet_writer_undefsz(stream, vl.as_octet_sequnce());
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<generalstring_type>& vl) {
                return stream << vl.value();
            }

            output_coder& operator<<(output_coder& stream, const universalstring_type& vl) {
                return stream << size_constrainter<universalstring_type, universalstring_ec>(const_cast<universalstring_type&> (vl)); // known-multi 4 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter<universalstring_type>& vl) {
                return stream << size_constrainter<universalstring_type, universalstring_ec>(const_cast<universalstring_type&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 4 oct
            }

            output_coder& operator<<(output_coder& stream, const bmpstring_type& vl) {
                return stream << size_constrainter< bmpstring_type, bmpstring_ec>(const_cast<bmpstring_type&> (vl)); // known-multi 2 oct
            }

            output_coder& operator<<(output_coder& stream, const size_constrainter< bmpstring_type>& vl) {
                return stream << size_constrainter< bmpstring_type, bmpstring_ec>(const_cast<bmpstring_type&> (vl.value()), vl.min(), vl.max(), vl.can_extended()); // known-multi 2 oct
            }

            output_coder& operator<<(output_coder& stream, const utctime_type& vl) {
                visiblestring_type tmp = as_visiblestring(vl);
                return stream << tmp;
            }

            output_coder& operator<<(output_coder& stream, const gentime_type& vl) {
                visiblestring_type tmp = as_visiblestring(vl);
                return stream << tmp;
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

            void input_coder::get_extentions_marker(bitstring_type& vl) {
                std::size_t rslt = get_nsn_small() + 1;
                vl = get_pop_bmp(rslt);
            }

            void input_coder::clear_extentions(const bitstring_type& exbmp, std::size_t cnt) {
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
            input_coder& octet_reader(input_coder& stream, bitstring_type& vl, std::size_t sz, bool alighn) {
                if (sz) {
                    bitstring_type readvl = stream.get_pop_bmp(sz, alighn);
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

            input_coder& operator>>(input_coder& stream, enumerated_type& vl) {
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
                bitstring_type rslt = stream.get_pop_bmp(1);
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

            input_coder& operator>>(input_coder& stream, bitstring_type& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<bitstring_type>& vl) {
                return stream;
            }

            input_coder& operator>>(input_coder& stream, octetstring_type& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<octetstring_type>& vl) {
                octet_reader_defsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, utf8string_type& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<utf8string_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, numericstring_type& vl) {
                size_constrainter<numericstring_type, numericstring_ec> tmp(vl);
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<numericstring_type>& vl) {
                size_constrainter<numericstring_type, numericstring_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, printablestring_type& vl) {
                size_constrainter<printablestring_type, printablestring_ec> tmp(vl);
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<printablestring_type>& vl) {
                size_constrainter<printablestring_type, printablestring_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, t61string_type& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<t61string_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, videotexstring_type& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<videotexstring_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, ia5string_type& vl) {
                size_constrainter< ia5string_type, ia5string_ec> tmp(vl);
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter< ia5string_type>& vl) {
                size_constrainter< ia5string_type, ia5string_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, graphicstring_type& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<graphicstring_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, objectdescriptor_type& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<objectdescriptor_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, visiblestring_type& vl) {
                size_constrainter<visiblestring_type, visiblestring_ec> tmp(vl);
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<visiblestring_type>& vl) {
                size_constrainter<visiblestring_type, visiblestring_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 1 oct
            }

            input_coder& operator>>(input_coder& stream, generalstring_type& vl) {
                octet_reader_undefsz(stream, vl);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<generalstring_type>& vl) {
                return stream >> vl.value();
            }

            input_coder& operator>>(input_coder& stream, universalstring_type& vl) {
                size_constrainter<universalstring_type, universalstring_ec> tmp(vl);
                return stream >> tmp; // known-multi 4 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter<universalstring_type>& vl) {
                size_constrainter<universalstring_type, universalstring_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 4 oct
            }

            input_coder& operator>>(input_coder& stream, bmpstring_type& vl) {
                size_constrainter< bmpstring_type, bmpstring_ec> tmp(vl);
                return stream >> tmp; // known-multi 2 oct
            }

            input_coder& operator>>(input_coder& stream, size_constrainter< bmpstring_type>& vl) {
                size_constrainter< bmpstring_type, bmpstring_ec> tmp(vl.value(), vl.min(), vl.max(), vl.can_extended());
                return stream >> tmp; // known-multi 2 oct
            }

            input_coder& operator>>(input_coder& stream, utctime_type& vl) {
                visiblestring_type tmp;
                stream >> tmp;
                vl = to_utctime(tmp);
                return stream;
            }

            input_coder& operator>>(input_coder& stream, gentime_type& vl) {
                visiblestring_type tmp;
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
            //int __tag_id__ = arch.test_id();
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
            //int __tag_id__ = arch.test_id();
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
            //int __tag_id__ = arch.test_id();
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

