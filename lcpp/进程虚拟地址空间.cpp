#include <iostream>
#include <cstring>
using namespace std;
bool compare(int a, int b)
{
    return a > b;
}
bool compare(double a, double b)
{
    return a > b;
}
bool compare(const char* a, const char* b)
{
    return strcmp(a, b)>0;
}
int main()
{
    char s[100];
    int* n = new(s)int [10];
    compare(2, 1);
    compare(2.0, 1.0);
    compare("aaa","aa");
    delete [] n;
    return 0;
}