
#include "mmsioclient.h"


namespace prot9506 {

    const service_option_type& MMS_SERVICE_OPTOION_CLNT() {
        static service_option_type vl = MMSO::serviceSupportOptions_status | MMSO::serviceSupportOptions_getNameList | MMSO::serviceSupportOptions_identify | MMSO::serviceSupportOptions_read | MMSO::serviceSupportOptions_write |
                MMSO::serviceSupportOptions_defineNamedVariableList | MMSO::serviceSupportOptions_deleteNamedVariableList | MMSO::serviceSupportOptions_getVariableAccessAttributes | MMSO::serviceSupportOptions_informationReport;
        return vl;
    }
    
    const parameter_option_type& MMS_CBB_OPTION_CLNT(){
        static parameter_option_type vl = MMSO::parameterSupportOptions_str1 | MMSO::parameterSupportOptions_str2 | MMSO::parameterSupportOptions_valt | MMSO::parameterSupportOptions_valt |
            MMSO::parameterSupportOptions_vnam | MMSO::parameterSupportOptions_vadr | MMSO::parameterSupportOptions_tpy | MMSO::parameterSupportOptions_vlis;
        return vl;}

    mmsioclient::mmsioclient() : io_service_(), socket_(io_service_, 
            prot9506::protocol_option(MMS_SERVICE_OPTOION_CLNT(), MMS_CBB_OPTION_CLNT())),  
            tmout_timer(io_service_), state_(disconnected), timout(),  is_data_ready(false), is_timout(false), 
            is_connect(false), is_error(false), error_cod(0) {
    }

    mmsioclient::~mmsioclient() {
        if (state_ == connected) disconnect();
    }

    void mmsioclient::connect(const std::string hst, const std::string prt, const std::string opt,  std::size_t tmo) {
        timout = tmo < 10 ? 10 : ( (tmo>600000) ?  600000 : tmo);
        socket_.aselector(opt);        
        boost::asio::ip::tcp::resolver resolver(io_service_);
        boost::asio::ip::tcp::resolver::query query(hst.c_str(), prt.c_str());

        is_timout = false;
        is_connect = false;
        is_error = false;
        error_cod = 0;

        io_service_.reset();

        boost::asio::ip::tcp::resolver::iterator itr(resolver.resolve(query));   
        endpoint_type endpoint = * itr;
                
        /*resolver.async_resolve(query,
                boost::bind(&mmsioclient::handle_resolve, shared_from_this(),
                boost::asio::placeholders::error,
                boost::asio::placeholders::iterator));*/
        
             socket_.async_connect(endpoint,
                boost::bind(&mmsioclient::handle_connect, shared_from_this(),
                boost::asio::placeholders::error,
                ++itr));        

        tmout_timer.expires_from_now(boost::posix_time::milliseconds(timout));
        tmout_timer.async_wait(boost::bind(
                &mmsioclient::handle_timout_expire, shared_from_this(),
                boost::asio::placeholders::error));

        io_service_.run();

        if (!is_connect) {
            state_ = disconnected;
            try {
                socket_.close();
                io_service_.stop();
            } catch (...) {
            };
            throw boost::itu::ER_NAADDRESS;//dvnci::dvncierror(dvnci::ERROR_NONET_CONNECTED);
        }
        state_ = connected;
    }

    void mmsioclient::disconnect() {
        state_ = disconnected;
        socket_.close();
        io_service_.stop();
    }

    void mmsioclient::handle_resolve(const boost::system::error_code& err,
            boost::asio::ip::tcp::resolver::iterator endpoint_iterator) {
         if (!err) {

             boost::asio::ip::tcp::endpoint endpoint = *endpoint_iterator;
             
             socket_.async_connect(endpoint,
                boost::bind(&mmsioclient::handle_connect, shared_from_this(),
                boost::asio::placeholders::error,
                ++endpoint_iterator));}
         else {
             io_service_.stop();
             tmout_timer.cancel();
             is_timout   = false;
             is_connect  = false;
             error_cod      = err.value();
             is_error       = true;}
    }

    void mmsioclient::handle_connect(const boost::system::error_code& err,
            boost::asio::ip::tcp::resolver::iterator endpoint_iterator) {

        if (!err) {
            io_service_.stop();
            tmout_timer.cancel();
            is_timout   = false;
            is_connect  = true;
            is_error       = false;}
        else
            if (endpoint_iterator != boost::asio::ip::tcp::resolver::iterator()) {
            socket_.close();
            boost::asio::ip::tcp::endpoint endpoint = *endpoint_iterator;
            socket_.async_connect(endpoint,
                    boost::bind(&mmsioclient::handle_connect, shared_from_this(),
                    boost::asio::placeholders::error, ++endpoint_iterator));}
        else {}
    }

    void mmsioclient::handle_timout_expire(const boost::system::error_code& err) {

        if (!err ) {
            io_service_.stop();
            socket_.close();
            is_timout      = true;
            is_data_ready  = false;
            is_error       = false;
            is_connect     = false;}
        else {}
    }

    const protocol_option & mmsioclient::mmsoption() const {
        return socket_.mmsoption();
    }

    bool mmsioclient::can_identyfy() const {
        return (mmsoption().service() & MMSO::serviceSupportOptions_identify);
    }

    bool mmsioclient::can_read() const {
        return (mmsoption().service() & MMSO::serviceSupportOptions_read);
    }

    bool mmsioclient::can_write() const {
        return (mmsoption().service() & MMSO::serviceSupportOptions_write);
    }

    bool mmsioclient::can_namedlist() const {
        return false;
        return ((mmsoption().service() & MMSO::serviceSupportOptions_defineNamedVariableList) && 
                (mmsoption().service() & MMSO::serviceSupportOptions_deleteNamedVariableList));
    }             
    
}



