#include <thread>
#include <iostream>

using namespace std;

const int FLOOD_COUNT = 2500;

void flood() {
	for (int i = 0; i < FLOOD_COUNT; i++)
		cout << "flood: " << i << endl;
}

int main() {
	thread mthread(flood);
	mthread.detach();

	for (int i = 0; i < FLOOD_COUNT; i++)
		cout << "main: " << i << endl;

	return 0;
}