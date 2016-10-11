#include <iostream>
#include <string>
#include <vector>
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
        vector<RobotArm> this_robot_arm;
        RobotHead *this_robot_head;
        RobotBattery *this_robot_battery;
        RobotLocomotor *this_robot_locomotor;
    

    public:
        RobotTorso(string name, int partNum, double weight, double cost, string description)
            : RobotPart(name, partNum, weight, cost, description) { }

        void addArm(string name, int partNum, double weight, double cost, string descrption);

        string getArm();

};
