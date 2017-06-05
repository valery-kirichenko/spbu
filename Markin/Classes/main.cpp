#include <iostream>

using namespace std;

class SEG{           // объ€вление класса
public:                 // уровень доступа
    int a,b;
    SEG()
    {
        cout << "Zapuschen constructor. Vvedite a i b: ";
        cin >> this->a >> this->b;
        cout << "Vot oni: " << this->a << ' ' << this->b;
        this->a *= 2;
        this->b *= 2;
        cout << "\nA vot oni umnozenniye na dva: " << this->a << ' ' << this->b << endl;
    }
    ~SEG()
    {
        cout << "Zapuschen destructor. Peremenniye ochischeni. Ih znacheniya: ";
        this->a = 0;
        this->b = 0;
        cout << a << ' ' << b;
    }
    void set(int,int,int,int);       // объ€вление метода
};

int main()
{
    SEG seg;
    return 0;
}

