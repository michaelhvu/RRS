#include <iostream>
#include <string>
#include <vector>
#include "robot_part.h"

using namespace std;
using std::string;

class RobotModel {
	private:
		string this_name;
		int this_modelNumber;
		double this_price;
		vector<RobotPart> *this_robotParts;


	public:
		RobotModel(string name, int modelNumber)
			: this_name(name), this_modelNumber(modelNumber) {}
		string getName();
		int getModelNumber();
		double getPrice();
		//void componentCost();
		double maxSpeed();
		void addPart(RobotPart);
};
