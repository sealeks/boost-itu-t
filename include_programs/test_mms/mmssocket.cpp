/* 
 * File:   mmssocket.cpp
 * Author: sealeks@mail.ru
 * 
 * Created on 27 Февраль 2013 г., 22:26
 */

#include "mmssocket.h"

namespace prot9506 {




    const MMS::ServiceSupportOptions MMS_SERVICE_OPTOION_SUPPORT = MMSO::ServiceSupportOptions_status | MMSO::ServiceSupportOptions_getNameList | MMSO::ServiceSupportOptions_identify | MMSO::ServiceSupportOptions_read | MMSO::ServiceSupportOptions_write |
            MMSO::ServiceSupportOptions_rename | MMSO::ServiceSupportOptions_deleteNamedVariableList | MMSO::ServiceSupportOptions_getVariableAccessAttributes | MMSO::ServiceSupportOptions_informationReport;
    const MMS::ParameterSupportOptions MMS_CBB_OPTION_SUPPORT = MMSO::ParameterSupportOptions_str1 | MMSO::ParameterSupportOptions_str2 | MMSO::ParameterSupportOptions_valt | MMSO::ParameterSupportOptions_valt |
            MMSO::ParameterSupportOptions_vnam | MMSO::ParameterSupportOptions_vadr | MMSO::ParameterSupportOptions_tpy | MMSO::ParameterSupportOptions_vlis;

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

        initpdu.localDetailCalling(MMS::Integer32(30000));
        initpdu.proposedMaxServOutstandingCalling(MMS::Integer16(1));
        initpdu.proposedMaxServOutstandingCalled(MMS::Integer16(5));
        initpdu.proposedDataStructureNestingLevel(new MMS::Integer8(5));
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
