#  ritmische playback
#  bas de bruin

import simpleaudio as sa
import time
import math

# load wave file
sound = sa.WaveObject.from_wave_file("soundFiles/triangle1.wav")

#  Intro  /  ask for bpm
print("\n       ---   INSTRUCTIONS   ---   \n", "\n enter your rythm values in the input.txt text file!")
print("\n                 ---")
bpm = float(input("\n enter the BPM please: "))

# calc time.sleep time
waitTime = 60 / bpm


# small terminnal visualiser
def visualise(t):
    str = "";
    for i in range(0, 60):
        # math magic
        wave = math.sin(i * 0.05) * math.tan(t * 0.1) * math.cos(i * t)
        if wave > 0.2:
            str += "#"
        elif wave > -0.2:
            str += " "
        else:
            str += "-"
    
    print(str, "\n", str)



# read input.txt and split by space
file = open("input.txt", "r")
seq = file.read().split()

# play
for i in seq:
    s = sound.play()
    #visualise
    visualise(float(i))
    # wait
    time.sleep(waitTime / float(i))

# wait till sample is done playing before terminating
s.wait_done()
