#include <iostream>

int main() {
	struct student {
		char firstname[20];
		char lastname[30];
		int  id;
	};
	
	struct student gr[3];
	
	for (int i = 0; i < 3; i++) {
		std::cin >> gr[i].firstname;
		std::cin >> gr[i].lastname;
		std::cin >> gr[i].id;
	}
	
	return 0;
}
