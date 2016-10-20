#include <iostream>
#include <vector>
#include <string>
#include "view.h"
#include "order.h"

string getName() {
    return name;
}

int getCustomerNumber() {
    return customerNumber;
}

double getWallet() {
    return wallet;
}

double getRemainingWallet() {
    int currentBill, size=order.size();
    currentBill=order.getTotalPrice();
    return wallet-currentBill;
}
