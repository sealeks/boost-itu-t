#include "ISO-9506-MMS-1A.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1A {

    template<> void ObtainFile_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(sourceFileServer_);

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

    template<> void FileOpen_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*fileName_);
       // ITU_T_BIND_NUM_CONSTRS(*initialPosition_, 0, 2147483647);
    }

    template<> void FileOpen_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*fileName_);
        //ITU_T_BIND_NUM_CONSTRS(*initialPosition_, 0, 2147483647);
    }

    template<> void FileOpen_Response::serialize(boost::asn1::x691::output_coder& arch) {
        //ITU_T_BIND_NUM_CONSTRS(*frsmID_, -2147483648, 2147483647);
        ITU_T_BIND_PER(*fileAttributes_);
    }

    template<> void FileOpen_Response::serialize(boost::asn1::x691::input_coder& arch) {
        //ITU_T_BIND_NUM_CONSTRS(*frsmID_, -2147483648, 2147483647);
        ITU_T_BIND_PER(*fileAttributes_);
    }

    template<> void FileRead_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(moreFollows_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*fileData_);
        ITU_T_BIND_PER(moreFollows_.get_shared());
    }

    template<> void FileRead_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_BIND_PER(*fileData_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(moreFollows_.get_shared());
    }

    template<> void FileRename_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*currentFileName_);
        ITU_T_BIND_PER(*newFileName_);
    }

    template<> void FileRename_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*currentFileName_);
        ITU_T_BIND_PER(*newFileName_);
    }

    template<> void FileDirectory_Request::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(fileSpecification_) + ITU_T_OPTIONAL_PER(continueAfter_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(fileSpecification_);
        ITU_T_BIND_PER(continueAfter_);
    }

    template<> void FileDirectory_Request::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(2);

        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(fileSpecification_);
        ITU_T_OPTIONAL_CHECK_PER(1) ITU_T_BIND_PER(continueAfter_);
    }

    template<> void FileDirectory_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(moreFollows_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_PER(*listOfDirectoryEntry_);
        ITU_T_BIND_PER(moreFollows_.get_shared());
    }

    template<> void FileDirectory_Response::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_BIND_PER(*listOfDirectoryEntry_);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(moreFollows_.get_shared());
    }

    template<> void DirectoryEntry::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*fileName_);
        ITU_T_BIND_PER(*fileAttributes_);
    }

    template<> void DirectoryEntry::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*fileName_);
        ITU_T_BIND_PER(*fileAttributes_);
    }

    template<> void FileAttributes::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(lastModified_);

        ITU_T_OPTIONAL_SET_PER;

        ITU_T_BIND_NUM_CONSTRS(*sizeOfFile_, 0, 2147483647);
        ITU_T_BIND_PER(lastModified_);
    }

    template<> void FileAttributes::serialize(boost::asn1::x691::input_coder& arch) {

        ITU_T_OPTIONAL_GET_PER(1);

        ITU_T_BIND_NUM_CONSTRS(*sizeOfFile_, 0, 2147483647);
        ITU_T_OPTIONAL_CHECK_PER(0) ITU_T_BIND_PER(lastModified_);
    }

    template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(componentName_) + ITU_T_OPTIONAL_PER(alternateAccess_);

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

    template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x691::output_coder& arch) {
        ITU_T_BIND_PER(*scatteredAccessName_);
        ITU_T_BIND_PER(*scatteredAccessDescription_);
    }

    template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x691::input_coder& arch) {
        ITU_T_BIND_PER(*scatteredAccessName_);
        ITU_T_BIND_PER(*scatteredAccessDescription_);
    }

    template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x691::output_coder& arch) {

        ITU_T_OPTIONAL_DECL_PER = ITU_T_OPTIONAL_PER(accessControlList_);

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

