#include <iostream> 
#include <vector>
#include <iterator>
#include <algorithm>
 
int main() {
    std::vector<int> vec1(10), vec2(10);
    
    for (int i = 0; i < 10; i++)
    	std::cin >> vec1[i];

    for (int i = 0; i < 10; i++) {
    	std::cin >> vec2[i];
    	vec1[i] *= vec2[i];
    }
    
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, "\n"));
 
    return 0;
}
