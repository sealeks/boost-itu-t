/* 
 * File:   ns_ioclient.h
 * Author: Serg Alexeev sealeks@mail.ru
 *
 */

#ifndef _DVNCI_KRNL_NS_MMSCLIENT_H
#define	_DVNCI_KRNL_NS_MMSCLIENT_H



#include <boost/asio/read_at.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/make_shared.hpp>
#include <mms/mmssocket.h>


namespace prot9506 {


    //dvnci::ERROR_NONET_CONNECTED

    typedef iso9506 protocol_type;
    typedef protocol_type::socket socket_type;
    typedef protocol_type::acceptor acceptor_type;
    typedef protocol_type::endpoint endpoint_type;
    typedef protocol_type::resolver resolver_type;
    typedef protocol_type::application_selector application_selector;

    const std::size_t MMSDEFAULT_TIMENOUT = 1000;

    class mmsioclient;
    typedef boost::shared_ptr<mmsioclient> mmsioclient_ptr;

    //template<typename T = mms_socket>

    class mmsioclient : public boost::enable_shared_from_this<mmsioclient > {

        //typedef T socket_type;

    public:

        enum connectionState {

            connected, disconnected
        };

        mmsioclient();

        virtual ~mmsioclient();

        connectionState state() {
            return state_;
        }

        void connect(const std::string hst, const std::string prt, const std::string opt, std::size_t tmo = MMSDEFAULT_TIMENOUT);

        void disconnect();

        template<typename T>
        bool req(boost::shared_ptr<T> operation) {

            if (state_ == connected) {

                is_timout = false;
                is_data_ready = false;
                is_error = false;
                is_connect = true;
                error_cod = 0;

                io_service_.reset();

                socket_.async_confirm_request(operation,
                        boost::bind(&mmsioclient::handle_cofirmreq_end<T>, this, operation));

                tmout_timer.expires_from_now(boost::posix_time::milliseconds(timout));
                tmout_timer.async_wait(boost::bind(
                        &mmsioclient::handle_timout_expire, shared_from_this(),
                        boost::asio::placeholders::error));

                io_service_.run();

                if (is_timout) {
                    state_ = disconnected;
                    try {
                        socket_.close();
                        io_service_.stop();
                    } catch (...) {
                    };
                    throw boost::itu::ER_NOLINK;
                }

                if (is_error) {
                    state_ = disconnected;
                    try {
                        socket_.close();
                        io_service_.stop();
                    } catch (...) {
                    };

                    if ((error_cod == 10054) || (error_cod == 10053))
                        throw boost::itu::ER_NOLINK;
                    else if (error_cod == boost::itu::ER_BEDSEQ.value())
                        throw boost::itu::ER_BEDSEQ;
                    else if (error_cod == boost::itu::ER_PROTOCOL.value())
                        throw boost::itu::ER_PROTOCOL;
                }
                return true;
            } else
                throw boost::itu::ER_NOLINK;
            return false;
        }

        template<typename T>
        void handle_cofirmreq_end(boost::shared_ptr<T> operation) {
            io_service_.stop();
            tmout_timer.cancel();
            is_timout = false;
            is_data_ready = true;
            if (operation->error()) {
                is_error = true;
                error_cod = (operation->error() == boost::itu::ER_BEDSEQ) ?
                        boost::itu::ER_BEDSEQ.value() : boost::itu::ER_PROTOCOL.value();
            } else
                is_error = false;
        }


        const protocol_option & mmsoption() const;

        bool can_identyfy() const;

        bool can_read() const;

        bool can_write() const;

        bool can_namedlist() const;

    private:

        void handle_resolve(const boost::system::error_code& err,
                boost::asio::ip::tcp::resolver::iterator endpoint_iterator);

        void handle_connect(const boost::system::error_code& err,
                boost::asio::ip::tcp::resolver::iterator endpoint_iterator);

        void handle_timout_expire(const boost::system::error_code& err);


        boost::asio::io_service io_service_;
        prot9506::mms_socket socket_;
        boost::asio::deadline_timer tmout_timer;
        connectionState state_;
        std::size_t timout;

        volatile bool is_data_ready;
        volatile bool is_timout;
        volatile bool is_connect;
        volatile bool is_error;
        volatile int error_cod;

    };

}


#endif	/* _NS_IOCLIENT_H */

