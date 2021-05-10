#ifndef NUCLEAR_HPP
#define NUCLEAR_HPP

#include <systemc>

enum state {inactive, active, exploded};

SC_MODULE(nuclear)
{
public:
	sc_core::sc_event* s0;
	
	static int num;
	
	SC_HAS_PROCESS(nuclear);
	
	nuclear(sc_core::sc_module_name name, sc_core::sc_event* );
	
	
	void process();
	void setState(state);

protected:
	state st;
	
};

#endif
