
#include "stdafx.h"
#include "iostream"
#include <vector>
#include <iterator>
using namespace std;

int main()
{
	int c;

	vector<int> a(10);
	vector<int> b(10);
	
	for(int i=0; i<10; i++)	
		cin >> b[i];
	
	cout << endl;
	
	for(int i=0; i<10; i++)
	{
		cin >> c;
		a[i]=c*b[i];
	}

	copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));

	
	cout << endl;
	system("pause");
	
	return 0;
}

