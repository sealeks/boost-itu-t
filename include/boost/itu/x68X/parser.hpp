//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680ROOTPARSER_H_
#define          _ITU_X680ROOTPARSER_H_

#include <boost/itu/x68X/semantics.hpp>
#include <boost/program_options.hpp>
#include <boost/lexical_cast.hpp>

namespace x680 {



    bool dir_exists(const std::string& path);
    bool dir_create(const std::string& path, const std::string& outdir);
    
        template<typename T>
        std::string to_string(T val) {
            try {
                return boost::lexical_cast<std::string > (val);
            } catch (boost::bad_lexical_cast) {
            }
            return "???";
        }
    
       

    namespace po = boost::program_options;
    
    typedef po::variables_map compile_option;
    
 
        //////////////////////////////////////////////////////
        //  base_options
        //////////////////////////////////////////////////////
   
        
        class base_options {

        public:

            base_options(const compile_option& opt) : opt_(opt) {};
            
            virtual ~base_options(){};

            bool option_no_holder() const;

            bool option_reverse_decl() const;

            bool option_ber_main() const;
            
            bool option_cout_metod() const;      
            
            bool option_define_struct() const;
            
            bool option_c11() const;             
            
            std::string option_path() const;
            
            std::string option_outdir() const;      
            
            std::string option_httpoutdir() const;            
            
            const compile_option options() const {
                return opt_;
            }

        protected:

            compile_option opt_;
        };        

        

}



#endif	

