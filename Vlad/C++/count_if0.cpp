#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class lambda
{
public:
	void operator()(int n)
	{
		cout << n;
	}
};

void main()
{
	int i = 1;
	int j = 3;
	int k = 0;
	vector<int> Viktor(10);
	for (int h = 0; h < Viktor.size(); h++)
	{
		Viktor[h] = h + 1;
	}
//	for_each(Viktor.begin(), Viktor.end(), lambda
//	{
//	});
	k = count_if(Viktor.begin(), Viktor.end(), [i, j](int n) {return i <= n && n < j; });
	cout << k << endl;
	system("pause");
}
