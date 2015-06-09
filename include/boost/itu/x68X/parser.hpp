//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X680ROOTPARSER_H_
#define          _ITU_X680ROOTPARSER_H_

#include <boost/itu/x68X/semantics.hpp>
#include <boost/program_options.hpp>

namespace x680 {

    namespace po = boost::program_options;
    
    typedef po::variables_map compile_option;
    
 
        //////////////////////////////////////////////////////
        //  base_options
        //////////////////////////////////////////////////////
   
        
        class base_options {

        public:

            base_options(const compile_option& opt) : opt_(opt) {};
            
            virtual ~base_options();

            bool option_no_holder() const;

            bool option_reverse_decl() const;

            bool option_ber_main() const;
            
            bool option_cout_metod() const;      
            
            std::string option_path() const;
            
            std::string option_outdir() const;      
            
            const compile_option options() const {
                return opt_;
            }

        protected:

            compile_option opt_;
        };        

        

}



#endif	

