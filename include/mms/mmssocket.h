/* 
 * File:   mmssocket.h
 * Author: sealeks@mail.ru
 *
 * Created on 27 Р¤РµРІСЂР°Р»СЊ 2013 Рі., 22:26
 */

#ifndef MMSSOCKET_H
#define	MMSSOCKET_H

#include <boost/itu/x22X/x227.hpp>
#include <mms/MMS-SCI-Module-1.hpp>


namespace prot9506 {

    namespace ACSE = ACSE_1;
    namespace MMS = ISO_9506_MMS_1;
    namespace MMSO = MMS_Object_Module_1;


    typedef boost::itu::defined_context_set_ptr defined_context_set_ptr;
    typedef MMSO::Unsigned32 invoke_id_type;

    const invoke_id_type MAXINVOKEID = 100000;


    using boost::itu::application_selector;
    using boost::itu::NULL_APPLICATION_SELECTOR;
    using boost::itu::x227impl::application_context;
    using MMS::Initiate_ResponsePDU;

    extern const boost::asn1::oid_type MMS_OID;
    extern const boost::asn1::oid_type MMSA_OID;

    const boost::uint32_t DEFAULT_MMS_VER = 1;


    typedef MMS::ServiceSupportOptions service_option_type;
    typedef MMS::ParameterSupportOptions parameter_option_type;
    typedef MMS::AdditionalSupportOptions exservice_option_type;
    typedef MMS::AdditionalCBBOptions exparameter_option_type;
    typedef boost::asn1::visiblestring_type privilege_type;

    extern const service_option_type MMS_SERVICE_OPTOION_DFLT;
    extern const parameter_option_type MMS_CBB_OPTION_DFLT;


    //presentation_option init_synaxes();

    class protocol_option {

    public:

        protocol_option();
        
        protocol_option(const application_selector& asel,
                const service_option_type& _service,
                const parameter_option_type& _parameter,
                boost::uint32_t _localdetail = 30000,
                boost::uint32_t _maxcalling = 1,
                boost::uint32_t _maxcalled = 5,
                boost::uint32_t _nested = 5,
                boost::uint32_t _version = DEFAULT_MMS_VER,
                const exservice_option_type& _exservice  = exservice_option_type(),
                const exparameter_option_type& _exparameter = exparameter_option_type(),   
                const privilege_type&  _privilege = privilege_type()       
                );

        protocol_option(const std::string& asel,
                const service_option_type& _service,
                const parameter_option_type& _parameter,
                boost::uint32_t _localdetail = 30000,
                boost::uint32_t _maxcalling = 1,
                boost::uint32_t _maxcalled = 5,
                boost::uint32_t _nested = 5,
                boost::uint32_t _version = DEFAULT_MMS_VER,
                const exservice_option_type& _exservice  = exservice_option_type(),
                const exparameter_option_type& _exparameter = exparameter_option_type(),   
                const privilege_type&  _privilege = privilege_type()              
                );

        protocol_option(const service_option_type& _service,
                const parameter_option_type& _parameter,
                boost::uint32_t _localdetail = 30000,
                boost::uint32_t _maxcalling = 1,
                boost::uint32_t _maxcalled = 5,
                boost::uint32_t _nested = 5,
                boost::uint32_t _version = DEFAULT_MMS_VER,
                const exservice_option_type& _exservice  = exservice_option_type(),
                const exparameter_option_type& _exparameter = exparameter_option_type(),   
                const privilege_type&  _privilege = privilege_type()           
                );

        const application_selector& aselector() const {
            return asel_;
        }

        application_selector& aselector() {
            return asel_;
        }

        const application_context& acontext() const {
            return acontext_;
        }

        application_context& acontext() {
            return acontext_;
        }

        boost::uint32_t localdetail() const {
            return localdetail_;
        }

        void localdetail(boost::uint32_t val) {
            localdetail_ = val;
        }

        boost::uint32_t maxcalling() const {
            return maxcalling_;
        }

        void maxcalling(boost::uint32_t val) {
            maxcalling_ = val;
        }

        boost::uint32_t maxcalled() const {
            return maxcalled_;
        }

        void maxcalled(boost::uint32_t val) {
            maxcalled_ = val;
        }

        boost::uint32_t nested() const {
            return nested_;
        }

        void nested(boost::uint32_t val) {
            nested_ = val;
        }

        boost::uint32_t version() const {
            return version_;
        }

        void version(boost::uint32_t val) {
            version_ = val;
        }

        const service_option_type& service() const {
            return service_;
        }

        service_option_type& service() {
            return service_;
        }

        const parameter_option_type& parameter() const {
            return parameter_;
        }

        parameter_option_type& parameter() {
            return parameter_;
        }
        
        const exservice_option_type& exservice() const {
            return service_;
        }

        exservice_option_type& exservice() {
            return exservice_;
        }

        const exparameter_option_type& exparameter() const {
            return parameter_;
        }

        exparameter_option_type& exparameter() {
            return exparameter_;
        }  
        
        const privilege_type& privilege() const {
            return privilege_;
        }

        privilege_type& privilege() {
            return privilege_;
        }        

    private:

        application_selector asel_;
        application_context acontext_;
        service_option_type service_;
        parameter_option_type parameter_;
        boost::uint32_t localdetail_;
        boost::uint32_t maxcalling_;
        boost::uint32_t maxcalled_;
        boost::uint32_t nested_;
        boost::uint32_t version_;
        exservice_option_type exservice_;
        exparameter_option_type exparameter_;
        privilege_type privilege_;
    };


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  Operation template  //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  confirmed_operation  template//
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

    class mms_socket;

    class basic_confirmed_operation {

    public:

        enum state_type {

            noproccess_state,
            ok_state,
            rejected_state,
            error_state,
            proterror_state,
            unexpid_state,
            unexp_resp_state
        };

        basic_confirmed_operation(mms_socket* sct = 0) : socket_(sct), invokeid_(), error_(), state_(noproccess_state) {
        }

        virtual ~basic_confirmed_operation() {
        }

        void error(const boost::system::error_code& val) {
            error_ = val;
            if (error_)
                state_ = proterror_state;
        }
        
        boost::system::error_code error() const {
            return error_;
        }        

        state_type state() const {
            return state_;
        }

        invoke_id_type invokeid() const {
            return invokeid_;
        }

        void invokeid(invoke_id_type val) {
            invokeid_ = val;
        }

        void setunexpetedIvoke() {
            state_ = error_state;
        }

        void setunexpetedresp() {
            state_ = unexp_resp_state;
        }

        operator bool() const {
            return state_ == ok_state;
        }

        friend bool operator==(const basic_confirmed_operation& ls, const basic_confirmed_operation& rs) {
            return (ls.invokeid() == rs.invokeid());
        }

        friend bool operator<(const basic_confirmed_operation& ls, const basic_confirmed_operation& rs) {
            return (ls.invokeid() < rs.invokeid());
        }
        
        

    protected:

        mms_socket* socket_;
        invoke_id_type invokeid_;
        boost::system::error_code error_;
        state_type state_;
    };


    typedef boost::shared_ptr<basic_confirmed_operation> confirmed_operation_ptr;
    typedef std::set<confirmed_operation_ptr> confirmed_operation_set;
    ;

    template< typename REQ, typename RSP, MMS::ConfirmedServiceRequest_enum REQID, MMS::ConfirmedServiceResponse_enum RSPID = MMS::ConfirmedServiceResponse_null >
    class confirmed_operation : public basic_confirmed_operation {

    public:

        typedef REQ request_type;
        typedef RSP response_type;
        typedef MMS::RejectPDU reject_type;
        typedef MMS::ServiceError serviceerror_type;

        typedef boost::shared_ptr<request_type> request_type_ptr;
        typedef boost::shared_ptr<response_type> response_type_ptr;
        typedef boost::shared_ptr<reject_type> reject_type_ptr;
        typedef boost::shared_ptr<serviceerror_type> serviceerror_type_ptr;

        confirmed_operation(mms_socket* sct = 0) : basic_confirmed_operation(sct) {
        }

        virtual ~confirmed_operation() {
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

        MMS::ConfirmedServiceRequest_enum reqid() const {
            return REQID;
        }

        MMS::ConfirmedServiceResponse_enum rspid() const {
            return RSPID;
        }

        virtual void request_operator(boost::shared_ptr<request_type> req) {

        }

        virtual void response_operator(boost::shared_ptr<response_type_ptr> resp) {

        }


    protected:

        request_type_ptr request_;
        response_type_ptr response_;
        reject_type_ptr reject_;
        serviceerror_type_ptr serviceerror_;

    };



    typedef confirmed_operation<MMS::Identify_Request, MMS::Identify_Response,
    MMS::ConfirmedServiceRequest_identify, MMS::ConfirmedServiceResponse_identify > identify_operation_type;

    typedef confirmed_operation<MMS::GetNameList_Request, MMS::GetNameList_Response,
    MMS::ConfirmedServiceRequest_getNameList, MMS::ConfirmedServiceResponse_getNameList > getnamelist_operation_type;

    typedef confirmed_operation<MMS::GetVariableAccessAttributes_Request, MMS::GetVariableAccessAttributes_Response,
    MMS::ConfirmedServiceRequest_getVariableAccessAttributes, MMS::ConfirmedServiceResponse_getVariableAccessAttributes > getvaraccess_operation_type;

    typedef confirmed_operation<MMS::Read_Request, MMS::Read_Response,
    MMS::ConfirmedServiceRequest_read, MMS::ConfirmedServiceResponse_read > read_operation_type;

    typedef confirmed_operation<MMS::DefineNamedVariableList_Request, MMS::DefineNamedVariableList_Response,
    MMS::ConfirmedServiceRequest_defineNamedVariableList, MMS::ConfirmedServiceResponse_defineNamedVariableList > definelist_operation_type;
    
    typedef confirmed_operation<MMS::DeleteNamedVariableList_Request, MMS::DeleteNamedVariableList_Response,
    MMS::ConfirmedServiceRequest_deleteNamedVariableList, MMS::ConfirmedServiceResponse_deleteNamedVariableList > deletelist_operation_type;    

    typedef confirmed_operation<MMS::Write_Request, MMS::Write_Response,
    MMS::ConfirmedServiceRequest_write > write_operation_type;


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  MMS mms_socket  //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    using boost::itu::x226impl::presentation_context;
    using boost::itu::x226impl::presentation_context_set;
    using boost::itu::x227impl::application_context;

    class mms_socket : protected boost::itu::x227impl::application_socket {
        
        friend class socket_acceptor;

        typedef boost::itu::x227impl::application_socket super_type;
        typedef super_type::defined_context_ptr    defined_context_ptr; 
        typedef super_type::defined_context_ptr application_context_ptr;
        typedef super_type::defined_context_map  defined_context_map;


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


    public:

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Constructors  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        explicit mms_socket(boost::asio::io_service& io_service,
                const protocol_option& protopt);

        mms_socket(boost::asio::io_service& io_service,
                const endpoint_type& endpoint,
                const protocol_option& protopt);


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
        //  Request operation  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     



    public:

        template< typename ConfirmRequestHandler, typename REQ, typename RSP, MMS::ConfirmedServiceRequest_enum REQID, MMS::ConfirmedServiceResponse_enum RSPID>
        void async_request(boost::shared_ptr<confirmed_operation<REQ, RSP, REQID, RSPID > > operation,
                ConfirmRequestHandler handler) {

            if (!operation->request()) {
                handler(operation);
                return;
            }

            MMS::MMSpdu mms;
            mms.confirmed_RequestPDU__new();
            MMS::Confirmed_RequestPDU& cfpdu = *mms.confirmed_RequestPDU();
            operation->invokeid(invoke_id());
            cfpdu.invokeID(operation->invokeid());
            cfpdu.service().set(operation->request(), operation->reqid());
            mmsdcs()->set(mms);


            super_type::async_request(&handler, boost::asio::placeholders::error);

        }

        template< typename REQ, typename RSP, MMS::ConfirmedServiceRequest_enum REQID, MMS::ConfirmedServiceResponse_enum RSPID>
        void async_request(boost::shared_ptr<confirmed_operation<REQ, RSP, REQID, RSPID > > operation) {
                 async_request(boost::bind(&confirmed_operation<REQ, RSP, REQID, RSPID >::response_operator, operation.get() , operation));
        }        
        
        
          //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Response operation  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     



    /*public:

        template< typename ConfirmRequestHandler>
        void async_response(ConfirmRequestHandler handler) {


            MMS::MMSpdu mms;
            mms.confirmed_RequestPDU__new();
            MMS::Confirmed_RequestPDU& cfpdu = *mms.confirmed_RequestPDU();
            operation->invokeid(invoke_id());
            cfpdu.invokeID(operation->invokeid());
            cfpdu.service().set(operation->request(), operation->reqid());
            mmsdcs()->set(mms);


            super_type::async_request(&handler, boost::asio::placeholders::error);

        }

        template< typename REQ, typename RSP, MMS::ConfirmedServiceRequest_enum REQID, MMS::ConfirmedServiceResponse_enum RSPID>
        void async_request(boost::shared_ptr<confirmed_operation<REQ, RSP, REQID, RSPID > > operation) {
                 async_request(boost::bind(&confirmed_operation<REQ, RSP, REQID, RSPID >::response_operator, operation.get() , operation));
        }*/          
        

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
                            if (!parse_response())
                                handler_(operation_);
                            else {
                                state = response;
                                socket_->super_type::async_response(boost::bind(& confirm_request_op<ConfirmRequestHandler, REQ, RSP, REQID, RSPID >::run, *this, boost::asio::placeholders::error));
                            }
                            return;
                        }
                        default:
                        {
                        }
                    }
                } else {
                    operation_->error(ec);
                }
                handler_(operation_);
            }

        protected:

            bool parse_response() {
                bool contin = false;
                try {
                    MMS::MMSpdu mms;
                    socket_->mmsdcs()->get(mms);
                    switch (mms.type()) {
                        case MMS::MMSpdu_confirmed_ResponsePDU:
                        {
                            const MMS::Confirmed_ResponsePDU& mmsresp = *mms.confirmed_ResponsePDU();
                            if ((mmsresp.invokeID()) == operation_->invokeid()) {
                                const MMS::ConfirmedServiceResponse& confirmresp = mmsresp.service();
                                if (confirmresp.type() == operation_->rspid()) {
                                    if (!operation_->rspid())
                                        operation_->response_new();
                                    else
                                        operation_->response(confirmresp.get< RSP > (operation_->rspid()));
                                } else {
                                    operation_->setunexpetedresp();
                                }
                            } else {
                                operation_->setunexpetedIvoke();
                            }
                            break;
                        }
                        case MMS::MMSpdu_confirmed_ErrorPDU:
                        {
                            const MMS::Confirmed_ErrorPDU& mmsresp = *mms.confirmed_ErrorPDU();
                            if ((mmsresp.invokeID()) == operation_->invokeid()) {
                                operation_->serviceerror(boost::shared_ptr<MMS::ServiceError > (new MMS::ServiceError(mmsresp.serviceError())));
                            } else {
                                operation_->setunexpetedIvoke();
                            }
                            break;
                        }
                        case MMS::MMSpdu_unconfirmed_PDU:
                        {
                            const MMS::Unconfirmed_PDU& mmsresp = *mms.unconfirmed_PDU();
                            socket_->information_report(mmsresp);
                            contin = true;
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
                    return contin;
                } catch (const boost::system::system_error& cerr) {
                    operation_->error(cerr.code());
                    return contin;
                } catch (...) {
                }
                operation_->error(boost::itu::ER_PROTOCOL);
                return contin;
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
            cfpdu.invokeID(operation->invokeid());
            cfpdu.service().set(operation->request(), operation->reqid());
            mmsdcs()->set(mms);


            super_type::async_request(boost::bind(& confirm_request_op<ConfirmRequestHandler, REQ, RSP, REQID, RSPID >::run,
                    confirm_request_op< ConfirmRequestHandler, REQ, RSP, REQID, RSPID > (const_cast<mms_socket*> (this), handler, operation), boost::asio::placeholders::error));

        }

        template< typename REQ, typename RSP, MMS::ConfirmedServiceRequest_enum REQID, MMS::ConfirmedServiceResponse_enum RSPID>
        void async_confirm_request(boost::shared_ptr<confirmed_operation<REQ, RSP, REQID, RSPID > > operation) {
                 async_confirm_request(boost::bind(&confirmed_operation<REQ, RSP, REQID, RSPID >::response_operator, operation.get() , operation));
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Release operations  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////               

    private:

        template <typename ReleaseRequestHandler>
        class release_request_op {

            enum state_type {

                request,
                response,
                error
            };

        public:

            release_request_op(mms_socket* socket, ReleaseRequestHandler handler) :
            socket_(socket), handler_(handler), state(request) {
            }

            void operator()(const boost::system::error_code& ec) {
                if (!ec) {
                    socket_->super_type::async_release(boost::bind(&release_request_op<ReleaseRequestHandler>::release,
                            this, boost::asio::placeholders::error));
                }
                handler_(ec);
            }

            void release(const boost::system::error_code& ec) {
                if (!ec) {

                }
                handler_(ec);
            }

        private:

            mms_socket* socket_;
            ReleaseRequestHandler handler_;
            state_type state;

        };


    public:

        template <typename ReleaseRequestHandler>
        void async_release(BOOST_ASIO_MOVE_ARG(ReleaseRequestHandler) handler) {


            MMS::MMSpdu mms;
            mms.conclude_RequestPDU__new();
            mmsdcs()->set(mms);

            typedef release_request_op<ReleaseRequestHandler> release_operation_type;


            super_type::async_request(boost::bind(&release_operation_type::operator(),
                    release_operation_type(const_cast<mms_socket*> (this), handler), boost::asio::placeholders::error));

        }

        virtual void information_report(const MMS::Unconfirmed_PDU& val);
        
        const protocol_option & mmsoption() const;
        
        void  aselector(const std::string& vl);        

    protected:
        
        protocol_option & mmsoption();             

        application_context_ptr mmsdcs();

        application_context_ptr mmsdcs() const;

        invoke_id_type invoke_id();
        
       void mmsoption(const Initiate_ResponsePDU& opt);
        
        

    private:


        boost::system::error_code init_request();
        boost::system::error_code init_response();

        application_context_ptr mmsdcs_;
        invoke_id_type invoke_id_;
        protocol_option mmsoption_;
        confirmed_operation_set out_requst_set_;
        confirmed_operation_set in_requst_set_;
        confirmed_operation_set out_response_set_;
        confirmed_operation_set in_response_set_;
    };


    /////////////////////////////

    class socket_acceptor : public boost::itu::x227impl::socket_acceptor {

        typedef boost::itu::x227impl::socket_acceptor super_type;

        friend class mms_socket;

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

    public:

        explicit socket_acceptor(boost::asio::io_service& io_service);

        socket_acceptor(boost::asio::io_service& io_service,
                const endpoint_type& endpoint, bool reuse_addr = true);




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Accept operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                          

                boost::system::error_code accept(
                        mms_socket& peer,
                        boost::system::error_code& ec) {
                    return accept_impl(peer, ec);
                }

                boost::system::error_code accept(
                        mms_socket& peer,
                        endpoint_type& peer_endpoint, boost::system::error_code& ec) {
                    return accept_impl(peer, peer_endpoint, ec);
                }

                template <typename AcceptHandler>
                void async_accept(mms_socket& peer,
                        BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    async_accept_impl(peer, BOOST_ASIO_MOVE_CAST(AcceptHandler)(handler));
                }

                template <typename AcceptHandler>
                void async_accept(mms_socket& peer,
                        endpoint_type& peer_endpoint, BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    async_accept_impl(peer, peer_endpoint, BOOST_ASIO_MOVE_CAST(AcceptHandler)(handler));
                }



            private:


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Private implementator  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                     

                template <typename AcceptHandler>
                void async_accept_impl(mms_socket& peer,
                        endpoint_type& peer_endpoint, BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    peer.mmsoption()=mmsoption_;
                    super_type::async_accept(peer, peer_endpoint, handler);
                }

                template <typename AcceptHandler>
                void async_accept_impl(mms_socket& peer,
                        BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {
                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;
                    peer.mmsoption()=mmsoption_;
                    super_type::async_accept(peer, handler);
                }

                boost::system::error_code accept_impl(
                        mms_socket& peer,
                        endpoint_type& peer_endpoint, boost::system::error_code& ec) {
                    peer.mmsoption()=mmsoption_;
                    //super_type::accept(peer, peer_endpoint, ec);
                    return ec;
                }

                boost::system::error_code accept_impl(
                        mms_socket& peer,
                        boost::system::error_code& ec) {
                    peer.mmsoption()=mmsoption_;
                    //super_type::accept(peer, ec);
                    return ec;
                }


                protocol_option mmsoption_;

            };
            

    double from_mmsfloat(const MMS::FloatingPoint& vl);
    MMS::FloatingPoint to_mmsfloat(const float& vl);
    MMS::FloatingPoint to_mmsfloat(const double& vl);
    MMS::FloatingPoint to_mmsfloat(const long double& vl);   
    
    boost::posix_time::ptime from_mms_datetime(const MMS::TimeOfDay& vl);
    MMS::TimeOfDay to_mms_datetime(const boost::posix_time::ptime& vl);    
    
    boost::posix_time::ptime from_mms_utctime(const  boost::asn1::octetstring_type& vl);
    boost::asn1::octetstring_type to_mms_utctime(const boost::posix_time::ptime& vl);      

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

