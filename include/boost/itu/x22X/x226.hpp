//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef     _ITU_X226_PRESENATION_IMPLEMENTATIUON_H_
#define	_ITU_X226_PRESENATION_IMPLEMENTATIUON_H_


#include <boost/itu/x22X/x225.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

namespace boost {
    namespace itu {
        namespace x226impl {

            using boost::asio::basic_socket;
            using boost::asio::basic_socket_acceptor;


            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   x226 utill   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

            const encoding_set DEFAULT_ENCODINGS = BER_ENCODING | CER_ENCODING | DER_ENCODING;// PER_ALIGNED_ENCODING;


            // presentation_context

            class presentation_context {

            public:

                presentation_context(const abstract_syntax_type& asyntax, encoding_set encing = DEFAULT_ENCODINGS) :
                abstract_syntax_(asyntax), encodings_(encing) {
                }

                const abstract_syntax_type& abstract_syntax() const {
                    return abstract_syntax_;
                }

                encoding_set encodings() const {
                    return encodings_;
                }

                void encodings(encoding_set val) {
                    encodings_ = val;
                }

                encoding_rule encoding() const {
                    return to_encoding_rule(encodings_);
                }

                void encoding(encoding_rule val) {
                    encodings_ = to_encoding_rule(val);
                }

                friend bool operator==(const presentation_context& ls, const presentation_context& rs) {
                    return ls.abstract_syntax_ == rs.abstract_syntax_;
                }

            private:
                abstract_syntax_type abstract_syntax_;
                encoding_set encodings_;
            };

            const presentation_context NULL_CONTEXT = presentation_context(abstract_syntax_type(), NULL_ENCODING);

            // presentation_context_set            

            typedef std::vector<presentation_context> presentation_context_set;



            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   X.226 protocol_option   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  


            typedef boost::asn1::bitstring_type presentation_req_type;
            typedef boost::asn1::bitstring_type userses_req_type;
            typedef boost::asn1::bitstring_type presentation_ver_type;

            const presentation_ver_type PRSNT_VERSION = boost::asn1::bitstring_type(true, 0);

            const presentation_req_type PRSNT_CONTEXT_MREQ = boost::asn1::bitstring_type(true, 0);
            const presentation_req_type PRSNT_REST_MREQ = boost::asn1::bitstring_type(true, 1);
            const presentation_req_type PRSNT_NULL_MREQ = boost::asn1::bitstring_type((int8_t) 0, 6);

            typedef int context_id_type;

            class protocol_option {

            public:

                protocol_option(const presentation_context_set& cntexts, const presentation_selector& psel,
                        const presentation_req_type& req = presentation_req_type()) :
                contexts_(cntexts), preq_(req), psel_(psel) {
                }

                const presentation_context_set& contexts() const {
                    return contexts_;
                }

                presentation_context_set& contexts() {
                    return contexts_;
                }

                const presentation_selector& selector() const {
                    return psel_;
                }

                presentation_selector& selector() {
                    return psel_;
                }

                const octet_sequnce & calling() const {
                    return psel_.calling();
                }

                void calling(const octet_sequnce & val) {
                    psel_.calling(val);
                }

                const octet_sequnce & called() const {
                    return psel_.called();
                }

                void called(const octet_sequnce & val) {
                    psel_.called(val);
                }

                bool has_abstract_syntax(const abstract_syntax_type& asyntax) const {
                    presentation_context_set::const_iterator it = std::find(contexts_.begin(), contexts_.end(), presentation_context(asyntax));
                    return it != contexts_.end();
                }

                bool has_context(const abstract_syntax_type& asyntax, encoding_set eset) const {
                    presentation_context_set::const_iterator it = std::find(contexts_.begin(), contexts_.end(), presentation_context(asyntax));
                    if (it != contexts_.end())
                        return (it->encodings() & eset);
                    return false;
                }

                const presentation_context& context(const abstract_syntax_type& asyntax) const {
                    presentation_context_set::const_iterator it = std::find(contexts_.begin(), contexts_.end(), presentation_context(asyntax));
                    return it != contexts_.end() ? (*it) : NULL_CONTEXT;
                }

                encoding_set encodings(const abstract_syntax_type& asyntax) const {
                    presentation_context_set::const_iterator it = std::find(contexts_.begin(), contexts_.end(), presentation_context(asyntax));
                    return it != contexts_.end() ? it->encodings() : 0;
                }

                encoding_rule encoding(const abstract_syntax_type& asyntax) const {
                    presentation_context_set::const_iterator it = std::find(contexts_.begin(), contexts_.end(), presentation_context(asyntax));
                    return it != contexts_.end() ? it->encodings() : 0;
                }

                void encodings(const abstract_syntax_type& asyntax, encoding_set val) {
                    presentation_context_set::iterator it = std::find(contexts_.begin(), contexts_.end(), presentation_context(asyntax));
                    if (it != contexts_.end())
                        it->encodings(val);
                }

                void encoding(const abstract_syntax_type& asyntax, encoding_rule val) {
                    presentation_context_set::iterator it = std::find(contexts_.begin(), contexts_.end(), presentation_context(asyntax));
                    if (it != contexts_.end())
                        it->encoding(val);
                }

                const presentation_req_type& p_requirements() const {
                    return preq_;
                }

                void p_requirements(const presentation_req_type& val) {
                    preq_ = val;
                }

                const presentation_ver_type& version() const {
                    return PRSNT_VERSION;
                }


            private:

                presentation_context_set contexts_;
                presentation_req_type preq_;
                presentation_selector psel_;
            };



            typedef boost::asn1::x690::input_coder x690_input_coder_type;
            typedef boost::asn1::x690::output_coder x690_output_coder_type;
            typedef boost::itu::asn_coder_templ<x690_input_coder_type, x690_output_coder_type> x690_coder_type;

            typedef boost::asn1::x691::input_coder x691_input_coder_type;
            typedef boost::asn1::x691::output_coder x691_output_coder_type;
            typedef boost::itu::asn_coder_templ<x691_input_coder_type, x691_output_coder_type> x691_coder_type;







            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   defined_context   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                   

            class defined_context {

            public:

                defined_context(const presentation_context& context);

                const abstract_syntax_type& abstract_syntax() const {
                    return context_.abstract_syntax();
                }

                encoding_rule encoding() const {
                    return context_.encoding();
                }

                encoding_set encodings() const {
                    return context_.encodings();
                }

                bool encoding(encoding_rule val);

                bool valid() {
                    return static_cast<bool> (coder_);
                }

                asn_coder_ptr coder() {
                    return coder_;
                }

                template<typename T> bool set(T& data) {
                    if (coder_) {
                        switch (encoding()) {
                            case BER_ENCODING:
                            case DER_ENCODING:
                            case CER_ENCODING:
                            {
                                data.serialize(boost::static_pointer_cast<x690_coder_type, basic_coder > (coder_)->output());
                                return true;
                            };
                            default:
                            {
                            }
                        }
                    }
                    return false;
                }

                template<typename T> bool get(T& data) {
                    if (coder_) {
                        switch (encoding()) {
                            case BER_ENCODING:
                            case DER_ENCODING:
                            case CER_ENCODING:
                            {
                                data.serialize(boost::static_pointer_cast<x690_coder_type, basic_coder > (coder_)->input());
                                return true;
                            };
                            default:
                            {
                            }
                        }
                    }
                    return false;
                }


            private:
                presentation_context context_;
                asn_coder_ptr coder_;
            };




            typedef shared_ptr<defined_context> defined_context_ptr;

            inline bool operator<(defined_context_ptr ls, defined_context_ptr rs) {
                if (ls && rs)
                    return ls->abstract_syntax() < rs->abstract_syntax();
                return rs ? true : false;
            }

            typedef std::pair<context_id_type, defined_context_ptr> defined_presentation_context;
            typedef std::map<context_id_type, defined_context_ptr> defined_context_map;




            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   presentation CS   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////               

            class defined_context_set {

            public:

                defined_context_set() :
                nextid_(0), preq_() {
                }

                defined_context_set(const protocol_option& opt, context_id_type id = 1) :
                nextid_(id), preq_(opt.p_requirements()) {
                    for (presentation_context_set::const_iterator it = opt.contexts().begin(); it != opt.contexts().end(); ++it)
                        insert_context(*it);
                }

                defined_context_ptr default_context() const {
                    return (is_default_context() && (!contexts_.empty())) ? contexts_.begin()->second : defined_context_ptr();
                }

                defined_context_ptr context(const context_id_type id) {
                    defined_context_map::iterator it = contexts_.find(id);
                    return it != contexts_.end() ? it->second : defined_context_ptr();
                }

                defined_context_ptr context(const abstract_syntax_type& oid) {
                    for (defined_context_map::iterator it = contexts_.begin(); it != contexts_.end(); ++it)
                        if (it->second->abstract_syntax() == oid && it->second->coder())
                            return it->second;
                    return defined_context_ptr();
                }

                context_id_type insert_context(context_id_type id, const presentation_context& context);

                context_id_type remove_contex(context_id_type id);

                bool transfer_syntax(context_id_type id, const transfer_syntax_type& val);

                bool transfer_syntax(abstract_syntax_type id, const transfer_syntax_type& val);

                asn_coder_ptr find(context_id_type id) {
                    defined_context_map::iterator it = contexts_.find(id);
                    return it != contexts_.end() ? it->second->coder() : asn_coder_ptr();
                }

                asn_coder_ptr exists(context_id_type id) {
                    defined_context_map::iterator it = contexts_.find(id);
                    return it != contexts_.end() ? it->second->coder() : asn_coder_ptr();
                }

                void clear() {
                    for (defined_context_map::iterator it = contexts_.begin(); it != contexts_.end(); ++it) {
                        if (it->second->coder())
                            it->second->coder()->clear();
                    }
                }

                void clear_output() {
                    for (defined_context_map::iterator it = contexts_.begin(); it != contexts_.end(); ++it) {
                        if (it->second->coder())
                            it->second->coder()->clear_output();
                    }
                }

                void clear_input() {
                    for (defined_context_map::iterator it = contexts_.begin(); it != contexts_.end(); ++it) {
                        if (it->second->coder())
                            it->second->coder()->clear_input();
                    }
                }

                bool has_input() const {
                    for (defined_context_map::const_iterator it = contexts_.begin(); it != contexts_.end(); ++it) {
                        if (it->second->coder() && (it->second->coder()->in()->size()))
                            return true;
                    }
                    return false;
                }

                template<typename T> bool set(context_id_type id, T& data) {
                    defined_context_map::iterator it = contexts_.find(id);
                    if (it != contexts_.end())
                        return it->second->set(data);
                    return false;
                }

                template<typename T> bool get(context_id_type id, T& data) {
                    defined_context_map::iterator it = contexts_.find(id);
                    if (it != contexts_.end())
                        return it->second->get(data);
                    return false;
                }

                template<typename T> bool set(const oid_type& oid, T& data) {
                    defined_context_map::iterator it = find(oid);
                    if (it != contexts_.end())
                        return it->second->set(data);
                    return false;
                }

                template<typename T> bool get(const oid_type& oid, T& data) {
                    defined_context_map::iterator it = find(oid);
                    if (it != contexts_.end())
                        return it->second->get(data);
                    return false;
                }

                defined_context_map& contexts() {
                    return contexts_;
                }

                const defined_context_map& contexts() const {
                    return contexts_;
                }

                const presentation_req_type& p_requirements() const {
                    return preq_;
                }

                void p_requirements(const presentation_req_type& val) {
                    preq_ = val;
                }

                bool is_context_menagment() const {
                    return ((!preq_.empty()) && (preq_.bit(0)));
                }

                bool is_restoration() const {
                    return ((preq_.size() > 1) && (preq_.bit(1)));
                }

                bool is_simple_encoding() const {
                    return ((contexts_.size() == 1) && (!is_context_menagment()));
                }

                bool is_default_context() const {
                    return ((contexts_.size() == 1) && (!is_context_menagment()));
                }


            private:

                context_id_type insert_context(const presentation_context& context);

                defined_context_map::iterator find(const oid_type & oid) {
                    for (defined_context_map::iterator it = contexts_.begin(); it != contexts_.end(); ++it) {
                        if (it->second->abstract_syntax() == oid && it->second->coder())
                            return it;
                    }
                    return contexts_.end();
                }

                context_id_type nextid_;
                presentation_req_type preq_;
                defined_context_map contexts_;

            };

            typedef shared_ptr<defined_context_set> defined_context_set_ptr;

            enum ppdu_enum {

                null_ppdu,
                error_ppdu,
                cp_ppdu,
                cpa_ppdu,
                cpr_ppdu,
                dt_ppdu,
                ac_ppdu,
                aca_ppdu,
                aru_ppdu,
                arp_ppdu
            };

            enum negotiate_rslt_enum {

                error_negotiate,
                accept_negotiate,
                reject_negotiate
            };



            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  rf1006 presentation_socket  //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

            class presentation_socket : protected boost::itu::x225impl::itu_socket {

                friend class socket_acceptor;

                typedef boost::itu::x225impl::itu_socket super_type;

                typedef x690_coder_type presentation_coder_type;
                typedef shared_ptr<presentation_coder_type> presentation_asn_coder_ptr;


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

                //using super_type::ready;
                using super_type::is_acceptor;

                /*using super_type::request;
                using super_type::async_request;                     
                using super_type::response;
                using super_type::async_response; 
                using super_type::conversation;
                using super_type::async_conversation;  */

            protected:


                using super_type::get_service;
                using super_type::get_implementation;


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Constructors  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                         

                explicit presentation_socket(boost::asio::io_service& io_service,
                        const presentation_context_set& cntexts,
                        const presentation_selector& psel = NULL_PRESENTATION_SELECTOR)
                : super_type(io_service, psel.sselector(), asn_coder_ptr(new presentation_coder_type())),
                option_(cntexts, psel), dcs_(new defined_context_set(option_)), contexts_(cntexts) {
                }

                presentation_socket(boost::asio::io_service& io_service,
                        const endpoint_type& endpoint, const presentation_context_set& cntexts,
                        const presentation_selector& psel = NULL_PRESENTATION_SELECTOR)
                : super_type(io_service, endpoint, psel.sselector(), asn_coder_ptr(new presentation_coder_type())),
                option_(cntexts, psel), dcs_(new defined_context_set(option_)), contexts_(cntexts) {
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

                public:

                    connect_operation(presentation_socket& sock, ConnectHandler handlr) : socket(sock), handler(handlr) {
                    }

                    void operator()(const error_code& ec) {
                        if (!ec) {
                            if (error_code erreslt = socket.parse_CR()) {
                                handler(erreslt);
                                return;
                            }
                        }

                        socket.clear_output();
                        handler(ec);
                    }

                private:

                    presentation_socket& socket;
                    ConnectHandler handler;
                };



                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    

            public:

                template <typename ConnectHandler>
                void async_connect(const endpoint_type& peer_endpoint,
                        ConnectHandler handler) {

                    clear_input();

                    if (error_code erreslt = build_CP_type()) {
                        handler(ER_PROTOCOL);
                        return;
                    }

                    typedef connect_operation<ConnectHandler> connect_operation_type;

                    super_type::async_connect(peer_endpoint, boost::bind(&connect_operation_type::operator(),
                            connect_operation_type(*this, handler), boost::asio::placeholders::error));
                }









                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  request operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

                error_code request(error_code& ec) {
                    clear_input();
                    if (ec = build_DT_type())
                        return ec;
                    super_type::request(ec);
                    clear_output();
                    return ec;
                }


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     

            private:

                template <typename RequestHandler>
                class request_operation {

                public:

                    request_operation(presentation_socket& sock, RequestHandler handlr) :
                    socket(sock),
                    handler(handlr) {
                    }

                    void operator()(const error_code& ec) {
                        socket.clear_output();
                        handler(ec);
                    }

                private:
                    presentation_socket& socket;
                    RequestHandler handler;
                };



                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                         

            public:

                template <typename RequestHandler>
                void async_request(
                        RequestHandler handler) {

                    typedef request_operation<RequestHandler> request_operation_type;

                    clear_input();

                    if (error_code erreslt = build_DT_type())
                        handler(erreslt);

                    super_type::async_request(boost::bind(&request_operation_type::operator(),
                            request_operation_type(*this, handler), boost::asio::placeholders::error));
                }








                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  response operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

                error_code response(error_code& ec) {
                    clear_input();
                    super_type::request(ec);
                    clear_output();
                    if (!ec) {
                        ppdu_enum ppdutype;
                        ec = parse_RESPONSE(ppdutype);
                    }
                    return ec;
                }

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                        


            private:

                template <typename ResponseHandler>
                class response_operation {

                public:

                    response_operation(presentation_socket& sock, ResponseHandler handlr) :
                    socket(sock),
                    handler(handlr) {
                    }

                    void operator()(const error_code& ec) {
                        socket.clear_output();
                        if (!ec) {
                            ppdu_enum ppdutype;
                            if (error_code erreslt = socket.parse_RESPONSE(ppdutype)) {
                                handler(erreslt);
                                return;
                            }
                        }
                        handler(ec);
                    }

                private:
                    presentation_socket& socket;
                    ResponseHandler handler;
                };




            public:

                template <typename ResponseHandler>
                void async_response(
                        ResponseHandler handler) {

                    //BOOST_ASIO_CONNECT_HANDLER_CHECK(ResponseHandler, handler) type_check;

                    typedef response_operation<ResponseHandler> response_operation_type;

                    clear_input();

                    super_type::async_response(
                            boost::bind(&response_operation_type::operator(),
                            response_operation_type(*this, handler), boost::asio::placeholders::error));
                }







                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  conversation operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

                error_code& conversation(error_code& ec) {
                    clear_input();
                    if (ec = build_DT_type())
                        return ec;
                    super_type::conversation(ec);
                    clear_output();
                    if (!ec) {
                        ppdu_enum ppdutype;
                        ec = parse_RESPONSE(ppdutype);
                    }
                    return ec;
                }

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                        


            private:

                template <typename ConversationHandler>
                class conversation_operation {

                public:

                    conversation_operation(presentation_socket& sock, ConversationHandler handlr) :
                    socket(sock),
                    handler(handlr) {
                    }

                    void operator()(const error_code& ec) {
                        socket.clear_output();
                        if (!ec) {
                            ppdu_enum ppdutype;
                            if (error_code erreslt = socket.parse_RESPONSE(ppdutype)) {
                                handler(erreslt);
                                return;
                            }
                        }
                        handler(ec);
                    }

                private:
                    presentation_socket& socket;
                    ConversationHandler handler;

                };


            public:

                template <typename ConversationHandler>
                void async_conversation(
                        ConversationHandler handler) {

                    //BOOST_ASIO_CONNECT_HANDLER_CHECK(ConversationHandler, handler) type_check;

                    if (error_code erreslt = build_DT_type())
                        handler(erreslt);

                    typedef conversation_operation<ConversationHandler> conversation_operation_type;

                    clear_input();

                    super_type::async_response(
                            boost::bind(&conversation_operation_type::operator(),
                            conversation_operation_type(*this, handler), boost::asio::placeholders::error));
                }


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  protected member  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    

            protected:

                presentation_asn_coder_ptr coder() {
                    return boost::static_pointer_cast<presentation_coder_type, basic_coder > (super_type::rootcoder());
                }

                presentation_asn_coder_ptr coder() const {
                    return boost::static_pointer_cast<presentation_coder_type, basic_coder > (super_type::rootcoder());
                }

                void clear_input() {
                    if (dcs())
                        dcs()->clear_input();
                }

                void clear_output() {
                    if (dcs())
                        dcs()->clear_output();
                }

                defined_context_set_ptr dcs() {
                    return dcs_;
                }

                defined_context_set_ptr dcs() const {
                    return dcs_;
                }

                const presentation_context_set& presentation_contexts() const {
                    return contexts_;
                }

                virtual bool negotiate_presentation_accept() {
                    return true;
                }

            private:

                void option(const presentation_context_set& ctx, const presentation_selector& psel) {
                    contexts_ = ctx;
                    option_.called(psel.called());
                    option_.calling(psel.calling());
                }

                const protocol_option& option() const {
                    return option_;
                }

                protocol_option& option() {
                    return option_;
                }



                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  private implementator  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

                error_code connect_impl(const endpoint_type& peer_endpoint,
                        error_code& ec) {
                    ec = build_CP_type();
                    if (!ec) {
                        if (!super_type::connect(peer_endpoint, ec)) {
                            return ec = parse_CR();
                        }
                    }
                    return ec;
                }


                ppdu_enum check_response();

                error_code build_DT_type();

                error_code build_CP_type();

                error_code parse_CR();

                error_code parse_RESPONSE(ppdu_enum& ppdutype);

                negotiate_rslt_enum parse_CP();


                protocol_option option_;
                defined_context_set_ptr dcs_;
                presentation_context_set contexts_;
            };








            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  x226 socket_acceptor //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            class socket_acceptor : public boost::itu::x225impl::socket_acceptor {

                typedef boost::itu::x225impl::socket_acceptor super_type;

                friend class presentation_socket;

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




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Constructors  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                          

                explicit socket_acceptor(boost::asio::io_service& io_service, const presentation_context_set& cntexts,
                        const presentation_selector& psel = NULL_PRESENTATION_SELECTOR)
                : super_type(io_service, psel.sselector()), contexts_(cntexts), psel_(psel) {
                }

                socket_acceptor(boost::asio::io_service& io_service,
                        const endpoint_type& endpoint, const presentation_context_set& cntexts,
                        const presentation_selector& psel = NULL_PRESENTATION_SELECTOR, bool reuse_addr = true)
                : super_type(io_service, endpoint, psel.sselector(), reuse_addr), contexts_(cntexts), psel_(psel) {
                }




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Accept operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                          

                error_code accept(
                        presentation_socket& peer,
                        error_code& ec) {
                    return accept_impl(peer, ec);
                }

                error_code accept(
                        presentation_socket& peer,
                        endpoint_type& peer_endpoint, error_code& ec) {
                    return accept_impl(peer, peer_endpoint, ec);
                }

                template <typename AcceptHandler>
                void async_accept(presentation_socket& peer,
                        BOOST_ITU_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    async_accept_impl(peer, BOOST_ASIO_MOVE_CAST(AcceptHandler)(handler));
                }

                template <typename AcceptHandler>
                void async_accept(presentation_socket& peer,
                        endpoint_type& peer_endpoint, BOOST_ITU_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    async_accept_impl(peer, peer_endpoint, BOOST_ASIO_MOVE_CAST(AcceptHandler)(handler));
                }



            private:


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Private implementator  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                     

                template <typename AcceptHandler>
                void async_accept_impl(presentation_socket& peer,
                        endpoint_type& peer_endpoint, BOOST_ITU_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    peer.option(contexts_, psel_);
                    super_type::async_accept(peer, peer_endpoint, handler);
                }

                template <typename AcceptHandler>
                void async_accept_impl(presentation_socket& peer,
                        BOOST_ITU_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    peer.option(contexts_, psel_);
                    super_type::async_accept(peer, handler);
                }

                error_code accept_impl(
                        presentation_socket& peer,
                        endpoint_type& peer_endpoint, error_code& ec) {
                    peer.option(contexts_, psel_);
                    super_type::accept(peer, peer_endpoint, ec);
                    return ec;
                }

                error_code accept_impl(
                        presentation_socket& peer,
                        error_code& ec) {
                    peer.option(contexts_, psel_);
                    super_type::accept(peer, ec);
                    return ec;
                }


                presentation_context_set contexts_;
                presentation_selector psel_;

            };

        }


        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  x226 declaration  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                  

        class x226 {

        public:

            typedef boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> endpoint;

            typedef presentation_selector selector;
            typedef presentation_selector p_selector;
            typedef session_selector s_selector;
            typedef transport_selector t_selector;

            static x226 v4() {

                return x226(PF_INET);
            }

            static x226 v6() {

                return x226(PF_INET6);
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

            typedef x226impl::presentation_socket socket;

            typedef x226impl::socket_acceptor acceptor;

            typedef boost::asio::ip::basic_resolver<boost::asio::ip::tcp> resolver;

#if !defined(BOOST_NO_IOSTREAM)
            typedef boost::asio::basic_socket_iostream<boost::asio::ip::tcp> iostream;
#endif 


            typedef boost::asio::detail::socket_option::boolean<
            IPPROTO_TCP, TCP_NODELAY> no_delay;

            /// Compare two protocols for equality.

            friend bool operator==(const x226& p1, const x226& p2) {

                return p1.family_ == p2.family_;
            }

            friend bool operator!=(const x226& p1, const x226& p2) {

                return p1.family_ != p2.family_;
            }

        private:

            explicit x226(int family)
            : family_(family) {
            }

            int family_;
        };

        typedef boost::itu::x226impl::defined_context_set_ptr defined_context_set_ptr;
        typedef boost::itu::x226impl::protocol_option presentation_option;

    }
} // namespace boost



#endif	

