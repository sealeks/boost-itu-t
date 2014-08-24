/* 
 * File:   extnetintf.cpp
 * Author: Alexeev
 */

#include "mmsmodel.h"
#include <boost/algorithm/string.hpp>
#include <iterator>

namespace prot9506 {

    static std::string first_sub_path(std::string& vl) {
        std::string rslt = vl;
        std::string::size_type fit = vl.find_first_of('$');
        if (fit != std::string::npos) {
            rslt = vl.substr(0, fit);
            if (fit >= (vl.size() - 1))
                vl = "";
            else
                vl = vl.substr(fit + 1);
        } else
            vl = "";
        return rslt;
    }

    static std::string end_sub_path(std::string& vl) {
        std::string rslt = vl;
        std::string::size_type fit = vl.find_last_of('$');
        if (fit != std::string::npos) {
            rslt = vl.substr(0, fit);
            if (fit >= (vl.size() - 1))
                vl = "";
            else
                vl = vl.substr(fit + 1);
        } else
            vl = "";
        return rslt;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////
    //////// objectname
    /////////////////////////////////////////////////////////////////////////////////////////////////        

    objectname::objectname() : obj_(new mmsobject_type()) {
    }

    objectname::objectname(mmsobject_ptr ob) : obj_(ob) {
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

    const mmsidentifier_type& objectname::path() const {
        if (obj_ptr()) {
            if (obj_ptr()->domain_specific())
                return obj_ptr()->domain_specific()->itemID();
            else if (obj_ptr()->aa_specific())
                return *obj_ptr()->aa_specific();
            else if (obj_ptr()->vmd_specific())
                return *obj_ptr()->vmd_specific();
        }
        return NULL_MMSID;
    }

    std::string objectname::name() const {
        const mmsidentifier_type& tmp = path();
        std::string tmps = tmp;
        return end_sub_path(tmps);
    }

    objectname_ptr objectname::insert_child(objectname_ptr vl) {
        childs_.push_back(vl);
        return vl;
    }

    void objectname::remove_child(objectname_ptr vl) {
        childs_.erase(std::remove(childs_.begin(), childs_.end(), vl), childs_.end());
    }

    objectname_ptr objectname::find_child(const std::string& vl) {
        for (objectname_vct::iterator it = childs_.begin(); it != childs_.end(); ++it) {
            if ((*it)->name() == vl)
                return *it;
        }
        return objectname_ptr();
    }

    std::size_t objectname::level() const {
        std::size_t rslt = 0;
        objectname_ptr next = parent();
        while (next) {
            next = next->parent();
            rslt++;
        }
        return rslt;
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

    std::ostream& operator<<(std::ostream& stream, const objectname& vl) {
        std::size_t lev = vl.level();
        while (lev) {
            stream << "   ";
            lev--;
        }
        stream << vl.name() << std::endl;
        for (objectname_vct::const_iterator it = vl.childs().begin(); it != vl.childs().end(); ++it)
            stream << *it;
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream, objectname_ptr vl) {
        if (vl)
            stream << *vl;
        else
            stream << "null";
        return stream;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////
    //////// mmsserver_model
    ///////////////////////////////////////////////////////////////////////////////////////////////// 

    bool mmsserver_model::insert_in(objectname_ptr vl, const mmsidentifier_type& path) {
        if (path.empty())
            return true;
        std::string next = path;
        std::string first = first_sub_path(next);
        if (!first.empty()) {
            objectname_ptr fit = vl->find_child(first);
            if (!fit) {
                const mmsidentifier_type& domname = vl->obj_ptr()->vmd_specific() ? (*vl->obj_ptr()->vmd_specific()) : (vl->obj_ptr()->domain_specific()->domainID());
                fit = vl->insert_child(objectname_ptr(new objectname(mmsobject_ptr(new mmsobject_type(
                        MMS::ObjectName::Domain_specific_type(domname, mmsidentifier_type(path)), MMS::ObjectName_domain_specific)))));
                insert_key(fit);
                fit->parent(vl);
            }
            return insert_in(fit, mmsidentifier_type(next));
        }
        return false;
    }

    bool mmsserver_model::insert_in(const mmsidentifier_type& vl, const mmsidentifier_type& path) {
        mmsobject_ptr dom = mmsobject_ptr(new mmsobject_type(vl, MMS::ObjectName_vmd_specific));
        objectname_ptr domainobj = objectname_ptr(new objectname(dom));
        objectname_ptr fit = find(domainobj);
        if (fit)
            insert_in(fit, path);
        return false;
    }

    bool mmsserver_model::insert_domain(const mmsidentifier_type& vl) {
        mmsobject_ptr dom = mmsobject_ptr(new mmsobject_type(vl, MMS::ObjectName_vmd_specific));
        return insert(objectname_ptr(new objectname(dom)));
    }

    bool mmsserver_model::remove(objectname_ptr vl) {
        objectname_ptr fit = mmsserver_model::find(vl);
        if (fit->parent()) {
            fit->parent()->remove_child(fit);
            remove_key(fit);
            return true;
        } else {
            if (objs_.find(vl) != objs_.end()) {
                remove_key(fit);
                objs_.erase(objs_.find(vl));
                return true;
            }
        }
        return false;
    }

    objectname_ptr mmsserver_model::find(objectname_ptr vl) {
        objectname_set::const_iterator fit = keys_.find(vl);
        if (fit != keys_.end())
            return *fit;
        return objectname_ptr();
    }

    bool mmsserver_model::insert(objectname_ptr vl) {
        if ((vl->obj_ptr())) {
            if (vl->obj_ptr()->vmd_specific()) {
                objs_.insert(vl);
                insert_key(vl);
                return true;
            } else if (vl->obj_ptr()->domain_specific()) {
                mmsobject_ptr dom = mmsobject_ptr(new mmsobject_type(
                        vl->obj_ptr()->domain_specific()->domainID(), MMS::ObjectName_vmd_specific));
                objectname_ptr domainobj = objectname_ptr(new objectname(dom));
                objectname_ptr fit = find(domainobj);
                if (fit) {
                    return insert_in(fit, vl->obj_ptr()->domain_specific()->itemID());
                }
            }
        }
        return false;
    }

    bool mmsserver_model::insert_key(objectname_ptr vl) {
        bool notexists = (keys_.find(vl) == keys_.end());
        keys_.insert(vl);
        return notexists;
    }

    void mmsserver_model::insert_keys(const objectname_set& vl) {
        for (objectname_set::const_iterator it = vl.begin(); it != vl.end(); ++it)
            insert_key(*it);
    }

    bool mmsserver_model::remove_key(objectname_ptr vl) {
        objectname_set::iterator fit = keys_.find(vl);
        if (fit != keys_.end()) {
            for (objectname_vct::const_iterator it = (*fit)->childs().begin(); it != (*fit)->childs().end(); ++it)
                remove_key(*it);
            keys_.erase(fit);
            return true;
        }
        return false;
    }

    std::ostream& operator<<(std::ostream& stream, const mmsserver_model& vl) {
        for (objectname_set::const_iterator it = vl.objs().begin(); it != vl.objs().end(); ++it)
            stream << *it;
        return stream;
    }

}

