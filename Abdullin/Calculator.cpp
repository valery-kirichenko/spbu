#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout<<"Vvedite 2 peremennih ";
    cin>>a;
    cin>>b;
    cout<<"Vvedite operaciu ";
    char c;
    cin>>c;
    if (c=='+') cout<<(a+b);
        else if (c=='-') cout<<(a-b);
            else if (c=='*') cout<<(a*b);
                else if (c=='/') cout<<(a/b);
}

