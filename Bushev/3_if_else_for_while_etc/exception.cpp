#include <iostream>

using namespace std;

int main(){
	int i, j;
	cin >> i >> j;

	try{
		if(j == 0) throw "Error, you can't devide by 0";
	}catch(char c[]){
		cout << c << endl;
		system("pause");
		return 0;
	}

	cout << "Devision: " << i / j << endl;
	system("pause");

	return 0;
}
