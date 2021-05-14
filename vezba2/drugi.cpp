#include <systemc>
#include <iostream>
#include <time.h>
 
int sc_main(int argc, char *argv[])
{
    srand(time(NULL));

    sc_core::sc_time t1((rand() % 10) + 1, sc_core::SC_NS);
    sc_core::sc_time t2((rand() % 10) + 1, sc_core::SC_NS);
    
    sc_start(t1+t2);
    
    std::cout << "t1="<< t1 << std::endl << "t2=" << t2 << std::endl <<"SystemC. Current simulation time is= " << sc_core::sc_time_stamp() << std::endl;
  
  return 0;
}
