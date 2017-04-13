#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct date {
	int year, month, day;
	date() {}
	date(int year, int month, int day):year(year), month(month), day(day){}
};

struct tour{
	string name;
	string clientname;
	int payment;
	date coming;
	int daycount;
	int transportPayment;
	double currencyCourse;
	double currencyCount;
	tour() { }
	tour(string name, int trp, date d) :name(name), transportPayment(trp), coming(d){}
};

bool namecmp(tour a, tour b) {
	return a.name < b.name;
}
bool transportPaymentcmp(tour a, tour b) {
	return a.transportPayment < b.transportPayment;
}
bool comingcmp(tour a, tour b) {
	if (a.coming.year < b.coming.year)
		return true;
	if (b.coming.year < a.coming.year)
		return false;
	if (a.coming.month < b.coming.month)
		return true;
	if (b.coming.month < a.coming.month)
		return false;
	if (a.coming.day < b.coming.day)
		return true;
	if (b.coming.day < a.coming.day)
		return false;
	return a.name < b.name;
}
#define it(v) v.begin(), v.end()

void out(vector <tour>& v) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i].name << ' ';
	cout << endl;
}
int main() {
	const int n = 4;
	vector <tour> a(n);
	a[0] = tour("2", 5, date(2016, 7, 8));
	a[1] = tour("1", 11, date(2015, 6, 8));
	a[2] = tour("3", 1, date(2016, 8, 8));
	a[3] = tour("4", 3, date(2015, 6, 1));
	out(a);
	sort(it(a), namecmp);
	out(a);
	sort(it(a), transportPaymentcmp);
	out(a);
	sort(it(a), comingcmp);
	out(a);
}