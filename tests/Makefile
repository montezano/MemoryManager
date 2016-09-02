LIBS = 
INCLUDES = -I./$(GTEST_DIR) -I../include
CC = g++
CPPFLAGS = -DGTEST_HAS_PTHREAD=0
CXXFLAGS = -g -MMD -MP -std=c++11 -lpthread
EXECUTABLE = test.out

GTEST_DIR = gtest
SRC_DIR = src
CODE_SRC_DIR = ../src

TEST_SRCS += $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRCS += $(wildcard $(CODE_SRC_DIR)/*.cpp)
OBJS += $(TEST_SRCS:.cpp=.o)

%.o: %.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	$(CC) $(INCLUDES) $(CPPFLAGS) $(CXXFLAGS)  -O0 -Wall -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

all:	gtest $(OBJS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJS) ./$(GTEST_DIR)/gtest-all.o $(LIBS)
	@echo 'Build complete!'
	@echo ' '
	
gtest: ./$(GTEST_DIR)/gtest-all.o

test:	all
	@echo 'Executing tests...'
	./$(EXECUTABLE)
	@echo 'Done!'

clean:
	rm -rf ./$(SRC_DIR)/*.o $(EXECUTABLE)

veryclean: clean
	rm -rf ./$(GTEST_DIR)/*.o