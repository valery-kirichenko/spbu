#include <bits\stdc++.h>

using namespace std;

int Return5()
{
    return 5;
}

int main()
{
    cout << "Vvedite <chislo>,<probel>,<operaciya>,<chislo>. Dostupniye operacii: +,-,*,/,%" << endl;
    int a,b;
    cin >> a;
    char c;
    cin >> c;
    cin >> b;
    if (c == '+')
        cout << "= " << a+b;
    else if (c == '-')
        cout << "= " << a-b;
    else if (c == '*')
        cout << "= " << a*b;
    else if (c == '/')
        cout << "= " << a/b;
    else if (c == '%')
        cout << "= " << a%b;
    return 0;
}
