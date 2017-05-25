#include <iostream>

using namespace std;

int main()
{
    int a,b;
    char c;
    cout<<"Vvedite 2 peremennyh\n";
    cin>>a>>b;
    cout<<"Vvedite operatsiyu: +, -, *, /\n";
    cin>>c;
    if (c=='+') cout<<a+b;
        else if (c=='-') cout<<a-b;
            else if (c=='*') cout<<a*b;
                else if (c=='/') cout<<a/b;
}