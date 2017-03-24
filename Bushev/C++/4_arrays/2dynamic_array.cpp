#include <iostream>
#include <ctime>

using namespace std;

int main(){
	srand(time(NULL));

	int **ma, size;
	cout << "Enter size: " << endl;
	cin >> size; cout << endl;
	
	ma = new int*[size];

	for(int i = 0; i < size; i++)
		ma[i] = new int[size];
	
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			ma[i][j] = rand() % 10 + 1;

	cout << "Your array: \n";

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			cout << ma[i][j] << " ";
		cout << endl;
	}

	cout << endl;

	system("pause");

	return 0;
}