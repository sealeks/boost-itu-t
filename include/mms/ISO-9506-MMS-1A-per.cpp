#include "ISO-9506-MMS-1A.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1A {



    // sequence ObtainFile-Request

    template<> void ObtainFile_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_EXISTS_BMP(sourceFileServer_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(sourceFileServer_);
        ITU_T_BIND_PER(*sourceFile_);
        ITU_T_BIND_PER(*destinationFile_);
    }

    template<> void ObtainFile_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(sourceFileServer_);
        ITU_T_BIND_PER(*sourceFile_);
        ITU_T_BIND_PER(*destinationFile_);
    }

    // sequence FileOpen-Request

    template<> void FileOpen_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*fileName_);
        ITU_T_BIND_NUM_CONSTRS(*initialPosition_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    template<> void FileOpen_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*fileName_);
        ITU_T_BIND_NUM_CONSTRS(*initialPosition_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
    }

    // sequence FileOpen-Response

    template<> void FileOpen_Response::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*frsmID_, static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*fileAttributes_);
    }

    template<> void FileOpen_Response::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_NUM_CONSTRS(*frsmID_, static_cast<int32_t> (std::numeric_limits<int32_t>::min()), static_cast<int32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(*fileAttributes_);
    }

    // sequence FileRead-Response

    template<> void FileRead_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*fileData_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void FileRead_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_BIND_PER(*fileData_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence FileRename-Request

    template<> void FileRename_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*currentFileName_);
        ITU_T_BIND_PER(*newFileName_);
    }

    template<> void FileRename_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*currentFileName_);
        ITU_T_BIND_PER(*newFileName_);
    }

    // sequence FileDirectory-Request

    template<> void FileDirectory_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_EXISTS_BMP(fileSpecification_) + ITU_T_EXISTS_BMP(continueAfter_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(fileSpecification_);
        ITU_T_BIND_PER(continueAfter_);
    }

    template<> void FileDirectory_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(fileSpecification_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(continueAfter_);
    }

    // sequence FileDirectory-Response

    template<> void FileDirectory_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_EXISTS_BMP(moreFollows_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*listOfDirectoryEntry_);
        ITU_T_BIND_PER(moreFollows_);
    }

    template<> void FileDirectory_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_BIND_PER(*listOfDirectoryEntry_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(moreFollows_);
    }

    // sequence DirectoryEntry

    template<> void DirectoryEntry::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*fileName_);
        ITU_T_BIND_PER(*fileAttributes_);
    }

    template<> void DirectoryEntry::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*fileName_);
        ITU_T_BIND_PER(*fileAttributes_);
    }

    // sequence FileAttributes

    template<> void FileAttributes::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_EXISTS_BMP(lastModified_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_NUM_CONSTRS(*sizeOfFile_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_BIND_PER(lastModified_);
    }

    template<> void FileAttributes::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_BIND_NUM_CONSTRS(*sizeOfFile_, static_cast<uint32_t> (0), static_cast<uint32_t> (std::numeric_limits<int32_t>::max()));
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(lastModified_);
    }

    // sequence 

    template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_EXISTS_BMP(componentName_) + ITU_T_EXISTS_BMP(alternateAccess_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(componentName_);
        ITU_T_BIND_PER(*variableSpecification_);
        ITU_T_BIND_PER(alternateAccess_);
    }

    template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(componentName_);
        ITU_T_BIND_PER(*variableSpecification_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(alternateAccess_);
    }

    // sequence DefineScatteredAccess-Request

    template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*scatteredAccessName_);
        ITU_T_BIND_PER(*scatteredAccessDescription_);
    }

    template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*scatteredAccessName_);
        ITU_T_BIND_PER(*scatteredAccessDescription_);
    }

    // sequence GetScatteredAccessAttributes-Response

    template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_EXISTS_BMP(accessControlList_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(*scatteredAccessDescription_);
        ITU_T_BIND_PER(accessControlList_);
    }

    template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_BIND_PER(*mmsDeletable_);
        ITU_T_BIND_PER(*scatteredAccessDescription_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(accessControlList_);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

