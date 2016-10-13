#include <iostream>
#include <string>
#include "robot_model.h"
#include "robot_part.h"


string RobotModel::getName() {
    return this_name;
}

int RobotModel::getModelNumber() {
    return this_modelNumber;
}

double RobotModel::getPrice() {
    return this_price;
}

/*double RobotModel::componentCost() {

}*/

double RobotModel::maxSpeed() {
    
}

void RobotModel::addPart(RobotPart piece) {
    this_robotParts.push_back(piece);
    this_price=this_price+piece.getCost();
}