//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <iosfwd>
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/utils/utils.h>


namespace boost {
    namespace asn1 {
        // oid type

        std::vector<oidindx_type> oid_from_string(const std::string vl) {
            std::string val = boost::algorithm::trim_copy(vl);
            if (val.size() < 3)
                return std::vector<oidindx_type > ();
            if ((val[0] == '{') && (val[val.size() - 1] == '}')) {
                val = val.substr(1, val.size() - 2);
                std::string::size_type digpos = val.find_first_of(",");
                std::vector<oidindx_type> rslt;
                oidindx_type un = 0;
                while (digpos != std::string::npos) {
                    std::string dig = val.substr(0, digpos);
                    if (dig.empty())
                        return std::vector<oidindx_type > ();
                    if (boost::itu::string_to(dig, un)) {
                        rslt.push_back(un);
                    } else {
                        if (!boost::itu::oid_component_by_name(dig, un))
                            return std::vector<oidindx_type > ();
                        else
                            rslt.push_back(un);
                    }
                    val = val.substr(digpos + 1);
                    digpos = val.find_first_of(",");
                }
                if (boost::itu::string_to(val, un)) {
                    rslt.push_back(un);
                    return rslt;
                } else {
                    if (!boost::itu::oid_component_by_name(val, un))
                        return std::vector<oidindx_type > ();
                    else
                        rslt.push_back(un);
                }
            }
            return std::vector<oidindx_type > ();
        }

        oid_type::oid_type(const std::string& vl) {
            std::vector<oidindx_type> tmp = oid_from_string(vl);
            if (!tmp.empty()) {
                insert(begin(), tmp.begin(), tmp.end());
            }
        }

        oid_type::oid_type(const oidindx_type * vl, std::size_t size) :
        boost::itu::containers::vector<oidindx_type>(vl, vl + size) {
        }

        std::ostream& operator<<(std::ostream& stream, const oid_type& vl) {
            for (oid_type::const_iterator it = vl.begin(); it != vl.end(); ++it)
                if (it == vl.begin())
                    stream << *it;
                else
                    stream << "." << *it;
            //stream << std::endl;
            return stream;
        }


        /// bitstring type

        bitstring_type::bitstring_type() : std::vector<octet_type>(), unuse_(0) {
        };

        bitstring_type::bitstring_type(uint8_t vl, std::size_t unuse) : std::vector<octet_type>(), unuse_(unuse) {
            construct(vl, unuse);
        };

        bitstring_type::bitstring_type(uint16_t vl, std::size_t unuse) : std::vector<octet_type>(), unuse_(unuse) {
            construct(vl, unuse);
        };

        bitstring_type::bitstring_type(uint32_t vl, std::size_t unuse) : std::vector<octet_type>(), unuse_(unuse) {
            construct(vl, unuse);
        };

        bitstring_type::bitstring_type(uint64_t vl, std::size_t unuse) : std::vector<octet_type>(), unuse_(unuse) {
            construct(vl, unuse);
        };

        bitstring_type::bitstring_type(int8_t vl, std::size_t unuse) : std::vector<octet_type>(), unuse_(unuse) {
            construct(*reinterpret_cast<uint8_t*> (&vl), unuse);
        };

        bitstring_type::bitstring_type(int16_t vl, std::size_t unuse) : std::vector<octet_type>(), unuse_(unuse) {
            construct(*reinterpret_cast<uint16_t*> (&vl), unuse);
        };

        bitstring_type::bitstring_type(int32_t vl, std::size_t unuse) : std::vector<octet_type>(), unuse_(unuse) {
            construct(*reinterpret_cast<uint32_t*> (&vl), unuse);
        };

        bitstring_type::bitstring_type(int64_t vl, std::size_t unuse) : std::vector<octet_type>(), unuse_(unuse) {
            construct(*reinterpret_cast<uint64_t*> (&vl), unuse);
        };

        bitstring_type::bitstring_type(bool const * const arr, std::size_t cnt) : std::vector<octet_type>() {
            construct(std::vector<bool>(arr, arr + cnt));
        }

        bitstring_type::bitstring_type(const octet_sequnce& vl, std::size_t unuse) : std::vector<octet_type>(), unuse_(unuse % 8) {
            insert_bitstring(vl, unuse);
        };

        bitstring_type::bitstring_type(const std::vector<bool>& vl) : std::vector<octet_type>() {
            construct(vl);
        };

        bitstring_type::bitstring_type(bool vl, std::size_t n) : std::vector<octet_type>(), unuse_(7 - n % 8) {
            reserve((n / 8 + 1));
            insert(begin(), (n / 8 + 1), 0);
            if (vl)
                back() = (0x1 << (7 - (n % 8)));
        }

        bitstring_type::bitstring_type(const std::string& vl, std::size_t unuse) : unuse_(unuse % 8) {
            std::copy(vl.begin(), vl.end(), std::back_inserter(*this));
        }

        void bitstring_type::insert_bitstring(const octet_sequnce& val, std::size_t unuse) {
            if (!val.empty()) {
                unuse_ = unuse % 8;
                std::copy(val.begin(), val.end(), std::back_inserter(*this));
                if (unuse_ && size())
                    back() &= ('\xFF' << unuse_);
            } else
                if (!size())
                unuse_ = 0;
        };

        std::size_t bitstring_type::unusebits(std::size_t vl) {
            if (!empty()) {
                unuse_ = vl % 8;
                if (unuse_)
                    back() &= ('\xFF' << unuse_);
                return unuse_;
            }
            return unuse_ = 0;
        }

        bitstring_type bitstring_type::create_from_string(const std::string& vl) {
            if (!vl.empty()) {
                std::vector<bool> tmpV;
                for (std::size_t i = 0; i < vl.size(); ++i)
                    tmpV.push_back(vl[i] == '0' ? false : true);
                return bitstring_type(tmpV);
            }
            return bitstring_type();
        }

        bool bitstring_type::bit(std::size_t num) const {
            if (sizebits() > num) {
                octet_type vl = ((num / 8) < size()) ? (operator[](num / 8)) : 0;
                return static_cast<octet_type> (1 << (7 - (num % 8))) & vl;
            }
            return false;
        }

        void bitstring_type::bit(std::size_t num, bool val) {
            if (sizebits() > num) {
                if ((num / 8) < size()) {
                    if (val)
                        operator[](num / 8) |= static_cast<octet_type> (1 << (7 - num % 8));
                    else
                        operator[](num / 8) &= ~static_cast<octet_type> (1 << (7 - num % 8));
                }
            }
        }

        bitstring_type::operator bitstring_type::bool_vector_type() const {
            bitstring_type::bool_vector_type tmp;
            for (std::size_t i = 0; i < sizebits(); ++i)
                tmp.push_back(bit(i));
            return tmp;
        }

        bitstring_type::operator bitstring_type::dynamic_bitset_type() const {
            bitstring_type::dynamic_bitset_type tmp(sizebits());
            for (std::size_t i = 0; i < sizebits(); ++i)
                tmp.operator[](i) = bit(i);
            return tmp;
        }

        bitstring_type::dynamic_bitset_type bitstring_type::dynamic_bitset() const {
            bitstring_type::dynamic_bitset_type tmp(sizebits());
            for (std::size_t i = 0; i < sizebits(); ++i)
                tmp.operator[](i) = bit(i);
            return tmp;
        }

        bitstring_type::operator boost::uint8_t() const {
            return return_int<uint8_t > ();
        }

        bitstring_type::operator boost::uint16_t() const {
            return return_int<uint16_t > ();
        }

        bitstring_type::operator boost::uint32_t() const {
            return return_int<uint32_t > ();
        }

        bitstring_type::operator boost::uint64_t() const {
            return return_int<uint64_t > ();
        }

        bitstring_type::operator boost::int8_t() const {
            return return_int<int8_t > ();
        }

        bitstring_type::operator boost::int16_t() const {
            return return_int<int16_t > ();
        }

        bitstring_type::operator boost::int32_t() const {
            return return_int<int32_t > ();
        }

        bitstring_type::operator boost::int64_t() const {
            return return_int<int64_t > ();
        }

        bitstring_type::operator bool() const {
            for (const_reverse_iterator it = rbegin(); it != rend(); ++it) {
                if (*it) {
                    if ((it == rbegin()) &&(unusebits()) && !((*it) & ('\xFF' << unusebits())))
                        continue;
                    return true;
                }
            }
            return false;
        }

        bitstring_type::operator octet_sequnce() const {
            octet_sequnce tmp(begin(), end());
            if ((!tmp.empty()) && (unusebits()))
                tmp.back() &= ('\xFF' << unusebits());
            return tmp;
        }

        octet_sequnce bitstring_type::as_octet_sequnce() const {
            octet_sequnce tmp(begin(), end());
            if ((!tmp.empty()) && (unusebits()))
                tmp.back() &= ('\xFF' << unusebits());
            return tmp;
        }

        bitstring_type bitstring_type::operator~() const {
            if (!empty()) {
                bitstring_type tmp = *this;
                for (iterator it = tmp.begin(); it != tmp.end(); ++it)
                    *it = ~(*it);
                tmp.unusebits(tmp.unusebits());
                return tmp;
            }
            return bitstring_type();
        }

        //bitstring_type::operator octet_sequnce() const{
        //    return  *this;
        //}    

        bitstring_type operator|(const bitstring_type& ls, const bitstring_type& rs) {
            if (ls.size() || rs.size()) {
                bitstring_type tmp;
                const bitstring_type& maxsb = (ls.size() > rs.size()) ? ls : rs;
                const bitstring_type& minsb = (ls.size() > rs.size()) ? rs : ls;
                tmp.assign(maxsb.begin(), maxsb.end());
                for (std::size_t i = 0; i < minsb.size(); ++i) {
                    tmp[i] |= minsb[i];
                }
                if (maxsb.size() == minsb.size())
                    tmp.unusebits(std::min(minsb.unusebits(), maxsb.unusebits()));
                else
                    tmp.unusebits(maxsb.unusebits());
                return tmp;
            }
            return bitstring_type();
        }

        bitstring_type operator&(const bitstring_type& ls, const bitstring_type& rs) {
            if (ls.size() && rs.size()) {
                bitstring_type tmp;
                const bitstring_type& maxsb = (ls.size() > rs.size()) ? ls : rs;
                const bitstring_type& minsb = (ls.size() > rs.size()) ? rs : ls;
                tmp.assign(minsb.begin(), minsb.end());
                for (std::size_t i = 0; i < minsb.size(); ++i) {
                    tmp[i] &= maxsb[i];
                }
                if (maxsb.size() == minsb.size())
                    tmp.unusebits(std::max(minsb.unusebits(), maxsb.unusebits()));
                else
                    tmp.unusebits(minsb.unusebits());
                return tmp;
            }
            return bitstring_type();
        }

        bitstring_type operator^(const bitstring_type& ls, const bitstring_type& rs) {
            if (ls.size() || rs.size()) {
                bitstring_type tmp;
                const bitstring_type& maxsb = (ls.size() > rs.size()) ? ls : rs;
                const bitstring_type& minsb = (ls.size() > rs.size()) ? rs : ls;
                tmp.assign(maxsb.begin(), maxsb.end());
                for (std::size_t i = 0; i < minsb.size(); ++i) {
                    tmp[i] ^= minsb[i];
                }
                if (maxsb.size() == minsb.size())
                    tmp.unusebits(std::min(minsb.unusebits(), maxsb.unusebits()));
                else
                    tmp.unusebits(maxsb.unusebits());
                return tmp;
            }
            return bitstring_type();
        }

        bitstring_type operator+(const bitstring_type& ls, const bitstring_type& rs) {
            octet_sequnce rslt = ls.as_octet_sequnce();
            std::size_t rsltsize = itu::split_bits_in_octets(rslt, ls.unusebits(), rs.as_octet_sequnce(), rs.unusebits());
            return bitstring_type(rslt, rsltsize);
        }

        void bitstring_type::append(const bitstring_type& vl) {
            itu::split_bits_in_octets(*this, unusebits(), vl, vl.unusebits());
        }

        void bitstring_type::append(const octetstring_type& vl) {
            itu::split_bits_in_octets(*this, unusebits(), vl, 0);
        }

        void bitstring_type::construct(const std::vector<bool>& vl) {
            assign((vl.size() % 8) ? (vl.size() / 8 + 1) : (vl.size() / 8), 0);
            unuse_ = (8 - vl.size() % 8) % 8;
            std::size_t sz = 0;
            for (std::vector<bool>::const_iterator it = vl.begin(); it != vl.end(); ++it)
                bit(sz++, *it);
        };

        void bitstring_type::construct(const dynamic_bitset_type& vl) {
            assign((vl.size() % 8) ? (vl.size() / 8 + 1) : (vl.size() / 8), 0);
            unuse_ = (8 - vl.size() % 8) % 8;
            std::size_t sz = 0;
            for (std::size_t it = 0; it < vl.size(); ++it)
                bit(sz++, vl.operator[](it));
        };

        std::ostream& operator<<(std::ostream& stream, const bitstring_type& vl) {
            std::vector<bool> val = vl.operator bitstring_type::bool_vector_type();
            std::size_t n = 0;
            for (std::vector<bool>::const_iterator it = val.begin(); it != val.end(); ++it) {
                if (n && !(n % 8))
                    stream << " ";
                n++;
                stream << (*it ? '1' : '0');
            }
            return stream;
        }



        // octetstring_type

        octetstring_type::operator octet_sequnce() const {
            return octet_sequnce(begin(), end());
        }

        octet_sequnce octetstring_type::as_octet_sequnce() const {
            return octet_sequnce(begin(), end());
        }

        std::ostream& operator<<(std::ostream& stream, const octetstring_type& vl) {
            stream << boost::itu::binary_to_hexsequence_debug(std::string(vl.begin(), vl.end()));
            return stream;
        }


    }


    namespace itu {


        const std::size_t ENCODING_RULE_MAX_BIT = 7;

        encoding_rule to_encoding_rule(encoding_set val) {
            std::size_t rslt = 0;
            while (rslt <= ENCODING_RULE_MAX_BIT) {
                if ((1 << rslt) & val)
                    return (1 << rslt);
                rslt++;
            }
            return NULL_ENCODING;
        }
        

        const transfer_syntax_type& to_transfer_syntax(encoding_rule rule) {
            switch (rule) {
                case BER_ENCODING: return boost::asn1::BASIC_ENCODING_OID;
                case CER_ENCODING: return boost::asn1::CANONICAL_ENCODING_OID;
                case DER_ENCODING: return boost::asn1::DISTINGUISH_ENCODING_OID;
                case PER_ALIGNED_ENCODING: return boost::asn1::PER_ALIGNED_ENCODING_OID;
                case PER_UNALIGNED_ENCODING: return boost::asn1::PER_UNALIGNED_ENCODING_OID;
                case CPER_ALIGNED_ENCODING: return boost::asn1::CPER_ALIGNED_ENCODING_OID;
                case CPER_UNALIGNED_ENCODING: return boost::asn1::CPER_UNALIGNED_ENCODING_OID;
                default:
                {
                }
            }
            return boost::asn1::NULL_ENCODING_OID;
        }

        encoding_rule to_encoding(const transfer_syntax_type& val) {
            if (val == boost::asn1::BASIC_ENCODING_OID)
                return BER_ENCODING;
            if (val == boost::asn1::CANONICAL_ENCODING_OID)
                return CER_ENCODING;
            if (val == boost::asn1::DISTINGUISH_ENCODING_OID)
                return DER_ENCODING;
            if (val == boost::asn1::PER_ALIGNED_ENCODING_OID)
                return PER_ALIGNED_ENCODING;
            if (val == boost::asn1::PER_UNALIGNED_ENCODING_OID)
                return PER_UNALIGNED_ENCODING;
            if (val == boost::asn1::CPER_ALIGNED_ENCODING_OID)
                return CPER_ALIGNED_ENCODING;
            if (val == boost::asn1::CPER_UNALIGNED_ENCODING_OID)
                return CPER_UNALIGNED_ENCODING;
            return NULL_ENCODING;
        }

        transfer_syntax_set to_transfer_syntax_set(encoding_set rules) {
            transfer_syntax_set rslt;
            for (std::size_t it = 0; it <= ENCODING_RULE_MAX_BIT; ++it) {
                if (rules & (1 << it)) {
                    if (to_transfer_syntax(1 << it) != boost::asn1::NULL_ENCODING_OID)
                        rslt.insert(to_transfer_syntax((1 << it)));
                }
            }
            return rslt;
        }

        encoding_set to_encoding_set(const transfer_syntax_set& val) {
            encoding_set rslt = 0;
            for (transfer_syntax_set::const_iterator it = val.begin(); it != val.end(); ++it) {
                rslt |= to_encoding(*it);
            }
            return rslt;
        }





        const char hex_char_array_const[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        const char bad_hex_char = '\xFF';

        void reverse_bit(octet_type& bits) {
            bits = ((bits & 0x0F) << 4) | ((bits & 0xF0) >> 4);
            bits = ((bits & 0x33) << 2) | ((bits & 0xcc) >> 2);
            bits = ((bits & 0x55) << 1) | ((bits & 0xaa) >> 1);
        }

        octet_type reverse_bit_copy(const octet_type& vl) {
            octet_type bits = vl;
            reverse_bit(bits);
            return bits;
        }

        std::size_t split_bits_in_octets(octet_sequnce& inos, std::size_t unus1, const octet_sequnce& fromos, std::size_t unus2) {
            if (inos.empty()) {
                unus1 = 0;
                inos = fromos;
            } else {
                unus1 %= 8;
                unus2 %= 8;
                if (unus1) {
                    if (!fromos.empty()) {
                        std::size_t from_bitcnt = fromos.size()*8 - unus2;
                        const octet_sequnce::value_type msk = (0xFF << unus1);
                        octet_sequnce::const_iterator fit = fromos.begin();
                        while ((from_bitcnt) && (fit != fromos.end())) {
                            inos.back() &= msk;
                            inos.back() |= (((*fit) >> (8 - unus1)) & ~msk);
                            if (from_bitcnt > unus1)
                                from_bitcnt -= unus1;
                            else
                                break;
                            inos.push_back(((*fit) << unus1) & msk);
                            if (from_bitcnt > (8 - unus1))
                                from_bitcnt -= (8 - unus1);
                            else
                                break;
                            ++fit;
                        }
                    } else {
                        unus2 = 0;
                    }
                } else
                    inos.insert(inos.end(), fromos.begin(), fromos.end());
            }
            return inos.empty() ? 0 : ((unus1 + unus2) % 8);
        }

        std::size_t left_shift_bits_in_octets(octet_sequnce& vl, std::size_t shft) {
            if (vl.size()) {
                if (shft > 7) {
                    std::size_t er = shft / 8;
                    if (vl.size() < er)
                        return 0;
                    vl.erase(vl.begin(), vl.begin() + er);
                    shft %= 8;
                }
                if (shft) {
                    const octet_sequnce::value_type msk = ~static_cast<octet_sequnce::value_type> (0xFF << shft);
                    for (octet_sequnce::iterator it = vl.begin(); it != vl.end(); ++it) {
                        *it <<= shft;
                        if ((it + 1) != vl.end())
                            *it |= (msk & ((*(it + 1))>> (8 - shft)));
                        else
                            *it &= ('\xFF') << shft;
                    }
                }
                return 1;
            }
            return 0;
        }

        static inline std::string num8t_to_hexstr(char vl) {
            return std::string(static_cast<const char*> (&hex_char_array_const[((vl >> 4) & 0xF)]), 1) +
                    std::string(static_cast<const char*> (&hex_char_array_const[((vl) & 0xF)]), 1);
        }

        std::string binary_to_hexsequence_debug(const std::string& vl, std::size_t group) {
            std::string rslt = "";
            for (std::string::size_type it = 0; it < vl.size(); ++it) {
                if ((group > 0) && it && !(it % group))
                    rslt = rslt + "  ";
                rslt = rslt + num8t_to_hexstr(vl.at(it));
            }
            return rslt;
        }

        std::size_t pop_frontlist(mutable_sequences& val, std::size_t start) {
            std::size_t rslt = 0;
            while (start && (!val.empty())) {
                if (boost::asio::buffer_size(val.front()) < start) {
                    start -= boost::asio::buffer_size(val.front());
                    rslt += boost::asio::buffer_size(val.front());
                    val.erase(val.begin());
                } else {
                    rslt += start;
                    val.front() = val.front() + start;
                    return rslt;
                }
            }
            return rslt;
        }

        bool splice_frontlist(mutable_sequences& val, std::size_t firstend, std::size_t secondend) {
            if ((!firstend) || (firstend > secondend))
                return false;
            if (firstend == secondend)
                return true;

            mutable_sequences::iterator fit = val.end();
            mutable_sequences::iterator sit = val.end();
            bool fset = false;
            bool sset = false;

            for (mutable_sequences::iterator it = val.begin(); it != val.end(); ++it) {
                mutable_buffer tmp = *it;
                std::size_t size = boost::asio::buffer_size(*it);
                if (!fset) {
                    if (size >= firstend) {
                        if (size == firstend) {
                            fit = it;
                            fset = true;
                        } else {
                            size = firstend;
                            it = val.insert(val.erase(it), tmp + firstend);
                            fit = it = val.insert(it, boost::asio::buffer(tmp, firstend));
                            tmp = *it;
                            fset = true;
                        }
                    }
                }
                if (!sset) {
                    if (size >= secondend) {
                        if (size == secondend) {
                            sit = it;
                            sset = true;
                            break;
                        } else {
                            size = secondend;
                            it = val.insert(val.erase(it), tmp + secondend);
                            sit = it = val.insert(it, boost::asio::buffer(tmp, secondend));
                            sset = true;
                            break;
                        }
                    }
                }

                if (firstend)
                    firstend = (firstend < size) ? 0 : (firstend - size);
                if (secondend)
                    secondend = (secondend < size) ? 0 : (secondend - size);

            }

            if (fset && sset) {
                //std::cout << " This Need splice " << std::endl;
                //std::cout << "before " << val << std::endl;
                val.splice(++sit, val, val.begin(), ++fit);
                //std::cout << "after " << val << std::endl;
                return true;
            }

            return false;
        }

        bool find_eof(const mutable_sequences& val, mutable_sequences::const_iterator bit, std::size_t& rslt, std::size_t start) {
            rslt = 0;
            bool findend = false;
            for (mutable_sequences::const_iterator it = bit; it != val.end(); ++it) {
                mutable_buffer tmp = *it;
                std::size_t size = boost::asio::buffer_size(*it);
                if (size > start) {
                    for (std::size_t i = 0; i < size; ++i) {
                        if (i >= start) {
                            if (findend) {
                                if (!(*boost::asio::buffer_cast<octet_sequnce::value_type*>(boost::asio::buffer(tmp + i, 1)))) {
                                    rslt--;
                                    return true;
                                }
                                findend = false;
                            } else
                                findend = !(*boost::asio::buffer_cast<octet_sequnce::value_type*>(boost::asio::buffer(tmp + i, 1)));
                        }
                        rslt++;
                    }
                } else
                    rslt += size;

                if (start)
                    start = (start < size) ? 0 : (start - size);
            }
            return false;
        }

        bool row_cast(const mutable_sequences& val, mutable_sequences::const_iterator bit, octet_sequnce& raw, std::size_t start, std::size_t size) {
            if (!size)
                return true;
            mutable_sequences::const_iterator it = bit;
            std::size_t sz = 0;
            std::size_t szc = 0;
            std::size_t szb = 0;
            std::size_t sze = 0;
            while (((sz < (start + size)) || (!size)) && (it != val.end())) {
                szc = boost::asio::buffer_size(*it);
                if ((sz + szc) > start) {

                    szb = sz > start ? 0 : start - sz;
                    sze = (!size || ((szb + size) > szc)) ? szc - szb : size;
                    mutable_buffer tmp = boost::asio::buffer(*it + szb, sze);
                    raw.insert(raw.end(), boost::asio::buffer_cast<octet_sequnce::value_type*>(tmp), boost::asio::buffer_cast<octet_sequnce::value_type*>(tmp) + boost::asio::buffer_size(tmp));
                }
                sz += szc;
                ++it;
            }
            return (raw.size() == size);
        }

        std::ostream& operator<<(std::ostream& stream, const const_sequences& self) {
            for (const_sequences::const_iterator it = self.begin(); it != self.end(); ++it)
                stream << binary_to_hexsequence_debug(std::string(boost::asio::buffer_cast<const char*>(*it), boost::asio::buffer_size(*it)));
            stream << std::endl;

            return stream;
        }

        std::ofstream& operator<<(std::ofstream& stream, const const_sequences& self) {
            for (const_sequences::const_iterator it = self.begin(); it != self.end(); ++it)
                stream << std::string(boost::asio::buffer_cast<const char*>(*it), boost::asio::buffer_size(*it));
            stream << std::endl;

            return stream;
        }

        std::ostream& operator<<(std::ostream& stream, const base_output_coder& vl) {
            stream << vl.buffers();

            return stream;
        }

        std::ofstream& operator<<(std::ofstream& stream, const base_output_coder& vl) {
            stream << vl.buffers();

            return stream;
        }

        std::ostream& operator<<(std::ostream& stream, const mutable_sequences& self) {
            for (mutable_sequences::const_iterator it = self.begin(); it != self.end(); ++it)
                stream << binary_to_hexsequence_debug(std::string(boost::asio::buffer_cast<const char*>(*it), boost::asio::buffer_size(*it)));
            stream << std::endl;

            return stream;

        }

        std::ofstream& operator<<(std::ofstream& stream, const mutable_sequences& self) {
            for (mutable_sequences::const_iterator it = self.begin(); it != self.end(); ++it)
                stream << std::string(boost::asio::buffer_cast<const char*>(*it), boost::asio::buffer_size(*it));
            stream << std::endl;
            return stream;
        }



        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////

        base_output_coder::iterator_type base_output_coder::add(const octet_sequnce& vl) {
            if (vl.empty()) return
                listbuffers_->end();
            rows_vect().push_back(octet_sequnce_ptr(new octet_sequnce(vl)));
            size_ += vl.size();
            unuse_ = 0;
            return listbuffers_->insert(listbuffers_->end(), const_buffer(&(rows_vect().back()->operator[](0)), rows_vect().back()->size()));
        }

        base_output_coder::iterator_type base_output_coder::add(const octet_sequnce& vl, iterator_type it) {
            if (vl.empty()) return
                listbuffers_->end();
            rows_vect().push_back(octet_sequnce_ptr(new octet_sequnce(vl)));
            size_ += vl.size();
            unuse_ = 0;
            return listbuffers_->insert(it, const_buffer(&(rows_vect().back()->operator[](0)), rows_vect().back()->size()));
        }

        void base_output_coder::add(const mutable_sequences& vl) {
            for (mutable_sequences::const_iterator it = vl.begin(); it != vl.end(); ++it)
                add(buffer_to_raw(*it));
        }

        std::size_t base_output_coder::load_sequence(const_sequences& val, std::size_t lim) {
            if (!lim) return 0;
            std::size_t rslt = 0;
            const_sequences::iterator it = listbuffers_->begin();
            while ((it != listbuffers_->end()) && (rslt < lim)) {
                std::size_t itbuffsz = boost::asio::buffer_size(*it);
                if ((itbuffsz + rslt) > lim) {
                    val.push_back(boost::asio::buffer(*it, lim - rslt));
                    *it = *it + (lim - rslt);
                    size_ = size(lim - rslt);
                    return lim;
                } else {
                    val.push_back(*it);
                    it = listbuffers_->erase(it);
                    size_ = size(itbuffsz);
                    rslt += itbuffsz;
                    if (rslt == lim)
                        return rslt;
                }
            }
            return rslt;
        }

        bool base_output_coder::bind(octet_sequnce& vl) {
            vl.clear();
            for (iterator_type it = listbuffers_->begin(); it != listbuffers_->end(); ++it)
                vl.insert(vl.end(),
                    const_cast<octet_sequnce::value_type*> (boost::asio::buffer_cast<const octet_sequnce::value_type*>(*it)),
                    const_cast<octet_sequnce::value_type*> (boost::asio::buffer_cast<const octet_sequnce::value_type*>(*it)) + boost::asio::buffer_size(*it));
            clear();
            return true;
        }

        void base_output_coder::datastate_push() {
            data_state ds;
            ds.swap(*this);
            state_stack_.push(ds);
        }

        base_output_coder::data_state base_output_coder::datastate_pop() {
            if (!state_stack_.empty()) {
                data_state ds = state_stack_.top();
                ds.swap(*this);
                state_stack_.pop();
                return ds;
            }
            return data_state();
        }

        bool base_output_coder::has_datastate() const {
            return !state_stack_.empty();
        }


        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////      

        void base_input_coder::add(const octet_sequnce& vl) {
            rows_vect().push_back(octet_sequnce_ptr(new octet_sequnce(vl.begin(), vl.end())));
            size_ += vl.size();
            listbuffers_->push_back(mutable_buffer(&rows_vect().back()->operator[](0), rows_vect().back()->size()));
        }

        void base_input_coder::add(const const_sequences& vl) {
            for (const_sequences::const_iterator it = vl.begin(); it != vl.end(); ++it)
                add(buffer_to_raw(*it));
        }

        void base_input_coder::add_front(const octet_sequnce& vl) {
            rows_vect().push_back(octet_sequnce_ptr(new octet_sequnce(vl.begin(), vl.end())));
            size_ += vl.size();
            listbuffers_->push_front(mutable_buffer(&rows_vect().back()->operator[](0), rows_vect().back()->size()));
        }

        bool base_input_coder::is_endof(std::size_t beg) const {
            octet_sequnce data;
            if (row_cast(*listbuffers_, listbuffers_->begin(), data, beg, 2)) {
                if ((data.size() == 2) && (data[0] == 0) && (data[1] == 0)) {
                    return true;
                }
            }
            return false;
        }

        void base_input_coder::clear() {
            listbuffers_->clear();
            rows_vect().clear(); //                                           ???
            size_ = 0;
        }

        bool base_input_coder::bind(const octet_sequnce& vl) {
            clear();
            add(vl);
            return true;
        }

        void base_input_coder::datastate_push() {
            data_state ds;
            ds.swap(*this);
            state_stack_.push(ds);
        }

        base_input_coder::data_state base_input_coder::datastate_pop() {
            if (!state_stack_.empty()) {
                data_state ds = state_stack_.top();
                ds.swap(*this);
                state_stack_.pop();
                return ds;
            }
            return data_state();
        }

        bool base_input_coder::has_datastate() const {
            return !state_stack_.empty();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////  

        std::string basic_coder::request_str() const {
            const const_sequences& tmp = request();
            std::string rslt;
            for (const_sequences::const_iterator it = tmp.begin(); it != tmp.end(); ++it) {
                rslt.insert(rslt.end(),
                        const_cast<std::string::value_type*> (boost::asio::buffer_cast<const std::string::value_type*>(*it)),
                        const_cast<std::string::value_type*> (boost::asio::buffer_cast<const std::string::value_type*>(*it)) + boost::asio::buffer_size(*it)
                        );
            }
            return rslt;
        };

        void basic_coder::request_str(const std::string& val) {
            output_->clear();
            output_->add(octet_sequnce(val.begin(), val.end()));
        };

        std::string basic_coder::respond_str() const {
            const mutable_sequences& tmp = input_->buffers();
            std::string rslt;
            for (mutable_sequences::const_iterator it = tmp.begin(); it != tmp.end(); ++it) {
                rslt.insert(rslt.end(),
                        const_cast<std::string::value_type*> (boost::asio::buffer_cast<const std::string::value_type*>(*it)),
                        const_cast<std::string::value_type*> (boost::asio::buffer_cast<const std::string::value_type*>(*it)) + boost::asio::buffer_size(*it)
                        );
            }
            return rslt;
        };

        void basic_coder::respond_str(const std::string& val) {
            input_->clear();
            input_->add(octet_sequnce(val.begin(), val.end()));
        };





        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////  

        std::size_t basic_sender_sequences::size(std::size_t sz) {

            if (sz == 0) return size_;
            std::size_t tmpsize = sz;
            while ((!buff().empty()) && tmpsize) {
                const_sequences::iterator it = buff().begin();
                if (tmpsize < boost::asio::buffer_size(*it)) {
                    *it = const_buffer((*it) + sz);
                    return size_ += sz;
                } else {
                    tmpsize = boost::asio::buffer_size(*it) > tmpsize ? 0 : (tmpsize - boost::asio::buffer_size(*it));
                    buff().erase(it);
                }
            }
            return size_ += sz;
        }

    }


}
