#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>

std::string steps[] = {
						"   _______ \n"
						"   |     | \n"
						"   |       \n"
						"   |       \n"
						"   |       \n"
						"   |       \n"
						"   |       \n"
						"¯¯¯¯¯¯¯    \n",
						"   _______ \n"
						"   |     | \n"
						"   |     @ \n"
						"   |       \n"
						"   |       \n"
						"   |       \n"
						"   |       \n"
						"¯¯¯¯¯¯¯    \n",
						"   _______ \n"
						"   |     | \n"
						"   |     @ \n"
						"   |     | \n"
						"   |     | \n"
						"   |       \n"
						"   |       \n"
						"¯¯¯¯¯¯¯    \n",
						"   _______ \n"
						"   |     | \n"
						"   |     @ \n"
						"   |    /| \n"
						"   |     | \n"
						"   |       \n"
						"   |       \n"
						"¯¯¯¯¯¯¯    \n",
						"   _______ \n"
						"   |     | \n"
						"   |     @ \n"
						"   |    /|\\\n"
						"   |     | \n"
						"   |       \n"
						"   |       \n"
						"¯¯¯¯¯¯¯    \n",
						"   _______ \n"
						"   |     | \n"
						"   |     @ \n"
						"   |    /|\\\n"
						"   |     | \n"
						"   |    /  \n"
						"   |       \n"
						"¯¯¯¯¯¯¯    \n",
						"   _______ \n"
						"   |     | \n"
						"   |     @ \n"
						"   |    /|\\\n"
						"   |     | \n"
						"   |    / \\\n"
						"   |       \n"
						"¯¯¯¯¯¯¯    \n"
					};

std::string alphabetL = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
std::string alphabetU = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

std::string to_lower(std::string s) {
	std::string out = "";
	for (int i = 0; i < s.length(); i += 2) {
		int find = alphabetU.find(s.substr(i, 2));
		if (find == std::string::npos) {
			find = alphabetL.find(s.substr(i, 2));
			if (find == std::string::npos) {
				return "false";
			} else {
				out += alphabetL.substr(find, 2);
			}
		} else {
			out += alphabetL.substr(find, 2);
		}
	}
	return out;
}

// Some magic needed to work with cyrillic letters, cause they weight 2 positions
// when _ symbol weight 1 position. We use additional array indices to calculate
// position for needed symbol, given like for normal string (e.g. for string "пр_вет" 
// normal position for letter в is 3, but in C++ we have 5)
int sym_to_pos(int sym, std::string word, int indices[]) {
	int sum = 0;
	for (int i = 0; i < sym; i++)
		sum += indices[i];
	return sum;
}

void game(std::string word) {
	int attempt = 0;
	int letter_count = word.length() / 2; // Division by 2 was explained above
	std::string mod_word = word.substr(0, 2);
	for (int i = 1; i < letter_count - 1; i++)
		mod_word += "_";
	mod_word += word.substr(letter_count*2 - 2, 2); // Take from 2 to penultimate letter
	std::string guess, letter;
	bool exist;

	int mod_ind[letter_count]; // Array for index calculation
	for (int i = 0; i < letter_count; i++) {
		mod_ind[i] = 1; // 1 where the symbol _
	}
	mod_ind[0] = 2; // And 2 where first...
	mod_ind[letter_count - 1] = 2; // ..and last letters
	int ind[letter_count];
	for (int i = 0; i < letter_count; i++)
		ind[i] = 2;
	int guessed_letters = 2;
	// TODO: add logic to letters
	std::vector<std::string> letters;
	while (attempt < 6) {
		std::cout << steps[attempt];
		std::cout << "Слово: " << mod_word << std::endl;
		std::cout << "Введите букву: ";
		std::cin >> guess;

		guess = to_lower(guess);
		if (guess == "false") {
			std::cout << "\033[10F\033[J";
			std::cout << "Введите букву русского алфавита\n";
			continue;
		}

		exist = false;

		for (int i = 1; i < letter_count - 1; i++) {
			letter = word.substr(sym_to_pos(i, word, ind), 2); // Take each letter
			if (letter == guess) { // Compare it with guessed one
				exist = true;
				mod_word.replace(sym_to_pos(i, mod_word, mod_ind), mod_ind[i], guess); // Replace placeholder
				mod_ind[i] = 2; // And modify appropriate index
				guessed_letters++;
				letters.push_back(guess);
			}
		}

		if (guessed_letters == letter_count) // If all letters guessed (player won)
			attempt += 10;
	
		if (!exist)
			attempt++;

		std::cout << "\033[10F\033[J";

	}
	if (attempt == 6) {
		std::cout << steps[attempt];
		std::cout << "Вы проиграли\nЗагаданное слово: " << word << std::endl;
	} else {
		std::cout << steps[attempt - 10];
		std::cout << "Вы победили!\nЗагаданное слово: " << word << std::endl;
	}
}

void play_computer() {
	std::cout << "\nСлово будет выбрано случайным образом из словаря.\n";
	std::ifstream dict("words.txt");
	std::string word, mod_word;
	int word_count = 0;
	while (std::getline(dict, word))
        ++word_count; // Calculate lines in the words file (each line is a word)
	dict.clear();
	dict.seekg(0, std::ios::beg); // Return to the beggining of the file
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(0, word_count);
	int rand = distribution(generator); // Select random word
	for (int i = 0; i < rand; i++)
		std::getline(dict, word);
	dict.close();
	game(word);
}

void play_friend() {
	std::string word;
	std::cout << "Загадайте слово:\n";
	std::cin >> word;
	std::cout << "\033[2F\033[K"; // Remove word that was entered by second player
	word = to_lower(word);
	if (word == "false") {
		std::cout << "Слово должно состоять из букв русского алфавита\n";
		play_friend();
	} else {
		if (word.length() < 6) {
			std::cout << "В слове должно быть больше 2 букв\n" << std::endl;
			play_friend();
		} else game(word);
	}
}

int main() {
	int action;
	bool work = true;
	std::cout << "\033[1;34mДобро пожаловать в Виселицу!\033[0m\n";
	while (work) {
		std::cout << "\033[1mВыберите режим игры:\033[0m\n1. С компьютером\n2. С другом\n3. Выход\n";
		std::cin >> action;
		std::cout << "\033[5F\033[J";
		switch (action) {
			case 1:
				play_computer();
				break;
			case 2:
				play_friend();
				break;
			case 3:
				work = false;
				break;
			default:
				std::cout << "Команда не найдена\n";
				break;
		}
	}

	return 0;
}