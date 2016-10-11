#include "robot_torso.h"


void RobotTorso::addArm(string name, int partNum, double weight, double cost, string descrption) {
    if (current_arms < 2) {
        this_robot_arm.push_back(RobotArm(name, partNum, weight, cost, descrption));
    }

}
