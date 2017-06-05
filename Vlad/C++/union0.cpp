int main() {
	typedef struct {
		int id;
		union {
			struct {char name[50];};
			struct {char lesson[50];};
			struct {int paper;};
		};
	}employer;
	
	employer student[3];
	employer lector[2];
	employer admin[1];
	
	for (int i = 0; i < 3; i++) {
		std::cin >> student[i].id; 
		std::cin >> student[i].name;
	}
	
	for (int i = 0; i < 2; i++) {
		std::cin >> lector[i].id;
		std::cin >> lector[i].name;
		std::cin >> lector[i].lesson;
	}
	
		std::cin >> admin[0].id;
		std::cin >> admin[0].name;
		std::cin >> admin[0].paper;
}
