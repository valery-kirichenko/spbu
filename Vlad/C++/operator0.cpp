#include <iostream>
#include <string>

using namespace std;

class high
{
private:
	int holdup[10];
	int sob[5];
public:
	high()
	{
		for (int i = 0; i < 10; i++)
		{
			holdup[i] = i + 1;
		}
	}
	void operator()()
	{
		int b = 0;
		for (int i = 0; i < 10; i++)
		{
			if (holdup[i] % 2 == 0)
			{
				sob[b] = holdup[i];
				b++;
			}
		}
		for (int i = 0; i < 5; i++)
		{
			cout << sob[i] << " ";
		}
	}
};

void main()
{
	high stay;
	stay();
	system("pause");
}
