/*
	-Linear search
	-Binary search
	-Bubble sort
	-Selection sort
	-Insertion sort
	-Quick sort
	-Merge sort
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <ctime>
#include <string>

using namespace std;

auto less_cmp = [](auto a, auto b) {return a < b; };
auto greater_cmp = [](auto a, auto b) {return a > b; };

//Finds the first element of v that is equal to x
template <class T>
int find_linear(const vector <T>& v, T x) {
	for (int i = 0; i < v.size(); i++)
		if (v[i] == x)
			return i;
	return n;
}

//The first element of sorted vector v that is greater than x
template <class T>
int bound(const vector <T>& v, T x, function<bool(T, T)> cmp = less_cmp) {
	int l = -1, r = v.size() - 1;
	while (l < r) {
		int m = (l + r + 1) >> 1;
		if (m == -1 || cmp(x, v[m]))
			r = m - 1;
		else
			l = m;
	}
	return l + 1;
}

template <class T>
void bubble_sort(vector <T>& v, function<bool(T, T)> cmp = less_cmp) {
	int n = v.size();
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++)
			if (cmp(v[j], v[j - 1]))
				swap(v[j], v[j - 1]);
}

template <typename T>
void selection_sort(vector <T>& v, function<bool(T, T)> cmp = less_cmp) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		int m = i;
		for (int j = i + 1; j < n; j++)
			if (cmp(v[j], v[m]))
				m = j;
		swap(v[m], v[i]);
	}
}

template <class T>
void insertion_sort(vector <T>& v, function<bool(T, T)> cmp = less_cmp) {
	int n = v.size();
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j != 0 && cmp(v[j], v[j - 1]))
			swap(v[j], v[j - 1]), j--;
	}
}

template <class T>
void qs(vector <T>& v, function<bool(T, T)> cmp, int l, int r) {
	int a = l, b = r;
	T pivot = v[(l + r) >> 1];
	while (l <= r) {
		while (cmp(v[l], pivot))
			l++;
		while (cmp(pivot, v[r]))
			r--;
		if (l <= r)
			swap(v[l++], v[r--]);
	}
	if (a < r)
		qs(v, cmp, a, r);
	if (l < b)
		qs(v, cmp, l, b);
}

template <class T>
void quick_sort(vector <T>& v, function<bool(T, T)> cmp = less_cmp) {
	qs(v, cmp, 0, v.size() - 1);
}

template <class T>
void merge_sort(vector <T>& v, function<bool(T, T)> cmp = less_cmp) {
	if (v.size() == 1)
		return;
	int m = v.size() / 2, k = v.size()  - m;
	vector <T> a(m), b(k);
	move(v.begin(), v.begin() + m, a.begin());
	move(v.begin() + m, v.end(), b.begin());
	merge_sort(a, cmp);
	merge_sort(b, cmp);
	int i = 0, j = 0, count = 0;
	while (i != m || j != k) {
		if (i == m || (j != k && cmp(b[j], a[i])))
			v[count++] = b[j++];
		else
			v[count++] = a[i++];
	}
}

template <typename T>
vector <function<void(vector <T>&, function<bool(T, T)>)> > sorts = {
	bubble_sort<T>, selection_sort<T>, insertion_sort<T>, quick_sort<T>, merge_sort<T> };

vector <string> sortName = { "Bubble", "Selection", "Insertion", "Quick", "Merge" };

template <typename U> vector <U> g;

void check(const vector <int>& a) {
	cout << "Array size: " << a.size() << endl;
	for (int i = 0; i < sorts<int>.size(); i++) {
		vector <int> b = a;
		clock_t clt = clock();
		sorts<int>[i](b, less_cmp);
		clock_t fn = clock();
		cout << sortName[i] << " sort: " << (double)(fn - clt) / CLOCKS_PER_SEC << endl;
	}
}

int main() {
	srand(time(NULL));
	const int n = 2e3;
	vector <int> a(n);
	generate(a.begin(), a.end(), [] {return rand(); });
	check(a);
}

/*
{ 1, -7, 234, 987, 2, 20, 5, 87, 1, 76, -25, 9, -10 };
*/