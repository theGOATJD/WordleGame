ALL: main

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)

OBJECTS := $(SOURCES:.cpp=.o)

%.o :  %.cpp ${HEADERS}
	g++ -c $<

main:  ${OBJECTS}
	g++ -o $@ ${OBJECTS}


