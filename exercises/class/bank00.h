#ifndef BANK00_H
#define BANK00_H
#include <string>
#include <iostream>
class bank{

private:
    int number_;
    std::string const name_;
    double balance_;
    
public:
    bank():number_(0),name_("NULL"),balance_(0){};
    bank(const std::string name,int number,double balance):
    name_(name),
    number_(number),
    balance_(balance)
    {std::cout<<"succeed!"<<std::endl;};
    ~bank();
    double deposit(int number, const std::string &name);
    double withdraw(int number, const std::string &name);
    double get_balance(const std::string &name);
    void display_info(const std::string &name);
};

#endif