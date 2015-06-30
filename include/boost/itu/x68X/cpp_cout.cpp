//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/cpp_cout.hpp>
#include <boost/itu/asn1/utf8.hpp>


namespace x680 {
    namespace cpp {

        namespace fsnsp = boost::filesystem;
        
        
        //////////////////////////////////////////////////////
        //  typeval_manager
        //////////////////////////////////////////////////////          

        void typeval_manager::push(namedtypeassignment_entity_ptr tas, value_atom_ptr val) {
            stack_.push_back(typeasmt_value_atom(tas, val));
            //std::cout << "typeval_manager PUSH: " << (tas ? tas->name()  : " ???? ")  << std::endl;
        }

        void typeval_manager::pop() {
            if (!stack_.empty())
                stack_.erase(stack_.begin()+(stack_.size() - 1));
            //std::cout << "typeval_manager POP"  << std::endl;            
        }

        void typeval_manager::add() {
            valueslines_.push_back(stack_);
            if (!stack_.empty())
                std::cout << "typeval_manager ADD: " <<
                    (stack_.back().typeassignment() ? stack_.back().typeassignment()->name() : " ???? ") << std::endl;  
        }
        
        
        //////////////////////////////////////////////////////
        //  main func
        //////////////////////////////////////////////////////        

        void test_out(std::ofstream& stream, const member_vect& vct) {
            stream << "\n";
            stream << "test declare\n";
            for (member_vect::const_iterator it = vct.begin(); it != vct.end(); ++it) {
                stream << "\n" << (it->name) << " - " << (it->typenam) << " - " << (it->enm);
            }
            stream << "\n";
        }

        const std::set<std::string>& token_base() {
            static std::set<std::string> base_;
            if (base_.empty()) {
                base_.insert("class");
                base_.insert("struct");
                base_.insert("union");
                base_.insert("typedef");
                base_.insert("unsigned");
                base_.insert("bool");
                base_.insert("int");
                base_.insert("for");
                base_.insert("switch");
                base_.insert("case");
                base_.insert("return");
                base_.insert("const");
                base_.insert("static");
                base_.insert("volatile");
                base_.insert("namespace");
                base_.insert("typename");
                base_.insert("if");
                base_.insert("else");
                base_.insert("do");
                base_.insert("while");
                base_.insert("default");
                base_.insert("try");
                base_.insert("catch");
                base_.insert("void");
                base_.insert("bit_string");
                base_.insert("octet_string");
                base_.insert("null_type");
                base_.insert("oid_type");
                base_.insert("object_descriptor");
                base_.insert("external_type");
                base_.insert("double");
                base_.insert("enumerated");
                base_.insert("embeded_pdv");
                base_.insert("reloid_type");
                base_.insert("numeric_string");
                base_.insert("printable_string");
                base_.insert("t61_string");
                base_.insert("videotex_string");
                base_.insert("ia5_string");
                base_.insert("utctime");
                base_.insert("gentime");
                base_.insert("graphic_string");
                base_.insert("visible_string");
                base_.insert("general_string");
                base_.insert("universal_string");
                base_.insert("character_string");
                base_.insert("bmp_string");
                base_.insert("sequence_of");
                base_.insert("set_of");
            }
            return base_;
        }






        const std::string FHHEADER = "#include <boost/itu/asn1/asnbase.hpp>\n#include <boost/itu/x69X/x690.hpp>\n#include <boost/itu/x69X/x691.hpp>\n\n#ifdef _MSC_VER\n#pragma warning(push)\n#pragma warning(disable: 4065)\n#endif\n\n";
        const std::string FHBOTTOM = "\n\n#ifdef _MSC_VER\n#pragma warning(pop)\n#endif\n\n#endif";
        const std::string CHHEADER = "\n#ifdef _MSC_VER\n#pragma warning(push)\n#pragma warning(disable: 4065)\n#endif\n\n";
        const std::string CHBOTTOM = "\n\n#ifdef _MSC_VER\n#pragma warning(pop)\n#endif\n";
        const std::string MNDCL = "    ITU_T_USE_UNIVESAL_DECL;\n";

        typeassignment_entity_ptr typeassignment_from_type(type_atom_ptr self) {
            //if (self->scope() && self->scope()->as_typeassigment())
            //return self->scope()->as_typeassigment();
            if (self->reff() && self->reff()->as_typeassigment())
                return self->reff()->as_typeassigment();
            return typeassignment_entity_ptr();
        }

        std::string correct_name(std::string vl) {
            const std::set<std::string>& base = token_base();
            return base.find(vl) != base.end() ? (vl + "V") : vl;
        }

        std::string nameconvert(std::string name) {
            boost::algorithm::replace_all(name, "-", "_");
            return correct_name(name);
        }

        std::string nameupper(std::string name) {
            if (!name.empty())
                return boost::algorithm::to_upper_copy(name.substr(0, 1)) + name.substr(1);
            return name;
        }

        std::string namelower(std::string name) {
            if (!name.empty())
                return boost::algorithm::to_lower_copy(name.substr(0, 1)) + name.substr(1);
            return name;
        }

        std::string argumentname(std::string name) {
            return "arg__" + name;
        }

        std::string tabformat(basic_entity_ptr selft, std::size_t delt, const std::string& tab) {
            assignment_entity_ptr self = selft ? selft->as_assigment() : assignment_entity_ptr();
            std::string rslt = tab;
            std::size_t inten = self ? (self->level() + delt) : delt;
            if (inten > 0) inten--;
            while (inten) {
                rslt += tab;
                inten--;
            }
            return rslt;
        }

        /* type in string*/

        std::string builtin_int_str(integer_constraints_ptr intconstr) {
            if (intconstr && (!intconstr->to_per().has_extention()) && (!intconstr->to_per().semi())) {
                integer_constraints::range_type main_int_cnstr = intconstr->to_per().main();
                if ((main_int_cnstr.left_ptr()) && (main_int_cnstr.right_ptr())) {
                    bool negat = main_int_cnstr.left() < 0;
                    if (negat) {
                        if ((main_int_cnstr.left() >= std::numeric_limits<boost::int8_t>::min()) &&
                                (main_int_cnstr.right() <= std::numeric_limits<boost::int8_t>::max()))
                            return "int8_t";
                        if ((main_int_cnstr.left() >= std::numeric_limits<boost::int16_t>::min()) &&
                                (main_int_cnstr.right() <= std::numeric_limits<boost::int16_t>::max()))
                            return "int16_t";
                        if ((main_int_cnstr.left() >= std::numeric_limits<boost::int32_t>::min()) &&
                                (main_int_cnstr.right() <= std::numeric_limits<boost::int32_t>::max()))
                            return "int32_t";
                        if ((main_int_cnstr.left() >= std::numeric_limits<boost::int64_t>::min()) &&
                                (main_int_cnstr.right() <= std::numeric_limits<boost::int64_t>::max()))
                            return "int64_t";
                    } else {
                        if (main_int_cnstr.right() <= std::numeric_limits<boost::uint8_t>::max())
                            return "uint8_t";
                        else if (main_int_cnstr.right() <= std::numeric_limits<boost::uint16_t>::max())
                            return "uint16_t";
                        else if (main_int_cnstr.right() <= std::numeric_limits<boost::uint32_t>::max())
                            return "uint32_t";
                        else if ((boost::uint64_t)main_int_cnstr.right() <= std::numeric_limits<boost::uint64_t>::max())
                            return "uint64_t";
                    }
                }
            }
            return "integer_type";
        }

        std::string builtin_str(defined_type tp, integer_constraints_ptr intconstr = integer_constraints_ptr()) {
            switch (tp) {
                case t_BOOLEAN: return "bool";
                case t_INTEGER: return builtin_int_str(intconstr); //"int";
                case t_BIT_STRING: return "bit_string";
                case t_OCTET_STRING: return "octet_string";
                case t_NULL: return "null_type";
                case t_OBJECT_IDENTIFIER: return "oid_type";
                case t_ObjectDescriptor: return "object_descriptor";
                case t_EXTERNAL: return "external_type";
                case t_REAL: return "double";
                case t_ENUMERATED: return "enumerated";
                case t_EMBEDDED_PDV: return "embeded_pdv";
                case t_UTF8String: return "utf8_string";
                case t_RELATIVE_OID: return "reloid_type";
                case t_NumericString: return "numeric_string";
                case t_PrintableString: return "printable_string";
                case t_T61String: return "t61_string";
                case t_VideotexString: return "videotex_string";
                case t_IA5String: return "ia5_string";
                case t_UTCTime: return "utctime";
                case t_GeneralizedTime: return "gentime";
                case t_GraphicString: return "graphic_string";
                case t_VisibleString: return "visible_string";
                case t_GeneralString: return "general_string";
                case t_UniversalString: return "universal_string";
                case t_CHARACTER_STRING: return "character_string";
                case t_BMPString: return "bmp_string";
                case t_TIME:
                case t_TIME_OF_DAY:
                case t_DATE:
                case t_DATE_TIME:
                case t_DURATION: return "printable_string";
                case t_OID_IRI: return "null_type";
                case t_ANY: return "any_type";
                case t_ClassField: return "any_type";
                default:
                {
                }
            }
            return "?type?";
        }

        std::string type_str(typeassignment_entity_ptr self, bool native) {
            if (self->isrefferrence())
                return nameupper(nameconvert(self->name()));
            else if (self->isstructure()) {
                typeassignment_entity_ptr ppas = self->scope() ?
                        self->scope()->as_typeassigment() : typeassignment_entity_ptr();
                std::string postfix = ""; //(ppas || native || (!self->tag())) ? "" : "_impl";
                if (ppas && (ppas->isstruct_of()))
                    return nameupper(type_str(ppas)+(ppas->builtin() == t_SEQUENCE_OF ? "_sequence_of" : "_set_of"));
                return nameupper(nameconvert(self->islocaldeclare() ? (self->name() + "_type") : self->name()) + postfix);
            } else
                return self->islocaldefined() ? builtin_str(self->builtin(), self->type() ?
                    (self->type()->integer_constraint()) : integer_constraints_ptr()) : nameupper(nameconvert(self->name()));
            return "";
        }

        std::string type_str(type_atom_ptr self, bool native) {
            if (typeassignment_entity_ptr tpas = typeassignment_from_type(self))
                return type_str(tpas, native);
            if (self->isprimitive())
                return builtin_str(self->root_builtin(), self ?
                    (self->integer_constraint()) : integer_constraints_ptr());
            return "?type?";
        }

        std::string fulltype_str(basic_entity_ptr self, bool withns, const std::string& delim) {
            if ((self->as_typeassigment()) || (self->as_module())) {
                if (self->as_module()) {
                    return withns ? nameconvert(self->name()) : "";
                } else if (self->as_typeassigment()) {
                    typeassignment_entity_ptr ppas = self->as_typeassigment();
                    std::string tmp = fulltype_str(self->scope(), withns, delim);
                    if (ppas->type())
                        return tmp.empty() ? type_str(ppas) : (tmp + delim + type_str(ppas));
                    else
                        return tmp;
                }
            }
            if (self->extract_type())
                return type_str(self->as_typeassigment());
            return "";
        }

        std::string fulltype_str(type_atom_ptr self, bool withns) {
            if (typeassignment_entity_ptr tpas = typeassignment_from_type(self))
                return fulltype_str(tpas, withns);
            if (self->isprimitive())
                return builtin_str(self->root_builtin(), self ?
                    (self->integer_constraint()) : integer_constraints_ptr());
            return "?type?";
        }

        std::string fullpathtype_str(typeassignment_entity_ptr self, typeassignment_entity_ptr root, std::string tp) {
            return self->islocaldeclare() ?
                    (fulltype_str(root, false) + "::" + tp) : fromtype_str(self);
        }

        std::string fromtype_str(typeassignment_entity_ptr self) {
            if (self->isrefferrence()) {
                typeassignment_entity_ptr frtp = (self->type()->reff() && self->type()->reff()->as_typeassigment()) ?
                        self->type()->reff()->as_typeassigment() : typeassignment_entity_ptr();
                if (self->shadow_for()
                        && self->shadow_for()->moduleref() != self->moduleref()
                        && self->shadow_for()->as_typeassigment())
                    frtp = self->shadow_for()->as_typeassigment();
                module_entity_ptr extmod = (frtp && (frtp->moduleref() != self->moduleref())) ? frtp->moduleref() : module_entity_ptr();
                std::string pref = extmod ? (nameconvert(extmod->name()) + "::") : "";
                return (pref + nameupper(nameconvert(self->type()->reff()->name())));
            } else if (self->isstructure())
                return type_str(self, true);
            else
                return builtin_str(self->builtin(), self->type() ?
                    (self->type()->integer_constraint()) : integer_constraints_ptr());

            return "?type?";
        }

        std::string fromtype_str(type_atom_ptr self) {
            if (self) {
                if ((self->reff()) && (self->reff()->as_typeassigment()) && (self->isrefferrence())) {
                    module_entity_ptr fmd = self->reff()->as_typeassigment()->moduleref();
                    return (fmd && (fmd != self->moduleref())) ?
                            (nameconvert(fmd->name()) + "::" + nameupper(nameconvert(self->reff()->name())))
                            : nameupper(nameconvert(self->reff()->name()));
                } else if (self->isstructure())
                    return "?type?";

                else
                    return builtin_str(self->builtin(), self->integer_constraint());
            }
            return "?type?";
        }

        bool fromtype_remote(typeassignment_entity_ptr self) {
            if (self->isrefferrence()) {
                typeassignment_entity_ptr frtp = ((self->type()->reff()) && (self->type()->reff()->as_typeassigment())) ?
                        self->type()->reff()->as_typeassigment() : typeassignment_entity_ptr();

                return ((frtp) && (frtp->moduleref() != self->moduleref()));
            }
            return false;
        }

        /* value in string*/

        std::string value_int_str(value_atom_ptr self) {
            if (self && (self->get_value<int64_t>()))
                return to_string(*(self->get_value<int64_t>()));
            return "?num?";
        }

        std::string value_null_str(value_atom_ptr self) {
            if (self && (self->get_value<null_initer>()))
                return "null_type()";
            return "?null?";
        }

        std::string value_bool_str(value_atom_ptr self) {
            if (self && (self->get_value<bool>()))
                return *(self->get_value<bool>()) ? "true" : "false";
            return "?bool?";
        }

        std::string value_real_str(value_atom_ptr self) {
            if (self && (self->get_value<double>())) {
                double tmp = *(self->get_value<double>());
                if (tmp != tmp)
                    return "std::numeric_limits<double>::quiet_NaN()";
                if (tmp == std::numeric_limits<double>::infinity())
                    return "std::numeric_limits<double>::infinity()";
                if (tmp == -std::numeric_limits<double>::infinity())
                    return " - std::numeric_limits<double>::infinity()";
                return to_string(*(self->get_value<double>()));
            }
            return "?real?";
        }

        std::string value_reff_str(defined_value_atom_ptr self) {
            if ((self->reff()) && (self->reff()->as_valueassigment())) {
                std::string rslt;
                typeassignment_entity_ptr tp = self->reff()->as_valueassigment()->scope() ?
                        self->reff()->as_valueassigment()->scope()->as_typeassigment() : typeassignment_entity_ptr();
                if (tp)
                    rslt = namelower(nameconvert(tp->name())) + "_";
                return rslt + nameconvert(self->reff()->as_valueassigment()->name());
            }
            return "?reff?";
        }

        template <typename T>
        static std::string num_to_hex(T vl) {
            std::string rslt;
            while (vl) {
                T tmp = vl & static_cast<T> ('\xF');
                if (tmp <= 9)
                    rslt = std::string::value_type('\x30' + static_cast<std::string::value_type> (tmp)) + rslt;
                else
                    rslt = std::string::value_type('\x41' + static_cast<std::string::value_type> (tmp - 10)) + rslt;
                if (vl < 0) {
                    vl >>= 1;
                    vl &= (~std::numeric_limits<T>::min());
                    vl >>= 3;
                } else
                    vl >>= 4;
            }
            return rslt.empty() ? "0" : rslt;
        }

        static std::string string_to_literal(const std::string& vl) {
            std::string rslt;
            if (!vl.empty())
                for (std::string::const_iterator it = vl.begin(); it != vl.end(); ++it)
                    rslt += ("\\x" + (num_to_hex<std::string::value_type>(*it)));
            return rslt;
        }

        static std::string string_to_literal(const std::wstring& vl) {
            std::string rslt;
            if (!vl.empty())
                for (std::wstring::const_iterator it = vl.begin(); it != vl.end(); ++it)
                    rslt += ("\\x" + (num_to_hex<std::wstring::value_type>(*it)));
            return rslt;
        }

        std::string value_chars8_str(value_atom_ptr self, bool cantuple) {
            if (cantuple && self->get_value<tuple>()) {
                boost::shared_ptr<tuple> tmp = self->get_value<tuple>();
                return "\"" +
                string_to_literal(std::string(1,
                        std::string::value_type(static_cast<std::string::value_type>
                        (tmp->tablecolumn * 16 + tmp->tablerow)))) +
                        "\"";
            } else if (self->get_value<std::string>()) {
                return "\"" +
                *(self->get_value<std::string>()) +
                        "\"";
            }
            return "?str?";
        }

        std::string value_chars16_str(value_atom_ptr self) {
            if (self->get_value<quadruple>()) {
                boost::shared_ptr<quadruple> tmp = self->get_value<quadruple>();
                return "L\'" +
                string_to_literal(std::wstring(1, std::wstring::value_type(static_cast<std::wstring::value_type> (tmp->row * 256 + tmp->cell)))) +
                        "')";
            }
            return "?wstr?";
        }

        std::string value_utfchar_str(const quadruple& self) {
            uint32_t tmp = 128 * self.group + 256 * self.plane + 256 * self.row + self.cell;
            std::string rslt;
            if (boost::asn1::quadrople_to_str(tmp, rslt))
                return rslt;
            return "?utfstr?";
        }

        std::string value_utfchars_str(value_atom_ptr self) {
            if (self->get_value<quadruple_vector>()) {
                boost::shared_ptr<quadruple_vector> tmp = self->get_value<quadruple_vector>();
                std::string rslt;
                for (quadruple_vector::const_iterator it = tmp->begin(); it != tmp->end(); ++it)
                    rslt += value_utfchar_str(*it);
                if (!rslt.empty())
                    return "\"" + string_to_literal(rslt) + "\"";
                else
                    return "\'\'";
            }
            return "?wstr?";
        }

        std::string value_enum_str(type_atom_ptr tp, value_atom_ptr self) {
            if (tp && self && (self->as_defined()) && (self->as_defined()->reff()))
                return namelower(fromtype_str(tp)) + "_" + nameconvert(self->as_defined()->reff()->name());
            return "?enum?";
        }

        value_atom_ptr value_skip_defined(value_atom_ptr self) {
            if (self->as_defined()) {
                if (self->as_defined()->reff())
                    if (self->as_defined()->reff()->as_valueassigment())
                        if (self->as_defined()->reff()->as_valueassigment()->value())
                            return value_skip_defined(self->as_defined()->reff()->as_valueassigment()->value());
                return value_atom_ptr();
            }
            return self;
        }

        bool value_oid_str(value_atom_ptr self, std::vector<std::string>& rslt) {
            if (self && self->get_value<unum_vector>()) {
                boost::shared_ptr<unum_vector> lst = self->get_value<unum_vector>();
                for (unum_vector::const_iterator it = lst->begin(); it != lst->end(); ++it)
                    rslt.push_back(to_string(*it));
                return true;
            }
            return false;
        }

        bool value_octets_str(value_atom_ptr self, std::vector<std::string>& rslt) {
            if (self && self->get_value<hstring_initer>()) {
                boost::shared_ptr<hstring_initer> lst = self->get_value<hstring_initer>();
                std::string ostr = lst->str;
                for (std::string::const_iterator it = ostr.begin(); it != ostr.end(); ++it)
                    rslt.push_back("'" + string_to_literal(std::string(it, it + 1)) + "'");
                return true;
            }
            return false;
        }

        bool value_bits_str(value_atom_ptr self, std::vector<std::string>& rslt, std::size_t& sz) {
            self = value_skip_defined(self);
            if (self && self->get_value<bstring_initer>()) {
                boost::shared_ptr<bstring_initer> lst = self->get_value<bstring_initer>();
                std::string bstr = lst->str;
                for (std::string::const_iterator it = bstr.begin(); it != bstr.end(); ++it)
                    rslt.push_back("'" + string_to_literal(std::string(it, it + 1)) + "'");
                sz = lst->unused;
                return true;
            }
            sz = 0;
            return value_octets_str(self, rslt);
        }

        std::string value_bits_str(value_atom_ptr self) {
            self = value_skip_defined(self);
            if (self->as_empty()) {
                return "";
            } else if (self->as_list()) {
                std::string rslt;
                for (value_vct::const_iterator it = self->as_list()->values().begin(); it != self->as_list()->values().end(); ++it) {
                    if (it != self->as_list()->values().begin())
                        rslt = " | ";
                    if ((*it)->as_defined())
                        rslt += value_reff_str((*it)->as_defined());
                    else
                        rslt += "?bitsting?";
                }
                return rslt;
            } else if (self->as_assign())
                return nameconvert(self->as_assign()->name());
            return "?bitsting?";
        }

        std::string print_initializer(const std::vector<std::string> vl) {
            std::string rslt;
            for (std::vector<std::string>::const_iterator it = vl.begin(); it != vl.end(); ++it) {
                if (it != vl.begin())
                    rslt += ", ";
                rslt += (*it);
            }
            return rslt;
        }

        std::string valueassmnt_str(type_atom_ptr tp, value_atom_ptr vl, const std::string& nm) {
            std::vector<std::string> vstr;
            std::size_t numbt = 0;
            switch (tp->root_builtin()) {
                case t_NULL: return value_null_str(vl);
                case t_INTEGER: return value_int_str(vl);
                case t_BOOLEAN: return value_bool_str(vl);
                case t_REAL: return value_real_str(vl);
                case t_ENUMERATED: return nested_init_str(tp, value_enum_str(tp, vl));
                case t_BIT_STRING: return (value_bits_str(vl, vstr, numbt)) ? ("bit_string({" + print_initializer(vstr) + "}, " + to_string(numbt) + ")"):
                    ("bit_string(" + value_bits_str(vl) + ")");
                case t_OCTET_STRING: return (value_octets_str(vl, vstr)) ? ("octet_string({" + print_initializer(vstr) + "})"): "octet_string({ ? ? })";
                case t_OBJECT_IDENTIFIER: return value_oid_str(vl, vstr) ? ("oid_type({" + print_initializer(vstr) + "})"): "oid_type({ ? ? })";
                case t_RELATIVE_OID: return value_oid_str(vl, vstr) ? ("reloid_type({" + print_initializer(vstr) + "})"): "reloid_type({ ? ? })";
                case t_NumericString:
                case t_PrintableString:
                case t_T61String:
                case t_VideotexString:
                case t_GraphicString:
                case t_VisibleString:
                case t_GeneralString:
                case t_ObjectDescriptor:
                case t_IA5String: return value_chars8_str(vl, tp->root_builtin() == t_IA5String);
                case t_BMPString:
                case t_UniversalString: return value_chars16_str(vl);
                case t_UTF8String: return value_utfchars_str(vl);
                default:
                {
                }
            }
            return "?";
        }

        std::string valueassmnt_str_ext(type_atom_ptr tp, value_atom_ptr vl, const std::string& nm) {
            std::string rslt;
            std::vector<std::string> arr;
            bool isreff = tp->isrefferrence();
            switch (tp->root_builtin()) {
                case t_OBJECT_IDENTIFIER:
                case t_RELATIVE_OID:
                {
                    if (value_oid_str(vl, arr)) {
                        rslt += "ITU_T_";
                        if (isreff)
                            rslt += "TP_";
                        rslt += ((tp->root_builtin() == t_OBJECT_IDENTIFIER) ? "OID( " : "RELOID( ");
                        if (isreff)
                            rslt += (fromtype_str(tp) + ", ");
                        rslt += (nm + " , ITU_T_VARRAY(  ");
                        rslt += print_initializer(arr);
                        return rslt += "))";
                    }
                    return nm + " ? ";
                    break;
                }
                case t_OCTET_STRING:
                {
                    if (value_octets_str(vl, arr)) {
                        if (!arr.empty()) {
                            rslt += (isreff ? ("ITU_T_TP_OCTETS( " + fromtype_str(tp) + ", ") : ("ITU_T_OCTETS( "));
                            rslt += (nm + " , ITU_T_VARRAY(  ");
                            rslt += print_initializer(arr);
                            return rslt += "))";
                        } else
                            return "const " + fromtype_str(tp) + " " + nm + " = " + fromtype_str(tp) + "()";
                    }
                    return nm + " =  ? ";
                    break;
                }
                case t_BIT_STRING:
                {
                    std::size_t numbt = 0;
                    if (value_bits_str(vl, arr, numbt)) {
                        if (!arr.empty()) {
                            rslt += (isreff ? ("ITU_T_TP_BITS( " + fromtype_str(tp) + ", ") : ("ITU_T_BITS( "));
                            rslt += (nm + " , ITU_T_VARRAY(  ");
                            rslt += print_initializer(arr);
                            return rslt += ("), " + to_string(numbt) + ")");
                        } else
                            return "const " + fromtype_str(tp) + " " + nm + " = " + fromtype_str(tp) + "()";
                    }
                    return "const " + fromtype_str(tp) + " " + nm + " = bit_string(" + value_bits_str(vl) + ")";
                    break;
                }
                default:
                {
                }
            }
            return nm + " = ? ";
        }
  

        std::string value_structure_str(typeassignment_entity_ptr tp, value_atom_ptr vl, std::size_t lev, typeval_manager_ptr vm) {
            switch (tp->root_builtin()) {
                case t_SET:
                case t_SEQUENCE:
                    if (tp->isrefferrence() && tp->type() && tp->type()->valuestructure())
                        tp = tp->type()->valuestructure();
                    return !lev ? (fulltype_str(tp) + "(" + value_struct_str(tp, vl, ++lev, vm) + ")") :
                            ("ITU_T_MAKE(" + fulltype_str(tp) + ")(" + value_struct_str(tp, vl, ++lev, vm) + ")");
                case t_CHOICE:
                    if (tp->isrefferrence() && tp->type() && tp->type()->valuestructure())
                        tp = tp->type()->valuestructure();
                    return !lev ? (fulltype_str(tp) + "(" + value_choice_str(tp, vl, ++lev, vm) + ")") :
                            ("ITU_T_MAKE(" + fulltype_str(tp) + ")(" + value_choice_str(tp, vl, ++lev, vm) + ")");
                case t_SET_OF:
                case t_SEQUENCE_OF: return !lev ? (fulltype_str(tp) + "(" + value_struct_of_str(tp, vl, ++lev, vm) + ")"):
                    ("ITU_T_MAKE(" + fulltype_str(tp) + ")(" + fulltype_str(tp) + "(" + value_struct_of_str(tp, vl, ++lev, vm) + "))");
                default:
                {
                    return value_structure_str(tp->type(), vl, ++lev, vm);
                }
            }
            return "()";
        }
        
        static bool iscomplexvalue_decl_static(defined_type tp) {
            switch (tp) {
                case t_BIT_STRING:
                case t_OCTET_STRING:
                case t_OBJECT_IDENTIFIER:
                case t_RELATIVE_OID: return true;
                default:
                {
                }
            }
            return false;
        }

        std::string value_structure_str(type_atom_ptr tp, value_atom_ptr vl, std::size_t lev, typeval_manager_ptr vm) {
            if (vm && iscomplexvalue_decl_static(tp->root_builtin())) {
                vm->add();
                return "ITU_T_MAKE(" + (tp->isprimitive() ? type_str(tp) : fromtype_str(tp)) + ")()";
            }
            return "ITU_T_MAKE(" + (tp->isprimitive() ? type_str(tp) : fromtype_str(tp)) + ")(" + valueassmnt_str(tp, vl) + ")";
        }

        std::string value_struct_str(typeassignment_entity_ptr tp, value_atom_ptr vl, std::size_t lev, typeval_manager_ptr vm) {
            basic_entity_ptr scp;
            if (tp) {
                std::string rslt = "";
                member_vect mmbr;
                load_member(mmbr, tp);
                if (boost::shared_ptr<namedvalue_initer_set> vlus = vl->get_value<namedvalue_initer_set>()) {
                    bool fst = true;
                    for (member_vect::const_iterator it = mmbr.begin(); it != mmbr.end(); ++it) {
                        if (fst)
                            fst = false;
                        else
                            rslt += (std::string(", \n") + tabformat(scp, 3 + lev));
                        namedvalue_initer_set::const_iterator fit = vlus->find(namedvalue_initer(it->typ->name()));
                        if (fit != vlus->end()) {
                            if (vm)
                                vm->push(it->typ, fit->val);                           
                            rslt += value_structure_str(it->typ, fit->val, lev, vm);
                            if (vm)
                                vm->pop();                             
                        } else {
                            rslt += ("ITU_T_SHARED(" + (it->typ->isprimitive() ? type_str(it->typ->type()) : fulltype_str(it->typ)) +
                                    ")(" + (it->marker == mk_none ? " ? " : "") + ")");
                        }
                    }
                }
                return rslt;
            }
            return "?";
        }

        static std::string value_struct_of_str_1(typeassignment_entity_ptr krnl, boost::shared_ptr<value_vct> vls, std::size_t lev) {
            std::string rslt = "";
            if (!vls->empty()) {
                rslt += "{";
                for (value_vct::const_iterator it = vls->begin(); it != vls->end(); ++it) {
                    if (it != vls->begin())
                        rslt += ", ";
                    rslt += valueassmnt_str(krnl->type(), *it);
                }
                rslt += " }";
            }
            return rslt;
        }

        static std::string value_struct_of_str_2(typeassignment_entity_ptr krnl, boost::shared_ptr<value_vct> vls, std::size_t lev) {
            std::string rslt = "";
            if (!vls->empty()) {
                rslt += "{";
                for (value_vct::const_iterator it = vls->begin(); it != vls->end(); ++it) {
                    if (it != vls->begin())
                        rslt += ", ";
                    rslt += value_structure_str(krnl, *it, 0);
                }
                rslt += " }";
            }
            return rslt;
        }

        std::string value_struct_of_str(typeassignment_entity_ptr tp, value_atom_ptr vl, std::size_t lev, typeval_manager_ptr vm) {
            if (tp) {
                if (vm) {
                    if (vl && !vl->as_empty())
                        vm->add();
                    return "";
                }
                if (typeassignment_entity_ptr krnl = tp->struct_of_kerrnel()) {
                    if (boost::shared_ptr<value_vct> vlus = vl->get_value<value_vct>()) {
                        switch (krnl->root_builtin()) {
                            case t_SEQUENCE:
                            case t_SET:
                            case t_SEQUENCE_OF:
                            case t_SET_OF:
                            case t_CHOICE: return value_struct_of_str_2(krnl, vlus, lev);
                            default:
                            {
                            }
                        }
                        return value_struct_of_str_1(krnl, vlus, lev);
                    }
                }
            }
            return "?";
        }

        std::string value_choice_str(typeassignment_entity_ptr tp, value_atom_ptr vl, std::size_t lev, typeval_manager_ptr vm) {
            std::string rslt;
            if (tp) {
                member_vect mmbr;
                load_member(mmbr, tp);
                if (vl->as_named() || vl->as_choice()) {
                    std::string name = vl->as_named() ? vl->as_named()->name() : 
                        vl->as_choice()->name();
                    value_atom_ptr value = vl->as_named() ? vl->as_named()->value() : 
                        vl->as_choice()->value();
                    for (member_vect::const_iterator it = mmbr.begin(); it != mmbr.end(); ++it) {
                        if (it->name == name) {
                            if (vm)
                                vm->push(it->typ, value);   
                            rslt=value_structure_str(it->typ, value, lev) + ", " +
                                    fulltype_str(tp, false) + "_" + nameconvert(name);
                            if (vm)
                                vm->pop();
                            return rslt;                             
                        }
                    }
                }
            }
            return "?";
        }

        declare_vect::iterator find_remote_reff(declare_vect& vct, const std::string& nm, declare_vect::iterator from) {
            for (declare_vect::iterator it = from; it != vct.end(); ++it)
                if (it->typenam == nm)
                    return it;
            return vct.end();
        }

        void resolve_remote_reff(declare_vect & vct) {
            bool fnd = true;
            while (fnd) {
                fnd = false;
                for (declare_vect::iterator it = vct.begin(); it != vct.end(); ++it) {
                    if (!it->remote_) {
                        declare_vect::iterator fit = find_remote_reff(vct, it->from_type, vct.begin());
                        if (fit != vct.end()) {
                            if (fit->remote_) {
                                it->remote_ = true;
                                fnd = true;
                            }
                        }
                    }
                }
            }
        }

        bool sort_reff(declare_vect & vct) {
            if (vct.size()) {
                declare_vect::iterator lit = vct.begin();
                while ((lit + 1) != vct.end()) {
                    for (declare_vect::iterator it = lit; it != vct.end(); ++it) {
                        declare_vect::iterator fit = find_remote_reff(vct, it->from_type, lit);
                        if (find_remote_reff(vct, it->from_type, lit) == vct.end()) {
                            std::swap(*it, *lit);
                            lit++;
                            break;
                        }
                        if ((it + 1) == vct.end())
                            return false;
                    }
                }
            }
            return true;
        }

        bool default_supported(typeassignment_entity_ptr self) {
            switch (self->root_builtin()) {
                case t_INTEGER:
                case t_BOOLEAN:
                case t_REAL:
                case t_ENUMERATED: return true;
                    /*case t_BIT_STRING:
                    case t_OCTET_STRING:                    
                    case t_OBJECT_IDENTIFIER:
                    case t_RELATIVE_OID: */
                default: return false;
            }
            return false;
        }

        std::string member_marker_str(const std::string& str, tagmarker_type self, const std::string& dflt, bool simple) {
            switch (self) {
                case mk_default:
                    return "default_holder<" + str + ", " + dflt + ">";
                case mk_optional:
                    return "shared_ptr<" + str + ">";
                default:
                    return simple ? str : ("value_holder<" + str + ">");
            }
            return str;
        }

        std::string struct_of_str(bool igsequence) {
            return igsequence ? "sequence_of" : "set_of";
        }

        std::string seqof_str(typeassignment_entity_ptr self, const std::string & name) {
            if (self->builtin() == t_SEQUENCE_OF)
                return "typedef " + struct_of_str(true) + "< " + name + "> ";
            else
                return "typedef " + struct_of_str(false) + "< " + name + "> ";
        }

        std::string choice_enum_str(typeassignment_entity_ptr self, basic_entity_ptr sub) {
            return type_str(self) + "_" + nameconvert(sub ? sub->name() : "");
        }

        std::string tagged_str(tagged_ptr self) {
            if ((self->number()) && (self->number()->as_number()))
                try {
                    return boost::lexical_cast<std::string > (self->number()->as_number()->value());
                } catch (boost::bad_lexical_cast) {
                }
            return "?tag?";
        }

        std::string tagged_str(canonical_tag_ptr self) {
            try {
                return boost::lexical_cast<std::string > (self->number());
            } catch (boost::bad_lexical_cast) {
            }
            return "";
        }

        std::string tagged_class_str(tagged_ptr self) {
            switch (self->_class()) {
                case tcl_application: return "APPLICATION_CLASS";
                case tcl_universal: return "UNIVERSAL_CLASS";
                case tcl_private: return "PRIVATE_CLASS";
                default:
                {
                }
            }
            return "CONTEXT_CLASS";
        }

        std::string tagged_class_str(canonical_tag_ptr self) {
            switch (self->_class()) {
                case tcl_application: return "APPLICATION_CLASS";
                case tcl_universal: return "UNIVERSAL_CLASS";
                case tcl_private: return "PRIVATE_CLASS";
                default:
                {
                }
            }
            return "CONTEXT_CLASS";
        }

        static std::string name_arch(const std::string& nm, tagmarker_type mkr) {
            switch (mkr) {
                case mk_exception: return "*(*" + nm + ")";
                    /*case mk_default: return nm + ".get_shared()"
                    case mk_none: return "*" + nm;*/;
                default:
                {
                }
            }
            return nm;
        }

        std::string struct_meth_str(typeassignment_entity_ptr self, const std::string & tp) {
            return "\n" + tabformat(basic_entity_ptr(), 2) + "template<> void " +
                    fulltype_str(self, false) + "::serialize(" +
                    tp + "& arch)";
        }

        std::string nested_init_str(type_atom_ptr self, const std::string& nm) {
            type_atom_ptr next = self->textualy_type();
            if (!next || next == self || !next->reff())
                return (next && next->tag() && next->isrefferrence()) ? (fromtype_str(next) + "(" + nm + ")") : nm;
            if (!next->reff()->as_typeassigment())
                return fromtype_str(next) + "(" + nm + ")";
            if (!next->reff()->as_typeassigment()->type())
                return fromtype_str(next) + "(" + nm + ")";
            return fromtype_str(next) + "(" + nested_init_str(next->reff()->as_typeassigment()->type(), nm) + ")";
        }

        bool expressed_import(module_entity_ptr self, const std::string & name) {
            if (basic_entity_ptr tas = self->find_by_name(name)) {
                if (tas->as_typeassigment())
                    return tas->as_typeassigment()->is_cpp_expressed();
                else if (tas->as_valueassigment())
                    return !tas->as_valueassigment()->has_arguments();
                else if (tas->as_valuesetassigment())
                    return false;
            }
            return false;
        }

        member_vect parse_membervct(const member_vect& vct, bool obligate) {
            member_vect rslt;
            for (member_vect::const_iterator it = vct.begin(); it != vct.end(); ++it)
                if ((obligate && it->marker == mk_none) || !obligate)
                    rslt.push_back(*it);
            return rslt;
        }

        member_vect parse_default_membervct(const member_vect & vct) {
            member_vect rslt;
            for (member_vect::const_iterator it = vct.begin(); it != vct.end(); ++it)
                if (it->marker == mk_default)
                    rslt.push_back(*it);
            return rslt;
        }

        static std::string execute_prefixed_static(const declare_atom& vl, basic_entity_ptr scp) {
            std::string rslt;
            if (type_atom_ptr tmptp = vl.typ->type()) {
                tagged_vct tags = tmptp->true_tags_sequence();
                if (!tags.empty()) {
                    bool isexplicit = (tags.front()->rule() == explicit_tags);
                    rslt += ("ITU_T_PREFIXED_DECLARE( " + vl.typenam + ", ITU_T_ARRAY(");
                    for (tagged_vct::const_iterator it = tags.begin(); it != tags.end(); ++it) {
                        if (it != tags.begin())
                            rslt += ", ";
                        rslt += ("prefixed_type(" + tagged_str(*it) + ", " + tagged_class_str(*it) + ")");
                    }
                    rslt += (" ), " + std::string(isexplicit ? "true" : "false") + ");");
                    rslt += (" //  initial =" + std::string(isexplicit ? "explicit" : "implicit"));
                }
            }
            return rslt;
        }

        static void load_member_static(typeassignment_entity_ptr self, member_vect& vct, namedtypeassignment_entity_vct & from) {
            for (namedtypeassignment_entity_vct::iterator it = from.begin(); it != from.end(); ++it) {
                tagmarker_type mkr = (*it)->marker();
                if ((*it)->type()) {
                    if (mkr == mk_default && !default_supported(*it))
                        mkr = mk_optional;
                    if (is_named(mkr))
                        vct.push_back(member_atom(mkr, nameconvert((*it)->name()), fromtype_str(*it),
                            ((self->builtin() == t_CHOICE) ? (type_str(self) + "_" + nameconvert((*it)->name())) : ""),
                            (*it), (*it)->istextualy_choice()));
                }
            }
        }

        void load_member(member_vect& vct, typeassignment_entity_ptr self) {
            namedtypeassignment_entity_vct root1 = self->child_root_1(false);
            namedtypeassignment_entity_vct root2 = self->child_root_2(false);
            namedtypeassignment_entity_vct extentions = self->extentions();

            load_member_static(self, vct, root1);

            for (namedtypeassignment_entity_vct::iterator it = extentions.begin(); it != extentions.end(); ++it)
                if ((*it)->type())
                    vct.push_back(member_atom(mk_optional, nameconvert((*it)->name()), fromtype_str(*it),
                        ((self->builtin() == t_CHOICE) ? (type_str(self) + "_" + nameconvert((*it)->name())) : ""),
                        (*it), (*it)->istextualy_choice()));

            load_member_static(self, vct, root2);
        }

        static std::string get_ber_helper_name(typeassignment_entity_ptr tp) {
            return fulltype_str(tp, false, "__");
        }

        static std::string get_per_helper_name(typeassignment_entity_ptr tp) {
            return fulltype_str(tp, false, "__");
        }




        ////////////////////////////////////////////////////////////////////////////////////////////////////         
        //  BaseModuleOUT
        ////////////////////////////////////////////////////////////////////////////////////////////////////       

        base_moduleout::base_moduleout(const char* path, module_entity_ptr mod, const compile_option & opt)
        : base_options(opt), module_(mod), stream(path, std::ofstream::out | std::ofstream::trunc) {
            if (!stream)
                throw fsnsp::filesystem_error("File dosnt create: " + std::string(path),
                    boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));
        }

        base_moduleout::~base_moduleout() {
        }




        ////////////////////////////////////////////////////////////////////////////////////////////////////         
        //  CppOUT
        ////////////////////////////////////////////////////////////////////////////////////////////////////       

        cppout::~cppout() {
        }

        void cppout::execute() {
            if (!dir_exists(option_path()))
                throw fsnsp::filesystem_error("File or directory error",
                    boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));
            std::string outpath = "";
            if (!dir_exists(option_outdir())) {
                if (!dir_create(option_path(), option_outdir()))
                    throw fsnsp::filesystem_error("File or directory error",
                        boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));
                boost::filesystem::path p(option_path().c_str());
                boost::filesystem::path f(option_outdir().c_str());
                boost::filesystem::path r = p / f;
                outpath = r.generic_string();
            } else
                outpath = option_outdir();

            for (basic_entity_vector::iterator it = global_->childs().begin(); it != global_->childs().end(); ++it) {
                if ((*it)->as_module()) {
                    moduleout_ptr hpp = generate<mainhpp_out>(outpath, (*it)->as_module(), "", "hpp");
                    hpp->execute();
                    moduleout_ptr cpp = generate<maincpp_out>(outpath, (*it)->as_module(), "", "cpp");
                    cpp->execute();
                    if (!option_ber_main()) {
                        moduleout_ptr ber = generate<ber_cpp_out>(outpath, (*it)->as_module(), "-ber", "cpp");
                        ber->execute();
                    }
                    moduleout_ptr per = generate<per_cpp_out>(outpath, (*it)->as_module(), "-per", "cpp");
                    per->execute();
                }
            }
        }







        ////////////////////////////////////////////////////////////////////////////////////////////////////         
        //  moduleout
        ////////////////////////////////////////////////////////////////////////////////////////////////////       

        std::size_t moduleout::load_predeclare(basic_entity_ptr self, structdeclare_vect & rslt) {
            load_struct_predeclare(self, rslt);
            load_structof_predeclare(self, rslt);
            return rslt.size();
        }

        std::size_t moduleout::load_structof_predeclare(basic_entity_ptr self, structdeclare_vect & rslt) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && tpas->is_cpp_expressed()) {
                    if (tpas->isstruct_of() && !tpas->childs().empty()) {
                        if (typeassignment_entity_ptr cpas = tpas->childs().front()->as_typeassigment()) {
                            if (cpas->isstruct_of())
                                load_structof_predeclare(tpas, rslt);
                            else if (cpas->isstruct())
                                rslt.push_back(type_str(cpas));
                        }
                    }
                }
            }
            return rslt.size();
        }

        std::size_t moduleout::load_struct_predeclare(basic_entity_ptr self, structdeclare_vect & rslt) {
            for (basic_entity_vector::const_iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->is_cpp_expressed())) {
                    if (tpas->isstruct())
                        rslt.push_back(type_str(tpas));
                }
            }
            return rslt.size();
        }

        void moduleout::load_typedef_simple_native(declare_vect& vct, basic_entity_ptr self, bool tagged) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type()) && (tpas->issimplerefferrence()) && (tpas->is_cpp_expressed())) {
                    if (!tagged && (!tpas->tag())) {
                        vct.push_back(declare_atom(declare_typedef, tpas, type_str(tpas), fromtype_str(tpas), false));
                    } else if (tagged && (tpas->tag())) {
                        vct.push_back(declare_atom(((tpas->tag()->rule() == explicit_tags) ? declare_explicit : declare_implicit),
                                tpas, type_str(tpas), fromtype_str(tpas), tagged_str(tpas->tag()), tagged_class_str(tpas->tag()), false));
                    }
                }
            }
        }

        void moduleout::load_typedef_structof_native(declare_vect& vct, basic_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->is_cpp_expressed()) && (tpas->isstruct_of()))
                    load_typedef_structof_native_impl(vct, tpas);
            }
        }

        bool moduleout::load_typedef_structof_native_impl(declare_vect& vct, typeassignment_entity_ptr self) {
            if (!self->childs().empty()) {
                typeassignment_entity_ptr cpas = self->childs().front()->as_typeassigment();
                if (cpas && (cpas->type())) {
                    if (cpas->issimplerefferrence()) {
                        vct.push_back(declare_atom(((self->builtin() == t_SEQUENCE_OF) ? declare_seq : declare_set),
                                self, type_str(self), fromtype_str(cpas), false));
                        return true;
                    } else if ((cpas->isstruct_of())) {
                        if (load_typedef_structof_native_impl(vct, cpas)) {
                            vct.push_back(declare_atom(((self->builtin() == t_SEQUENCE_OF) ? declare_seq : declare_set),
                                    self, type_str(self), fromtype_str(cpas), false));
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        void moduleout::load_typedef(declare_vect& vct, basic_entity_ptr self) {

            load_typedef_ref(vct, self);
            load_typedef_structof(vct, self);
            resolve_remote_reff(vct);
            sort_reff(vct);
        }

        void moduleout::load_typedef_ref(declare_vect& vct, basic_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->is_cpp_expressed())) {
                    if (tpas->isrefferrence()) {
                        if (!tpas->tag()) {
                            vct.push_back(declare_atom(declare_typedef, tpas, type_str(tpas), fromtype_str(tpas), fromtype_remote(tpas)));
                        } else {
                            vct.push_back(declare_atom(((tpas->tag()->rule() == explicit_tags) ? declare_explicit : declare_implicit),
                                    tpas, type_str(tpas), fromtype_str(tpas), tagged_str(tpas->tag()), tagged_class_str(tpas->tag()), fromtype_remote(tpas)));
                        }
                    } else if ((tpas->isstructure())&& (tpas->tag())) {

                        vct.push_back(declare_atom(((tpas->tag()->rule() == explicit_tags) ? declare_explicit : declare_implicit),
                                tpas, type_str(tpas, true), type_str(tpas), tagged_str(tpas->tag()), tagged_class_str(tpas->tag()), false));
                    }
                }
            }
        }

        void moduleout::load_typedef_structof(declare_vect& vct, basic_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && tpas->is_cpp_expressed()) {
                    if (tpas->isstruct_of() && !tpas->childs().empty())
                        load_typedef_structof_impl(vct, tpas);
                }
            }
        }

        bool moduleout::load_typedef_structof_impl(declare_vect& vct, typeassignment_entity_ptr self) {
            if (!self->childs().empty()) {
                typeassignment_entity_ptr cpas = self->childs().front()->as_typeassigment();
                if (cpas && cpas->type()) {
                    if (!cpas->issimplerefferrence() && !cpas->isstruct_of()) {
                        vct.push_back(declare_atom(((self->builtin() == t_SEQUENCE_OF) ? declare_seq : declare_set),
                                self, type_str(self), fromtype_str(cpas), fromtype_remote(cpas)));
                        return true;
                    } else if (cpas->isstruct_of()) {
                        if (load_typedef_structof_impl(vct, cpas)) {
                            vct.push_back(declare_atom(((self->builtin() == t_SEQUENCE_OF) ? declare_seq : declare_set),
                                    self, type_str(self), fromtype_str(cpas), fromtype_remote(cpas)));

                            return true;
                        }
                    }
                }
            }
            return false;
        }

        void moduleout::headerlock() {
            std::string name = nameconvert(module_->name());
            boost::algorithm::to_upper(name);
            name = "___" + name;
            stream << ("#ifndef " + name + "\n" + "#define " + name + "\n\n" + FHHEADER + "\n");
        }

        void moduleout::bottomlock() {
            std::string name = nameconvert(module_->name());
            boost::algorithm::to_upper(name);
            name = "___" + name;
            stream << (FHBOTTOM + "  /*" + name + " */\n");
        }

        void moduleout::execute_include(std::string name) {
            stream << "#include \"" << name << ".hpp\"\n";
        }

        void moduleout::execute_includes_hpp() {
            for (basic_entity_vector::iterator it = module_->imports().begin(); it != module_->imports().end(); ++it)
                if ((*it)->as_import())
                    execute_include((*it)->as_import()->name());
        }

        void moduleout::execute_standart_type() {
            stream << "\n";
            stream << MNDCL;
        }

        void moduleout::execute_start_ns() {
            stream << "\n";
            stream << "namespace " + nameconvert(module_->name()) + " {\n";
        }

        void moduleout::execute_stop_ns() {
            stream << "\n} ";
            stream << "\n";
        }

        void moduleout::execute_import(import_entity_ptr self) {
            if (self->scope())
                stream << "\n    // import   from  " << self->name();
            else
                stream << "\n";
            stream << "\n";
            stream << "\n";
            for (import_vector::iterator it = self->import().begin(); it != self->import().end(); ++it) {
                if (expressed_import(module_, nameconvert(*it))) {

                    basic_entity_ptr tas = self->find_by_name(*it);
                    typeassignment_entity_ptr tpas = tas ? tas->as_typeassigment() : typeassignment_entity_ptr();
                    stream << tabformat(self, 2) << "using " << nameconvert(self->name())
                            << "::" << nameconvert(*it) << ";\n";
                }
            }
            stream << "\n";
        }

        void moduleout::execute_imports() {
            for (basic_entity_vector::iterator it = module_->imports().begin(); it != module_->imports().end(); ++it)
                if ((*it)->as_import())
                    execute_import((*it)->as_import());
        }

        void moduleout::mark_constraints(typeassignment_entity_ptr self) {
            if ((self) && (self->type()) && (self->type()->can_per_constraints())) {
                type_atom_ptr tmp = self->type();
                if (tmp->integer_constraint())
                    stream << "  //   Ic" << (*(tmp->integer_constraint())).to_per() << " ";
                if (tmp->size_constraint())
                    stream << "  //    Sc " << (*(tmp->size_constraint())).to_per() << " ";
                if (tmp->char8_constraint())
                    stream << "  //    c8C " << (*(tmp->char8_constraint())).to_alphabet_per() << " ";
                if (tmp->quadruple_constraint())
                    stream << "  //   qC " << (*(tmp->quadruple_constraint())).to_alphabet_per() << " ";

                if (tmp->tuple_constraint())
                    stream << "  //   Tc " << (*(tmp->tuple_constraint())).to_alphabet_per() << " ";
                if (typeassignment_entity_ptr root = self->root_typeassignment()) {
                    if ((root->isstruct_of()) && (!root->childs().empty())
                            && (root->childs().front()->as_typeassigment()) &&
                            (root->childs().front()->as_typeassigment()->can_per_constraints())) {
                        stream << "  //  struct of ->  ";
                        mark_constraints(root->childs().front()->as_typeassigment());
                    }
                }
            }
        }

        void moduleout::execute_member(typeassignment_entity_ptr self) {
            //if (self->builtin() == t_CHOICE)
            return;
            member_vect mmbr;
            load_member(mmbr, self);
            if (!mmbr.empty())
                stream << "\n\n" << tabformat(self, 1) << "private:\n";
            for (member_vect::const_iterator it = mmbr.begin(); it != mmbr.end(); ++it) {
                stream << "\n";
                stream << tabformat(self, 1) <<
                        member_marker_str(it->typenam, it->marker, ((it->marker == mk_default) ? (it->name + "__default") : ""), option_no_holder()) <<
                        " " << it->name << "_;";
            }
        }

        void moduleout::print_name_type(typeassignment_entity_ptr tpas, basic_entity_ptr scp) {
            if (!scp)
                scp = tpas;
            if (tpas) {
                if (tpas->isstruct()) {
                    stream << "\n";
                    stream << tabformat(scp);
                    switch (tpas->builtin()) {
                        case t_CHOICE:
                        {
                            stream << "// choice ";
                            break;
                        }
                        case t_SET:
                        {
                            stream << "// set  ";
                            break;
                        }
                        case t_SEQUENCE:
                        {
                            stream << "// sequence ";
                            break;
                        }
                        default:
                        {
                        }
                    }
                    stream << tpas->name();
                }
            }
        }











        //////////////////////////////////////////////////////
        //  mainhpp_out
        //////////////////////////////////////////////////////

        void mainhpp_out::execute() {

            basic_entity_ptr scp;

            headerlock();
            execute_start_ns();
            execute_standart_type();

            execute_predeclare(module_);

            execute_typedef_native_global(module_);

            declare_vect vct;
            load_typedef(vct, module_);
            execute_typedef(vct, false);

            if (option_reverse_decl())
                execute_valueassignments<basic_entity_vector::const_reverse_iterator>(module_->childs().rbegin(), module_->childs().rend());
            else
                execute_valueassignments<basic_entity_vector::const_iterator>(module_->childs().begin(), module_->childs().end());

            execute_stop_ns();


            stream << "\n";
            execute_includes_hpp();



            execute_start_ns();

            execute_imports();
            execute_typedef(vct, true);

            if (option_reverse_decl())
                execute_typeassignments<basic_entity_vector::const_reverse_iterator>(module_->childs().rbegin(), module_->childs().rend());
            else
                execute_typeassignments<basic_entity_vector::const_iterator>(module_->childs().begin(), module_->childs().end());

            if (option_define_struct()) {
                stream << "\n" << tabformat(scp, 2) << "// struct var" << "\n";
                if (option_reverse_decl())
                    execute_valueassignments_ext<basic_entity_vector::const_reverse_iterator>(module_->childs().rbegin(), module_->childs().rend());
                else
                    execute_valueassignments_ext<basic_entity_vector::const_iterator>(module_->childs().begin(), module_->childs().end());
            }

            if (option_cout_metod()) {
                stream << "\n" << tabformat(scp, 2) << "// std::cout methods" << "\n";
                if (execute_struct_cout_meth(module_))
                    stream << "\n";
            }

            if (execute_struct_meth_hpp(module_, "X690"))
                stream << "\n";

            if (execute_struct_meth_hpp(module_, "X691"))
                stream << "\n";

            execute_stop_ns();


            if (registrate_struct_set(module_))
                stream << "\n";
            registrate_struct_choice(module_);

            bottomlock();
        }

        void mainhpp_out::execute_predeclare(basic_entity_ptr self) {
            // struct X1; ...
            structdeclare_vect vct;
            if (load_predeclare(self, vct)) {
                stream << "\n";
                for (structdeclare_vect::const_iterator it = vct.begin(); it != vct.end(); ++it)
                    stream << "\n" << tabformat(self, (self->as_typeassigment() ? 1 : 2)) << "struct " << *it << ";";
                stream << "\n";
            }
        }

        void mainhpp_out::execute_typedef(const declare_vect& vct, bool remote, basic_entity_ptr scp) {
            if (!vct.empty())
                stream << "\n";
            for (declare_vect::const_iterator it = vct.begin(); it != vct.end(); ++it) {
                if (it->remote_ == remote) {
                    switch (it->decl) {
                        case declare_typedef: stream << "\n" << tabformat(scp, 2) << "typedef " << it->from_type << " " << it->typenam << ";";
                            break;
                        case declare_seq: stream << "\n" << tabformat(scp, 2) << "typedef " << struct_of_str(true) << "< " << it->from_type << " > " << it->typenam << ";";
                            break;
                        case declare_set: stream << "\n" << tabformat(scp, 2) << "typedef " << struct_of_str(false) << "< " << it->from_type << " > " << it->typenam << ";";
                            break;
                        case declare_explicit:
                            if (it->from_type == it->typenam)
                                stream << "\n" << tabformat(scp, 2) << "ITU_T_EXPLICIT_TYPEDEF( " << it->typenam << "__expl_helper" << ", " << it->from_type << ", " << it->tag << ", " << it->class_ << ");";
                            if (it->from_type != it->typenam)
                                stream << "\n" << tabformat(scp, 2) << "typedef " << " " << it->from_type << " " << it->typenam << ";";
                            stream << "\n" << tabformat(scp, 2) << execute_prefixed_static(*it, scp);
                            break;
                        case declare_implicit:
                            if (it->from_type == it->typenam)
                                stream << "\n" << tabformat(scp, 2) << "ITU_T_IMPLICIT_TYPEDEF( " << it->typenam << "__impl_helper" << ", " << it->from_type << ", " << it->tag << ", " << it->class_ << ");";
                            if (it->from_type != it->typenam)
                                stream << "\n" << tabformat(scp, 2) << "typedef " << " " << it->from_type << " " << it->typenam << ";";
                            stream << "\n" << tabformat(scp, 2) << execute_prefixed_static(*it, scp);
                            break;
                        default:
                        {
                        }
                    }
                    mark_constraints(it->typ);
                }
            }
        }

        void mainhpp_out::execute_typedef_native_global(basic_entity_ptr self) {
            // expl X ::= INTEGER or X = [1] INEGER
            declare_vect vct;
            load_typedef_simple_native(vct, self, false);
            load_typedef_simple_native(vct, self, true);
            load_typedef_structof_native(vct, self);

            if (!vct.empty())
                execute_typedef(vct, false);
        }

        void mainhpp_out::execute_typedef_native_local(basic_entity_ptr self) {
            // expl X ::= INTEGER or X = [1] INEGER
            declare_vect vct;
            load_typedef_structof_native(vct, self);
            load_typedef_structof(vct, self);
            if (!vct.empty()) {

                stream << "\n";
                execute_typedef(vct, false, self);
                execute_typedef(vct, true, self);
            }
        }

        void mainhpp_out::execute_valueassignment(valueassignment_entity_ptr self) {
            basic_entity_ptr scp;
            switch (self->type()->root_builtin()) {
                case t_NULL:
                case t_INTEGER:
                case t_BOOLEAN:
                case t_REAL:
                case t_ENUMERATED:
                case t_IA5String:
                case t_BMPString:
                case t_UniversalString:
                case t_UTF8String:
                case t_NumericString:
                case t_PrintableString:
                case t_T61String:
                case t_VideotexString:
                case t_GraphicString:
                case t_VisibleString:
                case t_GeneralString:
                case t_ObjectDescriptor:
                {
                    stream << "\n" << tabformat(scp, 2) << "const " << fromtype_str(self->type()) << " " <<
                            nameconvert(self->name()) << " = " << valueassmnt_str(self->type(), self->value(), nameconvert(self->name())) << ";\n";
                    break;
                }
                case t_OBJECT_IDENTIFIER:
                case t_RELATIVE_OID:
                case t_OCTET_STRING:
                case t_BIT_STRING:
                {
                    stream << "\n" << tabformat(scp, 2) << valueassmnt_str_ext(self->type(), self->value(), nameconvert(self->name())) << ";\n";
                    break;
                }
                default:
                {
                }
            }
        }
        
        static std::string calculate_valuename_static(typeval_manager_ptr self, const typeasmt_value_atom_vct& seq) {    
            std::string rslt = nameconvert(self->valueassignment()->name());
            for (typeasmt_value_atom_vct::const_iterator it = seq.begin(); it != seq.end(); ++it) 
                rslt+=("__"+ (it->typeassignment() ? nameconvert(it->typeassignment()->name()) : "?"));
            return rslt;
        }
        
        static std::string calculate_valuesetter_static(typeval_manager_ptr self, const typeasmt_value_atom_vct& seq) {
            std::string rslt = nameconvert(self->valueassignment()->name()) + ".";
            typeasmt_value_atom_vct::const_iterator pit = !seq.empty() ? (seq.begin()+(seq.size()-1)) : seq.end();
            for (typeasmt_value_atom_vct::const_iterator it = seq.begin(); it != seq.end(); ++it) {
                rslt += (it->typeassignment() ? nameconvert(it->typeassignment()->name()) : "name?");
                if (it != pit) {
                    if (it->typeassignment() && it->marker() == mk_optional)
                        rslt += "()->";
                    else
                        rslt += "().";
                }
            }
            return rslt;
        }        

        void mainhpp_out::execute_valueassignment_ext(typeval_manager_ptr self) {
            basic_entity_ptr scp;
            if (self && !self->empty()) {
                for (typeasmt_value_atom_vct_vct::const_iterator it = self->valueslines().begin(); it != self->valueslines().end(); ++it) {
                    const typeasmt_value_atom_vct& curit = *it;
                    if (!curit.empty()) {
                        namedtypeassignment_entity_ptr tps = curit.back().typeassignment();
                        value_atom_ptr vls = curit.back().value();
                        if (tps && vls) {
                            defined_type dtype = tps->builtin();
                            if (iscomplexvalue_decl_static(dtype)) {
                                std::string name = calculate_valuename_static(self, curit);
                                stream <<  "\n" <<  tabformat(scp, 2) << valueassmnt_str_ext( tps->type(), vls, name) <<  ";";          
                                stream << "\n" <<   tabformat(scp, 2) << calculate_valuesetter_static(self, curit) << "(" <<  name<< ");";
                            } else {
                            }
                        }
                    }
                }
            }
        }         

        void mainhpp_out::execute_valueassignment_ext(valueassignment_entity_ptr self) {
            basic_entity_ptr scp;
            typeval_manager_ptr val_mgr;
            if (!option_c11())
                val_mgr=boost::make_shared<typeval_manager>(self);
            switch (self->type()->root_builtin()) {
                case t_SET:
                case t_SEQUENCE:
                case t_CHOICE:
                case t_SET_OF:
                case t_SEQUENCE_OF:
                {
                    stream << "\n" << tabformat(scp, 2) << "static " << fromtype_str(self->type()) << " " <<
                            nameconvert(self->name()) << " = " << value_structure_str(self->type()->valuestructure(), self->value(),0, val_mgr) << ";\n";
                    execute_valueassignment_ext(val_mgr);
                    stream << "\n";
                    break;
                }
                default:
                {
                }
            }
            
        }

        void mainhpp_out::execute_typeassignment(typeassignment_entity_ptr tpas) {
            basic_entity_ptr scp;
            if (tpas && (tpas->is_cpp_expressed())) {
                switch (tpas->builtin()) {
                    case t_CHOICE:
                        print_name_type(tpas);
                        execute_choice_hpp(tpas);
                        break;
                    case t_SEQUENCE:
                        print_name_type(tpas);
                        execute_struct_hpp(tpas);
                        break;
                    case t_SET:
                        print_name_type(tpas);
                        execute_struct_hpp(tpas);
                        break;
                    case t_SEQUENCE_OF:
                    case t_SET_OF:
                        execute_structof_hpp(tpas);
                        break;
                    default:
                    {
                        if ((tpas) && (tpas->predefined())) {
                            execute_predefined_hpp(tpas);
                        }
                    }
                }
            }
        }

        void mainhpp_out::execute_declare_hpp(typeassignment_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && tpas->type())
                    execute_declare_struct_hpp(tpas);
            }
        }

        void mainhpp_out::execute_declare_struct_hpp(typeassignment_entity_ptr self) {
            if (self) {
                switch (self->builtin()) {
                    case t_CHOICE: stream << "\n";
                        execute_choice_hpp(self);
                        break;
                    case t_SET:
                    case t_SEQUENCE: stream << "\n";
                        execute_struct_hpp(self);
                        break;
                    case t_SET_OF:
                    case t_SEQUENCE_OF:
                        execute_structof_hpp(self);
                        break;
                    default:
                    {
                    }
                }
            }
        }

        void mainhpp_out::execute_choice_hpp(typeassignment_entity_ptr self) {

            execute_choice_enum(self);

            stream << "\n" << tabformat(self) <<
                    "struct " << type_str(self) << "";
            stream << " : " << "public ITU_T_CHOICE(" << type_str(self) << "_enum) {\n";


            execute_predeclare(self);
            execute_declare_hpp(self);
            execute_typedef_native_local(self);

            execute_predefineds_hpp(self);

            execute_ctor_hpp(self);

            execute_access_member_hpp(self);

            execute_archive_meth_hpp(self);

            //execute_member(stream, self);
            stream << "\n" << tabformat(self) << "}; ";
            stream << "\n ";
        }

        void mainhpp_out::execute_choice_enum(typeassignment_entity_ptr self) {
            stream << "\n" << tabformat(self) <<
                    "enum " << type_str(self) << "_enum {";
            stream << "\n" << tabformat(self, 1) <<
                    type_str(self) << "_null = 0, ";
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if ((*it)->as_named_typeassigment()) {
                    tagmarker_type mkr = (*it)->as_named_typeassigment()->marker();
                    if (is_named(mkr))
                        stream << "\n" << tabformat(self, 1) <<
                        choice_enum_str(self, (*it)) << ",";
                }
            }
            stream << "}; ";
            stream << "\n ";
        }

        void mainhpp_out::execute_struct_hpp(typeassignment_entity_ptr self) {

            stream << "\n" << tabformat(self) <<
                    "struct " << type_str(self) << "{\n";



            execute_predeclare(self);
            execute_declare_hpp(self);
            execute_typedef_native_local(self);
            execute_predefineds_hpp(self);

            execute_default_hpp(self);

            execute_ctor_hpp(self);

            execute_access_member_hpp(self);

            execute_archive_meth_hpp(self);


            stream << "\n" << tabformat(self) << "};";
            stream << "\n ";
        }

        void mainhpp_out::execute_predefined_hpp(typeassignment_entity_ptr self) {
            if (self->type()) {
                predefined_ptr predef = self->predefined();
                if (predef) {
                    switch (self->root_builtin()) {
                        case t_INTEGER:
                        {
                            execute_predefined_int_hpp(predef, self);
                            break;
                        }
                        case t_BIT_STRING:
                        {
                            execute_predefined_bs_hpp(predef, self);
                            break;
                        }
                        case t_ENUMERATED:
                        {
                            execute_predefined_int_hpp(predef, self);
                        }
                        default:
                        {
                        }
                    }
                }
            }
        }

        void mainhpp_out::execute_predefineds_hpp(basic_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas)
                    execute_predefined_hpp(tpas);
            }
        }

        void mainhpp_out::execute_predefined_int_hpp(predefined_ptr prdf, typeassignment_entity_ptr self) {
            bool is_local_scope = ((self->scope()) && (self->scope()->as_typeassigment()));
            std::string pref = is_local_scope ? "static " : "";
            stream << "\n";
            for (basic_entity_vector::const_iterator it = prdf->values().begin(); it != prdf->values().end(); ++it) {
                valueassignment_entity_ptr vlass = (*it)->as_valueassigment();
                if (vlass) {
                    stream << tabformat(self) << pref << "const ";
                    stream << type_str(self) << " ";
                    stream << (namelower(nameconvert(self->name())) + "_") << nameconvert(vlass->name());
                    if (!is_local_scope)
                        stream << " = " << nested_init_str(self->type(), value_int_str(vlass->value()));
                    stream << ";\n";
                }
            }
        }

        void mainhpp_out::execute_predefined_bs_hpp(predefined_ptr prdf, typeassignment_entity_ptr self) {
            bool is_local_scope = ((self->scope()) && (self->scope()->as_typeassigment()));
            std::string pref = is_local_scope ? "static " : "";
            stream << "\n";
            for (basic_entity_vector::const_iterator it = prdf->values().begin(); it != prdf->values().end(); ++it) {
                valueassignment_entity_ptr vlass = (*it)->as_valueassigment();
                if (vlass) {

                    stream << tabformat(self) << pref << "const ";
                    stream << type_str(self) << " ";
                    stream << (namelower(nameconvert(self->name()) + "_")) << nameconvert(vlass->name());
                    if (!is_local_scope)
                        stream << " = " << nested_init_str(self->type(), "bit_string(true, " + value_int_str(vlass->value()) + ")");
                    stream << ";\n";
                }
            }
        }

        void mainhpp_out::execute_access_member_hpp(typeassignment_entity_ptr self) {
            bool ischoice = (self->builtin() == t_CHOICE);
            member_vect mmbr;
            load_member(mmbr, self);
            for (member_vect::const_iterator it = mmbr.begin(); it != mmbr.end(); ++it) {
                stream << "\n";
                if (!ischoice) {
                    switch (it->marker) {
                        case mk_none: stream << tabformat(self, 1) << "ITU_T_HOLDER" << (option_no_holder() ? "N": "H") <<
                            "_DECL(" << it->name << ", " << it->typenam << ");";
                            break;
                        case mk_optional: stream << tabformat(self, 1) << "ITU_T_OPTIONAL_DECL(" << it->name <<
                                    ", " << it->typenam << ");";
                            break;
                        case mk_default: stream << tabformat(self, 1) << "ITU_T_DEFAULTH_DECL(" << it->name <<
                                    ", " << it->typenam << ", " << (it->name + "__default") << ");";
                            break;
                        default:
                        {
                        }
                    }
                } else {
                    bool primitive = (it->typ && it->typ->isprimitive());
                    stream << tabformat(self, 1) << "ITU_T_CHOICE" << (primitive ? "S" : "C") << "_DECL(" << it->name << ", " <<
                            it->typenam << ", " << choice_enum_str(self, it->typ) << ");     " << (primitive ? "// primitive" : "");
                }
                mark_constraints(it->typ);
            }
        }

        void mainhpp_out::execute_structof_hpp(typeassignment_entity_ptr self) {
            if (self && (self->type())) {
                if (self->isstruct_of() && !self->childs().empty()) {
                    typeassignment_entity_ptr cpas = self->childs().front()->as_typeassigment();
                    if (cpas) {
                        if (cpas->isstruct_of()) {
                            execute_structof_hpp(cpas);
                        } else if (cpas->isstruct()) {
                            execute_declare_struct_hpp(cpas);
                        }
                    }
                }
            }
        }

        void mainhpp_out::execute_ctor_hpp(typeassignment_entity_ptr self) {
            if ((self) && (self->type())) {
                switch (self->builtin()) {
                    case t_CHOICE:
                    {
                        stream << "\n";
                        stream << "\n" << tabformat(self, 1) << "ITU_T_CHOICE_CTORS(" << type_str(self) << ");\n";
                        break;
                    }
                    case t_SET:
                    case t_SEQUENCE:
                    {

                        member_vect mmbr;
                        load_member(mmbr, self);
                        member_vect oblig = parse_membervct(mmbr, true);
                        member_vect nooblig = parse_membervct(mmbr, false);

                        stream << "\n";
                        stream << "\n" << tabformat(self, 1) << type_str(self) << "(); \n";

                        if (!oblig.empty()) {
                            stream << "\n" << tabformat(self, 1) << type_str(self) << "(";
                            for (member_vect::const_iterator it = oblig.begin(); it != oblig.end(); ++it) {
                                if (it != oblig.begin())
                                    stream << ",\n " << tabformat(self, 2);
                                stream << "const " << it->typenam << "&  " << argumentname(it->name);
                            }
                            stream << ");\n";
                        }

                        if (/*!nooblig.empty() && (nooblig.size() > oblig.size())*/!nooblig.empty()) {
                            stream << "\n" << tabformat(self, 1) << type_str(self) << "(";
                            for (member_vect::const_iterator it = nooblig.begin(); it != nooblig.end(); ++it) {
                                if (it != nooblig.begin())
                                    stream << ",\n " << tabformat(self, 2);
                                stream << "ITU_T_SHARED(" << it->typenam << ") " << argumentname(it->name);
                            }
                            stream << ");\n";
                        }

                        break;
                    }
                    default:
                    {
                    }
                }
            }
        }

        void mainhpp_out::execute_default_hpp(typeassignment_entity_ptr self) {
            if ((self) && (self->type())) {
                switch (self->builtin()) {
                    case t_SET:
                    case t_SEQUENCE:
                    {
                        member_vect mmbr;
                        load_member(mmbr, self);
                        for (member_vect::const_iterator it = mmbr.begin(); it != mmbr.end(); ++it) {
                            if (it->marker == mk_default)
                                stream << "\n" << tabformat(self, 1) << "static const " << fromtype_str(it->typ) << " " << it->name << "__default;";
                        }
                        break;
                    }
                    default:
                    {
                    }
                }
            }
        }

        void mainhpp_out::execute_archive_meth_hpp(basic_entity_ptr scp) {
            stream << "\n\n" << tabformat(scp, 1) << "ITU_T_ARCHIVE_FUNC;";
        }

        std::size_t mainhpp_out::registrate_struct_choice(basic_entity_ptr self) {
            std::size_t cnt = 0;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->isstructure()) && (tpas->is_cpp_expressed())) {
                    if (tpas->builtin() == t_CHOICE) {
                        stream << "\n" << "ITU_T_CHOICE_REGESTRATE(";
                        stream << fulltype_str(tpas, true);
                        stream << ")";
                        cnt++;
                    }
                    cnt += registrate_struct_choice(tpas);
                }
            }
            return cnt;
        }

        std::size_t mainhpp_out::registrate_struct_set(basic_entity_ptr self) {
            std::size_t cnt = 0;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && tpas->isstructure() && tpas->is_cpp_expressed()) {
                    if (tpas->builtin() == t_SET) {
                        stream << "\n" << "ITU_T_SET_REGESTRATE(";
                        stream << fulltype_str(tpas, true);
                        stream << ")";
                        cnt++;
                    }
                    cnt += registrate_struct_set(tpas);
                }
            }
            return cnt;
        }

        std::size_t mainhpp_out::execute_struct_meth_hpp(basic_entity_ptr self, const std::string & ctp) {
            std::size_t cnt = 0;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && tpas->isstructure() && tpas->is_cpp_expressed()) {
                    if (tpas->isstruct()) {
                        stream << "\n" << tabformat(basic_entity_ptr(), 1) << "ITU_T_ARCHIVE_" << ctp << "_DECL(" << fulltype_str(tpas, false) << ");";
                        cnt++;
                    }
                    cnt += execute_struct_meth_hpp(tpas, ctp);
                }
            }
            return cnt;
        }

        std::size_t mainhpp_out::execute_struct_cout_meth(basic_entity_ptr self) {
            std::size_t cnt = 0;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && tpas->isstructure() && tpas->is_cpp_expressed()) {
                    typeassignment_entity_ptr chek_tpas;
                    if (tpas->isstruct_of() && !tpas->childs().empty() &&
                            tpas->childs().front() && tpas->childs().front()->as_typeassigment() &&
                            tpas->childs().front()->as_typeassigment()) {
                        chek_tpas = tpas->childs().front()->as_typeassigment();
                        if (!(chek_tpas->root_builtin() == t_CHOICE ||
                                chek_tpas->root_builtin() == t_SEQUENCE ||
                                chek_tpas->root_builtin() == t_SEQUENCE_OF ||
                                chek_tpas->root_builtin() == t_SET ||
                                chek_tpas->root_builtin() == t_SET_OF))
                            chek_tpas.reset();
                    }
                    if (tpas->isstruct() || chek_tpas) {
                        stream << "\n" << tabformat(basic_entity_ptr(), 2) << "std::ostream& operator<<(std::ostream& stream, const ";
                        stream << fulltype_str(tpas, false) << "& vl);";
                        cnt++;
                    }
                    cnt += execute_struct_cout_meth(tpas);
                }
            }
            return cnt;
        }




        //////////////////////////////////////////////////////
        //  base_arch_out
        //////////////////////////////////////////////////////

        void base_arch_out::execute_archive_meth_cpp(typeassignment_entity_ptr self, const std::string & ctp) {
            //std::string ctp = "x690";
            switch (self->builtin()) {
                case t_CHOICE: stream << "\n";
                    stream << struct_meth_str(self, "boost::asn1::" + ctp + "::output_coder");
                    stream << "{";
                    execute_archive_choice_output(self);
                    stream << struct_meth_str(self, "boost::asn1::" + ctp + "::input_coder");
                    stream << "{";
                    execute_archive_choice_input(self);
                    break;
                case t_SET:
                case t_SEQUENCE: stream << "\n";

                    stream << struct_meth_str(self, "boost::asn1::" + ctp + "::output_coder");
                    stream << "{";
                    execute_archive_struct_output(self);
                    stream << struct_meth_str(self, "boost::asn1::" + ctp + "::input_coder");
                    stream << "{";
                    execute_archive_struct_input(self);

                    break;
                default:
                {
                }
            }
        }







        //////////////////////////////////////////////////////
        //  base_ber_arch_out
        //////////////////////////////////////////////////////

        void base_ber_arch_out::execute_archive_choice_output(typeassignment_entity_ptr self) {

            basic_entity_ptr scp;
            stream << "\n" << tabformat(scp, 3) <<
                    "switch(type()){";
            execute_archive_choice_output_helper(self);
            stream << "\n" << tabformat(scp, 3) << "}";
            stream << "\n";
            stream << tabformat(scp, 2) << "}";
            stream << "\n";
        }

        void base_ber_arch_out::execute_archive_choice_input(typeassignment_entity_ptr self) {

            basic_entity_ptr scp;

            bool alldefault = true;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (namedtypeassignment_entity_ptr named = (*it)->as_named_typeassigment()) {
                    if (is_named(named->marker())) {
                        if (named->cncl_tag() && !named->cncl_tags().empty())
                            alldefault = false;
                    }
                }
            }
            if (alldefault) {
                stream << "\n";
                execute_archive_choice_input_helper_mbr(self, tcl_universal, true, 4);
            } else {
                stream << "\n" << tabformat(scp, 3) <<
                        "int __tag_id__ =arch.test_id();";
                stream << "\n" << tabformat(scp, 3) <<
                        "switch(arch.test_class()){";

                execute_archive_choice_input_helper(self, tcl_universal, false);
                execute_archive_choice_input_helper(self, tcl_application, false);
                execute_archive_choice_input_helper(self, tcl_context, false);
                execute_archive_choice_input_helper(self, tcl_private, false);
                execute_archive_choice_input_helper(self, tcl_universal, true);
                stream << "\n" << tabformat(scp, 3) << "}";
            }
            stream << "\n";
            stream << tabformat(scp, 2) << "}";
            stream << "\n";
        }

        void base_ber_arch_out::execute_archive_struct_output(typeassignment_entity_ptr self) {
            basic_entity_ptr scp;

            namedtypeassignment_entity_vct root1 = self->child_root_1();
            namedtypeassignment_entity_vct root2 = self->child_root_2();
            namedtypeassignment_entity_vct extentions = self->extentions();

            for (namedtypeassignment_entity_vct::iterator it = root1.begin(); it != root1.end(); ++it)
                if ((*it)->type() && is_named((*it)->marker()))
                    execute_archive_member((*it), false);

            if (self->type() && self->type()->has_extention()) {

                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_RESET_EXTENTION" << ";\n";

                for (namedtypeassignment_entity_vct::iterator it = extentions.begin(); it != extentions.end(); ++it)
                    if ((*it)->type() && is_named((*it)->marker()))
                        execute_archive_member((*it), true);

                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_RESET_EXTENTION" << ";\n";
            }

            for (namedtypeassignment_entity_vct::iterator it = root2.begin(); it != root2.end(); ++it)
                if ((*it)->type() && is_named((*it)->marker()))
                    execute_archive_member(*it, false);

            stream << "\n";
            stream << tabformat(scp, 2) << "}";
            stream << "\n";
        }

        void base_ber_arch_out::execute_archive_struct_input(typeassignment_entity_ptr self) {
            execute_archive_struct_output(self);
        }

        std::string base_ber_arch_out::archive_member_ber_str(namedtypeassignment_entity_ptr self, const std::string& name, bool afterext) {
            tagmarker_type dfltopt = afterext ? mk_optional : self->marker();
            if ((dfltopt == mk_default) && (self->isstruct_of()))
                dfltopt = mk_optional;
            if (self->type() && self->type()->ismultipe_tagged()) {
                return "ITU_T_BIND_PREFIXED(" + name_arch(name, dfltopt) + ", " + get_ber_helper_name(self) + ")";
            } else {
                if ((self->isdefined_choice())) {
                    if (self->tag() || (self->type() && !self->type()->isuntagged())) {
                        tagged_ptr tgtmp = self->tag() ? self->tag() : self->type()->true_tags_sequence().front();
                        return "ITU_T_BIND_CHOICE_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(tgtmp) + ", " + tagged_class_str(tgtmp) + ")";
                    } else
                        return "ITU_T_BIND_CHOICE(" + name_arch(name, dfltopt) + ")";
                } else {
                    if (self->tag() || (self->type() && !self->type()->isuntagged())) {
                        tagged_ptr tgtmp = self->tag() ? self->tag() : self->type()->true_tags_sequence().front();
                        if (tgtmp->rule() == implicit_tags)
                            return "ITU_T_BIND_IMPLICIT(" + name_arch(name, dfltopt) + ", " + tagged_str(tgtmp) + ", " + tagged_class_str(tgtmp) + ")";
                        else
                            return "ITU_T_BIND_EXPLICIT(" + name_arch(name, dfltopt) + ", " + tagged_str(tgtmp) + ", " + tagged_class_str(tgtmp) + ")";
                    } else
                        return "ITU_T_BIND_TAG(" + name_arch(name, dfltopt) + ")";
                }
            }
            return "";
        }

        void base_ber_arch_out::execute_archive_member(namedtypeassignment_entity_ptr self, bool afterext) {
            basic_entity_ptr scp;
            if (self->type()) {
                stream << "\n";
                stream << tabformat(scp, 3) << archive_member_ber_str(self, nameconvert(self->name()) + "_", afterext) << ";";
            }
        }

        void base_ber_arch_out::execute_archive_choice_input_helper_mbr(typeassignment_entity_ptr self, tagclass_type cls, bool notag, std::size_t scpcnt) {
            basic_entity_ptr scp;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (namedtypeassignment_entity_ptr named = (*it)->as_named_typeassigment()) {
                    if (named->type() && is_named(named->marker())) {
                        canonical_tag_ptr ctag = named->cncl_tag();
                        canonical_tag_vct ctags = named->cncl_tags();
                        if (!notag) {
                            if (!ctags.empty()) {
                                for (canonical_tag_vct::iterator tit = ctags.begin(); tit != ctags.end(); ++tit) {
                                    if (cls == (*tit)->_class()) {
                                        stream << "\n" << tabformat(scp, scpcnt) << "case ";
                                        stream << tagged_str(*tit) << ":  { if (";
                                        std::string tmpval = "value<" + fromtype_str(named) + " > (true , " + choice_enum_str(self, (*it)) + ")";
                                        stream << archive_member_ber_str(named, tmpval);
                                        stream << ") return; else free(); break;}";
                                    }
                                }
                            } else if (ctag) {
                                if (cls == ctag->_class()) {
                                    stream << "\n" << tabformat(scp, scpcnt) << "case ";
                                    stream << tagged_str(ctag) << ":  { if (";
                                    std::string tmpval = "value<" + fromtype_str(named) + " > (true , " + choice_enum_str(self, (*it)) + ")";
                                    stream << archive_member_ber_str(named, tmpval);
                                    stream << ") return; else free(); break;}";
                                }
                            }
                        } else {
                            if (!ctag && ctags.empty()) {
                                stream << "\n" << tabformat(scp, scpcnt) << " if (";
                                std::string tmpval = "value<" + fromtype_str(named) + " > (true , " + choice_enum_str(self, (*it)) + ")";
                                stream << archive_member_ber_str(named, tmpval);
                                stream << ") return; else free();";
                            }
                        }
                    }
                }
            }
        }

        void base_ber_arch_out::execute_archive_choice_input_helper(typeassignment_entity_ptr self, tagclass_type cls, bool notag) {

            basic_entity_ptr scp;

            bool fnd = false;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (namedtypeassignment_entity_ptr named = (*it)->as_named_typeassigment()) {
                    if (named->type() && is_named(named->marker())) {
                        canonical_tag_ptr ctag = named->cncl_tag();
                        canonical_tag_vct ctags = named->cncl_tags();
                        if (!ctags.empty()) {
                            for (canonical_tag_vct::iterator tit = ctags.begin(); tit != ctags.end(); ++tit)
                                if (cls == (*tit)->_class()) {
                                    fnd = true;
                                    break;
                                }
                        } else if (ctag) {
                            if (cls == ctag->_class()) {
                                fnd = true;
                                break;
                            }
                        }
                    }
                }
            }

            if (notag) {
                stream << "\n" << tabformat(scp, 4) << "default: {";
                execute_archive_choice_input_helper_mbr(self, cls, notag, 6);
                stream << "\n" << tabformat(scp, 4) << "}";
            } else {
                if (fnd) {
                    stream << "\n" << tabformat(scp, 4) << "case ";
                    switch (cls) {
                        case tcl_universal: stream << "0x0: {";
                            break;
                        case tcl_application: stream << "0x40: {";
                            break;
                        case tcl_context: stream << "0x80: {";
                            break;
                        case tcl_private: stream << "0xC0: {";
                            break;
                    }
                    stream << "\n" << tabformat(scp, 5) << "switch(__tag_id__){";
                    execute_archive_choice_input_helper_mbr(self, cls, notag, 6);
                    stream << "\n" << tabformat(scp, 5) << "default:{}";
                    stream << "\n" << tabformat(scp, 5) << "}";
                    stream << "\n" << tabformat(scp, 4) << "}";
                }
            }
        }

        void base_ber_arch_out::execute_archive_choice_output_helper(typeassignment_entity_ptr self) {
            basic_entity_ptr scp;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (namedtypeassignment_entity_ptr named = (*it)->as_named_typeassigment()) {
                    if (named->type()) {

                        stream << "\n" << tabformat(scp, 4) << "case ";
                        stream << choice_enum_str(self, (*it)) << ":  {";
                        std::string tmpval = "value<" + fromtype_str(named) + " > (false , " + choice_enum_str(self, (*it)) + ")";
                        stream << archive_member_ber_str(named, tmpval);
                        stream << "; break; }";
                    }
                }
            }
            stream << "\n" << tabformat(scp, 4) << "default:{}";
        }





        //////////////////////////////////////////////////////
        //  mainhpp_out
        //////////////////////////////////////////////////////

        void maincpp_out::execute() {

            basic_entity_ptr scp;
            execute_include(module_->name());

            stream << CHHEADER << "\n";
            execute_start_ns();

            if (option_reverse_decl())
                execute_typeassignments<basic_entity_vector::const_reverse_iterator>(module_->childs().rbegin(), module_->childs().rend());
            else
                execute_typeassignments<basic_entity_vector::const_iterator>(module_->childs().begin(), module_->childs().end());

            if (option_cout_metod()) {
                stream << "\n" << tabformat(scp, 2) << "// std::cout methods" << "\n";
                if (execute_struct_cout_meth(module_))
                    stream << "\n";
            }

            execute_stop_ns();
            stream << CHBOTTOM << "\n";
        }

        void maincpp_out::execute_valueassignment(valueassignment_entity_ptr self) {
        }

        void maincpp_out::execute_typeassignment(typeassignment_entity_ptr tpas) {
            if (tpas && (tpas->is_cpp_expressed())) {
                switch (tpas->builtin()) {
                    case t_CHOICE:
                        print_name_type(tpas);
                        execute_choice_cpp(tpas);
                        break;
                    case t_SEQUENCE:
                        print_name_type(tpas);
                        execute_struct_cpp(tpas);
                        break;
                    case t_SET:
                        print_name_type(tpas);
                        execute_struct_cpp(tpas);
                        break;
                    case t_SEQUENCE_OF:
                        execute_structof_cpp(tpas);
                        break;
                    case t_SET_OF:
                        execute_structof_cpp(tpas);
                        break;
                    default:
                    {
                        if ((tpas) && (tpas->predefined()))
                            execute_predefined_cpp(tpas, tpas);
                    }
                }
            }
        }

        void maincpp_out::execute_predefined_cpp(typeassignment_entity_ptr self, typeassignment_entity_ptr ansec) {
            if (self->type()) {
                predefined_ptr predef = self->predefined();
                if (predef) {
                    switch (self->root_builtin()) {
                        case t_INTEGER:
                        {
                            execute_predefined_int_cpp(predef, self, ansec);
                            break;
                        }
                        case t_BIT_STRING:
                        {
                            execute_predefined_bs_cpp(predef, self, ansec);
                            break;
                        }
                        case t_ENUMERATED:
                        {
                            execute_predefined_int_cpp(predef, self, ansec);
                        }
                        default:
                        {
                        }
                    }
                }
            }
        }

        void maincpp_out::execute_predefineds_cpp(basic_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();

                if (tpas)
                    execute_predefined_cpp(tpas, self->as_typeassigment());
            }
        }

        void maincpp_out::execute_predefined_int_cpp(predefined_ptr prdf, typeassignment_entity_ptr self, typeassignment_entity_ptr ansec) {
            bool is_local_scope = ((self->scope()) && (self->scope()->as_typeassigment()));
            if (is_local_scope) {
                stream << "\n";
                for (basic_entity_vector::const_iterator it = prdf->values().begin(); it != prdf->values().end(); ++it) {
                    if (valueassignment_entity_ptr vlass = (*it)->as_valueassigment()) {
                        stream << tabformat() << "const ";
                        stream << type_str(self) << " ";
                        if (self->islocaldefined() && ansec)
                            stream << fulltype_str(ansec, false) << "::";
                        stream << ((namelower(nameconvert(self->name()) + "_"))) << nameconvert(vlass->name()) << " = ";
                        stream << nested_init_str(self->type(), value_int_str(vlass->value())) << ";\n";
                    }
                }
            }
        }

        void maincpp_out::execute_predefined_bs_cpp(predefined_ptr prdf, typeassignment_entity_ptr self, typeassignment_entity_ptr ansec) {
            bool is_local_scope = ((self->scope()) && (self->scope()->as_typeassigment()));
            if (is_local_scope) {
                stream << "\n";
                for (basic_entity_vector::const_iterator it = prdf->values().begin(); it != prdf->values().end(); ++it) {
                    if (valueassignment_entity_ptr vlass = (*it)->as_valueassigment()) {
                        stream << tabformat() << "const ";
                        stream << type_str(self) << " ";
                        if (self->islocaldefined() && ansec)
                            stream << fulltype_str(ansec, false) << "::";
                        stream << ((namelower(nameconvert(self->name()) + "_"))) << nameconvert(vlass->name()) << " = ";
                        stream << nested_init_str(self->type(), "bit_string(true, " + value_int_str(vlass->value()) + ")") << ";\n";
                    }
                }
            }
        }

        void maincpp_out::execute_defaultassignment_cpp(namedtypeassignment_entity_ptr self, typeassignment_entity_ptr ansec) {
            if (!self->has_arguments()) {
                if ((self->type()) && (self->_default()) && ansec) {
                    switch (self->type()->root_builtin()) {
                        case t_INTEGER:
                        case t_BOOLEAN:
                        case t_REAL:
                        case t_ENUMERATED:
                        case t_BIT_STRING:
                        case t_OBJECT_IDENTIFIER:
                        case t_RELATIVE_OID:
                        {
                            stream << "\n" << tabformat() << "const " << fromtype_str(self) << " " << fulltype_str(ansec, false) << "::"
                                    << nameconvert(self->name()) << "__default = " << valueassmnt_str(self->type(), self->_default()) << ";\n";
                            break;
                        }
                        default:
                        {
                        }
                    }
                }
            }
        }

        void maincpp_out::execute_access_member_cpp(typeassignment_entity_ptr self) {

            basic_entity_ptr scp;
            member_vect mmbr;
            load_member(mmbr, self);
            if (self->builtin() == t_CHOICE) {
                stream << "\n";
                for (member_vect::const_iterator it = mmbr.begin(); it != mmbr.end(); ++it) {
                    if (it->typ) {
                        stream << "\n" << tabformat(scp, 2);
                        if (it->typ->isprimitive())
                            stream << "ITU_T_CHOICES_DEFN( ";
                        else
                            stream << "ITU_T_CHOICEC_DEFN( ";
                        stream << fulltype_str(self, false) << "::" << it->name << ", " << it->name << ", ";
                        stream << fullpathtype_str(it->typ, self, it->typenam) << ", " << choice_enum_str(self, it->typ) << ");";
                    }
                }
            } else {
                stream << "\n";
                for (member_vect::const_iterator it = mmbr.begin(); it != mmbr.end(); ++it) {
                    stream << "\n" << tabformat(scp, 2);
                    switch (it->marker) {
                        case mk_none:
                        {
                            if (!option_no_holder())
                                stream << "ITU_T_HOLDERH_DEFN( ";
                            else
                                stream << "ITU_T_HOLDERN_DEFN( ";
                            break;
                        };
                        case mk_optional:
                            stream << "ITU_T_OPTIONAL_DEFN( ";
                            break;
                        case mk_default:
                            stream << "ITU_T_DEFAULTH_DEFN( ";
                            break;
                        default:
                        {
                            stream << "?( ";
                        }
                    }
                    stream << fulltype_str(self, false) << "::" << it->name << ", " << it->name << ", ";
                    stream << fullpathtype_str(it->typ, self, it->typenam) << ");";
                }
            }
        }

        void maincpp_out::execute_declare_cpp(typeassignment_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it)
                if (typeassignment_entity_ptr tpas = (*it)->as_typeassigment())
                    execute_declare_struct_cpp(tpas);
        }

        void maincpp_out::execute_declare_struct_cpp(typeassignment_entity_ptr self) {
            if (self) {
                switch (self->builtin()) {
                    case t_CHOICE: stream << "\n";
                        execute_choice_cpp(self);
                        break;
                    case t_SET:
                    case t_SEQUENCE: stream << "\n";
                        execute_struct_cpp(self);
                        break;
                    case t_SET_OF:
                    case t_SEQUENCE_OF:
                        execute_structof_cpp(self);
                        break;
                    default:
                    {
                    }
                }
            }
        }

        void maincpp_out::execute_choice_cpp(typeassignment_entity_ptr self) {

            execute_predefineds_cpp(self);

            //execute_ctor_hpp( self, scp);
            execute_declare_cpp(self);
            execute_access_member_cpp(self);

            if (option_ber_main())
                execute_archive_meth_cpp(self, "x690");



            stream << "\n ";
        }

        void maincpp_out::execute_struct_cpp(typeassignment_entity_ptr self) {

            execute_predefineds_cpp(self);

            execute_ctor_cpp(self);
            execute_declare_cpp(self);

            execute_default_cpp(self);

            if (option_ber_main())
                execute_archive_meth_cpp(self, "x690");

            execute_access_member_cpp(self);


            stream << "\n ";
        }

        void maincpp_out::execute_structof_cpp(typeassignment_entity_ptr self) {
            if (self && (self->type())) {
                if ((self->isstruct_of()) && (!self->childs().empty())) {
                    if (typeassignment_entity_ptr cpas = self->childs().front()->as_typeassigment()) {
                        if (cpas->isstruct_of()) {
                            execute_structof_cpp(cpas);
                        } else if (cpas->isstruct()) {
                            execute_declare_struct_cpp(cpas);
                        }
                    }
                }
            }
        }

        void maincpp_out::execute_ctor_cpp(typeassignment_entity_ptr self) {
            basic_entity_ptr scp;
            if ((self) && (self->type())) {
                switch (self->builtin()) {
                    case t_SET:
                    case t_SEQUENCE:
                    {
                        member_vect mmbr;
                        load_member(mmbr, self);
                        member_vect oblig = parse_membervct(mmbr, true);
                        member_vect nooblig = parse_membervct(mmbr, false);

                        stream << "\n";
                        stream << "\n" << tabformat(scp, 1) << fulltype_str(self, false) << "::" << type_str(self) << "()";
                        if (!oblig.empty()) {
                            stream << " : ";
                            for (member_vect::const_iterator it = oblig.begin(); it != oblig.end(); ++it) {
                                if (it != oblig.begin())
                                    stream << ", ";
                                stream << it->name << "_()";
                            }
                        }
                        stream << " {}; \n ";

                        if (!oblig.empty()) {
                            stream << "\n" << tabformat(scp, 1) << fulltype_str(self, false) << "::" << type_str(self) << "(";
                            for (member_vect::const_iterator it = oblig.begin(); it != oblig.end(); ++it) {
                                if (it != oblig.begin())
                                    stream << ",\n" << tabformat(scp, 2);
                                stream << "const " << it->typenam << "&  " << argumentname(it->name);
                            }
                            stream << ") : \n";
                            for (member_vect::const_iterator it = oblig.begin(); it != oblig.end(); ++it) {
                                if (it != oblig.begin())
                                    stream << ",\n";
                                stream << tabformat(scp, 2) << it->name << "_(" << argumentname(it->name) << ")";
                            }
                            stream << " {}; \n ";
                        }

                        if (/*!nooblig.empty() && (nooblig.size() > oblig.size())*/!nooblig.empty()) {
                            stream << "\n" << tabformat(scp, 1) << fulltype_str(self, false) << "::" << type_str(self) << "(";
                            for (member_vect::const_iterator it = nooblig.begin(); it != nooblig.end(); ++it) {
                                if (it != nooblig.begin())
                                    stream << ",\n" << tabformat(scp, 2);
                                stream << "ITU_T_SHARED( " << it->typenam << ")  " << argumentname(it->name);
                            }
                            stream << ") : \n";
                            for (member_vect::const_iterator it = nooblig.begin(); it != nooblig.end(); ++it) {
                                if (it != nooblig.begin())
                                    stream << ",\n";
                                stream << tabformat(scp, 2) << it->name << "_(";
                                if (option_no_holder() && (it->marker == mk_none))
                                    stream << "*";
                                stream << argumentname(it->name) << ")";
                            }
                            stream << " {}; \n ";
                        }

                        break;
                    }
                    default:
                    {
                    }
                }
            }
        }

        void maincpp_out::execute_default_cpp(typeassignment_entity_ptr self) {
            if ((self) && (self->type())) {
                switch (self->builtin()) {
                    case t_SET:
                    case t_SEQUENCE:
                    {
                        member_vect mmbr;
                        load_member(mmbr, self);
                        for (member_vect::const_iterator it = mmbr.begin(); it != mmbr.end(); ++it) {
                            if (it->marker == mk_default) {
                                execute_defaultassignment_cpp(it->typ, self);
                            }
                        }
                        break;
                    }
                    default:
                    {

                    }
                }
            }
        }

        static std::string quatation_val_static(basic_entity_ptr self) {
            return (self && self->as_typeassigment() && self->as_typeassigment()->isstring()) ? "<< \"\\\"\"" : "";
        }

        std::size_t maincpp_out::execute_struct_cout_meth(basic_entity_ptr self) {
            std::size_t cnt = 0;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && tpas->isstructure() && tpas->is_cpp_expressed()) {
                    typeassignment_entity_ptr chek_tpas;
                    if (tpas->isstruct_of() && !tpas->childs().empty() &&
                            tpas->childs().front() && tpas->childs().front()->as_typeassigment() &&
                            tpas->childs().front()->as_typeassigment()) {
                        chek_tpas = tpas->childs().front()->as_typeassigment();
                        if (!(chek_tpas->root_builtin() == t_CHOICE ||
                                chek_tpas->root_builtin() == t_SEQUENCE ||
                                chek_tpas->root_builtin() == t_SEQUENCE_OF ||
                                chek_tpas->root_builtin() == t_SET ||
                                chek_tpas->root_builtin() == t_SET_OF))
                            chek_tpas.reset();
                    }
                    if (tpas->isstruct() || chek_tpas) {
                        stream << "\n" << tabformat(basic_entity_ptr(), 2) << "std::ostream& operator<<(std::ostream& stream, const ";
                        stream << fulltype_str(tpas, false) << "& vl) {";
                        if (tpas->isstruct()) {
                            switch (tpas->builtin()) {
                                case t_CHOICE:
                                {
                                    stream << "\n" << tabformat(basic_entity_ptr(), 3) << "stream << \"{ \";";
                                    stream << "\n" << tabformat(basic_entity_ptr(), 3) << "switch (vl.type()) {";
                                    for (basic_entity_vector::iterator tit = tpas->childs().begin(); tit != tpas->childs().end(); ++tit) {
                                        if ((*tit)->as_named_typeassigment()) {
                                            if (is_named((*tit)->as_named_typeassigment()->marker())) {
                                                std::string fullpath = (self->as_typeassigment()) ?
                                                        fulltype_str(self->as_typeassigment(), false) : "";
                                                if (!fullpath.empty())
                                                    fullpath += "::";
                                                stream << "\n" << tabformat(basic_entity_ptr(), 4) << "case " << fullpath << choice_enum_str(tpas, (*tit)) << ": ";
                                                stream << "stream  << \"" << nameconvert((*tit)->as_named_typeassigment()->name()) <<
                                                        " :  \" " << quatation_val_static(*tit) << " << vl." <<
                                                        nameconvert((*tit)->as_named_typeassigment()->name()) << "() " <<
                                                        quatation_val_static(*tit) << "; break; ";
                                            }
                                        }
                                    }
                                    stream << "\n" << tabformat(basic_entity_ptr(), 4) << "default: { stream  <<  \" null \"; }\n";
                                    stream << tabformat(basic_entity_ptr(), 3) << "};";
                                    stream << "\n" << tabformat(basic_entity_ptr(), 3) << "stream << \" }\";";
                                    break;
                                }
                                case t_SEQUENCE:
                                case t_SET:
                                {
                                    member_vect mmbr;
                                    load_member(mmbr, tpas);
                                    stream << "\n" << tabformat(basic_entity_ptr(), 3) << "stream << \"{ \";";
                                    for (member_vect::const_iterator mit = mmbr.begin(); mit != mmbr.end(); ++mit) {
                                        if (mit->marker == mk_optional)
                                            stream << "\n" << tabformat(basic_entity_ptr(), 3) << "if (vl." << mit->name << "()) stream << \"" <<
                                                std::string((mit != mmbr.begin()) ? ", " : "") << mit->name << " :  \"   " <<
                                                quatation_val_static(mit->typ) << " << *(vl." << mit->name << "()) " << quatation_val_static(mit->typ) << ";";
                                        else
                                            stream << "\n" << tabformat(basic_entity_ptr(), 3) << "stream << \"" <<
                                            std::string((mit != mmbr.begin()) ? ", " : "") << mit->name <<
                                                " :  \" " << quatation_val_static(mit->typ) << " << vl." << mit->name << "()" << quatation_val_static(mit->typ) << ";";
                                    }
                                    stream << "\n" << tabformat(basic_entity_ptr(), 3) << "stream << \" }\";";
                                    break;
                                }
                                default:
                                {
                                }
                            }
                        } else if (tpas->isstruct_of() && chek_tpas) {
                            stream << "\n" << tabformat(basic_entity_ptr(), 3) << "for (" << fulltype_str(tpas, false);
                            stream << "::const_iterator it=vl.begin(); it!=vl.end();++it){";
                            stream << "\n" << tabformat(basic_entity_ptr(), 4) << "stream << \" {\" " << quatation_val_static(chek_tpas) <<
                                    " << *it <<  " << quatation_val_static(chek_tpas) << "\"}\";}; ";
                        }
                        stream << "\n" << tabformat(basic_entity_ptr(), 3) << "return stream;";
                        stream << "\n" << tabformat(basic_entity_ptr(), 2) << "};\n";
                        cnt++;
                    }
                    cnt += execute_struct_cout_meth(tpas);
                }
            }
            return cnt;
        }




        //////////////////////////////////////////////////////
        //  ber_cpp_out
        //////////////////////////////////////////////////////

        namedtypeassignment_entity_ptr ber_cpp_out::ber_helper_finder::check(typeassignment_entity_ptr tpas) {
            return (tpas && tpas->as_named() && tpas->type() && tpas->type()->ismultipe_tagged()) ?
                    tpas->as_named() : namedtypeassignment_entity_ptr();
        }

        void ber_cpp_out::execute() {
            execute_include(module_->name());

            stream << CHHEADER << "\n";
            execute_start_ns();

            stream << "\n";
            find_typeassignments<ber_helper_finder>(module_);
            stream << "\n";


            if (option_reverse_decl())
                execute_typeassignments<basic_entity_vector::const_reverse_iterator>(module_->childs().rbegin(), module_->childs().rend());
            else
                execute_typeassignments<basic_entity_vector::const_iterator>(module_->childs().begin(), module_->childs().end());


            execute_stop_ns();
            stream << CHBOTTOM << "\n";
        }

        void ber_cpp_out::add_helpers(namedtypeassignment_entity_ptr tpas) {

            basic_entity_ptr scp;
            if (tpas && tpas->type() && tpas->type()->ismultipe_tagged()) {
                stream << "\n" << tabformat(scp, 2) << execute_prefixed_static(declare_atom(declare_typedef, tpas,
                        get_ber_helper_name(tpas), get_ber_helper_name(tpas)), scp);
            }

        }

        void ber_cpp_out::execute_typeassignment(typeassignment_entity_ptr self) {
            if (self->is_cpp_expressed() && self->isstructure()) {
                if (self->isstruct()) {
                    print_name_type(self, self->moduleref());
                    execute_archive_meth_cpp(self, "x690");
                }
                for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it)
                    if ((*it)->as_typeassigment())
                        execute_typeassignment((*it)->as_typeassigment());
            }
        }







        //////////////////////////////////////////////////////
        //  per_cpp_out
        //////////////////////////////////////////////////////

        void per_cpp_out::execute() {
            execute_include(module_->name());

            stream << CHHEADER << "\n";
            execute_start_ns();

            stream << "\n";
            find_typeassignments<per_helper_finder>(module_);
            stream << "\n";

            print_helpers();

            if (option_reverse_decl())
                execute_typeassignments<basic_entity_vector::const_reverse_iterator>(module_->childs().rbegin(), module_->childs().rend());
            else
                execute_typeassignments<basic_entity_vector::const_iterator>(module_->childs().begin(), module_->childs().end());


            execute_stop_ns();
            stream << CHBOTTOM << "\n";
        }

        void per_cpp_out::execute_typeassignment(typeassignment_entity_ptr self) {
            if ((self->is_cpp_expressed()) && (self->isstructure())) {
                if (self->isstruct()) {
                    print_name_type(self, self->moduleref());
                    execute_archive_meth_cpp(self, "x691");
                }
                for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it)
                    if ((*it)->as_typeassigment())
                        execute_typeassignment((*it)->as_typeassigment());
            }
        }

        void per_cpp_out::execute_archive_choice_output(typeassignment_entity_ptr self) {

            basic_entity_ptr scp;

            bool has_extention = ((self->type()) && (self->type()->has_extention()));
            namedtypeassignment_entity_vct extentions = self->extentions();

            if (has_extention) {
                if (extentions.empty())
                    stream << "\n\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_WRITE_NULL;";
                else
                    stream << "\n\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_WRITE_CHOICE( " <<
                    choice_enum_str(self, extentions.front()) << ",  " <<
                    choice_enum_str(self, extentions.back()) << ");";
            }


            namedtypeassignment_entity_vct root = self->canonicalorder_root();

            bool can_extention = ((extentions.size()) && (has_extention));

            std::size_t scppad = 0;

            if (can_extention) {
                scppad++;
                stream << "\n\n" << tabformat(scp, 3) << "if (! ITU_T_EXTENTION) { ";
            }

            if (root.size()) {
                std::size_t rootcnt = root.size() - 1;
                std::size_t root_it = 0;
                if (rootcnt) {

                    stream << "\n" << tabformat(scp, 3 + scppad) <<
                            "switch(type()){";

                    for (namedtypeassignment_entity_vct::iterator it = root.begin(); it != root.end(); ++it) {
                        if ((*it)->as_named()) {
                            namedtypeassignment_entity_ptr named = (*it)->as_named();
                            if (named->type()) {
                                stream << "\n" << tabformat(scp, 4 + scppad) << "case ";
                                stream << choice_enum_str(self, (*it)) << ":  {";
                                stream << " ITU_T_SET_CONSTAINED_INDX(" << to_string(root_it++) << " , " << to_string(rootcnt) << "); ";
                                std::string tmpval = "value<" + fromtype_str(named) + " > (false , " + choice_enum_str(self, named) + ")";
                                stream << archive_member_per_str(named, tmpval);
                                stream << "; break; }";
                            }
                        }
                    }

                    stream << "\n" << tabformat(scp, 4 + scppad) << "default:{}";
                    stream << "\n" << tabformat(scp, 3 + scppad) << "}";
                    stream << "\n";
                } else {
                    if (root.front()->as_named()) {
                        namedtypeassignment_entity_ptr named = root.front()->as_named();
                        std::string tmpval = "value<" + fromtype_str(named) + " > (false , " + choice_enum_str(self, named) + ")";
                        stream << archive_member_per_str(named, tmpval);
                        stream << ";\n";
                    }
                }
            }

            if (can_extention) {
                std::size_t extention_it = 0;
                stream << tabformat(scp, 3) << "} ";
                stream << "\n" << tabformat(scp, 3) << "else { ";

                //// Extention

                stream << "\n" << tabformat(scp, 3 + scppad) <<
                        "switch(type()){";

                for (namedtypeassignment_entity_vct::iterator it = extentions.begin(); it != extentions.end(); ++it) {
                    if ((*it)->as_named()) {
                        namedtypeassignment_entity_ptr named = (*it)->as_named();
                        if (named->type()) {
                            stream << "\n" << tabformat(scp, 4 + scppad) << "case ";
                            stream << choice_enum_str(self, (*it)) << ":  {";
                            stream << " ITU_T_SET_NSN_SMALL_INDX(" << to_string(extention_it++) << "); ITU_T_START_OPEN; ";
                            std::string tmpval = "value<" + fromtype_str(named) + " > (false , " + choice_enum_str(self, named) + ")";
                            stream << archive_member_per_str(named, tmpval);
                            stream << ";ITU_T_END_OPEN; break; }";
                        }
                    }
                }

                stream << "\n" << tabformat(scp, 4 + scppad) << "default:{}";
                stream << "\n" << tabformat(scp, 3 + scppad) << "}";

                stream << "\n" << tabformat(scp, 3) << "}\n";

            }

            stream << tabformat(scp, 2) << "}";
            stream << "\n";
        }

        void per_cpp_out::execute_archive_choice_input(typeassignment_entity_ptr self) {

            basic_entity_ptr scp;

            bool has_extention = ((self->type()) && (self->type()->has_extention()));

            if (has_extention)
                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_READ;";

            namedtypeassignment_entity_vct root = self->canonicalorder_root();
            namedtypeassignment_entity_vct extentions = self->extentions();

            std::size_t scppad = 0;

            if (has_extention) {
                scppad++;
                stream << "\n\n" << tabformat(scp, 3) << "if (! ITU_T_EXTENTION) { ";
            }


            if (root.size()) {
                std::size_t rootcnt = root.size() - 1;
                std::size_t root_it = 0;
                if (rootcnt) {

                    stream << "\n\n" << tabformat(scp, 3 + scppad) << "ITU_T_GET_CONSTAINED_INDX(" << to_string(rootcnt) << ");\n";
                    stream << "\n" << tabformat(scp, 3 + scppad) << "switch(__indx__){";

                    for (namedtypeassignment_entity_vct::iterator it = root.begin(); it != root.end(); ++it) {
                        if ((*it)->as_named()) {
                            namedtypeassignment_entity_ptr named = (*it)->as_named();
                            if (named->type()) {
                                stream << "\n" << tabformat(scp, 4 + scppad) << "case ";
                                stream << to_string(root_it++) << ":  {";
                                std::string tmpval = "value<" + fromtype_str(named) + " > (true , " + choice_enum_str(self, named) + ")";
                                stream << archive_member_per_str(named, tmpval);
                                stream << "; break; }";
                            }
                        }
                    }

                    stream << "\n" << tabformat(scp, 4 + scppad) << "default:{}";
                    stream << "\n" << tabformat(scp, 3 + scppad) << "}";
                    stream << "\n";
                } else {
                    if (root.front()->as_named()) {
                        namedtypeassignment_entity_ptr named = root.front()->as_named();
                        std::string tmpval = "value<" + fromtype_str(named) + " > (true , " + choice_enum_str(self, named) + ")";
                        stream << archive_member_per_str(named, tmpval);
                        stream << ";\n";
                    }
                }
            }


            if (has_extention) {
                std::size_t extention_it = 0;
                stream << tabformat(scp, 3) << "} ";
                stream << "\n" << tabformat(scp, 3) << "else { ";

                //// Extention

                stream << "\n\n" << tabformat(scp, 3 + scppad) << "ITU_T_GET_NSN_SMALL_INDX;\n";
                stream << "\n" << tabformat(scp, 3 + scppad) << "switch(__indx__){";

                for (namedtypeassignment_entity_vct::iterator it = extentions.begin(); it != extentions.end(); ++it) {
                    if ((*it)->as_named()) {
                        namedtypeassignment_entity_ptr named = (*it)->as_named();
                        if (named->type()) {
                            stream << "\n" << tabformat(scp, 4 + scppad) << "case ";
                            stream << to_string(extention_it++) << ":  { ITU_T_START_OPEN;";
                            std::string tmpval = "value<" + fromtype_str(named) + " > (true , " + choice_enum_str(self, named) + ")";
                            stream << archive_member_per_str(named, tmpval);
                            stream << "; ITU_T_END_OPEN; break; }";
                        }
                    }
                }

                stream << "\n" << tabformat(scp, 4 + scppad) << "default:{ ITU_T_CLEAR_EXTENTION;}";
                stream << "\n" << tabformat(scp, 3 + scppad) << "}";

                stream << "\n" << tabformat(scp, 3) << "}\n";

            }

            stream << tabformat(scp, 2) << "}";
            stream << "\n";


        }

        static namedtypeassignment_entity_vct struct_optional_element(const namedtypeassignment_entity_vct & vl) {
            namedtypeassignment_entity_vct rslt;
            for (namedtypeassignment_entity_vct::const_iterator it = vl.begin(); it != vl.end(); ++it) {
                if ((*it)->as_named_typeassigment() &&
                        is_optional_or_default((*it)->as_named_typeassigment()->marker()))
                    rslt.push_back((*it));
            }
            return rslt;
        }

        static std::size_t struct_optional_count(const namedtypeassignment_entity_vct & vl) {
            std::size_t rslt = 0;
            for (namedtypeassignment_entity_vct::const_iterator it = vl.begin(); it != vl.end(); ++it) {
                if ((*it)->as_named_typeassigment() &&
                        is_optional_or_default((*it)->as_named_typeassigment()->marker()))
                    rslt++;
            }
            return rslt;
        }

        void per_cpp_out::execute_archive_struct_output(typeassignment_entity_ptr self) {

            basic_entity_ptr scp;
            namedtypeassignment_entity_vct root1 = self->child_root_1();
            namedtypeassignment_entity_vct root2 = self->child_root_2();
            namedtypeassignment_entity_vct root = root1;
            namedtypeassignment_entity_vct extentions = self->extentions();


            root.insert(root.end(), root2.begin(), root2.end());
            std::size_t opt_count = struct_optional_count(root);

            if (self->type() && self->type()->has_extention()) {
                if (!extentions.empty() && self->extention_count()) {
                    std::size_t extnum = 0;
                    bool needopr = false;
                    stream << "\n\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_GROUP_BOOL(  " << to_string(extnum) << " ) = ";
                    for (namedtypeassignment_entity_vct::iterator it = extentions.begin(); it != extentions.end(); ++it) {
                        if ((*it)->extentionnum()) {
                            if (extnum != (*(*it)->extentionnum())) {
                                extnum = *((*it)->extentionnum());
                                needopr = false;
                                stream << ";\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_GROUP_BOOL(  " << to_string(extnum) << " ) = ";
                            }
                            if (needopr)
                                stream << " || " << "\n" << tabformat(scp, 6);
                            else
                                needopr = true;
                            stream << " ITU_T_EXISTS_BOOL(" << nameconvert((*it)->name()) << "_)";
                        }
                    }
                    stream << ";\n";
                    stream << "\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_GROUPS_BMP = ";
                    for (std::size_t i = 0; i <= extnum; ++i) {
                        if (i)
                            stream << " + ";
                        stream << "ITU_T_EXTENTION_GROUP_AS_BMP( " << to_string(i) << ")";
                    }
                    stream << ";\n";
                    stream << "\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_WRITE;\n";
                } else
                    stream << "\n\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_WRITE_NULL;\n";
            }

            if (opt_count) {
                namedtypeassignment_entity_vct optels = struct_optional_element(root);
                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_OPTIONAL_BMP = ";
                for (namedtypeassignment_entity_vct::iterator it = optels.begin(); it != optels.end(); ++it) {
                    if (it != optels.begin())
                        stream << " + " << "\n" << tabformat(scp, 6);
                    stream << " ITU_T_EXISTS_BMP(" << nameconvert((*it)->name()) << "_)";
                }
                stream << ";\n";
                stream << "\n" << tabformat(scp, 3) << "ITU_T_OPTIONAL_WRITE;";
                stream << "\n";
            }

            for (namedtypeassignment_entity_vct::iterator it = root1.begin(); it != root1.end(); ++it)
                if ((*it)->type() && is_named((*it)->marker()))
                    execute_archive_member(*it);

            ///  Some for extention

            if (!extentions.empty() && self->extention_count()) {
                stream << "\n\n" << tabformat(scp, 3) << "if (ITU_T_EXTENTION) {\n";
                stream << "\n" << tabformat(scp, 4) << "ITU_T_EXTENTION_GROUPS_WRITE;\n";
                for (std::size_t i = 0; i < self->extention_count(); ++i) {
                    stream << "\n" << tabformat(scp, 5) << "if (ITU_T_EXTENTION_GROUPS_CHECK(" << to_string(i) << ")) {";
                    namedtypeassignment_entity_vct extention = self->extention_group(i);
                    if (extention.size() > 1) {
                        bool has_optional = false;
                        for (namedtypeassignment_entity_vct::iterator it = extention.begin(); it != extention.end(); ++it)
                            if (is_optional_or_default((*it)->marker()))
                                has_optional = true;

                        stream << "\n" << tabformat(scp, 6) << "ITU_T_START_OPEN;";
                        if (has_optional) {
                            stream << "\n" << tabformat(scp, 6) << "ITU_T_OPTIONAL_BMP = ";
                            bool is_first = true;
                            for (namedtypeassignment_entity_vct::iterator it = extention.begin(); it != extention.end(); ++it) {
                                if (is_optional_or_default((*it)->marker())) {
                                    if (is_first)
                                        is_first = false;
                                    else
                                        stream << " + " << "\n" << tabformat(scp, 9);
                                    stream << "ITU_T_EXISTS_BMP(" << nameconvert((*it)->name()) << "_)";
                                }
                            }
                            stream << ";\n" << tabformat(scp, 6) << "ITU_T_OPTIONAL_WRITE;";
                        }
                        for (namedtypeassignment_entity_vct::iterator it = extention.begin(); it != extention.end(); ++it)
                            execute_archive_member(*it, false, 0, 4);
                        stream << "\n" << tabformat(scp, 6) << "ITU_T_END_OPEN;";
                    } else {
                        if (!extention.empty()) {
                            stream << "\n" << tabformat(scp, 6) << "ITU_T_START_OPEN;";
                            execute_archive_member(extention.front(), false, 0, 4);
                            stream << "\n" << tabformat(scp, 6) << "ITU_T_END_OPEN;";
                        } else
                            stream << "\n????";
                    }
                    stream << "\n" << tabformat(scp, 5) << "}\n";
                }
                stream << "\n" << tabformat(scp, 3) << "};\n";
            }


            if (!root2.empty())
                for (namedtypeassignment_entity_vct::iterator it = root2.begin(); it != root2.end(); ++it)
                    if ((*it)->type() && is_named((*it)->marker()))
                        execute_archive_member(*it);

            stream << "\n";
            stream << tabformat(scp, 2) << "}";
            stream << "\n";
        }

        void per_cpp_out::execute_archive_struct_input(typeassignment_entity_ptr self) {

            basic_entity_ptr scp;
            namedtypeassignment_entity_vct root1 = self->child_root_1();
            namedtypeassignment_entity_vct root2 = self->child_root_2();
            namedtypeassignment_entity_vct root = root1;


            root.insert(root.end(), root2.begin(), root2.end());
            std::size_t opt_count = struct_optional_count(root);
            std::size_t opt_it = 0;
            if ((self->type()) && (self->type()->has_extention())) {
                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_READ;";
            }
            if (opt_count)
                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_OPTIONAL_READ(" << to_string(opt_count) << " );\n";
            for (namedtypeassignment_entity_vct::iterator it = root1.begin(); it != root1.end(); ++it) {
                if ((*it)->type()) {
                    if (is_named((*it)->marker())) {
                        bool is_opt = is_optional_or_default((*it)->marker());
                        execute_archive_member(*it, is_opt, is_opt ? opt_it : 0);
                        if (is_opt)
                            opt_it++;
                    }
                }
            }


            ///  Some for extention

            if ((self->type()) && (self->type()->has_extention())) {
                stream << "\n\n" << tabformat(scp, 3) << "if (ITU_T_EXTENTION) {\n";
                stream << "\n" << tabformat(scp, 4) << "ITU_T_EXTENTION_GROUPS_READ;\n";

                for (std::size_t i = 0; i < self->extention_count(); ++i) {
                    stream << "\n" << tabformat(scp, 5) << "if (ITU_T_EXTENTION_GROUPS_CHECK(" << to_string(i) << ")) {";
                    stream << "\n" << tabformat(scp, 6) << "ITU_T_START_OPEN;";

                    namedtypeassignment_entity_vct extention = self->extention_group(i);
                    if (extention.size() > 1) {
                        std::size_t opt_count = 0;
                        for (namedtypeassignment_entity_vct::iterator it = extention.begin(); it != extention.end(); ++it) {
                            if ((is_optional_or_default((*it)->marker())))
                                opt_count++;
                        }
                        std::size_t opt_it = 0;
                        if (opt_count)
                            stream << "\n" << tabformat(scp, 6) << "ITU_T_OPTIONAL_READ(" << to_string(opt_count) << " );\n";

                        for (namedtypeassignment_entity_vct::iterator it = extention.begin(); it != extention.end(); ++it) {
                            if ((*it)->type()) {
                                if (is_named((*it)->marker())) {
                                    bool is_opt = is_optional_or_default((*it)->marker());
                                    execute_archive_member(*it, is_opt, is_opt ? opt_it : 0, 3);
                                    if (is_opt)
                                        opt_it++;
                                }
                            }
                        }
                    } else {
                        execute_archive_member(extention.front(), false, 0, 3);
                    }
                    stream << "\n" << tabformat(scp, 6) << "ITU_T_END_OPEN;";
                    stream << "\n" << tabformat(scp, 5) << "}\n";
                }
                stream << "\n" << tabformat(scp, 4) << "ITU_T_CLEAR_EXTENTIONS(" << to_string(self->extention_count()) << ");";
                stream << "\n" << tabformat(scp, 3) << "};\n";
            }

            if (!root2.empty()) {
                for (namedtypeassignment_entity_vct::iterator it = root2.begin(); it != root2.end(); ++it) {
                    if ((*it)->type()) {
                        if (is_named((*it)->marker())) {
                            bool is_opt = is_optional_or_default((*it)->marker());
                            execute_archive_member(*it, is_opt, is_opt ? opt_it : 0);
                            if (is_opt)
                                opt_it++;
                        }
                    }
                }
            }


            stream << "\n";
            stream << tabformat(scp, 2) << "}";
            stream << "\n";
        }

        template<typename T>
        static std::string int_constr_str(T num, bool for_strust = false) {
            if (for_strust) {
                if (num <= std::numeric_limits<boost::int32_t>::min()) {
                    return (num == std::numeric_limits<boost::int32_t>::min()) ?
                            (to_string(std::numeric_limits<int32_t>::max()) + "-1") : (to_string(num) + "L");
                } else if (num <= std::numeric_limits<boost::int16_t>::min()) {
                    return (num == std::numeric_limits<boost::int16_t>::min()) ?
                            (to_string(std::numeric_limits<int16_t>::max()) + "-1") : (to_string(num));
                } else if (num <= std::numeric_limits<boost::int16_t>::min()) {
                    return (num == std::numeric_limits<boost::int8_t>::min()) ?
                            (to_string(std::numeric_limits<int8_t>::max()) + "-1") : (to_string(num));
                }
            } else {
                if (num <= std::numeric_limits<boost::int32_t>::min()) {
                    return (num == std::numeric_limits<boost::int32_t>::min()) ?
                            ("std::numeric_limits<int32_t>::min()") : (to_string(num) + "L");
                } else if (num <= std::numeric_limits<boost::int16_t>::min()) {
                    return (num == std::numeric_limits<boost::int16_t>::min()) ?
                            ("std::numeric_limits<int16_t>::min()") : to_string(num);
                } else if (num <= std::numeric_limits<boost::int16_t>::min()) {
                    return (num == std::numeric_limits<boost::int8_t>::min()) ?
                            ("std::numeric_limits<int8_t>::min()") : to_string(num);
                } else if (num <= std::numeric_limits<boost::int8_t>::max()) {
                    return (num == std::numeric_limits<boost::int8_t>::max()) ?
                            std::string("std::numeric_limits<int8_t>::max()") : to_string(num);
                } else if (num <= std::numeric_limits<boost::uint8_t>::max()) {
                    return (num == std::numeric_limits<boost::uint8_t>::max()) ?
                            std::string("std::numeric_limits<uint8_t>::max()") : to_string(num);
                } else if (num <= std::numeric_limits<boost::int16_t>::max()) {
                    return (num == std::numeric_limits<boost::int16_t>::max()) ?
                            std::string("std::numeric_limits<int8_t>::max()") : to_string(num);
                } else if (num <= std::numeric_limits<boost::uint16_t>::max()) {
                    return (num == std::numeric_limits<boost::uint16_t>::max()) ?
                            std::string("std::numeric_limits<uint16_t>::max()") : to_string(num);
                } else if (num <= std::numeric_limits<boost::int32_t>::max()) {
                    return (num == std::numeric_limits<boost::int32_t>::max()) ?
                            std::string("std::numeric_limits<int32_t>::max()") : to_string(num);
                } else if (num <= std::numeric_limits<boost::uint32_t>::max()) {
                    return (num == std::numeric_limits<boost::uint32_t>::max()) ?
                            std::string("std::numeric_limits<uint32_t>::max()") : to_string(num);
                } else if (num <= std::numeric_limits<boost::int64_t>::max()) {
                    return (num == std::numeric_limits<boost::int64_t>::max()) ?
                            std::string("std::numeric_limits<int64_t>::max()") : (to_string(num) + "L");
                } else if (num <= std::numeric_limits<boost::uint64_t>::max()) {
                    return (num == std::numeric_limits<boost::uint64_t>::max()) ?
                            std::string("std::numeric_limits<uint64_t>::max()") : (to_string(num) + "UL");
                }
            }
            return to_string(num);
        }

        static std::string left_int_constr_str(integer_constraints_ptr intconstr, bool for_strust = false) {
            if (intconstr) {
                integer_constraints::range_type main_int_cnstr = intconstr->to_per().main();
                if (main_int_cnstr.left_ptr()) {
                    return "static_cast<" + builtin_int_str(intconstr) + " >(" + int_constr_str(main_int_cnstr.left(), for_strust) + ")";
                }
            }
            return "?num?";
        }

        static std::string right_int_constr_str(integer_constraints_ptr intconstr, bool for_strust = false) {
            if (intconstr) {
                integer_constraints::range_type main_int_cnstr = intconstr->to_per().main();
                if (main_int_cnstr.right_ptr()) {
                    return "static_cast<" + builtin_int_str(intconstr) + " >(" + int_constr_str(main_int_cnstr.right(), for_strust) + ")";
                }
            }
            return "?num?";
        }

        std::string per_cpp_out::archive_member_per_constr(helper_ptr hlpr, const std::string& name, tagmarker_type dfltopt, size_constraints_ptr sizeconst, integer_constraints_ptr intconstr, bool alpha) {
            if (sizeconst) {
                size_constraints::range_type main_size_cnstr = sizeconst->to_per().main();
                bool ext_size_cnstr = sizeconst->to_per().has_extention();
                if (intconstr || alpha) {
                    if (hlpr && (hlpr->ts)) {
                        if (main_size_cnstr.single())
                            return "ITU_T_BIND_EXSIZE_SNGLCONSTRAINT" + std::string(ext_size_cnstr ? "_EXT" : "") + "( " +
                            fromtype_str(hlpr->ts) + ", " + hlpr->name + "__shelper, " + name_arch(name, dfltopt) + ", " +
                            std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ?num? ")) + ")";
                        else if (main_size_cnstr.right_semi())
                            return "ITU_T_BIND_EXSIZE_SEMICONSTRAINT" + std::string(ext_size_cnstr ? "_EXT" : "") + "( " +
                            fromtype_str(hlpr->ts) + ", " + hlpr->name + "__shelper, " + name_arch(name, dfltopt) + ", " +
                            std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ?num? ")) + ")";
                        else
                            return "ITU_T_BIND_EXSIZE_CONSTRAINT" + std::string(ext_size_cnstr ? "_EXT" : "") + "( " +
                            fromtype_str(hlpr->ts) + ", " + hlpr->name + "__shelper, " + name_arch(name, dfltopt) + ", " +
                            std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ?num? ")) + ", " +
                            std::string(main_size_cnstr.right_ptr() ? to_string(main_size_cnstr.right()) : std::string(" ?num? ")) + ")";
                    } else return "??? Per binding";
                } else {
                    if (main_size_cnstr.single())
                        return "ITU_T_BIND_SIZE_SNGLCONSTRAINT" + std::string(ext_size_cnstr ? "_EXT" : "") + "( " + name_arch(name, dfltopt) + ", " +
                        std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ?num? ")) + ")";
                    else if (main_size_cnstr.right_semi())
                        return "ITU_T_BIND_SIZE_SEMICONSTRAINT" + std::string(ext_size_cnstr ? "_EXT" : "") + "( " + name_arch(name, dfltopt) + ", " +
                        std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ?num? ")) + ")";
                    else
                        return "ITU_T_BIND_SIZE_CONSTRAINT" + std::string(ext_size_cnstr ? "_EXT" : "") + "( " + name_arch(name, dfltopt) + ", " +
                        std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ?num? ")) + ", " +
                        std::string(main_size_cnstr.right_ptr() ? to_string(main_size_cnstr.right()) : std::string(" ?num? ")) + ")";
                }
            } else if (intconstr) {
                integer_constraints::range_type main_int_cnstr = intconstr->to_per().main();
                bool ext_int_cnstr = intconstr->to_per().has_extention();
                if (main_int_cnstr.single())
                    return "ITU_T_BIND_NUM_SNGLCONSTRAINT" + std::string(ext_int_cnstr ? "_EXT" : "") + "( " + name_arch(name, dfltopt) + ", " +
                    left_int_constr_str(intconstr) + ")";
                else if (main_int_cnstr.right_semi())
                    return "ITU_T_BIND_NUM_SIMICONSTRAINT" + std::string(ext_int_cnstr ? "_EXT" : "") + "( " + name_arch(name, dfltopt) + ", " +
                    left_int_constr_str(intconstr) + ")";
                else
                    return "ITU_T_BIND_NUM_CONSTRAINT" + std::string(ext_int_cnstr ? "_EXT" : "") + "( " + name_arch(name, dfltopt) + ", " +
                    left_int_constr_str(intconstr) + ", " +
                    right_int_constr_str(intconstr) + ")";
            } else if (alpha) {
                if (hlpr && (hlpr->ts))
                    return "ITU_T_BIND_EX_CONSTRAINT(" + fromtype_str(hlpr->ts) + ", " + hlpr->name + "__shelper, " + name_arch(name, dfltopt) + ")";
                else
                    return "?Per binding?";
            }
            return "ITU_T_BIND_PER(" + name_arch(name, dfltopt) + ")";
        }

        std::string per_cpp_out::archive_member_per_str(namedtypeassignment_entity_ptr self, const std::string & name) {
            tagmarker_type dfltopt = self->extentionnum() ? mk_optional : self->marker();
            if ((dfltopt == mk_default) && (self->isstruct_of()))
                dfltopt = mk_optional;
            //if (self->prefixed_typeassignment())
            //dfltopt = mk_exception;
            helper_ptr helper = per_helper_finder::check(self);
            if (self->type()) {
                if (self->type()->can_per_constraints()) {
                    type_atom_ptr tmp = self->type();
                    size_constraints_ptr szconstr = tmp->size_constraint() ? tmp->size_constraint() : size_constraints_ptr();
                    integer_constraints_ptr intconstr = tmp->integer_constraint() ? tmp->integer_constraint() : integer_constraints_ptr();
                    bool alpha = (((tmp->char8_constraint())) || (tmp->tuple_constraint()) || (tmp->quadruple_constraint()));
                    return archive_member_per_constr(helper, name, dfltopt, szconstr, intconstr, alpha);
                } else if (helper) {
                    if (helper->type == pht_enumerated) {
                        return "ITU_T_BIND_PER_ENUM(" + name_arch(name, dfltopt) + ", " + helper->name + "__helper)";
                    } else if ((helper->type == pht_structof_enum) || (helper->type == pht_structof_int)) {
                        return "ITU_T_BIND_EX_CONSTRAINT(" + fromtype_str(self) + ", " + helper->name + "__shelper, " + name_arch(name, dfltopt) + ")";
                    }
                }
            }
            return "ITU_T_BIND_PER(" + name_arch(name, dfltopt) + ")";
        }

        void per_cpp_out::execute_archive_member(namedtypeassignment_entity_ptr self, bool opt, std::size_t optnum, std::size_t scpnum) {
            basic_entity_ptr scp;
            if (self->type()) {
                stream << "\n";
                stream << tabformat(scp, 3 + scpnum);
                if (opt)
                    stream << "ITU_T_OPTIONAL_CHECK(" << to_string(optnum) << ")  ";
                stream << archive_member_per_str(self, nameconvert(self->name()) + "_") << ";";
            }
        }





        //  simple criteria

        static typeassignment_entity_ptr next_reff(typeassignment_entity_ptr vl) {
            if (vl && (vl->extract_type()) &&
                    (vl->extract_type()->isrefferrence()) &&
                    (vl->extract_type()->reff())) {
                if (vl->extract_type()->reff()->as_typeassigment())
                    return vl->extract_type()->reff()->as_typeassigment();
            }
            return typeassignment_entity_ptr();
        }


        //  simple criteria 

        struct find_simple_ta_criteria {

            static typeassignment_entity_ptr calculate(typeassignment_entity_ptr vl) {
                if (typeassignment_entity_ptr next = next_reff(vl))
                    return calculate(next);
                return vl;
            }
        };

        //  char8 alphabet criteria        

        struct find_int_per_ta_criteria {

            static typeassignment_entity_ptr calculate(typeassignment_entity_ptr vl) {
                if (vl->type()) {
                    if (typeassignment_entity_ptr next = next_reff(vl)) {
                        if (next->type()) {
                            integer_constraints_ptr crnt_ptr = vl->type()->integer_constraint();
                            integer_constraints_ptr nxt_ptr = next->type()->integer_constraint();
                            if (crnt_ptr && nxt_ptr) {
                                integer_constraints crnt = crnt_ptr->to_per();
                                integer_constraints nxt = nxt_ptr->to_per();
                                if ((crnt.set() == nxt.set()) && (crnt.has_extention() == nxt.has_extention()))
                                    return calculate(next);
                            }
                        }
                    }
                }
                return vl;
            }
        };

        //  char8 alphabet criteria        

        struct find_char8_alphabet_ta_criteria {

            static typeassignment_entity_ptr calculate(typeassignment_entity_ptr vl) {
                if (vl->type()) {
                    if (typeassignment_entity_ptr next = next_reff(vl)) {
                        if (next->type()) {
                            char8_constraints_ptr crnt_ptr = vl->type()->char8_constraint();
                            char8_constraints_ptr nxt_ptr = next->type()->char8_constraint();
                            if (crnt_ptr && nxt_ptr) {
                                char8_constraints crnt = crnt_ptr->to_alphabet_per();
                                char8_constraints nxt = nxt_ptr->to_alphabet_per();
                                if ((crnt.set() == nxt.set()) && (crnt.has_extention() == nxt.has_extention()))
                                    return calculate(next);
                            }
                        }
                    }
                }
                return vl;
            }
        };

        struct find_tuple_alphabet_ta_criteria {

            static typeassignment_entity_ptr calculate(typeassignment_entity_ptr vl) {
                if (vl->type()) {
                    if (typeassignment_entity_ptr next = next_reff(vl)) {
                        if (next->type()) {
                            tuple_constraints_ptr crnt_ptr = vl->type()->tuple_constraint();
                            tuple_constraints_ptr nxt_ptr = next->type()->tuple_constraint();
                            if (crnt_ptr && nxt_ptr) {
                                tuple_constraints crnt = crnt_ptr->to_alphabet_per();
                                tuple_constraints nxt = nxt_ptr->to_alphabet_per();
                                if ((crnt.set() == nxt.set()) && (crnt.has_extention() == nxt.has_extention()))
                                    return calculate(next);
                            }
                        }
                    }
                }
                return vl;
            }
        };

        struct find_utf_alphabet_ta_criteria {

            static typeassignment_entity_ptr calculate(typeassignment_entity_ptr vl) {
                if (vl->type()) {
                    if (typeassignment_entity_ptr next = next_reff(vl)) {
                        if (next->type()) {
                            quadruple_constraints_ptr crnt_ptr = vl->type()->quadruple_constraint();
                            quadruple_constraints_ptr nxt_ptr = next->type()->quadruple_constraint();
                            if (crnt_ptr && nxt_ptr) {
                                quadruple_constraints crnt = crnt_ptr->to_alphabet_per();
                                quadruple_constraints nxt = nxt_ptr->to_alphabet_per();
                                if ((crnt.set() == nxt.set()) && (crnt.has_extention() == nxt.has_extention()))
                                    return calculate(next);
                            }
                        }
                    }
                }
                return vl;
            }
        };

        per_cpp_out::helper_ptr per_cpp_out::per_helper_finder::check(typeassignment_entity_ptr tpas) {
            if (tpas && (tpas->type()) && (tpas->is_cpp_expressed())) {
                if (tpas->type()->root_builtin() == t_ENUMERATED) {
                    typeassignment_entity_ptr fnd = tpas->criteria_typeassignment<find_simple_ta_criteria>();
                    return helper_ptr(new helper(get_per_helper_name(fnd), pht_enumerated, fnd));
                } else if ((tpas->type()->root_builtin() == t_SET_OF) || (tpas->type()->root_builtin() == t_SEQUENCE_OF)) {
                    typeassignment_entity_ptr fnd = tpas->criteria_typeassignment<find_simple_ta_criteria>();
                    if (fnd && (!fnd->childs().empty())) {
                        typeassignment_entity_ptr cpas = fnd->childs().front()->as_typeassigment();
                        if (cpas->root_builtin() == t_ENUMERATED) {
                            fnd = cpas->criteria_typeassignment<find_simple_ta_criteria>();
                            return helper_ptr(new helper(get_per_helper_name(fnd), pht_structof_enum, fnd));
                        } else if ((cpas->type()) && (cpas->type()->integer_constraint())) {
                            fnd = cpas->criteria_typeassignment<find_int_per_ta_criteria>();
                            return helper_ptr(new helper(get_per_helper_name(fnd), pht_structof_int, fnd));
                        }
                    }
                } else if (tpas->type()->char8_constraint()) {
                    typeassignment_entity_ptr fnd = tpas->criteria_typeassignment<find_char8_alphabet_ta_criteria>();
                    return helper_ptr(new helper(get_per_helper_name(fnd), pht_char8_alhabet, fnd));
                } else if (tpas->type()->tuple_constraint()) {
                    typeassignment_entity_ptr fnd = tpas->criteria_typeassignment<find_tuple_alphabet_ta_criteria>();
                    return helper_ptr(new helper(get_per_helper_name(fnd), pht_tuple_alhabet, fnd));
                } else if (tpas->type()->quadruple_constraint()) {
                    typeassignment_entity_ptr fnd = tpas->criteria_typeassignment<find_utf_alphabet_ta_criteria>();
                    return helper_ptr(new helper(get_per_helper_name(fnd), pht_utf_alhabet, fnd));
                }
            }
            return helper_ptr();
        }

        void per_cpp_out::add_helpers(helper_ptr hlpr) {
            if (hlpr) {
                if (helpers_chk.find(*hlpr) == helpers_chk.end()) {
                    helpers.push_back(hlpr);
                    helpers_chk.insert(*hlpr);
                }
            }
        }

        void per_cpp_out::print_helpers_header(helper_ptr hlpr) {
            basic_entity_ptr scp;
            stream << "\n\n";
            stream << tabformat(scp, 2);
            stream << "//  helper name:   " << hlpr->name << "           type: ";
            switch (hlpr->type) {
                case pht_enumerated: stream << " enumerated helper ";
                    break;
                case pht_structof_int: stream << " struct of constrained int helper";
                    break;
                case pht_structof_enum: stream << " struct of enumerated helper";
                    break;
                case pht_char8_alhabet:
                case pht_tuple_alhabet:
                case pht_utf_alhabet: stream << " alphabet helper";
                    break;
                default:
                {
                }
            }
            stream << "   ";
            mark_constraints(hlpr->ts);
            stream << "\n";
        }

        void per_cpp_out::print_helper(helper_ptr hlpr) {
            print_helpers_header(hlpr);
        }

        void per_cpp_out::print_enumeraded_helper(const std::string& name, predefined_ptr predef) {
            basic_entity_ptr scp;
            if (predef) {
                stream << tabformat(scp, 2);
                stream << "ITU_T_PER_ENUMCODER";
                bool ext = ((predef->extended()) && (predef->values().back()) &&
                        (predef->values().back()->as_valueassigment())); // extend and has ext;
                if (ext)
                    stream << "_EXT";
                stream << "(" << name << "__helper, ";
                if (!ext)
                    stream << std::string(predef->extended() ? "true, " : "false, ");
                stream << "ITU_T_ARRAY(";
                bool fst = true;
                for (basic_entity_vector::const_iterator it = predef->values().begin(); it != predef->values().end(); ++it) {
                    if ((*it)->as_valueassigment()) {
                        if (!fst)
                            stream << ", ";
                        else
                            fst = false;
                        if ((*it)->extract_value())
                            stream << value_int_str((*it)->extract_value());
                        else
                            stream << " ??? ";
                    } else {
                        if (!ext)
                            break;
                        stream << "), ITU_T_ARRAY(";
                        fst = true;
                    }
                }
                stream << "));";
                stream << "\n";
            } //else
            //stream << "#error ";
        }

        void per_cpp_out::print_struct_int_helper(helper_ptr hlpr) {
            basic_entity_ptr scp;
            if ((hlpr->ts) && (hlpr->ts->type()) && (hlpr->ts->type()->integer_constraint())) {
                stream << tabformat(scp, 2);
                integer_constraints::range_type main_int_cnstr = hlpr->ts->type()->integer_constraint()->to_per().main();
                std::string name = hlpr->name + "__shelper";
                bool ext_int_cnstr = hlpr->ts->type()->integer_constraint()->to_per().has_extention();
                if (main_int_cnstr.single())
                    stream << "ITU_T_REGISTRATE_NUM_SNGLCONSTRAINT" << std::string(ext_int_cnstr ? "_EXT" : "") << "( " << name << ", " << fromtype_str(hlpr->ts) << ", " <<
                    left_int_constr_str(hlpr->ts->type()->integer_constraint(), true) << ")";
                else if (main_int_cnstr.right_semi())
                    stream << "ITU_T_REGISTRATE_NUM_SEMICONSTRAINTTRAINT" << std::string(ext_int_cnstr ? "_EXT" : "") << "( " << name << ", " << fromtype_str(hlpr->ts) << ", " <<
                    left_int_constr_str(hlpr->ts->type()->integer_constraint(), true) << ")";
                else
                    stream << "ITU_T_REGISTRATE_NUM_CONSTRAINT" << std::string(ext_int_cnstr ? "_EXT" : "") << "( " << name << ", " << fromtype_str(hlpr->ts) << ", " <<
                    left_int_constr_str(hlpr->ts->type()->integer_constraint(), true) << ", " <<
                    right_int_constr_str(hlpr->ts->type()->integer_constraint(), true) << ")";
            }
        }

        void per_cpp_out::print_struct_enum_helper(helper_ptr hlpr) {
            basic_entity_ptr scp;
            if (hlpr->ts) {
                stream << tabformat(scp, 2);
                stream << "ITU_T_REGISTRATE_ENUM_CONSTRAINT(" << hlpr->name << "__shelper, " << hlpr->name << "__helper);";
            }
        }

        static std::set<boost::uint8_t> get_alhabet_static(const range_constraints<std::string::value_type>& rng) {
            std::set<boost::uint8_t> rslt;
            for (range_constraints<std::string::value_type>::container_type::const_iterator it = rng.set().begin(); it != rng.set().end(); ++it)
                for (boost::uint8_t i = static_cast<boost::uint8_t> (it->left_ptr() ? (it->left()) : (0));
                        i <= static_cast<boost::uint8_t> ((it->right_ptr() ? (it->right()) : (0xFF))); ++i)
                    rslt.insert(i);
            return rslt;
        }

        static std::set<boost::uint8_t> get_alhabet_static(const range_constraints<tuple>& rng) {
            std::set<boost::uint8_t> rslt;
            for (range_constraints<tuple>::container_type::const_iterator it = rng.set().begin(); it != rng.set().end(); ++it) {
                boost::uint8_t lft = it->left_ptr() ? (it->left().tablecolumn * 16 + it->left().tablerow) : 0;
                boost::uint8_t rght = it->right_ptr() ? (it->right().tablecolumn * 16 + it->right().tablerow) : 255;
                for (boost::uint8_t i = lft; i <= rght; ++i)
                    rslt.insert(i);
            }
            return rslt;
        }

        static std::set<boost::uint32_t> get_alhabet_static(const range_constraints<quadruple>& rng) {
            std::set<boost::uint32_t> rslt;
            for (range_constraints<quadruple>::container_type::const_iterator it = rng.set().begin(); it != rng.set().end(); ++it) {
                boost::uint32_t lft = it->left_ptr() ? (it->left().group * 127 + it->left().plane * 256 + it->left().row * 256 + it->left().cell) : 0;
                boost::uint32_t rght = it->right_ptr() ? (it->right().group * 127 + it->right().plane * 256 + it->right().row * 256 + it->right().cell) : 0x7FFFFFFF;
                if ((rght - lft) <= 1024) {
                    for (boost::uint32_t i = lft; i <= rght; ++i)
                        rslt.insert(i);
                }
            }
            return rslt;
        }

        template<typename T>
        static std::string print_alhabet_static(typeassignment_entity_ptr tpas, const std::string& name, const std::set<T>& st) {
            typedef typename std::set<T>::const_iterator const_iterator;
            std::string rslt = "ITU_T_PER_STRINGCODER";
            if (st.empty())
                return "ITU_T_PER_STRINGCODER( ?" + name + "__shelper)";
            std::size_t sz = st.size();
            std::size_t bsz = 1;
            while (sz >>= 1)
                bsz++;
            std::size_t asz = (bsz > 16) ? 32 : ((bsz > 8) ? 16 : ((bsz > 4) ?
                    8 : ((bsz > 2) ? 4 : ((bsz > 1) ? 2 : 1))));
            T maxvl = *st.rbegin();
            bool areindex = maxvl >= (1 << asz);
            bool breindex = maxvl >= (1 << bsz);
            if (!areindex && !breindex)
                rslt += "1";
            else
                rslt += "2";
            rslt += ("(" + name + "__shelper , boost::asn1::" + builtin_str(tpas->root_builtin()) + "::value_type ,");

            rslt += (" " + to_string(asz));
            rslt += (", " + to_string(bsz));
            if (!areindex && !breindex) {
                rslt += (");\n");
                return rslt;
            }
            rslt += " , ITU_T_ARRAY(";
            for (const_iterator it = st.begin(); it != st.end(); ++it) {
                if (it != st.begin())
                    rslt += ", ";
                rslt += ("\'\\x" + num_to_hex<T>(*it) + "\'");
            }
            rslt += " ), ";
            rslt += (areindex ? "true" : " false");
            rslt += (");\n");
            return rslt;
        }

        void per_cpp_out::print_struct_alphabet_helper(helper_ptr hlpr) {
            basic_entity_ptr scp;
            if (hlpr->ts && hlpr->ts->type()) {
                std::string typenm = builtin_str(hlpr->ts->root_builtin());
                if (hlpr->ts->type()->char8_constraint() || hlpr->ts->type()->tuple_constraint()) {
                    std::set<boost::uint8_t> vlset = hlpr->ts->type()->char8_constraint() ?
                            get_alhabet_static(hlpr->ts->type()->char8_constraint()->to_alphabet_per()) :
                            get_alhabet_static(hlpr->ts->type()->tuple_constraint()->to_alphabet_per());
                    if (vlset.size() > 1) {
                        stream << tabformat(scp, 2);
                        stream << print_alhabet_static(hlpr->ts, hlpr->name, vlset);
                        return;
                    }
                } else if (hlpr->ts->type()->quadruple_constraint()) {
                    std::set<boost::uint32_t> vlset = get_alhabet_static(hlpr->ts->type()->quadruple_constraint()->to_alphabet_per());
                    if ((vlset.size() > 1) && (vlset.size() < 512)) {
                        stream << tabformat(scp, 2);
                        stream << print_alhabet_static(hlpr->ts, hlpr->name, vlset);
                        return;
                    }
                    return;
                }
                stream << tabformat(scp, 2);
                stream << "struct " << hlpr->name << "__shelper" << " { ? null or compicated manually case.  };\n";
            }
        }

        void per_cpp_out::print_helpers() {
            for (helper_vct::iterator it = helpers.begin(); it != helpers.end(); ++it) {
                if ((*it)->type == pht_enumerated) {
                    print_helper(*it);
                    if (((*it)->ts))
                        print_enumeraded_helper((*it)->name, (*it)->ts->predefined());
                }
            }
            for (helper_vct::iterator it = helpers.begin(); it != helpers.end(); ++it) {
                if ((*it)->type != pht_enumerated) {
                    print_helper(*it);
                    switch ((*it)->type) {
                        case pht_enumerated:;
                            break;
                        case pht_structof_int: print_struct_int_helper(*it);
                            break;
                        case pht_structof_enum: print_struct_enum_helper(*it);
                            break;
                        case pht_char8_alhabet:
                        case pht_tuple_alhabet:
                        case pht_utf_alhabet: print_struct_alphabet_helper(*it);
                            break;
                        default:
                        {
                        }
                    }
                }
            }
        }

    }
}
