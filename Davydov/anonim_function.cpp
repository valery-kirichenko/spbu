//#include<stdafx.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <algorithm>
#include<vector>
using namespace std;

const int k = 10;
int main()
{
	vector<int> vec(k);
	for (int i=0; i<k; i++) {vec[i] = rand() % k;}
	for_each(vec.begin(), vec.end(), [](int n) {cout<<n<<" ";});

	system("pause");
	return 0;
}