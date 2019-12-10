CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example : jack_module.o osc.o sine.o main.o 
	$(CC) -o $@ $(CFLAGS) jack_module.o osc.o sine.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example


# CC = g++-9


# melody: jack_module.o osc.o sine.o main.o
# 	$(CC) -o melody jack_module.o osc.o sine.o main.o

# jack_module.o: jack_module.cpp jack_module.h
# 	$(CC) -c jack_module.cpp

# osc.o: osc.cpp osc.h
# 	$(CC) -c osc.cpp

# sine.o: sine.cpp sine.h
# 	$(CC) -c sine.cpp

# main.o: main.cpp
# 	$(CC) -c main.cpp

# clean:
# 	rm *.o melody

