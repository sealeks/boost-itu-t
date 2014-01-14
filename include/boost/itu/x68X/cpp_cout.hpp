//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1_SEM_CPPCOUT_IMPLEMENTATIUON_H_
#define	_ITU_ASN1_SEM_CPPCOUT_IMPLEMENTATIUON_H_


#include <boost/itu/x68X/semantics.hpp>
#include <fstream>


namespace x680 {

    namespace cpp {


        bool dir_exists(const std::string& path);
        bool dir_create(const std::string& path, const std::string& outdir);

        std::string nameconvert(std::string name);
        std::string tabformat(assignment_entity_ptr self = assignment_entity_ptr(), std::size_t delt = 0, const std::string& tab = "    ");

        class fileout {

        public:

            fileout(global_entity_ptr glb, const std::string& path, const std::string& outdir = "out");
            virtual ~fileout();

            void execute();

        private:

            void execute_module(module_entity_ptr self);
            void headerlock(std::ofstream& stream, std::string name);
            void bottomlock(std::ofstream& stream, std::string name);
            void execute_include(std::ofstream& stream, std::string name);
            void execute_includes(std::ofstream& stream, module_entity_ptr self);
            void execute_standart_type(std::ofstream& stream, module_entity_ptr self);
            void execute_start_ns(std::ofstream& stream, module_entity_ptr self);
            void execute_stop_ns(std::ofstream& stream, module_entity_ptr self);
            void execute_import(std::ofstream& stream, import_entity_ptr self);
            void execute_imports(std::ofstream& stream, module_entity_ptr self);
            void execute_struct_predeclare(std::ofstream& stream, basic_entity_ptr self);
            void execute_typedef_simple(std::ofstream& stream, basic_entity_ptr self);
            void execute_typedef_reff(std::ofstream& stream, basic_entity_ptr self);
            void execute_struct(std::ofstream& stream, basic_entity_ptr self);
            void execute_predefined(std::ofstream& stream, typeassignment_entity_ptr self);


            void execute_member(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_member_marker(std::string& str, namedtypeassignment_entity_ptr self);
            void execute_declare(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_choice(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_sequence(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_set(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_set_of(std::ofstream& stream, typeassignment_entity_ptr self);

            std::string path_;
            std::string outdir_;
            global_entity_ptr global_;


        };

    }

}

#endif	

