#include <iostream>
#include <vector>
#include <map>

using namespace std;

void out(const vector <string> & xo) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << xo[i][j];
		cout << endl;
	}
}

//0 - draw, 1 - x wins, 2 - o wins
int checkwins(const vector <string> & xo) {
	bool was = false;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (xo[i][j] == '_')
				was = true;
	if (!was)
		return -1;
	for (int i = 0; i < 3; i++) {
		int o = 0, x = 0;
		for (int j = 0; j < 3; j++)
			if (xo[i][j] == 'x')
				x++;
			else if (xo[i][j] == 'o')
				o++;
		if (x == 3)
			return 1;
		if (o == 3)
			return 2;
	}
	for (int i = 0; i < 3; i++) {
		int o = 0, x = 0;
		for (int j = 0; j < 3; j++)
			if (xo[j][i] == 'x')
				x++;
			else if (xo[j][i] == 'o')
				o++;
		if (x == 3)
			return 1;
		if (o == 3)
			return 2;
	}
	int o = 0, x = 0;
	for (int i = 0; i < 3; i++)
		if (xo[i][i] == 'x')
			x++;
		else if (xo[i][i] == 'o')
			o++;
	if (x == 3)
		return 1;
	if (o == 3)
		return 2;
	o = 0; x = 0;
	for (int i = 0; i < 3; i++)
		if (xo[i][2-i] == 'x')
			x++;
		else if (xo[i][2 - i] == 'o')
			o++;
	if (x == 3)
		return 1;
	if (o == 3)
		return 2;
	return 0;
}

void compGoes(vector <string> & xo, char c) {
	bool was = false;
	for (int i = 0; i < 3 && !was; i++)
		for (int j = 0; j < 3 && !was; j++)
			if (xo[i][j] == '_') {
				xo[i][j] = c;
				was = true;
			}
}
void userGoes(vector <string> & xo, char c) {
	while (true) {
		int i, j; cin >> i >> j; i--; j--;
		if (i < 0 || j < 0 || i >= 3 || j >= 3 || xo[i][j] != '_') {
			cout << "Incorrect input";
			continue;
		}
		xo[i][j] = c;
		break;
	}
}

int main() {
	vector <string> xo(3, "___");
	cout << "1 - computer goes, 2 - player goes\n";
	char c = 'x';
	int k; cin >> k;
	while (true) {
		if (k % 2)
			compGoes(xo, c);
		else {
			out(xo);
			cout << "Your move:";
			userGoes(xo, c);
		}
		if (c == 'x')
			c = 'o';
		else
			c = 'x';
		int t = checkwins(xo);
		if (t == -1)
			cout << "draw\n";
		else if (t == 1)
			cout << "x win\n";
		else if (t == 2)
			cout << "o win\n";
		if (t != 0)
			break;
		k++;
	}
	out(xo);
	getchar();
}