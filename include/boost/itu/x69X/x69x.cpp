//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#include <boost/lexical_cast.hpp>
#include <boost/itu/x69X/x69x.hpp>

namespace boost {
    namespace asn1 {

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
                octet_sequnce tmp;// (val.size());
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

/*
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

        }


*/
        
    }
}

