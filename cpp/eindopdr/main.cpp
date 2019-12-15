#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
// OSCILLATORS
#include "osc.h"
#include "sine.h"
#include "pulse.h"
#include "noise.h"
// SYNTHS
#include "snare.h"
#include "kick.h"
#include "lfosynth.h"

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

	// keeping track of time for the sequence
	int timePassed = 0;

	// --- DEFINING OSCILLATORS / SYNTHS ---
	Snare snare;
	Kick kick;

	// freq, lfo speed, envelope length
	LfoSynth synth(40, 2, 50000);



	// --- INTRODUCTION ----
	std::cout << "\n\n\n\n\n\n\n\n"
			  << "------------------------  \n"
		      << "     Welcome to the       \n"
			  << "------------------------  \n"
			  << "       C++ Techno         \n"
			  << "       EXPERIENCE         \n"
			  << "------------------------  \n";


	// --- JACK ONPROCESS ---
	jack.onProcess = [&](jack_default_audio_sample_t * inBuf,
		jack_default_audio_sample_t * outBuf, jack_nframes_t nframes) {

			// trigger kick and snare
			if (timePassed == 50) {
				kick.trigger();
				std::cout << "•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o\n";
				// trigger synth envelope
				synth.trigger();
			} else if (timePassed > 100) {
				timePassed = 0;
				snare.trigger();
				std::cout << "o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•o•\n";
			}
			timePassed++;


			for (unsigned int i = 0; i < nframes; i++) {
				// tick and sample
				
				synth.tick(samplerate);
				//
				snare.tick();
				kick.tick(samplerate);
				outBuf[i] = snare.getSample() + kick.getSample() + synth.getSample();
			}

			return 0;
	};

	jack.autoConnect();

	//keep the program running and listen for user input, q = quit
	std::cout << "\n~Press 'q' to exit, but why would you?~\n";
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