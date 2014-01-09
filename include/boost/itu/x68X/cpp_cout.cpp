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

        std::string tabformat(assignment_entity_ptr self, const std::string& tab) {
            std::string rslt = tab;
            if (self) {
                int inten = self->level();
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

        void fileout::execute_import(std::ofstream& stream, import_entity_ptr self) {
            if (self->scope())
                stream << "\n  // import   from  " << self->name();
            else
                stream << "\n";
            // if (self->objectid())
            //     stream  << "" << self->objectid();
            stream << "\n";
            stream << "\n";
            for (import_vector::iterator it = self->import().begin(); it != self->import().end(); ++it) {
                stream << tabformat() << "using " << nameconvert(self->name())
                        << "::" << nameconvert(*it) << "\n";
            }
            stream << "\n";
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

            /*for (basic_entity_vector::iterator it = self->imports().begin(); it != self->imports().end(); ++it)
                if ((*it)->as_import())
                    execute_import(stream, (*it)->as_import());

            stream << "\n";*/

            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->type()->isstruct()))
                    stream << tabformat() << "struct " << nameconvert((*it)->name()) + "; " << " \n";
            }

            stream << "\n";
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->type()->isrefferrence()))
                    stream << tabformat() << "typedef " <<
                    nameconvert((*it)->name()) << " " <<
                    nameconvert((*it)->as_typeassigment()->type()->reff()->name()) <<
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

            stream << "\n";

            stream << "\n} ";


            stream << bottomlock(self->name());
        }

    }
}