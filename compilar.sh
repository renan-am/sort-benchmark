for filePath in sources/*.c
do
	file=$(basename $filePath)
	name=$(echo $file | cut -f 1 -d '.')
	$(gcc sources/$name.c -o sorts/$name)
	
done