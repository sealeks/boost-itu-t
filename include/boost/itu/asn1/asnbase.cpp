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



        // null_type

        std::ostream& operator<<(std::ostream& stream, const null_type& vl) {
            return stream << "NULL TYPE" << std::endl;
        }


        // relative oid type


        // utf8_string

        std::ostream& operator<<(std::ostream& stream, const utf8_string& vl) {
            stream << std::string(vl.begin(), vl.end());
            return stream;
        }


        // universal_string

        std::ostream& operator<<(std::ostream& stream, const universal_string& vl) {
            return stream << vl.operator std::string();
        }



        // bmp_string       

        std::ostream& operator<<(std::ostream& stream, const bmp_string& vl) {
            return stream << vl.operator std::string();
        }



        // time types      

        static utctime to_z_impltime(const std::string& val, const utctime& tm) {
            if (val.empty())
                return tm;
            if (val.size() != 5)
                return utctime();
            switch (val[0]) {
                case '+':
                {
                    return (tm + (boost::posix_time::hours(string_to<int>(val.substr(1, 2))) + boost::posix_time::minutes(string_to<int>(val.substr(3, 2)))));
                }
                case '-':
                {
                    return (tm - (boost::posix_time::hours(string_to<int>(val.substr(1, 2))) + boost::posix_time::minutes(string_to<int>(val.substr(3, 2)))));
                }
            }
            return utctime();
        }

        static octet_sequnce from_impltime(const utctime& val, bool full) {
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

        static utctime to_impl_time(const octet_sequnce& val, bool full) {
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
                        return utctime();

                    if (!full)
                        tmp = ((tmp[0] == '9') || (tmp[0] == '8')) ? ("19" + tmp) : ("20" + tmp);

                    if (tmp.size() < 8)
                        return utctime();

                    utctime rslt(boost::gregorian::date(string_to<int>(tmp.substr(0, 4)), string_to<int>(tmp.substr(4, 2)), string_to<int>(tmp.substr(6, 2))));

                    if (tmp.size() == 8)
                        return zdelt.empty() ? rslt : to_z_impltime(zdelt, rslt);
                    else
                        tmp = tmp.substr(8);

                    if (tmp.size() < 2)
                        return utctime();

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
                            return utctime();
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
                            return utctime();
                    }

                    rslt += boost::posix_time::seconds(string_to<int>(tmp.substr(0, 2)));

                    if (tmp.size() == 2)
                        return zdelt.empty() ? rslt : to_z_impltime(zdelt, rslt);
                    else
                        tmp = tmp.substr(2);

                    if (tmp[0] != '.')
                        return utctime();


                    if (tmp.size() == 1)
                        return zdelt.empty() ? rslt : to_z_impltime(zdelt, rslt);

                    rslt += boost::posix_time::microsec(static_cast<int> (string_to<double>("0" + tmp)*1000000));

                    return zdelt.empty() ? rslt : to_z_impltime(zdelt, rslt);

                } catch (...) {
                }
            }
            return utctime();
        }

        octet_sequnce from_utctime(const utctime& val) {
            return from_impltime(val, false);
        }

        visible_string as_visiblestring(const utctime& val) {
            const octet_sequnce& trslt = from_utctime(val);
            return visible_string(trslt.begin(), trslt.end());
        }

        utctime to_utctime(const octet_sequnce& val) {
            return to_impl_time(val, false);
        }

        utctime to_utctime(const visible_string& val) {
            return to_utctime(as_octet_sequnce(val));
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

        external_type::external_type(shared_ptr< oid_type> arg__direct_reference,
                shared_ptr< int> arg__indirect_reference,
                shared_ptr< object_descriptor> arg__data_value_descriptor,
                shared_ptr< Encoding_type> arg__encoding) :
        direct_reference_(arg__direct_reference),
        indirect_reference_(arg__indirect_reference),
        data_value_descriptor_(arg__data_value_descriptor),
        encoding_(arg__encoding) {
        };

        void external_type::Encoding_type::single_ASN1_type(const any_type& vl) {
            set<any_type>(new any_type(vl), Encoding_type_single_ASN1_type);
        }

        void external_type::Encoding_type::octet_aligned(const octet_string& vl) {
            set<octet_string>(new octet_string(vl), Encoding_type_octet_aligned);
        }

        void external_type::Encoding_type::arbitrary(const bit_string& vl) {
            set<bit_string>(new bit_string(vl), Encoding_type_arbitrary);
        }

        shared_ptr<oid_type> external_type::direct_reference__new() {
            return direct_reference_ = shared_ptr<oid_type>(new oid_type());
        }

        void external_type::direct_reference(const oid_type& vl) {
            direct_reference_ = shared_ptr<oid_type>(new oid_type(vl));
        }

        shared_ptr<int> external_type::indirect_reference__new() {
            return indirect_reference_ = shared_ptr<int>(new int());
        }

        void external_type::indirect_reference(const int& vl) {
            indirect_reference_ = shared_ptr<int>(new int(vl));
        }

        shared_ptr<object_descriptor> external_type::data_value_descriptor__new() {
            return data_value_descriptor_ = shared_ptr<object_descriptor>(new object_descriptor());
        }

        void external_type::data_value_descriptor(const object_descriptor& vl) {
            data_value_descriptor_ = shared_ptr<object_descriptor>(new object_descriptor(vl));
        }

        external_type::Encoding_type& external_type::encoding() {
            return *encoding_;
        }

        const external_type::Encoding_type& external_type::encoding() const {
            return *encoding_;
        }

        void external_type::encoding(const Encoding_type& vl) {
            encoding_ = vl;
        }

        void external_type::encoding(shared_ptr< Encoding_type> vl) {
            encoding_ = vl;
        }




        //embeded_pdv

        embeded_pdv::embeded_pdv() : identification_(), data_value_() {
        };

        embeded_pdv::embeded_pdv(const Identification_type& arg__identification,
                const octet_string& arg__data_value) :
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

        oid_type& embeded_pdv::Identification_type::Syntaxes_type::abstract() {
            return *abstract_;
        }

        const oid_type& embeded_pdv::Identification_type::Syntaxes_type::abstract() const {
            return *abstract_;
        }

        void embeded_pdv::Identification_type::Syntaxes_type::abstract(const oid_type& vl) {
            abstract_ = vl;
        }

        void embeded_pdv::Identification_type::Syntaxes_type::abstract(shared_ptr< oid_type> vl) {
            abstract_ = vl;
        }

        oid_type& embeded_pdv::Identification_type::Syntaxes_type::transfer() {
            return *transfer_;
        }

        const oid_type& embeded_pdv::Identification_type::Syntaxes_type::transfer() const {
            return *transfer_;
        }

        void embeded_pdv::Identification_type::Syntaxes_type::transfer(const oid_type& vl) {
            transfer_ = vl;
        }

        void embeded_pdv::Identification_type::Syntaxes_type::transfer(shared_ptr< oid_type> vl) {
            transfer_ = vl;
        }

        embeded_pdv::Identification_type::Context_negotiation_type::Context_negotiation_type() : presentation_context_id_(), transfer_syntax_() {
        };

        embeded_pdv::Identification_type::Context_negotiation_type::Context_negotiation_type(const int& arg__presentation_context_id,
                const oid_type& arg__transfer_syntax) :
        presentation_context_id_(arg__presentation_context_id),
        transfer_syntax_(arg__transfer_syntax) {
        };

        int& embeded_pdv::Identification_type::Context_negotiation_type::presentation_context_id() {
            return *presentation_context_id_;
        }

        const int& embeded_pdv::Identification_type::Context_negotiation_type::presentation_context_id() const {
            return *presentation_context_id_;
        }

        void embeded_pdv::Identification_type::Context_negotiation_type::presentation_context_id(const int& vl) {
            presentation_context_id_ = vl;
        }

        void embeded_pdv::Identification_type::Context_negotiation_type::presentation_context_id(shared_ptr< int> vl) {
            presentation_context_id_ = vl;
        }

        oid_type& embeded_pdv::Identification_type::Context_negotiation_type::transfer_syntax() {
            return *transfer_syntax_;
        }

        const oid_type& embeded_pdv::Identification_type::Context_negotiation_type::transfer_syntax() const {
            return *transfer_syntax_;
        }

        void embeded_pdv::Identification_type::Context_negotiation_type::transfer_syntax(const oid_type& vl) {
            transfer_syntax_ = vl;
        }

        void embeded_pdv::Identification_type::Context_negotiation_type::transfer_syntax(shared_ptr< oid_type> vl) {
            transfer_syntax_ = vl;
        }

        void embeded_pdv::Identification_type::syntax(const oid_type& vl) {
            set<oid_type>(new oid_type(vl), Identification_type_syntax);
        }

        void embeded_pdv::Identification_type::presentation_context_id(const int& vl) {
            set<int>(new int(vl), Identification_type_presentation_context_id);
        }

        void embeded_pdv::Identification_type::transfer_syntax(const oid_type& vl) {
            set<oid_type>(new oid_type(vl), Identification_type_transfer_syntax);
        }

        void embeded_pdv::Identification_type::fixed(const null_type& vl) {
            set<null_type>(new null_type(vl), Identification_type_fixed);
        }

        embeded_pdv::Identification_type& embeded_pdv::identification() {
            return *identification_;
        }

        const embeded_pdv::Identification_type& embeded_pdv::identification() const {
            return *identification_;
        }

        void embeded_pdv::identification(const Identification_type& vl) {
            identification_ = vl;
        }

        void embeded_pdv::identification(shared_ptr< Identification_type> vl) {
            identification_ = vl;
        }

        octet_string& embeded_pdv::data_value() {
            return *data_value_;
        }

        const octet_string& embeded_pdv::data_value() const {
            return *data_value_;
        }

        void embeded_pdv::data_value(const octet_string& vl) {
            data_value_ = vl;
        }

        void embeded_pdv::data_value(shared_ptr< octet_string> vl) {
            data_value_ = vl;
        }


        //character_string

        character_string::character_string() : identification_(), string_value_() {
        };

        character_string::character_string(const Identification_type& arg__identification,
                const octet_string& arg__string_value) :
        identification_(arg__identification),
        string_value_(arg__string_value) {
        };

        character_string::Identification_type::Syntaxes_type::Syntaxes_type() : abstract_(), transfer_() {
        };

        character_string::Identification_type::Syntaxes_type::Syntaxes_type(const oid_type& arg__abstract,
                const oid_type& arg__transfer) :
        abstract_(arg__abstract),
        transfer_(arg__transfer) {
        };

        oid_type& character_string::Identification_type::Syntaxes_type::abstract() {
            return *abstract_;
        }

        const oid_type& character_string::Identification_type::Syntaxes_type::abstract() const {
            return *abstract_;
        }

        void character_string::Identification_type::Syntaxes_type::abstract(const oid_type& vl) {
            abstract_ = vl;
        }

        void character_string::Identification_type::Syntaxes_type::abstract(shared_ptr< oid_type> vl) {
            abstract_ = vl;
        }

        oid_type& character_string::Identification_type::Syntaxes_type::transfer() {
            return *transfer_;
        }

        const oid_type& character_string::Identification_type::Syntaxes_type::transfer() const {
            return *transfer_;
        }

        void character_string::Identification_type::Syntaxes_type::transfer(const oid_type& vl) {
            transfer_ = vl;
        }

        void character_string::Identification_type::Syntaxes_type::transfer(shared_ptr< oid_type> vl) {
            transfer_ = vl;
        }

        character_string::Identification_type::Context_negotiation_type::Context_negotiation_type() : presentation_context_id_(), transfer_syntax_() {
        };

        character_string::Identification_type::Context_negotiation_type::Context_negotiation_type(const int& arg__presentation_context_id,
                const oid_type& arg__transfer_syntax) :
        presentation_context_id_(arg__presentation_context_id),
        transfer_syntax_(arg__transfer_syntax) {
        };

        int& character_string::Identification_type::Context_negotiation_type::presentation_context_id() {
            return *presentation_context_id_;
        }

        const int& character_string::Identification_type::Context_negotiation_type::presentation_context_id() const {
            return *presentation_context_id_;
        }

        void character_string::Identification_type::Context_negotiation_type::presentation_context_id(const int& vl) {
            presentation_context_id_ = vl;
        }

        void character_string::Identification_type::Context_negotiation_type::presentation_context_id(shared_ptr< int> vl) {
            presentation_context_id_ = vl;
        }

        oid_type& character_string::Identification_type::Context_negotiation_type::transfer_syntax() {
            return *transfer_syntax_;
        }

        const oid_type& character_string::Identification_type::Context_negotiation_type::transfer_syntax() const {
            return *transfer_syntax_;
        }

        void character_string::Identification_type::Context_negotiation_type::transfer_syntax(const oid_type& vl) {
            transfer_syntax_ = vl;
        }

        void character_string::Identification_type::Context_negotiation_type::transfer_syntax(shared_ptr< oid_type> vl) {
            transfer_syntax_ = vl;
        }

        void character_string::Identification_type::syntax(const oid_type& vl) {
            set<oid_type>(new oid_type(vl), Identification_type_syntax);
        }

        void character_string::Identification_type::presentation_context_id(const int& vl) {
            set<int>(new int(vl), Identification_type_presentation_context_id);
        }

        void character_string::Identification_type::transfer_syntax(const oid_type& vl) {
            set<oid_type>(new oid_type(vl), Identification_type_transfer_syntax);
        }

        void character_string::Identification_type::fixed(const null_type& vl) {
            set<null_type>(new null_type(vl), Identification_type_fixed);
        }

        character_string::Identification_type& character_string::identification() {
            return *identification_;
        }

        const character_string::Identification_type& character_string::identification() const {
            return *identification_;
        }

        void character_string::identification(const Identification_type& vl) {
            identification_ = vl;
        }

        void character_string::identification(shared_ptr< Identification_type> vl) {
            identification_ = vl;
        }

        octet_string& character_string::string_value() {
            return *string_value_;
        }

        const octet_string& character_string::string_value() const {
            return *string_value_;
        }

        void character_string::string_value(const octet_string& vl) {
            string_value_ = vl;
        }

        void character_string::string_value(shared_ptr< octet_string> vl) {
            string_value_ = vl;
        }

    }
}

