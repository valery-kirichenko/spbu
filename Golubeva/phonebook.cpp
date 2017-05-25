#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct 
	{string name; string fname; int cp;} cell;
int main()
{
	
	int a=0,n=0;
	vector <cell> ph;
	while (a!=3) {
	cout << "1. Add cell number\n2. Look through cell phone numbers\n3. Exit\n";
	cin >> a;
	switch (a)
	{
	case 1:{
				n+=1;
				ph.reserve (n);  
				cout << "Enter first name: ";
				cin >> ph[n-1].name;
				cout << "Enter second name: ";
				cin >> ph[n-1].fname;
				cout << "Enter phone number: ";
				cin >> ph[n-1].cp;
				break;
		   }
	case 2:{
				for (int i=0; i<n; i++)
				{
					cout << i+1 << ". " << ph[i].fname << ' ' << ph[i].name << " Cell phone number: " << ph[i].cp << endl;

				}
				break;
		   }

	}
	}

	return 0;
}

