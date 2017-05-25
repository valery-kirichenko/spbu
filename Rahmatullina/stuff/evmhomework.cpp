// ConsoleApplication9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int>v(0);
	int N,k,l=1;
	cout << " enter number N " ; cin >> N;
	cout << " enter elements " << endl;
	for (int i=0;i<N;i++)
        {cin >> k;
	    v.push_back(k);}
	for (int i=0;i<(v.size()-1);i++) if (v[i]<v[i+1]){ l=i;cout << "No " << " Number = " << i+2; break;}
	else l++;if (l==N)cout << "Yes";
	system("pause");
	return 0;
}

