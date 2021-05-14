#include "module1.hpp"
#include <systemc>
namespace comm
{
	using namespace sc_core;
	using namespace std;

	module1::module1(sc_module_name n) : sc_module(n)
	{
		nums.bind(buff);
		cout << name() << " constructed.\n";
		SC_METHOD(process);
	}

	void module1::process()
	{
			std::vector<int>::iterator it;
			data.push_back(num0);
			data.push_back(num1);
			data.push_back(num2);
			if(data.size()==100)
			{
				sort(data.begin(), data.end());
				for(it=data.begin(); it!=data.end(); ++it )
					buff.nb_write(*it);
			}
					
		
	}

}
