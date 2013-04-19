/* 
 * File:   mmssocket.h
 * Author: sealeks@mail.ru
 *
 * Created on 27 Р¤РµРІСЂР°Р»СЊ 2013 Рі., 22:26
 */

#ifndef MMSSOCKET_H
#define	MMSSOCKET_H

#include <boost/itu/x22X/x227.hpp>
#include "mms/MMS-SCI-Module-1.h"


namespace prot9506 {

    namespace ACSE = ACSE_1;
    namespace MMS = ISO_9506_MMS_1;
    namespace MMSO = MMS_Object_Module_1;


    typedef boost::itu::defined_context_set_ptr defined_context_set_ptr;
    typedef MMSO::Unsigned32 invoke_id_type;

    const invoke_id_type MAXINVOKEID = 100000;


    using boost::itu::application_selector;
    using boost::itu::NULL_APPLICATION_SELECTOR;

    const boost::array<boost::asn1::oidindx_type, 5 > MMS_ARR = {1, 0, 9506, 2, 1};
    const boost::asn1::oid_type MMS_OID = boost::asn1::oid_type(MMS_ARR);

    const boost::array<boost::asn1::oidindx_type, 5 > MMSA_ARR = {1, 0, 9506, 2, 3};
    const boost::asn1::oid_type MMSA_OID = boost::asn1::oid_type(MMSA_ARR);


    //presentation_option init_synaxes();


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  Operation template  //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  confirmed_operation  template//
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

    template< typename REQ, typename RSP, MMS::ConfirmedServiceRequest_enum REQID, MMS::ConfirmedServiceResponse_enum RSPID>
    class confirmed_operation {
    public:

        typedef REQ request_type;
        typedef RSP response_type;
        typedef MMS::RejectPDU reject_type;
        typedef MMS::ServiceError serviceerror_type;

        typedef boost::shared_ptr<request_type> request_type_ptr;
        typedef boost::shared_ptr<response_type> response_type_ptr;
        typedef boost::shared_ptr<reject_type> reject_type_ptr;
        typedef boost::shared_ptr<serviceerror_type> serviceerror_type_ptr;

        enum state_type {
            noproccess_state,
            ok_state,
            rejected_state,
            error_state,
            proterror_state,
            unexpid_state,
            unexp_resp_state
        };

        confirmed_operation() : invokeid_(), error_(), state_(noproccess_state) {
        }

        request_type_ptr request() const {
            return request_;
        }

        response_type_ptr response() const {
            return response_;
        }

        reject_type_ptr reject() const {
            return reject_;
        }

        serviceerror_type_ptr serviceerror() const {
            return serviceerror_;
        }

        void request(request_type_ptr val) {
            request_ = val;
        }

        void response(response_type_ptr val) {
            state_ = ok_state;
            response_ = val;
        }

        void reject(reject_type_ptr val) {
            state_ = rejected_state;
            reject_ = val;
        }

        void serviceerror(serviceerror_type_ptr val) {
            state_ = error_state;
            serviceerror_ = val;
        }

        request_type_ptr request_new() {
            if (!request_) request_ = request_type_ptr(new request_type());
            return request_;
        }

        response_type_ptr response_new() {
            state_ = ok_state;
            if (!response_) response_ = response_type_ptr(new response_type());
            return response_;
        }

        reject_type_ptr reject_new() {
            state_ = rejected_state;
            if (!reject_) reject_ = reject_type_ptr(new reject_type());
            return reject_;
        }

        serviceerror_type_ptr serviceerror_new() {
            state_ = error_state;
            if (!serviceerror_) serviceerror_ = serviceerror_type_ptr(new serviceerror_type_ptr());
            return serviceerror_;
        }

        invoke_id_type invokeid() const {
            return invokeid_;
        }

        void invokeid(invoke_id_type val) {
            invokeid_ = val;
        }

        void error(const boost::system::error_code& val) {
            error_ = val;
            if (error_)
                state_ = proterror_state;
        }

        state_type state() const {
            return state_;
        }

        void setunexpetedIvoke() {
            state_ = error_state;
        }

        void setunexpetedresp() {
            state_ = unexp_resp_state;
        }

        MMS::ConfirmedServiceRequest_enum reqid() const {
            return REQID;
        }

        MMS::ConfirmedServiceResponse_enum rspid() const {
            return RSPID;
        }

        operator bool() const {
            return state_ == ok_state;
        }


    private:
        invoke_id_type invokeid_;
        request_type_ptr request_;
        response_type_ptr response_;
        reject_type_ptr reject_;
        serviceerror_type_ptr serviceerror_;
        boost::system::error_code error_;
        state_type state_;
    };


    typedef confirmed_operation<MMS::Identify_Request, MMS::Identify_Response,
    MMS::ConfirmedServiceRequest_identify, MMS::ConfirmedServiceResponse_identify > identify_operation_type;

    typedef confirmed_operation<MMS::GetNameList_Request, MMS::GetNameList_Response,
    MMS::ConfirmedServiceRequest_getNameList, MMS::ConfirmedServiceResponse_getNameList > getnamelist_operation_type;

    typedef confirmed_operation<MMS::GetVariableAccessAttributes_Request, MMS::GetVariableAccessAttributes_Response,
    MMS::ConfirmedServiceRequest_getVariableAccessAttributes, MMS::ConfirmedServiceResponse_getVariableAccessAttributes > getvaraccess_operation_type;

    typedef confirmed_operation<MMS::Read_Request, MMS::Read_Response,
    MMS::ConfirmedServiceRequest_read, MMS::ConfirmedServiceResponse_read > read_operation_type;

    //typedef confirmed_operation<MMS::Write_Request , MMS::Write_Response ,
    //MMS::ConfirmedServiceRequest_write  , MMS::ConfirmedServiceResponse_write >                                                                                     write_operation_type;   


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  MMS mms_socket  //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    using boost::itu::x226impl::presentation_context;
    using boost::itu::x226impl::presentation_context_set;
    using boost::itu::x227impl::application_context;


    const presentation_context MMS_CONTEXT_arr[] = {presentation_context(MMS_OID)};

    const presentation_context_set MMS_CONTEXT = presentation_context_set(MMS_CONTEXT_arr, MMS_CONTEXT_arr + 1);

    const application_context MMS_APPLICATION_CONTEXT = application_context(MMSA_OID, MMS_CONTEXT);

    class mms_socket : public boost::itu::x227impl::application_socket {
        typedef boost::itu::x227impl::application_socket super_type;
        typedef boost::itu::x226impl::defined_context_ptr application_context_ptr;


    public:



        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Constructors  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        explicit mms_socket(boost::asio::io_service& io_service,
                const application_selector& asel = NULL_APPLICATION_SELECTOR)
        : super_type(io_service, MMS_APPLICATION_CONTEXT, asel), invoke_id_(0) {
        }

        mms_socket(boost::asio::io_service& io_service,
                const endpoint_type& endpoint,
                const application_selector& asel = NULL_APPLICATION_SELECTOR)
        : super_type(io_service, endpoint, MMS_APPLICATION_CONTEXT, asel), invoke_id_(0) {
        }


        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Connect operation  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    private:

        template <typename ConnectHandler>
        class connect_operation {
        public:

            connect_operation(mms_socket& sock, const ConnectHandler handlr) : socket(sock), handler(handlr) {
            }

            void operator()(const boost::system::error_code& ec) {
                if (!ec) {
                    socket.init_response();
                    handler(ec);
                    return;
                }
                handler(ec);
            }

        private:
            mms_socket& socket;
            ConnectHandler handler;
        };


    public:

        template <typename ConnectHandler>
        void async_connect(const endpoint_type& peer_endpoint,
                ConnectHandler handler) {


            boost::system::error_code error = init_request();
            if (error) {
                handler(error);
            }

            typedef connect_operation<ConnectHandler> connect_operation_type;

            super_type::async_connect(peer_endpoint, boost::bind(&connect_operation_type::operator (),
                    connect_operation_type(*this, handler), boost::asio::placeholders::error));
        }



        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Confirm request operation  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     



    private:

        template <typename ConfirmRequestHandler, typename REQ, typename RSP, MMS::ConfirmedServiceRequest_enum REQID, MMS::ConfirmedServiceResponse_enum RSPID>
        class confirm_request_op {
            typedef boost::shared_ptr<confirmed_operation<REQ, RSP, REQID, RSPID > > operation_type;

            enum state_type {
                request,
                response,
                error
            };

        public:

            confirm_request_op(mms_socket* socket, ConfirmRequestHandler handler, operation_type operatetion) :
            socket_(socket), handler_(handler), operation_(operatetion), state(request) {
            }

            void run(const boost::system::error_code& ec) {
                operator()(ec);
            }

            void operator()(const boost::system::error_code& ec) {
                if (!ec) {
                    switch (state) {
                        case request:
                        {
                            state = response;
                            socket_->super_type::async_response(boost::bind(& confirm_request_op<ConfirmRequestHandler, REQ, RSP, REQID, RSPID >::run, *this, boost::asio::placeholders::error));
                            return;
                        }
                        case response:
                        {
                            parse_response();
                            handler_(operation_);
                            return;
                        }
                        default:
                        {
                        }
                    }
                }
                else {
                    operation_->error(ec);
                }
                handler_(operation_);
            }

        protected:

            void parse_response() {
                try {
                    MMS::MMSpdu mms;
                    socket_->mmsdcs()->get(mms);
                    switch (mms.type()) {
                        case MMS::MMSpdu_confirmed_ResponsePDU:
                        {
                            const MMS::Confirmed_ResponsePDU& mmsresp = *mms.confirmed_ResponsePDU();
                            if (*(mmsresp.invokeID) == operation_->invokeid()) {
                                const MMS::ConfirmedServiceResponse& confirmresp = *mmsresp.service;
                                if (confirmresp.type() == operation_->rspid()) {
                                    operation_->response(confirmresp.get< RSP > (operation_->rspid()));
                                }
                                else {
                                    operation_->setunexpetedresp();
                                }
                            }
                            else {
                                operation_->setunexpetedIvoke();
                            }
                            break;
                        }
                        case MMS::MMSpdu_confirmed_ErrorPDU:
                        {
                            const MMS::Confirmed_ErrorPDU& mmsresp = *mms.confirmed_ErrorPDU();
                            if (*(mmsresp.invokeID) == operation_->invokeid()) {
                                operation_->serviceerror(boost::shared_ptr<MMS::ServiceError > (new MMS::ServiceError(*mmsresp.serviceError)));
                            }
                            else {
                                operation_->setunexpetedIvoke();
                            }
                            break;
                        }
                        case MMS::MMSpdu_rejectPDU:
                        {
                            operation_->reject(mms.get<MMS::RejectPDU > (MMS::MMSpdu_rejectPDU));
                            break;
                        }
                        default:
                        {
                            operation_->setunexpetedresp();
                        }
                    }
                    return;
                }
                catch (const boost::system::system_error& cerr) {
                    operation_->error(cerr.code());
                    return;
                }
                catch (...) {
                }
                operation_->error(boost::itu::ER_PROTOCOL);
            }

        private:
            mms_socket* socket_;
            ConfirmRequestHandler handler_;
            operation_type operation_;
            state_type state;
        };


    public:

        template< typename ConfirmRequestHandler, typename REQ, typename RSP, MMS::ConfirmedServiceRequest_enum REQID, MMS::ConfirmedServiceResponse_enum RSPID>
        void async_confirm_request(boost::shared_ptr<confirmed_operation<REQ, RSP, REQID, RSPID > > operation,
                ConfirmRequestHandler handler) {

            if (!operation->request()) {
                handler(operation);
                return;
            }

            MMS::MMSpdu mms;
            mms.confirmed_RequestPDU__new();
            MMS::Confirmed_RequestPDU& cfpdu = *mms.confirmed_RequestPDU();
            operation->invokeid(invoke_id());
            cfpdu.invokeID = operation->invokeid();
            cfpdu.service->set(operation->request(), operation->reqid());
            mmsdcs()->set(mms);


            super_type::async_request(boost::bind(& confirm_request_op<ConfirmRequestHandler, REQ, RSP, REQID, RSPID >::run,
                    confirm_request_op< ConfirmRequestHandler, REQ, RSP, REQID, RSPID > (const_cast<mms_socket*> (this), handler, operation), boost::asio::placeholders::error));

        }



        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Other operations  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////               




    protected:

        application_context_ptr mmsdcs() {
            return mmsdcs_;
        }

        application_context_ptr mmsdcs() const {
            return mmsdcs_;
        }

        invoke_id_type invoke_id() {
            return invoke_id_ = ((invoke_id_ < MAXINVOKEID) ? (++invoke_id_) : 1);
        }




    private:



        boost::system::error_code init_request();
        boost::system::error_code init_response();



        application_context_ptr mmsdcs_;
        invoke_id_type invoke_id_;

    };


    /////////////////////////////

    class socket_acceptor : public boost::itu::x227impl::socket_acceptor {
        typedef boost::itu::x227impl::socket_acceptor super_type;

    public:

        explicit socket_acceptor(boost::asio::io_service& io_service)
        : super_type(io_service, MMS_APPLICATION_CONTEXT) {
        }

        socket_acceptor(boost::asio::io_service& io_service,
                const endpoint_type& endpoint, bool reuse_addr = true)
        : super_type(io_service, endpoint, MMS_APPLICATION_CONTEXT) {
        }




        /* template <typename SocketService>
         boost::system::error_code accept(
                 basic_socket<protocol_type, SocketService>& peer,
                 boost::system::error_code& ec) {
             return accept_impl(peer, ec);
         }

         template <typename SocketService>
         boost::system::error_code accept(
                 basic_socket<protocol_type, SocketService>& peer,
                 endpoint_type& peer_endpoint, boost::system::error_code& ec) {
             return accept_impl(peer, peer_endpoint, ec);
         }

         template <typename SocketService, typename AcceptHandler>
         void async_accept(basic_socket<protocol_type, SocketService>& peer,
                 BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {
             BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
             async_accept_impl(peer,  BOOST_ASIO_MOVE_CAST(AcceptHandler)(handler));
         }

         template <typename SocketService, typename AcceptHandler>
         void async_accept(basic_socket<protocol_type, SocketService>& peer,
                 endpoint_type& peer_endpoint, BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {
             BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
             async_accept_impl(peer, peer_endpoint , BOOST_ASIO_MOVE_CAST(AcceptHandler)(handler));
         }



     private:

         template <typename SocketService, typename AcceptHandler>
         void async_accept_impl(basic_socket<protocol_type, SocketService>& peer,
                 endpoint_type& peer_endpoint, BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {
             BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
             static_cast<mms_socket*> ( &peer)->option(option_);
             super_type::async_accept(peer,  peer_endpoint, static_cast<mms_socket*> (&peer)->coder(), handler);
         }

         template <typename SocketService, typename AcceptHandler>
         void async_accept_impl(basic_socket<protocol_type, SocketService>& peer,
                 BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {
             BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
             static_cast<mms_socket*> ( &peer)->option(option_);
             super_type::async_accept(peer,   static_cast<mms_socket*> (&peer)->coder(), handler);
         }

         template <typename SocketService>
         boost::system::error_code accept_impl(
                 basic_socket<protocol_type, SocketService>& peer,
                 endpoint_type& peer_endpoint, boost::system::error_code& ec) {
             static_cast<mms_socket*> ( &peer)->option(option_);
             super_type::accept(peer, peer_endpoint, static_cast<mms_socket*> ( &peer)->coder(),  ec);
             return ec;
         }

         template <typename SocketService>
         boost::system::error_code accept_impl(
                 basic_socket<protocol_type, SocketService>& peer,
                 boost::system::error_code& ec) {
             static_cast<mms_socket*> ( &peer)->option(option_);
             super_type::accept(peer, static_cast<mms_socket*> ( &peer)->coder(),  ec);
             return ec;
         }*/
    };

}

class iso9506 {
public:
    /// The type of a TCP endpoint.

    typedef boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> endpoint;

    typedef boost::itu::application_selector application_selector;

    typedef boost::itu::presentation_selector presentation_selector;

    typedef boost::itu::session_selector session_selector;

    typedef boost::itu::transport_selector transport_selector;

    /// Construct to represent the IPv4 TCP protocol.

    static iso9506 v4() {

        return iso9506(PF_INET);
    }

    /// Construct to represent the IPv6 TCP protocol.

    static iso9506 v6() {

        return iso9506(PF_INET6);
    }

    /// Obtain an identifier for the type of the protocol.

    int type() const {

        return SOCK_STREAM;
    }

    /// Obtain an identifier for the protocol.

    int protocol() const {

        return IPPROTO_TCP;
    }

    /// Obtain an identifier for the protocol family.

    int family() const {

        return family_;
    }

    /// The TCP socket type.
    typedef prot9506::mms_socket socket;

    /// The TCP acceptor type.
    typedef prot9506::socket_acceptor acceptor;

    /// The TCP resolver type.
    typedef boost::asio::ip::basic_resolver<boost::asio::ip::tcp> resolver;

#if !defined(BOOST_NO_IOSTREAM)
    /// The TCP iostream type.
    typedef boost::asio::basic_socket_iostream<boost::asio::ip::tcp> iostream;
#endif // !defined(BOOST_NO_IOSTREAM)


    typedef boost::asio::detail::socket_option::boolean<
    IPPROTO_TCP, TCP_NODELAY> no_delay;

    /// Compare two protocols for equality.

    friend bool operator==(const iso9506& p1, const iso9506& p2) {

        return p1.family_ == p2.family_;
    }

    /// Compare two protocols for inequality.

    friend bool operator!=(const iso9506& p1, const iso9506& p2) {

        return p1.family_ != p2.family_;
    }

private:
    // Construct with a specific family.

    explicit iso9506(int family)
    : family_(family) {
    }

    int family_;
};






#endif	/* MMSSOCKET_H */

