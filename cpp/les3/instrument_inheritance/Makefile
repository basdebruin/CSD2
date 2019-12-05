# makefile for instrument_inheritance ass.


inheritance: instrument.o banjo.o mayonaise.o bongo.o main.o
	g++ -o inheritance instrument.o banjo.o mayonaise.o bongo.o main.o

instrument.o: instrument.cpp
	g++ -c instrument.cpp

banjo.o: banjo.cpp
	g++ -c banjo.cpp

mayonaise.o: mayonaise.cpp
	g++ -c mayonaise.cpp

bongo.o: bongo.cpp
	g++ -c bongo.cpp

main.o: main.cpp
	g++ -c main.cpp


clean:
	rm *.o inheritance