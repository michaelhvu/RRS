#include <iostream>
#include <string>
#include "robot_part.h"

using namespace std;
using std::string;

class RobotArm : public RobotPart {
    public:
        RobotArm(string name, int partNum, double weight, double cost, string description)
            : RobotPart(name, partNum, weight, cost, description) { }

};

