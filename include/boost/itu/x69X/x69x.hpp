//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef ITU_X69XBOOST__H
#define	ITU_X69XBOOST__H

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)



#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/x22X/selectors.hpp>
#include <boost/itu/detail/error.hpp>



namespace boost {
    namespace asn1 {


            const octet_type NEGATIVE_MARKER = '\x80';
            const octet_type POSITIVE_START = '\xFF';

            const octet_type CONTENT_CONIIUE = '\x80';
            const octet_type UNDEF_BLOCK_SIZE = '\x80';

            const octet_type NAN_REAL_ID = '\x42';
            const octet_type INFINITY_REAL_ID = '\x40';
            const octet_type NEGATINFINITY_REAL_ID = '\x41';
            const octet_type NEGATNULL_REAL_ID = '\x43';

            const std::size_t MAX_SIMPLELENGTH_SIZE = 0x80;

            const std::size_t FLOAT_MANTISSA_SIZE = 23;
            const std::size_t FLOAT_EXPONENTA_DELT = 127;

            const std::size_t DOUBLE_MANTISSA_SIZE = 52;
            const std::size_t DOUBLE_EXPONENTA_DELT = 1023;

            const std::size_t LONGDOUBLE_MANTISSA_SIZE = 112;
            const std::size_t LONGDOUBLE_EXPONENTA_DELT = 16383;



            //////  Endian conv;

            void endian_conv(octet_sequnce& val);

            octet_sequnce endian_conv_conv(const octet_sequnce& val);

            void endian_push_pack(const octet_sequnce& val, octet_sequnce& dst);


            /////// timeconv

/*

            //  size_class

            class size_class {

            public:

                size_class() : size_(0), undefsize_(true) {
                }

                size_class(size_type vl) : size_(vl), undefsize_(false) {
                }

                bool undefsize() const {
                    return undefsize_;
                }

                size_type size() const {
                    return size_;
                }


            private:
                size_type size_;
                bool undefsize_;

            };

            inline std::ostream& operator<<(std::ostream& stream, const size_class& vl) {
                return vl.undefsize() ? (stream << "SIZE:  undef" << '\n') : (stream << "SIZE:  " << vl.size() << '\n');
            }


            ///////////////////





            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            // OUTPUT STREAM                                                                                                                                                                                        
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////




            /////  CAST FROM AND TO TYPE

            ///////////////////////////////////////////////////////////////////////////////////////////////
            // integer to X.690

            template<typename T>
            std::size_t to_x690_cast(T val, octet_sequnce& src) {
                octet_sequnce tmp;
                bool negat = (val < 0);



#ifdef BIG_ENDIAN_ARCHITECTURE      
                !!!not implement
#else

                if (negat)
                    if (val & (T(1) << (sizeof (T)*8 - 1))) {
                        val &= ~(T(1) << (sizeof (T)*8 - 1));
                        tmp.push_back(static_cast<octet_type> (POSITIVE_START & val));
                        val >>= 8;
                        val |= (T(1) << ((sizeof (T) - 1)*8 - 1));
                    }
                while (val) {
                    tmp.push_back(static_cast<octet_type> (POSITIVE_START & val));
                    val >>= 8;
                }
                if (negat && !tmp.empty())
                    while ((tmp.size() > 1) && (tmp.back() == static_cast<octet_type> (POSITIVE_START)))
                        tmp.pop_back();

                if ((tmp.empty() || (!negat && (tmp.back() & NEGATIVE_MARKER))))
                    tmp.push_back(static_cast<octet_type> (0));
                else {
                    if (negat && !(tmp.back() & NEGATIVE_MARKER))
                        tmp.push_back(static_cast<octet_type> (POSITIVE_START));
                }
                endian_push_pack(tmp, src);

#endif                              
                return tmp.size();
            }

            template<>
            std::size_t to_x690_cast(int8_t val, octet_sequnce& src);

            template<>
            std::size_t to_x690_cast(uint8_t val, octet_sequnce& src);





            ///////////////////////////////////////////////////////////////////////////////////
            // tag to X.690


            std::size_t to_x690_cast(const tag& val, octet_sequnce& src);

            octet_sequnce to_x690_cast(const tag& val);


            ///////////////////////////////////////////////////////////////////////////////////
            // size_class to X.690


            std::size_t to_x690_cast(const size_class& val, octet_sequnce& src);

            octet_sequnce to_x690_cast(const size_class& val);


            ///////////////////////////////////////////////////////////////////////////////////
            // real to X.690


            template<>
            std::size_t to_x690_cast(double val, octet_sequnce& src);

            template<>
            std::size_t to_x690_cast(float val, octet_sequnce& src);

            template<>
            std::size_t to_x690_cast(long double val, octet_sequnce& src);



            ///////////////////////////////////////////////////////////////////////////////////
            // bool to X.690

            template<>
            std::size_t to_x690_cast(bool val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // null to X.690

            std::size_t to_x690_cast(const null_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // enumerated_type to X.690

            std::size_t to_x690_cast(const enumerated_type& val, octet_sequnce& src);


            ///////////////////////////////////////////////////////////////////////////////////
            // oid to X.690


            std::size_t to_x690_cast(const oid_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // relative oid to X.690


            std::size_t to_x690_cast(const reloid_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // utctime to X.690


            std::size_t to_x690_cast(const utctime_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // gentime to X.690


            std::size_t to_x690_cast(const gentime_type& val, octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // any_type to X.690


            std::size_t to_x690_cast(const any_type& val, octet_sequnce& src);

            template<typename T>
            octet_sequnce to_x690_cast(const T& val) {
                octet_sequnce rslt;
                to_x690_cast(val, rslt);
                return rslt;
            }



   


            /////  CAST FROM AND TO TYPE

            ///////////////////////////////////////////////////////////////////////////////////////////////
            // integer from X.690          

            template<typename T>
            bool from_x690_cast(T& vl, const octet_sequnce& dt) {
                octet_sequnce val = dt;
#ifdef BIG_ENDIAN_ARCHITECTURE 
                !!!not implement
#else              
                endian_conv(val);
                if (sizeof (T) > val.size())
                    val.resize(sizeof (T), octet_type((val.empty() || (val.back() & NEGATIVE_MARKER)) ? POSITIVE_START : 0));
                vl = (*(T*) (&val[0]));
#endif                  
                return true;
            }




            ///////////////////////////////////////////////////////////////////////////////////
            // tag from X.690

            std::size_t tag_from_x690_cast(const tag& val, const octet_sequnce& src);

            std::size_t tag_x690_cast(tag& val, const mutable_sequences& src, mutable_sequences::const_iterator bit, std::size_t beg = 0);

            ///////////////////////////////////////////////////////////////////////////////////
            // size_class from X.690

            std::size_t size_x690_cast(size_class& val, const mutable_sequences& src, mutable_sequences::const_iterator bit, std::size_t beg = 0);

            ///////////////////////////////////////////////////////////////////////////////////
            // real from X.690

            template<>
            bool from_x690_cast(float& vl, const octet_sequnce& val);

            template<>
            bool from_x690_cast(double& vl, const octet_sequnce& val);

            template<>
            bool from_x690_cast(long double& vl, const octet_sequnce& val);


            ///////////////////////////////////////////////////////////////////////////////////
            // bool from X.690

            template<>
            bool from_x690_cast(bool& vl, const octet_sequnce& val);


            ///////////////////////////////////////////////////////////////////////////////////
            // null from X.690

            template<>
            bool from_x690_cast(null_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // enumerated_type from X.690

            template<>
            bool from_x690_cast(enumerated_type& val, const octet_sequnce& src);


            ///////////////////////////////////////////////////////////////////////////////////
            // oid from X.690

            template<>
            bool from_x690_cast(oid_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // relative from to X.690

            template<>
            bool from_x690_cast(reloid_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // utctime_type from to X.690

            template<>
            bool from_x690_cast(utctime_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // gentime_type from to X.690

            template<>
            bool from_x690_cast(gentime_type& val, const octet_sequnce& src);

            ///////////////////////////////////////////////////////////////////////////////////
            // any_type from to X.690

            template<>
            bool from_x690_cast(any_type& val, const octet_sequnce& src);

    
*/



    }
}


#endif	

