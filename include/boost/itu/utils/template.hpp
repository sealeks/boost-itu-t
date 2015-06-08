//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_TEMLATE_H_
#define	_ITU_TEMLATE_H_

#include <list>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <string>

#include <boost/itu/asn1/utf8.hpp>

namespace boost {
    namespace itu {

        template<typename T, std::size_t ID = 0, typename Alloc = std::allocator<T > >
        class vector : protected std::vector<T, Alloc> {

        private:

            static std::size_t get__id() {
                return ID;
            }

        public:

            typedef std::vector<T, Alloc> Base;

            typedef typename Base::reference reference;
            typedef typename Base::const_reference const_reference;
            typedef typename Base::iterator iterator;
            typedef typename Base::const_iterator const_iterator;
            typedef typename Base::size_type size_type;
            typedef typename Base::difference_type difference_type;
            typedef typename Base::value_type value_type;
            typedef typename Base::allocator_type allocator_type;
            typedef typename Base::pointer pointer;
            typedef typename Base::const_pointer const_pointer;
            typedef typename Base::reverse_iterator reverse_iterator;
            typedef typename Base::const_reverse_iterator const_reverse_iterator;

            vector() :
            Base() {
            }

            explicit
            vector(const allocator_type& a) :
            Base(a) {
            }

            template<typename InputIterator>
            vector(InputIterator first, InputIterator last,
                    const allocator_type& a = allocator_type()) : Base(first, last, a) {
            }

            vector(const vector& x) : Base(static_cast<const Base&> (x)) {
            }

            vector(const Base& x) : Base(x) {
            }

            explicit
            vector(size_type n, const value_type& value = value_type(), const allocator_type& a = allocator_type()) :
            Base(n, value, a) {
            }

#if __cplusplus >= 201103L

            vector(vector&& x)
            : Base(static_cast<Base&&> (x)) {
            }

            vector(Base&& x)
            : Base(x) {
            }

            explicit
            vector(size_type n, const allocator_type& a) :
            Base(n, a) {
            }

            vector(const vector& x, const allocator_type& a) :
            Base(static_cast<const Base&> (x), a) {
            }

            vector(vector&& rv, const allocator_type& m)
            : Base(static_cast<Base&&> (rv), m) {
            }

            vector(std::initializer_list<value_type> l,
                    const allocator_type& a = allocator_type())
            : Base(l, a) {
            }

#endif            

            vector& operator=(const vector& x) {
                Base::operator=(static_cast<const Base&> (x));
                return *this;
            }

            /*vector& operator=(const Base& x) {
                Base::operator=(x);
                return *this;
            }*/

#if __cplusplus >= 201103L

            vector& operator=(vector&& x) {
                Base::operator=(static_cast<Base&&> (x));
                return *this;
            }

            /*vector& operator=(Base&& x) {
                Base::operator=(x);
                return *this;
            }*/

            vector& operator=(std::initializer_list<value_type> l) {
                Base::operator=(l);
                return *this;
            }
#endif            

            ~vector() {
            }

            Base& as_base() {
                return static_cast<Base&> (*this);
            }

            const Base& as_base() const {
                return static_cast<const Base&> (*this);
            }

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

            friend bool operator==(const vector& x, const vector& y) {
                return static_cast<Base> (x) == static_cast<Base> (y);
            }

            friend bool operator!=(const vector& x, const vector& y) {
                return static_cast<Base> (x) != static_cast<Base> (y);
            }

            friend bool operator<(const vector& x, const vector& y) {
                return static_cast<Base> (x) < static_cast<Base> (y);
            }

            friend bool operator>(const vector& x, const vector& y) {
                return static_cast<Base> (x) > static_cast<Base> (y);
            }

            friend bool operator<=(const vector& x, const vector& y) {
                return static_cast<Base> (x) <= static_cast<Base> (y);
            }

            friend bool operator>=(const vector& x, const vector& y) {
                return static_cast<Base> (x) >= static_cast<Base> (y);
            }

        };


    }

    namespace asn1 {


        ///////////////////////////////////////////////////////////////////////
        //  sequence_of
        ///////////////////////////////////////////////////////////////////////

        template<typename T, typename Alloc = std::allocator<T > >
        class sequence_of : protected std::vector<T, Alloc> {

        public:

            typedef std::vector<T, Alloc> Base;

            typedef typename Base::reference reference;
            typedef typename Base::const_reference const_reference;
            typedef typename Base::iterator iterator;
            typedef typename Base::const_iterator const_iterator;
            typedef typename Base::size_type size_type;
            typedef typename Base::difference_type difference_type;
            typedef typename Base::value_type value_type;
            typedef typename Base::allocator_type allocator_type;
            typedef typename Base::pointer pointer;
            typedef typename Base::const_pointer const_pointer;
            typedef typename Base::reverse_iterator reverse_iterator;
            typedef typename Base::const_reverse_iterator const_reverse_iterator;

            sequence_of() :
            Base() {
            }

            explicit
            sequence_of(const allocator_type& a) :
            Base(a) {
            }

            template<typename InputIterator>
            sequence_of(InputIterator first, InputIterator last,
                    const allocator_type& a = allocator_type()) : Base(first, last, a) {
            }

            sequence_of(const sequence_of& x) : Base(static_cast<const Base&> (x)) {
            }

            /*sequence_of(const Base& x) : Base(x) {
            }*/

            explicit
            sequence_of(size_type n, const value_type& value = value_type(), const allocator_type& a = allocator_type()) :
            Base(n, value, a) {
            }

#if __cplusplus >= 201103L

            sequence_of(sequence_of&& x)
            : Base(static_cast<Base&&> (x)) {
            }

            /*sequence_of(Base&& x)
            : Base(x) {
            }*/

            explicit
            sequence_of(size_type n, const allocator_type& a) :
            Base(n, a) {
            }

            sequence_of(const sequence_of& x, const allocator_type& a) :
            Base(static_cast<const Base&> (x), a) {
            }

            sequence_of(sequence_of&& rv, const allocator_type& m)
            : Base(static_cast<Base&&> (rv), m) {
            }

            sequence_of(std::initializer_list<value_type> l,
                    const allocator_type& a = allocator_type())
            : Base(l, a) {
            }

#endif            

            sequence_of& operator=(const sequence_of& x) {
                Base::operator=(static_cast<const Base&> (x));
                return *this;
            }

            /*sequence_of& operator=(const Base& x) {
                Base::operator=(x);
                return *this;
            }*/

#if __cplusplus >= 201103L

            sequence_of& operator=(sequence_of&& x) {
                Base::operator=(static_cast<Base&&> (x));
                return *this;
            }

            /*sequence_of& operator=(Base&& x) {
                Base::operator=(x);
                return *this;
            }*/

            sequence_of& operator=(std::initializer_list<value_type> l) {
                Base::operator=(l);
                return *this;
            }
#endif            

            ~sequence_of() {
            }

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

            friend bool operator==(const sequence_of& x, const sequence_of& y) {
                return static_cast<Base> (x) == static_cast<Base> (y);
            }

            friend bool operator!=(const sequence_of& x, const sequence_of& y) {
                return static_cast<Base> (x) != static_cast<Base> (y);
            }

            friend bool operator<(const sequence_of& x, const sequence_of& y) {
                return static_cast<Base> (x) < static_cast<Base> (y);
            }

            friend bool operator>(const sequence_of& x, const sequence_of& y) {
                return static_cast<Base> (x) > static_cast<Base> (y);
            }

            friend bool operator<=(const sequence_of& x, const sequence_of& y) {
                return static_cast<Base> (x) <= static_cast<Base> (y);
            }

            friend bool operator>=(const sequence_of& x, const sequence_of& y) {
                return static_cast<Base> (x) >= static_cast<Base> (y);
            }

        };






        ///////////////////////////////////////////////////////////////////////
        //  set_of
        ///////////////////////////////////////////////////////////////////////

        template<typename T, typename Alloc = std::allocator<T > >
        class set_of : protected std::vector<T, Alloc> {

        public:

            typedef std::vector<T, Alloc> Base;

            typedef typename Base::reference reference;
            typedef typename Base::const_reference const_reference;
            typedef typename Base::iterator iterator;
            typedef typename Base::const_iterator const_iterator;
            typedef typename Base::size_type size_type;
            typedef typename Base::difference_type difference_type;
            typedef typename Base::value_type value_type;
            typedef typename Base::allocator_type allocator_type;
            typedef typename Base::pointer pointer;
            typedef typename Base::const_pointer const_pointer;
            typedef typename Base::reverse_iterator reverse_iterator;
            typedef typename Base::const_reverse_iterator const_reverse_iterator;

            set_of() :
            Base() {
            }

            explicit
            set_of(const allocator_type& a) :
            Base(a) {
            }

            template<typename InputIterator>
            set_of(InputIterator first, InputIterator last,
                    const allocator_type& a = allocator_type()) : Base(first, last, a) {
            }

            set_of(const set_of& x) : Base(static_cast<const Base&> (x)) {
            }

            /*set_of(const Base& x) : Base(x) {
            }*/

            explicit
            set_of(size_type n, const value_type& value = value_type(), const allocator_type& a = allocator_type()) :
            Base(n, value, a) {
            }

#if __cplusplus >= 201103L

            set_of(set_of&& x)
            : Base(static_cast<Base&&> (x)) {
            }

            /*set_of(Base&& x)
            : Base(x) {
            }*/

            explicit
            set_of(size_type n, const allocator_type& a) :
            Base(n, a) {
            }

            set_of(const set_of& x, const allocator_type& a) :
            Base(static_cast<const Base&> (x), a) {
            }

            set_of(set_of&& rv, const allocator_type& m)
            : Base(static_cast<Base&&> (rv), m) {
            }

            set_of(std::initializer_list<value_type> l,
                    const allocator_type& a = allocator_type())
            : Base(l, a) {
            }

#endif            

            set_of& operator=(const set_of& x) {
                Base::operator=(static_cast<const Base&> (x));
                return *this;
            }

            /*set_of& operator=(const Base& x) {
                Base::operator=(x);
                return *this;
            }*/

#if __cplusplus >= 201103L

            set_of& operator=(set_of&& x) {
                Base::operator=(static_cast<Base&&> (x));
                return *this;
            }

            /*set_of& operator=(Base&& x) {
                Base::operator=(x);
                return *this;
            }*/

            set_of& operator=(std::initializer_list<value_type> l) {
                Base::operator=(l);
                return *this;
            }
#endif            

            ~set_of() {
            }

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

            friend bool operator==(const set_of& x, const set_of& y) {
                return static_cast<Base> (x) == static_cast<Base> (y);
            }

            friend bool operator!=(const set_of& x, const set_of& y) {
                return static_cast<Base> (x) != static_cast<Base> (y);
            }

            friend bool operator<(const set_of& x, const set_of& y) {
                return static_cast<Base> (x) < static_cast<Base> (y);
            }

            friend bool operator>(const set_of& x, const set_of& y) {
                return static_cast<Base> (x) > static_cast<Base> (y);
            }

            friend bool operator<=(const set_of& x, const set_of& y) {
                return static_cast<Base> (x) <= static_cast<Base> (y);
            }

            friend bool operator>=(const set_of& x, const set_of& y) {
                return static_cast<Base> (x) >= static_cast<Base> (y);
            }

        };




        ///////////////////////////////////////////////////////////////////////
        //  smpl_string
        ///////////////////////////////////////////////////////////////////////        

        template<std::size_t ID = 0 >
        class smpl_string : protected std::string {

        private:

            static std::size_t get__id() {
                return ID;
            }

        public:

            typedef std::string Base;

            typedef typename Base::traits_type traits_type;
            typedef typename Base::value_type value_type;
            typedef typename Base::allocator_type allocator_type;
            typedef typename Base::size_type size_type;
            typedef typename Base::difference_type difference_type;
            typedef typename Base::reference reference;
            typedef typename Base::const_reference const_reference;
            typedef typename Base::pointer pointer;
            typedef typename Base::const_pointer const_pointer;
            typedef typename Base::iterator iterator;
            typedef typename Base::const_iterator const_iterator;
            typedef typename Base::const_reverse_iterator const_reverse_iterator;
            typedef typename Base::reverse_iterator reverse_iterator;

            smpl_string() : Base() {
            }

            explicit
            smpl_string(const allocator_type& a) : Base(a) {
            }

            smpl_string(const Base& str) : Base(str) {
            }

            smpl_string(const Base& str, size_type pos,
                    size_type n = npos) : Base(str, pos, n) {
            }

            smpl_string(const Base& str, size_type pos,
                    size_type n, const allocator_type& a) : Base(str, pos, n, a) {
            }

            smpl_string(const smpl_string& str) : Base(static_cast<const Base&> (str)) {
            }

            smpl_string(const smpl_string& str, size_type pos,
                    size_type n = npos) : Base(static_cast<const Base&> (str), pos, n) {
            }

            smpl_string(const smpl_string& str, size_type pos,
                    size_type n, const allocator_type& a) : Base(static_cast<const Base&> (str), pos, n, a) {
            }

            smpl_string(const value_type* s, size_type n,
                    const allocator_type& a = allocator_type()) : Base(s, n, a) {
            }

            smpl_string(const value_type* s,
                    const allocator_type& a = allocator_type()) : Base(s, a) {
            }

            smpl_string(size_type n, value_type c,
                    const allocator_type& a = allocator_type()) : Base(n, c, a) {
            }

            template<class InputIterator>
            smpl_string(InputIterator beg, InputIterator end,
                    const allocator_type& a = allocator_type()) : Base(beg, end, a) {
            }

#if __cplusplus >= 201103L            

            smpl_string(smpl_string&& str)
            : Base(static_cast<Base&&> (str)) {
            }

            smpl_string(Base&& str)
            : Base(str) {
            }

            smpl_string(std::initializer_list<value_type> l, const allocator_type& a = allocator_type())
            : Base(l, a) {
            }

#endif           

            ~smpl_string() {
            }

            smpl_string& operator=(const smpl_string& str) {
                Base::operator=(static_cast<const Base&> (str));
                return *this;
            }

            smpl_string& operator=(const Base& str) {
                Base::operator=(str);
                return *this;
            }

            smpl_string& operator=(const value_type* s) {
                Base::operator=(s);
                return *this;
            }

            smpl_string& operator=(value_type c) {
                Base::operator=(c);
                return *this;
            }

#if __cplusplus >= 201103L

            smpl_string& operator=(smpl_string&& str) {
                Base::operator=(static_cast<Base&&> (str));
                return *this;
            }

            smpl_string& operator=(Base&& str) {
                Base::operator=(str);
                return *this;
            }

            basic_string& operator=(std::initializer_list<value_type> l) {
                Base::operator=(l);
                return *this;
            }

#endif        

            Base& as_base() {
                return static_cast<Base&> (*this);
            }

            const Base& as_base() const {
                return static_cast<const Base&> (*this);
            }

            using Base::npos;

            using Base::append;
            using Base::assign;
            using Base::at;
            using Base::begin;
            using Base::c_str;
            using Base::capacity;
            using Base::clear;
            using Base::compare;
            using Base::copy;
            using Base::data;
            using Base::end;
            using Base::erase;
            using Base::empty;
            using Base::find;
            using Base::find_first_not_of;
            using Base::find_first_of;
            using Base::find_last_not_of;
            using Base::find_last_of;
            using Base::get_allocator;
            using Base::insert;
            using Base::length;
            using Base::max_size;
            using Base::operator[];
            using Base::push_back;
            using Base::rbegin;
            using Base::rend;
            using Base::replace;
            using Base::reserve;
            using Base::resize;
            using Base::rfind;
            using Base::size;
            using Base::substr;
            using Base::swap;

            friend bool operator==(const smpl_string& x, const smpl_string& y) {
                return static_cast<const Base&> (x) == static_cast<const Base&> (y);
            }

            friend bool operator!=(const smpl_string& x, const smpl_string& y) {
                return static_cast<const Base&> (x) != static_cast<const Base&> (y);
            }

            friend bool operator<(const smpl_string& x, const smpl_string& y) {
                return static_cast<const Base&> (x) < static_cast<const Base&> (y);
            }

            friend bool operator>(const smpl_string& x, const smpl_string& y) {
                return static_cast<const Base&> (x) > static_cast<const Base&> (y);
            }

            friend bool operator<=(const smpl_string& x, const smpl_string& y) {
                return static_cast<const Base&> (x) <= static_cast<const Base&> (y);
            }

            friend bool operator>=(const smpl_string& x, const smpl_string& y) {
                return static_cast<const Base&> (x) >= static_cast<const Base&> (y);
            }

            friend smpl_string operator+(const smpl_string& x, const smpl_string& y) {
                return static_cast<const Base&> (x) + static_cast<const Base&> (y);
            }

            friend smpl_string operator+(const smpl_string& x, const std::string& y) {
                return static_cast<const Base&> (x) + y;
            }

            friend smpl_string operator+(const std::string& x, const smpl_string& y) {
                return x + static_cast<const Base&> (y);
            }

        };


        ///////////////////////////////////////////////////////////////////////
        //  utf8_string
        ///////////////////////////////////////////////////////////////////////        

        class utf8_string : protected std::string {

        public:

            typedef std::string Base;
            typedef std::wstring WBase;


            typedef Base::traits_type traits_type;
            typedef Base::value_type value_type;
            typedef Base::allocator_type allocator_type;
            typedef Base::size_type size_type;
            typedef Base::difference_type difference_type;
            typedef Base::reference reference;
            typedef Base::const_reference const_reference;
            typedef Base::pointer pointer;
            typedef Base::const_pointer const_pointer;
            typedef Base::iterator iterator;
            typedef Base::const_iterator const_iterator;
            typedef Base::const_reverse_iterator const_reverse_iterator;
            typedef Base::reverse_iterator reverse_iterator;

            typedef WBase::value_type wvalue_type;
            typedef WBase::iterator witerator;
            typedef WBase::const_iterator wconst_iterator;
            typedef WBase::const_reverse_iterator wconst_reverse_iterator;
            typedef WBase::reverse_iterator wreverse_iterator;

        private:

            static Base to_base(const WBase& vl) {
                return wstr_to_utf8(vl);
            }

            static Base to_base(const wvalue_type* vl) {
                return wstr_to_utf8(vl);
            }

            static WBase to_Wbase(const Base& vl) {
                return utf8_to_wstr(vl);
            }

        public:

            utf8_string() : Base() {
            }

            explicit
            utf8_string(const allocator_type& a) : Base(a) {
            }

            utf8_string(const Base& str) : Base(str) {
            }

            utf8_string(const Base& str, size_type pos,
                    size_type n = npos) : Base(str, pos, n) {
            }

            utf8_string(const Base& str, size_type pos,
                    size_type n, const allocator_type& a) : Base(str, pos, n, a) {
            }

            utf8_string(const WBase& str, size_type pos,
                    size_type n = npos) : Base(to_base(WBase(str, pos, n))) {
            }

            utf8_string(const WBase& str, size_type pos,
                    size_type n, const allocator_type& a) : Base(to_base(WBase(str, pos, n, a))) {
            }

            utf8_string(const WBase& str) : Base(to_base(str)) {
            }

            utf8_string(const utf8_string& str) : Base(static_cast<const Base&> (str)) {
            }

            utf8_string(const utf8_string& str, size_type pos,
                    size_type n = npos) : Base(static_cast<const Base&> (str), pos, n) {
            }

            utf8_string(const utf8_string& str, size_type pos,
                    size_type n, const allocator_type& a) : Base(static_cast<const Base&> (str), pos, n, a) {
            }

            utf8_string(const value_type* s, size_type n,
                    const allocator_type& a = allocator_type()) : Base(s, n, a) {
            }

            utf8_string(const value_type* s,
                    const allocator_type& a = allocator_type()) : Base(s, a) {
            }

            utf8_string(size_type n, value_type c,
                    const allocator_type& a = allocator_type()) : Base(n, c, a) {
            }

            utf8_string(const wvalue_type* s, size_type n,
                    const allocator_type& a = allocator_type()) : Base(to_base(WBase(s, n, a))) {
            }

            utf8_string(const wvalue_type* s,
                    const allocator_type& a = allocator_type()) : Base(to_base(WBase(s, a))) {
            }

            utf8_string(size_type n, wvalue_type c,
                    const allocator_type& a = allocator_type()) : Base(to_base(WBase(n, c, a))) {
            }

            template<class InputIterator>
            utf8_string(InputIterator beg, InputIterator end,
                    const allocator_type& a = allocator_type()) : Base(beg, end, a) {
            }

            utf8_string(wconst_iterator beg, wconst_iterator end,
                    const allocator_type& a = allocator_type()) : Base(to_base(WBase(beg, end, a))) {
            }

#if __cplusplus >= 201103L            

            utf8_string(utf8_string&& str)
            : Base(static_cast<Base&&> (str)) {
            }

            utf8_string(Base&& str)
            : Base(str) {
            }

            /*utf8_string(WBase&& wstr)
            : Base(to_base(WBase(wstr))) {
            }*/

            utf8_string(std::initializer_list<value_type> l, const allocator_type& a = allocator_type())
            : Base(l, a) {
            }

            utf8_string(std::initializer_list<wvalue_type> l, const allocator_type& a = allocator_type())
            : Base(to_base(WBase(l, a))) {
            }

#endif           

            ~utf8_string() {
            }

            utf8_string& operator=(const utf8_string& str) {
                Base::operator=(static_cast<const Base&> (str));
                return *this;
            }

            utf8_string& operator=(const Base& str) {
                Base::operator=(str);
                return *this;
            }

            utf8_string& operator=(const value_type* s) {
                Base::operator=(s);
                return *this;
            }

            utf8_string& operator=(value_type c) {
                Base::operator=(c);
                return *this;
            }

#if __cplusplus >= 201103L

            utf8_string& operator=(utf8_string&& str) {
                Base::operator=(static_cast<Base&&> (str));
                return *this;
            }

            utf8_string& operator=(Base&& str) {
                Base::operator=(str);
                return *this;
            }

            basic_string& operator=(std::initializer_list<value_type> l) {
                Base::operator=(l);
                return *this;
            }

#endif        

            Base& as_base() {
                return static_cast<Base&> (*this);
            }

            const Base& as_base() const {
                return static_cast<const Base&> (*this);
            }

            Base as_string() const {
                return static_cast<const Base&> (*this);
            }

            WBase as_wstring() const {
                return well_formed() ? utf8_to_wstr(*this) : std::wstring();
            }

            bool well_formed() const {
                return check_utf8(*this);
            }

            operator std::wstring() const {
                return as_wstring();
            }


            using Base::npos;

            using Base::append;
            using Base::assign;
            using Base::at;
            using Base::begin;
            using Base::c_str;
            using Base::capacity;
            using Base::clear;
            using Base::compare;
            using Base::copy;
            using Base::data;
            using Base::end;
            using Base::erase;
            using Base::empty;
            using Base::find;
            using Base::find_first_not_of;
            using Base::find_first_of;
            using Base::find_last_not_of;
            using Base::find_last_of;
            using Base::get_allocator;
            using Base::insert;
            using Base::length;
            using Base::max_size;
            using Base::operator[];
            using Base::push_back;
            using Base::rbegin;
            using Base::rend;
            using Base::replace;
            using Base::reserve;
            using Base::resize;
            using Base::rfind;
            using Base::size;
            using Base::substr;
            using Base::swap;

            friend bool operator==(const utf8_string& x, const utf8_string& y) {
                return static_cast<const Base&> (x) == static_cast<const Base&> (y);
            }

            friend bool operator!=(const utf8_string& x, const utf8_string& y) {
                return static_cast<const Base&> (x) != static_cast<const Base&> (y);
            }

            friend bool operator<(const utf8_string& x, const utf8_string& y) {
                return static_cast<const Base&> (x) < static_cast<const Base&> (y);
            }

            friend bool operator>(const utf8_string& x, const utf8_string& y) {
                return static_cast<const Base&> (x) > static_cast<const Base&> (y);
            }

            friend bool operator<=(const utf8_string& x, const utf8_string& y) {
                return static_cast<const Base&> (x) <= static_cast<const Base&> (y);
            }

            friend bool operator>=(const utf8_string& x, const utf8_string& y) {
                return static_cast<const Base&> (x) >= static_cast<const Base&> (y);
            }

            friend utf8_string operator+(const utf8_string& x, const utf8_string& y) {
                return static_cast<const Base&> (x) + static_cast<const Base&> (y);
            }

            friend utf8_string operator+(const utf8_string& x, const std::string& y) {
                return static_cast<const Base&> (x) + y;
            }

            friend utf8_string operator+(const std::string& x, const utf8_string& y) {
                return x + static_cast<const Base&> (y);
            }

        };






        ///////////////////////////////////////////////////////////////////////
        //  smpl_wstring
        ///////////////////////////////////////////////////////////////////////        

        template<std::size_t ID = 0 >
        class smpl_wstring : public std::wstring {

        private:

            static std::size_t get__id() {
                return ID;
            }

        public:

            typedef std::wstring Base;
            typedef std::string LBase;

            typedef typename Base::traits_type traits_type;
            typedef typename Base::value_type value_type;
            typedef typename Base::allocator_type allocator_type;
            typedef typename Base::size_type size_type;
            typedef typename Base::difference_type difference_type;
            typedef typename Base::reference reference;
            typedef typename Base::const_reference const_reference;
            typedef typename Base::pointer pointer;
            typedef typename Base::const_pointer const_pointer;
            typedef typename Base::iterator iterator;
            typedef typename Base::const_iterator const_iterator;
            typedef typename Base::const_reverse_iterator const_reverse_iterator;
            typedef typename Base::reverse_iterator reverse_iterator;

            typedef LBase::value_type lvalue_type;
            typedef LBase::iterator literator;
            typedef LBase::const_iterator lconst_iterator;
            typedef LBase::const_reverse_iterator lconst_reverse_iterator;
            typedef LBase::reverse_iterator lreverse_iterator;

            static Base to_base(const LBase& vl) {
                return utf8_to_wstr(vl);
            }

            static Base to_base(const lvalue_type* vl) {
                return utf8_to_wstr(vl);
            }

            static LBase to_Lbase(const Base& vl) {
                return wstr_to_utf8(vl);
            }

            smpl_wstring() : Base() {
            }

            explicit
            smpl_wstring(const allocator_type& a) : Base(a) {
            }

            smpl_wstring(const Base& str) : Base(str) {
            }

            //  from utf-8

            smpl_wstring(const LBase& str) : Base(to_base(str)) {
            }

            smpl_wstring(const Base& str, size_type pos,
                    size_type n = npos) : Base(str, pos, n) {
            }

            smpl_wstring(const Base& str, size_type pos,
                    size_type n, const allocator_type& a) : Base(str, pos, n, a) {
            }

            smpl_wstring(const smpl_wstring& str) : Base(static_cast<const Base&> (str)) {
            }

            smpl_wstring(const smpl_wstring& str, size_type pos,
                    size_type n = npos) : Base(static_cast<const Base&> (str), pos, n) {
            }

            smpl_wstring(const smpl_wstring& str, size_type pos,
                    size_type n, const allocator_type& a) : Base(static_cast<const Base&> (str), pos, n, a) {
            }

            smpl_wstring(const value_type* s, size_type n,
                    const allocator_type& a = allocator_type()) : Base(s, n, a) {
            }

            smpl_wstring(const lvalue_type* s, size_type n,
                    const allocator_type& a = allocator_type()) : Base(to_base(LBase(s, n, a))) {
            }

            smpl_wstring(const value_type* s,
                    const allocator_type& a = allocator_type()) : Base(s, a) {
            }

            smpl_wstring(const lvalue_type* s,
                    const allocator_type& a = allocator_type()) : Base(to_base(LBase(s, a))) {
            }

            smpl_wstring(size_type n, value_type c,
                    const allocator_type& a = allocator_type()) : Base(n, c, a) {
            }

            template<class InputIterator>
            smpl_wstring(InputIterator beg, InputIterator end,
                    const allocator_type& a = allocator_type()) : Base(beg, end, a) {
            }

            smpl_wstring(lconst_iterator beg, lconst_iterator end,
                    const allocator_type& a = allocator_type()) : Base(to_base(LBase(beg, end, a))) {
            }

#if __cplusplus >= 201103L            

            smpl_wstring(smpl_wstring&& str)
            : Base(static_cast<Base&&> (str)) {
            }

            smpl_wstring(Base&& str)
            : Base(str) {
            }

            smpl_wstring(LBase&& str)
            : Base(to_base(str)) {
            }

            smpl_wstring(std::initializer_list<value_type> l, const allocator_type& a = allocator_type())
            : Base(l, a) {
            }

            smpl_wstring(std::initializer_list<lvalue_type> l, const allocator_type& a = allocator_type())
            : Base(to_base(LBase(l, a))) {
            }

#endif           

            ~smpl_wstring() {
            }

            smpl_wstring& operator=(const smpl_wstring& str) {
                Base::operator=(static_cast<const Base&> (str));
                return *this;
            }

            smpl_wstring& operator=(const Base& str) {
                Base::operator=(str);
                return *this;
            }

            smpl_wstring& operator=(const LBase& str) {
                Base::operator=(to_base(str));
                return *this;
            }

            smpl_wstring& operator=(const value_type* s) {
                Base::operator=(s);
                return *this;
            }

            smpl_wstring& operator=(const lvalue_type* s) {
                Base::operator=(to_base(LBase(s)));
                return *this;
            }

            smpl_wstring& operator=(value_type c) {
                Base::operator=(c);
                return *this;
            }

#if __cplusplus >= 201103L

            smpl_wstring& operator=(smpl_wstring&& str) {
                Base::operator=(static_cast<Base&&> (str));
                return *this;
            }

            smpl_wstring& operator=(Base&& str) {
                Base::operator=(str);
                return *this;
            }

            smpl_wstring& operator=(LBase&& str) {
                Base::operator=(to_base(str));
                return *this;
            }

            basic_string& operator=(std::initializer_list<value_type> l) {
                Base::operator=(l);
                return *this;
            }

            basic_string& operator=(std::initializer_list<lvalue_type> l) {
                Base::operator=(to_base(LBase(l)));
                return *this;
            }


#endif        

            Base& as_base() {
                return static_cast<Base&> (*this);
            }

            const Base& as_base() const {
                return static_cast<const Base&> (*this);
            }

            utf8_string as_utf8() const {
                return to_Lbase(*this);
            }



            using Base::npos;

            using Base::append;
            using Base::assign;
            using Base::at;
            using Base::begin;
            using Base::c_str;
            using Base::capacity;
            using Base::clear;
            using Base::compare;
            using Base::copy;
            using Base::data;
            using Base::end;
            using Base::erase;
            using Base::empty;
            using Base::find;
            using Base::find_first_not_of;
            using Base::find_first_of;
            using Base::find_last_not_of;
            using Base::find_last_of;
            using Base::get_allocator;
            using Base::insert;
            using Base::length;
            using Base::max_size;
            using Base::operator[];
            using Base::push_back;
            using Base::rbegin;
            using Base::rend;
            using Base::replace;
            using Base::reserve;
            using Base::resize;
            using Base::rfind;
            using Base::size;
            using Base::substr;
            using Base::swap;

            friend bool operator==(const smpl_wstring& x, const smpl_wstring& y) {
                return static_cast<const Base&> (x) == static_cast<const Base&> (y);
            }

            friend bool operator!=(const smpl_wstring& x, const smpl_wstring& y) {
                return static_cast<const Base&> (x) != static_cast<const Base&> (y);
            }

            friend bool operator<(const smpl_wstring& x, const smpl_wstring& y) {
                return static_cast<const Base&> (x) < static_cast<const Base&> (y);
            }

            friend bool operator>(const smpl_wstring& x, const smpl_wstring& y) {
                return static_cast<const Base&> (x) > static_cast<const Base&> (y);
            }

            friend bool operator<=(const smpl_wstring& x, const smpl_wstring& y) {
                return static_cast<const Base&> (x) <= static_cast<const Base&> (y);
            }

            friend bool operator>=(const smpl_wstring& x, const smpl_wstring& y) {
                return static_cast<const Base&> (x) >= static_cast<const Base&> (y);
            }

            friend smpl_wstring operator+(const smpl_wstring& x, const smpl_wstring& y) {
                return static_cast<const Base&> (x) + static_cast<const Base&> (y);
            }

            friend smpl_wstring operator+(const smpl_wstring& x, const std::wstring& y) {
                return static_cast<const Base&> (x) + y;
            }

            friend smpl_wstring operator+(const std::wstring& x, const smpl_wstring& y) {
                return x + static_cast<const Base&> (y);
            }

        };


    }
} // namespace boost

#endif	

