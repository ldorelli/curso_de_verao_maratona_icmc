for path in $(ls -d */)
do
	echo $path
	for file in $(ls $path)
	do
		./decrypt.sh $path$file
	done
done
