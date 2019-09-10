# IRREGULAR BEAT GEERATOR
# bas de bruin

import re

# open file and split lines
f = open("54prob.txt", "r")
f = f.read().split("\n")

# take the "kick" out and split to list
kickProbs = f[1].replace("kick", "").split()
print(kickProbs)