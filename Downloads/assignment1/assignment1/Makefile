
# If you are compiling natively on a mac, you will need to use the following flags.
# When you are compiling your executable: 
#
#     g++ $(macflag) -o <exectuable> <source files> $(maclib)
#
# For example:
#
# 	  g++ $(macflag) -o a1 main.o Panel.o Button.o CuWindow.o Tester.o $(maclib)
#
# When you are compiling your object files:
#
#	  g++ $(macflag) -c <source file> $(macinclude)
#
# macinclude is used to include the X11 library, if you have installed it using XQuartz.
# maclib is used to link the X11 library, if you have installed it using XQuartz.
# macflag is used to enable C++11 features, which are required for this assignment.

macflag    = -std=c++11 				
macinclude = -I /opt/X11/include 
maclib     = -L /opt/X11/lib 

# Put your Makefile instructions below.

CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lX11

SOURCES = RGB.cpp Button.cpp Panel.cpp CuWindow.cpp Tester.cpp main.cpp
HEADERS = RGB.h Button.h Panel.h CuWindow.h Tester.h defs.h
OBJECTS = $(SOURCES:.cpp=.o)

EXEC = a1

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(EXEC)