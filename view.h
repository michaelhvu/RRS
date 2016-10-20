#include <iostream>
#include <vector>
#include <string>
#include "robot_model.h"
#include "robot_head.h"
#include "robot_part.h"
#include "robot_locomotor.h"
#include "robot_torso.h"
#include "robot_battery.h"
#include "robot_arm.h"
#include "robot_model.h"
#include "order.h"


void robotComponent(vector<RobotHead> &head, vector<RobotArm> &arm, vector<RobotBattery> &battery, vector<RobotTorso> &torso, vector<RobotLocomotor> &locomotor);
void makeOrder(vector<RobotHead> &head, vector<RobotArm> &arm, vector<RobotBattery> &battery, vector<RobotTorso> &torso, vector<RobotLocomotor> &locomotor, vector<RobotModel> &Model, Order &order);
void viewOrder(Order &order);
void createMenu(vector<RobotHead> &head, vector<RobotArm> &arm, vector<RobotBattery> &battery, vector<RobotTorso> &torso, vector<RobotLocomotor> &locomotor, vector<RobotModel> &Model, Order &order);
void createReport(vector<RobotHead> &head, vector<RobotArm> &arm, vector<RobotBattery> &battery, vector<RobotTorso> &torso, vector<RobotLocomotor> &locomotor, vector<RobotModel> &Model, Order &order);
