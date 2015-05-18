//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_SELECTORS_IMPLEMENTATIUON_H_
#define	_ITU_SELECTORS_IMPLEMENTATIUON_H_

#include <boost/itu/coder/base_coder.hpp>
#include <boost/itu/asn1/asnbase.hpp>

//#define CHECK_ISO_SELECTOR


#if  defined(ITUX200_DEBUG) && !(defined(DEBUG) || defined(_DEBUG_))
#error "ITUX200_DEBUG = DEBUG MACROS MUST DEFINED"
#endif  

namespace boost {
    namespace itu {


        ///   selectors type            

        class selectorvalue_type {
        public:

            selectorvalue_type() {
            }

            selectorvalue_type(const std::string& vl) : value_(octet_sequnce(vl.begin(), vl.end())) {
            }

            explicit selectorvalue_type(const octet_sequnce& vl) : value_(vl) {
            }

            explicit selectorvalue_type(const int8_t vl) : value_(inttype_to_raw(vl)) {
            }

            explicit selectorvalue_type(const uint8_t vl) : value_(inttype_to_raw(vl)) {
            }

            explicit selectorvalue_type(const int16_t vl) : value_(inttype_to_raw(vl)) {
            }

            explicit selectorvalue_type(const uint16_t vl) : value_(inttype_to_raw(vl)) {
            }

            explicit selectorvalue_type(const int32_t vl) : value_(inttype_to_raw(vl)) {
            }

            explicit selectorvalue_type(const uint32_t vl) : value_(inttype_to_raw(vl)) {
            }

            explicit selectorvalue_type(const int64_t vl) : value_(inttype_to_raw(vl)) {
            }

            explicit selectorvalue_type(const uint64_t vl) : value_(inttype_to_raw(vl)) {
            }

            std::string to_string() const {
                return value_.empty() ? "" : std::string(value_.begin(), value_.end());
            }

            const octet_sequnce& to_raw(std::size_t constraintsize = 0) const {
                if (constraintsize && (value_.size() > constraintsize))
                    value_ = octet_sequnce(value_.begin(), value_.begin() + constraintsize);
                return value_;
            }

        private:
            mutable octet_sequnce value_;
        };


        //  SELECTOR[[SELECTOR]]/......
        // SELECTOR = string | \NNN...N\;
        std::pair<selectorvalue_type, selectorvalue_type> selector_cast(std::string& val);




        ///   selectors

        class transport_selector {
            static const std::size_t SIZE_CONSTRAINT = 16;

        public:

            transport_selector() {
            }

            //  TRANSPORT_SELECTOR-CALLED[[TRANSPORT_SELECTOR-CALLING]]
            transport_selector(const std::string& path);

            explicit transport_selector(const selectorvalue_type& called) :
            called_(called) {
            }

            explicit transport_selector(const selectorvalue_type& called, const selectorvalue_type& calling) :
            called_(called), calling_(calling) {
            }

            const octet_sequnce& called() const {
                return called_.to_raw(SIZE_CONSTRAINT);
            }

            const octet_sequnce& calling() const {
                return calling_.to_raw(SIZE_CONSTRAINT);
            }

            std::string called_str() const {
                return called_.to_string();
            }

            std::string calling_str() const {
                return calling_.to_string();
            }

        private:
            selectorvalue_type called_;
            selectorvalue_type calling_;
        };

        const transport_selector NULL_TRANSPORT_SELECTOR = transport_selector();



        // session            

        class session_selector {
            static const std::size_t SIZE_CONSTRAINT = 16;

        public:

            session_selector() : tselector_() {
            }

            //  SSELECTOR-CALLED[[SSELECTOR-CALLING]]   |
            //  TSELECTOR-CALLED[[TSELECTOR-CALLING]]/ SSELECTOR-CALLED[[SSELECTOR-CALLING]]            
            session_selector(const std::string& path);

            explicit session_selector(const selectorvalue_type& called) :
            called_(called), tselector_() {
            }

            explicit session_selector(const selectorvalue_type& called, const selectorvalue_type& calling) :
            called_(called), calling_(calling), tselector_() {
            }

            explicit session_selector(const selectorvalue_type& called, const transport_selector& tselector) :
            called_(called), tselector_(tselector) {
            }

            explicit session_selector(const selectorvalue_type& called, const selectorvalue_type& calling, const transport_selector& tselector) :
            called_(called), calling_(calling), tselector_(tselector) {
            }

            explicit session_selector(const transport_selector& tselector) :
            tselector_(tselector) {
            }

            const octet_sequnce& called() const {
                return called_.to_raw(SIZE_CONSTRAINT);
            }

            const octet_sequnce& calling() const {
                return calling_.to_raw(SIZE_CONSTRAINT);
            }

            std::string called_str() const {
                return called_.to_string();
            }

            std::string calling_str() const {
                return calling_.to_string();
            }

            const transport_selector& tselector() const {
                return tselector_;
            }

        private:
            selectorvalue_type called_;
            selectorvalue_type calling_;
            transport_selector tselector_;
        };


        const session_selector NULL_SESSION_SELECTOR = session_selector();

        
        
        /// Presentation

        class presentation_selector {
        public:

            presentation_selector() : called_(), calling_(), sselector_() {
            }

            //  PSELECTOR-CALLED[[PSELECTOR-CALLING]]   |
            //  SSELECTOR-CALLED[[SSELECTOR-CALLING]]/ PSELECTOR-CALLED[[PSELECTOR-CALLING]]  |
            //  TSELECTOR-CALLED[[TSELECTOR-CALLING]]/ SSELECTOR-CALLED[[SSELECTOR-CALLING]]/ PSELECTOR-CALLED[[PSELECTOR-CALLING]]              
            presentation_selector(const std::string& path);

            explicit presentation_selector(const selectorvalue_type& called) :
            called_(called), calling_(), sselector_() {
            }

            explicit presentation_selector(const selectorvalue_type& called, const selectorvalue_type& calling) :
            called_(called), calling_(calling), sselector_() {
            }

            explicit presentation_selector(const selectorvalue_type& called, const session_selector& sselector) :
            called_(called), calling_(), sselector_(sselector) {
            }

            explicit presentation_selector(const selectorvalue_type& called, const selectorvalue_type& calling, const session_selector& sselector) :
            called_(called), calling_(calling), sselector_(sselector) {
            }

            presentation_selector(const session_selector& sselector) : called_(), calling_(), sselector_(sselector) {
            }

            const octet_sequnce& called() const {
                return called_.to_raw();
            }

            const octet_sequnce& calling() const {
                return calling_.to_raw();
            }

            void called(const octet_sequnce& val) {
                called_ = selectorvalue_type(val);
            }

            void calling(const octet_sequnce& val) {
                calling_ = selectorvalue_type(val);
            }

            std::string called_str() const {
                return called_.to_string();
            }

            std::string calling_str() const {
                return calling_.to_string();
            }

            const session_selector& sselector() const {
                return sselector_;
            }

        private:

            selectorvalue_type called_;
            selectorvalue_type calling_;
            session_selector sselector_;

        };
        
        const presentation_selector NULL_PRESENTATION_SELECTOR = presentation_selector();        




        ///  acse_selectorvalue_type

        class acse_selectorvalue_type {
        public:

            typedef octet_sequnce app_title1_type;
            typedef boost::asn1::oid_type app_title2_type;
            typedef octet_sequnce ae_qualifier1_type;
            typedef std::size_t ae_qualifier2_type;
            typedef int32_t invoke_id_type;
            typedef shared_ptr<ae_qualifier2_type> ae_qualifier2_type_ptr;
            typedef shared_ptr<invoke_id_type> invoke_id_type_ptr;

            enum form_type {
                form1,
                form2,
                null
            };

            acse_selectorvalue_type() : form_(null) {
            }

            // SELECTOR = {{oid} , [ aeq NN..] , [ apinv NN..] ,  [ aeinv NN..]};            

            acse_selectorvalue_type(const std::string& val) {
                selector_init(*this, val);
            }

            acse_selectorvalue_type(const app_title1_type& ap_title, const ae_qualifier1_type& ae_qualifier,
                    invoke_id_type_ptr ap_inv = invoke_id_type_ptr(), invoke_id_type_ptr ae_inv = invoke_id_type_ptr()) :
            ap_title1_(ap_title), ae_qualifier1_(ae_qualifier), ap_invoke_id_(ap_inv), ae_invoke_id_(ae_inv),
            form_((!ap_title.empty() || !ae_qualifier.empty() || ap_inv || ae_inv) ? form1 : null) {
            }

            acse_selectorvalue_type(const app_title2_type& ap_title, ae_qualifier2_type_ptr ae_qualifier = ae_qualifier2_type_ptr(),
                    invoke_id_type_ptr ap_inv = invoke_id_type_ptr(), invoke_id_type_ptr ae_inv = invoke_id_type_ptr()) :
            ap_title2_(ap_title), ae_qualifier2_(ae_qualifier), ap_invoke_id_(ap_inv), ae_invoke_id_(ae_inv),
            form_((!ap_title.empty() || ae_qualifier || ap_inv || ae_inv) ? form2 : null) {
            }

            const app_title1_type& ap_title1() const {
                return ap_title1_;
            }

            const app_title2_type& ap_title2() const {
                return ap_title2_;
            }

            const ae_qualifier1_type& ae_qualifier1() const {
                return ae_qualifier1_;
            }

            ae_qualifier2_type_ptr ae_qualifier2() const {
                return ae_qualifier2_;
            }

            invoke_id_type_ptr ap_invoke_id() const {
                return ap_invoke_id_;
            }

            invoke_id_type_ptr ae_invoke_id() const {
                return ae_invoke_id_;
            }

            void value(const app_title1_type& ap, const ae_qualifier1_type& ae,
                    invoke_id_type_ptr ap_inv = invoke_id_type_ptr(), invoke_id_type_ptr ae_inv = invoke_id_type_ptr()) {
                ap_title1_ = ap;
                ae_qualifier1_ = ae;
                ap_invoke_id_ = ap_inv;
                ae_invoke_id_ = ae_inv;
                form_ = (!ap_title1_.empty() || !ae_qualifier1_.empty() || ap_invoke_id_ || ae_invoke_id_) ? form1 : null;
            }

            void value(const app_title2_type& ap, const ae_qualifier2_type& ae,
                    invoke_id_type_ptr ap_inv = invoke_id_type_ptr(), invoke_id_type_ptr ae_inv = invoke_id_type_ptr()) {
                ap_title2_ = ap;
                ae_qualifier2_ = ae_qualifier2_type_ptr(new ae_qualifier2_type(ae));
                ap_invoke_id_ = ap_inv;
                ae_invoke_id_ = ae_inv;
                form_ = (!ap_title2_.empty() || ae_qualifier2_ || ap_invoke_id_ || ae_invoke_id_) ? form2 : null;
            }

            form_type form() const {
                return form_;
            }

            operator bool() const {
                return (form_ != null);
            }


        private:

            static void selector_init(acse_selectorvalue_type& self, const std::string& val);

            app_title1_type ap_title1_;
            app_title2_type ap_title2_;
            ae_qualifier1_type ae_qualifier1_;
            ae_qualifier2_type_ptr ae_qualifier2_;
            invoke_id_type_ptr ap_invoke_id_;
            invoke_id_type_ptr ae_invoke_id_;
            form_type form_;
        };




        /// Association

        class application_selector {
        public:

            application_selector() : called_(), calling_(), pselector_() {
            }

            //  ASELECTOR-CALLED[[ASELECTOR-CALLING]]   |      
            //  PSELECTOR-CALLED[[PSELECTOR-CALLING]]/ ASELECTOR-CALLED[[ASELECTOR-CALLING]]  |
            //  SSELECTOR-CALLED[[SSELECTOR-CALLING]]/ PSELECTOR-CALLED[[PSELECTOR-CALLING]]/ ASELECTOR-CALLED[[ASELECTOR-CALLING]]  |
            //  TSELECTOR-CALLED[[TSELECTOR-CALLING]]/ SSELECTOR-CALLED[[SSELECTOR-CALLING]]/ PSELECTOR-CALLED[[PSELECTOR-CALLING]]/ ASELECTOR-CALLED[[ASELECTOR-CALLING]]                    
            application_selector(const std::string& path);

            explicit application_selector(const acse_selectorvalue_type& called) :
            called_(called), calling_(), pselector_() {
            }

            explicit application_selector(const acse_selectorvalue_type& called, const acse_selectorvalue_type& calling) :
            called_(called), calling_(calling), pselector_() {
            }

            explicit application_selector(const acse_selectorvalue_type& called, const presentation_selector & pselector) :
            called_(called), calling_(), pselector_(pselector) {
            }

            explicit application_selector(const acse_selectorvalue_type& called, const acse_selectorvalue_type& calling, const presentation_selector & pselector) :
            called_(called), calling_(calling), pselector_(pselector) {
            }

            application_selector(const presentation_selector & pselector) :
            called_(), calling_(), pselector_(pselector) {
            }

            const acse_selectorvalue_type& called() const {
                return called_;
            }

            const acse_selectorvalue_type& calling() const {
                return calling_;
            }

            void called(const acse_selectorvalue_type& val) {
                called_ = val;
            }

            void calling(const acse_selectorvalue_type& val) {
                calling_ = val;
            }

            void called(const std::string& val) {
                called_ = acse_selectorvalue_type(val);
            }

            void calling(const std::string& val) {
                calling_ = acse_selectorvalue_type(val);
            }

            const presentation_selector & pselector() const {
                return pselector_;
            }

        private:

            acse_selectorvalue_type called_;
            acse_selectorvalue_type calling_;
            presentation_selector pselector_;

        };     
        
        const application_selector NULL_APPLICATION_SELECTOR = application_selector();   
        
        
        


#if defined(ITUX200_DEBUG) 

        std::ostream& operator<<(std::ostream& stream, const transport_selector& self);
        std::ostream& operator<<(std::ostream& stream, const session_selector& self);
        std::ostream& operator<<(std::ostream& stream, const presentation_selector& self);
        std::ostream& operator<<(std::ostream& stream, const acse_selectorvalue_type& self);
        std::ostream& operator<<(std::ostream& stream, const application_selector& self);

#endif                   

    }
} // namespace boost

#endif	

