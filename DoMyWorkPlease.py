import os

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

for x in range(0,i):
    aux = sortArchives.pop()
    file_object = open(aux,"r")
    for line in file_object:
        if line[0] is '*':
            newstr = line.replace("*", "")
            size = int(newstr)
        elif line is '\n':
            if counter is 0:
                continue
            new = resultForSize()
            new.name = aux
            new.averageTime = accumulator/counter
            new.inputSize = size
            results.append(new)
            accumulator = 0
            counter = 0
        else:
            accumulator += float(line)
            counter+=1


print(results[0].inputSize)
