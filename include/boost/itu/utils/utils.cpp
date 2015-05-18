#include <boost/itu/utils/utils.h>
#include <map>



namespace itu {
    namespace utils {

        void addmillisec_to_now(boost::xtime& xt, uint64_t milsec) {
            boost::xtime_get(&xt, boost::TIME_UTC_);
            xt.sec += milsec / 1000;
            if ((xt.nsec + (milsec % 1000) * 1000000) < 1000000000) {
                xt.nsec += (milsec % 1000) * 1000000;
            }
            else {
                xt.sec += 1;
                xt.nsec += ((milsec % 1000) * 1000000 + xt.nsec - 1000000000);
            }
        }

    }
}

namespace boost {
    namespace itu {

        namespace global {

            typedef std::pair<std::string, std::size_t> globaloid_pair;
            typedef std::map<std::string, std::size_t> globaloid_map;
            typedef shared_ptr<globaloid_map> globaloid_map_ptr;

            const std::string GLOBAL_OID_COMPONENT_ISO = "iso";
            const std::string GLOBAL_OID_COMPONENT_ITU_T = "itu-t";
            const std::string GLOBAL_OID_COMPONENT_CCIITT = "ccitt";
            const std::string GLOBAL_OID_COMPONENT_JOINT_ISO_ITU_T = "joint-iso-itu-t";
            const std::string GLOBAL_OID_COMPONENT_JOINT_ISO_CCIITT = "joint-iso-ccitt";

            inline static globaloid_map_ptr init_map() {
                globaloid_map_ptr rslt = globaloid_map_ptr(new globaloid_map());
                rslt->insert(globaloid_pair(GLOBAL_OID_COMPONENT_ITU_T, 0));
                rslt->insert(globaloid_pair(GLOBAL_OID_COMPONENT_CCIITT, 0));
                rslt->insert(globaloid_pair(GLOBAL_OID_COMPONENT_ISO, 1));
                rslt->insert(globaloid_pair(GLOBAL_OID_COMPONENT_JOINT_ISO_ITU_T, 2));
                rslt->insert(globaloid_pair(GLOBAL_OID_COMPONENT_JOINT_ISO_CCIITT, 2));
                return rslt;
            }

        }

        bool oid_component_by_name(const std::string& str, std::size_t& vl) {
            static boost::itu::global::globaloid_map_ptr global = boost::itu::global::init_map();
            std::string val = boost::algorithm::trim_copy(boost::algorithm::to_lower_copy(str));
            boost::itu::global::globaloid_map::iterator it = global->find(val);
            if (it != global->end()) {
                vl = it->second;
                return true;
            }
            return false;
        }
    }
}
