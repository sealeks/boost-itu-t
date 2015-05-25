//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef ITU_X691BOOST__H
#define	ITU_X691BOOST__H

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)



#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/x22X/selectors.hpp>
#include <boost/itu/detail/error.hpp>
#include <boost/itu/x69X/x69x.hpp>



#define ITU_T_SET_CONSTAINED_INDX(indx, max) arch.add_constrained<std::size_t >(indx, 0, max);
#define ITU_T_GET_CONSTAINED_INDX( max) std::size_t __indx__ = arch.get_constrained<std::size_t >(0, max);

#define ITU_T_SET_NSN_SMALL_INDX(indx) arch.add_nsn_small(indx);
#define ITU_T_GET_NSN_SMALL_INDX std::size_t __indx__ = arch.get_nsn_small();


#define ITU_T_PER_START_OPEN  arch.start_open();
#define ITU_T_PER_END_OPEN  arch.end_open();
#define ITU_T_PER_CLEAR_EXTENTIONS( num )  arch.clear_extentions(__ext_optional_groups_bmp__, num);
#define ITU_T_PER_CLEAR_EXTENTION  arch.clear_extention();

//   main bind and bind per enum
#define ITU_T_BIND_PER(var) boost::asn1::bind_per(arch, var)
#define ITU_T_BIND_PER_ENUM(var, nm) boost::asn1::bind_per_enum< nm ## __coder >(arch, var);

// Integer constrant term ..S( not extended ) or ..E ( extended )  main, simiconstrained, single value
#define ITU_T_BIND_NUM_CONSTRS(var, mn, mx) boost::asn1::bind_constraints(arch, var, mn, mx, false);
#define ITU_T_BIND_NUM_CONSTRE(var, mn, mx) boost::asn1::bind_constraints(arch, var, mn, mx, true);
#define ITU_T_BIND_NUM_SIMICONS(var, mn) boost::asn1::bind_constraints(arch, var, mn, 0, false);
#define ITU_T_BIND_NUM_SIMICONE(var, mn) boost::asn1::bind_constraints(arch, var, mn, 0, true);
#define ITU_T_BIND_NUM_SNGLCONS(var, mn) boost::asn1::bind_constraints(arch, var, mn, mn, false);
#define ITU_T_BIND_NUM_SNGLCONE(var, mn) boost::asn1::bind_constraints(arch, var, mn, mn, true);

// Integer constrant helper for comlex case .   term ..S( not extended ) or ..E ( extended )
#define ITU_T_REGISTRATE_NUM_CONSTRS(var, tp, mn, mx) typedef boost::asn1::___integer_tmpl_ec___<tp , mn , mx , false>  var;
#define ITU_T_REGISTRATE_NUM_CONSTRE(var, tp, mn, mx) typedef boost::asn1::___integer_tmpl_ec___<tp , mn , mx , true>  var;
#define ITU_T_REGISTRATE_NUM_SIMICONS(var, tp, mn) typedef boost::asn1::___integer_tmpl_ec___<tp , mn , 0 , false>  var;
#define ITU_T_REGISTRATE_NUM_SIMICONE(var, tp, mn) typedef boost::asn1::___integer_tmpl_ec___<tp , mn , 0 , true>  var;
#define ITU_T_REGISTRATE_NUM_SNGLCONS(var, tp, mn) typedef boost::asn1::___integer_tmpl_ec___<tp , mn , mn , false>  var;
#define ITU_T_REGISTRATE_NUM_SNGLCONE(var, tp, mn) typedef boost::asn1::___integer_tmpl_ec___<tp , mn , mn , true>  var;

// Size constrant term ..S( not extended ) or ..E ( extended ) main, simiconstrained, single value
#define ITU_T_BIND_SIZE_CONSTRS(var, mn, mx) boost::asn1::bind_sizeconstraints(arch, var, mn, mx, false);
#define ITU_T_BIND_SIZE_CONSTRE(var, mn, mx) boost::asn1::bind_sizeconstraints(arch, var, mn, mx, true);
#define ITU_T_BIND_SIZE_SEMICONSTRS(var, mn) boost::asn1::bind_sizeconstraints(arch, var, mn, 0, false);
#define ITU_T_BIND_SIZE_SEMICONSTRE(var, mn) boost::asn1::bind_sizeconstraints(arch, var, mn, 0, true);
#define ITU_T_BIND_SIZE_SNGLCONSTRS(var, mn) boost::asn1::bind_sizeconstraints(arch, var, mn, mn, false);
#define ITU_T_BIND_SIZE_SNGLCONSTRE(var, mn) boost::asn1::bind_sizeconstraints(arch, var, mn, mn, true);

// Size constrant complex, term ..S( not extended ) or ..E ( extended ) nosize onle elements, main, simiconstrained, single value
#define ITU_T_BIND_EX_CONSTRS(tp, el, var) boost::asn1::bind_sizeconstraints_ext< tp, el > (arch, var, 0, 0, false);
#define ITU_T_BIND_EXSIZE_CONSTRS(tp, el, var, mn, mx) boost::asn1::bind_sizeconstraints_ext< tp, el > (arch, var, mn, mx, false);
#define ITU_T_BIND_EXSIZE_CONSTRE(tp, el, var, mn, mx) boost::asn1::bind_sizeconstraints_ext< tp, el >(arch, var, mn, mx, true);
#define ITU_T_BIND_EXSIZE_SEMICONSTRS(tp, el, var, mn) boost::asn1::bind_sizeconstraints_ext< tp, el >(arch, var, mn, 0, false);
#define ITU_T_BIND_EXSIZE_SEMICONSTRE(tp, el, var, mn) boost::asn1::bind_sizeconstraints_ext< tp, el >(arch, var, mn, 0, true);
#define ITU_T_BIND_EXSIZE_SNGLCONSTRS(tp, el, var, mn) boost::asn1::bind_sizeconstraints_ext< tp, el >(arch, var, mn, mn, false);
#define ITU_T_BIND_EXSIZE_SNGLCONSTRE(tp, el, var, mn) boost::asn1::bind_sizeconstraints_ext< tp, el >(arch, var, mn, mn, true);

//  enumerated complex case
#define ITU_T_REGISTRATE_ENUM_CONSTRS(var, tp) typedef boost::asn1::___enumerated_tmpl_ec___<tp>  var;

#define  ITU_T_PER_ENUMCODER(nm  , extbool , arrmain ) struct nm ## __coder { \
    static boost::asn1::indx_enumerated_map index_enumerated;\
    static boost::asn1::enumerated_indx_map enumerated_index;\
    static bool is_root(const boost::asn1::enumerated_type& vl) {\
        return true;}\
     static  bool ext() {\
        return extbool;}\
     static enumerated_type to_root(std::size_t vl) {\
         boost::asn1::indx_enumerated_map::const_iterator fit=index_enumerated.find(vl);\
        return fit != index_enumerated.end() ? fit->second : enumerated_type(0);}\
     static enumerated_type to_ext(std::size_t vl) {\
        return enumerated_type(0);}\
     static std::size_t from_root(const enumerated_type& vl) {\
         boost::asn1::enumerated_indx_map::const_iterator fit = enumerated_index.find(vl);\
        return fit != enumerated_index.end() ? fit->second : 0;}\
     static std::size_t from_ext(const enumerated_type& vl) {\
        return 0;}\
     static bool check_enum(enumerated_type vl) {\
        return (enumerated_index.find(vl)!= enumerated_index.end());}\
     static bool check_data(std::size_t vl, bool ext=false) {\
        return index_enumerated.find(vl)!= index_enumerated.end();}\
     static std::size_t rootsize() {\
        return index_enumerated.size();}};\
     const boost::asn1::enum_base_type nm##  __ARR[] = {arrmain};\
      boost::asn1::indx_enumerated_map nm## __coder::index_enumerated = boost::asn1::create_indx_enumerated(nm##  __ARR, sizeof(nm##  __ARR)/ sizeof(boost::asn1::enum_base_type));\
      boost::asn1::enumerated_indx_map nm## __coder::enumerated_index = boost::asn1::create_enumerated_indx(nm##  __ARR, sizeof(nm##  __ARR)/ sizeof(boost::asn1::enum_base_type));


#define  ITU_T_PER_ENUMCODER_EXT(nm  , arrmain, arrext ) struct nm ## __coder { \
    static boost::asn1::indx_enumerated_map index_enumerated;\
    static boost::asn1::indx_enumerated_map index_enumerated_ext;\
    static boost::asn1::enumerated_indx_map enumerated_index;\
    static boost::asn1::enumerated_indx_map enumerated_index_ext;\
    static bool is_root(const boost::asn1::enumerated_type& vl) {\
        return enumerated_index.find(vl) != enumerated_index.end();}\
     static  bool ext() {\
        return !index_enumerated_ext.empty();}\
     static enumerated_type to_root(std::size_t vl) {\
         boost::asn1::indx_enumerated_map::const_iterator fit=index_enumerated.find(vl);\
        return fit != index_enumerated.end() ? fit->second : enumerated_type(0);}\
     static enumerated_type to_ext(std::size_t vl) {\
         boost::asn1::indx_enumerated_map::const_iterator fit = index_enumerated_ext.find(vl);\
        return fit != index_enumerated_ext.end() ? fit->second : enumerated_type(0);}\
     static std::size_t from_root(const enumerated_type& vl) {\
         boost::asn1::enumerated_indx_map::const_iterator fit = enumerated_index.find(vl);\
        return fit != enumerated_index.end() ? fit->second : 0;}\
     static std::size_t from_ext(const enumerated_type& vl) {\
         boost::asn1::enumerated_indx_map::const_iterator fit = enumerated_index_ext.find(vl);\
        return fit != enumerated_index_ext.end() ? fit->second : 0;}\
     static bool check_enum(enumerated_type vl) {\
        return ((enumerated_index.find(vl)!= enumerated_index.end()) || (enumerated_index_ext.find(vl)!= enumerated_index_ext.end()));}\
     static bool check_data(std::size_t vl, bool ext=false) {\
        return ext ? (index_enumerated_ext.find(vl)!= index_enumerated_ext.end()) :  (index_enumerated.find(vl)!= index_enumerated.end());}\
     static std::size_t rootsize() {\
        return index_enumerated.size();}};\
     const boost::asn1::enum_base_type nm##  __ARR[] = {arrmain};\
     const boost::asn1::enum_base_type nm##  __EARR[] = {arrext};\
      boost::asn1::indx_enumerated_map nm## __coder::index_enumerated = boost::asn1::create_indx_enumerated(nm##  __ARR, sizeof(nm##  __ARR)/ sizeof(boost::asn1::enum_base_type));\
      boost::asn1::indx_enumerated_map  nm ## __coder::index_enumerated_ext = boost::asn1::create_indx_enumerated(nm##  __EARR, sizeof(nm##  __EARR)/ sizeof(boost::asn1::enum_base_type));\
      boost::asn1::enumerated_indx_map nm## __coder::enumerated_index = boost::asn1::create_enumerated_indx(nm##  __ARR, sizeof(nm##  __ARR)/ sizeof(boost::asn1::enum_base_type));\
      boost::asn1::enumerated_indx_map  nm ## __coder::enumerated_index_ext = boost::asn1::create_enumerated_indx(nm##  __EARR, sizeof(nm##  __EARR)/ sizeof(boost::asn1::enum_base_type));



/* Need helper case :
 *    1) Siimple case:
 *              a)   enumerated_type   
 *                       helper : no extention ITU_T_PER_ENUMCODER( helper_name, ITU_T_ARRAY( n1, n2....  nn))   or 
 *                                     extention  ITU_T_PER_ENUMCODER_EXT( helper_name, ITU_T_ARRAY( n1, n2....  nn), ITU_T_ARRAY( m1, m2....  mn))
 *                       and use   ITU_T_BIND_PER_ENUM( member, helper_name);
 * 
 *              b)   effective alphabet constraint
 * 
 *                         helper : struct printablestring_ec {
 *                                             static void out(boost::asn1::x691::output_coder& stream, ****string_type::value_type vl);   // char to stream
 *                                             static ***string_type::value_type in(boost::asn1::x691::input_coder& stream); // char from stream
 *                                             static std::size_t bits_count(bool aligned);  //  chars size in bits
 *                         };
 *                       and use   ITU_T_BIND_EX_CONSTRS( type, helper_name, member);   NB: The type is member type               
 * 
 *      2) Comlex case: (size constraint + )
 *              a)  enumerated_type  ( same helper 1.a + )
 *                       ITU_T_REGISTRATE_ENUM_CONSTRS(helper_name_cplx , helper_name)
 *                       and use ITU_T_BIND_EXSIZE_*****(type, helper_name_cplx,  .....) NB: The type is member type 
 *              b) effective alphabet constraint ( same  helper 1.b) and 
 *                       and use ITU_T_BIND_EXSIZE_*****(type, helper_name,  .....) NB: The type is member type
 *              c) integer constraint  
 *                       helper : ITU_T_REGISTRATE_NUM_******(helper_name,  type, min, ? max)  type is using ineger type  (see above)
 *                       and use ITU_T_BIND_EXSIZE_*****(type, helper_name,  .....) NB: The type is member type
 * 

    };
 * 
         
         
 */



namespace boost {
    namespace asn1 {


        //////////////////////////////////////////////
        //per_enumerated_holder
        //////////////////////////////////////////////

        template<typename T>
        struct per_enumerated_holder {

            typedef T coder_type;

            per_enumerated_holder(const enumerated_type& vl) :
            value_(const_cast<enumerated_type&> (vl)) {
            }

            per_enumerated_holder(enumerated_type& vl) :
            value_(vl) {
            }

            const T& value() const {
                return value_;
            }

            T& value() {
                return value_;
            }

            bool can_extended() const {
                return coder_type::ext();
            }

            bool is_root() const {
                return coder_type::is_root(value_);
            }

            std::size_t max() const {
                std::size_t maxnum = coder_type::rootsize();
                return maxnum ? (maxnum - 1) : 0;
            }

            std::size_t to() const {
                return coder_type::is_root(value_) ? coder_type::from_root(value_) :
                        coder_type::from_ext(value_);
            }

            void from(std::size_t vl, bool ext = false) {
                if (ext)
                    value_ = coder_type::to_ext(vl);
                else
                    value_ = coder_type::to_root(vl);
            }

            bool check_enum() const {
                return coder_type::check_enum(value_);
            }

            bool check_data(std::size_t vl, bool ext = false) {
                return coder_type::check_data(vl, ext);
            }

        private:

            enumerated_type& value_;
        };








        namespace x691 {


            const std::size_t MAX_OCTETLENGTH_SIZE = 0x100;
            const std::size_t MAX_SMALL_NN_SIZE = 64;
            const std::size_t MIN_NOT_ALIGN_BITSIZE = 16;
            const std::size_t MIN_NOT_ALIGN_OCTSIZE = 2;

            const octet_sequnce S0_OCTET = octet_sequnce(1, '\x0');
            const bitstring_type NULL_BITMAP = bitstring_type();


            /////// timeconv



            //  size_class

            class size_class {

            public:

                size_class() : size_(0) {
                }

                size_class(size_type vl) : size_(vl) {
                }

                size_type size() const {
                    return size_;
                }

            private:
                size_type size_;
            };

            std::ostream& operator<<(std::ostream& stream, const size_class& vl);


            ///////////////////////////////////////////////////////////////////////////////////
            // size_class to X.691


            std::size_t to_x691_cast(const size_class& val, octet_sequnce& src);

            octet_sequnce to_x691_cast(const size_class& val);

            template<typename T>
            std::size_t calculate_bitsize(T vl) {
                if (vl) {
                    std::size_t rslt = 1;
                    while (vl >>= 1)
                        rslt++;
                    return rslt;
                }
                return 0;
            }

            template<typename T>
            T calculate_octetsize(T sz) {
                return sz ? ((sz - 1) / 8 + 1) : 0;
            }


            //  constrained whole number            

            template<typename T>
            class constrained_wnumber {

            public:

                typedef T internal_type;

                constrained_wnumber(T& vl, const T& min, const T& max) : value_(vl), MIN(min), MAX(max) {
                    if ((vl < MIN) || (vl > MAX))
                        vl = (vl < MIN) ? MIN : MAX;
                }

                const T& min() const {
                    return MIN;
                }

                const T& max() const {
                    return MAX;
                }

                boost::uint64_t range() const {
                    return MAX - MIN;
                }

                bool is_single() const {
                    return MAX = MIN;
                }

                // bitmap for alighned vaiant

                bool is_minimal() const {
                    return (range() < MAX_OCTETLENGTH_SIZE);
                }

                const internal_type& value() const {
                    return value_;
                }

                void value(const octet_sequnce& vl) {
                    boost::uint64_t tmp;
                    from_x690_cast(tmp, vl);
                    tmp += MIN;
                    value_ = tmp > MAX ? MAX : static_cast<T> (tmp);
                }

                void value(const bitstring_type& vl) {
                    if (vl.unusebits() % 8) {
                        bitstring_type tmp = bitstring_type(S0_OCTET, 8 - vl.unusebits() % 8) + vl;
                        value(tmp.as_octet_sequnce());
                    } else
                        value(vl.as_octet_sequnce());
                }

                boost::uint64_t sendval() const {
                    return value_ - MIN;
                }

                std::size_t bitsize() const {
                    return calculate_bitsize(range());
                }

                std::size_t octetsize() const {
                    return calculate_octetsize(bitsize());
                }

                bitstring_type as_bitmap() const {
                    if (std::size_t bssz = bitsize()) {
                        boost::uint64_t val = sendval();
                        std::size_t octsz = (bssz - 1) / 8 + 1;
                        octet_sequnce tmp = endian_conv_conv(octet_sequnce(static_cast<octet_sequnce::value_type*> ((void*) &val),
                                static_cast<octet_sequnce::value_type*> ((void*) &val) + octsz));
#ifdef BIG_ENDIAN_ARCHITECTURE  
                        ?
#else                    
                        if (bssz % 8)
                            tmp.back() <<= (8 - bssz % 8);
#endif                    
                        return bitstring_type(tmp, (bssz % 8) ? (8 - bssz % 8) : 0);
                    }
                    return NULL_BITMAP;
                }

                octet_sequnce as_octets() const {
                    boost::uint64_t val = sendval();
                    if (std::size_t octsz = octetsize())
                        return endian_conv_conv(octet_sequnce(static_cast<octet_sequnce::value_type*> ((void*) &val),
                            static_cast<octet_sequnce::value_type*> ((void*) &val) + octsz));
                    return octet_sequnce();
                }


            private:

                internal_type& value_;
                const internal_type& MIN;
                const internal_type& MAX;
            };


            //  semiconstrained whole number            

            template<typename T>
            class semiconstrained_wnumber {

            public:

                typedef T internal_type;

                semiconstrained_wnumber(T& vl, const T& min) : value_(vl), MIN(min) {
                    if (vl < MIN)
                        vl = MIN;
                }

                const T& min() const {
                    return MIN;
                }

                const internal_type& value() const {
                    return value_;
                }

                void value(const octet_sequnce& vl) {
                    boost::uint64_t tmp = 0;
                    from_x690_cast(tmp, vl);
                    value(tmp);
                }

                void value(boost::uint64_t vl) {
                    value_ = static_cast<T> (vl + MIN);
                }

                boost::uint64_t sendval() const {
                    return value_ - MIN;
                }

                std::size_t bitsize() const {
                    return calculate_bitsize(sendval());
                }

                std::size_t octetsize() const {
                    if (std::size_t rslt = calculate_octetsize(bitsize()))
                        return rslt;
                    return 1;
                }

                octet_sequnce as_octets() const {
                    octet_sequnce vl;
                    to_x690_cast<boost::uint64_t>(sendval(), vl);
                    return vl.empty() ? S0_OCTET : vl;
                }


            private:

                internal_type& value_;
                const internal_type& MIN;
            };





            //  unconstrained whole number            

            template<typename T>
            class unconstrained_wnumber {

            public:

                typedef T internal_type;

                unconstrained_wnumber(T& vl) : value_(vl) {
                }

                const internal_type& value() const {
                    return value_;
                }

                bool value(const octet_sequnce& dt) {
                    return from_x690_cast(value_, dt);
                }

                octet_sequnce as_octets() const {
                    octet_sequnce vl;
                    to_x690_cast<internal_type>(value_, vl);
                    return vl.empty() ? S0_OCTET : vl;
                }


            private:

                internal_type& value_;
            };





            //  small_nn_wnumber  non-negative whole number

            template<typename T>
            class small_nn_wnumber {

            public:

                typedef T internal_type;
                BOOST_STATIC_ASSERT(!std::numeric_limits<internal_type>::is_signed);

                small_nn_wnumber(T& vl) : value_(vl) {
                }

                const internal_type& value() const {
                    return value_;
                }

                void value(boost::uint64_t vl) {
                    value_ = static_cast<T> (vl);
                }

                void value(const octet_sequnce& vl) {
                    boost::uint64_t tmp;
                    from_x690_cast(tmp, vl);
                    value_ = static_cast<T> (tmp);
                }

                std::size_t bitsize() const {
                    return calculate_bitsize(value_);
                }

                std::size_t octetsize() const {
                    if (std::size_t rslt = calculate_octetsize(bitsize()))
                        return rslt;
                    return 1;
                }

                bool is_minimal() const {
                    return value_<MAX_SMALL_NN_SIZE;
                }

            private:
                internal_type& value_;
            };




            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*OUTPUT STREAM                                                                                                                                                                                           */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


            // element constrainter

            class output_coder;
            class input_coder;

            struct numericstring_ec {

                static void out(boost::asn1::x691::output_coder& stream, numericstring_type::value_type vl);

                static numericstring_type::value_type in(boost::asn1::x691::input_coder& stream);

                static std::size_t bits_count(bool aligned) {
                    return /*aligned ? 4 :*/ 4;
                }

            };

            struct printablestring_ec {

                static void out(boost::asn1::x691::output_coder& stream, printablestring_type::value_type vl);

                static printablestring_type::value_type in(boost::asn1::x691::input_coder& stream);

                static std::size_t bits_count(bool aligned) {
                    return aligned ? 8 : 7;
                }

            };

            struct ia5string_ec {

                static void out(boost::asn1::x691::output_coder& stream, ia5string_type::value_type vl);

                static ia5string_type::value_type in(boost::asn1::x691::input_coder& stream);

                static std::size_t bits_count(bool aligned) {
                    return aligned ? 8 : 7;
                }

            };

            struct visiblestring_ec {

                static void out(boost::asn1::x691::output_coder& stream, visiblestring_type::value_type vl);

                static visiblestring_type::value_type in(boost::asn1::x691::input_coder& stream);

                static std::size_t bits_count(bool aligned) {
                    return aligned ? 8 : 7;
                }

            };

            struct bmpstring_ec {

                static void out(boost::asn1::x691::output_coder& stream, bmpstring_type::value_type vl);

                static bmpstring_type::value_type in(boost::asn1::x691::input_coder& stream);

                static std::size_t bits_count(bool aligned) {
                    return /*aligned ? 8 :*/ 16;
                }

            };

            struct universalstring_ec {

                static void out(boost::asn1::x691::output_coder& stream, universalstring_type::value_type vl);

                static universalstring_type::value_type in(boost::asn1::x691::input_coder& stream);

                static std::size_t bits_count(bool aligned) {
                    return /*aligned ? 8 :*/ 32;
                }

            };






            //////////////////////////////////////////////////////////////////////////////////////////
            ///  archiver     
            //////////////////////////////////////////////////////////////////////////////////////////            

            class output_coder : public boost::itu::base_output_coder {

            public:

                output_coder(encoding_rule rul = boost::itu::PER_ALIGNED_ENCODING) :
                boost::itu::base_output_coder(rul), unaligned_(rul == boost::itu::PER_UNALIGNED_ENCODING) {
                }

                bool aligned() const {
                    return !unaligned_;
                }

                bool unaligned() const {
                    return unaligned_;
                }


                void add_bitmap(const bitstring_type & vl, bool alighn = false);

                void add_octets(const octet_sequnce& vl, bool alighn = false);

                void add_octets(const octetstring_type & vl, bool alighn = false);

                template<typename T>
                void add_constrained(T indx, T min, T max) {
                    *this << constrained_wnumber<T>(indx, min, max);
                }

                void add_nsn_small(std::size_t indx);

                void start_open();

                void end_open();

                void set_extentions_marker(const bitstring_type & vl);

                template<typename T>
                void operator&(const T& vl) {
                    *this << vl;
                }

                template<typename T>
                void operator&(const boost::shared_ptr<T >& vl) {
                    if (static_cast<bool> (vl))
                        * this & (*vl);
                }

                template<typename T>
                void operator&(const explicit_value<T >& vl) {
                    *this & vl.value();
                }

                template<typename T>
                void operator&(const per_enumerated_holder<T >& vl) {
                    *this << vl;
                }

                template<typename T>
                void operator&(const implicit_value<T >& vl) {
                    *this & vl.value();
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const explicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this & vl.value();
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const implicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this & vl.value();
                }

                bool canonical() const {
                    return rule_ == boost::itu::CER_ENCODING;
                }

            private:

                bool unaligned_;

            };



            ////////////////////////////////////////////////////////////////////

            template<typename T>
            inline output_coder& operator<<(output_coder& stream, const T& vl) {
                const_cast<T&> (vl).serialize(stream);
                return stream;
            }

            template<typename T>
            inline output_coder& operator<<(output_coder& stream, const constrained_wnumber<T>& vl) {
                if ((stream.unaligned()) || (vl.is_minimal()))
                    stream.add_bitmap(vl.as_bitmap(), false);
                else
                    stream.add(vl.as_octets());
                return stream;
            }


            ////////////////// ELEMENTS AND STRINGS

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& elms, bool align = false);

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& sz, const octet_sequnce& elms, bool align = false);


            output_coder& octets_writer(output_coder& stream, const bitstring_type& elms, bool align = false);

            output_coder& octets_writer(output_coder& stream, const octet_sequnce& sz, const bitstring_type& elms, bool align = false);

            template<typename T>
            output_coder& elements_writer(output_coder& stream, T beg, T end) {
                for (T it = beg; it != end; ++it)
                    stream << (*it);
                return stream;
            }

            template<typename T>
            output_coder& elements_writer(output_coder& stream, const octet_sequnce& sz, T beg, T end) {
                stream.add_octets(sz, stream.aligned());
                return elements_writer<T>(stream, beg, end);
            }

            template<typename T, typename EC>
            output_coder& spec_elements_writer(output_coder& stream, T beg, T end) {
                for (T it = beg; it != end; ++it)
                    EC::out(stream, *it);
                return stream;
            }

            template<typename T, typename EC>
            output_coder& spec_elements_writer(output_coder& stream, const octet_sequnce& sz, T beg, T end) {
                stream.add_octets(sz, stream.aligned());
                return spec_elements_writer<T, EC>(stream, beg, end);
            }




            //  writer_defsz

            template<typename T>
            void writer_defsz(output_coder& stream, const size_constrainter<T>& vl) {

                std::size_t tmpsz = vl.value().size();
                if (!vl.check(tmpsz))
                    throw boost::system::system_error(boost::itu::ER_PROTOCOL);

                if (!vl.is_single()) {
                    if (vl.semi())
                        stream << semiconstrained_wnumber<std::size_t>(tmpsz, vl.min());
                    else
                        stream << constrained_wnumber<std::size_t>(tmpsz, vl.min(), vl.max());
                }

            }

            template<typename T, typename EC>
            void writer_defsz(output_coder& stream, const size_constrainter<T, EC>& vl) {

                std::size_t tmpsz = vl.value().size();
                if (!vl.check(tmpsz))
                    throw boost::system::system_error(boost::itu::ER_PROTOCOL);

                if (!vl.is_single()) {
                    if (vl.semi())
                        stream << semiconstrained_wnumber<std::size_t>(tmpsz, vl.min());
                    else
                        stream << constrained_wnumber<std::size_t>(tmpsz, vl.min(), vl.max());
                }

            }


            //  check_alighn                      

            template<typename T>
            bool check_alighn(const size_constrainter<T >& vl) {
                return (!(vl.is_single()) || ((vl.is_single()) &&(vl.value().size() > MIN_NOT_ALIGN_OCTSIZE)));
            }

            template<>
            bool check_alighn(const size_constrainter<bitstring_type >& vl);

            template<typename T, typename EC>
            bool spec_check_alighn(const size_constrainter<T, EC >& vl) {
                return (!(vl.is_single()) || ((vl.is_single()) && ((vl.max() * EC::bits_count(true)) > MIN_NOT_ALIGN_BITSIZE)));
            }



            //   undef size writer

            template<typename T>
            output_coder& octet_writer_undefsz(output_coder& stream, const T& vl) {
                std::size_t sz = vl.size();
                std::size_t beg = 0;
                while (beg < sz) {
                    if ((sz - beg) < LENGH_16K) {
                        octets_writer(stream, to_x691_cast(size_class(sz - beg)),
                                octet_sequnce(vl.begin() + beg, vl.end()), stream.aligned());
                        beg = sz;
                    } else {
                        if ((sz - beg) < LENGH_64K) {
                            std::size_t m = (sz - beg) / LENGH_16K;
                            std::size_t nbeg = beg + LENGH_16K*m;
                            octets_writer(stream, to_x691_cast(size_class(LENGH_16K * m)),
                                    octet_sequnce(vl.begin() + beg, vl.begin() + nbeg), stream.aligned());
                            beg = nbeg;
                        } else {
                            octets_writer(stream, to_x691_cast(size_class(LENGH_64K)),
                                    octet_sequnce(vl.begin() + beg, vl.begin() + beg + LENGH_64K), stream.aligned());
                            beg += LENGH_64K;
                        }
                        if (beg == sz)
                            octets_writer(stream, to_x691_cast(size_class(0)),
                                octet_sequnce(), stream.aligned());
                    }
                }
                return stream;
            }

            template<>
            output_coder& octet_writer_undefsz(output_coder& stream, const bitstring_type& vl);

            template<typename T>
            output_coder& element_writer_undefsz(output_coder& stream, const T& vl) {
                std::size_t sz = vl.size();
                std::size_t beg = 0;
                while (beg < sz) {
                    if ((sz - beg) < LENGH_16K) {
                        elements_writer(stream, to_x691_cast(size_class(sz - beg)), vl.begin() + beg, vl.end());
                        beg = sz;
                    } else {
                        if ((sz - beg) < LENGH_64K) {
                            std::size_t m = (sz - beg) / LENGH_16K;
                            std::size_t nbeg = beg + LENGH_16K*m;
                            elements_writer(stream, to_x691_cast(size_class(LENGH_16K * m)), vl.begin() + beg, vl.begin() + nbeg);
                            beg = nbeg;
                        } else {
                            elements_writer(stream, to_x691_cast(size_class(LENGH_64K)), vl.begin() + beg, vl.begin() + beg + LENGH_64K);
                            beg += LENGH_64K;
                        }
                        if (beg == sz)
                            octets_writer(stream, to_x691_cast(size_class(0)),
                                octet_sequnce());
                    }
                }
                return stream;
            }

            template<typename T, typename EC>
            output_coder& spec_element_writer_undefsz(output_coder& stream, const T& vl) {
                std::size_t sz = vl.size();
                std::size_t beg = 0;
                while (beg < sz) {
                    if ((sz - beg) < LENGH_16K) {
                        spec_elements_writer<typename T::const_iterator, EC > (stream, to_x691_cast(size_class(sz - beg)),
                                vl.begin() + beg, vl.end());
                        beg = sz;
                    } else {
                        if ((sz - beg) < LENGH_64K) {
                            std::size_t m = (sz - beg) / LENGH_16K;
                            std::size_t nbeg = beg + LENGH_16K*m;
                            spec_elements_writer<typename T::const_iterator, EC > (stream, to_x691_cast(size_class(LENGH_16K * m)),
                                    vl.begin() + beg, vl.begin() + nbeg);
                            beg = nbeg;
                        } else {
                            spec_elements_writer<typename T::const_iterator, EC > (stream, to_x691_cast(size_class(LENGH_64K)),
                                    vl.begin() + beg, vl.begin() + beg + LENGH_64K);
                            beg += LENGH_64K;
                        }
                        if (beg == sz) {
                            T tmp;
                            spec_elements_writer<typename T::const_iterator, EC > (stream, to_x691_cast(size_class(0)),
                                    tmp.begin(), tmp.end());
                        }
                    }
                }
                return stream;
            }




            /////////////////////////////////////////////////////           

            template<typename T>
            inline output_coder& operator<<(output_coder& stream, const semiconstrained_wnumber<T>& vl) {
                return octet_writer_undefsz(stream, vl.as_octets());
            }

            template<typename T>
            inline output_coder& operator<<(output_coder& stream, const small_nn_wnumber <T>& vl) {
                if (vl.value() < MAX_SMALL_NN_SIZE) {
                    stream.add_bitmap(bitstring_type(octet_sequnce(1, static_cast<octet_type> (vl.value() & 0x3F) << 1), 1));
                } else {
                    stream.add_bitmap(bitstring_type(true));
                    stream << semiconstrained_wnumber<T>(const_cast<T&> (vl.value()), 0);
                }
                return stream;
            }




            //   def size writer            

            template<typename T>
            output_coder& octet_writer_defsz(output_coder& stream, const size_constrainter<T>& vl) {

                if (vl.available()) {
                    if (vl.can_extended())
                        stream.add_bitmap(bitstring_type(vl.extended(vl.value().size())));

                    if ((!vl.extended(vl.value().size())) && (vl.constrained())) {

                        writer_defsz(stream, vl);
                        return octets_writer(stream, octet_sequnce(vl.value()), stream.aligned() ? check_alighn<T>(vl) : false);
                    }
                }
                return octet_writer_undefsz(stream, vl.value());
            }

            template<>
            output_coder& octet_writer_defsz(output_coder& stream, const size_constrainter<bitstring_type>& vl);

            template<typename T>
            output_coder& element_writer_defsz(output_coder& stream, const size_constrainter<T>& vl) {


                if (vl.available()) {
                    if (vl.can_extended())
                        stream.add_bitmap(bitstring_type(vl.extended(vl.value().size())));

                    if ((!vl.extended(vl.value().size())) && (vl.constrained())) {

                        writer_defsz(stream, vl);
                        return elements_writer(stream, vl.value().begin(), vl.value().end());
                    }
                }
                return element_writer_undefsz(stream, vl.value());
            }

            template<typename T, typename EC>
            output_coder& spec_element_writer_defsz(output_coder& stream, const size_constrainter<T, EC>& vl, bool checkal = false) {

                if (vl.available()) {
                    if (vl.can_extended())
                        stream.add_bitmap(bitstring_type(vl.extended(vl.value().size())));

                    if ((!vl.extended(vl.value().size())) && (vl.constrained())) {

                        writer_defsz(stream, vl);
                        if ((stream.aligned()) && checkal && (spec_check_alighn<T, EC>(vl)))
                            stream.force_alighn();
                        return spec_elements_writer<typename T::const_iterator, EC > (stream, vl.value().begin(), vl.value().end());
                    }
                }
                return spec_element_writer_undefsz<T, EC>(stream, vl.value());
            }




            ///////////////////////////////////////////////////////////////////////

            template<typename T>
            output_coder& primitive_int_serialize(output_coder& stream, const T& vl) {

                unconstrained_wnumber<T> tmp(const_cast<T&> (vl));
                octet_sequnce data = tmp.as_octets();
                octet_writer_undefsz(stream, data);
                return stream;

            }

            template<typename T>
            output_coder& alighned_int_serialize(output_coder& stream, const num_constrainter<T >& vl) {

                constrained_wnumber<T> tmp(const_cast<T&> (vl.value()), vl.min(), vl.max());
                boost::uint64_t semi = tmp.sendval();

                octet_sequnce data;
                to_x690_cast<boost::uint64_t>(semi, data);

                if (data.empty())
                    data = S0_OCTET;

                std::size_t octsz = data.size();

                constrained_wnumber<std::size_t> rng(octsz, 1, tmp.octetsize());

                stream.add_bitmap(rng.as_bitmap());
                stream.add_octets(data, true);

                return stream;
            }

            template<typename T>
            output_coder& primitive_690_serialize(output_coder& stream, const T& vl) {
                octet_sequnce tmp;
                to_x690_cast(vl, tmp);
                octet_writer_undefsz(stream, tmp);
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const per_enumerated_holder<T >& vl) {
                bool ext = false;
                std::size_t sval = vl.to();
                if (vl.can_extended()) {
                    ext = !vl.is_root();
                    stream.add_bitmap(bitstring_type(ext));
                }
                if (!ext) {
                    std::size_t maxnum = vl.max();
                    stream << constrained_wnumber<std::size_t>(sval, 0, maxnum);
                    //root
                } else {
                    //ext
                    stream << small_nn_wnumber<std::size_t>(sval);
                }
                return stream;
            }

            ////////////////////////////////////////////////////////////////////

            template<typename T>
            output_coder& operator<<(output_coder& stream, const std::vector<T>& vl) {
                return element_writer_undefsz(stream, vl);
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const std::deque<T>& vl) {
                return element_writer_undefsz(stream, vl);
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const size_constrainter<T >& vl) {
                element_writer_defsz(stream, vl);
                return stream;
            }

            template<typename T, typename EC>
            output_coder& operator<<(output_coder& stream, const size_constrainter<T, EC >& vl) {
                spec_element_writer_defsz<T, EC>(stream, vl);
                return stream;
            }

            template<typename T>
            output_coder& operator<<(output_coder& stream, const num_constrainter<T >& vl) {

                if (vl.can_extended()) {
                    stream.add_bitmap(bitstring_type(vl.extended()));
                    if (vl.extended())
                        return primitive_int_serialize(stream, vl.value());
                } else if (vl.nill_extended()) {
                    stream.add_bitmap(bitstring_type(false));
                    return primitive_int_serialize(stream, vl.value());
                }

                if (vl.is_single())
                    return stream;

                if (vl.constrained()) {
                    if (vl.semi()) {
                        semiconstrained_wnumber<T> tmp(const_cast<T&> (vl.value()), vl.min());
                        boost::uint64_t stmp = tmp.sendval();
                        return primitive_int_serialize(stream, stmp);
                    } else {
                        if ((vl.range() <= LENGH_64K) || (stream.unaligned()))
                            return stream << constrained_wnumber<T>(const_cast<T&> (vl.value()), vl.min(), vl.max());
                        else
                            return alighned_int_serialize(stream, vl);
                    }
                }

                return primitive_int_serialize(stream, vl.value());
            }

            output_coder& operator<<(output_coder& stream, const uint8_t& vl);

            output_coder& operator<<(output_coder& stream, const int8_t& vl);

            output_coder& operator<<(output_coder& stream, const uint16_t& vl);

            output_coder& operator<<(output_coder& stream, const int16_t& vl);

            output_coder& operator<<(output_coder& stream, const uint32_t& vl);

            output_coder& operator<<(output_coder& stream, const int32_t& vl);

            output_coder& operator<<(output_coder& stream, const uint64_t& vl);

            output_coder& operator<<(output_coder& stream, const int64_t& vl);

            output_coder& operator<<(output_coder& stream, const enumerated_type& vl);

            output_coder& operator<<(output_coder& stream, const float& vl);

            output_coder& operator<<(output_coder& stream, const double& vl);

            output_coder& operator<<(output_coder& stream, const long double& vl);

            output_coder& operator<<(output_coder& stream, const bool& vl);

            output_coder& operator<<(output_coder& stream, const null_type& vl);

            output_coder& operator<<(output_coder& stream, const oid_type& vl);

            output_coder& operator<<(output_coder& stream, const reloid_type& vl);

            output_coder& operator<<(output_coder& stream, const any_type& vl);

            // strings

            output_coder& operator<<(output_coder& stream, const bitstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<bitstring_type>& vl);

            output_coder& operator<<(output_coder& stream, const octetstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<octetstring_type>& vl);

            output_coder& operator<<(output_coder& stream, const utf8string_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<utf8string_type>& vl);

            output_coder& operator<<(output_coder& stream, const numericstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<numericstring_type>& vl);

            template<typename EC>
            output_coder& operator<<(output_coder& stream, const size_constrainter<numericstring_type, EC>& vl) {
                return spec_element_writer_defsz<numericstring_type, EC>(stream, vl, true);
            }


            output_coder& operator<<(output_coder& stream, const printablestring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<printablestring_type>& vl);

            template<typename EC>
            output_coder& operator<<(output_coder& stream, const size_constrainter<printablestring_type, EC>& vl) {
                return spec_element_writer_defsz<printablestring_type, EC>(stream, vl, true);
            }


            output_coder& operator<<(output_coder& stream, const t61string_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<t61string_type>& vl);


            output_coder& operator<<(output_coder& stream, const videotexstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<videotexstring_type>& vl);


            output_coder& operator<<(output_coder& stream, const ia5string_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter< ia5string_type>& vl);

            template<typename EC>
            output_coder& operator<<(output_coder& stream, const size_constrainter< ia5string_type, EC>& vl) {
                return spec_element_writer_defsz< ia5string_type, EC>(stream, vl, true);
            }

            output_coder& operator<<(output_coder& stream, const graphicstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<graphicstring_type>& vl);


            output_coder& operator<<(output_coder& stream, const objectdescriptor_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<objectdescriptor_type>& vl);


            output_coder& operator<<(output_coder& stream, const visiblestring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<visiblestring_type>& vl);

            template<typename EC>
            output_coder& operator<<(output_coder& stream, const size_constrainter<visiblestring_type, EC>& vl) {
                return spec_element_writer_defsz<visiblestring_type, EC>(stream, vl, true);
            }

            output_coder& operator<<(output_coder& stream, const generalstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<generalstring_type>& vl);


            output_coder& operator<<(output_coder& stream, const universalstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter<universalstring_type>& vl);

            template<typename EC>
            output_coder& operator<<(output_coder& stream, const size_constrainter<universalstring_type, EC>& vl) {
                return spec_element_writer_defsz<universalstring_type, EC>(stream, vl, true);
            }


            output_coder& operator<<(output_coder& stream, const bmpstring_type& vl);

            output_coder& operator<<(output_coder& stream, const size_constrainter< bmpstring_type>& vl);

            template<typename EC>
            output_coder& operator<<(output_coder& stream, const size_constrainter< bmpstring_type, EC>& vl) {
                return spec_element_writer_defsz< bmpstring_type, EC>(stream, vl, true);
            }



            output_coder& operator<<(output_coder& stream, const utctime_type& vl);

            output_coder& operator<<(output_coder& stream, const gentime_type& vl);




            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            /*INPUT STREAM                                                                                                                                                                                               */
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


            //////////////////////////////////////////////////////////
            //   archiver

            class input_coder : public boost::itu::base_input_coder {

            public:

                input_coder(encoding_rule rul = boost::itu::PER_ALIGNED_ENCODING) :
                boost::itu::base_input_coder(rul), unaligned_(rul == boost::itu::PER_UNALIGNED_ENCODING) {
                }

                bool aligned() const {
                    return !unaligned_;
                }

                bool unaligned() const {
                    return unaligned_;
                }

                std::size_t get_bitmap(std::size_t sz, bitstring_type& vl, bool alighn = false);

                std::size_t get_octets(std::size_t sz, octet_sequnce& vl, bool alighn = false);

                std::size_t pop_bitmap(std::size_t sz, bool alighn = false);

                std::size_t pop_octets(std::size_t sz, bool alighn = false);

                std::size_t get_pop_bitmap(std::size_t sz, bitstring_type& vl, bool alighn = false);

                std::size_t get_pop_octets(std::size_t sz, octet_sequnce& vl, bool alighn = false);

                bitstring_type get_pop_bmp(std::size_t sz, bool alighn = false);

                octet_sequnce get_pop_octs(std::size_t sz, bool alighn = false);

                template<typename T>
                T get_constrained(T min, T max) {
                    T rslt = min;
                    constrained_wnumber<T> vl(rslt, min, max);
                    *this >> vl;
                    return rslt;
                }

                std::size_t get_nsn_small();

                void start_open();
                
                void end_open();

                void get_extentions_marker(bitstring_type& vl);
                
                void clear_extentions(const bitstring_type& exbmp, std::size_t cnt);          
                
                void clear_extention();                   

                template<typename T>
                void operator&(const T& vl) {
                    *this >> const_cast<T&> (vl);
                }

                template<typename T>
                void operator&(const boost::shared_ptr<T >& vl) {
                    if (!static_cast<bool> (vl))
                        const_cast<boost::shared_ptr<T >&> (vl) = boost::shared_ptr<T >(new T());
                    * this & (*vl);
                }

                template<typename T>
                void operator&(const per_enumerated_holder<T >& vl) {
                    *this >> const_cast<per_enumerated_holder<T >&> (vl);
                }

                template<typename T>
                void operator&(const explicit_value<T >& vl) {
                    *this & vl.value();
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const explicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this & vl.value();
                }

                template<typename T>
                void operator&(const implicit_value<T >& vl) {
                    *this & vl.value();
                }

                template<typename T, class Tag, id_type ID, class_type TYPE >
                void operator&(const implicit_typedef <T, Tag, ID, TYPE>& vl) {
                    *this & vl.value();
                }


            private:

                bool unaligned_;

            };





            //////////////////////////////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////////////////////////////            

            template<typename T>
            inline input_coder& operator>>(input_coder& stream, T& vl) {
                const_cast<T&> (vl).serialize(stream);
                return stream;
            }

            template<typename T>
            inline input_coder& operator>>(input_coder& stream, constrained_wnumber<T>& vl) {
                if ((stream.unaligned()) || (vl.is_minimal())) {
                    std::size_t bitsz = vl.bitsize();
                    vl.value(stream.get_pop_bmp(bitsz));
                } else
                    vl.value(stream.get_pop_octs(vl.octetsize(), true));
                return stream;
            }


            //////////////////////////////////////////////////////////////////////////////////

            template<typename T>
            input_coder& octet_reader(input_coder& stream, T& vl, std::size_t sz, bool alighn = false) {
                if (sz) {
                    octet_sequnce readvl = stream.get_pop_octs(sz, alighn);
                    vl.insert(vl.end(), readvl.begin(), readvl.end());
                }
                return stream;
            }

            template<>
            input_coder& octet_reader(input_coder& stream, bitstring_type& vl, std::size_t sz, bool alighn);

            template<typename T>
            input_coder& element_reader(input_coder& stream, T& vl, std::size_t sz) {
                typedef typename T::value_type value_type;
                while (sz--) {
                    value_type tmp;
                    stream & tmp;
                    vl.push_back(tmp);
                }
                return stream;
            }

            template<typename T, typename EC>
            input_coder& spec_element_reader(input_coder& stream, T& vl, std::size_t sz) {
                while (sz--) {
                    std::back_inserter<T>(vl) = EC::in(stream);
                }
                return stream;
            }

            template<typename T>
            input_coder& octet_reader_undefsz(input_coder& stream, T& vl) {
                while (true) {
                    octet_sequnce strt = stream.get_pop_octs(1, stream.aligned());
                    if (strt.size()) {
                        octet_sequnce::value_type dtrm = strt[0];
                        switch (dtrm & '\xC0') {
                            case '\xC0':
                            {
                                octet_sequnce nxt = stream.get_pop_octs(1, stream.aligned());
                                std::size_t sz = LENGH_16K;
                                if ((nxt.size()) && ((0x7 & nxt[0]) <= 4))
                                    sz *= static_cast<std::size_t> (0x7 & nxt[0]);
                                else
                                    throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                                octet_reader(stream, vl, sz, stream.aligned());
                                break;
                            }
                            case '\x80':
                            {
                                octet_sequnce nxt = stream.get_pop_octs(1, stream.aligned());
                                boost::uint16_t dtrm16 = dtrm & '\x3f';
                                dtrm16 <<= 8;
                                if (nxt.size())
                                    dtrm16 |= nxt[0];
                                else
                                    throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                                return octet_reader(stream, vl, static_cast<std::size_t> (dtrm16 & 0x3FFF), stream.aligned());
                            }
                            default:
                            {
                                return octet_reader(stream, vl, static_cast<std::size_t> (dtrm & '\x7F'), stream.aligned());
                            }
                        }
                    } else
                        throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                }
                return stream;
            }

            template<typename T>
            input_coder& element_reader_undefsz(input_coder& stream, T& vl) {
                while (true) {
                    octet_sequnce strt = stream.get_pop_octs(1, stream.aligned());
                    if (strt.size()) {
                        octet_sequnce::value_type dtrm = strt[0];
                        switch (dtrm & '\xC0') {
                            case '\xC0':
                            {
                                octet_sequnce nxt = stream.get_pop_octs(1, stream.aligned());
                                std::size_t sz = LENGH_16K;
                                if ((nxt.size()) && ((0x7 & nxt[0]) <= 4))
                                    sz *= static_cast<std::size_t> (0x7 & nxt[0]);
                                else
                                    throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                                element_reader(stream, vl, sz);
                                break;
                            }
                            case '\x80':
                            {
                                octet_sequnce nxt = stream.get_pop_octs(1, stream.aligned());
                                boost::uint16_t dtrm16 = dtrm & '\x3f';
                                dtrm16 <<= 8;
                                if (nxt.size())
                                    dtrm16 |= nxt[0];
                                else
                                    throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                                return element_reader(stream, vl, static_cast<std::size_t> (dtrm16 & 0x3FFF));
                            }
                            default:
                            {
                                return element_reader(stream, vl, static_cast<std::size_t> (dtrm & '\x7F'));
                            }
                        }
                    } else
                        throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                }
                return stream;
            }

            template<typename T, typename EC>
            input_coder& spec_element_reader_undefsz(input_coder& stream, T& vl) {
                while (true) {
                    octet_sequnce strt = stream.get_pop_octs(1, stream.aligned());
                    if (strt.size()) {
                        octet_sequnce::value_type dtrm = strt[0];
                        switch (dtrm & '\xC0') {
                            case '\xC0':
                            {
                                octet_sequnce nxt = stream.get_pop_octs(1, stream.aligned());
                                std::size_t sz = LENGH_16K;
                                if ((nxt.size()) && ((0x7 & nxt[0]) <= 4))
                                    sz *= static_cast<std::size_t> (0x7 & nxt[0]);
                                else
                                    throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                                spec_element_reader<T, EC>(stream, vl, sz);
                                break;
                            }
                            case '\x80':
                            {
                                octet_sequnce nxt = stream.get_pop_octs(1, stream.aligned());
                                boost::uint16_t dtrm16 = dtrm & '\x3f';
                                dtrm16 <<= 8;
                                if (nxt.size())
                                    dtrm16 |= nxt[0];
                                else
                                    throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                                return spec_element_reader<T, EC>(stream, vl, static_cast<std::size_t> (dtrm16 & 0x3FFF));
                            }
                            default:
                            {
                                return spec_element_reader<T, EC>(stream, vl, static_cast<std::size_t> (dtrm & '\x7F'));
                            }
                        }
                    } else
                        throw boost::system::system_error(boost::itu::ER_BEDSEQ);
                }
                return stream;
            }

            template<typename T>
            inline input_coder& operator>>(input_coder& stream, semiconstrained_wnumber<T>& vl) {
                octet_sequnce data;
                octet_reader_undefsz(stream, data);
                vl.value(data);
                return stream;
            }

            template<typename T>
            inline input_coder& operator>>(input_coder& stream, small_nn_wnumber <T>& vl) {
                bitstring_type markerbit = stream.get_pop_bmp(1);
                if (markerbit.bit(0)) {
                    boost::uint64_t tmpvl = 0;
                    semiconstrained_wnumber<boost::uint64_t> tmp(tmpvl, 0);
                    stream>> tmp;
                    vl.value(tmp.value());
                    return stream;
                }
                bitstring_type valuebit = bitstring_type(S0_OCTET, 6) + stream.get_pop_bmp(6);
                vl.value(valuebit.as_octet_sequnce());
                return stream;
            }

            template<typename T>
            input_coder& octet_reader_defsz(input_coder& stream, size_constrainter<T>& vl) {


                if (vl.available()) {

                    if (vl.can_extended()) {
                        bitstring_type extendbit = stream.get_pop_bmp(1);
                        if (extendbit.bit(0)) {
                            return octet_reader_undefsz(stream, vl.value());
                        }
                    }

                    if (vl.constrained()) {

                        std::size_t sz = 0;
                        if (!vl.is_single()) {
                            if (vl.semi()) {
                                semiconstrained_wnumber<std::size_t> tmpsz(sz, vl.min());
                                stream >> tmpsz;
                            } else {
                                constrained_wnumber<std::size_t> tmpsz(sz, vl.min(), vl.max());
                                stream >> tmpsz;
                            }
                        } else
                            sz = vl.max();
                        return octet_reader(stream, vl.value(), sz, stream.aligned() ? check_alighn<T>(vl) : false);
                    }
                }
                return octet_reader_undefsz(stream, vl.value());
            }

            template<typename T>
            input_coder& element_reader_defsz(input_coder& stream, size_constrainter<T>& vl) {


                if (vl.available()) {

                    if (vl.can_extended()) {
                        bitstring_type extendbit = stream.get_pop_bmp(1);
                        if (extendbit.bit(0)) {
                            return element_reader_undefsz(stream, vl.value());
                        }
                    }

                    if (vl.constrained()) {

                        std::size_t sz = 0;
                        if (!vl.is_single()) {
                            if (vl.semi()) {
                                semiconstrained_wnumber<std::size_t> tmpsz(sz, vl.min());
                                stream >> tmpsz;
                            } else {
                                constrained_wnumber<std::size_t > tmpsz(sz, vl.min(), vl.max());
                                stream >> tmpsz;
                            }
                        } else
                            sz = vl.max();
                        element_reader(stream, vl.value(), sz);
                        return stream;

                    }
                }
                return element_reader_undefsz(stream, vl.value());
            }

            template<typename T, typename EC>
            input_coder& spec_element_reader_defsz(input_coder& stream, size_constrainter<T, EC>& vl, bool checkal = false) {


                if (vl.available()) {

                    if (vl.can_extended()) {
                        bitstring_type extendbit = stream.get_pop_bmp(1);
                        if (extendbit.bit(0)) {
                            return spec_element_reader_undefsz<T, EC>(stream, vl.value());
                        }
                    }

                    if (vl.constrained()) {

                        std::size_t sz = 0;
                        if (!vl.is_single()) {
                            if (vl.semi()) {
                                semiconstrained_wnumber<std::size_t> tmpsz(sz, vl.min());
                                stream >> tmpsz;
                            } else {
                                constrained_wnumber<std::size_t> tmpsz(sz, vl.min(), vl.max());
                                stream >> tmpsz;
                            }
                        } else
                            sz = vl.max();

                        if ((stream.aligned()) && checkal && (spec_check_alighn<T, EC>(vl)))
                            stream.force_alighn();

                        spec_element_reader<T, EC>(stream, vl.value(), sz);
                        return stream;

                    }
                }
                return spec_element_reader_undefsz<T, EC>(stream, vl.value());
            }

            template<typename T>
            input_coder& primitive_690_deserialize(input_coder& stream, T& vl) {
                octet_sequnce data;
                octet_reader_undefsz(stream, data);
                from_x690_cast<T>(const_cast<T&> (vl), data);
                return stream;
            }

            template<typename T>
            input_coder& primitive_int_deserialize(input_coder& stream, T& vl) {
                octet_sequnce data;
                octet_reader_undefsz(stream, data);
                unconstrained_wnumber<T> tmp(const_cast<T&> (vl));
                tmp.value(data);
                return stream;
            }

            template<typename T>
            input_coder& alighned_int_deserialize(input_coder& stream, num_constrainter<T >& vl) {


                constrained_wnumber<T> tmp(vl.value(), vl.min(), vl.max());
                //boost::uint64_t semi = tmp.sendval();

                std::size_t octsz = 1;
                constrained_wnumber<std::size_t> rng(octsz, 1, tmp.octetsize());

                rng.value(stream.get_pop_bmp(rng.bitsize()));


                octet_sequnce data = stream.get_pop_octs(octsz, true);

                tmp.value(data);

                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, num_constrainter<T >& vl) {


                if ((vl.can_extended()) || (vl.nill_extended())) {
                    bitstring_type extendbit = stream.get_pop_bmp(1);
                    if ((extendbit.bit(0)) || (vl.nill_extended()))
                        return primitive_int_deserialize(stream, vl.value());
                }

                if (vl.is_single()) {
                    vl.to_single();
                    return stream;
                }

                if (vl.constrained()) {
                    if (vl.semi()) {
                        boost::uint64_t stmp = 0;
                        primitive_int_deserialize(stream, stmp);
                        semiconstrained_wnumber<T> tmp(vl.value(), vl.min());
                        tmp.value(stmp);
                        return stream;
                    } else {
                        if ((vl.range() <= LENGH_64K) || (stream.unaligned())) {
                            constrained_wnumber<T> tmp(vl.value(), vl.min(), vl.max());
                            return stream >> tmp;
                        } else
                            return alighned_int_deserialize(stream, vl);
                    }
                }

                return primitive_int_deserialize(stream, vl.value());
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, per_enumerated_holder<T >& vl) {
                std::size_t rval = 0;
                if (vl.can_extended()) {
                    bitstring_type extendbit = stream.get_pop_bmp(1);
                    if (extendbit.bit(0)) {
                        //ext                        
                        small_nn_wnumber<std::size_t> rtmp(rval);
                        stream >> rtmp;
                        vl.from(rval, true);
                        return stream;
                    }
                }
                //root
                constrained_wnumber<std::size_t> rtmp(rval, 0, vl.max());
                stream >> rtmp;
                vl.from(rval, false);
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, std::vector<T>& vl) {
                element_reader_undefsz(stream, vl);
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, std::deque<T>& vl) {
                element_reader_undefsz(stream, vl);
                return stream;
            }

            template<typename T>
            input_coder& operator>>(input_coder& stream, size_constrainter<T>& vl) {
                return element_reader_defsz(stream, vl);
            }

            template<typename T, typename EC>
            input_coder& operator>>(input_coder& stream, size_constrainter<T, EC>& vl) {
                return spec_element_reader_defsz<T, EC>(stream, vl);
            }



            input_coder& operator>>(input_coder& stream, int8_t& vl);

            input_coder& operator>>(input_coder& stream, uint8_t& vl);

            input_coder& operator>>(input_coder& stream, int16_t& vl);

            input_coder& operator>>(input_coder& stream, uint16_t& vl);

            input_coder& operator>>(input_coder& stream, int32_t& vl);

            input_coder& operator>>(input_coder& stream, uint32_t& vl);

            input_coder& operator>>(input_coder& stream, int64_t& vl);

            input_coder& operator>>(input_coder& stream, uint64_t& vl);

            input_coder& operator>>(input_coder& stream, float& vl);

            input_coder& operator>>(input_coder& stream, double& vl);

            input_coder& operator>>(input_coder& stream, long double& vl);

            input_coder& operator>>(input_coder& stream, bool& vl);

            input_coder& operator>>(input_coder& stream, null_type& vl);

            input_coder& operator>>(input_coder& stream, oid_type& vl);

            input_coder& operator>>(input_coder& stream, reloid_type& vl);

            input_coder& operator>>(input_coder& stream, any_type& vl);


            input_coder& operator>>(input_coder& stream, bitstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<bitstring_type>& vl);

            input_coder& operator>>(input_coder& stream, octetstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<octetstring_type>& vl);

            input_coder& operator>>(input_coder& stream, utf8string_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<utf8string_type>& vl);


            input_coder& operator>>(input_coder& stream, numericstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<numericstring_type>& vl);

            template<typename EC>
            input_coder& operator>>(input_coder& stream, size_constrainter<numericstring_type, EC>& vl) {
                return spec_element_reader_defsz<numericstring_type, EC>(stream, vl, true);
            }


            input_coder& operator>>(input_coder& stream, printablestring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<printablestring_type>& vl);

            template<typename EC>
            input_coder& operator>>(input_coder& stream, size_constrainter<printablestring_type, EC>& vl) {
                return spec_element_reader_defsz<printablestring_type, EC>(stream, vl, true);
            }


            input_coder& operator>>(input_coder& stream, t61string_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<t61string_type>& vl);

            input_coder& operator>>(input_coder& stream, videotexstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<videotexstring_type>& vl);



            input_coder& operator>>(input_coder& stream, ia5string_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter< ia5string_type>& vl);

            template<typename EC>
            input_coder& operator>>(input_coder& stream, size_constrainter< ia5string_type, EC>& vl) {
                return spec_element_reader_defsz< ia5string_type, EC>(stream, vl, true);
            }



            input_coder& operator>>(input_coder& stream, graphicstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<graphicstring_type>& vl);

            input_coder& operator>>(input_coder& stream, objectdescriptor_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<objectdescriptor_type>& vl);



            input_coder& operator>>(input_coder& stream, visiblestring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<visiblestring_type>& vl);

            template<typename EC>
            input_coder& operator>>(input_coder& stream, size_constrainter<visiblestring_type, EC>& vl) {
                return spec_element_reader_defsz<visiblestring_type, EC>(stream, vl, true);
            }



            input_coder& operator>>(input_coder& stream, generalstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<generalstring_type>& vl);



            input_coder& operator>>(input_coder& stream, universalstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter<universalstring_type>& vl);

            template<typename EC>
            input_coder& operator>>(input_coder& stream, size_constrainter<universalstring_type, EC>& vl) {
                return spec_element_reader_defsz<universalstring_type, EC>(stream, vl, true);
            }


            input_coder& operator>>(input_coder& stream, bmpstring_type& vl);

            input_coder& operator>>(input_coder& stream, size_constrainter< bmpstring_type>& vl);

            template<typename EC>
            input_coder& operator>>(input_coder& stream, size_constrainter< bmpstring_type, EC>& vl) {
                return spec_element_reader_defsz< bmpstring_type, EC>(stream, vl, true);
            }



            input_coder& operator>>(input_coder& stream, utctime_type& vl);

            input_coder& operator>>(input_coder& stream, gentime_type& vl);



        }



        // integer element constrainter

        template<typename T, T mn, T mx, bool ext>
        struct ___integer_tmpl_ec___ {

            static void out(boost::asn1::x691::output_coder& stream, T vl) {
                stream & num_constrainter<T>(vl, mn, mx, ext);
            }

            static T in(boost::asn1::x691::input_coder& stream) {
                T inv;
                stream & num_constrainter<T>(inv, mn, mx, ext);
                return inv;
            }

            static std::size_t bits_count(bool aligned) {
                return 0xFF;
            }

        };



        // integer element constrainter

        template<typename T>
        struct ___enumerated_tmpl_ec___ {

            static void out(boost::asn1::x691::output_coder& stream, enumerated_type vl) {
                stream & T(vl);
            }

            static enumerated_type in(boost::asn1::x691::input_coder& stream) {
                enumerated_type inv = 0;
                T hlpr(inv);
                stream & hlpr;
                return inv;
            }

            static std::size_t bits_count(bool aligned) {
                return 0xFF;
            }

        };




        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Main bind
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        template<typename Archive, typename T>
        inline bool bind_per(Archive & arch, T& vl) {
            arch & vl;
            return true;
        }

        template<typename Archive, typename T>
        inline bool bind_per(Archive & arch, value_holder<T>& vl) {
            return bind_per(arch, *vl);
        }

        template<typename T>
        inline bool bind_per(boost::asn1::x691::output_coder & arch, boost::shared_ptr<T>& vl) {
            if (static_cast<bool> (vl))
                return bind_per(arch, *vl);
            return false;
        }

        template<typename T>
        inline bool bind_per(boost::asn1::x691::input_coder & arch, boost::shared_ptr<T>& vl) {
            if (!static_cast<bool> (vl))
                vl = boost::shared_ptr<T>(new T());
            return bind_per(arch, *vl);
        }

        template<typename T, const T& DT>
        inline bool bind_per(boost::asn1::x691::output_coder & arch, default_holder<T, DT>& vl) {
            if (!vl.isdefault())
                return bind_per(arch, vl.get_shared());
            return false;
        }

        template<typename T, const T& DT>
        inline bool bind_per(boost::asn1::x691::input_coder & arch, default_holder<T, DT>& vl) {
            return bind_per(arch, vl.get_shared());
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_per(Archive & arch, implicit_typedef<T, Tag, ID, TYPE>& vl) {
            return bind_per(arch, vl.value());
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_per(Archive & arch, explicit_typedef<T, Tag, ID, TYPE>& vl) {
            return bind_per(arch, vl.value());
        }


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Enum
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        template<typename T>
        inline bool bind_per_enum(boost::asn1::x691::output_coder & arch, enumerated_type& vl) {
            arch & per_enumerated_holder<T>(vl);
            return true;
        }

        template<typename T>
        inline bool bind_per_enum(boost::asn1::x691::input_coder & arch, enumerated_type& vl) {
            arch & per_enumerated_holder<T>(vl);
            return true;
        }

        template<typename T>
        inline bool bind_per_enum(boost::asn1::x691::output_coder & arch, value_holder<enumerated_type>& vl) {
            return bind_per_enum<T>(arch, *vl);
        }

        template<typename T>
        inline bool bind_per_enum(boost::asn1::x691::input_coder & arch, value_holder<enumerated_type>& vl) {
            return bind_per_enum<T>(arch, *vl);
        }

        template<typename T>
        inline bool bind_per_enum(boost::asn1::x691::output_coder & arch, boost::shared_ptr<enumerated_type>& vl) {
            if (static_cast<bool> (vl))
                return bind_per_enum<T>(arch, *vl);
            return false;
        }

        template<typename T>
        inline bool bind_per_enum(boost::asn1::x691::input_coder & arch, boost::shared_ptr<enumerated_type>& vl) {
            if (!static_cast<bool> (vl))
                vl = boost::shared_ptr<enumerated_type>(new enumerated_type());
            return bind_per_enum<T>(arch, *vl);
        }

        template<typename T, const enumerated_type& DT>
        inline bool bind_per_enum(boost::asn1::x691::output_coder & arch, default_holder<enumerated_type, DT>& vl) {
            if (!vl.isdefault())
                return bind_per_enum<T>(arch, vl.get_shared());
            return false;
        }

        template<typename T, const enumerated_type& DT>
        inline bool bind_per_enum(boost::asn1::x691::input_coder & arch, default_holder<enumerated_type, DT>& vl) {
            return bind_per_enum<T>(arch, vl.get_shared());
        }

        template<typename Archive, class Tag, id_type ID, class_type TYPE>
        inline bool bind_per_enum(Archive & arch, implicit_typedef<enumerated_type, Tag, ID, TYPE>& vl) {
            return bind_per_enum(arch, vl.value());
        }

        template<typename Archive, class Tag, id_type ID, class_type TYPE>
        inline bool bind_per(Archive & arch, explicit_typedef<enumerated_type, Tag, ID, TYPE>& vl) {
            return bind_per_enum(arch, vl.value());
        }



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Num bind
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////       

        template<typename Archive, typename T>
        inline bool bind_constraints(Archive & arch, T& vl, const T& MIN, const T& MAX, bool ext) {
            std::size_t tst = arch.size();
            arch & num_constrainter<T> (vl, MIN, MAX, ext);
            return (arch.size() != tst);
        }

        template<typename Archive, typename T>
        inline bool bind_constraints(Archive & arch, value_holder<T>& vl, const T& MIN, const T& MAX, bool ext) {
            return bind_constraints(arch, *vl, MIN, MAX, ext);
        }

        template<typename T>
        inline bool bind_constraints(boost::asn1::x691::output_coder & arch, boost::shared_ptr<T>& vl, const T& MIN, const T& MAX, bool ext) {
            if (static_cast<bool> (vl))
                return bind_constraints(arch, *vl, MIN, MAX, ext);
            return false;
        }

        template<typename T>
        inline bool bind_constraints(boost::asn1::x691::input_coder & arch, boost::shared_ptr<T>& vl, const T& MIN, const T& MAX, bool ext) {
            if (!static_cast<bool> (vl))
                vl = boost::shared_ptr<T>(new T());
            return bind_constraints(arch, *vl, MIN, MAX, ext);
        }

        template<typename T, const T& DT>
        inline bool bind_constraints(boost::asn1::x691::output_coder & arch, default_holder<T, DT>& vl, const T& MIN, const T& MAX, bool ext) {
            if (!vl.isdefault())
                return bind_constraints(arch, vl.get_shared(), MIN, MAX, ext);
            return false;
        }

        template<typename T, const T& DT>
        inline bool bind_constraints(boost::asn1::x691::input_coder & arch, default_holder<T, DT>& vl, const T& MIN, const T& MAX, bool ext) {
            return bind_constraints(arch, vl.get_shared(), MIN, MAX, ext);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_constraints(Archive & arch, implicit_typedef<T, Tag, ID, TYPE>& vl, const T& MIN, const T& MAX, bool ext) {
            return bind_constraints(arch, vl.value(), MIN, MAX, ext);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_constraints(Archive & arch, explicit_typedef<T, Tag, ID, TYPE>& vl, const T& MIN, const T& MAX, bool ext) {
            return bind_constraints(arch, vl.value(), MIN, MAX, ext);
        }





        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Main size
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        template<typename Archive, typename T>
        inline bool bind_sizeconstraints(Archive & arch, T& vl, const std::size_t& MIN, const std::size_t& MAX, bool ext) {
            arch & size_constrainter<T> (vl, MIN, MAX, ext);
            return true;
        }

        template<typename Archive, typename T>
        inline bool bind_sizeconstraints(Archive & arch, value_holder<T>& vl, const T& MIN, const T& MAX, bool ext) {
            return bind_sizeconstraints(arch, *vl, MIN, MAX, ext);
        }

        template<typename T>
        inline bool bind_sizeconstraints(boost::asn1::x691::output_coder & arch, boost::shared_ptr<T>& vl, const std::size_t& MIN, const std::size_t& MAX, bool ext) {
            if (static_cast<bool> (vl))
                return bind_sizeconstraints(arch, *vl, MIN, MAX, ext);
            return false;
        }

        template<typename T>
        inline bool bind_sizeconstraints(boost::asn1::x691::input_coder & arch, boost::shared_ptr<T>& vl, const std::size_t& MIN, const std::size_t& MAX, bool ext) {
            if (!static_cast<bool> (vl))
                vl = boost::shared_ptr<T>(new T());
            return bind_sizeconstraints(arch, *vl, MIN, MAX, ext);
        }

        template<typename T, const T& DT>
        inline bool bind_sizeconstraints(boost::asn1::x691::output_coder & arch, default_holder<T, DT>& vl, const std::size_t& MIN, const std::size_t& MAX, bool ext) {
            if (!vl.isdefault())
                return bind_sizeconstraints(arch, vl.get_shared(), MIN, MAX, ext);
            return false;
        }

        template<typename T, const T& DT>
        inline bool bind_sizeconstraints(boost::asn1::x691::input_coder & arch, default_holder<T, DT>& vl, const std::size_t& MIN, const std::size_t& MAX, bool ext) {
            return bind_sizeconstraints(arch, vl.get_shared(), MIN, MAX, ext);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_sizeconstraints(Archive & arch, implicit_typedef<T, Tag, ID, TYPE>& vl, const std::size_t& MIN, const std::size_t& MAX, bool ext) {
            return bind_sizeconstraints(arch, vl.value(), MIN, MAX, ext);
        }

        template<typename Archive, typename T, class Tag, id_type ID, class_type TYPE>
        inline bool bind_sizeconstraints(Archive & arch, explicit_typedef<T, Tag, ID, TYPE>& vl, const std::size_t& MIN, const std::size_t& MAX, bool ext) {
            return bind_sizeconstraints(arch, vl.value(), MIN, MAX, ext);
        }


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Main size
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        

        template<typename T, typename E>
        inline bool bind_sizeconstraints_ext(boost::asn1::x691::output_coder & arch, T& vl, const std::size_t& MIN, const std::size_t& MAX, bool ext) {
            arch & size_constrainter<T, E> (vl, MIN, MAX, ext);
            return true;
        }

        template<typename T, typename E>
        inline bool bind_sizeconstraints_ext(boost::asn1::x691::input_coder & arch, T& vl, const std::size_t& MIN, const std::size_t& MAX, bool ext) {
            arch & size_constrainter<T, E> (vl, MIN, MAX, ext);
            return true;
        }

        template<typename T, typename E>
        inline bool bind_sizeconstraints_ext(boost::asn1::x691::output_coder & arch, value_holder<T>& vl, const T& MIN, const T& MAX, bool ext) {
            return bind_sizeconstraints_ext<T, E>(arch, *vl, MIN, MAX, ext);
        }

        template<typename T, typename E>
        inline bool bind_sizeconstraints_ext(boost::asn1::x691::input_coder & arch, value_holder<T>& vl, const T& MIN, const T& MAX, bool ext) {
            return bind_sizeconstraints_ext<T, E>(arch, *vl, MIN, MAX, ext);
        }

        template<typename T, typename E>
        inline bool bind_sizeconstraints_ext(boost::asn1::x691::output_coder & arch, boost::shared_ptr<T>& vl, const std::size_t& MIN, const std::size_t& MAX, bool ext) {
            if (static_cast<bool> (vl))
                return bind_sizeconstraints_ext<T, E>(arch, *vl, MIN, MAX, ext);
            return false;
        }

        template<typename T, typename E>
        inline bool bind_sizeconstraints(boost::asn1::x691::input_coder & arch, boost::shared_ptr<T>& vl, const std::size_t& MIN, const std::size_t& MAX, bool ext) {
            if (!static_cast<bool> (vl))
                vl = boost::shared_ptr<T>(new T());
            return bind_sizeconstraints_ext<T, E>(arch, *vl, MIN, MAX, ext);
        }



        ////////////////////////////////////////////////////////////////////////////////////////////////////


        template<> void external_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void external_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void external_type::Encoding_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void external_type::Encoding_type::serialize(boost::asn1::x691::input_coder& arch);

        template<> void embeded_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void embeded_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void embeded_type::Identification_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void embeded_type::Identification_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void embeded_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void embeded_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void embeded_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void embeded_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::input_coder& arch);


        template<> void characterstring_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void characterstring_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void characterstring_type::Identification_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void characterstring_type::Identification_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void characterstring_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void characterstring_type::Identification_type::Syntaxes_type::serialize(boost::asn1::x691::input_coder& arch);
        template<> void characterstring_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::output_coder& arch);
        template<> void characterstring_type::Identification_type::Context_negotiation_type::serialize(boost::asn1::x691::input_coder& arch);




    }
}


#endif	/* ASNBASE_H */

