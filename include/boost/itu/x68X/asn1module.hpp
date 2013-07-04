//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_ASN1MODULE_IMPLEMENTATIUON_H_
#define	_ITU_ASN1MODULE_IMPLEMENTATIUON_H_



#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>

#include <boost/itu/x68X/x680.hpp>





namespace x680 {

 /*   std::size_t read_module_file(const std::string path, std::string& src);

    template <typename T> std::string to_str(const T& val) {

        std::string result = "";
        try {
            result = boost::lexical_cast<std::string > (val);
        }
        catch (boost::bad_lexical_cast) {
            return "";
        }
        return result;
    };

    typedef std::vector<std::string> object_identificator_type;
    
    

    class entity_type {
    public:
        
        typedef x680::defined_type defined_type;

        entity_type() :
        name_(""), type_(t_NODEF) {
        }

        entity_type(const std::string& name) :
        name_(name), type_(t_NODEF) {
        }

        const std::string& name() const {
            return name_;
        }

        void name(const std::string& val) {
            name_ = val;
        }
        
         defined_type type() const {
            return type_;
        }

        void type(defined_type val) {
            type_ = val;
        }
        
    private:

        std::string name_;
        defined_type type_;
    };

    typedef boost::shared_ptr<entity_type> entity_ptr;
    typedef std::vector< entity_ptr> entities_type;
    typedef boost::shared_ptr<entities_type> entities_ptr;    
    
    
    

    
    class import_module {
    public:

        import_module(const std::string& name = "") : name_(name), elements_(new entities_type()) {
        };

        virtual ~import_module() {
        };

        const std::string& name() const {
            return name_;
        }

        void name(const std::string& val) {
            name_ = val;
        }

        const object_identificator_type& definitive_identifier() const {
            return definitive_identifier_;
        }

        object_identificator_type& definitive_identifier() {
            return definitive_identifier_;
        }

        entities_ptr elements() const {
            return elements_;
        }

        entities_ptr elements() {
            return elements_;
        }

    private:
        std::string name_;
        object_identificator_type definitive_identifier_;
        entities_ptr elements_;
    };



    typedef boost::shared_ptr<import_module> import_module_ptr;
    typedef std::vector<import_module_ptr> import_mdules;

    class asn1module {
    public:

        
        typedef x680::tagrule_type tagrule_type;
        typedef x680::encoding_references_type encoding_references_type;

        asn1module(const std::string& name , entities_ptr ents) :
        name_(name),
        default_tags_(explicit_tags),
        encoding_references_(encoding_no),
        extesibility_implied_(false),
        elements_(ents){
        }

        virtual ~asn1module() {
        };

        const std::string& name() const {
            return name_;
        }

        void name(const std::string& val) {
            name_ = val;
        }

        entities_type& exports() {
            return exports_;
        }

        const entities_type& exports() const {
            return exports_;
        }

        import_mdules& imports() {
            return imports_;
        }

        const import_mdules& imports() const {
            return imports_;
        }

        const object_identificator_type& definitive_identifier() const {
            return definitive_identifier_;
        }

        object_identificator_type& definitive_identifier() {
            return definitive_identifier_;
        }

        tagrule_type default_tags() const {
            return default_tags_;
        }

        void default_tags(tagrule_type val) {
            default_tags_ = val;
        }

        encoding_references_type encoding_references() const {
            return encoding_references_;
        }

        void encoding_references(encoding_references_type val) {
            encoding_references_ = val;
        }

        bool extesibility_implied() const {
            return extesibility_implied_;
        }

        void extesibility_implied(bool val) {
            extesibility_implied_ = val;
        }

        entities_ptr  elements() const {
            return elements_;
        }

        entities_ptr  elements() {
            return elements_;
        }

    private:

        std::string name_;
        object_identificator_type definitive_identifier_;
        tagrule_type default_tags_;
        encoding_references_type encoding_references_;
        bool extesibility_implied_;
        entities_type exports_;
        import_mdules imports_;
        entities_ptr elements_;
    };






    typedef boost::shared_ptr<asn1module> asn1module_ptr;
    typedef std::vector<asn1module_ptr> asn1modules;
    typedef boost::shared_ptr<asn1modules> asn1modules_ptr;


*/

}

#endif	

