#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

char* toUpper(const char* s)
{
	int n = strlen(s);
	char* z = new char[n+1];
	for (int i = 0; i <n ; ++i)
	{
		z[i] = toupper(s[i]);
	}
	z[n] = '\0';
	cout<<sizeof(z)<<endl;//sizeof(z)是指针的大小
	return z;
}
template<typename T>
T Max(T arr[], int n)
{
	T max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max <=arr[i]);
		max = arr[i];
	}
	return max;
}
template<>
const char* Max(const char* arr[], int n)
{
	const char*s = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (strlen(s) <= strlen(arr[i]))
			s = arr[i];
	}
	return s;
}
int main()
{
	char* z = toUpper("hello");
	cout << z<<endl;
	delete[] z;//释放防止泄露

	int arr[5] = { 1,2,3,4,5 };
	cout<<Max(arr, 5)<<endl;

	const char* st[5] = { "Nangjing","Peiking","Hankou","Hangchou","Canton" };
	cout << Max(st, 5) << endl;
	return 0;
}