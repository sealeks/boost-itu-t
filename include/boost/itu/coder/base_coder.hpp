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
#include <boost/array.hpp>
#include <boost/cstdint.hpp>
#include <boost/dynamic_bitset.hpp>

#include <boost/itu/utils/template.hpp>



namespace boost {
    namespace asn1 {

        typedef std::size_t oidindx_type;


        //// OID_TYPE

        std::vector<oidindx_type> oid_from_string(const std::string val);

        class oid_type : public boost::itu::containers::vector<oidindx_type> {

        public:

            oid_type() : boost::itu::containers::vector<oidindx_type>() {
            }

            oid_type(const std::string& vl);

            explicit oid_type(const oidindx_type * vl, std::size_t size);

            explicit oid_type(const boost::array<oidindx_type, 2 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 3 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 4 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 5 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 6 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 7 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 8 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 9 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 10 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 11 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 12 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 13 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 14 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 15 > & vl);

            explicit oid_type(const boost::array<oidindx_type, 16 > & vl);

        };

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

        const std::size_t ENCODING_RULE_MAX_BIT = 3;

        typedef oid_type transfer_syntax_type;
        typedef oid_type abstract_syntax_type;
        typedef std::set<transfer_syntax_type> transfer_syntax_set;

        const transfer_syntax_type& to_transfer_syntax(encoding_rule rule);
        encoding_rule to_encoding(const transfer_syntax_type& val);

        transfer_syntax_set to_transfer_syntax_set(encoding_set rules);
        encoding_set to_encoding_set(const transfer_syntax_set& val);

        // with encoding priority 

        inline static encoding_rule to_encoding_rule(encoding_set val) {
            std::size_t rslt = 0;
            while (rslt <= ENCODING_RULE_MAX_BIT) {
                if ((1 << rslt) & val)
                    return (1 << rslt);
                rslt++;
            }
            return NULL_ENCODING;
        }





        using boost::asio::const_buffer;
        using boost::asio::const_buffers_1;
        using boost::asio::mutable_buffer;
        using boost::asio::mutable_buffers_1;




        typedef int contex_id_type;
        typedef int8_t octet_type;
        typedef std::vector<octet_type> octet_sequnce;
        typedef boost::shared_ptr<octet_sequnce> octet_sequnce_ptr;
        typedef std::vector<octet_sequnce_ptr> vect_octet_sequnce_ptr;

        typedef std::list<mutable_buffer> mutable_sequences;
        typedef boost::shared_ptr<mutable_sequences> mutable_sequences_ptr;
        typedef std::list<const_buffer> const_sequences;
        typedef boost::shared_ptr<const_sequences> const_sequences_ptr;


        const octet_sequnce NULL_OCTET_SEQUENCE = octet_sequnce();
        const const_sequences NULL_CONST_SEQUENCE = const_sequences();


        void reverse_bit(octet_type& bits);
        octet_type reverse_bit_copy(const octet_type& bits);
        std::size_t split_bits_in_octets(octet_sequnce& inos, std::size_t unus1, const octet_sequnce& fromos, std::size_t unus2 = 0);
        std::size_t left_shift_bits_in_octets(octet_sequnce& vl, std::size_t shft);        

    }

    namespace asn1 {

        ///  BITSTRING TYPE

        using itu::octet_type;
        using itu::octet_sequnce;

        class bitstring_type : public std::vector<octet_type> {

        public:

            typedef std::vector<bool> bool_vector_type;
            typedef boost::dynamic_bitset<> dynamic_bitset_type;

            bitstring_type();

            explicit bitstring_type(uint8_t vl, std::size_t unuse = 0);

            explicit bitstring_type(uint16_t vl, std::size_t unuse = 0);

            explicit bitstring_type(uint32_t vl, std::size_t unuse = 0);

            explicit bitstring_type(uint64_t vl, std::size_t unuse = 0);

            explicit bitstring_type(int8_t vl, std::size_t unuse = 0);

            explicit bitstring_type(int16_t vl, std::size_t unuse = 0);

            explicit bitstring_type(int32_t vl, std::size_t unuse = 0);

            explicit bitstring_type(int64_t vl, std::size_t unuse = 0);

            explicit bitstring_type(const octet_sequnce& vl, std::size_t unuse = 0);

            explicit bitstring_type(const std::vector<bool>& vl);

            explicit bitstring_type(bool vl, std::size_t n = 0);

            explicit bitstring_type(const std::string& vl, std::size_t unuse = 0);

            explicit bitstring_type(bool const * const arr, std::size_t cnt);

            bitstring_type(const dynamic_bitset_type& vl) : std::vector<octet_type>() {
                construct(vl);
            };

            void insert_bitstring(const octet_sequnce& val, std::size_t unuse = 0);

            static bitstring_type create_from_string(const std::string& vl);

            std::size_t unusebits() const {
                return empty() ? 0 : (unuse_);
            }

            std::size_t unusebits(std::size_t vl);

            std::size_t sizebits() const {
                return empty() ? 0 : (size() * 8 - unusebits());
            }

            bool bit(std::size_t num) const;

            void bit(std::size_t num, bool val);

            operator bool_vector_type() const;

            operator dynamic_bitset_type() const;

            dynamic_bitset_type dynamic_bitset() const;

            operator boost::uint8_t() const;

            operator boost::uint16_t() const;

            operator boost::uint32_t() const;

            operator boost::uint64_t() const;

            operator boost::int8_t() const;

            operator boost::int16_t() const;

            operator boost::int32_t() const;

            operator boost::int64_t() const;

            operator bool() const;

            operator octet_sequnce() const;

            octet_sequnce as_octet_sequnce() const;

            bitstring_type operator~() const;

            friend bitstring_type operator|(const bitstring_type& ls, const bitstring_type& rs);

            friend bitstring_type operator&(const bitstring_type& ls, const bitstring_type& rs);

            friend bitstring_type operator^(const bitstring_type& ls, const bitstring_type& rs);

            friend bitstring_type operator+(const bitstring_type& ls, const bitstring_type& rs);



        private:

            template<typename T>
            void construct(T val, std::size_t unuse) {
                if (unuse<sizeof (T)*8) {
                    reserve(sizeof (T));
                    insert(end(), (const char*) (&val), (const char*) (&val) +(sizeof (T) - unuse / 8));
                    for (iterator it = begin(); it != end(); ++it)
                        boost::itu::reverse_bit(*it);
#ifdef BIG_ENDIAN_ARCHITECTURE
                    std::reverse(begin(), end());
#endif                 
                }
                unusebits(unuse % 8);
            }

            void construct(const std::vector<bool>& vl);

            template<typename T>
            T return_int() const {
                if (!empty()) {
                    std::vector<octet_type> tmp(begin(), end());
                    tmp.back() &= ('\xFF' << unusebits());
                    for (std::vector<octet_type>::iterator it = tmp.begin(); it != tmp.end(); ++it)
                        boost::itu::reverse_bit(*it);
                    if (tmp.size()<sizeof (T))
                        tmp.insert(tmp.end(), sizeof (T) - size(), 0);
#ifdef BIG_ENDIAN_ARCHITECTURE
                    std::reverse(tmp.begin(), tmp.end());
#endif                      
                    return *reinterpret_cast<T*> (&tmp[0]);
                }
                return 0;
            }

            void construct(const dynamic_bitset_type& vl);

            std::size_t unuse_;


        };


        std::ostream& operator<<(std::ostream& stream, const bitstring_type& vl);


        ///  OCTETSTRING TYPE           

        class octetstring_type : public std::vector<octet_type> {

        public:

            octetstring_type() : std::vector<octet_type>() {
            }

            explicit octetstring_type(const octet_sequnce& vl) : std::vector<octet_type>(vl.begin(), vl.end()) {
            }

            octetstring_type(const std::string& vl) : std::vector<octet_type>(vl.begin(), vl.end()) {
            }

            operator octet_sequnce() const;

            octet_sequnce as_octet_sequnce() const;
            //operator octet_sequnce() const{
            //     return  *this;}   
        };


        std::ostream& operator<<(std::ostream& stream, const octetstring_type& vl);
    }




    namespace itu {


        typedef asn1::bitstring_type bitmap_type;
        using asn1::octetstring_type;


        std::string binary_to_hexsequence_debug(const std::string& vl);

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


            typedef const_sequences::iterator iterator_type;

            static bool __input__() {
                return false;
            }

            base_output_coder(encoding_rule rl = NULL_ENCODING) : unuse_(0), listbuffers_(new const_sequences()), size_(0) {
            }

            virtual ~base_output_coder() {
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

            void add_bitmap(const bitmap_type & vl, bool alighn = false);

            void add_octets(const octet_sequnce& vl, bool alighn = false);

            void add_octets(const octetstring_type & vl, bool alighn = false);

            iterator_type last() {
                return listbuffers_->empty() ? listbuffers_->end() : (--(listbuffers_->end()));
            }

            std::size_t size(std::size_t sz = 0) const {
                return (sz < size_) ? (size_ - sz) : 0;
            }

            std::size_t load_sequence(const_sequences& val, std::size_t lim);

            virtual void clear() {
                listbuffers_->clear();
                rows_vect.clear();
                size_ = 0;
            }

            bool bind(octet_sequnce& vl);

            std::size_t tie(boost::shared_ptr<base_output_coder> source) {
                listbuffers_->insert(listbuffers_->end(), source->buffers().begin(), source->buffers().end());
                size_ += source->size();
                return source->size();
            }

            std::size_t move_from(boost::shared_ptr<base_output_coder> source) {
                listbuffers_->insert(listbuffers_->end(), source->buffers().begin(), source->buffers().end());
                rows_vect.insert(rows_vect.begin(), source->rows_vect.begin(), source->rows_vect.end());
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

            virtual encoding_rule rule() const {
                return NULL_ENCODING;
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
            
        protected:

            std::size_t unusebits(std::size_t vl) {
                return unuse_ = vl % 8;
            }


        private:

            std::size_t unuse_;
            const_sequences_ptr listbuffers_;
            vect_octet_sequnce_ptr rows_vect;
            std::size_t size_;
        };



        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////

        class base_input_coder {

        public:

            typedef mutable_sequences::iterator iterator_type;

            static bool __input__() {
                return true;
            }

            base_input_coder() : unuse_(0), listbuffers_(new mutable_sequences()), size_(0) {
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

            std::size_t get_bitmap(std::size_t sz, bitmap_type& vl, bool alighn = false);

            std::size_t get_octets(std::size_t sz, octet_sequnce& vl, bool alighn = false);

            std::size_t pop_bitmap(std::size_t sz, bool alighn = false);

            std::size_t pop_octets(std::size_t sz, bool alighn = false);

            std::size_t get_pop_bitmap(std::size_t sz, bitmap_type& vl, bool alighn = false);

            std::size_t get_pop_octets(std::size_t sz, octet_sequnce& vl, bool alighn = false);

            bitmap_type get_pop_bmp(std::size_t sz, bool alighn = false);

            octet_sequnce get_pop_octs(std::size_t sz, bool alighn = false);         
            

            
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

        protected:

            std::size_t unusebits(std::size_t vl) {
                return unuse_ = vl % 8;
            }

            void decsize(std::size_t sz) {
                size_ = size_ < sz ? 0 : (size_ - sz);
                //std::cout << "decsize IARCHVE size:"  << size_  << std::endl;
            }

        private:

            std::size_t unuse_;
            mutable_sequences_ptr listbuffers_;
            vect_octet_sequnce_ptr rows_vect;
            std::size_t size_;

        };




        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////

        class basic_coder {

        public:

            typedef boost::shared_ptr<base_input_coder> input_coder_ptr;
            typedef boost::shared_ptr<base_output_coder> output_coder_ptr;

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



        typedef boost::shared_ptr<basic_coder> asn_coder_ptr;

        template<typename INPUT_TYPE = base_input_coder, typename OUTPUT_TYPE = base_output_coder>
        class asn_coder_templ : public basic_coder {

        public:

            typedef INPUT_TYPE input_coder_type;
            typedef OUTPUT_TYPE output_coder_type;

            asn_coder_templ(const oid_type& asx = oid_type(), encoding_rule rul = NULL_ENCODING) :
            basic_coder(new input_coder_type(), new output_coder_type(rul)), abstract_syntax_(asx) {
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


        typedef boost::shared_ptr<basic_sender_sequences> sender_sequnces_ptr;


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

        typedef boost::shared_ptr<basic_itu_sequences> basic_itu_sequences_ptr;


    }

    namespace asn1 {

        extern const boost::asn1::oid_type NULL_ENCODING_OID;

        extern const boost::asn1::oid_type BASIC_ENCODING_OID;

        extern const boost::asn1::oid_type CANONICAL_ENCODING_OID;

        extern const boost::asn1::oid_type DISTINGUISH_ENCODING_OID;

    }


} // namespace boost



#endif	/* RFC1006_H */

