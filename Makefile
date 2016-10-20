CXXFLAGS =

all: executable

debug: CXXFLAGES += -g
debug: executable

rebuild: clean executable
executable: controller.o robot_model.o robot_part.o robot_head.o robot_locomotor.o robot_torso.o robot_arm.o robot_battery.o view.o order.o
	$(CXX) $(CXXFLAGS) controller.o robot_model.o robot_part.o robot_head.o view.o order.o
controller.o: controller.cpp robot_head.h robot_part.h robot_battery.h robot_locomotor.h robot_model.h robot_torso.h view.h order.h
	$(CXX) $(CXXFLAGS) -w -c controller.cpp
robot_model.o: robot_model.cpp robot_model.h robot_part.h robot_head.h robot_locomotor.h robot_torso.h robot_arm.h robot_battery.h
	$(CXX) $(CXXFLAGS) -w -c robot_model.cpp
robot_part.o: robot_part.cpp robot_part.h
	$(CXX) $(CXXFLAGS) -w -c robot_part.cpp
robot_head.o: robot_head.cpp robot_head.h robot_part.h
	$(CXX) $(CXXFLAGS) -w -c robot_head.cpp
robot_locomotor.o: robot_locomotor.cpp robot_locomotor.h robot_part.h
	$(CXX) $(CXXFLAGS) -w -c robot_locomotor.cpp
robot_torso.o: robot_torso.cpp robot_torso.h robot_part.h robot_head.h robot_locomotor.h robot_torso.h robot_arm.h robot_battery.h
	$(CXX) $(CXXFLAGS) -w -c robot_torso.cpp
robot_arm.o: robot_arm.cpp robot_arm.h robot_part.h
	$(CXX) $(CXXFLAGS) -w -c robot_arm.cpp
robot_battery.o: robot_battery.cpp robot_battery.h robot_part.h
	$(CXX) $(CXXFLAGS) -w -c robot_battery.cpp
view.o: view.cpp view.h robot_head.h robot_part.h robot_battery.h robot_locomotor.h robot_model.h robot_torso.h order.h
	$(CXX) $(CXXFLAGS) -w -c view.cpp 
order.o: order.cpp order.h robot_head.h robot_part.h robot_battery.h robot_locomotor.h robot_model.h robot_torso.h
	$(CXX) $(CXXFLAGS) -w -c order.cpp



clean:
	rm -f *.o a.out