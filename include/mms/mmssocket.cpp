/* 
 * File:   mmssocket.cpp
 * Author: sealeks@mail.ru
 * 
 * Created on 27 Февраль 2013 г., 22:26
 */

#include "mmssocket.h"

namespace prot9506 {


    const boost::array<boost::asn1::oidindx_type, 5 > MMS_ARR = {1, 0, 9506, 2, 1};
    const boost::asn1::oid_type MMS_OID = boost::asn1::oid_type(MMS_ARR);

    const boost::array<boost::asn1::oidindx_type, 5 > MMSA_ARR = {1, 0, 9506, 2, 3};
    const boost::asn1::oid_type MMSA_OID = boost::asn1::oid_type(MMSA_ARR);

    const presentation_context MMS_CONTEXT_arr[] = {presentation_context(MMS_OID)};
    const presentation_context_set MMS_CONTEXT = presentation_context_set(MMS_CONTEXT_arr, MMS_CONTEXT_arr + 1);
    const application_context MMS_APPLICATION_CONTEXT = application_context(MMSA_OID, MMS_CONTEXT);

    const service_option_type MMS_SERVICE_OPTOION_DFLT = MMSO::serviceSupportOptions_status | MMSO::serviceSupportOptions_getNameList | MMSO::serviceSupportOptions_identify | MMSO::serviceSupportOptions_read | MMSO::serviceSupportOptions_write |
            MMSO::serviceSupportOptions_rename | MMSO::serviceSupportOptions_deleteNamedVariableList | MMSO::serviceSupportOptions_getVariableAccessAttributes | MMSO::serviceSupportOptions_informationReport;
    const parameter_option_type MMS_CBB_OPTION_DFLT = MMSO::parameterSupportOptions_str1 | MMSO::parameterSupportOptions_str2 | MMSO::parameterSupportOptions_valt | MMSO::parameterSupportOptions_valt |
            MMSO::parameterSupportOptions_vnam | MMSO::parameterSupportOptions_vadr | MMSO::parameterSupportOptions_tpy | MMSO::parameterSupportOptions_vlis;




    //////////////////////////////////////////////////////////////////////////
    ///  protocol_option
    //////////////////////////////////////////////////////////////////////////    

    protocol_option::protocol_option() : asel_(NULL_APPLICATION_SELECTOR),
    acontext_(MMS_APPLICATION_CONTEXT),
    service_(MMS_SERVICE_OPTOION_DFLT),
    parameter_(MMS_CBB_OPTION_DFLT),
    localdetail_(30000),
    maxcalling_(1),
    maxcalled_(5),
    nested_(5),
    version_(DEFAULT_MMS_VER),
    exservice_(),
    exparameter_(),
    privilege_(){
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
    privilege_(_privilege){
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
     privilege_(_privilege){
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
    privilege_(_privilege){
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
        std::cout << "server negotiate option"  << std::endl;
        if (opt.localDetailCalled()) {
            std::cout << "localDetailCalled : " << (*(opt.localDetailCalled())) << std::endl;
            mmsoption_.localdetail(*(opt.localDetailCalled()));
        }
        if (opt.negotiatedDataStructureNestingLevel()) {
            std::cout << "NestingLevel : " << (*(opt.negotiatedDataStructureNestingLevel())) << std::endl;
            mmsoption_.nested(*(opt.negotiatedDataStructureNestingLevel()));
        }        
        std::cout << "MaxServOutstandingCalling : " << (opt.negotiatedMaxServOutstandingCalling()) << std::endl;
        mmsoption_.maxcalling(opt.negotiatedMaxServOutstandingCalling());
        std::cout << "MaxServOutstandingCalled : " << (opt.negotiatedMaxServOutstandingCalled()) << std::endl;
        mmsoption_.maxcalled(opt.negotiatedMaxServOutstandingCalled());
        std::cout << "version : " << (opt.initResponseDetail().negotiatedVersionNumber()) << std::endl;
        mmsoption_.version(opt.initResponseDetail().negotiatedVersionNumber());
         std::cout << "parameter : " << (opt.initResponseDetail().negotiatedParameterCBB()) << std::endl;
        mmsoption_.parameter()=opt.initResponseDetail().negotiatedParameterCBB();       
         std::cout << "servicesSupportedCalled : " << (opt.initResponseDetail().servicesSupportedCalled()) << std::endl;
        mmsoption_.service()=opt.initResponseDetail().servicesSupportedCalled();
        if (opt.initResponseDetail().additionalSupportedCalled()) {
            std::cout << "additionalSupportedCalled : " << (*(opt.initResponseDetail().additionalSupportedCalled())) << std::endl;
            mmsoption_.exservice() = *(opt.initResponseDetail().additionalSupportedCalled());
        }
        if (opt.initResponseDetail().additionalSupportedCalled()) {
            std::cout << "additionalCbbSupportedCalled : " << (*(opt.initResponseDetail().additionalCbbSupportedCalled())) << std::endl;
            mmsoption_.exservice() = *(opt.initResponseDetail().additionalCbbSupportedCalled());
        }        
        if (opt.initResponseDetail().privilegeClassIdentityCalled()) {
            std::cout << "privilegeClassIdentityCalled : " << (*(opt.initResponseDetail().privilegeClassIdentityCalled())) << std::endl;
            mmsoption_.privilege() = *(opt.initResponseDetail().privilegeClassIdentityCalled());
        }           
    //    if (mmsoption_.service()=opt.initResponseDetail())

    }

    void mms_socket::information_report(const MMS::Unconfirmed_PDU& val) {
        std::cout << "information_report" << std::endl;
    }

    mms_socket::application_context_ptr mms_socket::mmsdcs() {
        return mmsdcs_;
    }

    mms_socket::application_context_ptr mms_socket::mmsdcs() const {
        return mmsdcs_;
    }

    invoke_id_type mms_socket::invoke_id() {
        return invoke_id_ = ((invoke_id_ < MAXINVOKEID) ? (++invoke_id_) : 1);
    }    

    /////////////////////////////////////////////////////

    socket_acceptor::socket_acceptor(boost::asio::io_service& io_service)
    : super_type(io_service, MMS_APPLICATION_CONTEXT) {
    }

    socket_acceptor::socket_acceptor(boost::asio::io_service& io_service,
            const endpoint_type& endpoint, bool reuse_addr)
    : super_type(io_service, endpoint, MMS_APPLICATION_CONTEXT) {
    }

}
