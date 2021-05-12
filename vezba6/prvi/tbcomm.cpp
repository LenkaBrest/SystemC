#include "tbcomm.hpp"

namespace comm
{
	using namespace sc_core;
	using namespace std;

	tbcomm::tbcomm(sc_module_name n) : sc_module(n), uut("UUT")
	{
		cout << name() << " constructed.\n";
		uut.gen(gen);
		uut.start(start);
		//uut.sort_o(res);
		SC_THREAD(driver);
		SC_THREAD(monitor);
		
	}

	void tbcomm::driver()
	{
		gen = true;
		wait(5, SC_NS);
	}

	void tbcomm::monitor()
	{
	int br;	
		while(1)
		{
			uut.sort_o->nb_read(br) ;
			cout << "From export: " << br<< endl;
			wait(2, SC_NS);
		}
	}
}
