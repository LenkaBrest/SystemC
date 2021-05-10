#include "nuclear.hpp"
#include <ctime>

using namespace sc_core;
using namespace std;



nuclear::nuclear(sc_module_name name, sc_event* s) : sc_module(name), s0(s)
{
	SC_THREAD(process);
	st = inactive;
}

int nuclear::num = 0;

void nuclear::setState(state stanje)
{
	st = stanje;
}

void nuclear::process()
{

 if(st == active)
{
	wait(rand() % 10 + 1, SC_NS);
	st = exploded;
	num++;
	s0->notify(SC_ZERO_TIME);
	return;
}

  while(1)
  {
  	wait(*s0);
	int a;
	a = rand() % 100;
	if(a  == 1)
	{
		st = active;
	}
	
  	if(st == active)
	{
		wait(rand() % 10 + 1, SC_NS);
		st = exploded;
		num++;
		s0->notify(SC_ZERO_TIME);
		return;
	}
  	
	
	
	

	
  }	
	
}
