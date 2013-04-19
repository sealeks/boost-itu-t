//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <cstdlib>
#include <deque>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define BOOST_THREAD_USE_LIB

#include <boost/thread/thread.hpp>
#include <boost/itu/utils/utils.h>

#define SESSION_PROT


#if defined(SESSION_PROT)
#include <boost/itu/x22X/x225.hpp>
#else
#include <boost/itu/rfc1006/rfc1006.hpp>
#endif






#define  PRINT_INPUT( val )        if (socket_.rootcoder()->respond_str().size() < 200) \
            std::cout << val <<" data, size: " << socket_.rootcoder()->respond_str().size()  << " data : " << socket_.rootcoder()->respond_str() << std::endl;\
        else\
            std::cout << val <<"  more 200 bytes, datasize: " << socket_.rootcoder()->respond_str().size() << " data :   ..." << socket_.rootcoder()->respond_str().substr(socket_.rootcoder()->respond_str().size() - 199)<< ""<< std::endl;

#define  PRINT_OUTPUT( val )        if (socket_.rootcoder()->request_str().size() < 200) \
            std::cout << val <<" datasize: " << socket_.rootcoder()->request_str().size()  << " data : " << socket_.rootcoder()->request_str() << std::endl;\
        else\
            std::cout << val <<"  more 200 bytes, datasize: " << socket_.rootcoder()->request_str().size() << " data : ..." << socket_.rootcoder()->request_str().substr(socket_.rootcoder()->request_str().size() - 199) << ""<< std::endl;

std::size_t MULTIFACTOR =19;

std::string CONNECT_DATA = std::string(12000, 'e');//"CONNECT-DATA";
std::string RELEASE_DATA = "RELEASE-DATA";
std::string ABORT_DATA = "ABORT-DATA";

inline static std::string generate_message(std::string vl) {
    if ((vl == "release" || vl == "abort" || vl == "release!" || vl == "abort!"))
        return vl;

    std::size_t r = MULTIFACTOR;
    while (r--) {
        vl += vl;
    }
    return vl;
}

enum {
    max_length = 100
};



#if defined(SESSION_PROT)
using boost::itu::x225;
typedef boost::itu::x225 protocol_type;
#else
using boost::itu::rfc1006;
typedef boost::itu::rfc1006 protocol_type;
#endif

typedef boost::itu::selectorvalue_type selectorvalue_type;
typedef protocol_type::selector selector_type;
typedef protocol_type::socket socket_type;
typedef protocol_type::acceptor acceptor_type;
typedef protocol_type::endpoint endpoint_type;
typedef protocol_type::resolver resolver_type;



#if defined(SESSION_PROT)

typedef protocol_type::t_selector lowselector_type;
const selector_type SELECTOR = selector_type(selectorvalue_type("SERVER-SSEL"), lowselector_type(selectorvalue_type("SERVER-TSEL")));
#else
const selector_type SELECTOR = selector_type(selectorvalue_type("SERVER-TSEL"));
#endif

int port = 102;

#define SESSION_CODER
//#define NET_BLOCKING

#ifndef NET_BLOCKING

class session {
public:

    session(boost::asio::io_service& io_service)
    : socket_(io_service, SELECTOR) {
        std::cout << "New sesion\n";
    }

    ~session() {
        std::cout << " Kill session\n";
    }

    socket_type& socket() {
        return socket_;
    }

    void start() {
#if defined(SESSION_PROT)  
         PRINT_INPUT("Server S-CONNECT-ind" )
#endif        

#if defined(SESSION_PROT)  &&   defined(SESSION_CODER)    
        socket_.async_response(
                boost::bind(&session::handle_conversation, this,
                boost::asio::placeholders::error));
#else       
        socket_.async_read_some(boost::asio::buffer(data_, max_length),
                boost::bind(&session::handle_read, this,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
#endif                
    }

private:

    void handle_read(const boost::system::error_code& error,
            size_t bytes_transferred) {
        if (!error) {
            if (!socket_.ready()) {
                std::cout << "Server read: " << std::string(data_, bytes_transferred) << " size: " << bytes_transferred  << std::endl;
                std::cout << "Server read continiue" << std::endl;
                socket_.async_read_some(boost::asio::buffer(data_, max_length),
                        boost::bind(&session::handle_read, this,
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
                return;
            }
            message = std::string(data_, bytes_transferred);
            if (!(message == "release!" || message == "abort!")) {

                boost::asio::async_write(socket_,
                        boost::asio::buffer(data_, bytes_transferred),
                        boost::bind(&session::handle_write, this,
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
                std::cout << "Server read: " << std::string(data_, bytes_transferred) << " size: " << bytes_transferred << std::endl;
                message = std::string(data_, bytes_transferred);
            }
            else {
                std::cout << "Client wants " << message << std::endl;
                if (message == "release!") {
#if defined(SESSION_PROT)                         
                    socket_.rootcoder()->request_str(RELEASE_DATA);
                    PRINT_OUTPUT("Server S-FINISH-req" )
                    socket_.async_release(boost::bind(&session::handle_release, this, boost::asio::placeholders::error));
#else
                    socket_.async_release(boost::bind(&session::handle_release, this, boost::asio::placeholders::error));
#endif                        
                }
                else {
#if defined(SESSION_PROT)                         
                    socket_.rootcoder()->request_str(ABORT_DATA);
                    PRINT_OUTPUT("Server S-ABORT-req" )
                    socket_.async_abort(boost::bind(&session::handle_abort, this, boost::asio::placeholders::error));
#else
                    socket_.async_release(boost::bind(&session::handle_release, this, boost::asio::placeholders::error));
#endif   
                }
            }
        }
        else {
            std::cout << "Finish session with error :  " << error.message() << std::endl;
#if defined(SESSION_PROT)              
            PRINT_INPUT("Server S-RELEASE-conf" )
#endif              
            delete this;
        }
    }

    void handle_write(const boost::system::error_code& error,
            size_t bytes_transferre) {
        if (!error) {
            std::cout << "Server write: " << message << " size: " << message.size() << std::endl;
            socket_.async_read_some(boost::asio::buffer(data_, max_length),
                    boost::bind(&session::handle_read, this,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));
            std::cout << "available: " << socket_.ready() << std::endl;

        }
        else {
            std::cout << "Finish session with error :  " << error.message() << std::endl;
#if defined(SESSION_PROT)            
            PRINT_INPUT("Server S-RELEASE-ind" )
#endif              
            delete this;
        }
    }

    void handle_conversation(const boost::system::error_code& error) {
        if (!error) {
            PRINT_INPUT("Server S-DATA-ind" )
            message = socket_.rootcoder()->respond_str();
            if (!(message == "release!" || message == "abort!")) {
                socket_.rootcoder()->request_str(socket_.rootcoder()->respond_str());
                socket_.async_conversation(boost::bind(&session::handle_conversation, this,
                        boost::asio::placeholders::error));
            }
            else {
                std::cout << "Client wants " << message << std::endl;
                if (message == "release!") {
#if defined(SESSION_PROT)                         
                    socket_.rootcoder()->request_str(RELEASE_DATA);
                    PRINT_OUTPUT("Server S-FINISH-req" )
                    socket_.async_release(boost::bind(&session::handle_release, this, boost::asio::placeholders::error));
#else
                    socket_.async_release(boost::bind(&session::handle_release, this, boost::asio::placeholders::error));
#endif                        
                }
                else {
#if defined(SESSION_PROT)                         
                    socket_.rootcoder()->request_str(ABORT_DATA);
                    PRINT_OUTPUT("Server S-ABORT-req" )
                    socket_.async_abort(boost::bind(&session::handle_abort, this, boost::asio::placeholders::error));
#else
                    socket_.async_release(boost::bind(&session::handle_release, this, boost::asio::placeholders::error));
#endif   
                }
            }
        }
        else {
            std::cout << "Finish session with error :  " << error.message() << std::endl;
#if defined(SESSION_PROT)            
            PRINT_INPUT("Server S-RELEASE-ind" )
#endif              
            delete this;
        }
    }

    void handle_release(const boost::system::error_code& error) {
        if (!error) {
            std::cout << "Release success" << std::endl;
#if defined(SESSION_PROT)         
            PRINT_INPUT("Server S-RELEASE-ind" )
#endif
        }
        else
            std::cout << "handle_release error: " << error << std::endl;
        delete this;
    }

    void handle_abort(const boost::system::error_code& error) {
        if (!error) {
            std::cout << "Abort success" << std::endl;
#if defined(SESSION_PROT)         
            //std::cout << "Server release data : " << socket_.rootcoder()->respond_str() << std::endl;
#endif
        }
        else
            std::cout << "handle_abort error: " << error << std::endl;
        delete this;
    }



    socket_type socket_;
    char data_[max_length];
    std::string message;
};

class server {
public:

    server(boost::asio::io_service& io_service, short port)
    : io_service_(io_service),
    acceptor_(io_service, endpoint_type(boost::asio::ip::tcp::v4(), port), SELECTOR) {
        start_accept();
    }

private:

    void start_accept() {
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

    client(boost::asio::io_service& io_service,
            resolver_type::iterator endpoint_iterator)
    : io_service_(io_service),
    socket_(io_service, SELECTOR) {
        endpoint_type endpoint = *endpoint_iterator;

#if defined(SESSION_PROT)
        socket_.rootcoder()->request_str(CONNECT_DATA);
#endif  

        socket_.async_connect(endpoint,
                boost::bind(&client::handle_connect, this,
                boost::asio::placeholders::error, ++endpoint_iterator));
    }

    ~client() {
        if (socket_.is_open()) {
            socket_.close();
        }
    }

    void write(const std::string& msg) {
        message = generate_message(msg);
        io_service_.post(boost::bind(&client::do_write, this));
    }


private:

    void handle_connect(const boost::system::error_code& error,
            resolver_type::iterator endpoint_iterator) {
        if (!error) {
#if defined(SESSION_PROT)                
            PRINT_INPUT("Client S-CONNECT-conf" )
#else
            std::cout << "Client successfull connect" << std::endl;
#endif                
        }
        else {
            std::cout << "Connect fail with error:" << error << std::endl;
            if (endpoint_iterator != resolver_type::iterator()) {
                std::cout << "Next endpoint:" << std::endl;
                endpoint_type endpoint = *endpoint_iterator;
                socket_.async_connect(endpoint,
                        boost::bind(&client::handle_connect, this,
                        boost::asio::placeholders::error, ++endpoint_iterator));
            }
        }
    }

    void handle_write(const boost::system::error_code& error,
            size_t bytes_transferred) {
        if (!error) {
            socket_.async_read_some(boost::asio::buffer(data_, max_length),
                    boost::bind(&client::handle_read, this,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));
        }
        else
            std::cout << "handle_write error: " << error << std::endl;
    }

    void handle_read(const boost::system::error_code& error,
            size_t bytes_transferred) {
        if (!error) {
            std::cout << "Client read:" << std::string(data_, bytes_transferred) << " size: " << bytes_transferred << " is complete: " << socket_.ready() << std::endl;
            if (!socket_.ready()) {
                std::cout << "Client read continiu" << std::endl;
                socket_.async_read_some(boost::asio::buffer(data_, max_length),
                        boost::bind(&client::handle_read, this,
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
                return;

            }
        }
        else
            std::cout << "handle_read error: " << error << std::endl;
    }

    void handle_conversation(const boost::system::error_code& error) {
#if defined(SESSION_PROT)   
        if (!error) {
            PRINT_INPUT("Client S-DATA-ind" )
        }
        else
            std::cout << "handle_conversation error: " << error << std::endl;
#endif       
    }

    void handle_release(const boost::system::error_code& error) {
        if (!error) {
            std::cout << "Release success" << std::endl;
#if defined(SESSION_PROT)         
            PRINT_INPUT("Client S-RELEASE-conf" )
#endif
        }
        else
            std::cout << "handle_release error: " << error << std::endl;
    }

    void handle_abort(const boost::system::error_code& error) {
        if (!error) {
            std::cout << "Abort success" << std::endl;
#if defined(SESSION_PROT)         
            //std::cout << "Server release data : " << socket_.rootcoder()->respond_str() << std::endl;
#endif
        }
        else
            std::cout << "handle_abort error: " << error << std::endl;
    }

    void do_write() {
        if (socket_.is_open()) {
            if (!(message == "release" || message == "abort")) {
                std::cout << "Client write message:" << " size: " << message.size() << std::endl;
#if defined(SESSION_PROT)  &&   defined(SESSION_CODER) 
                socket_.rootcoder()->request_str(message);
                socket_.async_conversation(boost::bind(&client::handle_conversation, this,
                        boost::asio::placeholders::error));
#else               
                socket_.async_write_some(
                        boost::asio::buffer(message.data(),
                        message.size()),
                        boost::bind(&client::handle_write, this,
                        boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
#endif                
            }
            else {
                std::cout << "Client " << message << std::endl;
                if (message == "release") {
#if defined(SESSION_PROT)                         
                    socket_.rootcoder()->request_str(RELEASE_DATA);
                    PRINT_OUTPUT("Client S-RELEASE-req" )
                    socket_.async_release(boost::bind(&client::handle_release, this, boost::asio::placeholders::error));
#else
                    socket_.async_release(boost::bind(&client::handle_release, this, boost::asio::placeholders::error));
#endif                        
                }
                else {
#if defined(SESSION_PROT)                         
                    socket_.rootcoder()->request_str(ABORT_DATA);
                    PRINT_OUTPUT("Client S-ABORT-req" )
                    socket_.async_abort(boost::bind(&client::handle_abort, this, boost::asio::placeholders::error));
#else
                    socket_.async_release(boost::bind(&client::handle_release, this, boost::asio::placeholders::error));
#endif   
                }
            }
        }
        else {
            std::cout << "Socket closed" << std::endl;
        }
    }

private:
    boost::asio::io_service& io_service_;
    socket_type socket_;
    std::string message;
    char data_[max_length];
};

#else

class session {
public:

    session(boost::asio::io_service& io_service)
    : socket_(io_service, SELECTOR) {
        std::cout << "New sesion\n";
    }

    socket_type& socket() {
        return socket_;
    }

    void run() {
#if defined(SESSION_PROT)         
        PRINT_INPUT("Server S-CONNECT-ind" )
#endif        

        boost::system::error_code ec;
#if defined(SESSION_PROT)  &&   defined(SESSION_CODER)    
        while (!ec) {
            socket_.response(ec);
            if (ec)
                break;

            PRINT_INPUT("Server S-DATA-ind" )
            
            message = socket_.rootcoder()->respond_str();
            if (!(message == "release!" || message == "abort!")) {
                socket_.rootcoder()->request_str(socket_.rootcoder()->respond_str());
                //PRINT_OUTPUT("Server S-DATAcnf" )
                socket_.request(ec);
            }
            else {
                std::cout << "Client wants " << message << std::endl;
                if (message == "release!") {

                    release();
                    ec = boost::itu::ER_RELEASE;
                    break;
                }
                else {
                   
                    socket_.rootcoder()->request_str(ABORT_DATA);
                    abort();

                    ec = boost::itu::ER_ABORT;
                    break;
                }
            }
        }
#else            
        std::size_t bytes_transferred = 0;
        while (!ec) {
            bytes_transferred = socket_.read_some(boost::asio::buffer(data_, max_length), ec);
            std::cout << "Server read: " << std::string(data_, bytes_transferred) << " size: " << bytes_transferred << std::endl;
            while (!socket_.ready() && !ec) {
                bytes_transferred = socket_.read_some(boost::asio::buffer(data_, max_length), ec);
                std::cout << "Server read: " << std::string(data_, bytes_transferred) << " size: " << bytes_transferred << std::endl;
            }
            if (ec) break;
            message = std::string(data_, bytes_transferred);
            if (!(message == "release!" || message == "abort!")) {
                socket_.write_some(boost::asio::buffer(data_, bytes_transferred), ec);
            }
            else {
                std::cout << "Client wants " << message << std::endl;
                if (message == "release!") {
#if defined(SESSION_PROT)                         
                    socket_.rootcoder()->request_str(RELEASE_DATA);
                    release();
#else
                    release();
#endif                        
                    ec = boost::itu::ER_RELEASE;
                    break;
                }
                else {
#if defined(SESSION_PROT)                         
                    socket_.rootcoder()->request_str(ABORT_DATA);
                    abort();
#else
                    release();
#endif   
                    ec = boost::itu::ER_ABORT;
                    break;
                }
            }
        }
        std::cout << "Session finish with error: " << ec.message() << std::endl;
        delete this;
#endif          
    }

    void release() {
#if defined(SESSION_PROT)
        socket_.rootcoder()->request_str(RELEASE_DATA);
        PRINT_OUTPUT("Server S-FINISH-req" )
        boost::system::error_code ecc;
        socket_.release(ecc);
        if (!ecc) {
            PRINT_INPUT("Server S-RELESE-ind")
        }
        else
            std::cout << "Server release error : " << ecc << std::endl;

#else
        boost::system::error_code ec;
        socket_.release(ec);
        if (!ec)
            std::cout << "Socket release success" << std::endl;
        else
            std::cout << "Socket release error" << ec << std::endl;
#endif  
    }

    void abort() {
#if defined(SESSION_PROT)
        socket_.rootcoder()->request_str(ABORT_DATA);
        PRINT_OUTPUT("Server S-ABORT-req")
        boost::system::error_code ecc;
        socket_.abort(ecc);
        if (!ecc)
            std::cout << "Server success abort " << std::endl;
        else
            std::cout << "Server abort error : " << ecc << std::endl;

#else
        boost::system::error_code ec;
        socket_.release(ec);
        if (!ec)
            std::cout << "Socket release success" << std::endl;
        else
            std::cout << "Socket release error" << ec << std::endl;
#endif  
    }

private:


    socket_type socket_;
    char data_[max_length];
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
        while (true) {


            session* new_session = new session(io_service_);
            boost::system::error_code ec;
            acceptor_.accept(new_session->socket(),
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
            resolver_type::iterator endpoint_iterator)
    : io_service_(io_service),
    socket_(io_service, SELECTOR) {

#if defined(SESSION_PROT)
        socket_.rootcoder()->request_str(CONNECT_DATA);
        PRINT_OUTPUT("Client S-CONNECT-req")
#endif       

        boost::system::error_code ec;
        while (endpoint_iterator != resolver_type::iterator()) {
            endpoint_type endpoint = *endpoint_iterator;
            socket_.connect(endpoint,
                    ec);
            if (!ec) {
                std::cout << "Client successfull connect" << std::endl;
#if defined(SESSION_PROT)
       PRINT_INPUT("Client S-CONNECT-cnf")
#endif                       
                return;
            }
            else {
                std::cout << "Connect fail with error:" << ec << std::endl;
                ++endpoint_iterator;
            }
        }

#if defined(SESSION_PROT)
        if (!ec){
            PRINT_INPUT("Client S-RELEASE-cnf")}
#endif  
    }

    ~client() {
        if (socket_.is_open()) {
            socket_.close();
        }
    }

    void write(const std::string& msg) {

        if (socket_.is_open()) {
            message = generate_message(msg);

            boost::system::error_code ec;

            if (!(msg == "release" || msg == "abort")) {
                std::cout << "Client write data size =" << message.size() << std::endl;
#if defined(SESSION_PROT)  &&   defined(SESSION_CODER) 
                socket_.rootcoder()->request_str(message);
                socket_.conversation(ec);
                PRINT_INPUT("Client read")
#else                 
                boost::system::error_code ec;
                socket_.write_some(boost::asio::buffer(message.data(), message.size()), ec);
                std::size_t bytes_transferred = socket_.read_some(boost::asio::buffer(data_, max_length), ec);
                std::cout << "Client read data:" << std::string(data_, bytes_transferred) << " size: " << bytes_transferred << std::endl;
                if (!socket_.ready()) {
                    while (!ec && !socket_.ready()) {
                        bytes_transferred = socket_.read_some(boost::asio::buffer(data_, max_length), ec);
                        std::cout << "Client read cont:" << std::string(data_, bytes_transferred) << " size: " << bytes_transferred << std::endl;
                    }
                }
#endif                  
            }
            else {
                std::cout << "Client " << message << std::endl;
                if (message == "release") {
                    release();
                }
                else {
                    abort();
                }
            }
        }
        else {
            std::cout << "Socket closed" << std::endl;
        }

    }

    void release() {
#if defined(SESSION_PROT)
        socket_.rootcoder()->request_str(RELEASE_DATA);
        PRINT_OUTPUT("Client S-RELEASE-req")
        boost::system::error_code ecc;
        socket_.release(ecc);
        if (!ecc){
            PRINT_INPUT("Client S-RELEASE-conf")
        }
        else
            std::cout << "Server release error : " << ecc << std::endl;

#else
        boost::system::error_code ec;
        socket_.release(ec);
        if (!ec)
            std::cout << "Socket release success" << std::endl;
        else
            std::cout << "Socket release error" << ec << std::endl;
#endif  
    }

    void abort() {
#if defined(SESSION_PROT)
        socket_.rootcoder()->request_str(ABORT_DATA);
        PRINT_OUTPUT("Client S-ABORT-req")        
        boost::system::error_code ecc;
        socket_.abort(ecc);
        if (!ecc)
            std::cout << "Server success abort " << std::endl;
        else
            std::cout << "Server abort error : " << ecc << std::endl;

#else
        boost::system::error_code ec;
        socket_.release(ec);
        if (!ec)
            std::cout << "Socket release success" << std::endl;
        else
            std::cout << "Socket release error" << ec << std::endl;
#endif  
    }


private:
    boost::asio::io_service& io_service_;
    socket_type socket_;
    std::string message;
    char data_[max_length];
};


#endif

using itu::utils::callable_shared_ptr;
using itu::utils::addmillisec_to_now;
using itu::utils::to_str;


#define THD_EXCLUSIVE_LOCK(a)  boost::mutex::scoped_lock thlock( a );

using namespace std;

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
    client_(io_service, iterator) {
    }

    bool operator()() {
        // io_service.run(); 
        while (!terminated_) {
            {
                THD_EXCLUSIVE_LOCK(mtx)
                if (msg.size()) {
                    io_service.reset();
                    client_.write(msg);
                    io_service.run();
                    msg = "";
                }
            }
            boost::xtime xt_loop;
            addmillisec_to_now(xt_loop, 100);
            boost::thread::sleep(xt_loop);
        }
        //io_service.stop();
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

