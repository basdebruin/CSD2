import bpy

import wave
import csv
import math

# load files

# open audio file
audio = wave.open(bpy.path.abspath('//audio.wav'), 'rb')

audio_framerate = audio.getframerate()
video_framerate = 24

# open csv file
f = open(bpy.path.abspath('//audio.csv'), 'r')
reader = csv.reader(f)
# make array of wave data
audio_frames = [i for i in reader]
audio_frames = [float(i) for i in audio_frames[0]]



# audio functions

def audio_at_frame(framenr, audio_frames, audio_framerate, video_framerate):
    index = int(framenr * audio_framerate / video_framerate)
    power = 0
    # take average absolute value for amplitude
    for i in range(1000):
        if 0 < index+i < len(audio_frames):
            power += abs(audio_frames[index+i])
    return power/500 




# emission property

emission = bpy.data.materials["Material"].node_tree.nodes["Principled BSDF"].inputs[17]

def setEmission(e):
    emission.default_value = (e, e, e, 1)
    
last_value = 0
for i in range(400):
    val = audio_at_frame(i, audio_frames, audio_framerate, video_framerate)
    setEmission((val + last_value)/2)
    last_value = val
    emission.keyframe_insert("default_value", frame=i)
    
    
    
    
audio.close()