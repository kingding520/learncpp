#include <iostream>
#include "stock00.h"

void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative." << std::endl;
        std::cout << company << " shares set to 0.\n";
        shares = 0;
        share_val = pr;
        set_tot();
    }
    else
    {
        shares = n;
        share_val = pr;
        set_tot();
    }
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative." << std::endl;
    }
    else
    {
        shares += num;  // 应该是增加，而不是赋值
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative." << std::endl;
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have!" << std::endl;
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::endl;
    cout << "Company: " << company << endl;
    cout << "Shares: " << shares << endl;
    cout << "Share Price: $" << share_val << endl;
    cout << "Total Worth: $" << total_val << "\n";
}