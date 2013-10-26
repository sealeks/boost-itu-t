/* 
 * File:   rsa_util.h
 * Author: sealeks@mail.ru
 *
 * Created on 26 Октябрь 2013 г., 20:11
 */

#ifndef RSA_UTIL_H
#define	RSA_UTIL_H

#include <iostream>
#include <string>
#include <algorithm>    

#include <cstddef>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_int/cpp_int_config.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/random_device.hpp>

namespace rsa_util {

    typedef std::size_t size_num;
    using boost::multiprecision::backends::cpp_int_backend;
    using boost::multiprecision::signed_magnitude;
    using boost::multiprecision::unchecked;

    extern boost::random::random_device randevice;

    size_num rand_digit();

    size_num rand_range(size_num min, size_num max);

    size_num rand_number();

    template < size_num SIZE >
    class rsa_key {

    public:

        typedef boost::multiprecision::number<cpp_int_backend<SIZE*2, SIZE*2, signed_magnitude, unchecked, void> > numtype;

        rsa_key(const numtype& mod, const numtype& exp) :
        modulo_(mod), exponent_(exp) {
        }

        virtual ~rsa_key() {
        }

        numtype modulo() const {
            return modulo_;
        }

        numtype exponent() const {
            return exponent_;
        }

        static size_num size() {
            return SIZE;
        }

    private:

        numtype modulo_;
        numtype exponent_;
    };

    template < size_num SIZE >
    class rsa_keypair {

    public:

        typedef rsa_key<SIZE> key_type;
        typedef boost::multiprecision::number<cpp_int_backend<SIZE*2, SIZE*2, signed_magnitude, unchecked, void> > numtype;

        rsa_keypair(const key_type& opn, const key_type& prv) :
        open_(opn), privated_(prv) {
        }
        
        rsa_keypair(const numtype& mod, const numtype& e, const numtype& d) :
        open_(key_type(mod,e)), privated_(key_type(mod,d)) {
        }        

        virtual ~rsa_keypair() {
        }

        key_type open() const {
            return open_;
        }

        key_type privated() const {
            return privated_;
        }

        static size_num size() {
            return SIZE;
        }


    private:

        key_type privated_;
        key_type open_;
    };

    template < size_num SIZE >
    struct util {

        typedef rsa_key<SIZE> key_type;
        typedef rsa_keypair<SIZE> keypair_type;
        typedef boost::multiprecision::number<cpp_int_backend<SIZE*2, SIZE*2, signed_magnitude, unchecked, void> > numtype;

        static size_num size_in_bit(numtype val) {
            size_num rslt = 0;
            if (!val)
                return 0;
            rslt = 1;
            while (val /= 2)
                rslt++;
            return rslt;
        }

        static numtype random_by_bit(size_num bitnum) {
            numtype rslt = 1;
            numtype rnd = rand_number();
            while (size_in_bit(rslt) < bitnum) {
                size_num j = size_in_bit(rnd);
                while (j--)
                    rslt *= 2;
                rslt += rnd;
                rnd = rand_number();
            }
            while (size_in_bit(rslt) > bitnum)
                rslt /= 2;
            return rslt;
        }

        static numtype random_by_bit_odd(size_num bitnum) {
            numtype tmp = random_by_bit(bitnum);
            return tmp % 2 ? tmp : (tmp + 1);
        }

        static numtype random_by_bit_range(size_num min, size_num max) {
            return random_by_bit(rand_range(min, max));
        }

        static numtype gcd(numtype val1, numtype val2) {
            numtype& a = (val1 > val2) ? val1 : val2;
            numtype& b = (val1 > val2) ? val2 : val1;
            numtype k = a % b;
            while (k) {
                a = b;
                b = k;
                k = a % b;
            }
            return b;
        }

        static numtype ext_gcd(numtype val1, numtype val2, numtype& x, numtype& y) {
            numtype& a = (val1 > val2) ? val1 : val2;
            numtype& b = (val1 > val2) ? val2 : val1;
            numtype q, r;
            numtype x2 = 1;
            numtype x1 = 0;
            numtype y2 = 0;
            numtype y1 = 1;
            while (b) {
                q = a / b, r = a - q * b;
                x = x2 - q * x1, y = y2 - q * y1;
                a = b, b = r;
                x2 = x1, x1 = x, y2 = y1, y1 = y;
            }
            x = x2, y = y2;
            return a;
        }

        static bool find_besu(numtype e, numtype mod, numtype& d) {
            if (mod < e)
                throw 2;
            numtype y = 0;
            return (ext_gcd(mod, e, y, d) == 1);
        }

        static numtype pow_modulo(numtype a, numtype k, numtype mod) {
            numtype rslt = 1;
            while (k) {
                a %= mod;
                if (k % 2 == 0) {
                    k /= 2;
                    a *= a;
                    a %= mod;
                } else {
                    k--;
                    rslt %= mod;
                    rslt *= a;
                    rslt %= mod;
                }
            }
            return rslt;
        }

        static bool primetest(numtype val) {
            numtype t = val - 1;
            numtype s = 1;
            while (t % 2) {
                t /= 2;
                s++;
            }
            size_num sz = size_in_bit(val);
            numtype a = random_by_bit_range(sz - 20, sz - 15);
            if (!(a % 2))
                a++;
            numtype rsl = pow_modulo(a, t, val);
            if (!((rsl == 1) || (rsl == t)) && s)
                while (s--)
                    rsl = pow_modulo(rsl, 2, val);
            return (rsl == 1) || (rsl == t);
        }

        static bool primetest_multi(numtype val) {
            numtype rnd = 1;//size_in_bit(val) + 20;
            while ((rnd--)) {
                if (!primetest(val))
                    return false;
            }
            return true;
        }

        static numtype find_prime(size_num sz) {
            for (int i = 0; i < 10000; i++) {
                numtype v1 = random_by_bit_odd(sz);
                if (primetest_multi(v1)) {
                    std::cout << "Try count : " << i  << std::endl;
                    return v1;
                }
            }
            throw 1;
        }

        static keypair_type key_creator() {
            size_num sig = rand_range(0, SIZE / 40);
            size_num size1 = SIZE / 2 + sig;
            size_num size2 = SIZE - size1;
            numtype q = find_prime(size1);
            std::cout << "find first prime : " << q << " size_in_bit(q) =" << size_in_bit(q) << std::endl;
            numtype p = find_prime(size2);
            std::cout << "find second prime : " << p << " size_in_bit(p) =" << size_in_bit(p) << std::endl;
            numtype mod = q * p;
            std::cout << "fi modulo : " << mod << " size_in_bit(mod) =" << size_in_bit(mod) << std::endl;
            numtype fi = (q - 1) * (p - 1);
            std::cout << "fi eiler : " << fi << std::endl;
            size_num sz=size_in_bit(fi);
            numtype e = random_by_bit_range(sz / 2, sz * 6 / 10);
            numtype d = 0;
            while (!find_besu(e, fi, d))
                e = random_by_bit_range(sz / 2, sz * 6 / 10);
            if (d < 0)
                d = d + fi;
            std::cout << "find e : " << e << "find d : " << d << std::endl;
            return keypair_type(mod,e,d);
        }

        static void test_key(const keypair_type& keyp) {
            numtype text = random_by_bit_range(SIZE / 2, SIZE * 9 / 10);
            std::cout << "text  : " << text << std::endl;
            numtype encript = pow_modulo(text, keyp.open().exponent(), keyp.open().modulo());
            std::cout << "cript : " << encript << std::endl;
            numtype decript = pow_modulo(encript, keyp.privated().exponent(), keyp.privated().modulo());
            std::cout << "encript : " << decript << std::endl;
            if (text == decript)
                std::cout << "sucsess!! " << std::endl;
        }
        
    };
    
    template < size_num SIZE >
    std::ostream& operator<<(std::ostream& stream, const rsa_keypair<SIZE>& self){
        stream  << "Open key: " << self.open() << "\n";
        stream  << "Private key: " << self.privated() << "\n";
        return stream;
    }
    
    template < size_num SIZE >
    std::ostream& operator<<(std::ostream& stream, const rsa_key<SIZE>& self){
        stream << "RSA-" << self.size()  << ":\n";
        stream  << "  modulo: " << self.modulo() << "\n";
        stream  << "  exponent: " << self.exponent() << "\n";
        return stream;      
    }    
    


}

#endif	/* RSA_UTIL_H */

