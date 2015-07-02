//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_BASECODER_IMPLEMENTATIUON_H_
#define         _ITU_BASECODER_IMPLEMENTATIUON_H_


#ifdef _MSC_VER
#if _MSC_VER >= 1800
#ifndef UNICODE
#define UNICODE
#endif
#endif
#endif

#include <boost/config.hpp>
#include <boost/cstdint.hpp>
#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/buffers_iterator.hpp>
#include <boost/cstdint.hpp>
#include <boost/dynamic_bitset.hpp>

#include <boost/itu/utils/template.hpp>

#define ITU_T_VARRAY(...) __VA_ARGS__
#define ITU_T_OID(nm  , arr )  const boost::asn1::oidindx_type nm ## ___ARR[] ={ arr } ; \
        const boost::asn1::oid_type  nm  = boost::asn1::oid_type(nm ## ___ARR, nm ## ___ARR + sizeof( nm ## ___ARR ) / sizeof(boost::asn1::oidindx_type));
#define ITU_T_RELOID(nm  , arr )  const boost::asn1::oidindx_type nm ## ___ARR[] ={ arr } ; \
        const boost::asn1::reloid_type  nm  = boost::asn1::reloid_type(nm ## ___ARR, nm ## ___ARR+ sizeof( nm ## ___ARR ) / sizeof(boost::asn1::oidindx_type));
#define ITU_T_OCTETS(nm  , arr )  const boost::asn1::octet_type nm ## ___ARR[] ={ arr } ; \
        const boost::asn1::octet_string  nm  = boost::asn1::octet_string(nm ## ___ARR, nm ## ___ARR+ sizeof( nm ## ___ARR ) / sizeof(boost::asn1::octet_type));
#define ITU_T_BITS(nm  , arr , un )  const boost::asn1::octet_type nm ## ___ARR[] ={ arr } ; \
        const boost::asn1::bit_string  nm  = boost::asn1::bit_string(nm ## ___ARR, nm ## ___ARR+ sizeof( nm ## ___ARR ) / sizeof(boost::asn1::octet_type), un );
#define ITU_T_TP_OID(tp, nm  , arr )  const boost::asn1::oidindx_type nm ## ___ARR[] ={ arr } ; \
        const tp nm  = boost::asn1::oid_type(nm ## ___ARR, nm ## ___ARR + sizeof( nm ## ___ARR ) / sizeof(boost::asn1::oidindx_type));
#define ITU_T_TP_RELOID(tp, nm  , arr )  const boost::asn1::oidindx_type nm ## ___ARR[] ={ arr } ; \
        const tp  nm  = boost::asn1::reloid_type(nm ## ___ARR, nm ## ___ARR+ sizeof( nm ## ___ARR ) / sizeof(boost::asn1::oidindx_type));
#define ITU_T_TP_OCTETS(tp, nm  , arr )  const boost::asn1::octet_type nm ## ___ARR[] ={ arr } ; \
        const tp  nm  = boost::asn1::octet_string(nm ## ___ARR, nm ## ___ARR+ sizeof( nm ## ___ARR ) / sizeof(boost::asn1::octet_type));
#define ITU_T_TP_BITS(tp, nm  , arr )  const boost::asn1::octet_type nm ## ___ARR[] ={ arr } ; \
        const tp  nm  = boost::asn1::bit_string(nm ## ___ARR, nm ## ___ARR+ sizeof( nm ## ___ARR ) / sizeof(boost::asn1::octet_type), un);

namespace boost {
    namespace asn1 {

        typedef std::size_t oidindx_type;

        //// OID_TYPE

        typedef boost::itu::vector<oidindx_type, 6> oid_type;

        oid_type oid_from_string(const std::string val);

        const oid_type NULL_OID = oid_type();

        std::ostream& operator<<(std::ostream& stream, const oid_type& vl);


    }

    namespace itu {

        using boost::asn1::oid_type;

        typedef int32_t encoding_rule;
        typedef encoding_rule encoding_set;



        const encoding_rule NULL_ENCODING = 0;
        const encoding_rule BER_ENCODING = 0x1;
        const encoding_rule CER_ENCODING = 0x2;
        const encoding_rule DER_ENCODING = 0x4;
        const encoding_rule PER_ALIGNED_ENCODING = 0x8;
        const encoding_rule PER_UNALIGNED_ENCODING = 0x10;
        const encoding_rule CPER_ALIGNED_ENCODING = 0x12;
        const encoding_rule CPER_UNALIGNED_ENCODING = 0x14;

        typedef oid_type transfer_syntax_type;
        typedef oid_type abstract_syntax_type;
        typedef std::set<transfer_syntax_type> transfer_syntax_set;

        const transfer_syntax_type& to_transfer_syntax(encoding_rule rule);
        encoding_rule to_encoding(const transfer_syntax_type& val);

        transfer_syntax_set to_transfer_syntax_set(encoding_set rules);
        encoding_set to_encoding_set(const transfer_syntax_set& val);

        // with encoding priority 

        encoding_rule to_encoding_rule(encoding_set val);





        using boost::asio::const_buffer;
        using boost::asio::const_buffers_1;
        using boost::asio::mutable_buffer;
        using boost::asio::mutable_buffers_1;




        typedef int contex_id_type;
        typedef int8_t octet_type;
        typedef std::vector<octet_type> octet_sequnce;
        typedef shared_ptr<octet_sequnce> octet_sequnce_ptr;
        typedef std::vector<octet_sequnce_ptr> octet_sequnce_ptr_vect;
        typedef shared_ptr<octet_sequnce_ptr_vect> octet_sequnce_ptr_vect_ptr;

        typedef std::list<mutable_buffer> mutable_sequences;
        typedef shared_ptr<mutable_sequences> mutable_sequences_ptr;
        typedef std::list<const_buffer> const_sequences;
        typedef shared_ptr<const_sequences> const_sequences_ptr;


        const octet_sequnce NULL_OCTET_SEQUENCE = octet_sequnce();
        const const_sequences NULL_CONST_SEQUENCE = const_sequences();


        void reverse_bit(octet_type& bits);
        octet_type reverse_bit_copy(const octet_type& bits);
        std::size_t split_bits_in_octets(octet_sequnce& inos, std::size_t unus1, const octet_sequnce& fromos, std::size_t unus2 = 0);
        std::size_t left_shift_bits_in_octets(octet_sequnce& vl, std::size_t shft);

    }

    namespace asn1 {


        using itu::octet_type;
        using itu::octet_sequnce;


        ///  OCTETSTRING TYPE        

        typedef boost::itu::vector<octet_type, 4> octet_string;

        std::ostream& operator<<(std::ostream& stream, const octet_string& vl);





        ///  BITSTRING TYPE       

        class bit_string : protected std::vector<octet_type> {

        public:

            typedef std::vector<octet_type> Base;

            typedef Base::reference reference;
            typedef Base::const_reference const_reference;
            typedef Base::iterator iterator;
            typedef Base::const_iterator const_iterator;
            typedef Base::size_type size_type;
            typedef Base::difference_type difference_type;
            typedef Base::value_type value_type;
            typedef Base::allocator_type allocator_type;
            typedef Base::pointer pointer;
            typedef Base::const_pointer const_pointer;
            typedef Base::reverse_iterator reverse_iterator;
            typedef Base::const_reverse_iterator const_reverse_iterator;

            bit_string() :
            Base(), unuse_(0) {
            }

            explicit
            bit_string(const allocator_type& a) :
            Base(a), unuse_(0) {
            }

            template<typename InputIterator>
            bit_string(InputIterator first, InputIterator last, std::size_t unuse = 0,
                    const allocator_type& a = allocator_type()) :
            Base(first, last, a), unuse_(unuse % 8) {
            }

            bit_string(const bit_string& x) :
            Base(static_cast<const Base&> (x)), unuse_(x.unuse_) {
            }

            bit_string(const Base& x) : Base(x), unuse_(0) {
            }

            explicit
            bit_string(size_type n, const value_type& value = value_type(),
                    std::size_t unuse = 0, const allocator_type& a = allocator_type()) :
            Base(n, value, a), unuse_(unuse % 8) {
            }

            explicit
            bit_string(const octet_sequnce& vl, std::size_t unuse = 0) :
            Base(vl.begin(), vl.end()), unuse_(unuse % 8) {
            }

            explicit
            bit_string(bool vl, std::size_t n = 0);

#if __cplusplus >= 201103L

            bit_string(bit_string&& x)
            : Base(static_cast<Base&&> (x)), unuse_(x.unuse_) {
            }

            bit_string(Base&& x)
            : Base(x), unuse_(0) {
            }

            bit_string(bit_string&& rv, const allocator_type& m)
            : Base(static_cast<Base&&> (rv), m), unuse_(rv.unuse_) {
            }

            bit_string(std::initializer_list<value_type> l, std::size_t unuse = 0,
                    const allocator_type& a = allocator_type())
            : Base(l, a), unuse_(unuse % 8) {
            }

#endif            

            bit_string& operator=(const bit_string& x) {
                Base::operator=(static_cast<const Base&> (x));
                unuse_ = x.unuse_;
                return *this;
            }


#if __cplusplus >= 201103L

            bit_string& operator=(bit_string&& x) {
                Base::operator=(static_cast<Base&&> (x));
                unuse_ = x.unuse_;
                return *this;
            }

            bit_string& operator=(std::initializer_list<value_type> l) {
                Base::operator=(l);
                unuse_ = 0;
                return *this;
            }
#endif            

            ~bit_string() {
            }

            Base& as_base() {
                return static_cast<Base&> (*this);
            }

            const Base& as_base() const {
                return static_cast<const Base&> (*this);
            }

            std::size_t unusebits() const {
                return !empty() ? (unuse_ % 8) : 0;
            }

            std::size_t unusebits(std::size_t vl);

            std::size_t sizebits() const {
                return empty() ? 0 : (size() * 8 - unusebits());
            }

            bool bit(std::size_t num) const;

            void bit(std::size_t num, bool val);

            operator bool() const;

            operator octet_sequnce() const;

            octet_sequnce as_octet_sequnce() const;

            bit_string operator~() const;

            friend bit_string operator|(const bit_string& ls, const bit_string& rs);

            friend bit_string operator&(const bit_string& ls, const bit_string& rs);

            friend bit_string operator^(const bit_string& ls, const bit_string& rs);

            friend bit_string operator+(const bit_string& ls, const bit_string& rs);

            void append(const bit_string& vl);

            void append(const octet_string& vl);

            using Base::assign;
            using Base::get_allocator;
            using Base::begin;
            using Base::end;
            using Base::rbegin;
            using Base::rend;
            using Base::size;
            using Base::max_size;
            using Base::resize;
            using Base::capacity;
            using Base::empty;
            using Base::reserve;
            using Base::operator[];
            using Base::at;
            using Base::front;
            using Base::back;
            using Base::push_back;
            using Base::pop_back;
            using Base::insert;
            using Base::erase;
            using Base::swap;
            using Base::clear;

            friend bool operator==(const bit_string& x, const bit_string& y) {
                return (static_cast<Base> (x) == static_cast<Base> (y)) && (x.unuse_ == y.unuse_);
            }

            friend bool operator!=(const bit_string& x, const bit_string& y) {
                return (static_cast<Base> (x) != static_cast<Base> (y)) || (x.unuse_ != y.unuse_);
            }

            friend bool operator<(const bit_string& x, const bit_string& y) {
                return (static_cast<Base> (x) < static_cast<Base> (y)) || (x.unuse_ < y.unuse_);
            }

            friend bool operator>(const bit_string& x, const bit_string& y) {
                return (static_cast<Base> (x) > static_cast<Base> (y)) || (x.unuse_ > y.unuse_);
            }

            friend bool operator<=(const bit_string& x, const bit_string& y) {
                return (static_cast<Base> (x) <= static_cast<Base> (y)) || (x.unuse_ <= y.unuse_);
            }

            friend bool operator>=(const bit_string& x, const bit_string& y) {
                return (static_cast<Base> (x) >= static_cast<Base> (y)) || (x.unuse_ >= y.unuse_);
            }

        private:

            std::size_t unuse_;

        };



        std::ostream& operator<<(std::ostream& stream, const bit_string& vl);



    }







    namespace itu {


        typedef asn1::bit_string bitmap_type;
        using asn1::octet_string;


        std::string binary_to_hexsequence_debug(const std::string& vl, std::size_t group = 1);

        inline static octet_sequnce buffer_to_raw(const mutable_buffer& buff, std::size_t beg = 0, std::size_t len = 0) {
            std::size_t buffsize = boost::asio::buffer_size(buff);
            len = (buffsize > beg) ? (((buffsize > (beg + len)) && len) ? len : (buffsize - beg)) : 0;
            return len ? octet_sequnce(boost::asio::buffer_cast<const octet_type*>(buff) + beg,
                    boost::asio::buffer_cast<const octet_type*>(buff) + (beg + len)) : octet_sequnce();
        }

        inline static octet_sequnce buffer_to_raw(const const_buffer& buff, std::size_t beg = 0, std::size_t len = 0) {
            std::size_t buffsize = boost::asio::buffer_size(buff);
            len = (buffsize > beg) ? (((buffsize > (beg + len)) && len) ? len : (buffsize - beg)) : 0;
            return len ? octet_sequnce(boost::asio::buffer_cast<const octet_type*>(buff) + beg,
                    boost::asio::buffer_cast<const octet_type*>(buff) + (beg + len)) : octet_sequnce();
        }

        template <typename T> octet_sequnce
        inline static inttype_to_raw(T vl) {
            return octet_sequnce(((const octet_type*) &vl), ((const octet_type*) &vl) + sizeof (T));
        }

        template <typename T>
        inline static bool raw_to_inttype(const octet_sequnce& dblk, T& vl) {
            if (sizeof (vl) > dblk.size()) return false;
            vl = *(reinterpret_cast<T*> (const_cast<octet_type*> (&dblk.front())));
            return true;
        }

        inline static int16_t endiancnv_copy(int16_t vl) {
            return (((vl >> 8) & 0xFF) | (0xFF00 & (vl << 8)));
        }

        inline static uint16_t endiancnv_copy(uint16_t vl) {
            return (((vl >> 8) & 0xFF) | (0xFF00 & (vl << 8)));
        }

        template <typename T>
        inline static T endiancnv_copy(const octet_sequnce& vl) {
            T tmp = 0;
            return raw_to_inttype<T > (vl, tmp) ? (((tmp >> 8) & 0xFF) | (0xFF00 & (tmp << 8))) : 0;
        }

        inline static void raw_back_insert(octet_sequnce& dst, const octet_sequnce& src) {
            dst.insert(dst.end(), src.begin(), src.end());
        }

        inline static void raw_front_insert(octet_sequnce& dst, const octet_sequnce& src) {
            dst.insert(dst.begin(), src.begin(), src.end());
        }

        std::size_t pop_frontlist(mutable_sequences& val, std::size_t start);

        bool splice_frontlist(mutable_sequences& val, std::size_t firstend, std::size_t secondend);

        bool find_eof(const mutable_sequences& val, mutable_sequences::const_iterator bit, std::size_t& rslt, std::size_t start = 0);

        bool row_cast(const mutable_sequences& val, mutable_sequences::const_iterator bit, octet_sequnce& raw, std::size_t start, std::size_t size);


        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////

        class base_output_coder {

        public:


            /////////////////////////////////////////////////////            

            struct data_state {

                data_state() : unuse_(0), listbuffers_(new const_sequences()),
                rows_vect_(new octet_sequnce_ptr_vect()), size_(0) {
                }

                ~data_state() {
                }

                void swap(base_output_coder& rt) {
                    std::swap(unuse_, rt.unuse_);
                    listbuffers_.swap(rt.listbuffers_);
                    rows_vect_.swap(rt.rows_vect_);
                    std::swap(size_, rt.size_);
                }

                std::size_t unuse_;
                const_sequences_ptr listbuffers_;
                octet_sequnce_ptr_vect_ptr rows_vect_;
                std::size_t size_;
            };

            typedef std::stack<data_state> state_stack_type;

            /////////////////////////////////////////////////////



            typedef const_sequences::iterator iterator_type;

            static bool __input__() {
                return false;
            }

            base_output_coder(encoding_rule rl = NULL_ENCODING) :
            rule_(rl), unuse_(0), listbuffers_(new const_sequences()),
            rows_vect_(new octet_sequnce_ptr_vect()), size_(0), canonical_(false) {
            }

            virtual ~base_output_coder() {
            }

            encoding_rule rule() const {
                return rule_;
            }

            const const_sequences& buffers() const {
                return *listbuffers_;
            }

            const_sequences& buffers() {
                return *listbuffers_;
            }

            const_sequences_ptr buffers_ptr() const {
                return listbuffers_;
            }

            const_sequences_ptr buffers_ptr() {
                return listbuffers_;
            }

            iterator_type add(const octet_sequnce& vl);

            iterator_type add(const octet_sequnce& vl, iterator_type it);

            void add(const mutable_sequences& vl);

            iterator_type last() {
                return listbuffers_->empty() ? listbuffers_->end() : (--(listbuffers_->end()));
            }

            std::size_t size(std::size_t sz = 0) const {
                return (sz < size_) ? (size_ - sz) : 0;
            }

            std::size_t load_sequence(const_sequences& val, std::size_t lim);

            virtual void clear() {
                listbuffers_->clear();
                rows_vect().clear();
                while (!state_stack_.empty())
                    state_stack_.pop();
                size_ = 0;
                unuse_=0;
            }

            bool bind(octet_sequnce& vl);

            std::size_t tie(shared_ptr<base_output_coder> source) {
                listbuffers_->insert(listbuffers_->end(), source->buffers().begin(), source->buffers().end());
                size_ += source->size();
                return source->size();
            }

            std::size_t move_from(shared_ptr<base_output_coder> source) {
                listbuffers_->insert(listbuffers_->end(), source->buffers().begin(), source->buffers().end());
                rows_vect().insert(rows_vect().begin(), source->rows_vect().begin(), source->rows_vect().end());
                std::size_t rslt = source->size();
                size_ += source->size();
                source->clear();
                return rslt;
            }

            virtual int test_id() {
                return 0;
            }

            virtual int test_class() {
                return 0;
            }

            void resetextention() {
            }

            const oid_type& transfer_syntax() const {
                return to_transfer_syntax(rule());
            }

            std::size_t unusebits() const {
                return unuse_ % 8;
            }

            std::size_t usebits() const {
                return 8 - unusebits();
            }

            void force_alighn() {
                if (unusebits())
                    unusebits(0);
            }

            bool canonical() const {
                return canonical_;
            }

        protected:

            void datastate_push();

            data_state datastate_pop();

            bool has_datastate() const;

            std::size_t unusebits(std::size_t vl) {
                return unuse_ = vl % 8;
            }

            octet_sequnce_ptr_vect& rows_vect() {
                return *rows_vect_;
            }

            const octet_sequnce_ptr_vect& rows_vect() const {
                return *rows_vect_;
            }

            encoding_rule rule_;

            /////////////////////////////////////////////////////            

            std::size_t unuse_;
            const_sequences_ptr listbuffers_;
            octet_sequnce_ptr_vect_ptr rows_vect_;
            std::size_t size_;

            /////////////////////////////////////////////////////            

            state_stack_type state_stack_;
            bool canonical_;

        };



        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////

        class base_input_coder {

        public:

            /////////////////////////////////////////////////////            

            struct data_state {

                data_state() : unuse_(0), listbuffers_(new mutable_sequences()),
                rows_vect_(new octet_sequnce_ptr_vect()), size_(0) {
                }

                ~data_state() {
                }

                void swap(base_input_coder& rt) {
                    std::swap(unuse_, rt.unuse_);
                    listbuffers_.swap(rt.listbuffers_);
                    rows_vect_.swap(rt.rows_vect_);
                    std::swap(size_, rt.size_);
                }

                std::size_t unuse_;
                mutable_sequences_ptr listbuffers_;
                octet_sequnce_ptr_vect_ptr rows_vect_;
                std::size_t size_;
            };

            typedef std::stack<data_state> state_stack_type;

            /////////////////////////////////////////////////////            

            typedef mutable_sequences::iterator iterator_type;

            static bool __input__() {
                return true;
            }

            base_input_coder(encoding_rule rl = NULL_ENCODING) :
            rule_(rl), unuse_(0), listbuffers_(new mutable_sequences()),
            rows_vect_(new octet_sequnce_ptr_vect()), size_(0) {
            }

            encoding_rule rule() const {
                return rule_;
            }

            const oid_type& transfer_syntax() const {
                return to_transfer_syntax(rule());
            }

            virtual ~base_input_coder() {
            }

            const mutable_sequences& buffers() const {
                return *listbuffers_;
            }

            mutable_sequences& buffers() {
                return *listbuffers_;
            }

            void add(const octet_sequnce& vl);

            void add(const const_sequences& vl);

            void pop_front(std::size_t sz) {
                decsize(pop_frontlist(*listbuffers_, sz));
            }

            void add_front(const octet_sequnce& vl);


            bool is_endof(std::size_t beg = 0) const;

            iterator_type last() {
                return listbuffers_->empty() ? listbuffers_->end() : (--(listbuffers_->end()));
            }

            std::size_t size(std::size_t sz) {
                return (sz < size_) ? (size_ - sz) : 0;
            }

            virtual void clear();

            std::size_t size() const {
                return size_;
            }

            bool bind(const octet_sequnce& vl);

            virtual int test_id() {
                return 0;
            };

            virtual int test_class() {
                return 0;
            };

            void resetextention() {
            }

            std::size_t unusebits() const {
                return unuse_ % 8;
            }

            std::size_t usebits() const {
                return 8 - unusebits();
            }

            void force_alighn() {
                if ((size()) && (unusebits())) {
                    pop_front(1);
                    unusebits(0);
                }
            }

        protected:

            void datastate_push();

            data_state datastate_pop();

            bool has_datastate() const;

            std::size_t unusebits(std::size_t vl) {
                return unuse_ = vl % 8;
            }

            void decsize(std::size_t sz) {
                size_ = size_ < sz ? 0 : (size_ - sz);
            }

            octet_sequnce_ptr_vect& rows_vect() {
                return *rows_vect_;
            }

            const octet_sequnce_ptr_vect& rows_vect() const {
                return *rows_vect_;
            }

            encoding_rule rule_;

            /////////////////////////////////////////////////////             

            std::size_t unuse_;
            mutable_sequences_ptr listbuffers_;
            octet_sequnce_ptr_vect_ptr rows_vect_;
            std::size_t size_;

            /////////////////////////////////////////////////////         

            state_stack_type state_stack_;

        };




        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////

        class basic_coder {

        public:

            typedef shared_ptr<base_input_coder> input_coder_ptr;
            typedef shared_ptr<base_output_coder> output_coder_ptr;

            basic_coder(base_input_coder* in, base_output_coder* out) : input_(in), output_(out) {
            }

            virtual ~basic_coder() {
            }

            input_coder_ptr in() {
                return input_;
            }

            input_coder_ptr in() const {
                return input_;
            }

            output_coder_ptr out() {
                return output_;
            }

            output_coder_ptr out() const {
                return output_;
            }

            const const_sequences& request() const {
                return output_->buffers();
            }

            std::string request_str() const;

            void request_str(const std::string& val);

            std::string respond_str() const;

            void respond_str(const std::string& val);

            virtual void clear() {
                output_->clear();
                input_->clear();
            }

            virtual void clear_input() {
                input_->clear();
            }

            virtual void clear_output() {
                output_->clear();
            }

            virtual oid_type abstract_syntax() const {
                return oid_type();
            }

            friend bool operator<(const basic_coder& ls, const basic_coder& rs) {
                return ls<rs;
            }

            encoding_rule rule() const {
                return output_->rule();
            }

            const oid_type& transfer_syntax() const {
                return output_->transfer_syntax();
            }


        protected:

            input_coder_ptr input_;
            output_coder_ptr output_;
        };


        typedef basic_coder asn_coder_type;
        typedef shared_ptr<basic_coder> asn_coder_ptr;

        template<typename INPUT_TYPE = base_input_coder, typename OUTPUT_TYPE = base_output_coder>
        class asn_coder_templ : public basic_coder {

        public:

            typedef INPUT_TYPE input_coder_type;
            typedef OUTPUT_TYPE output_coder_type;

            asn_coder_templ(const oid_type& asx = oid_type(), encoding_rule rul = NULL_ENCODING) :
            basic_coder(new input_coder_type(rul), new output_coder_type(rul)), abstract_syntax_(asx) {
            }

            asn_coder_templ(encoding_rule rul) :
            basic_coder(new input_coder_type(rul), new output_coder_type(rul)), abstract_syntax_(oid_type()) {
            }

            input_coder_type& input() {
                return *boost::static_pointer_cast<input_coder_type, base_input_coder > (input_);
            }

            const input_coder_type& input() const {
                return *boost::static_pointer_cast<input_coder_type, base_input_coder > (input_);
            }

            output_coder_type& output() {
                return *boost::static_pointer_cast<output_coder_type, base_output_coder > (output_);
            }

            const output_coder_type& output() const {
                return *boost::static_pointer_cast<output_coder_type, base_output_coder > (output_);
            }

            virtual abstract_syntax_type abstract_syntax() const {
                return abstract_syntax_;
            }


        private:

            oid_type abstract_syntax_;

        };


        /*      static inline asn_coder_ptr create_simple_data(const std::string& val) {
                   asn_coder_ptr tmp = asn_coder_ptr(new simple_trans_data());
                   tmp->request_str(val);
                   return tmp;
               }*/

        //////////////////////////////////////////////////////////////////////////////             



        std::ostream& operator<<(std::ostream& stream, const const_sequences& self);

        std::ofstream& operator<<(std::ofstream& stream, const const_sequences& self);

        std::ostream& operator<<(std::ostream& stream, const base_output_coder& vl);

        std::ofstream& operator<<(std::ofstream& stream, const base_output_coder& vl);

        std::ostream& operator<<(std::ostream& stream, const mutable_sequences& vl);

        std::ofstream& operator<<(std::ofstream& stream, const mutable_sequences& vl);



        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////            
        //   class  basic_sender_sequences 
        ///////////////////////////////////////////////////////////////////////////////////////////////////////     
        //////////////////////////////////////////////////////////////////////////////////////////////////////

        class basic_sender_sequences {

            friend class basic_itu_sequences;

        public:

            basic_sender_sequences() : bufferptr_(new const_sequences()), buffer_(*bufferptr_), size_(0) {
            }

            basic_sender_sequences(const_sequences_ptr bf) : bufferptr_(bf), buffer_(*bufferptr_), size_(0) {
            }

            basic_sender_sequences(const_sequences& bf) : buffer_(bf), size_(0) {
            }

            virtual ~basic_sender_sequences() {
            }

            const const_sequences& pop() {
                return buff();
            }

            std::size_t size(std::size_t sz = 0);

            virtual bool ready() const {
                return buff().empty();
            }

            virtual bool overflowed() const {
                return false;
            }

            virtual std::size_t constraint() const {
                return 0;
            }

        protected:

            virtual const_sequences& buff() {
                return buffer_;
            }

            virtual const_sequences& buff() const {
                return buffer_;
            }

        private:
            const_sequences_ptr bufferptr_;
            const_sequences& buffer_;
            std::size_t size_;
        };


        typedef shared_ptr<basic_sender_sequences> sender_sequnces_ptr;


        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////            
        //   class  basic_itu_sequences
        ///////////////////////////////////////////////////////////////////////////////////////////////////////     
        //////////////////////////////////////////////////////////////////////////////////////////////////////       

        class basic_itu_sequences : public basic_sender_sequences {

        public:

            basic_itu_sequences(asn_coder_ptr codr, std::size_t limit = 0) :
            basic_sender_sequences(codr->out()->buffers_ptr()), coder_(codr),
            limit_(limit), limited_(limit && (codr->out()->size() > limit)) {
            }

            virtual bool overflowed() const {
                return limited_;
            }

            virtual std::size_t constraint() const {
                return limited_ ? limit_ : coder_->out()->size();
            }

        protected:

            virtual const_sequences& buff() {
                return limited_ ? prepare() : buffer_;
            }

            virtual const_sequences& buff() const {
                return limited_ ? prepare() : buffer_;
            }

        private:

            const_sequences& prepare() const {
                if (limitedbuff_)
                    return *limitedbuff_;
                limitedbuff_ = const_sequences_ptr(new const_sequences());
                coder_->out()->load_sequence(*limitedbuff_, limit_);
                return *limitedbuff_;
            }

            asn_coder_ptr coder_;
            std::size_t limit_;
            bool limited_;
            mutable const_sequences_ptr limitedbuff_;
        };

        typedef shared_ptr<basic_itu_sequences> basic_itu_sequences_ptr;


    }

    namespace asn1 {

        const boost::asn1::oid_type NULL_ENCODING_OID = boost::asn1::oid_type();

        ITU_T_OID(BASIC_ENCODING_OID, ITU_T_VARRAY(2, 1, 1));
        ITU_T_OID(CANONICAL_ENCODING_OID, ITU_T_VARRAY(2, 1, 2, 0));
        ITU_T_OID(DISTINGUISH_ENCODING_OID, ITU_T_VARRAY(2, 1, 2, 1));
        ITU_T_OID(PER_ALIGNED_ENCODING_OID, ITU_T_VARRAY(2, 1, 3, 0, 0));
        ITU_T_OID(PER_UNALIGNED_ENCODING_OID, ITU_T_VARRAY(2, 1, 3, 0, 1));
        ITU_T_OID(CPER_ALIGNED_ENCODING_OID, ITU_T_VARRAY(2, 1, 3, 1, 0));
        ITU_T_OID(CPER_UNALIGNED_ENCODING_OID, ITU_T_VARRAY(2, 1, 1, 0, 1));

    }


} // namespace boost



#endif	/* RFC1006_H */

