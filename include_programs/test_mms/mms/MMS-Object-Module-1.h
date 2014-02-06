#ifndef	_MMS_Object_Module_1_H_
#define	_MMS_Object_Module_1_H_

#include <boost/itu/asn1/asnbase.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
 #endif


const boost::array<boost::asn1::oidindx_type, 5 >  MMS_Object_Module_1_OID_ARR = { 2  ,  2  ,  9506  ,  1  ,  2 };
const boost::asn1::oid_type MMS_Object_Module_1_OID = boost::asn1::oid_type(MMS_Object_Module_1_OID_ARR);


namespace MMS_Object_Module_1  {


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
	struct  ModifierStep;

 	//  type is  CHOICE
	struct  Modifier;

 	//  type is  CHOICE
	struct  AccessCondition;

 	//  type is  CHOICE
	struct  Address;

 	//  type is  CHOICE
	struct  TypeDescription;

 	//  type is  CHOICE
	struct  EventTime;

 	//  type is  SEQUENCE
	struct  Journal_Variable;

 	//  type is extended  INTEGER
	BOOST_ASN_IMPLICIT_TYPEDEF(LogicalStatus , int , 0  ,CONTEXT_CLASS)
 
 
 	//  type is extended  INTEGER
	BOOST_ASN_IMPLICIT_TYPEDEF(PhysicalStatus , int , 1  ,CONTEXT_CLASS)
 
 
 	//  type is  INTEGER
	typedef  int   VMDState;

 	//  type is  BIT STRING
	typedef  bitstring_type   ServiceSupportOptions;

 	//  type is  BIT STRING
	typedef  bitstring_type   ParameterSupportOptions;

 	//  type is  BIT STRING
	typedef  bitstring_type   AdditionalSupportOptions;

 	//  type is  BIT STRING
	typedef  bitstring_type   AdditionalCBBOptions;

 	//  type is  INTEGER
	typedef  int   DomainState;

 	//  type is  INTEGER
	typedef  int   ULState;

 	//  type is  INTEGER
	typedef  int   ProgramInvocationState;

 	//  type is  INTEGER
	typedef  int   Control_State;

 	//  type is  INTEGER
	typedef  int   Running_Mode;

 	//  type is  INTEGER
	typedef  int   Priority;

 	//  type is  INTEGER
	typedef  int   EC_Class;

 	//  type is  INTEGER
	typedef  int   EC_State;

 	//  type is  INTEGER
	typedef  int   Severity;

 	//  type is  INTEGER
	typedef  int   EE_Class;

 	//  type is  BIT STRING
	typedef  bitstring_type   Transitions;

 	//  type is  INTEGER
	typedef  int   EE_Duration;

 	//  type is  INTEGER
	typedef  int   AlarmAckRule;

 }
#include "MMS-Environment-1.h"
#include <boost/itu/x22X/acse/ACSE-1.hpp>
#include "ISO-9506-MMS-1.h"
 


namespace MMS_Object_Module_1  {

 
	//import type
	using MMS_Environment_1::ApplicationReference;
	using ACSE_1::Authentication_value;
	using ISO_9506_MMS_1::AlternateAccess;
	using ISO_9506_MMS_1::ConfirmedServiceRequest;
	using ISO_9506_MMS_1::AttachToSemaphore;
	using ISO_9506_MMS_1::AttachToEventCondition;
	using ISO_9506_MMS_1::Data;
	using ISO_9506_MMS_1::EE_State;
	using ISO_9506_MMS_1::Identifier;
	using ISO_9506_MMS_1::Integer8;
	using ISO_9506_MMS_1::Integer32;
	using ISO_9506_MMS_1::MMSString;
	using ISO_9506_MMS_1::MMS255String;
	using ISO_9506_MMS_1::ObjectName;
	using ISO_9506_MMS_1::TimeOfDay;
	using ISO_9506_MMS_1::TypeSpecification;
	using ISO_9506_MMS_1::Unsigned32;
	using ISO_9506_MMS_1::Unsigned8;
 
//start==============================================================
//It is   SEQUENCE  

	struct  Journal_Variable{

		boost::asn1::value_holder<MMS255String >  variableTag;
		boost::asn1::value_holder<Data >  valueSpecification;

		Journal_Variable()  : variableTag() , valueSpecification()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_BIND_TAG(variableTag);
			BOOST_ASN_CHOICE(valueSpecification);
		}
	};

//end==============================================================

	const int AlarmAckRule_none = 0;
	const int AlarmAckRule_simple = 1;
	const int AlarmAckRule_ack_active = 2;
	const int AlarmAckRule_ack_all = 3;


	const int EE_Duration_current = 0;
	const int EE_Duration_permanent = 1;


	const bitstring_type Transitions_idle_to_disabled= bitstring_type(true, 0);
	const bitstring_type Transitions_active_to_disabled= bitstring_type(true, 1);
	const bitstring_type Transitions_disabled_to_idle= bitstring_type(true, 2);
	const bitstring_type Transitions_active_to_idle= bitstring_type(true, 3);
	const bitstring_type Transitions_disabled_to_active= bitstring_type(true, 4);
	const bitstring_type Transitions_idle_to_active= bitstring_type(true, 5);
	const bitstring_type Transitions_any_to_deleted= bitstring_type(true, 6);


	const int EE_Class_modifier = 0;
	const int EE_Class_notification = 1;

//start==============================================================
//It is   CHOICE

	enum EventTime_enum {
		EventTime_null = 0  , 
		EventTime_timeOfDay , 
		EventTime_timeSequenceIdentifier , 
		EventTime_undefined , 
	};

	struct  EventTime : public BOOST_ASN_CHOICE_STRUCT(EventTime_enum) {



		EventTime() : BOOST_ASN_CHOICE_STRUCT(EventTime_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(timeOfDay, TimeOfDay,  EventTime_timeOfDay)
		BOOST_ASN_VALUE_CHOICE(timeSequenceIdentifier, Unsigned32,  EventTime_timeSequenceIdentifier)
		BOOST_ASN_VALUE_CHOICE(undefined, null_type,  EventTime_undefined)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (true , EventTime_timeOfDay) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (true , EventTime_timeSequenceIdentifier) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , EventTime_undefined) ,2)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case EventTime_timeOfDay: {BOOST_ASN_IMPLICIT_TAG(value<TimeOfDay > (false , EventTime_timeOfDay) ,0); break;}
					case EventTime_timeSequenceIdentifier: {BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (false , EventTime_timeSequenceIdentifier) ,1); break;}
					case EventTime_undefined: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , EventTime_undefined) ,2); break;}
					default:{}}}
		}
	};


	const int EC_State_disabled = 0;
	const int EC_State_idle = 1;
	const int EC_State_active = 2;


	const int EC_Class_network_triggered = 0;
	const int EC_Class_monitored = 1;

//start==============================================================
//It is   CHOICE

	enum TypeDescription_enum {
		TypeDescription_null = 0  , 
		TypeDescription_array , 
		TypeDescription_structure , 
		TypeDescription_boolean , 
		TypeDescription_bit_string , 
		TypeDescription_integer , 
		TypeDescription_unsignedV , 
		TypeDescription_floating_point , 
		TypeDescription_octet_string , 
		TypeDescription_visible_string , 
		TypeDescription_generalized_time , 
		TypeDescription_binary_time , 
		TypeDescription_bcd , 
		TypeDescription_objId , 
		TypeDescription_mMSString , 
	};

	struct  TypeDescription : public BOOST_ASN_CHOICE_STRUCT(TypeDescription_enum) {


	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  array_type{


			boost::shared_ptr<bool > packed;   //  DEFAULT   
 			BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  packed)

 			boost::asn1::value_holder<Unsigned32 >  numberOfElements;
			boost::asn1::value_holder<TypeSpecification >  elementType;

			array_type()  : numberOfElements() , elementType()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(packed ,0);
				BOOST_ASN_IMPLICIT_TAG(numberOfElements ,1);
				BOOST_ASN_CHOICE_TAG(elementType ,2);
			}
		};

	//end==============================================================

	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  structure_type{

			//   SEQUENCE_OF is components 
					//start==============================================================
			//It is  INTERNAL SEQUENCE  

				struct  components_type_sequence_of{

					boost::shared_ptr<Identifier > componentName;   //  OPTIONAL
					BOOST_ASN_VALUE_FUNC_DECLARATE(Identifier ,  componentName)

 					boost::asn1::value_holder<TypeSpecification >  componentType;

					components_type_sequence_of()  : componentType()  {}

					 template<typename Archive> void serialize(Archive& arch){

						BOOST_ASN_IMPLICIT_TAG(componentName ,0);
						BOOST_ASN_CHOICE_TAG(componentType ,1);
					}
				};

			//end==============================================================
	typedef std::vector<components_type_sequence_of >   components_type;


			boost::shared_ptr<bool > packed;   //  DEFAULT   
 			BOOST_ASN_VALUE_FUNC_DECLARATE(bool ,  packed)

 			boost::asn1::value_holder<components_type >  components;

			structure_type()  : components()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_IMPLICIT_TAG(packed ,0);
				BOOST_ASN_IMPLICIT_TAG(components ,1);
			}
		};

	//end==============================================================


	//start==============================================================
	//It is  INTERNAL SEQUENCE  

		struct  floating_point_type{

			boost::asn1::value_holder<Unsigned8 >  format_width;
			boost::asn1::value_holder<Unsigned8 >  exponent_width;

			floating_point_type()  : format_width() , exponent_width()  {}

			 template<typename Archive> void serialize(Archive& arch){

				BOOST_ASN_BIND_TAG(format_width);
				BOOST_ASN_BIND_TAG(exponent_width);
			}
		};

	//end==============================================================





		TypeDescription() : BOOST_ASN_CHOICE_STRUCT(TypeDescription_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(array, array_type,  TypeDescription_array)
		BOOST_ASN_VALUE_CHOICE(structure, structure_type,  TypeDescription_structure)
		BOOST_ASN_VALUE_CHOICE(boolean, null_type,  TypeDescription_boolean)
		BOOST_ASN_VALUE_CHOICE(bit_string, Integer32,  TypeDescription_bit_string)
		BOOST_ASN_VALUE_CHOICE(integer, Unsigned8,  TypeDescription_integer)
		BOOST_ASN_VALUE_CHOICE(unsignedV, Unsigned8,  TypeDescription_unsignedV)
		BOOST_ASN_VALUE_CHOICE(floating_point, floating_point_type,  TypeDescription_floating_point)
		BOOST_ASN_VALUE_CHOICE(octet_string, Integer32,  TypeDescription_octet_string)
		BOOST_ASN_VALUE_CHOICE(visible_string, Integer32,  TypeDescription_visible_string)
		BOOST_ASN_VALUE_CHOICE(generalized_time, null_type,  TypeDescription_generalized_time)
		BOOST_ASN_VALUE_CHOICE(binary_time, bool,  TypeDescription_binary_time)
		BOOST_ASN_VALUE_CHOICE(bcd, Unsigned8,  TypeDescription_bcd)
		BOOST_ASN_VALUE_CHOICE(objId, null_type,  TypeDescription_objId)
		BOOST_ASN_VALUE_CHOICE(mMSString, Integer32,  TypeDescription_mMSString)

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
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<array_type > (true , TypeDescription_array) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<structure_type > (true , TypeDescription_structure) ,2)) return; else free(); break;}
							case 3: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , TypeDescription_boolean) ,3)) return; else free(); break;}
							case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<Integer32 > (true , TypeDescription_bit_string) ,4)) return; else free(); break;}
							case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<Unsigned8 > (true , TypeDescription_integer) ,5)) return; else free(); break;}
							case 6: { if(BOOST_ASN_IMPLICIT_TAG(value<Unsigned8 > (true , TypeDescription_unsignedV) ,6)) return; else free(); break;}
							case 7: { if(BOOST_ASN_IMPLICIT_TAG(value<floating_point_type > (true , TypeDescription_floating_point) ,7)) return; else free(); break;}
							case 9: { if(BOOST_ASN_IMPLICIT_TAG(value<Integer32 > (true , TypeDescription_octet_string) ,9)) return; else free(); break;}
							case 10: { if(BOOST_ASN_IMPLICIT_TAG(value<Integer32 > (true , TypeDescription_visible_string) ,10)) return; else free(); break;}
							case 11: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , TypeDescription_generalized_time) ,11)) return; else free(); break;}
							case 12: { if(BOOST_ASN_IMPLICIT_TAG(value<bool > (true , TypeDescription_binary_time) ,12)) return; else free(); break;}
							case 13: { if(BOOST_ASN_IMPLICIT_TAG(value<Unsigned8 > (true , TypeDescription_bcd) ,13)) return; else free(); break;}
							case 15: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , TypeDescription_objId) ,15)) return; else free(); break;}
							case 16: { if(BOOST_ASN_EXPLICIT_TAG(value<Integer32 > (true , TypeDescription_mMSString) ,16)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case TypeDescription_array: {BOOST_ASN_IMPLICIT_TAG(value<array_type > (false , TypeDescription_array) ,1); break;}
					case TypeDescription_structure: {BOOST_ASN_IMPLICIT_TAG(value<structure_type > (false , TypeDescription_structure) ,2); break;}
					case TypeDescription_boolean: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , TypeDescription_boolean) ,3); break;}
					case TypeDescription_bit_string: {BOOST_ASN_IMPLICIT_TAG(value<Integer32 > (false , TypeDescription_bit_string) ,4); break;}
					case TypeDescription_integer: {BOOST_ASN_IMPLICIT_TAG(value<Unsigned8 > (false , TypeDescription_integer) ,5); break;}
					case TypeDescription_unsignedV: {BOOST_ASN_IMPLICIT_TAG(value<Unsigned8 > (false , TypeDescription_unsignedV) ,6); break;}
					case TypeDescription_floating_point: {BOOST_ASN_IMPLICIT_TAG(value<floating_point_type > (false , TypeDescription_floating_point) ,7); break;}
					case TypeDescription_octet_string: {BOOST_ASN_IMPLICIT_TAG(value<Integer32 > (false , TypeDescription_octet_string) ,9); break;}
					case TypeDescription_visible_string: {BOOST_ASN_IMPLICIT_TAG(value<Integer32 > (false , TypeDescription_visible_string) ,10); break;}
					case TypeDescription_generalized_time: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , TypeDescription_generalized_time) ,11); break;}
					case TypeDescription_binary_time: {BOOST_ASN_IMPLICIT_TAG(value<bool > (false , TypeDescription_binary_time) ,12); break;}
					case TypeDescription_bcd: {BOOST_ASN_IMPLICIT_TAG(value<Unsigned8 > (false , TypeDescription_bcd) ,13); break;}
					case TypeDescription_objId: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , TypeDescription_objId) ,15); break;}
					case TypeDescription_mMSString: {BOOST_ASN_EXPLICIT_TAG(value<Integer32 > (false , TypeDescription_mMSString) ,16); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   CHOICE

	enum Address_enum {
		Address_null = 0  , 
		Address_numericAddress , 
		Address_symbolicAddress , 
		Address_unconstrainedAddress , 
	};

	struct  Address : public BOOST_ASN_CHOICE_STRUCT(Address_enum) {



		Address() : BOOST_ASN_CHOICE_STRUCT(Address_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(numericAddress, Unsigned32,  Address_numericAddress)
		BOOST_ASN_VALUE_CHOICE(symbolicAddress, MMSString,  Address_symbolicAddress)
		BOOST_ASN_VALUE_CHOICE(unconstrainedAddress, octetstring_type,  Address_unconstrainedAddress)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (true , Address_numericAddress) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_EXPLICIT_TAG(value<MMSString > (true , Address_symbolicAddress) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (true , Address_unconstrainedAddress) ,2)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case Address_numericAddress: {BOOST_ASN_IMPLICIT_TAG(value<Unsigned32 > (false , Address_numericAddress) ,0); break;}
					case Address_symbolicAddress: {BOOST_ASN_EXPLICIT_TAG(value<MMSString > (false , Address_symbolicAddress) ,1); break;}
					case Address_unconstrainedAddress: {BOOST_ASN_IMPLICIT_TAG(value<octetstring_type > (false , Address_unconstrainedAddress) ,2); break;}
					default:{}}}
		}
	};


	const int Running_Mode_free_run = 0;
	const int Running_Mode_cycle_limited = 1;
	const int Running_Mode_step_limited = 2;


	const int Control_State_normal = 0;
	const int Control_State_controlling = 1;
	const int Control_State_controlled = 2;


	const int ProgramInvocationState_non_existent = 0;
	const int ProgramInvocationState_unrunnable = 1;
	const int ProgramInvocationState_idle = 2;
	const int ProgramInvocationState_running = 3;
	const int ProgramInvocationState_stopped = 4;
	const int ProgramInvocationState_starting = 5;
	const int ProgramInvocationState_stopping = 6;
	const int ProgramInvocationState_resuming = 7;
	const int ProgramInvocationState_resetting = 8;


	const int ULState_non_existent = 0;
	const int ULState_uploading = 1;
	const int ULState_uploaded = 2;
	const int ULState_u1 = 3;
	const int ULState_u2 = 4;
	const int ULState_u3 = 5;
	const int ULState_u4 = 6;


	const int DomainState_non_existent = 0;
	const int DomainState_loading = 1;
	const int DomainState_ready = 2;
	const int DomainState_in_use = 3;
	const int DomainState_complete = 4;
	const int DomainState_incomplete = 5;
	const int DomainState_d1 = 7;
	const int DomainState_d2 = 8;
	const int DomainState_d3 = 9;
	const int DomainState_d4 = 10;
	const int DomainState_d5 = 11;
	const int DomainState_d6 = 12;
	const int DomainState_d7 = 13;
	const int DomainState_d8 = 14;
	const int DomainState_d9 = 15;

//start==============================================================
//It is   CHOICE

	enum AccessCondition_enum {
		AccessCondition_null = 0  , 
		AccessCondition_never , 
		AccessCondition_semaphore , 
		AccessCondition_user , 
		AccessCondition_joint , 
		AccessCondition_alternate , 
	};

	struct  AccessCondition : public BOOST_ASN_CHOICE_STRUCT(AccessCondition_enum) {



	//start==============================================================
	//It is  INTERNAL CHOICE

			enum user_type_enum {
			user_type_null = 0  , 
			user_type_association , 
			user_type_none , 
		};

	struct  user_type : public BOOST_ASN_CHOICE_STRUCT(user_type_enum) {



			user_type() : BOOST_ASN_CHOICE_STRUCT(user_type_enum) ()  {}


			BOOST_ASN_VALUE_CHOICE(association, ApplicationReference,  user_type_association)
			BOOST_ASN_VALUE_CHOICE(none, null_type,  user_type_none)

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
								 if(BOOST_ASN_BIND_TAG(value<ApplicationReference > (true , user_type_association))) return; else free();
						 if(BOOST_ASN_BIND_TAG(value<null_type > (true , user_type_none))) return; else free();
						;}}}
				else {
					 switch(type()){
						case user_type_association: {BOOST_ASN_BIND_TAG(value<ApplicationReference > (false , user_type_association)); break;}
						case user_type_none: {BOOST_ASN_BIND_TAG(value<null_type > (false , user_type_none)); break;}
						default:{}}}
			}
		};

		//   SEQUENCE_OF is joint 
		typedef std::vector<AccessCondition >   joint_type;

		//   SEQUENCE_OF is alternate 
		typedef std::vector<AccessCondition >   alternate_type;


		AccessCondition() : BOOST_ASN_CHOICE_STRUCT(AccessCondition_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(never, null_type,  AccessCondition_never)
		BOOST_ASN_VALUE_CHOICE(semaphore, Identifier,  AccessCondition_semaphore)
		BOOST_ASN_VALUE_CHOICE(user, user_type,  AccessCondition_user)
		BOOST_ASN_VALUE_CHOICE(joint, joint_type,  AccessCondition_joint)
		BOOST_ASN_VALUE_CHOICE(alternate, alternate_type,  AccessCondition_alternate)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<null_type > (true , AccessCondition_never) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_EXPLICIT_TAG(value<Identifier > (true , AccessCondition_semaphore) ,1)) return; else free(); break;}
							case 2: { if(BOOST_ASN_CHOICE_TAG(value<user_type > (true , AccessCondition_user) ,2)) return; else free(); break;}
							case 4: { if(BOOST_ASN_IMPLICIT_TAG(value<joint_type > (true , AccessCondition_joint) ,4)) return; else free(); break;}
							case 5: { if(BOOST_ASN_IMPLICIT_TAG(value<alternate_type > (true , AccessCondition_alternate) ,5)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case AccessCondition_never: {BOOST_ASN_IMPLICIT_TAG(value<null_type > (false , AccessCondition_never) ,0); break;}
					case AccessCondition_semaphore: {BOOST_ASN_EXPLICIT_TAG(value<Identifier > (false , AccessCondition_semaphore) ,1); break;}
					case AccessCondition_user: {BOOST_ASN_CHOICE_TAG(value<user_type > (false , AccessCondition_user) ,2); break;}
					case AccessCondition_joint: {BOOST_ASN_IMPLICIT_TAG(value<joint_type > (false , AccessCondition_joint) ,4); break;}
					case AccessCondition_alternate: {BOOST_ASN_IMPLICIT_TAG(value<alternate_type > (false , AccessCondition_alternate) ,5); break;}
					default:{}}}
		}
	};


	const bitstring_type AdditionalCBBOptions_des= bitstring_type(true, 0);
	const bitstring_type AdditionalCBBOptions_dei= bitstring_type(true, 1);
	const bitstring_type AdditionalCBBOptions_recl= bitstring_type(true, 2);


	const bitstring_type AdditionalSupportOptions_vMDStop= bitstring_type(true, 0);
	const bitstring_type AdditionalSupportOptions_vMDReset= bitstring_type(true, 1);
	const bitstring_type AdditionalSupportOptions_select= bitstring_type(true, 2);
	const bitstring_type AdditionalSupportOptions_alterProgramInvocationAttributes= bitstring_type(true, 3);
	const bitstring_type AdditionalSupportOptions_initiateUnitControlLoad= bitstring_type(true, 4);
	const bitstring_type AdditionalSupportOptions_unitControlLoadSegment= bitstring_type(true, 5);
	const bitstring_type AdditionalSupportOptions_unitControlUpload= bitstring_type(true, 6);
	const bitstring_type AdditionalSupportOptions_startUnitControl= bitstring_type(true, 7);
	const bitstring_type AdditionalSupportOptions_stopUnitControl= bitstring_type(true, 8);
	const bitstring_type AdditionalSupportOptions_createUnitControl= bitstring_type(true, 9);
	const bitstring_type AdditionalSupportOptions_addToUnitControl= bitstring_type(true, 10);
	const bitstring_type AdditionalSupportOptions_removeFromUnitControl= bitstring_type(true, 11);
	const bitstring_type AdditionalSupportOptions_getUnitControlAttributes= bitstring_type(true, 12);
	const bitstring_type AdditionalSupportOptions_loadUnitControlFromFile= bitstring_type(true, 13);
	const bitstring_type AdditionalSupportOptions_storeUnitControlToFile= bitstring_type(true, 14);
	const bitstring_type AdditionalSupportOptions_deleteUnitControl= bitstring_type(true, 15);
	const bitstring_type AdditionalSupportOptions_defineEventConditionList= bitstring_type(true, 16);
	const bitstring_type AdditionalSupportOptions_deleteEventConditionList= bitstring_type(true, 17);
	const bitstring_type AdditionalSupportOptions_addEventConditionListReference= bitstring_type(true, 18);
	const bitstring_type AdditionalSupportOptions_removeEventConditionListReference= bitstring_type(true, 19);
	const bitstring_type AdditionalSupportOptions_getEventConditionListAttributes= bitstring_type(true, 20);
	const bitstring_type AdditionalSupportOptions_reportEventConditionListStatus= bitstring_type(true, 21);
	const bitstring_type AdditionalSupportOptions_alterEventConditionListMonitoring= bitstring_type(true, 22);


	const bitstring_type ParameterSupportOptions_str1= bitstring_type(true, 0);
	const bitstring_type ParameterSupportOptions_str2= bitstring_type(true, 1);
	const bitstring_type ParameterSupportOptions_vnam= bitstring_type(true, 2);
	const bitstring_type ParameterSupportOptions_valt= bitstring_type(true, 3);
	const bitstring_type ParameterSupportOptions_vadr= bitstring_type(true, 4);
	const bitstring_type ParameterSupportOptions_vsca= bitstring_type(true, 5);
	const bitstring_type ParameterSupportOptions_tpy= bitstring_type(true, 6);
	const bitstring_type ParameterSupportOptions_vlis= bitstring_type(true, 7);
	const bitstring_type ParameterSupportOptions_cei= bitstring_type(true, 10);
	const bitstring_type ParameterSupportOptions_aco= bitstring_type(true, 11);
	const bitstring_type ParameterSupportOptions_sem= bitstring_type(true, 12);
	const bitstring_type ParameterSupportOptions_csr= bitstring_type(true, 13);
	const bitstring_type ParameterSupportOptions_csnc= bitstring_type(true, 14);
	const bitstring_type ParameterSupportOptions_csplc= bitstring_type(true, 15);
	const bitstring_type ParameterSupportOptions_cspi= bitstring_type(true, 16);
	const bitstring_type ParameterSupportOptions_char= bitstring_type(true, 17);


	const bitstring_type ServiceSupportOptions_status= bitstring_type(true, 0);
	const bitstring_type ServiceSupportOptions_getNameList= bitstring_type(true, 1);
	const bitstring_type ServiceSupportOptions_identify= bitstring_type(true, 2);
	const bitstring_type ServiceSupportOptions_rename= bitstring_type(true, 3);
	const bitstring_type ServiceSupportOptions_read= bitstring_type(true, 4);
	const bitstring_type ServiceSupportOptions_write= bitstring_type(true, 5);
	const bitstring_type ServiceSupportOptions_getVariableAccessAttributes= bitstring_type(true, 6);
	const bitstring_type ServiceSupportOptions_defineNamedVariable= bitstring_type(true, 7);
	const bitstring_type ServiceSupportOptions_defineScatteredAccess= bitstring_type(true, 8);
	const bitstring_type ServiceSupportOptions_getScatteredAccessAttributes= bitstring_type(true, 9);
	const bitstring_type ServiceSupportOptions_deleteVariableAccess= bitstring_type(true, 10);
	const bitstring_type ServiceSupportOptions_defineNamedVariableList= bitstring_type(true, 11);
	const bitstring_type ServiceSupportOptions_getNamedVariableListAttributes= bitstring_type(true, 12);
	const bitstring_type ServiceSupportOptions_deleteNamedVariableList= bitstring_type(true, 13);
	const bitstring_type ServiceSupportOptions_defineNamedType= bitstring_type(true, 14);
	const bitstring_type ServiceSupportOptions_getNamedTypeAttributes= bitstring_type(true, 15);
	const bitstring_type ServiceSupportOptions_deleteNamedType= bitstring_type(true, 16);
	const bitstring_type ServiceSupportOptions_input= bitstring_type(true, 17);
	const bitstring_type ServiceSupportOptions_output= bitstring_type(true, 18);
	const bitstring_type ServiceSupportOptions_takeControl= bitstring_type(true, 19);
	const bitstring_type ServiceSupportOptions_relinquishControl= bitstring_type(true, 20);
	const bitstring_type ServiceSupportOptions_defineSemaphore= bitstring_type(true, 21);
	const bitstring_type ServiceSupportOptions_deleteSemaphore= bitstring_type(true, 22);
	const bitstring_type ServiceSupportOptions_reportSemaphoreStatus= bitstring_type(true, 23);
	const bitstring_type ServiceSupportOptions_reportPoolSemaphoreStatus= bitstring_type(true, 24);
	const bitstring_type ServiceSupportOptions_reportSemaphoreEntryStatus= bitstring_type(true, 25);
	const bitstring_type ServiceSupportOptions_initiateDownloadSequence= bitstring_type(true, 26);
	const bitstring_type ServiceSupportOptions_downloadSegment= bitstring_type(true, 27);
	const bitstring_type ServiceSupportOptions_terminateDownloadSequence= bitstring_type(true, 28);
	const bitstring_type ServiceSupportOptions_initiateUploadSequence= bitstring_type(true, 29);
	const bitstring_type ServiceSupportOptions_uploadSegment= bitstring_type(true, 30);
	const bitstring_type ServiceSupportOptions_terminateUploadSequence= bitstring_type(true, 31);
	const bitstring_type ServiceSupportOptions_requestDomainDownload= bitstring_type(true, 32);
	const bitstring_type ServiceSupportOptions_requestDomainUpload= bitstring_type(true, 33);
	const bitstring_type ServiceSupportOptions_loadDomainContent= bitstring_type(true, 34);
	const bitstring_type ServiceSupportOptions_storeDomainContent= bitstring_type(true, 35);
	const bitstring_type ServiceSupportOptions_deleteDomain= bitstring_type(true, 36);
	const bitstring_type ServiceSupportOptions_getDomainAttributes= bitstring_type(true, 37);
	const bitstring_type ServiceSupportOptions_createProgramInvocation= bitstring_type(true, 38);
	const bitstring_type ServiceSupportOptions_deleteProgramInvocation= bitstring_type(true, 39);
	const bitstring_type ServiceSupportOptions_start= bitstring_type(true, 40);
	const bitstring_type ServiceSupportOptions_stop= bitstring_type(true, 41);
	const bitstring_type ServiceSupportOptions_resume= bitstring_type(true, 42);
	const bitstring_type ServiceSupportOptions_reset= bitstring_type(true, 43);
	const bitstring_type ServiceSupportOptions_kill= bitstring_type(true, 44);
	const bitstring_type ServiceSupportOptions_getProgramInvocationAttributes= bitstring_type(true, 45);
	const bitstring_type ServiceSupportOptions_obtainFile= bitstring_type(true, 46);
	const bitstring_type ServiceSupportOptions_defineEventCondition= bitstring_type(true, 47);
	const bitstring_type ServiceSupportOptions_deleteEventCondition= bitstring_type(true, 48);
	const bitstring_type ServiceSupportOptions_getEventConditionAttributes= bitstring_type(true, 49);
	const bitstring_type ServiceSupportOptions_reportEventConditionStatus= bitstring_type(true, 50);
	const bitstring_type ServiceSupportOptions_alterEventConditionMonitoring= bitstring_type(true, 51);
	const bitstring_type ServiceSupportOptions_triggerEvent= bitstring_type(true, 52);
	const bitstring_type ServiceSupportOptions_defineEventAction= bitstring_type(true, 53);
	const bitstring_type ServiceSupportOptions_deleteEventAction= bitstring_type(true, 54);
	const bitstring_type ServiceSupportOptions_getEventActionAttributes= bitstring_type(true, 55);
	const bitstring_type ServiceSupportOptions_reportEventActionStatus= bitstring_type(true, 56);
	const bitstring_type ServiceSupportOptions_defineEventEnrollment= bitstring_type(true, 57);
	const bitstring_type ServiceSupportOptions_deleteEventEnrollment= bitstring_type(true, 58);
	const bitstring_type ServiceSupportOptions_alterEventEnrollment= bitstring_type(true, 59);
	const bitstring_type ServiceSupportOptions_reportEventEnrollmentStatus= bitstring_type(true, 60);
	const bitstring_type ServiceSupportOptions_getEventEnrollmentAttributes= bitstring_type(true, 61);
	const bitstring_type ServiceSupportOptions_acknowledgeEventNotification= bitstring_type(true, 62);
	const bitstring_type ServiceSupportOptions_getAlarmSummary= bitstring_type(true, 63);
	const bitstring_type ServiceSupportOptions_getAlarmEnrollmentSummary= bitstring_type(true, 64);
	const bitstring_type ServiceSupportOptions_readJournal= bitstring_type(true, 65);
	const bitstring_type ServiceSupportOptions_writeJournal= bitstring_type(true, 66);
	const bitstring_type ServiceSupportOptions_initializeJournal= bitstring_type(true, 67);
	const bitstring_type ServiceSupportOptions_reportJournalStatus= bitstring_type(true, 68);
	const bitstring_type ServiceSupportOptions_createJournal= bitstring_type(true, 69);
	const bitstring_type ServiceSupportOptions_deleteJournal= bitstring_type(true, 70);
	const bitstring_type ServiceSupportOptions_getCapabilityList= bitstring_type(true, 71);
	const bitstring_type ServiceSupportOptions_fileOpen= bitstring_type(true, 72);
	const bitstring_type ServiceSupportOptions_fileRead= bitstring_type(true, 73);
	const bitstring_type ServiceSupportOptions_fileClose= bitstring_type(true, 74);
	const bitstring_type ServiceSupportOptions_fileRename= bitstring_type(true, 75);
	const bitstring_type ServiceSupportOptions_fileDelete= bitstring_type(true, 76);
	const bitstring_type ServiceSupportOptions_fileDirectory= bitstring_type(true, 77);
	const bitstring_type ServiceSupportOptions_unsolicitedStatus= bitstring_type(true, 78);
	const bitstring_type ServiceSupportOptions_informationReport= bitstring_type(true, 79);
	const bitstring_type ServiceSupportOptions_eventNotification= bitstring_type(true, 80);
	const bitstring_type ServiceSupportOptions_attachToEventCondition= bitstring_type(true, 81);
	const bitstring_type ServiceSupportOptions_attachToSemaphore= bitstring_type(true, 82);
	const bitstring_type ServiceSupportOptions_conclude= bitstring_type(true, 83);
	const bitstring_type ServiceSupportOptions_cancel= bitstring_type(true, 84);
	const bitstring_type ServiceSupportOptions_getDataExchangeAttributes= bitstring_type(true, 85);
	const bitstring_type ServiceSupportOptions_exchangeData= bitstring_type(true, 86);
	const bitstring_type ServiceSupportOptions_defineAccessControlList= bitstring_type(true, 87);
	const bitstring_type ServiceSupportOptions_getAccessControlListAttributes= bitstring_type(true, 88);
	const bitstring_type ServiceSupportOptions_reportAccessControlledObjects= bitstring_type(true, 89);
	const bitstring_type ServiceSupportOptions_deleteAccessControlList= bitstring_type(true, 90);
	const bitstring_type ServiceSupportOptions_alterAccessControl= bitstring_type(true, 91);
	const bitstring_type ServiceSupportOptions_reconfigureProgramInvocation= bitstring_type(true, 92);

//start==============================================================
//It is   CHOICE

	enum Modifier_enum {
		Modifier_null = 0  , 
		Modifier_eventModifier , 
		Modifier_semaphoreModifier , 
	};

	struct  Modifier : public BOOST_ASN_CHOICE_STRUCT(Modifier_enum) {


		Modifier() : BOOST_ASN_CHOICE_STRUCT(Modifier_enum) ()  {}


		BOOST_ASN_VALUE_CHOICE(eventModifier, AttachToEventCondition,  Modifier_eventModifier)
		BOOST_ASN_VALUE_CHOICE(semaphoreModifier, AttachToSemaphore,  Modifier_semaphoreModifier)

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
							case 0: { if(BOOST_ASN_IMPLICIT_TAG(value<AttachToEventCondition > (true , Modifier_eventModifier) ,0)) return; else free(); break;}
							case 1: { if(BOOST_ASN_IMPLICIT_TAG(value<AttachToSemaphore > (true , Modifier_semaphoreModifier) ,1)) return; else free(); break;}
						default:{}}
						;}
					default:{
						;}}}
			else {
				 switch(type()){
					case Modifier_eventModifier: {BOOST_ASN_IMPLICIT_TAG(value<AttachToEventCondition > (false , Modifier_eventModifier) ,0); break;}
					case Modifier_semaphoreModifier: {BOOST_ASN_IMPLICIT_TAG(value<AttachToSemaphore > (false , Modifier_semaphoreModifier) ,1); break;}
					default:{}}}
		}
	};

//start==============================================================
//It is   SEQUENCE  

	struct  ModifierStep{


		boost::asn1::value_holder<int >  modifierID;
		boost::asn1::value_holder<Modifier >  modifier;

		ModifierStep()  : modifierID() , modifier()  {}

		 template<typename Archive> void serialize(Archive& arch){

			BOOST_ASN_BIND_TAG(modifierID);
			BOOST_ASN_CHOICE(modifier);
		}
	};

//end==============================================================

	const int VMDState_idle = 0;
	const int VMDState_loaded = 1;
	const int VMDState_ready = 2;
	const int VMDState_executing = 3;
	const int VMDState_motion_paused = 4;
	const int VMDState_manualInterventionRequired = 5;


	const int PhysicalStatus_operational = 0;
	const int PhysicalStatus_partially_operational = 1;
	const int PhysicalStatus_inoperable = 2;
	const int PhysicalStatus_needs_commissioning = 3;


	const int LogicalStatus_state_changes_allowed = 0;
	const int LogicalStatus_no_state_changes_allowed = 1;
	const int LogicalStatus_limited_services_permitted = 2;
	const int LogicalStatus_support_services_allowed = 3;


}


BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::Modifier) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::AccessCondition) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::AccessCondition::user_type) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::Address) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::TypeDescription) 
BOOST_ASN_CHOICE_REGESTRATE(MMS_Object_Module_1::EventTime) 

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif