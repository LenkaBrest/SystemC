#include "lotto.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace sc_core;
using namespace std;

lotto::lotto(sc_core::sc_module_name name) : sc_module(name)
{
	SC_THREAD(lotto_proc);
	SC_THREAD(first_player);
	SC_THREAD(second_player);
	SC_THREAD(third_player);
	SC_THREAD(winner);
}

void lotto::lotto_proc()
{
	
	 while(1)
	{
		lotto_comb.push_back(rand() % 39 + 1);
 
                while(1)
                {
			lotto_comb.push_back(rand() % 39 + 1);
 
                        for(int i = 0; i < lotto_comb.size(); ++i)
                        {
                            if((lotto_comb[i] == lotto_comb[lotto_comb.size() - 1]) && (i != lotto_comb.size() - 1))
                            {
                                lotto_comb.pop_back();
                                break;
                            }
                        }
 
                        if(lotto_comb.size() == 7)
                            break;
                }
 
        sort(lotto_comb.begin(), lotto_comb.end());

	wait(1, SC_SEC);
	
	}
}

void lotto::first_player()
{
	 while(1)
	{
		player1 = rand() % 2;
		if(player1)
		{
		
			p1_comb.push_back(rand() % 39 + 1);
 
                	while(1)
                	{
				p1_comb.push_back(rand() % 39 + 1);
 
                        	for(int i = 0; i < p1_comb.size(); ++i)
                        	{
                            		if((p1_comb[i] == p1_comb[p1_comb.size() - 1]) && (i != p1_comb.size() - 1))
                            		{
                                	p1_comb.pop_back();
                                	break;
                            		}
                        	}
 
                       		if(p1_comb.size() == 7)
                            		break;
               		}
 
        	sort(p1_comb.begin(), p1_comb.end());		
		}
        	

	wait(1, SC_SEC);
	
	}
}

void lotto::second_player()
{
	 while(1)
	{
		player2 = rand() % 2;
		if(player2)
		{
		
			p2_comb.push_back(rand() % 39 + 1);
 
                	while(1)
                	{
				p2_comb.push_back(rand() % 39 + 1);
 
                        	for(int i = 0; i < p2_comb.size(); ++i)
                        	{
                            		if((p2_comb[i] == p2_comb[p2_comb.size() - 1]) && (i != p2_comb.size() - 1))
                            		{
                                	p2_comb.pop_back();
                                	break;
                            		}
                        	}
 
                       		if(p2_comb.size() == 7)
                            		break;
               		}
 
        	sort(p2_comb.begin(), p2_comb.end());		
		}
        	

	wait(1, SC_SEC);
	
	}
}

void lotto::third_player()
{
	 while(1)
	{
		player3 = rand() % 2;
		if(player3)
		{
		
			p3_comb.push_back(rand() % 39 + 1);
 
                	while(1)
                	{
				p3_comb.push_back(rand() % 39 + 1);
 
                        	for(int i = 0; i < p3_comb.size(); ++i)
                        	{
                            		if((p3_comb[i] == p3_comb[p3_comb.size() - 1]) && (i != p3_comb.size() - 1))
                            		{
                                	p3_comb.pop_back();
                                	break;
                            		}
                        	}
 
                       		if(p3_comb.size() == 7)
                            		break;
               		}
 
        	sort(p3_comb.begin(), p3_comb.end());		
		}
        	

	wait(1, SC_SEC);
	
	}
}

void lotto::winner()
{
	int n = 0;
	
	wait(100, SC_MS);
	
	while(1)
	{
		cout<<"Round "<<++n<<endl;

		cout<<"-------"<<endl;
	
		if(player1)
		{
			cout<<"Player1 combination: ";
			
			for(int i = 0; i < 7; ++i)
            			cout<<p1_comb[i]<<" ";
        		cout<<endl;
			
			for(int i = 0; i < 7; ++i)
				for(int j = 0; j < 7; ++j)
					if(p1_comb[i] == lotto_comb[j])
					{
						hit_numbers1.push_back(p1_comb[i]);
						break;
					}
		}
		else
		{
			cout<<"Player1 doesn't play this round.\n";
		}

		if(player2)
		{
			cout<<"Player2 combination: ";
			for(int i = 0; i < 7; ++i)
            			cout<<p2_comb[i]<<" ";
        		cout<<endl;

			for(int i = 0; i < 7; ++i)
				for(int j = 0; j < 7; ++j)
					if(p2_comb[i] == lotto_comb[j])
					{
						hit_numbers2.push_back(p2_comb[i]);
						break;
					}
		}
		else
		{
			cout<<"Player2 doesn't play this round.\n";
		}
		if(player3)
		{
			cout<<"Player3 combination: ";
			for(int i = 0; i < 7; ++i)
            			cout<<p3_comb[i]<<" ";
        		cout<<endl;

			for(int i = 0; i < 7; ++i)
				for(int j = 0; j < 7; ++j)
					if(p3_comb[i] == lotto_comb[j])
					{
						hit_numbers3.push_back(p3_comb[i]);
						break;
					}
		}
		else
		{
			cout<<"Player3 doesn't play this round.\n";
		}

		cout<<"Lotto combination: ";

		for(int i = 0; i < 7; ++i)
            		cout<<lotto_comb[i]<<" ";
       		cout<<endl;

		if(player1)
		{
			if(!hit_numbers1.size())
			{
				cout<<"Player1 doesn't have hits"<<endl;
			}
			else
			{
			cout<<"Player1 hit: ";
			for(int i = 0; i < hit_numbers1.size() ; ++i)
            			cout<<hit_numbers1[i]<<" ";
        		cout<<endl;
			}
		}
		if(player2)
		{
			if(!hit_numbers2.size())
			{
				cout<<"Player2 doesn't have hits"<<endl;
			}
			else
			{
			cout<<"Player2 hit: ";
			for(int i = 0; i < hit_numbers2.size() ; ++i)
            			cout<<hit_numbers2[i]<<" ";
        		cout<<endl;
			}
		}
		if(player3)
		{
			if(!hit_numbers3.size())
			{
				cout<<"Player3 doesn't have hits"<<endl;
			}
			else
			{
			cout<<"Player3 hit: ";
			for(int i = 0; i < hit_numbers3.size() ; ++i)
            			cout<<hit_numbers3[i]<<" ";
        		cout<<endl;
			}
		}
		
		cout<<endl;
		
		if(!hit_numbers3.size() && !hit_numbers2.size() && !hit_numbers1.size())
		{
			cout<<"There is no winners"<<endl;
		}
		else if((hit_numbers1.size() > hit_numbers2.size()) && (hit_numbers1.size() > hit_numbers3.size()))
		{
			cout<<"Player1 is winner with "<<hit_numbers1.size()<<" hits"<<endl;
		}
		else if((hit_numbers2.size() > hit_numbers1.size()) && (hit_numbers2.size() > hit_numbers3.size()))
		{
			cout<<"Player2 is winner with "<<hit_numbers2.size()<<" hits"<<endl;
		}
		else if((hit_numbers3.size() > hit_numbers2.size()) && (hit_numbers3.size() > hit_numbers1.size()))
		{
			cout<<"Player3 is winner with "<<hit_numbers3.size()<<" hits"<<endl;
		}
		else if((hit_numbers3.size() == hit_numbers2.size()) && (hit_numbers3.size() > hit_numbers1.size()))
		{
			cout<<"There are two players (Player2 and Player3) with "<<hit_numbers3.size()<<" hits"<<endl;
		}
		else if((hit_numbers3.size() == hit_numbers1.size()) && (hit_numbers3.size() > hit_numbers2.size()))
		{
			cout<<"There are two players (Player1 and Player3) with "<<hit_numbers3.size()<<" hits"<<endl;
		}
		else if((hit_numbers1.size() == hit_numbers2.size()) && (hit_numbers1.size() > hit_numbers3.size()))
		{
			cout<<"There are two players (Player1 and Player2) with "<<hit_numbers1.size()<<" hits"<<endl;
		}	
		else
			cout<<"There are three players with "<<hit_numbers1.size()<<" hits"<<endl;

		hit_numbers1.clear();
		hit_numbers2.clear();
		hit_numbers3.clear();
		p1_comb.clear();
		p2_comb.clear();
		p3_comb.clear();
		lotto_comb.clear();

		cout<<"-------"<<endl;

		wait(1, SC_SEC);
	}
}


