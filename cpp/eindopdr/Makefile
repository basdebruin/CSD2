CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

OFILES = jack_module.o osc.o sine.o fm.o pulse.o noise.o main.o

all: player

player: $(OFILES) 
	$(CC) -o $@ $(CFLAGS) $(OFILES) $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
