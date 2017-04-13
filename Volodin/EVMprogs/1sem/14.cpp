#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>

using namespace std;

class HashTable {
public:
	int choose[6] = { 23, 131, 929, 10301, 90825, 1046527 };
	int m;
	int p = 15;
	vector < list<string> > ht;
	HashTable() { ht.resize(m = choose[0]); }
	int hs(string val){
		long long res = 0;
		long long pow = p;
		for (int i = 0; i < val.length(); i++) {
			res = (val[i] * pow + res) % m;
			pow = (pow * p) % m;
		}
		return (int)res;
	}
	void add(string val) {
		if (!find(val))
			ht[hs(val)].push_back(val);
	}
	bool find(string val) {
		int t = hs(val);
		for (auto i : ht[t])
			if (i == val)
				return true;
		return false;
	}
};

int main() {
	ifstream f;
	f.open("input.txt");
	HashTable ht;
	string a;
	while (f >> a)
		ht.add(a);
	while (cin >> a)		
		cout << ht.find(a) << endl;
}