#ifndef ___ISO_9506_MMS_1A
#define ___ISO_9506_MMS_1A

#include <boost/itu/asn1/asnbase.hpp>
#include <boost/itu/x69X/x690.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1A {

    using boost::asn1::null_type;
    using boost::asn1::enumerated_type;
    using boost::asn1::bitstring_type;
    using boost::asn1::octetstring_type;
    using boost::asn1::oid_type;
    using boost::asn1::reloid_type;
    using boost::asn1::utctime_type;
    using boost::asn1::gentime_type;
    using boost::asn1::ia5string_type;
    using boost::asn1::printablestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::visiblestring_type;
    using boost::asn1::numericstring_type;
    using boost::asn1::universalstring_type;
    using boost::asn1::bmpstring_type;
    using boost::asn1::utf8string_type;
    using boost::asn1::generalstring_type;
    using boost::asn1::graphicstring_type;
    using boost::asn1::t61string_type;
    using boost::asn1::t61string_type;
    using boost::asn1::videotexstring_type;
    using boost::asn1::objectdescriptor_type;
    using boost::asn1::external_type;
    using boost::asn1::embeded_type;
    using boost::asn1::characterstring_type;
    using boost::asn1::any_type;
    using boost::asn1::value_holder;
    using boost::asn1::default_holder;


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

    typedef std::vector< ScatteredAccessDescription_sequence_of > ScatteredAccessDescription;


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

    struct ObtainFile_Request {

        ObtainFile_Request();

        ObtainFile_Request(const ISO_9506_MMS_1::FileName& __sourceFile,
                const ISO_9506_MMS_1::FileName& __destinationFile);

        ObtainFile_Request(boost::shared_ptr< MMS_Environment_1::ApplicationReference> __sourceFileServer,
                boost::shared_ptr< ISO_9506_MMS_1::FileName> __sourceFile,
                boost::shared_ptr< ISO_9506_MMS_1::FileName> __destinationFile);

        BOOST_ASN_VALUE_OPTIONAL_DECL(sourceFileServer, MMS_Environment_1::ApplicationReference);
        BOOST_ASN_VALUE_HOLDERH_DECL(sourceFile, ISO_9506_MMS_1::FileName);
        BOOST_ASN_VALUE_HOLDERH_DECL(destinationFile, ISO_9506_MMS_1::FileName);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<MMS_Environment_1::ApplicationReference> sourceFileServer_;
        value_holder<ISO_9506_MMS_1::FileName> sourceFile_;
        value_holder<ISO_9506_MMS_1::FileName> destinationFile_;
    };

    extern const ObtainFile_Error ObtainFile_Error_source_file;
    extern const ObtainFile_Error ObtainFile_Error_destination_file;

    // sequence FileOpen-Request

    struct FileOpen_Request {

        FileOpen_Request();

        FileOpen_Request(const ISO_9506_MMS_1::FileName& __fileName,
                const ISO_9506_MMS_1::Unsigned32& __initialPosition);

        BOOST_ASN_VALUE_HOLDERH_DECL(fileName, ISO_9506_MMS_1::FileName);
        BOOST_ASN_VALUE_HOLDERH_DECL(initialPosition, ISO_9506_MMS_1::Unsigned32);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::FileName> fileName_;
        value_holder<ISO_9506_MMS_1::Unsigned32> initialPosition_;
    };

    // sequence FileOpen-Response

    struct FileOpen_Response {

        FileOpen_Response();

        FileOpen_Response(const ISO_9506_MMS_1::Integer32& __frsmID,
                const FileAttributes& __fileAttributes);

        BOOST_ASN_VALUE_HOLDERH_DECL(frsmID, ISO_9506_MMS_1::Integer32);
        BOOST_ASN_VALUE_HOLDERH_DECL(fileAttributes, FileAttributes);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::Integer32> frsmID_;
        value_holder<FileAttributes> fileAttributes_;
    };

    // sequence FileRead-Response

    struct FileRead_Response {

        static const bool moreFollows__default;

        FileRead_Response();

        FileRead_Response(const octetstring_type& __fileData);

        FileRead_Response(boost::shared_ptr< octetstring_type> __fileData,
                boost::shared_ptr< bool> __moreFollows);

        BOOST_ASN_VALUE_HOLDERH_DECL(fileData, octetstring_type);
        BOOST_ASN_VALUE_DEFAULT_DECL(moreFollows, bool);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<octetstring_type> fileData_;
        default_holder<bool, moreFollows__default> moreFollows_;
    };

    // sequence FileRename-Request

    struct FileRename_Request {

        FileRename_Request();

        FileRename_Request(const ISO_9506_MMS_1::FileName& __currentFileName,
                const ISO_9506_MMS_1::FileName& __newFileName);

        BOOST_ASN_VALUE_HOLDERH_DECL(currentFileName, ISO_9506_MMS_1::FileName);
        BOOST_ASN_VALUE_HOLDERH_DECL(newFileName, ISO_9506_MMS_1::FileName);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::FileName> currentFileName_;
        value_holder<ISO_9506_MMS_1::FileName> newFileName_;
    };

    extern const FileRename_Error FileRename_Error_source_file;
    extern const FileRename_Error FileRename_Error_destination_file;

    // sequence FileDirectory-Request

    struct FileDirectory_Request {

        FileDirectory_Request();

        FileDirectory_Request(boost::shared_ptr< ISO_9506_MMS_1::FileName> __fileSpecification,
                boost::shared_ptr< ISO_9506_MMS_1::FileName> __continueAfter);

        BOOST_ASN_VALUE_OPTIONAL_DECL(fileSpecification, ISO_9506_MMS_1::FileName);
        BOOST_ASN_VALUE_OPTIONAL_DECL(continueAfter, ISO_9506_MMS_1::FileName);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<ISO_9506_MMS_1::FileName> fileSpecification_;
        boost::shared_ptr<ISO_9506_MMS_1::FileName> continueAfter_;
    };

    // sequence FileDirectory-Response

    struct FileDirectory_Response {

        typedef std::vector< DirectoryEntry > listOfDirectoryEntry_type;

        static const bool moreFollows__default;

        FileDirectory_Response();

        FileDirectory_Response(const listOfDirectoryEntry_type& __listOfDirectoryEntry);

        FileDirectory_Response(boost::shared_ptr< listOfDirectoryEntry_type> __listOfDirectoryEntry,
                boost::shared_ptr< bool> __moreFollows);

        BOOST_ASN_VALUE_HOLDERH_DECL(listOfDirectoryEntry, listOfDirectoryEntry_type);
        BOOST_ASN_VALUE_DEFAULT_DECL(moreFollows, bool);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<listOfDirectoryEntry_type> listOfDirectoryEntry_;
        default_holder<bool, moreFollows__default> moreFollows_;
    };

    // sequence DirectoryEntry

    struct DirectoryEntry {

        DirectoryEntry();

        DirectoryEntry(const ISO_9506_MMS_1::FileName& __fileName,
                const FileAttributes& __fileAttributes);

        BOOST_ASN_VALUE_HOLDERH_DECL(fileName, ISO_9506_MMS_1::FileName);
        BOOST_ASN_VALUE_HOLDERH_DECL(fileAttributes, FileAttributes);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::FileName> fileName_;
        value_holder<FileAttributes> fileAttributes_;
    };

    // sequence FileAttributes

    struct FileAttributes {

        FileAttributes();

        FileAttributes(const ISO_9506_MMS_1::Unsigned32& __sizeOfFile);

        FileAttributes(boost::shared_ptr< ISO_9506_MMS_1::Unsigned32> __sizeOfFile,
                boost::shared_ptr< gentime_type> __lastModified);

        BOOST_ASN_VALUE_HOLDERH_DECL(sizeOfFile, ISO_9506_MMS_1::Unsigned32);
        BOOST_ASN_VALUE_OPTIONAL_DECL(lastModified, gentime_type);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::Unsigned32> sizeOfFile_;
        boost::shared_ptr<gentime_type> lastModified_;
    };

    struct ScatteredAccessDescription_sequence_of {

        ScatteredAccessDescription_sequence_of();

        ScatteredAccessDescription_sequence_of(const ISO_9506_MMS_1::VariableSpecification& __variableSpecification);

        ScatteredAccessDescription_sequence_of(boost::shared_ptr< ISO_9506_MMS_1::Identifier> __componentName,
                boost::shared_ptr< ISO_9506_MMS_1::VariableSpecification> __variableSpecification,
                boost::shared_ptr< ISO_9506_MMS_1::AlternateAccess> __alternateAccess);

        BOOST_ASN_VALUE_OPTIONAL_DECL(componentName, ISO_9506_MMS_1::Identifier);
        BOOST_ASN_VALUE_HOLDERH_DECL(variableSpecification, ISO_9506_MMS_1::VariableSpecification);
        BOOST_ASN_VALUE_OPTIONAL_DECL(alternateAccess, ISO_9506_MMS_1::AlternateAccess);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        boost::shared_ptr<ISO_9506_MMS_1::Identifier> componentName_;
        value_holder<ISO_9506_MMS_1::VariableSpecification> variableSpecification_;
        boost::shared_ptr<ISO_9506_MMS_1::AlternateAccess> alternateAccess_;
    };

    // sequence DefineScatteredAccess-Request

    struct DefineScatteredAccess_Request {

        DefineScatteredAccess_Request();

        DefineScatteredAccess_Request(const ISO_9506_MMS_1::ObjectName& __scatteredAccessName,
                const ScatteredAccessDescription& __scatteredAccessDescription);

        BOOST_ASN_VALUE_HOLDERH_DECL(scatteredAccessName, ISO_9506_MMS_1::ObjectName);
        BOOST_ASN_VALUE_HOLDERH_DECL(scatteredAccessDescription, ScatteredAccessDescription);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<ISO_9506_MMS_1::ObjectName> scatteredAccessName_;
        value_holder<ScatteredAccessDescription> scatteredAccessDescription_;
    };

    // sequence GetScatteredAccessAttributes-Response

    struct GetScatteredAccessAttributes_Response {

        GetScatteredAccessAttributes_Response();

        GetScatteredAccessAttributes_Response(const bool& __mmsDeletable,
                const ScatteredAccessDescription& __scatteredAccessDescription);

        GetScatteredAccessAttributes_Response(boost::shared_ptr< bool> __mmsDeletable,
                boost::shared_ptr< ScatteredAccessDescription> __scatteredAccessDescription,
                boost::shared_ptr< ISO_9506_MMS_1::Identifier> __accessControlList);

        BOOST_ASN_VALUE_HOLDERH_DECL(mmsDeletable, bool);
        BOOST_ASN_VALUE_HOLDERH_DECL(scatteredAccessDescription, ScatteredAccessDescription);
        BOOST_ASN_VALUE_OPTIONAL_DECL(accessControlList, ISO_9506_MMS_1::Identifier);

        BOOST_ASN_ARCHIVE_FUNC;

    private:

        value_holder<bool> mmsDeletable_;
        value_holder<ScatteredAccessDescription> scatteredAccessDescription_;
        boost::shared_ptr<ISO_9506_MMS_1::Identifier> accessControlList_;
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

