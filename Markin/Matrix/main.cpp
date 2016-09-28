#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[2][2],b[2][2],c[2][2];
    int k,i,j;
    cout << "Vvedite pervuyu matricu: " << endl;
    for (i = 0; i<2; i++)
        for (j = 0; j<2; j++)
            cin >> a[i][j];
    cout << "Vvedite vtoruyu matricu: " << endl;
    for (i = 0; i<2; i++)
        for (j = 0; j<2; j++)
            cin >> b[i][j];
    cout << "Vvedite nomer operacii: \n 1. Slozhenie. \n 2. Vichitanie. \n 3. Umnozhenie.\n";
    cin >> k;
    switch(k)
    {
        case 1:
        {
            for (i = 0; i<2; i++)
                for (j = 0; j<2; j++)
                    c[i][j] = a[i][j]+b[i][j];
            break;
        }
        case 2:
        {
            for (i = 0; i<2; i++)
                for (j = 0; j<2; j++)
                    c[i][j] = a[i][j]-b[i][j];
            break;
        }
        case 3:
        {
            for (i = 0; i<2; i++)
                for (j = 0; j<2; j++)
                {
                    c[i][j] = a[i][0]*b[0][j]+a[i][1]*b[1][j];
                }
            break;
        }
    }
    cout << "Poluchennaya matrica: \n";
    for (i = 0; i<2; i++)
    {
        for (j = 0; j<2; j++)
            cout << setw(3) << c[i][j];
        cout << endl;
    }
    cout << "Opredelitel' poluchennoy matrici: " << c[0][0]*c[1][1]-c[1][0]*c[0][1];
    return 0;
}
