#define SC_INCLUDE_FX
#include <iostream>
#include <iostream>
#include <cmath>
#include <vector>
#include <systemc>
 
typedef std::vector<double> array;
typedef sc_dt::sc_fix_fast fixp;
 
int factoriel(int num)
{
    int temp = 1;
 
    for(int i = 1; i <= num; ++i)
        temp *= i;
     
    return temp;
}

int floating_point_num(double &true_values,double &x)
{
    int i, counter;
    double d;
    double taylor = 0;
    counter = 0;
   
    do
    {
   
        for(i = 0; i <= counter; ++i)
                taylor += (pow(-1, i)*pow(x, 2*i + 1))/(factoriel(2*i + 1));
                
        std::cout<<taylor<<std::endl;
        d = std::abs(true_values-taylor);

        counter++;
        
        taylor = 0;
   
          
    } while(d > 1e-5);
    
    return counter-1;
}
 
void fix_point_bits(double &true_values, double &x, int &W, int &I)
{
	double taylor = 0;
	int counter = floating_point_num(true_values, x);
	int i;
	double d;
	
	for(i = 0; i <= counter; ++i)
                taylor += (pow(-1, i)*pow(x, 2*i + 1))/(factoriel(2*i + 1));
	//std::cout<<taylor<<"t"<<std::endl;

	do
	{
		
		
		for(I = 0; I<=W; I++)
		{
			fixp fix_point(W, I);
			fix_point = taylor;
		
			d = std::abs(true_values-fix_point);
			
			if(std::abs(fix_point - true_values) < 1e-5)
			{
				return;
			}
		}
		
		W++;
	}while(d > 1e-5);
	
	return;
	
	
	
   
}
 
int sc_main(int argc, char* arvg[])
{

    array true_values = {sin(M_PI/6), sin(M_PI/4), sin(M_PI/3), sin(M_PI/2), sin(M_PI)};
    array arguments = {M_PI/6, M_PI/4, M_PI/3, M_PI/2, M_PI};     

   int a;
   std::cout<<"Which member do you want for x"<<std::endl;
   std::cout<<"array arguments = {M_PI/6, M_PI/4, M_PI/3, M_PI/2, M_PI}"<<std::endl;
   std::cin>>a;
   
   double true_value = true_values[a];
   std::cout<<true_value<<std::endl;
   double x = arguments[a];
 
    int W = 1; 
    int I = 0; 
 
    int fl = floating_point_num(true_value,x);
    fix_point_bits(true_value, x, W, I);
    
 
    std::cout<<"Number of members of taylor expansion: "<< fl<<std::endl;
    std::cout<<"Number of bits in whole part: "<< I<<std::endl;
    std::cout<<"Number of decimals: "<< W-I<<std::endl;
   
    return 0;
 
}
