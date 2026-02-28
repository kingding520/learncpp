#include <iostream>
#include <string>
#include <ios>
#include<iomanip>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
	//choose average value
	cout << "yourname:";
	string name;
	cin >> name;
	cout << "hello, " + name + "!";
	double midterm, final;
	cout << "your miderm and final:" << endl;
	cin >> midterm >> final;

	int count = 0;
	double sum = 0;
	double x;//homework grade
	cout << "your homework:" << endl;
	while (cin >> x) {
		++count;
		sum += x;
	}
	if (count == 0)
	{
		cout << "error";
	}
	cin.clear();
	streamsize prec = cout.precision();
	cout << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * sum / count << setprecision(prec) << endl;


	//use vector and choose the midian as homeworkgrade
	typedef vector<double>::size_type vec_sz;
	vector<double> homework1;
	double x1;
	cout << "your homework:" << endl;
	while (cin >> x1) {
		homework1.push_back(x1);
	}
	sort(homework1.begin(), homework1.end());
	vec_sz count1 = homework1.size();
	if (count1 == 0)
	{
		cout << "error";
	}
	double midscore;
	vec_sz mid = count1 / 2;
	count1 % 2 == 0 ? midscore = (homework1[mid] + homework1[ mid-1]) / 2 :midscore= homework1[mid];
	cout << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * midscore << setprecision(prec) << endl;

	return 0;
}
