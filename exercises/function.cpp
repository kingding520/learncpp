#include <iostream>
using namespace std;
struct Job{
	char name[50];
	double salary;
	int floor;
};
template <typename T>
auto h(T a, T b) ->decltype(a + b)
{
	return a + b;
}

template <typename AnyType>
void Swap(AnyType& a, AnyType& b)
{
	AnyType temp = b;
	b = a;
	a = temp;
}
template <>void Swap<Job>(Job& j1, Job& j2)
{
	double temp_salary = j1.salary;
	j1.salary = j2.salary;
	j2.salary = temp_salary;

	int temp_floor = j1.floor;
	j1.floor = j2.floor;
	j2.floor = temp_floor;
}
inline double refcube(const double& ra)
{
	return ra * ra * ra;
}
const char* f(const char* st, int n = 1)
{
	char* p = new char[n+1];
	for (int i = 0; i < n && st[i]; ++i)
	{
		p[i] = st[i];
	}
	p[n] = '\0';
	return p;
}
double& copy(double& ra)
{
	return ra;
}
int main()
{
	double side = 3.0;
	double* pd = &side;
	double& rd = side;
	long edge = 5L;
	double lens[4] = { 2.0,5.0,10.0,12.0 };
	double c1, c2, c3, c4, c5, c6, c7,v1;
	c1 = refcube(side);
	c2 = refcube(lens[2]);
	c3 = refcube(rd);
	c4 = refcube(*pd);
	c5 = refcube(edge);
	
	c6 = refcube(7.0);
	c7 = refcube(side + 10.0);

	v1 = refcube(copy(side));

	const char* s = f("abc");
	delete[] s;

	Job p1 = { "man",500,1 }, p2 = { "woman",450,1 };
	Swap(p1, p2);
	Swap<Job>(p1, p2);

	double a = 1.0, b = 1.5;
	cout << h(a,b);

	return 0;
}