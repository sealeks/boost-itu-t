/* 
 * File:   mmssocket.cpp
 * Author: sealeks@mail.ru
 * 
 * Created on 27 Февраль 2013 г., 22:26
 */

#include "mmssocket.h"

namespace prot9506 {

    const boost::posix_time::ptime mmsepoch_time = boost::posix_time::ptime(boost::gregorian::date(1970, 1, 1));
    const boost::posix_time::ptime tofdepoch_time = boost::posix_time::ptime(boost::gregorian::date(1984, 1, 1));


    const boost::array<boost::asn1::oidindx_type, 5 > MMS_ARR = {1, 0, 9506, 2, 1};
    const boost::asn1::oid_type MMS_OID = boost::asn1::oid_type(MMS_ARR);

    const boost::array<boost::asn1::oidindx_type, 5 > MMSA_ARR = {1, 0, 9506, 2, 3};
    const boost::asn1::oid_type MMSA_OID = boost::asn1::oid_type(MMSA_ARR);

    const presentation_context MMS_CONTEXT_arr[] = {presentation_context(MMS_OID)};
    const presentation_context_set MMS_CONTEXT = presentation_context_set(MMS_CONTEXT_arr, MMS_CONTEXT_arr + 1);
    const application_context MMS_APPLICATION_CONTEXT = application_context(MMSA_OID, MMS_CONTEXT);

    const service_option_type& MMS_SERVICE_OPTOION_DFLT() {
        static service_option_type vl = MMSO::serviceSupportOptions_status | MMSO::serviceSupportOptions_getNameList | MMSO::serviceSupportOptions_identify | MMSO::serviceSupportOptions_read | MMSO::serviceSupportOptions_write |
                MMSO::serviceSupportOptions_rename | MMSO::serviceSupportOptions_deleteNamedVariableList | MMSO::serviceSupportOptions_getVariableAccessAttributes | MMSO::serviceSupportOptions_informationReport;
        return vl;
    }

    const parameter_option_type& MMS_CBB_OPTION_DFLT() {
        static parameter_option_type vl = MMSO::parameterSupportOptions_str1 | MMSO::parameterSupportOptions_str2 | MMSO::parameterSupportOptions_valt | MMSO::parameterSupportOptions_valt |
                MMSO::parameterSupportOptions_vnam | MMSO::parameterSupportOptions_vadr | MMSO::parameterSupportOptions_tpy | MMSO::parameterSupportOptions_vlis;
        return vl;
    }




    //////////////////////////////////////////////////////////////////////////
    ///  protocol_option
    //////////////////////////////////////////////////////////////////////////    

    protocol_option::protocol_option() : asel_(NULL_APPLICATION_SELECTOR),
    acontext_(MMS_APPLICATION_CONTEXT),
    service_(MMS_SERVICE_OPTOION_DFLT()),
    parameter_(MMS_CBB_OPTION_DFLT()),
    localdetail_(30000),
    maxcalling_(1),
    maxcalled_(5),
    nested_(5),
    version_(DEFAULT_MMS_VER),
    exservice_(),
    exparameter_(),
    privilege_() {
    }

    protocol_option::protocol_option(const application_selector& asel,
            const service_option_type& _service,
            const parameter_option_type& _parameter,
            boost::uint32_t _localdetail,
            boost::uint32_t _maxcalling,
            boost::uint32_t _maxcalled,
            boost::uint32_t _nested,
            boost::uint32_t _version,
            const exservice_option_type& _exservice,
            const exparameter_option_type& _exparameter,
            const privilege_type& _privilege
            ) : asel_(asel),
    acontext_(MMS_APPLICATION_CONTEXT),
    service_(_service),
    parameter_(_parameter),
    localdetail_(_localdetail),
    maxcalling_(_maxcalling),
    maxcalled_(_maxcalled),
    nested_(_nested),
    version_(_version),
    exservice_(_exservice),
    exparameter_(_exparameter),
    privilege_(_privilege) {
    }

    protocol_option::protocol_option(const std::string& asel,
            const service_option_type& _service,
            const parameter_option_type& _parameter,
            boost::uint32_t _localdetail,
            boost::uint32_t _maxcalling,
            boost::uint32_t _maxcalled,
            boost::uint32_t _nested,
            boost::uint32_t _version,
            const exservice_option_type& _exservice,
            const exparameter_option_type& _exparameter,
            const privilege_type& _privilege
            ) : asel_(asel),
    acontext_(MMS_APPLICATION_CONTEXT),
    service_(_service),
    parameter_(_parameter),
    localdetail_(_localdetail),
    maxcalling_(_maxcalling),
    maxcalled_(_maxcalled),
    nested_(_nested),
    version_(_version),
    exservice_(_exservice),
    exparameter_(_exparameter),
    privilege_(_privilege) {
    }

    protocol_option::protocol_option(const service_option_type& _service,
            const parameter_option_type& _parameter,
            boost::uint32_t _localdetail,
            boost::uint32_t _maxcalling,
            boost::uint32_t _maxcalled,
            boost::uint32_t _nested,
            boost::uint32_t _version,
            const exservice_option_type& _exservice,
            const exparameter_option_type& _exparameter,
            const privilege_type& _privilege
            ) : asel_(NULL_APPLICATION_SELECTOR),
    acontext_(MMS_APPLICATION_CONTEXT),
    service_(_service),
    parameter_(_parameter),
    localdetail_(_localdetail),
    maxcalling_(_maxcalling),
    maxcalled_(_maxcalled),
    nested_(_nested),
    version_(_version),
    exservice_(_exservice),
    exparameter_(_exparameter),
    privilege_(_privilege) {
    }




    //////////////////////////////////////////////////////////////////////////
    ///  mms_socket
    //////////////////////////////////////////////////////////////////////////

    mms_socket::mms_socket(boost::asio::io_service& io_service,
            const protocol_option& protopt)
    : super_type(io_service, protopt.acontext(), protopt.aselector()), invoke_id_(0), mmsoption_(protopt) {
    }

    mms_socket::mms_socket(boost::asio::io_service& io_service,
            const endpoint_type& endpoint,
            const protocol_option& protopt)
    : super_type(io_service, endpoint, protopt.acontext(), protopt.aselector()), invoke_id_(0), mmsoption_(protopt) {
    }

    void mms_socket::assign_informationreport_listener(informationreport_listner_ptr vl) {
        informationreportlistener_ = vl;
    }

    boost::system::error_code mms_socket::init_request() {

        mmsdcs_ = dcs()->context(MMS_OID);


        if (!mmsdcs_ || !mmsdcs_->valid())
            return boost::itu::ER_PROTOCOL;

        MMS::MMSpdu mms;
        mms.initiate_RequestPDU__new();
        MMS::Initiate_RequestPDU& initpdu = *mms.initiate_RequestPDU();

        initpdu.localDetailCalling(mmsoption_.localdetail());
        initpdu.proposedMaxServOutstandingCalling(mmsoption_.maxcalling());
        initpdu.proposedMaxServOutstandingCalled(mmsoption_.maxcalled());
        initpdu.proposedDataStructureNestingLevel(mmsoption_.nested());
        initpdu.initRequestDetail().proposedVersionNumber(mmsoption_.version());
        initpdu.initRequestDetail().servicesSupportedCalling(mmsoption_.service());
        initpdu.initRequestDetail().proposedParameterCBB(mmsoption_.parameter());
        /*if (!mmsoption_.exparameter().empty())
            initpdu.initRequestDetail().additionalCbbSupportedCalled(mmsoption_.exparameter());
        if (!mmsoption_.exservice().empty())
            initpdu.initRequestDetail().additionalSupportedCalled(mmsoption_.exservice()); */

        mmsdcs()->set(mms);

        return boost::system::error_code();

    }

    boost::system::error_code mms_socket::init_response() {
        try {



            if (!mmsdcs() || !mmsdcs()->valid())
                return boost::itu::ER_PROTOCOL;

            MMS::MMSpdu mms;
            mmsdcs()->get(mms);
            switch (mms.type()) {
                case MMS::MMSpdu_initiate_ResponsePDU:
                {
                    const MMS::Initiate_ResponsePDU& mmsresp = *mms.initiate_ResponsePDU();
                    mmsoption(mmsresp);
                    //mmsresp.
                    return boost::system::error_code();
                }
                default:
                {
                    return boost::itu::ER_REFUSE;
                }
            }

            return boost::itu::ER_PROTOCOL;

        } catch (const boost::system::system_error& cerr) {
            return cerr.code();
        } catch (...) {
        }
        return boost::itu::ER_NAADDRESS;
    }

    void mms_socket::mmsoption(const Initiate_ResponsePDU& opt) {
        if (opt.localDetailCalled())
            mmsoption_.localdetail(*(opt.localDetailCalled()));
        if (opt.negotiatedDataStructureNestingLevel())
            mmsoption_.nested(*(opt.negotiatedDataStructureNestingLevel()));
        mmsoption_.maxcalling(opt.negotiatedMaxServOutstandingCalling());
        mmsoption_.maxcalled(opt.negotiatedMaxServOutstandingCalled());
        mmsoption_.version(opt.initResponseDetail().negotiatedVersionNumber());
        mmsoption_.parameter(opt.initResponseDetail().negotiatedParameterCBB());
        mmsoption_.service(opt.initResponseDetail().servicesSupportedCalled());
        if (opt.initResponseDetail().additionalSupportedCalled())
            mmsoption_.exservice(*(opt.initResponseDetail().additionalSupportedCalled()));
        if (opt.initResponseDetail().additionalSupportedCalled())
            mmsoption_.exservice(*(opt.initResponseDetail().additionalCbbSupportedCalled()));
        if (opt.initResponseDetail().privilegeClassIdentityCalled())
            mmsoption_.privilege(*(opt.initResponseDetail().privilegeClassIdentityCalled()));
    }

    void mms_socket::information_report(const MMS::Unconfirmed_PDU& val) {
        if (informationreportlistener_) {
            informationreportlistener_->operator ()(val);
        }
    }

    const protocol_option & mms_socket::mmsoption() const {
        return mmsoption_;
    }

    void mms_socket::aselector(const std::string& vl) {
        mmsoption_.aselector(boost::itu::application_selector(vl));
    }

    protocol_option & mms_socket::mmsoption() {
        return mmsoption_;
    }

    mms_socket::application_context_ptr mms_socket::mmsdcs() {
        return mmsdcs_;
    }

    mms_socket::application_context_ptr mms_socket::mmsdcs() const {
        return mmsdcs_;
    }

    invoke_id_type mms_socket::invoke_id() {
        if (invoke_id_ < MAXINVOKEID)
            return ++invoke_id_;
        return invoke_id_ = 1;
    }

    /////////////////////////////////////////////////////

    socket_acceptor::socket_acceptor(boost::asio::io_service& io_service)
    : super_type(io_service, MMS_APPLICATION_CONTEXT) {
    }

    socket_acceptor::socket_acceptor(boost::asio::io_service& io_service,
            const endpoint_type& endpoint, bool reuse_addr)
    : super_type(io_service, endpoint, MMS_APPLICATION_CONTEXT) {
    }

    double from_mmsfloat(const MMS::FloatingPoint& vlt) {
        std::size_t sz = vlt.size();
        if (sz) {
#ifdef BIG_ENDIAN_ARCHITECTURE
            const MMS::FloatingPoint& vl = vlt;
#else
            MMS::FloatingPoint vl;
            vl.push_back(vlt[0]);
            std::reverse_copy(++vlt.begin(), vlt.end(), std::back_inserter<MMS::FloatingPoint>(vl));
#endif            
            std::size_t esz = static_cast<std::size_t> (vl[0]);
            if ((sz == 5) && (esz == 8))
                return *reinterpret_cast<const float*> (&vl[1]);
            else if ((sz == 9) && (esz == 11))
                return *reinterpret_cast<const double*> (&vl[1]);
            else if ((sz == 17) && (esz == 15))
                return *reinterpret_cast<const long double*> (&vl[1]);
        }
        return std::numeric_limits<double>::quiet_NaN();
    }

    MMS::FloatingPoint to_mmsfloat(const float& vl) {
#ifdef BIG_ENDIAN_ARCHITECTURE        
        MMS::FloatingPoint tmp;
        tmp.push_back('\x8');
        tmp.insert(tmp.end(), (const char*) (&vl), (const char*) (&vl) + 4);
#else
        MMS::FloatingPoint tmp;
        MMS::FloatingPoint tmpT;
        tmp.push_back('\x8');
        tmpT.insert(tmpT.end(), (const char*) (&vl), (const char*) (&vl) + 4);
        tmp.insert(tmp.end(), tmpT.rbegin(), tmpT.rend());
#endif          
        return tmp;
    }

    MMS::FloatingPoint to_mmsfloat(const double& vl) {
#ifdef BIG_ENDIAN_ARCHITECTURE        
        MMS::FloatingPoint tmp;
        tmp.push_back('\xB');
        tmp.insert(tmp.end(), (const char*) (&vl), (const char*) (&vl) + 8);
#else
        MMS::FloatingPoint tmp;
        MMS::FloatingPoint tmpT;
        tmp.push_back('\xB');
        tmpT.insert(tmpT.end(), (const char*) (&vl), (const char*) (&vl) + 8);
        tmp.insert(tmp.end(), tmpT.rbegin(), tmpT.rend());
#endif          
        return tmp;
    }

    MMS::FloatingPoint to_mmsfloat(const long double& vl) {
#ifdef BIG_ENDIAN_ARCHITECTURE        
        MMS::FloatingPoint tmp;
        tmp.push_back('\xF');
        tmp.insert(tmp.end(), (const char*) (&vl), (const char*) (&vl) + 16);
#else
        MMS::FloatingPoint tmp;
        MMS::FloatingPoint tmpT;
        tmp.push_back('\xF');
        tmpT.insert(tmpT.end(), (const char*) (&vl), (const char*) (&vl) + 16);
        tmp.insert(tmp.end(), tmpT.rbegin(), tmpT.rend());
#endif          
        return tmp;
    }

    boost::posix_time::ptime from_mms_datetime(const MMS::TimeOfDay& vlt) {
        try {
            if ((vlt.size() == 6) || (vlt.size() == 4)) {
#ifdef BIG_ENDIAN_ARCHITECTUREs
                const boost::asn1::octetstring_type& vl = vlt;
#else
                MMS::TimeOfDay vl;
                std::reverse_copy(vlt.begin(), vlt.end(), std::back_inserter<MMS::TimeOfDay>(vl));
#endif       
                boost::uint16_t dval = 0;
                boost::uint32_t msval = *reinterpret_cast<boost::uint32_t*> (&vl[0]);
                if (vlt.size() == 6)
                    dval = *reinterpret_cast<boost::uint16_t*> (&vl[4]);
                return tofdepoch_time + boost::gregorian::days(dval) + boost::posix_time::time_duration(0, 0, msval / 1000)
                        + boost::posix_time::millisec(msval % 1000);
                ;
            }
        } catch (...) {

        }
        return boost::posix_time::ptime();
    };

    MMS::TimeOfDay to_mms_datetime(const boost::posix_time::ptime& vl) {
        if (!vl.is_special()) {
            boost::gregorian::date_period tday(tofdepoch_time.date(), vl.date());
            boost::uint16_t dval = static_cast<uint16_t> (tday.length().days());
            boost::uint32_t tval = static_cast<uint32_t> (vl.time_of_day().fractional_seconds());
            MMS::TimeOfDay tmpT;
            tmpT.insert(tmpT.end(), (const char*) (&tval), (const char*) (&tval) + 4);
            tmpT.insert(tmpT.end(), (const char*) (&dval), (const char*) (&dval) + 2);
#ifndef BIG_ENDIAN_ARCHITECTURE
            MMS::TimeOfDay tmpR;
            std::reverse_copy(tmpT.begin(), tmpT.end(), std::back_inserter<boost::asn1::octetstring_type>(tmpR));
            return tmpR;
#else
            return tmpT;
#endif               
        }
        return MMS::TimeOfDay();
    }

    boost::posix_time::ptime from_mms_utctime(const boost::asn1::octetstring_type& vlt) {
        try {
            if (vlt.size() == 8) {
#ifdef BIG_ENDIAN_ARCHITECTURE
                const boost::asn1::octetstring_type& vl = vlt;
#else
                boost::asn1::octetstring_type vl;
                std::reverse_copy(vlt.begin(), vlt.end(), std::back_inserter<boost::asn1::octetstring_type>(vl));
#endif       
                boost::uint32_t fval = *reinterpret_cast<boost::uint32_t*> (&vl[0]);
                boost::uint64_t mcsec = (500000UL * static_cast<boost::uint64_t> (fval)) / 0x7FFFFFFFUL;
                boost::uint32_t tval = *reinterpret_cast<boost::uint32_t*> (&vl[4]);
                return mmsepoch_time + boost::posix_time::time_duration(0, 0, tval)
                        + boost::posix_time::microsec(mcsec);
            }
        } catch (...) {

        }
        return boost::posix_time::ptime();
    }

    boost::asn1::octetstring_type to_mms_utctime(const boost::posix_time::ptime & vl) {
        if (!vl.is_special()) {
            boost::posix_time::time_period td(mmsepoch_time, vl);
            boost::uint32_t tval = td.length().seconds();
            boost::uint64_t mcsec = (static_cast<boost::uint64_t> (vl.time_of_day().fractional_seconds())
                    * 0x7FFFFFFFUL) / 500000UL;
            boost::uint32_t fval = static_cast<boost::uint32_t> (mcsec);
            boost::asn1::octetstring_type tmpT;
            tmpT.insert(tmpT.end(), (const char*) (&fval), (const char*) (&fval) + 4);
            tmpT.insert(tmpT.end(), (const char*) (&tval), (const char*) (&tval) + 4);
#ifndef BIG_ENDIAN_ARCHITECTURE
            boost::asn1::octetstring_type tmpR;
            std::reverse_copy(tmpT.begin(), tmpT.end(), std::back_inserter<boost::asn1::octetstring_type>(tmpR));
            return tmpR;
#else
            return tmpT;
#endif   
        }
        return boost::asn1::octetstring_type();
    }

}
