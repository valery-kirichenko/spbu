// ConsoleApplication7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class cl
{
public: 
	int even; 
	int odd;
	cl() : even(0), odd(0) {}
		void operator()(int ch){
			if (ch%2==0)
				even++;
			else 
				odd++;
		}
	int even1() const { return even; }
    int odd1() const { return odd; }
};


int main()
{
	const int n=10;
	cl cc;
    int mas[n]; 
	for (int i=0; i<n; i++)
		mas[i]=i;
	for (int i=0; i<n; i++)
		cc(mas[i]);
	cout << "Even: " << cc.even1() << endl;
    cout << "Odd: " << cc.odd1() << endl;
	system("pause");
	return 0;
}

