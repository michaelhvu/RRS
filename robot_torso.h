#include <iostream>
#include <string>
#include "robot_part.h"

using namespace std;
using std::string;

class RobotTorso : public RobotPart {
    public:
        RobotTorso(string name, int partNum, double weight, double cost, string description)
            : RobotPart(name, partNum, weight, cost, description) { }

};
