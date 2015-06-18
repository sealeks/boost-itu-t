//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_T_SEM_HTTPCOUT_IMPLEMENTATIUON_H_
#define	_ITU_T_SEM_HTTPCOUT_IMPLEMENTATIUON_H_


#include <boost/itu/x68X/semantics.hpp>
#include <boost/itu/x68X/parser.hpp>
#include <fstream>


namespace x680 {
    namespace http {




        //////////////////////////////////////////////////////
        //  base_moduleout
        //////////////////////////////////////////////////////        

        class base_moduleout : public base_options {

        public:

            base_moduleout(const char* path, module_entity_ptr mod, const compile_option& opt);
            virtual ~base_moduleout();

            virtual void execute() = 0;

        protected:

            module_entity_ptr module_;
            std::ofstream stream;
        };


        typedef boost::shared_ptr<base_moduleout> moduleout_ptr;






        //////////////////////////////////////////////////////
        //  base_moduleout
        //////////////////////////////////////////////////////

        class httpout : public base_options {

        public:

            httpout(global_entity_ptr glb, const compile_option& opt) :
            base_options(opt), global_(glb) {
            };
            virtual ~httpout();

            void execute();

        protected:

            template< typename T>
            moduleout_ptr generate(const std::string& path, module_entity_ptr modl, const std::string add, const std::string ext = ".http") {
                std::string filepath = modl->name() + add + "." + ext;
                boost::filesystem::path p(path.c_str());
                boost::filesystem::path f(filepath.c_str());
                boost::filesystem::path r = p / f;
                return moduleout_ptr(new T(r.generic_string().c_str(), modl, opt_));
            }

            global_entity_ptr global_;
        };




        //////////////////////////////////////////////////////
        //  moduleout
        //////////////////////////////////////////////////////

        class moduleout : public base_moduleout {

        public:

            moduleout(const char* path, module_entity_ptr mod, const compile_option& opt) :
            base_moduleout(path, mod, opt) {
            };

            //virtual void execute(){};

        protected:

            virtual void execute_typeassignment(typeassignment_entity_ptr self) = 0;
            virtual void execute_valueassignment(valueassignment_entity_ptr self) = 0;
            virtual void execute_valuesetassignment(valuesetassignment_entity_ptr self) = 0;
            virtual void execute_classassignment(classassignment_entity_ptr tpas) = 0;
            virtual void execute_objectassignment(objectassignment_entity_ptr self) = 0;
            virtual void execute_objectsetassignment(objectsetassignment_entity_ptr self) = 0;

            template<typename Iter>
            void execute_assignments(Iter beg, Iter end) {
                for (Iter it = beg; it != end; ++it) {
                    if ((*it)->as_typeassigment())
                        execute_typeassignment((*it)->as_typeassigment());
                    else if ((*it)->as_valueassigment())
                        execute_valueassignment((*it)->as_valueassigment());
                    else if ((*it)->as_valuesetassigment())
                        execute_valuesetassignment((*it)->as_valuesetassigment());
                    else if ((*it)->as_classassigment())
                        execute_classassignment((*it)->as_classassigment());
                    else if ((*it)->as_objectassigment())
                        execute_objectassignment((*it)->as_objectassigment());
                    else if ((*it)->as_objectsetassigment())
                        execute_objectsetassignment((*it)->as_objectsetassigment());
                    execute_assignments((*it)->childs().begin(), (*it)->childs().end());
                }
            }

        };




        //////////////////////////////////////////////////////
        //  mainhttp_out
        //////////////////////////////////////////////////////

        class mainhttp_out : public moduleout {

        public:

            mainhttp_out(const char* path, module_entity_ptr mod, const compile_option& opt) :
            moduleout(path, mod, opt) {
            };

            virtual void execute();

        protected:

            virtual void execute_typeassignment(typeassignment_entity_ptr self);
            virtual void execute_valueassignment(valueassignment_entity_ptr self);
            virtual void execute_valuesetassignment(valuesetassignment_entity_ptr self);
            virtual void execute_classassignment(classassignment_entity_ptr tpas);
            virtual void execute_objectassignment(objectassignment_entity_ptr self);
            virtual void execute_objectsetassignment(objectsetassignment_entity_ptr self);

        };




    }

}

#endif	

