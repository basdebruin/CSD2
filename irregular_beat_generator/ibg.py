# IRREGULAR BEAT GENERATOR
# bas de bruin

import time
import simpleaudio as sa

# load sounds
kick = sa.WaveObject.from_wave_file("sounds/kick.wav")
snare = sa.WaveObject.from_wave_file("sounds/snare.wav")
hat = sa.WaveObject.from_wave_file("sounds/hat.wav")


# open file and split lines
f = open("54prob.txt", "r")
f = f.read().split("\n")

# take the "kick" out and split to list
kickProbs = f[1].replace("kick", "").split()
print(kickProbs)



# user inputs
print("             /")
print("            / ")
print("           /  ")
print("          /   ")
print("    ______    ")
print("   /      \   ")
print("  |\______/|  ")
print("  |        |  ")
print("   \______/   ")
print("\nBEAT GENERATOR\n")
bpm = input("--- Input your BPM - (default: 120) ---> ")
# test user input, otherwise go to default
if bpm == "":
    bpm = 120
else:
    bpm = float(bpm)
millis = 60 / bpm

#timestamps16th = [0, 1, 4, 5, 7, 11 etc]
#ts = timestamps16th.pop(0)
#while True:
#   now = time.time() * 1000
#   if now-timeZero >= ts * sixteenthnotedurationn
#   print(ts)
#   play_obj = snare.play()
#   if timestamps16th:
#       ts = timestams16.pop(0)
#   else:
#       break
#   else: time.sleep(0.001)
