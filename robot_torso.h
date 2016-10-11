#include <iostream>
#include <string>
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
        RobotArm *robot_arm;
        RobotHead *robot_head;
        RobotBattery *robot_battery;
        RobotLocomotor *robot_locomotor;
    

    public:
        RobotTorso(string name, int partNum, double weight, double cost, string description)
            : RobotPart(name, partNum, weight, cost, description) { }

};
