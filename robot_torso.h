#include <iostream>
#include <string>
#include <vector>
#include <new>
#include "robot_part.h"
#include "robot_battery.h"
#include "robot_head.h"
#include "robot_locomotor.h"
#include "robot_arm.h"

using namespace std;
using std::string;

class RobotTorso : public RobotPart {

    private:
    
        int batteryCompartments;
        int current_arms = 0;
    

    public:
        vector<RobotArm> this_robot_arm;
        RobotHead *this_robot_head;
        RobotBattery *this_robot_battery;
        RobotLocomotor *this_robot_locomotor;

        void addArm(string name, int partNum, double weight, double cost, string descrption) {

            if (current_arms < 2) {
                this_robot_arm.push_back(RobotArm(name, partNum, weight, cost, descrption));
            }

        }

        RobotTorso(string name, int partNum, double weight, double cost, string description)
            : RobotPart(name, partNum, weight, cost, description) { }





};

