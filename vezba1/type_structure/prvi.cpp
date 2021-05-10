#include <list>
#include <vector>
#include <iostream>

typedef std::vector<int> structure; //umesto vector treba upisati list ako zelimo da bude lista


int main()
{

	structure vec = {7, 5, 1, 3, 12};
	structure::iterator it;
	
	/*std::vector<int> vec = {7, 5, 1, 3, 12};
	std::vector<int>::iterator it;*/
	
	for(it=vec.begin(); it!=vec.end(); ++it )
	std::cout << *it << " ";
	return 0;
}


