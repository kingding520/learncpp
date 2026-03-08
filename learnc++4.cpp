#include"grade.h"
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<iomanip>

using namespace std;

struct student{
    string name;
    double midterm,final;
    vector <double>homework;
};

bool compare(const student& x,const student& y)
{
    return x.name<y.name;
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

istream& read(istream& in,student& s)
{
    in>>s.name>>s.final>>s.midterm;
    read_hw(in,s.homework);
    return in;
}

int main()
{
<<<<<<< HEAD
    typedef struct student s;
    vector<student> students;
    s record;
    string::size_type maxlen=0;
    while(read(cin,record)){
        maxlen=max(maxlen,record.name.size());
        students.push_back(record);
    }
    sort(students.begin(),students.end(),compare);
    for(vector<student>::size_type i=0;i!=students.size();++i)
    {
        cout<<students[i].name
            <<string(maxlen+1-students[i].name.size(),' ');
    }

=======
    vector<student> students;
    student record;
    string::size_type maxlen =0;
    while(read(cin,record)){
        cout<<"name midterm final homework: "<<endl;
        maxlen=max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(),students.end(),compare);

    cout<<endl<<"grade"<<endl;
    for(vector<student>::size_type i=0;i!=students.size();++i)
    {
        cout<<students[i].name
            <<string(maxlen+1-students[i].name.size(), ' ');
        try{
            double final_grade=grade(students[i]);
            streamsize prec =cout.precision();
            cout<<setprecision(3)<<final_grade
                <<setprecision(prec)<<endl;    
        }catch (domain_error e){
            cout<<e.what()<<endl;
        }
    }
>>>>>>> 32a8d41 (3/8/2026)
    return 0;
}