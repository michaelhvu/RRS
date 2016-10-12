#include "robot_part.h";


string RobotPart::getName() {
	return this_name;
}

int RobotPart::getPartNumber() {
	return this_partNumber;
}

double RobotPart::getWeight() {
	return this_weight;
}

double RobotPart::getCost() {
	return this_cost;
}

string RobotPart::getDescription() {
	return this_description;
}
