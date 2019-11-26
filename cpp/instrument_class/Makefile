banjo: instrument.o playing_the_banjo.o
	g++ -o banjo instrument.o playing_the_banjo.o

instrument.o: instrument.cpp
	g++ -c instrument.cpp

playing_the_banjo.o: playing_the_banjo.cpp
	g++ -c playing_the_banjo.cpp


clean:
	rm *.o banjo