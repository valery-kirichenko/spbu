#include <iostream>
using namespace std;
class Animal
{
protected:
	int leg_num;
public:
	Animal()
	{
		leg_num=0;
	}
	virtual void show()
	{
		cout<<leg_num;
	}


};
class Cat: public Animal
{
public:Cat()
	{
		leg_num=4;
	}
	void show()
	{
		cout<<leg_num<<" It's a cat ffs\n";
	}

};
class Ladybug: public Animal
{
public: Ladybug()
	{
		leg_num=6;
	}
	void show()
	{
		cout<<leg_num<<" It's a ladybug\n";
	}

};
class Kangaroo: public Animal
{
public: Kangaroo()
	{
		leg_num=2;
	}
	void show()
	{
		cout<<leg_num<<" It's a kangaroo\n";
	}

};

int main()
{
	Cat a;
	Ladybug b;
	Kangaroo c;
	Animal *ptr =&a;
	ptr->show();
	ptr=&b;
	ptr->show();
	ptr=&c;
	ptr->show();

	//system("pause");



	return 0;

}
