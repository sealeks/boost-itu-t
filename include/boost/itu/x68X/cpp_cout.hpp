//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_T_SEM_CPPCOUT_IMPLEMENTATIUON_H_
#define	_ITU_T_SEM_CPPCOUT_IMPLEMENTATIUON_H_


#include <boost/itu/x68X/semantics.hpp>
#include <boost/itu/x68X/parser.hpp>
#include <fstream>


namespace x680 {
    namespace cpp {

        struct declare_atom;
        struct member_atom;
        typedef std::vector<declare_atom> declare_vect;
        typedef std::vector<std::string> structdeclare_vect;
        typedef std::vector<member_atom> member_vect;

        std::string correct_name(std::string vl);
        std::string nameupper(std::string name);
        std::string namelower(std::string name);
        std::string type_str(typeassignment_entity_ptr self, bool native = false);
        std::string fulltype_str(basic_entity_ptr self, bool withns = false);
        std::string fulltype_str(type_atom_ptr self, bool withns = false);             
        std::string fulltype_str_ext(basic_entity_ptr self, bool withns = false, const std::string& delim = "::");
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
        std::string value_chars8_str(value_atom_ptr self, bool cantuple);
        std::string value_chars16_str(value_atom_ptr self);
        std::string value_utfchar_str(const quadruple& self);
        std::string value_utfchars_str(value_atom_ptr self);
        std::string value_enum_str(type_atom_ptr tp, value_atom_ptr self);
        bool value_oid_str(value_atom_ptr self, std::vector<std::string>& rslt);
        bool value_octets_str(value_atom_ptr self, std::vector<std::string>& rslt);
        bool value_bits_str(value_atom_ptr self, std::vector<std::string>& rslt, std::size_t& sz);
        std::string value_bits_str(value_atom_ptr self);
        std::string print_initializer(const std::vector<std::string> vl);
        std::string valueassmnt_str(type_atom_ptr val, value_atom_ptr vl, const std::string& nm = "");
        std::string valueassmnt_str_ext(type_atom_ptr tp, value_atom_ptr vl, const std::string& nm = "");
        std::string value_structure_str(type_atom_ptr tp, value_atom_ptr vl,  std::size_t lev = 0);        
        std::string value_struct_str(type_atom_ptr tp, value_atom_ptr vl,  std::size_t lev = 0);
        std::string value_struct_of_str(type_atom_ptr tp, value_atom_ptr vl,  std::size_t lev = 0);
        std::string value_choice_str(type_atom_ptr tp, value_atom_ptr vl,  std::size_t lev = 0);        

        std::string nameconvert(std::string name);
        std::string argumentname(std::string name);
        std::string tabformat(basic_entity_ptr selft = basic_entity_ptr(), std::size_t delt = 0, const std::string& tab = "    ");
        std::string member_marker_str(const std::string& str, tagmarker_type self, const std::string& dflt = "", bool simple = false);
        std::string struct_of_str(bool igsequence);
        std::string seqof_str(typeassignment_entity_ptr self, const std::string& name);
        std::string choice_enum_str(typeassignment_entity_ptr self, basic_entity_ptr sub);
        std::string tagged_str(tagged_ptr self);
        std::string tagged_str(canonical_tag_ptr self);
        std::string tagged_class_str(tagged_ptr self);
        std::string tagged_class_str(canonical_tag_ptr self);
        std::string struct_meth_str(typeassignment_entity_ptr self, const std::string& tp);
        std::string nested_init_str(type_atom_ptr self, const std::string& nm);

        bool expressed_import(module_entity_ptr self, const std::string& name);
        member_vect parse_membervct(const member_vect& vct, bool obligate);
        member_vect parse_default_membervct(const member_vect& vct);
        void load_member(member_vect& vct, typeassignment_entity_ptr self);        






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

        class cppout : public base_options {

        public:

            cppout(global_entity_ptr glb, const compile_option& opt) :
            base_options(opt), global_(glb) {
            };
            virtual ~cppout();

            void execute();

        protected:

            template< typename T>
            moduleout_ptr generate(const std::string& path, module_entity_ptr modl, const std::string add, const std::string ext = ".cpp") {
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

            void print_name_type(typeassignment_entity_ptr tpas, basic_entity_ptr scp = basic_entity_ptr());

            virtual void execute_typeassignment(typeassignment_entity_ptr tpas) = 0;
            virtual void execute_valueassignment(valueassignment_entity_ptr self) = 0;

            template<typename Iter>
            void execute_assignments(std::ofstream& stream, Iter beg, Iter end) {
                for (Iter it = beg; it != end; ++it) {
                    typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                    if (tpas && (tpas->type()) && (tpas->is_cpp_expressed()))
                        execute_typeassignment(tpas);
                    if (valueassignment_entity_ptr vpas = (*it)->as_valueassigment())
                        execute_valueassignment(vpas);
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
                for (Iter it = beg; it != end; ++it)
                    if (valueassignment_entity_ptr vpas = (*it)->as_valueassigment())
                        execute_valueassignment(vpas);
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
            void execute_valueassignment_ext(valueassignment_entity_ptr self);
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
            std::size_t execute_struct_cout_meth(basic_entity_ptr self);

            template<typename Iter>
            void execute_valueassignments_ext(Iter beg, Iter end) {
                stream << "\n";
                for (Iter it = beg; it != end; ++it)
                    if (valueassignment_entity_ptr vpas = (*it)->as_valueassigment())
                        execute_valueassignment_ext(vpas);
                stream << "\n";
            }


        };





        //////////////////////////////////////////////////////
        //  base_arch_out
        //////////////////////////////////////////////////////

        class base_arch_out : public moduleout {

        public:

            base_arch_out(const char* path, module_entity_ptr mod, const compile_option& opt) :
            moduleout(path, mod, opt) {
            };

        protected:


            virtual void execute_archive_meth_cpp(typeassignment_entity_ptr self, const std::string& ctp);

            virtual void execute_archive_choice_output(typeassignment_entity_ptr self) = 0;
            virtual void execute_archive_choice_input(typeassignment_entity_ptr self) = 0;
            virtual void execute_archive_struct_output(typeassignment_entity_ptr self) = 0;
            virtual void execute_archive_struct_input(typeassignment_entity_ptr self) = 0;

        };






        //////////////////////////////////////////////////////
        //  base_ber_arch_out
        //////////////////////////////////////////////////////

        class base_ber_arch_out : public base_arch_out {

        public:

            base_ber_arch_out(const char* path, module_entity_ptr mod, const compile_option& opt) :
            base_arch_out(path, mod, opt) {
            };


        protected:


            virtual void execute_archive_choice_output(typeassignment_entity_ptr self);
            virtual void execute_archive_choice_input(typeassignment_entity_ptr self);
            virtual void execute_archive_struct_output(typeassignment_entity_ptr self);
            virtual void execute_archive_struct_input(typeassignment_entity_ptr self);

            std::string archive_member_ber_str(namedtypeassignment_entity_ptr self, const std::string& name, bool afterext = false);
            void execute_archive_member(namedtypeassignment_entity_ptr self, bool afterext);
            void execute_archive_choice_input_helper_mbr(typeassignment_entity_ptr self, tagclass_type cls, bool notag, std::size_t scpcnt = 6);
            void execute_archive_choice_input_helper(typeassignment_entity_ptr self, tagclass_type cls, bool notag);
            void execute_archive_choice_output_helper(typeassignment_entity_ptr self);

        };








        //////////////////////////////////////////////////////
        //  mainhpp_out
        //////////////////////////////////////////////////////

        class maincpp_out : public base_ber_arch_out {

        public:

            maincpp_out(const char* path, module_entity_ptr mod, const compile_option& opt) :
            base_ber_arch_out(path, mod, opt) {
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
            std::size_t execute_struct_cout_meth(basic_entity_ptr self);

        };









        //////////////////////////////////////////////////////
        //  ber_cpp_out
        //////////////////////////////////////////////////////

        class ber_cpp_out : public base_ber_arch_out {

        public:

            struct ber_helper_finder {

                static namedtypeassignment_entity_ptr check(typeassignment_entity_ptr tpas);
            };

            ber_cpp_out(const char* path, module_entity_ptr mod, const compile_option& opt) :
            base_ber_arch_out(path, mod, opt) {
            };

            virtual void execute();

        protected:

            void add_helpers(namedtypeassignment_entity_ptr tpas);

            template<typename CriteriaT>
            void find_typeassignments(basic_entity_ptr self) {
                find_typeassignments<CriteriaT>(self->childs().begin(), self->childs().end());
            }

            template<typename CriteriaT>
            void find_typeassignments(basic_entity_vector::const_iterator beg, basic_entity_vector::const_iterator end) {
                for (basic_entity_vector::const_iterator it = beg; it != end; ++it) {
                    typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                    add_helpers(CriteriaT::check(tpas));
                    if (tpas)
                        find_typeassignments<CriteriaT>(tpas);
                }
            }

            virtual void execute_valueassignment(valueassignment_entity_ptr self) {
            };

            virtual void execute_typeassignment(typeassignment_entity_ptr tpas);

        };






        //////////////////////////////////////////////////////
        //  per_cpp_out
        //////////////////////////////////////////////////////

        class per_cpp_out : public base_arch_out {

        public:

            enum per_helper_type {

                pht_none,
                pht_enumerated,
                pht_structof_int,
                pht_structof_enum,
                pht_char8_alhabet,
                pht_tuple_alhabet,
                pht_utf_alhabet
            };

            struct helper {

                helper(const std::string& nm, per_helper_type tp, typeassignment_entity_ptr ta) :
                name(nm), type(tp), ts(ta) {
                }

                std::string name;
                per_helper_type type;
                mutable typeassignment_entity_ptr ts;

                friend bool operator==(const helper& ls, const helper& rs) {
                    return ((ls.name == rs.name) && (ls.type == rs.type));
                }

                friend bool operator<(const helper& ls, const helper& rs) {
                    return (ls.type == rs.type) ? (ls.name < rs.name) : ((int) ls.type < (int) rs.type);
                }

            };

            typedef std::set<helper> helper_set;
            typedef boost::shared_ptr<helper> helper_ptr;
            typedef std::vector<helper_ptr> helper_vct;

            struct per_helper_finder {

                static helper_ptr check(typeassignment_entity_ptr tpas);
            };



            ///////////////////////////////////////////////////            

            per_cpp_out(const char* path, module_entity_ptr mod, const compile_option& opt) :
            base_arch_out(path, mod, opt) {
            };

            virtual void execute();

        protected:

            virtual void execute_valueassignment(valueassignment_entity_ptr self) {
            };

            virtual void execute_typeassignment(typeassignment_entity_ptr tpas);


            virtual void execute_archive_choice_output(typeassignment_entity_ptr self);
            virtual void execute_archive_choice_input(typeassignment_entity_ptr self);
            virtual void execute_archive_struct_output(typeassignment_entity_ptr self);
            virtual void execute_archive_struct_input(typeassignment_entity_ptr self);

            std::string archive_member_per_constr(helper_ptr hlpr, const std::string& name, tagmarker_type dfltopt,
                    size_constraints_ptr sizeconst, integer_constraints_ptr intconstr, bool alpha);
            std::string archive_member_per_str(namedtypeassignment_entity_ptr self, const std::string& name);
            void execute_archive_member(namedtypeassignment_entity_ptr self, bool opt = false, std::size_t optnum = 0, std::size_t scpnum = 0);

            template<typename CriteriaT>
            void find_typeassignments(basic_entity_ptr self) {
                find_typeassignments<CriteriaT>(self->childs().begin(), self->childs().end());
            }

            template<typename CriteriaT>
            void find_typeassignments(basic_entity_vector::const_iterator beg, basic_entity_vector::const_iterator end) {
                for (basic_entity_vector::const_iterator it = beg; it != end; ++it) {
                    typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                    add_helpers(CriteriaT::check(tpas));
                    if (tpas)
                        find_typeassignments<CriteriaT>(tpas);
                }
            }

            void add_helpers(helper_ptr hlpr);
            void print_helpers_header(helper_ptr hlpr);
            void print_enumeraded_helper(const std::string& name, predefined_ptr predef);
            void print_struct_int_helper(helper_ptr hlpr);
            void print_struct_enum_helper(helper_ptr hlpr);
            void print_struct_alphabet_helper(helper_ptr hlpr);
            void print_helper(helper_ptr hlpr);
            void print_helpers();

        private:


            helper_set helpers_chk;
            helper_vct helpers;
        };




    }

}

#endif	

