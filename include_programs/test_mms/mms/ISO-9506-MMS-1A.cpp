#include "ISO-9506-MMS-1A.hpp"

namespace ISO_9506_MMS_1A {

    // sequence ObtainFile-Request

    ObtainFile_Request::ObtainFile_Request() : sourceFile_(), destinationFile_() {
    };

    ObtainFile_Request::ObtainFile_Request(const ISO_9506_MMS_1::FileName& __sourceFile,
            const ISO_9506_MMS_1::FileName& __destinationFile) :
    sourceFile_(__sourceFile),
    destinationFile_(__destinationFile) {
    };

    ObtainFile_Request::ObtainFile_Request(boost::shared_ptr< MMS_Environment_1::ApplicationReference> __sourceFileServer,
            boost::shared_ptr< ISO_9506_MMS_1::FileName> __sourceFile,
            boost::shared_ptr< ISO_9506_MMS_1::FileName> __destinationFile) :
    sourceFileServer_(__sourceFileServer),
    sourceFile_(__sourceFile),
    destinationFile_(__destinationFile) {
    };

    template<> void ObtainFile_Request::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(sourceFileServer_, 0);
        BOOST_ASN_IMPLICIT_TAG(sourceFile_, 1);
        BOOST_ASN_IMPLICIT_TAG(destinationFile_, 2);
    }

    template<> void ObtainFile_Request::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(sourceFileServer_, 0);
        BOOST_ASN_IMPLICIT_TAG(sourceFile_, 1);
        BOOST_ASN_IMPLICIT_TAG(destinationFile_, 2);
    }

    boost::shared_ptr<MMS_Environment_1::ApplicationReference> ObtainFile_Request::sourceFileServer__new() {
        return sourceFileServer_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference());
    }

    void ObtainFile_Request::sourceFileServer(const MMS_Environment_1::ApplicationReference& vl) {
        sourceFileServer_ = boost::shared_ptr<MMS_Environment_1::ApplicationReference>(new MMS_Environment_1::ApplicationReference(vl));
    }

    ISO_9506_MMS_1::FileName& ObtainFile_Request::sourceFile() {
        return *sourceFile_;
    }

    const ISO_9506_MMS_1::FileName& ObtainFile_Request::sourceFile() const {
        return *sourceFile_;
    }

    void ObtainFile_Request::sourceFile(const ISO_9506_MMS_1::FileName& vl) {
        sourceFile_ = vl;
    }

    void ObtainFile_Request::sourceFile(boost::shared_ptr< ISO_9506_MMS_1::FileName> vl) {
        sourceFile_ = vl;
    }

    ISO_9506_MMS_1::FileName& ObtainFile_Request::destinationFile() {
        return *destinationFile_;
    }

    const ISO_9506_MMS_1::FileName& ObtainFile_Request::destinationFile() const {
        return *destinationFile_;
    }

    void ObtainFile_Request::destinationFile(const ISO_9506_MMS_1::FileName& vl) {
        destinationFile_ = vl;
    }

    void ObtainFile_Request::destinationFile(boost::shared_ptr< ISO_9506_MMS_1::FileName> vl) {
        destinationFile_ = vl;
    }


    const ObtainFile_Error ObtainFile_Error_source_file = 0;
    const ObtainFile_Error ObtainFile_Error_destination_file = 1;

    // sequence FileOpen-Request

    FileOpen_Request::FileOpen_Request() : fileName_(), initialPosition_() {
    };

    FileOpen_Request::FileOpen_Request(const ISO_9506_MMS_1::FileName& __fileName,
            const ISO_9506_MMS_1::Unsigned32& __initialPosition) :
    fileName_(__fileName),
    initialPosition_(__initialPosition) {
    };

    template<> void FileOpen_Request::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(fileName_, 0);
        BOOST_ASN_IMPLICIT_TAG(initialPosition_, 1);
    }

    template<> void FileOpen_Request::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(fileName_, 0);
        BOOST_ASN_IMPLICIT_TAG(initialPosition_, 1);
    }

    ISO_9506_MMS_1::FileName& FileOpen_Request::fileName() {
        return *fileName_;
    }

    const ISO_9506_MMS_1::FileName& FileOpen_Request::fileName() const {
        return *fileName_;
    }

    void FileOpen_Request::fileName(const ISO_9506_MMS_1::FileName& vl) {
        fileName_ = vl;
    }

    void FileOpen_Request::fileName(boost::shared_ptr< ISO_9506_MMS_1::FileName> vl) {
        fileName_ = vl;
    }

    ISO_9506_MMS_1::Unsigned32& FileOpen_Request::initialPosition() {
        return *initialPosition_;
    }

    const ISO_9506_MMS_1::Unsigned32& FileOpen_Request::initialPosition() const {
        return *initialPosition_;
    }

    void FileOpen_Request::initialPosition(const ISO_9506_MMS_1::Unsigned32& vl) {
        initialPosition_ = vl;
    }

    void FileOpen_Request::initialPosition(boost::shared_ptr< ISO_9506_MMS_1::Unsigned32> vl) {
        initialPosition_ = vl;
    }


    // sequence FileOpen-Response

    FileOpen_Response::FileOpen_Response() : frsmID_(), fileAttributes_() {
    };

    FileOpen_Response::FileOpen_Response(const ISO_9506_MMS_1::Integer32& __frsmID,
            const FileAttributes& __fileAttributes) :
    frsmID_(__frsmID),
    fileAttributes_(__fileAttributes) {
    };

    template<> void FileOpen_Response::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(frsmID_, 0);
        BOOST_ASN_IMPLICIT_TAG(fileAttributes_, 1);
    }

    template<> void FileOpen_Response::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(frsmID_, 0);
        BOOST_ASN_IMPLICIT_TAG(fileAttributes_, 1);
    }

    ISO_9506_MMS_1::Integer32& FileOpen_Response::frsmID() {
        return *frsmID_;
    }

    const ISO_9506_MMS_1::Integer32& FileOpen_Response::frsmID() const {
        return *frsmID_;
    }

    void FileOpen_Response::frsmID(const ISO_9506_MMS_1::Integer32& vl) {
        frsmID_ = vl;
    }

    void FileOpen_Response::frsmID(boost::shared_ptr< ISO_9506_MMS_1::Integer32> vl) {
        frsmID_ = vl;
    }

    FileAttributes& FileOpen_Response::fileAttributes() {
        return *fileAttributes_;
    }

    const FileAttributes& FileOpen_Response::fileAttributes() const {
        return *fileAttributes_;
    }

    void FileOpen_Response::fileAttributes(const FileAttributes& vl) {
        fileAttributes_ = vl;
    }

    void FileOpen_Response::fileAttributes(boost::shared_ptr< FileAttributes> vl) {
        fileAttributes_ = vl;
    }


    // sequence FileRead-Response

    FileRead_Response::FileRead_Response() : fileData_() {
    };

    FileRead_Response::FileRead_Response(const octetstring_type& __fileData) :
    fileData_(__fileData) {
    };

    FileRead_Response::FileRead_Response(boost::shared_ptr< octetstring_type> __fileData,
            boost::shared_ptr< bool> __moreFollows) :
    fileData_(__fileData),
    moreFollows_(__moreFollows) {
    };

    const bool FileRead_Response::moreFollows__default = true;

    template<> void FileRead_Response::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(fileData_, 0);
        BOOST_ASN_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void FileRead_Response::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(fileData_, 0);
        BOOST_ASN_IMPLICIT_TAG(moreFollows_, 1);
    }

    octetstring_type& FileRead_Response::fileData() {
        return *fileData_;
    }

    const octetstring_type& FileRead_Response::fileData() const {
        return *fileData_;
    }

    void FileRead_Response::fileData(const octetstring_type& vl) {
        fileData_ = vl;
    }

    void FileRead_Response::fileData(boost::shared_ptr< octetstring_type> vl) {
        fileData_ = vl;
    }

    const bool& FileRead_Response::moreFollows() const {
        return *moreFollows_;
    }

    void FileRead_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void FileRead_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


    // sequence FileRename-Request

    FileRename_Request::FileRename_Request() : currentFileName_(), newFileName_() {
    };

    FileRename_Request::FileRename_Request(const ISO_9506_MMS_1::FileName& __currentFileName,
            const ISO_9506_MMS_1::FileName& __newFileName) :
    currentFileName_(__currentFileName),
    newFileName_(__newFileName) {
    };

    template<> void FileRename_Request::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(currentFileName_, 0);
        BOOST_ASN_IMPLICIT_TAG(newFileName_, 1);
    }

    template<> void FileRename_Request::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(currentFileName_, 0);
        BOOST_ASN_IMPLICIT_TAG(newFileName_, 1);
    }

    ISO_9506_MMS_1::FileName& FileRename_Request::currentFileName() {
        return *currentFileName_;
    }

    const ISO_9506_MMS_1::FileName& FileRename_Request::currentFileName() const {
        return *currentFileName_;
    }

    void FileRename_Request::currentFileName(const ISO_9506_MMS_1::FileName& vl) {
        currentFileName_ = vl;
    }

    void FileRename_Request::currentFileName(boost::shared_ptr< ISO_9506_MMS_1::FileName> vl) {
        currentFileName_ = vl;
    }

    ISO_9506_MMS_1::FileName& FileRename_Request::newFileName() {
        return *newFileName_;
    }

    const ISO_9506_MMS_1::FileName& FileRename_Request::newFileName() const {
        return *newFileName_;
    }

    void FileRename_Request::newFileName(const ISO_9506_MMS_1::FileName& vl) {
        newFileName_ = vl;
    }

    void FileRename_Request::newFileName(boost::shared_ptr< ISO_9506_MMS_1::FileName> vl) {
        newFileName_ = vl;
    }


    const FileRename_Error FileRename_Error_source_file = 0;
    const FileRename_Error FileRename_Error_destination_file = 1;

    // sequence FileDirectory-Request

    FileDirectory_Request::FileDirectory_Request() {
    };

    FileDirectory_Request::FileDirectory_Request(boost::shared_ptr< ISO_9506_MMS_1::FileName> __fileSpecification,
            boost::shared_ptr< ISO_9506_MMS_1::FileName> __continueAfter) :
    fileSpecification_(__fileSpecification),
    continueAfter_(__continueAfter) {
    };

    template<> void FileDirectory_Request::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(fileSpecification_, 0);
        BOOST_ASN_IMPLICIT_TAG(continueAfter_, 1);
    }

    template<> void FileDirectory_Request::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(fileSpecification_, 0);
        BOOST_ASN_IMPLICIT_TAG(continueAfter_, 1);
    }

    boost::shared_ptr<ISO_9506_MMS_1::FileName> FileDirectory_Request::fileSpecification__new() {
        return fileSpecification_ = boost::shared_ptr<ISO_9506_MMS_1::FileName>(new ISO_9506_MMS_1::FileName());
    }

    void FileDirectory_Request::fileSpecification(const ISO_9506_MMS_1::FileName& vl) {
        fileSpecification_ = boost::shared_ptr<ISO_9506_MMS_1::FileName>(new ISO_9506_MMS_1::FileName(vl));
    }

    boost::shared_ptr<ISO_9506_MMS_1::FileName> FileDirectory_Request::continueAfter__new() {
        return continueAfter_ = boost::shared_ptr<ISO_9506_MMS_1::FileName>(new ISO_9506_MMS_1::FileName());
    }

    void FileDirectory_Request::continueAfter(const ISO_9506_MMS_1::FileName& vl) {
        continueAfter_ = boost::shared_ptr<ISO_9506_MMS_1::FileName>(new ISO_9506_MMS_1::FileName(vl));
    }


    // sequence FileDirectory-Response

    FileDirectory_Response::FileDirectory_Response() : listOfDirectoryEntry_() {
    };

    FileDirectory_Response::FileDirectory_Response(const listOfDirectoryEntry_type& __listOfDirectoryEntry) :
    listOfDirectoryEntry_(__listOfDirectoryEntry) {
    };

    FileDirectory_Response::FileDirectory_Response(boost::shared_ptr< listOfDirectoryEntry_type> __listOfDirectoryEntry,
            boost::shared_ptr< bool> __moreFollows) :
    listOfDirectoryEntry_(__listOfDirectoryEntry),
    moreFollows_(__moreFollows) {
    };

    const bool FileDirectory_Response::moreFollows__default = false;

    template<> void FileDirectory_Response::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_EXPLICIT_TAG(listOfDirectoryEntry_, 0);
        BOOST_ASN_IMPLICIT_TAG(moreFollows_, 1);
    }

    template<> void FileDirectory_Response::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_EXPLICIT_TAG(listOfDirectoryEntry_, 0);
        BOOST_ASN_IMPLICIT_TAG(moreFollows_, 1);
    }

    FileDirectory_Response::listOfDirectoryEntry_type& FileDirectory_Response::listOfDirectoryEntry() {
        return *listOfDirectoryEntry_;
    }

    const FileDirectory_Response::listOfDirectoryEntry_type& FileDirectory_Response::listOfDirectoryEntry() const {
        return *listOfDirectoryEntry_;
    }

    void FileDirectory_Response::listOfDirectoryEntry(const listOfDirectoryEntry_type& vl) {
        listOfDirectoryEntry_ = vl;
    }

    void FileDirectory_Response::listOfDirectoryEntry(boost::shared_ptr< listOfDirectoryEntry_type> vl) {
        listOfDirectoryEntry_ = vl;
    }

    const bool& FileDirectory_Response::moreFollows() const {
        return *moreFollows_;
    }

    void FileDirectory_Response::moreFollows(const bool& vl) {
        moreFollows_ = vl;
    }

    void FileDirectory_Response::moreFollows(boost::shared_ptr< bool> vl) {
        moreFollows_ = vl;
    }


    // sequence DirectoryEntry

    DirectoryEntry::DirectoryEntry() : fileName_(), fileAttributes_() {
    };

    DirectoryEntry::DirectoryEntry(const ISO_9506_MMS_1::FileName& __fileName,
            const FileAttributes& __fileAttributes) :
    fileName_(__fileName),
    fileAttributes_(__fileAttributes) {
    };

    template<> void DirectoryEntry::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(fileName_, 0);
        BOOST_ASN_IMPLICIT_TAG(fileAttributes_, 1);
    }

    template<> void DirectoryEntry::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(fileName_, 0);
        BOOST_ASN_IMPLICIT_TAG(fileAttributes_, 1);
    }

    ISO_9506_MMS_1::FileName& DirectoryEntry::fileName() {
        return *fileName_;
    }

    const ISO_9506_MMS_1::FileName& DirectoryEntry::fileName() const {
        return *fileName_;
    }

    void DirectoryEntry::fileName(const ISO_9506_MMS_1::FileName& vl) {
        fileName_ = vl;
    }

    void DirectoryEntry::fileName(boost::shared_ptr< ISO_9506_MMS_1::FileName> vl) {
        fileName_ = vl;
    }

    FileAttributes& DirectoryEntry::fileAttributes() {
        return *fileAttributes_;
    }

    const FileAttributes& DirectoryEntry::fileAttributes() const {
        return *fileAttributes_;
    }

    void DirectoryEntry::fileAttributes(const FileAttributes& vl) {
        fileAttributes_ = vl;
    }

    void DirectoryEntry::fileAttributes(boost::shared_ptr< FileAttributes> vl) {
        fileAttributes_ = vl;
    }


    // sequence FileAttributes

    FileAttributes::FileAttributes() : sizeOfFile_() {
    };

    FileAttributes::FileAttributes(const ISO_9506_MMS_1::Unsigned32& __sizeOfFile) :
    sizeOfFile_(__sizeOfFile) {
    };

    FileAttributes::FileAttributes(boost::shared_ptr< ISO_9506_MMS_1::Unsigned32> __sizeOfFile,
            boost::shared_ptr< gentime_type> __lastModified) :
    sizeOfFile_(__sizeOfFile),
    lastModified_(__lastModified) {
    };

    template<> void FileAttributes::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(sizeOfFile_, 0);
        BOOST_ASN_IMPLICIT_TAG(lastModified_, 1);
    }

    template<> void FileAttributes::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(sizeOfFile_, 0);
        BOOST_ASN_IMPLICIT_TAG(lastModified_, 1);
    }

    ISO_9506_MMS_1::Unsigned32& FileAttributes::sizeOfFile() {
        return *sizeOfFile_;
    }

    const ISO_9506_MMS_1::Unsigned32& FileAttributes::sizeOfFile() const {
        return *sizeOfFile_;
    }

    void FileAttributes::sizeOfFile(const ISO_9506_MMS_1::Unsigned32& vl) {
        sizeOfFile_ = vl;
    }

    void FileAttributes::sizeOfFile(boost::shared_ptr< ISO_9506_MMS_1::Unsigned32> vl) {
        sizeOfFile_ = vl;
    }

    boost::shared_ptr<gentime_type> FileAttributes::lastModified__new() {
        return lastModified_ = boost::shared_ptr<gentime_type>(new gentime_type());
    }

    void FileAttributes::lastModified(const gentime_type& vl) {
        lastModified_ = boost::shared_ptr<gentime_type>(new gentime_type(vl));
    }

    ScatteredAccessDescription_sequence_of::ScatteredAccessDescription_sequence_of() : variableSpecification_() {
    };

    ScatteredAccessDescription_sequence_of::ScatteredAccessDescription_sequence_of(const ISO_9506_MMS_1::VariableSpecification& __variableSpecification) :
    variableSpecification_(__variableSpecification) {
    };

    ScatteredAccessDescription_sequence_of::ScatteredAccessDescription_sequence_of(boost::shared_ptr< ISO_9506_MMS_1::Identifier> __componentName,
            boost::shared_ptr< ISO_9506_MMS_1::VariableSpecification> __variableSpecification,
            boost::shared_ptr< ISO_9506_MMS_1::AlternateAccess> __alternateAccess) :
    componentName_(__componentName),
    variableSpecification_(__variableSpecification),
    alternateAccess_(__alternateAccess) {
    };

    template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(componentName_, 0);
        BOOST_ASN_CHOICE_TAG(variableSpecification_, 1);
        BOOST_ASN_IMPLICIT_TAG(alternateAccess_, 2);
    }

    template<> void ScatteredAccessDescription_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(componentName_, 0);
        BOOST_ASN_CHOICE_TAG(variableSpecification_, 1);
        BOOST_ASN_IMPLICIT_TAG(alternateAccess_, 2);
    }

    boost::shared_ptr<ISO_9506_MMS_1::Identifier> ScatteredAccessDescription_sequence_of::componentName__new() {
        return componentName_ = boost::shared_ptr<ISO_9506_MMS_1::Identifier>(new ISO_9506_MMS_1::Identifier());
    }

    void ScatteredAccessDescription_sequence_of::componentName(const ISO_9506_MMS_1::Identifier& vl) {
        componentName_ = boost::shared_ptr<ISO_9506_MMS_1::Identifier>(new ISO_9506_MMS_1::Identifier(vl));
    }

    ISO_9506_MMS_1::VariableSpecification& ScatteredAccessDescription_sequence_of::variableSpecification() {
        return *variableSpecification_;
    }

    const ISO_9506_MMS_1::VariableSpecification& ScatteredAccessDescription_sequence_of::variableSpecification() const {
        return *variableSpecification_;
    }

    void ScatteredAccessDescription_sequence_of::variableSpecification(const ISO_9506_MMS_1::VariableSpecification& vl) {
        variableSpecification_ = vl;
    }

    void ScatteredAccessDescription_sequence_of::variableSpecification(boost::shared_ptr< ISO_9506_MMS_1::VariableSpecification> vl) {
        variableSpecification_ = vl;
    }

    boost::shared_ptr<ISO_9506_MMS_1::AlternateAccess> ScatteredAccessDescription_sequence_of::alternateAccess__new() {
        return alternateAccess_ = boost::shared_ptr<ISO_9506_MMS_1::AlternateAccess>(new ISO_9506_MMS_1::AlternateAccess());
    }

    void ScatteredAccessDescription_sequence_of::alternateAccess(const ISO_9506_MMS_1::AlternateAccess& vl) {
        alternateAccess_ = boost::shared_ptr<ISO_9506_MMS_1::AlternateAccess>(new ISO_9506_MMS_1::AlternateAccess(vl));
    }


    // sequence DefineScatteredAccess-Request

    DefineScatteredAccess_Request::DefineScatteredAccess_Request() : scatteredAccessName_(), scatteredAccessDescription_() {
    };

    DefineScatteredAccess_Request::DefineScatteredAccess_Request(const ISO_9506_MMS_1::ObjectName& __scatteredAccessName,
            const ScatteredAccessDescription& __scatteredAccessDescription) :
    scatteredAccessName_(__scatteredAccessName),
    scatteredAccessDescription_(__scatteredAccessDescription) {
    };

    template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_CHOICE_TAG(scatteredAccessName_, 0);
        BOOST_ASN_IMPLICIT_TAG(scatteredAccessDescription_, 1);
    }

    template<> void DefineScatteredAccess_Request::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_CHOICE_TAG(scatteredAccessName_, 0);
        BOOST_ASN_IMPLICIT_TAG(scatteredAccessDescription_, 1);
    }

    ISO_9506_MMS_1::ObjectName& DefineScatteredAccess_Request::scatteredAccessName() {
        return *scatteredAccessName_;
    }

    const ISO_9506_MMS_1::ObjectName& DefineScatteredAccess_Request::scatteredAccessName() const {
        return *scatteredAccessName_;
    }

    void DefineScatteredAccess_Request::scatteredAccessName(const ISO_9506_MMS_1::ObjectName& vl) {
        scatteredAccessName_ = vl;
    }

    void DefineScatteredAccess_Request::scatteredAccessName(boost::shared_ptr< ISO_9506_MMS_1::ObjectName> vl) {
        scatteredAccessName_ = vl;
    }

    ScatteredAccessDescription& DefineScatteredAccess_Request::scatteredAccessDescription() {
        return *scatteredAccessDescription_;
    }

    const ScatteredAccessDescription& DefineScatteredAccess_Request::scatteredAccessDescription() const {
        return *scatteredAccessDescription_;
    }

    void DefineScatteredAccess_Request::scatteredAccessDescription(const ScatteredAccessDescription& vl) {
        scatteredAccessDescription_ = vl;
    }

    void DefineScatteredAccess_Request::scatteredAccessDescription(boost::shared_ptr< ScatteredAccessDescription> vl) {
        scatteredAccessDescription_ = vl;
    }


    // sequence GetScatteredAccessAttributes-Response

    GetScatteredAccessAttributes_Response::GetScatteredAccessAttributes_Response() : mmsDeletable_(), scatteredAccessDescription_() {
    };

    GetScatteredAccessAttributes_Response::GetScatteredAccessAttributes_Response(const bool& __mmsDeletable,
            const ScatteredAccessDescription& __scatteredAccessDescription) :
    mmsDeletable_(__mmsDeletable),
    scatteredAccessDescription_(__scatteredAccessDescription) {
    };

    GetScatteredAccessAttributes_Response::GetScatteredAccessAttributes_Response(boost::shared_ptr< bool> __mmsDeletable,
            boost::shared_ptr< ScatteredAccessDescription> __scatteredAccessDescription,
            boost::shared_ptr< ISO_9506_MMS_1::Identifier> __accessControlList) :
    mmsDeletable_(__mmsDeletable),
    scatteredAccessDescription_(__scatteredAccessDescription),
    accessControlList_(__accessControlList) {
    };

    template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x690::output_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(mmsDeletable_, 0);
        BOOST_ASN_IMPLICIT_TAG(scatteredAccessDescription_, 1);
        BOOST_ASN_IMPLICIT_TAG(accessControlList_, 2);
    }

    template<> void GetScatteredAccessAttributes_Response::serialize(boost::asn1::x690::input_coder& arch) {
        BOOST_ASN_IMPLICIT_TAG(mmsDeletable_, 0);
        BOOST_ASN_IMPLICIT_TAG(scatteredAccessDescription_, 1);
        BOOST_ASN_IMPLICIT_TAG(accessControlList_, 2);
    }

    bool& GetScatteredAccessAttributes_Response::mmsDeletable() {
        return *mmsDeletable_;
    }

    const bool& GetScatteredAccessAttributes_Response::mmsDeletable() const {
        return *mmsDeletable_;
    }

    void GetScatteredAccessAttributes_Response::mmsDeletable(const bool& vl) {
        mmsDeletable_ = vl;
    }

    void GetScatteredAccessAttributes_Response::mmsDeletable(boost::shared_ptr< bool> vl) {
        mmsDeletable_ = vl;
    }

    ScatteredAccessDescription& GetScatteredAccessAttributes_Response::scatteredAccessDescription() {
        return *scatteredAccessDescription_;
    }

    const ScatteredAccessDescription& GetScatteredAccessAttributes_Response::scatteredAccessDescription() const {
        return *scatteredAccessDescription_;
    }

    void GetScatteredAccessAttributes_Response::scatteredAccessDescription(const ScatteredAccessDescription& vl) {
        scatteredAccessDescription_ = vl;
    }

    void GetScatteredAccessAttributes_Response::scatteredAccessDescription(boost::shared_ptr< ScatteredAccessDescription> vl) {
        scatteredAccessDescription_ = vl;
    }

    boost::shared_ptr<ISO_9506_MMS_1::Identifier> GetScatteredAccessAttributes_Response::accessControlList__new() {
        return accessControlList_ = boost::shared_ptr<ISO_9506_MMS_1::Identifier>(new ISO_9506_MMS_1::Identifier());
    }

    void GetScatteredAccessAttributes_Response::accessControlList(const ISO_9506_MMS_1::Identifier& vl) {
        accessControlList_ = boost::shared_ptr<ISO_9506_MMS_1::Identifier>(new ISO_9506_MMS_1::Identifier(vl));
    }


}
