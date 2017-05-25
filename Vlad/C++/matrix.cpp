#include <iostream>


int main() {
	setlocale(LC_ALL, "RUSSIAN");

	int del1, del2, del3;
	int x1[4], x2[4], x3[4], a[8];
	std::cout << "Ïåðâàÿ ñòðîêà 1-îé ìàòðèöû: " << std::endl;
	for (int i = 0; i <= 1; i++) 
		std::cin >> a[i];
	std::cout << "Âòîðàÿ ñòðîêà 1-îé ìàòðèöû: " << std::endl;
	for (int i = 2; i <= 3; i++) 
		std::cin >> a[i];
	std::cout << "Ïåðâàÿ ñòðîêà 2-îé ìàòðèöû: " << std::endl;
	for (int i = 4; i <= 5; i++) 
		std::cin >> a[i];
	std::cout << "Âòîðàÿ ñòðîêà 2-îé ìàòðèöû: " << std::endl;
	for (int i = 6; i <= 7; i++) 
		std::cin >> a[i];

	x1[0] = a[0]*a[4] + a[1]*a[6];
	x1[1] = a[0]*a[5] + a[1]*a[7];
	x1[2] = a[2]*a[4] + a[3]*a[6];
	x1[3] = a[2]*a[5] + a[3]*a[7];

	x2[0] = a[0] + a[4];
	x2[1] = a[1] + a[5];
	x2[2] = a[2] + a[6];
	x2[3] = a[3] + a[7];

	x3[0] = a[0] - a[4];
	x3[1] = a[1] - a[5];
	x3[2] = a[2] - a[6];
	x3[3] = a[3] - a[7];

	del1 = x1[0]*x1[3] - x1[1]*x1[2];
	del2 = x2[0]*x2[3] - x2[1]*x2[2];
	del3 = x3[0]*x3[3] - x3[1]*x3[2];

	std::cout 
		<< "Ðåçóëüòàò óìíîæåíèÿ: " << std::endl 
		<< x1[0] << " " << x1[1]   << std::endl
		<< x1[2] << " " << x1[3]   << std::endl
		<< "Ðåçóëüòàò ñëîæåíèÿ: "  << std::endl
		<< x2[0] << " " << x2[1]   << std::endl
		<< x2[2] << " " << x2[3]   << std::endl
		<< "Ðåçóëüòàò âû÷èòàíèÿ: " << std::endl
		<< x3[0] << " " << x3[1]   << std::endl
		<< x3[2] << " " << x3[3]   << std::endl
		<< "Îïðåäåëèòåëè: "        << std::endl
		<< "1-àÿ ìàòðèöà: " << del1<< std::endl
		<< "2-àÿ ìàòðèöà: " << del2<< std::endl
		<< "3-àÿ ìàòðèöà: " << del3<< std::endl;
}
