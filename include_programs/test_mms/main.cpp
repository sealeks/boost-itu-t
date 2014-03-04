/*  * File:   main.cpp
 * Author: sealeks@mail.ru
 *
 * Created on 27 Р В  Р В Р вЂ№Р В  Р вЂ™Р’ВµР В  Р В РІР‚В¦Р В Р Р‹Р Р†Р вЂљРЎв„ўР В Р Р‹Р В Р РЏР В  Р вЂ™Р’В±Р В Р Р‹Р В РІР‚С™Р В Р Р‹Р В Р вЂ° 2012 Р В  Р РЋРІР‚вЂњ., 15:58
 */


#include <cstdlib>
#include <iostream>



#define BOOST_THREAD_USE_LIB

#include <boost/thread/thread.hpp>
#include <boost/itu/utils/utils.h>

#include "mmssocket.h"


typedef iso9506 protocol_type;
typedef protocol_type::socket socket_type;
typedef protocol_type::acceptor acceptor_type;
typedef protocol_type::endpoint endpoint_type;
typedef protocol_type::resolver resolver_type;
typedef protocol_type::application_selector application_selector;

//const session_selector LSELECTOR = session_selector(selectorvalue_type(std::string("\x0\x1", 2)), selectorvalue_type(std::string("\x0\x0", 2)), transport_selector(selectorvalue_type(std::string("\x0\x0", 2)), selectorvalue_type(std::string("\x0\x1", 2))));
//const presentation_selector PSELECTOR = presentation_selector(selectorvalue_type(std::string("\x0\x0\x0\x1", 4)), selectorvalue_type(std::string("\x0\x0\x0\x0", 4)), LSELECTOR);


const application_selector ASELECTOR = application_selector(std::string("{{1, 3, 9999, 106} , 33, 1, 2}[{{1, 3, 9999, 106} , 33, 3 , 4}]"));


namespace MMS = ISO_9506_MMS_1;
namespace MMSO = MMS_Object_Module_1;

int port = 102;

#ifndef NET_BLOCKING

class session {
public:

    session(boost::asio::io_service& io_service)
    : socket_(io_service, ASELECTOR) {
        std::cout << "New sesion\n";
    }

    socket_type& socket() {
        return socket_;
    }

    void start() {
        /*   if (trans_) {
               std::cout << "Client accept data : " << trans_->respond_str() << std::endl;
           }

           socket_.async_read_some(boost::asio::buffer(data_, max_length),
                   boost::bind(&session::handle_read, this,
                   boost::asio::placeholders::error,
                   boost::asio::placeholders::bytes_transferred));*/

    }

private:

    void handle_read(const boost::system::error_code& error,
            size_t bytes_transferred) {
        /* if (!error) {
              boost::asio::async_write(socket_,
                       boost::asio::buffer(data_, bytes_transferred),
                       boost::bind(&session::handle_write, this,
                       boost::asio::placeholders::error));
               std::cout << "Server read: " <<  std::string(data_, bytes_transferred) <<  " size: " <<  bytes_transferred << std::endl;
               message = std::string(data_, bytes_transferred); 
           }
           else {
               delete this;
           }*/
    }

    void handle_write(const boost::system::error_code& error) {
        /*  if (!error) {
              std::cout << "Server write: " <<  message <<  " size: " <<  message.size() << std::endl;
              socket_.async_read_some(boost::asio::buffer(data_, max_length),
                      boost::bind(&session::handle_read, this,
                      boost::asio::placeholders::error,
                      boost::asio::placeholders::bytes_transferred));
              std::cout << "Data indication: " <<  socket_.ready() << std::endl;

          }
          else {
              delete this;
          }*/
    }

    socket_type socket_;
    std::string message;
};

class server {
public:

    server(boost::asio::io_service& io_service, short port)
    : io_service_(io_service),
    acceptor_(io_service, endpoint_type(boost::asio::ip::tcp::v4(), port)) {
        start_accept();
    }

private:

    void start_accept() {
        //asn_coder_ptr trans_ = boost::itu::create_simple_data("Hello client from test");

        session* new_session = new session(io_service_);



        acceptor_.async_accept(new_session->socket(),

                boost::bind(&server::handle_accept, this, new_session,
                boost::asio::placeholders::error));
    }

    void handle_accept(session* new_session,
            const boost::system::error_code& error) {
        if (!error) {
            new_session->start();
        }
        else {
            delete new_session;
        }

        start_accept();
    }

    boost::asio::io_service& io_service_;
    acceptor_type acceptor_;

};

class client {
public:

    typedef prot9506::identify_operation_type identify_operation_type;
    typedef prot9506::getnamelist_operation_type getnamelist_operation_type;
    typedef prot9506::getvaraccess_operation_type getvaraccess_operation_type;
    typedef prot9506::read_operation_type read_operation_type;

    client(boost::asio::io_service& io_service,
            resolver_type::iterator endpoint_iterator, const std::string& called = "")
    : io_service_(io_service),
    socket_(io_service, ASELECTOR) {
        endpoint_type endpoint = *endpoint_iterator;
        socket_.async_connect(endpoint,
                boost::bind(&client::handle_connect, this,
                boost::asio::placeholders::error, ++endpoint_iterator));
    }

    ~client() {
        std::cout << "Socket destuctor" << std::endl;
        socket_.close();
    }

    void close() {
        //    io_service_.post(boost::bind(&client::do_close, this));
    }

private:

    void handle_connect(const boost::system::error_code& error,
            resolver_type::iterator endpoint_iterator) {
        if (!error) {

            boost::shared_ptr<identify_operation_type> operation =
                    boost::shared_ptr<identify_operation_type > (new identify_operation_type());

            operation->request_new();
            socket_.async_confirm_request(operation,
                    boost::bind(&client::handle_idenify_response, this, operation));



        }
    }
    
    

    void handle_idenify_response(boost::shared_ptr<identify_operation_type> rslt) {
        if (rslt->response()) {

            std::cout << "Vendor: " << rslt->response()->vendorName() << " Model: " << rslt->response()->modelName() << " Rev: " << rslt->response()->revision() << std::endl;

            boost::shared_ptr<getnamelist_operation_type > operation =
                    boost::shared_ptr<getnamelist_operation_type > (new getnamelist_operation_type());

            operation->request_new();
            operation->request()->objectClass().basicObjectClass(new int( MMS::ObjectClass::basicObjectClass_domain));
            operation->request()->objectScope().vmdSpecific__new();

            socket_.async_confirm_request(operation,
                    boost::bind(&client::handle_domainlist_response, this, operation));

        }
        else {
            std::cout << "handle_idenify_response: " << std::endl;
        }
    }

    void handle_domainlist_response(boost::shared_ptr<getnamelist_operation_type> rslt) {
        if (rslt->response()) {

            domain = rslt->response()->listOfIdentifier().operator [](0);

            std::cout << " domain name: " << domain << std::endl;



            boost::shared_ptr<getnamelist_operation_type > operation =
                    boost::shared_ptr<getnamelist_operation_type > (new getnamelist_operation_type());

            operation->request_new();
            operation->request()->objectClass().basicObjectClass(new int(MMS::ObjectClass::basicObjectClass_namedVariable));
            operation->request()->objectScope().domainSpecific__new(new MMS::Identifier(domain));

            socket_.async_confirm_request(operation,
                    boost::bind(&client::handle_variablelist_response, this, operation));

        }
        else {
            std::cout << "handle_domainlist_response: " << std::endl;
        }
    }

    void handle_variablelist_response(boost::shared_ptr<getnamelist_operation_type> rslt) {
        if (rslt->response()) {

            std::string last;

            typedef MMS::GetNameList_Response::ListOfIdentifier_type namedlist_type;
            for (namedlist_type::iterator it = rslt->response()->listOfIdentifier().begin(); it != rslt->response()->listOfIdentifier().end(); ++it) {
                fulllist.push_back((*it));
                last = (*it);
            }

            if ((!domain.empty()) && (rslt->response()->moreFollows())) {

                boost::shared_ptr<getnamelist_operation_type > operation =
                        boost::shared_ptr<getnamelist_operation_type > (new getnamelist_operation_type());

                operation->request_new();
                operation->request()->objectClass().basicObjectClass(new int( MMS::ObjectClass::basicObjectClass_namedVariable));
                operation->request()->objectScope().domainSpecific__new(new MMS::Identifier(domain));
                operation->request()->continueAfter(new MMS::Identifier(last));
                //operation->request()->continueAfter = MMS::Identifier(last));                

                socket_.async_confirm_request(operation,
                        boost::bind(&client::handle_variablelist_response, this, operation));


            }
            else {

                for (std::vector<std::string>::const_iterator it = fulllist.begin(); it != fulllist.end(); ++it) {
                    std::cout << " full lst var name: " << (*it) << std::endl;
                }
                std::cout << " full lst var size: " << fulllist.size() << std::endl;


                fullcnt = 0;

                if (!(fullcnt < fulllist.size())) return;

                boost::shared_ptr<getvaraccess_operation_type > operation =
                        boost::shared_ptr<getvaraccess_operation_type > (new getvaraccess_operation_type());

                operation->request_new();
                operation->request()->name__new();
                operation->request()->name()->domain_specific__new();
                operation->request()->name()->domain_specific()->domainID(domain);
                operation->request()->name()->domain_specific()->itemID(fulllist[fullcnt]);

                socket_.async_confirm_request(operation,
                        boost::bind(&client::handle_accesslist_response, this, operation));


            }
        }
        else {
            std::cout << "handle_domainlist_response: " << std::endl;
        }
    }

    
    void handle_accesslist_response(boost::shared_ptr<getvaraccess_operation_type> rslt) {
        if (rslt->response()) {

            //std::cout << "access var name: " <<     (int)( rslt->response()->typeDescription->type() )  << std::endl; 

            if ((int) (rslt->response()->typeDescription().type()) > (int) (MMSO::TypeDescription_structure))
                simplelist.push_back(fulllist[fullcnt]);


            fullcnt++;

            if (fullcnt < fulllist.size()) {

                boost::shared_ptr<getvaraccess_operation_type > operation =
                        boost::shared_ptr<getvaraccess_operation_type > (new getvaraccess_operation_type());

                operation->request_new();
                operation->request()->name__new();
                operation->request()->name()->domain_specific__new();
                operation->request()->name()->domain_specific()->domainID(domain);
                operation->request()->name()->domain_specific()->itemID(fulllist[fullcnt]);

                socket_.async_confirm_request(operation,
                        boost::bind(&client::handle_accesslist_response, this, operation));


            }
            else {
                for (std::vector<std::string>::const_iterator it = simplelist.begin(); it != simplelist.end(); ++it)
                    std::cout << " simple lst var name: " << (*it) << std::endl;

                std::cout << " simple lst var size: " << simplelist.size() << std::endl;

                boost::shared_ptr<read_operation_type > operationl =
                        boost::shared_ptr<read_operation_type > (new read_operation_type());

                simplecnt = 0;

                if (!(simplecnt < simplelist.size())) return;

                operationl->request_new();
                operationl->request()->variableAccessSpecification().listOfVariable__new();


                MMS::VariableAccessSpecification::ListOfVariable_type_sequence_of vacs;

                vacs.variableSpecification().name__new();
                vacs.variableSpecification().name()->domain_specific__new();
                vacs.variableSpecification().name()->domain_specific()->domainID(domain);
                vacs.variableSpecification().name()->domain_specific()->itemID( simplelist[simplecnt]);

                operationl->request()->variableAccessSpecification().listOfVariable()->push_back(vacs);



                socket_.async_confirm_request(operationl,
                        boost::bind(&client::handle_readlist_response, this, operationl));

            }

        }
        else {
            std::cout << "handle_accesslist_response: " << std::endl;
        }
    }

    void handle_readlist_response(boost::shared_ptr<read_operation_type> rslt) {
        if (rslt->response()) {


            std::cout << "access var val: " /*<<     rslt->response()->listOfAccessResult->operator [](0)->*/ << std::endl;



        }
        else {
            std::cout << "handle_readlist_response: " << std::endl;
        }
    }

    void handle_release(const boost::system::error_code& error) {
        // std::cout << "Client release :" << (error ? "error " : "success") << std::endl;
        //if (trans_) {
        //    std::cout << "Server release data : " << trans_->respond_str() << std::endl;
        // }
    }

    void do_close() {
        //   socket_.close();
    }

private:
    boost::asio::io_service& io_service_;
    socket_type socket_;
    std::string domain;
    std::vector<std::string> fulllist;
    std::vector<std::string> simplelist;
    std::size_t fullcnt;
    std::size_t simplecnt;

};

#else

class session {
public:

    session(boost::asio::io_service& io_service, asn_coder_ptr trans)
    : socket_(io_service, SELECTOR), trans_(trans) {
        std::cout << "New sesion\n";
    }

    socket_type& socket() {
        return socket_;
    }

    void run() {
        if (trans_)
            std::cout << "Client accept data : " << trans_->respond_str() << std::endl;
        boost::system::error_code ec;
        while (!ec) {
            std::size_t bytes_transferred = socket_.read_some(boost::asio::buffer(data_, max_length), ec);
            if (ec) break;
            message = std::string(data_, bytes_transferred);
            std::cout << "Server read: " << message << " size: " << message.size() << std::endl;
            socket_.write_some(boost::asio::buffer(data_, bytes_transferred), ec);
        }
    }

private:


    socket_type socket_;
    char data_[max_length];
    std::string message;
    asn_coder_ptr trans_;
};

class server {
public:

    server(boost::asio::io_service& io_service, short port)
    : io_service_(io_service),
    acceptor_(io_service, endpoint_type(boost::asio::ip::tcp::v4(), port)) {
        start_accept();
    }

private:

    void start_accept() {
        while (true) {

            asn_coder_ptr trans_ = boost::itu::create_simple_data("Hello client from test");

            session* new_session = new session(io_service_, trans_);
            boost::system::error_code ec;
            acceptor_.accept(new_session->socket(),
#if defined(PRES_PROT)
                    trans_,
#elif defined(SESSION_PROT)
                    trans_,
#else
#endif            
                    ec);
            if (ec)
                delete new_session;
            else
                new_session->run();
        };
    }

    boost::asio::io_service& io_service_;
    acceptor_type acceptor_;
};

class client {
public:

    client(boost::asio::io_service& io_service,
            resolver_type::iterator endpoint_iterator, const std::string& called = "")
    : io_service_(io_service),
    socket_(io_service, SELECTOR) {

        trans_ = boost::itu::create_simple_data("Hello server  from test");

        boost::system::error_code ec;
        endpoint_type endpoint = *endpoint_iterator;
        socket_.connect(endpoint,
#if defined(PRES_PROT)
                trans_,
#elif defined(SESSION_PROT)
                trans_,
#else
#endif          
                ec);
        if (!ec) {
            if (trans_)
                std::cout << "Client accept data : " << trans_->respond_str() << std::endl;
        }
    }

    ~client() {
        if (socket_.is_open()) {
            socket_.close();
        }
    }

    void release() {
#if defined(PRES_PROT)

#elif defined(SESSION_PROT)
        trans_ = asn_coder_ptr(new trans_data("Goodbuy server  from test"));
        boost::system::error_code ecc;
        socket_.releaseconnect(boost::itu::SESSION_NORMAL_RELEASE, trans_, ecc);
        if (trans_)
            std::cout << "Server release data : " << trans_->respond_str() << std::endl;

#else
        boost::system::error_code ecc;
        socket_.releaseconnect(ecc);
#endif  
    }

    void write(const std::string& msg) {


        message = msg;
        boost::system::error_code ec;
        socket_.write_some(boost::asio::buffer(message.data(), message.size()), ec);
        std::size_t bytes_transferred = socket_.read_some(boost::asio::buffer(data_, max_length), ec);
        std::cout << "Client read:" << std::string(data_, bytes_transferred) << " size: " << bytes_transferred << std::endl;

    }

    void close() {
        socket_.close();
    }



private:
    boost::asio::io_service& io_service_;
    socket_type socket_;
    std::string message;
    asn_coder_ptr trans_;
    char data_[max_length];
};


#endif

using itu::utils::callable_shared_ptr;
using itu::utils::addmillisec_to_now;
using itu::utils::to_str;

using namespace std;

#define THD_EXCLUSIVE_LOCK(a)  boost::mutex::scoped_lock thlock( a );

struct Server {

    Server(boost::asio::io_service & serv) : terminated_(false), io_service(serv), server_(io_service, port) {
    }

    bool operator()() {
        //io_service.run(); 
        while (!terminated_) {
            boost::xtime xt_loop;
            addmillisec_to_now(xt_loop, 100);
            boost::thread::sleep(xt_loop);
        }
        io_service.stop();
        return true;
    }

    void terminate() {
        terminated_ = true;
    }

private:
    bool terminated_;
    boost::asio::io_service& io_service;
    server server_;
};

typedef callable_shared_ptr< Server > server_ptr;

struct Client {

    Client(boost::asio::io_service& serv, const std::string & host) : terminated_(false), io_service(serv), resolver(io_service), query(boost::asio::ip::tcp::v4(), host, to_str(port)),
    iterator(resolver.resolve(query)),
    client_(io_service, iterator, "SERVER-TSEL") {
    }

    bool operator()() {
        // io_service.run(); 
        while (!terminated_) {
            {
                THD_EXCLUSIVE_LOCK(mtx)
                if (msg.size()) {
                    io_service.reset();
                    //client_.write(msg);
                    io_service.run();
                    msg = "";
                }
            }
            boost::xtime xt_loop;
            addmillisec_to_now(xt_loop, 100);
            boost::thread::sleep(xt_loop);
        }
        //io_service.stop();
        //client_.release();
        return true;
    }

    void set(const std::string & ms) {
        THD_EXCLUSIVE_LOCK(mtx)
        msg = ms;
    }

    void terminate() {
        terminated_ = true;
    }

private:
    bool terminated_;
    boost::asio::io_service& io_service;
    resolver_type resolver;
    resolver_type::query query;
    resolver_type::iterator iterator;
    client client_;
    boost::mutex mtx;
    std::string msg;
};




typedef callable_shared_ptr< Client > client_ptr;

struct IO {

    IO(boost::asio::io_service & serv) : terminated_(false), io_service(serv) {
    }

    bool operator()() {
        io_service.run();
        while (!terminated_) {
            boost::xtime xt_loop;
            addmillisec_to_now(xt_loop, 100);
            boost::thread::sleep(xt_loop);
        }
        // io_service.stop();
        return true;
    }

    void terminate() {
        terminated_ = true;
    }

private:
    bool terminated_;
    boost::asio::io_service& io_service;

};




typedef callable_shared_ptr<IO > io_ptr;

int main(int argc, char* argv[]) {



    try {
        if (argc < 2) {

            boost::asio::io_service io_service;

            server_ptr ss = server_ptr(new Server(io_service));
            boost::thread serverth = boost::thread(ss);

            io_ptr io = io_ptr(new IO(io_service));
            boost::thread clientio = boost::thread(io);



            std::string quit_in;
            while (true) {
                std::getline(std::cin, quit_in);
                if (quit_in == "q") break;
            }

            ss->terminate();
            serverth.join();



        }
        else {

            boost::asio::io_service io_service;

            client_ptr cc = client_ptr(new Client(io_service, argv[1]));
            boost::thread clientth = boost::thread(cc);

            io_ptr io = io_ptr(new IO(io_service));
            boost::thread clientio = boost::thread(io);



            std::string quit_in;
            while (true) {
                std::getline(std::cin, quit_in);
                if (quit_in == "q") break;
                cc->set(quit_in);
            }


            cc->terminate();
            clientth.join();






        }

    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

}