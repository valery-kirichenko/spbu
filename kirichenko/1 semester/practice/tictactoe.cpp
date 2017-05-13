#include <iostream>

char ttt[3][3] = {
	{'_', '_', '_'},
	{'_', '_', '_'},
	{'_', '_', '_'}
};

struct move {
	int x;
	int y;
};

int char_to_player(char c) {
	if (c == 'x') return 1;
	else if (c == 'o') return 2;
	else return 0;
}

int check_win() {
	// main diag
	if (ttt[0][0] == ttt[1][1] && ttt[2][2] == ttt[1][1] && ttt[1][1] != '_') return char_to_player(ttt[1][1]);

	// sec diag
	if (ttt[0][2] == ttt[1][1] && ttt[2][0] == ttt[1][1] && ttt[1][1] != '_') return char_to_player(ttt[1][1]);

	// vertical
	for (int i = 0; i < 3; i++) {
		char c = ttt[0][i];
		bool similar = true;
		for (int j = 1; j < 3; j++) {
			if (ttt[j][i] != c) similar = false;
		}
		if (similar) return char_to_player(c);
	}

	// horizontal
	for (int i = 0; i < 3; i++) {
		char c = ttt[i][0];
		bool similar = true;
		for (int j = 1; j < 3; j++) {
			if (ttt[i][j] != c) similar = false;
		}
		if (similar) return char_to_player(c);
	}

	return 0;
}

move computer_move() {
	move comp;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (ttt[i][j] == '_') {
				ttt[i][j] = 'o';
				comp.x = j;
				comp.y = i;
				return comp;
			}
		}
	}
	comp.x = -1;
	return comp;
}

void print_field() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << ttt[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	bool playerTurn = true;
	int x, y;
	move comp;
	while (!check_win()) {
		print_field();
		if (playerTurn) {
			std::cout << "Ваш ход. Введите координаты хода (x, y): ";
			std::cin >> x >> y;
			if (x < 1 || x > 3 || y < 1 || y > 3 || ttt[y - 1][x - 1] != '_')
				std::cout << "Неверные координаты хода" << std::endl;
			else {
				ttt[y - 1][x - 1] = 'x';
				playerTurn = false;
			}
		} else {
			comp = computer_move();
			if (comp.x == -1) {
				std::cout << "\n~~~ Ничья ~~~\n";
				break;
			}
			std::cout << "\nКомпьютер сходил по координатам (" << comp.x + 1 << ", " << comp.y + 1 << ")" << "\n" << std::endl;
			playerTurn = true;

		}
	}
	int won = check_win();
	print_field();
	if (won == 1) std::cout << "\n~~~ Вы победили! ~~~\n";
	else if (won == 2) std::cout << "\n~~~ Победил компьютер ~~~\n";
	else std::cout << "\n~~~ Ничья ~~~\n";
	return 0;
}