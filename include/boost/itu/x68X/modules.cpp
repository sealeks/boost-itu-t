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


            Assignments = *(ObjectClassAssignment | TypeAssignment
                    | TypeAssignmentSS | UnknownTCAssignment
                    | ValueAssignmentLS | ObjectAssignmentLS | ObjectAssignmentRS
                    | ValueSetTypeAssignmentLS | ObjectSetAssignmentLS
                    | UnknownValObjAssignment | UnknownValSetObjSetAssignment);


            ObjectClassAssignment = objectclassreference_[phx::bind(&classa_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&classa_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> StrictObjectClass[phx::bind(&classa_class, sprt::_val, sprt::_1)];

            ObjectClassAssignment0 = objectclassreference_[phx::bind(&classa_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&classa_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectClass[phx::bind(&classa_class, sprt::_val, sprt::_1)];

            TypeAssignment = typereference_[phx::bind(&type_identifier, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&typea_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> /*Type*/StrictType[phx::bind(&typea_type, sprt::_val, sprt::_1)];

            TypeAssignmentSS = typereference_strict[phx::bind(&type_identifier, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&typea_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Type[phx::bind(&typea_type, sprt::_val, sprt::_1)];

            TypeAssignment0 = typereference_[phx::bind(&type_identifier, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&typea_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Type[phx::bind(&typea_type, sprt::_val, sprt::_1)];



            ValueAssignmentLS = valuereference_[phx::bind(&valuea_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&valuea_arguments, sprt::_val, sprt::_1)])
                    >> StrictType[phx::bind(&valuea_type, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Value[phx::bind(&valuea_value, sprt::_val, sprt::_1)];

            ValueAssignmentRS = valuereference_[phx::bind(&valuea_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&valuea_arguments, sprt::_val, sprt::_1)])
                    >> Type[phx::bind(&valuea_type, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> StrictValue[phx::bind(&valuea_value, sprt::_val, sprt::_1)];

            ValueAssignment = valuereference_[phx::bind(&valuea_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&valuea_arguments, sprt::_val, sprt::_1)])
                    >> Type[phx::bind(&valuea_type, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> Value[phx::bind(&valuea_value, sprt::_val, sprt::_1)];

            ObjectAssignmentLS = objectreference_[phx::bind(&objecta_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&objecta_arguments, sprt::_val, sprt::_1)])
                    >> UsefulObjectClass[phx::bind(&objecta_class, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectDefn[phx::bind(&objecta_object, sprt::_val, sprt::_1)];

            ObjectAssignmentRS = objectreference_[phx::bind(&objecta_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&objecta_arguments, sprt::_val, sprt::_1)])
                    >> SimpleDefinedObjectClass[phx::bind(&objecta_class, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> DefaultSyntax[phx::bind(&objecta_object, sprt::_val, sprt::_1)];

            ObjectAssignment = objectreference_[phx::bind(&objecta_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&objecta_arguments, sprt::_val, sprt::_1)])
                    >> SimpleDefinedObjectClass[phx::bind(&objecta_class, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectDefn[phx::bind(&objecta_object, sprt::_val, sprt::_1)];


            ValueSetTypeAssignmentLS = valuesetreference_[phx::bind(&valueset_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&valueseta_arguments, sprt::_val, sprt::_1)])
                    >> StrictType[phx::bind(&valueseta_type, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ValueSet[phx::bind(&valueseta_set, sprt::_val, sprt::_1)];

            ValueSetTypeAssignment = valuesetreference_[phx::bind(&valueset_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&valueseta_arguments, sprt::_val, sprt::_1)])
                    >> Type[phx::bind(&valueseta_type, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ValueSet[phx::bind(&valueseta_set, sprt::_val, sprt::_1)];

            ObjectSetAssignmentLS = objectsetreference_[phx::bind(&objectseta_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&objectseta_arguments, sprt::_val, sprt::_1)])
                    >> UsefulObjectClass[phx::bind(&objectseta_class, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectSet[phx::bind(&objectseta_objectset, sprt::_val, sprt::_1)];

            ObjectSetAssignment = objectsetreference_[phx::bind(&objectseta_reference, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&objectseta_arguments, sprt::_val, sprt::_1)])
                    >> SimpleDefinedObjectClass[phx::bind(&objectseta_class, sprt::_val, sprt::_1)]
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> ObjectSet[phx::bind(&objectseta_objectset, sprt::_val, sprt::_1)];




            UnknownTCAssignment = ((qi::hold[TypeAssignment0[phx::bind(&unknown_tca_type, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectClassAssignment0[phx::bind(&unknown_tca_class, sprt::_val, sprt::_1)] >> qi::omit[';']])) |
                    (objectclassreference_[phx::bind(&unknown_tca_identifier, sprt::_val, sprt::_1)]
                    >> -(Parameters[phx::bind(&unknown_tca_arguments, sprt::_val, sprt::_1)])
                    >> qi::omit[qi::lexeme[qi::lit("::=")]]
                    >> UnknownReferencedTC[phx::bind(&unknown_tca, sprt::_val, sprt::_1)]);


            SettingType = Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)];

            SettingValue = Value[phx::bind(&setting_value, sprt::_val, sprt::_1)];

            SettingValueSet = ValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)];

            SettingClass = DefinedObjectClass[phx::bind(&setting_class, sprt::_val, sprt::_1)];

            SettingObject = Object[phx::bind(&setting_object, sprt::_val, sprt::_1)];

            SettingObjectSet = ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)];

            SettingLiteral = SyntaxField_[phx::bind(&setting_literal, sprt::_val, sprt::_1)];
            
            SettingSLiteral = Literal_[phx::bind(&setting_literal, sprt::_val, sprt::_1)];

            SettingArgument = bothreference_[phx::bind(&setting_literal, sprt::_val, sprt::_1)];

            SettingTypeNA = TypeNA[phx::bind(&setting_settype, sprt::_val, sprt::_1)];

            SettingValueNA = ValueNA[phx::bind(&setting_value, sprt::_val, sprt::_1)];

            SettingValueSetNA = ValueSetNA[phx::bind(&setting_valueset, sprt::_val, sprt::_1)];

            SettingObjectNA = ObjectNA[phx::bind(&setting_object, sprt::_val, sprt::_1)];

            SettingObjectSetNA = ObjectSetNA[phx::bind(&setting_objectset, sprt::_val, sprt::_1)];



            SettingMCN= SettingType | SettingValueSet | SettingObjectSet;

            SettingCN = ((qi::hold[Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSetNA[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingMCN;

            SettingM0 = SettingValue | SettingValueSet | SettingObject | SettingObjectSet;

            Setting0 = ((qi::hold[Value[phx::bind(&setting_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Object[phx::bind(&setting_object, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM0;


            SettingM1 = SettingType | SettingValue | SettingValueSet | SettingObject | SettingObjectSet | SettingLiteral;

            Setting = ((qi::hold[Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Value[phx::bind(&setting_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Object[phx::bind(&setting_object, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[SyntaxField_[phx::bind(&setting_literal, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM1;

            SettingM1NA = SettingTypeNA | SettingValueNA | SettingValueSetNA | SettingObjectNA | SettingObjectSetNA | SettingSLiteral;

            SettingNA = ((qi::hold[TypeNA[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ValueNA[phx::bind(&setting_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ValueSetNA[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectNA[phx::bind(&setting_object, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSetNA[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Literal_[phx::bind(&setting_literal, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM1NA;

            SettingM2 = SettingType | SettingValue | SettingValueSet | SettingClass | SettingObject | SettingObjectSet | SettingArgument;

            ActualParameter = ((qi::hold[Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Value[phx::bind(&setting_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[DefinedObjectClass[phx::bind(&setting_class, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Object[phx::bind(&setting_object, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[bothreference_[phx::bind(&setting_literal, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM2;

            SettingM3 = SettingValue | SettingObject;

            SettingU1 = ((qi::hold[Value[phx::bind(&setting_value, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[Object[phx::bind(&setting_object, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM3;

            SettingM4 = SettingType | SettingClass | SettingObjectSet;

            SettingU2 = ((qi::hold[Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[DefinedObjectClass[phx::bind(&setting_class, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM4;


            SettingCValueSet = SimpleValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)];

            SettingM5 = SettingType | SettingCValueSet | SettingObjectSet;

            SettingC = ((qi::hold[Type[phx::bind(&setting_settype, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[SimpleValueSet[phx::bind(&setting_valueset, sprt::_val, sprt::_1)] >> qi::omit[';']])
                    | (qi::hold[ObjectSet[phx::bind(&setting_objectset, sprt::_val, sprt::_1)] >> qi::omit[';']])) | SettingM5;



            Parameters = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> (Parameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];


            Parameter = ParameterA1 | ParameterA1 | ParameterB1
                    | ParameterB2 | ParameterC1 | ParameterC2 | ParameterD1 | ParameterD2;

            ParameterA1 = (UsefulObjectClass >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> typereference_)[phx::bind(&argument_governor_cl, sprt::_val, sprt::_1, sprt::_2, true)];

            ParameterA2 = (UsefulObjectClass >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> valuereference_)[phx::bind(&argument_governor_cl, sprt::_val, sprt::_1, sprt::_2, false)];

            ParameterB1 = (GovernorType >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> typereference_)[phx::bind(&argument_governor_tp, sprt::_val, sprt::_1, sprt::_2, true)];

            ParameterB2 = (GovernorType >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> valuereference_)[phx::bind(&argument_governor_tp, sprt::_val, sprt::_1, sprt::_2, false)];

            ParameterC1 = (DefinedType_ >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> typereference_)[phx::bind(&argument_governor_reff, sprt::_val, sprt::_1, sprt::_2, true)];

            ParameterC2 = (DefinedType_ >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> valuereference_)[phx::bind(&argument_governor_reff, sprt::_val, sprt::_1, sprt::_2, false)];

            ParameterD1 = typereference_[phx::bind(&argument_argument, sprt::_val, sprt::_1, true)];

            ParameterD2 = valuereference_[phx::bind(&argument_argument, sprt::_val, sprt::_1, false)];



            ActualParameters = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> (ActualParameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];



            UParameterA = (UsefulObjectClass >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> Setting0)[phx::bind(&uargument_governor_cl, sprt::_val, sprt::_1, sprt::_2)];

            UParameterB = (GovernorType >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> Setting0)[phx::bind(&uargument_governor_tp, sprt::_val, sprt::_1, sprt::_2)];

            UParameterC = (DefinedType_ >> qi::omit[qi::lexeme[qi::lit(":")]]
                    >> Setting0)[phx::bind(&uargument_governor_reff, sprt::_val, sprt::_1, sprt::_2)];

            UParameterD = (SettingM2)[phx::bind(&uargument_setting, sprt::_val, sprt::_1)];

            UParameter = UParameterA | UParameterB | UParameterC | UParameterD;

            UParameters = qi::omit[qi::lexeme[qi::lit("{")]]
                    >> -(UParameter % qi::omit[qi::lit(",")]) >> qi::omit[qi::lexeme[qi::lit("}")]];





            ValueOrObjectM =
                    Value[phx::bind(&unknown_vo_value, sprt::_val, sprt::_1)] | Object[phx::bind(&unknown_vo_object, sprt::_val, sprt::_1)];

            ValueOrObject =
                    (qi::hold[Value[phx::bind(&unknown_vo_value, sprt::_val, sprt::_1)] >> qi::omit[';']]
                    | qi::hold[Object[phx::bind(&unknown_vo_object, sprt::_val, sprt::_1)] >> qi::omit[';']])
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