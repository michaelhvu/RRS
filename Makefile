CXXFLAGS =

all: executable

debug: CXXFLAGES += -g
debug: executable

rebuild: clean executable
executable:


clean:
	rm -f *.o a.out