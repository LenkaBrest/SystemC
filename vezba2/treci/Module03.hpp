#ifndef MODULE03_H
#define MODULE03_H

#include <systemc>
#include <vector>

typedef sc_dt::sc_int<45> num;
typedef std::vector<num> array;

SC_MODULE(Module03)
{
public:
	SC_HAS_PROCESS(Module03);

	Module03(sc_core::sc_module_name name);

	void generatefib();
	void printfib();
protected:
	array a;
};

#endif
