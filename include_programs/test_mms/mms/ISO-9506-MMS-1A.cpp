#include "ISO-9506-MMS-1A.hpp"

namespace ISO_9506_MMS_1A {

        // sequence ObtainFile-Request

        template<> void ObtainFile_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(sourceFileServer, 0);
            BOOST_ASN_IMPLICIT_TAG(sourceFile, 1);
            BOOST_ASN_IMPLICIT_TAG(destinationFile, 2);
        }

        template<> void ObtainFile_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(sourceFileServer, 0);
            BOOST_ASN_IMPLICIT_TAG(sourceFile, 1);
            BOOST_ASN_IMPLICIT_TAG(destinationFile, 2);
        }

 
    const int ObtainFile_Error_source_file = 0;
    const int ObtainFile_Error_destination_file = 1;

        // sequence FileOpen-Request

        template<> void FileOpen_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(fileName, 0);
            BOOST_ASN_IMPLICIT_TAG(initialPosition, 1);
        }

        template<> void FileOpen_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(fileName, 0);
            BOOST_ASN_IMPLICIT_TAG(initialPosition, 1);
        }

 
        // sequence FileOpen-Response

        template<> void FileOpen_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(frsmID, 0);
            BOOST_ASN_IMPLICIT_TAG(fileAttributes, 1);
        }

        template<> void FileOpen_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(frsmID, 0);
            BOOST_ASN_IMPLICIT_TAG(fileAttributes, 1);
        }

 
        // sequence FileRead-Response

        template<> void FileRead_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(fileData, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void FileRead_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(fileData, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence FileRename-Request

        template<> void FileRename_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(currentFileName, 0);
            BOOST_ASN_IMPLICIT_TAG(newFileName, 1);
        }

        template<> void FileRename_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(currentFileName, 0);
            BOOST_ASN_IMPLICIT_TAG(newFileName, 1);
        }

 
    const int FileRename_Error_source_file = 0;
    const int FileRename_Error_destination_file = 1;

        // sequence FileDirectory-Request

        template<> void FileDirectory_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(fileSpecification, 0);
            BOOST_ASN_IMPLICIT_TAG(continueAfter, 1);
        }

        template<> void FileDirectory_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(fileSpecification, 0);
            BOOST_ASN_IMPLICIT_TAG(continueAfter, 1);
        }

 
        // sequence FileDirectory-Response

        template<> void FileDirectory_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(listOfDirectoryEntry, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

        template<> void FileDirectory_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_EXPLICIT_TAG(listOfDirectoryEntry, 0);
            BOOST_ASN_IMPLICIT_TAG(moreFollows, 1);
        }

 
        // sequence DirectoryEntry

        template<> void DirectoryEntry::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(fileName, 0);
            BOOST_ASN_IMPLICIT_TAG(fileAttributes, 1);
        }

        template<> void DirectoryEntry::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(fileName, 0);
            BOOST_ASN_IMPLICIT_TAG(fileAttributes, 1);
        }

 
        // sequence FileAttributes

        template<> void FileAttributes::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(sizeOfFile, 0);
            BOOST_ASN_IMPLICIT_TAG(lastModified, 1);
        }

        template<> void FileAttributes::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(sizeOfFile, 0);
            BOOST_ASN_IMPLICIT_TAG(lastModified, 1);
        }

 


        template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(componentName, 0);
            BOOST_ASN_CHOICE_TAG(variableSpecification, 1);
            BOOST_ASN_IMPLICIT_TAG(alternateAccess, 2);
        }

        template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(componentName, 0);
            BOOST_ASN_CHOICE_TAG(variableSpecification, 1);
            BOOST_ASN_IMPLICIT_TAG(alternateAccess, 2);
        }

 
        // sequence DefineScatteredAccess-Request

        template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_CHOICE_TAG(scatteredAccessName, 0);
            BOOST_ASN_IMPLICIT_TAG(scatteredAccessDescription, 1);
        }

        template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_CHOICE_TAG(scatteredAccessName, 0);
            BOOST_ASN_IMPLICIT_TAG(scatteredAccessDescription, 1);
        }

 
        // sequence GetScatteredAccessAttributes-Response

        template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x690::output_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_IMPLICIT_TAG(scatteredAccessDescription, 1);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 2);
        }

        template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x690::input_coder& arch){
            BOOST_ASN_IMPLICIT_TAG(mmsDeletable, 0);
            BOOST_ASN_IMPLICIT_TAG(scatteredAccessDescription, 1);
            BOOST_ASN_IMPLICIT_TAG(accessControlList, 2);
        }

 
} 
