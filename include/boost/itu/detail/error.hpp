//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ERRORIMPLEMENTATIUON_H_
#define	_ITU_ERRORIMPLEMENTATIUON_H_

#include <boost/itu/coder/base_coder.hpp>

//#define CHECK_ISO_SELECTOR


namespace boost {
    namespace itu {

        // ref X224 = ITU-T Rec. X.224(1995 E)

        using boost::system::error_code;

        const error_code ER_BEDSEQ = error_code(boost::system::errc::illegal_byte_sequence, boost::system::system_category());
        const error_code ER_REQBUSY = error_code(boost::system::errc::device_or_resource_busy, boost::system::system_category());
        const error_code ER_NOBUFFER = error_code(boost::system::errc::no_buffer_space, boost::system::system_category());
        const error_code ER_PROTOCOL = error_code(boost::system::errc::protocol_error, boost::system::system_category());
        const error_code ER_BADADDRESS = error_code(boost::system::errc::bad_address, boost::system::system_category());
        const error_code ER_NAADDRESS = error_code(boost::system::errc::address_not_available, boost::system::system_category());
        const error_code ER_OUTDOMAIN = error_code(boost::system::errc::argument_out_of_domain, boost::system::system_category());
        const error_code ER_PROTOPT = error_code(boost::system::errc::no_protocol_option, boost::system::system_category());
        const error_code ER_INOUT = error_code(boost::system::errc::io_error, boost::system::system_category());
        const error_code ER_REFUSE = error_code(boost::system::errc::connection_refused, boost::system::system_category());
        const error_code ER_ABORT = error_code(boost::system::errc::connection_aborted, boost::system::system_category());
        const error_code ER_RELEASE = error_code(boost::system::errc::connection_reset, boost::system::system_category());
        const error_code ER_NOLINK = error_code(boost::system::errc::no_link, boost::system::system_category());
        const error_code ER_EAGAIN = error_code(boost::system::errc::resource_unavailable_try_again, boost::system::system_category());
        const error_code ER_TIMEOUT = error_code(boost::system::errc::timed_out, boost::system::system_category());
        const error_code ER_INPROGRESS = error_code(boost::system::errc::operation_in_progress, boost::system::system_category());




        // Disconnection  REASON CODE *ref X224  13.5.3 d) and  *ref X225 8.3.5.10          
        const octet_type DR_REASON_NODEF = '\x00'; // Reason not specified         
        const octet_type DR_REASON_CONGST = '\x01'; // Congestion at TSAP  - ER_EAGAIN             
        const octet_type DR_REASON_SESSION = '\x02'; // Session entity not attached to TSAP                       
        const octet_type DR_REASON_ADDRESS = '\x03'; // address   error  - ER_NAADDRESS
        const octet_type DR_REASON_NORM = '\x80'; // Normal disconnect initiated by session entity.  -ER_RELEASE
        const octet_type DR_REASON_RCNGS = '\x81'; //Remote transport entity congestion at connect request time. -ER_REQBUSY   
        const octet_type DR_REASON_NEGOT = '\x82'; // Connection negotiation failed [i.e. proposed class(es) not supported].-ER_REQBUSY
        const octet_type DR_REASON_PROTO = '\x85'; // Protocol error.  -ER_PROTOCOL
        const octet_type DR_REASON_USER = '\x86'; // User refuse.  -ER_PROTOCOL        
        const octet_type DR_REASON_INVLN = '\x8A'; // Header or parameter length invalid.

        error_code errorcode_by_reason(octet_type val);
             

    }
} // namespace boost

#endif	

