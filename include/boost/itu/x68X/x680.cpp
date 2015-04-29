//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/x680.hpp>

namespace x680 {
    namespace syntactic {

        position_iterator::position_iterator(const supertype& s) :
        supertype(s), base_(new supertype(s)), pos_(new difference_type(0)) {
        }

        position_iterator&
        position_iterator::operator++() {
            return *this = private_ctr(++super(), base_, pos_);
        }

        position_iterator
        position_iterator::operator++(int a) {
            return private_ctr(super()++, base_, pos_);
        }

        position_iterator&
        position_iterator::operator--() {
            return *this = private_ctr(--super(), base_, pos_);
        }

        position_iterator
        position_iterator::operator--(int a) {
            return private_ctr(super()--, base_, pos_);
        }

#ifdef __GNUC__    

        position_iterator&
                position_iterator::operator+=(const difference_type& n) {
            return *this = private_ctr(super() + n, base_, pos_);
        }

        position_iterator
        position_iterator::operator+(const difference_type& n) const {
            return private_ctr(super(), base_, pos_);
        }

        position_iterator&
                position_iterator::operator-=(const difference_type& n) {
            return *this = private_ctr(super() - n, base_, pos_);
        }

        position_iterator
        position_iterator::operator-(const difference_type& n) const {
            return private_ctr(super(), base_, pos_);
        }

#endif

        position_iterator::supertype&
        position_iterator::super() const {
            return (supertype&) (*this);
        }

        position_iterator::supertype&
        position_iterator::base() const {
            return *base_;
        }

        position_iterator::difference_type
        position_iterator::pos() const {
            return *pos_;
        }

        void position_iterator::checkpos() const {
            if ((super() - base()) > pos())
                *pos_ = super() - base();
        }

        position_iterator position_iterator::private_ctr(const supertype& s, supertypeptr b, differenceptr p) const {
            checkpos();
            position_iterator tmp(s);
            tmp.base_ = b;
            tmp.pos_ = p;
            return tmp;
        }



        ///   synxtas_error  

        synxtas_error::synxtas_error(const std::string& file, const std::string& src, std::size_t ps) :
        filepos_(ps), linepos_(0), linenum_(0), file_(file) {
            linepos_ = build(src, ps, linenum_, line_);
        }

        std::size_t synxtas_error::build(const std::string& src, std::size_t pos, std::size_t& symb, std::string& line) {
            std::size_t rslt = 0;
            symb = 0;
            std::string::size_type it = 0, itl = 0, ita = 0, itd = 0;
            while ((it < pos) && (it != std::string::npos)) {
                itl = it;
                ita = src.find_first_of('\x0a', it);
                itd = src.find_first_of('\x0d', it);
                if ((ita != std::string::npos) && (itd != std::string::npos)) {
                    it = ((ita < itd) || ((ita - itd) == 1)) ? ita : itd;
                } else {
                    if (ita != std::string::npos)
                        it = ita;
                    if (itd != std::string::npos)
                        it = itd;
                    if ((ita == std::string::npos) && (itd == std::string::npos))
                        it = std::string::npos;
                }
                if (((it == std::string::npos) && (pos < src.size())) || (it > pos))
                    it = pos;
                rslt++;
                if (it != std::string::npos) {
                    it++;
                    it = it < src.size() ? it : std::string::npos;
                } else
                    symb = 0;
                line = src.substr(itl, it == std::string::npos ? std::string::npos : (it - itl));
                symb = (it == std::string::npos ? 0 : (it - itl));
            }
            return rslt; // = rslt ? rslt - 1 : rslt;
        }

        std::ostream& operator<<(std::ostream& stream, const synxtas_error& self) {
            stream << "Synxtas error in file: " << self.file() << " pos(" << self.filepos() << ")." << '\n';
            stream << "line: " << self.linepos() << " lpos:" << self.linenum() << "." << '\n';
            stream << "string: '" << self.line() << "'" << '\n';
            return stream;
        }


    }
}