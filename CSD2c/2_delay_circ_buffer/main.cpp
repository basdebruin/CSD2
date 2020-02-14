#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "circBuffer.h"
#include "delay.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

// 10 seconds if samplerate = 44100
#define MAX_DELAY_SIZE 441000
#define DELAY_TIME_SEC 9.0f

#define PI_2 6.28318530717959

int main(int argc, char ** argv) {
	// create a JackModule instance
	JackModule jack;

	// init the jack, use program name as JACK client name
	jack.init(argv[0]);
	float samplerate = jack.getSamplerate();

	// check arguments
	float delayTimeSec = DELAY_TIME_SEC;
	if(argc >= 2) delayTimeSec = (float) atof(argv[1]);
	std::cout <<  "\nDelay time in seconds: " << delayTimeSec << "\n";

	// make delay
	Delay delay(delayTimeSec, samplerate);

	//assign a function to the JackModule::onProces
	jack.onProcess = [ & delay](jack_default_audio_sample_t * inBuf,
		jack_default_audio_sample_t * outBuf, jack_nframes_t nframes) {

		delay.process(inBuf, outBuf, nframes);
		return 0;
	};

	jack.autoConnect();

	//keep the program running and listen for user input, q = quit
	std::cout << "\n\nPress 'q' when you want to quit the program.\n";
	bool running = true;
	while (running) {
		switch (std::cin.get()) {
			case 'q':
				running = false;
				jack.end();
				break;
		}
	}

	//end the program
	return 0;
} // main()