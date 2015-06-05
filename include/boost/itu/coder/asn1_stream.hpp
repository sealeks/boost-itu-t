//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1STREAM_IMPLEMENTATIUON_H_
#define         _ITU_ASN1STREAM_IMPLEMENTATIUON_H_


#ifdef _MSC_VER
#if _MSC_VER >= 1800
#ifndef UNICODE
#define UNICODE
#endif
#endif
#endif

#include <boost/itu/coder/base_coder.hpp>

#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>
#include <fstream>

namespace boost {
    namespace asn1 {

        using boost::itu::encoding_rule;
        using boost::itu::asn_coder_type;

        using boost::itu::BER_ENCODING;
        using boost::itu::CER_ENCODING;
        using boost::itu::DER_ENCODING;
        using boost::itu::PER_ALIGNED_ENCODING;
        using boost::itu::PER_UNALIGNED_ENCODING;
        using boost::itu::CPER_ALIGNED_ENCODING;
        using boost::itu::CPER_UNALIGNED_ENCODING;

        typedef boost::asn1::x690::input_coder X690_input_coder_type;
        typedef boost::asn1::x690::output_coder X690_output_coder_type;
        typedef boost::itu::asn_coder_templ<X690_input_coder_type, X690_output_coder_type> X690_coder_type;
        typedef shared_ptr<X690_coder_type> X690_coder_ptr;

        typedef boost::asn1::x691::input_coder X691_input_coder_type;
        typedef boost::asn1::x691::output_coder X691_output_coder_type;
        typedef boost::itu::asn_coder_templ<X691_input_coder_type, X691_output_coder_type> X691_coder_type;
        typedef shared_ptr<X691_coder_type> X691_coder_ptr;


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        /*BASIC STREAM                                                                                                                                                      */
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////            

        class asn1_stream {

        public:

            enum coder_type {

                x_none,
                x_690,
                x_691
            };

            typedef asn1_stream self_type;
            typedef asn_coder_type::output_coder_ptr output_coder_ptr;
            typedef asn_coder_type::input_coder_ptr input_coder_ptr;

            asn1_stream(encoding_rule rl, std::size_t frmt =0);

            virtual ~asn1_stream() {
            }

            coder_type type();
            

            bool input_empty();
            bool output_empty(); 
            bool clear();
            bool clear_input();
            bool clear_output();

        protected:

            X690_coder_ptr x690coder();
            X691_coder_ptr x691coder();
            
            bool fill_in_from_out();

            virtual void print_out();
            virtual void start_in();
            virtual void print_in();
            
            asn_coder_ptr coder;            
            std::size_t frmt_;            
        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        /*COUT STREAM                                                                                                                                                           */
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////             

        class ioasn1_stream : public asn1_stream {

        public:

            ioasn1_stream(encoding_rule rl, std::size_t frmt =0) :
            asn1_stream(rl, frmt) {
            }

            template<typename T>
            friend ioasn1_stream& operator<<(ioasn1_stream& strm, const T& vl) {
                strm.clear_output();
                switch (strm.type()) {
                    case x_690: strm.x690coder()->output() & vl;
                        break;
                    case x_691: strm.x691coder()->output() & vl;
                        break;
                    default:
                    {
                    }
                }
                strm.print_out();
                return strm;
            }

            template<typename T>
            friend ioasn1_stream& operator>>(ioasn1_stream& strm, T& vl) {
                strm.start_in();
                switch (strm.type()) {
                    case x_690: strm.x690coder()->input() & vl;
                        break;
                    case x_691: strm.x691coder()->input() & vl;
                        break;
                    default:
                    {
                    }
                }
                strm.print_in();
                return strm;
            }

        };
        
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        /*FILE STREAM                                                                                                                                                           */
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////          

        class fasn1_stream : public asn1_stream {

        public:

           fasn1_stream(encoding_rule rl, const std::string& file, 
                    std::ios_base::openmode flg = std::ios_base::out) :
            asn1_stream(rl), fstrm(file.c_str(), flg | std::ios_base::binary) {
            }

            template<typename T>
            friend fasn1_stream& operator<<(fasn1_stream& strm, const T& vl) {
                strm.clear_output();
                switch (strm.type()) {
                    case x_690: strm.x690coder()->output() & vl;
                        break;
                    case x_691: strm.x691coder()->output() & vl;
                        break;
                    default:
                    {
                    }
                }
                strm.print_out();
                return strm;
            }

            template<typename T>
            friend fasn1_stream& operator>>(fasn1_stream& strm, T& vl) {
                strm.start_in();
                switch (strm.type()) {
                    case x_690: strm.x690coder()->input() & vl;
                        break;
                    case x_691: strm.x691coder()->input() & vl;
                        break;
                    default:
                    {
                    }
                }
                strm.print_in();
                return strm;
            }
            
            virtual void print_out();
            virtual void start_in();
            virtual void print_in();         
            
        private:
            
            std::fstream fstrm;

        };


    }
} // namespace boost



#endif // _ITU_ASN1STREAM_IMPLEMENTATIUON_H_

