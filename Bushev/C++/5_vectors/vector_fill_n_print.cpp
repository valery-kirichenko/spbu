#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main(){
	srand(time(NULL));
	
	vector<int> v; 

	int size;
	cout << "Enter size: " << endl;
	cin >> size;
	
	v.resize(10);

	for(int i = 0; i < v.size(); i++)
		v[i] = rand() % 10 + 1;

	for(int i = 0; i < v.size(); i++)
		cout  << v[i] << " ";

	cout << endl;

	system("pause");
	return 0;
}