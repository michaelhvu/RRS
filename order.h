#ifndef __ROBOT_ORDER
#define __ROBOT_ORDER 2016

#include <vector>
#include "robot_model.h"
#include "robot_head.h"
#include "robot_part.h"
#include "robot_locomotor.h"
#include "robot_torso.h"
#include "robot_battery.h"
#include "robot_arm.h"
#include "robot_part.h"
#include "customer.h"

using namespace std;

class Order {
    private:
        int orderNumber;
        double this_totalPrice = 0;                     

    public:
        Customer *this_customer;
        vector<RobotModel> robotModels;
        vector<RobotPart> robotParts;

        Order(Customer customer, int number) : this_customer(&customer), orderNumber(number) { } 
        void addRobotModel(RobotModel robotModel);
        void addRobotPart(RobotPart robotPart);
        void robotPrice();
        double totalPrice();
};

#endif