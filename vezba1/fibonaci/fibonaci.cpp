#define SC_INCLUDE_FX
#include<systemc>
#include<iostream>
#include<vector>
#include <cmath>



typedef sc_dt::sc_ufix_fast numm;
typedef sc_dt::sc_int<64> n;
typedef std::vector<long int> arr;
typedef std::vector<numm> ar;
typedef sc_dt::sc_ufix_fast fixx;

using namespace std;

int  fib(int n)
{
	arr a;
	a.push_back(0);
	a.push_back(1);
	if(n<64)
	{
		if(n == 0)
			return 0;
		if(n == 1)
			return 1;
	
		int i;
		for(i = 2; i <= n; i++)
		{
			a.push_back(a[i-1]+a[i-2]);
		}
		return a[i-2];
	}
	else
	{
		cout<<"ulaz je veci od 64"<<endl;
		return 0;
	}
}
/*
bool passCheck(const arr& gold, const ar& sys,
			   double delta)
{
	for (size_t i = 0; i != sys.size(); ++i)
	{
		/*cout<<"gold"<<gold[i]<<endl;
		cout<<"sys"<<sys[i]<<endl;
		cout<<"greska"<<std::abs(gold[i] - sys[i])<<endl;*/
		/*if (std::abs(gold[i] - sys[i]) > delta)
			return false;
	}
	return true;
}
*/
int bits(int br)
{
	int bit = 1;
	bool p;
	/*
	double delta = 0.5;
	bool p=false;
	arr a;
	a.clear();
	a.push_back(0);
	a.push_back(1);*/
	//std::vector<sc_dt::sc_int<s>> m;

	do
	{
		numm b(bit, bit);
		b = br;
		bit++;
		p = b.overflow_flag();
	}while(p);
	
	return bit-1;
}
int sc_main(int argc, char* argv[])
{
	int n;
	int bit=1;
	
	cout<<"Unesite koji clan fibonacijevog niza zelite:"<<endl;
	cin >> n;
	cout<<"Odgovor:"<< fib(n)<<endl;
	/*do
	{
		bit++;
	}while(!bits(n, bit));*/
	
	cout<<"Najmanji broj bita za predstavljanje bez greske je "<<bits(fib(n))<<endl;
	return 0;
}
