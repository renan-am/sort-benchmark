tamanhos="5000 
10000 
25000
50000 
100000 
250000 
500000"

for tam in $tamanhos
do
	for ((i = 0; i<10; i++)); do
			gerador="./gerador/gerador <$tam 1000000"
			mkdir -p "inputs/$tam/"
			echo "$gerador" >> "inputs/$tam/input$i"
		done
done

for tam in $tamanhos
do
	echo $tam
	echo
	for sortPath in sorts/*
	do
		sort=$(basename $sortPath)
		echo $sort
		mkdir -p "outputs/"
		echo "$tam" >> "outputs/$sort.out"
			for inputPath in inputs/$tam/*
			do	
				input=$(basename $inputPath)
				var=$(./sorts/$sort <"inputs/$tam/$input")
				echo "$var" >> "outputs/$sort.out"
			done
	echo " " >> "outputs/$sort.out"
	done
	echo
done