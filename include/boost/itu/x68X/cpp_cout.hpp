//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1_SEM_CPPCOUT_IMPLEMENTATIUON_H_
#define	_ITU_ASN1_SEM_CPPCOUT_IMPLEMENTATIUON_H_


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
        std::string value_bool_str(value_atom_ptr self);
        std::string value_real_str(value_atom_ptr self);
        std::string value_bs_str(value_atom_ptr self);
        std::string value_enum_str(type_atom_ptr tp, value_atom_ptr self);
        bool value_oid_str(value_atom_ptr self, std::vector<std::string>& rslt);
        std::string valueassmnt_str(valueassignment_entity_ptr self);
        std::string valueassmnt_str(type_atom_ptr val, value_atom_ptr vl, const std::string& nm = "");
        std::string nameconvert(std::string name);
        std::string tabformat(basic_entity_ptr selft = basic_entity_ptr(), std::size_t delt = 0, const std::string& tab = "    ");
        std::string member_marker_str(const std::string& str, tagmarker_type self, const std::string& dflt="" , bool simple = false);
        std::string seqof_str(typeassignment_entity_ptr self, const std::string& name);
        std::string choice_enum_str(typeassignment_entity_ptr self, basic_entity_ptr sub);
        std::string tagged_str(tagged_ptr self);
        std::string tagged_class_str(tagged_ptr self);
        std::string archive_member_ber_str(namedtypeassignment_entity_ptr self, const std::string& name);
        std::string struct_meth_str(typeassignment_entity_ptr self, const std::string& tp);
        std::string nested_init_str(type_atom_ptr self, const std::string& nm);

        bool expressed_import(module_entity_ptr self, const std::string& name);
        member_vect parse_membervct(const member_vect& vct, bool obligate);
        member_vect parse_default_membervct(const member_vect& vct);

        class fileout {

        public:

            fileout(global_entity_ptr glb, const std::string& path, const std::string& outdir = "out", bool revrs = false, bool nohldr = false);
            virtual ~fileout();

            void execute();

        private:

            void execute_module(module_entity_ptr self);

            void execute_predeclare(std::ofstream& stream, basic_entity_ptr self);
            std::size_t load_predeclare(basic_entity_ptr self, structdeclare_vect& rslt);
            std::size_t load_structof_predeclare(basic_entity_ptr self, structdeclare_vect& rslt);
            std::size_t load_struct_predeclare(basic_entity_ptr self, structdeclare_vect& rslt);

            void execute_typedef_native_global(std::ofstream& stream, basic_entity_ptr self);
            void execute_typedef_native_local(std::ofstream& stream, basic_entity_ptr self);
            void load_typedef_simple_native(declare_vect& vct, basic_entity_ptr self, bool tagged);
            void load_typedef_structof_native(declare_vect& vct, basic_entity_ptr self);
            bool load_typedef_structof_native_impl(declare_vect& vct, typeassignment_entity_ptr self);

            void execute_typedef(std::ofstream& stream, const declare_vect& vct, bool remote = false, basic_entity_ptr scp = basic_entity_ptr());
            void load_typedef(declare_vect& vct, basic_entity_ptr self);
            void load_typedef_ref(declare_vect& vct, basic_entity_ptr self);
            void load_typedef_structof(declare_vect& vct, basic_entity_ptr self);
            bool load_typedef_structof_impl(declare_vect& vct, typeassignment_entity_ptr self);

            void load_member(member_vect& vct, typeassignment_entity_ptr self);

            void headerlock(std::ofstream& stream, std::string name);
            void bottomlock(std::ofstream& stream, std::string name);

            void execute_include(std::ofstream& stream, std::string name);
            void execute_includes_hpp(std::ofstream& stream, module_entity_ptr self);

            void execute_standart_type(std::ofstream& stream, module_entity_ptr self);

            void execute_start_ns(std::ofstream& stream, module_entity_ptr self);
            void execute_stop_ns(std::ofstream& stream, module_entity_ptr self);

            void execute_import(std::ofstream& stream, module_entity_ptr mod, import_entity_ptr self);
            void execute_imports(std::ofstream& stream, module_entity_ptr self);


            void execute_typeassignment_hpp(std::ofstream& stream, typeassignment_entity_ptr tpas);
            void execute_typeassignment_cpp(std::ofstream& stream, typeassignment_entity_ptr tpas);

            void execute_predefined_hpp(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_predefined_cpp(std::ofstream& stream, typeassignment_entity_ptr self, typeassignment_entity_ptr ansec);

            void execute_predefineds_hpp(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            void execute_predefineds_cpp(std::ofstream& stream, basic_entity_ptr self);

            void execute_predefined_int_hpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self);
            void execute_predefined_int_cpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self, typeassignment_entity_ptr ansec);

            void execute_predefined_bs_hpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self);
            void execute_predefined_bs_cpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self, typeassignment_entity_ptr ansec);

            void execute_valueassignment_hpp(std::ofstream& stream, valueassignment_entity_ptr self);
            void execute_valueassignment_cpp(std::ofstream& stream, valueassignment_entity_ptr self);
            void execute_defaultassignment_cpp(std::ofstream& stream, namedtypeassignment_entity_ptr self, typeassignment_entity_ptr ansec);


            void execute_access_member_hpp(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_access_member_cpp(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_member(std::ofstream& stream, typeassignment_entity_ptr self);

            void execute_declare_hpp(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_declare_cpp(std::ofstream& stream, typeassignment_entity_ptr self);

            void execute_declare_struct_hpp(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_declare_struct_cpp(std::ofstream& stream, typeassignment_entity_ptr self);

            void execute_choice_hpp(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_choice_enum(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_choice_cpp(std::ofstream& stream, typeassignment_entity_ptr self);

            void execute_struct_hpp(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_struct_cpp(std::ofstream& stream, typeassignment_entity_ptr self);

            void execute_ctor_hpp(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_ctor_cpp(std::ofstream& stream, typeassignment_entity_ptr self);
            
            void execute_default_hpp(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_default_cpp(std::ofstream& stream, typeassignment_entity_ptr self);

            void execute_structof_hpp(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_structof_cpp(std::ofstream& stream, typeassignment_entity_ptr self);

            void execute_archive_meth_hpp(std::ofstream& stream, basic_entity_ptr scp = basic_entity_ptr());
            void execute_archive_meth_cpp(std::ofstream& stream, typeassignment_entity_ptr self);

            void execute_archive_ber_struct(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_archive_ber_member(std::ofstream& stream, namedtypeassignment_entity_ptr self);
            void execute_archive_ber_choice_chi(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_archive_ber_choice_cho(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_archive_ber_member_chi(std::ofstream& stream, typeassignment_entity_ptr self, tagclass_type cls, bool notag = false);
            void execute_archive_ber_member_cho(std::ofstream& stream, typeassignment_entity_ptr self);

            std::size_t registrate_struct_choice(std::ofstream& stream, basic_entity_ptr self);
            std::size_t registrate_struct_set(std::ofstream& stream, basic_entity_ptr self);
            std::size_t execute_struct_meth_hpp(std::ofstream& stream, basic_entity_ptr self);

            template<typename Iter>
            void execute_typeassignments_hpp(std::ofstream& stream, Iter beg, Iter end) {
                for (Iter it = beg; it != end; ++it) {
                    typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                    if (tpas && (tpas->type()) && (tpas->is_cpp_expressed()))
                        execute_typeassignment_hpp(stream, tpas);
                }
            }

            template<typename Iter>
            void execute_valueassignments_hpp(std::ofstream& stream, Iter beg, Iter end) {
                stream << "\n";
                for (Iter it = beg; it != end; ++it) {
                    valueassignment_entity_ptr vpas = (*it)->as_valueassigment();
                    if (vpas)
                        execute_valueassignment_hpp(stream, vpas);
                }
                stream << "\n";
            }

            template<typename Iter>
            void execute_assignments_cpp(std::ofstream& stream, Iter beg, Iter end) {
                for (Iter it = beg; it != end; ++it) {
                    typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                    if (tpas && (tpas->type()) && (tpas->is_cpp_expressed()))
                        execute_typeassignment_cpp(stream, tpas);
                    valueassignment_entity_ptr vpas = (*it)->as_valueassigment();
                    if (vpas) {
                        execute_valueassignment_cpp(stream, vpas);
                    }
                }
            }

            std::string path_;
            std::string outdir_;
            global_entity_ptr global_;
            bool reverse_;
            bool noholder_;


        };

    }

}

#endif	

