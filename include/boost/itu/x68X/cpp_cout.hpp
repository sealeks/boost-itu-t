//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_T_SEM_CPPCOUT_IMPLEMENTATIUON_H_
#define	_ITU_T_SEM_CPPCOUT_IMPLEMENTATIUON_H_


#include <boost/itu/x68X/semantics.hpp>
#include <fstream>


namespace x680 {
    namespace cpp {

        struct declare_atom;
        struct member_atom;
        typedef std::vector<declare_atom> declare_vect;
        typedef std::vector<std::string> structdeclare_vect;
        typedef std::vector<member_atom> member_vect;


        bool dir_exists(const std::string& path);
        bool dir_create(const std::string& path, const std::string& outdir);

        std::string correct_name(std::string vl);
        std::string nameupper(std::string name);
        std::string namelower(std::string name);
        std::string type_str(typeassignment_entity_ptr self, bool native = false);
        std::string fulltype_str(basic_entity_ptr self, bool withns = false);
        std::string fullpathtype_str(typeassignment_entity_ptr self, typeassignment_entity_ptr root, std::string tp);
        std::string fromtype_str(typeassignment_entity_ptr self);
        std::string fromtype_str(type_atom_ptr self);
        bool fromtype_remote(typeassignment_entity_ptr self);
        declare_vect::iterator find_remote_reff(declare_vect& vct, const std::string& nm, declare_vect::iterator from);
        void resolve_remote_reff(declare_vect& vct);
        bool sort_reff(declare_vect& vct);
        bool default_supported(typeassignment_entity_ptr self);
        value_atom_ptr value_skip_defined(value_atom_ptr self);
        std::string value_int_str(value_atom_ptr self);
        std::string value_null_str(value_atom_ptr self);
        std::string value_bool_str(value_atom_ptr self);
        std::string value_real_str(value_atom_ptr self);
        std::string value_reff_str(defined_value_atom_ptr self);
        std::string value_bs_str(value_atom_ptr self);
        std::string value_os_str(value_atom_ptr self);
        std::string value_chars8_str(value_atom_ptr self, bool cantuple);
        std::string value_chars16_str(value_atom_ptr self);
        std::string value_utfchar_str(const quadruple& self);
        std::string value_utfchars_str(value_atom_ptr self);
        std::string value_enum_str(type_atom_ptr tp, value_atom_ptr self);
        bool value_oid_str(value_atom_ptr self, std::vector<std::string>& rslt);
        std::string valueassmnt_str(valueassignment_entity_ptr self);
        std::string valueassmnt_str(type_atom_ptr val, value_atom_ptr vl, const std::string& nm = "", bool ext = false);
        std::string value_struct_str(value_atom_ptr vl, type_atom_ptr tp);
        std::string nameconvert(std::string name);
        std::string argumentname(std::string name);
        std::string tabformat(basic_entity_ptr selft = basic_entity_ptr(), std::size_t delt = 0, const std::string& tab = "    ");
        std::string member_marker_str(const std::string& str, tagmarker_type self, const std::string& dflt = "", bool simple = false);
        std::string seqof_str(typeassignment_entity_ptr self, const std::string& name);
        std::string choice_enum_str(typeassignment_entity_ptr self, basic_entity_ptr sub);
        std::string tagged_str(tagged_ptr self);
        std::string tagged_class_str(tagged_ptr self);
        std::string archive_member_ber_str(namedtypeassignment_entity_ptr self, const std::string& name, bool afterext = false);
        std::string archive_member_per_str(namedtypeassignment_entity_ptr self, const std::string& name, bool afterext = false);
        std::string struct_meth_str(typeassignment_entity_ptr self, const std::string& tp);
        std::string nested_init_str(type_atom_ptr self, const std::string& nm, bool ext = false);

        bool expressed_import(module_entity_ptr self, const std::string& name);
        member_vect parse_membervct(const member_vect& vct, bool obligate);
        member_vect parse_default_membervct(const member_vect& vct);



        //////////////////////////////////////////////////////

        struct compile_option {

            compile_option(const std::string& pth, const std::string& outdr = "out", bool rev = false, bool nohld = false) :
            path(pth), outdir(outdr), revrs(rev), nohldr(nohld) {
            }
            std::string path;
            std::string outdir;
            bool revrs;
            bool nohldr;
        };




        //////////////////////////////////////////////////////
        //  base_moduleout
        //////////////////////////////////////////////////////

        class base_moduleout {

        public:

            base_moduleout(const char* path, module_entity_ptr mod, const compile_option& opt);
            virtual ~base_moduleout();

            virtual void execute() = 0;

            bool option_no_holder() const {
                return opt_.nohldr;
            }

            bool option_reverse_decl() const {
                return opt_.revrs;
            }            

        protected:

            module_entity_ptr module_;
            compile_option opt_;
            std::ofstream stream;
        };


        typedef boost::shared_ptr<base_moduleout> moduleout_ptr;






        //////////////////////////////////////////////////////
        //  base_moduleout
        //////////////////////////////////////////////////////

        class cppout {

        public:

            cppout(global_entity_ptr glb, const std::string& path, const std::string& outdir = "out", bool revrs = false, bool nohldr = false);

            cppout(global_entity_ptr glb, const compile_option& opt) : global_(glb), opt_(opt) {
            };
            virtual ~cppout();

            void execute();

        protected:

            template< typename T>
            moduleout_ptr generate(module_entity_ptr modl, const std::string add, const std::string ext = ".cpp") {
                std::string fullpath = opt_.path + "\\" + modl->name() + add + "." + ext;
                boost::filesystem::path p(fullpath.c_str());
                return moduleout_ptr(new T(p.generic_string().c_str(), modl, opt_));
            }

            global_entity_ptr global_;
            compile_option opt_;

        };




        //////////////////////////////////////////////////////
        //  moduleout
        //////////////////////////////////////////////////////

        class moduleout : public base_moduleout {

        public:

            moduleout(const char* path, module_entity_ptr mod, const compile_option& opt) :
            base_moduleout(path, mod, opt) {
            };

            virtual void execute() = 0;

        protected:

            std::size_t load_predeclare(basic_entity_ptr self, structdeclare_vect& rslt);
            std::size_t load_structof_predeclare(basic_entity_ptr self, structdeclare_vect& rslt);
            std::size_t load_struct_predeclare(basic_entity_ptr self, structdeclare_vect& rslt);


            void load_typedef_simple_native(declare_vect& vct, basic_entity_ptr self, bool tagged);
            void load_typedef_structof_native(declare_vect& vct, basic_entity_ptr self);
            bool load_typedef_structof_native_impl(declare_vect& vct, typeassignment_entity_ptr self);


            void load_typedef(declare_vect& vct, basic_entity_ptr self);
            void load_typedef_ref(declare_vect& vct, basic_entity_ptr self);
            void load_typedef_structof(declare_vect& vct, basic_entity_ptr self);
            bool load_typedef_structof_impl(declare_vect& vct, typeassignment_entity_ptr self);

            void load_member(member_vect& vct, typeassignment_entity_ptr self);

            void headerlock();
            void bottomlock();

            void execute_include(std::string name);
            void execute_includes_hpp();

            void execute_standart_type();

            void execute_start_ns();
            void execute_stop_ns();

            void execute_import(import_entity_ptr self);
            void execute_imports();

            void mark_constraints(typeassignment_entity_ptr self);
            void execute_member(typeassignment_entity_ptr self);

            virtual void execute_typeassignment(typeassignment_entity_ptr tpas) = 0;
            virtual void execute_valueassignment(valueassignment_entity_ptr self) = 0;

            template<typename Iter>
            void execute_assignments(std::ofstream& stream, Iter beg, Iter end) {
                for (Iter it = beg; it != end; ++it) {
                    typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                    if (tpas && (tpas->type()) && (tpas->is_cpp_expressed()))
                        execute_typeassignment(tpas);
                    valueassignment_entity_ptr vpas = (*it)->as_valueassigment();
                    if (vpas) {
                        execute_valueassignment(vpas);
                    }
                }
            }

            template<typename Iter>
            void execute_typeassignments(Iter beg, Iter end) {
                for (Iter it = beg; it != end; ++it) {
                    typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                    if (tpas && (tpas->type()) && (tpas->is_cpp_expressed()))
                        execute_typeassignment(tpas);
                }
            }

            template<typename Iter>
            void execute_valueassignments(Iter beg, Iter end) {
                stream << "\n";
                for (Iter it = beg; it != end; ++it) {
                    valueassignment_entity_ptr vpas = (*it)->as_valueassigment();
                    if (vpas)
                        execute_valueassignment(vpas);
                }
                stream << "\n";
            }






        };







        //////////////////////////////////////////////////////
        //  mainhpp_out
        //////////////////////////////////////////////////////

        class mainhpp_out : public moduleout {

        public:

            mainhpp_out(const char* path, module_entity_ptr mod, const compile_option& opt) :
            moduleout(path, mod, opt) {
            };

            virtual void execute();

        protected:


            void execute_predeclare(basic_entity_ptr self);
            void execute_typedef(const declare_vect& vct, bool remote = false, basic_entity_ptr scp = basic_entity_ptr());
            void execute_typedef_native_global(basic_entity_ptr self);
            void execute_typedef_native_local(basic_entity_ptr self);

            virtual void execute_valueassignment(valueassignment_entity_ptr self);
            virtual void execute_typeassignment(typeassignment_entity_ptr tpas);


            void execute_declare_hpp(typeassignment_entity_ptr self);
            void execute_declare_struct_hpp(typeassignment_entity_ptr self);
            void execute_choice_hpp(typeassignment_entity_ptr self);
            void execute_choice_enum(typeassignment_entity_ptr self);
            void execute_struct_hpp(typeassignment_entity_ptr self);
            void execute_predefined_hpp(typeassignment_entity_ptr self);
            void execute_predefineds_hpp(basic_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            void execute_predefined_int_hpp(predefined_ptr prdf, typeassignment_entity_ptr self);
            void execute_predefined_bs_hpp(predefined_ptr prdf, typeassignment_entity_ptr self);
            void execute_access_member_hpp(typeassignment_entity_ptr self);
            void execute_structof_hpp(typeassignment_entity_ptr self);
            void execute_ctor_hpp(typeassignment_entity_ptr self);
            void execute_default_hpp(typeassignment_entity_ptr self);
            void execute_archive_meth_hpp(basic_entity_ptr scp = basic_entity_ptr());
            std::size_t registrate_struct_choice(basic_entity_ptr self);
            std::size_t registrate_struct_set(basic_entity_ptr self);
            std::size_t execute_struct_meth_hpp(basic_entity_ptr self, const std::string& ctp);


        };




        //////////////////////////////////////////////////////
        //  mainhpp_out
        //////////////////////////////////////////////////////

        class maincpp_out : public moduleout {

        public:

            maincpp_out(const char* path, module_entity_ptr mod, const compile_option& opt) :
            moduleout(path, mod, opt) {
            };

            virtual void execute();

        protected:


            virtual void execute_valueassignment(valueassignment_entity_ptr self);
            virtual void execute_typeassignment(typeassignment_entity_ptr tpas);

            void execute_structof_cpp(typeassignment_entity_ptr self);
            void execute_predefined_cpp(typeassignment_entity_ptr self, typeassignment_entity_ptr ansec);
            void execute_predefineds_cpp(basic_entity_ptr self);
            void execute_predefined_int_cpp(predefined_ptr prdf, typeassignment_entity_ptr self, typeassignment_entity_ptr ansec);
            void execute_predefined_bs_cpp(predefined_ptr prdf, typeassignment_entity_ptr self, typeassignment_entity_ptr ansec);
            void execute_defaultassignment_cpp(namedtypeassignment_entity_ptr self, typeassignment_entity_ptr ansec);
            void execute_access_member_cpp(typeassignment_entity_ptr self);
            void execute_declare_cpp(typeassignment_entity_ptr self);
            void execute_declare_struct_cpp(typeassignment_entity_ptr self);
            void execute_choice_cpp(typeassignment_entity_ptr self);
            void execute_struct_cpp(typeassignment_entity_ptr self);
            void execute_ctor_cpp(typeassignment_entity_ptr self);
            void execute_default_cpp(typeassignment_entity_ptr self);

        };






















        /*class fileout {


         protected:


             // ber
             void execute_archive_ber_struct(std::ofstream& stream, typeassignment_entity_ptr self);
             void execute_archive_ber_member(std::ofstream& stream, namedtypeassignment_entity_ptr self, bool afterext = false);
             void execute_archive_ber_choice_chi(std::ofstream& stream, typeassignment_entity_ptr self);
             void execute_archive_ber_choice_cho(std::ofstream& stream, typeassignment_entity_ptr self);
             void execute_archive_ber_member_chi(std::ofstream& stream, typeassignment_entity_ptr self, tagclass_type cls, bool notag = false);
             void execute_archive_ber_member_cho(std::ofstream& stream, typeassignment_entity_ptr self);

             // per
             void execute_archive_per_struct_in(std::ofstream& stream, typeassignment_entity_ptr self);
             void execute_archive_per_struct_out(std::ofstream& stream, typeassignment_entity_ptr self);
             void execute_archive_per_member(std::ofstream& stream, namedtypeassignment_entity_ptr self, bool afterext = false);
             void execute_archive_per_choice_chi(std::ofstream& stream, typeassignment_entity_ptr self);
             void execute_archive_per_choice_cho(std::ofstream& stream, typeassignment_entity_ptr self);
             void execute_archive_per_member_chi(std::ofstream& stream, typeassignment_entity_ptr self, tagclass_type cls, bool notag = false);
             void execute_archive_per_member_cho(std::ofstream& stream, typeassignment_entity_ptr self);



         };*/

    }

}

#endif	

