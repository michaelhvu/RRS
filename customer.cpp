
#include "customer.h"

string Customer::getName() {
    return name;
}

int Customer::getCustomerNumber() {
    return customerNumber;
}

double Customer::getWallet() {
    return wallet;
}

double Customer::getRemainingWallet(double money) {
    wallet = wallet - money;
    return wallet;
}
