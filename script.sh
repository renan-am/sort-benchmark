#!/bin/bash

# Executes command with a timeout
# Params:
#   $1 timeout in seconds
#   $2 command
# Returns 1 if timed out 0 otherwise
timeouts() {

    time=$1

    # start the command in a subshell to avoid problem with pipes
    # (spawn accepts one command)
    command="/bin/sh -c \"$2\""

    expect -c "set echo \"-noecho\"; set timeout $time; spawn -noecho $command; expect timeout { exit 1 } eof { exit 0 }"    

    if [ $? = 1 ] ; then
        echo "Timeout after ${time} seconds"
    fi

}

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
	flag=0
	for tam in $tamanhos
	do
		echo $tam
		mkdir -p "outputs/"
		echo "$tam" >> "outputs/$sort.out"
		if [ $flag -eq 1 ];
			then
				continue;
		fi
			for inputPath in inputs/$tam/*
			do
				input=$(basename $inputPath)
				#var=$(./sorts/$sort <"inputs/$tam/$input" >> "outputs/$sort.out")
				timeout 2 ./sorts/$sort <"inputs/$tam/$input" >> "outputs/$sort.out" 
				if [ $? -eq 124 ]; 
					then 
						flag=1
						break; 
				fi

			done
		echo " " >> "outputs/$sort.out"
	done
	echo
done