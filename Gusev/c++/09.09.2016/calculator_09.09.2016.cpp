#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<Windows.h>

using namespace std;

string help = "Это калькулятор!\nЯ знаю команды:\nhelp - экран помощи\nexit - выход\nclear - очистить список предыдущих примеров\nили вы можете ввести пример содержащий операции +, -, *, / ,% и скобки ()\nВнимание пример не должен содержать пробелы!";
vector<string> prev1;
HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
bool cyc = true;
bool firs = true;;

pair<double, bool> mu(string,int);
pair<double, bool> su(string,int);

double del(double a, double b){
	if (b < 0){
		a *= -1;
		b *= -1;
	}
	if (a < 0){
		while (a < 0)
			a += b;
		return a;
	}
	else{
		while (a > b)
			a -= b;
		return a;
	}
}

pair<double, bool> mu(string str,int pos){
	if (str == "")
		return make_pair(0, 1);
	if (pos>str.size() || !((str[0]>='0' && str[0]<='9') || str[0]=='(' || str[0]=='-'))
		return make_pair(0, 0);
	double ans = 1,b;
	pair<double, bool> prot;
	int k = 0, j=pos,a=0;
	for (int i = pos; i < str.size() && k >= 0; i++){
		if (str[i] == '('){
			k++;
			j = i;
			i++;
			while (k != 0 && i < str.size()){
				if (str[i] == '(')
					k++;
				if (str[i] == ')')
					k--;
				i++;
			}
			if (i == str.size()&&k!=0)
				return make_pair(0, 0);
			else{
				prot = su(str.substr(j+1, i-j-2), 0);
				if (!prot.second)
					return make_pair(0, 0);
				else{
					if (a==0)
						ans *= prot.first;
					else if (a == 1){
						if (prot.first == 0)
							return make_pair(0, 0);
						else
							ans /= prot.first;
					}
					else{
						if (prot.first == 0)
							return make_pair(0, 0);
						else
							ans = del(ans, prot.first);
					}
						
				}
				a = 0;
				j = i;
			}
		}
		if (str[i] == '*' || str[i] == '/' || str[i] == '%'){
			if (j > i - 1){
				b = 1;
				a = 0;
			}
			else{
				if (sscanf(str.substr(j, i-j).c_str(), "%lf", &b) != 1)
					return make_pair(0, 0);
				else
					b = atof(str.substr(j, i-j).c_str());
			}
			if (a == 0)
				ans *= b;
			else if (a == 1){
				if (b == 0)
					return make_pair(0, 0);
				else
					ans /= b;
			}
			else{
				if (b == 0)
					return make_pair(0, 0);
				else
					ans = del(ans, b);
			}
			a = 0;
			j = i + 1;
			if (str[i] == '*')
				a = 0;
			else if (str[i] == '/')
				a = 1;
			else
				a = 2;
		}
	}
	if (j >= str.size()){
		b = 1;
		a = 0;
	}
	else{
		if (sscanf(str.substr(j, str.size()-j).c_str(), "%llf", &b) != 1)
			return make_pair(0, 0);
		else
			b = atof(str.substr(j, str.size()-j).c_str());
	}
	if (a == 0)
		ans *= b;
	else if (a == 1){
		if (b == 0)
			return make_pair(0, 0);
		else
			ans /= b;
	}
	else{
		if (b == 0)
			return make_pair(0, 0);
		else
			ans = del(ans, b);
	}
	return make_pair(ans, 1);
}

pair<double,bool> su(string str,int pos){
	if (str == "")
		return make_pair(0, 1);
	if (pos>str.size() || !((str[0] >= '0' && str[0] <= '9') || str[0] == '(' || str[0] == '-'))
		return make_pair(0,0);
	double ans = 0;
	pair<double, bool> prot;
	bool si = false;
	int k = 0, j=pos;
	for (int i = pos; i < str.size() && k >= 0; i++){
		if (str[i] == '(')
			k++;
		if (str[i] == ')')
			k--;
		if (k==0&&(str[i] == '+' || str[i] == '-')){
			prot = mu(str.substr(j, i-j), 0);
			if (!prot.second)
				return make_pair(0, 0);
			else{
				if (si)
					ans -= prot.first;
				else
					ans += prot.first;
			}
			if (str[i] == '-')
				si = true;
			else
				si = false;
			j = i + 1;
		}
	}
	prot = mu(str.substr(j, str.size()-j), 0);
	if (!prot.second)
		return make_pair(0, 0);
	else{
		if (si)
			ans -= prot.first;
		else
			ans += prot.first;
	}
	return make_pair(ans,1);
}

void proc(string str){
	pair<double,bool> ans = su(str,0);
	COORD coord;
	string str1;
	coord.X = 18;
	if (firs)
		coord.Y = 1;
	else
		coord.Y = 0;
	char C[256];
	if (ans.second){
		str1 += " = ";
		sprintf(C, "%lf", ans.first);
		for (int i = 0; C[i] != 0; i++)
			str1 += C[i];
		SetConsoleCursorPosition(hconsole, coord);
		cout << str+str1 << endl;;
		prev1.push_back(str+str1);
	}
	else{
		SetConsoleCursorPosition(hconsole, coord);
		str1 += " = ERROR";
		cout << str+str1<<endl;
	}
}

int main(){
	setlocale(LC_ALL, "rus");
	bool a;
	COORD coord;
	coord.X = 18;
	coord.Y = 0;
	string str;
	cout << "введите команду help для пояснений"<<endl;
	while (cyc){
		cout << "введите команду: " << endl << endl<<"предыдущте вычисления: "<<endl;
		for (int i = 0; i < prev1.size(); i++)
			cout << i + 1 << ") " << prev1[prev1.size() - 1 - i] << endl;
		coord.X = 18;
		if (firs)
			coord.Y = 1;
		else
			coord.Y = 0;
		SetConsoleCursorPosition(hconsole, coord);
		cin >> str;
		a = false;
		for (int i = 0; i < str.size(); i++){
			if (str[i] == '.')
				str[i] = ',';
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '/' || str[i] == '*' || str[i] == '-' || str[i] == '+' ||str[i] == ',' || str[i] == '(' || str[i] == ')' || str[i] == '%')
				continue;
			a = true;
			break;
		}
		if (a){
			if (str == "help"){
				system("cls");
				cout << help << endl;
			}
			else if (str == "exit")
				cyc = false;
			else if (str == "clear")
				prev1.clear();
			else
				cout <<endl<< "я не знаю такой косанды:(.";
		}
		else{
			proc(str);
		}
		cout <<"для продолжения нажмите кнопку...";
		_getch();
		firs = false;
		system("cls");
	}
	return 0;
}