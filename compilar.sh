for filePath in sources/*.c
do
	file=$(basename $filePath)
	name=$(echo $file | cut -f 1 -d '.')
	$(gcc sources/$name.c -o sorts/$name)

done

for filePath in sources/*.pll.cpp
do
	file=$(basename $filePath)
	name=$(echo $file | cut -f 1 -d '.')
	$(g++ sources/$name.pll.cpp -o sorts/$name -pthread -std=c++11)

done
