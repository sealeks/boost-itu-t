#include "ISO-9506-MMS-1A.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace ISO_9506_MMS_1A {

    // sequence ObtainFile-Request

    ObtainFile_Request::ObtainFile_Request() : sourceFile_(), destinationFile_() {
    };

    ObtainFile_Request::ObtainFile_Request(const ISO_9506_MMS_1::FileName& arg__sourceFile,
            const ISO_9506_MMS_1::FileName& arg__destinationFile) :
    sourceFile_(arg__sourceFile),
    destinationFile_(arg__destinationFile) {
    };

    ObtainFile_Request::ObtainFile_Request(shared_ptr< MMS_Environment_1::ApplicationReference> arg__sourceFileServer,
            shared_ptr< ISO_9506_MMS_1::FileName> arg__sourceFile,
            shared_ptr< ISO_9506_MMS_1::FileName> arg__destinationFile) :
    sourceFileServer_(arg__sourceFileServer),
    sourceFile_(arg__sourceFile),
    destinationFile_(arg__destinationFile) {
    };


    ITU_T_OPTIONAL_DEFN(ObtainFile_Request::sourceFileServer, sourceFileServer, MMS_Environment_1::ApplicationReference);
    ITU_T_HOLDERH_DEFN(ObtainFile_Request::sourceFile, sourceFile, ISO_9506_MMS_1::FileName);
    ITU_T_HOLDERH_DEFN(ObtainFile_Request::destinationFile, destinationFile, ISO_9506_MMS_1::FileName);

    // sequence FileOpen-Request

    FileOpen_Request::FileOpen_Request() : fileName_(), initialPosition_() {
    };

    FileOpen_Request::FileOpen_Request(const ISO_9506_MMS_1::FileName& arg__fileName,
            const ISO_9506_MMS_1::Unsigned32& arg__initialPosition) :
    fileName_(arg__fileName),
    initialPosition_(arg__initialPosition) {
    };


    ITU_T_HOLDERH_DEFN(FileOpen_Request::fileName, fileName, ISO_9506_MMS_1::FileName);
    ITU_T_HOLDERH_DEFN(FileOpen_Request::initialPosition, initialPosition, ISO_9506_MMS_1::Unsigned32);

    // sequence FileOpen-Response

    FileOpen_Response::FileOpen_Response() : frsmID_(), fileAttributes_() {
    };

    FileOpen_Response::FileOpen_Response(const ISO_9506_MMS_1::Integer32& arg__frsmID,
            const FileAttributes& arg__fileAttributes) :
    frsmID_(arg__frsmID),
    fileAttributes_(arg__fileAttributes) {
    };


    ITU_T_HOLDERH_DEFN(FileOpen_Response::frsmID, frsmID, ISO_9506_MMS_1::Integer32);
    ITU_T_HOLDERH_DEFN(FileOpen_Response::fileAttributes, fileAttributes, FileAttributes);

    // sequence FileRead-Response

    FileRead_Response::FileRead_Response() : fileData_() {
    };

    FileRead_Response::FileRead_Response(const octet_string& arg__fileData) :
    fileData_(arg__fileData) {
    };

    FileRead_Response::FileRead_Response(shared_ptr< octet_string> arg__fileData,
            shared_ptr< bool> arg__moreFollows) :
    fileData_(arg__fileData),
    moreFollows_(arg__moreFollows) {
    };

    const bool FileRead_Response::moreFollows__default = true;


    ITU_T_HOLDERH_DEFN(FileRead_Response::fileData, fileData, octet_string);
    ITU_T_DEFAULTH_DEFN(FileRead_Response::moreFollows, moreFollows, bool);

    // sequence FileRename-Request

    FileRename_Request::FileRename_Request() : currentFileName_(), newFileName_() {
    };

    FileRename_Request::FileRename_Request(const ISO_9506_MMS_1::FileName& arg__currentFileName,
            const ISO_9506_MMS_1::FileName& arg__newFileName) :
    currentFileName_(arg__currentFileName),
    newFileName_(arg__newFileName) {
    };


    ITU_T_HOLDERH_DEFN(FileRename_Request::currentFileName, currentFileName, ISO_9506_MMS_1::FileName);
    ITU_T_HOLDERH_DEFN(FileRename_Request::newFileName, newFileName, ISO_9506_MMS_1::FileName);

    // sequence FileDirectory-Request

    FileDirectory_Request::FileDirectory_Request() {
    };

    FileDirectory_Request::FileDirectory_Request(shared_ptr< ISO_9506_MMS_1::FileName> arg__fileSpecification,
            shared_ptr< ISO_9506_MMS_1::FileName> arg__continueAfter) :
    fileSpecification_(arg__fileSpecification),
    continueAfter_(arg__continueAfter) {
    };


    ITU_T_OPTIONAL_DEFN(FileDirectory_Request::fileSpecification, fileSpecification, ISO_9506_MMS_1::FileName);
    ITU_T_OPTIONAL_DEFN(FileDirectory_Request::continueAfter, continueAfter, ISO_9506_MMS_1::FileName);

    // sequence FileDirectory-Response

    FileDirectory_Response::FileDirectory_Response() : listOfDirectoryEntry_() {
    };

    FileDirectory_Response::FileDirectory_Response(const ListOfDirectoryEntry_type& arg__listOfDirectoryEntry) :
    listOfDirectoryEntry_(arg__listOfDirectoryEntry) {
    };

    FileDirectory_Response::FileDirectory_Response(shared_ptr< ListOfDirectoryEntry_type> arg__listOfDirectoryEntry,
            shared_ptr< bool> arg__moreFollows) :
    listOfDirectoryEntry_(arg__listOfDirectoryEntry),
    moreFollows_(arg__moreFollows) {
    };

    const bool FileDirectory_Response::moreFollows__default = false;


    ITU_T_HOLDERH_DEFN(FileDirectory_Response::listOfDirectoryEntry, listOfDirectoryEntry, FileDirectory_Response::ListOfDirectoryEntry_type);
    ITU_T_DEFAULTH_DEFN(FileDirectory_Response::moreFollows, moreFollows, bool);

    // sequence DirectoryEntry

    DirectoryEntry::DirectoryEntry() : fileName_(), fileAttributes_() {
    };

    DirectoryEntry::DirectoryEntry(const ISO_9506_MMS_1::FileName& arg__fileName,
            const FileAttributes& arg__fileAttributes) :
    fileName_(arg__fileName),
    fileAttributes_(arg__fileAttributes) {
    };


    ITU_T_HOLDERH_DEFN(DirectoryEntry::fileName, fileName, ISO_9506_MMS_1::FileName);
    ITU_T_HOLDERH_DEFN(DirectoryEntry::fileAttributes, fileAttributes, FileAttributes);

    // sequence FileAttributes

    FileAttributes::FileAttributes() : sizeOfFile_() {
    };

    FileAttributes::FileAttributes(const ISO_9506_MMS_1::Unsigned32& arg__sizeOfFile) :
    sizeOfFile_(arg__sizeOfFile) {
    };

    FileAttributes::FileAttributes(shared_ptr< ISO_9506_MMS_1::Unsigned32> arg__sizeOfFile,
            shared_ptr< gentime> arg__lastModified) :
    sizeOfFile_(arg__sizeOfFile),
    lastModified_(arg__lastModified) {
    };


    ITU_T_HOLDERH_DEFN(FileAttributes::sizeOfFile, sizeOfFile, ISO_9506_MMS_1::Unsigned32);
    ITU_T_OPTIONAL_DEFN(FileAttributes::lastModified, lastModified, gentime);

    ScatteredAccessDescription_sequence_of::ScatteredAccessDescription_sequence_of() : variableSpecification_() {
    };

    ScatteredAccessDescription_sequence_of::ScatteredAccessDescription_sequence_of(const ISO_9506_MMS_1::VariableSpecification& arg__variableSpecification) :
    variableSpecification_(arg__variableSpecification) {
    };

    ScatteredAccessDescription_sequence_of::ScatteredAccessDescription_sequence_of(shared_ptr< ISO_9506_MMS_1::Identifier> arg__componentName,
            shared_ptr< ISO_9506_MMS_1::VariableSpecification> arg__variableSpecification,
            shared_ptr< ISO_9506_MMS_1::AlternateAccess> arg__alternateAccess) :
    componentName_(arg__componentName),
    variableSpecification_(arg__variableSpecification),
    alternateAccess_(arg__alternateAccess) {
    };


    ITU_T_OPTIONAL_DEFN(ScatteredAccessDescription_sequence_of::componentName, componentName, ISO_9506_MMS_1::Identifier);
    ITU_T_HOLDERH_DEFN(ScatteredAccessDescription_sequence_of::variableSpecification, variableSpecification, ISO_9506_MMS_1::VariableSpecification);
    ITU_T_OPTIONAL_DEFN(ScatteredAccessDescription_sequence_of::alternateAccess, alternateAccess, ISO_9506_MMS_1::AlternateAccess);

    // sequence DefineScatteredAccess-Request

    DefineScatteredAccess_Request::DefineScatteredAccess_Request() : scatteredAccessName_(), scatteredAccessDescription_() {
    };

    DefineScatteredAccess_Request::DefineScatteredAccess_Request(const ISO_9506_MMS_1::ObjectName& arg__scatteredAccessName,
            const ScatteredAccessDescription& arg__scatteredAccessDescription) :
    scatteredAccessName_(arg__scatteredAccessName),
    scatteredAccessDescription_(arg__scatteredAccessDescription) {
    };


    ITU_T_HOLDERH_DEFN(DefineScatteredAccess_Request::scatteredAccessName, scatteredAccessName, ISO_9506_MMS_1::ObjectName);
    ITU_T_HOLDERH_DEFN(DefineScatteredAccess_Request::scatteredAccessDescription, scatteredAccessDescription, ScatteredAccessDescription);

    // sequence GetScatteredAccessAttributes-Response

    GetScatteredAccessAttributes_Response::GetScatteredAccessAttributes_Response() : mmsDeletable_(), scatteredAccessDescription_() {
    };

    GetScatteredAccessAttributes_Response::GetScatteredAccessAttributes_Response(const bool& arg__mmsDeletable,
            const ScatteredAccessDescription& arg__scatteredAccessDescription) :
    mmsDeletable_(arg__mmsDeletable),
    scatteredAccessDescription_(arg__scatteredAccessDescription) {
    };

    GetScatteredAccessAttributes_Response::GetScatteredAccessAttributes_Response(shared_ptr< bool> arg__mmsDeletable,
            shared_ptr< ScatteredAccessDescription> arg__scatteredAccessDescription,
            shared_ptr< ISO_9506_MMS_1::Identifier> arg__accessControlList) :
    mmsDeletable_(arg__mmsDeletable),
    scatteredAccessDescription_(arg__scatteredAccessDescription),
    accessControlList_(arg__accessControlList) {
    };


    ITU_T_HOLDERH_DEFN(GetScatteredAccessAttributes_Response::mmsDeletable, mmsDeletable, bool);
    ITU_T_HOLDERH_DEFN(GetScatteredAccessAttributes_Response::scatteredAccessDescription, scatteredAccessDescription, ScatteredAccessDescription);
    ITU_T_OPTIONAL_DEFN(GetScatteredAccessAttributes_Response::accessControlList, accessControlList, ISO_9506_MMS_1::Identifier);

}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

