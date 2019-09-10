#  ritmische playback
#  bas de bruin

import simpleaudio as sa
import time

# load wave file
sound = sa.WaveObject.from_wave_file("soundFiles/triangle1.wav")

#  Intro  /  ask for bpm
print("\n       ---   INSTRUCTIONS   ---   \n", "\n enter your rythm values in the input.txt text file!")
print("\n                 ---")
bpm = input("\n enter the BPM please: ")

waitTime = 60 / bpm

file = open("input.txt", "r")
seq = file.read().split()

for i in seq:
    sound.play()
    time.sleep(bpm / i)