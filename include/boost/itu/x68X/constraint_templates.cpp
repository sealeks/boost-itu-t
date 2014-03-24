/* 
 * File:   constraint_templates.cpp
 * Author: sealeks@mail.ru
 * 
 * Created on 12 Март 2014 г., 15:01
 */

#include "constraint_templates.h"

namespace x680 {

    std::ostream& operator<<(std::ostream& stream, const quadruple & vl) {
        return stream << "{" << static_cast<int>(vl.group) << " , " << static_cast<int>(vl.plane) << " , " << static_cast<int>(vl.row) << " , " << static_cast<int>(vl.cell) << "}";
    }

    std::ostream& operator<<(std::ostream& stream, const tuple & vl) {
        return stream << "{" << static_cast<int>(vl.tablecolumn) << " , " << static_cast<int>(vl.tablerow) << "}";
    }
}
