#include <iostream>

using namespace std;

class Mas
{
public:
    int s;
    void operator()(int a[10])
    {
        for (int i = 0; i<10; i++)
        {
            if (a[i]%2 == 0) cout << "Chet ";
            if (a[i]%2 == 1) cout << "Nechet ";
            cout << a[i] << endl;
        }
    }
};

int main()
{
    int a[10] = {1,2,5,3,8,4,6,5,9,7};
    Mas m;
    m(a);
    return 0;
}
