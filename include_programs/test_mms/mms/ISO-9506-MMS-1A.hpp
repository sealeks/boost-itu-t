#ifndef ___ISO_9506_MMS_1A
#define ___ISO_9506_MMS_1A

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1A {

    using  boost::asn1::null_type;
    using  boost::asn1::enumerated_type;
    using  boost::asn1::bitstring_type;
    using  boost::asn1::octetstring_type;
    using  boost::asn1::oid_type;
    using  boost::asn1::reloid_type;
    using  boost::asn1::utctime_type;
    using  boost::asn1::gentime_type;
    using  boost::asn1::ia5string_type;
    using  boost::asn1::printablestring_type;
    using  boost::asn1::visiblestring_type;
    using  boost::asn1::visiblestring_type;
    using  boost::asn1::numericstring_type;
    using  boost::asn1::universalstring_type;
    using  boost::asn1::bmpstring_type;
    using  boost::asn1::utf8string_type;
    using  boost::asn1::generalstring_type;
    using  boost::asn1::graphicstring_type;
    using  boost::asn1::t61string_type;
    using  boost::asn1::t61string_type;
    using  boost::asn1::videotexstring_type;
    using  boost::asn1::objectdescriptor_type;
    using  boost::asn1::external_type;
    using  boost::asn1::embeded_type;
    using  boost::asn1::characterstring_type;
    using  boost::asn1::any_type;

    struct ObtainFile_Request;  
    struct FileOpen_Request;  
    struct FileOpen_Response;  
    struct FileRead_Response;  
    struct FileRename_Request;  
    struct FileDirectory_Request;  
    struct FileDirectory_Response;  
    struct DirectoryEntry;  
    struct FileAttributes;  
    struct DefineScatteredAccess_Request;  
    struct GetScatteredAccessAttributes_Response;  

    struct ScatteredAccessDescription_sequence_of;
    typedef null_type ObtainFile_Response;  
    typedef int ObtainFile_Error;  
    typedef null_type FileClose_Response;  
    typedef null_type FileRename_Response;  
    typedef int FileRename_Error;  
    typedef null_type FileDelete_Response;  
    typedef null_type DefineScatteredAccess_Response;  




    typedef std::deque< ScatteredAccessDescription_sequence_of > ScatteredAccessDescription;

} 

#include "ISO-9506-MMS-1.hpp"
#include "MMS-Environment-1.hpp"

namespace ISO_9506_MMS_1A {

  // import   from  ISO-9506-MMS-1

    using ISO_9506_MMS_1::FileName;
    using ISO_9506_MMS_1::ObjectName;
    using ISO_9506_MMS_1::AlternateAccess;
    using ISO_9506_MMS_1::VariableSpecification;
    using ISO_9506_MMS_1::Identifier;
    using ISO_9506_MMS_1::Integer32;
    using ISO_9506_MMS_1::Unsigned32;


  // import   from  MMS-Environment-1

    using MMS_Environment_1::ApplicationReference;



    typedef ISO_9506_MMS_1::Integer32 FileRead_Request;
    typedef ISO_9506_MMS_1::Integer32 FileClose_Request;
    typedef ISO_9506_MMS_1::FileName FileDelete_Request;
    typedef ISO_9506_MMS_1::ObjectName GetScatteredAccessAttributes_Request;

        // sequence ObtainFile-Request
        struct ObtainFile_Request{



            ObtainFile_Request() : sourceFile(), destinationFile() {} 
 
            boost::shared_ptr<MMS_Environment_1::ApplicationReference> sourceFileServer;
            BOOST_ASN_VALUE_FUNC_DECLARATE(MMS_Environment_1::ApplicationReference, sourceFileServer)

            boost::asn1::value_holder<ISO_9506_MMS_1::FileName> sourceFile;
            boost::asn1::value_holder<ISO_9506_MMS_1::FileName> destinationFile;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        extern const int ObtainFile_Error_source_file;
        extern const int ObtainFile_Error_destination_file;

        // sequence FileOpen-Request
        struct FileOpen_Request{



            FileOpen_Request() : fileName(), initialPosition() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::FileName> fileName;
            boost::asn1::value_holder<ISO_9506_MMS_1::Unsigned32> initialPosition;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence FileOpen-Response
        struct FileOpen_Response{



            FileOpen_Response() : frsmID(), fileAttributes() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::Integer32> frsmID;
            boost::asn1::value_holder<FileAttributes> fileAttributes;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence FileRead-Response
        struct FileRead_Response{



            FileRead_Response() : fileData() {} 
 
            boost::asn1::value_holder<octetstring_type> fileData;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence FileRename-Request
        struct FileRename_Request{



            FileRename_Request() : currentFileName(), newFileName() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::FileName> currentFileName;
            boost::asn1::value_holder<ISO_9506_MMS_1::FileName> newFileName;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        extern const int FileRename_Error_source_file;
        extern const int FileRename_Error_destination_file;

        // sequence FileDirectory-Request
        struct FileDirectory_Request{



            FileDirectory_Request() {} 
 
            boost::shared_ptr<ISO_9506_MMS_1::FileName> fileSpecification;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ISO_9506_MMS_1::FileName, fileSpecification)

            boost::shared_ptr<ISO_9506_MMS_1::FileName> continueAfter;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ISO_9506_MMS_1::FileName, continueAfter)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence FileDirectory-Response
        struct FileDirectory_Response{

        typedef std::vector< DirectoryEntry> listOfDirectoryEntry_type;


            FileDirectory_Response() : listOfDirectoryEntry() {} 
 
            boost::asn1::value_holder<listOfDirectoryEntry_type> listOfDirectoryEntry;
            boost::shared_ptr<bool> moreFollows;
            BOOST_ASN_VALUE_FUNC_DECLARATE(bool, moreFollows)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence DirectoryEntry
        struct DirectoryEntry{



            DirectoryEntry() : fileName(), fileAttributes() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::FileName> fileName;
            boost::asn1::value_holder<FileAttributes> fileAttributes;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence FileAttributes
        struct FileAttributes{



            FileAttributes() : sizeOfFile() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::Unsigned32> sizeOfFile;
            boost::shared_ptr<gentime_type> lastModified;
            BOOST_ASN_VALUE_FUNC_DECLARATE(gentime_type, lastModified)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 

            struct ScatteredAccessDescription_sequence_of{



                ScatteredAccessDescription_sequence_of() : variableSpecification() {} 
 
                boost::shared_ptr<ISO_9506_MMS_1::Identifier> componentName;
                BOOST_ASN_VALUE_FUNC_DECLARATE(ISO_9506_MMS_1::Identifier, componentName)

                boost::asn1::value_holder<ISO_9506_MMS_1::VariableSpecification> variableSpecification;
                boost::shared_ptr<ISO_9506_MMS_1::AlternateAccess> alternateAccess;
                BOOST_ASN_VALUE_FUNC_DECLARATE(ISO_9506_MMS_1::AlternateAccess, alternateAccess)


                BOOST_ASN_ARCHIVE_FUNC;
            };
 
        // sequence DefineScatteredAccess-Request
        struct DefineScatteredAccess_Request{



            DefineScatteredAccess_Request() : scatteredAccessName(), scatteredAccessDescription() {} 
 
            boost::asn1::value_holder<ISO_9506_MMS_1::ObjectName> scatteredAccessName;
            boost::asn1::value_holder<ScatteredAccessDescription> scatteredAccessDescription;

            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        // sequence GetScatteredAccessAttributes-Response
        struct GetScatteredAccessAttributes_Response{



            GetScatteredAccessAttributes_Response() : mmsDeletable(), scatteredAccessDescription() {} 
 
            boost::asn1::value_holder<bool> mmsDeletable;
            boost::asn1::value_holder<ScatteredAccessDescription> scatteredAccessDescription;
            boost::shared_ptr<ISO_9506_MMS_1::Identifier> accessControlList;
            BOOST_ASN_VALUE_FUNC_DECLARATE(ISO_9506_MMS_1::Identifier, accessControlList)


            BOOST_ASN_ARCHIVE_FUNC;
        };
 
        template<> void ObtainFile_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ObtainFile_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void FileOpen_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void FileOpen_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void FileOpen_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void FileOpen_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void FileRead_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void FileRead_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void FileRename_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void FileRename_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void FileDirectory_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void FileDirectory_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void FileDirectory_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void FileDirectory_Response::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DirectoryEntry::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DirectoryEntry::serialize(boost::asn1::x690::input_coder& arch);
        template<> void FileAttributes::serialize(boost::asn1::x690::output_coder& arch);
        template<> void FileAttributes::serialize(boost::asn1::x690::input_coder& arch);
        template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x690::output_coder& arch);
        template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x690::input_coder& arch);
        template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x690::output_coder& arch);
        template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x690::input_coder& arch);
        template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x690::output_coder& arch);
        template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x690::input_coder& arch);
} 


#endif  /*___ISO_9506_MMS_1A */

