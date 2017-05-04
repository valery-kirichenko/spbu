#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream infile("input.txt");
	std::ofstream outfile("output.txt");

	std::string line;
	int paragraph = 1, from, to;
	bool newParagraph = true;
	std::cout << "Введите, с какого и по какой параграфы нужно вставить красные строки: ";
	std::cin >> from >> to;
	while(std::getline(infile, line)) {
		if (line.empty()) {
			paragraph++;
			newParagraph = true;
			outfile << "\n";
		} else {
			if (newParagraph) {
				if (paragraph >= from && paragraph <= to) {
					if (line.substr(0, 1) == "\t") outfile << line << "\n";
					else outfile << "\t" << line << "\n";
				}
				else outfile << line << "\n";
				newParagraph = false;
			} else {
				outfile << line << "\n";
			}
		}
		
	}

	infile.close();
	outfile.close();
	return 0;
}