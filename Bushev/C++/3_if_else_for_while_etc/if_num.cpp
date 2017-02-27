#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main(){
	string str, res = "Number";
	cin >> str;

	for(int i = 0; i < str.size(); i++){
		if((str[i] < '0' || str[i] > '9')){
			if(str[i] == '-' && i == 0) continue;
			
			res = "String";
			break;
		}
	}

	cout << res << endl;
	system("pause");

	return 0;
}
