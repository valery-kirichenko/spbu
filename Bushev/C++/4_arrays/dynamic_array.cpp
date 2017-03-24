#include <iostream>
#include <ctime>

using namespace std;

int main(){
	srand(time(NULL));

	int *ma, size;
	cout << "Enter size: " << endl;
	cin >> size; cout << endl;

	ma = new int[size];

	for(int i = 0; i < size; i++)
		ma[i] = rand() % 10 + 1;

	cout << "Your array: \n";

	for(int i = 0; i < size; i++)
		cout << ma[i] << " ";

	cout << endl;

	system("pause");

	return 0;
}