#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	cin >> str;

	for(int i = 0; i < str.size(); i++){
		if((str[i] < '0' || str[i] > '9') && str[i] != '-'){
			cout << "String";
			system("pause");
			return 0;
		}
	}

	cout << "Number";
	system("pause");

	return 0;
}