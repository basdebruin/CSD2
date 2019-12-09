melody: jack_module.o osc.o sine.o main.o
	g++ -o melody jack_module.o osc.o sine.o main.o

jack_module.o: jack_module.cpp jack_module.h
	g++ -c jack_module.cpp

osc.o: osc.cpp osc.h
	g++ -c osc.cpp

sine.o: sine.cpp sine.h
	g++ -c sine.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o melody

