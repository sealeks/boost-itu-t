//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef _BOOST_RFC1006_IMPLEMENTATIUON_H_
#define _BOOST_RFC1006_IMPLEMENTATIUON_H_



#include <boost/itu/x22X/selectors.hpp>
#include <boost/itu/x22X/x224.hpp>


namespace boost {
    namespace itu {
        namespace rfc1006impl {

            // ref X224 = ITU-T Rec. X.224(1995 E)
            // ref RFC1006

            using namespace boost::itu::x224impl;


            using boost::asio::basic_socket;
            using boost::asio::basic_socket_acceptor;


            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   rfc1006 utill   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                 

            inline static bool negotiate_rfc1006impl_option(protocol_options& self, const protocol_options& dist, octet_type& error) {
#ifndef CHECK_ISO_SELECTOR
                if (!self.called().empty() && self.called() != dist.called()) {
                    error = DR_REASON_ADDRESS;
                    return false;
                }
#endif                
                self = protocol_options(dist.src_tsap(), self.src_tsap(),
                        less_tpdu(dist.pdusize(), self.pdusize()),
                        self.calling(), dist.calling());
                return true;
            }

            void generate_TKPTDU(octet_sequnce& val);

            octet_sequnce generate_header_TKPT_CR(const protocol_options& opt, const tpdu_size& tpdusize);

            octet_sequnce generate_header_TKPT_CC(const protocol_options& opt, const tpdu_size& tpdusize);

            octet_sequnce generate_header_TKPT_DC(const protocol_options& opt);

            octet_sequnce generate_header_TKPT_DR(const protocol_options& opt, octet_type reason);

            octet_sequnce generate_header_TKPT_ER(const protocol_options& opt, octet_type errortype, const octet_sequnce& errorseq);



            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  rfc1006 data_sender_sequences   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    


            // *ref RFC1006 6.0
            const octet_type TKPT_STARTar[] = {'\x3', '\x0'};
            const octet_sequnce TKPT_START = octet_sequnce(TKPT_STARTar, TKPT_STARTar + 2);

            const std::size_t TKPT_LENGTH = 4;

            const octet_sequnce::size_type DT_SEND_BUFF_HEADER = 7;

            // allways 2 fore class 0 *ref X224 13.7.1
            const octet_type DATA_HEADER_LI = '\x2';

            template <typename ConstBufferSequence>
            class data_sender_sequences : public basic_sender_sequences {
            public:

                data_sender_sequences(const ConstBufferSequence& bf, const tpdu_size& pdusize, std::size_t constraint_size) :
                basic_sender_sequences(), headercontinue_(), headereof_() {
                    construct(bf, pdusize, constraint_size);

                }

                void construct(const ConstBufferSequence& bf, const tpdu_size& pdusize, std::size_t constraint_size) {
                    std::size_t pdusz = pdusize.size();
                    if (!pdusz) pdusz = 128;
                    pdusz -= 3;

                    headercontinue_.reserve(DT_SEND_BUFF_HEADER);
                    uint16_t normalsz = endiancnv_copy(static_cast<uint16_t> (pdusz + 7));
                    headercontinue_ = TKPT_START;
                    // packet lengh *ref RFC1006 6.0
                    raw_back_insert(headercontinue_, inttype_to_raw(normalsz));
                    headercontinue_.insert(headercontinue_.end(), DATA_HEADER_LI);
                    headercontinue_.insert(headercontinue_.end(), DT_TPDU_ID);
                    headercontinue_.insert(headercontinue_.end(), TPDU_CONTINIUE);

                    typedef typename ConstBufferSequence::const_iterator constbuffseq_iterator;
                    typedef typename ConstBufferSequence::value_type constbuffseq_value;

                    constbuffseq_iterator it = bf.begin();
                    constbuffseq_iterator end = bf.end();
                    constbuffseq_iterator pend = end;
                    if (it != end)
                        --pend;

                    constbuffseq_value val;

                    const_sequences tmp;
                    std::size_t tmpsize = 0;

                    bool ended = (it == end) || (it == pend);
                    while (it != end) {
                        val = *it;
                        do {
                            if ((boost::asio::buffer_size(val) + tmpsize) > pdusz) {
                                buff().push_back(const_buffer(&headercontinue_.front(), headercontinue_.size()));
                                if (!tmp.empty())
                                    std::copy(tmp.begin(), tmp.end(), std::back_inserter(buff()));
                                tmp.clear();
                                buff().push_back(boost::asio::buffer(val, pdusz - tmpsize));
                                val = val + (pdusz - tmpsize);
                                tmpsize = 0;
                            }
                            else {
                                if (ended) {
                                    uint16_t eofsz = endiancnv_copy(static_cast<uint16_t> (boost::asio::buffer_size(val) + boost::asio::buffer_size(tmp) + 7));
                                    headereof_.reserve(DT_SEND_BUFF_HEADER);
                                    headereof_ = TKPT_START;
                                    // packet lengh  *ref RFC1006 6.0
                                    raw_back_insert(headereof_, inttype_to_raw(eofsz));
                                    headereof_ .insert(headereof_ .end(), DATA_HEADER_LI);
                                    headereof_ .insert(headereof_ .end(), DT_TPDU_ID);
                                    headereof_ .insert(headereof_ .end(), TPDU_ENDED);
                                    buff().push_back(const_buffer(&headereof_.front(), headereof_.size()));
                                    if (!tmp.empty())
                                        std::copy(tmp.begin(), tmp.end(), std::back_inserter(buff()));
                                    tmp.clear();
                                    buff().push_back(const_buffer(val));
                                    val = val + pdusz;
                                    tmpsize = 0;
                                }
                                else {
                                    tmp.push_back(const_buffer(val));
                                    tmpsize += boost::asio::buffer_size(val);
                                    val = val + pdusz;
                                }
                            }
                        }
                        while (boost::asio::buffer_size(val));
                        ++it;
                        ended = (it == end) || (it == pend);
                    }
                }

            private:

                octet_sequnce headercontinue_;
                octet_sequnce headereof_;
            };


            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // optimized rfc1006 data_sender_sequences   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                

            template<>
            class data_sender_sequences<const_sequences> : public basic_sender_sequences {
            public:

                data_sender_sequences<const_sequences>(const const_sequences& bf, const tpdu_size& pdusize, std::size_t constraint_size) :
                basic_sender_sequences(const_cast<const_sequences&> (bf)), headercontinue_(), headereof_() {
                    construct(pdusize, constraint_size);
                }

                void construct(const tpdu_size& pdusize, std::size_t constraint_size) {
                    if (buff().empty()) return;
                    std::size_t pdusz = pdusize.size();
                    if (!pdusz) pdusz = 128;
                    pdusz -= 3;
                    std::size_t tmpsize = 0;
                    std::size_t buffsize = 0;
                    const_sequences::iterator it = buff().begin();
                    const_sequences::iterator insert_pos = it;


                    if (constraint_size && (pdusz >= constraint_size)) {
                        tmpsize = constraint_size;
                    }
                    else {
                        while (it != buff().end()) {
                            buffsize = boost::asio::buffer_size(*it);
                            if ((buffsize + tmpsize) >= pdusz) {

                                if (headercontinue_.empty()) {
                                    uint16_t normalsz = endiancnv_copy(static_cast<uint16_t> (pdusz + 7));
                                    headercontinue_.reserve(DT_SEND_BUFF_HEADER);
                                    headercontinue_ = TKPT_START;
                                    //  packet lengh *ref RFC1006 6.0
                                    raw_back_insert(headercontinue_, inttype_to_raw(normalsz));

                                    headercontinue_.insert(headercontinue_.end(), DATA_HEADER_LI);
                                    headercontinue_.insert(headercontinue_.end(), DT_TPDU_ID);
                                    headercontinue_.insert(headercontinue_.end(), TPDU_CONTINIUE);
                                }

                                if ((buffsize + tmpsize) == pdusz) {
                                    buff().insert(insert_pos, const_buffer(static_cast<const octet_type*> (&headercontinue_[0]), headercontinue_.size()));
                                    insert_pos = it;
                                    ++insert_pos;
                                    tmpsize = 0;
                                }
                                else {
                                    const_buffer firstpart = boost::asio::buffer(*it, (pdusz - tmpsize));
                                    const_buffer secondpart = (*it)+(pdusz - tmpsize);
                                    buff().insert(insert_pos, const_buffer(static_cast<const octet_type*> (&headercontinue_[0]), headercontinue_.size()));
                                    insert_pos = buff().insert(buff().erase(it), secondpart);
                                    it = buff().insert(insert_pos, firstpart);
                                    tmpsize = 0;
                                }
                            }
                            else
                                tmpsize += buffsize;
                            ++it;
                        }
                    }
                    if (tmpsize) {
                        headereof_.reserve(DT_SEND_BUFF_HEADER);
                        headereof_ = TKPT_START;
                        uint16_t eofsz = endiancnv_copy(static_cast<uint16_t> (tmpsize + 7));
                        // packet lengh  *ref RFC1006 6.0
                        raw_back_insert(headereof_, inttype_to_raw(eofsz));
                        headereof_ .insert(headereof_ .end(), DATA_HEADER_LI);
                        headereof_ .insert(headereof_ .end(), DT_TPDU_ID);
                        headereof_ .insert(headereof_ .end(), TPDU_ENDED);
                        buff().insert(insert_pos, const_buffer(static_cast<const octet_type*> (&headereof_[0]), headereof_.size()));
                    }
                }

            private:

                octet_sequnce headercontinue_;
                octet_sequnce headereof_;

            };





            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  rfc1006 sender   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                  

            class sender {
            public:

                sender(tpdu_type type) :
                type_(type) {
                }

                sender(tpdu_type type, const protocol_options& opt,
                        octet_type reason_or_error = 0, const octet_sequnce& errorseq = NULL_OCTET_SEQUENCE);

                sender(tpdu_type type, const protocol_options& opt, const tpdu_size& tpdusize);

                virtual ~sender() {
                }

                bool ready() const {
                    return (!buf_) || (buf_->ready());
                }

                const const_sequences& pop() {
                    return buf_ ? buf_->pop() : NULL_CONST_SEQUENCE;
                }

                std::size_t size(std::size_t sz) {
                    return ready() ? 0 : buf_->size(sz);
                }

                tpdu_type type() const {
                    return type_;
                }




            protected:


                void constructCR(const protocol_options& opt, const tpdu_size& tpdusize);

                void constructCC(const protocol_options& opt, const tpdu_size& tpdusize);

                void constructDR(const protocol_options& opt, octet_type reason);

                void constructER(const protocol_options& opt, octet_type errtype, const octet_sequnce& errorreason);



                tpdu_type type_;
                sender_sequnces_ptr buf_;
            };




            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  rfc1006 data_sender   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

            template <typename ConstBufferSequence >
            class data_sender : public sender {
            public:

                data_sender(const ConstBufferSequence& buff, const tpdu_size& pdusize, std::size_t constraint_size) : sender(DT) {
                    constructDT(buff, pdusize, constraint_size);
                }

            protected:

                void constructDT(const ConstBufferSequence& buff, const tpdu_size& pdusize, std::size_t constraint_size) {
                    buf_ = sender_sequnces_ptr(new data_sender_sequences<ConstBufferSequence > (buff, pdusize, constraint_size));
                }

            };


            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  rfc1006 receiver   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

            const std::size_t TKPT_WITH_LI = 5;

            class receiver {
            public:

                typedef boost::shared_ptr< protocol_options > protocol_options_ptr;

                enum operation_state {
                    waittkpt,
                    waitheader,
                    waitdata,
                    complete,
                    error
                };

                receiver(const mutable_buffer& buff, std::size_t waitingsize, bool ef);

                receiver();

                mutable_buffer buffer();

                void put(std::size_t sz);

                bool ready() const {
                    return (state_ == error || state_ == complete);
                }

                operation_state state() const {
                    return state_;
                }

                tpdu_type type() const {
                    return type_;
                }

                bool eof() const {
                    return eof_;
                }

                std::size_t datasize() const {
                    return datasize_;
                }

                std::size_t waitdatasize() const {
                    return waitdatasize_;
                }

                const protocol_options& options() const {
                    return options_ ? *options_ : NULL_PROTOCOL_OPTION;
                }

                error_code errcode() const {
                    return errcode_ ? errcode_ : ER_REFUSE;
                }

                const octet_sequnce& errsequense() const {
                    return header_data ? *header_data : NULL_OCTET_SEQUENCE;
                }


            private:

                operation_state state(operation_state val);

                error_code errcode(const error_code& err);

                void reject_reason(octet_type val);

                error_code check_tkpt();

                error_code check_header();

                operation_state state_;
                std::size_t size_;
                std::size_t estimatesize_;
                std::size_t datasize_;
                std::size_t waitdatasize_;
                tpdu_type type_;
                error_code errcode_;
                bool eof_;
                octet_sequnce_ptr tkpt_data;
                octet_sequnce_ptr header_data;
                mutable_buffer tkpt_buff_;
                mutable_buffer header_buff_;
                mutable_buffer userbuff_;
                protocol_options_ptr options_;
            };






            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  rf1006 itu_socket  //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

            class itu_socket : protected boost::asio::basic_stream_socket<boost::asio::ip::tcp > {
                typedef boost::shared_ptr<receiver> receiver_ptr;
                typedef boost::shared_ptr<sender> sender_ptr;
                typedef boost::asio::basic_stream_socket<boost::asio::ip::tcp > super_type;

                friend class socket_acceptor;

            public:

                typedef super_type::protocol_type protocol_type;
                typedef super_type::lowest_layer_type lowest_layer_type;
                typedef super_type::native_handle_type native_handle_type;
                typedef super_type::native_type native_type;
                typedef super_type::message_flags message_flags;
                typedef super_type::endpoint_type endpoint_type;
                typedef super_type::service_type service_type;
                typedef super_type::shutdown_type shutdown_type;
                typedef super_type::implementation_type implementation_type;


                using super_type::assign;
                using super_type::at_mark;
                using super_type::available;
                using super_type::bind;
                using super_type::cancel;
                using super_type::close;
                using super_type::get_io_service;
                using super_type::get_option;
                using super_type::io_control;
                using super_type::is_open;
                using super_type::lowest_layer;
                using super_type::native;
                using super_type::native_handle;
                using super_type::native_non_blocking;
                using super_type::non_blocking;
                using super_type::open;
                using super_type::remote_endpoint;
                using super_type::set_option;
                using super_type::shutdown;

            protected:

                using super_type::get_service;
                using super_type::get_implementation;

            public:


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Constructors  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       

                explicit itu_socket(boost::asio::io_service& io_service, const transport_selector& tsel = NULL_TRANSPORT_SELECTOR)
                : super_type(io_service),
                transport_option_(0, 1, DEFAULT_TPDU_SIZE, tsel.called(), tsel.calling()), waiting_data_size_(0),
                eof_state_(true), is_acceptor_(false), tpdusize_(DEFAULT_TPDU_SIZE) {
                }

                itu_socket(boost::asio::io_service& io_service,
                        const endpoint_type& endpoint, const transport_selector& tsel = NULL_TRANSPORT_SELECTOR)
                : super_type(io_service, endpoint),
                transport_option_(0, 1, DEFAULT_TPDU_SIZE, tsel.called(), tsel.calling()), waiting_data_size_(0),
                eof_state_(true), is_acceptor_(false), tpdusize_(DEFAULT_TPDU_SIZE) {
                }




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Data indication  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

                bool ready() const {
                    return (!waiting_data_size_) && (eof_state_);
                }

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  This Is accptor  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

                bool is_acceptor() const {
                    return is_acceptor_;
                }

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Connnect operations  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

                void connect(const endpoint_type& peer_endpoint) {
                    error_code ec;
                    connect(peer_endpoint, ec);
                    boost::asio::detail::throw_error(ec, "connect");
                }

                error_code connect(const endpoint_type& peer_endpoint,
                        error_code& ec) {
                    return connect_impl(peer_endpoint, ec);
                }


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            private:

                template <typename ConnectHandler>
                class connect_operation {
                    typedef connect_operation <ConnectHandler> operation_type;

                    enum stateconnection {
                        request,
                        response
                    };

                public:

                    connect_operation(itu_socket& sock, ConnectHandler handlr) :
                    socket(sock),
                    handler(handlr),
                    state_(request),
                    sender_(sender_ptr(new sender(CR, sock.transport_option(), sock.pdusize()))),
                    receiver_(new receiver()) {
                    }

                    void start(const error_code& ec) {
                        if (!ec)
                            operator()(ec, 0);
                        else
                            handler(ec);
                    }

                    void operator()(const error_code& ec, std::size_t bytes_transferred) {
                        if (!ec) {
                            switch (state_) {
                                case request:
                                {
                                    sender_->size(bytes_transferred);
                                    if (!sender_->ready()) {
                                        socket.super_type::async_send(sender_->pop(), 0, *this);
                                        return;
                                    }
                                    else {
                                        state(response);
                                        operator()(ec, 0);
                                        return;
                                    }
                                }
                                case response:
                                {
                                    receiver_->put(bytes_transferred);
                                    if (!receiver_->ready()) {
                                        socket.super_type::async_receive(boost::asio::buffer(receiver_->buffer()), 0, *this);
                                        return;
                                    }
                                    finish(ec);
                                    return;
                                }
                            }
                        }
                        handler(ec);
                    }



                private:

                    void finish(const error_code& ec) {
                        switch (receiver_->state()) {
                            case receiver::complete:
                            {
                                switch (receiver_->type()) {
                                    case CC:
                                    { // Accepted. Negotiate options *ref X224 6.5.4 a) j)
                                        tpdu_size pdsize = receiver_->options().pdusize();
                                        socket.pdusize(pdsize);
                                        socket.pdusize(receiver_->options().pdusize());
                                        socket.dst_tsap(receiver_->options().src_tsap());

                                        handler(ec);
                                        return;
                                    }
                                    case ER:
                                    case DR:
                                    { // Both cases indicates connections refuse  *ref X224 6.6.2
                                        // Release by means implicit variant  *ref X224 6.7.1.4  
                                        socket.async_internal_close();
                                        handler(receiver_->errcode());
                                        return;
                                    }
                                }
                                break;
                            }
                            case receiver::error:
                            {
                                // Release by means implicit variant  *ref X224 6.7.1.4
                                socket.async_internal_close();
                                handler(receiver_->errcode());
                                return;
                            }
                        }
                        // Release by means implicit variant  *ref X224 6.7.1.4
                        socket.async_internal_close();
                        handler(ER_PROTOCOL);
                    }

                    void state(stateconnection st) {
                        if (state_ != st) {
                            state_ = st;
                        }
                    }

                    itu_socket& socket;
                    ConnectHandler handler;
                    stateconnection state_;
                    sender_ptr sender_;
                    receiver_ptr receiver_;

                };


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            public:

                template <typename ConnectHandler>
                void async_connect(const endpoint_type& peer_endpoint,
                        BOOST_ASIO_MOVE_ARG(ConnectHandler) handler) {

                    //BOOST_ASIO_CONNECT_HANDLER_CHECK(ConnectHandler, handler) type_check;

                    typedef connect_operation<ConnectHandler> connect_operation_type;

                    super_type::async_connect(peer_endpoint, boost::bind(&connect_operation_type::start,
                            connect_operation_type(*this, handler), boost::asio::placeholders::error));

                }





                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Release operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

            public:

                // It is in general agreement with *ref X224 (TPM understands DR)   

                void release(octet_type rsn = DR_REASON_NORM) {

                    error_code ec;
                    release(ec, rsn);
                    boost::asio::detail::throw_error(ec, "release");
                }

                error_code release(error_code& ec, octet_type rsn = DR_REASON_NORM) {

                    return release_impl(ec, rsn);
                }



                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            private:

                template <typename ReleaseHandler>
                class release_operation {
                    typedef release_operation<ReleaseHandler> operation_type;

                public:

                    release_operation(itu_socket& sock, ReleaseHandler handlr, octet_type rsn) :
                    socket(sock),
                    handler(handlr)//,
                    /*sender_(sender_ptr(new sender(DR, sock.transport_option(), rsn)))*/ {
                    }

                    void start(const error_code& ec) {
                        operator()(ec, 0);
                    }

                    void operator()(const error_code& ec, std::size_t bytes_transferred) {
                        /*if (!ec) {
                            sender_->size(bytes_transferred);
                            if (!sender_->ready()) {
                                socket.super_type::async_send(sender_->pop(), 0, *this);
                                return;
                            }
                        }*/
                        // Release by means implicit variant  *ref X224 6.7.1.4
                        socket.async_internal_close();
                        handler(ec);
                    }


                private:
                    itu_socket& socket;
                    ReleaseHandler handler;
                    //sender_ptr sender_;
                };


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            public:

                template <typename ReleaseHandler>
                void async_release(BOOST_ASIO_MOVE_ARG(ReleaseHandler) handler,
                        octet_type rsn = DR_REASON_NORM) {

                    typedef release_operation<ReleaseHandler > release_operation_type;

                    get_io_service().post(boost::bind(&release_operation_type::start,
                            release_operation_type(*this, handler, rsn), is_open() ? error_code() : ER_NOLINK));
                }





                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Check accept operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

            protected:

                void check_accept() {
                    error_code ec;
                    boost::asio::detail::throw_error(ec, "connect");
                }

                error_code check_accept(error_code& ec) {

                    return check_accept_imp(ec);
                }


            private:

                template <typename CheckAcceptHandler>
                class check_accept_operation {
                    typedef check_accept_operation<CheckAcceptHandler> operation_type;

                    enum stateconnection {
                        response,
                        request,
                        refuse
                    };

                public:

                    check_accept_operation(itu_socket& sock, CheckAcceptHandler handlr) :
                    socket(sock),
                    handler(handlr),
                    state_(response),
                    sender_(),
                    tpdusize(sock.transport_option().pdusize()),
                    receiver_(new receiver()) {
                    }

                    void start() {
                        error_code ec;
                        operator()(ec, 0);
                    }

                    void operator()(const error_code& ec, std::size_t bytes_transferred) {
                        if (!ec) {
                            switch (state_) {
                                case response:
                                {
                                    receiver_->put(bytes_transferred);
                                    if (!receiver_->ready()) {
                                        socket.super_type::async_receive(boost::asio::buffer(receiver_->buffer()), 0, *this);
                                        return;
                                    }
                                    parse_response(ec);
                                    return;
                                }
                                case request:
                                {
                                    sender_->size(bytes_transferred);
                                    if (!sender_->ready()) {
                                        socket.super_type::async_send(sender_->pop(), 0, *this);
                                        return;
                                    }
                                    handler(ec);
                                    return;
                                }
                                case refuse:
                                {
                                    sender_->size(bytes_transferred);
                                    if (!sender_->ready()) {
                                        socket.super_type::async_send(sender_->pop(), 0, *this);
                                        return;
                                    }
                                    // Release by means implicit variant  *ref X224 6.7.1.4
                                    socket.async_internal_close();
                                    handler(ER_PROTOPT);
                                    return;
                                }
                            }
                        }
                        // Release by means implicit variant  *ref X224 6.7.1.4
                        socket.async_internal_close();
                        handler(ec);
                    }


                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                private:

                    void parse_response(const error_code& ec) {

                        switch (receiver_->state()) {
                            case receiver::complete:
                            {
                                switch (receiver_->type()) {
                                    case CR:
                                    { //  *ref X224 6.5.4 
                                        protocol_options options_ = socket.transport_option();
                                        octet_type error_accept = 0;
                                        if (!negotiate_rfc1006impl_option(options_, receiver_->options(), error_accept)) {
                                            //  Not negotiated.  send DR
                                            sender_ = sender_ptr(new sender(DR, socket.transport_option(), error_accept));
                                            state(refuse);
                                            operator()(ec, 0);
                                            return;
                                        }
                                        //  Accepted. send CC
                                        socket.dst_tsap(receiver_->options().src_tsap());
                                        socket.pdusize(less_tpdu(receiver_->options().pdusize(), socket.transport_option().pdusize()));
                                        tpdu_size pdsize = options_.pdusize();
                                        socket.pdusize(pdsize);
                                        sender_ = sender_ptr(new sender(CC, socket.transport_option(), socket.pdusize()));
                                        state(request);
                                        operator()(ec, 0);
                                        return;
                                    }
                                    default:
                                    {
                                        //  Error. send ER
                                        sender_ = sender_ptr(new sender(ER, socket.transport_option(),
                                                ERT_REASON_TPDU_TYPE, receiver_->errsequense()));
                                        state(refuse);
                                        operator()(ec, 0);
                                        return;
                                    }
                                }
                                break;
                            }
                            case receiver::error:
                            {
                                //  Error. send ER
                                sender_ = sender_ptr(new sender(ER, socket.transport_option(), ERT_REASON_NODEF));
                                state(refuse);
                                operator()(ec, 0);
                                return;
                            }
                        }
                        // Release by means implicit variant  *ref X224 6.7.1.4
                        socket.async_internal_close();
                        handler(ER_PROTOCOL);
                    }

                    void state(stateconnection st) {

                        if (state_ != st)
                            state_ = st;
                    }

                    itu_socket& socket;
                    CheckAcceptHandler handler;
                    stateconnection state_;
                    sender_ptr sender_;
                    receiver_ptr receiver_;
                    tpdu_size tpdusize;

                };


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    

            protected:

                template <typename CheckAcceptHandler>
                void async_check_accept(BOOST_ASIO_MOVE_ARG(CheckAcceptHandler) handler) {

                    typedef check_accept_operation<CheckAcceptHandler > check_accept_operation_type;

                    get_io_service().post(boost::bind(&check_accept_operation_type::start,
                            check_accept_operation_type(*this, handler)));
                }







                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Send operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////       

            public:

                template <typename ConstBufferSequence>
                std::size_t send(const ConstBufferSequence& buffers, std::size_t constraint_size = 0) {

                    return send(buffers, 0, constraint_size);
                }

                template <typename ConstBufferSequence>
                std::size_t send(const ConstBufferSequence& buffers,
                        message_flags flags, std::size_t constraint_size = 0) {
                    error_code ec;
                    std::size_t s = send(buffers, flags, ec, constraint_size);
                    boost::asio::detail::throw_error(ec, "send");

                    return s;
                }

                template <typename ConstBufferSequence>
                std::size_t write_some(const ConstBufferSequence& buffers, std::size_t constraint_size = 0) {
                    error_code ec;
                    std::size_t s = send(buffers, 0, ec, constraint_size);
                    boost::asio::detail::throw_error(ec, "write_some");

                    return s;
                }

                template <typename ConstBufferSequence>
                std::size_t write_some(const ConstBufferSequence& buffers,
                        error_code& ec, std::size_t constraint_size = 0) {

                    return send(buffers, 0, ec, constraint_size);
                }

                template <typename ConstBufferSequence>
                std::size_t send(const ConstBufferSequence& buffers,
                        message_flags flags, error_code& ec, std::size_t constraint_size = 0) {

                    return send_impl(buffers, flags, ec, constraint_size);
                }



                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                     

            private:

                template <typename SendHandler, typename ConstBufferSequence>
                class send_operation {
                    typedef send_operation<SendHandler, ConstBufferSequence> operation_type;


                public:

                    send_operation(itu_socket& sock, SendHandler handlr,
                            const ConstBufferSequence& buffers, message_flags flags, std::size_t constraint_size) :
                    socket(sock),
                    sendsize(constraint_size ? constraint_size : boost::asio::buffer_size(buffers)),
                    handler(handlr),
                    sender_(sender_ptr(new data_sender<ConstBufferSequence>(buffers, sock.pdusize(), constraint_size))),
                    flags_(flags) {
                    }

                    void start(const error_code& ec) {
                        operator()(ec, 0);
                    }

                    void operator()(const error_code& ec, std::size_t bytes_transferred) {
                        if (!ec) {
                            sender_->size(bytes_transferred);
                            if (!sender_->ready()) {
                                socket.super_type::async_send(sender_->pop(), flags_, *this);
                                return;
                            }
                        }
                        handler(ec, ec ? 0 : static_cast<std::size_t> (sendsize));
                    }


                private:

                    itu_socket& socket;
                    std::size_t sendsize;
                    SendHandler handler;
                    sender_ptr sender_;
                    message_flags flags_;

                };


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       

            public:

                template <typename ConstBufferSequence, typename WriteHandler>
                void async_send(const ConstBufferSequence& buffers,
                        BOOST_ASIO_MOVE_ARG(WriteHandler) handler, std::size_t constraint_size = 0) {

                    async_send(buffers, 0, handler, constraint_size);
                }

                template <typename ConstBufferSequence, typename WriteHandler>
                void async_write_some(const ConstBufferSequence& buffers,
                        BOOST_ASIO_MOVE_ARG(WriteHandler) handler, std::size_t constraint_size = 0) {

                    async_send<ConstBufferSequence, WriteHandler > (buffers, 0, handler, constraint_size);
                }

                template <typename ConstBufferSequence, typename WriteHandler>
                void async_send(const ConstBufferSequence& buffers,
                        message_flags flags,
                        BOOST_ASIO_MOVE_ARG(WriteHandler) handler, std::size_t constraint_size = 0) {
                    //BOOST_ASIO_WRITE_HANDLER_CHECK(WriteHandler, handler) type_check;

                    typedef send_operation<WriteHandler, ConstBufferSequence> send_operation_type;


                    get_io_service().post(boost::bind(&send_operation_type::start,
                            send_operation_type(*this, handler, buffers, flags, constraint_size), ready() ? error_code() : ER_INPROGRESS));

                }









                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Receive  operation  //
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

            public:

                template <typename MutableBufferSequence>
                std::size_t receive(const MutableBufferSequence& buffers) {

                    return receive<MutableBufferSequence > (buffers, 0);
                }

                template <typename MutableBufferSequence>
                std::size_t receive(const MutableBufferSequence& buffers,
                        message_flags flags) {
                    error_code ec;
                    std::size_t s = receive(buffers, flags, ec);
                    boost::asio::detail::throw_error(ec, "receive");

                    return s;
                }

                template <typename MutableBufferSequence>
                std::size_t read_some(const MutableBufferSequence& buffers,
                        error_code& ec) {

                    return receive(buffers, 0, ec);
                }

                template <typename MutableBufferSequence>
                std::size_t read_some(const MutableBufferSequence& buffers) {
                    error_code ec;
                    std::size_t s = receive(buffers, 0, ec);
                    boost::asio::detail::throw_error(ec, "read_some");

                    return s;
                }

                template <typename MutableBufferSequence>
                std::size_t receive(const MutableBufferSequence& buffers,
                        message_flags flags, error_code& ec) {

                    return receive_impl(buffers, flags, ec);
                }

            private:


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                      

                template <typename ReceiveHandler, typename Mutable_Buffers>
                class receive_operation {
                    typedef receive_operation<ReceiveHandler, Mutable_Buffers> operation_type;

                    enum stateconnection {
                        response,
                        refuse
                    };

                public:

                    receive_operation(itu_socket& sock, ReceiveHandler handlr,
                            receiver_ptr receive, const Mutable_Buffers& buff, message_flags flags) :
                    socket(sock),
                    handler(handlr),
                    receiver_(receive),
                    buff_(buff),
                    flags_(flags),
                    state_(response) {
                    }

                    void start() {

                        error_code ec;
                        operator()(ec, 0);
                    }

                    void operator()(const error_code& ec, std::size_t bytes_transferred) {
                        if (!ec) {
                            //  *ref X224 6.2
                            switch (state_) {
                                case response:
                                {
                                    receiver_->put(bytes_transferred);
                                    if (!receiver_->ready()) {
                                        socket.super_type::async_receive(boost::asio::buffer(receiver_->buffer()), flags_, *this);
                                        return;
                                    }
                                    parse_response(ec);
                                    return;
                                }
                                case refuse:
                                {
                                    sender_->size(bytes_transferred);
                                    if (!sender_->ready()) {
                                        socket.super_type::async_send(sender_->pop(), 0, *this);
                                        return;
                                    }
                                    // Release by means implicit variant  *ref X224 6.7.1.4
                                    socket.async_internal_close();
                                    handler(ER_PROTOPT, 0);
                                    return;
                                }
                            }
                        }
                        handler(ec, 0);
                    }


                private:

                    void parse_response(const error_code& ec) {

                        switch (receiver_->state()) {
                            case receiver::complete:
                            {
                                switch (receiver_->type()) {
                                    case CR:
                                    {
                                        // ??? unexpected duplecated CR-TPDU *ref X224 6.5.4
                                        socket.waiting_data_size(receiver_->waitdatasize(), receiver_->eof());
                                        handler(ec, 0);
                                        return;
                                    }
                                    case DT:
                                    {
                                        // Data. Ok
                                        socket.waiting_data_size(receiver_->waitdatasize(), receiver_->eof());
                                        handler(ec, static_cast<std::size_t> (receiver_->datasize()));
                                        return;
                                    }
                                    case ER:
                                    {
                                        // Error. // Release by means implicit variant  *ref X224 6.7.1.4
                                        socket.async_internal_close();
                                        handler(ER_PROTOCOL, 0);
                                        return;
                                    }
                                    case DR:
                                    {
                                        // Refuse. // Release by means implicit variant  *ref X224 6.7.1.4
                                        socket.async_internal_close();
                                        handler(ER_REFUSE, 0);
                                        return;
                                    }
                                    default:
                                    {
                                        // Unexpected. Send refuse
                                        sender_ = sender_ptr(new sender(ER, socket.transport_option(),
                                                ERT_REASON_TPDU_TYPE, receiver_->errsequense()));
                                        state(refuse);
                                        operator()(ec, 0);
                                        return;
                                    }
                                }
                                return;
                                break;
                            }
                            case receiver::error:
                            {
                                // Error. Send refuse
                                sender_ = sender_ptr(new sender(ER, socket.transport_option(),
                                        ERT_REASON_NODEF, receiver_->errsequense()));
                                state(refuse);
                                operator()(ec, 0);
                                return;
                                break;
                            }
                        }
                        // Release by means implicit variant  *ref X224 6.7.1.4
                        socket.async_internal_close();
                        handler(ER_PROTOCOL, 0);
                    }

                    void state(stateconnection st) {

                        if (state_ != st)
                            state_ = st;
                    }

                    itu_socket& socket;
                    ReceiveHandler handler;
                    const Mutable_Buffers& buff_;
                    receiver_ptr receiver_;
                    sender_ptr sender_;
                    message_flags flags_;
                    stateconnection state_;
                };


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                      

            public:

                template <typename MutableBufferSequence, typename ReadHandler>
                void async_receive(const MutableBufferSequence& buffers,
                        BOOST_ASIO_MOVE_ARG(ReadHandler) handler) {

                    async_receive<MutableBufferSequence, ReadHandler > (buffers, handler, 0);
                }

                template <typename MutableBufferSequence, typename ReadHandler>
                void async_read_some(const MutableBufferSequence& buffers,
                        BOOST_ASIO_MOVE_ARG(ReadHandler) handler) {

                    async_receive<MutableBufferSequence, ReadHandler > (buffers, 0, handler);
                }

                template <typename MutableBufferSequence, typename ReadHandler>
                void async_receive(const MutableBufferSequence& buffers,
                        message_flags flags,
                        BOOST_ASIO_MOVE_ARG(ReadHandler) handler) {

                    //BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

                    typedef receive_operation<ReadHandler, MutableBufferSequence> receive_operation_type;
                    typedef boost::asio::detail::buffer_sequence_adapter< mutable_buffer, MutableBufferSequence> sequence_adapter_type;

                    get_io_service().post(boost::bind(&receive_operation_type::start, receive_operation_type(*this, handler,
                            receiver_ptr(new receiver(sequence_adapter_type::first(buffers), waiting_data_size(), eof_state())), buffers, flags)));

                }




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  private member  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       

            private:

                const protocol_options& transport_option() const {
                    return transport_option_;
                }

                const tpdu_size& pdusize() const {
                    return tpdusize_;
                };

                void pdusize(const tpdu_size& val) {
                    //transport_option_.pdusize(val);
                    tpdusize_ = val;
                };

                int16_t dst_tsap() const {
                    return transport_option_.dst_tsap();
                }

                void dst_tsap(int16_t val) {
                    transport_option_.dst_tsap(val);
                }

                std::size_t waiting_data_size() const {
                    return waiting_data_size_;
                }

                void waiting_data_size(std::size_t val, bool st) {
                    eof_state_ = st;
                    waiting_data_size_ = val;
                }

                bool eof_state() const {
                    return eof_state_;
                }



                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  private implementator  //
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

                boost::system::error_code async_internal_close() {
                    if (is_open()) {
                        error_code ecc;
                        super_type::shutdown(boost::asio::socket_base::shutdown_both, ecc);
                        super_type::close(ecc); // generate abort error
                        //super_type::shutdown(boost::asio::socket_base::shutdown_both, ecc);
                        return ecc;
                    }
                    return boost::system::error_code();
                }

                boost::system::error_code internal_close() {
                    if (is_open()) {
                        error_code ecc;
                        super_type::shutdown(boost::asio::socket_base::shutdown_both, ecc);
                        super_type::close(ecc);
                    }
                    return boost::system::error_code();
                }

                error_code connect_impl(const endpoint_type& peer_endpoint,
                        error_code& ec) {

                    if (!super_type::connect(peer_endpoint, ec)) {


                        sender_ptr sender_(sender_ptr(new sender(CR, transport_option(), pdusize())));
                        while (!ec && !sender_->ready())
                            sender_->size(super_type::send(sender_->pop(), 0, ec));

                        if (!ec) {
                            receiver_ptr receiver_(receiver_ptr(new receiver()));
                            while (!ec && !receiver_->ready()) {
                                receiver_->put(super_type::receive(boost::asio::buffer(receiver_->buffer()), 0, ec));
                            }
                            if (!ec) {
                                switch (receiver_->state()) {
                                    case receiver::complete:
                                    {
                                        switch (receiver_->type()) {
                                            case CC:
                                            { // Negotiate option *ref X224 6.5.4 a) j)
                                                pdusize(receiver_->options().pdusize());
                                                dst_tsap(receiver_->options().src_tsap());
                                                return ec;
                                            }
                                            case ER: //Both cases indicates connections refuse  *ref X224 6.6.2
                                            case DR:
                                            {
                                                ec = receiver_->errcode();
                                                break;
                                            }
                                            default:
                                            {
                                                ec = ER_PROTOCOL;
                                            }
                                        }
                                        break;
                                    }
                                    case receiver::error:
                                    {
                                        ec = receiver_->errcode();
                                        break;
                                    }
                                    default:
                                    {
                                        ec = ER_PROTOCOL;
                                    }
                                }
                            }
                        }
                    }
                    // Release by means implicit variant  *ref X224 6.7.1.4
                    internal_close();
                    return ec;
                }

                // It is in general agreement with *ref X224 (TPM understands DR)   

                error_code release_impl(error_code& ec, octet_type rsn = DR_REASON_NORM) {
                    if (is_open()) {
                        /*sender_ptr sender_(sender_ptr(new sender(DR, transport_option(), rsn)));
                        while (!ec && !sender_->ready())
                            sender_->size(super_type::send(sender_->pop(), 0, ec));*/
                        // Release by means implicit variant  *ref X224 6.7.1.4
                        internal_close();
                        return ec;
                    }
                    return ec = ER_NOLINK;
                }

                //  *ref X224 6.5.4 

                error_code check_accept_imp(error_code& ec) {

                    bool canceled = false;
                    receiver_ptr receiver_(receiver_ptr(new receiver()));
                    while (!ec && !receiver_->ready()) {
                        receiver_->put(super_type::receive(boost::asio::buffer(receiver_->buffer()), 0, ec));
                    }
                    if (!ec) {

                        sender_ptr sender_;
                        protocol_options options_ = transport_option();
                        switch (receiver_->state()) {
                            case receiver::complete:
                            {
                                switch (receiver_->type()) {
                                    case CR:
                                    {
                                        octet_type error_accept = 0;
                                        if (!negotiate_rfc1006impl_option(options_, receiver_->options(), error_accept)) {
                                            //  Not negotiated.  send DR
                                            canceled = true;
                                            sender_ = sender_ptr(new sender(DR, transport_option(), error_accept));
                                        }
                                        else {
                                            //  Accepted.  send CC
                                            pdusize(less_tpdu(receiver_->options().pdusize(), transport_option().pdusize()));
                                            dst_tsap(receiver_->options().src_tsap());
                                            tpdu_size pdsize = options_.pdusize();
                                            pdusize(pdsize);
                                            sender_ = sender_ptr(new sender(CC, transport_option(), pdusize()));
                                        }
                                        break;
                                    }
                                    default:
                                    {
                                        canceled = true;
                                        //  Error.  send ER
                                        sender_ = sender_ptr(new sender(ER, transport_option(),
                                                ERT_REASON_TPDU_TYPE, receiver_->errsequense()));
                                    }
                                }
                                break;
                            }
                            case receiver::error:
                            {
                                canceled = true;
                                sender_ = sender_ptr(new sender(ER, transport_option(),
                                        ERT_REASON_NODEF, receiver_->errsequense()));
                                break;
                            }
                            default:
                            {
                                // Release by means implicit variant  *ref X224 6.7.1.4
                                internal_close();
                                return ER_PROTOCOL;
                            }
                        }

                        while (!ec && !sender_->ready())
                            sender_->size(super_type::send(sender_->pop(), 0, ec));
                        if (!ec) {
                            if (!canceled) return ec;
                            // Release by means implicit variant  *ref X224 6.7.1.4
                            internal_close();
                            ec = ER_PROTOCOL;
                        }
                    }
                    return ec;
                }

                template <typename ConstBufferSequence>
                std::size_t send_impl(const ConstBufferSequence& buffers,
                        message_flags flags, error_code& ec, std::size_t constraint_size) {
                    if (!ready()) {
                        ec = ER_INPROGRESS;
                        return 0;
                    }
                    std::size_t sendersize = constraint_size ? constraint_size : boost::asio::buffer_size(buffers);
                    sender_ptr sender_(new data_sender<ConstBufferSequence > (buffers, pdusize(), constraint_size));
                    while (!ec && !sender_->ready())
                        sender_->size(super_type::send(sender_->pop(), 0, ec));
                    return ec ? 0 : sendersize;
                }

                //  *ref X224 6.2

                template <typename MutableBufferSequence>
                std::size_t receive_impl(const MutableBufferSequence& buffers,
                        message_flags flags, error_code& ec) {

                    typedef boost::asio::detail::buffer_sequence_adapter< boost::asio::mutable_buffer, MutableBufferSequence> sequence_adapter_type;

                    receiver_ptr receiver_(new receiver(sequence_adapter_type::first(buffers), waiting_data_size(), eof_state()));
                    while (!ec && !receiver_->ready()) {
                        receiver_->put(super_type::receive(boost::asio::buffer(
                                receiver_->buffer()), 0, ec));
                    }

                    if (!ec) {

                        sender_ptr sender_;
                        switch (receiver_->state()) {
                            case receiver::complete:
                            {
                                switch (receiver_->type()) {
                                    case CR:
                                    {
                                        // ??? unexpected duplecated CR-TPDU *ref X224 6.5.4
                                        waiting_data_size(receiver_->waitdatasize(), receiver_->eof());
                                        return 0;
                                    }
                                    case DT:
                                    {
                                        // Data. Ok.
                                        waiting_data_size(receiver_->waitdatasize(), receiver_->eof());
                                        return receiver_->datasize();
                                    }
                                    case ER:
                                    {
                                        // Error. // Release by means implicit variant  *ref X224 6.7.1.4
                                        internal_close();
                                        ec = ER_PROTOCOL;
                                        return 0;
                                    }
                                    case DR:
                                    {
                                        // Refuse. // Release by means implicit variant  *ref X224 6.7.1.4
                                        internal_close();
                                        ec = ER_REFUSE;
                                        return 0;
                                    }
                                    default:
                                    {
                                        // Unexpected. Send refuse
                                        sender_ = sender_ptr(new sender(ER, transport_option(),
                                                ERT_REASON_TPDU_TYPE, receiver_->errsequense()));
                                    }
                                }
                                break;
                            }
                            default:
                            {
                                // Error. Send refuse
                                sender_ = sender_ptr(new sender(ER, transport_option(),
                                        ERT_REASON_TPDU_TYPE, receiver_->errsequense()));
                            }
                        }
                        while (!ec && !sender_->ready())
                            sender_->size(super_type::send(sender_->pop(), 0, ec));
                    }
                    // Release by means implicit variant  *ref X224 6.7.1.4
                    internal_close();
                    ec = ER_PROTOCOL;
                    return 0;
                }

                tpdu_size tpdusize_;
                protocol_options transport_option_;
                std::size_t waiting_data_size_;
                bool eof_state_;
                bool is_acceptor_;
            };






            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  rfc1006 socket_ acceptor  //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                

            class socket_acceptor : protected basic_socket_acceptor<boost::asio::ip::tcp> {
                typedef basic_socket_acceptor<boost::asio::ip::tcp> super_type;

                friend class itu_socket;

            public:

                typedef super_type::protocol_type protocol_type;
                typedef super_type::endpoint_type endpoint_type;
                typedef super_type::implementation_type implementation_type;
                typedef super_type::service_type service_type;
                typedef super_type::message_flags message_flags;
                typedef super_type::native_handle_type native_handle_type;
                typedef super_type::native_type native_type;

                using super_type::assign;
                using super_type::bind;
                using super_type::cancel;
                using super_type::close;
                using super_type::get_io_service;
                using super_type::get_option;
                using super_type::io_control;
                using super_type::is_open;
                using super_type::listen;
                using super_type::local_endpoint;
                using super_type::native;
                using super_type::native_handle;
                using super_type::native_non_blocking;
                using super_type::non_blocking;
                using super_type::open;
                using super_type::set_option;


            protected:

                using super_type::get_service;
                using super_type::get_implementation;


            public:

                explicit socket_acceptor(boost::asio::io_service& io_service, const transport_selector& tsel = NULL_TRANSPORT_SELECTOR)
                : super_type(io_service), src_(0), tselector(tsel) {
                }

                socket_acceptor(boost::asio::io_service& io_service,
                        const endpoint_type& endpoint, const transport_selector& tsel = NULL_TRANSPORT_SELECTOR, bool reuse_addr = true)
                : super_type(io_service, endpoint, reuse_addr), src_(0), tselector(tsel) {
                }

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Accept operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////            

                void accept(itu_socket& peer) {

                    error_code ec;
                    accept_impl(peer, ec);
                    boost::asio::detail::throw_error(ec, "accept");
                }

                error_code accept(
                        itu_socket& peer,
                        error_code& ec) {

                    return accept_impl(peer, ec);
                }

                void accept(itu_socket& peer,
                        endpoint_type& peer_endpoint) {

                    error_code ec;
                    accept_impl(peer, peer_endpoint, ec);
                    boost::asio::detail::throw_error(ec, "accept");
                }

                error_code accept(
                        itu_socket& peer,
                        endpoint_type& peer_endpoint, error_code& ec) {

                    return accept_impl(peer, peer_endpoint, ec);
                }

                template <typename AcceptHandler>
                void async_accept(itu_socket& peer,
                        endpoint_type& peer_endpoint, BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {

                    async_accept_impl(peer, peer_endpoint, handler);
                }

                template <typename AcceptHandler>
                void async_accept(itu_socket& peer,
                        BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {

                    async_accept_impl(peer, handler);
                }


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                         

            private:

                template <typename AcceptHandler>
                class accept_operation {
                    typedef accept_operation<AcceptHandler> operation_type;

                public:

                    accept_operation(AcceptHandler hendlr, itu_socket& sock)
                    : handler(hendlr), socket(sock) {
                    }

                    void execute(const error_code& ec) {
                        if (!ec) {
                            socket.async_check_accept(boost::bind(&operation_type::accept_result, *this,
                                    boost::asio::placeholders::error));
                            return;
                        }
                        handler(ec);
                    }

                    void accept_result(const error_code& ec) {
                        handler(ec);
                    }

                private:
                    AcceptHandler handler;
                    itu_socket& socket;
                };


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                         

                template <typename AcceptHandler>
                void async_accept_impl(itu_socket& peer,
                        endpoint_type& peer_endpoint, BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {

                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;

                    typedef accept_operation<AcceptHandler > accept_operation_type;

                    peer.is_acceptor_ = true;
                    peer.transport_option_ = protocol_options(0, src(), DEFAULT_TPDU_SIZE, tselector.called(), tselector.calling());

                    super_type::async_accept(peer, peer_endpoint, boost::bind(&accept_operation_type::execute,
                            accept_operation_type(handler, peer), boost::asio::placeholders::error));

                }

                template < typename AcceptHandler>
                void async_accept_impl(itu_socket& peer,
                        BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {

                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;

                    typedef accept_operation<AcceptHandler > accept_operation_type;

                    peer.is_acceptor_ = true;
                    peer.transport_option_ = protocol_options(0, src(), DEFAULT_TPDU_SIZE, tselector.called(), tselector.calling());

                    super_type::async_accept(peer, boost::bind(&accept_operation_type::execute,
                            accept_operation_type(handler, peer), boost::asio::placeholders::error));

                }

                error_code accept_impl(
                        itu_socket& peer,
                        endpoint_type& peer_endpoint, error_code& ec) {

                    peer.is_acceptor_ = true;
                    peer.transport_option_ = protocol_options(0, src(), DEFAULT_TPDU_SIZE, tselector.called(), tselector.calling());

                    super_type::accept(peer, peer_endpoint, ec);
                    if (ec)
                        return ec;
                    peer.check_accept(ec);
                    return ec;
                }

                error_code accept_impl(
                        itu_socket& peer,
                        error_code& ec) {

                    peer.is_acceptor_ = true;
                    peer.transport_option_ = protocol_options(0, src(), DEFAULT_TPDU_SIZE, tselector.called(), tselector.calling());

                    super_type::accept(peer, ec);
                    if (ec)
                        return ec;
                    peer.check_accept(ec);
                    return ec;
                }

                int16_t src() const {
                    //boost::mutex::scoped_lock(mtx);
                    return src_ = ((src_ + 1) ? (src_ + 1) : 1);
                }


                mutable int16_t src_;
                transport_selector tselector;
                //boost::mutex mtx;

            };

        }




        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  rfc1006 declaration  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                

        class rfc1006 {
        public:

            typedef boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> endpoint;

            typedef transport_selector selector;
            typedef transport_selector t_selector;

            static rfc1006 v4() {

                return rfc1006(PF_INET);
            }

            static rfc1006 v6() {

                return rfc1006(PF_INET6);
            }

            int type() const {

                return SOCK_STREAM;
            }

            int protocol() const {

                return IPPROTO_TCP;
            }

            int family() const {

                return family_;
            }

            typedef rfc1006impl::itu_socket socket;

            typedef rfc1006impl::socket_acceptor acceptor;

            typedef boost::asio::ip::basic_resolver<boost::asio::ip::tcp> resolver;

#if !defined(BOOST_NO_IOSTREAM)
            //typedef boost::asio::basic_socket_iostream<boost::asio::ip::tcp> iostream;
#endif 


            typedef boost::asio::detail::socket_option::boolean<
            IPPROTO_TCP, TCP_NODELAY> no_delay;

            friend bool operator==(const rfc1006& p1, const rfc1006& p2) {

                return p1.family_ == p2.family_;
            }

            friend bool operator!=(const rfc1006& p1, const rfc1006& p2) {

                return p1.family_ != p2.family_;
            }

        private:

            explicit rfc1006(int family)
            : family_(family) {
            }

            int family_;
        };




    }
}


#endif  /* _BOOST_RFC1006_IMPLEMENTATIUON_H_ */