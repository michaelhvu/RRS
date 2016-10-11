#ifndef __ROBOT_LOCOMOTOR
#define __ROBOT_LOCOMOTOR 2016
#include "robot_part.h"
#include <string>

using namespace std;
using std::string;

class RobotLocomotor : public RobotPart {
    private:
        int this_maxSpeed;

    public:
        RobotLocomotor(string name, int partNum, double weight, double cost, string description, int maxSpeed)
            : RobotPart(name, partNum, weight, cost, description), this_maxSpeed(maxSpeed) { }

        int powerConsumed(int speed);
};

#endif