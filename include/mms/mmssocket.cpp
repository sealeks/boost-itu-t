/* 
 * File:   mmssocket.cpp
 * Author: sealeks@mail.ru
 * 
 * Created on 27 Февраль 2013 г., 22:26
 */

#include "mmssocket.h"

namespace prot9506 {




    const MMS::ServiceSupportOptions MMS_SERVICE_OPTOION_SUPPORT = MMSO::serviceSupportOptions_status | MMSO::serviceSupportOptions_getNameList | MMSO::serviceSupportOptions_identify | MMSO::serviceSupportOptions_read | MMSO::serviceSupportOptions_write |
            MMSO::serviceSupportOptions_rename | MMSO::serviceSupportOptions_deleteNamedVariableList | MMSO::serviceSupportOptions_getVariableAccessAttributes | MMSO::serviceSupportOptions_informationReport;
    const MMS::ParameterSupportOptions MMS_CBB_OPTION_SUPPORT = MMSO::parameterSupportOptions_str1 | MMSO::parameterSupportOptions_str2 | MMSO::parameterSupportOptions_valt | MMSO::parameterSupportOptions_valt |
            MMSO::parameterSupportOptions_vnam | MMSO::parameterSupportOptions_vadr | MMSO::parameterSupportOptions_tpy | MMSO::parameterSupportOptions_vlis;

    //presentation_option init_synaxes() {
    //   return presentation_option( ACSE_1_OID, MMS_OID);
    // }

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
        initpdu.initRequestDetail().proposedVersionNumber (1);
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

        }
        catch (const boost::system::system_error& cerr) {
            return cerr.code();
        }
        catch (...) {
        }
        return boost::itu::ER_NAADDRESS;
    }



}
