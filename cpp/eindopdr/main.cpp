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
#include "kick.h"

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

	// Noise noise;

	int timePassed = 0;

	Snare snare;
	Kick kick;

	Pulse p;
	p.setFreq(200);
	p.setSaturation(50);
	p.setAmp(0.2);



	// --- JACK ONPROCESS ---
	jack.onProcess = [&](jack_default_audio_sample_t * inBuf,
		jack_default_audio_sample_t * outBuf, jack_nframes_t nframes) {

			// trigger kick and snare
			if (timePassed == 100) {
				kick.trigger();
				std::cout << "kick trigger\n";
				//
				p.setFreq(300);
			} else if (timePassed > 200) {
				timePassed = 0;
				snare.trigger();
				std::cout << "snare trigger\n";
				//
				p.setFreq(200);
			}
			timePassed++;


			for (unsigned int i = 0; i < nframes; i++) {
				// tick and sample
				
				p.tick(samplerate);
				//
				snare.tick();
				kick.tick(samplerate);
				outBuf[i] = snare.getSample() + kick.getSample() + p.getSample();
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