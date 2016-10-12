
#ifndef __ROBOT_PART
#define __ROBOT_PART 2016
#include <string>
using std::string;

class RobotPart {
	private:
		string this_name;
		int this_partNumber;
		double this_weight;
		double this_cost;
		string this_description;

	public:
		RobotPart(string name, int partNum, double weight, double cost, string description)
			: this_name(name), this_partNumber(partNum), this_weight(weight), this_cost(cost), this_description(description) { }
		string getName();
		int getPartNumber();
		double getWeight();
		double getCost();
		string getDescription();
};
#endif
