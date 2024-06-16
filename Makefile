#CXX = icpx
CXX = g++
SRC = $(wildcard ./Src/*.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
TARGET = LeastDis
CXXFLAGS = -O3 -std=c++17 -Wall
$(TARGET): $(OBJ)
	@$(CXX) $^ -o $@ 

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) $< -c -o $@

.PHONY: cl
cl:
	@rm -f ./Src/*.o $(TARGET)

.PHONY: r
r:
	@./$(TARGET)