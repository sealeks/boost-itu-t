//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/itu/x22X/selectors.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/itu/utils/utils.h>

namespace boost {
    namespace itu {

        inline static bool selector_test_as_number(std::string& val) {
            if (val.size() > 2) {
                if ((val[0] == '\\') && (val[val.size() - 1] == '\\')) {
                    std::string tmp = boost::algorithm::trim_copy(val.substr(1, val.size() - 2));
                    int64_t rslt = 0;
                    try {
                        rslt = boost::lexical_cast<int64_t > (tmp);
                    }                    catch (...) {
                        return false;
                    }
                    if (rslt) {
                        val = "";
                        while (rslt) {
                            val.push_back(static_cast<std::string::value_type> (0xFF & rslt));
                            rslt >>= 8;
                        }
                    }
                }
            }
            return false;
        }

        std::pair<selectorvalue_type, selectorvalue_type> selector_cast(std::string& val) {
            if (val.empty())
                return std::pair<selectorvalue_type, selectorvalue_type > (selectorvalue_type(), selectorvalue_type());
            std::string::size_type end = val.find_last_of("/");
            std::string selector = (end == std::string::npos) ? val : val.substr(end + 1);
            val = (end == std::string::npos) ? "" : val.substr(0, end);
            boost::algorithm::trim(val);
            if (!selector.empty()) {
                std::string::size_type sbeg = selector.find_first_of("[");
                std::string::size_type send = selector.find_last_of("]");
                std::string selector1 = (sbeg != std::string::npos && send != std::string::npos && sbeg < send) ?
                        selector.substr(0, sbeg) : selector;
                std::string selector2 = (sbeg != std::string::npos && send != std::string::npos && sbeg < send) ?
                        selector.substr(sbeg + 1, send - sbeg - 1) : "";
                boost::algorithm::trim(selector1);
                boost::algorithm::trim(selector2);
                selector_test_as_number(selector1);
                selector_test_as_number(selector2);
                return std::pair<selectorvalue_type, selectorvalue_type > (selectorvalue_type(selector1), selectorvalue_type(selector2));
            }
            return std::pair<selectorvalue_type, selectorvalue_type > (selectorvalue_type(), selectorvalue_type());
        }



        //transport_selector

        transport_selector::transport_selector(const std::string& path) {
            std::string tmp = path;
            std::pair<selectorvalue_type, selectorvalue_type> selectors = selector_cast(tmp);
            called_ = selectors.first;
            calling_ = selectors.second;
        }

        //session_selector

        session_selector::session_selector(const std::string& path) {
            std::string tmp = path;
            std::pair<selectorvalue_type, selectorvalue_type> selectors = selector_cast(tmp);
            called_ = selectors.first;
            calling_ = selectors.second;
            if (!tmp.empty()) {
                tselector_ = transport_selector(tmp);
            }
        }

        //presentation_selector

        presentation_selector::presentation_selector(const std::string& path) {
            std::string tmp = path;
            std::pair<selectorvalue_type, selectorvalue_type> selectors = selector_cast(tmp);
            called_ = selectors.first;
            calling_ = selectors.second;
            if (!tmp.empty()) {
                sselector_ = session_selector(tmp);
            }
        }

        //acse_selectorvalue_type

        void acse_selectorvalue_type::selector_init(acse_selectorvalue_type& self, const std::string& vl) {
            std::string val = boost::algorithm::trim_copy(vl);
            if (val.size() > 2) {
                if ((val[0] == '{') && (val[val.size() - 1] == '}')) {
                    val = val.substr(1, val.size() - 2);
                    std::string::size_type oidpos = val.find_first_of("}");
                    std::string::size_type ppos = val.find_first_of(",", oidpos == std::string::npos ? 0 : oidpos);
                    if (ppos != std::string::npos) {
                        if (oidpos != std::string::npos)
                            self.ap_title2_ = app_title2_type(boost::asn1::oid_from_string(val.substr(0,
                                oidpos == std::string::npos ? ppos : (oidpos + 1))));
                        val = val.substr(ppos + 1);

                        if (!val.empty()) {
                            ppos = val.find_first_of(",");
                            ae_qualifier2_type aeq;
                            if (ppos != std::string::npos) {

                                if (string_to(val.substr(0, ppos), aeq))
                                    self.ae_qualifier2_ = ae_qualifier2_type_ptr(new ae_qualifier2_type(aeq));
                                val = val.substr(ppos + 1);

                                if (!val.empty()) {
                                    ppos = val.find_first_of(",");
                                    invoke_id_type api;
                                    if (ppos != std::string::npos) {
                                        if (string_to(val.substr(0, ppos), api))
                                            self.ap_invoke_id_ = invoke_id_type_ptr(new invoke_id_type(api));

                                        val = val.substr(ppos + 1);
                                        if (!val.empty()) {
                                            if (string_to(val, api))
                                                self.ae_invoke_id_ = invoke_id_type_ptr(new invoke_id_type(api));
                                        }
                                    } else {
                                        if (string_to(val, api))
                                            self.ap_invoke_id_ = invoke_id_type_ptr(new invoke_id_type(api));
                                    }
                                }
                            } else {
                                if (string_to(val, aeq))
                                    self.ae_qualifier2_ = ae_qualifier2_type_ptr(new ae_qualifier2_type(aeq));
                            }
                        }
                    } else
                        self.ap_title2_ = app_title2_type(boost::asn1::oid_from_string(val));
                }
            }
            self.form_ = (!self.ap_title2_.empty() || self.ae_qualifier2_ || self.ap_invoke_id_ || self.ae_invoke_id_) ? form2 : null;
        }

        //presentation_selector

        application_selector::application_selector(const std::string& path) {
            std::string tmp = path;
            std::pair<selectorvalue_type, selectorvalue_type> selectors = selector_cast(tmp);
            called_ = acse_selectorvalue_type(selectors.first.to_string());
            calling_ = acse_selectorvalue_type(selectors.second.to_string());
            if (!tmp.empty()) {
                pselector_ = presentation_selector(tmp);
            }
        }





#if defined(ITUX200_DEBUG) 

        std::ostream& operator<<(std::ostream& stream, const transport_selector& self) {
            return stream << "Transport selector is called  = " << self.called_str() << ",  calling = " << self.calling_str() << " ;\n";
        }

        std::ostream& operator<<(std::ostream& stream, const session_selector& self) {
            stream << "Session selector is called  = " << self.called_str() << ",  calling = " << self.calling_str() << ";\n";
            return stream << self.tselector();
        }

        std::ostream& operator<<(std::ostream& stream, const presentation_selector& self) {
            stream << "Presentation selector is called  = " << self.called_str() << ",  calling = " << self.calling_str() << ";\n";
            return stream << self.sselector();
        }

        std::ostream& operator<<(std::ostream& stream, const acse_selectorvalue_type& self) {
            stream << "ACSE value type   = ";
            switch (self.form()) {
                case acse_selectorvalue_type::form1:
                {
                    stream << "form1  ";
                    if (!self.ap_title1().empty())
                        stream << " AP-Title: " << std::string(self.ap_title1().begin(), self.ap_title1().end());
                    if (!self.ae_qualifier1().empty())
                        stream << " AE-Qual: " << std::string(self.ae_qualifier1().begin(), self.ae_qualifier1().end());
                    if (self.ap_invoke_id())
                        stream << " AP-inv-id: " << (*self.ap_invoke_id());
                    if (self.ae_invoke_id())
                        stream << " AE-inv-id: " << (*self.ae_invoke_id());
                    return stream << "\n";
                }
                case acse_selectorvalue_type::form2:
                {
                    stream << "form2  ";
                    if (!self.ap_title2().empty())
                        stream << " AP-Title: " << self.ap_title2();
                    if (self.ae_qualifier2())
                        stream << " AE-Qual: " << (*self.ae_qualifier2());
                    if (self.ap_invoke_id())
                        stream << " AP-inv-id: " << (*self.ap_invoke_id());
                    if (self.ae_invoke_id())
                        stream << " AE-inv-id: " << (*self.ae_invoke_id());
                    return stream << "\n";
                }
                default:
                {
                    return stream << "NULL\n";
                }
            }
            return stream;
        }

        std::ostream& operator<<(std::ostream& stream, const application_selector& self) {
            stream << "Association selector is ";
            if (self.called())
                stream << " called  = " << self.called();
            if (self.calling())
                stream << " calling = " << self.calling();
            return stream << self.pselector();
        }

#endif           


    }
}
