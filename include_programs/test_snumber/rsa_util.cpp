/* 
 * File:   rsa_util.cpp
 * Author: sealeks@mail.ru
 * 
 * Created on 26 Октябрь 2013 г., 20:11
 */

#include "rsa_util.h"

namespace rsa_util {

    boost::random::random_device randevice;

    size_num rand_digit() {
        return randevice() % 10;
    }

    size_num rand_range(size_num min, size_num max) {
        return (max == min) ? min : ((max > min) ?
                (min + randevice() % (max - min)) : (max + randevice() % (min - max)));
    }
    
size_num rand_number(){
    return randevice();
}    



}
