#include <string>
#include <iostream>
#include "bank00.h"

    bank::bank(){}
    bank::bank(const std::string name,int number,double balance){}
    bank::~bank(){
        std::cout<<"bye "<<name_<<std::endl;
    }
    double bank::deposit(int number, const std::string  &name){}
    double bank::withdraw(int number, const std::string  &name){}
    double bank::get_balance(const std::string  &name){}
    void bank::display_info(const std::string  &name){}