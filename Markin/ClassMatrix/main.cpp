#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class MATRIX{
public:
    int m[3][3];
    MATRIX()
    {
        int i,j;
        cout << "vvedite elementi matrici:\n";
        for (i = 0; i<3; i++)
            for (j = 0; j<3; j++)
                cin >> m[i][j];
    }
    MATRIX(int a)
    {
        int i,j;
        for (i = 0; i<3; i++)
            for (j = 0; j<3; j++)
                m[i][j] = a;
    }
    MATRIX operator +(MATRIX n)
    {
        MATRIX a(0);
        int i,j;
        for (i = 0; i<3; i++)
            for (j = 0; j<3; j++)
                a.m[i][j] = this->m[i][j] + n.m[i][j];
        return a;
    }
    MATRIX operator -(MATRIX n)
    {
        MATRIX a(0);
        int i,j;
        for (i = 0; i<3; i++)
            for (j = 0; j<3; j++)
                a.m[i][j] = this->m[i][j] - n.m[i][j];
        return a;
    }
    MATRIX operator *(MATRIX n)
    {
        MATRIX a(0);
        int i,j,g;
        for (i = 0; i<3; i++)
            for (j = 0; j<3; j++)
                for (g = 0; g<3; g++)
                    a.m[i][j] += this->m[i][g] * n.m[g][j];
        return a;
    }
    int opr()
    {
        return m[0][0]*m[1][1]*m[2][2]+m[0][1]*m[1][2]*m[2][0]+m[1][0]*m[2][1]*m[0][2]-m[0][2]*m[1][1]*m[2][0]-m[0][1]*m[1][0]*m[2][2]-m[0][0]*m[2][1]*m[1][2];
    }
};

int main()
{
    cout << "Dlya matrici a ";
    MATRIX a;
    cout << "Dlya matrici b ";
    MATRIX b;
    MATRIX c(0);
    int k;
    system("cls");
    while(1)
    {
        cout << "Vvedite nomer operacii:\n1.Slozheniye.\n2.Raznost'.\n3.Umnozheniye.\n0.Vihod\n";
        cin >> k;
        switch (k)
        {
            case (1):
            {
                c = a+b;
                break;
            }
            case (2):
            {
                c = a-b;
                break;
            }
            case (3):
            {
                c = a*b;
                break;
            }
            case (0):
            {
                return 0;
            }
        }
        system("cls");
        int i,j;
        for (i = 0; i<3; i++)
        {
            for (j = 0; j<3; j++)
                cout << setw(4) <<c.m[i][j];
            cout << endl;
        }
        cout << "\nOpredlitel' poluchennoy matrici raven " << c.opr() << endl << endl;
    }
    return 0;
}

