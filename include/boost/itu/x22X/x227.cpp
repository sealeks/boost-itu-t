//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x22X/x227.hpp>
#include <boost/itu/x22X/acse/ACSE-1.hpp>


namespace boost {
    namespace itu {

        namespace x227impl {

            namespace ACSE = ACSE_1;

            error_code application_socket::connect_request(error_code& ec) {
                acse_context_ = dcs()->context(ACSE_OID);
                if (!acse_context_)
                    return ec = ER_PROTOCOL;


                ACSE::ACSE_apdu apdu;
                ACSE::AARQ_apdu areq;

                //areq->protocol_version__assign( new application_ver_type(DEFAULT_APPLICATION_VER));
                areq->aSO_context_name = ACSE::ASO_context_name(this->application_contexts().context());

                if (option().called()) {
                    switch (option().called().form()) {
                        case boost::itu::acse_selectorvalue_type::form1:
                        {
                            if (!option().called().ap_title1().empty())
                                areq->called_AP_title__new()->ap_title_form1(new ACSE::AP_title_form1(option().called().ap_title1()));
                            if (!option().called().ae_qualifier1().empty())
                                areq->called_AE_qualifier__new()->aso_qualifier_form1(new ACSE::ASO_qualifier_form1(option().called().ae_qualifier1()));
                            if (option().called().ap_invoke_id())
                                areq->called_AP_invocation_identifier__assign(new ACSE::AP_invocation_identifier(*(option().called().ap_invoke_id())));
                            if (option().called().ae_invoke_id())
                                areq->called_AE_invocation_identifier__assign(new ACSE::AE_invocation_identifier(*(option().called().ae_invoke_id())));
                            break;
                        }
                        case boost::itu::acse_selectorvalue_type::form2:
                        {
                            if (!option().called().ap_title2().empty())
                                areq->called_AP_title__new()->ap_title_form2(new ACSE::AP_title_form2(option().called().ap_title2()));
                            if (option().called().ae_qualifier2())
                                areq->called_AE_qualifier__new()->aso_qualifier_form2(new ACSE::ASO_qualifier_form2(*(option().called().ae_qualifier2())));
                            if (option().called().ap_invoke_id())
                                areq->called_AP_invocation_identifier__assign(new ACSE::AP_invocation_identifier(*(option().called().ap_invoke_id())));
                            if (option().called().ae_invoke_id())
                                areq->called_AE_invocation_identifier__assign(new ACSE::AE_invocation_identifier(*(option().called().ae_invoke_id())));
                            break;
                        }
                        default:
                        {
                        }
                    }
                }


                if (option().calling()) {
                    switch (option().calling().form()) {
                        case boost::itu::acse_selectorvalue_type::form1:
                        {
                            if (!option().calling().ap_title1().empty())
                                areq->calling_AP_title__new()->ap_title_form1(new ACSE::AP_title_form1(option().calling().ap_title1()));
                            if (!option().calling().ae_qualifier1().empty())
                                areq->calling_AE_qualifier__new()->aso_qualifier_form1(new ACSE::ASO_qualifier_form1(option().calling().ae_qualifier1()));
                            if (option().calling().ap_invoke_id())
                                areq->calling_AP_invocation_identifier__assign(new ACSE::AP_invocation_identifier(*(option().calling().ap_invoke_id())));
                            if (option().calling().ae_invoke_id())
                                areq->calling_AE_invocation_identifier__assign(new ACSE::AE_invocation_identifier(*(option().calling().ae_invoke_id())));
                            break;
                        }
                        case boost::itu::acse_selectorvalue_type::form2:
                        {
                            if (!option().calling().ap_title2().empty())
                                areq->calling_AP_title__new()->ap_title_form2(new ACSE::AP_title_form2(option().calling().ap_title2()));
                            if (option().calling().ae_qualifier2())
                                areq->calling_AE_qualifier__new()->aso_qualifier_form2(new ACSE::ASO_qualifier_form2(*(option().calling().ae_qualifier2())));
                            if (option().calling().ap_invoke_id())
                                areq->calling_AP_invocation_identifier__assign(new ACSE::AP_invocation_identifier(*(option().calling().ap_invoke_id())));
                            if (option().calling().ae_invoke_id())
                                areq->calling_AE_invocation_identifier__assign(new ACSE::AE_invocation_identifier(*(option().calling().ae_invoke_id())));
                            break;
                        }
                        default:
                        {
                        }
                    }
                }

                for (defined_context_map::iterator it = dcs()->contexts().begin(); it != dcs()->contexts().end(); ++it) {

                    if ((it->second->abstract_syntax() != ACSE_OID) && (it->second->coder()->out())) {
                        boost::asn1::external_type userdata;
                        userdata.indirect_reference__assign(new context_id_type(it->first));
                        userdata.direct_reference__assign(new boost::asn1::oid_type(to_transfer_syntax(it->second->coder()->rule())));
                        userdata.encoding->single_ASN1_type__new();
                        userdata.encoding->single_ASN1_type()->bind(*(it->second->coder()->out()));
                        it->second->coder()->clear();
                        if (!areq->user_information)
                            areq->user_information__new();
                        areq->user_information->push_back(userdata);
                    }
                }

                apdu.aarq(new ACSE::AARQ_apdu(areq));
                acse_context_->set(apdu);
                return ec;
            }

            error_code application_socket::connect_response(error_code& ec) {
                try {

                    if (!acse_context() || !acse_context()->valid())
                        return ec = ER_PROTOCOL;

                    ACSE::ACSE_apdu apdu;

                    acse_context()->get(apdu);

                    switch (apdu.type()) {
                        case ACSE::ACSE_apdu_aare:
                        {
                            const ACSE::AARE_apdu& aresp = *apdu.aare();
                            if (aresp->user_information) {
                                if (aresp->user_information->size()) {
                                    std::size_t cntxt_cnt = 0;
                                    for (defined_context_map::iterator it = dcs()->contexts().begin(); it != dcs()->contexts().end(); ++it) {
                                        if ((it->second->abstract_syntax() != ACSE_OID) && (cntxt_cnt < aresp->user_information->size())) {
                                            boost::asn1::external_type& ext = aresp->user_information->operator [](cntxt_cnt);
                                            ext.encoding->single_ASN1_type()->bind(*(it->second->coder()->in()));
                                        }
                                    }
                                }
                            }
                            return ec;
                        }
                        default:
                        {
                        }
                    }
                }

                catch (const boost::system::system_error& cerr) {
                    return cerr.code();
                }
                catch (...) {
                }
                return ec = ER_PROTOCOL;
            }




        }
    }
}
