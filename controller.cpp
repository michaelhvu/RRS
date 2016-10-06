#include <iostream>
#include "robot_head.h"
#include "robot_part.h"
#include "robot_locomotor.h"
#include "robot_torso.h"
#include "robot_battery.h"
#include "robot_arm.h"


int main() {


//	Testing the class
//                    RobotPart(name, partNum, weight, cost, description)

	RobotHead robotHead("Head created", 1, 120, 1234.21, "make robot head");
	cout << robotHead.getName() << endl;
	
	RobotLocomotor robotLocomotor("Locomotor created", 2, 200.50, 2000, "make robot locomotor");
	cout << robotLocomotor.getName() << endl;

	RobotTorso robotTorso("Torso created", 3, 350, 4300, "make robot torso");
	cout << robotTorso.getName() << endl;

	RobotArm robotArm("Arm created", 4, 150.50, 750.50, "make robot arm");
	cout << robotArm.getName() << endl;

	RobotBattery robotBattery("Battery created", 5, 300, 999.99, "make robot battery");
	cout << robotBattery.getName() << endl;

}

