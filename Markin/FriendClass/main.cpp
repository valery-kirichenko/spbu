#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class Circle;

class Square
{
    int side;
public:
    void operator >>(int a)
    {
        side = a;
    }
    friend class Circle;
};

class Circle
{
    int rad;
public:
    void operator >>(int a)
    {
        rad = a;
    }
    void convert (Square s)
    {
        rad = s.side;
    }
    void print()
    {
        cout << rad;
    }
};

int main()
{
    Square s;
    Circle c;
    int a,r;
    cin >> a;
    s >> a;
    cin >> r;
    c >> r;
    c.convert(s);
    c.print();
    return 0;
}

