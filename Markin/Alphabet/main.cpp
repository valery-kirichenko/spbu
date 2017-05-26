#include <iostream>

using namespace std;

int main()
{
    char c;
    for (c = 'a'; c<='z'; c++)
    {
        cout << c << ' ';
    }
    cout << endl;
    c = 'a';
    while (c<='z')
    {
        cout << c << ' ';
        c++;
    }
    cout << endl;
    c = 'a';
    do
    {
        cout << c << ' ';
        c++;
    }
    while (c<='z');
    return 0;
}
