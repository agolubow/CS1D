CC = g++
FLAGS = -std=c++11
WFLAG = -Wall
OFLAG = -o
CFLAG = -c
SOURCES = ArrayList.cpp
OBJS = $(SOURCES:.cpp=.o)
EXECUTABLE = ArrayList

all:$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):$(OBJS)

	$(CC) $(OBJS) $(OFLAG) $@ $(WFLAG)

.cpp.o:

	$(CC) $(CFLAG) $< $(OFLAG) $@ $(WFLAG)

clean:

	rm *.o *.tar $(EXECUTABLE)

tar:

	tar cf $(EXECUTABLE).tar $(EXECUTABLE).scr *.cpp *.h