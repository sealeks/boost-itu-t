//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef     _ITU_X227_PRESENATION_IMPLEMENTATIUON_H_
#define	_ITU_X227_PRESENATION_IMPLEMENTATIUON_H_


#include <boost/itu/x22X/x226.hpp>
#include <boost/itu/x69X/x690.hpp>


namespace boost {
    namespace itu {
        namespace x227impl {

            using boost::asio::basic_socket;
            using boost::asio::basic_socket_acceptor;

            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   x227 utill   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  



            using boost::itu::x226impl::context_id_type;
                    
            typedef oid_type application_context_type;
            typedef std::set<application_context_type> application_context_set;

            const boost::array<boost::asn1::oidindx_type, 5 > ACSE_OID_ARR = {2, 2, 1, 0, 1};
            const boost::asn1::oid_type ACSE_OID = boost::asn1::oid_type(ACSE_OID_ARR);

            //typedef boost::asn1::bitstring_type presentation_req_type;
            //typedef boost::asn1::bitstring_type userses_req_type;
            typedef boost::asn1::bitstring_type application_ver_type;

            const application_ver_type DEFAULT_APPLICATION_VER = boost::asn1::bitstring_type((int8_t) 3, 6);

            /*const presentation_req_type PRSNT_CONTEXT_MREQ = boost::asn1::bitstring_type(true, 0);
            const presentation_req_type PRSNT_REST_MREQ = boost::asn1::bitstring_type(true, 1);
            const presentation_req_type PRSNT_NULL_MREQ = boost::asn1::bitstring_type((int8_t) 0, 6);*/




            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   X.227 protocol_option   //
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

            class application_context {
            public:


                typedef boost::itu::x226impl::presentation_context_set presentation_context_set;
                typedef boost::itu::x226impl::presentation_context context_type;

                application_context(const application_context_set actxs, const presentation_context_set& ctx) : application_context_(actxs) {
                    contexts_ = ctx;
                    contexts_.insert(contexts_.begin(), context_type(ACSE_OID));
                }

                application_context(const application_context_type actx, const presentation_context_set& ctx) {
                    contexts_ = ctx;
                    contexts_.insert(contexts_.begin(), context_type(ACSE_OID));
                    application_context_.insert(actx);
                }

                virtual ~application_context() {
                }

                const presentation_context_set& p_contexts() const {
                    return contexts_;
                }

                const application_context_set& contexts() const {
                    return application_context_;
                }

                const application_context_type& context() const {
                    return application_context_.empty() ? boost::asn1::NULL_OID : (*(application_context_.begin()));
                }
                

            private:

                presentation_context_set contexts_;
                application_context_set application_context_;
            };




            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   X.227 protocol_option   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

            class protocol_option {
            public:

                protocol_option(const application_context_set& appcntexts,
                        const application_selector& asel = NULL_APPLICATION_SELECTOR) :
                app_contexts_(appcntexts), asel_(asel), ver_(DEFAULT_APPLICATION_VER) {
                }

                const application_context_set& app_contexts() const {
                    return app_contexts_;
                }

                application_context_set& app_contexts() {
                    return app_contexts_;
                }

                const application_selector& selector() const {
                    return asel_;
                }

                application_selector& selector() {
                    return asel_;
                }

                const acse_selectorvalue_type& calling() const {
                    return asel_.calling();
                }

                void calling(const acse_selectorvalue_type & val) {
                    asel_.calling(val);
                }

                const acse_selectorvalue_type& called() const {
                    return asel_.called();
                }

                void called(const acse_selectorvalue_type& val) {
                    asel_.called(val);
                }

                bool has_app_context(const abstract_syntax_type& asyntax) const {
                    //context_set::const_iterator it = std::find(contexts_.begin(), contexts_.end(), context_type(asyntax));
                    //return it != contexts_.end();
                    return false;
                }

                const application_ver_type& version() const {
                    return ver_;
                }       
                
                void version(const application_ver_type& ver) {
                    ver_=ver;;
                }                     

            private:

                application_context_set app_contexts_;
                application_selector asel_;
                application_ver_type ver_;
            };




            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  rf1006 application_socket  //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

            class application_socket : protected boost::itu::x226impl::presentation_socket {
                friend class socket_acceptor;

                typedef boost::itu::x226impl::presentation_socket super_type;
                
            public:
                
                typedef boost::itu::x226impl::defined_context_ptr    defined_context_ptr; 
                typedef boost::itu::x226impl::defined_context_map    defined_context_map;


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

                using super_type::request;
                using super_type::async_request;                     
                using super_type::response;
                using super_type::async_response; 
                using super_type::conversation;
                using super_type::async_conversation;  

            protected:



                using super_type::get_service;
                using super_type::get_implementation;

                //using super_type::coder;
                using super_type::dcs;
                using super_type::clear_input;
                using super_type::clear_output;
                using super_type::negotiate_presentation_accept;
                using super_type::presentation_contexts;

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Constructors  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                         

                explicit application_socket(boost::asio::io_service& io_service,
                        const application_context& acntexts,
                        const application_selector& asel = NULL_APPLICATION_SELECTOR)
                : super_type(io_service, acntexts.p_contexts(), asel.pselector()),
                option_(acntexts.contexts(), asel), contexts_(acntexts) {
                }

                application_socket(boost::asio::io_service& io_service,
                        const endpoint_type& endpoint, const application_context& acntexts,
                        const application_selector& asel = NULL_APPLICATION_SELECTOR)
                : super_type(io_service, endpoint, acntexts.p_contexts(), asel.pselector()),
                option_(acntexts.contexts(), asel), contexts_(acntexts) {
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

                    connect_operation(application_socket& sock, ConnectHandler handlr) : socket(sock), handler(handlr) {
                    }

                    void operator()(const error_code& ec) {
                        if (!ec) {
                            error_code ecc;
                            if (socket.connect_response(ecc)) {
                                handler(ecc);
                                return;
                               }
                        }
                        handler(ec);
                    }

                private:

                    application_socket& socket;
                    ConnectHandler handler;
                };



                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    

            public:

                template <typename ConnectHandler>
                void async_connect(const endpoint_type& peer_endpoint,
                        ConnectHandler handler) {


                    error_code ec;
                    if (connect_request(ec)) {
                        handler(ec);
                        return;
                    }

                    typedef connect_operation<ConnectHandler> connect_operation_type;

                    super_type::async_connect(peer_endpoint, boost::bind(&connect_operation_type::operator (),
                            connect_operation_type(*this, handler), boost::asio::placeholders::error));
                }




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  protected member  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    

            protected:

                const application_context& application_contexts() const {
                    return contexts_;
                }

                   defined_context_ptr acse_context() {
                        return acse_context_;
                    }

                   defined_context_ptr acse_context() const {
                        return acse_context_;
                    }

                   asn_coder_ptr acse_coder() const {
                        return acse_context_ ? acse_context_->coder() : asn_coder_ptr();
                    }      
                   
                   asn_coder_ptr acse_coder() {
                        return acse_context_ ? acse_context_->coder() : asn_coder_ptr();
                    }       
                   

                     

            private:

                void option(const application_context& ctx, const application_selector& asel) {
                    contexts_ = ctx;
                    option_.called(asel.called());
                    option_.calling(asel.calling());
                }

                const protocol_option & option() const {
                    return option_;
                }

                protocol_option & option() {
                    return option_;
                }



                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  private implementator  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
                
                
                error_code connect_request(error_code& ec);
                
                error_code connect_response(error_code& ec);

                error_code connect_impl(const endpoint_type& peer_endpoint,
                        error_code& ec) {
                    if (!connect_request(ec)) {
                        if (!super_type::connect(peer_endpoint, ec))
                            connect_response(ec);
                    }
                    return ec;
                }



                protocol_option option_;
                application_context contexts_;
                defined_context_ptr acse_context_;
            };








            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  x227 socket_acceptor //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            class socket_acceptor : public boost::itu::x226impl::socket_acceptor {
                typedef boost::itu::x226impl::socket_acceptor super_type;

                friend class application_socket;

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

                explicit socket_acceptor(boost::asio::io_service& io_service, 
                        const application_context& acntexts,
                        const application_selector& asel = NULL_APPLICATION_SELECTOR)
                : super_type(io_service, acntexts.p_contexts(), asel.pselector()), 
                 contexts_(acntexts), asel_(asel) {
                }

                socket_acceptor(boost::asio::io_service& io_service,
                        const endpoint_type& endpoint, 
                        const application_context& acntexts, 
                        const application_selector& asel = NULL_APPLICATION_SELECTOR,
                        bool reuse_addr = true)
                : super_type(io_service, endpoint, acntexts.p_contexts(), asel.pselector(),reuse_addr),
                contexts_(acntexts), asel_(asel) {
                }




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Accept operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                          

                error_code accept(
                        application_socket& peer,
                        error_code& ec) {
                    return accept_impl(peer, ec);
                }

                error_code accept(
                        application_socket& peer,
                        endpoint_type& peer_endpoint, error_code& ec) {
                    return accept_impl(peer, peer_endpoint, ec);
                }

                template <typename AcceptHandler>
                void async_accept(application_socket& peer,
                        BOOST_ITU_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    async_accept_impl(peer, BOOST_ASIO_MOVE_CAST(AcceptHandler)(handler));
                }

                template <typename AcceptHandler>
                void async_accept(application_socket& peer,
                        endpoint_type& peer_endpoint, BOOST_ITU_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    async_accept_impl(peer, peer_endpoint, BOOST_ASIO_MOVE_CAST(AcceptHandler)(handler));
                }



            private:


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Private implementator  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                     

                template <typename AcceptHandler>
                void async_accept_impl(application_socket& peer,
                        endpoint_type& peer_endpoint, BOOST_ITU_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    //peer.option(contexts_, asel_);
                    super_type::async_accept(peer, peer_endpoint, handler);
                }

                template <typename AcceptHandler>
                void async_accept_impl(application_socket& peer,
                        BOOST_ITU_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    //peer.option(contexts_, asel_);
                    super_type::async_accept(peer, handler);
                }

                error_code accept_impl(
                        application_socket& peer,
                        endpoint_type& peer_endpoint, error_code& ec) {
                    //peer.option(contexts_, asel_);
                    super_type::accept(peer, peer_endpoint, ec);
                    return ec;
                }

                error_code accept_impl(
                        application_socket& peer,
                        error_code& ec) {
                    //peer.option(contexts_, asel_);
                    super_type::accept(peer, ec);
                    return ec;
                }


                application_context contexts_;
                application_selector asel_;

            };

        }


        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  x227 declaration  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                  

        class x227 {
        public:

            typedef boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> endpoint;

            typedef application_selector selector;
            typedef application_selector a_selector;
            typedef presentation_selector p_selector;
            typedef session_selector s_selector;
            typedef transport_selector t_selector;

            static x227 v4() {

                return x227(PF_INET);
            }

            static x227 v6() {

                return x227(PF_INET6);
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

            typedef x227impl::application_socket socket;

            typedef x227impl::socket_acceptor acceptor;

            typedef boost::asio::ip::basic_resolver<boost::asio::ip::tcp> resolver;

#if !defined(BOOST_NO_IOSTREAM)
            typedef boost::asio::basic_socket_iostream<boost::asio::ip::tcp> iostream;
#endif 


            typedef boost::asio::detail::socket_option::boolean<
            IPPROTO_TCP, TCP_NODELAY> no_delay;

            /// Compare two protocols for equality.

            friend bool operator==(const x227& p1, const x227& p2) {

                return p1.family_ == p2.family_;
            }

            friend bool operator!=(const x227& p1, const x227& p2) {

                return p1.family_ != p2.family_;
            }

        private:

            explicit x227(int family)
            : family_(family) {
            }

            int family_;
        };



    }
} // namespace boost



#endif	

