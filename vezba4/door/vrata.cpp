#include <systemc>
#include <ctime>
#include <iostream>

using namespace sc_core;
using namespace std;

enum state {a, b, c, e};
enum door{a_d,b_d,c_d};

SC_MODULE(Door)
{
public:
	sc_event s0;

	SC_HAS_PROCESS(Door);
	
	Door(sc_module_name, state);
	
protected:
	state st;
	
	door d;
	
	int v;
	
	void change_door_state();
	
	void where_am_i();
};

Door::Door(sc_module_name name, state st): sc_module(name), st(st)
{
	SC_THREAD(change_door_state);
	
	SC_METHOD(where_am_i)
		sensitive<<s0;
}

void Door::change_door_state()
{
	srand(time(NULL));
	while(1)
	{
		v=rand()%7+3;
		
		wait(v, SC_SEC);
	
		int g = rand()%3;
		
		switch(g)
		{
			case 0: d = a_d;
				break;
			case 1: d = b_d;
				break;
			case 2: d = c_d;
				break;
			default: assert(false);
		}
		
		cout<<"currently opened "<<d<<endl;
		//cout<<"Current simulation time is "<<sc_time_stamp() << std::endl;
		s0.notify();
	}
}

void Door::where_am_i()
{
	//int p=rand()%6;
	
	//cout<<"currently at door "<<st<<endl;
	
	
	switch(st)
	{
		//cout<<"time"<<v<<endl;
		//cout<<"at door "<<d<<endl;
	
		
		case a: if(v<=5 && d == a_d)
				st = b;
			break;
		case b: if(v<=5)
			{
				if(d == b_d)
					st = c;
			}
			else
				st = a;
			break;
		case c: if(v<=5)
			{
				if(d == c_d)
					st = e;
			}
			else
				st = a;
			break;
		case e: cout<<"end"<<endl;
			  break;
		default: assert(false);
			
	}
	cout<<"currently at door "<<st<<endl;
	cout<<"Current simulation time is "<<sc_time_stamp() << std::endl;
}

int sc_main(int argc, char* argv[])
{
	srand(time(NULL));
	
	Door door("door", a);
	
	sc_start(100, SC_SEC);
	
	cout<<"Current simulation time is "<<sc_time_stamp() << std::endl;
	
	return 0;
}

