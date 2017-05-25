
#include "stdafx.h"
#include "iostream"
#include <vector>
#include <iterator>
using namespace std;

int main()
{
	vector<int> a(10);

	for(int i=0; i<10; i++)	
		cin >> a[i];

	copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));

	
	cout << endl;
	system("pause");
	
	return 0;
}

