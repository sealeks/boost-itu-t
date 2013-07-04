//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x68X/modules.hpp>


namespace x680 {
    namespace syntactic {

        namespace phx = boost::phoenix;

        //Modules_grammar

        void Modules_grammar::init() {



            start_rule = +ModuleDefinition;



            ModuleDefinition = qi::lexeme[ modulereference_[ bind(&module_name, qi::_val, qi::_1) ]]
                    >> -(ObjectIdentifierValue[ bind(&module_oid, qi::_val, qi::_1) ] >> -(IRIValue[ bind(&module_iri, qi::_val, qi::_1) ]))
                    >> qi::lexeme[DEFINITIONS_ ]

                    >> -(qi::lexeme[EncodingReferenceDefault[bind(&module_encoding, qi::_val, qi::_1)]]
                    >> qi::lexeme[INSTRUCTIONS_])

                    >> -(qi::lexeme[ TagDefault[bind(&module_tags, qi::_val, qi::_1)]
                    >> +qi::space >> TAGS_])

                    >> -(qi::lexeme[EXTENSIBILITY_
                    >> +qi::space
                    >> IMPLIED_[ bind(&module_extesibility, qi::_val) ]])

                    >> qi::lexeme[qi::lit("::=")]
                    >> qi::lexeme[BEGIN_]
                    >> -((qi::lexeme[qi::omit[EXPORTS_ >> +qi::space >> ALL_ >> *qi::space >> qi::lit(";") ]])[bind(&module_allexport, qi::_val)]
                    | Exports[bind(&module_exports, qi::_val, qi::_1)])
                    >> -(Imports[bind(&module_imports, qi::_val, qi::_1)])
                    >> -(Assignments[bind(&module_assignments, qi::_val, qi::_1)])
                    >> END_;

            Import = SymbolList[ bind(&import_add, qi::_val, qi::_1) ]
                    >> FROM_
                    >> modulereference_[ bind(&import_name, qi::_val, qi::_1) ]
                    >> -(ObjectIdentifierValue[ bind(&import_oid, qi::_val, qi::_1) ] | (DefinedValue - qi::omit[(DefinedValue >> (FROM_ | qi::lit(",")))])[ bind(&import_defined, qi::_val, qi::_1) ]);


            Importsdecl = *Import;

            Imports = qi::omit[IMPORTS_]
                    >> Importsdecl
                    >> qi::omit[qi::lit(";")];

            Exports = qi::omit[EXPORTS_]
                    >> SymbolList
                    >> qi::omit[qi::lit(";")];

            SymbolList = qi::lexeme[Symbol_] % qi::omit[qi::lexeme[ lit(",")]];


            Assignments = *(ObjectClassAssignment | TypeAssignment | TypeAssignmentSS | UnknownTCAssignment
                    | ValueAssignmentLS | ValueAssignmentRS | ObjectAssignmentLS | ObjectAssignmentRS | ValueAssignment | ObjectAssignment
                    | ValueSetTypeAssignmentLS | ObjectSetAssignmentLS | ValueSetTypeAssignment | ObjectSetAssignment);



            ObjectClassAssignment = objectclassreference_[bind(&classa_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&classa_arguments, qi::_val, qi::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> StrictObjectClass[bind(&classa_class, qi::_val, qi::_1)];

            TypeAssignment = typereference_[bind(&type_identifier, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&typea_arguments, qi::_val, qi::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> /*Type*/StrictType[bind(&typea_type, qi::_val, qi::_1)];

            TypeAssignmentSS = typereference_strict[bind(&type_identifier, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&typea_arguments, qi::_val, qi::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Type[bind(&typea_type, qi::_val, qi::_1)];

            UnknownTCAssignment = objectclassreference_[bind(&unknown_tca_identifier, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&unknown_tca_arguments, qi::_val, qi::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> UnknownReferencedTC[bind(&unknown_tca, qi::_val, qi::_1)];




            ValueAssignmentLS = valuereference_[bind(&valuea_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valuea_arguments, qi::_val, qi::_1)])
                    >> StrictType[bind(&valuea_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Value[bind(&valuea_value, qi::_val, qi::_1, true)];

            ValueAssignmentRS = valuereference_[bind(&valuea_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valuea_arguments, qi::_val, qi::_1)])
                    >> Type[bind(&valuea_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> StrictValue[bind(&valuea_value, qi::_val, qi::_1, true)];

            ValueAssignment = valuereference_[bind(&valuea_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valuea_arguments, qi::_val, qi::_1)])
                    >> Type[bind(&valuea_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Value[bind(&valuea_value, qi::_val, qi::_1, false)];

            ObjectAssignmentLS = objectreference_[bind(&objecta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objecta_arguments, qi::_val, qi::_1)])
                    >> UsefulObjectClass[bind(&objecta_class, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectDefn[bind(&objecta_object, qi::_val, qi::_1)];

            ObjectAssignmentRS = objectreference_[bind(&objecta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objecta_arguments, qi::_val, qi::_1)])
                    >> SimpleDefinedObjectClass[bind(&objecta_class, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> DefaultSyntax[bind(&objecta_object, qi::_val, qi::_1)];

            ObjectAssignment = objectreference_[bind(&objecta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objecta_arguments, qi::_val, qi::_1)])
                    >> SimpleDefinedObjectClass[bind(&objecta_class, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectDefn[bind(&objecta_object, qi::_val, qi::_1)];


            ValueSetTypeAssignmentLS = valuesetreference_[bind(&valueset_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valueseta_arguments, qi::_val, qi::_1)])
                    >> StrictType[bind(&valueseta_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ValueSet[bind(&valueset_set, qi::_val, qi::_1, true)];

            ValueSetTypeAssignment = valuesetreference_[bind(&valueset_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&valueseta_arguments, qi::_val, qi::_1)])
                    >> Type[bind(&valueseta_type, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ValueSet[bind(&valueset_set, qi::_val, qi::_1, false)];

            ObjectSetAssignmentLS = objectsetreference_[bind(&objectseta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objectseta_arguments, qi::_val, qi::_1)])
                    >> UsefulObjectClass[bind(&objectseta_class, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectSet[bind(&objectseta_objectset, qi::_val, qi::_1)];

            ObjectSetAssignment = objectsetreference_[bind(&objectseta_reference, qi::_val, qi::_1)]
                    >> -(Parameters[bind(&objectseta_arguments, qi::_val, qi::_1)])
                    >> SimpleDefinedObjectClass[bind(&objectseta_class, qi::_val, qi::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectSet[bind(&objectseta_objectset, qi::_val, qi::_1)];



            Setting = SettingStrictType | SettingStrictValue | SettingStrictClass | SettingUnknownTC | /*SettingUnknownVO | */
                    SettingType | SettingValue | SettingValueSet | /*SettingClass |*/ SettingObject | SettingObjectSet;

            SettingU1 = SettingValue | SettingObject;

            SettingU2 = SettingStrictType | SettingStrictClass | SettingUnknownTC |
                    SettingType | SettingObjectSet;


            SettingType = Type[bind(&setting_settype, qi::_val, qi::_1)];

            SettingStrictType = StrictType[bind(&setting_settype, qi::_val, qi::_1)];

            SettingValue = Value[bind(&setting_value, qi::_val, qi::_1)];

            SettingStrictValue = StrictValue[bind(&setting_value, qi::_val, qi::_1)];

            SettingValueSet = ValueSet[bind(&setting_valueset, qi::_val, qi::_1)];

            SettingClass = DefinedObjectClass[bind(&setting_class, qi::_val, qi::_1)];

            SettingStrictClass = UsefulObjectClass[bind(&setting_class, qi::_val, qi::_1)];

            SettingObject = Object[bind(&setting_object, qi::_val, qi::_1)];

            SettingObjectSet = ObjectSet[bind(&setting_objectset, qi::_val, qi::_1)];

            SettingUnknownTC = UnknownTC[bind(&setting_tc, qi::_val, qi::_1)];

            SettingUnknownVO = UnknownVO[bind(&setting_vo, qi::_val, qi::_1)];


            Parameters = qi::omit[qi::lexeme[qi::lit("{")]] >> (Parameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];

            Parameter = ParameterA1 | ParameterA1 | ParameterB1 | ParameterB2 | ParameterC1 | ParameterC2 | ParameterD1 | ParameterD2;

            ParameterA1 = (UsefulObjectClass >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> typereference_)[bind(&argument_governor_cl, qi::_val, qi::_1, qi::_2, true)];

            ParameterA2 = (UsefulObjectClass >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> valuereference_)[bind(&argument_governor_cl, qi::_val, qi::_1, qi::_2, false)];

            ParameterB1 = (GovernorType >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> typereference_)[bind(&argument_governor_tp, qi::_val, qi::_1, qi::_2, true)];

            ParameterB2 = (GovernorType >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> valuereference_)[bind(&argument_governor_tp, qi::_val, qi::_1, qi::_2, false)];

            ParameterC1 = (UnknownTC >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> typereference_)[bind(&argument_governor_reff, qi::_val, qi::_1, qi::_2, true)];

            ParameterC2 = (UnknownTC >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> valuereference_)[bind(&argument_governor_reff, qi::_val, qi::_1, qi::_2, false)];

            ParameterD1 = typereference_[bind(&argument_argument, qi::_val, qi::_1, true)];

            ParameterD2 = valuereference_[bind(&argument_argument, qi::_val, qi::_1, false)];



            ActualParameters = qi::omit[qi::lexeme[qi::lit("{")]] >> (ActualParameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];

            ActualParameter = SettingStrictType | SettingStrictValue | SettingStrictClass | SettingUnknownTC | /*SettingUnknownVO | */
                    SettingType | SettingValue | SettingValueSet | SettingClass | SettingObject | SettingObjectSet;




            initV();
            initT();
            initVS();
            initCl();
            initO();
            initOS();

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
                std::size_t length = ifs.tellg();
                ifs.seekg(0, ifs.beg);
                char * buffer = new char [length];
                ifs.read(buffer, length);
                src.insert(src.end(), buffer, buffer + length);
                delete[] buffer;
            }
            return src.size();
        }

        Modules_grammar ModulesDefGrammar;




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

            result.clear();
            std::string src;
            std::cout << "compile file:" << filename << std::endl;
            if (!read_module_file(filename, src)) {
                throw FILE_OR_DIRECTORY_ERROR;
            }

            str_iterator begin = str_iterator(src.begin());
            str_iterator end = str_iterator(src.end());

            bool rslt = qi::phrase_parse(begin, end, ModulesDefGrammar, comment_skip, result);
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