#include "ISO-9506-MMS-1A.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1A {

    // sequence ObtainFile-Request

    template<> void ObtainFile_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(sourceFileServer_, 0);
        ITU_T_IMPLICIT_TAG(*sourceFile_, 1);
        ITU_T_IMPLICIT_TAG(*destinationFile_, 2);
    }

    template<> void ObtainFile_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(sourceFileServer_, 0);
        ITU_T_IMPLICIT_TAG(*sourceFile_, 1);
        ITU_T_IMPLICIT_TAG(*destinationFile_, 2);
    }

    // sequence FileOpen-Request

    template<> void FileOpen_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*fileName_, 0);
        ITU_T_IMPLICIT_TAG(*initialPosition_, 1);
    }

    template<> void FileOpen_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*fileName_, 0);
        ITU_T_IMPLICIT_TAG(*initialPosition_, 1);
    }

    // sequence FileOpen-Response

    template<> void FileOpen_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*frsmID_, 0);
        ITU_T_IMPLICIT_TAG(*fileAttributes_, 1);
    }

    template<> void FileOpen_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*frsmID_, 0);
        ITU_T_IMPLICIT_TAG(*fileAttributes_, 1);
    }

    // sequence FileRead-Response

    template<> void FileRead_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*fileData_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void FileRead_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*fileData_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence FileRename-Request

    template<> void FileRename_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*currentFileName_, 0);
        ITU_T_IMPLICIT_TAG(*newFileName_, 1);
    }

    template<> void FileRename_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*currentFileName_, 0);
        ITU_T_IMPLICIT_TAG(*newFileName_, 1);
    }

    // sequence FileDirectory-Request

    template<> void FileDirectory_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(fileSpecification_, 0);
        ITU_T_IMPLICIT_TAG(continueAfter_, 1);
    }

    template<> void FileDirectory_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(fileSpecification_, 0);
        ITU_T_IMPLICIT_TAG(continueAfter_, 1);
    }

    // sequence FileDirectory-Response

    template<> void FileDirectory_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXPLICIT_TAG(*listOfDirectoryEntry_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void FileDirectory_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXPLICIT_TAG(*listOfDirectoryEntry_, 0);
        ITU_T_IMPLICIT_TAG(moreFollows_, 1);
    }

    // sequence DirectoryEntry

    template<> void DirectoryEntry::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*fileName_, 0);
        ITU_T_IMPLICIT_TAG(*fileAttributes_, 1);
    }

    template<> void DirectoryEntry::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*fileName_, 0);
        ITU_T_IMPLICIT_TAG(*fileAttributes_, 1);
    }

    // sequence FileAttributes

    template<> void FileAttributes::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*sizeOfFile_, 0);
        ITU_T_IMPLICIT_TAG(lastModified_, 1);
    }

    template<> void FileAttributes::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*sizeOfFile_, 0);
        ITU_T_IMPLICIT_TAG(lastModified_, 1);
    }

    // sequence 

    template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(componentName_, 0);
        ITU_T_CHOICE_TAG(*variableSpecification_, 1);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 2);
    }

    template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(componentName_, 0);
        ITU_T_CHOICE_TAG(*variableSpecification_, 1);
        ITU_T_IMPLICIT_TAG(alternateAccess_, 2);
    }

    // sequence DefineScatteredAccess-Request

    template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(*scatteredAccessName_, 0);
        ITU_T_IMPLICIT_TAG(*scatteredAccessDescription_, 1);
    }

    template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(*scatteredAccessName_, 0);
        ITU_T_IMPLICIT_TAG(*scatteredAccessDescription_, 1);
    }

    // sequence GetScatteredAccessAttributes-Response

    template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(*scatteredAccessDescription_, 1);
        ITU_T_IMPLICIT_TAG(accessControlList_, 2);
    }

    template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(*mmsDeletable_, 0);
        ITU_T_IMPLICIT_TAG(*scatteredAccessDescription_, 1);
        ITU_T_IMPLICIT_TAG(accessControlList_, 2);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

