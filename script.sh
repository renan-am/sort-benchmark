#!/bin/bash

./compilar.sh

tamanhos=""

for ((i = 1000000; i <= 10000000; i += 1000000)); do
	tamanhos+=" $i "
done


for tam in $tamanhos
do
	for ((i = 0; i<2; i++)); do
			mkdir -p "inputs/$tam/"
			path="/gerador/input"
			echo "$tam" > gerador/input
			echo "1000000" >> gerador/input
			gerador=$(./gerador/gerador <gerador/input > inputs/$tam/input$i)
			$gerador
		done
		echo gerou $tam
		echo -n > gerador/input
done

for sortPath in sorts/*
do
	sort=$(basename $sortPath)
	mkdir -p outputs
	echo $sort
	echo
	echo -n > "outputs/$sort.out"
	flag=0
	for tam in $tamanhos
	do
		if [ $flag -eq 1 ];
			then
				continue;
		fi
		echo $tam
		mkdir -p "outputs/"
		echo "*$tam" >> "outputs/$sort.out"
			for inputPath in inputs/$tam/*
			do
				input=$(basename $inputPath)
				#var=$(./sorts/$sort <"inputs/$tam/$input" >> "outputs/$sort.out")
				timeout 10 ./sorts/$sort <"inputs/$tam/$input" >> "outputs/$sort.out" 
				if [ $? -eq 124 ]; 
					then 
						flag=1
						echo TIMEOUT
						break; 
				fi

			done
		echo "" >> "outputs/$sort.out"
	done
	echo
done

rm -f outputs/*.html
python3 DoMyWorkPlease.py