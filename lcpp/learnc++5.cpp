#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

struct Stu_info{
    string name;
    double grade;
};
bool fgrade(Stu_info& s){
    return s.grade<60.0;
}

istream& read(istream& in,Stu_info& s){
    cin>>s.name>>s.grade;
    return in;
}

vector<Stu_info> extract_fails_1(vector<Stu_info>& students){    
    typedef vector<double>::size_type vec_sz;
    vector<Stu_info> fail;
    vec_sz i=0;
    students.clear();
    while(i!=students.size()){
        if(fgrade(students[i])){
            fail.push_back(students[i]);
            students.erase(students.begin()+i);//delete students[i]
        }else
        ++i;
    }
    return fail;
}

vector<Stu_info> extract_fails_2(vector<Stu_info>& students){    
    typedef vector<double>::size_type vec_sz;
    vector<Stu_info> fail;
    vector<Stu_info>::iterator iter=students.begin();
    students.clear();
    while(iter!=students.end()){
        if(fgrade(*iter)){
            fail.push_back(*iter);
            iter=students.erase(iter);//delete students[i]
        }else
        ++iter;
    }
    return fail;
}

int main()
{
    vector<Stu_info> s1,s2;
    Stu_info student;
    vector<Stu_info> f1,f2;
    while(read(cin,student)){
         s1.push_back(student);
    }
    f1=extract_fails_1(s1);
    while(read(cin,student)){
        s2.push_back(student);
    } 
    f2=extract_fails_2(s2);
    return 0;
}