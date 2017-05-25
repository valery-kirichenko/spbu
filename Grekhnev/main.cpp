#include <iostream>

using namespace std;

class SEG
    {
        public:
        int l,k;

        SEG(int, int);
        void set(int,int);
        ~SEG();
    };

     SEG::SEG(int a, int b)
        {
            this->l=2*a; this->k=2*b;
            cout<<"rabota cons\n";
            cout<<l<<" "<<k<<"\n";
        };

    SEG::~SEG()
    {
       this->l=0;
       this->k=0;
       cout<<"rabota dis\n";
       cout<<this->l<<" "<<this->k;
    };


int main()
{
    int x,y;
    cout<<"a,b =";
    cin>>x>>y;
    SEG seg(x,y);
    return 0;
}
