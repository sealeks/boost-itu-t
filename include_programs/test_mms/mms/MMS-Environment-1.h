#ifndef	_MMS_Environment_1_H_
#define	_MMS_Environment_1_H_

#include <boost/itu/asn1/asnbase.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
 #endif


const boost::array<boost::asn1::oidindx_type, 5 >  MMS_Environment_1_OID_ARR = { 2  ,  2  ,  9506  ,  2  ,  4 };
const boost::asn1::oid_type MMS_Environment_1_OID = boost::asn1::oid_type(MMS_Environment_1_OID_ARR);


namespace MMS_Environment_1  {


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

	//  type is  SEQUENCE
	struct  ApplicationReference;

 }
#include <boost/itu/x22X/acse/ACSE-1.hpp>
 


namespace MMS_Environment_1  {

 
	//import type
	using ACSE_1::AP_title;
	using ACSE_1::AP_invocation_identifier;
	using ACSE_1::AE_qualifier;
	using ACSE_1::AE_invocation_identifier;
 
//start==============================================================
//It is   SEQUENCE  

	struct  ApplicationReference{


		ApplicationReference()  {}

		 template<typename Archive> void serialize(Archive& arch){

		}
	};
        
                	struct  Authentication_value{


		Authentication_value()  {}

		 template<typename Archive> void serialize(Archive& arch){

		}
	};  

//end==============================================================

}



#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif