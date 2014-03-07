//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <cstdlib>
#include <deque>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>


#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/asn1/asnbase.hpp>

#include "Test1.hpp"

typedef boost::asn1::x690::input_coder x690_input_coder_type;
typedef boost::asn1::x690::output_coder x690_output_coder_type;
typedef boost::itu::asn_coder_templ<x690_input_coder_type, x690_output_coder_type> x690_coder_type;

template<typename INPUT_TYPE, typename OUTPUT_TYPE>
class asn1_stream_adaptor {
public:

    typedef INPUT_TYPE input_stream_type;
    typedef OUTPUT_TYPE output_stream_type;
    typedef asn1_stream_adaptor<INPUT_TYPE, OUTPUT_TYPE> self_type;

    asn1_stream_adaptor(input_stream_type& in_, output_stream_type& out_)
    : in(in_), out(out_) {
    }

    virtual ~asn1_stream_adaptor() {
    }

    template<typename T>
    friend self_type& operator<<(self_type& stream, const T& vl) {
        boost::asn1::bind_element(stream.coder.output(), vl);
        const boost::itu::const_sequences& seq = stream.coder.output().buffers();
        for (boost::itu::const_sequences::const_iterator it = seq.begin(); it != seq.end(); ++it) {
            stream.out << boost::itu::binary_to_hexsequence_debug(std::string(boost::asio::buffer_cast<const char*>(*it), boost::asio::buffer_size(*it)));
            //stream.out << seq;
        }
        return stream;
    }

private:

    input_stream_type& in;
    output_stream_type& out;
    x690_coder_type coder;
};

template<typename T>
class range {
public:

    typedef T root_type;
    typedef boost::shared_ptr<T> root_type_ptr;
    typedef range<T> self_type;
    typedef std::vector<self_type> range_container_type;
    typedef std::set<self_type> range_set_type;

    static const root_type min;
    static const root_type max;

    range() : left_(root_type_ptr(new T(T() + 1))), right_(root_type_ptr(new T())) {
    };

    //   l <=  x  <= r    

    range(root_type l, root_type r) :
    left_(root_type_ptr(new T(l))), right_(root_type_ptr(new T(r))) {
    };

    range(root_type v) :
    left_(root_type_ptr(new T(v))), right_(root_type_ptr(new T(v))) {
    };

    range(root_type_ptr l, root_type_ptr r) :
    left_(l), right_(r) {
    };

    virtual ~range() {
    };

    root_type_ptr left_ptr() const {
        return left_;
    }

    root_type left() const {
        return *left_;
    }

    root_type is_min() const {
        return left_ && (*left_ == min);
    }

    root_type_ptr right_ptr() const {
        return right_;
    }

    root_type right() const {
        return *right_;
    }

    root_type is_max() const {
        return right_ && (*right_ == max);
    }

    bool empty() const {
        return (right_ && left_ && (*right_<*left_));
    }

    bool all() const {
        return ((!right_ && !left_) || (((left_) && (*left_ == min)) && ((right_) &&(*right_ == max))));
    }

    //   l <  x  < r

    range<T> create_unstrict_range(root_type l, root_type r) {
        return range<T>(l + 1, r - 1);
    }

    //   l <  x  <= r        

    range<T> create_ul_rr_range(root_type l, root_type r) {
        return range<T>(l + 1, r);
    }

    //   l <=  x  < r         

    range<T> create_rl_uu_range(root_type l, root_type r) {
        return range<T>(l, r - 1);
    }

    //   x  <= r        

    range<T> create_rr_range(root_type r) {
        return range<T>(root_type_ptr(), root_type_ptr(new T(r)));
    }

    //   l <=  x          

    range<T> create_rl_range(root_type l) {
        return range<T>(root_type_ptr(new T(l)), root_type_ptr());
    }

    //   x  < r        

    range<T> create_ur_range(root_type r) {
        return range<T>(root_type_ptr(), root_type_ptr(new T(r - 1)));
    }

    //   l <  x          

    range<T> create_ul_range(root_type l) {
        return range<T>(root_type_ptr(new T(l + 1)), root_type_ptr());
    }

    operator range_container_type() const {
        range_container_type rslt;
        if (empty())
            return rslt;
        rslt.push_back(range<T>(*this));
        return rslt;
    }

    friend bool operator ==(const range<T>& l, const range<T>& r) {
        if (l.empty() && r.empty())
            return true;
        if (l.all() && r.all())
            return true;
        return ((l.left_ == r.left_) && (l.right_ == r.right_));
    }

    friend bool operator<(const range<T>& l, const range<T>& r) {
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

    static bool has_intercection(const range<T>& l, const range<T>& r) {
        range<T> tmp = l & r;
        return !tmp.empty();
    }

    static range_container_type normalize(const range_container_type & vl) {
        if (vl.empty())
            return vl;
        if (vl.size() == 1) {
            if (vl.begin()->empty())
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
                        tmpset.insert(*(nval.begin()));
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
                            range<T> nval(it->left_ptr(), next->right_ptr());
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

    friend range<T> operator &(const range<T>& l, const range<T>& r) {
        root_type_ptr nl;
        root_type_ptr nr;
        if (l.empty() || r.empty())
            return range<T>();
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
        range<T> rslt(nl, nr);
        return rslt.empty() ? range<T>() : rslt;
    }

    friend range_container_type operator |(const range<T>& l, const range<T>& r) {
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
        if (l.has_intercection(l, r)) {
            if (r.left_ && l.left_)
                nl = (*(l.left_)<*(r.left_)) ? l.left_ : r.left_;
            if (r.right_ && l.right_)
                nr = (*(l.right_)>*(r.right_)) ? l.right_ : r.right_;
            rslt.push_back(range<T>(nl, nr));
            return rslt;
        }
        rslt.push_back(r);
        rslt.push_back(l);
        return rslt;
    }

    friend range_container_type operator-(const range<T>& l, const range<T>& r) {
        if (l.empty() && r.empty())
            return l;
        if (l.empty())
            return l;
        if (r.all())
            return range<T>();
        if (r.empty())
            return l;
        return !r & l;
    }

    friend range_container_type operator&(const range_container_type& l, const range<T>& r) {
        return l & (r.operator range_container_type());
    }

    friend range_container_type operator |(const range_container_type& l, const range<T>& r) {
        return l | (r.operator range_container_type());
    }

    friend range_container_type operator-(const range_container_type& l, const range<T>& r) {
        return l - (r.operator range_container_type());
    }

    friend range_container_type operator&(const range<T>& l, const range_container_type& r) {
        return r & l;
    }

    friend range_container_type operator |(const range<T>& l, const range_container_type& r) {
        return r | l;
    }

    friend range_container_type operator -(const range<T>& l, const range_container_type& r) {
        return (l.operator range_container_type()) -r;
    }

    friend range_container_type operator&(const range_container_type& l, const range_container_type& r) {
        range_container_type rslt;
        range_container_type rslt1 = range<T>::normalize(l);
        range_container_type rslt2 = range<T>::normalize(r);
        if (rslt1.empty() || rslt2.empty())
            return rslt;
        for (typename range_container_type::iterator it1 = rslt1.begin(); it1 != rslt1.end(); ++it1) {
            for (typename range_container_type::iterator it2 = rslt2.begin(); it2 != rslt2.end(); ++it2) {
                if (has_intercection(*it1, *it2)) {
                    range<T> nval = (*it1) & (*it2);
                    rslt.push_back(nval);
                }
            }
        }
        return range<T>::normalize(rslt);
    }

    friend range_container_type operator |(const range_container_type& l, const range_container_type& r) {
        range_container_type tmp = normalize(l);
        range_container_type tmpr = normalize(r);
        tmp.insert(tmp.end(), tmpr.begin(), tmpr.end());
        return range<T>::normalize(tmp);
    }

    friend range_container_type operator-(const range_container_type& l, const range_container_type& r) {
        return l & notop(r);
    }

    range_container_type operator!() const {
        range_container_type rslt;
        if (empty()) {
            rslt.push_back(range<T>(root_type_ptr(), root_type_ptr()));
            return rslt;
        }
        if (left_ && right_) {
            if (!is_min())
                rslt.push_back(range<T>(root_type_ptr(), root_type_ptr(new T(*left_ - 1))));
            if (!is_max())
                rslt.push_back(range<T>(root_type_ptr(new T(*right_ + 1)), root_type_ptr()));
            return rslt;
        } else if (left_) {
            if (!is_min())
                rslt.push_back(range<T>(root_type_ptr(), root_type_ptr(new T(*left_ - 1))));
            return rslt;
        } else if (right_) {
            if (!is_max())
                rslt.push_back(range<T>(root_type_ptr(new T(*right_ + 1)), root_type_ptr()));
            return rslt;
        }
        return rslt;
    }

    friend range_container_type notop(const range_container_type& vl) {
        range_container_type rslt;
        range_container_type tmp = range<T>::normalize(vl);
        if (tmp.empty()) {
            rslt.push_back(range<T>(root_type_ptr(), root_type_ptr()));
            return rslt;
        }
        if ((tmp.size() == 1) && (tmp.front().all()))
            return range_container_type();
        rslt.push_back(range<T>(root_type_ptr(), root_type_ptr()));
        for (typename range_container_type::iterator it = tmp.begin(); it != tmp.end(); ++it)
            rslt = rslt & !(*it);
        return rslt;
    }


private:

    root_type_ptr left_;
    root_type_ptr right_;
};

template<typename T>
const T range<T>::min = std::numeric_limits<T>::min();

template<typename T>
const T range<T>::max = std::numeric_limits<T>::max();

template<typename T>
std::ostream& operator<<(std::ostream& stream, const range<T>& vl) {
    if (vl.empty())
        return stream << " range [ null ] ";
    if ((vl.left_ptr()) && (vl.right_ptr())) {
        if (vl.left() != vl.right())
            stream << " range [ " << vl.left() << "  ...   " << vl.right() << " ] ";
        else
            stream << " range [ " << vl.left() << " ] ";
        return stream;
    }
    if (vl.left_ptr()) {
        stream << " range [ " << vl.left() << "  ...   " << " ] ";
        return stream;
    }
    if (vl.right_ptr()) {
        stream << " range [ " << "  ...   " << vl.right() << " ] ";
        return stream;
    }
    return stream << " range [ ... ] ";
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<range<T> >& vl) {
    if (vl.empty())
        return stream << " range [ null ] ";
    for (typename std::vector<range<T> >::const_iterator it = vl.begin(); it != vl.end(); ++it) {
        stream << *it;
    }
    return stream;
}





using namespace Test1;

typedef asn1_stream_adaptor<std::istream, std::ostream> asn1_adaptor;
typedef range<int> rangeint_type;

int main(int argc, char* argv[]) {

    /*    PersonnelRecord PR(PersonnelRecord_impl(Name(Name_impl(std::string("John"), std::string("P"), std::string("Smith"))), 
                "Director", 
                EmployeeNumber(51), 
                Date("19710917"), 
                Name(Name_impl(std::string("Mary"), std::string("T"), std::string("Smith")))));
    
        PersonnelRecord_impl::Children_type& chlds = *(PR->children__new());
        chlds.push_back(ChildInformation(Name(Name_impl(std::string("Ralph"), std::string("T"), std::string("Smith"))), Date("19571111")));
        chlds.push_back(ChildInformation(Name(Name_impl(std::string("Susan"), std::string("B"), std::string("Jones"))), Date("19590717")));

        asn1_adaptor adaptor(std::cin,std::cout);
    
       adaptor << PR;*/

    rangeint_type A(0, 100);
    rangeint_type B(15, 150);
    rangeint_type C(5, 80);
    rangeint_type D(1, 3);
    rangeint_type E(5, 15);

    rangeint_type A1(1);
    rangeint_type B1(2);
    rangeint_type C1(3);

    std::cout << (A & B & C) << "\n";
    std::cout << !(A & B & C) << "\n";
    std::cout << (A1 | B1 | C1 | C) << "\n";
    std::cout << (!(A & B & C) & (A1 | B1 | C1 | C)) << "\n";
    std::cout << (A - B) << "\n";
    std::cout << notop(!(A & B & C) & (A1 | B1 | C1 | C)) << "\n";
    std::cout << (notop(D | E)) << "\n";
    std::cout << ((A & B & C) - (D | E)) << "\n";

}

