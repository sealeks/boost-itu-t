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
                    }
                    else {
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
                }
                else {
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

        oid_type::oid_type(const boost::array<oidindx_type, 2 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 3 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 4 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 5 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 6 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 7 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 8 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 9 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 10 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 11 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 12 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 13 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 14 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 15 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
        }

        oid_type::oid_type(const boost::array<oidindx_type, 16 > & vl) :
        boost::itu::containers::vector<oidindx_type>(vl.begin(), vl.end()) {
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

    }


    namespace itu {

        const transfer_syntax_type& to_transfer_syntax(encoding_rule rule) {
            switch (rule) {
                case BER_ENCODING: return boost::asn1::BASIC_ENCODING_OID;
                case CER_ENCODING: return boost::asn1::CANONICAL_ENCODING_OID;
                case DER_ENCODING: return boost::asn1::DISTINGUISH_ENCODING_OID;
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
            return NULL_ENCODING;
        }

        transfer_syntax_set to_transfer_syntax_set(encoding_set rules) {
            transfer_syntax_set rslt;
            for (std::size_t it = 0; it <= ENCODING_RULE_MAX_BIT; ++it) {
                if (rules && (1 << it)) {
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

        static inline std::string num8t_to_hexstr(char vl) {
            return std::string(static_cast<const char*> (&hex_char_array_const[((vl >> 4) & 0xF)]), 1) +
                    std::string(static_cast<const char*> (&hex_char_array_const[((vl) & 0xF)]), 1);
        }

        std::string binary_to_hexsequence_debug(const std::string& vl) {
            std::string rslt = "";
            for (std::string::size_type it = 0; it < vl.size(); ++it) {
                rslt = rslt + " " + num8t_to_hexstr(vl.at(it));
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
                }
                else {
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
                        }
                        else {
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
                        }
                        else {
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
                            }
                            else
                                findend = !(*boost::asio::buffer_cast<octet_sequnce::value_type*>(boost::asio::buffer(tmp + i, 1)));
                        }
                        rslt++;
                    }
                }
                else
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
            rows_vect.push_back(octet_sequnce_ptr(new octet_sequnce(vl)));
            size_ += vl.size();
            return listbuffers_->insert(listbuffers_->end(), const_buffer(&(rows_vect.back()->operator[](0)), rows_vect.back()->size()));
        }

        base_output_coder::iterator_type base_output_coder::add(const octet_sequnce& vl, iterator_type it) {
            if (vl.empty()) return
                listbuffers_->end();
            rows_vect.push_back(octet_sequnce_ptr(new octet_sequnce(vl)));
            size_ += vl.size();
            return listbuffers_->insert(it, const_buffer(&(rows_vect.back()->operator[](0)), rows_vect.back()->size()));
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
                }
                else {
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


        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////      

        void base_input_coder::add(const octet_sequnce& vl) {
            rows_vect.push_back(octet_sequnce_ptr(new octet_sequnce(vl.begin(), vl.end())));
            size_ += vl.size();
            listbuffers_->push_back(mutable_buffer(&rows_vect.back()->operator [](0), rows_vect.back()->size()));
        }

        void base_input_coder::add(const const_sequences& vl) {
            for (const_sequences::const_iterator it = vl.begin(); it != vl.end(); ++it)
                add(buffer_to_raw(*it));
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
            size_ = 0;
        }

        bool base_input_coder::bind(const octet_sequnce& vl) {
            clear();
            add(vl);
            return true;
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
                }
                else {
                    tmpsize = boost::asio::buffer_size(*it) > tmpsize ? 0 : (tmpsize - boost::asio::buffer_size(*it));
                    buff().erase(it);
                }
            }
            return size_ += sz;
        }

    }
}
