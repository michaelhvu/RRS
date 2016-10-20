#ifndef __ROBOT_CUSTOMER
#define __ROBOT_CUSTOMER 2016

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using std::string;

class Customer {
    private:
        string name;
        int customerNumber;
        double wallet;

    public:
        Customer(string custname, int custNumber, double custwallet)
            : name(custname), customerNumber(custNumber), wallet(custwallet) { }
        string getName();
        int getCustomerNumber();
        double getWallet();
        double getRemainingWallet(double money);
        
};

#endif