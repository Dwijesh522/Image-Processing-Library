CXX=g++
CFLAGS=-I.
#DEPS = functions.h
DEPS = $(wildcard *.h)
SRCS = $(wildcard *.cpp)
OBJ = $(SRCS:%.cpp=%.o)
# OBJ = printHello.o deleteThis.o 


%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

binaryFile: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -rvf *.o 

# .PHONY = all clean

# cpp = g++

# srcs := $(wildcard *.cpp)
# bins := $(srcs:%.cpp=%)

# all: $(bins)

# %: %.o
# 	$(cpp) -lm $< -o hi
# %.o: %.cpp functions.h
# 	$(cpp) -o $@ -c $<

# clean:
# 	rm -rvf *.o

# .PHONY = all clean

# CC = g++                        # compiler to use


# SRCS := $(wildcard *.cpp)
# BINS := $(SRCS:%.cpp=%)

# all: ${BINS}

# %: %.o
# 	@echo "Checking.."
# 	${CC} -lm $< -o $@

# %.o: %.cpp
# 	@echo "Creating object.."
# 	${CC} -c $<

# clean:
# 	@echo "Cleaning up..."
# 	rm -rvf *.o ${BINS}