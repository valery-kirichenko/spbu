#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int N, k;
	cout << "Please, entry your number:" << endl;
	cin >> N;
	k = (N % 3600) / 60;
	cout << k << endl;
	system("pause");
	return 0;
}