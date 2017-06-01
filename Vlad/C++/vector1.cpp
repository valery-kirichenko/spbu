#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec(11);
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = i;
		std::cout << vec[i] << ' ';
	} 
}
