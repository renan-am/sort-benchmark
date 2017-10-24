import os
import plotly
import plotly.graph_objs as go

def magnitude(x):
	return int(math.log10(x))

os.chdir('outputs/')
i = 0
sortArchives = [];
for filename in os.listdir():
    i = i + 1
    sortArchives.append(filename)

results = []
accumulator = 0
counter = 0
size = 0

for n in range(0,i):
    aux = sortArchives.pop()
    file_object = open(aux,"r")
    newstr2 = aux.replace(".out","")
    aux = newstr2
    results.append([])
    results[n].append(aux)
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

possibleMagnitudes = []
## Classifying lists by magnitude to get a good scale, and more graphs
for n in range(0,i):
	results[n].append([])
	results[n][3].append(magnitude(max(results[n][1])))
	if magnitude(max(results[n][1]) in possibleMagnitudes:
		continue
	else:
		possibleMagnitudes.append(magnitude(max(results[n][1])))

numberOfGraphs = len(possibleMagnitudes)

## fazer por numero de ocorrencias de cada termo de possibleMagnitudes


trace = [None]*i

for n in range (0,i):
    trace[n] = go.Scatter(
        x = results[n][1],
        y = results[n][2],
        name = results[n][0],
        line = dict(
            #color = ('rgb(205, 12, 24)'),
            width = 4,
            #dash = 'linedot' # dash options include 'dash', 'dot', and 'dashdot'
            )
)

# Edit the layout
layout = dict(title = 'Teste de desempenho de Algoritmos de Ordenação',
              xaxis = dict(title = 'Número de Elementos de Entrada (n)'),
              yaxis = dict(title = 'Tempo de execução (s)'),
              )

fig = dict(data=trace, layout=layout)
plotly.offline.plot(fig, filename='grafico.html')
