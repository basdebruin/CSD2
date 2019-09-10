#  ritmische playback
#  bas de bruin

import simpleaudio as sa
import time

# load wave file
sound = sa.WaveObject.from_wave_file("soundFiles/triangle1.wav")

#  Intro  /  ask for bpm
print("\n       ---   INSTRUCTIONS   ---   \n", "\n enter your rythm values in the input.txt text file!")
print("\n                 ---")
bpm = float(input("\n enter the BPM please: "))

# calc time.sleep time
waitTime = 60 / bpm

# read input.txt and split by space
file = open("input.txt", "r")
seq = file.read().split()

# play
for i in seq:
    s = sound.play()
    # mini visualiser
    print("#" * int(i), " " * abs(8 - int(i)) * 2, "#" * int(i))
    # wait
    time.sleep(waitTime / float(i))

# wait till sample is done playing before terminating
s.wait_done()