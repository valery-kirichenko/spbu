#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>

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
int printed = 0;


// Scr = 0 — Menu
// Scr = 1 — Computer game
// Scr = 2 — Player game
// Scr = 3 — End of the game
void screen(int scr, std::string message = "", int img = -1, std::string word = "") {
	// Move cursor to (1; 1) and clear screen
	while (printed > 0) {
		std::cout << "\033[F\033[2K";
		printed--;
	}
	std::cout << "\033[1;34mДобро пожаловать в Виселицу!\033[0m\n";
	printed++;
	if (message != "") {
	 	printed++;
	}
	switch (scr) {
		case 0:
			std::cout << message
					  << "\033[1mВыберите режим игры:\033[0m\n"
					  << "1. С компьютером\n2. С другом\n3. Выход\n";
			printed += 4;
			break;
		case 1:
			std::cout << message
					  << steps[img]
					  << "Слово: " << word << "\n"
					  << "Введите букву: ";
			printed += 9;
			break;
		case 2:
			std::cout << message
					  << "Загадайте слово:\n";
			printed += 2;
			break;
		case 3:
			std::cout << steps[img]
					  << message
					  << "Загаданное слово: " << word << "\n"
					  << "Нажмите enter, чтобы продолжить" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cin.get();
			printed += 11;
			break;
	}


}

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

void game(std::string word, std::string message = "") {
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
	std::vector<std::string> letters;
	while (attempt < 6) {
		screen(1, message, attempt, mod_word);
		message = "";
		std::cin >> guess;
		printed++;
		guess = to_lower(guess);
		if (guess == "false") {
			message = "Введите букву русского алфавита\n";
			continue;
		}

		if (std::find(letters.begin(), letters.end(), guess) != letters.end()) {
			message = "Вы уже вводили эту букву\n";
			continue;
		}

		letters.push_back(guess);

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
	}
	if (attempt == 6) {
		screen(3, "Вы проиграли.\n", attempt, word);
	} else {
		screen(3, "Вы победили!\n", attempt - 10, word);
	}
}

void play_computer() {
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
	game(word, "Слово выбрано случайным образом из словаря.\n");
}

void play_friend(std::string message = "") {
	std::string word;
	screen(2, message);
	std::cin >> word;
<<<<<<< Updated upstream
	std::cout << "\033[2F\033[K"; // Remove word that was entered by second player
=======
>>>>>>> Stashed changes
	word = to_lower(word);
	if (word == "false") {
		message = "Слово должно состоять из букв русского алфавита\n";
		play_friend(message);
	} else {
		if (word.length() < 6) {
			message = "В слове должно быть больше 2 букв\n";
			play_friend(message);
		} else game(word);
	}
}

int main() {
	int action;
	bool work = true;
	std::string message = "";
	while (work) {
		screen(0, message);
		std::cin >> action;
		printed++;
		switch (action) {
			case 1:
				message = "";
				play_computer();
				break;
			case 2:
				message = "";
				play_friend();
				break;
			case 3:
				message = "";
				work = false;
				break;
			default:
				message = "Команда не найдена\n";
				break;
		}
	}

	return 0;
}