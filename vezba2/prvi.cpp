#include <systemc>
#include <iostream>
#include <time.h>
 
int sc_main(int argc, char *argv[])
{
    srand(time(NULL));

    sc_core::sc_time t((rand() % 91) + 10, sc_core::SC_NS);

    sc_start(t);
 
    std::cout << "SystemC. Current simulation time is= " << sc_core::sc_time_stamp() << std::endl;
   
     return 0;
}
