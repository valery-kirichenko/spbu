#include <iostream>
#include <deque>
#include <list>
#include <map>
#include <queue>

int main() {
	std::deque<int> deque;
	std::list<int> list;
	std::queue<int> queue;
	std::map<int, int> map;

	for (int i = 0; i < 10; i++) {
		deque.push_front(i);
		list.push_back(10 + i);
		queue.push(20 + i);
		map.insert(std::pair<int, int>(i, 30 + i));
	}

	std::cout << "Deque:" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << deque.back() << " ";
		deque.pop_back();
	}
	std::cout << std::endl;

	std::cout << "List:" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << list.front() << " ";
		list.pop_front();
	}
	std::cout << std::endl;

	std::cout << "Queue:" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << queue.front() << " ";
		queue.pop();
	}
	std::cout << std::endl;

	std::cout << "Map:" << std::endl;
	for (std::map<int, int>::iterator i = map.begin(); i != map.end(); i++) {
		std::cout << i->second << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
