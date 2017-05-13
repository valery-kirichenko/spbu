#include "stdafx.h"
#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <queue>
#include <map>
#include <iterator>


int main()
{	
	// Declaration.
	const int n = 5;
	std::deque<int> deque;
	std::list<int> list;
	std::queue<int> queue;
	std::map<int, int> map;

	// Initialization.
	std::cout << "Filling containers with (numbers from 1 to 5) * const.\n" << std::endl;
	for (int i = 1; i <= n; i++) 
	{
		deque.push_front(i);

		list.push_back(i * 2);

		queue.push(i * 3);

		map.insert(std::pair<int, int>(i, i * 4));
	}

	// Output.
	std::cout << "Print containers to the console:" << std::endl;
	std::copy(deque.begin(), deque.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	while (!queue.empty()) {
		std::cout << queue.front() << " ";
		queue.pop();
	}
	std::cout << std::endl;

	for (auto it = map.begin(); it != map.end(); ++it)
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	}
	std::cout << "\nThat's all I wanted to show.\n" << std::endl;

	system("pause");
	return 0;
}