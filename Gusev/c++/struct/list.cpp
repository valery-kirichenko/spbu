#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <time.h>
#include <conio.h>

using namespace std;

struct st{
private:
	string name1,number1;
public:
	st(){
		name1 = "no name";
		number1 = "no number";
	}
	st(string _name){
		rename(_name);
		number1 = "no number";
	}
	st(string _name, string _number){
		rename(_name);
		renum(_number);
	}
	void rename(string _name1){
		name1 = _name1;
	}
	void renum(string number){
		if (is_ok(number))
			number1 = number;
		else
			number1 = is_ok(number1) ? number1 : "no number";
	}
	string name(){
		return name1;
	}
	string number(){
		return number1;
	}
private:
	bool is_ok(string str){
		bool f = true;
		if (str.empty())
			return false;
		f &= str[0] == '+';
		f &= str.size() == 12;
		for (int i = 1; i < str.size(); i++)
			f &= (str[i] >= '0' && str[i] <= '9');
		return f;
	}
};//class of one number

ostream& operator << (ostream& out, st st1){
	out << "name is: " << st1.name() << "\nnumber is: " << st1.number() << "\n";
	return out;
}//ouput of number

struct list{
private:
	vector<st> l;
public:
	list(){
		l.clear();
	}
	list(st st1){
		l.push_back(st1);
	}
	void push_back(st st1){
		l.push_back(st1);
	}
	void user_insert(){
		st st1;
		string str;
		cout << "insert name: ";
		cin >> str;
		while (!is_ok(str)){
			cout << "This name already exist!\nInsert name again: ";
			cin >> str;
		}
		st1.rename(str);
		cout << "insert nmber(in format +79123456789): ";
		cin >> str;
		st1.renum(str);
		while (st1.number()[0] != '+'){
			cout << "invalidate data! insert again(in format +79123456789): ";
			cin >> str;
			st1.renum(str);
		}
		l.push_back(st1);
	}//function for users insert
	string search(){
		string _name;
		cout << "insert name: ";
		cin >> _name;
		string s = "no data";
		for (int i = 0; i < l.size(); i++){
			if (l[i].name() == _name){
				s = l[i].number();
				break;
			}
		}
		return s;
	}//serching function
	void clear(){
		l.clear();
	}
	size_t size(){
		return l.size();
	}
	st& operator [](int i){
		return l[i];
	}
	list(vector<st> st1){
		l = st1;
	}
private:
	bool is_ok(st st1){
		for (int i = 0; i < l.size(); i++){
			if (l[i].name() == st1.name())
				return false;
		}
		return true;
	}
};//class of list of numbers

ostream& operator << (ostream& out, list l){
	if (l.size() != 0){
		for (int i = 0; i < l.size(); i++)
			out << "acaunt " << i+1 << ":\n" << l[i];
	}
	else
		cout << "no data\n";
	return out;
}//ouput of list

void intialise(list& L){
	st s1;
	s1.rename((string)"sudent1");
	s1.renum((string)"+79123456789");
	L.push_back(s1);
	s1.rename((string)"sudent2");
	s1.renum((string)"+79116578349");
	L.push_back(s1);
	s1.rename((string)"sudent3");
	s1.renum((string)"+79216587943");
	L.push_back(s1);
	s1.rename((string)"sudent4");
	s1.renum((string)"+79216543789");
	L.push_back(s1);
}//starting list

int main(){
	//freopen("feelgood.in", "r", stdin);
	//freopen("feelgood.out", "w", stdout);
	list L;
	char c;
	intialise(L);
	string str = "what i should do?\n1) show a list\n2)insert new number\n3)clear list\n4)search number\n5)exit\n\n";
	while (0 == 0){
		cout << str;
		c = _getch();
		system("cls");
		switch (c){
		case '1': 
			cout << L << "\npress any key";
			_getch();
			break;
		case '2':
			L.user_insert();
			break;
		case '3':
			L.clear();
			break;
		case '4':
			cout << L.search() << "\npress any key";
			_getch();
			break;
		case '5':
			return 0;
		default: break;
		}
		system("cls");
	}
	return 0;
}