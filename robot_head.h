#ifndef __ROBOT_HEAD
#define __ROBOT_HEAD 2016
#include <string>
#include "robot_part.h"


using namespace std;
using std::string;

class RobotHead : public RobotPart {
    public:
        RobotHead(string name, int partNum, double weight, double cost, string description)
            : RobotPart(name, partNum, weight, cost, description) { }

};

#endif