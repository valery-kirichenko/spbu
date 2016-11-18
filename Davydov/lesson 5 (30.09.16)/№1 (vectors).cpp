#include<stdafx>
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int main()
{
	
	vector<int> v(10);
	v.resize(10);
	int i;

	for (i=0; i < v.size(); i++)
		cout<<v[i]<<endl;

	system("pause");
	return 0;
}


