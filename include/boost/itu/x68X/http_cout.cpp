//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/http_cout.hpp>
#include <boost/itu/asn1/utf8.hpp>


namespace x680 {
    namespace http {


        namespace fsnsp = boost::filesystem;

        ////////////////////////////////////////////////////////////////////////////////////////////////////         
        //  BaseModuleOUT
        ////////////////////////////////////////////////////////////////////////////////////////////////////       

        base_moduleout::base_moduleout(const char* path, module_entity_ptr mod, const compile_option& opt)
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

        httpout::~httpout() {
        }

        void httpout::execute() {
            if (!dir_exists(option_path()))
                throw fsnsp::filesystem_error("File or directory error",
                    boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));
            std::string outpath = "";
            if (!dir_exists(option_httpoutdir())) {
                if (!dir_create(option_path(), option_httpoutdir()))
                    throw fsnsp::filesystem_error("File or directory error",
                        boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));
                boost::filesystem::path p(option_path().c_str());
                boost::filesystem::path f(option_httpoutdir().c_str());
                boost::filesystem::path r = p / f;
                outpath = r.generic_string();
            } else
                outpath = option_httpoutdir();

            for (basic_entity_vector::iterator it = global_->childs().begin(); it != global_->childs().end(); ++it) {
                if ((*it)->as_module()) {
                    moduleout_ptr http = generate<mainhttp_out>(outpath, (*it)->as_module(), "", "http");
                    http->execute();
                }
            }
        }




        //////////////////////////////////////////////////////
        //  mainhttp_out
        //////////////////////////////////////////////////////

        void mainhttp_out::execute() {

            basic_entity_ptr scp;


        }

        void mainhttp_out::execute_typeassignment(typeassignment_entity_ptr self) {
        }

        void mainhttp_out::execute_valueassignment(valueassignment_entity_ptr self) {
        }

        void mainhttp_out::execute_valuesetassignment(valuesetassignment_entity_ptr self) {
        }

        void mainhttp_out::execute_classassignment(classassignment_entity_ptr tpas) {
        }

        void mainhttp_out::execute_objectassignment(objectassignment_entity_ptr self) {
        }

        void mainhttp_out::execute_objectsetassignment(objectsetassignment_entity_ptr self) {
        }
        
    }
}
