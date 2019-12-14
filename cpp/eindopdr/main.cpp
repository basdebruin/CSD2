#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
// my own:
#include "osc.h"
#include "sine.h"
#include "pulse.h"
#include "noise.h"
#include "snare.h"

/*
 * Modified by Bas de Bruin
 * to play oscillators
 */

int main(int argc, char ** argv) {
	// create a JackModule instance
	JackModule jack;

	// init the jack, use program name as JACK client name
	jack.init(argv[0]);
	double samplerate = jack.getSamplerate();


	// --- DEFINING OSCILLATORS ---
	//Sine sine;
	//sine.setFreq(300);
	//Pulse p;
	// p.setFreq(300);
	// p.setSaturation(100);

	// Noise noise;

	int timePassed = 0;

	Snare snare;



	// --- JACK ONPROCESS ---
	jack.onProcess = [&](jack_default_audio_sample_t * inBuf,
		jack_default_audio_sample_t * outBuf, jack_nframes_t nframes) {

			// retrigger snare
			if (timePassed > 100) {
				snare.trigger();
				timePassed = 0;
				std::cout << "snare trigger\n";
			}
			timePassed++;


			for (unsigned int i = 0; i < nframes; i++) {
				// tick and sample
				
				snare.tick();
				outBuf[i] = snare.getSample();
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