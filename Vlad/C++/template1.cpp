#include <conio.h>
#include <iostream>

template <typename value>	

class list
{
	class element
	{
	public:
		value x;
		element* next;
	};
	element* first_element;

public:
	list()
	{
		first_element = NULL;
	}
	
	void add_Element(int a)
	{
		element* temp = new element;
		temp->next = first_element;
		first_element = temp;
		temp->x = a;
	}
	void delete_Element()
	{
		first_element = first_element->next;
	}
	void show_Elements()
	{
		element* shower = first_element;
		while (shower != NULL)
		{
			std::cout << shower->x;
			shower = shower->next;
		}
		std::cout << std::endl;
	}
};

int main()
{
	list <int> hi;
	list <char> yo;
	for (int i = 1; i < 6; i++)
	{
		hi.add_Element(i);
		yo.add_Element(i+59);
	}
	hi.delete_Element();
	yo.delete_Element();
	hi.show_Elements();
	yo.show_Elements();
	system("pause");
}
