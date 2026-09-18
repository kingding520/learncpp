#include <iostream>
using namespace std;
class Animal {
public:
    virtual void makeSound() {
        cout << "The animal makes a sound.\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() override//重写虚函数覆盖
    {
        cout << "Meow!\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() override{
        cout << "Woof!\n";
    }
};

void makesound(Animal & a){
    a.makeSound();//根据a的类型调用子类的函数
}

template<typename T>
void printMemberFnPtr() {
    void (T::*dvptr)() = &T::makeSound;
    cout << "member function pointer = " << reinterpret_cast<void*>(dvptr) << '\n';
}

int main()
{
    Cat c;
    Dog d;
    makesound(c);
    makesound(d);
    void (Animal::*p)() = &Animal::makeSound;
    (c.*p)();   // 输出 Meow!（因为是虚函数，走动态绑定）
    void*vptr=nullptr;
    cout<<memcpy(&vptr,&c,sizeof(void*))<<endl;
    return 0;
}