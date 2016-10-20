#ifndef __ROBOT_ORDER
#define __ORDER 2016

#include <vector>
#include "robot_model.h"
#include "robot_head.h"
#include "robot_part.h"
#include "robot_locomotor.h"
#include "robot_torso.h"
#include "robot_battery.h"
#include "robot_arm.h"
#include "robot_part.h"


class Order {
    private:
        int orderNumber;
//      vector<Customer> customers;
        double this_totalPrice = 0;                     

    public:
        vector<RobotModel> robotModels;
        vector<RobotPart> robotParts;

        void addRobotModel(RobotModel robotModel);
        void addRobotPart(RobotPart robotPart);
        void robotPrice();
        double totalPrice();
}

#endif