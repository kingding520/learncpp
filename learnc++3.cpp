#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;
int median(vector<double> vec)
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
int main()
{
    int v=10;
    vector<double> vec;
    srand(time(0));
    for(int i=0;i!=10;++i)
    {
        vec.push_back(rand()%100);
    }
    int mid=median(vec);
}