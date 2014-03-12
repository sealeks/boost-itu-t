/* 
 * File:   constraint_templates.h
 * Author: sealeks@mail.ru
 *
 * Created on 12 Март 2014 г., 15:01
 */

#ifndef ___CONSTRAINT_TEMPLATES_H
#define	____CONSTRAINT_TEMPLATES_H

#include <iostream>
#include <boost/itu/x68X/x680.hpp>


namespace x680 {

    template<typename T>
    class range {

    public:


        typedef T root_type;
        typedef range<T> self_type;
        typedef boost::shared_ptr<T> root_type_ptr;
        typedef std::vector<self_type> range_container_type;
        typedef std::set<self_type> range_set_type;

        static const T min;
        static const T max;


        // empty()

        range() : left_(root_type_ptr(new T(T() + 1))), right_(root_type_ptr(new T())) {
        };

        //   l <=  x  <= r    

        range(T l, T r) :
        left_(root_type_ptr(new T(l))), right_(root_type_ptr(new T(r))) {
            if (l > r) {
                left_ = root_type_ptr(new T(T() + 1));
                right_ = root_type_ptr(new T());
            }
        };

        range(T v) :
        left_(root_type_ptr(new T(v))), right_(root_type_ptr(new T(v))) {
        };

        virtual ~range() {
        };

        root_type_ptr left_ptr() const {
            return left_;
        }

        T left() const {
            return *left_;
        }

        T is_min() const {
            return left_ && (*left_ == min);
        }

        root_type_ptr right_ptr() const {
            return right_;
        }

        T right() const {
            return *right_;
        }

        T is_max() const {
            return right_ && (*right_ == max);
        }

        bool empty() const {
            return (right_ && left_ && (*right_<*left_));
        }

        bool all() const {
            return ((!right_ && !left_) || (((left_) && (*left_ == min)) && ((right_) &&(*right_ == max))));
        }

        static self_type create_empty() {
            return self_type();
        }

        static self_type create_all() {
            return self_type(root_type_ptr(), root_type_ptr());
        }

        static self_type create_range(T l, T r) {
            return self_type(l, r);
        }

        static self_type create_single(T v) {
            return self_type(v);
        }

        //   l <  x  < r

        static self_type create_more_and_less(T l, T r) {
            return self_type(l + 1, r - 1);
        }

        //   l <  x  <= r        

        static self_type create_more_and_less_or_eq(T l, T r) {
            return self_type(l + 1, r);
        }

        //   l <=  x  < r         

        static self_type create_more_or_eq_and_less(T l, T r) {
            return self_type(l, r - 1);
        }

        //   x  <= r        

        static self_type create_less_or_eq(T r) {
            return self_type(root_type_ptr(), root_type_ptr(new T(r)));
        }

        //   l <=  x          

        static self_type create_more_or_eq(T l) {
            return self_type(root_type_ptr(new T(l)), root_type_ptr());
        }

        //   x  < r        

        static self_type create_less(T r) {
            return self_type(root_type_ptr(), root_type_ptr(new T(r - 1)));
        }

        //   l <  x          

        static self_type create_more(T l) {
            return self_type(root_type_ptr(new T(l + 1)), root_type_ptr());
        }

        operator range_container_type() const {
            range_container_type rslt;
            if (empty())
                return rslt;
            rslt.push_back(self_type(*this));
            return rslt;
        }

        friend bool operator ==(const self_type& l, const self_type& r) {
            if (l.empty() && r.empty())
                return true;
            if (l.all() && r.all())
                return true;
            return ((l.left_ == r.left_) && (l.right_ == r.right_));
        }

        friend bool operator<(const self_type& l, const self_type& r) {
            if (l.empty() && r.empty())
                return false;
            if (l.all() && r.all())
                return false;
            if (l.left_ && r.left_)
                return *l.left_ < *r.left_;
            if (l.left_ && !r.left_)
                return false;
            if (!l.left_ && r.left_)
                return true;
            if (l.right_ && r.right_)
                return *l.right_ < *r.right_;
            if (l.right_ && !r.right_)
                return false;
            if (!l.right_ && r.right_)
                return true;
            return false;
        }

        static bool has_intercection(const self_type& l, const self_type& r) {
            self_type tmp = l & r;
            return !tmp.empty();
        }

        static range_container_type normalize(const range_container_type & vl) {
            if (vl.empty())
                return vl;
            if (vl.size() == 1) {
                if (vl.front().empty())
                    return range_container_type();
                else
                    return vl;
            }
            range_set_type tmpset(vl.begin(), vl.end());
            bool fnd = true;
            while (fnd) {
                fnd = false;
                for (typename range_set_type::iterator it = tmpset.begin(); it != tmpset.end(); ++it) {
                    typename range_set_type::iterator next = it;
                    ++next;
                    if (next == tmpset.end()) break;
                    if (has_intercection(*it, *next)) {
                        range_container_type nval = (*it) | (*next);
                        if (nval.size() == 1) {
                            tmpset.erase(next);
                            tmpset.erase(it);
                            tmpset.insert(nval.front());
                            fnd = true;
                            break;
                        }
                    }
                }
            }
            if (!tmpset.empty() || (tmpset.size() != 1)) {
                fnd = true;
                while (fnd) {
                    fnd = false;
                    for (typename range_set_type::iterator it = tmpset.begin(); it != tmpset.end(); ++it) {
                        typename range_set_type::iterator next = it;
                        ++next;
                        if (next == tmpset.end()) break;
                        if (it->right_ptr() && next->left_ptr()) {
                            if ((it->right() + 1) == next->left()) {
                                self_type nval(it->left_ptr(), next->right_ptr());
                                tmpset.erase(next);
                                tmpset.erase(it);
                                tmpset.insert(nval);
                                fnd = true;
                                break;
                            }
                        }
                    }
                }
            }
            return range_container_type(tmpset.begin(), tmpset.end());
        }

        friend self_type operator &(const self_type& l, const self_type& r) {
            root_type_ptr nl;
            root_type_ptr nr;
            if (l.empty() || r.empty())
                return create_empty();
            if (l.all() && r.all())
                return create_all();
            if (r.left_ || l.left_) {
                if (!r.left_)
                    nl = l.left_;
                else if (!l.left_)
                    nl = r.left_;
                else
                    nl = (*(l.left_)<*(r.left_)) ? r.left_ : l.left_;
            }
            if (r.right_ || l.right_) {
                if (!r.right_)
                    nr = l.right_;
                else if (!l.right_)
                    nr = r.right_;
                else
                    nr = (*(l.right_)>*(r.right_)) ? r.right_ : l.right_;
            }
            self_type rslt(nl, nr);
            return rslt.empty() ? create_empty() : rslt;
        }

        friend range_container_type operator |(const self_type& l, const self_type& r) {
            root_type_ptr nl;
            root_type_ptr nr;
            range_container_type rslt;
            if (l.empty() && r.empty())
                return rslt;
            if (l.empty()) {
                rslt.push_back(r);
                return rslt;
            }
            if (r.empty()) {
                rslt.push_back(l);
                return rslt;
            }
            if (has_intercection(l, r)) {
                if (r.left_ && l.left_)
                    nl = (*(l.left_)<*(r.left_)) ? l.left_ : r.left_;
                if (r.right_ && l.right_)
                    nr = (*(l.right_)>*(r.right_)) ? l.right_ : r.right_;
                rslt.push_back(self_type(nl, nr));
                return rslt;
            }
            rslt.push_back(r);
            rslt.push_back(l);
            return rslt;
        }

        friend range_container_type operator-(const self_type& l, const self_type& r) {
            range_container_type rslt;
            if (l.empty() && r.empty())
                return rslt;
            if (l.empty())
                return rslt;
            if (r.all())
                return rslt;
            if (r.empty()) {
                rslt.push_back(l);
                return rslt;
            }
            return !r & l;
        }

        friend range_container_type operator&(const range_container_type& l, const self_type& r) {
            return l & (r.operator range_container_type());
        }

        friend range_container_type operator |(const range_container_type& l, const self_type& r) {
            return l | (r.operator range_container_type());
        }

        friend range_container_type operator-(const range_container_type& l, const self_type& r) {
            return l - (r.operator range_container_type());
        }

        friend range_container_type operator&(const self_type& l, const range_container_type& r) {
            return r & l;
        }

        friend range_container_type operator |(const self_type& l, const range_container_type& r) {
            return r | l;
        }

        friend range_container_type operator -(const self_type& l, const range_container_type& r) {
            return (l.operator range_container_type()) -r;
        }

        friend range_container_type operator&(const range_container_type& l, const range_container_type& r) {
            range_container_type rslt;
            range_container_type rslt1 = self_type::normalize(l);
            range_container_type rslt2 = self_type::normalize(r);
            if (rslt1.empty() || rslt2.empty())
                return rslt;
            for (typename range_container_type::iterator it1 = rslt1.begin(); it1 != rslt1.end(); ++it1) {
                for (typename range_container_type::iterator it2 = rslt2.begin(); it2 != rslt2.end(); ++it2) {
                    if (has_intercection(*it1, *it2)) {
                        self_type nval = (*it1) & (*it2);
                        rslt.push_back(nval);
                    }
                }
            }
            return self_type::normalize(rslt);
        }

        friend range_container_type operator |(const range_container_type& l, const range_container_type& r) {
            range_container_type tmp = normalize(l);
            range_container_type tmpr = normalize(r);
            tmp.insert(tmp.end(), tmpr.begin(), tmpr.end());
            return self_type::normalize(tmp);
        }

        friend range_container_type operator-(const range_container_type& l, const range_container_type& r) {
            return l & notop(r);
        }

        range_container_type operator!() const {
            range_container_type rslt;
            if (empty()) {
                rslt.push_back(create_all());
                return rslt;
            }
            if (left_ && right_) {
                if (!is_min())
                    rslt.push_back(self_type(root_type_ptr(), root_type_ptr(new T(*left_ - 1))));
                if (!is_max())
                    rslt.push_back(self_type(root_type_ptr(new T(*right_ + 1)), root_type_ptr()));
                return rslt;
            } else if (left_) {
                if (!is_min())
                    rslt.push_back(self_type(root_type_ptr(), root_type_ptr(new T(*left_ - 1))));
                return rslt;
            } else if (right_) {
                if (!is_max())
                    rslt.push_back(self_type(root_type_ptr(new T(*right_ + 1)), root_type_ptr()));
                return rslt;
            }
            return rslt;
        }

        friend range_container_type notop(const range_container_type& vl) {
            range_container_type rslt;
            range_container_type tmp = self_type::normalize(vl);
            if (tmp.empty()) {
                rslt.push_back(create_all());
                return rslt;
            }
            if ((tmp.size() == 1) && (tmp.front().all()))
                return range_container_type();
            rslt.push_back(create_all());
            for (typename range_container_type::iterator it = tmp.begin(); it != tmp.end(); ++it)
                rslt = rslt & !(*it);
            return rslt;
        }


    private:

        range(root_type_ptr l, root_type_ptr r) :
        left_(l), right_(r) {
        };

        root_type_ptr left_;
        root_type_ptr right_;
    };

    template<typename T>
    const T range<T>::min = std::numeric_limits<T>::min();

    template<typename T>
    const T range<T>::max = std::numeric_limits<T>::max();

    template<typename T>
    class range_constraints {

    public:

        typedef range_constraints<T> self_type;
        typedef range<T> range_type;
        typedef typename range_type::range_container_type container_type;

        range_constraints() {
            expention_ = range_type::create_empty();
        }

        explicit range_constraints(const T& vl) {
            range_.push_back(range_type(vl));
            expention_ = range_type::create_empty();
        }

        explicit range_constraints(const T& l, const T& r) {
            range_.push_back(range_type(l, r));
            expention_ = range_type::create_empty();
        }

        explicit range_constraints(const T& l, const T& r, const T& e) {
            range_.push_back(range_type(l, r));
            if (e > r)
                expention_ = range_type::create_more_or_eq(e);
            else
                expention_ = range_type::create_empty();
        }

        explicit range_constraints(const T& l, const T& r, bool e) {
            range_.push_back(range_type(l, r));
            expention_ = range_type::create_all();
        }

        explicit range_constraints(const range_type& vl, const T& e) {
            if (!vl.empty())
                range_.push_back(vl);
            range_type tmp = range_type::create_more_or_eq(e);
            container_type test = range_type::normalize(tmp - range_);
            if (test.empty()) {
                expention_ = tmp;
                return;
            }
            expention_ = range_type::create_empty();
        }

        explicit range_constraints(const range_type& vl, bool e) {
            if (!vl.empty()) {
                range_.push_back(vl);
                expention_ = range_type::create_all();
            }
        }

        range_constraints(const container_type& vl, bool e = false) : range_(vl) {
            if (e)
                expention_ = range_type::create_all();
        }

        container_type& set() {
            return range_;
        }

        const container_type& set() const {
            return range_;
        }

        bool has_extention() const {
            return !expention_.empty();
        }

        range_type extention() const {
            return expention_;
        }

        void extention(range_type e) {
            expention_ = e;
        }

        void add_extention(const T& e) {
            if (e < range_type::max)
                expention_ = range_type::create_more_or_eq(e + 1);
        }

        void add_extention() {
            if (!all() && !empty()) {
                container_type tmp = range_type::normalize(range_);
                if (!tmp.empty()) {
                    if (tmp.back().right_ptr()) {
                        if (tmp.back().right() != range_type::max) {
                            expention_ = range_type::create_more_or_eq(tmp.back().right() + 1);
                        }
                    }
                }
            }
        }

        void clear_extention() {
            expention_ = range_type::create_empty();
        }

        bool all() {
            if (!range_.empty()) {
                container_type tmp = range_type::normalize(range_);
                return ((tmp.size() == 1) && (tmp.front().all()));
            }
            return false;
        }

        bool empty() {
            if (range_.empty())
                return true;
            container_type tmp = range_type::normalize(range_);
            return ((tmp.size() == 1) && (tmp.front().empty()));
        }

        self_type& operator&=(const self_type& vl) {
            range_ = range_ & vl.range_;
            return *this;
        }

        self_type& operator&=(const container_type& vl) {
            range_ = range_ & vl;
            return *this;
        }

        self_type& operator&=(const range_type& vl) {
            range_ = range_ & vl;
            return *this;
        }

        self_type& operator&=(const T& vl) {
            range_ = range_ & range_type(vl);
            return *this;
        }

        self_type& operator|=(const self_type& vl) {
            range_ = range_ | vl.range_;
            return *this;
        }

        self_type& operator|=(const container_type& vl) {
            range_ = range_ | vl;
            return *this;
        }

        self_type& operator|=(const range_type& vl) {
            range_ = range_ | vl;
            return *this;
        }

        self_type& operator|=(const T& vl) {
            range_ = range_ | range_type(vl);
            return *this;
        }

        self_type& operator-=(const self_type& vl) {
            range_ = range_ - vl.range_;
            return *this;
        }

        self_type& operator-=(const container_type& vl) {
            range_ = range_ - vl;
            return *this;
        }

        self_type& operator-=(const range_type& vl) {
            range_ = range_ - vl;
            return *this;
        }

        self_type& operator-=(const T& vl) {
            range_ = range_ - vl;
            return *this;
        }

        self_type& operator!() {
            range_ = notop(range_);
            return *this;
        }

    private:

        container_type range_;
        range_type expention_;
    };

    template<typename T, typename U>
    class dual_constraints {

    public:

        typedef range<T> first_range;
        typedef typename first_range::range_container_type first_container;
        typedef range_constraints<T> first_constraints;

        typedef range<U> second_range;
        typedef typename second_range::range_container_type second_container;
        typedef range_constraints<U> second_constraints;

        typedef dual_constraints<T, U> self_type;

        dual_constraints() :
        first_(first_range::create_all()), second_(second_range::create_all()) {
        }

        dual_constraints(first_range f, second_range s) :
        first_(f), second_(s) {
        }

        virtual ~dual_constraints() {
        }

        first_constraints& first() {
            return first_;
        }

        second_constraints& second() {
            return second_;
        }

        const first_constraints& first() const {
            return first_;
        }

        const second_constraints& second() const {
            return second_;
        }

        self_type& operator&=(const self_type& v) {
            first_ &= v.first();
            second_ &= v.second();
            return *this;
        }

        self_type& operator|=(const self_type& v) {
            first_ |= v.first();
            second_ |= v.second();
            return *this;
        }

        self_type& operator-=(const self_type& v) {
            first_ -= v.first();
            second_ -= v.second();
            return *this;
        }

        static self_type create_and(const first_range& f, const second_range& s) {
            return create_first(f) &= create_second(s);
        }

        static self_type create_or(const first_range& f, const second_range& s) {
            return create_first(f) |= create_second(s);
        }

        static self_type create_except(const first_range& f, const second_range& s) {
            return create_first(f) -= create_second(s);
        }

        static self_type create_first(const first_range& v) {
            self_type tmp;
            tmp.first_ &= v;
            return tmp;
        }

        static self_type create_second(const second_range& v) {
            self_type tmp;
            tmp.second_ &= v;
            return tmp;
        }


    private:

        first_constraints first_;
        second_constraints second_;
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const range<T>& vl) {
        if (vl.empty())
            return stream << "  [ null ] ";
        if ((vl.left_ptr()) && (vl.right_ptr())) {
            if (vl.left() != vl.right())
                stream << "  [ " << vl.left() << "  ...   " << vl.right() << " ] ";
            else
                stream << "  [ " << vl.left() << " ] ";
            return stream;
        }
        if (vl.left_ptr()) {
            stream << "  [ " << vl.left() << "  ...   " << " ] ";
            return stream;
        }
        if (vl.right_ptr()) {
            stream << "  [ " << "  ...   " << vl.right() << " ] ";
            return stream;
        }
        return stream << "  [ ... ] ";
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const std::vector<range<T> >& vl) {
        if (vl.empty())
            return stream << "  [ null ] ";
        for (typename std::vector<range<T> >::const_iterator it = vl.begin(); it != vl.end(); ++it) {
            stream << *it;
        }
        return stream;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const range_constraints<T>& vl) {
        stream << "{" << vl.set() << "}";
        if (vl.has_extention()) {
            stream << "( ext " << vl.extention() << ")";
        }
        return stream;
    }

    template<typename T, typename U>
    std::ostream& operator<<(std::ostream& stream, const dual_constraints<T, U>& vl) {
        stream << "(" << vl.first() << ")" << "(" << vl.second() << ")";
        /* if (vl.has_extention()) {
             stream << "( ext "  << vl.extention()  << ")"  ;
         }*/
        return stream;
    }

}

#endif	/* CONSTRAINT_TEMPLATES_H */

