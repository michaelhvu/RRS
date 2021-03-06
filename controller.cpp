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
#include "sales_associate.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_bar.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_JPEG_Image.H>
#include <Fl/Fl_Shared_Image.H>

// Declarations
class OrderWindow;
class SelectPart;
class PictureWindow;
class HeadPart;
class TorsoPart;
class LocomotorPart;
class ArmPart;
class BatteryPart;
class CreateCustomer;
class CreateSalesAssociate;
class CreateRobotModel;
class PriceWindow;
class RobotModelPicture;
void OrderCB(Fl_Widget *w, void *p);
void SelectPartCB(Fl_Widget *w, void *p);
void CustomerDialogCB(Fl_Widget *w, void *p);
void SalesDialogCB(Fl_Widget *w, void *p);
void ModelDialogCB(Fl_Widget *w, void *p);
void NextPictureCB(Fl_Widget *w, void *p);
void RobotModelPicturesCB(Fl_Widget *w, void *p);
void CreateRobotCB(Fl_Widget *w, void *p);
void CreateHeadCB(Fl_Widget *w, void *p);
void CreateModelCB(Fl_Widget *w, void *p);
void CreateLocomotorCB(Fl_Widget *w, void *p);
void CreateArmCB(Fl_Widget *w, void *p);
void CreateBatteryCB(Fl_Widget *w, void *p);
void CreateTorsoCB(Fl_Widget *w, void *p);
void CreateCustomerCB(Fl_Widget *w, void *p);
void CreateSalesCB(Fl_Widget *w, void *p);
void nameCB(Fl_Widget *w, void *p);
void CancelHeadDialogCB(Fl_Widget *w, void *p);
void CancelLocomotorDialogCB(Fl_Widget *w, void *p);
void CancelTorsoDialogCB(Fl_Widget *w, void *p);
void CancelBatteryDialogCB(Fl_Widget *w, void *p);
void CancelArmDialogCB(Fl_Widget *w, void *p);
void CreatePartCB(Fl_Widget *w, void *p);
void CancelCustomerDialogCB(Fl_Widget *w, void *p);
void CancelSalesDialogCB(Fl_Widget *w, void *p);
void CancelModelDialogCB(Fl_Widget *w, void *p);
void CancelOrderCB(Fl_Widget *w, void *p);
void CancelPictureDialogCB(Fl_Widget *w, void *p);
void ModelPictureCB(Fl_Widget *w, void *p);

// Widgets
Fl_Window *win;
Fl_Menu_Bar *menubar;
View *view;
CreateRobotModel *robotWindow;
CreateCustomer *customerWindow;
CreateSalesAssociate *salesWindow;
OrderWindow *orderWindow;
SelectPart *selectPart;
RobotModelPicture *pictureWindow;
HeadPart *head;
LocomotorPart *locomotor;
TorsoPart *torso;
BatteryPart *battery;
ArmPart *arm;
vector<RobotModel> robots;
vector<RobotHead> heads;
vector<RobotArm> arms;
vector<RobotBattery> batteries;
vector<RobotTorso> torsos;
vector<RobotLocomotor> locomotors;
vector<Customer> customers;
vector<SalesAssociate> sales;
vector<Order> orders;



class CreatePart {
	public:
		CreatePart() {
			dialog = new Fl_Window(340, 300, "Part");
			name = new Fl_Input(120, 10, 210, 25, "Name:");
			name->align(FL_ALIGN_LEFT);

			partNumber = new Fl_Input(120, 40, 210, 25, "Part Number:");
			partNumber->align(FL_ALIGN_LEFT);	

			weight = new Fl_Input(120, 70, 210, 25, "Weight:");
			weight->align(FL_ALIGN_LEFT);	

			cost = new Fl_Input(120, 100, 210, 25, "Cost:");
			cost->align(FL_ALIGN_LEFT);		
		}

		void show() {
			dialog->show();
		}

		void hide() {
			dialog->hide();
		}

	protected:
		Fl_Window *dialog;
		Fl_Input *name;
		Fl_Input *partNumber;
		Fl_Input *weight;
		Fl_Input *cost;
		Fl_Input *description;
		Fl_Return_Button *create;
		Fl_Button *cancel;
};


class HeadPart : public CreatePart {
	public:
		HeadPart() {
			dialog->label("Create Head Part");

			description = new Fl_Multiline_Input(120, 130, 210, 75, "Description:");
			description->align(FL_ALIGN_LEFT);

			create = new Fl_Return_Button(145, 210, 120, 25, "Create");
			create->callback((Fl_Callback *)CreateHeadCB, 0);

			cancel = new Fl_Button(270, 210, 60, 25, "Cancel");
			cancel->callback((Fl_Callback *)CancelHeadDialogCB, 0);
		}

		void createHead() {
			if (strcmp(name->value(),"") != 0 && strcmp(partNumber->value(),"") != 0 && strcmp(weight->value(),"") != 0 &&
				strcmp(cost->value(),"") != 0 && strcmp(description->value(),"") != 0) {

				heads.push_back(RobotHead(name->value(), atoi(partNumber->value()), atoi(weight->value()), atoi(cost->value()), description->value()));
				dialog->hide();

				for (int i = 0; i < heads.size(); i++) {
					// print list of head parts
					cout << heads[i].getName() << ", " << heads[i].getDescription() << endl;
				}
			}
			else {
				cout << "Please fill in the entire form" << endl;
			}
		}
};

class LocomotorPart : public CreatePart {
	public:
		LocomotorPart() {
			dialog->label("Create Locomotor Part");
			speed = new Fl_Input(120, 130, 210, 25, "Speed:");

			description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
			description->align(FL_ALIGN_LEFT);

			create = new Fl_Return_Button(145, 240, 120, 25, "Create");
			create->callback((Fl_Callback *)CreateLocomotorCB, 0);

			cancel = new Fl_Button(270, 240, 60, 25, "Cancel");	
			cancel->callback((Fl_Callback *)CancelLocomotorDialogCB, 0);
			
		}

		void createLocomotor() {
			if (strcmp(name->value(),"") != 0 && strcmp(partNumber->value(),"") != 0 && strcmp(weight->value(),"") != 0 &&
				strcmp(cost->value(),"") != 0 && strcmp(description->value(),"") != 0 && strcmp(speed->value(),"") != 0) {

				locomotors.push_back(RobotLocomotor(name->value(), atoi(partNumber->value()), atoi(weight->value()), atoi(cost->value()), description->value(), atoi(speed->value())));
				dialog->hide();

				for (int i = 0; i < locomotors.size(); i++) {
					// print list of head parts
					cout << locomotors[i].getName() << ", " << locomotors[i].getDescription() << endl;
				}
			}
			else {
				cout << "Please fill in the entire form" << endl;
			}
		}

	protected:
		Fl_Input *speed;
};

class TorsoPart : public CreatePart {
	public:
		TorsoPart() {
			dialog->label("Create Torso Part");
			compartment = new Fl_Input(120, 130, 210, 25, "Compartments:");
			compartment->align(FL_ALIGN_LEFT);

			description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
			description->align(FL_ALIGN_LEFT);

			create = new Fl_Return_Button(145, 240, 120, 25, "Create");
			create->callback((Fl_Callback *)CreateTorsoCB, 0);

			cancel = new Fl_Button(270, 240, 60, 25, "Cancel");	
			cancel->callback((Fl_Callback *)CancelTorsoDialogCB, 0);
	
			}

		void createTorso() {
			if (strcmp(name->value(),"") != 0 && strcmp(partNumber->value(),"") != 0 && strcmp(weight->value(),"") != 0 &&
				strcmp(cost->value(),"") != 0 && strcmp(description->value(),"") != 0 && strcmp(compartment->value(),"") != 0) {

				torsos.push_back(RobotTorso(name->value(), atoi(partNumber->value()), atoi(weight->value()), atoi(cost->value()), description->value(), atoi(compartment->value())));
				dialog->hide();

				for (int i = 0; i < torsos.size(); i++) {
					// print list of head parts
					cout << torsos[i].getName() << ", " << torsos[i].getDescription() << endl;
				}
			}
			else {
				cout << "Please fill in the entire form" << endl;
			}
		}			

	protected:
		Fl_Input *compartment;
};

class BatteryPart : public CreatePart {
	public:
		BatteryPart() {
			dialog->label("Create Battery Part");
			energy = new Fl_Input(120, 130, 210, 25, "Energy:");
			energy->align(FL_ALIGN_LEFT);

			maxPower = new Fl_Input(120, 160, 210, 25, "Max Power:");
			maxPower->align(FL_ALIGN_LEFT);

			description = new Fl_Multiline_Input(120, 190, 210, 75, "Description:");
			description->align(FL_ALIGN_LEFT);

			create = new Fl_Return_Button(145, 270, 120, 25, "Create");
			create->callback((Fl_Callback *)CreateBatteryCB, 0);

			cancel = new Fl_Button(270, 270, 60, 25, "Cancel");	
			cancel->callback((Fl_Callback *)CancelBatteryDialogCB, 0);

		}

		void createBattery() {
			if (strcmp(name->value(),"") != 0 && strcmp(partNumber->value(),"") != 0 && strcmp(weight->value(),"") != 0 &&
				strcmp(cost->value(),"") != 0 && strcmp(description->value(),"") != 0 && strcmp(energy->value(),"") != 0 && strcmp(maxPower->value(),"") != 0) {

				batteries.push_back(RobotBattery(name->value(), atoi(partNumber->value()), atoi(weight->value()), atoi(cost->value()), description->value(), atoi(energy->value()), atoi(maxPower->value())));
				dialog->hide();

				for (int i = 0; i < batteries.size(); i++) {
					// print list of head parts
					cout << batteries[i].getName() << ", " << batteries[i].getDescription() << endl;
				}
			}
			else {
				cout << "Please fill in the entire form" << endl;
			}
		}

	protected:
		Fl_Input *energy;
		Fl_Input *maxPower;
};

class ArmPart : public CreatePart {
	public:
		ArmPart() {
			dialog->label("Create Arm Part");

			description = new Fl_Multiline_Input(120, 130, 210, 75, "Description:");
			description->align(FL_ALIGN_LEFT);

			create = new Fl_Return_Button(145, 210, 120, 25, "Create");
			create->callback((Fl_Callback *)CreateArmCB, 0);

			cancel = new Fl_Button(270, 210, 60, 25, "Cancel");
			cancel->callback((Fl_Callback *)CancelArmDialogCB, 0);			
		}

		void createArm() {
			if (strcmp(name->value(),"") != 0 && strcmp(partNumber->value(),"") != 0 && strcmp(weight->value(),"") != 0 &&
				strcmp(cost->value(),"") != 0 && strcmp(description->value(),"") != 0) {

				arms.push_back(RobotArm(name->value(), atoi(partNumber->value()), atoi(weight->value()), atoi(cost->value()), description->value()));
				dialog->hide();

				for (int i = 0; i < arms.size(); i++) {
					// print list of head parts
					cout << arms[i].getName() << ", " << arms[i].getDescription() << endl;
				}
			}
			else {
				cout << "Please fill in the entire form" << endl;
			}
		}		
};


class SelectPart {
	public:
		SelectPart() {
			window = new Fl_Window(340, 100, "Create Model");
			choice = new Fl_Choice(120, 20, 210, 25, "Type:");
			next = new Fl_Button(270, 50, 60, 25, "Next");

			next->callback((Fl_Callback *)CreatePartCB);

			choice->value(0);
			choice->add("Head", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Locomotor", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Torso", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Battery", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Arm", 0, (Fl_Callback *)SelectPartCB);
			choice->value(0);


		}

		void show() {
			window->show();
		}


		void selectPart() {

			if (choice->value() == 0) {
				head = new HeadPart;
				head->show();
				window->hide();
			}
			else if (choice->value() == 1) {
				locomotor = new LocomotorPart;
				locomotor->show();
				window->hide();
			}
			else if (choice->value() == 2) {
				torso = new TorsoPart;
				torso->show();
				window->hide();
			}
			else if (choice->value() == 3) {
				battery = new BatteryPart;
				battery->show();
				window->hide();
			}
			else if (choice->value() == 4) {
				arm = new ArmPart;
				arm->show();
				window->hide();
			}

		}

	private:
		Fl_Window *window;
		Fl_Choice *choice;
		Fl_Button *next;
};

class PictureWindow {
	public:
		PictureWindow(RobotModel Robot_Model, int number) {
			this_number = number;
			window = new Fl_Window(400, 350, "Robot Model");
			name = new Fl_Output(140, 10, 210, 25, "Model Name:");
			name->value(Robot_Model.getName().c_str());
			part_number = new Fl_Output(140, 40, 210, 25, "Model Part Number:");
			part_number->value(to_string(Robot_Model.getModelNumber()).c_str());

			pictureNames.push_back("full_business_can.jpg");
			pictureNames.push_back("full_button_can.jpg");
			pictureNames.push_back("full_humanoid_soldier.jpg");
			pictureNames.push_back("full_medic_can.jpg");
			pictureNames.push_back("full_orange_can.jpg");
			pictureNames.push_back("full_orange_humanoid_meditating.jpg");
			pictureNames.push_back("full_orange_humanoid_with_laptop_computer.jpg");
			pictureNames.push_back("full_white_can_w_antennae.jpg");

			box = new Fl_Box(170, 150, 50, 50);
			jpg = new Fl_JPEG_Image(pictureNames[number].c_str());
			temp = jpg->copy(200,200);

			box->image(temp);
		}

		void show() {
			window->show();
		}

	private:
		int this_number;
		vector<string> pictureNames;
		Fl_Window *window;
		Fl_Output *name;
		Fl_Output *part_number;
		Fl_Box *box;
		Fl_JPEG_Image *jpg;
		Fl_Image *temp;
};

class RobotModelPicture {
	public:
		RobotModelPicture() {
			window = new Fl_Window(340, 80, "List of Robot Models");
			model = new Fl_Choice(120, 10, 210, 25, "Select Model:");

			next = new Fl_Return_Button(140, 40, 125, 25, "Next");
			next->callback((Fl_Callback *)ModelPictureCB);
			cancel = new Fl_Button(270, 40, 60, 25, "Cancel");
			cancel->callback((Fl_Callback *)CancelPictureDialogCB);

			for (int i = 0; i < robots.size(); i++) {
				model->add(robots[i].getName().c_str());
			}
		}

		void show() {
			window->show();
		}

		void hide() {
			window->hide();
		}

		void showModel() {
			if (model->value() != -1) {
				Pic_Window = new PictureWindow(robots[model->value()], model->value());
				Pic_Window->show();

			}
		}

	private:
		Fl_Window *window;
		Fl_Return_Button *next;
		Fl_Button *cancel;
		Fl_Choice *model;
		PictureWindow *Pic_Window;

};


class CreateRobotModel {
	public:

		CreateRobotModel() {

			window = new Fl_Window(340, 260, "Create Robot Model");
			name = new Fl_Input(120, 10, 210, 25, "Name:");
			name->align(FL_ALIGN_LEFT);

			number = new Fl_Input(120, 40, 210, 25, "Part Number:");
			number->align(FL_ALIGN_LEFT);	

			head = new Fl_Choice(120, 70, 210, 25, "Head Part:");

			for (int i = 0; i < heads.size(); i++) {
				head->add(heads[i].getName().c_str());
			}

			arm = new Fl_Choice(120, 100, 210, 25, "Arm Part:");

			for (int i = 0; i < arms.size(); i++) {
				arm->add(arms[i].getName().c_str());
			}
			
			locomotor = new Fl_Choice(120, 130, 210, 25, "Locomotor Part:");

			for (int i = 0; i < locomotors.size(); i++) {
				locomotor->add(locomotors[i].getName().c_str());
			}

			torso = new Fl_Choice(120, 160, 210, 25, "Torso Part:");

			for (int i = 0; i < torsos.size(); i++) {
				torso->add(torsos[i].getName().c_str());
			}
			
			battery = new Fl_Choice(120, 190, 210, 25, "Battery Part:");			
			for (int i = 0; i < batteries.size(); i++) {
				battery->add(batteries[i].getName().c_str());
			}

			create = new Fl_Return_Button(140, 220, 125, 25, "Create");
			create->callback((Fl_Callback *)CreateModelCB, 0);

			cancel = new Fl_Button(270, 220, 60, 25, "Cancel");
			cancel->callback((Fl_Callback *)CancelModelDialogCB, 0);
		}

		void show() {
			window->show();
		}

		void hide() {
			window->hide();
		}

		void CreateModel() {
			
			if (strcmp(name->value(), "") != 0 && strcmp(number->value(), "") != 0 &&
				head->value() != -1 && arm->value() != -1 && locomotor->value() != -1 &&
				torso->value() != -1 && battery->value() != -1) {

				RobotModel model(name->value(), atoi(number->value()));
				model.addPart(heads[head->value()]);
				model.addPart(arms[arm->value()]);
				model.addPart(locomotors[locomotor->value()]);
				model.addPart(torsos[torso->value()]);
				model.addPart(batteries[battery->value()]);

				robots.push_back(model);

				heads.erase(heads.begin() + head->value());
				arms.erase(arms.begin() + arm->value());
				locomotors.erase(locomotors.begin() + locomotor->value());
				torsos.erase(torsos.begin() + torso->value());
				batteries.erase(batteries.begin() + battery->value());

				for (int i = 0; i < robots.size(); i++) {
					cout << robots[i].getName() << endl;
				}

			}
			else {
				cout << "Please fill in the entire form" << endl;
			}	
		}
		

	private:
		RobotModel *robotModel;
		Fl_Window *window;
		Fl_Button *cancel;
		Fl_Return_Button *create;
		Fl_Input *name;
		Fl_Input *number;
		Fl_Choice *head;
		Fl_Choice *arm;
		Fl_Choice *locomotor;
		Fl_Choice *torso;
		Fl_Choice *battery;
};

class CreateCustomer {
	public:
		CreateCustomer() {
			window = new Fl_Window(340, 140, "Create Customer");
			create = new Fl_Return_Button(140, 100, 125, 25, "Create");
			create->callback((Fl_Callback *)CreateCustomerCB, 0);

			cancel = new Fl_Button(270, 100, 60, 25, "Cancel");
			cancel->callback((Fl_Callback *)CancelCustomerDialogCB, 0);

			name = new Fl_Input(120, 10, 210, 25, "Name:");
			name->align(FL_ALIGN_LEFT);
			number = new Fl_Input(120, 40, 210, 25, "Number:");
			number->align(FL_ALIGN_LEFT);
			money = new Fl_Input(120, 70, 210, 25, "Money:");
			money->align(FL_ALIGN_LEFT);


		}

		void createCustomer() {
			if (strcmp(name->value(), "") != 0 && strcmp(number->value(), "") != 0 && strcmp(money->value(), "") != 0) {
				customers.push_back(Customer(name->value(), atoi(number->value()), atof(money->value())));

				name->value("");
				number->value("");
				money->value("");
				
				window->hide();

				for (int i=0; i < customers.size(); i++) {
					cout << customers[i].getName() << ", " << customers[i].getCustomerNumber() << ", " << customers[i].getWallet() <<endl;
				}

			}
			else {
				cout << "Please fill in the entire form" << endl;
			}
		}

		void show() {
			window->show();
		}
		
		void hide() {
			window->hide();
			name->value("");
			number->value("");
			money->value("");

		}
	
	private:
		Fl_Window *window;
		Fl_Return_Button *create;
		Fl_Button *cancel;
		Fl_Input *name;
		Fl_Input *number;
		Fl_Input *money;
};

class CreateSalesAssociate {
	public:
		CreateSalesAssociate() {
			window = new Fl_Window(340, 120, "Create Sales Associate");
			create = new Fl_Return_Button(140, 70, 125, 25, "Create");
			create->callback((Fl_Callback *)CreateSalesCB, 0);

			cancel = new Fl_Button(270, 70, 60, 25, "Cancel");
			cancel->callback((Fl_Callback *)CancelSalesDialogCB, 0);

			name = new Fl_Input(120, 10, 210, 25, "Name:");
			name->align(FL_ALIGN_LEFT);
			number = new Fl_Input(120, 40, 210, 25, "Number:");
			number->align(FL_ALIGN_LEFT);
		}

		void show() {
			window->show();
		}

		void hide() {
			window->hide();
			name->value("");
			number->value("");
		}

		void createSales() {
			if (strcmp(name->value(), "") != 0 && strcmp(number->value(), "") != 0) {
				sales.push_back(SalesAssociate(name->value(), atoi(number->value())));

				name->value("");
				number->value("");

				window->hide();

				for (int i=0; i < sales.size(); i++) {
					cout << sales[i].getName() << ", " << sales[i].getNumber() << endl;
				}
			}
		}


	private:
		Fl_Window *window;
		Fl_Return_Button *create;
		Fl_Button *cancel;
		Fl_Input *name;
		Fl_Input *number;

};

class PriceWindow {

	public:
		PriceWindow(string dollars) {

			window = new Fl_Window(340, 60, "Recipe");
			Fl_Output *price = new Fl_Output(120, 10, 210, 25, "Price:");
			price->value(dollars.c_str());
		}

		void show() {
			window->show();
		}
		
		void hide() {
			window->hide();
		}

	private:
		Fl_Window *window;
		Fl_Output *price;
};

class OrderWindow {

	public:
		OrderWindow() {
			window = new Fl_Window(340,170, "Order Robot");
			create = new Fl_Return_Button(140, 130, 125, 25, "Create");
			create->callback((Fl_Callback *)OrderCB, 0);
			cancel = new Fl_Button(270, 130, 60, 25, "Cancel");
			cancel->callback((Fl_Callback*)CancelOrderCB, 0);
			
			model = new Fl_Choice(120, 10, 210, 25, "Robot:");
			for (int i = 0; i < robots.size(); i++) {
				model->add(robots[i].getName().c_str());
			}

			number = new Fl_Input(120, 40, 210, 25, "Order Number:");

			customer = new Fl_Choice(120, 70, 210, 25, "Customer:");
			for (int i = 0; i < customers.size(); i++) {
				customer->add(customers[i].getName().c_str());
			}

			sale = new Fl_Choice(120, 100, 210, 25, "Sales Associate:");
			for (int i = 0; i < sales.size(); i++) {
				sale->add(sales[i].getName().c_str());
			}


		}

		void show() {
			window->show();
		}

		void hide() {
			window->hide();
		}

		void createOrder() {

				if (model->value() != -1 && customer->value() != -1 && sale->value() != -1 && strcmp(number->value(), "") != 0) {

				Order created_order(&customers[customer->value()], &sales[sale->value()], atoi(number->value()));
				created_order.addRobotModel(robots[model->value()]);
				orders.push_back(created_order);
				robots.erase(robots.begin() + model->value());
				created_order.robotPrice();


				price = new PriceWindow(to_string(created_order.totalPrice()));
				price->show();
			}
		}



	private:
		Fl_Window *window;
		Fl_Return_Button *create;
		Fl_Button *cancel;
		Fl_Choice *model;
		Fl_Choice *customer;
		Fl_Choice *sale;
		Fl_Input *number;
		PriceWindow *price;

	
};

// Callbacks
void CloseCB(Fl_Widget* w, void* p) {
	win->hide();
}

void NextPictureCB(Fl_Widget *w, void *p) {
	pictureWindow->showModel();
	pictureWindow->hide();
}

void OrderRobotCB(Fl_Widget *w, void *p) {
	orderWindow = new OrderWindow;
	orderWindow->show();
}

void CustomerDialogCB(Fl_Widget *w, void *p) {
	customerWindow->show();
}

void RobotModelPicturesCB(Fl_Widget *w, void *p) {
	pictureWindow = new RobotModelPicture;
	pictureWindow->show();
}

void ModelPictureCB(Fl_Widget *w, void *p) {
	pictureWindow->showModel();
	pictureWindow->hide();
}

void SalesDialogCB(Fl_Widget *w, void *p) {
	salesWindow->show();
}

void ModelDialogCB(Fl_Widget *w, void *p) {
	robotWindow = new CreateRobotModel;
	robotWindow->show();
}

void CreateRobotCB(Fl_Widget *w, void *p) {
	selectPart->show();
}

void CreateModelCB(Fl_Widget *w, void *p) {
	robotWindow->CreateModel();
	robotWindow->hide();
}

void SelectPartCB(Fl_Widget *w, void *p) {
	cout << "Changing choice\n";
}

void CreateHeadCB(Fl_Widget *w, void *p) {
	head->createHead();
}

void CreateLocomotorCB(Fl_Widget *w, void *p) {
	locomotor->createLocomotor();
}

void CreateTorsoCB(Fl_Widget *w, void *p) {
	torso->createTorso();
}

void CreateArmCB(Fl_Widget *w, void *p) {
	arm->createArm();
}

void CreateCustomerCB(Fl_Widget *w, void *p) {
	customerWindow->createCustomer();
}

void CreateSalesCB(Fl_Widget *w, void *p) {
	salesWindow->createSales();
}

void CreateBatteryCB(Fl_Widget *w, void *p) {
	battery->createBattery();
}

void OrderCB(Fl_Widget *w, void *p) {
	orderWindow->createOrder();
	orderWindow->hide();
}

void CancelOrderCB(Fl_Widget *w, void *p) {
	orderWindow->hide();
}

void CancelCustomerDialogCB(Fl_Widget *w, void *p) {
	customerWindow->hide();
}

void CancelSalesDialogCB(Fl_Widget *w, void *p) {
	salesWindow->hide();
}

void CancelHeadDialogCB(Fl_Widget *w, void *p) {
	head->hide();
}

void CancelLocomotorDialogCB(Fl_Widget *w, void *p) {
	locomotor->hide();
}

void CancelTorsoDialogCB(Fl_Widget *w, void *p) {
	torso->hide();
}

void CancelArmDialogCB(Fl_Widget *w, void *p) {
	arm->hide();
}

void CancelBatteryDialogCB(Fl_Widget *w, void *p) {
	battery->hide();
}

void CreatePartCB(Fl_Widget *w, void *p) {
	selectPart->selectPart();
}

void CancelModelDialogCB(Fl_Widget *w, void *p) {
	robotWindow->hide();
}

void CancelPictureDialogCB(Fl_Widget *w, void *p) {
	pictureWindow->hide();
}


Fl_Menu_Item menuitems[] = {
	{"&File", 0, 0, 0, FL_SUBMENU},
		{"&Quit", FL_ALT + 'Q', (Fl_Callback *)CloseCB},
		{0},
	{"&Create", 0, 0, 0, FL_SUBMENU},
		{"&Order", 0, (Fl_Callback *)OrderRobotCB, 0, FL_MENU_DIVIDER},
		{"&Customer", 0, (Fl_Callback *)CustomerDialogCB},
		{"&Sales Associate", 0, (Fl_Callback *)SalesDialogCB, 0, FL_MENU_DIVIDER},
		{"&Robot Part", 0, (Fl_Callback *)CreateRobotCB},
		{"&Robot Model", 0, (Fl_Callback *)ModelDialogCB},
		{0},
	{"&Report", 0, 0, 0, FL_SUBMENU},
		{"&All Robot Models", 0, (Fl_Callback *)RobotModelPicturesCB},
		{0},
	{0}
};

int main() {
	vector<int> prices;
	vector<string> names;

	customers.push_back(Customer("Michael", 0117, 1000000));
	sales.push_back(SalesAssociate("Zaman", 1325));


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

	// GUI
	const int X = 330; 
	const int Y = 270;

	// Create a window
	win = new Fl_Window(X, Y, "Robbie Robot Shop Manager");
	win->color(FL_WHITE);

	// Install a menu bar
	menubar = new Fl_Menu_Bar(0,0, X, 30);
	menubar->menu(menuitems);

	view = new View(0, 0, X, Y);
	selectPart = new SelectPart;
	customerWindow = new CreateCustomer;
	salesWindow = new CreateSalesAssociate;

	win->end();
	win->show();
	return(Fl::run());
}
