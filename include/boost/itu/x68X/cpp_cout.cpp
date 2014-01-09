//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/cpp_cout.hpp>



namespace x680 {

    namespace cpp {



        const std::string FHHEADER = "#include <boost/itu/asn1/asnbase.hpp>\n\n#ifdef _MSC_VER\n#pragma warning(push)\n#pragma warning(disable: 4065)\n#endif\n\n";
        const std::string FHBOTTOM = "\n\n#endif";

        inline std::string nameconvert(std::string name) {
            boost::algorithm::replace_all(name, "-", "_");
            return name;
        }

        std::string tabformat(assignment_entity_ptr self = assignment_entity_ptr(), const std::string& tab = "  ") {
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

        inline std::string headerlock(std::string name) {
            name = nameconvert(name);
            boost::algorithm::to_upper(name);
            name = "___" + name;
            return "#ifndef " + name + "\n" + "#define " + name + "\n\n" + FHHEADER + "\n";
        }

        inline std::string bottomlock(std::string name) {
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

        void fileout::execute_import(std::ofstream& fsh, import_entity_ptr self) {
            if (self->scope())
                fsh << "\n  // import   from  " << nameconvert(self->name());
            else
                fsh << "\n";
            if (self->objectid())
                fsh << "" << self->objectid();
            fsh << "\n";
            fsh << "\n";
            for (import_vector::iterator it = self->import().begin(); it != self->import().end(); ++it) {
                fsh << tabformat() << "using " << nameconvert(self->name())
                        << "::" << nameconvert(*it) << "\n";
            }
            fsh << "\n";
        }

        void fileout::execute_module(module_entity_ptr self) {
            std::string newpath = path_ + "\\" + self->name() + ".hpp";
            std::ofstream fsh(newpath.c_str(), std::ofstream::out | std::ofstream::trunc);
            fsh << headerlock(self->name());
            fsh << "\n";

            for (basic_entity_vector::iterator it = self->imports().begin(); it != self->imports().end(); ++it)
                if ((*it)->as_import())
                    fsh << "#include \"" << nameconvert((*it)->as_import()->name()) << ".hpp\"\n";

            fsh << "\n";

            fsh << "namespace " + nameconvert(self->name()) + " {\n";

            fsh << "\n";

            for (basic_entity_vector::iterator it = self->imports().begin(); it != self->imports().end(); ++it)
                if ((*it)->as_import())
                    execute_import(fsh, (*it)->as_import());

            fsh << "\n";

            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->type()->isstruct()))
                    fsh << tabformat((*it)->as_typeassigment()) << "struct " << nameconvert((*it)->name()) + "; " << " \n";
            }

            fsh << "\n";
            for (basic_entity_vector::iterator it = self->childs().begin(); it != self->childs().end(); ++it) {
                if (((*it)->as_typeassigment()) && ((*it)->as_typeassigment()->type()->isrefferrence()))
                    fsh << tabformat((*it)->as_typeassigment()) << "typedef " <<
                    nameconvert((*it)->name()) << " " <<
                    nameconvert((*it)->as_typeassigment()->type()->reff()->name()) <<
                    "; " << " \n";
            }
            fsh << "\n} ";
            fsh << bottomlock(self->name());
        }

    }
}