#include "Vector.h"
#include <cmath>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
const double Rad_to_deg=45.0/atan(1.0);

void Vector::set_mag()
{
    mag=sqrt(x*x+y*y);
}
void Vector::set_ang()
{
    if(x==0.0&&y==0.0)
        ang=0.0;
    else
        ang=atan2(y,x);
}

void Vector::set_x()
{
    x=mag*cos(ang);
}
void Vector::set_y()
{
    y=mag*sin(ang);
}

Vector::Vector()
{
    x=y=mag=ang=0.0;
    mode=RECT;
}
Vector::Vector(double n1,double n2,Mode form)
{
    mode=form;
    if(mode==RECT)
    {
        x=n1;
        y=n2;
        set_ang();
        set_mag();
    }
    else if(mode==POL)
    {
        mag=n1;
        ang=n2;
        set_x();
        set_y();
    }
    else
    {
        cout<<"error:incorrect vector"<<std::endl;
        x=y=mag=ang=0.0;
        mode=RECT;
    }
}

void Vector::reset(double n1,double n2,Mode form)
{
        mode=form;
    if(mode==RECT)
    {
        x=n1;
        y=n2;
        set_ang();
        set_mag();
    }
    else if(mode==POL)
    {
        mag=n1;
        ang=n2;
        set_x();
        set_y();
    }
    else
    {
        cout<<"error:incorrect vector"<<std::endl;
        x=y=mag=ang=0.0;
        mode=RECT;
    }
}
Vector::~Vector(){}
void Vector::polar_mode(){mode=POL;}
void Vector::rect_mode(){mode=RECT;}

Vector Vector::operator+(const Vector & b)const
{
    return Vector(x+b.x,y+b.y);
}
Vector Vector::operator-(const Vector & b)const
{
    return Vector(x-b.x,y-b.y);
}
Vector Vector::operator-()const
{
    return Vector(-x,-y);
}
Vector Vector::operator*(double n)const
{
    return Vector(x*n,y*n);
}

Vector operator*(double n,const Vector & a)
{
    return a*n;
}
std::ostream & operator<<(std::ostream & os,const Vector & v)
{
    if(v.mode==Vector::RECT)
        os<<"("<<v.x<<","<<v.y<<")"<<std::endl;
    else if(v.mode==Vector::POL)
    {
        os<<"("<<v.mag<<","<<v.ang*Rad_to_deg<<")"<<std::endl;
    }
    else
        os<<"invalid vector"<<std::endl;
    return os;
}
};
