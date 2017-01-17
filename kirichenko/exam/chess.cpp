#include <iostream>
#include <cstdlib>
#include <string>

int board[8][8]; // Figures board
int pboard[8][8]; // Players board
enum {
	// 0    1     2      3      4      5       6
	PAWN, KING, QUEEN, ROOK, BISHOP, KNIGHT, EMPTY, BLACK, WHITE
};

std::string figures[] = {"♙", "♔", "♕", "♖", "♗", "♘", " ", "♟", "♚", "♛", "♜", "♝", "♞"};

/*
0 | 3 5 4 2 1 4 5 3       8 | ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙
1 | 0 0 0 0 0 0 0 0       7 | ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖
2 | 6 6 6 6 6 6 6 6       6 | . . . . . . . .
3 | 6 6 6 6 6 6 6 6       5 | . . . . . . . .
4 | 6 6 6 6 6 6 6 6       4 | . . . . . . . .
5 | 6 6 6 6 6 6 6 6       3 | . . . . . . . .
6 | 0 0 0 0 0 0 0 0       2 | ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜
7 | 3 5 4 2 1 4 5 3       1 | ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟
   ----------------          ----------------
    0 1 2 3 4 5 6 7           a b c d e f g h
*/

int LetterToCoord(char c) {
	return (c - 97);
}

bool CheckMove(int x1, int y1, int x2, int y2, int player) {
	if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 > 7 || x2 > 7 || y1 > 7 ||
		y2 > 7 || (x1 == x2 && y1 == y2) || (pboard[y1][x1] != player)) {
		return false;
	}

	switch (board[y1][x1]) {
		case PAWN:
			if (x1 == x2 && board[y2][x2] == EMPTY) { // Move forward
				if (player == WHITE) { // White
					if ((y1 - y2) == 1) return true;
					if ((y1 - y2) == 2 && y1 == 6 && board[5][x1] == EMPTY) return true;
					return false;
				} else { // Black
					if ((y2 - y1) == 1) return true;
					if ((y2 - y1) == 2 && y1 == 1 && board[2][x1] == EMPTY) return true; 
					return false;
				}
			} else if (std::abs(x1 - x2) == 1 && std::abs(y1 - y2) == 1 && board[y2][x2] != EMPTY) { // Attack
				if (player == WHITE) {
					if (y2 < y1 && pboard[y2][x2] == BLACK) return true;
					return false;
				} else {
					if (y2 > y1 && pboard[y2][x2] == WHITE) return true;
					return false;
				}
			} else {
				return false;
			}
			break;
		case ROOK:
			if (x1 == x2) { // Vertical move
				if (y2 > y1) { // Goes down
					for (int i = y1 + 1; i < y2; i++) {
						if (board[i][x1] != EMPTY) return false;
					}
					return true;
				} else { // Goes up
					for (int i = y1 - 1; i > y2; i--) {
						if (board[i][x1] != EMPTY) return false;
					}
					return true;
				}
			} else if (y1 == y2) { // Horizontal move
				if (x2 > x1) { // Goes right
					for (int i = x1 + 1; i < x2; i++) {
						if (board[y1][i] != EMPTY) return false;
					}
					return true;
				} else {
					for (int i = x1 - 1; i > x2; i--) { // Goes left
						if (board[y1][i] != EMPTY) return false;
					}
					return true;
				}
			} else {
				return false;
			}
			break;
		case KNIGHT:
			if ((std::abs(x1 - x2) == 2 && std::abs(y1 - y2) == 1) || (std::abs(x1 - x2) == 1 && std::abs(y1 - y2) == 2)) {
				return true;
			}
			return false;
			break;
		case BISHOP:
			if (std::abs(y2 - y1) != std::abs(x2 - x1)) return false;
			if (y2 > y1 && x2 > x1) { // Down right
				int i = y1 + 1, j = x1 + 1;
				while (i < y2 && j < x2) {
					if (board[i][j] != EMPTY) return false;
					i++; j++;
				}
			} else if (y2 > y1 && x2 < x1) { // Down left
				int i = y1 + 1, j = x1 - 1;
				while (i < y2 && j > x2) {
					if (board[i][j] != EMPTY) return false;
					i++; j--;
				}
			} else if (y2 < y1 && x2 < x1) { // Up left
				int i = y1 - 1, j = x1 - 1;
				while (i > y2 && j > x2) {
					if (board[i][j] != EMPTY) return false;
					i--; j--;
				}
			} else if (y2 < y1 && x2 > x1) { // Up right
				int i = y1 - 1, j = x1 + 1;
				while (i > y2 && j < x2) {
					if (board[i][j] != EMPTY) return false;
					i--; j++;
				}
			}
			return true;
			break;
		case KING:
			if ((x1 == x2 && std::abs(y1 - y2) == 1) || (y1 == y2 && std::abs(x1 - x2) == 1) ||
				(std::abs(x1 - x2) == 1 && std::abs(y1 - y2) == 1)) return true;
			return false;
			break;
		case QUEEN:
			if (x1 == x2) { // Vertical move
				if (y2 > y1) { // Goes down
					for (int i = y1 + 1; i < y2; i++) {
						if (board[i][x1] != EMPTY) return false;
					}
					return true;
				} else { // Goes up
					for (int i = y1 - 1; i > y2; i--) {
						if (board[i][x1] != EMPTY) return false;
					}
					return true;
				}
			} else if (y1 == y2) { // Horizontal move
				if (x2 > x1) { // Goes right
					for (int i = x1 + 1; i < x2; i++) {
						if (board[y1][i] != EMPTY) return false;
					}
					return true;
				} else {
					for (int i = x1 - 1; i > x2; i--) { // Goes left
						if (board[y1][i] != EMPTY) return false;
					}
					return true;
				}
			} else {
				if (std::abs(y2 - y1) != std::abs(x2 - x1)) return false;
				if (y2 > y1 && x2 > x1) { // Down right
					int i = y1 + 1, j = x1 + 1;
					while (i < y2 && j < x2) {
						if (board[i][j] != EMPTY) return false;
						i++; j++;
					}
				} else if (y2 > y1 && x2 < x1) { // Down left
					int i = y1 + 1, j = x1 - 1;
					while (i < y2 && j > x2) {
						if (board[i][j] != EMPTY) return false;
						i++; j--;
					}
				} else if (y2 < y1 && x2 < x1) { // Up left
					int i = y1 - 1, j = x1 - 1;
					while (i > y2 && j > x2) {
						if (board[i][j] != EMPTY) return false;
						i--; j--;
					}
				} else if (y2 < y1 && x2 > x1) { // Up right
					int i = y1 - 1, j = x1 + 1;
					while (i > y2 && j < x2) {
						if (board[i][j] != EMPTY) return false;
						i--; j++;
					}
				}
				return true;
			}
			break;
	}
	return false;
}

void InitBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i < 2) pboard[i][j] = BLACK;
			else if (i > 5) pboard[i][j] = WHITE;
			else pboard[i][j] = EMPTY;
		}
	}
	for (int i = 0; i < 8; i++) {
		board[1][i] = PAWN;
		board[6][i] = PAWN;
		for (int j = 2; j < 6; j++) board[j][i] = EMPTY;
	}
	board[0][0] = ROOK; board[0][1] = KNIGHT; board[0][2] = BISHOP; board[0][3] = QUEEN; board[0][4] = KING;
	board[0][7] = ROOK; board[0][6] = KNIGHT; board[0][5] = BISHOP;
	board[7][0] = ROOK; board[7][1] = KNIGHT; board[7][2] = BISHOP; board[7][3] = QUEEN; board[7][4] = KING;
	board[7][7] = ROOK; board[7][6] = KNIGHT; board[7][5] = BISHOP;
}

void PrintBoard() {
	for (int i = 0; i < 8; i++) {
		std::cout << std::abs(i - 8) << " | ";
		for (int j = 0; j < 8; j++) {
			std::cout << figures[board[i][j] + ((pboard[i][j] == WHITE) ? 7 : 0)] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "    ---------------" << std::endl;
	std::cout << "    a b c d e f g h" << std::endl;
}

int main() {
	InitBoard();

	int player = WHITE;
	char c;
	int x1, y1, x2, y2;
	
	std::string message = "Use coords to move (e.g. \"a2 a4\")";
	while (true) {
		PrintBoard();
		std::cout << message << std::endl;

		if (player == WHITE) std::cout << "White move" << std::endl;
		else if (player == BLACK) std::cout << "Black move" << std::endl;

		std::cin >> c >> y1;
		x1 = LetterToCoord(c);
		y1 = std::abs(y1 - 8);

		std::cin >> c >> y2;
		x2 = LetterToCoord(c);
		y2 = std::abs(y2 - 8);

		std::cout << "\033[13F\033[0J"; // Clear screen 13 rows up

		if (!CheckMove(x1, y1, x2, y2, player)) {
			message = "Incorrect move";
			continue;
		} else {
			message = "";
		}

		// Move figure
		board[y2][x2] = board[y1][x1];
		pboard[y2][x2] = player;
		pboard[y1][x1] = EMPTY;
		board[y1][x1] = EMPTY;

		player = (player == WHITE) ? BLACK : WHITE;
	}

	return 0;
}