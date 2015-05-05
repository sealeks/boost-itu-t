/* 
 * File:   constraint_templates.h
 * Author: sealeks@mail.ru
 *
 * Created on 12 РњР°СЂС‚ 2014 Рі., 15:01
 */

#ifndef ___CONSTRAINT_TEMPLATES_H
#define	____CONSTRAINT_TEMPLATES_H

#include <iostream>
#include <boost/itu/x68X/x680.hpp>


namespace x680 {

    /////////////////////////////////////////////////////////////////////////      
    // null_initer
    /////////////////////////////////////////////////////////////////////////     

    struct null_initer {

    };


    /////////////////////////////////////////////////////////////////////////      
    // bstring_initer
    /////////////////////////////////////////////////////////////////////////     

    struct bstring_initer {

        bstring_initer() : str(), unused(0) {
        }

        bstring_initer(const std::string vl) : str(vl), unused(0) {
        }

        bstring_initer(const std::string vl, std::size_t un) : str(vl), unused(un) {
        }

        std::string str;
        std::size_t unused;
    };

    /////////////////////////////////////////////////////////////////////////      
    // hstring_initer
    /////////////////////////////////////////////////////////////////////////     

    struct hstring_initer {

        hstring_initer() : str() {
        }

        hstring_initer(const std::string vl) : str(vl) {
        }

        std::string str;
    };

    /////////////////////////////////////////////////////////////////////////      
    // quadruple
    /////////////////////////////////////////////////////////////////////////     

    struct quadruple {

        quadruple() : group(0), plane(0), row(0), cell(0) {
        };

        quadruple(uint8_t r, uint8_t c) :
        group(0), plane(0), row(r), cell(c) {
        };

        quadruple(uint8_t g, uint8_t p, uint8_t r, uint8_t c) :
        group(g), plane(p), row(r), cell(c) {
        };

        uint8_t group;
        uint8_t plane;
        uint8_t row;
        uint8_t cell;

        friend bool operator==(const quadruple& ls, const quadruple& rs) {
            return ((ls.group == rs.group) && (ls.plane == rs.plane) && (ls.row == rs.row) && (ls.cell == rs.cell));
        }

        friend quadruple operator+(const quadruple& ls, int rs) {
            if (ls.cell < 255)
                return quadruple(ls.group, ls.plane, ls.row, ls.cell + 1);
            if (ls.row < 255)
                return quadruple(ls.group, ls.plane, ls.row + 1, 0);
            if (ls.plane < 255)
                return quadruple(ls.group, ls.plane + 1, 0, 0);
            if (ls.group < 127)
                return quadruple(ls.group + 1, 0, 0, 0);
            return ls;
        }

        friend quadruple operator-(const quadruple& ls, int rs) {
            if (ls.cell > 0)
                return quadruple(ls.group, ls.plane, ls.row, ls.cell - 1);
            if (ls.row > 0)
                return quadruple(ls.group, ls.plane, ls.row - 1, 0);
            if (ls.plane > 0)
                return quadruple(ls.group, ls.plane - 1, 0, 0);
            if (ls.group > 0)
                return quadruple(ls.group - 1, 0, 0, 0);
            return ls;
        }

        friend bool operator!=(const quadruple& ls, const quadruple& rs) {
            return !(ls == rs);
        }

        friend bool operator<(const quadruple& ls, const quadruple& rs) {
            if (ls.group < rs.group)
                return true;
            if (ls.group > rs.group)
                return false;
            if (ls.plane < rs.plane)
                return true;
            if (ls.plane > rs.plane)
                return false;
            if (ls.row < rs.row)
                return true;
            if (ls.row > rs.row)
                return false;
            if (ls.cell < rs.cell)
                return true;
            return false;
        }

        operator bool() const {
            return (group || plane || row || cell);
        }

    };



    const quadruple NULL_QUADRUPLE = quadruple();
    const quadruple MAX_QUADRUPLE = quadruple(127, 255, 255, 255);



    /////////////////////////////////////////////////////////////////////////      
    // tuple
    /////////////////////////////////////////////////////////////////////////    

    struct tuple {

        tuple() : tablecolumn(0), tablerow(0) {
        };

        tuple(uint8_t c, uint8_t r) : tablecolumn(c), tablerow(r) {
        };


        uint8_t tablecolumn;
        uint8_t tablerow;

        friend bool operator==(const tuple& ls, const tuple& rs) {
            return ((ls.tablecolumn == rs.tablecolumn) && (ls.tablerow == rs.tablerow));
        }

        friend tuple operator+(const tuple& ls, int rs) {
            if (ls.tablerow < 15)
                return tuple(ls.tablecolumn, ls.tablerow + 1);
            if (ls.tablecolumn < 7)
                return tuple(ls.tablecolumn + 1, 0);
            return ls;
        }

        friend tuple operator-(const tuple& ls, int rs) {
            if (ls.tablerow > 0)
                return tuple(ls.tablecolumn, ls.tablerow - 1);
            if (ls.tablecolumn > 0)
                return tuple(ls.tablecolumn - 1, 0);
            return ls;
        }

        friend bool operator!=(const tuple& ls, const tuple& rs) {
            return !(ls == rs);
        }

        friend bool operator<(const tuple& ls, const tuple& rs) {
            if (ls.tablecolumn < rs.tablecolumn)
                return true;
            if (ls.tablecolumn > rs.tablecolumn)
                return false;
            if (ls.tablerow < rs.tablerow)
                return true;
            return false;
        }

        operator bool() const {
            return (tablerow || tablerow);
        }

    };

    const tuple NULL_TUPLE = tuple();
    const tuple MAX_TUPLE = tuple(7, 15);


    typedef std::vector<std::string> string_vector;
    typedef std::vector<std::size_t> unum_vector;
    typedef std::vector<int64_t> num_vector;
    typedef std::vector<tuple> tuple_vector;
    typedef std::vector<quadruple> quadruple_vector;


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  range
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

        range(root_type_ptr l, root_type_ptr r) :
        left_(l), right_(r) {
        };

        virtual ~range() {
        };

        root_type_ptr left_ptr() const {
            return left_;
        }

        T left() const {
            return *left_;
        }

        bool is_min() const {
            return left_ && (*left_ == min);
        }

        root_type_ptr right_ptr() const {
            return right_;
        }

        T right() const {
            return *right_;
        }

        bool is_max() const {
            return right_ && (*right_ == max);
        }

        bool empty() const {
            return (right_ && left_ && (*right_<*left_));
        }

        bool single() const {
            return (right_ && left_ && (*right_ == *left_));
        }

        bool semi() const {
            return ((left_semi()) || (right_semi()));
        }

        bool left_semi() const {
            return ((right_ && !left_ && (*right_ != max)) || (left_ && (*left_ == min) && right_ && (*right_ != max)));
        }

        bool right_semi() const {
            return ((!right_ && left_ && (*left_ != min)) || (right_ && (*right_ == max) && left_ && (*left_ != min)));
        }

        bool all() const {
            return ((!right_ && !left_) || (((left_) && (*left_ == min)) && ((right_) && (*right_ == max))));
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

        friend bool operator==(const self_type& l, const self_type& r) {
            if (l.empty() && r.empty())
                return true;
            if (l.all() && r.all())
                return true;
            bool leq = (l.left_ && r.left_) ? (*(l.left_) == *(r.left_)) : ((!l.left_ && !r.left_) ? true : false);
            bool req = (l.right_ && r.right_) ? (*(l.right_) == *(r.right_)) : ((!l.right_ && !r.right_) ? true : false);
            return (leq && req);
        }

        friend bool operator<(const self_type& l, const self_type& r) {
            if (l.empty() && r.empty())
                return false;
            if (l.all() && r.all())
                return false;
            if (l.left_ && r.left_ && (*l.left_ != *r.left_))
                return *l.left_ < *r.left_;
            if (l.left_ && !r.left_)
                return false;
            if (!l.left_ && r.left_)
                return true;
            if (l.right_ && r.right_ && (*l.right_ != *r.right_))
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

        friend self_type operator&(const self_type& l, const self_type& r) {
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

        friend range_container_type operator|(const self_type& l, const self_type& r) {
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

        friend range_container_type operator|(const range_container_type& l, const self_type& r) {
            return l | (r.operator range_container_type());
        }

        friend range_container_type operator-(const range_container_type& l, const self_type& r) {
            return l - (r.operator range_container_type());
        }

        friend range_container_type operator&(const self_type& l, const range_container_type& r) {
            return r & l;
        }

        friend range_container_type operator|(const self_type& l, const range_container_type& r) {
            return r | l;
        }

        friend range_container_type operator-(const self_type& l, const range_container_type& r) {
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

        friend range_container_type operator|(const range_container_type& l, const range_container_type& r) {
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


        root_type_ptr left_;
        root_type_ptr right_;
    };

    template<typename T>
    const T range<T>::min = std::numeric_limits<T>::min();

    template<typename T>
    const T range<T>::max = std::numeric_limits<T>::max();








    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  range_constraints
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

    template<typename T>
    class range_constraints {

    public:

        typedef range_constraints<T> self_type;
        typedef range<T> range_type;
        typedef typename range_type::range_container_type container_type;

        range_constraints() {
            range_.push_back(range_type::create_all());
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
            expention_ = e ? range_type::create_all() : range_type::create_empty();
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
                expention_ = e ? range_type::create_all() : range_type::create_empty();
            }
        }

        range_constraints(const container_type& vl, bool e = false) : range_(vl) {
            expention_ = e ? range_type::create_all() : range_type::create_empty();
        }

        container_type& set() {
            return range_;
        }

        const container_type& set() const {
            return range_;
        }

        bool single() const {
            return ((range_.size() == 1) && (range_.front().single()));
        }

        bool semi() const {
            return ((left_semi()) || (right_semi()));
        }

        bool left_semi() const {
            return ((range_.size() == 1) && (range_.front().left_semi()));
        }

        bool right_semi() const {
            return ((range_.size() == 1) && (range_.front().right_semi()));
        }

        bool has_main() const {
            return (range_.size());
        }

        range_type main() const {
            return (range_.size()) ? range_.front() : range_type();
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
            expention_ = range_type::create_all();
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

        bool effective() {
            return ((!all()) || (has_extention()));
        }

        bool empty() {
            if (range_.empty())
                return true;
            container_type tmp = range_type::normalize(range_);
            return ((tmp.size() == 1) && (tmp.front().empty()));
        }

        self_type to_per() {
            range_ = range_type::normalize(range_);
            if ((range_.empty()) || (empty()))
                return self_type(range_type::create_empty());
            if (all())
                return self_type();
            container_type tmp = range_type::normalize(range_);
            typename range_type::root_type_ptr lptr;
            typename range_type::root_type_ptr rptr;
            for (typename container_type::const_iterator it = range_.begin(); it != range_.end(); ++it) {
                typename container_type::const_iterator nxt = it + 1;
                if (it == range_.begin())
                    lptr = it->left_ptr();
                if (nxt == range_.end())
                    rptr = it->right_ptr();
            }
            return self_type(range_type(lptr, rptr), has_extention());
        }

        self_type to_alphabet_per() {
            range_ = range_type::normalize(range_);
            if ((range_.empty()) || (empty()))
                return self_type(range_type::create_empty());
            if (all())
                return self_type();
            clear_extention();
            return *this;
        }

        bool include(const self_type& vl) const {
            return (container_type(range_) & container_type(vl.range_)) == container_type(vl.range_);
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


    std::ostream& operator<<(std::ostream& stream, const quadruple& vl);

    std::ostream& operator<<(std::ostream& stream, const tuple& vl);

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
        std::size_t cnt = 1;
        for (typename std::vector<range<T> >::const_iterator it = vl.begin(); it != vl.end(); ++it) {
            stream << *it;
            if (cnt++ > 10)
                return stream << " ... more folllow element full size =" << vl.size();
        }
        return stream;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const range_constraints<T>& vl) {
        stream << "(" << vl.set() << " ";
        if (vl.has_extention()) {
            stream << " ...ext...)";
        }
        return stream;
    }



    typedef range_constraints<int64_t> integer_constraints;
    typedef integer_constraints::range_type integer_range;
    typedef boost::shared_ptr<integer_constraints> integer_constraints_ptr;

    typedef range_constraints<std::size_t> size_constraints;
    typedef size_constraints::range_type size_range;
    typedef boost::shared_ptr<size_constraints> size_constraints_ptr;

    typedef range_constraints<std::string::value_type> char8_constraints;
    typedef char8_constraints::range_type char8_range;
    typedef boost::shared_ptr<char8_constraints> char8_constraints_ptr;

    typedef range_constraints<quadruple> quadruple_constraints;
    typedef quadruple_constraints::range_type quadruple_range;
    typedef boost::shared_ptr<quadruple_constraints> quadruple_constraints_ptr;

    typedef range_constraints<tuple> tuple_constraints;
    typedef tuple_constraints::range_type tuple_range;
    typedef boost::shared_ptr<tuple_constraints> tuple_constraints_ptr;



}

namespace std {

    template<>
    struct numeric_limits<x680::quadruple> {

        static x680::quadruple min() {
            return x680::NULL_QUADRUPLE;
        }

        static x680::quadruple max() {
            return x680::MAX_QUADRUPLE;
        }

    };

    template<>
    struct numeric_limits<x680::tuple> {

        static x680::tuple min() {
            return x680::NULL_TUPLE;
        }

        static x680::tuple max() {
            return x680::MAX_TUPLE;
        }

    };

}

#endif	/* CONSTRAINT_TEMPLATES_H */

