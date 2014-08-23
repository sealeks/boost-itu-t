/* 
 * File:   extnetintf.cpp
 * Author: Alexeev
 */

#include "mmsmodel.h"
#include <boost/algorithm/string.hpp>

namespace prot9506 {


    /////////////////////////////////////////////////////////////////////////////////////////////////
    //////// objectname
    /////////////////////////////////////////////////////////////////////////////////////////////////        

    objectname::objectname() : obj_(new mmsobject_type()) {
    }

    objectname::objectname(const std::string& id, const std::string& domain) :
    obj_(domain.size() ? new mmsobject_type(MMS::ObjectName::Domain_specific_type(mmsidentifier_type(domain),
    mmsidentifier_type(id)), MMS::ObjectName_domain_specific) : new mmsobject_type(mmsidentifier_type(id), MMS::ObjectName_vmd_specific)) {
    }

    objectname::~objectname() {
    }

    objectname_ptr objectname::create(const std::string& id, const std::string& domain) {
        return objectname_ptr(new objectname(id, domain));
    }

    objectname_ptr objectname::create_aa(const std::string& id) {
        objectname_ptr obj(new objectname());
        obj->obj_ = mmsobject_ptr(new mmsobject_type(mmsidentifier_type(id), MMS::ObjectName_aa_specific));
        return obj;
    }

    // 1 @bind and @domain  =>  domainspesific : @domain | @bind
    // 2 only @bind a) "xxxx" => vmdspesific
    //                         b) "xxxx : yyyy" domain specific @xxxx | @yyyy !!!! high prior,  defdomain ignore if exists
    //                         c) "@xxxx" application spesific @xxxx    

    objectname_ptr objectname::create_from_bind(const std::string& id, const std::string& defdomain) {
        std::string tstid = boost::algorithm::replace_all_copy(id, " ", "");
        std::string tstdom = boost::algorithm::replace_all_copy(defdomain, " ", "");
        std::string::size_type it = tstid.find('/');
        std::string::size_type ita = tstid.find('@');
        if (ita == 0) {
            if (tstid.size() > 0)
                return create_aa(tstid.substr(1));
        } else if ((it != std::string::npos) && (it != (tstid.size() - 1))) {
            tstdom = tstid.substr(0, it);
            tstid = tstid.substr(it + 1);
        }
        if (tstid.size())
            return create(tstid, tstdom);
        return objectname_ptr();
    }

    objectname::operator bool() const {
        return (obj_ && (obj_->type() != MMS::ObjectName_null));
    }

    bool operator==(const objectname& ls, const objectname& rs) {
        if (ls.obj_ && rs.obj_) {
            if (ls.obj_->type() == rs.obj_->type()) {
                switch (ls.obj_->type()) {
                    case MMS::ObjectName_vmd_specific:
                        return *(ls.obj_->vmd_specific()) == *(rs.obj_->vmd_specific());
                    case MMS::ObjectName_domain_specific:
                        return ((ls.obj_->domain_specific()->domainID() == rs.obj_->domain_specific()->domainID()) &&
                                (ls.obj_->domain_specific()->itemID() == rs.obj_->domain_specific()->itemID()));
                    case MMS::ObjectName_aa_specific:
                        return *(ls.obj_->aa_specific()) == *(rs.obj_->aa_specific());
                    default:
                    {
                    }
                        return true;
                }
            }
            return false;
        } else if (!ls.obj_ && !rs.obj_)
            return true;
        return false;
    }

    bool operator<(const objectname& ls, const objectname& rs) {
        if (ls.obj_ && rs.obj_) {
            if (ls.obj_->type() == rs.obj_->type()) {
                switch (ls.obj_->type()) {
                    case MMS::ObjectName_vmd_specific:
                        return *(ls.obj_->vmd_specific()) < *(rs.obj_->vmd_specific());
                    case MMS::ObjectName_domain_specific:
                    {
                        if (ls.obj_->domain_specific()->domainID() == rs.obj_->domain_specific()->domainID())
                            return (ls.obj_->domain_specific()->itemID() < rs.obj_->domain_specific()->itemID());
                        return (ls.obj_->domain_specific()->domainID() < rs.obj_->domain_specific()->domainID());
                    }
                    case MMS::ObjectName_aa_specific:
                        return *(ls.obj_->aa_specific()) < *(rs.obj_->aa_specific());
                    default:
                    {
                    }
                        return false;
                }
            } else if (ls.obj_->type() == MMS::ObjectName_null)
                return true;
            else if (rs.obj_->type() == MMS::ObjectName_null)
                return false;
            return (int) ls.obj_->type() < (int) rs.obj_->type();
        } else if (ls.obj_ && !rs.obj_)
            return false;
        else if (ls.obj_ && !rs.obj_)
            return false;
        else if (!ls.obj_ && !rs.obj_)
            return true;
        return false;
    }

    bool operator==(const objectname_ptr& ls, const objectname_ptr& rs) {
        if (ls && rs)
            return *ls == *rs;
        if (!ls && !rs)
            return true;
        return false;
    }

    bool operator<(const objectname_ptr& ls, const objectname_ptr& rs) {
        if (ls && rs)
            return *ls < *rs;
        if ((!ls && !rs) || (!rs))
            return false;
        return true;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////
    //////// mmsserver_model
    ///////////////////////////////////////////////////////////////////////////////////////////////// 

    bool mmsserver_model::insert(objectname_ptr vl) {
        return false;
    }

    objectname_ptr mmsserver_model::insert(const std::string& vl) {
        return objectname_ptr();
    }

    bool mmsserver_model::remove(objectname_ptr vl) {
        return false;
    }

    objectname_ptr mmsserver_model::remove(const std::string& vl) {
        return objectname_ptr();
    }

    bool mmsserver_model::find(objectname_ptr vl) {
        return false;
    }

    objectname_ptr mmsserver_model::find(const std::string& vl) {
        return objectname_ptr();
    }       


}

