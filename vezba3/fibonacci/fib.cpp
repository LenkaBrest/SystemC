#include <systemc>
#include <iostream>
#include <vector>
#include <ctime>

using namespace sc_core;
using namespace std;

typedef sc_dt::sc_int<45> num;

SC_MODULE(Fib)
{
public:
    sc_core::sc_event s0, s1;

    SC_CTOR(Fib)
    {
        SC_THREAD(generate_fib);
        SC_THREAD(write_mess);
    }

    void generate_fib();
    void write_mess();
protected:
	vector<num> arr;

};

void Fib::generate_fib()
{
	while(1)
	{
		wait(rand() % 91 + 10, SC_NS);
		if(arr.size() % 64 == 0)
			arr.push_back(0);
		else if (arr.size()%64 == 1)
			arr.push_back(1);
		else
			arr.push_back(arr[arr.size()-1] + arr[arr.size()-2]);			
		s0.notify(5, SC_NS);
		wait(s1);
	}
}

void Fib::write_mess()
{
	while(1)
	{
		wait(s0);
		
		std::cout<<(arr.size() - 1)<<"."<<" Fibonacci number is "<<arr[arr.size()-1]<<endl;
		cout<<"Current simulation time is: "<<sc_time_stamp()<<endl;
		s1.notify();
	}
}

int sc_main(int argc, char* argv[])
{

    Fib uut("UUT");
    
    sc_start(70000, SC_NS);
    
    std::cout << "Simulation finished at " << sc_core::sc_time_stamp() << std::endl;

    return 0;
}
