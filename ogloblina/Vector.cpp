#include "stdafx.h"
#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{	int n,i;
	cout << "enter amout of numbers n" << endl;
    cin >> n;
    vector<int>v1(n);
    vector<int>v2(n);
    vector<int>v3(n);
    cout << "enter v1";
    for (i=0;i<v1.size();i++)
	cin >> v1[i];
    cout << "enter v2";
    for (i=0;i<v2.size();i++)
    cin >> v2[i];
    for(i=0;i<v1.size();i++)
    v3[i]=v1[i]*v2[i];
    cout << "v1="<< endl;
    copy(v1.begin(),v1.end(), ostream_iterator<int>(cout," "));
	cout << "v2="<< endl;
    copy(v2.begin(),v2.end(), ostream_iterator<int>(cout," "));
    cout << "v3="<< endl;
	copy(v3.begin(),v3.end(), ostream_iterator<int>(cout," "));
    system ("pause");
    return 0;
}