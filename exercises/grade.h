#include<iostream>
#include<vector>
#include<algorithm>
#include<stdexcept>

double median(std::vector<double> vec)//find the median 
{
    typedef std::vector<double>::size_type vec_typ;
    vec_typ size=vec.size();
    if(size==0)
    {
    throw std::domain_error ("median of an empty vector !");
    }
    sort(vec.begin(),vec.end());
    vec_typ mid=size/2;
    return size%2==0?(vec[mid]+vec[mid-1])/2:vec[mid];
}

double grade (double midterm,double final,double homework){
    return  0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade (double midterm,double final,const vector<double>&hw){
    if(hw.size()==0){
        throw(domain_error("empty hw"));
    }
    return grade(midterm,final,median(hw));
}

double grade(const student& s){
    return grade(s.midterm,s.final,s.homework);
}