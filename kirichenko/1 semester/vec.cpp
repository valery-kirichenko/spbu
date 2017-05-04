#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec(10);

	std::cout << "Vector size: " << vec.size() << std::endl;


	for (int i = 0; i < vec.size(); i++) {
		vec[i] = i;
		std::cout << vec[i] << std::endl;
	}

	std::vector<int> vec2(vec); // Copy vec to vec2

	for (int i = 0; i < vec2.size(); i++) {
		std::cout << vec2[i] << std::endl;
	}

	
	return 0;
}