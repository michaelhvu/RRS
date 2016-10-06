#include <iostream>
#include "robot_head.h"
#include "robot_part.h"
#include "robot_locomotor.h"
#include "robot_torso.h"
#include "robot_battery.h"
#include "robot_arm.h"

void testArm() {
	RobotArm robotArm("Arm created", 4, 150.50, 750.50, "make robot arm");
	cout << robotArm.getName() << endl;

}

void testBattery() {
	RobotBattery robotBattery("Battery created", 5, 300, 999.99, "make robot battery");
	cout << robotBattery.getName() << endl;

}

void testHead() {
	RobotHead robotHead("Head created", 1, 120, 1234.21, "make robot head");
	cout << robotHead.getName() << endl;
}

void testLocomotor() {
	RobotLocomotor robotLocomotor("Locomotor created", 2, 200.50, 2000, "make robot locomotor");
	cout << robotLocomotor.getName() << endl;
}

/*void testModel() {

}

void testPart() {

}*/

void testTorso() {
	RobotTorso robotTorso("Torso created", 3, 350, 4300, "make robot torso");
	cout << robotTorso.getName() << endl;
}

int main() {


//	Testing the class
//                    RobotPart(name, partNum, weight, cost, description)
    int menu=1;

	while (menu!=0) {
		cout << "Test which one?\n1) Arm\n2) Battery\n3) Head\n4) Locomotor\n5) Model\n6) Part\n7) Torso\n0) Exit\n";
    	cin >> menu;
    	if (menu==1) testArm();
    	else if (menu==2) testBattery();
    	else if (menu==3) testHead();
    	else if (menu==4) testLocomotor();
    	//else if (menu==5) testModel();
    	//else if (menu==6) testPart();
    	else if (menu==7) testTorso();
	}

}
