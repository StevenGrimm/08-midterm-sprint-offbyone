GPP = g++

SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst src/%.cpp,obj/%.o,$(SRCS))

# above but without main for catch2 utesting
SRCS_NOMAIN = $(filter-out src/main.cpp,$(SRCS))
OBJS_NOMAIN := $(patsubst src/%.cpp,obj/%.o,$(SRCS_NOMAIN))

TSRCS := $(wildcard test/*.cpp)
TOBJS := $(patsubst test/%.cpp,obj/%.o,$(TSRCS))

EXE := bin/class_roster

.PHONY: all clean pre-build test

all: pre-build $(EXE)

pre-build:
#	$(warning $(SRCS_NOMAIN))
	mkdir -p bin obj

$(EXE): $(OBJS)
#	$(warning  Linking object files)
	$(GPP) -g $(OBJS) -o $(EXE)

# pattern for obj files from src
obj/%.o: src/%.cpp
	$(GPP) -g --std=c++17 -c $< -o $@

# pattern for obj files from test
obj/%.o: test/%.cpp
	$(GPP) -g --std=c++17 -c $< -o $@


make test: pre-build $(TOBJS) $(OBJS_NOMAIN)
	$(GPP) $(TOBJS) $(OBJS_NOMAIN) -o test/test
	test/test
# chmod 773 test/expect_test
# test/expect_test	

clean: 
	-rm -rf bin/ obj/