#include <bits/stdc++.h>

using namespace std;

class Soldier
{
public:
    int maxHP,HP,damage,range;
    Soldier()
    {
        maxHP = 0;
        HP = 0;
        damage = 0;
        range = 0;
    }
    virtual void print()
    {
        cout << "This is soldier. He has:\n" << HP << '/' << maxHP << " HP\n" << damage << " dmg\n" << range << " range\n\n";
    }
};

class Swordman: public Soldier
{
public:
    Swordman()
    {
        maxHP = rand()%15+35;
        HP = maxHP;
        damage = rand()%5+5;
        range = 1;
    }
    void print()
    {
        cout << "This is swordman. He has:\n" << HP << '/' << maxHP << " HP\n" << damage << " dmg\n" << range << " range\n\n";
    }
};

class Archer: public Soldier
{
public:
    Archer()
    {
        maxHP = rand()%10+20;
        HP = maxHP;
        damage = rand()%5+10;
        range = rand()%5+45;
    }
    void print()
    {
        cout << "This is archer. He has:\n" << HP << '/' << maxHP << " HP\n" << damage << " dmg\n" << range << " range\n\n";
    }
};

template <class T>
class Squad
{
public:
    int size;
    Squad *next;
    Squad *top;
    T value;
    Squad()
    {
        size = 0;
        next = 0;
        top = 0;
    }
    Squad(T a)
    {
        size = 1;
        next = 0;
        value = a;
        /*top->value = a;
        top->size = 1;
        top->next = 0;*/
    }
    void push(T a)
    {
        Squad *p = new Squad(a);
        p->next = top;
        top = p;
        size++;
    }
    void pop()
    {
        top = top->next;
        size--;
    }
    void print()
    {
        Squad *p = top;
        while(p)
        {
            p->value.print();
            p = p->next;
        }
    }
};

template <typename M>
class ListM
{
public:
    int size;
    ListM *next;
    ListM *top;
    M value;
    ListM()
    {
        size = 0;
        next = 0;
        top = 0;
    }
    ListM(M a)
    {
        size = 1;
        next = 0;
        value = a;
        /*top->value = a;
        top->size = 1;
        top->next = 0;*/
    }
    void push(M a)
    {
        ListM *p = new ListM(a);
        p->next = top;
        top = p;
        size++;
    }
    void pop()
    {
        top = top->next;
        size--;
    }
    void print()
    {
        ListM *p = top;
        while(p)
        {
            cout << p->value;
            p = p->next;
        }
    }
    int lcount()
    {
        int k = 0;
        ListM *p = top;
        while(p)
        {
            k += p->value;
            p = p->next;
        }
        return k;
    }
};

int main()
{
    ListM <int>l;
    int n,i,a;
    cout << "Hello, comander! How many squads would you like to have?\n";
    cin >> n;
    cout << "Great! How many soldiers will be in your squads?\n\n";
    for (i = 0; i<n; i++)
    {
        cout << "In squad number " << i+1 << ": ";
        cin >> a;
        cout << endl;
        l.push(a);
        cout << "What kind of soldiers contain this squad?\n1.Swordman\n2.Archer\n\n";
        int k;srand(time(0));
        cin >> k;
        switch(k)
        {
        case 1:
            {
                Squad <Swordman> s;
                for (int j = 0; j<a; j++)
                {
                    Swordman p;
                    s.push(p);
                }
                cout << "\nYour squad number " << i+1 << ":\n\n";
                s.print();
                break;
            }
        case 2:
            {
                Squad <Archer> s;
                for (int j = 0; j<a; j++)
                {
                    Archer p;
                    s.push(p);
                }
                cout << "\nYour squad number " << i+1 << ":\n\n";
                s.print();
                break;
            }
        }
    }
    cout << "Size of your army: " << l.lcount();
    return 0;
}
