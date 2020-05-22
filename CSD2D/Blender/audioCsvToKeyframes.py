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
# make array of wave data (mono)
audio_frames = [i for i in reader]
audio_frames = [float(i) for i in audio_frames[0]]



# audio functions

# get audio loudness/power at certain video frame
# takes average of many audio frames to calc power
def audio_at_frame(framenr, audio_frames, audio_framerate, video_framerate):
    index = int(framenr * audio_framerate / video_framerate)
    power = 0
    # take average absolute value for amplitude
    for i in range(200):
        if 0 < index+i < len(audio_frames):
            power += abs(audio_frames[index+i])
    return power/100 




# change properties of material

# getting the z rotation property from deep within blender
property = bpy.data.materials["blobs"].node_tree.nodes["Mapping"].inputs[2]
property.default_value[2] = 0

# for 400 frames (the length of the audio)
# make keyframes based on audio data
for i in range(400):
    vel = audio_at_frame(i, audio_frames, audio_framerate, video_framerate) / 1.2
    # keep increasing the value with vel as velocity
    property.default_value[2] += vel * vel
    # insert keyframe at frame i
    property.keyframe_insert("default_value", frame=i)
    
    
    
    
audio.close()