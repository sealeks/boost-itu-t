//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <iosfwd>
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>


#include <boost/itu/coder/asn1_stream.hpp>



namespace boost {
    namespace asn1 {

        static asn_coder_ptr build_coder(encoding_rule rl) {

            switch (rl) {
                case BER_ENCODING:
                case DER_ENCODING:
                case CER_ENCODING: return asn_coder_ptr(new X690_coder_type(NULL_OID, rl));
                case PER_ALIGNED_ENCODING:
                case PER_UNALIGNED_ENCODING:
                case CPER_ALIGNED_ENCODING:
                case CPER_UNALIGNED_ENCODING: return asn_coder_ptr(new X691_coder_type(NULL_OID, rl));
                default:
                {
                }
            }
            return asn_coder_ptr();
        }



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        /*BASIC STREAM                                                                                                                                                      */
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////                   

        asn1_stream::asn1_stream(encoding_rule rl)
        : coder(build_coder(rl)) {
        }

        asn1_stream::coder_type asn1_stream::type() {
            if (coder && coder->rule()) {
                if ((coder->rule() >= BER_ENCODING) &&
                        (coder->rule() <= CER_ENCODING))
                    return x_690;
                else if ((coder->rule() >= PER_ALIGNED_ENCODING) &&
                        (coder->rule() <= CPER_UNALIGNED_ENCODING))
                    return x_691;
            }
            return x_none;
        }

        X690_coder_ptr asn1_stream::x690coder() {
            return (type() == x_690) ? boost::static_pointer_cast<X690_coder_type> (coder) : X690_coder_ptr();
        }

        X691_coder_ptr asn1_stream::x691coder() {
            return (type() == x_691) ? boost::static_pointer_cast<X691_coder_type> (coder) : X691_coder_ptr();
        }

        bool asn1_stream::input_empty() {
            return  !((coder && coder->in()) ? coder->in()->size() : false);
        }

        bool asn1_stream::output_empty() {
            return  !((coder && coder->out()) ? coder->out()->size() : false);
        }        
        
        bool asn1_stream::clear() {
            if (coder)
                coder->clear();
            return true;
        }

        bool asn1_stream::clear_input() {
            bool rslt = (coder && coder->in()) ? coder->in()->size() : false;
            if (coder)
                coder->clear_input();
            return rslt;
        }

        bool asn1_stream::clear_output() {
            bool rslt = (coder && coder->out()) ? coder->out()->size() : false;
            if (coder)
                coder->clear_output();
            return rslt;
        }

        bool asn1_stream::fill_in_from_out() {
            if (coder && coder->out() && coder->out()->size()) {
                octet_sequnce oseq;
                coder->out()->bind(oseq);
                coder->in()->add(oseq);
                return true;
            }
            return false;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        /*COUT STREAM                                                                                                                                                          */
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////             

        void std_stream::print_out() {
            
            const boost::itu::const_sequences& seq = coder->out()->buffers();
            std::string strout;
            for (boost::itu::const_sequences::const_iterator it = seq.begin(); it != seq.end(); ++it)
                strout += std::string(boost::asio::buffer_cast<const char*>(*it), boost::asio::buffer_size(*it));
            std::cout << "out operation result: "  << boost::itu::binary_to_hexsequence_debug(strout, 4);
            
            if ((coder->out()->unusebits()) && (!seq.empty())) {
                std::string tmp1(boost::asio::buffer_cast<const char*>(seq.back()), boost::asio::buffer_size(seq.back()));
                if (!tmp1.empty()) {
                    std::string tmp(tmp1.rbegin(), tmp1.rbegin() + 1);
                    std::cout   << " {" << boost::asn1::bit_string(tmp, coder->out()->unusebits()) <<
                            " unus =" << coder->out()->unusebits() << "}";
                }
            };            
            std::cout  << std::endl;
        }

        void std_stream::start_in() {
            if (input_empty()) {
                std::cout << "input buffer is empty ";
                if (output_empty())
                    std::cout << "and output buffer is empty. ";
                else {
                    fill_in_from_out();
                    std::cout << ", copy from output.  ";
                }
            }
            if (!input_empty()) {
                std::cout << " before opreration input size :  " << coder->in()->size();
                if (coder->in()->unusebits())
                    std::cout << " { unuse :  " << coder->in()->unusebits() << " }";
                std::cout << std::endl;
            }
        }

        void std_stream::print_in() {
            std::cout << " aftrer opreration input size :  " << coder->in()->size();
            if (coder->in()->unusebits())
                std::cout << " { unuse :  " << coder->in()->unusebits() << " }";
            std::cout << std::endl;            
        }

    }
}
