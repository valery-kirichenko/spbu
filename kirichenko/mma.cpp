#include <iostream>
#include <vector>

int main() {
	int n, max, min, avg;
	std::vector<int> v;
	std::cout << "Количество элементов: ";
	std::cin >> n;
	v.reserve(n);
	std::cin >> v[0];
	max = v[0];
	min = v[0];
	avg = v[0];
	for (int i = 1; i < n; i++) {
		std::cin >> v[i];
		if (v[i] > max) max = v[i];
		if (v[i] < min) min = v[i];
		avg += v[i];
	}
	std::cout << avg << std::endl	std::cout << "Max: " << max << "\nMin: " << min << "\nAvg: " << float(avg) / n << std::endl;

	return 0;

}