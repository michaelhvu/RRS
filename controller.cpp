#include <iostream>
#include "robot_head.h"
#include "robot_part.h"

int main() {


//	Testing the class

	RobotPart robotHead("Doug", 123553, 123.52, 1234.21, "Dougs head");
	cout << robotHead.getName() << endl;

}


