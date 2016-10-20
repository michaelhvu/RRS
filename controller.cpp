#include <iostream>
#include <vector>
#include <string>
#include "robot_model.h"
#include "robot_head.h"
#include "robot_part.h"
#include "robot_locomotor.h"
#include "robot_torso.h"
#include "robot_battery.h"
#include "robot_arm.h"
#include "view.h"
#include "order.h"
#include "customer.h"


int main() {

	vector<RobotModel> robots;
	vector<RobotHead> heads;
	vector<RobotArm> arms;
	vector<RobotBattery> batteries;
	vector<RobotTorso> torsos;
	vector<RobotLocomotor> locomotors;	
	vector<int> prices;
	vector<string> names;

	Customer Doug("Douglas", 1432, 1000000);
	Order order(Doug,35813);


	heads.push_back(RobotHead("Doug", 1100, 25, 110, "Doug's head"));
	heads.push_back(RobotHead("Michael", 1101, 50, 510, "Michael's head"));
	heads.push_back(RobotHead("Grant", 1102, 10, 50, "Grant's head"));
	heads.push_back(RobotHead("Goku", 1103, 11, 75, "Head that looks like Goku"));
	heads.push_back(RobotHead("Ang", 1104, 17, 120, "Head that looks like Ang"));

	arms.push_back(RobotArm("Model A", 2201, 10, 20, "Useless arm"));
	arms.push_back(RobotArm("Model B", 2202, 12, 35, "Swinging arm"));
	arms.push_back(RobotArm("Model R", 2215, 13, 40, "Karate Chop arm"));
	arms.push_back(RobotArm("Model X", 2224, 14, 50, "Can pick up cups"));
	arms.push_back(RobotArm("Model Z", 2226, 15, 1000, "Can pick up any object"));

	batteries.push_back(RobotBattery("Old", 3300, 2, 10, "Short lasting batteries", 10, 30));
	batteries.push_back(RobotBattery("Dura", 3302, 2, 5, "Long lasting batteries", 5, 30));
	batteries.push_back(RobotBattery("Rechargable", 3301, 4, 35, "Rechargable batteries", 15, 25));

	locomotors.push_back(RobotLocomotor("V2", 4400, 275, 200, "Slow", 20));
	locomotors.push_back(RobotLocomotor("V4", 4401, 350, 300, "Medium", 60));
	locomotors.push_back(RobotLocomotor("V8", 4402, 500, 400, "Fast", 140));

	torsos.push_back(RobotTorso("Ver. 1", 5500, 300, 5000, "Box Shaped Torso", 2));
	torsos.push_back(RobotTorso("Ver. 2", 5502, 300, 8000, "Gold Plated Torso", 2));
	torsos.push_back(RobotTorso("Ver. 3", 5501, 300, 5000, "Green Torso", 2));

	robots.push_back(RobotModel("The Hulking Monster", 7001));
	robots[0].addPart(heads[2]);
	robots[0].addPart(arms[2]);
	robots[0].addPart(batteries[2]);
	robots[0].addPart(locomotors[1]);
	robots[0].addPart(torsos[1]);
	robots.push_back(RobotModel("Very Boring Robot", 7002));
	robots[1].addPart(heads[0]);
	robots[1].addPart(arms[0]);
	robots[1].addPart(batteries[0]);
	robots[1].addPart(locomotors[0]);
	robots[1].addPart(torsos[0]);

	int choice;
	bool shopOpen = true;

	while (shopOpen != false)
	{
		cout << "\nMAIN MENU" << endl << "---------" << endl;
		cout << "1 - Create\n";
		cout << "2 - Report\n";
		cout << "3 - Quit\n";
		cout << "Your Choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Create Robot\n";
			createMenu(heads, arms, batteries, torsos, locomotors, robots, order);
			break;
		case 2:
			cout << "Report of Robot\n";
			createReport(heads, arms, batteries, torsos, locomotors, robots, order);
			break;
		case 3:
			cout << "End of Program.\n";
			shopOpen = false;
			break;
			default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			cin >> choice;
			break;
		}
	}
	return 0;
}
