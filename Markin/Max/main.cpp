#include <iostream>

using namespace std;

int Max(int a, int b)
{
    if (a>=b) return a;
    else return b;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << Max(a,b);
    return 0;
}
