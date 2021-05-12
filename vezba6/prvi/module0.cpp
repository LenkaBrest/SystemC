#include "module0.hpp"
#include <ctime>

namespace comm
{
	using namespace sc_core;
	using namespace std;

	module0::module0(sc_module_name n) : sc_module(n)
	{
		cout << name() << " constructed.\n";
		SC_THREAD(process);
			
		srand(time(NULL));
	}

	void module0::process()
	{
		if(gen)
		{
			wait((rand()%5+6), SC_NS);
			num->write(rand()%100);
			start->write(true);
		}
	}
}
