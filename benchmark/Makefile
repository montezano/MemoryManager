# CC := g++
# TARGET ?= benchmark
# SRC_DIRS ?= ./ ./src ../src
# INC_BASE_DIR ?= ../include ./hayai ./src

# SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
# OBJS := $(addsuffix .o,$(basename $(SRCS)))
# DEPS := $(OBJS:.o=.d)

# INC_DIRS := $(shell find $(INC_BASE_DIR) -type d)
# INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# CPPFLAGS ?= $(INC_FLAGS) -g -MMD -MP -std=c++11 -lpthread

# $(TARGET): $(OBJS)
# 	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBES) $(LDLIBS)

# bench:	$(TARGET)
# 	@echo 'Executing benchmark...'
# 	./$(TARGET)
# 	@echo 'Done!'

# .PHONY: clean
# clean:
# 	$(RM) $(TARGET) $(OBJS) $(DEPS)

# -include $(DEPS)

LIBS = 
INCLUDES = -I./$(BENCHMARK_DIR) -I../include
CC = g++
CPPFLAGS = 
CXXFLAGS = -g -MMD -MP -std=c++11 -lpthread
EXECUTABLE = bench.out

BENCHMARK_DIR = hayai
SRC_DIR = src
CODE_SRC_DIR = ../src

BENCHMARK_SRC += $(wildcard $(SRC_DIR)/*.cpp)
BENCHMARK_SRC += $(wildcard $(CODE_SRC_DIR)/*.cpp)
OBJS += $(BENCHMARK_SRC:.cpp=.o)
HAYAI_SRC += $(wildcard $(BENCHMARK_DIR)/*.cpp)
HAYAI_OBJS += $(HAYAI_SRC:.cpp=.o)

%.o: %.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	$(CC) $(INCLUDES) $(CPPFLAGS) $(CXXFLAGS)  -O0 -Wall -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

all:	bench $(OBJS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJS) ./$(HAYAI_OBJS) $(LIBS)
	@echo 'Build complete!'
	@echo ' '
	
bench: ./$(HAYAI_OBJS)

$(HAYAI_OBJS): 

test:	all
	@echo 'Executing tests...'
	./$(EXECUTABLE)
	@echo 'Done!'

clean:
	rm -rf ./$(SRC_DIR)/*.o $(EXECUTABLE)

veryclean: clean
	rm -rf ./$(BENCHMARK_DIR)/*.o