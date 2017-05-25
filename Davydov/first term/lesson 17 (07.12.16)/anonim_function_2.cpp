//#include<stdafx.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;

const int k = 10;
int main()
{
	vector<int> vec(k);
	int x = 3;
	int y = 6;

	for (int i=0; i<k; i++) {vec[i] = rand() % k;}
	copy( vec.begin(), vec.end(), ostream_iterator<int>(cout," "));

	int k = count_if(vec.begin(), vec.end(), [x, y](int n) {return (x<n) && (n>y);});
	cout<<"\nКоличество чётных: "<<k<<endl;

	system("pause");
	return 0;
}