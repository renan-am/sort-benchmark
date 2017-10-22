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
			path="/gerador/input"
			echo "$tam" > gerador/input
			echo "1000000" >> gerador/input
			gerador=$(./gerador/gerador <gerador/input > inputs/$tam/input$i)
			mkdir -p "inputs/$tam/"
			$gerador
		done
		echo -n > gerador/input
done

for sortPath in sorts/*
do
	sort=$(basename $sortPath)
	echo $sort
	echo
	echo -n > "outputs/$sort.out"
	for tam in $tamanhos
	do
		echo $tam
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
