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
        typedef std::vector<declare_atom> declare_vect;


        bool dir_exists(const std::string& path);
        bool dir_create(const std::string& path, const std::string& outdir);

        std::string correct_name(std::string vl);
        std::string type_str(typeassignment_entity_ptr self, bool native = false);
        std::string fulltype_str(basic_entity_ptr self, bool withns = false);
        std::string fromtype_str(typeassignment_entity_ptr self);
        bool fromtype_remote(typeassignment_entity_ptr self);
        declare_vect::iterator find_remote_reff(declare_vect& vct, const std::string& nm, declare_vect::iterator from);   
        void resolve_remote_reff(declare_vect& vct);
        bool sort_reff(declare_vect& vct);
        std::string fromtype_str(type_atom_ptr self);
        value_atom_ptr value_skip_defined(value_atom_ptr self);
        std::string value_int_str(value_atom_ptr self);
        bool value_oid_str(value_atom_ptr self, std::vector<std::string>& rslt);
        std::string nameconvert(std::string name);
        std::string tabformat(basic_entity_ptr selft = basic_entity_ptr(), std::size_t delt = 0, const std::string& tab = "    ");
        std::string member_marker_str(const std::string& str, tagmarker_type self, bool simple = false);
        std::string seqof_str(typeassignment_entity_ptr self, const std::string& name);
        std::string choice_enum_str(typeassignment_entity_ptr self, basic_entity_ptr sub);
        std::string tagged_str(tagged_ptr self);
        std::string tagged_class_str(tagged_ptr self);
        std::string archive_member_ber_str(namedtypeassignment_entity_ptr self, const std::string& name);
        std::string struct_meth_str(typeassignment_entity_ptr self, const std::string& tp);

        bool expressed_import(module_entity_ptr self, const std::string& name);

        class fileout {

        public:

            fileout(global_entity_ptr glb, const std::string& path, const std::string& outdir = "out", bool revrs = false, bool nohldr = false);
            virtual ~fileout();

            void execute();

        private:

            void execute_module(module_entity_ptr self);
            
            void loaddecl(declare_vect& vct, basic_entity_ptr self);
            void execute_typedef_reff(declare_vect& vct, basic_entity_ptr self);
            void execute_typedef_seqof(declare_vect& vct, basic_entity_ptr self);
            bool execute_typedef_seqof_impl(declare_vect& vct,  typeassignment_entity_ptr self);     
            void execute_typedef(std::ofstream& stream, const declare_vect& vct, bool remote =false,  basic_entity_ptr scp =  basic_entity_ptr());
            
            void headerlock(std::ofstream& stream, std::string name);
            void bottomlock(std::ofstream& stream, std::string name);

            void execute_include(std::ofstream& stream, std::string name);
            void execute_includes_hpp(std::ofstream& stream, module_entity_ptr self);

            void execute_standart_type(std::ofstream& stream, module_entity_ptr self);

            void execute_start_ns(std::ofstream& stream, module_entity_ptr self);
            void execute_stop_ns(std::ofstream& stream, module_entity_ptr self);

            void execute_import(std::ofstream& stream, module_entity_ptr mod, import_entity_ptr self);
            void execute_imports(std::ofstream& stream, module_entity_ptr self);

            void execute_struct_predeclare(std::ofstream& stream, basic_entity_ptr self);
            void execute_typedef_native(std::ofstream& stream, basic_entity_ptr self, bool tagged);
            void execute_typedef_reff(std::ofstream& stream, basic_entity_ptr self, bool tagged);            
            void execute_typedef_struct(std::ofstream& stream, basic_entity_ptr self);
            void execute_typedef_decl_seqof(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            void execute_typedef_seqof(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr(), bool endl = true);
            void execute_typedef_seqof_native(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp);
            bool execute_typedef_seqof_native_impl(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp =  basic_entity_ptr());
            
    
            void execute_typeassignment_hpp(std::ofstream& stream, basic_entity_ptr self, typeassignment_entity_ptr tpas, basic_entity_ptr scp = basic_entity_ptr());
            void execute_typeassignment_cpp(std::ofstream& stream, typeassignment_entity_ptr tpas);

            void execute_predefined_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            void execute_predefined_cpp(std::ofstream& stream, typeassignment_entity_ptr self,  typeassignment_entity_ptr ansec);
            
            void execute_predefineds_hpp(std::ofstream& stream, basic_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            void execute_predefineds_cpp(std::ofstream& stream, basic_entity_ptr self);            
            
            void execute_predefined_int_hpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            void execute_predefined_int_cpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self,  typeassignment_entity_ptr ansec);          
            
            void execute_predefined_bs_hpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            void execute_predefined_bs_cpp(std::ofstream& stream, predefined_ptr prdf, typeassignment_entity_ptr self, typeassignment_entity_ptr ansec);

            void execute_valueassignment_hpp(std::ofstream& stream, valueassignment_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            void execute_valueassignment_cpp(std::ofstream& stream, valueassignment_entity_ptr self);


            void execute_member(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            
            void execute_declare_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
             void execute_declare_cpp(std::ofstream& stream, typeassignment_entity_ptr self);
            
            void execute_declare_struct_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            void execute_declare_struct_cpp(std::ofstream& stream, typeassignment_entity_ptr self);
            
            void execute_choice_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());           
            void execute_choice_enum(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());            
            void execute_choice_cpp(std::ofstream& stream, typeassignment_entity_ptr self); 
            
            void execute_seqset_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            void execute_seqset_cpp(std::ofstream& stream, typeassignment_entity_ptr self);
            
            void execute_ctor(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp);
            
            void execute_seqsetof_hpp(std::ofstream& stream, typeassignment_entity_ptr self, basic_entity_ptr scp = basic_entity_ptr());
            void execute_seqsetof_cpp(std::ofstream& stream, typeassignment_entity_ptr self);

            void execute_archive_meth_hpp(std::ofstream& stream,  basic_entity_ptr scp = basic_entity_ptr());
            void execute_archive_meth_cpp(std::ofstream& stream, typeassignment_entity_ptr self);

            void execute_archive_ber_seqset(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_archive_ber_member(std::ofstream& stream, namedtypeassignment_entity_ptr self);
            void execute_archive_ber_choice_chi(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_archive_ber_choice_cho(std::ofstream& stream, typeassignment_entity_ptr self);
            void execute_archive_ber_member_chi(std::ofstream& stream, typeassignment_entity_ptr self, tagclass_type cls, bool notag = false);
            void execute_archive_ber_member_cho(std::ofstream& stream, typeassignment_entity_ptr self);

            std::size_t registrate_struct_choice(std::ofstream& stream, basic_entity_ptr self);
            std::size_t registrate_struct_set(std::ofstream& stream, basic_entity_ptr self);
            std::size_t execute_struct_meth_hpp(std::ofstream& stream, basic_entity_ptr self);
            

            template<typename Iter>
            void execute_assignments_hpp(std::ofstream& stream, basic_entity_ptr self, Iter beg, Iter end, basic_entity_ptr scp = basic_entity_ptr()) {
                scp = scp ? scp : self;
                for (Iter it = beg; it != end; ++it) {
                    typeassignment_entity_ptr tpas = (*it)->as_typeassigment();
                    if (tpas && (tpas->type()) && (tpas->is_cpp_expressed()))
                        execute_typeassignment_hpp(stream, self, tpas, scp);
                    valueassignment_entity_ptr vpas = (*it)->as_valueassigment();
                    if (vpas) {
                        execute_valueassignment_hpp(stream, vpas);
                    }
                }
            }
            
            template<typename Iter>
            void execute_assignments_cpp(std::ofstream& stream, basic_entity_ptr self, Iter beg, Iter end, basic_entity_ptr scp = basic_entity_ptr()) {
                scp = scp ? scp : self;
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

