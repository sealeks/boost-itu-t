//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef _BOOST_ITU_X224_IMPLEMENTATIUON_H_
#define _BOOST_ITU_X224_IMPLEMENTATIUON_H_

#include <boost/asio/basic_socket_acceptor.hpp>
#include <boost/asio/basic_socket_iostream.hpp>
#include <boost/asio/basic_stream_socket.hpp>
#include <boost/asio/detail/socket_option.hpp>
#include <boost/asio/detail/socket_types.hpp>
#include <boost/asio/ip/basic_endpoint.hpp>
#include <boost/asio/ip/basic_resolver.hpp>
#include <boost/asio/ip/basic_resolver_iterator.hpp>
#include <boost/asio/ip/basic_resolver_query.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/bind.hpp>

#include <boost/itu/x22X/selectors.hpp>
#include <boost/itu/detail/error.hpp>


namespace boost {
    namespace itu {
        namespace x224impl {

            // ref X224 = ITU-T Rec. X.224(1995 E)
            // ref RFC1006



            // TPDU code *ref X224  13.1 Table 8   only class 0 implemented ( over RFC1006 )
            const octet_type CR_TPDU_ID = '\xE0'; //Connection request   !!xxxx - out class 0
            const octet_type CC_TPDU_ID = '\xD0'; //Connection confirm   !!xxxx - out class 0
            const octet_type DR_TPDU_ID = '\x80'; //Disconnection request 
            const octet_type DC_TPDU_ID = '\xC0'; //Disconnection  confirm                              !!not used here
            const octet_type DT_TPDU_ID = '\xF0'; //Data !!y - out class 0
            const octet_type ED_TPDU_ID = '\x10'; //Expedited data !!not use here impl                  !!not used here
            const octet_type DA_TPDU_ID = '\x60'; //Data acknowledgement !!not use here impl
            const octet_type EA_TPDU_ID = '\x20'; //Expedited data acknowledgement                      !!not used here
            const octet_type RJ_TPDU_ID = '\x50'; //Reject                                              !!not used here
            const octet_type ER_TPDU_ID = '\x70'; //Error


            // see Disconnection  REASON CODE  iso.h

            // Error REASON CODE *ref X224  13.12.3 c)   
            const octet_type ERT_REASON_NODEF = '\x0'; // Reason not specified    - all ER_PROTOCOL
            const octet_type ERT_REASON_PARAM_CODE = '\x1'; // Invalid parameter code
            const octet_type ERT_REASON_TPDU_TYPE = '\x2'; // Invalid TPDU type
            const octet_type ERT_REASON_PARAM_VALUE = '\x3'; // Invalid parameter value

            // Error REASON CODE *ref X224  13.12.4
            const octet_type ERT_PARAM_ID = '\xC1'; //Parameter code:        

            // VAR ID  *ref X224  13.3.4
            const octet_type VAR_TSAPCALLING_ID = '\xC1'; //calling Transport-Selector *ref X224 13.3.4 a)
            const octet_type VAR_TSAPCALLED_ID = '\xC2'; //called Transport-Selector *ref X224 13.3.4 a)
            const octet_type VAR_TPDU_SIZE = '\xC0'; //TPDU size *ref X224 13.3.4 b)
            const octet_type VAR_MAXTPDU_SIZE = '\xF0'; // Preferred maximum TPDU size *ref X224 13.3.4 c)

            // EOT *ref X224  13.7.3  d)
            const octet_type TPDU_ENDED = '\x80';
            const octet_type TPDU_CONTINIUE = '\x0';

            enum tpdu_type {
                NL = 0,
                CR = CR_TPDU_ID,
                CC = CC_TPDU_ID,
                DR = DR_TPDU_ID,
                DC = DC_TPDU_ID,
                DT = DT_TPDU_ID,
                ED = ED_TPDU_ID,
                DA = DA_TPDU_ID,
                EA = EA_TPDU_ID,
                RJ = RJ_TPDU_ID,
                ER = ER_TPDU_ID
            };

            inline octet_type tpdu_type_primitive(tpdu_type val) {
                return static_cast<octet_type> (val);
            }

            tpdu_type tpdu_type_from(octet_type val);



            //   transport
            // TPDU size  ref X224  13.3.4 b)
            const octet_type TPDU_SIZE8192 = '\xD'; // not denied in 0 class
            const octet_type TPDU_SIZE4096 = '\xC'; // not denied in 0 class
            const octet_type TPDU_SIZE2048 = '\xB';
            const octet_type TPDU_SIZE1024 = '\xA';
            const octet_type TPDU_SIZE512 = '\x9';
            const octet_type TPDU_SIZE256 = '\x8';
            const octet_type TPDU_SIZE128 = '\x7';
            //const octet_type TPDU_SIZE4 = '\x5';   /// test

            class tpdu_size {
                static const uint16_t PREFFERED_TPDU_SIZE = 511; // (510 * 128 = 65408 <  max 65535 * ref RFC1006 )

            public:

                tpdu_size();

                tpdu_size(octet_type bas);

                tpdu_size(const octet_sequnce& pref, octet_type bas = TPDU_SIZE2048);

                uint16_t preferred() const {
                    return preferred_;
                }

                octet_type basic() const {
                    return basic_;
                }

                std::size_t size() const {
                    return size_;
                }

            private:

                void preferred(uint16_t val, octet_type bas);

                void basic(octet_type val);

                static std::size_t size_from_octet(octet_type val);

                uint16_t preferred_;
                octet_type basic_;
                std::size_t size_;
            };

            inline const tpdu_size& less_tpdu(const tpdu_size& left, const tpdu_size& right) {
                if (((bool)left.preferred()) == ((bool)right.preferred()))
                    return left.size() < right.size() ? left : right;
                else
                    return right.preferred() ? left : right;
            }

            const tpdu_size DEFAULT_TPDU_SIZE = tpdu_size();





            typedef std::pair<octet_type, std::size_t> headarvar;

            typedef std::pair<headarvar, octet_sequnce> headarvarvalue;
            typedef std::vector<headarvarvalue> headarvarvalues;



            bool parse_vars(const octet_sequnce& str, headarvarvalues& vars);


            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  x224 protocol_options   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

            struct protocol_options {

                protocol_options() :
                dst_(0), src_(0) {
                }

                protocol_options(int16_t dst, int16_t src,
                        const headarvarvalues& vars = headarvarvalues()) :
                dst_(dst), src_(src), vars_(vars) {
                }

                protocol_options(int16_t dst, int16_t src, const tpdu_size& pdusize,
                        const octet_sequnce& called = NULL_OCTET_SEQUENCE, const octet_sequnce& calling = NULL_OCTET_SEQUENCE);

                protocol_options(const transport_selector & tsl, const tpdu_size& pdusize = DEFAULT_TPDU_SIZE);

                int16_t dst_tsap() const {
                    return dst_;
                }

                void dst_tsap(int16_t val) {
                    dst_ = val;
                }

                int16_t src_tsap() const {
                    return src_;
                }

                void src_tsap(int16_t val) {
                    src_ = val;
                }

                tpdu_size pdusize() const;

                const octet_sequnce & calling() const;

                void calling(const octet_sequnce & val);

                const octet_sequnce & called() const;

                void called(const octet_sequnce & val);

                std::size_t maxpdusize() const;

                void maxpdusize(std::size_t val);

            private:
                int16_t dst_;
                int16_t src_;
                headarvarvalues vars_;
                octet_sequnce null_;
            };

            const protocol_options NULL_PROTOCOL_OPTION = protocol_options();

        }
    }
}


#endif  /* _BOOST_ITU_X224_IMPLEMENTATIUON_H_ */