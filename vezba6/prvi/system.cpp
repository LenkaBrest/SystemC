#include "system.hpp"

namespace comm
{
	using namespace sc_core;
	using namespace std;

	system::system(sc_module_name n) :
		sc_module(n),
		m00("g0"),
		m01("g1"),
		m02("g2"),
		m1("coll")
		
	{
		
		
		cout << name() << " constructed.\n";
		m00.gen(gen);
		m00.start(s0);
		m00.num(n0);
		
		m01.gen(s0);
		m01.start(s1);
		m01.num(n1);
		
		m02.gen(s1);
		m02.start(start);
		m02.num(n2);
		
		m1.num0(n0);
		m1.num1(n1);
		m1.num2(n2);
		
		sort_o(m1.nums);
		
	}
}

