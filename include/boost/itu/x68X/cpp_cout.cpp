//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/cpp_cout.hpp>
#include <boost/itu/asn1/utf8.hpp>


namespace x680 {
    namespace cpp {

        template<typename T>
        std::string to_string(T val) {
            try {
                return boost::lexical_cast<std::string > (val);
            } catch (boost::bad_lexical_cast) {
            }
            return "???";
        }

        enum declare_type {
            declare_typedef,
            declare_seq,
            declare_set,
            declare_explicit,
            declare_implicit
        };

        struct declare_atom {

            declare_atom() :
            decl(declare_typedef), remote_(false) {
            };

            declare_atom(declare_type decl_, typeassignment_entity_ptr tp, const std::string& typenam_, const std::string& from_type_, bool rem = false) :
            decl(decl_), typ(tp), typenam(typenam_), from_type(from_type_), remote_(rem) {
            };

            declare_atom(declare_type decl_, typeassignment_entity_ptr tp, const std::string& typenam_, const std::string& from_type_, const std::string& tag_, const std::string& _class_, bool rem = false) :
            decl(decl_), typ(tp), typenam(typenam_), from_type(from_type_), tag(tag_), class_(_class_), remote_(rem) {
            };

            declare_type decl;
            typeassignment_entity_ptr typ;
            std::string typenam;
            std::string from_type;
            std::string tag;
            std::string class_;
            bool remote_;

        };

        struct member_atom {

            member_atom(tagmarker_type mkr = mk_extention) :
            marker(mkr), ischoice(false), afterextention(false) {
            };

            member_atom(tagmarker_type mkr, const std::string&name_, const std::string& typenam_, const std::string& enm_ = "",
                    namedtypeassignment_entity_ptr typ_ = namedtypeassignment_entity_ptr(), bool ischoice_ = false, bool afterextention_ = false) :
            marker(mkr), name(name_), typenam(typenam_), enm(enm_), typ(typ_), ischoice(ischoice_), afterextention(afterextention_) {
            };




            tagmarker_type marker;
            std::string name;
            std::string typenam;
            std::string enm;
            namedtypeassignment_entity_ptr typ;
            bool ischoice;
            bool afterextention;

        };

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
            }
            return base_;
        }




        namespace fsnsp = boost::filesystem;

        bool dir_exists(const std::string& path) {
            fsnsp::path p(path.c_str());
            return ((fsnsp::exists(p)) && (fsnsp::is_directory(p)));
        }

        bool dir_create(const std::string& path, const std::string& outdir) {
            std::string newpath = path + "\\" + outdir;
            if (!dir_exists(newpath))
                return fsnsp::create_directory(fsnsp::path(newpath.c_str()));
            return true;
        }


        const std::string FHHEADER = "#include <boost/itu/asn1/asnbase.hpp>\n#include <boost/itu/x69X/x690.hpp>\n#include <boost/itu/x69X/x691.hpp>\n\n#ifdef _MSC_VER\n#pragma warning(push)\n#pragma warning(disable: 4065)\n#endif\n\n";
        const std::string FHBOTTOM = "\n\n#ifdef _MSC_VER\n#pragma warning(pop)\n#endif\n\n#endif";
        const std::string CHHEADER = "\n#ifdef _MSC_VER\n#pragma warning(push)\n#pragma warning(disable: 4065)\n#endif\n\n";
        const std::string CHBOTTOM = "\n\n#ifdef _MSC_VER\n#pragma warning(pop)\n#endif\n";
        const std::string MNDCL_OLD = "    using  boost::asn1::null_type;\n"
                "    using  boost::asn1::enumerated_type;\n"
                "    using  boost::asn1::bitstring_type;\n"
                "    using  boost::asn1::octetstring_type;\n"
                "    using  boost::asn1::oid_type;\n"
                "    using  boost::asn1::reloid_type;\n"
                "    using  boost::asn1::utctime_type;\n"
                "    using  boost::asn1::gentime_type;\n"
                "    using  boost::asn1::ia5string_type;\n"
                "    using  boost::asn1::printablestring_type;\n"
                "    using  boost::asn1::visiblestring_type;\n"
                "    using  boost::asn1::visiblestring_type;\n"
                "    using  boost::asn1::numericstring_type;\n"
                "    using  boost::asn1::universalstring_type;\n"
                "    using  boost::asn1::bmpstring_type;\n"
                "    using  boost::asn1::utf8string_type;\n"
                "    using  boost::asn1::generalstring_type;\n"
                "    using  boost::asn1::graphicstring_type;\n"
                "    using  boost::asn1::t61string_type;\n"
                "    using  boost::asn1::t61string_type;\n"
                "    using  boost::asn1::videotexstring_type;\n"
                "    using  boost::asn1::objectdescriptor_type;\n"
                "    using  boost::asn1::external_type;\n"
                "    using  boost::asn1::embeded_type;\n"
                "    using  boost::asn1::characterstring_type;\n"
                "    using  boost::asn1::any_type;\n"
                "    using  boost::asn1::value_holder;\n"
                "    using  boost::asn1::default_holder;\n";

        const std::string MNDCL = "    ITU_T_USE_UNIVESAL_DECL;\n";

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

        std::string builtin_str(defined_type tp) {
            switch (tp) {
                case t_BOOLEAN: return "bool";
                case t_INTEGER: return "int";
                case t_BIT_STRING: return "bitstring_type";
                case t_OCTET_STRING: return "octetstring_type";
                case t_NULL: return "null_type";
                case t_OBJECT_IDENTIFIER: return "oid_type";
                case t_ObjectDescriptor: return "objectdescriptor_type";
                case t_EXTERNAL: return "external_type";
                case t_REAL: return "double";
                case t_ENUMERATED: return "enumerated_type";
                case t_EMBEDDED_PDV: return "embeded_type";
                case t_UTF8String: return "utf8string_type";
                case t_RELATIVE_OID: return "reloid_type";
                case t_NumericString: return "numericstring_type";
                case t_PrintableString: return "printablestring_type";
                case t_T61String: return "t61string_type";
                case t_VideotexString: return "videotexstring_type";
                case t_IA5String: return "ia5string_type";
                case t_UTCTime: return "utctime_type";
                case t_GeneralizedTime: return "gentime_type";
                case t_GraphicString: return "graphicstring_type";
                case t_VisibleString: return "visiblestring_type";
                case t_GeneralString: return "generalstring_type";
                case t_UniversalString: return "universalstring_type";
                case t_CHARACTER_STRING: return "characterstring_type";
                case t_BMPString: return "bmpstring_type";
                case t_TIME:
                case t_TIME_OF_DAY:
                case t_DATE:
                case t_DATE_TIME:
                case t_DURATION: return "printablestring_type";
                case t_OID_IRI: return "null_type";
                case t_ANY: return "any_type";
                case t_ClassField: return "any_type";
                    //case t_Selection: return "null_type";
                    //case t_Instance_Of: return "null_type";
                    //case t_RELATIVE_OID_IRI: return "null_type";                
                    //case t_TypeFromObject: return "null_type";
                    //case t_ValueSetFromObjects: return "null_type";
                default:
                {
                }
            }
            return "";
        }

        std::string type_str(typeassignment_entity_ptr self, bool native) {
            if (self->isrefferrence())
                return nameupper(nameconvert(self->name()));
            else if (self->isstructure()) {
                typeassignment_entity_ptr ppas = self->scope() ?
                        self->scope()->as_typeassigment() : typeassignment_entity_ptr();
                std::string postfix = (ppas || native || (!self->tag())) ? "" : "_impl";
                if (ppas && (ppas->isstruct_of()))
                    return nameupper(type_str(ppas)+(ppas->builtin() == t_SEQUENCE_OF ? "_sequence_of" : "_set_of"));
                return nameupper(nameconvert(self->islocaldeclare() ? (self->name() + "_type") : self->name()) + postfix);
            } else
                return self->islocaldefined() ? builtin_str(self->builtin()) : nameupper(nameconvert(self->name()));
            return "";
        }

        std::string fulltype_str(basic_entity_ptr self, bool withns) {
            if ((self->as_typeassigment()) || (self->as_module())) {
                if (self->as_module()) {
                    return withns ? nameconvert(self->name()) : "";
                } else if (self->as_typeassigment()) {
                    typeassignment_entity_ptr ppas = self->as_typeassigment();
                    std::string tmp = fulltype_str(self->scope(), withns);
                    if ((ppas->type()) && (!ppas->isstruct_of()))
                        return tmp.empty() ? type_str(ppas) : (tmp + "::" + type_str(ppas));
                    else
                        return tmp;
                }
            }
            typeassignment_entity_ptr ppas = self->as_typeassigment();
            if ((ppas->type()) && (!ppas->isstruct_of()))
                return type_str(self->as_typeassigment());
            return "";
        }

        std::string fulltype_str_ext(basic_entity_ptr self, bool withns, const std::string& delim) {
            if ((self->as_typeassigment()) || (self->as_module())) {
                if (self->as_module()) {
                    return withns ? nameconvert(self->name()) : "";
                } else if (self->as_typeassigment()) {
                    typeassignment_entity_ptr ppas = self->as_typeassigment();
                    std::string tmp = fulltype_str_ext(self->scope(), withns, delim);
                    if (ppas->type())
                        return tmp.empty() ? type_str(ppas) : (tmp + delim + type_str(ppas));
                    else
                        return tmp;
                }
            }
            typeassignment_entity_ptr ppas = self->as_typeassigment();
            if (self->extract_type())
                return type_str(self->as_typeassigment());
            return "";
        }

        std::string fullpathtype_str(typeassignment_entity_ptr self, typeassignment_entity_ptr root, std::string tp) {
            if (self->islocaldeclare()) {
                return fulltype_str(root, false) + "::" + tp;
            } else
                return fromtype_str(self);
        }

        std::string value_int_str(value_atom_ptr self) {
            if (self && (self->get_value<int64_t>())) {
                try {
                    return boost::lexical_cast<std::string > (*(self->get_value<int64_t>()));
                } catch (boost::bad_lexical_cast) {
                    return "???num???";
                }
            }
            return "???num???";
        }

        std::string value_null_str(value_atom_ptr self) {
            if (self && (self->get_value<null_initer>())) {
                return "boost::asn1::null_type()";
            }
            return "???null???";
        }

        std::string value_bool_str(value_atom_ptr self) {
            if (self && (self->get_value<bool>()))
                return *(self->get_value<bool>()) ? "true" : "false";
            return "???bool???";
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
                return boost::lexical_cast<std::string > (*(self->get_value<double>()));
            }
            return "???real???";
        }

        std::string value_reff_str(defined_value_atom_ptr self) {
            if ((self->reff()) && (self->reff()->as_valueassigment())) {
                std::string rslt;
                typeassignment_entity_ptr tp = self->reff()->as_valueassigment()->scope() ?
                        self->reff()->as_valueassigment()->scope()->as_typeassigment() : typeassignment_entity_ptr();
                if (tp /*&& (!tp->islocaldefined())*/)
                    rslt = namelower(nameconvert(tp->name())) + "_";
                return rslt + nameconvert(self->reff()->as_valueassigment()->name());
            }
            return "???reff???";
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
            if (!vl.empty()) {
                for (std::string::const_iterator it = vl.begin(); it != vl.end(); ++it)
                    rslt += ("\\x" + (num_to_hex<std::string::value_type>(*it)));
            }
            return rslt;
        }

        static std::string string_to_literal(const std::wstring& vl) {
            std::string rslt;
            if (!vl.empty()) {
                for (std::wstring::const_iterator it = vl.begin(); it != vl.end(); ++it)
                    rslt += ("\\x" + (num_to_hex<std::wstring::value_type>(*it)));
            }
            return rslt;
        }

        std::string value_bs_str(value_atom_ptr self) {
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
                        rslt += "???expr???";
                }
                return rslt;
            } else if (self->as_cstr()) {
                if (self->get_value<bstring_initer>()) {
                    boost::shared_ptr<bstring_initer> tmp = self->get_value<bstring_initer>();
                    if (!tmp->str.empty())
                        return "boost::asn1::bitstring_type(std::string(\"" + string_to_literal(tmp->str) + "\", "
                        + boost::lexical_cast<std::string >(tmp->str.size()) + "), "
                        + boost::lexical_cast<std::string >(tmp->unused) + ")";
                    else
                        return "boost::asn1::bitstring_type()";
                }
            } else if (self->as_assign())
                return nameconvert(self->as_assign()->name());
            return "???bitnum???";
        }

        std::string value_os_str(value_atom_ptr self) {
            if (self->get_value<hstring_initer>()) {
                boost::shared_ptr<hstring_initer> tmp = self->get_value<hstring_initer>();
                if (!tmp->str.empty())
                    return "boost::asn1::octetstring_type(std::string(\"" + string_to_literal(tmp->str) + "\", "
                    + boost::lexical_cast<std::string >(tmp->str.size()) + "))";
                else
                    return "boost::asn1::octetstring_type()";
            };
            return "???0str???";
        }

        std::string value_chars8_str(value_atom_ptr self, bool cantuple) {
            if (cantuple && self->get_value<tuple>()) {
                boost::shared_ptr<tuple> tmp = self->get_value<tuple>();
                return "std::string(1, \'" +
                string_to_literal(std::string(1, std::string::value_type(static_cast<std::string::value_type> (tmp->tablecolumn * 16 + tmp->tablerow)))) +
                        "\')";
            } else if (self->get_value<std::string>()) {
                return "std::string(\"" +
                *(self->get_value<std::string>()) +
                        "\")";
            }
            return "???str???";
        }

        std::string value_chars16_str(value_atom_ptr self) {
            if (self->get_value<quadruple>()) {
                boost::shared_ptr<quadruple> tmp = self->get_value<quadruple>();
                return "std::wstring(1, L\'" +
                string_to_literal(std::wstring(1, std::wstring::value_type(static_cast<std::wstring::value_type> (tmp->row * 256 + tmp->cell)))) +
                        "\')";
            }
            return "???wstr???";
        }

        std::string value_utfchar_str(const quadruple& self) {
            uint32_t tmp = 128 * self.group + 256 * self.plane + 256 * self.row + self.cell;
            std::string rslt;
            if (boost::asn1::quadrople_to_str(tmp, rslt)) {
                return rslt;
            }
            return "";
        }

        std::string value_utfchars_str(value_atom_ptr self) {
            if (self->get_value<quadruple_vector>()) {
                boost::shared_ptr<quadruple_vector> tmp = self->get_value<quadruple_vector>();
                std::string rslt;
                for (quadruple_vector::const_iterator it = tmp->begin(); it != tmp->end(); ++it)
                    rslt += value_utfchar_str(*it);
                if (!rslt.empty())
                    return "std::string(\"" + string_to_literal(rslt) + "\" , " + boost::lexical_cast<std::string >(rslt.size()) + ")";
                else
                    return "std::string()";
            }
            return "???wstr???";
        }

        std::string value_enum_str(type_atom_ptr tp, value_atom_ptr self) {
            if (tp && self && (self->as_defined()) && (self->as_defined()->reff()))
                return namelower(fromtype_str(tp)) + "_" + nameconvert(self->as_defined()->reff()->name());
            return "???enum???";
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
            if (self && (self->get_value<unum_vector>())) {
                boost::shared_ptr<unum_vector> lst = self->get_value<unum_vector>();
                if (!lst->empty()) {
                    for (unum_vector::const_iterator it = lst->begin(); it != lst->end(); ++it)
                        rslt.push_back(boost::lexical_cast<std::string >(*it));
                } else rslt.push_back("???");
            } else rslt.push_back("???");
            return !rslt.empty();
        }

        std::string valueassmnt_str(valueassignment_entity_ptr self) {
            return valueassmnt_str(self->type(), self->value(), nameconvert(self->name()));
        }

        std::string value_struct_str(value_atom_ptr vl, type_atom_ptr tp) {
            std::string rslt = fromtype_str(tp) + "(";
            if (tp && (tp->refference_to()) && (tp->refference_to()->as_typeassigment())) {
                typeassignment_entity_ptr tpassmt = tp->refference_to()->as_typeassigment();
                if (tpassmt->type()) {
                    boost::shared_ptr<namedvalue_initer_set> values = vl->get_value<namedvalue_initer_set>();
                    bool first = true;
                    if (values) {
                        for (basic_entity_vector::iterator it = tpassmt->childs().begin(); it != tpassmt->childs().end(); ++it) {
                            typeassignment_entity_ptr subtpassmt = (*it)->as_typeassigment();
                            if (subtpassmt) {
                                if (first)
                                    first = false;
                                else
                                    rslt += ", ";
                                std::string subelmt = "";
                                namedvalue_initer_set::iterator fid = values->find(namedvalue_initer(subtpassmt->name()));
                                if (fid != values->end())
                                    subelmt = " new " + valueassmnt_str(subtpassmt->type(), fid->val, fid->str, true) + "";
                                rslt += ("boost::shared_ptr<" + fromtype_str((*it)->as_typeassigment()->type()) +
                                        " >(" + subelmt + ")");
                            }
                        }
                    }
                }
            }
            rslt += ")";
            return rslt;
        }

        std::string valueassmnt_str(type_atom_ptr tp, value_atom_ptr vl, const std::string& nm, bool ext) {
            switch (tp->root_builtin()) {
                case t_NULL: return nested_init_str(tp, value_null_str(vl), ext);
                case t_INTEGER: return nested_init_str(tp, value_int_str(vl), ext);
                case t_BOOLEAN: return nested_init_str(tp, value_bool_str(vl), ext);
                case t_REAL: return nested_init_str(tp, value_real_str(vl), ext);
                case t_BIT_STRING: return nested_init_str(tp, value_bs_str(vl), ext);
                case t_OCTET_STRING: return nested_init_str(tp, value_os_str(vl), ext);
                case t_ENUMERATED: return nested_init_str(tp, value_enum_str(tp, vl), ext);
                case t_OBJECT_IDENTIFIER: return "#error iternal";
                case t_RELATIVE_OID: return "#error iternal";
                case t_NumericString:
                case t_PrintableString:
                case t_T61String:
                case t_VideotexString:
                case t_GraphicString:
                case t_VisibleString:
                case t_GeneralString:
                case t_ObjectDescriptor:
                case t_IA5String: return nested_init_str(tp, value_chars8_str(vl, tp->root_builtin() == t_IA5String), ext);
                case t_BMPString: return nested_init_str(tp, value_chars16_str(vl), ext);
                case t_UniversalString:
                case t_UTF8String: return nested_init_str(tp, value_utfchars_str(vl), ext);
                    //case t_SEQUENCE:
                    //case t_SET: return nested_init_str(tp, value_struct_str(vl, tp),ext);
                    /*case t_SEQUENCE_OF:  return nested_init_str(tp, value_struct_str(vl, tp));               
                    case t_SET_OF:
                    case t_CHOICE:  return nested_init_str(tp, value_struct_str(vl, tp)); */
                default:
                {
                }
            }

            return "";
        }

        std::string fromtype_str(typeassignment_entity_ptr self) {
            if (self->isrefferrence()) {
                typeassignment_entity_ptr frtp = ((self->type()->reff()) && (self->type()->reff()->as_typeassigment())) ?
                        self->type()->reff()->as_typeassigment() : typeassignment_entity_ptr();
                if ((self->shadow_for())
                        && (self->shadow_for()->moduleref() != self->moduleref())
                        && (self->shadow_for()->as_typeassigment()))
                    frtp = self->shadow_for()->as_typeassigment();
                module_entity_ptr extmod = (frtp && (frtp->moduleref() != self->moduleref())) ? frtp->moduleref() : module_entity_ptr();
                std::string pref = extmod ? (nameconvert(extmod->name()) + "::") : "";
                return (pref + nameupper(nameconvert(self->type()->reff()->name())));
            } else if (self->isstructure())
                return type_str(self, true);
            else
                return builtin_str(self->builtin());

            return "???type???";
        }

        std::string fromtype_str(type_atom_ptr self) {
            if (self) {
                if ((self->reff()) && (self->reff()->as_typeassigment()) && (self->isrefferrence())) {
                    module_entity_ptr fmd = self->reff()->as_typeassigment()->moduleref();
                    return (fmd && (fmd != self->moduleref())) ? (nameconvert(fmd->name()) + "::" + nameupper(nameconvert(self->reff()->name())))
                            : nameupper(nameconvert(self->reff()->name()));
                } else if (self->isstructure())
                    return "???type???";

                else
                    return builtin_str(self->builtin());
            }
            return "???type???";
        }

        bool fromtype_remote(typeassignment_entity_ptr self) {
            if (self->isrefferrence()) {
                typeassignment_entity_ptr frtp = ((self->type()->reff()) && (self->type()->reff()->as_typeassigment())) ?
                        self->type()->reff()->as_typeassigment() : typeassignment_entity_ptr();

                return ((frtp) && (frtp->moduleref() != self->moduleref()));
            }
            return false;
        }

        declare_vect::iterator find_remote_reff(declare_vect& vct, const std::string& nm, declare_vect::iterator from) {
            for (declare_vect::iterator it = from; it != vct.end(); ++it)
                if (it->typenam == nm)
                    return it;

            return vct.end();
        }

        void resolve_remote_reff(declare_vect& vct) {
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

        bool sort_reff(declare_vect& vct) {
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
                case t_BIT_STRING:
                case t_ENUMERATED:
                case t_OBJECT_IDENTIFIER:
                case t_RELATIVE_OID: return true;
                default: return false;
            }
            return false;
        }

        std::string member_marker_str(const std::string& str, tagmarker_type self, const std::string& dflt, bool simple) {
            switch (self) {
                case mk_default:
                {
                    return "default_holder<" + str + ", " + dflt + ">";
                }
                case mk_optional:
                {
                    return "boost::shared_ptr<" + str + ">";
                }
                default:
                {

                    return simple ? str : ("value_holder<" + str + ">");
                }
            }
            return str;
        }

        std::string seqof_str(typeassignment_entity_ptr self, const std::string& name) {
            if (self->builtin() == t_SEQUENCE_OF)
                return "typedef std::vector< " + name + "> ";

            else
                return "typedef std::deque< " + name + "> ";
        }

        std::string choice_enum_str(typeassignment_entity_ptr self, basic_entity_ptr sub) {

            return type_str(self) + "_" + nameconvert(sub ? sub->name() : "");
        }

        std::string tagged_str(tagged_ptr self) {
            if ((self->number()) && (self->number()->as_number()))
                try {
                    return boost::lexical_cast<std::string > (self->number()->as_number()->value());
                } catch (boost::bad_lexical_cast) {

                    return "";
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

        static std::string name_arch(const std::string& nm, tagmarker_type mkr) {
            switch (mkr) {
                case mk_exception: return "*(*" + nm + ")";                
                case mk_default: return nm + ".get_shared()";
                case mk_none: return "*" + nm;
                default:
                {
                }
            }
            return nm;
        }

        std::string struct_meth_str(typeassignment_entity_ptr self, const std::string& tp) {

            return "\n" + tabformat(basic_entity_ptr(), 2) + "template<> void " +
                    fulltype_str(self, false) + "::serialize(" +
                    tp + "& arch)";
        }

        std::string nested_init_str(type_atom_ptr self, const std::string& nm, bool ext) {
            type_atom_ptr next = self->textualy_type();
            if ((!next) || (next == self) || (!next->reff()))
                return ((next) && (next->tag()) && (next->isrefferrence())) ? (fromtype_str(next) + "(" + nm + ")") : nm;
            if (!next->reff()->as_typeassigment())
                return fromtype_str(next) + "(" + nm + ")";
            if (!next->reff()->as_typeassigment()->type())
                return fromtype_str(next) + "(" + nm + ")";
            return fromtype_str(next) + "(" + nested_init_str(next->reff()->as_typeassigment()->type(), nm) + ")";
        }

        bool expressed_import(module_entity_ptr self, const std::string& name) {
            basic_entity_ptr tas = self->find_by_name(name);
            if (tas) {
                if (tas->as_typeassigment()) {
                    return tas->as_typeassigment()->is_cpp_expressed();
                } else if (tas->as_valueassigment()) {
                    return !tas->as_valueassigment()->has_arguments();
                } else if (tas->as_valuesetassigment()) {

                    return false; // !tas->as_valueassigment()->has_arguments();
                }
            }
            return false;
        }

        member_vect parse_membervct(const member_vect& vct, bool obligate) {
            member_vect rslt;
            for (member_vect::const_iterator it = vct.begin(); it != vct.end(); ++it) {
                if (!is_extention(it->marker)) {

                    if ((obligate && ((it->marker == mk_none) && !(it->afterextention))) || (!obligate))
                        rslt.push_back(*it);
                }
            }
            return rslt;
        }

        member_vect parse_default_membervct(const member_vect& vct) {
            member_vect rslt;
            for (member_vect::const_iterator it = vct.begin(); it != vct.end(); ++it) {

                if (it->marker == mk_default)
                    rslt.push_back(*it);
            }
            return rslt;
        }


        ////////////////////////////////////////////////////////////////////////////////////////////////////         
        //  BaseModuleOUT
        ////////////////////////////////////////////////////////////////////////////////////////////////////       

        base_moduleout::base_moduleout(const char* path, module_entity_ptr mod, const compile_option& opt)
        : module_(mod), opt_(opt), stream(path, std::ofstream::out | std::ofstream::trunc) {
            if (!stream)
                throw fsnsp::filesystem_error("File dosnt create: " + std::string(path),
                    boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));
        }

        base_moduleout::~base_moduleout() {
        }




        ////////////////////////////////////////////////////////////////////////////////////////////////////         
        //  CppOUT
        ////////////////////////////////////////////////////////////////////////////////////////////////////       

        cppout::cppout(global_entity_ptr glb, const std::string& path, const std::string& outdir,
                bool revrs, bool nohldr, bool bermn)
        : global_(glb), opt_(path, outdir, revrs, nohldr, bermn) {
        }

        cppout::~cppout() {
        }

        void cppout::execute() {
            if (!dir_exists(opt_.path))
                throw fsnsp::filesystem_error("File or directory error",
                    boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));
            if (!dir_create(opt_.path, opt_.outdir))
                throw fsnsp::filesystem_error("File or directory error",
                    boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));
            opt_.path = opt_.path + "\\" + opt_.outdir + "\\";

            for (basic_entity_vector::iterator it = global_->childs().begin(); it != global_->childs().end(); ++it) {
                if ((*it)->as_module()) {
                    moduleout_ptr hpp = generate<mainhpp_out>((*it)->as_module(), "", "hpp");
                    hpp->execute();
                    moduleout_ptr cpp = generate<maincpp_out>((*it)->as_module(), "", "cpp");
                    cpp->execute();
                    if (!opt_.ber_in_main) {
                        moduleout_ptr ber = generate<ber_cpp_out>((*it)->as_module(), "_ber", "cpp");
                        ber->execute();
                    }
                    moduleout_ptr per = generate<per_cpp_out>((*it)->as_module(), "_per", "cpp");
                    per->execute();
                    //execute_module((*it)->as_module());
                }
            }
        }







        ////////////////////////////////////////////////////////////////////////////////////////////////////         
        //  moduleout
        ////////////////////////////////////////////////////////////////////////////////////////////////////       

        std::size_t moduleout::load_predeclare(basic_entity_ptr self, structdeclare_vect& rslt) {
            load_struct_predeclare(self, rslt);
            load_structof_predeclare(self, rslt);
            return rslt.size();
        }

        std::size_t moduleout::load_structof_predeclare(basic_entity_ptr self, structdeclare_vect& rslt) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->is_cpp_expressed())) {
                    if ((tpas->isstruct_of()) && (!tpas->childs().empty())) {
                        typeassignment_entity_ptr cpas = tpas->childs().front()->as_typeassigment();
                        if (cpas) {
                            if (cpas->isstruct_of()) {
                                load_structof_predeclare(tpas, rslt);
                            } else if (cpas->isstruct()) {
                                rslt.push_back(type_str(cpas));
                            }
                        }
                    }
                }
            }
            return rslt.size();
        }

        std::size_t moduleout::load_struct_predeclare(basic_entity_ptr self, structdeclare_vect& rslt) {
            for (basic_entity_vector::const_iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->is_cpp_expressed())) {
                    if (tpas->isstruct())
                        rslt.push_back(type_str(tpas));
                    //if (tpas->tag())
                    //     stream << tabformat() << "struct " << type_str(tpas, true) + "; " << " \n";
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
                if (tpas && (tpas->is_cpp_expressed())) {

                    if ((tpas->isstruct_of()) && (!tpas->childs().empty()))
                        load_typedef_structof_impl(vct, tpas);
                }
            }
        }

        bool moduleout::load_typedef_structof_impl(declare_vect& vct, typeassignment_entity_ptr self) {
            if (!self->childs().empty()) {
                typeassignment_entity_ptr cpas = self->childs().front()->as_typeassigment();
                if (cpas && (cpas->type())) {
                    if ((!cpas->issimplerefferrence()) && (!cpas->isstruct_of())) {
                        vct.push_back(declare_atom(((self->builtin() == t_SEQUENCE_OF) ? declare_seq : declare_set),
                                self, type_str(self), fromtype_str(cpas), fromtype_remote(cpas)));
                        return true;
                    } else if ((cpas->isstruct_of())) {
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

        void moduleout::load_member(member_vect& vct, typeassignment_entity_ptr self) {
            bool afterextention = false;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                namedtypeassignment_entity_ptr named = (*it)->as_named_typeassigment();
                tagmarker_type mkr = named->marker();
                if (named->type()) {
                    if ((mkr == mk_default) && (!default_supported(named)))
                        mkr = mk_optional;
                    if (is_named(mkr))
                        vct.push_back(member_atom(mkr, nameconvert(named->name()), fromtype_str(named),
                            ((self->builtin() == t_CHOICE) ? (type_str(self) + "_" + nameconvert(named->name())) : ""),
                            named, named->istextualy_choice(), afterextention));
                }
                if (mkr == mk_extention) {
                    vct.push_back(member_atom());
                    afterextention = !afterextention;
                }
                if ((*it)->as_extention()) {

                    vct.push_back(member_atom());
                    afterextention = !afterextention;
                }
            }
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
                tagmarker_type mkr = (it->afterextention && (it->marker == mk_none)) ? mk_optional : it->marker;
                if ((mkr == mk_none) || (mkr == mk_default) || (mkr == mk_optional)) {

                    stream << "\n";
                    stream << tabformat(self, 1) <<
                            member_marker_str(it->typenam, mkr, ((mkr == mk_default) ? (it->name + "__default") : ""), option_no_holder()) <<
                            " " << it->name << "_;" << (it->afterextention ? " // after extention" : "");
                }
            }
        }
















        //////////////////////////////////////////////////////
        //  mainhpp_out
        //////////////////////////////////////////////////////

        void mainhpp_out::execute() {

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

            if (execute_struct_meth_hpp(module_, "x690"))
                stream << "\n";

            if (execute_struct_meth_hpp(module_, "x691"))
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
                        case declare_seq: stream << "\n" << tabformat(scp, 2) << "typedef std::vector< " << it->from_type << " > " << it->typenam << ";";
                            break;
                        case declare_set: stream << "\n" << tabformat(scp, 2) << "typedef std::deque< " << it->from_type << " > " << it->typenam << ";";
                            break;
                        case declare_explicit: stream << "\n" << tabformat(scp, 2) << "ITU_T_EXPLICIT_TYPEDEF( "
                                    << it->typenam << ", " << it->from_type << ", " << it->tag << ", " << it->class_ << ");";
                            break;
                        case declare_implicit: stream << "\n" << tabformat(scp, 2) << "ITU_T_IMPLICIT_TYPEDEF( "
                                    << it->typenam << ", " << it->from_type << ", " << it->tag << ", " << it->class_ << ");";
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
                case t_BIT_STRING:
                case t_OCTET_STRING:
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
                    stream << "\n" << tabformat(scp, 2) << "const " << fromtype_str(self->type()) << " " << nameconvert(self->name()) << " = " << valueassmnt_str(self) << ";\n";
                    break;
                }
                case t_OBJECT_IDENTIFIER:
                case t_RELATIVE_OID:
                {
                    std::vector<std::string> rslt;
                    if (value_oid_str(self->value(), rslt)) {
                        if (self->type()->root_builtin() == t_OBJECT_IDENTIFIER)
                            stream << "\n" << tabformat(scp, 2) << "ITU_T_OID( ";
                        else
                            stream << "\n" << tabformat(scp, 2) << "ITU_T_RELOID( ";
                        stream << nameconvert(self->name()) << " , ITU_T_VARRAY(  ";
                        for (std::vector<std::string>::const_iterator it = rslt.begin(); it != rslt.end(); ++it) {
                            if (it != rslt.begin())
                                stream << ", ";
                            stream << (*it);
                        }
                        stream << "));";
                    }
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
                        stream << "\n";
                        stream << tabformat(tpas) << "// choice " << tpas->name();
                        execute_choice_hpp(tpas);
                        break;
                    case t_SEQUENCE:
                        stream << "\n";
                        stream << tabformat(tpas) << "// sequence " << tpas->name();
                        execute_struct_hpp(tpas);
                        break;
                    case t_SET:
                        stream << "\n";
                        stream << tabformat(tpas) << "// set " << tpas->name();
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
                if ((tpas) && (tpas->type()))
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
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                    tagmarker_type mkr = (*it)->as_typeassigment()->as_named()->marker();

                    if ((mkr == mk_none) || (mkr == mk_default) || (mkr == mk_optional))
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

            //execute_member(stream, self);

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
                            // t_BIT_STRING,
                            // t_OCTET_STRING
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
                    stream << ((namelower(nameconvert(self->name())) + "_")) << nameconvert(vlass->name());
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
                    stream << ((namelower(nameconvert(self->name()) + "_"))) << nameconvert(vlass->name());
                    if (!is_local_scope)
                        stream << " = " << nested_init_str(self->type(), "bitstring_type(true, " + value_int_str(vlass->value()) + ")");
                    stream << ";\n";
                }
            }
        }

        void mainhpp_out::execute_access_member_hpp(typeassignment_entity_ptr self) {
            bool ischoice = (self->builtin() == t_CHOICE);
            member_vect mmbr;
            load_member(mmbr, self);
            for (member_vect::const_iterator it = mmbr.begin(); it != mmbr.end(); ++it) {
                tagmarker_type mkr = (it->afterextention && (it->marker == mk_none)) ? mk_optional : it->marker;
                if ((mkr == mk_none) || (mkr == mk_default) || (mkr == mk_optional)) {
                    stream << "\n";
                    if (!ischoice) {
                        switch (mkr) {
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

                        bool primitive = ((it->typ) && (it->typ->isprimitive()));
                        stream << tabformat(self, 1) << "ITU_T_CHOICE" << (primitive ? "S" : "C") << "_DECL(" << it->name << ", " <<
                                it->typenam << ", " << choice_enum_str(self, it->typ) << ");     " << (primitive ? "// primitive" : "");
                    }
                    mark_constraints(it->typ);
                }
            }
        }

        void mainhpp_out::execute_structof_hpp(typeassignment_entity_ptr self) {
            if (self && (self->type())) {
                if ((self->isstruct_of()) && (!self->childs().empty())) {
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
                        stream << "\n" << tabformat(self, 1) << type_str(self) << "()";
                        stream << " : " << " ITU_T_CHOICE(" << type_str(self) << "_enum) () {} \n";

                        stream << "\n" << tabformat(self, 1) << "template<typename T> ";
                        stream << type_str(self) << "(boost::shared_ptr< T> vl, " << type_str(self) << "_enum enm) : \n";
                        stream << tabformat(self, 2) << " ITU_T_CHOICE(" << type_str(self) << "_enum) (vl, static_cast<int>(enm)) {} \n";

                        stream << "\n" << tabformat(self, 1) << "template<typename T> ";
                        stream << type_str(self) << "(const T& vl, " << type_str(self) << "_enum enm) : \n";
                        stream << tabformat(self, 2) << " ITU_T_CHOICE(" << type_str(self) << "_enum) ( new T(vl), static_cast<int>(enm)) {} \n";

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

                        if (!nooblig.empty() && (nooblig.size() > oblig.size())) {
                            stream << "\n" << tabformat(self, 1) << type_str(self) << "(";
                            for (member_vect::const_iterator it = nooblig.begin(); it != nooblig.end(); ++it) {
                                if (it != nooblig.begin())
                                    stream << ",\n " << tabformat(self, 2);
                                stream << "boost::shared_ptr< " << it->typenam << ">  " << argumentname(it->name);
                                if (it->afterextention)
                                    stream << " = boost::shared_ptr< " << it->typenam << ">()";
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
                            tagmarker_type mkr = (it->afterextention && (it->marker == mk_none)) ? mk_optional : it->marker;
                            if (mkr == mk_default) {
                                stream << "\n" << tabformat(self, 1) << "static const " << fromtype_str(it->typ) << " " << it->name << "__default;";
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
                if (tpas && (tpas->isstructure()) && (tpas->is_cpp_expressed())) {
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

        std::size_t mainhpp_out::execute_struct_meth_hpp(basic_entity_ptr self, const std::string& ctp) {
            std::size_t cnt = 0;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->isstructure()) && (tpas->is_cpp_expressed())) {
                    if (tpas->isstruct()) {
                        stream << struct_meth_str(tpas, "boost::asn1::" + ctp + "::output_coder") << ";";
                        stream << struct_meth_str(tpas, "boost::asn1::" + ctp + "::input_coder") << ";";
                        cnt++;
                    }
                    cnt += execute_struct_meth_hpp(tpas, ctp);
                }
            }
            return cnt;
        }





        //////////////////////////////////////////////////////
        //  base_arch_out
        //////////////////////////////////////////////////////

        void base_arch_out::execute_archive_meth_cpp(typeassignment_entity_ptr self, const std::string& ctp) {
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
            stream << "\n";
            stream << tabformat(scp, 2) << "}";
            stream << "\n";
        }

        void base_ber_arch_out::execute_archive_struct_output(typeassignment_entity_ptr self) {
            basic_entity_ptr scp;
            bool afterext = false;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if ((tpas) && (tpas->as_named())) {
                    namedtypeassignment_entity_ptr named = tpas->as_named();
                    tagmarker_type mkr = named->marker();
                    if (named->type()) {
                        if (is_named(mkr))
                            execute_archive_member(named, afterext);
                    } else if (mkr == mk_extention) {
                        afterext = !afterext;
                        stream << "\n" << tabformat(scp, 3) << "ITU_T_EXTENTION" << ";";
                    }
                }

                if ((*it)->as_extention()) {
                    afterext = !afterext;
                    stream << "\n" << tabformat(scp, 3) << "ITU_T_EXTENTION" << ";";
                }
            }
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
            if ((self->isdefined_choice())) {
                if (self->tag()) {
                    switch (self->tag()->_class()) {
                        case tcl_application: return "ITU_T_CHOICE_APPLICATION_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                        case tcl_universal: return "ITU_T_CHOICE_UNIVERSAL_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                        case tcl_private: return "ITU_T_CHOICE_PRIVATE_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                        default: return "ITU_T_CHOICE_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                    }
                } else
                    return "ITU_T_BIND_CHOICE(" + name_arch(name, dfltopt) + ")";
            } else {
                if (self->tag()) {
                    if (self->tag()->rule() == implicit_tags) {
                        switch (self->tag()->_class()) {
                            case tcl_application: return "ITU_T_IMPLICIT_APPLICATION_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                            case tcl_universal: return "ITU_T_IMPLICIT_UNIVERSAL_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                            case tcl_private: return "ITU_T_IMPLICIT_PRIVATE_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                            default: return "ITU_T_IMPLICIT_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                        }
                    } else {
                        switch (self->tag()->_class()) {
                            case tcl_application: return "ITU_T_EXPLICIT_APPLICATION_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                            case tcl_universal: return "ITU_T_EXPLICIT_UNIVERSAL_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                            case tcl_private: return "ITU_T_EXPLICIT_PRIVATE_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                            default: return "ITU_T_EXPLICIT_TAG(" + name_arch(name, dfltopt) + ", " + tagged_str(self->tag()) + ")";
                        }
                    }
                } else
                    return "ITU_T_BIND_TAG(" + name_arch(name, dfltopt) + ")";
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

        void base_ber_arch_out::execute_archive_choice_input_helper(typeassignment_entity_ptr self, tagclass_type cls, bool notag) {
            basic_entity_ptr scp;
            if (notag) {
                stream << "\n" << tabformat(scp, 4) << "default: {";
            } else {
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
            }
            if (!notag)
                stream << "\n" << tabformat(scp, 5) << "switch(__tag_id__){";
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if ((tpas) && (tpas->as_named())) {
                    namedtypeassignment_entity_ptr named = tpas->as_named();

                    if (named->type()) {
                        tagmarker_type mkr = named->marker();
                        if ((mkr == mk_none) || (mkr == mk_default) || (mkr == mk_optional)) {
                            if (named->tag()) {
                                if (cls == named->tag()->_class()) {
                                    stream << "\n" << tabformat(scp, 6) << "case ";
                                    stream << tagged_str(named->tag()) << ":  { if (";
                                    std::string tmpval = "value<" + fromtype_str(named) + " > (true , " + choice_enum_str(self, (*it)) + ")";
                                    stream << archive_member_ber_str(named, tmpval);
                                    stream << ") return; else free(); break;}";
                                }
                            } else {
                                if (notag) {
                                    stream << "\n" << tabformat(scp, 6) << " if (";
                                    std::string tmpval = "value<" + fromtype_str(named) + " > (true , " + choice_enum_str(self, (*it)) + ")";
                                    stream << archive_member_ber_str(named, tmpval);
                                    stream << ") return; else free();";
                                }
                            }
                        }
                    }
                }
            }
            if (!notag) {

                stream << "\n" << tabformat(scp, 5) << "default:{}";
                stream << "\n" << tabformat(scp, 5) << "}";
            }
            stream << "\n" << tabformat(scp, 4) << "}";
        }

        void base_ber_arch_out::execute_archive_choice_output_helper(typeassignment_entity_ptr self) {
            basic_entity_ptr scp;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if ((tpas) && (tpas->as_named())) {
                    namedtypeassignment_entity_ptr named = tpas->as_named();
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
            execute_include(module_->name());

            stream << CHHEADER << "\n";
            execute_start_ns();

            if (option_reverse_decl())
                execute_typeassignments<basic_entity_vector::const_reverse_iterator>(module_->childs().rbegin(), module_->childs().rend());
            else
                execute_typeassignments<basic_entity_vector::const_iterator>(module_->childs().begin(), module_->childs().end());


            execute_stop_ns();
            stream << CHBOTTOM << "\n";
        }

        void maincpp_out::execute_valueassignment(valueassignment_entity_ptr self) {
        }

        void maincpp_out::execute_typeassignment(typeassignment_entity_ptr tpas) {
            if (tpas && (tpas->is_cpp_expressed())) {
                switch (tpas->builtin()) {
                    case t_CHOICE:
                        stream << "\n";
                        stream << tabformat(tpas) << "// choice " << tpas->name();
                        execute_choice_cpp(tpas);
                        break;
                    case t_SEQUENCE:
                        stream << "\n";
                        stream << tabformat(tpas) << "// sequence " << tpas->name();
                        execute_struct_cpp(tpas);
                        break;
                    case t_SET:
                        stream << "\n";
                        stream << tabformat(tpas) << "// set " << tpas->name();
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
                        if ((tpas) && (tpas->predefined())) {
                            execute_predefined_cpp(tpas, tpas);
                        }
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
                            // t_BIT_STRING,
                            // t_OCTET_STRING
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
                    valueassignment_entity_ptr vlass = (*it)->as_valueassigment();
                    if (vlass) {
                        stream << tabformat() << "const ";
                        stream << type_str(self) << " ";

                        if ((self->islocaldefined()) && ansec)
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
                    valueassignment_entity_ptr vlass = (*it)->as_valueassigment();
                    if (vlass) {
                        stream << tabformat() << "const ";
                        stream << type_str(self) << " ";

                        if ((self->islocaldefined()) && ansec)
                            stream << fulltype_str(ansec, false) << "::";
                        stream << ((namelower(nameconvert(self->name()) + "_"))) << nameconvert(vlass->name()) << " = ";
                        stream << nested_init_str(self->type(), "bitstring_type(true, " + value_int_str(vlass->value()) + ")") << ";\n";
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
                for (member_vect::const_iterator it = mmbr.begin(); it != mmbr.end(); ++it) {

                    if ((it->typ) && (it->typ->isprimitive())) {
                        tagmarker_type mkr = (it->afterextention && (it->marker == mk_none)) ? mk_optional : it->marker;
                        stream << "\n";
                        if ((mkr == mk_none) || (mkr == mk_default) || (mkr == mk_optional)) {
                            stream << "\n" << tabformat(scp, 2) << "void " << fulltype_str(self, false) << "::" << it->name <<
                                    "( const " << it->typenam << "& vl){ set<" << it->typenam << ">(" << "new " <<
                                    it->typenam << "(vl), " << choice_enum_str(self, it->typ) << ") ;}\n";
                        }
                    }
                }
            } else {
                for (member_vect::const_iterator it = mmbr.begin(); it != mmbr.end(); ++it) {
                    tagmarker_type mkr = (it->afterextention && (it->marker == mk_none)) ? mk_optional : it->marker;
                    if ((mkr == mk_none) || (mkr == mk_default) || (mkr == mk_optional)) {
                        stream << "\n";
                        switch (mkr) {
                            case mk_none:
                                stream << "\n" << tabformat(scp, 2) << fullpathtype_str(it->typ, self, it->typenam) << "& " <<
                                        fulltype_str(self, false) << "::" << it->name << "(){ return " << (option_no_holder() ? "" : "*") << it->name << "_ ;}\n";
                                stream << "\n" << tabformat(scp, 2) << "const " << fullpathtype_str(it->typ, self, it->typenam) << "& " <<
                                        fulltype_str(self, false) << "::" << it->name << "() const { return " << (option_no_holder() ? "" : "*") << it->name << "_ ;}\n";
                                stream << "\n" << tabformat(scp, 2) << "void " << fulltype_str(self, false) << "::" << it->name <<
                                        "( const " << it->typenam << "& vl){ " << it->name << "_ =vl ;}\n";
                                if (!option_no_holder()) {
                                    stream << "\n" << tabformat(scp, 2) << "void " << fulltype_str(self, false) << "::" << it->name <<
                                            "( boost::shared_ptr< " << it->typenam << ">  vl){ " << it->name << "_ =vl ;}\n";
                                }
                                break;
                            case mk_optional:
                                stream << "\n" << tabformat(scp, 2) << "boost::shared_ptr<" << fullpathtype_str(it->typ, self, it->typenam) << "> " <<
                                        fulltype_str(self, false) << "::" << it->name << "__new (){ return " << it->name << "_ = boost::shared_ptr<" <<
                                        it->typenam << ">(new " << it->typenam << "()) ;}\n";
                                stream << "\n" << tabformat(scp, 2) << "void " << fulltype_str(self, false) << "::" <<
                                        it->name << "( const " << it->typenam << "& vl){ " << it->name << "_ = boost::shared_ptr<" <<
                                        it->typenam << ">(new " << it->typenam << "(vl)) ;}\n";
                                break;
                            case mk_default:
                                stream << "\n" << tabformat(scp, 2) << "const " << fullpathtype_str(it->typ, self, it->typenam) << "& " <<
                                        fulltype_str(self, false) << "::" << it->name << "() const { return *" << it->name << "_ ;}\n";
                                stream << "\n" << tabformat(scp, 2) << "void " << fulltype_str(self, false) << "::" << it->name <<
                                        "( const " << it->typenam << "& vl){ " << it->name << "_ =vl ;}\n";
                                stream << "\n" << tabformat(scp, 2) << "void " << fulltype_str(self, false) << "::" << it->name <<
                                        "( boost::shared_ptr< " << it->typenam << ">  vl){ " << it->name << "_ =vl ;}\n";
                                break;
                            default:
                            {
                            }
                        }
                    }
                }
            }
        }

        void maincpp_out::execute_declare_cpp(typeassignment_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();

                if ((tpas) && (tpas->type()))
                    execute_declare_struct_cpp(tpas);
            }
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
                    typeassignment_entity_ptr cpas = self->childs().front()->as_typeassigment();
                    if (cpas) {
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

                        if (!nooblig.empty() && (nooblig.size() > oblig.size())) {
                            stream << "\n" << tabformat(scp, 1) << fulltype_str(self, false) << "::" << type_str(self) << "(";
                            for (member_vect::const_iterator it = nooblig.begin(); it != nooblig.end(); ++it) {
                                if (it != nooblig.begin())
                                    stream << ",\n" << tabformat(scp, 2);
                                stream << "boost::shared_ptr< " << it->typenam << ">  " << argumentname(it->name);
                            }
                            stream << ") : \n";
                            for (member_vect::const_iterator it = nooblig.begin(); it != nooblig.end(); ++it) {
                                if (it != nooblig.begin())
                                    stream << ",\n";
                                stream << tabformat(scp, 2) << it->name << "_(";
                                if (option_no_holder() && (it->marker == mk_none) && (!it->afterextention))
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
                            tagmarker_type mkr = (it->afterextention && (it->marker == mk_none)) ? mk_optional : it->marker;
                            if (mkr == mk_default) {
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







        //////////////////////////////////////////////////////
        //  ber_cpp_out
        //////////////////////////////////////////////////////

        void ber_cpp_out::execute() {
            execute_include(module_->name());

            stream << CHHEADER << "\n";
            execute_start_ns();

            if (option_reverse_decl())
                execute_typeassignments<basic_entity_vector::const_reverse_iterator>(module_->childs().rbegin(), module_->childs().rend());
            else
                execute_typeassignments<basic_entity_vector::const_iterator>(module_->childs().begin(), module_->childs().end());


            execute_stop_ns();
            stream << CHBOTTOM << "\n";
        }

        void ber_cpp_out::execute_typeassignment(typeassignment_entity_ptr self) {
            if ((self->is_cpp_expressed()) && (self->isstructure())) {
                if (self->isstruct())
                    execute_archive_meth_cpp(self, "x690");
                for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                    if ((*it)->as_typeassigment()) {
                        execute_typeassignment((*it)->as_typeassigment());
                    }
                }
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
                if (self->isstruct())
                    execute_archive_meth_cpp(self, "x691");
                for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                    if ((*it)->as_typeassigment()) {
                        execute_typeassignment((*it)->as_typeassigment());
                    }
                }
            }

        }

        void per_cpp_out::execute_archive_choice_output(typeassignment_entity_ptr self) {

            basic_entity_ptr scp;

            bool has_extention = ((self->type()) && (self->type()->has_extention()));

            if (has_extention) {
                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_SET_PER;";
            }


            namedtypeassignment_entity_vct root = self->canonicalorder_root();
            namedtypeassignment_entity_vct extentions = self->extentions();

            bool can_extention = ((extentions.size()) && (has_extention));

            std::size_t scppad = 0;

            if (can_extention) {
                scppad++;
                stream << "\n\n" << tabformat(scp, 3) << "if (ITU_T_EXTENTION_CHECK_PER) { ";
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
                        stream << "\n";
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
                            stream << " ITU_T_SET_NSN_SMALL_INDX(" << to_string(extention_it++) << "); ";
                            std::string tmpval = "value<" + fromtype_str(named) + " > (false , " + choice_enum_str(self, named) + ")";
                            stream << archive_member_per_str(named, tmpval);
                            stream << "; break; }";
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

            if (has_extention) {
                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_GET_PER;";
            }

            namedtypeassignment_entity_vct root = self->canonicalorder_root();
            namedtypeassignment_entity_vct extentions = self->extentions();

            bool can_extention = ((extentions.size()) && (has_extention));

            std::size_t scppad = 0;

            if (can_extention) {
                scppad++;
                stream << "\n\n" << tabformat(scp, 3) << "if (ITU_T_EXTENTION_CHECK_PER) { ";
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
                        stream << "\n";
                    }
                }
            }


            if (can_extention) {
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
                            stream << to_string(extention_it++) << ":  {";
                            std::string tmpval = "value<" + fromtype_str(named) + " > (false , " + choice_enum_str(self, named) + ")";
                            stream << archive_member_per_str(named, tmpval);
                            stream << "; break; }";
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

        static namedtypeassignment_entity_vct struct_optional_element(const namedtypeassignment_entity_vct& vl) {
            namedtypeassignment_entity_vct rslt;
            for (namedtypeassignment_entity_vct::const_iterator it = vl.begin(); it != vl.end(); ++it) {
                if (((*it)->as_named_typeassigment()) &&
                        (is_optional_or_default((*it)->as_named_typeassigment()->marker())))
                    rslt.push_back((*it));
            }
            return rslt;
        }

        static std::size_t struct_optional_count(const namedtypeassignment_entity_vct& vl) {
            std::size_t rslt = 0;
            for (namedtypeassignment_entity_vct::const_iterator it = vl.begin(); it != vl.end(); ++it) {
                if (((*it)->as_named_typeassigment()) &&
                        (is_optional_or_default((*it)->as_named_typeassigment()->marker())))
                    rslt++;
            }
            return rslt;
        }

        void per_cpp_out::execute_archive_struct_output(typeassignment_entity_ptr self) {
            basic_entity_ptr scp;
            namedtypeassignment_entity_vct root1 = self->child_root_1();
            namedtypeassignment_entity_vct root2 = self->child_root_2();
            namedtypeassignment_entity_vct root = root1;
            root.insert(root.end(), root2.begin(), root2.end());
            std::size_t opt_count = struct_optional_count(root);
            //std::size_t opt_it = 0;
            if ((self->type()) && (self->type()->has_extention())) {
                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_SET_PER;";
            }
            if (opt_count) {
                namedtypeassignment_entity_vct optels = struct_optional_element(root);
                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_OPTIONAL_DECL_PER = ";
                for (namedtypeassignment_entity_vct::iterator it = optels.begin(); it != optels.end(); ++it) {
                    if (it != optels.begin())
                        stream << " + ";
                    stream << " ITU_T_OPTIONAL_PER(" << (*it)->name() << "_)";
                }
                stream << ";\n";
                stream << "\n" << tabformat(scp, 3) << "ITU_T_OPTIONAL_SET_PER;";
                stream << "\n";
            }
            for (namedtypeassignment_entity_vct::iterator it = root1.begin(); it != root1.end(); ++it) {
                if ((*it)->type()) {
                    if (is_named((*it)->marker())) {
                        //bool is_opt = is_optional_or_default((*it)->marker());
                        execute_archive_member(*it/*, is_opt, is_opt ?  opt_it : 0*/);
                        /*if (is_opt)
                            opt_it++;*/
                    }
                }
            }
            ///  Some for extention

            if (!root2.empty()) {
                for (namedtypeassignment_entity_vct::iterator it = root2.begin(); it != root2.end(); ++it) {
                    if ((*it)->type()) {
                        if (is_named((*it)->marker())) {
                            //bool is_opt = is_optional_or_default((*it)->marker());
                            execute_archive_member(*it/*, is_opt, is_opt ? opt_it : 0*/);
                            /*if (is_opt)
                                opt_it++;*/
                        }
                    }
                }
            }
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
                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_EXTENTION_GET_PER;";
            }
            if (opt_count)
                stream << "\n\n" << tabformat(scp, 3) << "ITU_T_OPTIONAL_GET_PER(" << to_string(opt_count) << " );\n";
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

        std::string per_cpp_out::archive_member_per_constr(helper_ptr hlpr, const std::string& name, tagmarker_type dfltopt, size_constraints_ptr sizeconst, integer_constraints_ptr intconstr, bool alpha) {
            if (sizeconst) {
                size_constraints::range_type main_size_cnstr = sizeconst->to_per().main();
                bool ext_size_cnstr = sizeconst->to_per().has_extention();
                if (intconstr || alpha) {
                    if (hlpr && (hlpr->ts)) {
                        if (main_size_cnstr.single())
                            return "ITU_T_BIND_EXSIZE_SNGLCONSTR" + std::string(ext_size_cnstr ? "E" : "S") + "( " + 
                                    fromtype_str(hlpr->ts) + ", "+ hlpr->name + "__shelper, " + name_arch(name, dfltopt) + ", " +
                                    std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ??? ")) + ")";
                        else if (main_size_cnstr.right_semi())
                            return "ITU_T_BIND_EXSIZE_SEMICONSTR" + std::string(ext_size_cnstr ? "E" : "S")  + "( " +
                                    fromtype_str(hlpr->ts) + ", "+ hlpr->name + "__shelper, " + name_arch(name, dfltopt) + ", " +
                            std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ??? ")) + ")";
                        else
                            return "ITU_T_BIND_EXSIZE_CONSTR" + std::string(ext_size_cnstr ? "E" : "S") + "( " +
                                    fromtype_str(hlpr->ts) + ", "+ hlpr->name + "__shelper, "  + name_arch(name, dfltopt) + ", " +
                            std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ??? ")) + ", " +
                            std::string(main_size_cnstr.right_ptr() ? to_string(main_size_cnstr.right()) : std::string(" ??? ")) + ")";
                    }
                    else  return "??? Per binding";
                } else {
                    if (main_size_cnstr.single())
                        return "ITU_T_BIND_SIZE_SNGLCONSTR" + std::string(ext_size_cnstr ? "E" : "S") + "( " + name_arch(name, dfltopt) + ", " +
                        std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ??? ")) + ")";
                    else if (main_size_cnstr.right_semi())
                        return "ITU_T_BIND_SIZE_SEMICONSTR" + std::string(ext_size_cnstr ? "E" : "S") + "( " + name_arch(name, dfltopt) + ", " +
                        std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ??? ")) + ")";
                    else
                        return "ITU_T_BIND_SIZE_CONSTR" + std::string(ext_size_cnstr ? "E" : "S") + "( " + name_arch(name, dfltopt) + ", " +
                        std::string(main_size_cnstr.left_ptr() ? to_string(main_size_cnstr.left()) : std::string(" ??? ")) + ", " +
                        std::string(main_size_cnstr.right_ptr() ? to_string(main_size_cnstr.right()) : std::string(" ??? ")) + ")";
                }
            } else if (intconstr) {
                integer_constraints::range_type main_int_cnstr = intconstr->to_per().main();
                bool ext_int_cnstr = intconstr->to_per().has_extention();
                if (main_int_cnstr.single())
                    return "ITU_T_BIND_NUM_SNGLCON" + std::string(ext_int_cnstr ? "E" : "S") + "( " + name_arch(name, dfltopt) + ", " +
                    std::string(main_int_cnstr.left_ptr() ? to_string(main_int_cnstr.left()) : std::string(" ??? ")) + ")";
                else if (main_int_cnstr.right_semi())
                    return "ITU_T_BIND_NUM_SIMICON" + std::string(ext_int_cnstr ? "E" : "S") + "( " + name_arch(name, dfltopt) + ", " +
                    std::string(main_int_cnstr.left_ptr() ? to_string(main_int_cnstr.left()) : std::string(" ??? ")) + ")";
                else
                    return "ITU_T_BIND_NUM_CONSTR" + std::string(ext_int_cnstr ? "E" : "S") + "( " + name_arch(name, dfltopt) + ", " +
                    std::string(main_int_cnstr.left_ptr() ? to_string(main_int_cnstr.left()) : std::string(" ??? ")) + ", " +
                    std::string(main_int_cnstr.right_ptr() ? to_string(main_int_cnstr.right()) : std::string(" ??? ")) + ")";
            } else if (alpha) {
                if (hlpr && (hlpr->ts))
                    return "ITU_T_BIND_EX_CONSTRS(" + fromtype_str(hlpr->ts) + ", " + hlpr->name + "__shelper, " + name_arch(name, dfltopt) + ")";
                else
                    return "??? Per binding";
            }
            return "ITU_T_BIND_PER(" + name_arch(name, dfltopt) + ")";
        }

        std::string per_cpp_out::archive_member_per_str(namedtypeassignment_entity_ptr self, const std::string& name) {
            tagmarker_type dfltopt = self->marker();
            if ((dfltopt == mk_default) && (self->isstruct_of()))
                dfltopt = mk_optional;
            if (self->prefixed_typeassignment())
                dfltopt = mk_exception;
            helper_ptr helper = per_helper_finder::check(self);
            if (self->type()) {
                if (self->type()->can_per_constraints()) {
                    type_atom_ptr tmp = self->type();
                    size_constraints_ptr szconstr = tmp->size_constraint() ? tmp->size_constraint() : size_constraints_ptr();
                    integer_constraints_ptr intconstr = tmp->integer_constraint() ? tmp->integer_constraint() : integer_constraints_ptr();
                    bool alpha = (((tmp->char8_constraint())) || (tmp->tuple_constraint()) || (tmp->quadruple_constraint()));
                    return archive_member_per_constr(helper, name, dfltopt, szconstr, intconstr, alpha);
                }
                else if (helper) {
                    if (helper->type==pht_enumerated){
                        return "ITU_T_BIND_PER_ENUM(" + name_arch(name, dfltopt) + ", " +  helper->name + "__helper)";
                    } else if ((helper->type==pht_structof_enum) || (helper->type==pht_structof_int)) {
                       return "ITU_T_BIND_EX_CONSTRS(" +  fromtype_str(self) + ", " +  helper->name + "__shelper, "+ name_arch(name, dfltopt) +")";                        
                    }                   
                }
            }
            return "ITU_T_BIND_PER(" + name_arch(name, dfltopt) + ")";
        }

        void per_cpp_out::execute_archive_member(namedtypeassignment_entity_ptr self, bool opt, std::size_t optnum) {
            basic_entity_ptr scp;
            if (self->type()) {
                stream << "\n";
                stream << tabformat(scp, 3);
                if (opt)
                    stream << "ITU_T_OPTIONAL_CHECK_PER(" << to_string(optnum) << ")  ";
                stream << archive_member_per_str(self, nameconvert(self->name()) + "_") << ";";
            }
        }

        static std::string get_per_helper_name(typeassignment_entity_ptr tp) {
            return fulltype_str_ext(tp, false, "__");
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
                if (predef->extended())
                    stream << "_EXT";
                stream << "(" << name << "__helper, ITU_T_ARRAY(";
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
                    stream << "ITU_T_REGISTRATE_NUM_SNGLCON" << std::string(ext_int_cnstr ? "E" : "S") << "( " << name << ", " << fromtype_str(hlpr->ts) << ", " <<
                    std::string(main_int_cnstr.left_ptr() ? to_string(main_int_cnstr.left()) : std::string(" ??? ")) << ")";
                else if (main_int_cnstr.right_semi())
                    stream << "ITU_T_REGISTRATE_NUM_SIMICON" << std::string(ext_int_cnstr ? "E" : "S") << "( " << name << ", " << fromtype_str(hlpr->ts) << ", " <<
                    std::string(main_int_cnstr.left_ptr() ? to_string(main_int_cnstr.left()) : std::string(" ??? ")) << ")";
                else
                    stream << "ITU_T_REGISTRATE_NUM_CONSTR" << std::string(ext_int_cnstr ? "E" : "S") << "( " << name << ", " << fromtype_str(hlpr->ts) << ", " <<
                    std::string(main_int_cnstr.left_ptr() ? to_string(main_int_cnstr.left()) : std::string(" ??? ")) << ", " <<
                    std::string(main_int_cnstr.right_ptr() ? to_string(main_int_cnstr.right()) : std::string(" ??? ")) << ")";
            } //else
            //stream << "#error ";
        }

        void per_cpp_out::print_struct_enum_helper(helper_ptr hlpr) {
            basic_entity_ptr scp;
            if (hlpr->ts) {
                stream << tabformat(scp, 2);                
                stream << "ITU_T_REGISTRATE_ENUM_CONSTRS(" << hlpr->name << "__shelper, " << hlpr->name << "__helper);";
            } //else
            //stream << "#error ";
        }

        void per_cpp_out::print_struct_alphabet_helper(helper_ptr hlpr) {
            basic_entity_ptr scp;
            if (hlpr->ts) {
                 std::string typenm = builtin_str(hlpr->ts->root_builtin());
                stream << tabformat(scp, 2);
                stream << "struct " << hlpr->name << "__shelper" << " {\n";
                stream << tabformat(scp, 3);
                stream << "static void out(boost::asn1::x691::output_coder& stream, boost::asn1::" << typenm << "::value_type vl){\n";
                stream << tabformat(scp, 4);
                stream << "??? Manualy_mplementation_required \n";
                stream << tabformat(scp, 4);
                stream << "}\n\n";
                stream << tabformat(scp, 3);
                stream << "static " << typenm << "::value_type in(boost::asn1::x691::input_coder& stream){\n";
                stream << tabformat(scp, 4);
                stream << "??? Manualy_mplementation_required \n";
                stream << tabformat(scp, 4);
                stream << "}\n\n";
                stream << tabformat(scp, 3);                
                stream << "static std::size_t bits_count(bool aligned){\n";
                stream << tabformat(scp, 4);
                stream << "??? Manualy_mplementation_required \n";
                stream << tabformat(scp, 4);
                stream << "}\n\n";
                stream << tabformat(scp, 2);
                stream << "};\n";
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
