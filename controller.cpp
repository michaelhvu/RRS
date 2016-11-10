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
#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Box.H"
#include "FL/fl_ask.H"
#include "FL/FL_Menu_Bar.H"
#include "FL/Fl_Input.H"
#include "FL/Fl_Multiline_Input.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Return_Button.H"

// Declarations
void create_robot_partCB(Fl_Widget* w, void* p);
void cancel_robot_partCB(Fl_Widget* w, void* p);
class Robot_Part_Dialog;

// Widgets
Fl_Window *win;
Fl_Menu_Bar *menubar;
Robot_Part_Dialog *robot_part_dlg;

class Robot_Part_Dialog {
 public:
    Robot_Part_Dialog() { // Create and populate the dialog (but don't show it!)
    dialog = new Fl_Window(340, 270, "Robot Part");
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
        rp_type->align(FL_ALIGN_LEFT);
        rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_robot_partCB, 0);
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);
    dialog->end();
    dialog->set_non_modal();

 }
 void show() {dialog->show();}
 void hide() {dialog->hide();}
 string name() {return rp_name->value();}
 string part_number() {return rp_part_number->value();}
 string type() {return rp_type->value();}
 string weight() {return rp_weight->value();}
 string cost() {return rp_cost->value();}
 string description() {return rp_description->value();}

 private:
 Fl_Window *dialog;
 Fl_Input *rp_name;
 Fl_Input *rp_part_number;
 Fl_Input *rp_type;
 Fl_Input *rp_weight;
 Fl_Input *rp_cost;
 Fl_Input *rp_description;
 Fl_Return_Button *rp_create;
 Fl_Button *rp_cancel;
};

// Callbacks
void CloseCB(Fl_Widget* w, void* p) {
	win->hide();
}
void CB(Fl_Widget* w, void* p) { } // No action
void menu_create_robot_partCB(Fl_Widget* w, void* p) {
 robot_part_dlg->show();
}
void create_robot_partCB(Fl_Widget* w, void* p) { // Replace with call to model!
 cout << "CREATING ROBOT PART" << endl;
 cout << "Name : " << robot_part_dlg->name() << endl;
 cout << "Part # : " << robot_part_dlg->part_number() << endl;
 cout << "Type : " << robot_part_dlg->type() << endl;
 cout << "Weight : " << robot_part_dlg->weight() << endl;
 cout << "Cost : " << robot_part_dlg->cost() << endl;
 cout << "Description: " << robot_part_dlg->description() << endl;
 robot_part_dlg->hide();
}
void cancel_robot_partCB(Fl_Widget* w, void* p) {
 robot_part_dlg->hide();
}

// Menu
Fl_Menu_Item menuitems[] = {
	{ "&File", 0, 0, 0, FL_SUBMENU },
		{ "&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB },
		{ 0 },
	{ "&Create", 0, 0, 0, FL_SUBMENU },
		{ "Order", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
		{ "Customer", 0, (Fl_Callback *)CB },
		{ "Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
		{ "Robot Part", 0, (Fl_Callback *)menu_create_robot_partCB },
		{ "Robot Model", 0, (Fl_Callback *)CB },
		{ 0 },
	{ "&Report", 0, 0, 0, FL_SUBMENU },
		{ 0 },
	{ 0 } 
};

// Main
int main() {
/*
	vector<RobotModel> robots;
	vector<RobotHead> heads;
	vector<RobotArm> arms;
	vector<RobotBattery> batteries;
	vector<RobotTorso> torsos;
	vector<RobotLocomotor> locomotors;	
	vector<int> prices;
	vector<string> names;

	Customer Michael("Michael", 1432, 1000000);
	Order order(Michael,35813);


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
*/
	const int X = 640; 
	const int Y = 480;
	// Create dialogs
 	robot_part_dlg = new Robot_Part_Dialog{};

	// Create a window
	win = new Fl_Window{X, Y, "Robbie Robot Shop Manager"};
	win->color(FL_WHITE);

	// Install menu bar
	menubar = new Fl_Menu_Bar(0, 0, X, 30);
	menubar->menu(menuitems);

	// Wrap it up and let FLTK do its thing
	win->end();
	win->show();
	return(Fl::run());
}
