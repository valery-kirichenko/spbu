#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cout << "Please, entry your number:" << endl;
	cin >> K;
	N = (K + 1) % 7;
	cout << "Day is " << N << endl;
	system("pause");
	return 0;
}