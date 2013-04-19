//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <cstdlib>
#include <deque>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define BOOST_THREAD_USE_LIB

#include <boost/thread/thread.hpp>
#include <boost/itu/utils/utils.h>


#include <boost/itu/x22X/selectors.hpp>


using namespace boost::itu;

using boost::asn1::oid_type;



int main(int argc, char* argv[]) {
    
    /*transport_selector tsl(selectorvalue_type("transport_called"), selectorvalue_type("transport_calling"));
    session_selector ssl(selectorvalue_type("session_called"), selectorvalue_type("session_calling"), tsl);
    presentation_selector psl(selectorvalue_type("presentation_called"), selectorvalue_type("presentation_calling"), ssl);*/
    
    /*transport_selector tsl(std::string("transport_called[transport_calling]"));
    session_selector ssl(std::string("transport_called[transport_calling]/session_called[session_calling]"));
    presentation_selector psl(std::string("transport_called[transport_calling]/session_called[session_calling]/presentation_called[presentation_calling]"));*/ 
    
    transport_selector tsl("transport_called[transport_calling]");
    session_selector ssl("transport_called[transport_calling]/session_called[session_calling]");
    presentation_selector psl("presentation_called[presentation_calling]");
    application_selector asl("transport_called[transport_calling]//presentation_called[presentation_calling]/ { {1,3,2,4,200,23456} , 5 , , 8 } [{ {1,3,2,4,200,23456} , 500 ,77 , 88 }]");
    
    std::cout << "TSELECTOR: "  << tsl << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------------------------"   << std::endl;
     std::cout << "SSELECTOR: "  << ssl << std::endl;   
    std::cout << "--------------------------------------------------------------------------------------------------------------------------"   << std::endl;
     std::cout << "PSELECTOR: "  << psl << std::endl;   
    std::cout << "--------------------------------------------------------------------------------------------------------------------------"   << std::endl;
     std::cout << "ASELECTOR: "  << asl << std::endl;   
     
     oid_type testoid("{ iso ,3,2,4,5} ");
     std::cout << "TESTOID: "  << testoid << std::endl; 
     
     //acse_selectorvalue_type acsesel(testoid, acse_selectorvalue_type::ae_qualifier2_type_ptr( new acse_selectorvalue_type::ae_qualifier2_type(20)) );
	 acse_selectorvalue_type acsesel("{ {1,3,2,4,200,23456} , 5 , , 8 }");
       std::cout << "ACSE SEL VALUE: "  << acsesel << std::endl;    
     /*std::string test ="  ggmmmmmmmmmmmmmmmmmmmmmm /\\1234\\  [  SECONDSELECTOR  ]";
     std::pair<selectorvalue_type, selectorvalue_type> result = selector_cast(test);
     
     std::cout << "TEST  S1:  \\"  <<    result.first.to_string() << "\\  S2:  \\"  <<  result.second.to_string() << "\\  ost: \\"  << test << "\\" << std::endl;*/
      
}