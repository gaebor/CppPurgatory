CFLAGS := --std=c++11 -Wfatal-errors
CPP := g++

SRCS := $(wildcard src/*.cpp)
PRGS := $(patsubst src/%.cpp,%,$(SRCS))

default: right

dir:
	mkdir -p lin

clean:
	rm -Rf lin

all : clean dir $(PRGS)
right: clean dir operator_order array pointer_play

% :: src/%.cpp
	$(CPP) $(CFLAGS) $< -o lin/$@
