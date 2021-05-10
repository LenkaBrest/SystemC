#include <iostream>
#include <systemc>
#include <ctime>
#include "nuclear.hpp"

using namespace sc_core;
using namespace std;


int sc_main(int argc, char* argv[])
{	
	srand(time(NULL));
	sc_event se;
	nuclear *uut[1000];
	
	char name[4];	
	
	
	for(int i = 0; i < 1000; ++i)
	{
		sprintf(name, "%i", i);
		uut[i] = new nuclear(name, &se);
	}
	
	uut[0]->setState(active);
	

	sc_start(100, SC_NS);
		
	cout<<"Exploded: "<<uut[1000]->num<<" particles"<<endl;
	cout<<"Current simulation time is "<<sc_time_stamp() << std::endl;
	
	return 0;
}
