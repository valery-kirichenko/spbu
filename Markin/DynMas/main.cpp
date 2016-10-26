#include <iostream>

using namespace std;

int main()
{
    int i;
    int n;
    cin >> n;
    int *b = new int [n];
    for (i = 0; i<n; i++)
        cin >> *(b+i);
    for (i = 0; i<n; i++)
        cout << *(b+i) << ' ';
}
