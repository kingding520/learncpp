#include <iostream>

void* operator new(size_t size)
{
    void*p=malloc(size);
    if(p==nullptr)
    {
        throw std::bad_alloc();
    }
    std::cerr<<"new"<<std::endl;
    return p;
}
void*operator new[](size_t size)
{
    void*p=malloc(size);
    if(p==nullptr)
    {
        throw std::bad_alloc();
    }
    std::cerr<<"new[]"<<std::endl;
    return p;
}
void operator delete(void *ptr)
{
    std::cout<<"free"<<std::endl;
    free(ptr);
}
void operator delete[](void*ptr)
{
    std::cerr<<"free[]"<<std::endl;
    free(ptr);
}
class test
{
    public:
    test(int data=1)
    {
        n=data;
        std::cout<<"test()"<<std::endl;
    }
    ~test()
    {
        std::cout<<"delete test "<<std::endl;
    }
    private:
    int n;
};
int main()
{
    test*p=new test[5];
    int*p1=new int[5];
    delete[] p;
    delete[]p1;
    return 0;
}