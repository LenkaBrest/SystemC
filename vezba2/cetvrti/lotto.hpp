#ifndef LOTTO_HPP
#define LOTTO_HPP
 
#include <systemc>
#include <vector>
 
typedef std::vector<int> array;
 
SC_MODULE(lotto)
{
public:
	SC_HAS_PROCESS(lotto);
   
	lotto(sc_core::sc_module_name name);
   
	void lotto_proc();
    	void first_player();
    	void second_player();
    	void third_player();
    	void winner();
protected:
    	array lotto_comb;
    	array p1_comb;
    	array p2_comb;
    	array p3_comb;
	array hit_numbers1;
	array hit_numbers2;
	array hit_numbers3;
    	int player1;
    	int player2;
    	int player3;
};
 
#endif
