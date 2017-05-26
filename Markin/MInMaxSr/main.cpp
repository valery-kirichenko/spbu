#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int n,i,M,m,s = 0;
    cin >> n;
    vector <int> v(n);
    for (i = 0; i<n; i++)
    {
        cin >> v[i];
    }
    m = v[0];
    M = v[0];
    for (i = 0; i<n; i++)
    {
        s += v[i];
        if (v[i]>M) M = v[i];
        if (v[i]<m) m = v[i];
    }
    cout << "Minimal'niy: " << m << "\nMaksimal'niy: " << M << "\nSrednee arifmeticeskoe: " << (double)s/n;
}
