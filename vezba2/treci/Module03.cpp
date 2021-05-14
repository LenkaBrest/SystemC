#include "Module03.hpp"
#include <cstdlib>
#include <ctime>

using namespace sc_core;
using namespace std;

Module03::Module03(sc_core::sc_module_name name) : sc_module (name)
{
	SC_THREAD(generatefib);
 	SC_THREAD(printfib);
}

void Module03::generatefib()
{
	while(1)
    	{
        	if((a.size() % 65 == 0))
        	{
         		a.push_back(0);
        	}
        	else if((a.size() % 65 == 1))
        	{
            		a.push_back(1);
        	}
        	else
        	{
            		a.push_back(a[a.size()-1] + a[a.size()-2]);
       		}
        	wait(rand() % 91 + 10, SC_NS);
    	}
}

void Module03::printfib()
{
	while(1)
	{
		wait(1, SC_SEC);
		cout<<"Fibonacci numbers: "<<a.size()<<endl;
		a.clear();
	}
}
