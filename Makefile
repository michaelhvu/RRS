CXXFLAGS =

all: executable

debug: CXXFLAGES += -g
debug: executable

rebuild: clean executable
executable: controller.o robot_model.o robot_part.o robot_head.o
	$(CXX) $(CXXFLAGS) controller.o robot_model.o robot_part.o robot_head.o
controller.o: controller.cpp robot_head.h robot_part.h
	$(CXX) $(CXXFLAGS) -w -c controller.cpp
robot_model.o: robot_model.cpp 
	$(CXX) $(CXXFLAGS) -w -c robot_model.cpp
robot_part.o: robot_part.cpp
	$(CXX) $(CXXFLAGS) -w -c robot_part.cpp
robot_head.o: robot_head.cpp robot_part.h
	$(CXX) $(CXXFLAGS) -w -c robot_head.cpp



clean:
	rm -f *.o a.out