#include <iostream> 
#include <vector>
#include <iterator>
#include <algorithm>
 
int main()
{
    std::vector<int> vec(10);
    
    for (int i = 0; i < 10; i++)
    	std::cin >> vec[i];
     
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, "\n" ) ) ;
 
    return 0;
}
