#include "stdafx.h"
#include <iostream>
#include <string>

class Par {
public:
	int x;

	Par ()
	{
		int x = 0;
	}

	void enter(int a)
	{
		x = a;
	}
};

template <class T>
class listM {
public:
	unsigned int size;
	struct list {
		T field;
		list *ptr;
	};
	list *firstptr;
	list *last;

	listM(T value)
	{
		size = 0;
		firstptr = nullptr;
		list *lst;

		lst = new list;
		lst->field = value;
		lst->ptr = nullptr;
		firstptr = lst;
		last = lst;
		size = 1;
	}

	~listM()
	{
		list *temp;
		if (size != 0) {
			while (firstptr->ptr != nullptr)
			{
				temp = firstptr;
				firstptr = firstptr->ptr;
				delete temp;
			}
			delete firstptr;
		}
		std::cout << "\nList has been deleted!\n";
	}

	void push_front(T value)
	{
		list *temp;
		temp = new list;
		temp->field = value;
		temp->ptr = firstptr;
		firstptr = temp;
		size++;
	}

	void push_back(T value)
	{
		list *temp, *p;
		temp = new list;
		p = last->ptr;
		last->ptr = temp;
		temp->field = value;
		temp->ptr = p;
		last = temp;
		size++;
	}

	void pop_front()
	{
		list *temp;
		temp = firstptr->ptr;
		delete firstptr;
		firstptr = temp;
		size--;
	}

	void pop_back()
	{
		list *temp;
		temp = firstptr;
		for (unsigned int i = 1; i < size - 1; i++)
			temp = temp->ptr;
		temp->ptr = last->ptr;
		delete last;
		last = temp;
		size--;
	}

	void print() {
		list *p;
		T temp;
		p = firstptr;
		do {
			temp = p->field;
			std::cout << temp.x << " "; 
			p = p->ptr; 
		} while (p != nullptr);
		std::cout << "\n";
	}

	unsigned int getSize()
	{
		return size;
	}
};

int main()
{
	Par clas0;
	clas0.enter(5);

	Par clas1;
	clas1.enter(0);

	Par clas2;
	clas2.enter(10);

	listM<Par> list(clas0);
	
	list.print();
	std::cout << "\n";
	list.push_back(clas2);
	list.push_front(clas1);
	list.print();
	std::cout << "\n";
	list.pop_back();
	list.pop_front();
	list.print();

	system("pause");
	return 0;
}