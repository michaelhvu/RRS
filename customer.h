#ifndef __ROBOT_MODEL
#define __ROBOT_MODEL 2016

#include <iostream>
#include <vector>
#include <string>
#include "view.h"
#include "order.h"

using namespace std;
using std::string;

class Customer {
    private:
        string name;
        int customerNumber;
        double wallet;
        vector<Order> order;

    public:
        Customer(string custname, int custNumber, double custwallet)
            : name(custname), customerNumber(custNumber), wallet(custwallet) { }
        string getName();
        int getCustomerNumber();
        double getWallet();
        double getRemainingWallet();
        
};

#endif