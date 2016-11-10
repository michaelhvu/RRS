CXX	= $(shell fltk-config --cxx)
CXXOPTS = -std=c++11
DEBUG = -g
CXXFLAGS = $(shell fltk-config --use-gl --use-images --cxxflags ) $(CXXOPTS)
LDFLAGS = $(shell fltk-config --use-gl --use-images --ldflags )
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )
LINK = $(CXX)
TARGET = a.out
OBJS = controller.o robot_model.o robot_part.o robot_head.o robot_locomotor.o robot_torso.o robot_arm.o robot_battery.o view.o customer.o order.o
SRCS = controller.cxx robot_model.cxx robot_part.cxx robot_head.cxx robot_locomotor.cxx robot_torso.cxx robot_arm.cxx robot_battery.cxx view.cxx customer.cxx order.cxx
.SUFFIXES: .o .cxx
%.o: %.cxx
	$(CXX) $(CXXFLAGS) $(DEBUG) -c $(CXXOPTS) $<
all: $(TARGET)
	$(LINK) -o $(TARGET) $(OBJS) $(LDSTATIC)
$(TARGET): $(OBJS)
controller.o: controller.cpp robot_head.h robot_part.h robot_battery.h robot_locomotor.h robot_model.h robot_torso.h view.h order.h customer.h
robot_model.o: robot_model.cpp robot_model.h robot_part.h robot_head.h robot_locomotor.h robot_torso.h robot_arm.h robot_battery.h
robot_part.o: robot_part.cpp robot_part.h
robot_head.o: robot_head.cpp robot_head.h robot_part.h
robot_locomotor.o: robot_locomotor.cpp robot_locomotor.h robot_part.h
robot_torso.o: robot_torso.cpp robot_torso.h robot_part.h robot_head.h robot_locomotor.h robot_torso.h robot_arm.h robot_battery.h
robot_arm.o: robot_arm.cpp robot_arm.h robot_part.h
robot_battery.o: robot_battery.cpp robot_battery.h robot_part.h
view.o: view.cpp view.h robot_head.h robot_part.h robot_battery.h robot_locomotor.h robot_model.h robot_torso.h order.h
customer.o: customer.cpp customer.h order.h
order.o: order.cpp order.h robot_head.h robot_part.h robot_battery.h robot_locomotor.h robot_model.h robot_torso.h customer.h

clean: $(TARGET) $(OBJS)
	rm -f *.o 2> /dev/null
	rm -f $(TARGET) 2> /dev/null