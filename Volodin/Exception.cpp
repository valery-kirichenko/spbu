#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	try {
		if (b == 0)
			throw (string)"Dividing by zero";
		cout << a / b;
	}
	catch (string e) {
		cout << "Error " << e;
	}
}

