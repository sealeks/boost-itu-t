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

namespace boost {
    namespace itu {

        namespace containers {

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

                vector() : Base() {
                }

                explicit vector(const allocator_type& a) : Base(a) {
                }

                explicit vector(size_type n, const value_type& value = value_type(),
                        const allocator_type& a = allocator_type()) : Base(n, a) {
                }

                vector(const vector& x) : Base(x) {
                }

                template<typename InputIterator>
                vector(InputIterator first, InputIterator last,
                        const allocator_type& a = allocator_type()) : Base(first, last, a) {
                }

                vector& operator=(const vector& x) {
                    return static_cast<vector&> (Base::operator =(static_cast<Base> (x)));
                }

                ~vector() {
                }
                
               operator Base&()  {
                    return static_cast<Base&> (*this);
                }
               
               operator const Base&() const  {
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
    }
} // namespace boost

#endif	

