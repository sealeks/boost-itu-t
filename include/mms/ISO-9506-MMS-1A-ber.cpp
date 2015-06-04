#include "ISO-9506-MMS-1A.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1A {



    // sequence ObtainFile-Request

    template<> void ObtainFile_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(sourceFileServer_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(sourceFile_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(destinationFile_, 2, CONTEXT_CLASS);
    }

    template<> void ObtainFile_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(sourceFileServer_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(sourceFile_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(destinationFile_, 2, CONTEXT_CLASS);
    }

    // sequence FileOpen-Request

    template<> void FileOpen_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(fileName_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(initialPosition_, 1, CONTEXT_CLASS);
    }

    template<> void FileOpen_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(fileName_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(initialPosition_, 1, CONTEXT_CLASS);
    }

    // sequence FileOpen-Response

    template<> void FileOpen_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(frsmID_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(fileAttributes_, 1, CONTEXT_CLASS);
    }

    template<> void FileOpen_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(frsmID_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(fileAttributes_, 1, CONTEXT_CLASS);
    }

    // sequence FileRead-Response

    template<> void FileRead_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(fileData_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
    }

    template<> void FileRead_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(fileData_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
    }

    // sequence FileRename-Request

    template<> void FileRename_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(currentFileName_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(newFileName_, 1, CONTEXT_CLASS);
    }

    template<> void FileRename_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(currentFileName_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(newFileName_, 1, CONTEXT_CLASS);
    }

    // sequence FileDirectory-Request

    template<> void FileDirectory_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(fileSpecification_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(continueAfter_, 1, CONTEXT_CLASS);
    }

    template<> void FileDirectory_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(fileSpecification_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(continueAfter_, 1, CONTEXT_CLASS);
    }

    // sequence FileDirectory-Response

    template<> void FileDirectory_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_EXPLICIT(listOfDirectoryEntry_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
    }

    template<> void FileDirectory_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_EXPLICIT(listOfDirectoryEntry_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(moreFollows_, 1, CONTEXT_CLASS);
    }

    // sequence DirectoryEntry

    template<> void DirectoryEntry::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(fileName_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(fileAttributes_, 1, CONTEXT_CLASS);
    }

    template<> void DirectoryEntry::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(fileName_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(fileAttributes_, 1, CONTEXT_CLASS);
    }

    // sequence FileAttributes

    template<> void FileAttributes::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(sizeOfFile_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(lastModified_, 1, CONTEXT_CLASS);
    }

    template<> void FileAttributes::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(sizeOfFile_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(lastModified_, 1, CONTEXT_CLASS);
    }

    // sequence 

    template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(componentName_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(variableSpecification_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(alternateAccess_, 2, CONTEXT_CLASS);
    }

    template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(componentName_, 0, CONTEXT_CLASS);
        ITU_T_BIND_CHOICE_TAG(variableSpecification_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(alternateAccess_, 2, CONTEXT_CLASS);
    }

    // sequence DefineScatteredAccess-Request

    template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(scatteredAccessName_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(scatteredAccessDescription_, 1, CONTEXT_CLASS);
    }

    template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_CHOICE_TAG(scatteredAccessName_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(scatteredAccessDescription_, 1, CONTEXT_CLASS);
    }

    // sequence GetScatteredAccessAttributes-Response

    template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(scatteredAccessDescription_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControlList_, 2, CONTEXT_CLASS);
    }

    template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_IMPLICIT(mmsDeletable_, 0, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(scatteredAccessDescription_, 1, CONTEXT_CLASS);
        ITU_T_BIND_IMPLICIT(accessControlList_, 2, CONTEXT_CLASS);
    }

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

