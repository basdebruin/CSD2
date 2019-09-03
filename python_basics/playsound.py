#  playsound
#  bas de bruin

import simpleaudio as sa


print("\n -------  EPIC TRIANGLE PLAYER  ------- \n ")

repeat = input("How many times would you like to hear the triangle? ")

print("\n                 enjoy! \n ")


# load wave file
waveObj = sa.WaveObject.from_wave_file("soundFiles/triangle1.wav")

# play for each repeat function
def repeator(repeats):
    for i in range(int(repeats)):
        playObj = waveObj.play()
        playObj.wait_done()

# do it
repeator(repeat);