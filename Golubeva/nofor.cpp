// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	vector <int>  v (10);
	for (int i=0; i<v.size(); i++)
	{
		v[i]=i;
	}
	
	copy( v.begin(), v.end(), ostream_iterator <int> (cout," "));

	int a;
	cin >> a;
	return 0;
}

