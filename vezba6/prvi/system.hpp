#ifndef _SYS_HPP_
#define _SYS_HPP_

#include <systemc>
#include "module0.hpp"
#include "module1.hpp"

namespace comm
{
using namespace sc_core;

SC_MODULE(system)
{
public:
	SC_HAS_PROCESS(system);

	system(sc_module_name);

	sc_port<sc_signal_in_if<int> > p0;
	sc_in<bool> gen;
	sc_out<bool> start;
	sc_export< sc_fifo<int> > sort_o;
protected:
	module0 m00;
	module0 m01;
	module0 m02;
	module1 m1;
	
	sc_signal<bool> s0;
	sc_signal<bool> s1;
	sc_signal<int> n0;
	sc_signal<int> n1;
	sc_signal<int> n2;

	

};


}
#endif
