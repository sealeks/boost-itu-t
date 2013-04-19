//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef ___ITU__UTILS_H
#define	___ITU__UTILS_H

#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/thread/xtime.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/cstdint.hpp>
#include <boost/algorithm/string.hpp>

namespace itu {
    namespace utils {

        using boost::uint64_t;

        template <typename T>
        class callable_shared_ptr {
        public:
            typedef typename boost::shared_ptr<T> sh_ptrtype;

            callable_shared_ptr() {
            };

            virtual ~callable_shared_ptr() {
                if (!(sh_ptr.use_count() - 1)) {
                    ;
                }
            };

            callable_shared_ptr(T* src) {
                sh_ptr = sh_ptrtype(src);
            }

            callable_shared_ptr(const callable_shared_ptr& val) {
                sh_ptr = val.sh_ptr;
            }

            sh_ptrtype ptr() {
                return sh_ptr;
            }

            void operator()() {
                sh_ptr->operator()();
            }

            callable_shared_ptr& operator=(const callable_shared_ptr& val) {
                sh_ptr = val.sh_ptr;
                return *this;
            }

            T& operator*() const {
                return sh_ptr.operator*();
            }

            T* operator-> () const {
                return sh_ptr.operator ->();
            }

            operator bool() {
                return sh_ptr;
            }

            void reset() {
                sh_ptr.reset();
            }

            void swap(callable_shared_ptr & other) {
                sh_ptr.swap(other.sh_ptr);
            }

            bool unique() const {
                return sh_ptr.unique();
            }

            long use_count() const {
                return sh_ptr.use_count();
            }

            void terminate() {
                if (sh_ptr) sh_ptr->terminate();
            }


        private:
            sh_ptrtype sh_ptr;
        };

        template <typename T> std::string to_str(const T& val) {

            std::string result = "";
            try {
                result = boost::lexical_cast<std::string > (val);
            }
            catch (boost::bad_lexical_cast) {
                return "";
            }
            return result;
        }

        void addmillisec_to_now(boost::xtime& xt, uint64_t milsec);

    }
}

namespace boost {
    namespace itu {

        bool oid_component_by_name(const std::string& val, std::size_t& rslt);
        
        template<typename T>
        bool string_to(const std::string& val, T& rslt) {
            try {
                rslt = boost::lexical_cast<T > (boost::algorithm::trim_copy(val));
                return true;
            }
            catch (boost::bad_lexical_cast &) {
                return false;
            }            
        }

    }
}

#endif	/*___ITU__UTILS_H */

