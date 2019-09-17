# IRREGULAR BEAT GENERATOR
# bas de bruin

import time
import random as r
import simpleaudio as sa
import sys

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
else:
    bpm = float(bpm)

timePerLoop = 60 / bpm / 4

if playTimes == "":
    playTimes = 3
elif 0 < int(playTimes) < 100:
    playTimes = int(playTimes)
else:
    playTimes = 3




# PLAYER
lastTime = time.time()
index = 0
while True:
    if time.time() - lastTime >= timePerLoop and index < len(kickProbs):

        # speel
        # kick en hihat
        currentKick = float(kickProbs[index])
        if r.random() < currentKick:
            kp = kick.play()
        else:
            # play hihat if kick doens't play
            hp = hat.play()
        
        # snare
        currentSnare = float(snareProbs[index])
        if r.random() < currentSnare:
            sp = snare.play()
        # reset lastTime for next loop
        lastTime = time.time()
        index += 1

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
