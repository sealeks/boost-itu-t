//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#include <boost/itu/asn1/asnbase.hpp>
#include <algorithm>

namespace boost {
    namespace asn1 {

        template <typename T> inline static T string_to(std::string val) {
            std::string::size_type it = val.find_first_not_of('0');
            if (it == std::string::npos)
                return 0;
            val = val.substr(it);
            return boost::lexical_cast<T > (val);
        }

        class_type to_class_type(octet_type vl) {
            switch (vl & 0xC0) {
                case 0x40: return APPLICATION_CLASS;
                case 0x80: return CONTEXT_CLASS;
                case 0xC0: return PRIVATE_CLASS;
                default:
                {
                }
            }
            return UNIVERSAL_CLASS;
        }




        // enumerated type        

        indx_enumerated_map create_indx_enumerated(const enum_base_type* ev, std::size_t sz) {
            indx_enumerated_map rslt;
            if (sz) {
                typedef std::set<enumerated > enumerated_set;
                typedef std::pair<std::size_t, enumerated > indx_enumerated_pair;
                enumerated_set tmpset;
                std::size_t ind = 0;
                while (sz--)
                    tmpset.insert(*ev++);
                for (enumerated_set::const_iterator it = tmpset.begin(); it != tmpset.end(); ++it)
                    rslt.insert(indx_enumerated_pair(ind++, *it));
            }
            return rslt;
        }

        enumerated_indx_map create_enumerated_indx(const enum_base_type* ev, std::size_t sz) {
            enumerated_indx_map rslt;
            if (sz) {
                typedef std::set<enumerated > enumerated_set;
                typedef std::pair<enumerated, std::size_t> enumerated_indx_pair;
                enumerated_set tmpset;
                std::size_t ind = 0;
                while (sz--)
                    tmpset.insert(*ev++);
                for (enumerated_set::const_iterator it = tmpset.begin(); it != tmpset.end(); ++it)
                    rslt.insert(enumerated_indx_pair(*it, ind++));
            }
            return rslt;
        }

        std::ostream& operator<<(std::ostream& stream, const enumerated& vl) {
            return stream << "(enum)" << vl.as_base();
        }

        // null_type

        std::ostream& operator<<(std::ostream& stream, const null_type& vl) {
            return stream << "NULL";
        }


        // relative oid type

        std::ostream& operator<<(std::ostream& stream, const reloid_type& vl) {
            for (reloid_type::const_iterator it = vl.begin(); it != vl.end(); ++it)
                if (it == vl.begin())
                    stream << *it;
                else
                    stream << "." << *it;
            return stream;
        }


        // utf8_string

        std::ostream& operator<<(std::ostream& stream, const utf8_string& vl) {
            stream << std::string(vl.begin(), vl.end());
            return stream;
        }

        // oid_iri_type

        std::ostream& operator<<(std::ostream& stream, const oid_iri_type& vl) {
            stream << std::string(vl.begin(), vl.end());
            return stream;
        }

        // reloid_iri_type

        std::ostream& operator<<(std::ostream& stream, const reloid_iri_type& vl) {
            stream << std::string(vl.begin(), vl.end());
            return stream;
        }

        // universal_string  // bmp_string

        octet_sequnce as_octet_sequnce(const universal_string& vl) {
            octet_sequnce rslt;
            rslt.reserve(4 * vl.size());
            for (universal_string::const_iterator it = vl.begin(); it != vl.end(); ++it) {
#ifdef __ITU_IS_LE_STRING__
                const universal_string::value_type& el = *it;
                octet_sequnce tmp(reinterpret_cast<octet_sequnce::const_pointer> (&el),
                        reinterpret_cast<octet_sequnce::const_pointer> (&el) + sizeof (universal_string::value_type));
#ifdef __ITU__WCHAR16__ 
                rslt.insert(rslt.end(), 2, 0);
#endif                  
                rslt.insert(rslt.end(), tmp.rbegin(), tmp.rend());
#else
                const universal_string::value_type& el = *it;
#ifdef __ITU__WCHAR16__ 
                rslt.insert(rslt.end(), 2, 0);
#endif                   
                rslt.insert(rslt.end(), reinterpret_cast<octet_sequnce::const_pointer> (&el),
                        reinterpret_cast<octet_sequnce::const_pointer> (&el) + sizeof (universal_string::value_type));
#endif            
            }
            return rslt;
        }

        octet_sequnce as_octet_sequnce(const bmp_string& vl) {
            octet_sequnce rslt;
            rslt.reserve(2 * vl.size());
            for (bmp_string::const_iterator it = vl.begin(); it != vl.end(); ++it) {
#ifdef __ITU_IS_LE_STRING__
                const bmp_string::value_type& el = *it;
                octet_sequnce tmp(reinterpret_cast<octet_sequnce::const_pointer> (&el),
                        reinterpret_cast<octet_sequnce::const_pointer> (&el) + 2);
                rslt.insert(rslt.end(), tmp.rbegin(), tmp.rend());
#else
                const bmp_string::value_type& el = *it;
                rslt.insert(rslt.end(), reinterpret_cast<octet_sequnce::const_pointer> (&el),
                        reinterpret_cast<octet_sequnce::const_pointer> (&el) + 2);
#endif            
            }
            return rslt;
        }

        bool from_octet_sequnce(universal_string& vl, const octet_sequnce& val) {
            for (octet_sequnce::size_type it = 0; it < val.size(); it += 4) {
                if ((it + 4) > val.size())
                    return false;
#ifdef __ITU__WCHAR16__ 
                boost::uint16_t el = *(reinterpret_cast<const boost::uint16_t*> (&val[it + 2]));

#ifdef __ITU_IS_LE_STRING__
                vl.push_back((universal_string::value_type) ((0xFF00 & (el << 8)) | (0xFF & (el >> 8))));
#else
                vl.push_back((universal_string::value_type) el);
#endif                   

#else                 
                boost::uint32_t el = *(reinterpret_cast<const boost::uint32_t*> (&val[it]));

#ifdef __ITU_IS_LE_STRING__
                vl.push_back((universal_string::value_type) ((0xFF000000 & (el << 24)) | (0xFF0000 & (el << 16)) | (0xFF00 & (el >> 16)) | (0xFF & (el >> 24))));
#else
                vl.push_back((universal_string::value_type) el);
#endif   

#endif                 
            }
            return true;
        }

        bool from_octet_sequnce(bmp_string& vl, const octet_sequnce& val) {
            for (octet_sequnce::size_type it = 0; it < val.size(); it += 2) {
                if ((it + 2) > val.size())
                    return false;
#ifdef __ITU__WCHAR16__ 
                boost::uint16_t el = *(reinterpret_cast<const boost::uint16_t*> (&val[it]));

#ifdef __ITU_IS_LE_STRING__
                vl.push_back((bmp_string::value_type) ((0xFF00 & (el << 8)) | (0xFF & (el >> 8))));
#else
                vl.push_back((bmp_string::value_type) el);
#endif 

#else                 
                boost::uint32_t el = *(reinterpret_cast<const boost::uint16_t*> (&val[it]));
#ifdef __ITU_IS_LE_STRING__
                vl.push_back((bmp_string::value_type) ((0xFF000000 & (el << 24)) | (0xFF0000 & (el << 16)) | (0xFF00 & (el >> 16)) | (0xFF & (el >> 24))));
#else
                vl.push_back((bmp_string::value_type) el);
#endif   
#endif                 
            }
            return true;
        }

        // universal_string

        std::ostream& operator<<(std::ostream& stream, const universal_string& vl) {
            return stream << "UNIVERSALSTRING"; //vl.as_utf8().as_base();
        }


        // bmp_string       

        std::ostream& operator<<(std::ostream& stream, const bmp_string& vl) {
            return stream << "BMPSTRING"; //vl.as_utf8().as_base();
        }



        // time types      

        static base_date_time to_z_impltime(const std::string& val, const base_date_time& tm) {
            if (val.empty())
                return tm;
            if (val.size() != 5)
                return base_date_time();
            switch (val[0]) {
                case '+':
                {
                    return (tm + (boost::posix_time::hours(string_to<int>(val.substr(1, 2))) +
                            boost::posix_time::minutes(string_to<int>(val.substr(3, 2)))));
                }
                case '-':
                {
                    return (tm - (boost::posix_time::hours(string_to<int>(val.substr(1, 2))) +
                            boost::posix_time::minutes(string_to<int>(val.substr(3, 2)))));
                }
            }
            return base_date_time();
        }

        static octet_sequnce from_impltime(const base_date_time& val, bool full) {
            octet_sequnce rslt;
            if (!val.is_special()) {
                std::string tmp = boost::posix_time::to_iso_string(val) + "Z";
                //std::string tmp = boost::posix_time::to_iso_string(val) + "+0400";
                //std::string tmp = "201211301232.51+0400";
                if (tmp.find('T') != std::string::npos)
                    tmp.erase(tmp.find('T'), 1);
                if (!full) {
                    if (tmp.size() > 2)
                        std::copy(tmp.begin() + 2, tmp.end(), std::back_inserter(rslt));
                } else
                    std::copy(tmp.begin(), tmp.end(), std::back_inserter(rslt));
            }
            return rslt;
        }

        static base_date_time to_impl_time(const octet_sequnce& val, bool full) {
            if (val.size() > 8) {
                try {
                    std::string tmp(val.begin(), val.end());
                    std::string::size_type it = tmp.find('z');
                    std::string zdelt = "";
                    if (it == std::string::npos)
                        it = tmp.find('Z');
                    if (it == std::string::npos) {
                        it = tmp.find('-');
                        if (it != std::string::npos) {
                            zdelt = tmp.substr(it);
                            tmp = tmp.substr(0, it);
                        } else {
                            it = tmp.find('+');
                            if (it != std::string::npos) {
                                zdelt = tmp.substr(it);
                                tmp = tmp.substr(0, it);
                            }
                        }
                    } else
                        tmp = tmp.substr(0, it);

                    if (tmp.empty())
                        return base_date_time();

                    if (!full)
                        tmp = ((tmp[0] == '9') || (tmp[0] == '8')) ? ("19" + tmp) : ("20" + tmp);

                    if (tmp.size() < 8)
                        return base_date_time();

                    base_date_time rslt(boost::gregorian::date(string_to<int>(tmp.substr(0, 4)), string_to<int>(tmp.substr(4, 2)), string_to<int>(tmp.substr(6, 2))));

                    if (tmp.size() == 8)
                        return zdelt.empty() ? rslt : to_z_impltime(zdelt, rslt);
                    else
                        tmp = tmp.substr(8);

                    if (tmp.size() < 2)
                        return base_date_time();

                    rslt += boost::posix_time::hours(string_to<int>(tmp.substr(0, 2)));

                    if (tmp.size() == 2)
                        return zdelt.empty() ? rslt : to_z_impltime(zdelt, rslt);
                    else
                        tmp = tmp.substr(2);

                    if (tmp[0] == '.') {
                        return zdelt.empty() ? (rslt + boost::posix_time::millisec(static_cast<int> (3600000 * string_to<double>("0" + tmp)))) :
                                to_z_impltime(zdelt, (rslt + boost::posix_time::millisec(static_cast<int> (3600000 * string_to<double>("0" + tmp)))));
                    } else {
                        if (tmp.size() < 2)
                            return base_date_time();
                    }

                    rslt += boost::posix_time::minutes(string_to<int>(tmp.substr(0, 2)));

                    if (tmp.size() == 2)
                        return zdelt.empty() ? rslt : to_z_impltime(zdelt, rslt);
                    else
                        tmp = tmp.substr(2);

                    if (tmp[0] == '.') {
                        return zdelt.empty() ? (rslt + boost::posix_time::microsec(static_cast<int> (60000000 * string_to<double>("0" + tmp)))) :
                                to_z_impltime(zdelt, (rslt + boost::posix_time::microsec(static_cast<int> (60000000 * string_to<double>("0" + tmp)))));
                    } else {
                        if (tmp.size() < 2)
                            return base_date_time();
                    }

                    rslt += boost::posix_time::seconds(string_to<int>(tmp.substr(0, 2)));

                    if (tmp.size() == 2)
                        return zdelt.empty() ? rslt : to_z_impltime(zdelt, rslt);
                    else
                        tmp = tmp.substr(2);

                    if (tmp[0] != '.')
                        return base_date_time();


                    if (tmp.size() == 1)
                        return zdelt.empty() ? rslt : to_z_impltime(zdelt, rslt);

                    rslt += boost::posix_time::microsec(static_cast<int> (string_to<double>("0" + tmp)*1000000));

                    return zdelt.empty() ? rslt : to_z_impltime(zdelt, rslt);

                } catch (...) {
                }
            }
            return base_date_time();
        }





        // utctime      

        utctime::utctime(const boost::posix_time::ptime& vl) :
        val_(vl) {
        }

        utctime::utctime(const std::string::value_type* val) :
        val_(to_utctime(std::string(val))) {
        }

        utctime::utctime(const std::string& val) :
        val_(to_utctime(val)) {
        }

        utctime& utctime::operator=(const std::string::value_type* val) {
            val_ = to_utctime(std::string(val));
            return *this;
        }

        utctime& utctime::operator=(const std::string& val) {
            val_ = to_utctime(val);
            return *this;
        }

        octet_sequnce from_utctime(const utctime& val) {
            return from_impltime(val.value(), false);
        }

        visible_string as_visiblestring(const utctime& val) {
            const octet_sequnce& trslt = from_utctime(val);
            return visible_string(trslt.begin(), trslt.end());
        }

        utctime to_utctime(const octet_sequnce& val) {
            return utctime(to_impl_time(val, false));
        }

        utctime to_utctime(const visible_string& val) {
            return to_utctime(as_octet_sequnce(val));
        }

        utctime to_utctime(const std::string& val) {
            return to_utctime(octet_sequnce(val.begin(), val.end()));
        }

        std::ostream& operator<<(std::ostream& stream, const utctime& vl) {
            return stream << vl.value();
        }


        // gentime      

        gentime::gentime(const boost::posix_time::ptime& vl) :
        val_(vl) {
        }

        gentime::gentime(const std::string::value_type* val) :
        val_(to_gentime(std::string(val))) {
        }

        gentime::gentime(const std::string& val) :
        val_(to_gentime(val)) {
        }

        gentime& gentime::operator=(const std::string::value_type* val) {
            val_ = to_gentime(std::string(val));
            return *this;
        }

        gentime& gentime::operator=(const std::string& val) {
            val_ = to_gentime(val);
            return *this;
        }

        octet_sequnce from_gentime(const gentime& val) {
            return from_impltime(val.value(), true);
        }

        visible_string as_visiblestring(const gentime& val) {
            const octet_sequnce& trslt = from_gentime(val);
            return visible_string(trslt.begin(), trslt.end());
        }

        gentime to_gentime(const octet_sequnce& val) {
            return gentime(to_impl_time(val, true));
        }

        gentime to_gentime(const visible_string& val) {
            return to_gentime(as_octet_sequnce(val));
        }

        gentime to_gentime(const std::string& val) {
            return to_gentime(octet_sequnce(val.begin(), val.end()));
        }

        std::ostream& operator<<(std::ostream& stream, const gentime& vl) {
            return stream << vl.value();
        }





        //  explicit_value   

        std::ostream& operator<<(std::ostream& stream, const tag& vl) {
            return stream << "TAG: " << vl.id() << " mask:" << vl.mask() << '\n';
        }

        // prefixed

        std::ostream& operator<<(std::ostream& stream, const prefixed_type& vl) {
            stream << "[ " << vl.first << "]";
            switch (vl.second) {
                case APPLICATION_CLASS:
                {
                    stream << " APPLICATION";
                    break;
                }
                case CONTEXT_CLASS:
                {
                    stream << " CONTEXT";
                    break;
                }
                case PRIVATE_CLASS:
                {
                    stream << " PRIVATE";
                    break;
                }
                default:
                {
                    stream << " UNIVERSAL";
                }
            }
            return stream;
        }

        std::ostream& operator<<(std::ostream& stream, const prefixed_vect& vl) {
            stream << "{ ";
            for (prefixed_vect::const_iterator it = vl.begin(); it != vl.end(); ++it) {
                if (it != vl.begin())
                    stream << ", ";
                stream << "{" << (*it) << "}";
            }
            return stream << " }";
        }

        std::ostream& operator<<(std::ostream& stream, const prefixed_helper& vl) {
            stream << "prefix:  initial ";
            if (vl.init_explicit)
                stream << " explicit  -> " << vl.vect;
            else
                stream << " implicit  -> " << vl.vect;
            return stream << " ";
        }

        // external 

        external_type::external_type() : encoding_() {
        };

        external_type::external_type(const Encoding_type& arg__encoding) :
        encoding_(arg__encoding) {
        };

        external_type::external_type(ITU_T_SHARED(oid_type) arg__direct_reference,
                ITU_T_SHARED(integer_type) arg__indirect_reference,
                ITU_T_SHARED(object_descriptor) arg__data_value_descriptor,
                ITU_T_SHARED(Encoding_type) arg__encoding) :
        direct_reference_(arg__direct_reference),
        indirect_reference_(arg__indirect_reference),
        data_value_descriptor_(arg__data_value_descriptor),
        encoding_(arg__encoding) {
        };



        ITU_T_CHOICES_DEFN(external_type::Encoding_type::single_ASN1_type, single_ASN1_type, any_type, Encoding_type_single_ASN1_type);
        ITU_T_CHOICES_DEFN(external_type::Encoding_type::octet_aligned, octet_aligned, octet_string, Encoding_type_octet_aligned);
        ITU_T_CHOICES_DEFN(external_type::Encoding_type::arbitrary, arbitrary, bit_string, Encoding_type_arbitrary);


        ITU_T_OPTIONAL_DEFN(external_type::direct_reference, direct_reference, oid_type);
        ITU_T_OPTIONAL_DEFN(external_type::indirect_reference, indirect_reference, integer_type);
        ITU_T_OPTIONAL_DEFN(external_type::data_value_descriptor, data_value_descriptor, object_descriptor);
        ITU_T_HOLDERH_DEFN(external_type::encoding, encoding, external_type::Encoding_type);




        //embeded_pdv

        embeded_pdv::embeded_pdv() : identification_(), data_value_() {
        };

        embeded_pdv::embeded_pdv(const Identification_type& arg__identification,
                const octet_string& arg__data_value) :
        identification_(arg__identification),
        data_value_(arg__data_value) {
        };

        embeded_pdv::embeded_pdv(ITU_T_SHARED(Identification_type) arg__identification,
                ITU_T_SHARED(octet_string) arg__data_value) :
        identification_(arg__identification),
        data_value_(arg__data_value) {
        };

        embeded_pdv::Identification_type::Syntaxes_type::Syntaxes_type() : abstract_(), transfer_() {
        };

        embeded_pdv::Identification_type::Syntaxes_type::Syntaxes_type(const oid_type& arg__abstract,
                const oid_type& arg__transfer) :
        abstract_(arg__abstract),
        transfer_(arg__transfer) {
        };

        embeded_pdv::Identification_type::Syntaxes_type::Syntaxes_type(ITU_T_SHARED(oid_type) arg__abstract,
                ITU_T_SHARED(oid_type) arg__transfer) :
        abstract_(arg__abstract),
        transfer_(arg__transfer) {
        };


        ITU_T_HOLDERH_DEFN(embeded_pdv::Identification_type::Syntaxes_type::abstract, abstract, oid_type);
        ITU_T_HOLDERH_DEFN(embeded_pdv::Identification_type::Syntaxes_type::transfer, transfer, oid_type);

        embeded_pdv::Identification_type::Context_negotiation_type::Context_negotiation_type() : presentation_context_id_(), transfer_syntax_() {
        };

        embeded_pdv::Identification_type::Context_negotiation_type::Context_negotiation_type(const integer_type& arg__presentation_context_id,
                const oid_type& arg__transfer_syntax) :
        presentation_context_id_(arg__presentation_context_id),
        transfer_syntax_(arg__transfer_syntax) {
        };

        embeded_pdv::Identification_type::Context_negotiation_type::Context_negotiation_type(ITU_T_SHARED(integer_type) arg__presentation_context_id,
                ITU_T_SHARED(oid_type) arg__transfer_syntax) :
        presentation_context_id_(arg__presentation_context_id),
        transfer_syntax_(arg__transfer_syntax) {
        };


        ITU_T_HOLDERH_DEFN(embeded_pdv::Identification_type::Context_negotiation_type::presentation_context_id, presentation_context_id, integer_type);
        ITU_T_HOLDERH_DEFN(embeded_pdv::Identification_type::Context_negotiation_type::transfer_syntax, transfer_syntax, oid_type);


        ITU_T_CHOICEC_DEFN(embeded_pdv::Identification_type::syntaxes, syntaxes, embeded_pdv::Identification_type::Syntaxes_type, Identification_type_syntaxes);
        ITU_T_CHOICES_DEFN(embeded_pdv::Identification_type::syntax, syntax, oid_type, Identification_type_syntax);
        ITU_T_CHOICES_DEFN(embeded_pdv::Identification_type::presentation_context_id, presentation_context_id, integer_type, Identification_type_presentation_context_id);
        ITU_T_CHOICEC_DEFN(embeded_pdv::Identification_type::context_negotiation, context_negotiation, embeded_pdv::Identification_type::Context_negotiation_type, Identification_type_context_negotiation);
        ITU_T_CHOICES_DEFN(embeded_pdv::Identification_type::transfer_syntax, transfer_syntax, oid_type, Identification_type_transfer_syntax);
        ITU_T_CHOICES_DEFN(embeded_pdv::Identification_type::fixed, fixed, null_type, Identification_type_fixed);


        ITU_T_HOLDERH_DEFN(embeded_pdv::identification, identification, embeded_pdv::Identification_type);
        ITU_T_HOLDERH_DEFN(embeded_pdv::data_value, data_value, octet_string);



        //character_string

        character_string::character_string() : identification_(), data_value_() {
        };

        character_string::character_string(const Identification_type& arg__identification,
                const octet_string& arg__data_value) :
        identification_(arg__identification),
        data_value_(arg__data_value) {
        };

        character_string::character_string(ITU_T_SHARED(Identification_type) arg__identification,
                ITU_T_SHARED(octet_string) arg__data_value) :
        identification_(arg__identification),
        data_value_(arg__data_value) {
        };

        character_string::Identification_type::Syntaxes_type::Syntaxes_type() : abstract_(), transfer_() {
        };

        character_string::Identification_type::Syntaxes_type::Syntaxes_type(const oid_type& arg__abstract,
                const oid_type& arg__transfer) :
        abstract_(arg__abstract),
        transfer_(arg__transfer) {
        };

        character_string::Identification_type::Syntaxes_type::Syntaxes_type(ITU_T_SHARED(oid_type) arg__abstract,
                ITU_T_SHARED(oid_type) arg__transfer) :
        abstract_(arg__abstract),
        transfer_(arg__transfer) {
        };


        ITU_T_HOLDERH_DEFN(character_string::Identification_type::Syntaxes_type::abstract, abstract, oid_type);
        ITU_T_HOLDERH_DEFN(character_string::Identification_type::Syntaxes_type::transfer, transfer, oid_type);

        character_string::Identification_type::Context_negotiation_type::Context_negotiation_type() : presentation_context_id_(), transfer_syntax_() {
        };

        character_string::Identification_type::Context_negotiation_type::Context_negotiation_type(const integer_type& arg__presentation_context_id,
                const oid_type& arg__transfer_syntax) :
        presentation_context_id_(arg__presentation_context_id),
        transfer_syntax_(arg__transfer_syntax) {
        };

        character_string::Identification_type::Context_negotiation_type::Context_negotiation_type(ITU_T_SHARED(integer_type) arg__presentation_context_id,
                ITU_T_SHARED(oid_type) arg__transfer_syntax) :
        presentation_context_id_(arg__presentation_context_id),
        transfer_syntax_(arg__transfer_syntax) {
        };


        ITU_T_HOLDERH_DEFN(character_string::Identification_type::Context_negotiation_type::presentation_context_id, presentation_context_id, integer_type);
        ITU_T_HOLDERH_DEFN(character_string::Identification_type::Context_negotiation_type::transfer_syntax, transfer_syntax, oid_type);


        ITU_T_CHOICEC_DEFN(character_string::Identification_type::syntaxes, syntaxes, character_string::Identification_type::Syntaxes_type, Identification_type_syntaxes);
        ITU_T_CHOICES_DEFN(character_string::Identification_type::syntax, syntax, oid_type, Identification_type_syntax);
        ITU_T_CHOICES_DEFN(character_string::Identification_type::presentation_context_id, presentation_context_id, integer_type, Identification_type_presentation_context_id);
        ITU_T_CHOICEC_DEFN(character_string::Identification_type::context_negotiation, context_negotiation, character_string::Identification_type::Context_negotiation_type, Identification_type_context_negotiation);
        ITU_T_CHOICES_DEFN(character_string::Identification_type::transfer_syntax, transfer_syntax, oid_type, Identification_type_transfer_syntax);
        ITU_T_CHOICES_DEFN(character_string::Identification_type::fixed, fixed, null_type, Identification_type_fixed);


        ITU_T_HOLDERH_DEFN(character_string::identification, identification, character_string::Identification_type);
        ITU_T_HOLDERH_DEFN(character_string::data_value, data_value, octet_string);


    }
}

