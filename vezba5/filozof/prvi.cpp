#include <systemc>
#include <iostream>
#include <string>
#include <ctime>

using namespace sc_core;
using namespace std;

enum state{thinking, left_fork, right_fork, eating};

SC_MODULE(Filozof)
{
public:
	SC_HAS_PROCESS(Filozof);

	Filozof(sc_module_name name, sc_mutex*, sc_mutex* );
	
	unsigned int has_one_fork();

protected:
	//sc_event s0;
	sc_mutex* fork_left;
	
	sc_mutex* fork_right;
	
	state st;
	
	void print();

	void proc();
};

Filozof::Filozof(sc_module_name name, sc_mutex* m1, sc_mutex* m2) : sc_module(name),fork_left(m1),fork_right(m2)
{
	st = thinking;
	SC_THREAD(print);
	
	SC_THREAD(proc);
		//sensitive<<s0;
	srand(time(NULL));
}

void Filozof::print()
{
	while(1)
	{
		switch(st)
		{
		case thinking:
			cout<< sc_time_stamp() << ": " << name() << " is thinking." <<endl;
			break;
		case left_fork:
			cout<<sc_time_stamp() << ": " << name() << " is taking the left fork." <<endl;
			break;
		case right_fork:
			cout<< sc_time_stamp() << ": " << name() << " is taking the right fork." <<endl;
			break;
		case eating:
			cout<< sc_time_stamp() << ": " << name() << " is eating." <<endl;
			break;
		default:
			assert(false);
		}

		wait(1, SC_SEC);
		//s0->notify();
	}
}

unsigned int Filozof::has_one_fork()
{
	if (st == left_fork || st == right_fork)
		return 1;
	else
		return 0;
}

void Filozof::proc()
{
	//while(1)
	//{

		switch(st)
		{
			case thinking: wait(5, SC_SEC);
					//srand(time(NULL));
					if(rand()%2 == 1)
					{
						if(fork_left->trylock() != -1)
						{
							st = left_fork;
							
						}
							
					}
					else
					{
						if(fork_right->trylock() != -1)
							st = right_fork;
					}
					break;
			case left_fork: if(fork_right->trylock() != -1)
							st = eating;
					else
						st = left_fork;
					break;
			case right_fork: if(fork_left->trylock() != -1)
						st = eating;
					 else
					 	st = right_fork;
					 break;
			case eating: wait(10, SC_SEC);
				     fork_left->unlock();
				     fork_right->unlock();
				     st = thinking;
				     break;
			default: assert(false);
		}
	//}
}

int sc_main(int argc, char* argv[])
{
	srand(time(NULL));
	
	sc_mutex mtx1, mtx2, mtx3, mtx4, mtx5;
	Filozof fica("fica", &mtx1, &mtx2);
	Filozof kica("kica", &mtx2, &mtx3);
	Filozof mica("mica", &mtx3, &mtx4);
	Filozof tica("tica", &mtx4, &mtx5);
	Filozof dica("dica", &mtx5, &mtx1);
	
	

	sc_start(100, SC_SEC);
	
	if(fica.has_one_fork() == 1 && kica.has_one_fork() == 1 && mica.has_one_fork() == 1 && tica.has_one_fork() == 1 && dica.has_one_fork() == 1)
	{
		cout<<"Everybody have only one fork"<<endl;
		return 0;
	}

    return 0;
}
