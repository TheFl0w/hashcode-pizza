SRC := $(notdir $(wildcard src/*.cpp))
OBJ := $(SRC:.cpp=.o)
DEPS := $(addprefix bin/,$(SRC:.cpp=.d))

CXX := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -MMD -I include/
LD := $(CXX) # lol
LD_FLAGS :=

all: bin pizza

pizza: $(addprefix bin/,$(OBJ))
	$(LD) $^ -o $@

bin/%.o: src/%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

bin:
	mkdir -p bin

clean:
	rm -rf bin
	rm -f pizza

-include $(DEPS)

.PHONY: all clean
