//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x22X/x226.hpp>
#include <boost/itu/x22X/presentation/ISO8823-PRESENTATION.hpp>

namespace boost {
    namespace itu {

        namespace x226impl {



            typedef ISO8823_PRESENTATION::CP_type CP_type;
            typedef ISO8823_PRESENTATION::CPA_PPDU CPA_type;
            typedef ISO8823_PRESENTATION::CPR_PPDU CPR_type;
            typedef ISO8823_PRESENTATION::User_data User_data;
            typedef ISO8823_PRESENTATION::Mode_selector mode_type;
            typedef ISO8823_PRESENTATION::Called_presentation_selector cd_selector_type;
            typedef ISO8823_PRESENTATION::Calling_presentation_selector cng_selector_type;
            typedef ISO8823_PRESENTATION::Simply_encoded_data simpledata_type;
            typedef ISO8823_PRESENTATION::Fully_encoded_data fulldata_type;
            typedef ISO8823_PRESENTATION::Context_list_sequence_of p_context_type;
            typedef p_context_type::Transfer_syntax_name_list_type transfer_syntax_list;
            typedef ISO8823_PRESENTATION::Result_list_sequence_of p_result_type;
            typedef ISO8823_PRESENTATION::PDV_list pdv_list_type;
            typedef ISO8823_PRESENTATION::PDV_list::Presentation_data_values_type data_values_type;
            typedef ISO8823_PRESENTATION::Result_list result_list_type;
            typedef ISO8823_PRESENTATION::Presentation_context_definition_list definition_list_type;
            typedef ISO8823_PRESENTATION::Presentation_context_definition_result_list definitionresult_list_type;

            static asn_coder_ptr build_by_context(const presentation_context& context) {

                switch (context.encoding()) {
                    case BER_ENCODING:
                    case DER_ENCODING:
                    case CER_ENCODING: return asn_coder_ptr(new x690_coder_type(context.abstract_syntax(), context.encoding()));
                    case PER_ALIGNED_ENCODING:
                    case PER_UNALIGNED_ENCODING:
                    case CPER_ALIGNED_ENCODING:
                    case CPER_UNALIGNED_ENCODING:  return asn_coder_ptr(new x691_coder_type(context.abstract_syntax(), context.encoding()));                    
                    default:
                    {
                    }
                }
                return asn_coder_ptr();
            }

            static encoding_set to_encodings(const transfer_syntax_list& val) {
                transfer_syntax_set tmp(val.begin(), val.end());
                return to_encoding_set(tmp);
            }



            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            defined_context::defined_context(const presentation_context& context) :
            context_(context) {
                coder_ = build_by_context(context);
            }

            bool defined_context::encoding(encoding_rule val) {
                if (encoding() != val) {
                    context_.encoding(val);
                    coder_ = build_by_context(context_);
                }
                return static_cast<bool>(coder_);
            }


            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            context_id_type defined_context_set::insert_context(context_id_type id, const presentation_context& context) {
                defined_context_ptr tmp = defined_context_ptr(new defined_context(context));
                if (!tmp->valid())
                    return 0;
                contexts_.insert(defined_presentation_context(id, tmp));
                return id;
            }

            context_id_type defined_context_set::remove_contex(context_id_type id) {
                defined_context_map::iterator it = contexts_.find(id);
                if (it != contexts_.end()) {
                    contexts_.erase(it);
                    return id;
                }
                return 0;
            }

            bool defined_context_set::transfer_syntax(context_id_type id, const transfer_syntax_type& val) {
                defined_context_map::iterator it = contexts_.find(id);
                if (it != contexts_.end()) {
                    it->second->encoding(to_encoding(val));
                    return static_cast<bool>(it->second->coder());
                }
                return false;
            }

            bool defined_context_set::transfer_syntax(abstract_syntax_type id, const transfer_syntax_type& val) {
                for (defined_context_map::iterator it = contexts_.begin(); it != contexts_.end(); ++it) {
                    if (it->second && it->second->abstract_syntax() == id) {
                        it->second->encoding(to_encoding(val));
                        return static_cast<bool>(it->second->coder());
                    }
                }
                return false;
            }

            context_id_type defined_context_set::insert_context(const presentation_context& context) {
                context_id_type tmp = insert_context(nextid_, context);
                if (tmp) nextid_ += 2;
                return tmp;
            }


            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            static void build_userdata(defined_context_set_ptr dcs, boost::shared_ptr<User_data>& data) {
                if (dcs->contexts().empty())
                    return;
                data = shared_ptr<User_data>(new User_data());
                if (dcs->is_simple_encoding()) {
                    data->simply_encoded_data__new();
                } else {
                    data->fully_encoded_data__new();
                    for (defined_context_map::const_iterator it = dcs->contexts().begin(); it != dcs->contexts().end(); ++it) {
                        if (it->second->valid() && it->second->coder()->out()->size()) {
                            pdv_list_type pdv_lst;
                            pdv_lst.presentation_context_identifier(it->first);
                            pdv_lst.presentation_data_values().single_ASN1_type__new();
                            pdv_lst.presentation_data_values().single_ASN1_type()->tie(it->second->coder());
                            data->fully_encoded_data()->push_back(pdv_lst);
                        }
                    }
                }
            }

            static void parse_userdata(defined_context_set_ptr dcs, const shared_ptr<User_data>& data) {
                if (!data)
                    return;
                try {
                    switch (data->type()) {
                        case ISO8823_PRESENTATION::User_data_simply_encoded_data:
                        {
                            if (!data->simply_encoded_data())
                                throw error_code(ER_BEDSEQ);
                            return;
                        }
                        case ISO8823_PRESENTATION::User_data_fully_encoded_data:
                        {
                            if (!data->fully_encoded_data())
                                throw error_code(ER_BEDSEQ);
                            const fulldata_type& values = *(data->fully_encoded_data());
                            for (fulldata_type::const_iterator it = values.begin(); it != values.end(); ++it) {
                                if (dcs->exists(it->presentation_context_identifier())) {
                                    if (it->transfer_syntax_name()) {
                                        dcs->transfer_syntax(it->presentation_context_identifier(), *(it->transfer_syntax_name()));
                                        if (!dcs->exists(it->presentation_context_identifier())) continue;
                                    }
                                    const data_values_type& values = it->presentation_data_values();
                                    switch (values.type()) {
                                        case ISO8823_PRESENTATION::PDV_list::Presentation_data_values_type_single_ASN1_type:
                                        {
                                            if (values.single_ASN1_type())
                                                values.single_ASN1_type()->bind(*(dcs->find(it->presentation_context_identifier())->in()));
                                            break;
                                        }
                                        case ISO8823_PRESENTATION::PDV_list::Presentation_data_values_type_octet_aligned:
                                        {
                                            error_code(ER_BEDSEQ);
                                            break;
                                        }
                                        case ISO8823_PRESENTATION::PDV_list::Presentation_data_values_type_arbitrary:
                                        {
                                            error_code(ER_BEDSEQ);
                                            break;
                                        }
                                        default:
                                        {
                                            error_code(ER_BEDSEQ);
                                        }
                                    }

                                } else {
                                    throw error_code(ER_PROTOCOL);
                                }
                            }
                            return;
                        }
                        default:
                        {
                        }
                    }
                } catch (const boost::system::system_error& cerr) {
                    throw cerr;
                } catch (...) {
                }
                throw error_code(ER_PROTOCOL);
            }

            ppdu_enum presentation_socket::check_response() {
                if (!coder()->input().size())
                    return null_ppdu;
                switch (coder()->input().test_class()) {
                    case boost::asn1::UNIVERSAL_CLASS:
                    {
                        switch (coder()->input().test_id()) {
                            case boost::asn1::TYPE_SET: return cp_ppdu;
                            default:
                            {
                            }
                        };
                        break;
                    }
                    case boost::asn1::APPLICATION_CLASS:
                    {
                        switch (coder()->input().test_id()) {
                            case 0: return dt_ppdu;
                            case 1: return dt_ppdu;
                            default:
                            {
                            }
                        };
                        break;
                    }

                    default:
                    {

                    }
                }
                return error_ppdu;
            }

            error_code presentation_socket::build_DT_type() {
                try {
                    shared_ptr<User_data> udt;
                    build_userdata(dcs(), udt);
                    if (udt)
                        udt->serialize(coder()->output());
                    return error_code();
                } catch (const boost::system::system_error& cerr) {
                    return cerr.code();
                } catch (...) {
                }
                return ER_PROTOCOL;
            }

            error_code presentation_socket::build_CP_type() {
                try {
                    CP_type request_pdu;

                    request_pdu.mode_selector().mode_value(mode_type::mode_value_normal_mode);

                    CP_type::Normal_mode_parameters_type& request_parameters = *request_pdu.normal_mode_parameters__new();                   
                    definition_list_type& request_list = * request_parameters.presentation_context_definition_list__new();

                    if (!option().called().empty())
                        request_parameters.called_presentation_selector(new cd_selector_type(option().called()));
                    if (!option().calling().empty())
                        request_parameters.calling_presentation_selector(new cng_selector_type(option().calling()));
                    // if (dcs->is_context_menagment())
                    //  request_pdu.normal_mode_parameters->presentation_requirements__assign(dcs->p_requirements());
                    //  request_pdu.normal_mode_parameters->protocol_version__assign(PRSNT_VERSION);
                    for (defined_context_map::const_iterator it = dcs()->contexts().begin(); it != dcs()->contexts().end(); ++it) {
                        if (it->second->valid()) {
                            p_context_type ctx;
                            ctx.abstract_syntax_name(it->second->abstract_syntax());
                            ctx.presentation_context_identifier(it->first);
                            transfer_syntax_set transferset = to_transfer_syntax_set(it->second->encodings());
                            ctx.transfer_syntax_name_list().insert(ctx.transfer_syntax_name_list().begin(),
                                    transferset.begin(), transferset.end());
                            request_list.push_back(ctx);
                        }
                    }
                    request_parameters.user_data__new();
                    build_userdata(dcs(), request_parameters.user_data());
                    (coder()->output()) & request_pdu;
                    return error_code();
                } catch (const boost::system::system_error& cerr) {
                    return cerr.code();
                } catch (...) {
                }
                return ER_PROTOCOL;
            }

            error_code presentation_socket::parse_CR() {
                try {
                    switch (check_response()) {
                        case cp_ppdu:
                        {
                            CPA_type accept_pdu;
                            (coder()->input()) & accept_pdu;

                            if (accept_pdu.mode_selector().mode_value() == mode_type::mode_value_normal_mode) {
                                if (accept_pdu.normal_mode_parameters()) {

                                    CPA_type::Normal_mode_parameters_type& accept_parameters = *accept_pdu.normal_mode_parameters();

                                    if (accept_parameters.presentation_context_definition_result_list()) {

                                        definitionresult_list_type& accept_list = *accept_parameters.presentation_context_definition_result_list();


                                        if (!accept_list.empty()) {
                                            defined_context_map::iterator ctxit = dcs()->contexts().begin();
                                            for (result_list_type::const_iterator it = accept_list.begin(); it != accept_list.end(); ++it) {
                                                if (it->result() != ISO8823_PRESENTATION::result_acceptance) {
                                                    if (ctxit != dcs()->contexts().end())
                                                        dcs()->remove_contex(ctxit->first);
                                                } else {
                                                    if ((it->transfer_syntax_name()) && (ctxit != dcs()->contexts().end()))
                                                        dcs()->transfer_syntax(ctxit->first, *(it->transfer_syntax_name()));
                                                    ctxit++;
                                                }
                                            }
                                        }
                                    }
                                    if (accept_parameters.responding_presentation_selector()) {
                                        option().called(*(accept_parameters.responding_presentation_selector()));
                                    }
                                    if (accept_parameters.presentation_requirements()) {
                                        dcs()->p_requirements(dcs()->p_requirements() &
                                                *(accept_parameters.presentation_requirements()));
                                    }
                                    parse_userdata(dcs(), accept_parameters.user_data());
                                    return error_code();

                                }
                            }
                        }
                        default:
                        {
                        }
                    }
                } catch (const boost::system::system_error& cerr) {
                    return cerr.code();
                } catch (...) {
                }
                return ER_PROTOCOL;
            }

            negotiate_rslt_enum presentation_socket::parse_CP() {
                try {
                    CP_type respond_pdu;

                    (coder()->input()) & respond_pdu;

                    CPA_type accept_pdu;
                    CPR_type reject_pdu;


                    accept_pdu.mode_selector().mode_value(respond_pdu.mode_selector().mode_value());

                    CPA_type::Normal_mode_parameters_type& accept_parameters = *accept_pdu.normal_mode_parameters__new();
                    CPR_type::Normal_mode_parameters_type& reject_parameters = *reject_pdu.normal_mode_parameters__new();

                    if (respond_pdu.mode_selector().mode_value() == mode_type::mode_value_normal_mode && respond_pdu.normal_mode_parameters()) {

                        CP_type::Normal_mode_parameters_type& respond_parameters = *respond_pdu.normal_mode_parameters();

                        option().called(respond_parameters.called_presentation_selector() ?
                                *(respond_parameters.called_presentation_selector()) : octet_sequnce());
                        if (respond_parameters.called_presentation_selector()) {
                            accept_parameters.responding_presentation_selector(respond_parameters.called_presentation_selector());
                            reject_parameters.responding_presentation_selector(respond_parameters.called_presentation_selector());
                        }

                        option().calling(respond_parameters.calling_presentation_selector() ?
                                *(respond_parameters.calling_presentation_selector()) : octet_sequnce());

                        if (!respond_parameters.presentation_context_definition_list())
                            return error_negotiate;

                        definition_list_type& respond_list = *respond_parameters.presentation_context_definition_list();
                        definitionresult_list_type& accept_list = *accept_parameters.presentation_context_definition_result_list__new();
                        definitionresult_list_type& reject_list = *reject_parameters.presentation_context_definition_result_list__new();

                        for (definition_list_type::const_iterator it = respond_list.begin(); it != respond_list.end(); ++it) {

                            if (option_.has_context(it->abstract_syntax_name(), to_encodings(it->transfer_syntax_name_list()))) {
                                context_id_type cid = dcs()->insert_context(it->presentation_context_identifier(), it->abstract_syntax_name());
                                p_result_type tmp;
                                tmp.result(ISO8823_PRESENTATION::result_acceptance);
                                tmp.transfer_syntax_name(new oid_type(to_transfer_syntax(dcs()->context(cid)->encoding())));
                                accept_list.push_back(tmp);
                                reject_list.push_back(tmp);
                            } else {
                                p_result_type tmp;
                                tmp.result(ISO8823_PRESENTATION::result_user_rejection);
                                tmp.provider_reason(0);
                                accept_list.push_back(tmp);
                                reject_list.push_back(tmp);
                            }
                        }

                        parse_userdata(dcs(), respond_parameters.user_data());
                        if (negotiate_presentation_accept()) {
                            build_userdata(dcs(), accept_parameters.user_data());
                            (coder()->output()) & reject_pdu;
                            return accept_negotiate;
                        }
                        (coder()->output()) & reject_pdu;
                        return reject_negotiate;
                    } else {
                        return error_negotiate;
                    }
                } catch (...) {
                }
                return error_negotiate;
            }

            error_code presentation_socket::parse_RESPONSE(ppdu_enum& ppdutype) {
                try {
                    switch (check_response()) {
                        case dt_ppdu:
                        {
                            shared_ptr<User_data> data(new User_data());
                            data->serialize(coder()->input());
                            parse_userdata(dcs(), data);
                            return error_code();

                        }
                        default:
                        {
                        }
                    }
                } catch (const boost::system::system_error& cerr) {
                    return cerr.code();
                } catch (...) {
                }
                return ER_PROTOCOL;
            }

        }
    }
}
