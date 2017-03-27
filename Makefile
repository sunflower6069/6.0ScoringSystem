#------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++11
CLIBS = -lgmp -lgmpxx
OBJ = main.o tools.o election.o ballot.o candidate.o vote.o
TARGET = stv
#------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(CLIBS) $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#------------------
# Dependencies
main.o: main.cpp tools.hpp vote.hpp candidate.hpp ballot.hpp election.hpp
#score.o: score.cpp score.hpp
#judge.o: judge.cpp judge.hpp
#skater.o: skater.cpp skater.hpp
#sixoh.o: sixoh.cpp sixoh.hpp
#tools.o: tools.cpp tools.hpp 
