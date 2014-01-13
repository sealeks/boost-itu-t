//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/cpp_cout.hpp>



namespace x680 {

    namespace cpp {



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

        std::string tabformat(assignment_entity_ptr self, std::size_t delt, const std::string& tab) {
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

        std::string headerlock(std::string name) {
            name = nameconvert(name);
            boost::algorithm::to_upper(name);
            name = "___" + name;
            return "#ifndef " + name + "\n" + "#define " + name + "\n\n" + FHHEADER + "\n";
        }

        std::string bottomlock(std::string name) {
            name = nameconvert(name);
            boost::algorithm::to_upper(name);
            name = "___" + name;
            return FHBOTTOM + "  /*" + name + " */\n";
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
                    //case t_SEQUENCE: return "null_type";
                    //case t_SEQUENCE_OF: return "null_type";
                    //case t_SET: return "null_type";
                    //case t_SET_OF: return "null_type";
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
                    //case t_CHOICE: return "null_type";
                    //case t_Selection: return "null_type";
                    //case t_Instance_Of: return "null_type";
                    //case t_RELATIVE_OID_IRI: return "null_type";
                case t_OID_IRI: return "null_type";
                case t_ANY: return "any_type";
                case t_ClassField: return "any_type";
                    //case t_TypeFromObject: return "null_type";
                    //case t_ValueSetFromObjects: return "null_type";
                default:
                {
                }
            }
            return "";
        }
        
        
       std::string type_str(typeassignment_entity_ptr self){
           if (self->type()) {
                switch (self->type()->builtin()) {
                    case t_Reference: return nameconvert(self->type()->reff()->name());
                    case t_CHOICE: return nameconvert(self->type()->islocaldeclare() ? (self->name() + "_type") : self->name());
                    case t_SEQUENCE: return nameconvert(self->type()->islocaldeclare() ? (self->name() + "_type") : self->name());
                    case t_SET: return nameconvert(self->type()->islocaldeclare() ? (self->name() + "_type") : self->name());                    
                    default:{
                        return builtin_str(self->type()->builtin());
                    }       
                }
           }
           return "";
       }         


        namespace fsnsp = boost::filesystem;

        bool dir_exists(const std::string& path) {
            fsnsp::path p(path.c_str());
            return ((fsnsp::exists(p)) && (fsnsp::is_directory(p)));
        }

        bool dir_create(const std::string& path, const std::string& outdir) {
            std::string newpath = path + "\\" + outdir;
            if (!dir_exists(path))
                return fsnsp::create_directory(fsnsp::path(newpath.c_str()));
            return true;
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
            std::ofstream stream(newpath.c_str(), std::ofstream::out | std::ofstream::trunc);
            stream << headerlock(self->name());
            stream << "\n";



            stream << "namespace " + nameconvert(self->name()) + " {\n";

            stream << "\n";
            stream << MNDCL;
            stream << "\n";


            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->type()->isstruct()))
                    stream << tabformat() << "struct " << nameconvert((*it)->name()) + "; " << " \n";
            }

            stream << "\n";
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->type()->issimplerefferrence()))
                    stream << tabformat() << "typedef " <<
                    type_str((*it)->as_typeassigment()) << " " <<
                    nameconvert((*it)->name()) <<
                    "; " << " \n";
            }

            stream << "\n";
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->type()->isrefferrence()))
                    stream << tabformat() << "typedef " <<
                    nameconvert((*it)->as_typeassigment()->type()->reff()->name()) << " " <<
                    nameconvert((*it)->name()) <<
                    "; " << " \n";
            }

            stream << "\n} ";
            stream << "\n";

            for (basic_entity_vector::iterator it = self->imports().begin(); it != self->imports().end(); ++it)
                if ((*it)->as_import())
                    stream << "#include \"" << nameconvert((*it)->as_import()->name()) << ".hpp\"\n";

            stream << "\n";
            stream << "namespace " + nameconvert(self->name()) + " {\n";
            stream << "\n";


            for (basic_entity_vector::iterator it = self->imports().begin(); it != self->imports().end(); ++it)
                if ((*it)->as_import())
                    execute_import(stream, (*it)->as_import());

            execute_struct(stream, self);


            stream << "\n";
            stream << "\n} ";


            stream << bottomlock(self->name());
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

        void fileout::execute_struct(std::ofstream& stream, basic_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (((*it)->as_typeassigment())) {
                    switch ((*it)->as_typeassigment()->type()->builtin()) {
                        case t_CHOICE:
                            stream << "\n";
                            stream << tabformat((*it)->as_typeassigment()) << "// choice " << (*it)->as_typeassigment()->name();
                            execute_choice(stream, (*it)->as_typeassigment());
                            break;
                        case t_SEQUENCE:
                            stream << "\n";
                            stream << tabformat((*it)->as_typeassigment()) << "// sequence " << (*it)->as_typeassigment()->name();
                            execute_sequence(stream, (*it)->as_typeassigment());
                            break;
                        case t_SET:
                            stream << "\n";
                            stream << tabformat((*it)->as_typeassigment()) << "// set " << (*it)->as_typeassigment()->name();
                            execute_set(stream, (*it)->as_typeassigment());
                            break;
                        default:
                        {
                        }
                    }
                }
            }
        }

        void fileout::execute_member_marker(std::string& str, namedtypeassignment_entity_ptr self) {
            switch (self->marker()) {
                case mk_default:
                case mk_optional:
                {
                    str = "boost::shared_ptr<" + str + ">";
                }
                default:
                {
                }
            }
        }

        void fileout::execute_member(std::ofstream& stream, typeassignment_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->as_named())) {
                    namedtypeassignment_entity_ptr named = (*it)->as_typeassigment()->as_named();
                    std::string tmp;
                    if (named->type()) {
                        stream << "\n";
                        tmp=  type_str(named);
                        execute_member_marker(tmp, named);
                        stream << tabformat(self, 1) << tmp << " " << nameconvert(named->name()) << ";";
                    }
                }
            }
        }

        void fileout::execute_declare(std::ofstream& stream, typeassignment_entity_ptr self) {
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (((*it)->as_typeassigment())) {
                    typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                    if (tpas->type()) {
                        switch (tpas->type()->builtin()) {
                            case t_CHOICE: stream << "\n";
                                execute_choice(stream, tpas);
                                break;
                            case t_SEQUENCE: stream << "\n";
                                execute_sequence(stream, tpas);
                                break;
                            case t_SET: stream << "\n";
                                execute_set(stream, tpas);
                                break;
                            default:
                            {
                            }
                        }
                    }
                }
            }
        }

        void fileout::execute_choice(std::ofstream& stream, typeassignment_entity_ptr self) {

            stream << "\n" << tabformat(self) << "enum " << nameconvert(self->name()) << "_enum {";
            stream << "\n" << tabformat(self, 1) << nameconvert((self->name())) << "_null = 0, ";
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                stream << "\n" << tabformat(self, 1) << nameconvert((self->name())) << "_" << nameconvert(((*it)->name())) << ",";
            }
            stream << "} ";
            stream << "\n ";

            stream << "\n" << tabformat(self) << "struct " << type_str(self) << "";
            stream << " : " << "public BOOST_ASN_CHOICE_STRUCT(" << nameconvert(self->name()) << "_enum) {";

            stream << "\n ";
            execute_declare(stream, self);

            stream << "\n" << tabformat(self, 1) << type_str(self) << "()";
            stream << " : " << " BOOST_ASN_CHOICE_STRUCT(" << nameconvert(self->name()) << "_enum) () {}";

            stream << "\n ";

            execute_member(stream, self);

            stream << "} ";
            stream << "\n ";
        }

        void fileout::execute_sequence(std::ofstream& stream, typeassignment_entity_ptr self) {
            stream << "\n" << tabformat(self) << "struct " << type_str(self) << "{";

            stream << "\n ";
            execute_declare(stream, self);

            stream << "\n ";
            stream << "\n" << tabformat(self, 1) << "" << type_str(self) << "() {}";     
            
            stream << "\n ";            
            execute_member(stream, self);

            stream << "} ";
            stream << "\n ";
        }

        void fileout::execute_set(std::ofstream& stream, typeassignment_entity_ptr self) {
            stream << "\n" << tabformat(self) << "struct " << type_str(self) << "{";

            stream << "\n ";
            execute_declare(stream, self);
            
            stream << "\n ";
            stream << "\n" << tabformat(self, 1) << "" << type_str(self) << "() {}";            
            
            stream << "\n ";
            execute_member(stream, self);

            stream << "} ";
            stream << "\n ";
        }



    }
}