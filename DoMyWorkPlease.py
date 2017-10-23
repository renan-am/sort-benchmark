import os
import matplotlib.pyplot as plt

class resultForSize:
    def __init__(self):
        self.sortName = ''
        self.inputSize = 0
        self.averageTime = 0

os.chdir('outputs/')
i = 0
sortArchives = [];
for filename in os.listdir():
    print(filename)
    i = i + 1
    sortArchives.append(filename)
print(i)
print(sortArchives)

results = []
accumulator = 0
counter = 0
size = 0

for n in range(0,i):
    aux = sortArchives.pop()
    results.append([])
    results[n].append(aux)
    file_object = open(aux,"r")
    results[n].append([])
    results[n].append([])
    for line in file_object:
        if line[0] is '*':
            newstr = line.replace("*", "")
            results[n][1].append(int(newstr))
        elif line is '\n':
            if counter is 0:
                continue

            results[n][2].append(accumulator/counter)

            accumulator = 0
            counter = 0
        else:
            accumulator += float(line)
            counter+=1


for n in range(0,i):
    if len(results[n][1]) > len(results[n][2]):
        results[n][1].pop()

        
for n in range(0,i):
    plt.plot(results[n][1], results[n][2])


plt.ylabel('some numbers')
plt.show()
