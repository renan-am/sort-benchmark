import os

class resultForSize:
    def __init__(self):
        self.inputSize = 0
        self.avarageTime = 0

os.chdir('outputs/')
i = 0
sortArchives = [];
for filename in os.listdir():
    print(filename)
    i = i + 1
    sortArchives.append(filename)
print(i)
print(sortArchives)



results =

for x in range(0,i):
    file_object = open(sortArchives.pop(),"r")
    for line in file_object:
        if line[0] is '*':
            newstr = line.replace("*", "")
            print(newstr)
