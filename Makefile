CFLAGS := --std=c++11 -Wfatal-errors -pthread -Wall
CPP := g++

SRCS := $(wildcard src/*.cpp)
PRGS := $(patsubst src/%.cpp,%,$(SRCS))

right: clean dir operator_order array pointer_play thread_local ambiguity \
    parameter_precedence static_cast tls template_static_const \
    constructor_destructor

dir:
	mkdir -p lin

clean:
	rm -Rf lin

all : clean dir $(PRGS)

% :: src/%.cpp
	$(CPP) $(CFLAGS) $< -o lin/$@
