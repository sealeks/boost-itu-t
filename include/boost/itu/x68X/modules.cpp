//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>


namespace x680 {
    namespace syntactic {

        namespace phx = boost::phoenix;

        //Modules_grammar

        void Modules_grammar::init() {


            start_rule = +ModuleDefinition >> qi::omit[ qi::eoi];



            ModuleDefinition = qi::lexeme[ modulereference_[ phx::bind(&module_name, sprt::_val, sprt::_1) ]]
                    >> -(ObjectIdentifierValue[ phx::bind(&module_oid, sprt::_val, sprt::_1) ]
                    >> -(IRIValue[ phx::bind(&module_iri, sprt::_val, sprt::_1) ]))
                    >> qi::lexeme[DEFINITIONS_ ]

                    >> -(qi::lexeme[EncodingReferenceDefault[phx::bind(&module_encoding, sprt::_val, sprt::_1)]]
                    >> qi::lexeme[INSTRUCTIONS_])

                    >> -(qi::lexeme[ TagDefault[phx::bind(&module_tags, sprt::_val, sprt::_1)]
                    >> +qi::space >> TAGS_])

                    >> -(qi::lexeme[EXTENSIBILITY_
                    >> +qi::space
                    >> IMPLIED_[ phx::bind(&module_extesibility, sprt::_val) ]])

                    >> qi::lexeme[qi::lit("::=")]
                    >> qi::lexeme[BEGIN_]
                    >> (Exports[phx::bind(&module_exports, sprt::_val, sprt::_1)]
                    | (-(qi::lexeme[qi::omit[EXPORTS_ >> +qi::space >> ALL_
                    >> *qi::space >> qi::lit(";") ]]))[phx::bind(&module_allexport, sprt::_val)])
                    >> -(Imports[phx::bind(&module_imports, sprt::_val, sprt::_1)])
                    >> -(Assignments[phx::bind(&module_assignments, sprt::_val, sprt::_1)])
                    >> END_ >> qi::lexeme[qi::omit[*comment_skip]];

            Import = SymbolList[ phx::bind(&import_add, sprt::_val, sprt::_1) ]
                    >> FROM_
                    >> modulereference_[ phx::bind(&import_name, sprt::_val, sprt::_1) ]
                    >> -(ObjectIdentifierValue[ phx::bind(&import_oid, sprt::_val, sprt::_1) ]
                    | (DefinedValue - qi::omit[(DefinedValue
                    >> (FROM_ | qi::lit(",")))])[ phx::bind(&import_defined, sprt::_val, sprt::_1) ]);


            Importsdecl = *Import;

            Imports = qi::omit[IMPORTS_]
                    >> Importsdecl
                    >> qi::omit[qi::lit(";")];

            Exports = qi::omit[EXPORTS_]
                    >> SymbolList
                    >> qi::omit[qi::lit(";")];

            SymbolList = qi::lexeme[Symbol_] % qi::omit[qi::lexeme[ lit(",")]];



            ValueOrObjectM =
                    Value[phx::bind(&unknown_vo_value, sprt::_val, sprt::_1)] | Object[phx::bind(&unknown_vo_object, sprt::_val, sprt::_1)];

            ValueOrObject =
                    ((qi::hold[Value[phx::bind(&unknown_vo_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Object[phx::bind(&unknown_vo_object, sprt::_val, sprt::_1)] >> qi::omit[';']]))
                    | ValueOrObjectM;

            ValueSetOrObjectSetM =
                    ValueSet[phx::bind(&unknown_so_valueset, sprt::_val, sprt::_1)] | ObjectSet[phx::bind(&unknown_so_objectset, sprt::_val, sprt::_1)];

            ValueSetOrObjectSet = (qi::hold[ValueSet[phx::bind(&unknown_so_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']]
                    | qi::hold[ObjectSet[phx::bind(&unknown_so_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | ValueSetOrObjectSetM;


            UnknownValObjAssignment =
                    ((qi::hold[ValueAssignment[phx::bind(&unknown_voa_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectAssignment[phx::bind(&unknown_voa_object, sprt::_val, sprt::_1)] >> qi::omit[';']]))
                    | (valuereference_[phx::bind(&unknown_voa_identifier, sprt::_val, sprt::_1)]
                    >> qi::omit[-(Parameters)]
                    >> DefinedType_[phx::bind(&unknown_voa_refference, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]
                    >> ValueOrObject]);


            UnknownValSetObjSetAssignment =
                    ((qi::hold[ValueSetTypeAssignment[phx::bind(&unknown_soa_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSetAssignment[phx::bind(&unknown_soa_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']]))
                    | (valuesetreference_[phx::bind(&unknown_soa_identifier, sprt::_val, sprt::_1)]
                    >> qi::omit[-(Parameters)]
                    >> DefinedType_[phx::bind(&unknown_soa_refference, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]
                    >> ValueSetOrObjectSet]);


            initV();
            initT();
            initVS();
            initCl();
            initClf();
            initO();
            initOS();
            initSt();
            initA();

        }

        template <typename T> inline static std::string pto_str(const T& val) {
            std::string result = "";
            try {
                result = boost::lexical_cast<std::string > (val);
            } catch (boost::bad_lexical_cast) {
                return "";
            }
            return result;
        };

        inline static std::size_t read_module_file(const std::string path, std::string& src) {

            std::ifstream ifs(path.c_str(), std::ifstream::binary);
            src.clear();
            if (ifs) {
                ifs.seekg(0, ifs.end);
                std::streamoff length = ifs.tellg();
                ifs.seekg(0, ifs.beg);
                char * buffer = new char [static_cast<std::size_t>(length)];
                ifs.read(buffer, length);
                src.insert(src.end(), buffer, buffer + length);
                delete[] buffer;
            }
            return src.size();
        }

        Modules_grammar& MainGrammar() {
            static Modules_grammar Grammar;
            return Grammar;
        }




        namespace fsnsp = boost::filesystem;

        const fsnsp::filesystem_error FILE_OR_DIRECTORY_ERROR("File or directory error",
                boost::system::error_code(boost::system::errc::io_error, boost::system::system_category()));

        int parse_fs(const std::string& path, modules& result, const std::string& ext) {
            fsnsp::path p(path.c_str());
            if (fsnsp::exists(p)) {
                if (fsnsp::is_directory(p)) {
                    return parse_directory(path, result, ext);
                }
                if (fsnsp::is_regular_file(p)) {
                    return parse_file(path.c_str(), result);
                }
            }
            throw FILE_OR_DIRECTORY_ERROR;
            return PARSE_EFILESTREAM;
        }

        int parse_directory(const std::string& directory, modules& result, const std::string& ext) {
            result.clear();
            fsnsp::path p(directory.c_str());
            for (fsnsp::directory_iterator it = fsnsp::directory_iterator(p); it != fsnsp::directory_iterator(); ++it) {
                if (fsnsp::is_regular_file(it->path())) {
                    if ((ext.empty()) || (it->path().extension() == fsnsp::path("." + ext))) {
                        modules resulttmp;
                        parse_file(it->path().generic_string(), resulttmp);
                        result.insert(result.end(), resulttmp.begin(), resulttmp.end());
                    }
                }
            }
            return PARSE_SUCCESS;
        }

        int parse_file(const std::string& filename, modules& result) {

            // Modules_grammar ModulesDefGrammar;

            result.clear();
            std::string src;
            std::cout << "parse file:" << filename << std::endl;
            if (!read_module_file(filename, src)) {
                throw FILE_OR_DIRECTORY_ERROR;
            }

            str_iterator begin = str_iterator(src.begin());
            str_iterator end = str_iterator(src.end());

            bool rslt = qi::phrase_parse(begin, end, MainGrammar(), comment_skip, result);
            if (rslt && begin == end) {
                for (modules::iterator it = result.begin(); it != result.end(); ++it)
                    it->file = filename;
                return PARSE_SUCCESS;
            }

            throw synxtas_error(filename, src, begin.pos());
            return PARSE_ESYNXTAS;
        }


    }
}