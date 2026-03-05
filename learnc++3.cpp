#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<stdexcept>

using namespace std;
double median(vector<double> vec)//find the median
{
    typedef vector<double>::size_type vec_typ;
    vec_typ size=vec.size();
    if(size==0)
    {
    throw domain_error ("median of an empty vector !");
    }
    sort(vec.begin(),vec.end());
    vec_typ mid=size/2;
    return size%2==0?(vec[mid]+vec[mid-1])/2:vec[mid];
}
istream& read_hw(istream& in, vector<double>& hw)//read homework
{
    if(in)
    {
        double x;
        hw.clear();//clear the formal vector
        while(in>>x){
            hw.push_back(x);
        }
        in.clear();//clear stream for available for the next
    }
    return in;
}
int main()
{
    int v=10;
    vector<double> vec;
    vector<double> homework;
    read_hw(cin,homework);
    double hw=median(homework);
    try{
        int final=90,midscore=90;
        streamsize prec=cout.precision();
        cout << setprecision(3) << 0.2 * hw + 0.4 * final + 0.4 * midscore << setprecision(prec) << endl;
    }catch(domain_error){
        cout<<"error"<<endl;
        return 1;
    }
    return 0;
}