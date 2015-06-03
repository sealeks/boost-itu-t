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

namespace boost {
    namespace itu {

        template<typename T, typename Alloc = std::allocator<T > >
        class vector : protected std::vector<T, Alloc> {

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

#if __cplusplus < 201103L

            explicit
            vector(size_type n, const value_type& value = value_type(), const allocator_type& a = allocator_type()) :
            Base(n, value, a) {
            }

            vector(const vector& x) : Base(static_cast<const Base&> (x)) {
            }

            template<typename InputIterator>
            vector(InputIterator first, InputIterator last,
                    const allocator_type& a = allocator_type()) : Base(first, last, a) {
            }

#else

            explicit
            vector(size_type n, const allocator_type& a = allocator_type()) :
            Base(n, a) {
            }

            vector(size_type n, const value_type& value, const allocator_type& a = allocator_type()) :
            Base(n, value, a) {
            }

            vector(vector&& x) noexcept
            : Base(static_cast<Base&&> (x)) {
            }

            vector(const vector& x, const allocator_type& a) :
            Base(static_cast<const Base&> (x), a) {
            }

            vector(vector&& rv, const allocator_type& m)
            : Base(static_cast<Base&&> (rv), m) {
            }

            vector(initializer_list<value_type> l,
                    const allocator_type& a = allocator_type())
            : Base(l, a) {
            }

            template<typename InputIterator>
            vector(_InputIterator first, _InputIterator last,
                    const allocator_type& a = allocator_type())
            : _Base(first, last, a) {
            }


#endif            

            vector& operator=(const vector& x) {
                return static_cast<vector&> (Base::operator=(static_cast<const Base&> (x)));
            }

#if __cplusplus >= 201103L

            vector& operator=(vector&& x) {
                return static_cast<vector&> (Base::operator=(static_cast<Base&&> (x)));
            }

            vector& operator=(initializer_list<value_type> l) {
                return static_cast<vector&> (Base::operator=(l));
            }
#endif            

            ~vector() {
            }

            operator Base&() {
                return static_cast<Base&> (*this);
            }

            operator const Base&() const {
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

#if __cplusplus < 201103L

            explicit
            sequence_of(size_type n, const value_type& value = value_type(), const allocator_type& a = allocator_type()) :
            Base(n, value, a) {
            }

            sequence_of(const sequence_of& x) : Base(static_cast<const Base&> (x)) {
            }

            template<typename InputIterator>
            sequence_of(InputIterator first, InputIterator last,
                    const allocator_type& a = allocator_type()) : Base(first, last, a) {
            }

#else

            explicit
            sequence_of(size_type n, const allocator_type& a = allocator_type()) :
            Base(n, a) {
            }

            sequence_of(size_type n, const value_type& value, const allocator_type& a = allocator_type()) :
            Base(n, value, a) {
            }

            sequence_of(sequence_of&& x) noexcept
            : Base(static_cast<Base&&> (x)) {
            }

            sequence_of(const sequence_of& x, const allocator_type& a) :
            Base(static_cast<const Base&> (x), a) {
            }

            sequence_of(sequence_of&& rv, const allocator_type& m)
            : Base(static_cast<Base&&> (rv), m) {
            }

            sequence_of(initializer_list<value_type> l,
                    const allocator_type& a = allocator_type())
            : Base(l, a) {
            }

            template<typename InputIterator>
            sequence_of(_InputIterator first, _InputIterator last,
                    const allocator_type& a = allocator_type())
            : _Base(first, last, a) {
            }


#endif            

            sequence_of& operator=(const sequence_of& x) {
                return static_cast<sequence_of&> (Base::operator=(static_cast<const Base&> (x)));
            }

#if __cplusplus >= 201103L

            sequence_of& operator=(sequence_of&& x) {
                return static_cast<sequence_of&> (Base::operator=(static_cast<Base&&> (x)));
            }

            sequence_of& operator=(initializer_list<value_type> l) {
                return static_cast<sequence_of&> (Base::operator=(l));
            }

#endif                

            ~sequence_of() {
            }

            operator Base&() {
                return static_cast<Base&> (*this);
            }

            operator const Base&() const {
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

#if __cplusplus < 201103L

            explicit
            set_of(size_type n, const value_type& value = value_type(), const allocator_type& a = allocator_type()) :
            Base(n, value, a) {
            }

            set_of(const set_of& x) : Base(static_cast<const Base&> (x)) {
            }

            template<typename InputIterator>
            set_of(InputIterator first, InputIterator last,
                    const allocator_type& a = allocator_type()) : Base(first, last, a) {
            }

#else

            explicit
            set_of(size_type n, const allocator_type& a = allocator_type()) :
            Base(n, a) {
            }

            set_of(size_type n, const value_type& value, const allocator_type& a = allocator_type()) :
            Base(n, value, a) {
            }

            set_of(set_of&& x) noexcept
            : Base(static_cast<Base&&> (x)) {
            }

            set_of(const set_of& x, const allocator_type& a) :
            Base(static_cast<const Base&> (x), a) {
            }

            set_of(set_of&& rv, const allocator_type& m)
            : Base(static_cast<Base&&> (rv), m) {
            }

            set_of(initializer_list<value_type> l,
                    const allocator_type& a = allocator_type())
            : Base(l, a) {
            }

            template<typename InputIterator>
            set_of(_InputIterator first, _InputIterator last,
                    const allocator_type& a = allocator_type())
            : _Base(first, last, a) {
            }


#endif            

            set_of& operator=(const set_of& x) {
                return static_cast<set_of&> (Base::operator=(static_cast<const Base&> (x)));
            }

#if __cplusplus >= 201103L

            set_of& operator=(set_of&& x) {
                return static_cast<set_of&> (Base::operator=(static_cast<Base&&> (x)));
            }

            set_of& operator=(initializer_list<value_type> l) {
                return Base::operator=(l);
            }

#endif             

            ~set_of() {
            }

            operator Base&() {
                return static_cast<Base&> (*this);
            }

            operator const Base&() const {
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

        //template<std::size_t ID = 0 >

        class smpl_string : protected std::string {

        public:

            /*static std::size_t get__id() {
                return ID;
            }*/

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

            smpl_string(smpl_string&& str) noexcept
            : Base(static_cast<Base&&> (str)) {
            }

            smpl_string(initializer_list<value_type l, const allocator_type& a = allocator_type())
            : Base(l, a) {
            }

#endif           

            ~smpl_string() {
            }

            smpl_string& operator=(const smpl_string& str) {
                return static_cast<smpl_string&> (Base::operator=(static_cast<const Base&> (str)));
            }

            smpl_string& operator=(const value_type* s) {
                return static_cast<smpl_string&> (Base::operator=(s));
            }

            smpl_string& operator=(value_type c) {
                return static_cast<smpl_string&> (Base::operator=(c));
            }

#if __cplusplus >= 201103L

            smpl_string& operator=(smpl_string&& str) {
                return static_cast<smpl_string&> (Base::operator=Base(static_cast<Base&&> (str)));
            }

            basic_string& operator=(initializer_list<_CharT> l) {
                return static_cast<smpl_string&> (Base::operator=Base(l));
            }

#endif        

            operator Base&() {
                return static_cast<Base&> (*this);
            }

            operator const Base&() const {
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

        };

    }
} // namespace boost

#endif	

