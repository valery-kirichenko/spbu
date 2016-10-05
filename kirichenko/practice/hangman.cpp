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

int sym_to_pos(int sym, std::string word, int indices[]) {
	int sum = 0;
	for (int i = 0; i < sym; i++)
		sum += indices[i];
	return sum;
}

void game(std::string word) {
	int attempt = 0;
	int letter_count = word.length() / 2;
	std::string mod_word = word.substr(0, 2);
	for (int i = 1; i < letter_count - 1; i++)
		mod_word += "_";
	mod_word += word.substr(letter_count*2 - 2, 2);
	std::string guess, letter;
	bool exist;

	int mod_ind[letter_count];
	for (int i = 0; i < letter_count; i++) {
		mod_ind[i] = 1;
	}
	mod_ind[0] = 2;
	mod_ind[letter_count - 1] = 2;
	int ind[letter_count];
	for (int i = 0; i < letter_count; i++)
		ind[i] = 2;
	int guessed_letters = 2;
	std::vector<std::string> letters;
	while (attempt < 6) {
		std::cout << steps[attempt];
		std::cout << "Слово: " << mod_word << std::endl;
		std::cout << "Введите букву: ";
		std::cin >> guess;

		exist = false;

		for (int i = 1; i < letter_count - 1; i++) {
			letter = word.substr(sym_to_pos(i, word, ind), 2);
			if (letter == guess) {
				exist = true;
				mod_word.replace(sym_to_pos(i, mod_word, mod_ind), mod_ind[i], guess);
				mod_ind[i] = 2;
				guessed_letters++;
				letters.push_back(guess);
			}
		}

		if (guessed_letters == letter_count)
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
        ++word_count;
	dict.clear();
	dict.seekg(0, std::ios::beg);
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(0, word_count);
	int rand = distribution(generator);
	for (int i = 0; i < rand; i++)
		std::getline(dict, word);
	dict.close();
	game(word);
}

void play_friend() {
	std::string word;
	std::cout << "Загадайте слово:\n";
	std::cin >> word;
	std::cout << "\033[2F\033[K";
	game(word);
}

int main() {
	//std::cout << "123456";
	//std::cout << "\033[4D\033[K" << std::endl;
	int action;
	bool work = true;
	std::cout << "Добро пожаловать в Виселицу!\n";
	while (work) {
		std::cout << "Выберите режим игры:\n1. С компьютером\n2. С другом\n3. Выход\n";
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