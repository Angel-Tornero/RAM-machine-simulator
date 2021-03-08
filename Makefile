CXX = g++
#CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g 
LDFLAGS =  -fsanitize=address
#-fsanitize=address
#-Werror
SRC= $(wildcard src/*.cc) $(wildcard src/Instrucciones/*.cc)
OBJ = $(SRC:.cc=.o)
EXEC = bin/ram_sim

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)