# IRREGULAR BEAT GENERATOR
# bas de bruin

import time
from datetime import datetime
import random as r
import simpleaudio as sa
import sys
from midiutil import MIDIFile

# load sounds
kick = sa.WaveObject.from_wave_file("sounds/kick.wav")
snare = sa.WaveObject.from_wave_file("sounds/snare.wav")
hat = sa.WaveObject.from_wave_file("sounds/hat.wav")


# open file and split lines
if len(sys.argv) > 1:
    f = open(sys.argv[1], "r")
else:
    sys.exit("Make sure to include a text file as an argument. ")
f = f.read().split("\n")


# take the "kick", "snare" out and split to list
kickProbs = f[1].replace("kick", "").split()
snareProbs = f[2].replace("snare", "").split()



# USER INPUTS
print("\              /")
print(" \            / ")
print("  \          /  ")
print("   \        /   ")
print("     ______     ")
print("    /      \    ")
print("   |\______/|   ")
print("   |        |   ")
print("    \______/    ")
print("\nBEAT GENERATOR\n")
bpm = input("--- Input your BPM --- (default: 120) ---> ")
playTimes = input("--- How many times would you like to hear the beat? --- (default: 3) ---> ")

# test user input, otherwise go to default
if bpm == "":
    bpm = 120
elif 10 < float(bpm) < 1000:
    bpm = float(bpm)
else:
    bpm = 120


timePerLoop = 60 / bpm / 4

if playTimes == "":
    playTimes = 3
elif 1 < int(playTimes) < 100:
    playTimes = int(playTimes)
else:
    playTimes = 3

# setup midi file
myMidi = MIDIFile(1)
myMidi.addTempo(0,0,bpm)
# MIDI Note Maker
def addMidiNote(p, t):
    # track, channnel, pitch, time(quarter note), duration, volume
    myMidi.addNote(0, 0, p, t / 4, 0.25, 100)


# PLAYER
lastTime = time.time()
index = 0
indexFromStart = 0
while True:
    if time.time() - lastTime >= timePerLoop and index < len(kickProbs):

        # play
        # kick & hihat
        currentKick = float(kickProbs[index])
        if r.random() < currentKick:
            kp = kick.play()
            addMidiNote(36, indexFromStart)
        else:
            # play hihat if kick doens't play
            hp = hat.play()
            addMidiNote(42, indexFromStart)
        
        # snare
        currentSnare = float(snareProbs[index])
        if r.random() < currentSnare:
            sp = snare.play()
            addMidiNote(38, indexFromStart)
        # reset lastTime for next loop
        lastTime = time.time()
        index += 1
        indexFromStart += 1

    elif index >= len(kickProbs):

        # reset index for next loop through array
        if playTimes > 1:
            index = 0
            playTimes -= 1
        else:
            # wait till done and break
            kp.wait_done()
            hp.wait_done()
            sp.wait_done()
            break

    else:

        time.sleep(0.001)


# WRITE MIDI

print("That was all.\n")
saveOrNot = input("--- Would you like to save the beat as a MIDI file? --- (y/n) ---> ")
if saveOrNot.lower() == "y":
    fileName = "Generated_Beat_" + datetime.now().strftime("%H:%M:%S_%d-%m-%y") + ".mid"
    with open(fileName, "wb") as output_file:
        myMidi.writeFile(output_file)
    print("Saved as ", fileName, "\nBye!")
else:
    print("Okay, I won't \nBye!")