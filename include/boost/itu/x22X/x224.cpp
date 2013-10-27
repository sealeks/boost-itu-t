//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x22X/x224.hpp>


namespace boost {
    namespace itu {
        namespace x224impl {

            tpdu_type tpdu_type_from(octet_type val) {
                switch (val) {
                    case CR_TPDU_ID: return CR;
                    case CC_TPDU_ID: return CC;
                    case DR_TPDU_ID: return DR;
                    case DC_TPDU_ID: return DR;
                    case DT_TPDU_ID: return DT;
                    case ED_TPDU_ID: return ED;
                    case DA_TPDU_ID: return DA;
                    case EA_TPDU_ID: return EA;
                    case RJ_TPDU_ID: return RJ;
                    case ER_TPDU_ID: return ER;
                };
                return NL;
            }


            /// tpdu_size

            tpdu_size::tpdu_size() : preferred_(), basic_(), size_(0) {
                basic(TPDU_SIZE2048);
                preferred(PREFFERED_TPDU_SIZE, TPDU_SIZE2048);
            }

            tpdu_size::tpdu_size(octet_type bas) : preferred_(), basic_(), size_(0) {
                basic(bas);
            }

            tpdu_size::tpdu_size(const octet_sequnce& pref, octet_type bas) : preferred_(), basic_(), size_(0) {
                if (pref.empty()) {
                    basic(bas);
                    preferred_ = 0;
                }
                else {
                    if (pref.size() == 1) {
                        preferred(static_cast<uint16_t> (pref[0]), bas);
                    }
                    else {
                        uint16_t tmp = 0;
                        if (raw_to_inttype(octet_sequnce(pref.begin() + (pref.size() < 3 ? 0 : (pref.size() - 2)), pref.end()), tmp)) {
                            preferred(tmp, bas);
                        }
                        else {
                            basic(bas);
                            preferred_ = 0;
                        }
                    }
                }
            }

            void tpdu_size::preferred(uint16_t val, octet_type bas) {
                if (val) {
                    preferred_ = val > PREFFERED_TPDU_SIZE ? PREFFERED_TPDU_SIZE : val;
                    size_ = preferred_ * 128;
                }
                else {
                    preferred_ = 0;
                    basic(bas);
                }
            }

            void tpdu_size::basic(octet_type val) {
                basic_ = val;
                size_ = size_from_octet(basic_);
            }

            std::size_t tpdu_size::size_from_octet(octet_type val) {
                switch (val) {
                    case TPDU_SIZE8192: return 8192;
                    case TPDU_SIZE4096: return 4096;
                    case TPDU_SIZE2048: return 2048;
                    case TPDU_SIZE1024: return 1024;
                    case TPDU_SIZE512: return 512;
                    case TPDU_SIZE256: return 256;
                    case TPDU_SIZE128: return 128;
                }
                return 128;
            }


            /////

            bool parse_vars(const octet_sequnce& data, headarvarvalues& vars) {
                vars.clear();
                std::size_t it = 0;
                while (it + 2 < data.size()) {
                    octet_type par = static_cast<octet_type> (data[it]);
                    std::size_t len = static_cast<std::size_t> (static_cast<uint8_t> (data[it + 1]));
                    if ((it + 2 + len) > data.size()) {
                        vars.clear();
                        return false;
                    }
                    vars.push_back(headarvarvalue(headarvar(par, len), octet_sequnce(data.begin() +(it + 2), data.begin() +(it + 2 + len))));
                    it += (2 + len);
                }
                return it == data.size();
            }

            ///   protocol_options

            protocol_options::protocol_options(int16_t dst, int16_t src, const tpdu_size& pdusz, const octet_sequnce& called, const octet_sequnce& calling) :
            dst_(dst), src_(src) {
                vars_.push_back(headarvarvalue(headarvar(VAR_TPDU_SIZE, 1), inttype_to_raw<octet_type > (pdusz.basic())));
                if (pdusz.preferred())
                    vars_.push_back(headarvarvalue(headarvar(VAR_MAXTPDU_SIZE, 2), inttype_to_raw<uint16_t > (pdusz.preferred())));
                if (!calling.empty()) vars_.push_back(headarvarvalue(headarvar(VAR_TSAPCALLING_ID, calling.size()), calling));
                if (!called.empty()) vars_.push_back(headarvarvalue(headarvar(VAR_TSAPCALLED_ID, called.size()), called));
            }

            protocol_options::protocol_options(const transport_selector& tsl, const tpdu_size& pdusz) :
            dst_(0), src_(0) {
                vars_.push_back(headarvarvalue(headarvar(VAR_TPDU_SIZE, 1), inttype_to_raw(pdusz.basic())));
                if (pdusz.preferred())
                    vars_.push_back(headarvarvalue(headarvar(VAR_MAXTPDU_SIZE, 2), inttype_to_raw(pdusz.preferred())));
                if (!tsl.calling().empty()) vars_.push_back(headarvarvalue(headarvar(VAR_TSAPCALLING_ID, tsl.calling().size()), tsl.calling()));
                if (!tsl.called().empty()) vars_.push_back(headarvarvalue(headarvar(VAR_TSAPCALLED_ID, tsl.called().size()), tsl.called()));
            }

            tpdu_size protocol_options::pdusize() const {
                octet_type basic = TPDU_SIZE128;
                octet_sequnce preferred;
                for (headarvarvalues::const_reverse_iterator it = vars_.rbegin(); it != vars_.rend(); ++it) {
                    if (it->first.first == VAR_TPDU_SIZE && !it->second.empty()) {
                        basic = static_cast<octet_type> (it->second[0]);
                    }
                    if (it->first.first == VAR_MAXTPDU_SIZE && !it->second.empty()) {
                        preferred = it->second;
                    }
                }
                return preferred.empty() ? tpdu_size(basic) : tpdu_size(preferred, basic);
            }

            const octet_sequnce& protocol_options::calling() const {
                for (headarvarvalues::const_reverse_iterator it = vars_.rbegin(); it != vars_.rend(); ++it) {
                    if (it->first.first == VAR_TSAPCALLING_ID && !it->second.empty()) {
                        return it->second;
                    }
                }
                return null_;
            }

            void protocol_options::calling(const octet_sequnce& val) {
                for (headarvarvalues::reverse_iterator it = vars_.rbegin(); it != vars_.rend(); ++it) {
                    if (it->first.first == VAR_TSAPCALLING_ID) {
                        it->second = val;
                        return;
                    }
                }
                vars_.push_back(headarvarvalue(headarvar(VAR_TSAPCALLING_ID, val.size()), octet_sequnce(val.begin(), val.end())));
            }

            const octet_sequnce& protocol_options::called() const {
                for (headarvarvalues::const_reverse_iterator it = vars_.rbegin(); it != vars_.rend(); ++it) {
                    if (it->first.first == VAR_TSAPCALLED_ID && !it->second.empty()) {
                        return it->second;
                    }
                }
                return null_;
            }

            void protocol_options::called(const octet_sequnce& val) {
                for (headarvarvalues::reverse_iterator it = vars_.rbegin(); it != vars_.rend(); ++it) {
                    if (it->first.first == VAR_TSAPCALLED_ID) {
                        it->second = val;
                        return;
                    }
                }
                vars_.push_back(headarvarvalue(headarvar(VAR_TSAPCALLED_ID, val.size()), octet_sequnce(val.begin(), val.end())));
            }

            std::size_t protocol_options::maxpdusize() const {
                for (headarvarvalues::const_reverse_iterator it = vars_.rbegin(); it != vars_.rend(); ++it) {
                    if (it->first.first == VAR_MAXTPDU_SIZE && !it->second.empty()) {
                        return 128;
                    }
                }
                return 128;
            }

            void protocol_options::maxpdusize(std::size_t val) {
                for (headarvarvalues::reverse_iterator it = vars_.rbegin(); it != vars_.rend(); ++it) {
                    if (it->first.first == VAR_MAXTPDU_SIZE) {
                        return;
                    }
                }
                vars_.push_back(headarvarvalue(headarvar(VAR_MAXTPDU_SIZE, 1), inttype_to_raw(static_cast<octet_type> ('\x80'))));
            }

        }
    }
}