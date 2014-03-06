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

template<typename TYPE>
class range {
public:

    typedef TYPE root_type;
    typedef boost::shared_ptr<TYPE> root_type_ptr;
    typedef range<TYPE> self_type;
    typedef std::vector<self_type> range_container_type;

    static const root_type min;
    static const root_type max;

    range() : left_(root_type_ptr(new TYPE(TYPE() + 1))), right_(root_type_ptr(new TYPE())) {
    };

    //   l <=  x  <= r    

    range(root_type l, root_type r) :
    left_(root_type_ptr(new TYPE(l))), right_(root_type_ptr(new TYPE(r))) {
    };

    range(root_type v) :
    left_(root_type_ptr(new TYPE(v))), right_(root_type_ptr(new TYPE(v))) {
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

    //   l <  x  < r

    range<TYPE> create_unstrict_range(root_type l, root_type r) {
        return range<TYPE>(l + 1, r - 1);
    }

    //   l <  x  <= r        

    range<TYPE> create_ul_rr_range(root_type l, root_type r) {
        return range<TYPE>(l + 1, r);
    }

    //   l <=  x  < r         

    range<TYPE> create_rl_uu_range(root_type l, root_type r) {
        return range<TYPE>(l, r - 1);
    }

    //   x  <= r        

    range<TYPE> create_rr_range(root_type r) {
        return range<TYPE>(root_type_ptr(), root_type_ptr(new TYPE(r)));
    }

    //   l <=  x          

    range<TYPE> create_rl_range(root_type l) {
        return range<TYPE>(root_type_ptr(new TYPE(l)), root_type_ptr());
    }

    //   x  < r        

    range<TYPE> create_ur_range(root_type r) {
        return range<TYPE>(root_type_ptr(), root_type_ptr(new TYPE(r - 1)));
    }

    //   l <  x          

    range<TYPE> create_ul_range(root_type l) {
        return range<TYPE>(root_type_ptr(new TYPE(l + 1)), root_type_ptr());
    }

    operator range_container_type() const {
        if (empty())
            return range_container_type();
        range_container_type rslt;
        rslt.push_back(new range<TYPE>(*this));
        return rslt;
    }

    friend range<TYPE> operator&(const range<TYPE>& l, const range<TYPE>& r) {
        root_type_ptr nl;
        root_type_ptr nr;
        if (l.empty() || r.empty())
            return range<TYPE>();
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
        range<TYPE> rslt(nl, nr);
        return rslt.empty() ? range<TYPE>() : rslt;
    }

    friend range_container_type operator&(const range_container_type& l, const range<TYPE>& r) {
        return range_container_type();
    }

    friend range_container_type operator&(const range<TYPE>& l, const range_container_type& r) {
        return r & l;
    }

    friend range_container_type operator&(const range_container_type& l, const range_container_type& r) {
        return range_container_type();
    }

    bool has_intercection(const range<TYPE>& l, const range<TYPE>& r) const {
        range<TYPE> tmp = l & r;
        return !tmp.empty();
    }

    range_container_type operator!() {
        if (empty()) {
            range_container_type rslt;
            rslt.push_back(range<TYPE>(root_type_ptr(), root_type_ptr()));
            return rslt;
        }
        if (left_ && right_) {
            range_container_type rslt;
            if (!is_min())
                rslt.push_back(range<TYPE>(root_type_ptr(), root_type_ptr(new TYPE(*left_ - 1))));
            if (!is_max())
                rslt.push_back(range<TYPE>(root_type_ptr(new TYPE(*right_ + 1)), root_type_ptr()));
            return rslt;
        } else if (left_) {
            range_container_type rslt;
            if (!is_min())
                rslt.push_back(range<TYPE>(root_type_ptr(), root_type_ptr(new TYPE(*left_ - 1))));
            return rslt;
        } else if (right_) {
            range_container_type rslt;
            if (!is_max())
                rslt.push_back(range<TYPE>(root_type_ptr(new TYPE(*right_ + 1)), root_type_ptr()));
            return rslt;
        }
        return range_container_type();
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
    std::cout << (A & B & C);
    std::cout << !(A & B & C);

}

