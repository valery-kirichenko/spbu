// ConsoleApplication7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<iomanip>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	vector<string>v(0);
	string s="abc";
    string t="abc";
    int n,j=0;
	cout << "enter number of people n";cin >> n;
	
	for (int i=0;i<n;i++) {
		cout << " enter name: " << endl;
		cin >> s;
	    cout << " enter telephone: " << endl;
		cin >> t;
	    v.push_back(s);
		v.push_back(t);
	    }
	for (int i=0;i<n;i++){
		cout << setw(10) << v[j] << " " << setw(11) << v[j+1];
	    cout << endl;
		j+=2;}
	system("pause");
		return 0;
}

