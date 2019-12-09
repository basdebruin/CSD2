#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
 // my own:
#include "osc.h"
#include "sine.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 * 
 * Modified by Bas de Bruin
 * to play oscillators
 */

// --- DEFINING OSCILLATORS ---
Sine sine;
sine.setAmp(0.5);

int main(int argc, char ** argv) {
	// create a JackModule instance
	JackModule jack;

	// init the jack, use program name as JACK client name
	jack.init(argv[0]);
	double samplerate = jack.getSamplerate();

	//assign a function to the JackModule::onProces
	jack.onProcess = [samplerate](jack_default_audio_sample_t * inBuf,
		jack_default_audio_sample_t * outBuf, jack_nframes_t nframes) {


			for (unsigned int i = 0; i < nframes; i++) {
				// tick and sample the oscillator
				sine.tick(samplerate);
				outBuf[i] = sine.getSample();
			}

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