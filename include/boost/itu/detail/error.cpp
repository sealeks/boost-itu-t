//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/detail/error.hpp>

namespace boost {
    namespace itu {

        error_code errorcode_by_reason(octet_type val) {
            switch (val) {
                case DR_REASON_CONGST: return ER_EAGAIN;
                case DR_REASON_ADDRESS: return ER_NAADDRESS;
                case DR_REASON_NORM: return ER_RELEASE;
                case DR_REASON_RCNGS: return ER_REQBUSY;
                case DR_REASON_NEGOT: return ER_REQBUSY;
                default:
                {
                }
            }
            return ER_PROTOCOL;
        }

    }
}
