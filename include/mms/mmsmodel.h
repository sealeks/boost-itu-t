/* 
 * File:   extnetintf.h
 * Author: Alexeev
 *
 * 
 */

#ifndef MMSMODEL_H
#define	MMSMODEL_H

#include <boost/weak_ptr.hpp>

#include <mms/mmssocket.h>
#include <mms/MMS-Object-Module-1.hpp>
#include <mms/ISO-9506-MMS-1.hpp>

namespace prot9506 {


    namespace MMS = ISO_9506_MMS_1;
    namespace MMSO = MMS_Object_Module_1;


    class objectname;

    typedef MMSO::Identifier mmsidentifier_type;
    typedef MMS::ObjectName mmsobject_type;
    typedef MMS::ObjectClass mmsclass_type;
    typedef MMS::GetVariableAccessAttributes_Response access_attribute_type;
    typedef MMS::Data mmsdata_type;
    typedef MMS::AccessResult mmsresult_type;
    typedef MMS::Read_Response::ListOfAccessResult_type resultslist_type;
    typedef MMS::ServiceError serviceerror_type;


    typedef boost::shared_ptr<mmsobject_type> mmsobject_ptr;
    typedef boost::shared_ptr<mmsclass_type> mmsclass_ptr;
    typedef boost::shared_ptr<access_attribute_type> access_attribute_ptr;
    typedef boost::shared_ptr<mmsresult_type> mmsresult_ptr;
    typedef boost::shared_ptr< serviceerror_type> serviceerror_ptr;


    typedef boost::shared_ptr<objectname> objectname_ptr;
    typedef boost::weak_ptr<objectname> objectname_wptr;

    typedef std::vector<objectname_ptr> objectname_vct;
    typedef std::set<objectname_ptr> objectname_set;


    const mmsidentifier_type NULL_MMSID = "";



    /////////////////////////////////////////////////////////////////////////////////////////////////
    //////// objectname
    /////////////////////////////////////////////////////////////////////////////////////////////////    

    class objectname {

    public:

        objectname();
        objectname(mmsobject_ptr ob);
        objectname(const std::string& id, const std::string& domain = "");

        virtual ~objectname();

        static objectname_ptr create(const std::string& id, const std::string& domain = "");
        static objectname_ptr create_aa(const std::string& id);

        // 1 @bind and @domain  =>  domainspesific : @domain | @bind
        // 2 only @bind a) "xxxx" => vmdspesific
        //                         b) "xxxx : yyyy" domain specific @xxxx | @yyyy !!!! high prior  defdomain ignore if exists
        //                         c) "@xxxx" application spesific @xxxx
        static objectname_ptr create_from_bind(const std::string& id, const std::string& defdomain = "");

        objectname_ptr parent() const {
            return !parent_._empty() ? parent_.lock() : objectname_ptr();
        }

        void parent(objectname_ptr vl) {
            parent_ = objectname_wptr(vl);
        }

        const objectname_vct& childs() const {
            return childs_;
        }

        objectname_ptr insert_child(objectname_ptr vl);

        void remove_child(objectname_ptr vl);

        mmsobject_type obj() const {
            return obj_ ? (*obj_) : mmsobject_type();
        }

        mmsobject_ptr obj_ptr() const {
            return obj_;
        }

        const mmsidentifier_type& path() const;

        std::string name() const;

        access_attribute_ptr access() const {
            return access_;
        }

        void access(access_attribute_ptr vl) {
            access_ = vl;
        }

        mmsclass_ptr _class() const {
            return class_;
        }

        void _class(mmsclass_ptr vl) {
            class_ = vl;
        }

        mmsresult_ptr data() const {
            return data_;
        }

        virtual void data(mmsresult_ptr vl) {
            data_ = vl;
        }

        std::size_t level() const;

        operator bool() const;

        objectname_ptr find_child(const std::string& vl);

        friend bool operator==(const objectname& ls, const objectname& rs);
        friend bool operator<(const objectname& ls, const objectname& rs);
        friend bool operator==(const objectname_ptr& ls, const objectname_ptr& rs);
        friend bool operator<(const objectname_ptr& ls, const objectname_ptr& rs);



    private:

        mmsobject_ptr obj_;
        objectname_wptr parent_;
        objectname_vct childs_;
        mmsclass_ptr class_;
        access_attribute_ptr access_;
        mmsresult_ptr data_;
    };


    std::ostream& operator<<(std::ostream& stream, const objectname& vl);
    std::ostream& operator<<(std::ostream& stream, objectname_ptr vl);

    /////////////////////////////////////////////////////////////////////////////////////////////////
    //////// mmsserver_model
    /////////////////////////////////////////////////////////////////////////////////////////////////        

    class mmsserver_model {

    public:

        mmsserver_model() {
        }

        virtual ~mmsserver_model() {
        }

        const objectname_set& objs() const {
            return objs_;
        }

        bool insert_domain(const mmsidentifier_type& vl);

        bool insert_in(objectname_ptr vl, const mmsidentifier_type& path);

        bool insert_in(const mmsidentifier_type& vl, const mmsidentifier_type& path);

        bool remove(objectname_ptr vl);

        objectname_ptr find(objectname_ptr vl);

    protected:

        bool insert(objectname_ptr vl);
        bool insert_key(objectname_ptr vl);
        void insert_keys(const objectname_set& vl);
        bool remove_key(objectname_ptr vl);

        objectname_set objs_;
        objectname_set keys_;

    };

    std::ostream& operator<<(std::ostream& stream, const mmsserver_model& vl);


}

#endif	/* EXTNETINTF_H */

