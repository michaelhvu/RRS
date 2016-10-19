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
		int this_numberOfPieces;
		double this_price;
		vector<RobotPart> *this_robotParts;


	public:
		RobotModel(string name, int modelNumber)
			: this_name(name), this_modelNumber(modelNumber), this_numberOfPieces(0) {}
		string getName();
		int getModelNumber();
		double getPrice();
		double getComponentCost(RobotPart);
		double maxSpeed();
		void addPart(RobotPart);
};
