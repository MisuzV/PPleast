#CXX = icpx
CXX = g++
SRC = $(wildcard ./src/*.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
TARGET = LeastDis
CXXFLAGS = -O3 -std=c++17
$(TARGET): $(OBJ)
	$(CXX) $^ -o $@ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

.PHONY: cl
cl:
	@rm -f ./src/*.o $(TARGET)

.PHONY: r
r:
	@./$(TARGET)