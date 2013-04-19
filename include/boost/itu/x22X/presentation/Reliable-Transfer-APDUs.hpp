#ifndef	_Reliable_Transfer_APDUs_H_
#define	_Reliable_Transfer_APDUs_H_

#include <boost/itu/asn1/asnbase.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
 #endif


const boost::asn1::oidindx_type  Reliable_Transfer_APDUs_OID_ARR[] = { 2  ,  3  ,  0 };
const boost::asn1::oid_type Reliable_Transfer_APDUs_OID = boost::asn1::oid_type(Reliable_Transfer_APDUs_OID_ARR, 3);


namespace Reliable_Transfer_APDUs  {


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

	//  type is  CHOICE
	struct  RTSE_apdus;

 	//  type is  SET
	struct  RTORQapdu;

 	//  type is  SET
	struct  RTOACapdu;

 	//  type is  SET
	struct  RTORJapdu;

 	//  type is  SET
	struct  RTABapdu;

 	//  type is  CHOICE
	struct  ConnectionData;

 	//  type is  SEQUENCE
	struct  SessionConnectionIdentifier;

 	//  type is  CHOICE
	struct  CallingSSuserReference;

 	//  type is  INTEGER
	typedef  int   RTTPapdu;

 	//  type is  OCTET STRING
	typedef  octetstring_type   RTTRapdu;

 	//  type is  INTEGER
	typedef  int   RefuseReason;

 	//  type is  UTCTime
	typedef  utctime_type   CommonReference;

 	//  type is  T61String
	typedef  t61string_type   AdditionalReferenceInformation;

 	//  type is  INTEGER
	typedef  int   AbortReason;

 }


namespace Reliable_Transfer_APDUs  {


	const int AbortReason_localSystemProblem = 0;
	const int AbortReason_invalidParameter = 1;
	const int AbortReason_unrecognizedActivity = 2;
	const int AbortReason_temporaryProblem = 3;
	const int AbortReason_protocolError = 4;
	const int AbortReason_permanentProblem = 5;
	const int AbortReason_userError = 6;
	const int AbortReason_transferCompleted = 7;

//start==============================================================
//It is   CHOICE

	enum CallingSSuserReference_enum {
		CallingSSuserReference_null = 0  , 
		CallingSSuserReference_t61String , 
		CallingSSuserReference_octetString , 
	};

	struct  CallingSSuserReference : public BOOST_ASN_CHOICE_STRUCT(CallingSSuserReference_enum) {




		CallingSSuserReference() : BOOST_ASN_CHOICE_STRUCT(CallingSSuserReference_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(t61String, t61string_type,  CallingSSuserReference_t61String)
		BOOST_ASN_VALUE_CHOICE(octetString, octetstring_type,  CallingSSuserReference_octetString)

		 template<typename Archive> void serialize(Archive& arch){

			if (arch.__input__()){
				int __tag_id__ =arch.test_id();
				switch(arch.test_class()){
					case 0x0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x40: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0xC0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x80: {
						switch(__tag_id__){
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<t61string_type > (true , CallingSSuserReference_t61String))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<octetstring_type > (true , CallingSSuserReference_octetString))) return; else free();
					;}}}
			else {
				 switch(type()){
					case CallingSSuserReference_t61String: {BOOST_ASN_BIND_TAG(value<t61string_type > (false , CallingSSuserReference_t61String)); break;}
					case CallingSSuserReference_octetString: {BOOST_ASN_BIND_TAG(value<octetstring_type > (false , CallingSSuserReference_octetString)); break;}
					default:{}}}
		}
	};


	const int RefuseReason_rtsBusy = 0;
	const int RefuseReason_cannotRecover = 1;
	const int RefuseReason_validationFailure = 2;
	const int RefuseReason_unacceptableDialogueMode = 3;

//start==============================================================
//It is   SEQUENCE  

	struct  SessionConnectionIdentifier{

		CallingSSuserReference   callingSSuserReference;
		CommonReference   commonReference;
		boost::shared_ptr<AdditionalReferenceInformation > additionalReferenceInformation;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AdditionalReferenceInformation ,  additionalReferenceInformation)

 
		SessionConnectionIdentifier()  : callingSSuserReference() , commonReference()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_CHOICE(callingSSuserReference);
			BOOST_ASN_BIND_TAG(commonReference);
			BOOST_ASN_IMPLICIT_TAG(additionalReferenceInformation ,0);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum ConnectionData_enum {
		ConnectionData_null = 0  , 
		ConnectionData_open , 
		ConnectionData_recover , 
	};

	struct  ConnectionData : public BOOST_ASN_CHOICE_STRUCT(ConnectionData_enum) {


		ConnectionData() : BOOST_ASN_CHOICE_STRUCT(ConnectionData_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(open, any_type,  ConnectionData_open)
		BOOST_ASN_VALUE_CHOICE(recover, SessionConnectionIdentifier,  ConnectionData_recover)

		 template<typename Archive> void serialize(Archive& arch){

			if (arch.__input__()){
				int __tag_id__ =arch.test_id();
				switch(arch.test_class()){
					case 0x0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x40: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0xC0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x80: {
						switch(__tag_id__){
							case 0: { if(BOOST_ASN_EXPLICIT_TAG(value<any_type > (true , ConnectionData_open) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<SessionConnectionIdentifier > (true , ConnectionData_recover) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case ConnectionData_open: {BOOST_ASN_EXPLICIT_TAG(value<any_type > (false , ConnectionData_open) ,0); break;}
					case ConnectionData_recover: {BOOST_ASN_IMPLICIT_TAG(value<SessionConnectionIdentifier > (false , ConnectionData_recover) ,1); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SET  

	struct  RTABapdu{


		boost::shared_ptr<AbortReason > abortReason;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(AbortReason ,  abortReason)

 		boost::shared_ptr<bitstring_type > reflectedParameter;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(bitstring_type ,  reflectedParameter)

 		boost::shared_ptr<any_type > userdataAB;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(any_type ,  userdataAB)

 
		RTABapdu()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(abortReason ,0);
			BOOST_ASN_IMPLICIT_TAG(reflectedParameter ,1);
			BOOST_ASN_EXPLICIT_TAG(userdataAB ,2);
		}
	};

//end==============================================================
//start==============================================================
//It is   SET  

	struct  RTORJapdu{

		boost::shared_ptr<RefuseReason > refuseReason;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(RefuseReason ,  refuseReason)

 		boost::shared_ptr<any_type > userDataRJ;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(any_type ,  userDataRJ)

 
		RTORJapdu()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(refuseReason ,0);
			BOOST_ASN_EXPLICIT_TAG(userDataRJ ,1);
		}
	};

//end==============================================================
//start==============================================================
//It is   SET  

	struct  RTOACapdu{



		boost::shared_ptr<int > checkpointSize;   //  DEFAULT  int  0  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  checkpointSize)

 		boost::shared_ptr<int > windowSize;   //  DEFAULT  int  3  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  windowSize)

 		ConnectionData   connectionDataAC;

		RTOACapdu()  : connectionDataAC()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(checkpointSize ,0);
			BOOST_ASN_IMPLICIT_TAG(windowSize ,1);
			BOOST_ASN_CHOICE(connectionDataAC);
		}
	};

//end==============================================================
//start==============================================================
//It is   SET  

	struct  RTORQapdu{




		static const int dialogueMode_monologue = 0;
		static const int dialogueMode_twa = 1;



		boost::shared_ptr<int > checkpointSize;   //  DEFAULT  int  0  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  checkpointSize)

 		boost::shared_ptr<int > windowSize;   //  DEFAULT  int  3  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  windowSize)

 		boost::shared_ptr<int > dialogueMode;   //  DEFAULT  int  0  
 		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  dialogueMode)

 		ConnectionData   connectionDataRQ;
		boost::shared_ptr<int > applicationProtocol;   //  OPTIONAL
		BOOST_ASN_VALUE_FUNC_DECLARATE(int ,  applicationProtocol)

 
		RTORQapdu()  : connectionDataRQ()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_IMPLICIT_TAG(checkpointSize ,0);
			BOOST_ASN_IMPLICIT_TAG(windowSize ,1);
			BOOST_ASN_IMPLICIT_TAG(dialogueMode ,2);
			BOOST_ASN_CHOICE(connectionDataRQ);
			BOOST_ASN_IMPLICIT_TAG(applicationProtocol ,4);
		}
	};

//end==============================================================
//start==============================================================
//It is   CHOICE

	enum RTSE_apdus_enum {
		RTSE_apdus_null = 0  , 
		RTSE_apdus_rtorq_apdu , 
		RTSE_apdus_rtoac_apdu , 
		RTSE_apdus_rtorj_apdu , 
		RTSE_apdus_rttp_apdu , 
		RTSE_apdus_rttr_apdu , 
		RTSE_apdus_rtab_apdu , 
	};

	struct  RTSE_apdus : public BOOST_ASN_CHOICE_STRUCT(RTSE_apdus_enum) {


		RTSE_apdus() : BOOST_ASN_CHOICE_STRUCT(RTSE_apdus_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(rtorq_apdu, RTORQapdu,  RTSE_apdus_rtorq_apdu)
		BOOST_ASN_VALUE_CHOICE(rtoac_apdu, RTOACapdu,  RTSE_apdus_rtoac_apdu)
		BOOST_ASN_VALUE_CHOICE(rtorj_apdu, RTORJapdu,  RTSE_apdus_rtorj_apdu)
		BOOST_ASN_VALUE_CHOICE(rttp_apdu, RTTPapdu,  RTSE_apdus_rttp_apdu)
		BOOST_ASN_VALUE_CHOICE(rttr_apdu, RTTRapdu,  RTSE_apdus_rttr_apdu)
		BOOST_ASN_VALUE_CHOICE(rtab_apdu, RTABapdu,  RTSE_apdus_rtab_apdu)

		 template<typename Archive> void serialize(Archive& arch){

			if (arch.__input__()){
				int __tag_id__ =arch.test_id();
				switch(arch.test_class()){
					case 0x0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x40: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0xC0: {
						switch(__tag_id__){
						default:{}}
						;}
					case 0x80: {
						switch(__tag_id__){
							case 16: { if(BOOST_ASN_IMPLICIT_TAG(value<RTORQapdu > (true , RTSE_apdus_rtorq_apdu) ,16)) return; else free(); break;}
							case 17: { if(BOOST_ASN_IMPLICIT_TAG(value<RTOACapdu > (true , RTSE_apdus_rtoac_apdu) ,17)) return; else free(); break;}
							case 18: { if(BOOST_ASN_IMPLICIT_TAG(value<RTORJapdu > (true , RTSE_apdus_rtorj_apdu) ,18)) return; else free(); break;}
							case 22: { if(BOOST_ASN_IMPLICIT_TAG(value<RTABapdu > (true , RTSE_apdus_rtab_apdu) ,22)) return; else free(); break;}
						default:{}}
						;}
					default:{
						 if(BOOST_ASN_BIND_TAG(value<RTTPapdu > (true , RTSE_apdus_rttp_apdu))) return; else free();
					 if(BOOST_ASN_BIND_TAG(value<RTTRapdu > (true , RTSE_apdus_rttr_apdu))) return; else free();
					;}}}
			else {
				 switch(type()){
					case RTSE_apdus_rtorq_apdu: {BOOST_ASN_IMPLICIT_TAG(value<RTORQapdu > (false , RTSE_apdus_rtorq_apdu) ,16); break;}
					case RTSE_apdus_rtoac_apdu: {BOOST_ASN_IMPLICIT_TAG(value<RTOACapdu > (false , RTSE_apdus_rtoac_apdu) ,17); break;}
					case RTSE_apdus_rtorj_apdu: {BOOST_ASN_IMPLICIT_TAG(value<RTORJapdu > (false , RTSE_apdus_rtorj_apdu) ,18); break;}
					case RTSE_apdus_rttp_apdu: {BOOST_ASN_BIND_TAG(value<RTTPapdu > (false , RTSE_apdus_rttp_apdu)); break;}
					case RTSE_apdus_rttr_apdu: {BOOST_ASN_BIND_TAG(value<RTTRapdu > (false , RTSE_apdus_rttr_apdu)); break;}
					case RTSE_apdus_rtab_apdu: {BOOST_ASN_IMPLICIT_TAG(value<RTABapdu > (false , RTSE_apdus_rtab_apdu) ,22); break;}
					default:{}}}
		}
	};


}

BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDUs::RTORQapdu) 
BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDUs::RTOACapdu) 
BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDUs::RTORJapdu) 
BOOST_ASN_SET_REGESTRATE(Reliable_Transfer_APDUs::RTABapdu) 

BOOST_ASN_CHOISE_REGESTRATE(Reliable_Transfer_APDUs::RTSE_apdus) 
BOOST_ASN_CHOISE_REGESTRATE(Reliable_Transfer_APDUs::ConnectionData) 
BOOST_ASN_CHOISE_REGESTRATE(Reliable_Transfer_APDUs::CallingSSuserReference) 

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif