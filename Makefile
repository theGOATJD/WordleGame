ALL: main

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)

OBJECTS := $(SOURCES:.cpp=.o)

%.o :  %.cpp ${HEADERS}
	g++ -c $<

main:  ${OBJECTS}
	g++ -o $@ ${OBJECTS}

testing: main
	 ./main > /dev/null
	 @if [ $$? -eq 0]; then echo "test passed": fi

