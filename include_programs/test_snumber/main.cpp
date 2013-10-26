/*=============================================================================
    Copyright (c) 2002-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
///////////////////////////////////////////////////////////////////////////////
//
//  A parser for arbitrary tuples. This example presents a parser
//  for an employee structure.
//
//  [ JDG May 9, 2007 ]
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>    



#include "rsa_util.h"

/*using boost::multiprecision::backends::cpp_int_backend;
typedef boost::multiprecision::number<cpp_int_backend<4096, 4096, boost::multiprecision::signed_magnitude, boost::multiprecision::unchecked, void> >  int4096_t;

typedef int4096_t  numtype;
//typedef boost::multiprecision::int1024_t  numtype;
typedef std::size_t size_num;

struct rsa_key {
    numtype mod;
    numtype e;
    numtype d;
};


boost::random::random_device randevice;

int rand_digit(){
    return randevice() % 10;
}

size_num rand_range(size_num min, size_num max){
    return (max==min)  ? min :  ((max>min) ? 
        (min + randevice() % (max - min)) : (max + randevice() % (min - max)));
}

unsigned int rand_number(){
    return randevice();
}

size_num size_in_bit(numtype val) {
    size_num rslt = 0;
    if (!val)
        return 0;
    rslt = 1;
    while (val /= 2)
        rslt++;
    return rslt;
}


numtype random_by_bit(size_num bitnum){      
    numtype rslt = 1;
    numtype rnd = rand_number();
    while(size_in_bit(rslt)<bitnum){
        size_num j=size_in_bit(rnd);
        while(j--)
            rslt*=2;
         rslt += rnd;
         rnd = rand_number();}
    while (size_in_bit(rslt)>bitnum)
        rslt/=2;  
    return rslt;
}

numtype random_by_bit_odd(size_num bitnum){
    numtype tmp =random_by_bit(bitnum);
    return tmp % 2 ? tmp :  (tmp+1);
}

numtype random_by_bit_range(size_num min, size_num max){
    return random_by_bit(rand_range(min,max));
}




numtype gcd(numtype val1, numtype val2) {
    numtype& a = (val1>val2) ? val1 : val2;
    numtype& b = (val1>val2) ? val2 : val1;
    numtype k = a % b;
    while(k){
        a=b;
        b=k;
        k = a % b;
    }
    return b;
}


numtype ext_gcd(numtype val1, numtype val2, numtype& x, numtype& y)
{
   numtype& a = (val1>val2) ? val1 : val2;
   numtype& b = (val1>val2) ? val2 : val1;
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

bool find_besu(numtype e, numtype mod,  numtype& d)
{
    if (mod<e)
        throw 2;
    numtype y=0;
    return (ext_gcd(mod, e ,y,d)==1);
}

numtype pow_modulo(numtype a, numtype k, numtype mod) {
    numtype rslt = 1;
    while (k) {
        a %=mod;
        if ( k % 2 == 0) {
            k /= 2;
             a*=a;
             a %=mod;
        } else {
            k--;
            rslt %=mod;
            rslt*=a;
            rslt %=mod;
        }
    }
    return rslt;
}



bool primetest(numtype val){
    numtype t = val -1;
    numtype s = 1;
    while (t % 2){
        t /=2;
        s++;
    }
    size_num sz = size_in_bit(val);
    numtype a =random_by_bit_range(sz-20, sz-15);
    if (!(a%2))
        a++;
    numtype rsl = pow_modulo(a, t, val);
    if (!((rsl==1) || (rsl==t))  && s)
        while(s--)
            rsl = pow_modulo(rsl, 2, val);
    return (rsl==1) || (rsl==t); 
}


bool primetest_multi(numtype val){
    numtype rnd =  size_in_bit(val)+20;
    while((rnd--)){
        if (!primetest(val))
            return false;
    }
    return true;
}

numtype find_prime(size_num sz) {
    for (int i = 0; i < 10000; i++) {
        numtype v1 = random_by_bit_odd(sz);
        if (primetest_multi(v1)) {
            return v1;
        }
    }
        throw 1;
}

rsa_key key_creator(size_num sz){
    size_num sig =rand_range(0, sz /40);
    size_num size1 =sz / 2 +sig;
    size_num size2 =sz - size1;
    numtype q = find_prime(size1);
    std::cout << "find first prime : " <<q << " size_in_bit(q) =" <<size_in_bit(q) << std::endl;
    numtype p = find_prime(size2);
    std::cout << "find second prime : " <<p    << " size_in_bit(p) =" <<size_in_bit(p) << std::endl;    
    numtype mod = q *  p;
    std::cout << "fi modulo : " <<mod  << " size_in_bit(mod) =" <<size_in_bit(mod) << std::endl; 
    numtype fi = (q-1) *  (p-1);
    std::cout << "fi eiler : " << fi  << std::endl; 
    numtype e = random_by_bit_range(sz /2 , sz* 6 / 10);
    numtype d = 0;
    while(!find_besu(e, fi , d))
         e = random_by_bit_range(sz /2 , sz* 6 / 10);
    if (d<0)
        d=d+fi;
    std::cout << "find e : " <<e << "find d : " <<d << std::endl;
    rsa_key key;
    key.mod =mod;
    key.d=d;
    key.e=e;
    return key;
}

void test_key(const rsa_key& key, size_num sz){
    numtype text = random_by_bit_range(sz /2 , sz* 9 / 10);
    std::cout << "text  : " << text << std::endl;
    numtype encript = pow_modulo(text, key.e, key.mod);
    std::cout << "encript : " << encript << std::endl;
   numtype decript = pow_modulo(encript, key.d, key.mod);
    std::cout << "encript : " << decript  << std::endl;    
    if (text==decript)
        std::cout << "sucsess!! " <<  std::endl; 
}*/

typedef  rsa_util::util<2048> util_RSA;
typedef  util_RSA::key_type   key_type512;
typedef  util_RSA::keypair_type   keypair_type512;
    
int
main()
{


    
   keypair_type512 K = util_RSA::key_creator(); 
   //std::cout << "size_in_bit(key) =" <<size_in_bit(K.open().exponent())  << std::endl;   
   std::cout << "Key =" <<K<< std::endl;   
   util_RSA::test_key(K);

    

    
    return 0;
}