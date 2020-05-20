# turns wave file into csv file that blender can read

import numpy as np
import soundfile as sf
import csv

# load audio file

audio, samplerate = sf.read('audio.wav')

output_array = [audio[i][0] for i in range(len(audio))]

# write to csv file
with open('audio.csv', 'w') as f:
    writer = csv.writer(f)
    writer.writerow(output_array)


# read using:
#
#f = open('audio.csv', 'r')
#reader = csv.reader(f)
#audio_data = [i for i in reader]
#float(audio_data[0][0]) => first sample value