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

void createMenu() {
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
			createMenu();
			break;
		case 5:
			cout << "Robot Component\n";
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
			createMenu();
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
			createMenu();
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


//	Testing the class
//      
/*              RobotPart(name, partNum, weight, cost, description)
    int menu=1;
	while (menu!=0) {
		cout << "Main Menu" << endl << "---------" << endl;
	}

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
	*/
