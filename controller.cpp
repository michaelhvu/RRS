#include <iostream>
#include <vector>
#include "robot_model.h"
#include "robot_head.h"
#include "robot_part.h"
#include "robot_locomotor.h"
#include "robot_torso.h"
#include "robot_battery.h"
#include "robot_arm.h"


void robotComponent(vector<RobotHead> head, vector<RobotArm> arm, vector<RobotBattery> battery, vector<RobotTorso> torso, vector<RobotLocomotor> locomotor) {

	int i;
	cout << endl;
	if (head.size() != 0) {
		cout << "Head" << endl << "------" << endl;
		cout << "Name\tPart #\tWeight\tCost\tDescription" << endl;
		cout << "------------------------------------------------------" << endl;
		for (i = 0; i < head.size(); i++) {
			cout << head[i].getName() << "\t" << head[i].getPartNumber() << "\t" << head[i].getWeight() << "\t" << head[i].getCost() << "\t" << head[i].getDescription() << endl;
		}
	}

	if (arm.size() != 0) {
		cout << endl << "Arm" << endl << "------" << endl;
		cout << "Name\tPart #\tWeight\tCost\tDescription" << endl;
		cout << "------------------------------------------------------" << endl;
		for (i = 0; i < arm.size(); i++) {
			cout << arm[i].getName() << "\t" << arm[i].getPartNumber() << "\t" << arm[i].getWeight() << "\t" << arm[i].getCost() << "\t" << arm[i].getDescription() << endl;
		}
	}
	
	if (battery.size() != 0) {
		cout << endl << "Battery" << endl << "------" << endl;
		cout << "Name\tPart #\tWeight\tCost\tEnergy\tMax Power\tDescription" << endl;
		cout << "------------------------------------------------------" << endl;
		for (i = 0; i < arm.size(); i++) {
			cout << battery[i].getName() << "\t" << battery[i].getPartNumber() << "\t" << battery[i].getWeight() << "\t" << battery[i].getCost() << "\t" << battery[i].getEnergy() << "\t" << battery[i].getMaxPower() << "\t" << battery[i].getDescription() << endl;
		}
	}

	if (torso.size() != 0) {
		cout << endl << "Torso" << endl << "------" << endl;
		cout << "Name\tPart #\tWeight\tCost\t\tBattery Compartments\tDescription" << endl;
		cout << "------------------------------------------------------" << endl;
		for (i = 0; i < arm.size(); i++) {
			cout << torso[i].getName() << "\t" << torso[i].getPartNumber() << "\t" << torso[i].getWeight() << "\t" << torso[i].getCost() << "\t" << torso[i].getCompartments() << "\t" << torso[i].getDescription() << endl;
		}
	}

	if (locomotor.size() != 0) {
		cout << endl << "Locomotor" << endl << "------" << endl;
		cout << "Name\tPart #\tWeight\tCost\tMax Speed\tDescription" << endl;
		cout << "------------------------------------------------------" << endl;
		for (i = 0; i < arm.size(); i++) {
			cout << locomotor[i].getName() << "\t" << locomotor[i].getPartNumber() << "\t" << locomotor[i].getWeight() << "\t" << locomotor[i].getCost() << "\t" << locomotor[i].getMaxSpeed() << "\t" << locomotor[i].getDescription() << endl;
		}
	}				

}

void createMenu(vector<RobotHead> head, vector<RobotArm> arm, vector<RobotBattery> battery, vector<RobotTorso> torso, vector<RobotLocomotor> locomotor) {
	int choice;
	bool flag = true;
	do
	{
		cout << "\nCreate" << endl << "------" << endl;
		cout << "1 - Order\n";
		cout << "2 - Customer\n";
		cout << "3 - Sales Associate\n";
		cout << "4 - Robot Model\n";
		cout << "5 - Robot Component\n";
		cout << "6 - Quit to Main Menu\n";
		cout << "Your Choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Order\n";
			break;
		case 2:
			cout << "Customer\n";
			// rest of code here
			break;
		case 3:
			cout << "Sales Assoiciate\n";
			break;
		case 4:
			cout << "Robot Model\n";
//			createMenu();
			break;
		case 5:
			cout << "Robot Component\n";
			// rest of code here
			robotComponent(head, arm, battery, torso, locomotor);
			break;
		case 6:
			cout << "Quit to Main Menu\n";
			flag = false;
			break;
			default:
			cout << "Not a Valid Choice \n";
			cout << "Please Choose Again: ";
			cin >> choice;
			break;
		}
	} while (flag != false);
}


void createReport() {
	int choice;
	bool flag = true;
	do
	{
		cout << "\nReport" << endl << "------" << endl;
		cout << "1 - Orders\n";
		cout << "2 - Customers\n";
		cout << "3 - Sales Associates\n";
		cout << "4 - Robot Models\n";
		cout << "5 - Robot Parts\n";
		cout << "6 - Quit to Main Menu\n";
		cout << "Your Choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Orders\n";
			break;
		case 2:
			cout << "Customers\n";
			// rest of code here
			break;
		case 3:
			cout << "Sales Assoiciates\n";
			break;
		case 4:
			cout << "Robot Models\n";
//			createMenu();
			break;
		case 5:
			cout << "Robot Parts\n";
			// rest of code here
			break;
		case 6:
			cout << "Quit to Main Menu\n";
			flag = false;
			break;
			default:
			cout << "Not a Valid Choice \n";
			cout << "Please Choose Again: ";
			cin >> choice;
			break;
		}
	} while (flag != false);
}

int main() {

	vector<RobotModel> robots;
	vector<RobotHead> heads;
	vector<RobotArm> arms;
	vector<RobotBattery> batteries;
	vector<RobotTorso> torsos;
	vector<RobotLocomotor> locomotors;

	heads.push_back(RobotHead("Doug", 1100, 25, 110, "Doug's head"));
	heads.push_back(RobotHead("Michael", 1101, 50, 510, "Michael's head"));
	heads.push_back(RobotHead("Grant", 1102, 10, 50, "Grant's head"));
	heads.push_back(RobotHead("Goku", 1103, 11, 75, "Head that looks like Goku"));
	heads.push_back(RobotHead("Ang", 1104, 17, 120, "Head that looks like Ang"));

	arms.push_back(RobotArm("Model X", 2200, 10, 50, "Can pick up cups"));
	arms.push_back(RobotArm("Model A", 2201, 10, 20, "Useless arm"));
	arms.push_back(RobotArm("Model Z", 2202, 10, 1000, "Can pick up any object"));





	int choice;
	bool shopOpen = true;

	while (shopOpen != false)
	{
		cout << "\nMain Menu" << endl << "---------" << endl;
		cout << "1 - Create\n";
		cout << "2 - Report\n";
		cout << "3 - Quit\n";
		cout << "Your Choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Create Robot\n";
			createMenu(heads, arms, batteries, torsos, locomotors);
			break;
		case 2:
			cout << "Report of Robot\n";
			createReport();
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
