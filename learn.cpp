#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
void name_present()//名字带框
{
	cout << "your naem: ";
	string name;
	cin >> name;
	const string greeting = "Hello, " + name + "!";
	const int pad = 1;
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 3;
	cout << endl;
	for (int r = 0; r != rows; ++r)
	{
		string::size_type c = 0;
		while(c!=cols){
			if (r == pad + 1 && c == pad + 1)
			{
				cout << greeting;
				c += greeting.size();
			}
			else
			{
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
}
void triangle_1(int n)//靠左三角形
{
	cout << endl;
	for(int r=1;r<=n;r++)
	{
		int c = 0;
		while (c < 2 * r- 1)
		{
			cout << "*";
			++c;
		}
		cout << endl;
	}
}
void triangle_2(int n)//靠右
{
	cout << endl;
	for (int r = 1; r <= n; ++r)
	{
		for (int j = 1; j <= 2*(n-r); ++j)
		{
			cout << " ";
		}
		for (int j = 1; j <= 2 * r - 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void triangle_3(int n)//等腰
{
	for (int r = 1; r <= n; r++)
	{
		for (int j = 1; j <= n - r; ++j)
		{
			cout << " ";
		}

		for (int j = 1; j <= 2 * r - 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
}
int main()
{
	name_present();
	int n;
	cin >> n;
	triangle_1(n);
	triangle_2(n);
	triangle_3(n);
	return 0;
}

