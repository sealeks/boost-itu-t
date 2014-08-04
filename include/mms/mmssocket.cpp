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

    const MMS::ServiceSupportOptions MMS_SERVICE_OPTOION_SUPPORT = MMSO::serviceSupportOptions_status | MMSO::serviceSupportOptions_getNameList | MMSO::serviceSupportOptions_identify | MMSO::serviceSupportOptions_read | MMSO::serviceSupportOptions_write |
            MMSO::serviceSupportOptions_rename | MMSO::serviceSupportOptions_deleteNamedVariableList | MMSO::serviceSupportOptions_getVariableAccessAttributes | MMSO::serviceSupportOptions_informationReport;
    const MMS::ParameterSupportOptions MMS_CBB_OPTION_SUPPORT = MMSO::parameterSupportOptions_str1 | MMSO::parameterSupportOptions_str2 | MMSO::parameterSupportOptions_valt | MMSO::parameterSupportOptions_valt |
            MMSO::parameterSupportOptions_vnam | MMSO::parameterSupportOptions_vadr | MMSO::parameterSupportOptions_tpy | MMSO::parameterSupportOptions_vlis;

    mms_socket::mms_socket(boost::asio::io_service& io_service,
            const application_selector& asel)
    : super_type(io_service, MMS_APPLICATION_CONTEXT, asel), invoke_id_(0) {
    }

    mms_socket::mms_socket(boost::asio::io_service& io_service,
            const endpoint_type& endpoint,
            const application_selector& asel)
    : super_type(io_service, endpoint, MMS_APPLICATION_CONTEXT, asel), invoke_id_(0) {
    }

    boost::system::error_code mms_socket::init_request() {

        mmsdcs_ = dcs()->context(MMS_OID);


        if (!mmsdcs_ || !mmsdcs_->valid())
            return boost::itu::ER_PROTOCOL;

        MMS::MMSpdu mms;
        mms.initiate_RequestPDU__new();
        MMS::Initiate_RequestPDU& initpdu = *mms.initiate_RequestPDU();

        initpdu.localDetailCalling(30000);
        initpdu.proposedMaxServOutstandingCalling(1);
        initpdu.proposedMaxServOutstandingCalled(5);
        initpdu.proposedDataStructureNestingLevel(5);
        initpdu.initRequestDetail().proposedVersionNumber(1);
        initpdu.initRequestDetail().servicesSupportedCalling(MMS_SERVICE_OPTOION_SUPPORT);
        initpdu.initRequestDetail().proposedParameterCBB(MMS_CBB_OPTION_SUPPORT);

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


    /////////////////////////////////////////////////////

    socket_acceptor::socket_acceptor(boost::asio::io_service& io_service)
    : super_type(io_service, MMS_APPLICATION_CONTEXT) {
    }

    socket_acceptor::socket_acceptor(boost::asio::io_service& io_service,
            const endpoint_type& endpoint, bool reuse_addr)
    : super_type(io_service, endpoint, MMS_APPLICATION_CONTEXT) {
    }

}
