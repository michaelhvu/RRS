#include <iostream>
#include "robot_head.h"
#include "robot_part.h"
#include "robot_locomotor.h"
#include "robot_torso.h"
#include "robot_battery.h"
#include "robot_arm.h"

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
