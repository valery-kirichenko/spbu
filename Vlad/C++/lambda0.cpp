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
	vector<int> Viktor(5);
	for (int i = 0; i < Viktor.size(); i++)
	{
		Viktor[i] = i + 1;
	}
	for_each(Viktor.begin(), Viktor.end(), lambda
	{
	});
	cout << endl;
	system("pause");
}
