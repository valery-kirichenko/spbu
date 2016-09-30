#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec(6);
	// or     vec.reserve(10);
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << ' ';
	} 
}