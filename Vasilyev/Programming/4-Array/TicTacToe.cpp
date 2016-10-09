#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const int nc = 3;
char c[nc][nc];
int lip = 0, ljp = 0, lxp = 0, ldp = 0, liu = 0, lju = 0, lxu = 0, ldu = 0, nx = 0, nd = 0, px = 0, pd = 0;
int ni[nc], nj[nc], pi[nc], pj[nc];

int chEnd();

char pcFunc()
{
	chEnd();
	cout << "Computer step...\n";

	//pcwin
	if (px == 1) {
		if (c[0][0] == ' ') {
			c[0][0] = '0';
			return 0;
		}
		else if (c[1][1] == ' ') {
			c[1][1] = '0';
			return 0;
		}
		else if (c[2][2] == ' ') {
			c[2][2] = '0';
			return 0;
		}
	}

	if (pd == 1) {
		if (c[0][2] == ' ') {
			c[0][2] = '0';
			return 0;
		}
		else if (c[1][1] == ' ') {
			c[1][1] = '0';
			return 0;
		}
		else if (c[2][0] == ' ') {
			c[2][0] = '0';
			return 0;
		}
	}

	if (pi[0] == 2) {
		if (c[0][0] == ' ') {
			c[0][0] = '0';
			return 0;
		}
		else if (c[0][1] == ' ') {
			c[0][1] = '0';
			return 0;
		}
		else if (c[0][2] == ' ') {
			c[0][2] = '0';
			return 0;
		}
	}
	if (pi[1] == 2) {
		if (c[1][0] == ' ') {
			c[1][0] = '0';
			return 0;
		}
		else if (c[1][1] == ' ') {
			c[1][1] = '0';
			return 0;
		}
		else if (c[1][2] == ' ') {
			c[1][2] = '0';
			return 0;
		}
	}
	if (pi[2] == 2) {
		if (c[2][0] == ' ') {
			c[2][0] = '0';
			return 0;
		}
		else if (c[2][1] == ' ') {
			c[2][1] = '0';
			return 0;
		}
		else if (c[2][2] == ' ') {
			c[2][2] = '0';
			return 0;
		}
	}

	if (pj[0] == 2) {
		if (c[0][0] == ' ') {
			c[0][0] = '0';
			return 0;
		}
		else if (c[1][0] == ' ') {
			c[1][0] = '0';
			return 0;
		}
		else if (c[2][0] == ' ') {
			c[2][0] = '0';
			return 0;
		}
	}
	if (pj[1] == 2) {
		if (c[0][1] == ' ') {
			c[0][1] = '0';
			return 0;
		}
		else if (c[1][1] == ' ') {
			c[1][1] = '0';
			return 0;
		}
		else if (c[2][1] == ' ') {
			c[2][1] = '0';
			return 0;
		}
	}
	if (pj[2] == 2) {
		if (c[0][2] == ' ') {
			c[0][2] = '0';
			return 0;
		}
		else if (c[1][2] == ' ') {
			c[1][2] = '0';
			return 0;
		}
		else if (c[2][2] == ' ') {
			c[2][2] = '0';
			return 0;
		}
	}
	
	//antiwin
	if (nx == 1) {
		if (c[0][0] == ' ') {
			c[0][0] = '0';
			return 0;
		}
		else if (c[1][1] == ' ') {
			c[1][1] = '0';
			return 0;
		}
		else if (c[2][2] == ' ') {
			c[2][2] = '0';
			return 0;
		}
	}

	if (nd == 1) {
		if (c[0][2] == ' ') {
			c[0][2] = '0';
			return 0;
		}	
		else if (c[1][1] == ' ') {
			c[1][1] = '0';
			return 0;
		}
		else if (c[2][0] == ' ') {
			c[2][0] = '0';
			return 0;
		}
	}

	if (ni[0] == 2) {
		if (c[0][0] == ' ') {
			c[0][0] = '0';
			return 0;
		}
		else if (c[0][1] == ' ') {
			c[0][1] = '0';
			return 0;
		}
		else if (c[0][2] == ' ') {
			c[0][2] = '0';
			return 0;
		}
	}
	if (ni[1] == 2) {
		if (c[1][0] == ' ') {
			c[1][0] = '0';
			return 0;
		}
		else if (c[1][1] == ' ') {
			c[1][1] = '0';
			return 0;
		}
		else if (c[1][2] == ' ') {
			c[1][2] = '0';
			return 0;
		}
	}
	if (ni[2] == 2) {
		if (c[2][0] == ' ') {
			c[2][0] = '0';
			return 0;
		}
		else if (c[2][1] == ' ') {
			c[2][1] = '0';
			return 0;
		}
		else if (c[2][2] == ' ') {
			c[2][2] = '0';
			return 0;
		}
	}

	if (nj[0] == 2) {
		if (c[0][0] == ' ') {
			c[0][0] = '0';
			return 0;
		}
		else if (c[1][0] == ' ') {
			c[1][0] = '0';
			return 0;
		}
		else if (c[2][0] == ' ') {
			c[2][0] = '0';
			return 0;
		}
	}
	if (nj[1] == 2) {
		if (c[0][1] == ' ') {
			c[0][1] = '0';
			return 0;
		}
		else if (c[1][1] == ' ') {
			c[1][1] = '0';
			return 0;
		}
		else if (c[2][1] == ' ') {
			c[2][1] = '0';
			return 0;
		}
	}
	if (nj[2] == 2) {
		if (c[0][2] == ' ') {
			c[0][2] = '0';
			return 0;
		}
		else if (c[1][2] == ' ') {
			c[1][2] = '0';
			return 0;
		}
		else if (c[2][2] == ' ') {
			c[2][2] = '0';
			return 0;
		}
	}

	//other field
	if (c[2][2] == ' ') {
		c[2][2] = '0';
		return 0;
	}

	if ((c[2][2] == '0') & (c[1][1] == 'X')) {
		if (c[0][0] == ' ') {
			c[0][0] = '0';
			return 0;
		}
	}

	if (c[0][2] == ' ') {
		c[0][2] = '0';
		return 0;
	}

	if (c[1][1] == ' ') {
		c[1][1] = '0';
		return 0;
	}

	for (int i = 0; i < nc; i++)
		for (int j = 0; j < nc; j++)
			if (c[i][j] == ' ') {
				c[i][j] = '0';
				return 0;
			}
	return 0;
}

char usFunc()
{
	int ic, jc, x, kek = 1;
	string s;
	cout << "Your step (enter index of field - <1, 2, 3>)\n";
st1:
	cout << "Enter index (format: 'x y' ): ";
	cin >> s;
	try {
		x = stoi(s);
		ic = x - 1;
	}
	catch (...) {
		cout << "You enter not integer.\n";
		goto st3;
	}
	if ((ic < 0) | (ic > 2)) {
		cout << "You enter incorrect index.\n";
		goto st3;
	}
	cin >> s;
	try {
		x = stoi(s);
		jc = x - 1;
		}
	catch (...) {
		cout << "You enter not integer.\n";
		goto st1;
	}
	if ((jc < 0) | (jc > 2)) {
		cout << "You enter incorrect index.\n";
		goto st1;
	}
	if (c[ic][jc] == ' ') {
		c[ic][jc] = 'X';
	}
	else {
		cout << "You chose incorrect cell.\n";
		goto st1;
	}
	return 0;

st3:
	cin >> s;
	goto st1;

/*st2:
	//cout << endl;
	cout << "Input validation, please, enter '0': ";
	cin >> s1;
	if (s1 == '0')
		goto st1;
	else {
		cout << "You do not enter '0'!\n";
		goto st2;
	}*/
}

int outF()
{
	int k = 0;
	//cout << endl;
	for (int i = 0; i < nc; i++)
	{
		cout << endl;
		for (int j = 0; j < nc; j++)
		{
			if (c[i][j] == ' ')
				cout << " _ ";
			if (c[i][j] == '0') {
				cout << " 0 ";
				k++;
			}
			if (c[i][j] == 'X') {
				cout << " X ";
				k++;
			}
		}
	}
	cout << endl;
	cout << endl;
	if (k == 9) {
		switch (chEnd())
		{
			case 0:
				cout << "Computer WIN!\n";
				system("pause");
				return 1;
				break;
			case 1:
				cout << "You WIN!\n";
				system("pause");
				return 1;
				break;
			default:
				cout << "Game over\n";
				system("pause");
				return 1;
				break;
		}
	}
	else
		return 0;
}

int chEnd()
{
	lip = 0; ljp = 0; lxp = 0; ldp = 0; liu = 0; lju = 0; lxu = 0; ldu = 0; nx = 0; nd = 0; px = 0; pd = 0;
	for (int i = 0; i < nc; i++)
		ni[i] = 0;
	for (int i = 0; i < nc; i++)
		nj[i] = 0;
	for (int i = 0; i < nc; i++)
		pi[i] = 0;
	for (int i = 0; i < nc; i++)
		pj[i] = 0;

	for (int i = 0; i < nc; i++)
	{
		lip = 0; liu = 0;
		for (int j = 0; j < nc; j++)
		{
			if (c[i][j] == '0') {
				lip++;
				pi[i]++;
			}
			if (c[i][j] == 'X') {
				liu++;
				ni[i]++;
			}
		}
		if (lip == 3)
			return 0;
		if (liu == 3)
			return 1;
	}

	for (int i = 0; i < nc; i++)
	{
		ljp = 0; lju = 0;
		for (int j = 0; j < nc; j++)
		{
			if (c[j][i] == '0') {
				ljp++;
				pj[i]++;
			}
			if (c[j][i] == 'X') {
				lju++;
				nj[i]++;
			}
		}
		if (ljp == 3)
			return 0;
		if (lju == 3)
			return 1;
	}

	for (int i = 0; i < nc; i++)
	{
		if (c[i][i] == '0') {
			lxp++;
		}
		if (c[i][i] == 'X') {
			lxu++;
		}
	}
	if (lxu == 2) {
		nx = 1;
	}
	if (lxp == 2) {
		px = 1;
	}
	if (lxp == 3)
		return 0;
	if (lxu == 3)
		return 1;

	for (int i = 0; i < nc; i++)
	{
		if (c[i][nc - i - 1] == '0') {
			ldp++;
		}
		if (c[i][nc - i - 1] == 'X') {
			ldu++;
		}
	}
	if (ldu == 2) {
		nd = 1;
	}
	if (ldp == 2) {
		pd = 1;
	}
	if (ldp == 3)
		return 0;
	if (ldu == 3)
		return 1;

	return -1;
}

int main()
{
	int n, x, step = -1, k = 0, stP = 0, stU = 0;
	string s;

	for (int i = 0; i < nc; i++)
		ni[i] = 0;
	for (int i = 0; i < nc; i++)
		nj[i] = 0;
	for (int i = 0; i < nc; i++)
		pi[i] = 0;
	for (int i = 0; i < nc; i++)
		pj[i] = 0;
	for (int i = 0; i < nc; i++)
		for (int j = 0; j < nc; j++)
			c[i][j] = ' ';
	cout << "Noughts & Crosses\n";

	if (outF() == 1)
		return 0;
	cout << endl;

start:
	cout << "Choose who should make the first move (0 - PC, 1 - You): ";
	cin >> s;
	try {
		x = stoi(s);
		n = x;
	}
	catch (...) {
		cout << "You enter not integer.\n";
		goto start;
	}
	switch (n)
	{
		case 0:
			step = 0;
			break;
		case 1:
			step = 1;
			break;
		default:
			cout << "You enter incorrect number.\n";
			goto start;
			break;
	}
	cout << endl;
	
	if (step == 0) {
		pcFunc();
		stP++;
	}
	else {
		usFunc();
		stU++;
	}

game:
	if (outF() == 1)
		return 0;
	switch (chEnd())
	{
		case 0:
			cout << "Computer WIN!\n";
			goto end;
			break;
		case 1:
			cout << "You WIN!\n";
			goto end;
			break;
	}
	switch (step)
	{
		case 0:
			if (stP > stU) {
				usFunc();
				stU++;
			}
			else {
				pcFunc();
				stP++;
			}
			//system("cls");
			goto game;
			break;
		case 1:
			if (stU > stP) {
				pcFunc();
				stP++;
			}
			else {
				usFunc();
				stU++;
			}
			//system("cls");
			goto game;
			break;
	}
end:
	system("pause");
	return 0;
}