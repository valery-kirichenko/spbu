#include <iostream>

using namespace std;

int max(int a, int b){
	return (a > b) ? a : b;
}

int main(){
	int a, b;
	
	cout << "Enter 2 numbers: " << endl;
	cin >> a >> b;

	cout << "Max: " << max(a, b) << endl;
	system("pause");

	return 0;
}