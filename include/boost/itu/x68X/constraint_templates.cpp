/* 
 * File:   constraint_templates.cpp
 * Author: sealeks@mail.ru
 * 
 * Created on 12 Март 2014 г., 15:01
 */

#include "constraint_templates.h"

namespace x680 {

    std::ostream& operator<<(std::ostream& stream, const quadruple & vl) {
        return stream << "{" << vl.group << " , " << vl.plane << " , " << vl.row << " , " << vl.cell << "}";
    }

    std::ostream& operator<<(std::ostream& stream, const tuple & vl) {
        return stream << "{" << vl.tablecolumn << " , " << vl.tablerow << "}";
    }
}
