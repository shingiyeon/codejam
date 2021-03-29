import os
import random
import math

def sigmoid_function(x):
    return 1 / (1 + math.exp(-x))

def create_data():
    datas = []
    Q = []
    for i in range(1, 10001):
        Q.append(random.uniform(-3.0, 3.0))

    for i in range(1, 100):
        string = ""
        S = random.uniform(-3.0, 3.0)

        for j in range(0, 10000):
          f = sigmoid_function(S - Q[j])
          prob = random.uniform(0, 1.0)
          if prob <= f:
              string += "1"
          else:
              string += "0"
        datas.append((string, False))

    string = ""
    for j in range(0, 10000):
        prob = random.uniform(0, 1.0)
        S = random.uniform(-3.0, 3.0)
        if prob <= 0.5:
            string += "1"
        else:
            f = sigmoid_function(S - Q[j])
            prob2 = random.uniform(0, 1.0)
            if prob2 <= f:
                string += "1"
            else:
                string += "0"
    datas.append((string, True))
    random.shuffle(datas)
    return datas

with open("new_input.txt", "a", encoding="utf-8") as f:
	f.write("50\n")
	f.write("10\n")

for i in range(0, 50):
	datas = create_data()
	with open("new_input.txt", "a", encoding="utf-8") as f:
		for data in datas:
			f.write(data[0] + "\n")

	for idx, data in enumerate(datas):
		if data[1] == True:
			ans = idx

	with open("new_output.txt", "a", encoding="utf-8") as f:
		f.write(str(ans + 1) + "\n")