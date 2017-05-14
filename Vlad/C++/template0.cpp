#include <iostream>

using namespace std;

template <typename T>
void print(const T* array, int count)
{
	for (int i = 0; i < count; i++)
		cout << array[i] << " ";
}

template <typename A>
void bubble(A* array, int count)
{
	for (int i = 0; i < count - 1; i++) 
	{
		bool checker_s = 0;
		for (int j = 0; j < count - i - 1; j++) {
			if (array[j] > array[j + 1]) 
			{
				int brray = array[j];
				array[j] = array[j + 1];
				array[j + 1] = brray;
				checker_s = 1;
			}
		}
		if (checker_s == 0) break;
	}
}

int main()
{
	const int size = 5;
	int array[size] = { 10,3,2,7,8 };
	bubble(array, size);
	print(array, size);
	system("pause");
}
