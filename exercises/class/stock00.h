#ifndef STOCK00_H
#define STOCK00_H

#include <string>
#include <iostream>
class Stock {
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock::Stock() {
        company = "";
        shares = 0;
        share_val = 0;
        total_val = 0;
    }
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
};
#endif
