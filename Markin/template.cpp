#include <iostream>

using namespace std;

template <typename A>

void printArr(const A *a, int b)
{
    for (int i = 0; i<b; i++)
        cout << a[i] << ' ';
}

template <typename A>

void scanArr(A *a, int b)
{
    for (int i = 0; i<b; i++)
        cin >> a[i];
}

template <typename A>

void sortArr(A *a, int b)
{
    int i,j;
    for (i = 0; i<b; i++)
        for (j = 0; j<b; j++)
        {
            if (a[j] > a[i]) swap(a[i],a[j]);
        }
}

int main()
{
    int n,a;
    cout << "Kakie elementi vi budete vvodit'?\n1.Celie\n2.Veschestvenniye\n3.Simvoli\n";
    cin >> a;
    if (a<1 || a>3) cout << "Neobhodimo vibrat' chislo iz spiska!";
    else switch (a)
    {
    case 1:
        {

            cout << "Vvedite kolichestvo elementov v massive: ";
            cin >> n;
            int a[n];
            cout << "Vvedite massiv:\n";
            scanArr(a,n);
            sortArr(a,n);
            cout << "Vot vash otsortirovanniy massiv:\n";
            printArr(a,n);
            break;
        }
    case 2:
        {
            cout << "Vvedite kolichestvo elementov v massive: ";
            cin >> n;
            double a[n];
            cout << "Vvedite massiv:\n";
            scanArr(a,n);
            sortArr(a,n);
            cout << "Vot vash otsortirovanniy massiv:\n";
            printArr(a,n);
            break;
        }
    case 3:
        {
            cout << "Vvedite kolichestvo elementov v massive: ";
            cin >> n;
            char a[n];
            cout << "Vvedite massiv:\n";
            scanArr(a,n);
            sortArr(a,n);
            cout << "Vot vash otsortirovanniy massiv:\n";
            printArr(a,n);
            break;
        }
    }
    return 0;
}
