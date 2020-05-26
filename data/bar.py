# usage:
# python3 bar.py <num-thousand-hands> <num-players>

import sys
import csv
import matplotlib.pyplot as plt
import numpy as np

hands = []
count = []

title = "./hand_counts/" + sys.argv[2] + "-players/" + sys.argv[1] + "-hands"

with open(title) as fp:
    r = csv.reader(fp)
    for h,n in r:
        hands.append(h)
        count.append(int(n))

hands=["HC","1P","2P","3oK","St","Fl","FH","4oK","SF"]

plt.style.use("fivethirtyeight")
plt.rcParams.update({'font.size': 10})

plot_title = "Winning hands over " + sys.argv[1] + ",000 hands - " + sys.argv[2] + " players"
plt.title(plot_title)
plt.bar(hands,count,color="#444444")
plt.ylabel("Number of wins")

if int(sys.argv[1]) is 1:
    plt.yticks(np.arange(400, step=50))
elif int(sys.argv[1]) is 10:
    plt.yticks(np.arange(4000, step=500))
elif int(sys.argv[1]) is 100:
    plt.yticks(np.arange(40000, step=5000))
elif int(sys.argv[1]) is 250:
    plt.yticks(np.arange(100000, step=12500))

plt.tight_layout()

filename = "./figs/" + sys.argv[1] + "_hands_" + sys.argv[2] + "_players"
plt.savefig(filename)
