#ifndef ___ISO_9506_MMS_1A
#define ___ISO_9506_MMS_1A

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>
#include <boost/itu/x69X/x691.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1A {

    ITU_T_USE_UNIVESAL_DECL;


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
    typedef uint8_t ObtainFile_Error; //   Ic(  [ 0  ...   1 ]   
    typedef null_type FileClose_Response;
    typedef null_type FileRename_Response;
    typedef uint8_t FileRename_Error; //   Ic(  [ 0  ...   1 ]   
    typedef null_type FileDelete_Response;
    typedef null_type DefineScatteredAccess_Response;

    typedef std::vector< ScatteredAccessDescription_sequence_of > ScatteredAccessDescription;


}

#include <mms/ISO-9506-MMS-1.hpp>
#include <mms/MMS-Environment-1.hpp>

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



    typedef ISO_9506_MMS_1::Integer32 FileRead_Request; //   Ic(  [ -2147483648  ...   2147483647 ]   
    typedef ISO_9506_MMS_1::Integer32 FileClose_Request; //   Ic(  [ -2147483648  ...   2147483647 ]   
    typedef ISO_9506_MMS_1::FileName FileDelete_Request;
    typedef ISO_9506_MMS_1::ObjectName GetScatteredAccessAttributes_Request;
    // sequence ObtainFile-Request

    struct ObtainFile_Request {

        ObtainFile_Request();

        ObtainFile_Request(const ISO_9506_MMS_1::FileName& arg__sourceFile,
                const ISO_9506_MMS_1::FileName& arg__destinationFile);

        ObtainFile_Request(shared_ptr< MMS_Environment_1::ApplicationReference> arg__sourceFileServer,
                shared_ptr< ISO_9506_MMS_1::FileName> arg__sourceFile,
                shared_ptr< ISO_9506_MMS_1::FileName> arg__destinationFile);

        ITU_T_OPTIONAL_DECL(sourceFileServer, MMS_Environment_1::ApplicationReference);
        ITU_T_HOLDERH_DECL(sourceFile, ISO_9506_MMS_1::FileName);
        ITU_T_HOLDERH_DECL(destinationFile, ISO_9506_MMS_1::FileName);

        ITU_T_ARCHIVE_FUNC;
    };

    const ObtainFile_Error obtainFile_Error_source_file = 0;
    const ObtainFile_Error obtainFile_Error_destination_file = 1;

    // sequence FileOpen-Request

    struct FileOpen_Request {

        FileOpen_Request();

        FileOpen_Request(const ISO_9506_MMS_1::FileName& arg__fileName,
                const ISO_9506_MMS_1::Unsigned32& arg__initialPosition);

        ITU_T_HOLDERH_DECL(fileName, ISO_9506_MMS_1::FileName);
        ITU_T_HOLDERH_DECL(initialPosition, ISO_9506_MMS_1::Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence FileOpen-Response

    struct FileOpen_Response {

        FileOpen_Response();

        FileOpen_Response(const ISO_9506_MMS_1::Integer32& arg__frsmID,
                const FileAttributes& arg__fileAttributes);

        ITU_T_HOLDERH_DECL(frsmID, ISO_9506_MMS_1::Integer32); //   Ic(  [ -2147483648  ...   2147483647 ]   
        ITU_T_HOLDERH_DECL(fileAttributes, FileAttributes);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence FileRead-Response

    struct FileRead_Response {

        static const bool moreFollows__default;

        FileRead_Response();

        FileRead_Response(const octetstring_type& arg__fileData);

        FileRead_Response(shared_ptr< octetstring_type> arg__fileData,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(fileData, octetstring_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence FileRename-Request

    struct FileRename_Request {

        FileRename_Request();

        FileRename_Request(const ISO_9506_MMS_1::FileName& arg__currentFileName,
                const ISO_9506_MMS_1::FileName& arg__newFileName);

        ITU_T_HOLDERH_DECL(currentFileName, ISO_9506_MMS_1::FileName);
        ITU_T_HOLDERH_DECL(newFileName, ISO_9506_MMS_1::FileName);

        ITU_T_ARCHIVE_FUNC;
    };

    const FileRename_Error fileRename_Error_source_file = 0;
    const FileRename_Error fileRename_Error_destination_file = 1;

    // sequence FileDirectory-Request

    struct FileDirectory_Request {

        FileDirectory_Request();

        FileDirectory_Request(shared_ptr< ISO_9506_MMS_1::FileName> arg__fileSpecification,
                shared_ptr< ISO_9506_MMS_1::FileName> arg__continueAfter);

        ITU_T_OPTIONAL_DECL(fileSpecification, ISO_9506_MMS_1::FileName);
        ITU_T_OPTIONAL_DECL(continueAfter, ISO_9506_MMS_1::FileName);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence FileDirectory-Response

    struct FileDirectory_Response {

        typedef std::vector< DirectoryEntry > ListOfDirectoryEntry_type;

        static const bool moreFollows__default;

        FileDirectory_Response();

        FileDirectory_Response(const ListOfDirectoryEntry_type& arg__listOfDirectoryEntry);

        FileDirectory_Response(shared_ptr< ListOfDirectoryEntry_type> arg__listOfDirectoryEntry,
                shared_ptr< bool> arg__moreFollows);

        ITU_T_HOLDERH_DECL(listOfDirectoryEntry, ListOfDirectoryEntry_type);
        ITU_T_DEFAULTH_DECL(moreFollows, bool, moreFollows__default);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DirectoryEntry

    struct DirectoryEntry {

        DirectoryEntry();

        DirectoryEntry(const ISO_9506_MMS_1::FileName& arg__fileName,
                const FileAttributes& arg__fileAttributes);

        ITU_T_HOLDERH_DECL(fileName, ISO_9506_MMS_1::FileName);
        ITU_T_HOLDERH_DECL(fileAttributes, FileAttributes);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence FileAttributes

    struct FileAttributes {

        FileAttributes();

        FileAttributes(const ISO_9506_MMS_1::Unsigned32& arg__sizeOfFile);

        FileAttributes(shared_ptr< ISO_9506_MMS_1::Unsigned32> arg__sizeOfFile,
                shared_ptr< gentime_type> arg__lastModified);

        ITU_T_HOLDERH_DECL(sizeOfFile, ISO_9506_MMS_1::Unsigned32); //   Ic(  [ 0  ...   2147483647 ]   
        ITU_T_OPTIONAL_DECL(lastModified, gentime_type);

        ITU_T_ARCHIVE_FUNC;
    };

    struct ScatteredAccessDescription_sequence_of {

        ScatteredAccessDescription_sequence_of();

        ScatteredAccessDescription_sequence_of(const ISO_9506_MMS_1::VariableSpecification& arg__variableSpecification);

        ScatteredAccessDescription_sequence_of(shared_ptr< ISO_9506_MMS_1::Identifier> arg__componentName,
                shared_ptr< ISO_9506_MMS_1::VariableSpecification> arg__variableSpecification,
                shared_ptr< ISO_9506_MMS_1::AlternateAccess> arg__alternateAccess);

        ITU_T_OPTIONAL_DECL(componentName, ISO_9506_MMS_1::Identifier);
        ITU_T_HOLDERH_DECL(variableSpecification, ISO_9506_MMS_1::VariableSpecification);
        ITU_T_OPTIONAL_DECL(alternateAccess, ISO_9506_MMS_1::AlternateAccess);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence DefineScatteredAccess-Request

    struct DefineScatteredAccess_Request {

        DefineScatteredAccess_Request();

        DefineScatteredAccess_Request(const ISO_9506_MMS_1::ObjectName& arg__scatteredAccessName,
                const ScatteredAccessDescription& arg__scatteredAccessDescription);

        ITU_T_HOLDERH_DECL(scatteredAccessName, ISO_9506_MMS_1::ObjectName);
        ITU_T_HOLDERH_DECL(scatteredAccessDescription, ScatteredAccessDescription);

        ITU_T_ARCHIVE_FUNC;
    };

    // sequence GetScatteredAccessAttributes-Response

    struct GetScatteredAccessAttributes_Response {

        GetScatteredAccessAttributes_Response();

        GetScatteredAccessAttributes_Response(const bool& arg__mmsDeletable,
                const ScatteredAccessDescription& arg__scatteredAccessDescription);

        GetScatteredAccessAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
                shared_ptr< ScatteredAccessDescription> arg__scatteredAccessDescription,
                shared_ptr< ISO_9506_MMS_1::Identifier> arg__accessControlList);

        ITU_T_HOLDERH_DECL(mmsDeletable, bool);
        ITU_T_HOLDERH_DECL(scatteredAccessDescription, ScatteredAccessDescription);
        ITU_T_OPTIONAL_DECL(accessControlList, ISO_9506_MMS_1::Identifier);

        ITU_T_ARCHIVE_FUNC;
    };

    ITU_T_ARCHIVE_X690_DECL(ObtainFile_Request);
    ITU_T_ARCHIVE_X690_DECL(FileOpen_Request);
    ITU_T_ARCHIVE_X690_DECL(FileOpen_Response);
    ITU_T_ARCHIVE_X690_DECL(FileRead_Response);
    ITU_T_ARCHIVE_X690_DECL(FileRename_Request);
    ITU_T_ARCHIVE_X690_DECL(FileDirectory_Request);
    ITU_T_ARCHIVE_X690_DECL(FileDirectory_Response);
    ITU_T_ARCHIVE_X690_DECL(DirectoryEntry);
    ITU_T_ARCHIVE_X690_DECL(FileAttributes);
    ITU_T_ARCHIVE_X690_DECL(ScatteredAccessDescription_sequence_of);
    ITU_T_ARCHIVE_X690_DECL(DefineScatteredAccess_Request);
    ITU_T_ARCHIVE_X690_DECL(GetScatteredAccessAttributes_Response);

    ITU_T_ARCHIVE_X691_DECL(ObtainFile_Request);
    ITU_T_ARCHIVE_X691_DECL(FileOpen_Request);
    ITU_T_ARCHIVE_X691_DECL(FileOpen_Response);
    ITU_T_ARCHIVE_X691_DECL(FileRead_Response);
    ITU_T_ARCHIVE_X691_DECL(FileRename_Request);
    ITU_T_ARCHIVE_X691_DECL(FileDirectory_Request);
    ITU_T_ARCHIVE_X691_DECL(FileDirectory_Response);
    ITU_T_ARCHIVE_X691_DECL(DirectoryEntry);
    ITU_T_ARCHIVE_X691_DECL(FileAttributes);
    ITU_T_ARCHIVE_X691_DECL(ScatteredAccessDescription_sequence_of);
    ITU_T_ARCHIVE_X691_DECL(DefineScatteredAccess_Request);
    ITU_T_ARCHIVE_X691_DECL(GetScatteredAccessAttributes_Response);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif  /*___ISO_9506_MMS_1A */
