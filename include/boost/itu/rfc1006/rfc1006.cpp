//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/rfc1006/rfc1006.hpp>


namespace boost {
    namespace itu {
        namespace rfc1006impl {


            ////////////////////

            void generate_TKPTDU(octet_sequnce& val) {
                octet_sequnce hdr = TKPT_START;
                raw_back_insert(hdr, inttype_to_raw(endiancnv_copy(static_cast<int16_t> (val.size() + TKPT_LENGTH))));
                raw_front_insert(val, hdr);
            }



            /////////////////////



            octet_sequnce generate_header_TKPT_CR(const protocol_options& opt, const tpdu_size& tpdusize) {
                octet_sequnce rslt;
                rslt.insert(rslt.end(), CR_TPDU_ID);
                raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(static_cast<int16_t> (0))));
                raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(opt.src_tsap())));
                rslt.insert(rslt.end(), '\x0');

                rslt.insert(rslt.end(), VAR_TPDU_SIZE);
                rslt.insert(rslt.end(), static_cast<octet_type> (1));
                raw_back_insert(rslt, inttype_to_raw(tpdusize.basic()));

                if (tpdusize.preferred()) {
                    if (tpdusize.preferred() < static_cast<uint16_t> (0x100)) {
                        rslt.insert(rslt.end(), VAR_MAXTPDU_SIZE);
                        rslt.insert(rslt.end(), static_cast<octet_type> (1));
                        raw_back_insert(rslt, inttype_to_raw(static_cast<uint8_t> (tpdusize.preferred())));
                    }
                    else {
                        rslt.insert(rslt.end(), VAR_MAXTPDU_SIZE);
                        rslt.insert(rslt.end(), static_cast<octet_type> (2));
                        raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(tpdusize.preferred())));
                    }
                }

                if (!opt.calling().empty()) {
                    rslt.insert(rslt.end(), VAR_TSAPCALLING_ID);
                    rslt.insert(rslt.end(), static_cast<octet_type> (opt.calling().size()));
                    raw_back_insert(rslt, opt.calling());
                }
                if (!opt.called().empty()) {
                    rslt.insert(rslt.end(), VAR_TSAPCALLED_ID);
                    rslt.insert(rslt.end(), static_cast<octet_type> (opt.called().size()));
                    raw_back_insert(rslt, opt.called());
                }
                std::size_t sz = rslt.size();
                raw_front_insert(rslt, inttype_to_raw(static_cast<octet_type> (sz)));
                generate_TKPTDU(rslt);
                return rslt;
            }

            octet_sequnce generate_header_TKPT_CC(const protocol_options& opt, const tpdu_size& tpdusize) {
                octet_sequnce rslt;
                rslt.insert(rslt.end(), CC_TPDU_ID);
                raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(opt.dst_tsap())));
                raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(opt.src_tsap())));
                rslt.insert(rslt.end(), '\x0');

                if (tpdusize.preferred()) {
                    if (tpdusize.preferred() < static_cast<uint16_t> (0x100)) {
                        rslt.insert(rslt.end(), VAR_MAXTPDU_SIZE);
                        rslt.insert(rslt.end(), static_cast<octet_type> (1));
                        raw_back_insert(rslt, inttype_to_raw(static_cast<uint8_t> (tpdusize.preferred())));
                    }
                    else {
                        rslt.insert(rslt.end(), VAR_MAXTPDU_SIZE);
                        rslt.insert(rslt.end(), static_cast<octet_type> (2));
                        raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(tpdusize.preferred())));
                    }
                }
                else {
                    rslt.insert(rslt.end(), VAR_TPDU_SIZE);
                    rslt.insert(rslt.end(), static_cast<octet_type> (1));
                    raw_back_insert(rslt, inttype_to_raw(tpdusize.basic()));
                }

                if (!opt.calling().empty()) {
                    rslt.insert(rslt.end(), VAR_TSAPCALLING_ID);
                    rslt.insert(rslt.end(), static_cast<octet_type> (opt.calling().size()));
                    raw_back_insert(rslt, opt.calling());
                }
                if (!opt.called().empty()) {
                    rslt.insert(rslt.end(), VAR_TSAPCALLED_ID);
                    rslt.insert(rslt.end(), static_cast<octet_type> (opt.called().size()));
                    raw_back_insert(rslt, opt.called());
                }
                std::size_t sz = rslt.size();
                raw_front_insert(rslt, inttype_to_raw(static_cast<octet_type> (sz)));
                generate_TKPTDU(rslt);
                return rslt;
            }

            octet_sequnce generate_header_TKPT_DC(const protocol_options& opt) {
                octet_sequnce rslt;
                rslt.insert(rslt.end(), DR_TPDU_ID);
                raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(opt.dst_tsap())));
                raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(opt.src_tsap())));
                std::size_t sz = rslt.size();
                raw_front_insert(rslt, inttype_to_raw(static_cast<octet_type> (sz)));
                generate_TKPTDU(rslt);
                return rslt;
            }

            octet_sequnce generate_header_TKPT_DR(const protocol_options& opt, octet_type rsn) {
                octet_sequnce rslt;
                rslt.insert(rslt.end(), DR_TPDU_ID);
                raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(opt.dst_tsap())));
                raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(opt.src_tsap())));
                rslt.insert(rslt.end(), rsn);
                std::size_t sz = rslt.size();
                raw_front_insert(rslt, inttype_to_raw(static_cast<octet_type> (sz)));
                generate_TKPTDU(rslt);
                return rslt;
            }

            octet_sequnce generate_header_TKPT_ER(const protocol_options& opt, octet_type err, const octet_sequnce& errorseq) {
                octet_sequnce rslt;
                rslt.insert(rslt.end(), ER_TPDU_ID);
                raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(opt.dst_tsap())));
                rslt.insert(rslt.end(), err);
                rslt.insert(rslt.end(), ERT_PARAM_ID);
                rslt.insert(rslt.end(), static_cast<octet_type> (errorseq.size()));
                raw_back_insert(rslt, octet_sequnce(errorseq.begin(), errorseq.end()));
                std::size_t sz = rslt.size();
                raw_front_insert(rslt, inttype_to_raw(static_cast<octet_type> (sz)));
                generate_TKPTDU(rslt);
                return rslt;
            }




            /////////////////////////////////////////////////////////////////////////////////////////

            receiver::receiver(const mutable_buffer& buff, std::size_t waitingsize, bool ef) :
            state_(waitingsize ? waitdata : waittkpt),
            size_(0),
            estimatesize_(waitingsize ? ((boost::asio::buffer_size(buff) < waitingsize) ? boost::asio::buffer_size(buff) : waitingsize) : TKPT_WITH_LI),
            datasize_(0),
            waitdatasize_(waitingsize),
            type_(waitingsize ? DT : NL),
            errcode_(),
            eof_(ef),
            tkpt_data(new octet_sequnce(TKPT_WITH_LI)),
            tkpt_buff_(boost::asio::buffer(*tkpt_data)),
            header_buff_(),
            userbuff_(waitingsize ? boost::asio::buffer(buff, waitingsize) : buff) {
            }

            receiver::receiver() :
            state_(waittkpt),
            size_(0),
            estimatesize_(TKPT_WITH_LI),
            datasize_(0),
            waitdatasize_(0),
            type_(NL),
            errcode_(),
            eof_(true),
            tkpt_data(new octet_sequnce(TKPT_WITH_LI)),
            tkpt_buff_(boost::asio::buffer(*tkpt_data)),
            header_buff_(),
            userbuff_() {

            }

            mutable_buffer receiver::buffer() {
                switch (state_) {
                    case waittkpt: return tkpt_buff_ + size_;
                    case waitheader: return header_buff_ + size_;
                    case waitdata: return boost::asio::buffer(userbuff_ + datasize_, estimatesize_);
                    default: return mutable_buffer();
                }
                return mutable_buffer();
            }

            void receiver::put(std::size_t sz) {
                if (!sz) return;
                size_ += sz;
                if (size_ >= estimatesize_) {
                    switch (state_) {
                        case waittkpt:
                        {
                            check_tkpt();
                            return;
                        }
                        case waitheader:
                        {
                            check_header();
                            return;
                        }
                        case waitdata:
                        {
                            waitdatasize_ -= ((sz > waitdatasize_) ? waitdatasize_ : sz);
                            datasize_ += sz;
                            if (eof_ || !boost::asio::buffer_size(userbuff_ + datasize_)) {
                                state_ = complete;
                            }
                            else {
                                state(waittkpt);
                                estimatesize_ = TKPT_WITH_LI;
                            }
                            return;
                        }
                        default:
                        {
                            errcode(ER_PROTOCOL);
                            return;
                        }
                    }

                }
                if (state_ == waitdata) {
                    waitdatasize_ -= ((sz > waitdatasize_) ? waitdatasize_ : sz);
                    datasize_ += sz;
                }
            }

            receiver::operation_state receiver::state(operation_state val) {
                if (val != state_) {
                    size_ = 0;
                }
                if (val == error) {
                    estimatesize_ = 0;
                }
                return state_ = val;
            }

            error_code receiver::check_tkpt() {
                mutable_buffer buff_ = tkpt_buff_;
                octet_sequnce hdr = buffer_to_raw(buff_, 0, 2);
                if (hdr != TKPT_START) {
                    return errcode(ER_PROTOCOL);
                }
                uint16_t pdsz = endiancnv_copy<uint16_t > (buffer_to_raw(buff_, 2, 2));
                if (pdsz < 0) {
                    return errcode(ER_PROTOCOL);
                }
                std::size_t li = static_cast<std::size_t> (*boost::asio::buffer_cast<uint8_t*>(buff_ + 4));
                if (!li)
                    return errcode(ER_PROTOCOL);
                state_ = waitheader;
                if (li > 128)
                    return errcode(ER_PROTOCOL);
                header_data = octet_sequnce_ptr(new octet_sequnce(li));
                header_buff_ = mutable_buffer(boost::asio::buffer(*header_data));
                size_ = 0;
                estimatesize_ = li;
                waitdatasize_ = pdsz - TKPT_WITH_LI - li;
                return error_code();
            }

            error_code receiver::check_header() {
                mutable_buffer buff_ = header_buff_;
                octet_type nativetp = *boost::asio::buffer_cast<octet_type*>(buff_);
                type_ = tpdu_type_from(((nativetp & '\xF0') == CR_TPDU_ID) ? (nativetp & '\xF0') : nativetp);
                switch (type_) {
                    case DT:
                    {
                        octet_type eof = *boost::asio::buffer_cast<octet_type*>(buff_ + 1);
                        if (estimatesize_ != 2 || !((eof == TPDU_CONTINIUE) || (eof == TPDU_ENDED)))
                            return errcode(ER_PROTOCOL);
                        estimatesize_ = (boost::asio::buffer_size(userbuff_ + datasize_) < waitdatasize_) ?
                                boost::asio::buffer_size(userbuff_ + datasize_) : waitdatasize_;
                        eof_ = (eof == TPDU_ENDED);
                        if (boost::asio::buffer_size(userbuff_) > waitdatasize_)
                            userbuff_ = boost::asio::buffer(userbuff_, waitdatasize_);
                        state(boost::asio::buffer_size(userbuff_) ? waitdata : complete);
                        return error_code();
                    }
                    case CR:
                    {
                        waitdatasize_ = 0;
                        if (estimatesize_ < 6)
                            return errcode(ER_PROTOCOL);
                        int16_t dst_tsap_ = 0;
                        int16_t src_tsap_ = 0;
                        octet_type class_option;
                        raw_to_inttype(buffer_to_raw(buff_, 1, 2), dst_tsap_);
                        dst_tsap_ = endiancnv_copy(dst_tsap_);
                        raw_to_inttype(buffer_to_raw(buff_, 3, 2), src_tsap_);
                        src_tsap_ = endiancnv_copy(src_tsap_);
                        raw_to_inttype(buffer_to_raw(buff_, 5, 1), class_option);
                        headarvarvalues vars;
                        if (!parse_vars(buffer_to_raw(buff_, 6, (estimatesize_ - 6)), vars))
                            return errcode(ER_PROTOCOL);
                        options_ = protocol_options_ptr(new protocol_options(dst_tsap_, src_tsap_, vars));
                        state(complete);
                        return error_code();
                    }
                    case CC:
                    {
                        waitdatasize_ = 0;
                        if (estimatesize_ < 6)
                            return errcode(ER_PROTOCOL);
                        int16_t dst_tsap_ = 0;
                        int16_t src_tsap_ = 0;
                        octet_type class_option;
                        raw_to_inttype(buffer_to_raw(buff_, 1, 2), dst_tsap_);
                        dst_tsap_ = endiancnv_copy(dst_tsap_);
                        raw_to_inttype(buffer_to_raw(buff_, 3, 2), src_tsap_);
                        src_tsap_ = endiancnv_copy(src_tsap_);
                        raw_to_inttype(buffer_to_raw(buff_, 5, 1), class_option);
                        headarvarvalues vars;
                        if (!parse_vars(buffer_to_raw(buff_, 6, (estimatesize_ - 6)), vars))
                            return errcode(ER_PROTOCOL);
                        options_ = protocol_options_ptr(new protocol_options(dst_tsap_, src_tsap_, vars));
                        state(complete);
                        return error_code();
                    }
                    case DR:
                    {
                        waitdatasize_ = 0;
                        if (estimatesize_ < 6)
                            return errcode(ER_PROTOCOL);
                        int16_t dst_tsap_ = 0;
                        int16_t src_tsap_ = 0;
                        raw_to_inttype(buffer_to_raw(buff_, 1, 2), dst_tsap_);
                        dst_tsap_ = endiancnv_copy(dst_tsap_);
                        raw_to_inttype(buffer_to_raw(buff_, 3, 2), src_tsap_);
                        src_tsap_ = endiancnv_copy(src_tsap_);
                        octet_type rsn = 0;
                        raw_to_inttype(buffer_to_raw(buff_, 5, 1), rsn);
                        reject_reason(rsn);
                        headarvarvalues vars;
                        if (!parse_vars(buffer_to_raw(buff_, 6, (estimatesize_ - 6)), vars))
                            return errcode(ER_PROTOCOL);
                        options_ = protocol_options_ptr(new protocol_options(dst_tsap_, src_tsap_, vars));
                        state(complete);
                        return error_code();
                    }
                    case ER:
                    {
                        waitdatasize_ = 0;
                        if (estimatesize_ < 4)
                            return errcode(ER_PROTOCOL);
                        int16_t dst_tsap_ = 0;
                        octet_type reject_rsn = 0;
                        raw_to_inttype(buffer_to_raw(buff_, 1, 2), dst_tsap_);
                        raw_to_inttype(buffer_to_raw(buff_, 3, 1), reject_rsn);
                        headarvarvalues vars;
                        if (!parse_vars(buffer_to_raw(buff_, 4, (estimatesize_ - 4)), vars))
                            state(complete);
                        return error_code();

                    }
                    default:
                    {
                        errcode(ER_PROTOCOL);
                    }
                }
                return errcode(ER_PROTOCOL);
            }

            void receiver::reject_reason(octet_type val) {
                errcode_ = errorcode_by_reason(val);
            }

            error_code receiver::errcode(const error_code& err) {
                if (!errcode_ && err)
                    errcode_ = err;
                if (err)
                    state_ = error;
                return errcode_;
            }



            ///////////////////////////////////////////////////////////////////////////////////////                 

            class service_sender_sequences : public basic_sender_sequences {
            public:

                service_sender_sequences(const octet_sequnce& send) : basic_sender_sequences(), send_(send) {
                    buff().push_back(send_.empty() ? const_buffer() : const_buffer(&send_.front(), send_.size()));
                }

            private:
                octet_sequnce send_;
            };



            ///////////////////////////////////////////////////////////////////////////////////////

            sender::sender(tpdu_type type, const protocol_options& opt, octet_type reason_or_error, const octet_sequnce& errorseq) :
            type_(type) {
                switch (type_) {
                    case DR:
                    {
                        constructDR(opt, reason_or_error);
                        break;
                    }
                    case ER:
                    {
                        constructER(opt, reason_or_error, errorseq);
                        break;
                    }
                    default:
                    {
                    }
                }
            }

            sender::sender(tpdu_type type, const protocol_options& opt, const tpdu_size& tpdusize) :
            type_(type) {
                switch (type_) {
                    case CR:
                    {
                        constructCR(opt, tpdusize);
                        break;
                    }
                    case CC:
                    {
                        constructCC(opt, tpdusize);
                        break;
                    }
                }
            }

            void sender::constructCR(const protocol_options& opt, const tpdu_size& tpdusize) {
                buf_ = sender_sequnces_ptr(new service_sender_sequences(generate_header_TKPT_CR(opt, tpdusize)));
            }

            void sender::constructCC(const protocol_options& opt, const tpdu_size& tpdusize) {
                buf_ = sender_sequnces_ptr(new service_sender_sequences(generate_header_TKPT_CC(opt, tpdusize)));
            }

            void sender::constructDR(const protocol_options& opt, octet_type rsn) {
                buf_ = sender_sequnces_ptr(new service_sender_sequences(generate_header_TKPT_DR(opt, rsn)));
            }

            void sender::constructER(const protocol_options& opt, octet_type errtype, const octet_sequnce& errorseq) {
                buf_ = sender_sequnces_ptr(new service_sender_sequences(generate_header_TKPT_ER(opt, errtype, errorseq)));
            }



        }
    }
}