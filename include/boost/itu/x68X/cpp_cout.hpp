//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1_SEM_CPPCOUT_IMPLEMENTATIUON_H_
#define	_ITU_ASN1_SEM_CPPCOUT_IMPLEMENTATIUON_H_


#include <boost/itu/x68X/semantics.hpp>
#include <fstream>


namespace x680 {

    namespace cpp {

        std::string nameconvert(std::string name);
        std::string tabformat(assignment_entity_ptr self = assignment_entity_ptr(), const std::string& tab = "    ");
        std::string headerlock(std::string name);
        std::string bottomlock(std::string name);

        bool dir_exists(const std::string& path);
        bool dir_create(const std::string& path, const std::string& outdir);
        //std::ofstream open(const std::string& path, const std::string& name);

        class fileout {

        public:

            fileout(global_entity_ptr glb, const std::string& path, const std::string& outdir = "out")
            : path_(path), outdir_(outdir), global_(glb) {
            }

            virtual ~fileout() {
            }

            void execute();

        private:

            void execute_import(std::ofstream& stream, import_entity_ptr self);
            void execute_module(module_entity_ptr self);

            std::string path_;
            std::string outdir_;
            global_entity_ptr global_;


        };

    }

}

#endif	

