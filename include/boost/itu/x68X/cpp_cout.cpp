//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/cpp_cout.hpp>



namespace x680 {
    namespace cpp {

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


        const std::string FHHEADER = "#include <boost/itu/asn1/asnbase.hpp>\n\n#ifdef _MSC_VER\n#pragma warning(push)\n#pragma warning(disable: 4065)\n#endif\n\n";
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

        std::string nameconvert(std::string name) {
            boost::algorithm::replace_all(name, "-", "_");
            return name;
        }

        std::string tabformat(basic_entity_ptr selft, std::size_t delt, const std::string& tab) {
            assignment_entity_ptr self = selft ? selft->as_assigment() : assignment_entity_ptr();
            std::string rslt = tab;
            if (self) {
                std::size_t inten = self->level() + delt;
                if (inten > 0) inten--;
                while (inten) {
                    rslt += tab;
                    inten--;
                }
            }
            return rslt;
        }

        std::string builtin_str(defined_type tp) {
            switch (tp) {
                case t_BOOLEAN: return "boolean";
                case t_INTEGER: return "integer";
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

        std::string type_str(typeassignment_entity_ptr self) {
            if (self->type()) {
                switch (self->type()->builtin()) {
                    case t_Reference: return nameconvert(self->name());
                    case t_CHOICE:
                    case t_SEQUENCE:
                    case t_SET:
                    case t_SEQUENCE_OF:
                    case t_SET_OF:
                    {
                        typeassignment_entity_ptr ppas = self->scope() ?
                                self->scope()->as_typeassigment() : typeassignment_entity_ptr();
                        if (ppas && (ppas->type())&& (ppas->type()->isstruct_of()))
                            return type_str(ppas)+(ppas->type()->builtin() == t_SEQUENCE_OF ? "_seqof" : "_setof");
                        return nameconvert(self->type()->islocaldeclare() ? (self->name() + "_type") : self->name());
                    }
                    default:
                    {
                        return nameconvert(self->name());
                    }
                }
            }
            return "";
        }

        std::string fromtype_str(typeassignment_entity_ptr self) {
            if (self->type()) {
                switch (self->type()->builtin()) {
                    case t_Reference: return nameconvert(self->type()->reff()->name());
                    case t_CHOICE:
                    case t_SEQUENCE:
                    case t_SET:
                    case t_SEQUENCE_OF:
                    case t_SET_OF: return type_str(self);
                    default:
                    {
                        return builtin_str(self->type()->builtin());
                    }
                }
            }
            return "";
        }

        std::string member_marker_str(const std::string& str, tagmarker_type self) {
            switch (self) {
                case mk_default:
                case mk_optional:
                {
                    return "boost::shared_ptr<" + str + ">";
                }
                default:
                {
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

        fileout::fileout(global_entity_ptr glb, const std::string& path, const std::string& outdir)
        : path_(path), outdir_(outdir), global_(glb) {
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
            execute_struct_predeclare(stream, self);
            execute_typedef_simple(stream, self);
            execute_typedef_reff(stream, self);
            execute_typedef_decl_seqof(stream, self, self);
            execute_typedef_seqof(stream, self, self);

            execute_stop_ns(stream, self);


            execute_includes(stream, self);


            execute_start_ns(stream, self);

            execute_imports(stream, self);
            execute_struct(stream, self);

            execute_stop_ns(stream, self);


            bottomlock(stream, self->name());
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
            stream << "#include \"" << nameconvert(name) << ".hpp\"\n";
        }

        void fileout::execute_includes(std::ofstream& stream, module_entity_ptr self) {
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

        void fileout::execute_import(std::ofstream& stream, import_entity_ptr self) {
            if (self->scope())
                stream << "\n  // import   from  " << self->name();
            else
                stream << "\n";
            stream << "\n";
            stream << "\n";
            for (import_vector::iterator it = self->import().begin(); it != self->import().end(); ++it) {
                stream << tabformat() << "using " << nameconvert(self->name())
                        << "::" << nameconvert(*it) << "\n";
            }
            stream << "\n";
        }

        void fileout::execute_imports(std::ofstream& stream, module_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->imports().begin(); it != self->imports().end(); ++it)
                if ((*it)->as_import())
                    execute_import(stream, (*it)->as_import());
        }

        void fileout::execute_struct_predeclare(std::ofstream& stream, basic_entity_ptr self) {
            for (basic_entity_vector::const_iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type())) {
                    if ((tpas->type()) && (tpas->type()->isstruct()))
                        stream << tabformat() << "struct " << type_str(tpas) + "; " << " \n";
                }
            }
            if (!self->childs().empty())
                stream << "\n";
        }

        void fileout::execute_typedef_simple(std::ofstream& stream, basic_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type())) {
                    if (tpas->type()->issimplerefferrence())
                        stream << tabformat() << "typedef " <<
                        fromtype_str(tpas) << " " <<
                        type_str(tpas) <<
                        "; " << " \n";
                }
            }
            if (!self->childs().empty())
                stream << "\n";
        }

        void fileout::execute_typedef_reff(std::ofstream& stream, basic_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type())) {
                    if (tpas->type()->isrefferrence())
                        stream << tabformat() << "typedef " <<
                        fromtype_str(tpas) << " " <<
                        type_str(tpas) <<
                        "; " << " \n";
                }
            }
            if (!self->childs().empty())
                stream << "\n";
        }

        void fileout::execute_typedef_decl_seqof(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp) {
            typeassignment_entity_ptr selft = self->as_typeassigment();
            scp = scp ? scp : self;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type())) {
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

        void fileout::execute_typedef_seqof(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp, bool endl) {
            typeassignment_entity_ptr selft = self->as_typeassigment();
            scp = scp ? scp : self;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type())) {
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

        void fileout::execute_struct(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type())) {
                    switch (tpas->type()->builtin()) {
                        case t_CHOICE:
                            stream << "\n";
                            stream << tabformat(tpas) << "// choice " << tpas->name();
                            execute_choice(stream, tpas);
                            break;
                        case t_SEQUENCE:
                            stream << "\n";
                            stream << tabformat(tpas) << "// sequence " << tpas->name();
                            execute_seqset(stream, tpas);
                            break;
                        case t_SET:
                            stream << "\n";
                            stream << tabformat(tpas) << "// set " << tpas->name();
                            execute_seqset(stream, tpas);
                            break;
                        case t_SEQUENCE_OF:
                            //stream << "\n";
                            //stream << tabformat(tpas) << "// sequence " << tpas->name();
                            execute_seqsetof(stream, tpas);
                            break;
                        case t_SET_OF:
                            //stream << "\n";
                            //stream << tabformat(tpas) << "// set " << tpas->name();
                            execute_seqsetof(stream, tpas);
                            break;
                        default:
                        {
                            if ((tpas) && (tpas->type()->predefined())) {
                                execute_predefined(stream, tpas);
                            }
                        }
                    }
                }
            }
        }

        void fileout::execute_predefined(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            if (self->type()) {
                predefined_ptr predef = self->type()->predefined();
                switch (self->type()->root_builtin()) {
                    case t_INTEGER:
                    {
                        stream << "\n";
                        for (basic_entity_vector::const_iterator it = predef->values().begin(); it != predef->values().end(); ++it) {
                            valueassignment_entity_ptr vlass = (*it)->as_valueassigment();
                            if (vlass) {
                                stream << tabformat(scp) << "const " << nameconvert(self->name()) << " "
                                        << nameconvert(vlass->name()) << " = "
                                        << vlass->value()->as_number()->value() << ";\n";
                            }
                        }
                        break;
                    }
                    default:
                    {
                    }
                        // t_BIT_STRING,
                        // t_OCTET_STRING
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
                        stream << "\n";
                        if (!ischoice) {
                            stream << tabformat(scp, 1) <<
                                    member_marker_str(fromtype_str(named), named->marker()) <<
                                    " " << nameconvert(named->name()) << ";";
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

        void fileout::execute_declare(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if ((tpas) && (tpas->type()))
                    execute_declare_struct(stream, tpas, scp);
            }
        }

        void fileout::execute_declare_struct(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {
            scp = scp ? scp : self;
            if ((self) && (self->type())) {
                switch (self->type()->builtin()) {
                    case t_CHOICE: stream << "\n";
                        execute_choice(stream, self, scp);
                        break;
                    case t_SET:
                    case t_SEQUENCE: stream << "\n";
                        execute_seqset(stream, self, scp);
                        break;
                    default:
                    {
                    }
                }
            }
        }

        void fileout::execute_choice(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {

            scp = scp ? scp : self;
            execute_choice_enum(stream, self, scp);

            stream << "\n" << tabformat(scp) <<
                    "struct " << type_str(self) << "";
            stream << " : " << "public BOOST_ASN_CHOICE_STRUCT(" << type_str(self) << "_enum) {";

            stream << "\n";
            execute_declare(stream, self, scp);
            stream << "\n";
            execute_typedef_seqof(stream, self, scp);

            stream << "\n" << tabformat(scp, 1) <<
                    type_str(self) << "()";
            stream << " : " << " BOOST_ASN_CHOICE_STRUCT(" << type_str(self) << "_enum) () {}";

            stream << "\n ";

            execute_member(stream, self, scp);

            stream << "} ";
            stream << "\n ";
        }

        void fileout::execute_choice_enum(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {

            scp = scp ? scp : self;
            stream << "\n" << tabformat(scp) <<
                    "enum " << type_str(self) << "_enum {";
            stream << "\n" << tabformat(scp, 1) <<
                    type_str(self) << "_null = 0, ";
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                stream << "\n" << tabformat(scp, 1) <<
                        type_str(self) << "_" << nameconvert(((*it)->name())) << ",";
            }
            stream << "} ";
            stream << "\n ";
        }

        void fileout::execute_seqset(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {

            scp = scp ? scp : self;
            stream << "\n" << tabformat(scp) <<
                    "struct " << type_str(self) << "{";

            stream << "\n";
            execute_declare(stream, self, scp);
            stream << "\n";
            execute_typedef_seqof(stream, self, scp);

            stream << "\n" << tabformat(scp, 1) <<
                    "" << type_str(self) << "() {}";

            stream << "\n ";
            execute_member(stream, self, scp);

            stream << "} ";
            stream << "\n ";
        }

        void fileout::execute_seqsetof(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp) {

            scp = scp ? scp : self;
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                if (tpas && (tpas->type())) {
                    if ((tpas->type()->isstruct_of()) && (!tpas->childs().empty())) {
                        typeassignment_entity_ptr cpas = tpas->childs().front()->as_typeassigment();
                        if (cpas && (cpas->type())) {
                            if (cpas->type()->isstruct_of()) {
                                execute_seqsetof(stream, tpas, scp);
                            } else if (cpas->type()->isstruct()) {
                                execute_declare_struct(stream, cpas, scp);
                            }
                        }
                    }
                }
            }
        }





    }
}