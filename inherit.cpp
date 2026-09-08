#include <iostream>

using namespace std;
class A
{
public:
void show_A()
{
    cout<<"A"<<endl;
}
void show(int n=10)
{
    m=n;
    cout<<"A "<<m<<endl;
}
private:
    int m;
};
class B:public A
{
public:
void show()
{
    cout<<"B"<<endl;
}
};
int main()
{
    B m;
    m.show();
    m.A::show(10);
    m.show_A();
    A*a=&m;
    A*a1=new B;
    a->show(10);
    (*a1).show_A();


    return 0;
}