//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/cpp_cout.hpp>


namespace x680 {
    namespace cpp {

        enum declare_type {
            declare_typedef,
            declare_seq,
            declare_set,
            declare_explicit,
            declare_implicit
        };

        struct declare_atom {

            declare_atom() {
            };

            declare_atom(declare_type decl_, const std::string& typenam_, const std::string& from_type_, bool rem = false) :
            decl(decl_), typenam(typenam_), from_type(from_type_), remote_(rem) {
            };

            declare_atom(declare_type decl_, const std::string& typenam_, const std::string& from_type_, const std::string& tag_, const std::string& _class_, bool rem = false) :
            decl(decl_), typenam(typenam_), from_type(from_type_), tag(tag_), class_(_class_), remote_(rem) {
            };

            declare_type decl;
            std::string typenam;
            std::string from_type;
            std::string tag;
            std::string class_;
            bool remote_;

        };

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


        const std::string FHHEADER = "#include <boost/itu/asn1/asnbase.hpp>\n#include <boost/itu/x69X/x690.hpp>\n\n#ifdef _MSC_VER\n#pragma warning(push)\n#pragma warning(disable: 4065)\n#endif\n\n";
        const std::string FHBOTTOM = "\n\n#endif";
        const std::string MNDCL = "    using  boost::asn1::null_type;\n"
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
                "    using  boost::asn1::any_type;\n";

        std::string correct_name(std::string vl) {
            const std::set<std::string>& base = token_base();
            return base.find(vl) != base.end() ? (vl + "V") : vl;
        }

        std::string nameconvert(std::string name) {
            boost::algorithm::replace_all(name, "-", "_");
            return correct_name(name);
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
            if (self->type()) {
                if (self->type()->isrefferrence())
                    return nameconvert(self->name());
                else if (self->type()->isstructure()) {
                    typeassignment_entity_ptr ppas = self->scope() ?
                            self->scope()->as_typeassigment() : typeassignment_entity_ptr();
                    std::string postfix = (ppas || native || (!self->type()->tag())) ? "" : "_impl";
                    if (ppas && (ppas->type())&& (ppas->type()->isstruct_of()))
                        return type_str(ppas)+(ppas->type()->builtin() == t_SEQUENCE_OF ? "_sequence_of" : "_set_of");
                    return nameconvert(self->islocaldeclare() ? (self->name() + "_type") : self->name()) + postfix;
                } else
                    return nameconvert(self->name());
            }
            return "";
        }

        std::string fulltype_str(basic_entity_ptr self, bool withns) {
            if ((self->as_typeassigment()) || (self->as_module())) {
                if (self->as_module()) {
                    if (withns)
                        return nameconvert(self->name());
                    else
                        return "";
                } else if (self->as_typeassigment()) {
                    typeassignment_entity_ptr ppas = self->as_typeassigment();
                    std::string tmp = fulltype_str(self->scope(), withns);
                    if ((ppas->type()) && (!ppas->type()->isstruct_of()))
                        return tmp.empty() ? type_str(ppas) : (tmp + "::" + type_str(ppas));
                    else
                        return tmp;
                }
            }
            typeassignment_entity_ptr ppas = self->as_typeassigment();
            if ((ppas->type()) && (!ppas->type()->isstruct_of()))
                return type_str(self->as_typeassigment());
            return "";
        }

        std::string value_int_str(value_atom_ptr self) {
            if (self && (self->as_number())) {
                try {
                    return boost::lexical_cast<std::string > (self->as_number()->value());
                } catch (boost::bad_lexical_cast) {
                    return "???num???";
                }
            }
            if ((self->as_defined()) && (self->as_defined()->reff())) {
                if (self->as_defined()->reff()->as_valueassigment())
                    return value_int_str(self->as_defined()->reff()->as_valueassigment()->value());
            }
            return "???num???";
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
            if (self && (self->as_list())) {
                structvalue_atom_ptr lst = self->as_list();
                for (value_vct::const_iterator it = lst->values().begin(); it != lst->values().end(); ++it) {
                    value_atom_ptr subval = (*it);
                    if (subval->as_number())
                        rslt.push_back(value_int_str(subval));
                    else if (subval->as_assign())
                        rslt.push_back(value_int_str(subval->as_assign()->value()));
                    else if (subval->as_defined()) {
                        if (subval->as_defined()->reff()) {
                            if (subval->as_defined()->reff()->as_valueassigment()) {
                                value_atom_ptr tmpval = value_skip_defined(subval->as_defined()->reff()->as_valueassigment()->value());
                                if (tmpval) {
                                    if (tmpval->as_list())
                                        value_oid_str(tmpval, rslt);
                                    else
                                        rslt.push_back(value_int_str(tmpval));
                                }
                            } else rslt.push_back("???");
                        } else rslt.push_back("???");
                    } else rslt.push_back("???");
                }
            }
            return !rslt.empty();
        }

        std::string fromtype_str(typeassignment_entity_ptr self) {
            if (self->type()) {
                if (self->type()->isrefferrence()) {
                    typeassignment_entity_ptr frtp = ((self->type()->reff()) && (self->type()->reff()->as_typeassigment())) ?
                            self->type()->reff()->as_typeassigment() : typeassignment_entity_ptr();
                    module_entity_ptr extmod = (frtp && (frtp->moduleref() != self->moduleref())) ? frtp->moduleref() : module_entity_ptr();
                    std::string pref = extmod ? (nameconvert(extmod->name()) + "::") : "";
                    return (pref + nameconvert(self->type()->reff()->name()));
                } else if (self->type()->isstructure())
                    return type_str(self, true);
                else
                    return builtin_str(self->type()->builtin());
            }
            return "???type???";
        }

        bool fromtype_remote(typeassignment_entity_ptr self) {
            if (self->type()) {
                if (self->type()->isrefferrence()) {
                    typeassignment_entity_ptr frtp = ((self->type()->reff()) && (self->type()->reff()->as_typeassigment())) ?
                            self->type()->reff()->as_typeassigment() : typeassignment_entity_ptr();
                    return ((frtp) && (frtp->moduleref() != self->moduleref()));
                }
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

        std::string fromtype_str(type_atom_ptr self) {
            if (self) {
                if (self->isrefferrence())
                    return nameconvert(self->reff()->name());
                else if (self->isstructure())
                    return "???type???";
                else
                    return builtin_str(self->builtin());
            }
            return "???type???";
        }

        std::string member_marker_str(const std::string& str, tagmarker_type self, bool simple) {
            switch (self) {
                case mk_default:
                case mk_optional:
                {
                    return "boost::shared_ptr<" + str + ">";
                }
                default:
                {
                    return simple ? str : ("boost::asn1::value_holder<" + str + ">");
                }
            }
            return str;
        }

        std::string seqof_str(typeassignment_entity_ptr self, const std::string& name) {
            if (self->type()->builtin() == t_SEQUENCE_OF)
                return "typedef std::vector< " + name + "> ";
            else
                return "typedef std::deque< " + name + "> ";
        }

        std::string choice_enum_str(typeassignment_entity_ptr self, basic_entity_ptr sub) {
            return type_str(self) + "_" + nameconvert(sub->name());
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

        std::string archive_member_ber_str(namedtypeassignment_entity_ptr self, const std::string& name) {
            if (self->type()) {
                if (self->type()->istextualy_choice()) {
                    if (self->type()->tag()) {
                        switch (self->type()->tag()->_class()) {
                            case tcl_application: return "BOOST_ASN_CHOICE_APPLICATION_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                            case tcl_universal: return "BOOST_ASN_CHOICE_UNIVERSAL_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                            case tcl_private: return "BOOST_ASN_CHOICE_PRIVATE_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                            default: return "BOOST_ASN_CHOICE_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                        }
                    } else
                        return "BOOST_ASN_CHOICE(" + name + ")";
                } else {
                    if (self->type()->tag()) {
                        if (self->type()->tag()->rule() == implicit_tags) {
                            switch (self->type()->tag()->_class()) {
                                case tcl_application: return "BOOST_ASN_IMPLICIT_APPLICATION_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                                case tcl_universal: return "BOOST_ASN_IMPLICIT_UNIVERSAL_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                                case tcl_private: return "BOOST_ASN_IMPLICIT_PRIVATE_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                                default: return "BOOST_ASN_IMPLICIT_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                            }
                        } else {
                            switch (self->type()->tag()->_class()) {
                                case tcl_application: return "BOOST_ASN_EXPLICIT_APPLICATION_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                                case tcl_universal: return "BOOST_ASN_EXPLICIT_UNIVERSAL_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                                case tcl_private: return "BOOST_ASN_EXPLICIT_PRIVATE_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                                default: return "BOOST_ASN_EXPLICIT_TAG(" + name + ", " + tagged_str(self->type()->tag()) + ")";
                            }
                        }
                    } else
                        return "BOOST_ASN_BIND_TAG(" + name + ")";
                }
            }
            return "";
        }

        std::string struct_meth_str(typeassignment_entity_ptr self, const std::string& tp) {
            return "\n" + tabformat(basic_entity_ptr(), 2) + "template<> void " +
                    fulltype_str(self, false) + "::serialize(" +
                    tp + "& arch)";
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

        fileout::fileout(global_entity_ptr glb, const std::string& path, const std::string& outdir, bool revrs, bool nohldr)
        : path_(path), outdir_(outdir), global_(glb), reverse_(revrs), noholder_(nohldr) {
        }

        fileout::~fileout() {
        }

        void fileout::execute() {

            if (!dir_exists(path_))
                throw fsnsp::filesystem_error("File or directory error",
                    boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));
            if (!dir_create(path_, outdir_))
                throw fsnsp::filesystem_error("File or directory error",
                    boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));
            path_ = path_ + "\\" + outdir_ + "\\";

            for (basic_entity_vector::iterator it = global_->childs().begin(); it != global_->childs().end(); ++it) {
                if ((*it)->as_module())
                    execute_module((*it)->as_module());
            }
        }

        void fileout::execute_module(module_entity_ptr self) {

            std::string newpath = path_ + "\\" + self->name() + ".hpp";
            fsnsp::path p(newpath.c_str());
            std::ofstream stream(p.generic_string().c_str(), std::ofstream::out | std::ofstream::trunc);
            if (!stream)
                throw fsnsp::filesystem_error("File dosnt create: " + p.generic_string(),
                    boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));

            headerlock(stream, self->name());


            execute_start_ns(stream, self);

            execute_standart_type(stream, self);

            // struct X1; ...
            
            execute_struct_predeclare(stream, self);
            execute_typedef_decl_seqof(stream, self, self);

            execute_typedef_native(stream, self, true);

            declare_vect vct;
            loaddecl(vct, self);
            execute_typedef(stream, vct, false);

            execute_stop_ns(stream, self);

            

            execute_includes_hpp(stream, self);

            

            execute_start_ns(stream, self);
            
            execute_imports(stream, self);
            execute_typedef(stream, vct, true);

            if (reverse_)
                execute_assignments_hpp<basic_entity_vector::const_reverse_iterator>(stream, self, self->childs().rbegin(), self->childs().rend());
            else
                execute_assignments_hpp<basic_entity_vector::const_iterator>(stream, self, self->childs().begin(), self->childs().end());

            execute_struct_meth_hpp(stream, self);

            execute_stop_ns(stream, self);

            
            
            if (registrate_struct_set(stream, self))
                stream << "\n";
            registrate_struct_choice(stream, self);

            bottomlock(stream, self->name());


            newpath = path_ + "\\" + self->name() + ".cpp";
            fsnsp::path p_cpp(newpath.c_str());
            std::ofstream stream_cpp(p_cpp.generic_string().c_str(), std::ofstream::out | std::ofstream::trunc);
            if (!stream_cpp)
                throw fsnsp::filesystem_error("File dosnt create: " + p_cpp.generic_string(),
                    boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));

            execute_include(stream_cpp, self->name());
            stream << "\n";
            execute_start_ns(stream_cpp, self);

            if (reverse_)
                execute_assignments_cpp<basic_entity_vector::const_reverse_iterator>(stream_cpp, self, self->childs().rbegin(), self->childs().rend());
            else
                execute_assignments_cpp<basic_entity_vector::const_iterator>(stream_cpp, self, self->childs().begin(), self->childs().end());

            execute_stop_ns(stream_cpp, self);

        }

        void fileout::loaddecl(declare_vect& vct, basic_entity_ptr self) {
            execute_typedef_reff(vct, self);
            execute_typedef_seqof(vct, self);
            resolve_remote_reff(vct);
            sort_reff(vct);
        }

        void fileout::execute_typedef_reff(declare_vect& vct, basic_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type()) && (tpas->is_cpp_expressed())) {
                    if (tpas->type()->isrefferrence()) {
                        if (!tpas->type()->tag()) {
                            vct.push_back(declare_atom(declare_typedef, type_str(tpas), fromtype_str(tpas), fromtype_remote(tpas)));
                        } else {
                            vct.push_back(declare_atom(((tpas->type()->tag()->rule() == explicit_tags) ? declare_explicit : declare_implicit),
                                    type_str(tpas), fromtype_str(tpas), tagged_str(tpas->type()->tag()), tagged_class_str(tpas->type()->tag()), fromtype_remote(tpas)));
                        }
                    } else if ((tpas->type()->isstructure())&& (tpas->type()->tag())) {
                        vct.push_back(declare_atom(((tpas->type()->tag()->rule() == explicit_tags) ? declare_explicit : declare_implicit),
                                type_str(tpas, true), type_str(tpas), tagged_str(tpas->type()->tag()), tagged_class_str(tpas->type()->tag()), false));
                    }
                }
            }
        }

        void fileout::execute_typedef_seqof(declare_vect& vct, basic_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type()) && (tpas->is_cpp_expressed())) {
                    if ((tpas->type()->isstruct_of()) && (!tpas->childs().empty()))
                        execute_typedef_seqof_impl(vct, tpas);
                }
            }
        }

        bool fileout::execute_typedef_seqof_impl(declare_vect& vct, typeassignment_entity_ptr self) {
            if (!self->childs().empty()) {
                typeassignment_entity_ptr cpas = self->childs().front()->as_typeassigment();
                if (cpas && (cpas->type())) {
                    if ((!cpas->type()->issimplerefferrence()) && (!cpas->type()->isstruct_of())) {
                        vct.push_back(declare_atom(((cpas->type()->builtin() == t_SEQUENCE_OF) ? declare_seq : declare_set),
                                type_str(self), fromtype_str(cpas), fromtype_remote(cpas)));
                        return true;
                    } else if ((cpas->type()->isstruct_of())) {
                        if (execute_typedef_seqof_impl(vct, cpas)) {
                            vct.push_back(declare_atom(((cpas->type()->builtin() == t_SEQUENCE_OF) ? declare_seq : declare_set),
                                    type_str(self), fromtype_str(cpas), fromtype_remote(cpas)));
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        void fileout::execute_typedef(std::ofstream& stream, const declare_vect& vct, bool remote, basic_entity_ptr scp) {
            stream << "\n";
            for (declare_vect::const_iterator it = vct.begin(); it != vct.end(); ++it) {
                if (it->remote_ == remote) {
                    switch (it->decl) {
                        case declare_typedef: stream << "\n" << tabformat(scp) << "typedef " << it->from_type << " " << it->typenam << ";";
                            break;
                        case declare_seq: stream << "\n" << tabformat(scp) << "std::vector< " << it->from_type << " > " << it->typenam << ";";
                            break;
                        case declare_set: stream << "\n" << tabformat(scp) << "std::deque< " << it->from_type << " > " << it->typenam << ";";
                            break;
                        case declare_explicit: stream << "\n" << tabformat(scp) << "BOOST_ASN_EXPLICIT_TYPEDEF( "
                                    << it->typenam << ", " << it->from_type << ", " << it->tag << ", " << it->class_ << ");";
                            break;
                        case declare_implicit: stream << "\n" << tabformat(scp) << "BOOST_ASN_IMPLICIT_TYPEDEF( "
                                    << it->typenam << ", " << it->from_type << ", " << it->tag << ", " << it->class_ << ");";
                            break;
                        default:
                        {
                        }
                    }
                }
            }
            if (!vct.empty())
                stream << "\n";
        }

        void fileout::execute_typedef_native(std::ofstream& stream, basic_entity_ptr self, bool global, basic_entity_ptr scp) {
            // expl X ::= INTEGER or X = [1] INEGER
            if (global) {
                execute_typedef_simple_native(stream, self, false);
                execute_typedef_simple_native(stream, self, true);
            }
            execute_typedef_seqof_native(stream, self, scp);
        }
        

        void fileout::headerlock(std::ofstream& stream, std::string name) {
            name = nameconvert(name);
            boost::algorithm::to_upper(name);
            name = "___" + name;
            stream << ("#ifndef " + name + "\n" + "#define " + name + "\n\n" + FHHEADER + "\n");
        }

        void fileout::bottomlock(std::ofstream& stream, std::string name) {
            name = nameconvert(name);
            boost::algorithm::to_upper(name);
            name = "___" + name;
            stream << (FHBOTTOM + "  /*" + name + " */\n");
        }

        void fileout::execute_include(std::ofstream& stream, std::string name) {
            stream << "#include \"" << name << ".hpp\"\n";
        }

        void fileout::execute_includes_hpp(std::ofstream& stream, module_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->imports().begin(); it != self->imports().end(); ++it)
                if ((*it)->as_import())
                    execute_include(stream, (*it)->as_import()->name());
        }

        void fileout::execute_standart_type(std::ofstream& stream, module_entity_ptr self) {
            stream << "\n";
            stream << MNDCL;
            stream << "\n";
        }

        void fileout::execute_start_ns(std::ofstream& stream, module_entity_ptr self) {
            stream << "\n";
            stream << "namespace " + nameconvert(self->name()) + " {\n";
        }

        void fileout::execute_stop_ns(std::ofstream& stream, module_entity_ptr self) {
            stream << "\n} ";
            stream << "\n";
        }

        void fileout::execute_import(std::ofstream& stream, module_entity_ptr mod, import_entity_ptr self) {

            if (self->scope())
                stream << "\n  // import   from  " << self->name();
            else
                stream << "\n";
            stream << "\n";
            stream << "\n";
            for (import_vector::iterator it = self->import().begin(); it != self->import().end(); ++it) {
                if (expressed_import(mod, nameconvert(*it))) {
                    stream << tabformat() << "using " << nameconvert(self->name())
                            << "::" << nameconvert(*it) << ";\n";
                }
            }
            stream << "\n";
        }

        void fileout::execute_imports(std::ofstream& stream, module_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->imports().begin(); it != self->imports().end(); ++it)
                if ((*it)->as_import())
                    execute_import(stream, self, (*it)->as_import());
        }

        void fileout::execute_struct_predeclare(std::ofstream& stream, basic_entity_ptr self) {
            for (basic_entity_vector::const_iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type()) && (tpas->is_cpp_expressed())) {
                    if ((tpas->type()) && (tpas->type()->isstruct()))
                        stream << tabformat() << "struct " << type_str(tpas) + "; " << " \n";
                    //if (tpas->type()->tag())
                    //     stream << tabformat() << "struct " << type_str(tpas, true) + "; " << " \n";
                }
            }
            if (!self->childs().empty())
                stream << "\n";
        }

        void fileout::execute_typedef_simple_native(std::ofstream& stream, basic_entity_ptr self, bool tagged) {
            std::size_t cnt = 0;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type())) {
                    if ((tpas->type()->issimplerefferrence()) && (tpas->is_cpp_expressed())) {
                        if (!tagged && (!tpas->type()->tag())) {
                            stream << tabformat() << "typedef ";
                            stream << fromtype_str(tpas) << " " << type_str(tpas);
                            stream << "; " << " \n";
                            cnt++;
                        } else if (tagged && (tpas->type()->tag())) {
                            stream << tabformat() << "BOOST_ASN_";
                            stream << (tpas->type()->tag()->rule() == explicit_tags ? "EXPLICIT_TYPEDEF(" : "IMPLICIT_TYPEDEF(");
                            stream << type_str(tpas) << ", " << fromtype_str(tpas) << ",  ";
                            stream << tagged_str(tpas->type()->tag()) << ", " << tagged_class_str(tpas->type()->tag());
                            stream << "); " << " \n";
                            cnt++;
                        }
                    }
                }
            }
            if (cnt)
                stream << "\n";
        }



        void fileout::execute_typedef_decl_seqof(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type()) && (tpas->is_cpp_expressed())) {
                    if ((tpas->type()->isstruct_of()) && (!tpas->childs().empty())) {
                        typeassignment_entity_ptr cpas = tpas->childs().front()->as_typeassigment();
                        if (cpas && (cpas->type())) {
                            if (cpas->type()->isstruct_of()) {
                                execute_typedef_decl_seqof(stream, tpas, scp);
                            } else if (cpas->type()->isstruct()) {
                                stream << tabformat(scp);
                                stream << "struct " << type_str(cpas) << ";";
                                stream << "\n";
                            }
                        }
                    }
                }
            }
        }

        void fileout::execute_typedef_seqof_native(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type()) && (tpas->is_cpp_expressed())) {
                    if ((tpas->type()->isstruct_of())) {
                        execute_typedef_seqof_native_impl(stream, tpas, scp);
                    }
                }
            }
            stream << "\n";
        }

        bool fileout::execute_typedef_seqof_native_impl(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            if (!self->childs().empty()) {
                typeassignment_entity_ptr cpas = self->childs().front()->as_typeassigment();
                if (cpas && (cpas->type())) {
                    if (cpas->type()->issimplerefferrence()) {
                        stream << "\n" << tabformat(scp) << seqof_str(self, fromtype_str(cpas)) << type_str(self) << ";";
                        return true;
                    } else if ((cpas->type()->isstruct_of())) {
                        if (execute_typedef_seqof_native_impl(stream, cpas, scp)) {
                            stream << "\n" << tabformat(scp) << seqof_str(self, fromtype_str(cpas)) << type_str(self) << ";";
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        void fileout::execute_typedef_seqof(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp, bool endl) {
            scp = scp ? scp : self;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type()) && (tpas->is_cpp_expressed())) {
                    if ((tpas->type()->isstruct_of()) && (!tpas->childs().empty())) {
                        typeassignment_entity_ptr cpas = tpas->childs().front()->as_typeassigment();
                        if (cpas) {
                            if (endl)
                                stream << "\n";
                            if (cpas->type()->isrefferrence()) {
                                stream << tabformat(scp);
                                stream << seqof_str(tpas, fromtype_str(cpas)) << type_str(tpas) << ";";
                            } else {
                                if (!tpas->childs().empty()) {
                                    typeassignment_entity_ptr ipas = tpas->childs().front()->as_typeassigment();
                                    if ((ipas->type()) && (ipas->type()->isstruct_of()))
                                        execute_typedef_seqof(stream, tpas, scp, false);
                                }
                                stream << tabformat(scp);
                                stream << seqof_str(tpas, fromtype_str(cpas)) << type_str(tpas) << ";";
                            }
                        }
                    }
                }
            }
            if (!self->childs().empty())
                stream << "\n";
        }

        void fileout::execute_typeassignment_hpp(std::ofstream& stream, basic_entity_ptr self, typeassignment_entity_ptr tpas, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            if (tpas && (tpas->type()) && (tpas->is_cpp_expressed())) {
                switch (tpas->type()->builtin()) {
                    case t_CHOICE:
                        stream << "\n";
                        stream << tabformat(tpas) << "// choice " << tpas->name();
                        execute_choice_hpp(stream, tpas);
                        break;
                    case t_SEQUENCE:
                        stream << "\n";
                        stream << tabformat(tpas) << "// sequence " << tpas->name();
                        execute_seqset_hpp(stream, tpas);
                        break;
                    case t_SET:
                        stream << "\n";
                        stream << tabformat(tpas) << "// set " << tpas->name();
                        execute_seqset_hpp(stream, tpas);
                        break;
                    case t_SEQUENCE_OF:
                        execute_seqsetof_hpp(stream, tpas);
                        break;
                    case t_SET_OF:
                        execute_seqsetof_hpp(stream, tpas);
                        break;
                    default:
                    {
                        if ((tpas) && (tpas->type()->predefined())) {
                            execute_predefined_hpp(stream, tpas);
                        }
                    }
                }
            }
        }

        void fileout::execute_typeassignment_cpp(std::ofstream& stream, typeassignment_entity_ptr tpas) {
            // scp = scp ? scp : self;
            if (tpas && (tpas->type()) && (tpas->is_cpp_expressed())) {
                switch (tpas->type()->builtin()) {
                    case t_CHOICE:
                        stream << "\n";
                        stream << tabformat(tpas) << "// choice " << tpas->name();
                        execute_choice_cpp(stream, tpas);
                        break;
                    case t_SEQUENCE:
                        stream << "\n";
                        stream << tabformat(tpas) << "// sequence " << tpas->name();
                        execute_seqset_cpp(stream, tpas);
                        break;
                    case t_SET:
                        stream << "\n";
                        stream << tabformat(tpas) << "// set " << tpas->name();
                        execute_seqset_cpp(stream, tpas);
                        break;
                    case t_SEQUENCE_OF:
                        execute_seqsetof_cpp(stream, tpas);
                        break;
                    case t_SET_OF:
                        execute_seqsetof_cpp(stream, tpas);
                        break;
                    default:
                    {
                        if ((tpas) && (tpas->type()->predefined())) {
                            execute_predefined_cpp(stream, tpas, tpas);
                        }
                    }
                }
            }
        }

        void fileout::execute_predefined_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            if (self->type()) {
                predefined_ptr predef = self->type()->predefined();
                if (predef) {
                    switch (self->type()->root_builtin()) {
                        case t_INTEGER:
                        {
                            execute_predefined_int_hpp(stream, predef, self, scp);
                            break;
                        }
                        case t_BIT_STRING:
                        {
                            execute_predefined_bs_hpp(stream, predef, self, scp);
                            break;
                        }
                        case t_ENUMERATED:
                        {
                            execute_predefined_int_hpp(stream, predef, self, scp);
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

        void fileout::execute_predefined_cpp(std::ofstream& stream, typeassignment_entity_ptr self, typeassignment_entity_ptr ansec) {
            if (self->type()) {
                predefined_ptr predef = self->type()->predefined();
                if (predef) {
                    switch (self->type()->root_builtin()) {
                        case t_INTEGER:
                        {
                            execute_predefined_int_cpp(stream, predef, self, ansec);
                            break;
                        }
                        case t_BIT_STRING:
                        {
                            execute_predefined_bs_cpp(stream, predef, self, ansec);
                            break;
                        }
                        case t_ENUMERATED:
                        {
                            execute_predefined_int_cpp(stream, predef, self, ansec);
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

        void fileout::execute_predefineds_hpp(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas)
                    execute_predefined_hpp(stream, tpas);
            }
        }

        void fileout::execute_predefineds_cpp(std::ofstream& stream, basic_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas)
                    execute_predefined_cpp(stream, tpas, self->as_typeassigment());
            }
        }

        void fileout::execute_predefined_int_hpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            std::string pref = ((self->scope()) && (self->scope()->as_typeassigment())) ? "static " : "extern ";
            stream << "\n";
            for (basic_entity_vector::const_iterator it = prdf->values().begin(); it != prdf->values().end(); ++it) {
                valueassignment_entity_ptr vlass = (*it)->as_valueassigment();
                if (vlass) {
                    stream << tabformat(scp) << pref << "const ";
                    stream << /*nameconvert(self->name())*/"int" << " ";
                    stream << nameconvert(self->name()) << "_" << nameconvert(vlass->name()) << ";\n";
                }
            }
        }

        void fileout::execute_predefined_int_cpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self, typeassignment_entity_ptr ansec) {
            bool local = ((self->scope()) && (self->scope()->as_typeassigment()));
            stream << "\n";
            for (basic_entity_vector::const_iterator it = prdf->values().begin(); it != prdf->values().end(); ++it) {
                valueassignment_entity_ptr vlass = (*it)->as_valueassigment();
                if (vlass) {
                    stream << tabformat() << "const ";
                    stream << /*nameconvert(self->name())*/"int" << " ";
                    if (local && ansec)
                        stream << fulltype_str(ansec, false) << "::";
                    stream << nameconvert(self->name()) << "_" << nameconvert(vlass->name()) << " = ";
                    stream << value_int_str(vlass->value()) << ";\n";
                }
            }
        }

        void fileout::execute_predefined_bs_hpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            std::string pref = ((self->scope()) && (self->scope()->as_typeassigment())) ? "static " : "extern ";
            stream << "\n";
            for (basic_entity_vector::const_iterator it = prdf->values().begin(); it != prdf->values().end(); ++it) {
                valueassignment_entity_ptr vlass = (*it)->as_valueassigment();
                if (vlass) {
                    stream << tabformat(scp) << pref << "const ";
                    stream << /*nameconvert(self->name())*/"bitstring_type" << " ";
                    stream << nameconvert(self->name()) << "_" << nameconvert(vlass->name()) << ";\n";
                }
            }
        }

        void fileout::execute_predefined_bs_cpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self, typeassignment_entity_ptr ansec) {
            bool local = ((self->scope()) && (self->scope()->as_typeassigment()));
            stream << "\n";
            for (basic_entity_vector::const_iterator it = prdf->values().begin(); it != prdf->values().end(); ++it) {
                valueassignment_entity_ptr vlass = (*it)->as_valueassigment();
                if (vlass) {
                    stream << tabformat() << "const ";
                    stream << /*nameconvert(self->name())*/"bitstring_type" << " ";
                    if (local && ansec)
                        stream << fulltype_str(ansec, false) << "::";
                    stream << nameconvert(self->name()) << "_" << nameconvert(vlass->name()) << " = ";
                    stream << "bitstring_type(true, " << value_int_str(vlass->value()) << ");\n";
                }
            }
        }

        void fileout::execute_valueassignment_hpp(std::ofstream& stream, valueassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            switch (self->type()->root_builtin()) {
                case t_INTEGER:
                {
                    stream << "\n" << tabformat(scp) << "extern const " << fromtype_str(self->type()) << ";";
                    stream << "\n";
                    break;
                }
                case t_OBJECT_IDENTIFIER:
                {
                    std::vector<std::string> rslt;
                    if (value_oid_str(self->value(), rslt)) {
                        stream << "\n" << tabformat(scp) << "extern const boost::asn1::oid_type " << nameconvert(self->name()) << ";";
                        stream << "\n";
                    }
                    break;
                }
                default:
                {
                }
            }
        }

        void fileout::execute_valueassignment_cpp(std::ofstream& stream, valueassignment_entity_ptr self) {
            switch (self->type()->root_builtin()) {
                case t_INTEGER:
                {
                    stream << "\n" << tabformat() << "const " << fromtype_str(self->type()) << " "
                            << nameconvert(self->name()) << " = "
                            << value_int_str(self->value()) << ";";
                    stream << "\n";
                    break;
                }
                case t_OBJECT_IDENTIFIER:
                {
                    std::vector<std::string> rslt;
                    if (value_oid_str(self->value(), rslt)) {
                        stream << "\n" << tabformat() << "const boost::array<boost::asn1::oidindx_type, ";
                        stream << rslt.size() << "> " << nameconvert(self->name()) << "_OID_ARR = { ";
                        for (std::vector<std::string>::const_iterator it = rslt.begin(); it != rslt.end(); ++it) {
                            if (it != rslt.begin())
                                stream << ", ";
                            stream << (*it);
                        }
                        stream << "};";
                        stream << "\n" << tabformat() << "const boost::asn1::oid_type " << nameconvert(self->name());
                        stream << "  = boost::asn1::oid_type(" << nameconvert(self->name()) << "_OID_ARR );";
                        stream << "\n";
                    }
                    break;
                }
                default:
                {
                }
            }
        }

        void fileout::execute_member(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            bool ischoice = (self->type()->builtin() == t_CHOICE);
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if ((tpas) && (tpas->as_named())) {
                    namedtypeassignment_entity_ptr named = tpas->as_named();
                    if (named->type()) {
                        tagmarker_type mkr = named->type()->isnotagged_choice() ? mk_none : named->marker();
                        if ((mkr == mk_none) || (mkr == mk_default) || (mkr == mk_optional)) {
                            stream << "\n";
                            if (!ischoice) {
                                stream << tabformat(scp, 1) <<
                                        member_marker_str(fromtype_str(named), mkr, noholder_) <<
                                        " " << nameconvert(named->name()) << ";";

                                if ((mkr == mk_optional) || (mkr == mk_default)) {
                                    stream << "\n" << tabformat(scp, 1) << "BOOST_ASN_VALUE_FUNC_DECLARATE(";
                                    stream << fromtype_str(named) << ", " << nameconvert(named->name()) << ")\n";

                                }
                            } else {
                                stream << tabformat(scp, 1) <<
                                        "BOOST_ASN_VALUE_CHOICE(" <<
                                        nameconvert(named->name()) << ", " << fromtype_str(named) << ", " <<
                                        type_str(self) << "_" << nameconvert(named->name()) << ");";
                            }
                        }
                    }
                }
            }
        }

        void fileout::execute_declare_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if ((tpas) && (tpas->type()))
                    execute_declare_struct_hpp(stream, tpas, scp);
            }
        }

        void fileout::execute_declare_cpp(std::ofstream& stream, typeassignment_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if ((tpas) && (tpas->type()))
                    execute_declare_struct_cpp(stream, tpas);
            }
        }

        void fileout::execute_declare_struct_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            if ((self) && (self->type())) {
                switch (self->type()->builtin()) {
                    case t_CHOICE: stream << "\n";
                        execute_choice_hpp(stream, self);
                        break;
                    case t_SET:
                    case t_SEQUENCE: stream << "\n";
                        execute_seqset_hpp(stream, self);
                        break;
                    case t_SET_OF:
                    case t_SEQUENCE_OF:
                        execute_seqsetof_hpp(stream, self);
                        break;
                    default:
                    {
                    }
                }
            }
        }

        void fileout::execute_declare_struct_cpp(std::ofstream& stream, typeassignment_entity_ptr self) {
            if ((self) && (self->type())) {
                switch (self->type()->builtin()) {
                    case t_CHOICE: stream << "\n";
                        execute_choice_cpp(stream, self);
                        break;
                    case t_SET:
                    case t_SEQUENCE: stream << "\n";
                        execute_seqset_cpp(stream, self);
                        break;
                    case t_SET_OF:
                    case t_SEQUENCE_OF:
                        execute_seqsetof_cpp(stream, self);
                        break;
                    default:
                    {
                    }
                }
            }
        }

        void fileout::execute_choice_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {

            scp = scp ? scp : self;
            execute_choice_enum(stream, self, scp);

            stream << "\n" << tabformat(scp) <<
                    "struct " << type_str(self) << "";
            stream << " : " << "public BOOST_ASN_CHOICE_STRUCT(" << type_str(self) << "_enum) {\n";


            execute_typedef_decl_seqof(stream, self, scp);
            execute_declare_hpp(stream, self);
            execute_typedef_seqof(stream, self, scp);
            execute_predefineds_hpp(stream, self);

            execute_ctor(stream, self, scp);

            execute_member(stream, self, scp);

            execute_archive_meth_hpp(stream, scp);

            stream << "\n" << tabformat(scp) << "}; ";
            stream << "\n ";
        }

        void fileout::execute_choice_cpp(std::ofstream& stream, typeassignment_entity_ptr self) {

            execute_predefineds_cpp(stream, self);

            //execute_ctor(stream, self, scp);
            execute_declare_cpp(stream, self);

            execute_archive_meth_cpp(stream, self);
            stream << "\n ";
        }

        void fileout::execute_choice_enum(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            stream << "\n" << tabformat(scp) <<
                    "enum " << type_str(self) << "_enum {";
            stream << "\n" << tabformat(scp, 1) <<
                    type_str(self) << "_null = 0, ";
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                    tagmarker_type mkr = (*it)->as_typeassigment()->as_named()->marker();
                    if ((mkr == mk_none) || (mkr == mk_default) || (mkr == mk_optional))
                        stream << "\n" << tabformat(scp, 1) <<
                        choice_enum_str(self, (*it)) << ",";
                }
            }
            stream << "}; ";
            stream << "\n ";
        }

        void fileout::execute_seqset_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {

            scp = scp ? scp : self;
            stream << "\n" << tabformat(scp) <<
                    "struct " << type_str(self) << "{\n";

            execute_typedef_decl_seqof(stream, self, scp);
            execute_declare_hpp(stream, self);
            execute_typedef_seqof(stream, self, scp);
            execute_predefineds_hpp(stream, self);

            execute_ctor(stream, self, scp);

            execute_member(stream, self, scp);

            execute_archive_meth_hpp(stream, scp);

            stream << "\n" << tabformat(scp) << "};";
            stream << "\n ";
        }

        void fileout::execute_seqset_cpp(std::ofstream& stream, typeassignment_entity_ptr self) {

            execute_predefineds_cpp(stream, self);

            //execute_ctor(stream, self, scp);
            execute_declare_cpp(stream, self);

            execute_archive_meth_cpp(stream, self);

            stream << "\n ";
        }

        void fileout::execute_ctor(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            if ((self) && (self->type())) {
                switch (self->type()->builtin()) {
                    case t_CHOICE:
                    {
                        stream << "\n";
                        stream << "\n" << tabformat(scp, 1) << type_str(self) << "()";
                        stream << " : " << " BOOST_ASN_CHOICE_STRUCT(" << type_str(self) << "_enum) () {}";

                        stream << "\n ";
                        break;
                    }
                    case t_SET:
                    case t_SEQUENCE:
                    {
                        stream << "\n";
                        stream << "\n" << tabformat(scp, 1) << type_str(self) << "()";
                        std::string tmpmbr = "";
                        for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                            typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                            if ((tpas) && (tpas->as_named())) {
                                namedtypeassignment_entity_ptr named = tpas->as_named();
                                if (named->marker() == mk_none) {
                                    if (tmpmbr.empty())
                                        tmpmbr = " : " + nameconvert(named->name()) + "()";
                                    else
                                        tmpmbr = tmpmbr + ", " + nameconvert(named->name()) + "()";
                                }
                            }
                        }
                        stream << tmpmbr << " {} \n ";
                        break;
                    }
                    default:
                    {
                    }
                }
            }
        }

        void fileout::execute_seqsetof_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            if (self && (self->type())) {
                if ((self->type()->isstruct_of()) && (!self->childs().empty())) {
                    typeassignment_entity_ptr cpas = self->childs().front()->as_typeassigment();
                    if (cpas && (cpas->type())) {
                        if (cpas->type()->isstruct_of()) {
                            execute_seqsetof_hpp(stream, cpas, scp);
                        } else if (cpas->type()->isstruct()) {
                            execute_declare_struct_hpp(stream, cpas, scp);
                        }
                    }
                }
            }
        }

        void fileout::execute_seqsetof_cpp(std::ofstream& stream, typeassignment_entity_ptr self) {
            if (self && (self->type())) {
                if ((self->type()->isstruct_of()) && (!self->childs().empty())) {
                    typeassignment_entity_ptr cpas = self->childs().front()->as_typeassigment();
                    if (cpas && (cpas->type())) {
                        if (cpas->type()->isstruct_of()) {
                            execute_seqsetof_cpp(stream, cpas);
                        } else if (cpas->type()->isstruct()) {
                            execute_declare_struct_cpp(stream, cpas);
                        }
                    }
                }
            }
        }

        void fileout::execute_archive_meth_hpp(std::ofstream& stream, basic_entity_ptr scp) {
            stream << "\n\n" << tabformat(scp, 1) << "BOOST_ASN_ARCHIVE_FUNC;";
        }

        void fileout::execute_archive_meth_cpp(std::ofstream& stream, typeassignment_entity_ptr self) {
            switch (self->type()->builtin()) {
                case t_CHOICE: stream << "\n";
                    stream << struct_meth_str(self, "boost::asn1::x690::output_coder");
                    stream << "{";
                    execute_archive_ber_choice_cho(stream, self);
                    stream << struct_meth_str(self, "boost::asn1::x690::input_coder");
                    stream << "{";
                    execute_archive_ber_choice_chi(stream, self);
                    break;
                case t_SET:
                case t_SEQUENCE: stream << "\n";

                    stream << struct_meth_str(self, "boost::asn1::x690::output_coder");
                    stream << "{";
                    execute_archive_ber_seqset(stream, self);
                    stream << struct_meth_str(self, "boost::asn1::x690::input_coder");
                    stream << "{";
                    execute_archive_ber_seqset(stream, self);

                    break;
                default:
                {
                }
            }
        }

        void fileout::execute_archive_ber_seqset(std::ofstream& stream, typeassignment_entity_ptr self) {
            basic_entity_ptr scp;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if ((tpas) && (tpas->as_named())) {
                    namedtypeassignment_entity_ptr named = tpas->as_named();
                    tagmarker_type mkr = named->marker();
                    if (named->type()) {
                        if ((mkr == mk_none) || (mkr == mk_default) || (mkr == mk_optional))
                            execute_archive_ber_member(stream, named);
                    } else if (mkr == mk_extention)
                        stream << "\n" << tabformat(scp, 3) << "BOOST_ASN_EXTENTION" << ";";
                }
                if ((*it)->as_extention())
                    stream << "\n" << tabformat(scp, 3) << "BOOST_ASN_EXTENTION" << ";";
            }
            stream << "\n";
            stream << tabformat(scp, 2) << "}";
            stream << "\n";
        }

        void fileout::execute_archive_ber_member(std::ofstream& stream, namedtypeassignment_entity_ptr self) {
            basic_entity_ptr scp;
            if (self->type()) {
                stream << "\n";
                stream << tabformat(scp, 3) << archive_member_ber_str(self, nameconvert(self->name())) << ";";
            }
        }

        void fileout::execute_archive_ber_choice_chi(std::ofstream& stream, typeassignment_entity_ptr self) {
            basic_entity_ptr scp;
            stream << "\n" << tabformat(scp, 3) <<
                    "int __tag_id__ =arch.test_id();";
            stream << "\n" << tabformat(scp, 3) <<
                    "switch(arch.test_class()){";

            execute_archive_ber_member_chi(stream, self, tcl_universal, false);
            execute_archive_ber_member_chi(stream, self, tcl_application, false);
            execute_archive_ber_member_chi(stream, self, tcl_context, false);
            execute_archive_ber_member_chi(stream, self, tcl_private, false);
            execute_archive_ber_member_chi(stream, self, tcl_universal, true);
            stream << "\n" << tabformat(scp, 3) << "}";
            stream << "\n";
            stream << tabformat(scp, 2) << "}";
            stream << "\n";
        }

        void fileout::execute_archive_ber_choice_cho(std::ofstream& stream, typeassignment_entity_ptr self) {
            basic_entity_ptr scp;
            stream << "\n" << tabformat(scp, 3) <<
                    "switch(type()){";
            execute_archive_ber_member_cho(stream, self);
            stream << "\n" << tabformat(scp, 3) << "}";
            stream << "\n";
            stream << tabformat(scp, 2) << "}";
            stream << "\n";
        }

        void fileout::execute_archive_ber_member_chi(std::ofstream& stream, typeassignment_entity_ptr self, tagclass_type cls, bool notag) {
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
                            if (named->type()->tag()) {
                                if (cls == named->type()->tag()->_class()) {
                                    stream << "\n" << tabformat(scp, 6) << "case ";
                                    stream << tagged_str(named->type()->tag()) << ":  { if (";
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

        void fileout::execute_archive_ber_member_cho(std::ofstream& stream, typeassignment_entity_ptr self) {
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

        std::size_t fileout::registrate_struct_choice(std::ofstream& stream, basic_entity_ptr self) {
            std::size_t cnt = 0;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type()) && (tpas->type()->isstructure()) && (tpas->is_cpp_expressed())) {
                    if (tpas->type()->builtin() == t_CHOICE) {
                        stream << "\n" << "BOOST_ASN_CHOICE_REGESTRATE(";
                        stream << fulltype_str(tpas, true);
                        stream << ")";
                        cnt++;
                    }
                    cnt += registrate_struct_choice(stream, tpas);
                }
            }
            return cnt;
        }

        std::size_t fileout::registrate_struct_set(std::ofstream& stream, basic_entity_ptr self) {
            std::size_t cnt = 0;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type()) && (tpas->type()->isstructure()) && (tpas->is_cpp_expressed())) {
                    if (tpas->type()->builtin() == t_SET) {
                        stream << "\n" << "BOOST_ASN_SET_REGESTRATE(";
                        stream << fulltype_str(tpas, true);
                        stream << ")";
                        cnt++;
                    }
                    cnt += registrate_struct_set(stream, tpas);
                }
            }
            return cnt;
        }

        std::size_t fileout::execute_struct_meth_hpp(std::ofstream& stream, basic_entity_ptr self) {
            std::size_t cnt = 0;
            basic_entity_ptr scp;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type()) && (tpas->type()->isstructure()) && (tpas->is_cpp_expressed())) {
                    if (tpas->type()->isstruct()) {
                        stream << struct_meth_str(tpas, "boost::asn1::x690::output_coder") << ";";
                        stream << struct_meth_str(tpas, "boost::asn1::x690::input_coder") << ";";
                        cnt++;
                    }
                    cnt += execute_struct_meth_hpp(stream, tpas);
                }
            }
            return cnt;
        }




    }
}